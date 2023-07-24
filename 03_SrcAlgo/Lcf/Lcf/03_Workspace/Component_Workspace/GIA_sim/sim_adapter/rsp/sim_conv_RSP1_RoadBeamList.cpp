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
  CHANGES:         $Log: sim_conv_RSP1_RoadBeamList.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:37CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.5 2016/09/29 14:03:31CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         * default assignment Dest.RBListHead.u_StartRG = 2u; instead of 0u
  CHANGES:         Revision 1.4 2014/06/13 10:46:58CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         #include "sim_conv_rsp1_roadbeamlist.h" instead of #include "sim_conv_rsp_inputactl.h"
  CHANGES:         --- Added comments ---  berndtt1 [Jun 13, 2014 11:09:31 AM CEST]
  CHANGES:         Change Package : 221167:3 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.3 2014/05/20 17:09:04CEST Stolle, Ulf Eike (uidv1902) 
  CHANGES:         Seperate namespace for Entry and Premium
  CHANGES:         --- Added comments ---  uidv1902 [May 20, 2014 5:09:04 PM CEST]
  CHANGES:         Change Package : 226364:5 http://mks-psad:7002/im/viewissue?selection=226364
  CHANGES:         Revision 1.2 2014/05/20 15:05:57CEST Stolle, Ulf Eike (uidv1902) 
  CHANGES:         added a_RoadBeam_array_t for en
  CHANGES:         --- Added comments ---  uidv1902 [May 20, 2014 3:05:58 PM CEST]
  CHANGES:         Change Package : 226364:5 http://mks-psad:7002/im/viewissue?selection=226364
  CHANGES:         Revision 1.1 2014/05/19 10:32:22CEST Stolle, Ulf Eike (uidv1902) 
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

#include "sim_conv_rsp1_roadbeamlist.h"
#include "sim_versioninfo_impl.h"

typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef unsigned __int32 uint32;
typedef unsigned __int16 uint16;
typedef struct 			/* [Satisfies_rte sws 1191] */
{
  signed char s_Real;
  signed char s_Imag;
} t_Complex8;			/* signed 8 bit integer complex */

namespace RSP_RoadBeam_V2_PR
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

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    SignalHeader_t sSigHeader;
    AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_VersionNumber;
    unsigned long u_NofRGs;
    unsigned long u_NofDoppler;
    unsigned long u_MidDoppler;
  } RSP_t_RBHeader;			

  typedef t_Complex8                	a_SpecBeamCmplx_array_t_2[16];/* Complex beam spectrum */	/* [Satisfies_rte sws 1189] */
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned short u_PowerScaleFactor;
    a_SpecBeamCmplx_array_t_2 a_SpecBeamCmplx;
  } RSP_t_RBSpecBeamCmplx;			/* SpecBeamCmplx for RoadBeam */

  typedef RSP_t_RBSpecBeamCmplx     	RSP_t_RBSpecBeamDoppler[21];/* values for road beam estimation for one range gate */	/* [Satisfies_rte sws 1189] */

  typedef RSP_t_RBSpecBeamDoppler   	a_RoadBeam_array_t[11];/* values for road beam estimation */	/* [Satisfies_rte sws 1189] */
                          /* input data origin ACTL @vaddr:0x06030000, 0x06030100, 0x06030200, 0x06030300 @vaddr_defs: RSP1_MEAS_ID_IN_ACTL_FAR,RSP1_MEAS_ID_IN_ACTL_NEAR,RSP2_MEAS_ID_IN_ACTL_FAR,RSP2_MEAS_ID_IN_ACTL_NEAR @cycleid:RSP_ENV @vname:RSP1_InputActlFS,RSP1_InputActlNS,RSP2_InputActlFS,RSP2_InputActlNS */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    RSP_t_RBHeader RBListHead;
    a_RoadBeam_array_t a_RoadBeam;
  } RSP_RoadBeam;
}

namespace RSP_RoadBeam_V2_EN
{
  typedef t_Complex8                	a_Channels_array_t_1[4];/* Complex channel values */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned short u_PowerScaleFactor;
    a_Channels_array_t_1 a_Channels;
  } RSP_t_RBSpecBeamCmplx;			/* SpecBeamCmplx for RoadBeam */

  typedef RSP_t_RBSpecBeamCmplx     	RSP_t_RBSpecBeamDoppler[21];/* values for road beam estimation for one range gate */	/* [Satisfies_rte sws 1189] */

  typedef RSP_t_RBSpecBeamDoppler   	a_RoadBeam_array_t[21];/* values for road beam estimation */	/* [Satisfies_rte sws 1189] */

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    RSP_RoadBeam_V2_PR::RSP_t_RBHeader RBListHead;
    a_RoadBeam_array_t a_RoadBeam;
  } RSP_RoadBeam;
}

// ARS4xx RSP_t_InputActl version 2 V2           Length = 
namespace RSP_RoadBeam_V3_PR
{
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    RSP_RoadBeam_V2_PR::SignalHeader_t sSigHeader;
    unsigned long u_VersionNumber;
    unsigned short u_NofRGs;
    unsigned short u_NofDoppler;
    unsigned short u_MidDoppler;
    unsigned short u_StartRG;
  } RSP_t_RBHeader;
  
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    RSP_t_RBHeader RBListHead;
    RSP_RoadBeam_V2_PR::a_RoadBeam_array_t a_RoadBeam;
  } RSP_RoadBeam;

}

namespace RSP_RoadBeam_V3_EN
{
  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    RSP_RoadBeam_V3_PR::RSP_t_RBHeader RBListHead;
    RSP_RoadBeam_V2_EN::a_RoadBeam_array_t a_RoadBeam;
  } RSP_RoadBeam;
}


class CConvRsp1RoadBeamList : public CSimConverterBase
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

  RSP_RoadBeam_V2_PR::RSP_RoadBeam m_RB_V2_PR;
  RSP_RoadBeam_V3_PR::RSP_RoadBeam m_RB_V3_PR;
  RSP_RoadBeam_V2_EN::RSP_RoadBeam m_RB_V2_EN;
  RSP_RoadBeam_V3_EN::RSP_RoadBeam m_RB_V3_EN;

  static void InitV2_PR(RSP_RoadBeam_V2_PR::RSP_RoadBeam & Params);
  static void InitV3_PR(RSP_RoadBeam_V3_PR::RSP_RoadBeam & Params);
  static void InitV2_EN(RSP_RoadBeam_V2_EN::RSP_RoadBeam & Params);
  static void InitV3_EN(RSP_RoadBeam_V3_EN::RSP_RoadBeam & Params);

public:

  static const char *GetConverterTypeName()
  {
    return "RSP_RoadBeam";
  }

  CConvRsp1RoadBeamList(void);
  virtual ~CConvRsp1RoadBeamList(void);

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
  static CVersionInfoImpl VERSION3;
  static CVersionInfoImpl VERSION4;

  // 29.9.2016 Isn't used in this adapter:
  //enum BSWAlgoParameters
  //{
  //  ALN_RTE_BSW_IN_V2_1,
  //  ALN_RTE_BSW_IN_V2_2,
  //  ALN_RTE_BSW_IN_V4,
  //  BSW_ALGO_PARAM_VERSION_COUNT
  //};
  //static const unsigned long SUPPORTED_SIZE[BSW_ALGO_PARAM_VERSION_COUNT];
};

CVersionInfoImpl CConvRsp1RoadBeamList::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvRsp1RoadBeamList::VERSION2(0, 0, 2);
CVersionInfoImpl CConvRsp1RoadBeamList::VERSION3(0, 0, 3);

// 29.9.2016 Isn't used in this adapter:
//const unsigned long CConvRsp1RoadBeamList::SUPPORTED_SIZE[CConvRsp1RoadBeamList::BSW_ALGO_PARAM_VERSION_COUNT] =
//{
//  sizeof(RSP_RoadBeam_V2_PR::RSP_RoadBeam),
//  sizeof(RSP_RoadBeam_V3_PR::RSP_RoadBeam),
//};

CConvRsp1RoadBeamList::CConvRsp1RoadBeamList(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_RB_V2_PR(), m_RB_V3_PR(), m_RB_V2_EN(), m_RB_V3_EN()
{
}

CConvRsp1RoadBeamList::~CConvRsp1RoadBeamList(void)
{
}

void CConvRsp1RoadBeamList::InitV2_PR(RSP_RoadBeam_V2_PR::RSP_RoadBeam & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.RBListHead.u_VersionNumber = 2u;
}
void CConvRsp1RoadBeamList::InitV3_PR(RSP_RoadBeam_V3_PR::RSP_RoadBeam & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.RBListHead.u_VersionNumber = 3u;
}
void CConvRsp1RoadBeamList::InitV2_EN(RSP_RoadBeam_V2_EN::RSP_RoadBeam & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.RBListHead.u_VersionNumber = 2u;
}
void CConvRsp1RoadBeamList::InitV3_EN(RSP_RoadBeam_V3_EN::RSP_RoadBeam & Params)
{
  ::memset(&Params, 0, sizeof(Params));
  Params.RBListHead.u_VersionNumber = 3u;
}

long CConvRsp1RoadBeamList::ConvertData(
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
    else if ((ulRPortSize == sizeof(m_RB_V3_PR)) && (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V4
      RSP_RoadBeam_V3_PR::RSP_RoadBeam & Dest = m_RB_V3_PR;
      if ((ulPPortSize == sizeof(m_RB_V2_PR))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const RSP_RoadBeam_V2_PR::RSP_RoadBeam & Src = *reinterpret_cast<RSP_RoadBeam_V2_PR::RSP_RoadBeam*>(pPPortData);
        memcpy(&(Dest.RBListHead.sSigHeader),&(Src.RBListHead.sSigHeader),sizeof(RSP_RoadBeam_V2_PR::SignalHeader_t));
        memcpy(&(Dest.a_RoadBeam),(Src.a_RoadBeam),sizeof(RSP_RoadBeam_V2_PR::a_RoadBeam_array_t));
        Dest.RBListHead.u_MidDoppler =  (uint16)Src.RBListHead.u_MidDoppler;
        Dest.RBListHead.u_NofDoppler =  (uint16)Src.RBListHead.u_NofDoppler;
        Dest.RBListHead.u_NofRGs =      (uint16)Src.RBListHead.u_NofRGs;
        Dest.RBListHead.u_VersionNumber = 3u;
        Dest.RBListHead.u_StartRG = 2u;
        *pOutData = &Dest;
        ulOutSize = sizeof(Dest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(m_RB_V3_EN)) && (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Destination port of V4
      RSP_RoadBeam_V3_EN::RSP_RoadBeam & Dest = m_RB_V3_EN;
      if ((ulPPortSize == sizeof(m_RB_V2_EN))
        && ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(&VERSION2) || pProvidePortVersionInfo->Equals(&BASE_VERSION)))
      {
        const RSP_RoadBeam_V2_EN::RSP_RoadBeam & Src = *reinterpret_cast<RSP_RoadBeam_V2_EN::RSP_RoadBeam*>(pPPortData);
        memcpy(&(Dest.RBListHead.sSigHeader),&(Src.RBListHead.sSigHeader),sizeof(RSP_RoadBeam_V2_PR::SignalHeader_t));
        memcpy(&(Dest.a_RoadBeam),(Src.a_RoadBeam),sizeof(RSP_RoadBeam_V2_EN::a_RoadBeam_array_t));
        Dest.RBListHead.u_MidDoppler =  (uint16)Src.RBListHead.u_MidDoppler;
        Dest.RBListHead.u_NofDoppler =  (uint16)Src.RBListHead.u_NofDoppler;
        Dest.RBListHead.u_NofRGs =      (uint16)Src.RBListHead.u_NofRGs;
        Dest.RBListHead.u_VersionNumber = 3u;
        Dest.RBListHead.u_StartRG = 2u;
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
long CConvRsp1RoadBeamList::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    // Disclamation of check on version, only the size matters
    //if (BASE_VERSION.Equals(&requestPortVersionInfo) || VERSION2.Equals(&requestPortVersionInfo))
    //{
      if (ulRPortSize == sizeof(m_RB_V3_PR))
      {
        InitV3_PR(m_RB_V3_PR);
        *pDefaultData = &m_RB_V3_PR;
        ulDefaultSize = sizeof(m_RB_V3_PR);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_RB_V2_PR))
      {
        InitV2_PR(m_RB_V2_PR);
        *pDefaultData = &m_RB_V2_PR;
        ulDefaultSize = sizeof(m_RB_V2_PR);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_RB_V2_EN))
      {
        InitV2_EN(m_RB_V2_EN);
        *pDefaultData = &m_RB_V2_EN;
        ulDefaultSize = sizeof(m_RB_V2_EN);
        lRet = SIM_ERR_OK;
      }
      else if (ulRPortSize == sizeof(m_RB_V3_EN))
      {
        InitV3_EN(m_RB_V3_EN);
        *pDefaultData = &m_RB_V3_EN;
        ulDefaultSize = sizeof(m_RB_V3_EN);
        lRet = SIM_ERR_OK;
      }
    //}
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRsp1RoadBeamList::IsVersionCompatibleWithType(
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
    else if (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&VERSION2) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (ulRPortSize == sizeof(m_RB_V3_PR))
      {
        if (ulPPortSize == sizeof(m_RB_V2_PR))
        {
          bResult = true;
        }
      }
      else if (ulRPortSize == sizeof(m_RB_V3_EN))
      {
        if (ulPPortSize == sizeof(m_RB_V2_EN))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvRsp1RoadBeamList::AreVersionsCompatible(
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
    else if (requestPortVersionInfo.Equals(&VERSION3) || requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      if (providePortVersionInfo.Equals(&VERSION2) || providePortVersionInfo.Equals(&BASE_VERSION))
      {
        if (ulRPortSize == sizeof(m_RB_V3_PR))
        {
          if (ulPPortSize == sizeof(m_RB_V2_PR))
          {
            bResult = true;
          }
        }
        else if (ulRPortSize == sizeof(m_RB_V3_EN))
        {
          if (ulPPortSize == sizeof(m_RB_V2_EN))
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
IConverter * CreateRsp1RoadBeamListConvClass(void)
{
  return new CConvRsp1RoadBeamList();
}
