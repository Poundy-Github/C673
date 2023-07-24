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
  CHANGES:         $Log: sim_conv_RSP1_syncref.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:38CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.3 2014/09/17 15:46:04CEST Manea, Gabriela (ManeaG) 
  CHANGES:         Included sim_adapter_cfg.h
  CHANGES:         - Added comments -  ManeaG [Sep 17, 2014 3:46:05 PM CEST]
  CHANGES:         Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
  CHANGES:         Revision 1.2 2014/07/01 14:30:31CEST Engels, Florian (engelsf) 
  CHANGES:         Added monopulse look up table.
  CHANGES:         --- Added comments ---  engelsf [Jul 1, 2014 2:30:31 PM CEST]
  CHANGES:         Change Package : 214850:1 http://mks-psad:7002/im/viewissue?selection=214850
  CHANGES:         Revision 1.1 2014/05/19 10:32:36CEST Stolle, Ulf Eike (uidv1902) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj
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
#include "sim_adapter_cfg.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;

namespace RSP1_SyncRef_V0
{
  typedef unsigned short AlgoCycleCounter_t        /* Algo cycle counter @min:0 @max:65535 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t       /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */	/* [Satisfies_rte sws 1188] */;
  typedef unsigned char AlgoSignalState_t         /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */	/* [Satisfies_rte sws 1188] */;
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;


  typedef struct 
  {
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
    SignalHeader_t RspInputActl;		
    SignalHeader_t RhcEventConfigRsp1;		
    SignalHeader_t p_RhcHwConfig;
#if (SRR_SWITCH == SWITCH_OFF)
    SignalHeader_t VehicleDynData;
#endif
  } RSP1_t_SyncRef;
}


namespace RSP1_SyncRef_V1
{
  typedef struct 
  {
    uint32 u_VersionNumber;
    RSP1_SyncRef_V0::SignalHeader_t sSigHeader;
    RSP1_SyncRef_V0::SignalHeader_t RspInputActl;		
    RSP1_SyncRef_V0::SignalHeader_t RhcEventConfigRsp1;		
    RSP1_SyncRef_V0::SignalHeader_t p_RhcHwConfig;
#if (SRR_SWITCH == SWITCH_OFF)
    RSP1_SyncRef_V0::SignalHeader_t VehicleParData;
    RSP1_SyncRef_V0::SignalHeader_t VehicleDynData;
#endif
  } RSP1_t_SyncRef;
}


namespace RSP1_SyncRef_V2
{
  typedef struct 
  {
    uint32 u_VersionNumber;
    RSP1_SyncRef_V0::SignalHeader_t sSigHeader;
    RSP1_SyncRef_V0::SignalHeader_t RspInputActl;		
    RSP1_SyncRef_V0::SignalHeader_t RhcEventConfigRsp1;		
    RSP1_SyncRef_V0::SignalHeader_t p_RhcHwConfig;
#if (SRR_SWITCH == SWITCH_OFF)
    RSP1_SyncRef_V0::SignalHeader_t MonopulsePhaseLut;
    RSP1_SyncRef_V0::SignalHeader_t VehicleParData;
    RSP1_SyncRef_V0::SignalHeader_t VehicleDynData;
#endif
  } RSP1_t_SyncRef;
}




class CConvRsp1SyncRef : public CSimConverterBase
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

  RSP1_SyncRef_V0::RSP1_t_SyncRef m_SyncRef_V0;
  RSP1_SyncRef_V1::RSP1_t_SyncRef m_SyncRef_V1;
  RSP1_SyncRef_V2::RSP1_t_SyncRef m_SyncRef_V2;
  
  static void InitV0(RSP1_SyncRef_V0::RSP1_t_SyncRef & Params);
  static void InitV1(RSP1_SyncRef_V1::RSP1_t_SyncRef & Params);
  static void InitV2(RSP1_SyncRef_V2::RSP1_t_SyncRef & Params);
  

public:

  static const char *GetConverterTypeName()
  {
    return "RSP1_SyncRef";
  }

  CConvRsp1SyncRef(void);
  virtual ~CConvRsp1SyncRef(void);

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
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;

  enum BSWAlgoParameters
  {
    ALN_RTE_BSW_IN_V2_1,
    ALN_RTE_BSW_IN_V2_2,
    ALN_RTE_BSW_IN_V4,
    BSW_ALGO_PARAM_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];

};

CVersionInfoImpl CConvRsp1SyncRef::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRsp1SyncRef::VERSION1(0, 0, 1);
CVersionInfoImpl CConvRsp1SyncRef::VERSION2(0, 0, 2);

const unsigned long CConvRsp1SyncRef::SUPPORTED_SIZE[CConvRsp1SyncRef::BSW_ALGO_PARAM_VERSION_COUNT] =
{
  sizeof(RSP1_SyncRef_V0::RSP1_t_SyncRef),
  sizeof(RSP1_SyncRef_V1::RSP1_t_SyncRef),
  sizeof(RSP1_SyncRef_V2::RSP1_t_SyncRef)
};

CConvRsp1SyncRef::CConvRsp1SyncRef(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_SyncRef_V0(), m_SyncRef_V1()
{
}

CConvRsp1SyncRef::~CConvRsp1SyncRef(void)
{
}

void CConvRsp1SyncRef::InitV0(RSP1_SyncRef_V0::RSP1_t_SyncRef & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 0;
}

void CConvRsp1SyncRef::InitV1(RSP1_SyncRef_V1::RSP1_t_SyncRef & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 1u;
  // Signal Header
}

void CConvRsp1SyncRef::InitV2(RSP1_SyncRef_V2::RSP1_t_SyncRef & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.u_VersionNumber = 2u;
  // Signal Header
}

long CConvRsp1SyncRef::ConvertData(
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
    else if ((ulRPortSize == sizeof(m_SyncRef_V1)) && (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V4
      RSP1_SyncRef_V1::RSP1_t_SyncRef & Dest = m_SyncRef_V1;
      if ((ulPPortSize == sizeof(m_SyncRef_V0))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION1) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const RSP1_SyncRef_V0::RSP1_t_SyncRef & Src = *reinterpret_cast<RSP1_SyncRef_V0::RSP1_t_SyncRef*>(pPPortData);
        Dest.u_VersionNumber = 1u;
        memcpy( &(Dest.sSigHeader),         &(Src.sSigHeader),          sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RspInputActl),       &(Src.RspInputActl),        sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RhcEventConfigRsp1), &(Src.RhcEventConfigRsp1),  sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.p_RhcHwConfig),      &(Src.p_RhcHwConfig),       sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
#if (SRR_SWITCH == SWITCH_OFF)
        memcpy( &(Dest.VehicleDynData),     &(Src.VehicleDynData),      sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memset( &(Dest.VehicleParData), 0,  sizeof(RSP1_SyncRef_V0::SignalHeader_t)  );
#endif
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(m_SyncRef_V2)) && (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      RSP1_SyncRef_V2::RSP1_t_SyncRef & Dest = m_SyncRef_V2;
      if ((ulPPortSize == sizeof(m_SyncRef_V0))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const RSP1_SyncRef_V0::RSP1_t_SyncRef & Src = *reinterpret_cast<RSP1_SyncRef_V0::RSP1_t_SyncRef*>(pPPortData);
        Dest.u_VersionNumber = 1u;
        memcpy( &(Dest.sSigHeader),         &(Src.sSigHeader),          sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RspInputActl),       &(Src.RspInputActl),        sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RhcEventConfigRsp1), &(Src.RhcEventConfigRsp1),  sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.p_RhcHwConfig),      &(Src.p_RhcHwConfig),       sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
#if (SRR_SWITCH == SWITCH_OFF)
        memcpy( &(Dest.VehicleDynData),     &(Src.VehicleDynData),      sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memset( &(Dest.VehicleParData),     0,                          sizeof(RSP1_SyncRef_V0::SignalHeader_t)  );
        memset( &(Dest.MonopulsePhaseLut),  0,                          sizeof(RSP1_SyncRef_V0::SignalHeader_t)  );
#endif
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
      else if((ulPPortSize == sizeof(m_SyncRef_V1))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const RSP1_SyncRef_V1::RSP1_t_SyncRef & Src = *reinterpret_cast<RSP1_SyncRef_V1::RSP1_t_SyncRef*>(pPPortData);
        Dest.u_VersionNumber = 2u;
        memcpy( &(Dest.sSigHeader),         &(Src.sSigHeader),          sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RspInputActl),       &(Src.RspInputActl),        sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.RhcEventConfigRsp1), &(Src.RhcEventConfigRsp1),  sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.p_RhcHwConfig),      &(Src.p_RhcHwConfig),       sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
#if (SRR_SWITCH == SWITCH_OFF)
        memcpy( &(Dest.VehicleDynData),     &(Src.VehicleDynData),      sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memcpy( &(Dest.VehicleParData),     &(Src.VehicleParData),      sizeof(RSP1_SyncRef_V0::SignalHeader_t) );
        memset( &(Dest.MonopulsePhaseLut),  0,                          sizeof(RSP1_SyncRef_V0::SignalHeader_t)  );
#endif
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
long CConvRsp1SyncRef::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Disclamation of check on version, only the size matters
    //if (BASE_VERSION.Equals(&requestPortVersionInfo) || VERSION2.Equals(&requestPortVersionInfo))
    //{
      if (ulRPortSize == sizeof(m_SyncRef_V1))
      {
        InitV1(m_SyncRef_V1);
        *pDefaultData = &m_SyncRef_V1;
        ulDefaultSize = sizeof(m_SyncRef_V1);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_SyncRef_V0))
      {
        InitV0(m_SyncRef_V0);
        *pDefaultData = &m_SyncRef_V0;
        ulDefaultSize = sizeof(m_SyncRef_V0);
        lRet = SIM_ERR_OK;
      }
       else if (ulRPortSize == sizeof(m_SyncRef_V2))
      {
        InitV2(m_SyncRef_V2);
        *pDefaultData = &m_SyncRef_V2;
        ulDefaultSize = sizeof(m_SyncRef_V2);
        lRet = SIM_ERR_OK;
      }
    //}
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRsp1SyncRef::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal, then always compatible
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else if (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(m_SyncRef_V1))
      {
        if (ulPPortSize == sizeof(m_SyncRef_V0))
        {
          bResult = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(m_SyncRef_V2))
      {
        if ((ulPPortSize == sizeof(m_SyncRef_V1)) || (ulPPortSize == sizeof(m_SyncRef_V0)))
        {
           bResult = true;
        }
        
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRsp1SyncRef::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    // If ports equal, then always compatible
    if (ulRPortSize == ulPPortSize)
    {
      bResult = true;
    }
    else if (requestPortVersionInfo.Equals(&VERSION1) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (providePortVersionInfo.Equals(&BASE_VERSION))
      {
        if (ulRPortSize == sizeof(m_SyncRef_V1))
        {
          if (ulPPortSize == sizeof(m_SyncRef_V0))
          {
            bResult = true;
          }
        }
      }

    }
    else if (requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (providePortVersionInfo.Equals(&BASE_VERSION))
      {
        if (ulRPortSize == sizeof(m_SyncRef_V2))
        {
          if ((ulPPortSize == sizeof(m_SyncRef_V0)) || (ulPPortSize == sizeof(m_SyncRef_V0)))
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
IConverter * CreateRsp1SyncRefConvClass(void)
{
  return new CConvRsp1SyncRef();
}
