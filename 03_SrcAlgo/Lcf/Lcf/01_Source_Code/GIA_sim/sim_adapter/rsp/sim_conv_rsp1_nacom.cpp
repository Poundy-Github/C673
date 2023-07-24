/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter rsp

  MODULNAME:       sim_conv_rsp1_nacom

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   20.08.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp1_nacom.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:21:40CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.2 2017/08/24 15:23:21CEST uid34177 
  CHANGES:         added include <math.h>
  CHANGES:         Revision 1.1 2017/08/10 13:15:33CEST Elsayed, Abdallah (uid34177) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1 2014/08/22 16:56:31CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_rsp1_nacom.h"
#include "sim_versioninfo_impl.h"

#include <math.h>

typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;

typedef struct                                                       /* [Satisfies_rte sws 1191] */
{
  signed char s_Real;
  signed char s_Imag;
} t_Complex8;                                                        /* signed 8 bit integer complex */

#ifndef   SPT_N_BEAMS
  #define SPT_N_BEAMS 16
#endif
#ifndef RSP1_NACOM_NOF_RGS
  #define RSP1_NACOM_NOF_RGS 10
#endif
#ifndef RSP1_NACOM_NOF_DOPPLER_BINS
  #define RSP1_NACOM_NOF_DOPPLER_BINS 5
#endif

#define CML_INLINE  __inline
/*! Rounds of positive and negative numbers */
#define CML_Round(x) CML_f_Round2FloatGen(x)

#define ONE_DIV_2POT23 1.192092895507813e-007f
#define C_LUT_MAP ((float)N_LUT * ONE_DIV_2POT23)
#define N_LUT 32

__inline float CML_f_Round2FloatGen(float x);
__inline float CML_f_Round2FloatGen(float x)
{
  return (x >= 0.f) ? (float)(signed long)(x + 0.5f) : (float)(signed long)(x - 0.5f);
}


namespace RSP1_Nacom_V1                                              // Length: ARS400 PR 1716
{
  static const unsigned int NumNacomSpecBeamCmplxList = RSP1_NACOM_NOF_RGS * RSP1_NACOM_NOF_DOPPLER_BINS;

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

  typedef struct
  {
    unsigned short u_PowerScaleFactor;
    t_Complex8 a_SpecBeamCmplx[SPT_N_BEAMS];
  } NACOM_t_SpecBeamCmplx;

  typedef struct
  {
#ifdef FIRST_VERSION
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
#endif
    NACOM_t_SpecBeamCmplx a_Data[NumNacomSpecBeamCmplxList];
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
  } RSP1_t_Nacom;
} // end of namespace RSP_Nacom_V1

namespace RSP1_Nacom_V2                                              // Length: ARS400 PR 1816
{
  static const unsigned int NumNacomSpecBeamCmplxList = RSP1_NACOM_NOF_RGS * RSP1_NACOM_NOF_DOPPLER_BINS;

  typedef struct
  {
    float f_PowerScaleFactor;
    t_Complex8 a_SpecBeamCmplx[SPT_N_BEAMS];
  } NACOM_t_SpecBeamCmplx;

  typedef struct
  {
    uint32 u_VersionNumber;
    RSP1_Nacom_V1::SignalHeader_t sSigHeader;
    NACOM_t_SpecBeamCmplx a_Data[NumNacomSpecBeamCmplxList];
  } RSP1_t_Nacom;
} // end of namespace RSP_Nacom_V2

namespace RSP1_Nacom_Gen                                             // Length: not used
{
  typedef struct
  {
    uint32 u_VersionNumber;
    RSP1_Nacom_V1::SignalHeader_t sSigHeader;
    RSP1_Nacom_V1::NACOM_t_SpecBeamCmplx a_Data_V1[RSP1_Nacom_V1::NumNacomSpecBeamCmplxList];
    RSP1_Nacom_V2::NACOM_t_SpecBeamCmplx a_Data_V2[RSP1_Nacom_V2::NumNacomSpecBeamCmplxList];
  } RSP1_t_Nacom;
} // end of namespace RSP_Nacom_V2

// Initialization
template <typename T> static void InitVersion (T & Dest, uint32 VersionNumber)
{
  ::memset(&Dest, 0, sizeof(Dest));
  Dest.u_VersionNumber = VersionNumber;
}

class CConvRsp1Nacom : public CSimConverterBase
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

  RSP1_Nacom_V1::RSP1_t_Nacom m_BufV1;
  RSP1_Nacom_V2::RSP1_t_Nacom m_BufV2;
  RSP1_Nacom_Gen::RSP1_t_Nacom m_BufGen;

public:

  static const char *GetConverterTypeName()
  {
    return "RSP_Nacom";
  }

  CConvRsp1Nacom(void);
  virtual ~CConvRsp1Nacom(void);

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

  enum Nacoms
  {
    NACOM_V1,
    NACOM_V2,
    NACOM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[NACOM_VERSION_COUNT];
  static const CVersionInfoImpl * const NACOM_INPUT_VERSIONS[NACOM_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
  {
    for (int nI = 0; nI < NACOM_VERSION_COUNT; nI++)
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
  void Convert_v1_to_Gen (RSP1_Nacom_Gen::RSP1_t_Nacom & Dest, const RSP1_Nacom_V1::RSP1_t_Nacom & Src);
  void Convert_v2_to_Gen (RSP1_Nacom_Gen::RSP1_t_Nacom & Dest, const RSP1_Nacom_V2::RSP1_t_Nacom & Src);

  // Conversions from generic buffer to receive port (output)
  void Convert_Gen_to_v1 (RSP1_Nacom_V1::RSP1_t_Nacom & Dest, const RSP1_Nacom_Gen::RSP1_t_Nacom & Src);
  void Convert_Gen_to_v2 (RSP1_Nacom_V2::RSP1_t_Nacom & Dest, const RSP1_Nacom_Gen::RSP1_t_Nacom & Src);

  float CalcScale(float f_PowLog2Max, float f_PowLinCP16Max);
  void SetPowScaleFactorV1toV2 (float *p_fPowScaleFactor , const RSP1_Nacom_V1::NACOM_t_SpecBeamCmplx *const pSrc);
};

CVersionInfoImpl CConvRsp1Nacom::BASE_VERSION(0, 0, 0);

const unsigned long CConvRsp1Nacom::SUPPORTED_SIZE[CConvRsp1Nacom::NACOM_VERSION_COUNT] =
{
  sizeof(RSP1_Nacom_V1::RSP1_t_Nacom),
  sizeof(RSP1_Nacom_V2::RSP1_t_Nacom),
};

const CVersionInfoImpl * const CConvRsp1Nacom::NACOM_INPUT_VERSIONS[CConvRsp1Nacom::NACOM_VERSION_COUNT] =
{
  &BASE_VERSION,
  &BASE_VERSION
};


CConvRsp1Nacom::CConvRsp1Nacom(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufGen(), m_BufV1(), m_BufV2()
{
}

CConvRsp1Nacom::~CConvRsp1Nacom(void)
{
}

__inline float FastLog2(float x)
{
  typedef union
  {
    float  f_entry;
    uint32 u_entry;
    signed __int32  s_entry;
  } t_FltAccess;

  /* bias of exponent in internal float memory */
  static const uint32 F32_EXPO_BIAS =      127u;
  /* number of mantissa bits in internal float memory */
  static const uint32 F32_MANT_BITS =      23u;

  static const uint32 F32_EXPO_MASK =        0x7F800000u;
  static const uint32 F32_MANT_MASK =        0x007FFFFFu;

  /* Log2 lookup table between 1 and 2 */
  static const float log2_lut [N_LUT] = 
  {
    0.00000000000000f,
    0.04439411935845f,
    0.08746284125034f,
    0.12928301694497f,
    0.16992500144231f,
    0.20945336562895f,
    0.24792751344359f,
    0.28540221886225f,
    0.32192809488736f,
    0.35755200461808f,
    0.39231742277876f,
    0.42626475470210f,
    0.45943161863730f,
    0.49185309632967f,
    0.52356195605701f,
    0.55458885167764f,
    0.58496250072116f,
    0.61470984411521f,
    0.64385618977472f,
    0.67242534197150f,
    0.70043971814109f,
    0.72792045456320f,
    0.75488750216347f,
    0.78135971352466f,
    0.80735492205760f,
    0.83289001416474f,
    0.85798099512757f,
    0.88264304936184f,
    0.90689059560852f,
    0.93073733756289f,
    0.95419631038688f,
    0.97727992349992f
  };

  float f_lut_val;
  float f_lut_idx;
  uint32 uitemp;
  t_FltAccess xFltAcc;
  xFltAcc.f_entry = x;

  uitemp =  xFltAcc.u_entry & F32_MANT_MASK ;
  f_lut_idx = (float)uitemp;    
  f_lut_idx *= C_LUT_MAP;    
  f_lut_val = log2_lut[(uint32) f_lut_idx];

  xFltAcc.u_entry = xFltAcc.u_entry & F32_EXPO_MASK;  
  xFltAcc.u_entry = xFltAcc.u_entry >> F32_MANT_BITS;     
  xFltAcc.s_entry = xFltAcc.s_entry - (signed __int32) F32_EXPO_BIAS;

  xFltAcc.f_entry = (float) (  ( (float) xFltAcc.s_entry + f_lut_val ) );

  return xFltAcc.f_entry;
}


float CConvRsp1Nacom::CalcScale(float f_PowLog2Max, float f_PowLinCP16Max)
{
  static const float a_Pow2Lu[16] = {  1.0f,   2.0f,    4.0f,    8.0f,   16.0f,   32.0f,    64.0f,   128.0f,
                                     256.0f, 512.0f, 1024.0f, 2048.0f, 4096.0f, 8192.0f, 16384.0f, 32768.0f };
  float f_Scale;
  if(f_PowLinCP16Max > 0.001f)
  {
    float f_ErgFastLog2 = FastLog2(f_PowLinCP16Max);
    f_ErgFastLog2 *= 256.f;
    f_ErgFastLog2 = f_PowLog2Max - f_ErgFastLog2;
    f_ErgFastLog2 *= 0.001953125f;
    f_ErgFastLog2 = CML_Round(f_ErgFastLog2);
    uint32 u_ScaleLTst = (uint32)CML_Round((f_PowLog2Max - 256.f*FastLog2(f_PowLinCP16Max))*0.001953125f);
    if ((u_ScaleLTst >= 0) && (u_ScaleLTst < 16))
    {
      f_Scale = a_Pow2Lu[u_ScaleLTst];
    }
    else
    {
      f_Scale = a_Pow2Lu[0];
    }
  }
  else
  {
    f_Scale = 0.0f;
  }
  return f_Scale;
}

void CConvRsp1Nacom::SetPowScaleFactorV1toV2 (float *p_fPowScaleFactor , const RSP1_Nacom_V1::NACOM_t_SpecBeamCmplx *const pSrc)
{
  float f_PowLinCP16Max, f_tmpCmplx, f_Re, f_Im;
  /* Find Maxima of Complex value */
  f_Re = ((float)pSrc->a_SpecBeamCmplx[0].s_Real);
  f_Im = ((float)pSrc->a_SpecBeamCmplx[0].s_Imag);
  f_PowLinCP16Max = (f_Re*f_Re) + (f_Im*f_Im);
  for (int ii = 1; ii<SPT_N_BEAMS; ii++ )
  {
    f_Re = ((float)pSrc->a_SpecBeamCmplx[ii].s_Real);
    f_Im = ((float)pSrc->a_SpecBeamCmplx[ii].s_Imag);

    f_tmpCmplx =(f_Re*f_Re) + (f_Im*f_Im);

    if (f_tmpCmplx > f_PowLinCP16Max)
    {
      f_PowLinCP16Max = f_tmpCmplx;
    }
  }
  /* Calculate PowerScaleFactor */
  if(f_PowLinCP16Max > 0.001f)
  {
    const uint16 u_PowLog2Max = pSrc->u_PowerScaleFactor;
    double f_PowLin, f_ScaleL;
    f_PowLin = pow((double)2.0,(double)(u_PowLog2Max * 0.00390625));
    f_ScaleL = f_PowLin / f_PowLinCP16Max;
    f_ScaleL = sqrt(f_ScaleL);
    *p_fPowScaleFactor = (float)f_ScaleL;
  }
  else
  {
    *p_fPowScaleFactor = 0.f;
  }
  float fPowScaleFactorOld = *p_fPowScaleFactor;
  const uint16 u_PowLog2Max = pSrc->u_PowerScaleFactor;
  *p_fPowScaleFactor = CalcScale((float) u_PowLog2Max, f_PowLinCP16Max);
  float fPowScaleFactorOld2 = fPowScaleFactorOld;
}

// template function for little-big/big-little endian conversion
template<typename T> 
inline T Swap(T Value)
{
  T RetValue = 0;
  for(int i = 0; i < sizeof(T); i++)
  {
    RetValue <<= 8;
    RetValue |= Value & 0xFF;
    Value >>=8;
  }
  return RetValue;
}

void CConvRsp1Nacom::Convert_v1_to_Gen (RSP1_Nacom_Gen::RSP1_t_Nacom & Dest, const RSP1_Nacom_V1::RSP1_t_Nacom & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  for (int nI = 0; nI < (RSP1_Nacom_V1::NumNacomSpecBeamCmplxList); nI++)
  {
    SetPowScaleFactorV1toV2 (&(Dest.a_Data_V2[nI].f_PowerScaleFactor), &(Src.a_Data[nI]));
    memcpy (Dest.a_Data_V2[nI].a_SpecBeamCmplx, Src.a_Data[nI].a_SpecBeamCmplx, sizeof(Dest.a_Data_V2[nI].a_SpecBeamCmplx));
  }
}

void CConvRsp1Nacom::Convert_v2_to_Gen (RSP1_Nacom_Gen::RSP1_t_Nacom & Dest, const RSP1_Nacom_V2::RSP1_t_Nacom & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  for (int nI = 0; nI < (RSP1_Nacom_V2::NumNacomSpecBeamCmplxList); nI++)
  {
    // SetPowScaleFactorV2toV1 (&(Dest.a_Data_V1[nI].u_PowerScaleFactor), &(Src.a_Data[nI]));
    memcpy (Dest.a_Data_V1[nI].a_SpecBeamCmplx, Src.a_Data[nI].a_SpecBeamCmplx, sizeof(Dest.a_Data_V1[nI].a_SpecBeamCmplx));
  }
}

void CConvRsp1Nacom::Convert_Gen_to_v1 (RSP1_Nacom_V1::RSP1_t_Nacom & Dest, const RSP1_Nacom_Gen::RSP1_t_Nacom & Src)
{
  Dest.u_VersionNumber = 1u;
  Dest.sSigHeader = Src.sSigHeader;
  memcpy (Dest.a_Data, Src.a_Data_V1, sizeof(Dest.a_Data));
}

void CConvRsp1Nacom::Convert_Gen_to_v2 (RSP1_Nacom_V2::RSP1_t_Nacom & Dest, const RSP1_Nacom_Gen::RSP1_t_Nacom & Src)
{
  Dest.u_VersionNumber = Src.u_VersionNumber;
  Dest.sSigHeader = Src.sSigHeader;
  memcpy (Dest.a_Data, Src.a_Data_V2, sizeof(Dest.a_Data));
}

long CConvRsp1Nacom::ConvertData (
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  bool bGenBufferFilled = false;
  // First decide which version we are converting to
  // If direct one:one copy possible then do that (without check of Versions!)
  if (ulPPortSize == ulRPortSize)
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == SUPPORTED_SIZE[1]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[1])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))/* &&
    ((uDataVer == 2u) || (uDataVer == 0))*/)
  {
    // Source Port V2
    InitVersion(m_BufGen, 0);
    const RSP1_Nacom_V2::RSP1_t_Nacom & Src = *reinterpret_cast<RSP1_Nacom_V2::RSP1_t_Nacom *>(pPPortData);
    Convert_v2_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == SUPPORTED_SIZE[0]) &&
    ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(NACOM_INPUT_VERSIONS[0])) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))/* &&
    ((uDataVer == 1u) || (uDataVer == 0))*/)
  {
    // Source Port V1
    InitVersion(m_BufGen, 0);
    const RSP1_Nacom_V1::RSP1_t_Nacom & Src = *reinterpret_cast<RSP1_Nacom_V1::RSP1_t_Nacom *>(pPPortData);
    Convert_v1_to_Gen(m_BufGen, Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == SUPPORTED_SIZE[1]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[1])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V2
      InitVersion(m_BufV2, 0);
      RSP1_Nacom_V2::RSP1_t_Nacom & Dest = /*reinterpret_cast<RSP1_Nacom_V2::RSP1_t_Nacom &>*/(m_BufV2);
      Convert_Gen_to_v2(Dest, m_BufGen);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == SUPPORTED_SIZE[0]) &&
      ((requestPortVersionInfo.Equals(NACOM_INPUT_VERSIONS[0])) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V1
      InitVersion(m_BufV1, 0);
      RSP1_Nacom_V1::RSP1_t_Nacom & Dest = /*reinterpret_cast<RSP1_Nacom_V1::RSP1_t_Nacom &>*/(m_BufV1);
      Convert_Gen_to_v1(Dest, m_BufGen);
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
long CConvRsp1Nacom::GetDefaultValue(
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
    if (ulRPortSize == sizeof(m_BufV1))
    {
      InitVersion(m_BufV1, 0);
      *pDefaultData = &m_BufV1;
      ulDefaultSize = sizeof(m_BufV1);
      lRet = SIM_ERR_OK;
    }
    else if (ulRPortSize == sizeof(m_BufV2))
    {
      InitVersion(m_BufV2, 0);
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
bool CConvRsp1Nacom::IsVersionCompatibleWithType (
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
bool CConvRsp1Nacom::AreVersionsCompatible (
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
IConverter * CreateRSPNacomConvClass(void)
{
  return new CConvRsp1Nacom();
}
