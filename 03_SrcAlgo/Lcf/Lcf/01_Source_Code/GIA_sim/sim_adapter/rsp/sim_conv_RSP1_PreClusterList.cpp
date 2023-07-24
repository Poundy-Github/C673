/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_RSP1_PreClusterList

  DESCRIPTION:          Convert static peak list

  AUTHOR:               Stephan Kaelberer

  CREATION DATE:        28.03.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_RSP1_PreClusterList.cpp  $
  CHANGES:              Revision 1.1 2021/12/13 17:21:42CET Wang, David (Wangd3) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2017/08/10 13:15:36CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.8.1.13 2017/04/05 13:51:27CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Limiting pDest->PreClustHead.u_NofClusters to the maximal target number
  CHANGES:              Revision 1.8.1.12 2016/08/18 13:32:41CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + ARS510: V100A and V100B and conversion between those
  CHANGES:              Revision 1.8.1.11 2015/05/07 10:22:23CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace RSP1_PRECLUSTERLIST_V6_2_PR_EN
  CHANGES:              + Conversions
  CHANGES:              --- Added comments ---  berndtt1 [May 7, 2015 10:25:12 AM CEST]
  CHANGES:              Change Package : 335739:1 http://mks-psad:7002/im/viewissue?selection=335739
  CHANGES:              Revision 1.8.1.10 2014/12/12 08:43:32CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Clean up of the Entry paths, joint and switched by compiler defines
  CHANGES:              --- Added comments ---  berndtt1 [Dec 12, 2014 9:35:43 AM CET]
  CHANGES:              Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8.1.9 2014/12/05 11:43:05CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Bugfix GetDeps: ">=" ---> "=="
  CHANGES:              --- Added comments ---  berndtt1 [Dec 5, 2014 11:43:43 AM CET]
  CHANGES:              Change Package : 221167:41 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8.1.8 2014/10/24 09:45:23CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version V10 (Corresponds to transmitted Version 6)
  CHANGES:              --- Added comments ---  berndtt1 [Oct 31, 2014 7:55:04 AM CET]
  CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8.1.7 2014/08/14 09:16:44CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:              Added Preclusterlist with size 1024
  CHANGES:              --- Added comments ---  berndtt1 [Aug 14, 2014 9:18:55 AM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8.1.6 2014/08/11 07:59:19CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:              --- Added comments ---  berndtt1 [Aug 13, 2014 4:33:30 PM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8.1.5 2014/07/14 15:12:13CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Dependencies
  CHANGES:              + Workaround for corrupted RCS
  CHANGES:              --- Added comments ---  berndtt1 [Jul 14, 2014 3:22:06 PM CEST]
  CHANGES:              Change Package : 246752:1 http://mks-psad:7002/im/viewissue?selection=246752
  CHANGES:              Revision 1.8.1.4 2014/06/30 10:01:24CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace RSP1_PRECLUSTERLIST_V7
  CHANGES:              Conversion implemented for Near (Cluster Size 960 -> 640)
  CHANGES:              --- Added comments ---  berndtt1 [Jun 30, 2014 10:04:54 AM CEST]
  CHANGES:              Change Package : 244114:2 http://mks-psad:7002/im/viewissue?selection=244114
  CHANGES:              Revision 1.8.1.3 2014/03/27 14:26:22CET Schluttig, Jakob (uidv7098) 
  CHANGES:              fix (?): removed port version conditions for adaptions -> only rely on structure size for the moment
  CHANGES:              --- Added comments ---  uidv7098 [Mar 27, 2014 2:26:23 PM CET]
  CHANGES:              Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:              Revision 1.8.1.2 2014/03/24 13:30:52CET Zeitler, Armin02 (uidv8867) 
  CHANGES:              - u_MultipleTargetProb has been added due to new algoextract.
  CHANGES:              --- Added comments ---  uidv8867 [Mar 24, 2014 1:30:52 PM CET]
  CHANGES:              Change Package : 226903:1 http://mks-psad:7002/im/viewissue?selection=226903
  CHANGES:              Revision 1.8.1.1 2014/03/21 14:22:46CET Zeitler, Armin02 (uidv8867) 
  CHANGES:              RSP1 PreCluster lists
  CHANGES:              --- Added comments ---  uidv8867 [Mar 21, 2014 2:22:47 PM CET]
  CHANGES:              Change Package : 226903:1 http://mks-psad:7002/im/viewissue?selection=226903
  CHANGES:              Revision 1.8 2014/01/30 12:59:40CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              sim_adapter_cfg.h
  CHANGES:              --- Added comments ---  berndtt1 [Jan 30, 2014 1:00:56 PM CET]
  CHANGES:              Change Package : 208935:12 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.7 2014/01/29 15:00:29CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + #include "sim_adapter_cfg.h"
  CHANGES:              --- Added comments ---  berndtt1 [Jan 29, 2014 3:16:28 PM CET]
  CHANGES:              Change Package : 208935:12 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.6 2013/09/16 14:36:13CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              New version of RSP_t_PreClusterListNear/Far
  CHANGES:              --- Added comments ---  berndtt1 [Sep 16, 2013 2:43:08 PM CEST]
  CHANGES:              Change Package : 193430:3 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.5 2013/08/12 14:10:28CEST Schluttig, Jakob (uidv7098) 
  CHANGES:              Fix far cluster list adaption from B0 (copy paste error)
  CHANGES:              --- Added comments ---  uidv7098 [Aug 12, 2013 2:10:29 PM CEST]
  CHANGES:              Change Package : 183793:2 http://mks-psad:7002/im/viewissue?selection=183793
  CHANGES:              Revision 1.4 2013/07/10 17:17:05CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:              - adapted to b1 interfaces.
  CHANGES:              --- Added comments ---  uidu2446 [Jul 10, 2013 5:17:05 PM CEST]
  CHANGES:              Change Package : 187998:2 http://mks-psad:7002/im/viewissue?selection=187998
  CHANGES:              Revision 1.3 2013/06/11 19:14:35CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:              - modularized code.
  CHANGES:              --- Added comments ---  uidu2446 [Jun 11, 2013 7:14:35 PM CEST]
  CHANGES:              Change Package : 185634:1 http://mks-psad:7002/im/viewissue?selection=185634
  CHANGES:              Revision 1.2 2013/06/11 16:35:56CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:              - first working version, converts from (v1 and v0) to v2.
  CHANGES:              --- Added comments ---  uidu2446 [Jun 11, 2013 4:35:56 PM CEST]
  CHANGES:              Change Package : 185634:1 http://mks-psad:7002/im/viewissue?selection=185634
  CHANGES:              Revision 1.1 2013/03/28 15:13:28CET Kaelberer, Stephan (uidu2442) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:56:14CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */

/* includes ---------------------------------------------------------------- */
#include <atlbase.h>                             // ATL includes
#include "sim_adapter_cfg.h"
#include "sim_conv_RSP1_PreClusterList.h"
#include <math.h>

#include "sim_versioninfo_impl.h"
#include "interface_RSP1_PreClusterList_ars400.h"

#define _MINI(x,y) (x<y?x:y)

class CConvRSP1PreClusterList : public CSimConverterBase
{
  // the list of dependency names used inside by the converter
  static const TCHAR *DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    RECVERSION = 0,
    DORCSCORRECTION,
    // add new dependencies here
    DEP_COUNT
  };

  RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar      m_FarV0;
  RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear     m_NearV0;
  RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar      m_FarV1;
  RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear     m_NearV1;
  RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar      m_FarV2;
  RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear     m_NearV2;
  RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS       m_FarV3;
  RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS       m_NearV3;
  RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS       m_FarV4;
  RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS       m_NearV4;
  RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS m_FarV2pren;
  RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS m_NearV2pren;
  RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS m_FarV4pren;
  RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS m_NearV4pren;
  RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS m_FarV5pren;
  RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS m_NearV5pren;
  RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS m_FarV6pren;
  RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS m_NearV6pren;
  RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS m_FarV62pren;
  RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS m_NearV62pren;
  // ARS510:
  RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS m_NearV100A;
  RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS m_NearV100B;


  // Initialization of header
  template <typename T> static void InitPreClusterHeader (T & Dest, uint32 VersionNumber)
  {
    ::memset(&(Dest.PreClustHead), 0, sizeof(Dest.PreClustHead));
    Dest.PreClustHead.u_VersionNumber = VersionNumber;
  }

  void InitPreCluster(RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V2::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V3::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V4::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreCluster & Dest) const
  {
    ::memset(&Dest, 0, sizeof(Dest));
  };

  void InitPreCluster(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreCluster & Dest) const
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

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V3::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V3::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V4::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V4::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V2_PR_EN::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V2_PR_EN::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V4_PR_EN::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V5_PR_EN::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V5_PR_EN::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V6_PR_EN::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V6_PR_EN::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V6_2_PR_EN::NumFSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V6_2_PR_EN::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

  void InitPreClusterList(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V100_A::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };
  void InitPreClusterList(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS & Dest) const
  {
    for (unsigned int i=0; i<RSP1_PRECLUSTERLIST_V100_B::NumNSPreClusters; i++)
    {
      InitPreCluster(Dest.a_Clusters[i]);
    }
  };

public:

  CConvRSP1PreClusterList(void): CSimConverterBase(DEP_NAMES, DEP_COUNT),
    m_FarV0(), m_NearV0(), m_FarV1(), m_NearV1(), m_FarV2(), m_NearV2(), m_FarV3(), m_NearV3(), m_FarV4(), m_NearV4(),
    m_FarV2pren(), m_NearV2pren(), m_FarV4pren(), m_NearV4pren(), m_FarV5pren(), m_NearV5pren(), m_FarV6pren(), m_NearV6pren(), m_FarV62pren(), m_NearV62pren(),
    m_NearV100A(), m_NearV100B()
  {
    InitPreClusterList(m_FarV0);
    InitPreClusterList(m_NearV0);
    InitPreClusterList(m_FarV1);
    InitPreClusterList(m_NearV1);
    InitPreClusterList(m_FarV2);
    InitPreClusterList(m_NearV2);
    InitPreClusterList(m_FarV3);
    InitPreClusterList(m_NearV3);
    InitPreClusterList(m_FarV4);
    InitPreClusterList(m_NearV4);
    InitPreClusterList(m_FarV2pren);
    InitPreClusterList(m_NearV2pren);
    InitPreClusterList(m_FarV4pren);
    InitPreClusterList(m_NearV4pren);
    InitPreClusterList(m_FarV5pren);
    InitPreClusterList(m_NearV5pren);
    InitPreClusterList(m_FarV6pren);
    InitPreClusterList(m_NearV6pren);
    InitPreClusterList(m_FarV62pren);
    InitPreClusterList(m_NearV62pren);
    InitPreClusterList(m_NearV100A);
    InitPreClusterList(m_NearV100B);
  };

  // Not implemented copy constructor to get linker error
  CConvRSP1PreClusterList(const CConvRSP1PreClusterList & init);

  virtual ~CConvRSP1PreClusterList(void)
  {
  };

  // IConverterDestroy::Destroy implementation
  virtual void Destroy()
  {
    delete this;
  };

  // IConverter::GetTypeName implementation
  virtual const char *GetTypeName(void)
  {
    return "RSP_PreClusterList";
  };

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    if (( (pPortVersion == NULL)  || (pPortVersion->Equals(&RSP1V100)) || (pPortVersion->Equals(&RSP1V6)) || (pPortVersion->Equals(&RSP1V5)) || (pPortVersion->Equals(&RSP1V4)) || (pPortVersion->Equals(&RSP1V3)) || (pPortVersion->Equals(&RSP1V2)) || (pPortVersion->Equals(&RSP1V1)) || (pPortVersion->Equals(&BASE_VERSION)))
    &&(
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS)) ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS))       ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS))       ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS))       ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS))       ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar))      ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear))     ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar))      ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear))     ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar))      ||
      (ulPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear))
      ))
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
    void **pOutData, unsigned long &ulOutSize);

  /** returns:
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    void **pDefaultData, unsigned long& ulDefaultSize);

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
  // Following Version Information are not used at the moment:
  static CVersionInfoImpl RSP1V1;
  static CVersionInfoImpl RSP1V2;
  static CVersionInfoImpl RSP1V3;
  static CVersionInfoImpl RSP1V4;
  static CVersionInfoImpl RSP1V5;
  static CVersionInfoImpl RSP1V6;
  static CVersionInfoImpl RSP1V100;

  //enum eFPGAStaticPeakListVersion
  //{
  //  FPGA_STATIC_PEAK_VERSION_COUNT
  //};
  //static unsigned long SUPPORTED_SIZE[FPGA_STATIC_PEAK_VERSION_COUNT];

  //static const CVersionInfoImpl * const FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT];

  bool GetDeps (unsigned int &uiRecVersion, unsigned char &ucDoRCSCorrection)
  {
    bool bRet = false;
    DepInfo *pValUi = GetDependencyInfo(RECVERSION);
    // retrieve dependency for being used
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL))
    {
      uiRecVersion = * (unsigned int *) pValUi->m_pDepData;
    }
    DepInfo *pValUc = GetDependencyInfo(DORCSCORRECTION);
    // retrieve dependency for being used
    if ((pValUc != NULL) && (pValUc->m_pDepData != NULL))
    {
      ucDoRCSCorrection = *((unsigned char *) pValUc->m_pDepData);
    }
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL) &&
      (pValUc != NULL) && (pValUc->m_pDepData != NULL))
    {
      if ((uiRecVersion == 0x40004) ||
        (uiRecVersion == 0x40022) ||
        (uiRecVersion == 0x40100) ||
        ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105)))
      {
        if (ucDoRCSCorrection == 1)
        {
          bRet = true;
        }
      }
    }
    return bRet;
  }

};

const TCHAR *CConvRSP1PreClusterList::DEP_NAMES[CConvRSP1PreClusterList::DEP_COUNT] = {_T("RecVersion"), _T("DoRCSCorrection")};

CVersionInfoImpl  CConvRSP1PreClusterList::BASE_VERSION(0, 0, 0);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V1(0, 0, 1);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V2(0, 0, 2);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V3(0, 0, 3);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V4(0, 0, 4);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V5(0, 0, 5);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V6(0, 0, 6);
CVersionInfoImpl  CConvRSP1PreClusterList::RSP1V100(0, 1, 0);
//
//unsigned long CConvRSP1PreClusterList::SUPPORTED_SIZE[CConvFPGAStaticPeakList::FPGA_STATIC_PEAK_VERSION_COUNT]=
//{
//};
//
//const CVersionInfoImpl *const CConvRSP1PreClusterList::FPGA_STATIC_PEAK_LIST_VERSIONS[FPGA_STATIC_PEAK_VERSION_COUNT] =
//{
//  &BASE_VERSION,
//  &RSP_CTX_VERSION_V0,
//  &RSP_CTX_VERSION_V1,
//  &RSP_CTX_VERSION_V1_1,
//  &RSP_CTX_VERSION_V2
//};

__inline void v_Convert_v100A_to_v100B_NEAR(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS & Source)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  Dest.PreClustHead.u_VersionNumber = 0x100u;
  Dest.PreClustHead.sSigHeader = Source.PreClustHead.sSigHeader;
  Dest.PreClustHead.u_NofClusters = Source.PreClustHead.u_NofClusters;
  Dest.PreClustHead.ContextData = Source.PreClustHead.ContextData;
};

__inline void v_Convert_v100B_to_v100A_NEAR(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS & Source)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  Dest.PreClustHead.u_VersionNumber = 0x100u;
  Dest.PreClustHead.sSigHeader = Source.PreClustHead.sSigHeader;
  Dest.PreClustHead.u_TimeStamp = Source.PreClustHead.sSigHeader.uiTimeStamp;
  Dest.PreClustHead.u_NofClusters = Source.PreClustHead.u_NofClusters;
  Dest.PreClustHead.ContextData = Source.PreClustHead.ContextData;
};

__inline void v_Convert_v6pren_to_v62pren_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  memcpy(&Dest.PreClustHead, &Source.PreClustHead, nSize);           // PreClustHead is the same except the last element
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  Dest.PreClustHead.ContextData.f_PowerScalingFactor = -114.1f;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  Dest.PreClustHead.ContextData.f_PowerScalingFactor = -119.5f;
#elif (SRR_SWITCH == SWITCH_ON)
  Dest.PreClustHead.ContextData.f_PowerScalingFactor = -115.5f;
#endif

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v6pren_to_v62pren_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  memcpy(&Dest.PreClustHead, &Source.PreClustHead, nSize);           // PreClustHead is the same except the last element
  // Far scan only for Premium and Premium Plus (ARS430/ARS440)
  Dest.PreClustHead.ContextData.f_PowerScalingFactor = -109.5f;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

__inline void v_Convert_v62pren_to_v6pren_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  memcpy(&Dest.PreClustHead, &Source.PreClustHead, nSize);           // PreClustHead is the same except the last element

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v62pren_to_v6pren_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest.a_Clusters, &Source.a_Clusters, sizeof(Dest.a_Clusters));
  int nSize = _MINI(sizeof(Source.PreClustHead), sizeof(Dest.PreClustHead));
  memcpy(&Dest.PreClustHead, &Source.PreClustHead, nSize);           // PreClustHead is the same except the last element

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

__inline void v_Convert_v5pren_to_v6pren_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.PreClustHead.ContextData.u_GainReduction = 0;
  Dest.PreClustHead.ContextData.u_CurrentRfIndex = Source.PreClustHead.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v5pren_to_v6pren_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.PreClustHead.ContextData.u_GainReduction = 0;
  Dest.PreClustHead.ContextData.u_CurrentRfIndex = Source.PreClustHead.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

__inline void v_Convert_v4pren_to_v6pren_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.PreClustHead.u_NofClusters = _MINI(RSP1_PRECLUSTERLIST_V6_PR_EN::NumFSPreClusters, Source.PreClustHead.u_NofClusters);
  Dest.PreClustHead.ContextData.u_GainReduction = 0;
  Dest.PreClustHead.ContextData.u_CurrentRfIndex = Source.PreClustHead.ContextData.u_CurrentRfIndex;

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

__inline void v_Convert_v2pren_to_v6pren_FAR (RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc )
{
  // Header part
  pDest->PreClustHead.u_VersionNumber                   = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.sSigHeader.uiTimeStamp            = pSrc->PreClustHead.sSigHeader.uiTimeStamp;
  pDest->PreClustHead.sSigHeader.uiMeasurementCounter   = pSrc->PreClustHead.sSigHeader.uiMeasurementCounter;
  pDest->PreClustHead.sSigHeader.uiCycleCounter         = pSrc->PreClustHead.sSigHeader.uiCycleCounter;
  pDest->PreClustHead.sSigHeader.eSigStatus             = pSrc->PreClustHead.sSigHeader.eSigStatus;
  pDest->PreClustHead.u_TimeStamp                       = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters                     = _MINI(RSP1_PRECLUSTERLIST_V6_PR_EN::NumFSPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.ContextData.f_PulseRepetitionTime = pSrc->PreClustHead.ContextData.f_PulseRepetitionTime;
  pDest->PreClustHead.ContextData.f_RangeGateLength     = pSrc->PreClustHead.ContextData.f_RangeGateLength;
  pDest->PreClustHead.ContextData.f_MidFrequency        = pSrc->PreClustHead.ContextData.f_MidFrequency;
  pDest->PreClustHead.ContextData.f_TargetNormS         = pSrc->PreClustHead.ContextData.f_TargetNormS;
  pDest->PreClustHead.ContextData.u_GainReduction       = 0u;
  pDest->PreClustHead.ContextData.u_CurrentRfIndex      = 0u;
  memset(&(pDest->PreClustHead.ContextData.u_Dummy), 0, sizeof(pDest->PreClustHead.ContextData.u_Dummy));
  memcpy(pDest->PreClustHead.ContextData.a_PathCompensation, pSrc->PreClustHead.ContextData.a_PathCompensation, sizeof(pDest->PreClustHead.ContextData.a_PathCompensation));
  memcpy(pDest->PreClustHead.ContextData.a_AzimuthWindow, pSrc->PreClustHead.ContextData.a_AzimuthWindow, sizeof(pDest->PreClustHead.ContextData.a_AzimuthWindow));

  // Copy cluster values
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V2_PR_EN::NumFSPreClusters, RSP1_PRECLUSTERLIST_V6_PR_EN::NumFSPreClusters); i++)
  {
    pDest->a_Clusters[i].f_IntRangeBin        = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntDopplerBin      = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].a_IntBeamBin[0]      = pSrc->a_Clusters[i].a_IntBeamBin[0];
    pDest->a_Clusters[i].a_IntBeamBin[1]      = pSrc->a_Clusters[i].a_IntBeamBin[1];
    pDest->a_Clusters[i].f_IntRangeBinLength  = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_IntPowerLog        = pSrc->a_Clusters[i].f_IntPowerLog;
    memcpy(pDest->a_Clusters[i].a_Pdh0, pSrc->a_Clusters[i].a_Pdh0, sizeof(pSrc->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].a_Pdh0[7]            = 0u;
    pDest->a_Clusters[i].f_SNR                = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v5pren_to_v6pren_NEAR(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Source)
{
  /* The differences are
  - the inclusion of u_MultipleTargetProb into the array a_Pdh0_array_t_0 (in RSP_t_PreCluster), which grows from 7 to 8.
  - introduced u_GainReduction (in t_ContextData), which moves u_CurrentRfIndex by one position down */
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.PreClustHead.ContextData.u_GainReduction = 0;
  Dest.PreClustHead.ContextData.u_CurrentRfIndex = Source.PreClustHead.ContextData.u_CurrentRfIndex;
};

__inline void v_Convert_v5pren_to_v6pren_FAR(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Source)
{
  memcpy(&Dest, &Source, sizeof(Dest));
  Dest.PreClustHead.ContextData.u_GainReduction = 0;
  Dest.PreClustHead.ContextData.u_CurrentRfIndex = Source.PreClustHead.ContextData.u_CurrentRfIndex;
};

__inline void v_Convert_v5pren_to_v4pren_NEAR (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pSrc )
{
  // Header part
  pDest->PreClustHead = pSrc->PreClustHead;
  pDest->PreClustHead.u_NofClusters = _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);

  // Copy cluster values
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters, RSP1_PRECLUSTERLIST_V5_PR_EN::NumNSPreClusters); i++)
  {
    pDest->a_Clusters[i] = pSrc->a_Clusters[i];
  }
}

__inline void v_Convert_v4pren_to_v5pren_FAR (RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc )
{
  // Header part
  pDest->PreClustHead = pSrc->PreClustHead;

  // Copy cluster values
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumFSPreClusters, RSP1_PRECLUSTERLIST_V5_PR_EN::NumFSPreClusters); i++)
  {
    pDest->a_Clusters[i] = pSrc->a_Clusters[i];
  }
}

__inline void v_Convert_v2pren_to_v4pren_FAR (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc )
{
  // Header part
  pDest->PreClustHead.u_VersionNumber                   = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.sSigHeader.uiTimeStamp            = pSrc->PreClustHead.sSigHeader.uiTimeStamp;
  pDest->PreClustHead.sSigHeader.uiMeasurementCounter   = pSrc->PreClustHead.sSigHeader.uiMeasurementCounter;
  pDest->PreClustHead.sSigHeader.uiCycleCounter         = pSrc->PreClustHead.sSigHeader.uiCycleCounter;
  pDest->PreClustHead.sSigHeader.eSigStatus             = pSrc->PreClustHead.sSigHeader.eSigStatus;
  pDest->PreClustHead.u_TimeStamp                       = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters                     = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.ContextData.f_PulseRepetitionTime = pSrc->PreClustHead.ContextData.f_PulseRepetitionTime;
  pDest->PreClustHead.ContextData.f_RangeGateLength     = pSrc->PreClustHead.ContextData.f_RangeGateLength;
  pDest->PreClustHead.ContextData.f_MidFrequency        = pSrc->PreClustHead.ContextData.f_MidFrequency;
  pDest->PreClustHead.ContextData.f_TargetNormS         = pSrc->PreClustHead.ContextData.f_TargetNormS;
  pDest->PreClustHead.ContextData.u_CurrentRfIndex      = 0u;
  memset(&(pDest->PreClustHead.ContextData.u_Dummy), 0, sizeof(pDest->PreClustHead.ContextData.u_Dummy));
  memcpy(pDest->PreClustHead.ContextData.a_PathCompensation, pSrc->PreClustHead.ContextData.a_PathCompensation, sizeof(pDest->PreClustHead.ContextData.a_PathCompensation));
  memcpy(pDest->PreClustHead.ContextData.a_AzimuthWindow, pSrc->PreClustHead.ContextData.a_AzimuthWindow, sizeof(pDest->PreClustHead.ContextData.a_AzimuthWindow));

  // Copy cluster values
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V2_PR_EN::NumFSPreClusters, RSP1_PRECLUSTERLIST_V4_PR_EN::NumFSPreClusters); i++)
  {
    pDest->a_Clusters[i].f_IntRangeBin        = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntDopplerBin      = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].a_IntBeamBin[0]      = pSrc->a_Clusters[i].a_IntBeamBin[0];
    pDest->a_Clusters[i].a_IntBeamBin[1]      = pSrc->a_Clusters[i].a_IntBeamBin[1];
    pDest->a_Clusters[i].f_IntRangeBinLength  = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_IntPowerLog        = pSrc->a_Clusters[i].f_IntPowerLog;
    memcpy(pDest->a_Clusters[i].a_Pdh0, pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].u_MultipleTargetProb = 0u;
    pDest->a_Clusters[i].f_SNR                = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v2pren_to_v4pren_NEAR (RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS * const pSrc )
{
  // Header part
  pDest->PreClustHead.u_VersionNumber                   = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.sSigHeader.uiTimeStamp            = pSrc->PreClustHead.sSigHeader.uiTimeStamp;
  pDest->PreClustHead.sSigHeader.uiMeasurementCounter   = pSrc->PreClustHead.sSigHeader.uiMeasurementCounter;
  pDest->PreClustHead.sSigHeader.uiCycleCounter         = pSrc->PreClustHead.sSigHeader.uiCycleCounter;
  pDest->PreClustHead.sSigHeader.eSigStatus             = pSrc->PreClustHead.sSigHeader.eSigStatus;
  pDest->PreClustHead.u_TimeStamp                       = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters                     = _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.ContextData.f_PulseRepetitionTime = pSrc->PreClustHead.ContextData.f_PulseRepetitionTime;
  pDest->PreClustHead.ContextData.f_RangeGateLength     = pSrc->PreClustHead.ContextData.f_RangeGateLength;
  pDest->PreClustHead.ContextData.f_MidFrequency        = pSrc->PreClustHead.ContextData.f_MidFrequency;
  pDest->PreClustHead.ContextData.f_TargetNormS         = pSrc->PreClustHead.ContextData.f_TargetNormS;
  pDest->PreClustHead.ContextData.u_CurrentRfIndex      = 0u;
  memset(&(pDest->PreClustHead.ContextData.u_Dummy), 0, sizeof(pDest->PreClustHead.ContextData.u_Dummy));
  memcpy(pDest->PreClustHead.ContextData.a_PathCompensation, pSrc->PreClustHead.ContextData.a_PathCompensation, sizeof(pDest->PreClustHead.ContextData.a_PathCompensation));
  memcpy(pDest->PreClustHead.ContextData.a_AzimuthWindow, pSrc->PreClustHead.ContextData.a_AzimuthWindow, sizeof(pDest->PreClustHead.ContextData.a_AzimuthWindow));

  // Copy cluster values
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V2_PR_EN::NumNSPreClusters, RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters); i++)
  {
    pDest->a_Clusters[i].f_IntRangeBin        = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntDopplerBin      = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].a_IntBeamBin[0]      = pSrc->a_Clusters[i].a_IntBeamBin[0];
    pDest->a_Clusters[i].a_IntBeamBin[1]      = pSrc->a_Clusters[i].a_IntBeamBin[1];
    pDest->a_Clusters[i].f_IntRangeBinLength  = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_IntPowerLog        = pSrc->a_Clusters[i].f_IntPowerLog;
    memcpy(pDest->a_Clusters[i].a_Pdh0, pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].u_MultipleTargetProb = 0u;
    pDest->a_Clusters[i].f_SNR                = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v6_to_v6_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v4pren_to_v4pren_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

__inline void v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround (RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  // Header part
  Dest.PreClustHead = Source.PreClustHead;
  Dest.PreClustHead.u_NofClusters = _MINI(RSP1_PRECLUSTERLIST_V5_PR_EN::NumNSPreClusters, Source.PreClustHead.u_NofClusters);

  // Copy cluster values
  for (int i = 0; i < _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumNSPreClusters, RSP1_PRECLUSTERLIST_V5_PR_EN::NumNSPreClusters); i++)
  {
    Dest.a_Clusters[i] = Source.a_Clusters[i];
  }

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
}

__inline void v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround (RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  // Header part
  Dest.PreClustHead = Source.PreClustHead;

  // Copy cluster values
  for (int i = 0; i < _MINI(RSP1_PRECLUSTERLIST_V4_PR_EN::NumFSPreClusters, RSP1_PRECLUSTERLIST_V5_PR_EN::NumFSPreClusters); i++)
  {
    Dest.a_Clusters[i] = Source.a_Clusters[i];
  }

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
}

__inline void v_Convert_v5_to_v5_NEAR_RCSWorkaround (RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v5_to_v5_FAR_RCSWorkaround (RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

// convert all to v4
__inline void v_Convert_v0_to_v4_NEAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V4::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V0::NumNearPreClusters,RSP1_PRECLUSTERLIST_V4::NumNSPreClusters); i++  )
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      = pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  = 0.0f;
  }
}

__inline void v_Convert_v0_to_v4_FAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V0::NumFarPreClusters,RSP1_PRECLUSTERLIST_V4::NumFSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v1_to_v4_NEAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V4::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V1::NumNearPreClusters,RSP1_PRECLUSTERLIST_V4::NumNSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v1_to_v4_FAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V1::NumFarPreClusters,RSP1_PRECLUSTERLIST_V4::NumFSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v2_to_v4_NEAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V4::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumNearPreClusters,RSP1_PRECLUSTERLIST_V4::NumNSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   0.0f;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v2_to_v4_FAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.sSigHeader.eSigStatus = RSP1_PRECLUSTERLIST_V4::SIGNAL_INVALID;
  }
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumFarPreClusters,RSP1_PRECLUSTERLIST_V4::NumFSPreClusters); i++  )
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,            pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin            = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth       = 0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin         = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog           = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin           = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength     = 0.0f;
    pDest->a_Clusters[i].f_SNR                   = 0.0f;
  }
}

__inline void v_Convert_v3_to_v4_NEAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber            = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp                = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters              = _MINI(RSP1_PRECLUSTERLIST_V4::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.sSigHeader.uiTimeStamp     = pSrc->PreClustHead.SignalHeader.uiTimeStamp;
  pDest->PreClustHead.sSigHeader.uiMeasurementCounter = pSrc->PreClustHead.SignalHeader.uiMeasurementCounter;
  pDest->PreClustHead.sSigHeader.uiCycleCounter  = pSrc->PreClustHead.SignalHeader.uiCycleCounter;
  pDest->PreClustHead.sSigHeader.eSigStatus      = pSrc->PreClustHead.SignalHeader.eSigStatus;
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, RSP1_PRECLUSTERLIST_V4::NumNSPreClusters); i++)
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,            pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin            = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth       = pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin         = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog           = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin           = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength     = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                   = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v3_to_v4_FAR (RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber            = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp                = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters              = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.sSigHeader.uiTimeStamp     = pSrc->PreClustHead.SignalHeader.uiTimeStamp;
  pDest->PreClustHead.sSigHeader.uiMeasurementCounter = pSrc->PreClustHead.SignalHeader.uiMeasurementCounter;
  pDest->PreClustHead.sSigHeader.uiCycleCounter  = pSrc->PreClustHead.SignalHeader.uiCycleCounter;
  pDest->PreClustHead.sSigHeader.eSigStatus      = pSrc->PreClustHead.SignalHeader.eSigStatus;
  memset(&(pDest->PreClustHead.ContextData), 0, sizeof(pDest->PreClustHead.ContextData));

  // copy clusters
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V3::NumFSPreClusters, RSP1_PRECLUSTERLIST_V4::NumFSPreClusters); i++)
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,            pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin            = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth       = pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin         = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog           = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin           = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength     = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                   = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v4_to_v3_NEAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber            = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp                = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters              = _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.SignalHeader.uiTimeStamp   = pSrc->PreClustHead.sSigHeader.uiTimeStamp;
  pDest->PreClustHead.SignalHeader.uiMeasurementCounter = pSrc->PreClustHead.sSigHeader.uiMeasurementCounter;
  pDest->PreClustHead.SignalHeader.uiCycleCounter= pSrc->PreClustHead.sSigHeader.uiCycleCounter;
  pDest->PreClustHead.SignalHeader.eSigStatus    = pSrc->PreClustHead.sSigHeader.eSigStatus;
  pDest->PreClustHead.f_RangeGateLength          = 1.f;

  // copy clusters
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, RSP1_PRECLUSTERLIST_V4::NumNSPreClusters); i++)
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,            pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin            = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth       = pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin         = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog           = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin           = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength     = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                   = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v4_to_v3_FAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber            = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp                = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters              = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.SignalHeader.uiTimeStamp   = pSrc->PreClustHead.sSigHeader.uiTimeStamp;
  pDest->PreClustHead.SignalHeader.uiMeasurementCounter = pSrc->PreClustHead.sSigHeader.uiMeasurementCounter;
  pDest->PreClustHead.SignalHeader.uiCycleCounter= pSrc->PreClustHead.sSigHeader.uiCycleCounter;
  pDest->PreClustHead.SignalHeader.eSigStatus    = pSrc->PreClustHead.sSigHeader.eSigStatus;
  pDest->PreClustHead.f_RangeGateLength          = 1.f;

  // copy clusters
  for (int i =0; i < _MINI(RSP1_PRECLUSTERLIST_V3::NumFSPreClusters, RSP1_PRECLUSTERLIST_V4::NumFSPreClusters); i++)
  {
    memcpy(pDest->a_Clusters[i].a_Pdh0,            pSrc->a_Clusters[i].a_Pdh0, sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin            = pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth       = pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin         = pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog           = pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin           = pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength     = pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                   = pSrc->a_Clusters[i].f_SNR;
  }
}

__inline void v_Convert_v4_to_v4_NEAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS & Dest, const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 7.4F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 0.5F;
    }
  }
};

__inline void v_Convert_v4_to_v4_FAR_RCSWorkaround(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS & Dest, const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS & Source,
  unsigned int uiRecVersion, unsigned char ucDoRCSCorrection)
{
  memcpy(&Dest, &Source, sizeof(Dest));

  // Other fields
  if (ucDoRCSCorrection == 1)
  {
    if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS + 3.3F;
    }
    else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
    {
      Dest.PreClustHead.ContextData.f_TargetNormS = Source.PreClustHead.ContextData.f_TargetNormS - 4.2F;
    }
  }
};

// end of convert all to v4

// convert all to v3
__inline void v_Convert_v0_to_v3_NEAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.     ?????    = 256; // range limit ist missing
  //

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V0::NumNearPreClusters,RSP1_PRECLUSTERLIST_V3::NumNSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v0_to_v3_FAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.u_RangeLimit        = 256;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V0::NumFarPreClusters,RSP1_PRECLUSTERLIST_V3::NumFSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v1_to_v3_NEAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V1::NumNearPreClusters,RSP1_PRECLUSTERLIST_V3::NumNSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v1_to_v3_FAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V1::NumFarPreClusters,RSP1_PRECLUSTERLIST_V3::NumFSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   pSrc->a_Clusters[i].f_IntBeamBinWidth;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   pSrc->a_Clusters[i].f_IntRangeBinLength;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v2_to_v3_NEAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V3::NumNSPreClusters, pSrc->PreClustHead.u_NofClusters);
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumNearPreClusters,RSP1_PRECLUSTERLIST_V3::NumNSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   0.0f;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

__inline void v_Convert_v2_to_v3_FAR (RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  if (pSrc->PreClustHead.u_ClusterListValid == TRUE )
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_VALID;
  }
  else
  {
    pDest->PreClustHead.SignalHeader.eSigStatus = RSP1_PRECLUSTERLIST_V3::SIGNAL_INVALID;
  }

  // fill missing header data
  //pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumFarPreClusters,RSP1_PRECLUSTERLIST_V3::NumFSPreClusters); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   0.0f;
    pDest->a_Clusters[i].f_SNR                  =   0.0f;
  }
}

// end of convert all to v3

__inline void v_Convert_v0_to_v2_NEAR (RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V2::NumNearPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = 256;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumNearPreClusters,RSP1_PRECLUSTERLIST_V0::NumNearPreClusters ) ; i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
  }
}
__inline void v_Convert_v0_to_v2_FAR (RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = 256;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumFarPreClusters,RSP1_PRECLUSTERLIST_V0::NumFarPreClusters ); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
  }
}
__inline void v_Convert_v1_to_v2_NEAR (RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V2::NumNearPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumNearPreClusters,RSP1_PRECLUSTERLIST_V1::NumNearPreClusters ); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
  }
}
__inline void v_Convert_v1_to_v2_FAR (RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pDest,
  const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  //pDest->PreClustHead.u_VersionNumber     = 2UL;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumFarPreClusters,RSP1_PRECLUSTERLIST_V1::NumFarPreClusters ); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
  }
}
__inline void v_Convert_v0_to_v1_NEAR (RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pDest,
  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V1::NumNearPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = 256;

  // copy clusters
  memcpy(pDest->a_Clusters, pSrc->a_Clusters, sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster)*RSP1_PRECLUSTERLIST_V0::NumNearPreClusters);
}
__inline void v_Convert_v0_to_v1_FAR (RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pDest,
                                  const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = 256;

  // copy clusters
  memcpy(pDest->a_Clusters, pSrc->a_Clusters, sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster)*RSP1_PRECLUSTERLIST_V0::NumFarPreClusters);
}

__inline void v_Convert_v2_to_v1_NEAR (RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = _MINI(RSP1_PRECLUSTERLIST_V1::NumNearPreClusters, pSrc->PreClustHead.u_NofClusters);
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumNearPreClusters,RSP1_PRECLUSTERLIST_V1::NumNearPreClusters ); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_BeamSpecPowLog,                                   0, sizeof(pDest->a_Clusters[i].a_BeamSpecPowLog));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   0.0f;
  }
}

__inline void v_Convert_v2_to_v1_FAR (RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pDest,
  const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc )
{
  // copy consistent header part
  pDest->PreClustHead.u_VersionNumber     = pSrc->PreClustHead.u_VersionNumber;
  pDest->PreClustHead.u_TimeStamp         = pSrc->PreClustHead.u_TimeStamp;
  pDest->PreClustHead.u_NofClusters       = pSrc->PreClustHead.u_NofClusters;
  pDest->PreClustHead.u_ClusterListValid  = pSrc->PreClustHead.u_ClusterListValid;

  // fill missing header data
  pDest->PreClustHead.u_RangeLimit        = pSrc->PreClustHead.u_RangeLimit;

  // copy clusters
  for (int i =0; i < _MINI( RSP1_PRECLUSTERLIST_V2::NumFarPreClusters,RSP1_PRECLUSTERLIST_V1::NumFarPreClusters ); i++  )
  {
    memcpy(  pDest->a_Clusters[i].a_BeamSpecCmplx,  pSrc->a_Clusters[i].a_BeamSpecCmplx, sizeof(pDest->a_Clusters[i].a_BeamSpecCmplx));
    memcpy(  pDest->a_Clusters[i].a_BeamSpecPowLog,                                   0, sizeof(pDest->a_Clusters[i].a_BeamSpecPowLog));
    memcpy(  pDest->a_Clusters[i].a_Pdh0,           pSrc->a_Clusters[i].a_Pdh0         , sizeof(pDest->a_Clusters[i].a_Pdh0));
    pDest->a_Clusters[i].CmplxRatioMonop.s_Imag =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Imag;
    pDest->a_Clusters[i].CmplxRatioMonop.s_Real =   pSrc->a_Clusters[i].CmplxRatioMonop.s_Real;
    pDest->a_Clusters[i].f_AngMonop             =   pSrc->a_Clusters[i].f_AngMonop;
    pDest->a_Clusters[i].f_IntBeamBin           =   pSrc->a_Clusters[i].f_IntBeamBin;
    pDest->a_Clusters[i].f_IntBeamBinWidth      =   0.0f;
    pDest->a_Clusters[i].f_IntDopplerBin        =   pSrc->a_Clusters[i].f_IntDopplerBin;
    pDest->a_Clusters[i].f_IntPowerLog          =   pSrc->a_Clusters[i].f_IntPowerLog;
    pDest->a_Clusters[i].f_IntRangeBin          =   pSrc->a_Clusters[i].f_IntRangeBin;
    pDest->a_Clusters[i].f_IntRangeBinLength    =   0.0f;
  }
}

long CConvRSP1PreClusterList::ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
    void *pPPortData,
    void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  unsigned int uiRecVersion = 0;
  unsigned char ucDoRCSCorrection = 0;
  bool bWorkaroundHandling = false;

  // retrieve dependency for being used
  bWorkaroundHandling = GetDeps(uiRecVersion, ucDoRCSCorrection);
  const unsigned __int32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned __int32*>(pPPortData)):(0);

  // If direct one-to-one copy possible do that
  if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))) &&
      (!(requestPortVersionInfo.Equals(&RSP1V6) && (uDataVer == 5u))) &&
      (bWorkaroundHandling == false))
  {
    *pOutData = pPPortData;
    ulOutSize = ulRPortSize;
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  else
  {
    // First branch to decide which version we are converting to

    // **************************************************************************************************************************
    // * Preclusters NEAR
    // **************************************************************************************************************************
    if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS))
    {
      // request port version V100_B (RSP1V100) - provide port version V100_A - A-Sample -> B-Sample
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS)) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V100.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 0x100u))
      {
        const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v100A_to_v100B_NEAR(m_NearV100B, *pSrc);
        *pOutData = &m_NearV100B;
        ulOutSize = sizeof(m_NearV100B);
        lRet = SIM_ERR_OK;
      }
    }
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS))
    {
      // request port version V100_A (RSP1V100) - provide port version V100_B - B-Sample -> A-Sample (not needed?)
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS)) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V100.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 0x100u))
      {
        const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v100B_to_v100A_NEAR(m_NearV100A, *pSrc);
        *pOutData = &m_NearV100A;
        ulOutSize = sizeof(m_NearV100B);
        lRet = SIM_ERR_OK;
      }
    }
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS))
    {
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V6_PR_EN - RCS Correction
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS)) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V6.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 6u))
      {
        const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v6pren_to_v62pren_NEAR_RCSWorkaround(m_NearV62pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_NearV62pren;
        ulOutSize = sizeof(m_NearV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS)) &&
        (uDataVer == 5u))
      {
        const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v5pren_to_v6pren_NEAR_RCSWorkaround(m_NearV6pren, *pSrc, uiRecVersion, 0);
        v_Convert_v6pren_to_v62pren_NEAR_RCSWorkaround(m_NearV62pren, m_NearV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_NearV62pren;
        ulOutSize = sizeof(m_NearV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version V4_PR_EN
      else if (ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS))
      {
        const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(m_NearV5pren, *pSrc, uiRecVersion, 0);
        v_Convert_v5pren_to_v6pren_NEAR(m_NearV6pren, m_NearV5pren);
        v_Convert_v6pren_to_v62pren_NEAR_RCSWorkaround(m_NearV62pren, m_NearV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_NearV62pren;
        ulOutSize = sizeof(m_NearV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version 5
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v2pren_to_v4pren_NEAR(&m_NearV4pren,pSrc);
        v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(m_NearV5pren, m_NearV4pren, uiRecVersion, 0);
        v_Convert_v5pren_to_v6pren_NEAR(m_NearV6pren,m_NearV5pren);
        v_Convert_v6pren_to_v62pren_NEAR_RCSWorkaround(m_NearV62pren, m_NearV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_NearV62pren;
        ulOutSize = sizeof(m_NearV62pren);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS))          // also RSP1_PRECLUSTERLIST_V6_PR_EN
    {
      // Check Request port version, because size of V5_PR_EN is equal to V6_PR_EN
      if (requestPortVersionInfo.Equals(&RSP1V6))
      {
        // request port version V6_PR_EN (RSP1V6) - provide port version V6_2_PR_EN - RCS Correction
        if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS)) &&
          (uDataVer == 6u))
        {
          const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          v_Convert_v62pren_to_v6pren_NEAR_RCSWorkaround(m_NearV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = &m_NearV6pren;
          ulOutSize = sizeof(m_NearV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS)) &&
          (uDataVer == 5u))
        {
          const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          v_Convert_v5pren_to_v6pren_NEAR_RCSWorkaround(m_NearV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = &m_NearV6pren;
          ulOutSize = sizeof(m_NearV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version V4_PR_EN
        else if (ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pIntMed = &m_NearV5pren;
          v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(*pIntMed, *pSrc, uiRecVersion, ucDoRCSCorrection);
          v_Convert_v5pren_to_v6pren_NEAR(m_NearV6pren, *pIntMed);
          *pOutData = &m_NearV6pren;
          ulOutSize = sizeof(m_NearV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version V2_PR_EN
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS)))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pIntMed1 = &m_NearV4pren;
          RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pIntMed2 = &m_NearV5pren;
          v_Convert_v2pren_to_v4pren_NEAR(pIntMed1,pSrc);
          v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(*pIntMed2, *pIntMed1, uiRecVersion, 0);
          v_Convert_v5pren_to_v6pren_NEAR(m_NearV6pren,*pIntMed2);
          *pOutData = &m_NearV6pren;
          ulOutSize = sizeof(m_NearV6pren);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // No conversion possible
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }

      }
      else
      {
        RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pDest = &m_NearV5pren;
        if (uDataVer == 6u)
        {
          // Conversion from V6_PR_EN to V5_PR_EN
          // ToDo:
        }
        // request port version V5_PR_EN - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS)))
        {
          const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          v_Convert_v5_to_v5_NEAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version V5_PR_EN - provide port version V4_PR_EN
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS)))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version V5_PR_EN - provide port version 5
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS)))
        {
          RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pIntMed = &m_NearV4pren;
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
          v_Convert_v2pren_to_v4pren_NEAR(pIntMed,pSrc);
          v_Convert_v4pren_to_v5pren_NEAR_RCSWorkaround(*pDest, *pIntMed, uiRecVersion, 0);
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
    }
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS))
    {
      RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS * const pDest = &m_NearV4pren;
      // request port version V4_PR_EN - provide port version V5_PR_EN
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v5pren_to_v4pren_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version V4_PR_EN - provide port version 5
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v2pren_to_v4pren_NEAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS)))
    {
      RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pDest = &m_NearV4;
      // request port version 4 - provide port version 4 - RCS Correction
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v4_to_v4_NEAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 3
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v3_to_v4_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v2_to_v4_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v1_to_v4_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 0
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v4_NEAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS)))
    {
      RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS * const pDest = &m_NearV3;
      // request port version 3 - provide port version 4
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS)))
      {
        const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS*>(pPPortData);
        v_Convert_v4_to_v3_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 0
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v3_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v1_to_v3_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v2_to_v3_NEAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)))
    {
      // Request port has layout of version 2 near, convert to that
      RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pDest = &m_NearV2;
      // request port version 2 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v2_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 2 - provide port version 1
      else  if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v1_to_v2_NEAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear)))
    {
      // Request port has layout of version 1 far, convert to that
      RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear * const pDest = &m_NearV1;
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v0_to_v1_NEAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 1 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear*>(pPPortData);
        v_Convert_v2_to_v1_NEAR(pDest,pSrc);
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
    // **************************************************************************************************************************
    // * Preclusters FAR
    // **************************************************************************************************************************
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS))
    {
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V6_PR_EN - RCS Correction
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS)) &&
        ((pProvidePortVersionInfo == NULL) || (RSP1V6.Equals(pProvidePortVersionInfo))) &&
        (uDataVer == 6u))
      {
        const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v6pren_to_v62pren_FAR_RCSWorkaround(m_FarV62pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_FarV62pren;
        ulOutSize = sizeof(m_FarV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS)) &&
        (uDataVer == 5u))
      {
        const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v5pren_to_v6pren_FAR_RCSWorkaround(m_FarV6pren, *pSrc, uiRecVersion, 0);
        v_Convert_v6pren_to_v62pren_FAR_RCSWorkaround(m_FarV62pren, m_FarV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_FarV62pren;
        ulOutSize = sizeof(m_FarV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version V4_PR_EN
      else if (ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS))
      {
        const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(m_FarV5pren, *pSrc, uiRecVersion, 0);
        v_Convert_v5pren_to_v6pren_FAR(m_FarV6pren, m_FarV5pren);
        v_Convert_v6pren_to_v62pren_FAR_RCSWorkaround(m_FarV62pren, m_FarV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_FarV62pren;
        ulOutSize = sizeof(m_FarV62pren);
        lRet = SIM_ERR_OK;
      }
      // request port version V6_2_PR_EN - provide port version 5
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)))
      {
        const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v2pren_to_v4pren_FAR(&m_FarV4pren,pSrc);
        v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(m_FarV5pren, m_FarV4pren, uiRecVersion, 0);
        v_Convert_v5pren_to_v6pren_FAR(m_FarV6pren,m_FarV5pren);
        v_Convert_v6pren_to_v62pren_FAR_RCSWorkaround(m_FarV62pren, m_FarV6pren, uiRecVersion, ucDoRCSCorrection);
        *pOutData = &m_FarV62pren;
        ulOutSize = sizeof(m_FarV62pren);
        lRet = SIM_ERR_OK;
      }
      else
      {
        // No conversion possible
        lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
      }
    }
    else if (ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS))          // also RSP1_PRECLUSTERLIST_V6_PR_EN
    {
      // Check Request port version, because size of V5_PR_EN is equal to V6_PR_EN
      if (requestPortVersionInfo.Equals(&RSP1V6))
      {
        // request port version V6_PR_EN (RSP1V6) - provide port version V6_2_PR_EN - RCS Correction
        if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS)) &&
          (uDataVer == 6u))
        {
          const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v62pren_to_v6pren_FAR_RCSWorkaround(m_FarV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = &m_FarV6pren;
          ulOutSize = sizeof(m_FarV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN (RSP1V6) - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS)) &&
          (uDataVer == 5u))
        {
          const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v5pren_to_v6pren_FAR_RCSWorkaround(m_FarV6pren, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = &m_FarV6pren;
          ulOutSize = sizeof(m_FarV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version V4_PR_EN
        else if (ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pIntMed = &m_FarV5pren;
          v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(*pIntMed, *pSrc, uiRecVersion, ucDoRCSCorrection);
          v_Convert_v5pren_to_v6pren_FAR(m_FarV6pren, *pIntMed);
          *pOutData = &m_FarV6pren;
          ulOutSize = sizeof(m_FarV6pren);
          lRet = SIM_ERR_OK;
        }
        // request port version V6_PR_EN - provide port version 5
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pIntMed1 = &m_FarV4pren;
          RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pIntMed2 = &m_FarV5pren;
          v_Convert_v2pren_to_v4pren_FAR(pIntMed1,pSrc);
          v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(*pIntMed2, *pIntMed1, uiRecVersion, 0);
          v_Convert_v5pren_to_v6pren_FAR(m_FarV6pren,*pIntMed2);
          *pOutData = &m_FarV6pren;
          ulOutSize = sizeof(m_FarV6pren);
          lRet = SIM_ERR_OK;
        }
        else
        {
          // No conversion possible
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
        }
      }
      else
      {
        RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pDest = &m_FarV5pren;
        if (uDataVer == 6u)
        {
          // Conversion from V6_PR_EN to V5_PR_EN
          // ToDo:
        }
        // request port version V5_PR_EN - provide port version V5_PR_EN - RCS Correction
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v5_to_v5_FAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version V5_PR_EN - provide port version V4_PR_EN
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version V5_PR_EN - provide port version 5
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)))
        {
          RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pIntMed = &m_FarV4pren;
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v2pren_to_v4pren_FAR(pIntMed,pSrc);
          v_Convert_v4pren_to_v5pren_FAR_RCSWorkaround(*pDest, *pIntMed, uiRecVersion, 0);
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
    }
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS)))
    {
      // Sizes are the same for RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS, RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS and
      // RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS. Handle V10_PR by requestPortVersionInfo
      if (requestPortVersionInfo.Equals(&RSP1V6))
      {
        RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS * const pDest = &m_FarV6pren;
        if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS)) &&
          (uDataVer != 6u))
        {
          // request port version 10 - provide port version (4), 6, 7 - RCS Correction
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v4pren_to_v6pren_FAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version 10 - provide port version 5
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v2pren_to_v6pren_FAR(pDest,pSrc);
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
      else
      {
        RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pDest = &m_FarV4pren;
        // request port version 6 - provide port version 6 - RCS Correction
        if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v4pren_to_v4pren_FAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
          *pOutData = pDest;
          ulOutSize = sizeof(*pDest);
          lRet = SIM_ERR_OK;
        }
        // request port version 6 - provide port version 5
        else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS)))
        {
          const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS*>(pPPortData);
          v_Convert_v2pren_to_v4pren_FAR(pDest,pSrc);
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
    }
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS)))
    {
      RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pDest = &m_FarV4;
      // request port version 4 - provide port version 4 - RCS Correction
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS)))
      {
        const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v4_to_v4_FAR_RCSWorkaround(*pDest, *pSrc, uiRecVersion, ucDoRCSCorrection);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 3
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS)))
      {
        const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v3_to_v4_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v2_to_v4_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v1_to_v4_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 4 - provide port version 0
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v0_to_v4_FAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS)))
    {
      RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS * const pDest = &m_FarV3;
      // request port version 3 - provide port version 4
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS)))
      {
        const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS*>(pPPortData);
        v_Convert_v4_to_v3_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v2_to_v3_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 1
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v1_to_v3_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 3 - provide port version 0
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v0_to_v3_FAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)))
    {
      // Request port has layout of version 2 far, convert to that
      RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pDest = &m_FarV2;
      // request port version 2 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v0_to_v2_FAR(pDest,pSrc);
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 2 - provide port version 1
      else  if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v1_to_v2_FAR(pDest,pSrc);
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
    else if ((ulRPortSize == sizeof(RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar)) &&
        (
         (requestPortVersionInfo.Equals(&BASE_VERSION)) ||
         (requestPortVersionInfo.Equals(&RSP1V1)) ||
         (requestPortVersionInfo.Equals(&RSP1V2)) ||
         (requestPortVersionInfo.Equals(&RSP1V3)) ||
         (requestPortVersionInfo.Equals(&RSP1V4)) ||
         (requestPortVersionInfo.Equals(&RSP1V5)) ||
         (requestPortVersionInfo.Equals(&RSP1V6))
        ))
    {
      // Request port has layout of version 1 far, convert to that
      RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar * const pDest = &m_FarV1;

      // request port version 1 - provide port version 0
      if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v0_to_v1_FAR (pDest, pSrc );
        *pOutData = pDest;
        ulOutSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      // request port version 1 - provide port version 2
      else if ((ulPPortSize == sizeof(RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar)))
      {
        const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar * const pSrc = reinterpret_cast<const RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar*>(pPPortData);
        v_Convert_v2_to_v1_FAR(pDest, pSrc);
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
long CConvRSP1PreClusterList::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(m_NearV100B)) &&
      (RSP1V100.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V100_B::RSP_t_PreClusterListNS & Dest = m_NearV100B;
      InitPreClusterHeader(Dest, 0x100u);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV100A)) &&
      (RSP1V100.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V100_A::RSP_t_PreClusterListNS & Dest = m_NearV100A;
      InitPreClusterHeader(Dest, 0x100u);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV62pren)) &&
      (RSP1V6.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V6_2_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV62pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV6pren)) &&
      (RSP1V6.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV6pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV6pren)) &&
      (RSP1V6.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV6pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV5pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV5pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV5pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V5_PR_EN::RSP_t_PreClusterListNS & Dest = m_NearV5pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV4pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV4pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV4pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterListNS & Dest = m_NearV4pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV2pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListFS & Dest = m_FarV2pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV2pren)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V2_PR_EN::RSP_t_PreClusterListNS & Dest = m_NearV2pren;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV4)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListFS & Dest = m_FarV4;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV4)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V4::RSP_t_PreClusterListNS & Dest = m_NearV4;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV3)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListFS & Dest = m_FarV3;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV3)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V3::RSP_t_PreClusterListNS & Dest = m_NearV3;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV2)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListFar & Dest = m_FarV2;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV2)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V2::RSP_t_PreClusterListNear & Dest = m_NearV2;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV1)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListFar & Dest = m_FarV1;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV1)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterListNear & Dest = m_NearV1;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_FarV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListFar & Dest = m_FarV0;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(m_NearV0)) &&
      (BASE_VERSION.Equals(&requestPortVersionInfo)))
    {
      RSP1_PRECLUSTERLIST_V0::RSP_t_PreClusterListNear & Dest = m_NearV0;
      InitPreClusterHeader(Dest, 0);
      InitPreClusterList(Dest);
      *pDefaultData = &Dest;
      ulDefaultSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
  }
  return lRet;
}

// used to check if an unversioned PPort is compatible with a certain version of RPort
bool CConvRSP1PreClusterList::IsVersionCompatibleWithType(
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
bool CConvRSP1PreClusterList::AreVersionsCompatible(
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
IConverter * CreateRSP1PreClusterListConvClass(void)
{
  return new CConvRSP1PreClusterList();
}