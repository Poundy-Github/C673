/*! \file **********************************************************************

  COMPANY:              Continental

  PROJECT:              Simulation

  COMPONENT:            sim_adapter

  MODULNAME:            interface_RSP1_PreClusterList_ars400

  DESCRIPTION:          ARS400 peak list layout header file (all versions)

  AUTHOR:               Gergely Ungvary

  CREATION DATE:        07.02.2013

  VERSION:              $Revision: 1.1 $

  ---*/ /*---
  CHANGES:              $Log: interface_RSP1_PreClusterList_ars400.h  $
  CHANGES:              Revision 1.1 2017/08/10 13:15:25CEST uid34177 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/include/project.pj
  CHANGES:              Revision 1.5.1.9 2016/08/18 11:08:22CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + ARS510: V100_A and V100_B (A- and B-Sample)
  CHANGES:              Revision 1.5.1.8 2015/05/07 06:28:08CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace RSP1_PRECLUSTERLIST_V6_2_PR_EN
  CHANGES:              --- Added comments ---  berndtt1 [May 7, 2015 8:07:37 AM CEST]
  CHANGES:              Change Package : 335739:1 http://mks-psad:7002/im/viewissue?selection=335739
  CHANGES:              Revision 1.5.1.7 2014/12/12 08:25:27CET Berndt, Thomas01 (berndtt1) 
  CHANGES:              * Clean up of the Entry paths, joint and switched by compiler defines
  CHANGES:              --- Added comments ---  berndtt1 [Dec 12, 2014 9:35:44 AM CET]
  CHANGES:              Change Package : 221167:44 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.5.1.6 2014/10/24 08:46:27CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + Version V10_PR
  CHANGES:              --- Added comments ---  berndtt1 [Oct 31, 2014 7:44:56 AM CET]
  CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.5.1.5 2014/08/14 08:51:13CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:              Added Preclusterlist with size 1024
  CHANGES:              --- Added comments ---  berndtt1 [Aug 14, 2014 8:54:26 AM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.5.1.4 2014/08/11 07:55:28CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
  CHANGES:              --- Added comments ---  berndtt1 [Aug 13, 2014 4:28:05 PM CEST]
  CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
  CHANGES:              Revision 1.5.1.3 2014/06/30 09:53:02CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              + namespace RSP1_PRECLUSTERLIST_V7
  CHANGES:              --- Added comments ---  berndtt1 [Jun 30, 2014 9:57:26 AM CEST]
  CHANGES:              Change Package : 244114:2 http://mks-psad:7002/im/viewissue?selection=244114
  CHANGES:              Revision 1.5.1.2 2014/03/24 13:29:27CET Zeitler, Armin02 (uidv8867) 
  CHANGES:              - u_MultipleTargetProb has been added due to new algoextract.
  CHANGES:              --- Added comments ---  uidv8867 [Mar 24, 2014 1:29:27 PM CET]
  CHANGES:              Change Package : 226903:1 http://mks-psad:7002/im/viewissue?selection=226903
  CHANGES:              Revision 1.5.1.1 2014/03/21 14:22:17CET Zeitler, Armin02 (uidv8867) 
  CHANGES:              - Adaption due to new interface have been done.
  CHANGES:              --- Added comments ---  uidv8867 [Mar 21, 2014 2:22:17 PM CET]
  CHANGES:              Change Package : 226903:1 http://mks-psad:7002/im/viewissue?selection=226903
  CHANGES:              Revision 1.5 2013/09/16 11:34:36CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              New version of RSP_t_PreClusterListNear/Far
  CHANGES:              --- Added comments ---  berndtt1 [Sep 16, 2013 2:43:19 PM CEST]
  CHANGES:              Change Package : 193430:3 http://mks-psad:7002/im/viewissue?selection=193430
  CHANGES:              Revision 1.4 2013/07/17 16:41:05CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:              Replaced #include "platform_types.h" by #include "interface_base.h"
  CHANGES:              Note: In the adapter there should always be used a local definition!
  CHANGES:              --- Added comments ---  berndtt1 [Jul 17, 2013 4:52:26 PM CEST]
  CHANGES:              Change Package : 181622:5 http://mks-psad:7002/im/viewissue?selection=181622
  CHANGES:              Revision 1.3 2013/07/10 17:17:06CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:              - adapted to b1 interfaces.
  CHANGES:              --- Added comments ---  uidu2446 [Jul 10, 2013 5:17:06 PM CEST]
  CHANGES:              Change Package : 187998:2 http://mks-psad:7002/im/viewissue?selection=187998
  CHANGES:              Revision 1.2 2013/06/11 16:35:56CEST Fuentes, Juan-Carlos (uidu2446) 
  CHANGES:              - first working version, converts from (v1 and v0) to v2.
  CHANGES:              --- Added comments ---  uidu2446 [Jun 11, 2013 4:35:57 PM CEST]
  CHANGES:              Change Package : 185634:1 http://mks-psad:7002/im/viewissue?selection=185634
  CHANGES:              Revision 1.1 2013/03/28 15:13:59CET Kaelberer, Stephan (uidu2442) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/include/project.pj
  CHANGES:              Revision 1.1 2013/02/07 13:56:10CET Ungvary, Gergely (ungvaryg) 
  CHANGES:              Initial revision
  CHANGES:              Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/CRT_CommonRadarToolbox/04_Engineering/03_Workspace/algo/sim_adapter/include/project.pj


**************************************************************************** */
#ifndef INTERFACE_RSP1_PRECLUSTERLIST_ARS400
#define INTERFACE_RSP1_PRECLUSTERLIST_ARS400

#include "interface_base.h"

typedef struct                                                       /* [Satisfies_rte sws 1191] */
{
  signed short s_Real;
  signed short s_Imag;
} t_Complex16;

typedef struct                                                       /* [Satisfies_rte sws 1191] */
{
  signed char s_Real;
  signed char s_Imag;
} t_Complex8;                                                        /* signed 8 bit integer complex */

typedef t_Complex8 a_BeamSpecCmplx_array_t[16];                      /* Complex Beam spectrum */ /* [Satisfies_rte sws 1189] */
typedef unsigned short  a_BeamSpecPowLog_array_t[16];                /* Beam power spectrum */ /* [Satisfies_rte sws 1189] */

//
// Peak-list used up to rte_type.h version 1.27.1.14 (inclusive),
// up to ARS400_algo_interface_types.xls 1.24 (inclusive)
//
namespace RSP1_PRECLUSTERLIST_V0
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 512;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 512;
#endif

  typedef unsigned char a_Pdh0_array_t_0[8];

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    uint32 u_VersionNumber;                                          /* Number of used version @min:0.0 @max:4294967295.0 */
    uint8 u_ClusterListValid;
    uint8 u_reserved;                                                /* byte alignment */
    uint16 u_TimeStamp;                                              /* Timestamp in 100µS per digit */
    uint32 u_NofClusters;                                            /* Number of clusters in list */
  } RSP_t_PreClusterHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    float f_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntBeamBinWidth;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    float f_AngMonop;
    t_Complex16 CmplxRatioMonop;
    a_BeamSpecPowLog_array_t a_BeamSpecPowLog;
    a_BeamSpecCmplx_array_t a_BeamSpecCmplx;
  } RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumNearPreClusters]; /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_1[NumFarPreClusters];  /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_PreClusterListFar;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListNear;

};  // End of namespace RSP1_PRECLUSTERLIST_V0

//
// Updated peak-list starting from rte_type.h version 1.27.1.15,
// starting from ARS400_algo_interface_types.xls 1.25
//
namespace RSP1_PRECLUSTERLIST_V1
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 512;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 224;
#endif

  typedef unsigned char u_reserved_array_t_0[3];                     /* byte alignment */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    unsigned char u_ClusterListValid;
    u_reserved_array_t_0 u_reserved;
    unsigned short u_TimeStamp;
    unsigned long u_NofClusters;
    unsigned short u_RangeLimit;
  } RSP_t_PreClusterHeader;

  typedef RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster a_Clusters_array_t_3[NumNearPreClusters]; /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP1_PRECLUSTERLIST_V0::RSP_t_PreCluster a_Clusters_array_t_1[NumFarPreClusters];  /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_PreClusterListFar;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListNear;

};  // End of namespace RSP1_PRECLUSTERLIST_V1

// Updated peak-list starting from rte_type.h version
// starting from ARS400_algo_interface_types.xls
//
namespace RSP1_PRECLUSTERLIST_V2
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 512;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumFarPreClusters = 224;
  static const unsigned int NumNearPreClusters = 512;
#endif

  typedef unsigned char a_Pdh0_array_t_0[8];

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    float f_IntBeamBin;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    float f_AngMonop;
    t_Complex16 CmplxRatioMonop;
    a_BeamSpecCmplx_array_t a_BeamSpecCmplx;
  } RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_1[NumFarPreClusters];  /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumNearPreClusters]; /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_1 a_Clusters;
  } RSP_t_PreClusterListFar;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_PRECLUSTERLIST_V1::RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListNear;

} // end of namespace RSP1_PRECLUSTERLIST_V2

namespace RSP1_PRECLUSTERLIST_V3
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 960;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 1024;                 /* not approved */
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef unsigned char a_Pdh0_array_t_0[8];
  const int SIGNAL_INVALID =0;
  const int SIGNAL_VALID =1;

  typedef unsigned long AlgoDataTimeStamp_t;                         /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */
  typedef unsigned short AlgoCycleCounter_t;                         /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */
  typedef unsigned char AlgoSignalState_t;                           /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t;                                                  /* Common header for all structured data types */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    SignalHeader_t SignalHeader;
    AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    float f_RangeGateLength;
  } RSP_t_PreClusterHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    float f_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntBeamBinWidth;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    float f_SNR;
  } RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterListFS RSP_PreClusterListFS;
    uint32 u_MiscSignature;
  } RSP_t_PreClusterListFSMisc;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterListNS RSP_PreClusterListNS;
    uint32 u_MiscSignature;
  } RSP_t_PreClusterListNSMisc;
}// endofnamespace RSP1_PRECLUSTERLIST_V3

namespace RSP1_PRECLUSTERLIST_V4
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 960;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 1024;                 /* not approved */
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef unsigned char a_Pdh0_array_t_0[7];                         /* False alarm probability:
                                                                        ArrEntry
                                                                        0 = nacom
                                                                        1 = ramp artifact
                                                                        2 = Interference
                                                                        3 = sidelobe
                                                                        4 = doppler spread
                                                                        5 = tbd
                                                                        6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */
  typedef t_Complex16 a_PathCompensation_array_t_0[12];              /* [Satisfies_rte sws 1189] */
  typedef unsigned short a_AzimuthWindow_array_t[16];                /* [Satisfies_rte sws 1189] */
  const int SIGNAL_INVALID = 0;
  const int SIGNAL_VALID = 1;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_MidFrequency;
    float f_TargetNormS;
    boolean b_RfChanged;
    a_PathCompensation_array_t_0 a_PathCompensation;
    a_AzimuthWindow_array_t a_AzimuthWindow;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    float f_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntBeamBinWidth;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    unsigned char u_reserved;
    float f_SNR;
  } RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V4

namespace RSP1_PRECLUSTERLIST_V2_PR_EN
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 960;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 1024;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif
  typedef unsigned char a_Pdh0_array_t_0[7];                         /* False alarm probability:
                                                                        ArrEntry
                                                                        0 = nacom
                                                                        1 = ramp artifact
                                                                        2 = Interference
                                                                        3 = sidelobe
                                                                        4 = doppler spread
                                                                        5 = tbd
                                                                        6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  typedef t_Complex16 a_PathCompensation_array_t_0[12];              /* combined path compensation in Tx and Rx. The separated Tx and Rx gains are handled in RHC internally and are not visible at the interfaces */ /* [Satisfies_rte sws 1189] */
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef t_Complex16 a_PathCompensation_array_t_0[6];               /* combined path compensation in Tx and Rx. The separated Tx and Rx gains are handled in RHC internally and are not visible at the interfaces */ /* [Satisfies_rte sws 1189] */
#endif
  typedef unsigned short a_AzimuthWindow_array_t[16];                /* [Satisfies_rte sws 1189] */
  const int SIGNAL_INVALID = 0;
  const int SIGNAL_VALID = 1;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_MidFrequency;
    float f_TargetNormS;
    boolean b_RfChanged;
    a_PathCompensation_array_t_0 a_PathCompensation;
    a_AzimuthWindow_array_t a_AzimuthWindow;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef float a_IntBeamBin_array_t[2];                             /* Interpolated beam bin */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    a_IntBeamBin_array_t a_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntBeamBinWidth;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    unsigned char ucReserved;
    float f_SNR;
  } RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP_ENV @vname:RSP_PreClusterListNS */

}// endofnamespace RSP1_PRECLUSTERLIST_V2_PR_EN

namespace RSP1_PRECLUSTERLIST_V4_PR_EN
{
#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 960;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 1024;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif
  typedef float a_IntBeamBin_array_t[2];                             /* Interpolated beam bin */ /* [Satisfies_rte sws 1189] */
  typedef unsigned short a_AzimuthWindow_array_t[16];                /* [Satisfies_rte sws 1189] */

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  typedef t_Complex16 a_PathCompensation_array_t_0[12];              /* combined path compensation in Tx and Rx. The separated Tx and Rx gains are handled in RHC internally and are not visible at the interfaces */ /* [Satisfies_rte sws 1189] */
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef t_Complex16 a_PathCompensation_array_t_0[6];               /* combined path compensation in Tx and Rx. The separated Tx and Rx gains are handled in RHC internally and are not visible at the interfaces */ /* [Satisfies_rte sws 1189] */
#endif

  typedef unsigned char a_Pdh0_array_t_0[7];                         /* False alarm probability:
                                                                        ArrEntry
                                                                        0 = nacom
                                                                        1 = ramp artifact
                                                                        2 = Interference
                                                                        3 = sidelobe
                                                                        4 = doppler spread
                                                                        5 = tbd
                                                                        6 = tbd @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef unsigned char u_Dummy_array_t_13[3];                       /* dummy for byte alignment */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    a_IntBeamBin_array_t a_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    unsigned char u_MultipleTargetProb;
    float f_SNR;
  } RSP_t_PreCluster;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_MidFrequency;
    float f_TargetNormS;
    unsigned char u_CurrentRfIndex;
    u_Dummy_array_t_13 u_Dummy;
    a_PathCompensation_array_t_0 a_PathCompensation;
    a_AzimuthWindow_array_t a_AzimuthWindow;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterListFS RSP_PreClusterListFS;
    uint32 u_MiscSignature;
  } RSP_t_PreClusterListFSMisc;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterListNS RSP_PreClusterListNS;
    uint32 u_MiscSignature;
  } RSP_t_PreClusterListNSMisc;

}// endofnamespace RSP1_PRECLUSTERLIST_V4_PR_EN

// Declaration of RSP2 pre cluster list(s) taken from SW_ARS400_PR_RTE_ALGOECUEXTRACT_1.56
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06%5fAlgorithm/04%5fEngineering/00%5fCodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.56
// Declaration of RSP2 pre cluster list(s) taken from rte_type.h revision 1.50
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/SW/SW%5fARS4xx/SW%5fARS400%5fPR/M11%5fAppl/04%5fEngineering/01%5fSource%5fCode/common/rte/project.pj&selection=Rte%5fType.h&revision=1.50
// ARS400_PR
// Remark: The only difference to RSP1_PRECLUSTERLIST_V4_PR_EN is the size of the near cluster array, which changed from 960 to 640 in PR and from 1024 to 768 in EN
namespace RSP1_PRECLUSTERLIST_V5_PR_EN                               /* Size ARS Near, Far: PR: 23164, 16252 EN: 27748 */
{
  // Following two defines are for reference only
  #ifndef RSP_OUTP_PRE_CLLST_FAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_FAR_INTFVER 5U
  #endif
  #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 5U
  #endif

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 640;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 768;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreCluster RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V5_PR_EN

// Declaration of RSP2 pre cluster list(s) taken from SW_ARS400_PR_RTE_ALGOECUEXTRACT_1.62 and 1.63
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.62
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/project.pj&selection=AlgoTypesAUTOSAR4.ecuextract&revision=1.63
// ARS400_PR
// Remark: The difference to RSP1_PRECLUSTERLIST_V5_PR_EN is 
//   + u_GainReduction
//   - u_MultipleTargetProb
//   * Array size u_Dummy_array_t 3 -> 2
//   * Array size a_Pdh0_array_t_0 7 -> 8
namespace RSP1_PRECLUSTERLIST_V6_PR_EN                               /* Size ARS Near, Far: PR: 23164, 16252 EN: 27748 */
{
  // Following two defines are for reference only
  #ifndef RSP_OUTP_PRE_CLLST_FAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_FAR_INTFVER 6U
  #endif
  #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 6U
  #endif

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 640;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 768;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef unsigned char u_Dummy_array_t[2];                          /* dummy for byte alignment */ /* [Satisfies_rte sws 1189] */

  typedef unsigned char a_Pdh0_array_t_0[8];                         /* False alarm probability:
                                                                        0 = nacom
                                                                        1 = sidelobe
                                                                        2 = Doppler spread
                                                                        3 = tbd
                                                                        4 = tbd
                                                                        5 = Add cluster
                                                                        6 = tbd
                                                                        7 = fka MultipleTargetProb
                                                                        @min:0 @max:100 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_MidFrequency;
    float f_TargetNormS;
    unsigned char u_GainReduction;
    unsigned char u_CurrentRfIndex;
    u_Dummy_array_t u_Dummy;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_PathCompensation_array_t_0 a_PathCompensation;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_AzimuthWindow_array_t a_AzimuthWindow;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_IntRangeBin;
    float f_IntDopplerBin;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_IntBeamBin_array_t a_IntBeamBin;
    float f_IntRangeBinLength;
    float f_IntPowerLog;
    a_Pdh0_array_t_0 a_Pdh0;
    float f_SNR;
  } RSP_t_PreCluster;

  //typedef RSP1_PRECLUSTERLIST_V4_PR_EN::RSP_t_PreCluster RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V6_PR_EN

// Declaration of RSP2 pre cluster list(s) taken from rsp_algo_interface_types.xls V1.147
// http://mks-psad:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/00_CodeGen/algo/rsp/core/project.pj&selection=rsp_algo_interface_types.xls&revision=1.147
// ARS4D0
// Remark: The difference to RSP1_PRECLUSTERLIST_V6_PR_EN is 
//   + f_PowerScalingFactor
// Unfortunately the version number was not increased (yet)
namespace RSP1_PRECLUSTERLIST_V6_2_PR_EN                             /* Size ARS Near, Far: PR: 23168, 16256 EN: 27752 */
{
  // Following two defines are for reference only
  #ifndef RSP_OUTP_PRE_CLLST_FAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_FAR_INTFVER 6U
  #endif
  #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 6U
  #endif

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 640;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 768;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_MidFrequency;
    float f_TargetNormS;
    unsigned char u_GainReduction;
    unsigned char u_CurrentRfIndex;
    RSP1_PRECLUSTERLIST_V6_PR_EN::u_Dummy_array_t u_Dummy;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_PathCompensation_array_t_0 a_PathCompensation;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_AzimuthWindow_array_t a_AzimuthWindow;
    float f_PowerScalingFactor;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreCluster RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V6_2_PR_EN

// Declaration of RSP2 pre cluster list(s) taken from rsp_algo_interface_types.xls V1.147
// http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/06_Algorithm/04_Engineering/00_CodeGen/algo/rsp/core/project.pj&selection=rsp_algo_interface_types.xls&revision=1.12.1.1
// ARS4D0
// Remark: The difference to RSP1_PRECLUSTERLIST_V6_2_PR_EN is 
//   + f_Reserved_array_t f_Reserved;
// The version number was set to 0x100
namespace RSP1_PRECLUSTERLIST_V100_A                                 /* Size ARS Near, Far: PR: ?, ? EN: ? ARS510:  */
{
  // Following two defines are for reference only
  #ifndef RSP_OUTP_PRE_CLLST_FAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_FAR_INTFVER 0x100U
  #endif
  #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 0x100U
  #endif

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 640;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 768;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef float f_Reserved_array_t[8];                               /* reserved */ /* [Satisfies_rte sws 1189] */
  typedef t_Complex16 a_PathCompensation_array_t_0[12];              /* combined path compensation in Tx and Rx. The separated Tx and Rx gains are handled in RHC internally and are not visible at the interfaces */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float f_PulseRepetitionTime;
    float f_RangeGateLength;
    float f_RangeLimit;
    float f_MidFrequency;
    float f_TargetNormS;
    unsigned char u_GainReduction;
    unsigned char u_CurrentRfIndex;
    RSP1_PRECLUSTERLIST_V6_PR_EN::u_Dummy_array_t u_Dummy;
    a_PathCompensation_array_t_0 a_PathCompensation;
    RSP1_PRECLUSTERLIST_V4_PR_EN::a_AzimuthWindow_array_t a_AzimuthWindow;
    float f_PowerScalingFactor;
    f_Reserved_array_t f_Reserved;
  } t_ContextData;

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    RSP1_PRECLUSTERLIST_V3::AlgoDataTimeStamp_t u_TimeStamp;
    unsigned long u_NofClusters;
    t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreCluster RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V100_A

// Declaration of RSP2 pre cluster list(s) taken from rsp_algo_interface_types.xls V1.147
// http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/06_Algorithm/04_Engineering/00_CodeGen/algo/rsp/core/project.pj&selection=rsp_algo_interface_types.xls&revision=1.14
// ARS4D0
// Remark: The difference to RSP1_PRECLUSTERLIST_V100_A is 
//   - AlgoDataTimeStamp_t u_TimeStamp;
// Unfortunately the version number was not increased (yet)
namespace RSP1_PRECLUSTERLIST_V100_B                                 /* Size ARS Near, Far: PR: ?, ? EN: ? ARS510:  */
{
  // Following two defines are for reference only
  #ifndef RSP_OUTP_PRE_CLLST_FAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_FAR_INTFVER 0x100U
  #endif
  #ifndef RSP_OUTP_PRE_CLLST_NEAR_INTFVER
    #define RSP_OUTP_PRE_CLLST_NEAR_INTFVER 0x100U
  #endif

#if ((CFG_ARS400_PR_SWITCH == SWITCH_ON) || (CFG_ARS400_PP_SWITCH == SWITCH_ON))
  static const unsigned int NumNSPreClusters = 640;
  static const unsigned int NumFSPreClusters = 448;
#elif (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  static const unsigned int NumNSPreClusters = 768;
  static const unsigned int NumFSPreClusters = 448;                  /* Dummy !!! */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long u_VersionNumber;
    RSP1_PRECLUSTERLIST_V3::SignalHeader_t sSigHeader;
    unsigned long u_NofClusters;
    RSP1_PRECLUSTERLIST_V100_A::t_ContextData ContextData;
  } RSP_t_PreClusterHeader;

  typedef RSP1_PRECLUSTERLIST_V6_PR_EN::RSP_t_PreCluster RSP_t_PreCluster;

  typedef RSP_t_PreCluster a_Clusters_array_t_3[NumFSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef RSP_t_PreCluster a_Clusters_array_t_2[NumNSPreClusters];   /* cluster array */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_3 a_Clusters;
  } RSP_t_PreClusterListFS;                                          /* @vaddr:0x06000000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_FS @cycleid:RSP1_ENV @vname:RSP_PreClusterListFS */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    RSP_t_PreClusterHeader PreClustHead;
    a_Clusters_array_t_2 a_Clusters;
  } RSP_t_PreClusterListNS;                                          /* @vaddr:0x06010000 @vaddr_defs: RSP_VADDR_PRE_CLU_LST_NS @cycleid:RSP1_ENV @vname:RSP_PreClusterListNS */

} // endofnamespace RSP1_PRECLUSTERLIST_V6_2_PR_EN

#endif
