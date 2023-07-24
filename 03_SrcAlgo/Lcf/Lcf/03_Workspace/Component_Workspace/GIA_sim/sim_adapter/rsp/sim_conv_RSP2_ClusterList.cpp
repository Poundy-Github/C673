/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            sim_conv_RSP2_ClusterList.cpp

  DESCRIPTION:          Converter for far/near RSP2 cluster list

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        31.07.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: sim_conv_RSP2_ClusterList.cpp  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:39CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rsp/project.pj
  CHANGES:              Revision 1.11 2016/08/17 14:06:15CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + ARS510 V100 (0x100) A-Sample to B-Sample Conversion
  CHANGES:              Revision 1.10 2014/12/04 10:16:11CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + RSP2CluV7:
  CHANGES:              ARS400_PR: /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/AlgoTypesAUTOSAR4.ecuextract&revision=1.63
  CHANGES:              ARS400_EN: /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/AlgoTypesAUTOSAR4.ecuextract&revision=1.26.1.25
  CHANGES:              --- Added comments ---  berndtt1 [Dec 4, 2014 10:21:19 AM CET]
  CHANGES:              Change Package : 221167:41 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.9 2014/08/14 07:18:37CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Bugfix: added break to case 6
  CHANGES:              --- Added comments ---  berndtt1 [Aug 14, 2014 7:31:25 AM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.8 2014/06/30 10:05:40CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + RSP2CluV6: ARS400_PR: rte_type.h revision 1.50 (SW_ARS400_PR_RTE_ALGOECUEXTRACT_1.56)
  CHANGES:              --- Added comments ---  berndtt1 [Jun 30, 2014 10:30:41 AM CEST]
  CHANGES:              Change Package : 244114:2 http://mks-psad:7002/im/viewissue?selection=244114
  CHANGES:              Revision 1.7 2014/03/20 13:50:19CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              + RSP2CluV5: ARS400_PR: rte_type.h revision 1.37
  CHANGES:              --- Added comments ---  berndtt1 [Mar 20, 2014 3:29:53 PM CET]
  CHANGES:              Change Package : 221167:3 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.6 2014/01/24 07:58:36CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added conversion V4 to V3
  CHANGES:              --- Added comments ---  berndtt1 [Jan 24, 2014 8:02:31 AM CET]
  CHANGES:              Change Package : 208935:8 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.5 2014/01/17 14:27:09CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Bugfix: conversion from V3 of cluster list fell through into V4 branch, through second bug of not using proper V4 header and cluster
  CHANGES:              size check this did not result in a failed conversion return value (nasty hard to find bug)
  CHANGES:              --- Added comments ---  ungvaryg [Jan 17, 2014 2:27:09 PM CET]
  CHANGES:              Change Package : 213726:1 http://mks-psad:7002/im/viewissue?selection=213726
  CHANGES:              Revision 1.4 2014/01/17 08:22:23CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Added version 4
  CHANGES:              Additional elements in header (RSP_t_ClustListHeader)
  CHANGES:              - float f_MaximumSensorRange;
  CHANGES:              - float f_MinimumSensorRange;
  CHANGES:              - boolean b_ExtraDistInfluencedByLargePeak;
  CHANGES:              - boolean b_MaxRangeInfluencedByLargePeak;
  CHANGES:              - u_Dummy_array_t_10 u_Dummy;
  CHANGES:              --- Added comments ---  berndtt1 [Jan 17, 2014 8:48:30 AM CET]
  CHANGES:              Change Package : 208935:8 http://mks-psad:7002/im/viewissue?selection=208935
  CHANGES:              Revision 1.3 2013/11/07 14:56:03CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              Extended for Version 3.
  CHANGES:              Version number HACK is excluded only for ClusterListNS by checking the size.
  CHANGES:              Requested by ARS400 Entry. Must perhaps be adapted to include ClusterListFS.
  CHANGES:              --- Added comments ---  berndtt1 [Nov 7, 2013 3:00:42 PM CET]
  CHANGES:              Change Package : 193430:7 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.2 2013/08/02 19:17:57CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Fix file header and remove unnecessary code
  CHANGES:              Add semi-proper handling for B0 cluser lists (accept version 4)
  CHANGES:              Add hack for output timestamp/cycle counter (note: will always auto-change from cycle to cycle)
  CHANGES:              --- Added comments ---  ungvaryg [Aug 2, 2013 7:17:57 PM CEST]
  CHANGES:              Change Package : 190143:3 http://mks-psad:7002/im/viewissue?selection=190143
  CHANGES:              Revision 1.1 2013/08/02 11:10:51CEST Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rsp/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_adapter_cfg.h"
#include "sim_conv_RSP2_ClusterList.h"
#include "sim_versioninfo_impl.h"
#include "interface_base.h"

#define MIN(x,y) (((x)<(y))?(x):(y))

typedef enum eAlgoSignalState_t {
  AL_SIG_STATE_INIT=0,
  AL_SIG_STATE_OK=1,
  AL_SIG_STATE_INVALID=2,
} eAlgoSignalState_t;

#pragma warning (push)
#pragma warning (disable : 4200)       // warning C4200: nonstandard extension used : zero-sized array in struct/union
                                       // Cannot generate copy-ctor or copy-assignment operator when UDT contains a zero-sized array

//
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.27.1.5.2.5
// (/nfs/projekte1/PROJECTS/ARS400/05_Software/B0_Sample/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 B0)
//
namespace RSP2CluV1                                                  /* Length = 32788, 14356 */
{
  typedef float32 a_AzAng_array_t[2];/* azimuth angle (main reflection), 2 hypotesis possible values sorted by hypothesis likelihood (main hypothesis first) */

  typedef struct t_Complex16
  {
    sint16 s_Real;
    sint16 s_Imag;
  } t_Complex16; /* signed 16 bit integer complex */

  typedef uint8 a_Pdh0_array_t[7];/* False alarm probability: ArrEntry
                                    0 = nacom
                                    1 = ramp artifact
                                    2 = Interference
                                    3 = sidelobe  
                                    4 = tdb 
                                    5 = tbd
                                    6 = tbd @min:0 @max:100 */

  typedef struct RSP_t_Cluster
  {
    float32 f_VrelRad;
    float32 f_RangeRad;
    float32 f_RangeExtens;
    a_AzAng_array_t a_AzAng;
    float32 f_AzAngExtens;
    float32 f_AzAngMidDiff;
    t_Complex16 t_ElAngCplx;
    float32 f_ElAng;
    float32 f_RcsRaw;
    float32 f_AzAngVar;
    float32 f_VrelRadVar;
    float32 f_RangeRadVar;
    float32 f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    uint8 u_ElAngQuality;
  } RSP_t_Cluster;

  typedef struct RSP_t_ClustListHeader
  {
    uint32 u_VersionNumber;
    uint8 u_ClusterListValid;
    uint8 u_reserved[3];
    uint32 u_NofClusters;
    float32 f_AmbFreeDopplerRange;
    float32 f_RangeLimit;
  } RSP_t_ClustListHeader;

  typedef RSP_t_Cluster a_Clusters_array_t_4[512];/* cluster array */

  typedef RSP_t_Cluster a_Clusters_array_t_2[224];/* cluster array */

  typedef struct RSP_t_ClusterListFar
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_ClusterListFar;  /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP_ENV @vname:RSP2_ClusterListFar */

  typedef struct RSP_t_ClusterListNear
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNear; /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP_ENV @vname:RSP2_ClusterListNear */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster         a_Clusters[];
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 1);
};

//
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.14.1.4
// (/nfs/projekte1/SW/SW_ARS4xx/SW_ARS400_PR/M11_Appl/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 B1)
//
namespace RSP2CluV2                                                  /* Length = 57636, 26916 */
{
  static const uint32 RSP_OUTP_CLLST_NEAR_INTFVER = 2u;
  static const uint32 RSP_OUTP_CLLST_FAR_INTFVER  = 2u;

  typedef uint16 AlgoCycleCounter_t;            /* Algo cycle counter @min:0 @max:65535 */
  typedef uint32 AlgoDataTimeStamp_t;           /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */
  typedef uint8 AlgoSignalState_t;              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */

  typedef RSP2CluV1::a_AzAng_array_t a_AzAng_array_t;
  typedef RSP2CluV1::a_Pdh0_array_t a_Pdh0_array_t;

  typedef struct t_Complex8
  {
    sint8 s_Real;
    sint8 s_Imag;
  } t_Complex8; /* signed 8 bit integer complex */

  typedef struct RSP_t_Cluster
  {
    float32 f_VrelRad;
    float32 f_RangeRad;
    float32 f_RangeExtens;
    a_AzAng_array_t a_AzAng;
    float32 f_AzAngExtens;
    float32 f_AzAngMidDiff;
    t_Complex8 ComplMaxBeam;
    t_Complex8 ComplMonoPulseBeam;
    float32 f_RcsRaw;
    float32 f_AzAngVar;
    float32 f_VrelRadVar;
    float32 f_RangeRadVar;
    float32 f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    uint8 u_ElevAngQuality;
  } RSP_t_Cluster;

  typedef RSP_t_Cluster a_Clusters_array_t_1[448];/* cluster array */

  typedef RSP_t_Cluster a_Clusters_array_t_4[960];/* cluster array */

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t; /* Common header for all structured data types */

  typedef struct RSP_t_ClustListHeader
  {
    uint32 u_VersionNumber;
    SignalHeader_t sSigHeader;
    AlgoDataTimeStamp_t u_TimeStamp;
    float32 f_AmbFreeDopplerRange;
    uint32 u_NofClusters;
    float32 f_RangeGateLength;
    float32 f_RangeLimit;
  } RSP_t_ClustListHeader;

  typedef struct
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;     /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP_ENV @vname:RSP2_ClusterListFS */

  typedef struct
  {
    RSP_t_ClusterListFS RSP_ClusterListFS;
    uint32 u_MiscSignature;
  } RSP_t_ClusterListFSMisc;

  typedef struct
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;     /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster         a_Clusters[];
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 2);
};

//
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.5.1.3.1.7
// (/nfs/projekte1/SW/SW_ARS4xx/SW_ARS4D0/M11_Appl/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 D0 (ARS400Entry))
//
namespace RSP2CluV3                                                  /* Length = 65572 */
{
  typedef unsigned char a_Pdh0_array_t_0[8];                         /* False alarm probability: ArrEntry: 0 = nacom, 1 = ramp artifact, 2 = Interference, 3 = sidelobe, 4 = tdb, 5 = tbd, 6 = tbd, 7 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    RSP2CluV2::AlgoDataTimeStamp_t u_TimeStamp;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    signed char s_Real;
    signed char s_Imag;
  } t_Complex8;                                                      /* signed 8 bit integer complex */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    float f_AzAngExtens;
    float f_AzAngMidDiff;
    t_Complex8 ComplMaxBeam;
    t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    a_Pdh0_array_t_0 a_Pdh0;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

  typedef RSP_t_Cluster a_Clusters_array_t_2[1024];                  /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster         a_Clusters[];
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 3);
} // end of namespace RSP2CluV3

//
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.5.1.3.1.13
// (/nfs/projekte1/SW/SW_ARS4xx/SW_ARS4D2/M11_Appl/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 D2 (ARS400Entry, ARS400_EN))
//
namespace RSP2CluV4                                                  /* Length = 65584 (also 61488 and 28720) */
{
  typedef unsigned char u_Dummy_array_t_10[2];                       /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    RSP2CluV2::AlgoDataTimeStamp_t u_TimeStamp;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t_10 u_Dummy;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    float f_AzAngExtens;
    float f_AzAngMidDiff;
    RSP2CluV3::t_Complex8 ComplMaxBeam;
    RSP2CluV3::t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    RSP2CluV3::a_Pdh0_array_t_0 a_Pdh0;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

  typedef RSP_t_Cluster a_Clusters_array_t_2[1024];                  /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 4);
} // end of namespace RSP2CluV4

//
// Declaration of RSP2 cluster list(s) taken from AlgoTypesAUTOSAR4.ecuextract revision 1.46
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/project.pj&developmentPath=ARS400_PR&selection=AlgoTypesAUTOSAR4.ecuextract
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.37
// (/nfs/projekte1/PROJECTS/ARS400_PR/06_Algorithm/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// ARS400_PR
//
namespace RSP2CluV5                                                  /* Length = 53808, 25136 */
{
  typedef unsigned char u_Dummy_array_t_11[2];                       /* [Satisfies_rte sws 1189] */
  typedef unsigned char a_Pdh0_array_t[7];                           /* False alarm probability: ArrEntry:   0 = nacom; 1 = ramp artifact; 2 = Interference; 3 = sidelobe; 4 = tdb; 5 = tbd; 6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    RSP2CluV2::AlgoDataTimeStamp_t u_TimeStamp;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t_11 u_Dummy;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    RSP2CluV3::t_Complex8 ComplMaxBeam;
    RSP2CluV3::t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    unsigned char u_MultibleTargetProb;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

  typedef RSP_t_Cluster a_Clusters_array_t_4[960];                   /* cluster array */	/* [Satisfies_rte sws 1189] */

  typedef RSP_t_Cluster a_Clusters_array_t_1[448];                   /* cluster array */	/* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;                                             /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 5);
} // end of namespace RSP2CluV5

//
// Declaration of RSP2 cluster list(s) taken from SW_ARS400_PR_RTE_ALGOECUEXTRACT_1.56
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.56
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.50
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/SW/SW%5fARS4xx/SW%5fARS400%5fPR/M11%5fAppl/04%5fEngineering/01%5fSource%5fCode/common/rte/project.pj&selection=Rte%5fType.h&revision=1.50
// ARS400_PR
// Remark: The only difference to RSP2CluV5 is the size of the near cluster array, which changed from 960 to 640
//         The namespace is implemented to get static const CVersionInfoImpl Version(0, 0, 6);
namespace RSP2CluV6                                                  /* Length = 35888, 25136 */
{
  typedef unsigned char u_Dummy_array_t_11[2];                       /* [Satisfies_rte sws 1189] */
  typedef unsigned char a_Pdh0_array_t[7];                           /* False alarm probability: ArrEntry:   0 = nacom; 1 = ramp artifact; 2 = Interference; 3 = sidelobe; 4 = tdb; 5 = tbd; 6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    RSP2CluV2::AlgoDataTimeStamp_t u_TimeStamp;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t_11 u_Dummy;
  } RSP_t_ClustListHeader;

  typedef RSP2CluV5::RSP_t_Cluster a_Clusters_array_t_4[640];        /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP2CluV5::RSP_t_Cluster a_Clusters_array_t_1[448];        /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP2CluV5::RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;                                             /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP2CluV5::RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP2CluV5::RSP_t_ClustListHeader ClustListHead;
    RSP2CluV5::RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 6);
} // end of namespace RSP2CluV6

//
// Declaration of RSP2 cluster list(s) taken from 
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.63
// ARS400_PR
// Declaration of RSP2 cluster list(s) taken from 
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.26.1.25
// ARS400_EN
// Remark: The only difference to RSP2CluV6 is that u_MultipleTargetProb is now included in a_Pdh0_array_t
//         The namespace is implemented to get static const CVersionInfoImpl Version(0, 0, 7);
//         The switching for CFG_ARS400_EN_SWITCH is not neccessary because the amount of clusters is calculated during ConvertData(...)
namespace RSP2CluV7                                                  /* Length = PR: 35888, 25136; EN: 43056 */
{
  typedef unsigned char u_Dummy_array_t_11[2];                       /* [Satisfies_rte sws 1189] */
  typedef unsigned char a_Pdh0_array_t[8];                           /* False alarm probability: ArrEntry:   0 = nacom; 1 = ramp artifact; 2 = Interference; 3 = sidelobe; 4 = tdb; 5 = tbd; 6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    RSP2CluV2::AlgoDataTimeStamp_t u_TimeStamp;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t_11 u_Dummy;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    RSP2CluV3::t_Complex8 ComplMaxBeam;
    RSP2CluV3::t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef RSP_t_Cluster a_Clusters_array_t_4[768];                   /* cluster array */ /* [Satisfies_rte sws 1189] */
#else
  typedef RSP_t_Cluster a_Clusters_array_t_4[640];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_Cluster a_Clusters_array_t_1[448];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;                                             /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListFS */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP2CluV5::RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP2CluV5::RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 0, 7);
} // end of namespace RSP2CluV7

//
// Declaration of RSP2 cluster list(s) taken from 
// http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/06_Algorithm/04_Engineering/00_CodeGen/algo/rsp/core/project.pj&selection=rsp_algo_interface_types.xls&revision=1.12.1.1
// ARS510
// Remark: The difference to RSP2CluV7 is: RSP_t_ClustListHeader.u_TimeStamp is deleted and a_Pdh0_array_t is unsigned __int16
//         The namespace is implemented to get static const CVersionInfoImpl Version(0, 0, 7);
//         The switching for CFG_ARS400_EN_SWITCH is not neccessary because the amount of clusters is calculated during ConvertData(...)
namespace RSP2CluV100_A                                              /* Length = PR: , ; EN:  ; ARS510: 49196 */
{
  typedef unsigned __int8 u_Dummy_array_t[2];                        /* [Satisfies_rte sws 1189] */
  typedef unsigned __int16 a_Pdh0_array_t[16];                       /* False alarm probability: ArrEntry:   0 = nacom; 1 = ramp artifact; 2 = Interference; 3 = sidelobe; 4 = tdb; 5 = tbd; 6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t u_Dummy;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    RSP2CluV3::t_Complex8 ComplMaxBeam;
    RSP2CluV3::t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef RSP_t_Cluster a_Clusters_array_t_4[768];                   /* cluster array */ /* [Satisfies_rte sws 1189] */
#else
  typedef RSP_t_Cluster a_Clusters_array_t_4[640];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_Cluster a_Clusters_array_t_1[448];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;                                             /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListFS */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 1, 0);
} // end of namespace RSP2CluV100_A

//
// Declaration of RSP2 cluster list(s) taken from 
// http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/06_Algorithm/04_Engineering/00_CodeGen/algo/rsp/core/project.pj&selection=rsp_algo_interface_types.xls&revision=1.18
// ARS510
// Remark: The difference to RSP2CluV100_A is: a_Pdh0_array_t is unsigned __int8
//         The namespace is implemented to get static const CVersionInfoImpl Version(0, 0, 7);
//         The switching for CFG_ARS400_EN_SWITCH is not neccessary because the amount of clusters is calculated during ConvertData(...)
namespace RSP2CluV100_B                                              /* Length = PR: , ; EN:  ; ARS510: 43052 */
{
  typedef unsigned __int8 u_Dummy_array_t[2];                        /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 a_Pdh0_array_t[16];                        /* False alarm probability: ArrEntry:   0 = nacom; 1 = ramp artifact; 2 = Interference; 3 = sidelobe; 4 = tdb; 5 = tbd; 6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP2CluV2::SignalHeader_t sSigHeader;
    float f_AmbFreeDopplerRange;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MaximumSensorRange;
    float f_MinimumSensorRange;
    boolean b_ExtraDistInfluencedByLargePeak;
    boolean b_MaxRangeInfluencedByLargePeak;
    u_Dummy_array_t u_Dummy;
  } RSP_t_ClustListHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_VrelRad;
    float f_RangeRad;
    float f_RangeExtens;
    RSP2CluV1::a_AzAng_array_t a_AzAng;
    RSP2CluV3::t_Complex8 ComplMaxBeam;
    RSP2CluV3::t_Complex8 ComplMonoPulseBeam;
    float f_RcsRaw;
    float f_AzAngVar;
    float f_VrelRadVar;
    float f_RangeRadVar;
    float f_RangeExtrapol;
    a_Pdh0_array_t a_Pdh0;
    unsigned short u_IdxPreCluster;
    unsigned short u_ByteAlignment;
  } RSP_t_Cluster;

#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef RSP_t_Cluster a_Clusters_array_t_4[768];                   /* cluster array */ /* [Satisfies_rte sws 1189] */
#else
  typedef RSP_t_Cluster a_Clusters_array_t_4[640];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_Cluster a_Clusters_array_t_1[448];                   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_ClusterListFS;                                             /* @vaddr:0x06040000 @vaddr_defs: RSP2_VADDR_CLU_LST_FAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListFS */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_ClustListHeader ClustListHead;
    a_Clusters_array_t_4 a_Clusters;
  } RSP_t_ClusterListNS;                                             /* @vaddr:0x06050000 @vaddr_defs: RSP2_VADDR_CLU_LST_NEAR @cycleid:RSP2_ENV @vname:RSP2_ClusterListNS */

  typedef struct RSP_t_GenClusterList
  {
    RSP_t_ClustListHeader ClustListHead;
    RSP_t_Cluster a_Clusters[]; 
  } RSP_t_GenClusterList;

  static const CVersionInfoImpl Version(0, 1, 0);
} // end of namespace RSP2CluV100_B




#pragma warning (pop)

//
// Helper functions
//
float32 DeduceRgLenFromRange(float32 fRange)
{
  return fRange * (1.f/128.f);
}

//
// Main RSP2 cluster list conversion class
//

class CConvRsp2CluList : public CSimConverterBase
{
  size_t  m_uAllocSize;
  void *  m_pAllocBuffer;
  uint32  m_uiLastTimeStamp;
  uint32  m_uiLastCycCnt;

  void ConvertHeaderV1ToV3(RSP2CluV3::RSP_t_ClustListHeader & Dest, const RSP2CluV1::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 3;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = m_uiLastTimeStamp;
    m_uiLastTimeStamp += 100000;
    //Dest.sSigHeader.uiMeasurementCounter = ;
    Dest.sSigHeader.uiCycleCounter = m_uiLastCycCnt;
    m_uiLastCycCnt++;
    Dest.sSigHeader.eSigStatus  = ((Source.u_ClusterListValid == 1)?AL_SIG_STATE_OK:AL_SIG_STATE_INVALID);
    // Fill rest of fields
    Dest.u_TimeStamp            = Dest.sSigHeader.uiTimeStamp;  // Directly re-used signal header timestamp already filled above
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = DeduceRgLenFromRange(Source.f_RangeLimit);
    Dest.f_RangeLimit           = Source.f_RangeLimit;
  };
  void ConvertHeaderV2ToV3(RSP2CluV3::RSP_t_ClustListHeader & Dest, const RSP2CluV2::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 3;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
  };
  void ConvertHeaderV1ToV2(RSP2CluV2::RSP_t_ClustListHeader & Dest, const RSP2CluV1::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 2;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp           = m_uiLastTimeStamp;
    m_uiLastTimeStamp += 100000;
    //Dest.sSigHeader.uiMeasurementCounter = ;
    Dest.sSigHeader.uiCycleCounter        = m_uiLastCycCnt;
    m_uiLastCycCnt++;
    Dest.sSigHeader.eSigStatus            = ((Source.u_ClusterListValid == 1)?AL_SIG_STATE_OK:AL_SIG_STATE_INVALID);
    // Fill rest of fields
    Dest.u_TimeStamp            = Dest.sSigHeader.uiTimeStamp;  // Directly re-used signal header timestamp already filled above
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = DeduceRgLenFromRange(Source.f_RangeLimit);
    Dest.f_RangeLimit           = Source.f_RangeLimit;
  };
  void ConvertHeaderV1ToV4(RSP2CluV4::RSP_t_ClustListHeader & Dest, const RSP2CluV1::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 4;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp           = m_uiLastTimeStamp;
    m_uiLastTimeStamp += 100000;
    //Dest.sSigHeader.uiMeasurementCounter = ;
    Dest.sSigHeader.uiCycleCounter        = m_uiLastCycCnt;
    m_uiLastCycCnt++;
    Dest.sSigHeader.eSigStatus            = ((Source.u_ClusterListValid == 1)?AL_SIG_STATE_OK:AL_SIG_STATE_INVALID);
    // Fill rest of fields
    Dest.u_TimeStamp            = Dest.sSigHeader.uiTimeStamp;  // Directly re-used signal header timestamp already filled above
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = DeduceRgLenFromRange(Source.f_RangeLimit);
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  void ConvertHeaderV1ToV5(RSP2CluV5::RSP_t_ClustListHeader & Dest, const RSP2CluV1::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 5;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = m_uiLastTimeStamp;
    m_uiLastTimeStamp += 100000;
    //Dest.sSigHeader.uiMeasurementCounter = ;
    Dest.sSigHeader.uiCycleCounter = m_uiLastCycCnt;
    m_uiLastCycCnt++;
    Dest.sSigHeader.eSigStatus  = ((Source.u_ClusterListValid == 1)?AL_SIG_STATE_OK:AL_SIG_STATE_INVALID);
    // Fill rest of fields
    Dest.u_TimeStamp            = Dest.sSigHeader.uiTimeStamp;  // Directly re-used signal header timestamp already filled above
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = DeduceRgLenFromRange(Source.f_RangeLimit);
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  void ConvertHeaderV2ToV4(RSP2CluV4::RSP_t_ClustListHeader & Dest, const RSP2CluV2::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 4;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  void ConvertHeaderV2ToV5(RSP2CluV5::RSP_t_ClustListHeader & Dest, const RSP2CluV2::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 5;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  void ConvertHeaderV3ToV4(RSP2CluV4::RSP_t_ClustListHeader & Dest, const RSP2CluV3::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 4;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  void ConvertHeaderV3ToV5(RSP2CluV5::RSP_t_ClustListHeader & Dest, const RSP2CluV3::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 5;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.f_MaximumSensorRange   = 0.f;
    Dest.f_MinimumSensorRange   = 200.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
  };
  static void ConvertHeaderV2ToV1(RSP2CluV1::RSP_t_ClustListHeader & Dest, const RSP2CluV2::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 1;
    Dest.u_ClusterListValid     = (Source.sSigHeader.eSigStatus == AL_SIG_STATE_OK);
    Dest.u_reserved[0]          = 0;
    Dest.u_reserved[1]          = 0;
    Dest.u_reserved[2]          = 0;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
  };
  static void ConvertHeaderV3ToV1(RSP2CluV1::RSP_t_ClustListHeader & Dest, const RSP2CluV3::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV3ToV2(RSP2CluV2::RSP_t_ClustListHeader & Dest, const RSP2CluV3::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV4ToV1(RSP2CluV1::RSP_t_ClustListHeader & Dest, const RSP2CluV4::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV4ToV2(RSP2CluV2::RSP_t_ClustListHeader & Dest, const RSP2CluV4::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV4ToV3(RSP2CluV3::RSP_t_ClustListHeader & Dest, const RSP2CluV4::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 3;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
  };
  static void ConvertHeaderV4ToV5(RSP2CluV5::RSP_t_ClustListHeader & Dest, const RSP2CluV4::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 5;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.b_ExtraDistInfluencedByLargePeak = Source.b_ExtraDistInfluencedByLargePeak;
    Dest.b_MaxRangeInfluencedByLargePeak = Source.b_MaxRangeInfluencedByLargePeak;
    Dest.f_MaximumSensorRange   = Source.f_MaximumSensorRange;
    Dest.f_MinimumSensorRange   = Source.f_MinimumSensorRange;
  };
  static void ConvertHeaderV5ToV1(RSP2CluV1::RSP_t_ClustListHeader & Dest, const RSP2CluV5::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV5ToV2(RSP2CluV2::RSP_t_ClustListHeader & Dest, const RSP2CluV5::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV5ToV3(RSP2CluV3::RSP_t_ClustListHeader & Dest, const RSP2CluV5::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    // Not used yet
  };
  static void ConvertHeaderV5ToV4(RSP2CluV4::RSP_t_ClustListHeader & Dest, const RSP2CluV5::RSP_t_ClustListHeader & Source, const uint32 uMaxClusters)
  {
    Dest.u_VersionNumber        = 4;
    // Fill signal header
    Dest.sSigHeader.uiTimeStamp = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus  = Source.sSigHeader.eSigStatus;
    // Fill rest of fields
    Dest.u_TimeStamp            = Source.u_TimeStamp;
    Dest.f_AmbFreeDopplerRange  = Source.f_AmbFreeDopplerRange;
    Dest.u_NofClusters          = min(Source.u_NofClusters, uMaxClusters);
    Dest.f_RangeGateLength      = Source.f_RangeGateLength;
    Dest.f_RangeLimit           = Source.f_RangeLimit;
    Dest.b_ExtraDistInfluencedByLargePeak = Source.b_ExtraDistInfluencedByLargePeak;
    Dest.b_MaxRangeInfluencedByLargePeak = Source.b_MaxRangeInfluencedByLargePeak;
    Dest.f_MaximumSensorRange   = Source.f_MaximumSensorRange;
    Dest.f_MinimumSensorRange   = Source.f_MinimumSensorRange;
  };
  static void ConvertClusterV1ToV3(RSP2CluV3::RSP_t_Cluster & Dest, const RSP2CluV1::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.f_AzAngExtens              = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
    // @todo: find suitable conversion
    //Dest.ComplMaxBeam.s_Real        = Source.t_ElAngCplx.s_Real / 256;
    //Dest.ComplMaxBeam.s_Imag        = Source.t_ElAngCplx.s_Imag / 256;
    Dest.ComplMonoPulseBeam.s_Real  = Source.t_ElAngCplx.s_Real / 256;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.t_ElAngCplx.s_Imag / 256;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV2ToV3(RSP2CluV3::RSP_t_Cluster & Dest, const RSP2CluV2::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.f_AzAngExtens              = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
    Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
    Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
    Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV2ToV4(RSP2CluV4::RSP_t_Cluster & Dest, const RSP2CluV2::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.f_AzAngExtens              = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
    Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
    Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
    Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV2ToV5(RSP2CluV5::RSP_t_Cluster & Dest, const RSP2CluV2::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
    Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
    Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_MultibleTargetProb       = 0;
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV1ToV2(RSP2CluV2::RSP_t_Cluster & Dest, const RSP2CluV1::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.f_AzAngExtens              = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
    // @todo: find suitable conversion
    //Dest.ComplMaxBeam.s_Real        = Source.t_ElAngCplx.s_Real / 256;
    //Dest.ComplMaxBeam.s_Imag        = Source.t_ElAngCplx.s_Imag / 256;
    Dest.ComplMonoPulseBeam.s_Real  = Source.t_ElAngCplx.s_Real / 256;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.t_ElAngCplx.s_Imag / 256;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<(sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_ElevAngQuality           = Source.u_ElAngQuality;
  };
  static void ConvertClusterV2ToV1(RSP2CluV1::RSP_t_Cluster & Dest, const RSP2CluV2::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad          = Source.f_VrelRad;
    Dest.f_RangeRad         = Source.f_RangeRad;
    Dest.f_RangeExtens      = Source.f_RangeExtens;
    Dest.a_AzAng[0]         = Source.a_AzAng[0];
    Dest.a_AzAng[1]         = Source.a_AzAng[1];
    Dest.f_AzAngExtens      = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff     = Source.f_AzAngMidDiff;
    Dest.t_ElAngCplx.s_Real = Source.ComplMonoPulseBeam.s_Real * 256;
    Dest.t_ElAngCplx.s_Imag = Source.ComplMonoPulseBeam.s_Imag * 256;
    //Dest.f_ElAng            = ;
    Dest.f_RcsRaw           = Source.f_RcsRaw;
    Dest.f_AzAngVar         = Source.f_AzAngVar;
    Dest.f_VrelRadVar       = Source.f_VrelRadVar;
    Dest.f_RangeRadVar      = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol    = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<(sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_ElAngQuality     = Source.u_ElevAngQuality;
  };
  static void ConvertClusterV1ToV4(RSP2CluV4::RSP_t_Cluster & Dest, const RSP2CluV1::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    Dest.f_AzAngExtens              = Source.f_AzAngExtens;
    Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
    // @todo: find suitable conversion
    //Dest.ComplMaxBeam.s_Real        = Source.t_ElAngCplx.s_Real / 256;
    //Dest.ComplMaxBeam.s_Imag        = Source.t_ElAngCplx.s_Imag / 256;
    Dest.ComplMonoPulseBeam.s_Real  = Source.t_ElAngCplx.s_Real / 256;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.t_ElAngCplx.s_Imag / 256;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV1ToV5(RSP2CluV5::RSP_t_Cluster & Dest, const RSP2CluV1::RSP_t_Cluster & Source)
  {
    Dest.f_VrelRad                  = Source.f_VrelRad;
    Dest.f_RangeRad                 = Source.f_RangeRad;
    Dest.f_RangeExtens              = Source.f_RangeExtens;
    Dest.a_AzAng[0]                 = Source.a_AzAng[0];
    Dest.a_AzAng[1]                 = Source.a_AzAng[1];
    // @todo: find suitable conversion
    //Dest.ComplMaxBeam.s_Real        = Source.t_ElAngCplx.s_Real / 256;
    //Dest.ComplMaxBeam.s_Imag        = Source.t_ElAngCplx.s_Imag / 256;
    Dest.ComplMonoPulseBeam.s_Real  = Source.t_ElAngCplx.s_Real / 256;
    Dest.ComplMonoPulseBeam.s_Imag  = Source.t_ElAngCplx.s_Imag / 256;
    Dest.f_RcsRaw                   = Source.f_RcsRaw;
    Dest.f_AzAngVar                 = Source.f_AzAngVar;
    Dest.f_VrelRadVar               = Source.f_VrelRadVar;
    Dest.f_RangeRadVar              = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
    for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
    {
      Dest.a_Pdh0[i] = Source.a_Pdh0[i];
    }
    Dest.u_MultibleTargetProb       = 0;
    Dest.u_IdxPreCluster            = 0;
    Dest.u_ByteAlignment            = 0;
  };
  static void ConvertClusterV3ToV4(RSP2CluV4::RSP_t_Cluster & Dest, const RSP2CluV3::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV3::RSP_t_Cluster) == sizeof(RSP2CluV4::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV4::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.f_AzAngExtens              = Source.f_AzAngExtens;
      Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV3ToV5(RSP2CluV5::RSP_t_Cluster & Dest, const RSP2CluV3::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV3::RSP_t_Cluster) == sizeof(RSP2CluV5::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV5::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_MultibleTargetProb       = 0;
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV4ToV3(RSP2CluV3::RSP_t_Cluster & Dest, const RSP2CluV4::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV3::RSP_t_Cluster) == sizeof(RSP2CluV4::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV3::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.f_AzAngExtens              = Source.f_AzAngExtens;
      Dest.f_AzAngMidDiff             = Source.f_AzAngMidDiff;
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV4ToV5(RSP2CluV5::RSP_t_Cluster & Dest, const RSP2CluV4::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV5::RSP_t_Cluster) == sizeof(RSP2CluV4::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV5::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_MultibleTargetProb       = 0;
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV4ToV7(RSP2CluV7::RSP_t_Cluster & Dest, const RSP2CluV4::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV7::RSP_t_Cluster) == sizeof(RSP2CluV4::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV7::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      memset (Dest.a_Pdh0, 0, sizeof(Dest.a_Pdh0));
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV5ToV1(RSP2CluV1::RSP_t_Cluster & Dest, const RSP2CluV5::RSP_t_Cluster & Source)
  {
    // Not used yet
  }
  static void ConvertClusterV5ToV2(RSP2CluV2::RSP_t_Cluster & Dest, const RSP2CluV5::RSP_t_Cluster & Source)
  {
    // Not used yet
  }
  static void ConvertClusterV5ToV3(RSP2CluV3::RSP_t_Cluster & Dest, const RSP2CluV5::RSP_t_Cluster & Source)
  {
    // Not used yet
  }
  static void ConvertClusterV5ToV4(RSP2CluV4::RSP_t_Cluster & Dest, const RSP2CluV5::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV4::RSP_t_Cluster) == sizeof(RSP2CluV5::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV4::RSP_t_Cluster));
    }
    else
    {
      Dest.f_VrelRad                  = Source.f_VrelRad;
      Dest.f_RangeRad                 = Source.f_RangeRad;
      Dest.f_RangeExtens              = Source.f_RangeExtens;
      Dest.a_AzAng[0]                 = Source.a_AzAng[0];
      Dest.a_AzAng[1]                 = Source.a_AzAng[1];
      Dest.f_AzAngExtens              = 0.f;
      Dest.f_AzAngMidDiff             = 0.f;
      Dest.ComplMaxBeam.s_Real        = Source.ComplMaxBeam.s_Real;
      Dest.ComplMaxBeam.s_Imag        = Source.ComplMaxBeam.s_Imag;
      Dest.ComplMonoPulseBeam.s_Real  = Source.ComplMonoPulseBeam.s_Real;
      Dest.ComplMonoPulseBeam.s_Imag  = Source.ComplMonoPulseBeam.s_Imag;
      Dest.f_RcsRaw                   = Source.f_RcsRaw;
      Dest.f_AzAngVar                 = Source.f_AzAngVar;
      Dest.f_VrelRadVar               = Source.f_VrelRadVar;
      Dest.f_RangeRadVar              = Source.f_RangeRadVar;
      Dest.f_RangeExtrapol            = Source.f_RangeExtrapol;
      for (unsigned int i=0; i<MIN((sizeof(Dest.a_Pdh0)/sizeof(Dest.a_Pdh0[0])),(sizeof(Source.a_Pdh0)/sizeof(Source.a_Pdh0[0]))); i++)
      {
        Dest.a_Pdh0[i] = Source.a_Pdh0[i];
      }
      Dest.u_IdxPreCluster            = Source.u_IdxPreCluster;
      Dest.u_ByteAlignment            = Source.u_ByteAlignment;
    }
  };
  static void ConvertClusterV5ToV7(RSP2CluV7::RSP_t_Cluster & Dest, const RSP2CluV5::RSP_t_Cluster & Source)
  {
    if (sizeof(RSP2CluV7::RSP_t_Cluster) == sizeof(RSP2CluV5::RSP_t_Cluster))
    {
      memcpy(&Dest, &Source, sizeof(RSP2CluV7::RSP_t_Cluster));
    }
    else
    {
    }
  };
  static void ConvertClusterV100AToV100B(RSP2CluV100_B::RSP_t_Cluster & Dest, const RSP2CluV100_A::RSP_t_Cluster & Source)
  {
    int nI;
    Dest.f_VrelRad = Source.f_VrelRad;
    Dest.f_RangeRad = Source.f_RangeRad;
    Dest.f_RangeExtens = Source.f_RangeExtens;
    for (nI=0; nI<2; nI++)
    {
      Dest.a_AzAng[nI] = Source.a_AzAng[nI];
    }
    Dest.ComplMaxBeam = Source.ComplMaxBeam;
    Dest.ComplMonoPulseBeam = Source.ComplMonoPulseBeam;
    Dest.f_RcsRaw = Source.f_RcsRaw;
    Dest.f_AzAngVar = Source.f_AzAngVar;
    Dest.f_VrelRadVar = Source.f_VrelRadVar;
    Dest.f_RangeRadVar = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol = Source.f_RangeExtrapol;
    for (nI=0; nI<16; nI++)
    {
      Dest.a_Pdh0[nI] = static_cast <unsigned char> (Source.a_Pdh0[nI]);
    }
    Dest.u_IdxPreCluster = Source.u_IdxPreCluster;
    Dest.u_ByteAlignment = Source.u_ByteAlignment;
  };
  static void ConvertClusterV100BToV100A(RSP2CluV100_A::RSP_t_Cluster & Dest, const RSP2CluV100_B::RSP_t_Cluster & Source)
  {
    int nI;
    Dest.f_VrelRad = Source.f_VrelRad;
    Dest.f_RangeRad = Source.f_RangeRad;
    Dest.f_RangeExtens = Source.f_RangeExtens;
    for (nI=0; nI<2; nI++)
    {
      Dest.a_AzAng[nI] = Source.a_AzAng[nI];
    }
    Dest.ComplMaxBeam = Source.ComplMaxBeam;
    Dest.ComplMonoPulseBeam = Source.ComplMonoPulseBeam;
    Dest.f_RcsRaw = Source.f_RcsRaw;
    Dest.f_AzAngVar = Source.f_AzAngVar;
    Dest.f_VrelRadVar = Source.f_VrelRadVar;
    Dest.f_RangeRadVar = Source.f_RangeRadVar;
    Dest.f_RangeExtrapol = Source.f_RangeExtrapol;
    for (nI=0; nI<16; nI++)
    {
      Dest.a_Pdh0[nI] = static_cast <unsigned char> (Source.a_Pdh0[nI]);
    }
    Dest.u_IdxPreCluster = Source.u_IdxPreCluster;
    Dest.u_ByteAlignment = Source.u_ByteAlignment;
  };
  static void InitCluHeader(RSP2CluV1::RSP_t_ClustListHeader & Dest)
  {
    Dest.u_VersionNumber          = 1u;
    Dest.u_ClusterListValid       = false;
    Dest.u_reserved[0]            = 0;
    Dest.u_reserved[1]            = 0;
    Dest.u_reserved[2]            = 0;
    Dest.u_NofClusters            = 0;
    Dest.f_AmbFreeDopplerRange    = 0;
    Dest.f_RangeLimit             = 0;
  };
  static void InitCluHeader(RSP2CluV2::RSP_t_ClustListHeader & Dest)
  {
    Dest.u_VersionNumber                  = 2;
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.u_TimeStamp                      = Dest.sSigHeader.uiTimeStamp;
    Dest.f_AmbFreeDopplerRange            = 0;
    Dest.u_NofClusters                    = 0;
    Dest.f_RangeGateLength                = 0;
    Dest.f_RangeLimit                     = 0;
  };
  static void InitCluHeader(RSP2CluV3::RSP_t_ClustListHeader & Dest)
  {
    Dest.u_VersionNumber                  = 3;
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.u_TimeStamp                      = Dest.sSigHeader.uiTimeStamp;
    Dest.f_AmbFreeDopplerRange            = 0.f;
    Dest.u_NofClusters                    = 0;
    Dest.f_RangeGateLength                = 0.f;
    Dest.f_RangeLimit                     = 0.f;
  };
  static void InitCluHeader(RSP2CluV4::RSP_t_ClustListHeader & Dest)
  {
    Dest.u_VersionNumber                  = 4;
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.u_TimeStamp                      = Dest.sSigHeader.uiTimeStamp;
    Dest.f_AmbFreeDopplerRange            = 0.f;
    Dest.u_NofClusters                    = 0;
    Dest.f_RangeGateLength                = 0.f;
    Dest.f_RangeLimit                     = 0.f;
    Dest.f_MaximumSensorRange             = 0.f;
    Dest.f_MinimumSensorRange             = 0.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
    Dest.u_Dummy[0]                       = 0;
    Dest.u_Dummy[1]                       = 0;
  };
  static void InitCluHeader(RSP2CluV5::RSP_t_ClustListHeader & Dest)
  {
    Dest.u_VersionNumber                  = 5;
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.u_TimeStamp                      = Dest.sSigHeader.uiTimeStamp;
    Dest.f_AmbFreeDopplerRange            = 0.f;
    Dest.u_NofClusters                    = 0;
    Dest.f_RangeGateLength                = 0.f;
    Dest.f_RangeLimit                     = 0.f;
    Dest.f_MaximumSensorRange             = 0.f;
    Dest.f_MinimumSensorRange             = 0.f;
    Dest.b_ExtraDistInfluencedByLargePeak = FALSE;
    Dest.b_MaxRangeInfluencedByLargePeak  = FALSE;
    Dest.u_Dummy[0]                       = 0;
    Dest.u_Dummy[1]                       = 0;
  };
  static void InitCluHeader(RSP2CluV100_A::RSP_t_ClustListHeader & Dest)
  {
    memset(&Dest, 0, sizeof(Dest));
    Dest.u_VersionNumber                  = 0x100;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.f_AmbFreeDopplerRange            = 0.f;
    Dest.f_RangeGateLength                = 0.f;
    Dest.f_RangeLimit                     = 0.f;
    Dest.f_MaximumSensorRange             = 0.f;
    Dest.f_MinimumSensorRange             = 0.f;
  };
  static void InitCluHeader(RSP2CluV100_B::RSP_t_ClustListHeader & Dest)
  {
    memset(&Dest, 0, sizeof(Dest));
    Dest.u_VersionNumber                  = 0x100;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    Dest.f_AmbFreeDopplerRange            = 0.f;
    Dest.f_RangeGateLength                = 0.f;
    Dest.f_RangeLimit                     = 0.f;
    Dest.f_MaximumSensorRange             = 0.f;
    Dest.f_MinimumSensorRange             = 0.f;
  };

  template <typename T> static void InitCluster (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }
  template <typename T, typename C> static void InitClusterList (T * Dest, unsigned int uNumClusters)
  {
    InitCluHeader(Dest->ClustListHead);
    for (unsigned int uCluIdx=0; uCluIdx < uNumClusters; uCluIdx++)
    {
      InitCluster<C>(Dest->a_Clusters[uCluIdx]);
    }
  }
  template <class Header, class Cluster> static unsigned int ValidateCluListSize (size_t nRawSize)
  {
    const size_t nRawCluSize = (nRawSize - sizeof(Header));
    const size_t nNumClu = (nRawCluSize / sizeof(Cluster));
    if ((nNumClu * sizeof(Cluster)) == nRawCluSize)
    {
      return static_cast<unsigned int>(nNumClu);
    }
    return 0;
  };

  bool AllocClusterBuffer(size_t nSize)
  {
    if (m_uAllocSize < nSize)
    {
      if (m_pAllocBuffer != NULL)
      {
        ::free(m_pAllocBuffer);
        m_pAllocBuffer  = NULL;
        m_uAllocSize    = 0;
      }
      m_pAllocBuffer = ::malloc(nSize);
      if (m_pAllocBuffer != NULL)
      {
        m_uAllocSize = nSize;
      }
    }
    return ((m_uAllocSize >= nSize) && (m_pAllocBuffer != NULL));
  };

public:

  CConvRsp2CluList(void) : CSimConverterBase(NULL, 0), m_uAllocSize(0), m_pAllocBuffer(NULL), m_uiLastTimeStamp(0), m_uiLastCycCnt(0)
  {
  };
  virtual ~CConvRsp2CluList(void)
  {
    if (m_pAllocBuffer != NULL)
    {
      ::free(m_pAllocBuffer);
      m_pAllocBuffer = NULL;
    }
  };

  const char* GetTypeName()
  {
    return "RSP_2_ClusterList";
  };

  void Destroy()
  {
    delete this;
  };

  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_VALUE_FROM_PPORT - when the conversion is not implemented here
   *                                  and the value from Provide Port must be used
   */
  long ConvertData(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo* pProvidePortVersionInfo, 
    void* pPPortData,
    void** pOutData, unsigned long& ulOutSize)
  {
    long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
    if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // Some form of conversion needed, allocate buffer large enough to store converted data
      if (AllocClusterBuffer(ulRPortSize))
      {
        uint32 src_ver = (ulPPortSize > 4)?(*static_cast<const uint32*>(pPPortData)):0;
        // HACK: B0 measurements had different (higher) version numbers
        // B1 measurements increased version numbers. 7.11.2013 -> 3. Exclude from Hack by size recognition.
        if ((src_ver > 2) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          if (sizeof(RSP2CluV3::RSP_t_ClusterListNS) != ulPPortSize)
          {
            src_ver = 1;
          }
        }
        // HACK END
        switch (src_ver)
        {
        case 1:
          {
            // Source provides cluster list version 1
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV1::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV1::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V1 header to V5 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV1ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V1 clusters to V5 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV1ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V1 header to V5 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV1ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V1 clusters to V5 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV1ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V1 header to V4 header
                  ConvertHeaderV1ToV4(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V1 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV1ToV4(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V1 header to V3 header
                  ConvertHeaderV1ToV3(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V1 clusters to V3 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV1ToV3(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV2::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV2::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V1 header to V2 header
                  ConvertHeaderV1ToV2(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V1 clusters to V2 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV1ToV2(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV2::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV1::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV1::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV1::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            else
            {
              lRet = SIM_ERR_INVALID_INDEX;
            }
          }
          break;
        case 2:
          {
            // Source provides cluster list version 2
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV2::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV2::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V2 header to V4 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV2ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V2 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV2ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V2 header to V4 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV2ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V2 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV2ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V2 header to V4 header
                  ConvertHeaderV2ToV4(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V2 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV2ToV4(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V2 header to V3 header
                  ConvertHeaderV2ToV3(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V2 clusters to V3 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV2ToV3(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV2::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV2::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV2::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV1::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV1::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V2 header to V1 header
                  ConvertHeaderV2ToV1(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Convert V2 clusters to V1 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV2ToV1(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV1::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            else
            {
              lRet = SIM_ERR_INVALID_INDEX;
            }
          }
          break;
        case 3:
          {
            // Source provides cluster list version 3
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV3::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV3::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V3 header to V4 header
                  ConvertHeaderV3ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V3 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV3ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V3 header to V4 header
                  ConvertHeaderV3ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V3 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV3ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V3 header to V4 header
                  ConvertHeaderV3ToV4(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V3 clusters to V4 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV3ToV4(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            else
            {
              lRet = SIM_ERR_INVALID_INDEX;
            }
          }
          break;
        case 4:
          {
            // Source provides cluster list version 4
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV4::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV4::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV7::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV7::RSP_t_ClustListHeader, RSP2CluV7::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV7::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV7::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V4 header to V5 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV4ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    //pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                    ConvertClusterV4ToV7(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV7::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V4 header to V5 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV4ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    //pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                    ConvertClusterV4ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V4 header to V5 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV4ToV5(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    //pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                    ConvertClusterV4ToV5(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V4 header to V3 header
                  ConvertHeaderV4ToV3(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Convert V4 clusters to V3 clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV4ToV3(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }

              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            else
            {
              lRet = SIM_ERR_INVALID_INDEX;
            }
          }
          break;
        case 5:
          {
            // Source provides cluster list version 5
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV5::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV5::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV7::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV7::RSP_t_ClustListHeader, RSP2CluV7::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV7::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV7::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV7(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV7::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V4 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV4(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV4(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V3 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV3(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV3(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV2::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV2::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V2 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV2(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV2(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV2::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV1::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV1::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V1 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV1(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV1(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV1::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            else
            {
              lRet = SIM_ERR_INVALID_INDEX;
            }
          }
          break;
        case 6:
          {
            // Source provides cluster list version 6
            const unsigned int NumSrcClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize);
            if (NumSrcClusters > 0)
            {
              const RSP2CluV6::RSP_t_GenClusterList * const pSrc = reinterpret_cast<const RSP2CluV6::RSP_t_GenClusterList*>(pPPortData);
              // We know the provided data consists of 'NumSrcClusters'
              if (requestPortVersionInfo.Equals(&RSP2CluV7::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV7::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV7::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV7(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV7::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }


              else if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV6::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV6::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Copy header
                  pDest->ClustListHead = pSrc->ClustListHead;
                  // Limit number of clusters to maximum destination can take
                  if (pDest->ClustListHead.u_NofClusters > num_copy_cluster)
                  {
                    pDest->ClustListHead.u_NofClusters = num_copy_cluster;
                  }
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    pDest->a_Clusters[uCluIdx] = pSrc->a_Clusters[uCluIdx];
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV5::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V4 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV4(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV4(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV4::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V3 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV3(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV3(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV3::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV2::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV2::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V2 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV2(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV2(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV2::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
              {
                const unsigned int NumDestClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
                if (NumDestClusters > 0)
                {
                  RSP2CluV1::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV1::RSP_t_GenClusterList*>(m_pAllocBuffer);
                  unsigned int uCluIdx = 0;
                  const uint32 num_copy_cluster = min(NumSrcClusters, NumDestClusters);
                  // Convert V5 header to V1 header and
                  // limit number of clusters to maximum destination can take
                  ConvertHeaderV5ToV1(pDest->ClustListHead, pSrc->ClustListHead, num_copy_cluster);
                  // Copy clusters
                  for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
                  {
                    ConvertClusterV5ToV1(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
                  }
                  // Fill any empty clusters
                  for (; uCluIdx < NumDestClusters; uCluIdx++)
                  {
                    InitCluster<RSP2CluV1::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
                  }
                  *pOutData = pDest;
                  ulOutSize = ulRPortSize;
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_INDEX;
                }
              }
              else
              {
                // Don't know request port version
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
          }
          break;
        // ARS5xx:
        case 0x100:
          // Source provides cluster list version 100 -> RSP2CluV100_A and RSP2CluV100_B with different RSP_t_cluster sizes.
          if (requestPortVersionInfo.Equals(&RSP2CluV100_A::Version))
          {
            unsigned int uCluIdx = 0;
            // Check if request port size checks out for version 100_B and
            // provide port size checks out for version 100_A
            if ((ulRPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)) &&
              (ulPPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)))
            {
              RSP2CluV100_A::RSP_t_ClusterListNS *pSrc =  reinterpret_cast <RSP2CluV100_A::RSP_t_ClusterListNS *> (pPPortData);
              RSP2CluV100_B::RSP_t_ClusterListNS *pDest = reinterpret_cast <RSP2CluV100_B::RSP_t_ClusterListNS *> (m_pAllocBuffer);
              // Copy Header
              pDest->ClustListHead = *(reinterpret_cast <RSP2CluV100_B::RSP_t_ClustListHeader *> (&pSrc->ClustListHead));
              // Convert Cluster
              const unsigned int NumSrcClustersA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_A::RSP_t_Cluster>(ulPPortSize);
              const unsigned int NumDestClustersB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
              // limit number of clusters to maximum destination can take
              const uint32 num_copy_cluster = min(NumSrcClustersA, NumDestClustersB);
              for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
              {
                ConvertClusterV100AToV100B(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
              }
              // Fill any empty clusters
              for (; uCluIdx < NumDestClustersB; uCluIdx++)
              {
                InitCluster<RSP2CluV100_B::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
              }

              *pOutData = pDest;
              ulOutSize = ulRPortSize;
              lRet = SIM_ERR_OK;
            }
            // Check if request port size checks out for version 100_A and
            // provide port size checks out for version 100_B
            else if ((ulRPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)) &&
              (ulPPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)))
            {
              RSP2CluV100_B::RSP_t_ClusterListNS *pSrc =  reinterpret_cast <RSP2CluV100_B::RSP_t_ClusterListNS *> (pPPortData);
              RSP2CluV100_A::RSP_t_ClusterListNS *pDest = reinterpret_cast <RSP2CluV100_A::RSP_t_ClusterListNS *> (m_pAllocBuffer);
              // Copy Header
              pDest->ClustListHead = *(reinterpret_cast <RSP2CluV100_A::RSP_t_ClustListHeader *> (&pSrc->ClustListHead));
              // Convert Cluster
              const unsigned int NumSrcClustersB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulPPortSize);
              const unsigned int NumDestClustersA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
              // limit number of clusters to maximum destination can take
              const uint32 num_copy_cluster = min(NumSrcClustersB, NumDestClustersA);
              for (uCluIdx=0; uCluIdx < num_copy_cluster; uCluIdx++)
              {
                ConvertClusterV100BToV100A(pDest->a_Clusters[uCluIdx], pSrc->a_Clusters[uCluIdx]);
              }
              // Fill any empty clusters
              for (; uCluIdx < NumDestClustersA; uCluIdx++)
              {
                InitCluster<RSP2CluV100_A::RSP_t_Cluster>(pDest->a_Clusters[uCluIdx]);
              }

              *pOutData = pDest;
              ulOutSize = ulRPortSize;
              lRet = SIM_ERR_OK;
            }
            // The following procedure doesn't function because the header are the same and
            // deviding the remainder by the cluster size gives an integer in both cases
            //const unsigned int uNumRCluA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_A::RSP_t_Cluster>(ulRPortSize);
            //const unsigned int uNumRCluB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
          }
          break;
        case 0:
        default:
          // Hmm... Don't know this version
          lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
          break;
        }
      }
      else
      {
        // could not allocate buffer for converted data
        lRet = SIM_ERR_INVALID_DATA_SIZE;
      }
    }
    return lRet;
  };

  /** returns: 
   *   SIM_ERR_OK - when this value can be used
   *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
   *                                            and the default value from Request Port must be used
   */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo, 
    void **pDefaultData, unsigned long &ulDefaultSize)
  {
    long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    if (requestPortVersionInfo.Equals(&RSP2CluV100_A::Version))
    {
      const unsigned int uNumClustersA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_A::RSP_t_Cluster>(ulRPortSize);
      const unsigned int uNumClustersB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
      if (uNumClustersA > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV100_A::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV100_A::RSP_t_GenClusterList *>(m_pAllocBuffer);
          InitClusterList<RSP2CluV100_A::RSP_t_GenClusterList, RSP2CluV100_A::RSP_t_Cluster>(pDest, uNumClustersA);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV7::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV7::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV7::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV7::RSP_t_GenClusterList *>(m_pAllocBuffer);
          InitClusterList<RSP2CluV7::RSP_t_GenClusterList, RSP2CluV7::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList *>(m_pAllocBuffer);
          InitClusterList<RSP2CluV5::RSP_t_GenClusterList, RSP2CluV5::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }


    else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV5::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV5::RSP_t_GenClusterList *>(m_pAllocBuffer);
          InitClusterList<RSP2CluV5::RSP_t_GenClusterList, RSP2CluV5::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV4::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV4::RSP_t_GenClusterList*>(m_pAllocBuffer);
          InitClusterList<RSP2CluV4::RSP_t_GenClusterList,RSP2CluV4::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV3::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV3::RSP_t_GenClusterList*>(m_pAllocBuffer);
          InitClusterList<RSP2CluV3::RSP_t_GenClusterList,RSP2CluV3::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV2::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV2::RSP_t_GenClusterList*>(m_pAllocBuffer);
          InitClusterList<RSP2CluV2::RSP_t_GenClusterList,RSP2CluV2::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
    {
      const unsigned int uNumClusters = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
      if (uNumClusters > 0)
      {
        if (AllocClusterBuffer(ulRPortSize))
        {
          RSP2CluV1::RSP_t_GenClusterList * const pDest = reinterpret_cast<RSP2CluV1::RSP_t_GenClusterList*>(m_pAllocBuffer);
          InitClusterList<RSP2CluV1::RSP_t_GenClusterList,RSP2CluV1::RSP_t_Cluster>(pDest, uNumClusters);
          *pDefaultData = m_pAllocBuffer;
          ulDefaultSize = m_uAllocSize;
          lRet = SIM_ERR_OK;
        }
      }
    }
    else
    {
      lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    }
    return lRet;
  };

protected:

  // used to check if an unversioned PPort is compatible with a certain version of RPort
  bool IsVersionCompatibleWithType(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
  {
    bool bRet = false;
    if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
    {
      // Seem to be identical size. Without additional info just accept
      bRet = true;
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV100_A::Version))
    {
      // Check if request port size checks out for version 100_B and
      // provide port size checks out for version 100_A
      if ((ulRPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)) &&
        (ulPPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)))
      {
        bRet = true;
      }
      // Check if request port size checks out for version 100_A and
      // provide port size checks out for version 100_B
      else if ((ulRPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)) &&
        (ulPPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)))
      {
        bRet = true;
      }
      // The following procedure doesn't function because the header are the same and
      // deviding the remainder by the cluster size gives an integer in both cases
      //const unsigned int uNumRCluA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_A::RSP_t_Cluster>(ulRPortSize);
      //const unsigned int uNumRCluB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV7::Version))
    {
      // Check if request port size checks out for version 7
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV7::RSP_t_ClustListHeader, RSP2CluV7::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV6::Version))
    {
      // Check if request port size checks out for version 6
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV6::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
    {
      // Check if request port size checks out for version 5
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
    {
      // Check if request port size checks out for version 4
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
    {
      // Check if request port size checks out for version 3
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
    {
      // Check if request port size checks out for version 2
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
    {
      // Check if request port size checks out for version 1
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)) ||
          (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else
    {
      bRet = false;
    }
    return bRet;
  };

  // used to check if ports are compatible between different versions
  bool AreVersionsCompatible(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo,
    SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo& providePortVersionInfo)
  {
    bool bRet = false;
    if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType) && (requestPortVersionInfo.Equals(&providePortVersionInfo)))
    {
      // Seem to be identical size/version.
      bRet = true;
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV100_A::Version) && providePortVersionInfo.Equals(&RSP2CluV100_A::Version))
    {
      // Check if request port size checks out for version 100_B and
      // provide port size checks out for version 100_A
      if ((ulRPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)) &&
        (ulPPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)))
      {
        bRet = true;
      }
      // Check if request port size checks out for version 100_A and
      // provide port size checks out for version 100_B
      else if ((ulRPortSize == sizeof(RSP2CluV100_A::RSP_t_ClusterListNS)) &&
        (ulPPortSize == sizeof(RSP2CluV100_B::RSP_t_ClusterListNS)))
      {
        bRet = true;
      }
      // The following procedure doesn't function because the header are the same and
      // deviding the remainder by the cluster size gives an integer in both cases
      //const unsigned int uNumRCluA = ValidateCluListSize<RSP2CluV100_A::RSP_t_ClustListHeader, RSP2CluV100_A::RSP_t_Cluster>(ulRPortSize);
      //const unsigned int uNumRCluB = ValidateCluListSize<RSP2CluV100_B::RSP_t_ClustListHeader, RSP2CluV100_B::RSP_t_Cluster>(ulRPortSize);
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV5::Version))
    {
      // Check if request port size checks out for version 5
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((providePortVersionInfo.Equals(&RSP2CluV1::Version)) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV2::Version)) && (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV3::Version)) && (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV4::Version)) && (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV5::Version)) && (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV4::Version))
    {
      // Check if request port size checks out for version 4
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((providePortVersionInfo.Equals(&RSP2CluV1::Version)) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV2::Version)) && (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV3::Version)) && (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV4::Version)) && (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV5::Version)) && (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV3::Version))
    {
      // Check if request port size checks out for version 3
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((providePortVersionInfo.Equals(&RSP2CluV1::Version)) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV2::Version)) && (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV3::Version)) && (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV4::Version)) && (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV5::Version)) && (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV2::Version))
    {
      // Check if request port size checks out for version 2
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((providePortVersionInfo.Equals(&RSP2CluV1::Version)) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV2::Version)) && (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV2::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV3::Version)) && (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV4::Version)) && (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV5::Version)) && (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else if (requestPortVersionInfo.Equals(&RSP2CluV1::Version))
    {
      // Check if request port size checks out for version 1
      const unsigned int uNumRClu = ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulRPortSize);
      if (uNumRClu > 0)
      {
        if ((providePortVersionInfo.Equals(&RSP2CluV1::Version)) && (ValidateCluListSize<RSP2CluV1::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV2::Version)) && (ValidateCluListSize<RSP2CluV2::RSP_t_ClustListHeader, RSP2CluV1::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV3::Version)) && (ValidateCluListSize<RSP2CluV3::RSP_t_ClustListHeader, RSP2CluV3::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV4::Version)) && (ValidateCluListSize<RSP2CluV4::RSP_t_ClustListHeader, RSP2CluV4::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
        else if ((providePortVersionInfo.Equals(&RSP2CluV5::Version)) && (ValidateCluListSize<RSP2CluV5::RSP_t_ClustListHeader, RSP2CluV5::RSP_t_Cluster>(ulPPortSize)))
        {
          bRet = true;
        }
      }
    }
    else
    {
      bRet = false;
    }
    return bRet;
  };

#ifdef _DEBUG
  static const unsigned long SUPPORTED_SIZE[9];
#endif
};

#ifdef _DEBUG
const unsigned long CConvRsp2CluList::SUPPORTED_SIZE[9]=
{                                                          //SUPPORTED_SIZE	0x1938451c unsigned long const * const CConvRsp2CluList::SUPPORTED_SIZE	const unsigned long [9]
  sizeof(RSP2CluV1::RSP_t_ClusterListNear),                //[0]  32788  const unsigned long
  sizeof(RSP2CluV2::RSP_t_ClusterListNS),                  //[1]  57636  const unsigned long
  sizeof(RSP2CluV3::RSP_t_ClusterListNS),                  //[2]  65572  const unsigned long
  sizeof(RSP2CluV4::RSP_t_ClusterListNS),                  //[3]  65584  const unsigned long
  sizeof(RSP2CluV5::RSP_t_ClusterListNS),                  //[4]  53808  const unsigned long
  sizeof(RSP2CluV6::RSP_t_ClusterListNS),                  //[5]  35888  const unsigned long
  sizeof(RSP2CluV7::RSP_t_ClusterListNS),                  //[6]  43056  const unsigned long
  sizeof(RSP2CluV100_A::RSP_t_ClusterListNS),              //[7]  49196  const unsigned long
  sizeof(RSP2CluV100_B::RSP_t_ClusterListNS),              //[8]  43052  const unsigned long
};
#endif
//
// Factory function
//
IConverter * CreateRsp2CluListConvClass(void)
{
  return new CConvRsp2CluList();
}
