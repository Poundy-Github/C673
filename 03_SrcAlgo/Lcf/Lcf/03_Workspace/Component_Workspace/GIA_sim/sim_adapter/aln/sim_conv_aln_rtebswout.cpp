/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_rtebswout

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   18.09.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_rtebswout.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:50CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 1.1 2013/09/19 15:06:49CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_rtebswout.h"
#include "sim_versioninfo_impl.h"

// typedef float float32;
typedef unsigned __int8 boolean/*, uint8*/;
// typedef unsigned __int32 uint32;

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif

/* typedef e_AlnState_t */
#ifndef   AlnStateNormal
  #define AlnStateNormal (0U)
#endif

// ARS4xx ALN_BSWOut_t version 2 V1               Length = 32
namespace ALN_BSWOut_t_ARS4xx_V2_1
{
  typedef unsigned char AlgoErrorState_t         /* Algo error state enumeration @min: 0 @max:2 @values: enum { AL_ERR_STATE_UNKNOWN=0,AL_ERR_STATE_ACTIVE=1,AL_ERR_STATE_INACTIVE=2,} */ /* [Satisfies_rte sws 1188] */;
  typedef AlgoErrorState_t u_AngleDevTooHigh_array_t[2];/* angle deviations to high */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_AzimuthLeft_array_t[2];/* sensor is rotated too far to the right */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_AzimuthRight_array_t[2];/* sensor is rotated too far to the left */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_ElevationHigh_array_t[2];/* sensor is rotated to low */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_ElevationLow_array_t[2];/* sensor is rotated to high */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_MaxPowerLow_array_t[2];/* power of eol target to low */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_MovingInterf_array_t[2];/* moving interferer during eol */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_PathCompTooHigh_array_t[2];/* path compensations to high */ /* [Satisfies_rte sws 1189] */
  typedef AlgoErrorState_t u_StationaryInterferer_array_t[2];/* stationary interferer during eol */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char u_Dummy_array_t_4[1];    /* dummy for 4-byte alignment */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char u_Dummy_array_t_5[2];    /* dummy for 4-byte alignment */ /* [Satisfies_rte sws 1189] */
  typedef unsigned char u_AlnState_t             /* state of alignment @min: 0 @max:2 @values: enum { AlnStateFinished=1,AlnStateNormal=0,AlnStateFailed=2,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct                                 /* [Satisfies_rte sws 1191] */
  {
    AlgoErrorState_t u_SoftwareBug;
    u_ElevationLow_array_t u_ElevationLow;
    u_ElevationHigh_array_t u_ElevationHigh;
    u_AzimuthLeft_array_t u_AzimuthLeft;
    u_AzimuthRight_array_t u_AzimuthRight;
    u_MaxPowerLow_array_t u_MaxPowerLow;
    u_MovingInterf_array_t u_MovingInterf;
    u_StationaryInterferer_array_t u_StationaryInterferer;
    u_PathCompTooHigh_array_t u_PathCompTooHigh;
    u_AngleDevTooHigh_array_t u_AngleDevTooHigh;
    u_Dummy_array_t_4 u_Dummy;
  } ALN_Errors_t;                                /* errors from ALN which can be connected to DEM events */

  typedef struct ALN_BswOut_t
  {
    unsigned long u_VersionNumber;
    ALN_Errors_t ALN_Errors;
    float f_Progress;
    boolean b_SensorDeadjusted;
    u_AlnState_t u_AlnState;
    u_Dummy_array_t_5 u_Dummy;
  } ALN_BswOut_t;

} // end of namespace ALN_BSWOut_t_ARS4xx_V2_1

// ARS4xx ALN_BSWOut_t version 2 V2              Length = 48
namespace ALN_BSWOut_t_ARS4xx_V2_2
{
  typedef unsigned long AlgoDataTimeStamp_t      /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned short AlgoCycleCounter_t      /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t        /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;
  typedef unsigned char e_AlnState_t             /* state of alignment @min: 0 @max:2 @values: enum { AlnStateFinished=1,AlnStateNormal=0,AlnStateFailed=2,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t                  /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                              /* Common header for all structured data types */

  typedef struct ALN_BSWOut_t                    /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    SignalHeader_t sSigHeader;
    ALN_BSWOut_t_ARS4xx_V2_1::ALN_Errors_t ALN_Errors;
    float f_Progress;
    float f_EolPlateSnr;
    boolean b_SensorDeadjusted;
    e_AlnState_t e_AlnState;
    ALN_BSWOut_t_ARS4xx_V2_1::u_Dummy_array_t_5 u_Dummy;
  } ALN_BSWOut_t;                                /* output to base software @vaddr:0x20510000, 0x20511000, 0x20512000 @vaddr_defs: ALN_MEAS_ID_BSW_OUT_FAR,ALN_MEAS_ID_BSW_OUT_NEAR,ALN_MEAS_ID_BSW_OUT_CLUSTERS @cycleid:ALN_ENV @vname:ALN_RteBswOutFar,ALN_RteBswOutNear,ALN_RteBswOutClusters */

} // end of namespace ALN_BSWOut_t_ARS4xx_V2_2


class CConvAlnBswOut : public CSimConverterBase
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

  ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t m_BufV2_1;
  ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t m_BufV2_2;

  static void InitV2_1(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t & Params);
  static void InitV2_2(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "AlnRteBswInput";
  }

  CConvAlnBswOut(void);
  virtual ~CConvAlnBswOut(void);

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

  enum BSWAlgoParameters
  {
    ALN_RTE_BSW_IN_V2_1,
    ALN_RTE_BSW_IN_V2_2,
    //ALN_RTE_BSW_IN_V3,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

};

CVersionInfoImpl CConvAlnBswOut::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnBswOut::VERSION2(0, 0, 2);

const unsigned long CConvAlnBswOut::SUPPORTED_SIZE[CConvAlnBswOut::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t),
  sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t)
};

CConvAlnBswOut::CConvAlnBswOut(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2_1(), m_BufV2_2()
{
  InitV2_1(m_BufV2_1);
  InitV2_2(m_BufV2_2);
}

CConvAlnBswOut::~CConvAlnBswOut(void)
{
}

void CConvAlnBswOut::InitV2_1(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 1u;
  // Aln State
  Params.u_AlnState                              = AlnStateNormal;
}

void CConvAlnBswOut::InitV2_2(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber                         = 2u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  // Aln State
  Params.e_AlnState                              = AlnStateNormal;
}

long CConvAlnBswOut::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V2
    ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t & Dest = /*reinterpret_cast<ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t &>*/(m_BufV2_2);
    if ((ulPPortSize == ulRPortSize)
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else if ((ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      const ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t & Src = *reinterpret_cast<ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t*>(pPPortData);
      Dest.u_VersionNumber                 = 2u;
      Dest.sSigHeader.uiTimeStamp          = 0;
      Dest.sSigHeader.uiCycleCounter       = 0;
      Dest.sSigHeader.uiMeasurementCounter = 0;
      Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
      Dest.e_AlnState                      = Src.u_AlnState;
      Dest.b_SensorDeadjusted              = Src.b_SensorDeadjusted;
      Dest.f_EolPlateSnr                   = 0.f;
      Dest.f_Progress                      = Src.f_Progress;
      Dest.u_Dummy[0]                      = Src.u_Dummy[0];
      Dest.u_Dummy[1]                      = Src.u_Dummy[1];
      memcpy(&(Dest.ALN_Errors), &(Src.ALN_Errors), sizeof(Src.ALN_Errors));
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V1
    ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t & Dest = /*reinterpret_cast<ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t &>*/(m_BufV2_1);;
    if ((ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      const ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t & Src = *reinterpret_cast<ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t*>(pPPortData);
      Dest.u_VersionNumber                 = 1u;
      Dest.u_AlnState                      = Src.e_AlnState;
      Dest.b_SensorDeadjusted              = Src.b_SensorDeadjusted;
      Dest.f_Progress                      = Src.f_Progress;
      Dest.u_Dummy[0]                      = Src.u_Dummy[0];
      Dest.u_Dummy[1]                      = Src.u_Dummy[1];
      memcpy(&(Dest.ALN_Errors), &(Src.ALN_Errors), sizeof(Src.ALN_Errors));
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
long CConvAlnBswOut::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV2_2(m_BufV2_2);
      *pDefaultData = &m_BufV2_2;
      ulDefaultSize = sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (VERSION2.Equals(&requestPortVersionInfo))))
    {
      InitV2_1(m_BufV2_1);
      *pDefaultData = &m_BufV2_1;
      ulDefaultSize = sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t);
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
bool CConvAlnBswOut::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
      {
        if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
        {
          bResult = true;
        }
        else if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
        {
          bResult = true;
        }
      }
      else if (ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
      {
        if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
        {
          bResult = true;
        }
        else if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvAlnBswOut::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
      {
        if (providePortVersionInfo.Equals(&VERSION2) || providePortVersionInfo.Equals(&BASE_VERSION))
        {
          if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
          {
            bResult = true;
          }
          else if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
          {
            bResult = true;
          }
        }
      }
      else if (ulRPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
      {
        if (providePortVersionInfo.Equals(&VERSION2) || providePortVersionInfo.Equals(&BASE_VERSION))
        {
          if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_1::ALN_BswOut_t))
          {
            bResult = true;
          }
          else if (ulPPortSize == sizeof(ALN_BSWOut_t_ARS4xx_V2_2::ALN_BSWOut_t))
          {
            bResult = true;
          }
        }
      }
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateAlnBswOutConvClass(void)
{
  return new CConvAlnBswOut();
}
