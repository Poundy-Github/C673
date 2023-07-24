/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter_em

  MODULNAME:            sim_conv_VdyCtrlData.cpp

  DESCRIPTION:          

  AUTHOR:               Manuel Olejua

  CREATION DATE:        

  VERSION:              $$

  ---*/ /*---

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_VdyCtrlData.h"
#include "sim_versioninfo_impl.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;


/* typedef VDYCtrlState_t */
#ifndef VDY_CTRL_STATE_STARTUP
  #define VDY_CTRL_STATE_STARTUP (0U)
#endif
#ifndef VDY_CTRL_STATE_INIT
  #define VDY_CTRL_STATE_INIT (1U)
#endif
#ifndef VDY_CTRL_STATE_RUNNING
  #define VDY_CTRL_STATE_RUNNING (2U)
#endif

/* typedef VDYCaliState_t */
	#ifndef   VDY_CAL_INIT
	  #define VDY_CAL_INIT	(0U)
	#endif
	#ifndef   VDY_CAL_YWR_OFFS_STST
	  #define VDY_CAL_YWR_OFFS_STST	(1U)
	#endif
	#ifndef   VDY_CAL_YWR_OFFS_DYN
	  #define VDY_CAL_YWR_OFFS_DYN	(2U)
	#endif
	#ifndef   VDY_CAL_WHS_OFFS
	  #define VDY_CAL_WHS_OFFS	(4U)
	#endif
	#ifndef   VDY_CAL_SWA_OFFS
	  #define VDY_CAL_SWA_OFFS	(16U)
	#endif
	#ifndef   VDY_CAL_LTA_OFFS
	  #define VDY_CAL_LTA_OFFS	(32U)
	#endif
	#ifndef   VDY_CAL_SWA_GRAD
	  #define VDY_CAL_SWA_GRAD	(64U)
	#endif
	#ifndef   VDY_CAL_WHS_LOAD
	  #define VDY_CAL_WHS_LOAD	(128U)
	#endif

/* typedef AlgoSignalState_t */
#ifndef AL_SIG_STATE_INIT
  #define AL_SIG_STATE_INIT (0U)
#endif
#ifndef AL_SIG_STATE_OK
  #define AL_SIG_STATE_OK (1U)
#endif


// BSW_s_VDYCtrlData_t_ARS4xx_V2_1           
namespace BSW_s_VDYCtrlData_t_ARS4xx_V2_1
{
  typedef unsigned short AlgoDataTimeStamp_t       /* Algo data time-stamp type @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned short uiTime_t                  /* Period of time in ms @min:0 @max:62000 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char VDYCaliState_t            /* Calibration inhibition states @min: 0 @max:128 @values: enum { VDY_CAL_INIT=0,VDY_CAL_SWA_GRAD=64,VDY_CAL_YWR_OFFS_STST=1,VDY_CAL_YWR_OFFS_DYN=2,VDY_CAL_SWA_OFFS=16,VDY_CAL_WHS_OFFS=4,VDY_CAL_WHS_LOAD=128,VDY_CAL_LTA_OFFS=32,} */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char VDYCtrlState_t            /* Operating modes of vdy component @min: 0 @max:2 @values: enum { VDY_CTRL_STATE_INIT=1,VDY_CTRL_STATE_STARTUP=0,VDY_CTRL_STATE_RUNNING=2,} */	/* [Satisfies_rte sws 1188] */;

  typedef struct BSW_s_VDYCtrlData_t                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    AlgoDataTimeStamp_t uiTimeStamp;
    uiTime_t CycleTime;
    VDYCaliState_t CaliMode;
    VDYCtrlState_t CtrlMode;
  } BSW_s_VDYCtrlData_t;                             
}

// BSW_s_VDYCtrlData_t_ARS4xx_V2_1          
namespace BSW_s_VDYCtrlData_t_ARS4xx_V2_2
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

  typedef struct BSW_s_VDYCtrlData_t                 /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_InterfaceVersion;
    SignalHeader_t sSigHeader;
    BSW_s_VDYCtrlData_t_ARS4xx_V2_1::uiTime_t CycleTime;
    BSW_s_VDYCtrlData_t_ARS4xx_V2_1::VDYCaliState_t CaliMode;
    BSW_s_VDYCtrlData_t_ARS4xx_V2_1::VDYCtrlState_t CtrlMode;
  } BSW_s_VDYCtrlData_t;                             
}


class CConvVdyCtrlData : public CSimConverterBase
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

  BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t m_BufV2_1;
  BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t m_BufV2_2;

  static void InitV2_1(BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t & Params);
  static void InitV2_2(BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t & Params);

public:

  static const TCHAR *GetConverterTypeName()
  {
    return TEXT("VdyCtrlData");
  }

  CConvVdyCtrlData(void);
  virtual ~CConvVdyCtrlData(void);

  const TCHAR *GetTypeName()
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
  /*static CVersionInfoImpl VERSION3;*/

  enum BSWAlgoParameters
  {
    ALN_RTE_BSW_IN_V2_1,
    ALN_RTE_BSW_IN_V2_2,
    //ALN_RTE_BSW_IN_V3,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

};

CVersionInfoImpl CConvVdyCtrlData::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvVdyCtrlData::VERSION2(0, 0, 2);
//CVersionInfoImpl CConvVdyCtrlData::VERSION3(0, 0, 3);

const unsigned long CConvVdyCtrlData::SUPPORTED_SIZE[CConvVdyCtrlData::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t),
  sizeof(BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t),

};

CConvVdyCtrlData::CConvVdyCtrlData(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV2_1(), m_BufV2_2()
{
}

CConvVdyCtrlData::~CConvVdyCtrlData(void)
{
}

void CConvVdyCtrlData::InitV2_1(BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 2u;
  Params.uiTimeStamp                          = 0; 
  Params.CycleTime                            = 0;
  Params.CaliMode                             = VDY_CAL_INIT;
  Params.CtrlMode                             = VDY_CTRL_STATE_STARTUP;
}

void CConvVdyCtrlData::InitV2_2(BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_InterfaceVersion = 2u;
  // Signal Header
  Params.sSigHeader.uiTimeStamp                  = 0;
  Params.sSigHeader.uiMeasurementCounter         = 0;
  Params.sSigHeader.uiCycleCounter               = 0;
  Params.sSigHeader.eSigStatus                   = AL_SIG_STATE_INIT;
  Params.CycleTime                               = 0;
  Params.CaliMode                                = VDY_CAL_INIT;
  Params.CtrlMode                                = VDY_CTRL_STATE_STARTUP;
}

long CConvVdyCtrlData::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<uint32*>(pPPortData)):(0);
  // First decide which version we are converting to
  if ((ulRPortSize == sizeof(m_BufV2_2)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V2_2
    BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t & Dest = m_BufV2_2;
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
      const BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t & Src = *reinterpret_cast<BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t*>(pPPortData);
      Dest.u_InterfaceVersion              = 2u;
      Dest.sSigHeader.uiTimeStamp          = 0;
      Dest.sSigHeader.uiCycleCounter       = 0;
      Dest.sSigHeader.uiMeasurementCounter = 0;
      Dest.sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
      Dest.CycleTime                       = Src.CycleTime;
      Dest.CaliMode                        = Src.CaliMode;
      Dest.CtrlMode                        = Src.CtrlMode;
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  else if ((ulRPortSize == sizeof(m_BufV2_1)) && ((requestPortVersionInfo.Equals(&VERSION2)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V2_1
    BSW_s_VDYCtrlData_t_ARS4xx_V2_1::BSW_s_VDYCtrlData_t & Dest = m_BufV2_1;
    if ((ulPPortSize == sizeof(m_BufV2_2))
      && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      && ((uDataVer == 2u) || (uDataVer == 0)))
    {
      const BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t & Src = *reinterpret_cast<BSW_s_VDYCtrlData_t_ARS4xx_V2_2::BSW_s_VDYCtrlData_t*>(pPPortData);
      Dest.u_InterfaceVersion              = 2u;
      Dest.uiTimeStamp                     = (short)Src.sSigHeader.uiTimeStamp;
      Dest.CycleTime                       = Src.CycleTime;
      Dest.CaliMode                        = Src.CaliMode;
      Dest.CtrlMode                        = Src.CtrlMode;
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
long CConvVdyCtrlData::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if (BASE_VERSION.Equals(&requestPortVersionInfo) || VERSION2.Equals(&requestPortVersionInfo))
    {
      if (ulRPortSize == sizeof(m_BufV2_2))
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
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvVdyCtrlData::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(m_BufV2_1))
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
      else if (ulRPortSize == sizeof(m_BufV2_2))
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
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvVdyCtrlData::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (providePortVersionInfo.Equals(&VERSION2) || providePortVersionInfo.Equals(&BASE_VERSION))
      {
        if (ulRPortSize == sizeof(m_BufV2_1))
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
        else if (ulRPortSize == sizeof(m_BufV2_2))
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
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateVdyCtrlDataConvClass(void)
{
  return new CConvVdyCtrlData();
}