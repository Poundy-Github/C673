/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter

  MODULNAME:       sim_conv_rsp_specbeamcmplxlist.cpp

  DESCRIPTION:     Adapter/Converter for SpecBeamCmplxList

  AUTHOR:          Thomas Berndt

  CREATION DATE:   16.09.2013

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_rsp_specbeamcmplxlist.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:15:32CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:         Revision 1.1.1.10 2017/01/19 13:43:20CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         * adaption of the order of the complex channel values of ARS510 A-Sample is not made for B-Sample data any more. Detected by the version number u_VersionNumber
  CHANGES:         Revision 1.1.1.9 2016/10/10 14:45:50CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + IsPortSupported checks also VERSION1 and VERSION2
  CHANGES:         Revision 1.1.1.8 2016/09/13 10:16:20CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Update Simulation adapters and Simulation plugin for ARS510
  CHANGES:         Revision 1.1.1.7 2016/08/23 10:59:37CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + ARS510 V100
  CHANGES:         Revision 1.1.1.6 2015/04/02 11:50:42CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         removed init function for precluster v1 after recognizing that member revisions of other files were not correctly set
  CHANGES:         - Added comments -  uidv7098 [Apr 2, 2015 11:50:42 AM CEST]
  CHANGES:         Change Package : 321616:1 http://mks-psad:7002/im/viewissue?selection=321616
  CHANGES:         Revision 1.1.1.5 2015/04/02 11:15:58CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         readded init for v1
  CHANGES:         --- Added comments ---  uidv7098 [Apr 2, 2015 11:15:58 AM CEST]
  CHANGES:         Change Package : 321616:1 http://mks-psad:7002/im/viewissue?selection=321616
  CHANGES:         Revision 1.1.1.4 2014/12/12 08:27:11CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         * Clean up of the Entry paths, joint and switched by compiler defines
  CHANGES:         --- Added comments ---  berndtt1 [Dec 12, 2014 9:35:44 AM CET]
  CHANGES:         Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.1.1.3 2014/08/13 16:30:42CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:         --- Added comments ---  berndtt1 [Aug 13, 2014 4:31:45 PM CEST]
  CHANGES:         Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:         Revision 1.1.1.2 2014/07/02 08:48:15CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + V3_PR Near Array Size 960 -> 640
  CHANGES:         --- Added comments ---  berndtt1 [Jul 2, 2014 8:56:41 AM CEST]
  CHANGES:         Change Package : 244114:2 http://mks-psad:7002/im/viewissue?selection=244114
  CHANGES:         Revision 1.1.1.1 2014/03/21 11:17:23CET Stolle, Ulf Eike (uidv1902) 
  CHANGES:         added adapter from SpecBeamCmplxList V1Premium to SpecBeamCmplxList V1Premium_V2
  CHANGES:         there are big differences between Pr and En List
  CHANGES:         --- Added comments ---  uidv1902 [Mar 21, 2014 11:17:23 AM CET]
  CHANGES:         Change Package : 211391:4 http://mks-psad:7002/im/viewissue?selection=211391
  CHANGES:         Revision 1.1 2013/09/18 16:30:47CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_conv_rsp_specbeamcmplxlist.h"
#include <math.h>
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"
#include "interface_RSP1_PreClusterList_ars400.h"
#include "interface_rsp_specbeamcmplxlist.h"

#define _MINI(x,y) (x<y?x:y)

class CConvRSPSpecBeamCmplxList : public CSimConverterBase
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

  RSP_SPECBEAMCMPLXLIST_GEN::RSP_t_SpecBeamCmplxListNS m_NearGen;
  RSP_SPECBEAMCMPLXLIST_GEN::RSP_t_SpecBeamCmplxListFS m_FarGen;
  RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS m_FarV0;
  RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS m_NearV0;
  RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS m_NearV1;
  RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS m_FarV1PR;
  RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS m_NearV1PR;
  RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS m_FarV2PR;
  RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS m_NearV2PR;
  RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS m_NearV3PR;
  RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS m_NearV2_1EN;
  RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS m_NearV2_2EN;
  RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS m_NearArs5xxV1;

  void InitPreCluster(RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V2::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V0::NumFarPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V0::NumNearPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V1::NumFarPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V1::NumNearPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V2::NumFarPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V2::NumNearPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitSpecBeamCmplx(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplx & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitSpecBeamCmplx(RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplx & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  //void InitSpecBeamCmplx(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplx & Dest) const
  //{
  //  ::memset(&Dest, 0, sizeof(Dest));
  //};
  void InitSpecBeamCmplx(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplx & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitSpecBeamCmplx(RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplx & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V0::NumFarSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V1::NumNearSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };
  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V1_PR::NumNearSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V1_PR::NumFarSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V2_PR::NumNearSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V2_PR::NumFarSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP_SPECBEAMCMPLXLIST_V3_PR::NumNearSpecBeamCmplxList; i++)
    {
      InitSpecBeamCmplx(Dest.a_SpecBeamCmplx[i]);
    }
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_GEN::RSP_t_SpecBeamCmplxListNS & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitSpecBeamCmplxList(RSP_SPECBEAMCMPLXLIST_GEN::RSP_t_SpecBeamCmplxListFS & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  template <typename T> static void InitSpecBeamCmplxList (T & Dest, unsigned long uVersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.Header.u_VersionNumber = uVersionNumber;
  }

public:

  CConvRSPSpecBeamCmplxList(void): CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT),
    m_NearGen(), m_FarGen(),
    m_FarV0(), m_NearV0(),
    m_FarV2PR(), m_NearV2PR(), m_FarV1PR(), m_NearV1PR(), m_NearV3PR()
  {
    InitSpecBeamCmplxList(m_NearGen);
    InitSpecBeamCmplxList(m_FarGen);
    InitSpecBeamCmplxList(m_NearV0);
    InitSpecBeamCmplxList(m_FarV0);
    InitSpecBeamCmplxList(m_FarV2PR);
    InitSpecBeamCmplxList(m_NearV2PR);
    InitSpecBeamCmplxList(m_FarV1PR);
    InitSpecBeamCmplxList(m_NearV1PR);
    InitSpecBeamCmplxList(m_NearV3PR);
    InitSpecBeamCmplxList(m_NearV2_1EN, 2U);
    InitSpecBeamCmplxList(m_NearV2_2EN, 2U);
  };

  // Not implemented copy constructor to get linker error
  CConvRSPSpecBeamCmplxList(const CConvRSPSpecBeamCmplxList & init);

  virtual ~CConvRSPSpecBeamCmplxList(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char* GetTypeName(void)
  {
    return "RSP_SpecBeamCmplxList";
  };

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo * pPortVersion) const
  {
    if (((pPortVersion == NULL) || (pPortVersion->Equals(&BASE_VERSION)) || (pPortVersion->Equals(&VERSION1)) || (pPortVersion->Equals(&VERSION2))) &&
      ((ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear))))
    {
      return true;
    }
    return false;
  };

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long& ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void** pDefaultData, unsigned long& ulDefaultSize);

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize);

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo);
private:

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION1;
  static CVersionInfoImpl VERSION2;
  // Following Version Information are not used at the moment:
  static CVersionInfoImpl RSP1V1;

  //enum eFPGAStaticPeakListVersion
  //{
  //  FPGA_STATIC_PEAK_VERSION_COUNT
  //};
  //static unsigned long SUPPORTED_SIZE[FPGA_STATIC_PEAK_VERSION_COUNT];

  //static const CVersionInfoImpl * const FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT];
};

CVersionInfoImpl  CConvRSPSpecBeamCmplxList::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvRSPSpecBeamCmplxList::VERSION1(0, 0, 1);
CVersionInfoImpl  CConvRSPSpecBeamCmplxList::VERSION2(0, 0, 2);
CVersionInfoImpl  CConvRSPSpecBeamCmplxList::RSP1V1(0, 0, 1);
//
//unsigned long CConvRSPSpecBeamCmplxList::SUPPORTED_SIZE[CConvFPGAStaticPeakList::FPGA_STATIC_PEAK_VERSION_COUNT]=
//{
//};
//
//const CVersionInfoImpl * const CConvRSPSpecBeamCmplxList::FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT] =
//{
//  &BASE_VERSION,
//  &RSP_CTX_VERSION_V0,
//  &RSP_CTX_VERSION_V1,
//  &RSP_CTX_VERSION_V1_1,
//  &RSP_CTX_VERSION_V2
//};

// convert all to v0 of RSP_SPECBEAMCMPLXLIST_V0
__inline void v_Convert_v0_to_v0_NEAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V0::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v0_to_v0_FAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V0::NumFarPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v1_to_v0_NEAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V1::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v1_to_v0_FAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V1::NumFarPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v2_to_v0_NEAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  pDest->u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V2::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v2_to_v0_FAR (RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc)
{
  // copy consistent header part
  pDest->u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumFarSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V2::NumFarPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

// end of convert all to v0

// convert all to v1 of RSP_SPECBEAMCMPLXLIST_V0
__inline void v_Convert_v0_to_v1_NEAR (RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V0::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v1_to_v1_NEAR (RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V1::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v2_to_v1_NEAR (RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc)
{
  // copy consistent header part
  pDest->u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE)
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1::NumNearSpecBeamCmplxList, RSP1_PRECLUSTERLIST_V2::NumNearPreClusters); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(a_BeamSpecCmplx_array_t));
  }
}

__inline void v_Convert_v0_to_v1_NEAR (RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  pDest->u_VersionNumber = pSrc->u_VersionNumber;
  pDest->sSigHeader.eSigStatus = pSrc->sSigHeader.eSigStatus;
  pDest->sSigHeader.uiTimeStamp = pSrc->sSigHeader.uiTimeStamp;
  pDest->sSigHeader.uiMeasurementCounter = pSrc->sSigHeader.uiMeasurementCounter;
  pDest->sSigHeader.uiCycleCounter = pSrc->sSigHeader.uiCycleCounter;

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V0::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V1::NumNearSpecBeamCmplxList); i++)
  {
    //pDest->a_SpecBeamCmplx[i].u_PowerScaleFactor = pSrc->a_Clusters[i].CmplxRatioMonop;
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_SpecBeamCmplx[i].a_SpecBeamCmplx, sizeof(a_BeamSpecCmplx_array_t));
    memset(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplxMonopulse, 0, sizeof(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplxMonopulse));
  }
}
__inline void SetPowScaleFactorV1PRtoV2PR(float32* p_fPowScaleFactor , const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplx * const pSrc )
{
  float32 f_PowLinCP16Max,f_tmpCmplx,f_Re,f_Im;
  /*Find Maxima of Complex value*/
  f_Re = ((float32)pSrc->a_SpecBeamCmplx[0].s_Real);
  f_Im = ((float32)pSrc->a_SpecBeamCmplx[0].s_Imag);
  f_PowLinCP16Max = (f_Re*f_Re) + (f_Im*f_Im);
  for (int ii = 1; ii<16; ii++ )
  {
    f_Re = ((float32)pSrc->a_SpecBeamCmplx[ii].s_Real);
    f_Im = ((float32)pSrc->a_SpecBeamCmplx[ii].s_Imag);

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
    float32 f_PowLin, f_ScaleL;
    f_PowLin = powf(2.0f,(float32)(u_PowLog2Max*0.00390625f));
    f_ScaleL = f_PowLin/f_PowLinCP16Max;
    f_ScaleL = sqrt(f_ScaleL);
    *p_fPowScaleFactor = f_ScaleL;
  }
  else
  {
    *p_fPowScaleFactor = 0.f;
  }
}

__inline void v_Convert_v1pr_to_v2pr_NEAR (RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1_PR::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V2_PR::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_SpecBeamCmplx[i].a_SpecBeamCmplx, sizeof(a_BeamSpecCmplx_array_t));
    pDest->a_SpecBeamCmplx[i].f_PowerScaleFactor = 0.f; // TODO: do right calculation? pSrc->a_SpecBeamCmplx[i].f_PowerScaleFactor;
    SetPowScaleFactorV1PRtoV2PR( &(pDest->a_SpecBeamCmplx[i].f_PowerScaleFactor), &(pSrc->a_SpecBeamCmplx[i]) );
  }
}

__inline void v_Convert_v1pr_to_v2pr_FAR (RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1_PR::NumFarSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V2_PR::NumFarSpecBeamCmplxList); i++)
  {
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_SpecBeamCmplx[i].a_SpecBeamCmplx, sizeof(a_BeamSpecCmplx_array_t));
    SetPowScaleFactorV1PRtoV2PR( &(pDest->a_SpecBeamCmplx[i].f_PowerScaleFactor), &(pSrc->a_SpecBeamCmplx[i]) );
  }
}

__inline void v_Convert_v1pr_to_v3pr_NEAR (RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V1_PR::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V3_PR::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(pDest->a_SpecBeamCmplx[i].a_SpecBeamCmplx, pSrc->a_SpecBeamCmplx[i].a_SpecBeamCmplx, sizeof(a_BeamSpecCmplx_array_t));
    pDest->a_SpecBeamCmplx[i].f_PowerScaleFactor = 0.f; // TODO: do right calculation? pSrc->a_SpecBeamCmplx[i].f_PowerScaleFactor;
    SetPowScaleFactorV1PRtoV2PR( &(pDest->a_SpecBeamCmplx[i].f_PowerScaleFactor), &(pSrc->a_SpecBeamCmplx[i]) );
  }
}

__inline void v_Convert_v2pr_to_v3pr_NEAR (RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V2_PR::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V3_PR::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(&(pDest->a_SpecBeamCmplx[i]), &(pSrc->a_SpecBeamCmplx[i]), sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplx));
  }
}

__inline void v_Convert_v3pr_to_v2pr_NEAR (RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V2_PR::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V3_PR::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(&(pDest->a_SpecBeamCmplx[i]), &(pSrc->a_SpecBeamCmplx[i]), sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplx));
  }
}

__inline void v_Convert_v2_2en_to_v2_1en_NEAR (RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V2_1_EN::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V2_2_EN::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(&(pDest->a_SpecBeamCmplx[i]), &(pSrc->a_SpecBeamCmplx[i]), sizeof(RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplx));
  }
}

__inline void v_Convert_v2_1en_to_v2_2en_NEAR (RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  // copy consistent header part
  memcpy(&(pDest->Header),&(pSrc->Header),sizeof(pDest->Header));

  // copy clusters
  for (int i=0; i < _MINI(RSP_SPECBEAMCMPLXLIST_V2_1_EN::NumNearSpecBeamCmplxList, RSP_SPECBEAMCMPLXLIST_V2_2_EN::NumNearSpecBeamCmplxList); i++)
  {
    memcpy(&(pDest->a_SpecBeamCmplx[i]), &(pSrc->a_SpecBeamCmplx[i]), sizeof(RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplx));
  }
}

__inline void v_Convert_ARS5xx_V1_A_to_ARS5xx_V1_B (RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS * const pDest,
  const RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS * const pSrc)
{
  static unsigned char TransTable[16] = { 1, 3, 5, 7, 9, 11, 0, 2, 4, 6, 8, 10, 12, 13, 14, 15 };
  // first copy all
  memcpy(pDest,pSrc,sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS));
  // rearrange a_Channels
  for (int nI=0; nI < RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::NumNearSpecBeamCmplxList; nI++)
  {
    for (int nJ=0; nJ < /*16*/12; nJ++)                                      // Important: Changing the TransTable in the last 4 Elements -> Adapt end value
    {
      pDest->a_SpecBeamCmplx[nI].a_Channels[TransTable[nJ]] = pSrc->a_SpecBeamCmplx[nI].a_Channels[nJ];
    }
  }
}

// end of convert all to v1

long CConvRSPSpecBeamCmplxList::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;

  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // If direct one-one copy possible do that
  if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))) &&
    // except for ARS510. Conversion A-Sample to B-Sample
    (ulRPortSize != sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)))
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else
  {
    // First branch to decide which version we are converting to
    if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 0 far, convert to that
      RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS * const pDest = &m_FarV0;

      // request port version 0 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v0_to_v0_FAR (pDest, pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v1_to_v0_FAR(pDest, pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v2_to_v0_FAR(pDest, pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 0 near, convert to that
      RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV0;

      // request port version 0 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v0_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v1_to_v0_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v2_to_v0_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 1 near, convert to that
      RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV1;

      // request port version 0 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v1_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v1_to_v1_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 0 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v2_to_v1_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v0_to_v1_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 2 PR near, convert to that
      RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV2PR;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v1pr_to_v2pr_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v3pr_to_v2pr_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 2 PR far, convert to that
      RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS * const pDest = &m_FarV2PR;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS*>(pPPortData);
        v_Convert_v1pr_to_v2pr_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 2 PR near, convert to that
      RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV3PR;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v1pr_to_v3pr_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v2pr_to_v3pr_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
    }
    // ARS400_EN, ARS4D2
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 2.1 EN near, convert to that
      RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV2_1EN;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v2_2en_to_v2_1en_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
    }
    // ARS400_EN, ARS4D2
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS)) && (requestPortVersionInfo.Equals(&BASE_VERSION)))
    {
      // Request port has layout of version 2.2 EN near, convert to that
      RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearV2_2EN;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION))))
      {
        const RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<const RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_v2_1en_to_v2_2en_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
    }

    // ARS510
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)) && requestPortVersionInfo.Equals(&VERSION2))
    {
      // Request port has layout of version RSP_SPECBEAMCMPLXLIST_ARS5xx_V1
      RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS * const pDest = &m_NearArs5xxV1;

      if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION2))) && (uDataVer == 0x2u))
      {
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else if ((ulPPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)) && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)) || (pProvidePortVersionInfo->Equals(&VERSION1))) && ((uDataVer == 0x0u) || (uDataVer == 0x1u)))
      {
        const RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS * const pSrc = reinterpret_cast<RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS*>(pPPortData);
        v_Convert_ARS5xx_V1_A_to_ARS5xx_V1_B(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // Not supported conversion, since destination port not supported
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if ((ulRPortSize == sizeof(RSP_SPECBEAMCMPLXLIST_ARS5xx_V1::RSP_t_SpecBeamCmplxListNS)) && requestPortVersionInfo.Equals(&BASE_VERSION))
    {
      // Not supported conversion, since destination port not supported
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }

    else
    {
      // Not supported conversion, since destination port not supported
      lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    }
  }
  return lRet;
}

/** returns:
 *   SIM_ERR_OK - when this value can be used
 *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implememnted here
 *                                            and the default value from Request Port must be used
 */
long CConvRSPSpecBeamCmplxList::GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    void** pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_FarV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListFS & Dest = m_FarV0;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V0::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV0;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV1)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V1::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV1;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV1PR)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListFS & Dest = m_FarV1PR;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV1PR)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V1_PR::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV1PR;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV2PR)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListFS & Dest = m_FarV2PR;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV2PR)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V2_PR::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV2PR;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV3PR)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V3_PR::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV3PR;
      InitSpecBeamCmplxList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV2_1EN)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V2_1_EN::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV2_1EN;
      InitSpecBeamCmplxList(Dest, 2U);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV2_2EN)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP_SPECBEAMCMPLXLIST_V2_2_EN::RSP_t_SpecBeamCmplxListNS & Dest = m_NearV2_2EN;
      InitSpecBeamCmplxList(Dest, 2U);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRSPSpecBeamCmplxList::IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
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
bool CConvRSPSpecBeamCmplxList::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
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
// The one and only externally visible factory function
//
IConverter * CreateRSPSpecBeamCmplxListConvClass(void)
{
  return new CConvRSPSpecBeamCmplxList();
}

