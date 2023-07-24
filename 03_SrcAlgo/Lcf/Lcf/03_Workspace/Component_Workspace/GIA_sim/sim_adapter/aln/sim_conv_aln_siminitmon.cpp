/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter aln

  MODULNAME:       sim_conv_aln_siminitmon

  DESCRIPTION:     Conversion module

  AUTHOR:          Fabian Diewald / Mohammad Altamash Yakoob

  CREATION DATE:   10.04.2014

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_aln_siminitmon.cpp  $
  CHANGES:         Revision 1.1 2017/08/10 13:14:54CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/aln/project.pj
  CHANGES:         Revision 2.5 2017/05/17 15:29:34CEST Schmitz, David (uidq6182) 
  CHANGES:         * Added missing compiler switches for SRR520
  CHANGES:         Revision 2.4 2017/05/17 13:53:41CEST Schmitz, David (uidq6182) 
  CHANGES:         fixed Vrel adaption (Yawangle + LastEgoVelocity)
  CHANGES:         Revision 2.3 2017/05/17 08:26:03CEST Schmitz, David (uidq6182) 
  CHANGES:         * added a new structure version V104
  CHANGES:         * added the monopulse median value to the siminit structure
  CHANGES:         Revision 2.1 2017/04/05 13:30:09CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx]
  CHANGES:         ? Remove A Sample compatilbility
  CHANGES:         ? Clean up SimAdapters
  CHANGES:         ? Only have version V100 and above
  CHANGES:         Revision 1.29 2017/03/09 11:32:55CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS5xx/SRR5xx] Update SimAdapters for ALN_SimInit V102 and ALN_SimInitMon V103
  CHANGES:         Revision 1.28 2017/02/15 15:55:39CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         [ARS510/SRR520] Update SimAdapter for the interface changes caused by removal of Elevation feature in SRR520
  CHANGES:         Revision 1.27 2016/11/23 14:17:51CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Rename "aln_mon_path_comp_elev" to "aln_mon_process_frame" and make adaptions for following:
  CHANGES:         * Source code
  CHANGES:         * plug in
  CHANGES:         * Simulation adapter
  CHANGES:         * mo
  CHANGES:         Revision 1.26 2016/10/27 14:13:31CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Adaption of new SimInitMon structure for the new architecture "ALN_MON_PATH_COMP_ELEV".
  CHANGES:         Revision 1.25 2016/09/13 10:16:14CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Update Simulation adapters and Simulation plugin for ARS510
  CHANGES:         Revision 1.24 2016/06/29 15:35:50CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         fix "OutputElev" initialization
  CHANGES:         Revision 1.23 2016/06/08 16:09:25CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Compiler Swithch for Entry fixed
  CHANGES:         Revision 1.22 2016/06/08 16:02:10CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         SimAdapter Bug fix
  CHANGES:         Revision 1.21 2016/06/08 15:51:24CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         SimAdapter Bug fix
  CHANGES:         Revision 1.20 2016/06/06 08:13:52CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         SimInit changed to V20 - ARS410 ADE Partial Blockage mechanism
  CHANGES:         Revision 1.19 2016/04/12 11:27:21CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Sim adaptation fix for ARS400PR SimInitMon version 19
  CHANGES:         Revision 1.18 2016/04/05 08:07:12CEST Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         Implementation of SimAdapter changes for ARS400EN Tunnel Monitor
  CHANGES:         Revision 1.17 2016/03/15 13:13:43CET Yakoob, Mohammad Altamash (uidj9850) 
  CHANGES:         fix Sim_Adapter initialization leading to FPEs in SIL
  CHANGES:         Revision 1.16 2016/02/16 07:59:10CET Schluttig, Jakob (uidv7098) 
  CHANGES:         bugfix of v18 adaption for Entry
  CHANGES:         Revision 1.15 2016/02/12 13:07:36CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added V18
  CHANGES:         Revision 1.14 2016/02/03 10:47:42CET Schluttig, Jakob (uidv7098) 
  CHANGES:         generalized version check ; removed mistaken conversion of old tunnel structure (already in last revision, forgot to comment)
  CHANGES:         Revision 1.13 2016/02/02 17:46:01CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added version number checks for equal sized structures in ARS400EN project
  CHANGES:         Revision 1.12 2015/12/21 09:02:37CET Schluttig, Jakob (uidv7098) 
  CHANGES:         added versions 16, 16_v2, 17 ; added conversions for PathComp 14/16->16v2->17
  CHANGES:         Revision 1.11 2015/12/14 14:18:05CET Dagli-EXT, Goekhan (uidj7850) 
  CHANGES:         updated SimInitMon v14
  CHANGES:         Revision 1.10 2015/04/17 15:38:30CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         fixed v12_2 adapter ; added example rec. and ALN versions for v10, v11, v12, v12_2
  CHANGES:         - Added comments -  uidv7098 [Apr 17, 2015 3:38:34 PM CEST]
  CHANGES:         Change Package : 321616:1 http://mks-psad:7002/im/viewissue?selection=321616
  CHANGES:         Revision 1.9 2015/04/17 13:05:29CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added v12, v12_2 and v13 ; dedicated adaption of PathComp part not done yet
  CHANGES:         --- Added comments ---  uidv7098 [Apr 17, 2015 1:05:29 PM CEST]
  CHANGES:         Change Package : 321616:1 http://mks-psad:7002/im/viewissue?selection=321616
  CHANGES:         Revision 1.8 2014/10/09 16:38:51CEST Manea, Gabriela (ManeaG) 
  CHANGES:         small fix
  CHANGES:         --- Added comments ---  ManeaG [Oct 9, 2014 4:38:51 PM CEST]
  CHANGES:         Change Package : 263320:1 http://mks-psad:7002/im/viewissue?selection=263320
  CHANGES:         Revision 1.7 2014/10/01 08:25:30CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         fixed to work with erroneous version number "1u"
  CHANGES:         --- Added comments ---  uidv7098 [Oct 1, 2014 8:25:30 AM CEST]
  CHANGES:         Change Package : 215877:1 http://mks-psad:7002/im/viewissue?selection=215877
  CHANGES:         Revision 1.6 2014/09/23 12:35:15CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         updated SimInitMon v11
  CHANGES:         --- Added comments ---  uidv7098 [Sep 23, 2014 12:35:15 PM CEST]
  CHANGES:         Change Package : 264784:1 http://mks-psad:7002/im/viewissue?selection=264784
  CHANGES:         Revision 1.5 2014/09/19 16:32:55CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added ALN_SimInitMon adapter for v9, v10, v11
  CHANGES:         --- Added comments ---  uidv7098 [Sep 19, 2014 4:32:56 PM CEST]
  CHANGES:         Change Package : 264400:1 http://mks-psad:7002/im/viewissue?selection=264400
  CHANGES:         Revision 1.4 2014/07/23 17:10:56CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         always allow direct copy (do not explicitely check for intf version number in case of correct size)
  CHANGES:         --- Added comments ---  uidv7098 [Jul 23, 2014 5:10:56 PM CEST]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.3 2014/07/08 16:23:53CEST Schluttig, Jakob (uidv7098) 
  CHANGES:         added new IF versions for direct copy
  CHANGES:         --- Added comments ---  uidv7098 [Jul 8, 2014 4:23:53 PM CEST]
  CHANGES:         Change Package : 215875:1 http://mks-psad:7002/im/viewissue?selection=215875
  CHANGES:         Revision 1.2 2014/04/15 19:12:55CEST Diewald, Fabian (uidt8878) 
  CHANGES:         fix for V4
  CHANGES:         added V5
  CHANGES:         --- Added comments ---  uidt8878 [Apr 15, 2014 7:12:56 PM CEST]
  CHANGES:         Change Package : 228417:1 http://mks-psad:7002/im/viewissue?selection=228417
  CHANGES:         Revision 1.1 2014/04/11 12:42:03CEST Diewald, Fabian (uidt8878) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ALN_Alignment/04_Engineering/03_Workspace/algo/sim_adapter/aln/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_conv_aln_siminitmon.h"
#include "sim_versioninfo_impl.h"
#include "sim_adapter_cfg.h"

// Commonly used type definitions
typedef float float32;
typedef unsigned __int8 boolean, uint8;
typedef signed __int8 sint8;
typedef unsigned __int16 uint16;
typedef signed __int16 sint16;
typedef unsigned __int32 uint32;

typedef unsigned long AlgoDataTimeStamp_t;
typedef unsigned short AlgoCycleCounter_t;
typedef unsigned char AlgoSignalState_t;

typedef struct SignalHeader_t
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;

typedef enum
{
  ServiceAlignmentNotActive,
  ServiceAlignment,
  ServiceWriteToNvm,
  ServiceFinished,
  ServiceFailed,
  ServiceInvalid = 4294967295U
} ALN_Sevice_t_State;


/* Common */
#define ALN_SimInitMon_NumOfChannels                        (12u)
#define ALN_F_INVALID                                       (999999.f)

/* AzVrel */
#define ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax             (41u)
#define ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax_SRR         (25u)

/* Elevation */
#define ALN_MON_COMMON_u_NOF_MOVING_STATES                  (2u)
#define ALN_MON_ELEV_u_NOF_HIST_BINS                        (50)
#define ALN_MON_COMMON_f_ObstacleRangeMax                   (200.f)
#define ALN_MON_ELEV_u_NOF_AZ_ZONES                         (2u)
#define ALN_MON_ELEV_u_RESULT_BUFFER_SIZE                   (2u)

#if (CFG_SRR520_SWITCH == SWITCH_ON)
#ifdef ALN_MON_ELEV_u_NOF_HIST_BINS
#undef ALN_MON_ELEV_u_NOF_HIST_BINS
#define ALN_MON_ELEV_u_NOF_HIST_BINS                        (100)
#endif
#ifdef ALN_MON_ELEV_u_NOF_AZ_ZONES
#undef ALN_MON_ELEV_u_NOF_AZ_ZONES
#define ALN_MON_ELEV_u_NOF_AZ_ZONES                         (1u)
#endif
#endif

/* PathCompensation */
#define ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE              (2u)
#define ALN_MON_PATH_COMP_s_RANGEHISTBINS                   (12)
#define ALN_MON_PATH_COMP_s_NOF_AZIMUTHZONES_V100           (1)

/* PartialBlockage */
#define ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES             (2u)
#define ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES         (8u)
#define ALN_MON_PARTIAL_BLOCKAGE_s_ADE_ROLLING_BUFFER_SIZE  (4)

/* Monopulse */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
#define ALN_MON_MONOPULSE_u_SizeHistogramMonopulseBeamDiff  (33u)
#define ALN_MON_MONOPULSE_u_SizeHistogramMonopulse          (193u)
#endif

/* Tunnel */
#define ALN_MON_TUNNEL_u_NOF_FEATURES                       (2u)
#define ALN_MON_TUNNEL_u_HIST_LENGTH                        (3u)


typedef struct
{
  float f_Real;
  float f_Imag;
} t_Complexf32;

typedef struct
{
  float f_Amplitude;
  float f_Phase;
} t_ComplexPolarf32;


// ALN_MON_t_SimInit version 100
namespace ALN_SimInitMon_t_Radar5xx_V100
{
  /* s_Az */
  typedef struct 
  {
    float32 f_Misalignment;
    float32 f_Std;
  } ALN_MON_t_AzimuthMisalign;

  typedef struct
  {
    ALN_MON_t_AzimuthMisalign s_MisalnMinStd;
    float32                   f_SensorOrientationSign;
  } ALN_MON_AZ_t_SimInit;
  

  /* s_PathComp */
  typedef struct
  {
    float32      af_CovDiag0[ALN_SimInitMon_NumOfChannels];
    uint32       u_CovDiag0Count;
    t_Complexf32 a_CovDiag1[ALN_SimInitMon_NumOfChannels-1];
    uint32       u_CovDiag1Count;
  } ALN_MON_PATH_COMP_t_SimInitAzimuthZone;

  typedef struct
  {
    float32      af_CovDiag0[ALN_SimInitMon_NumOfChannels];
    t_Complexf32 a_CovDiag1[ALN_SimInitMon_NumOfChannels-1];
    float32      f_DistSinceErrorMonReset;
    uint16       u_CovDiag0Count,
                 u_CovDiag1Count;
  } ALN_MON_PATH_COMP_t_ErrorMonAzZoneSimInit;

  typedef struct
  {
    ALN_MON_PATH_COMP_t_ErrorMonAzZoneSimInit Az[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
    float32                                   f_ErrorPresentTime;
    sint8                                     s_ErrorLevel,
                                              as_ErrorLevelAz[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
#if (ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES == 2u)
    uint8                                     u_Dummy;
#endif
  } ALN_MON_PATH_COMP_t_ErrorMonSimInitData;

  typedef struct
  {
    float32 f_AmpVarSum;
    float32 f_AmpVarCount;
  } ALN_MON_PATH_COMP_t_SingleTargetSelectData;

  typedef struct
  {
    ALN_MON_PATH_COMP_t_SimInitAzimuthZone     a_AzZone[ALN_MON_PATH_COMP_s_NOF_AZIMUTHZONES_V100];
    float32                                    f_DistSinceAmpReset,
                                               f_DistSincePhaseReset;
    t_ComplexPolarf32                          a_AdjBuffer[ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE][ALN_SimInitMon_NumOfChannels];
    ALN_MON_PATH_COMP_t_ErrorMonSimInitData    ErrorMon;
    ALN_MON_PATH_COMP_t_SingleTargetSelectData SingleTargetSelectData_Amp[ALN_MON_PATH_COMP_s_NOF_AZIMUTHZONES_V100],
                                               SingleTargetSelectData_Phase[ALN_MON_PATH_COMP_s_NOF_AZIMUTHZONES_V100];
    uint8                                      u_AdjLevelAmp,
                                               u_AdjLevelPhase;
    uint8                                      au_dummy[2];
  } ALN_MON_PATH_COMP_t_SimInitScan;

  typedef struct
  {
    float32 af_ElevPhaseSumZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES];
    uint32  u_CovDiag1AltCountZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES];
    float32 af_ElevRollingBuffer[ALN_MON_PARTIAL_BLOCKAGE_s_ADE_ROLLING_BUFFER_SIZE],
            f_ADEObstacleRange,
            f_GlobADEObstacleRange,
            f_ElevErrorPresentTime;
    sint8   s_ElevBufferFillCount;
    uint8   au_dummy[3];
  }ALN_MON_ELEV_ADE_t_SimInitData;

  typedef struct
  {
    uint16        au_ElevPhaseHist[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES][ALN_MON_ELEV_u_NOF_HIST_BINS];
    uint32        u_CovDiag1AltCount[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES];
    float32       f_OutputElev,
                  f_OutputElevStd,
                  af_DistSinceElevReset[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES],
                  af_MisAlnElevAdjBuffer[ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE];
    ALN_MON_PATH_COMP_t_SingleTargetSelectData  a_SingleTargetSelectData_Elev[ALN_MON_COMMON_u_NOF_MOVING_STATES];
    ALN_MON_ELEV_ADE_t_SimInitData  a_SimInitElevErrorMon;
    uint8         au_HistRanges[ALN_MON_PATH_COMP_s_NOF_AZIMUTHZONES_V100][ALN_MON_PATH_COMP_s_RANGEHISTBINS];
    uint8         u_AdjLevel,
                  e_DrivingLvl,
                  u_dummy[2];
  } ALN_MON_PATH_COMP_t_SimInitElevationScan;

  typedef struct
  {
    ALN_MON_PATH_COMP_t_SimInitScan          s_Scan;
    ALN_MON_PATH_COMP_t_SimInitElevationScan s_ElevScan;
  } ALN_MON_PATH_COMP_t_SimInit;
  

  /* s_Tunnel */
  typedef struct
  {
    float32 af_SumFeat[ALN_MON_TUNNEL_u_NOF_FEATURES],
            af_SumFeatSq[ALN_MON_TUNNEL_u_NOF_FEATURES],
            f_TunnelHysteresis;
    uint32  au_NofMeas[ALN_MON_TUNNEL_u_NOF_FEATURES],
            au_TunnelHist[ALN_MON_TUNNEL_u_HIST_LENGTH];
  } ALN_MON_TUNNEL_t_SimInit;
  

  /* s_Vrel */
  typedef struct
  {
    float32 f_SumWeightedMisaln;
    float32 f_SumWeights;
  } ALN_AZ_VREL_t_MisalignmentAvgSums;

  typedef struct
  {
    ALN_AZ_VREL_t_MisalignmentAvgSums AzHistogram[ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax];
    float32                           f_LastVegoEstimate;
    float32                           f_YawAngle;
    uint32                            u_CyclesDrivCondFulfilled;
    uint32                            u_CyclesDrivCondFulfilledTotal;
    float32                           f_DistanceDrivCondFulfilledTotal;
    uint32                            u_TimeStampRSPClustersNearLastCycle;
    float32                           f_VegoVdyLastCycle;
  } ALN_AZ_VREL_t_SimInit;


  /* ALN_MON_t_SimInit */
  typedef struct
  {
    SignalHeader_t              sSigHeader;
    uint32                      u_VersionNumber;
    ALN_MON_AZ_t_SimInit        s_Az;
    ALN_MON_PATH_COMP_t_SimInit s_PathComp;
    ALN_MON_TUNNEL_t_SimInit    s_Tunnel;
    ALN_AZ_VREL_t_SimInit       s_Vrel;
    ALN_Sevice_t_State          e_Service;
    float32                     f_MaxProgress;
    boolean                     b_AIAFctFullyActivated;
    uint8                       a_Dummy[3];
  } ALN_MON_t_SimInit;
}// ALN_MON_t_SimInit version 100


// ALN_MON_t_SimInit version 101
namespace ALN_SimInitMon_t_Radar5xx_V101
{
  /* Elevation */
  typedef uint32 e_AlnDrvLevel_t;

  typedef struct
  {
    uint16          au_ElevPhaseHist[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES][ALN_MON_ELEV_u_NOF_HIST_BINS];
    uint32          au_CovDiag1AltCount[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES];
    float32         af_DistSinceElevReset[ALN_MON_ELEV_u_NOF_AZ_ZONES][ALN_MON_COMMON_u_NOF_MOVING_STATES],
                    af_MisAlnElevAdjBuffer[ALN_MON_ELEV_u_RESULT_BUFFER_SIZE],
                    f_OutputElev,
                    f_OutputElevStd;
    e_AlnDrvLevel_t e_DrivingLvl;
    uint8           u_AdjLevel;
    uint8           au_dummy[3];
  } ALN_MON_ELEV_t_SimInit;


  /* PathComp*/
  typedef struct
  {
    float32       af_CovDiag0[ALN_SimInitMon_NumOfChannels];
    uint32        u_CovDiag0Count;
    t_Complexf32  a_CovDiag1[ALN_SimInitMon_NumOfChannels-1];
    uint32        u_CovDiag1Count;
  } ALN_MON_PATH_COMP_t_CovDiag_SimInitData;

  typedef struct
  {
    ALN_MON_PATH_COMP_t_CovDiag_SimInitData CovDiags;
    float32                                 f_DistSinceAmpReset,
                                            f_DistSincePhaseReset;
    t_ComplexPolarf32                       a_AdjBuffer[ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE][ALN_SimInitMon_NumOfChannels];
    uint8                                   au_HistRanges[ALN_MON_PATH_COMP_s_RANGEHISTBINS];
    uint8                                   u_AdjLevelAmp,
                                            u_AdjLevelPhase;
    uint8                                   au_dummy[2];
  } ALN_MON_PATH_COMP_t_SimInit;


  /* Partial blockage */
  typedef struct
  {
    ALN_MON_PATH_COMP_t_CovDiag_SimInitData  CovDiags;
    float32                                  f_DistSinceNormTargetReset;
  } ALN_MON_PARTIAL_BLOCKAGE_t_AzZone_SimInitData;

  typedef struct
  {
    ALN_MON_PARTIAL_BLOCKAGE_t_AzZone_SimInitData Az[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
    float32                                       f_HysteresisTime;
    sint8                                         s_GlobErrorLevel,
                                                  as_LocErrorLevelAz[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
#if (ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES == 2u)
    uint8                                         u_Dummy;
#endif
  } ALN_MON_PARTBLOCK_t_NormTargetSimInitData;

  typedef struct
  {
    uint32  au_CovDiag1AltCountZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES];
    float32 af_ElevPhaseSumZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES],
            af_ElevRollingBuffer[ALN_MON_PARTIAL_BLOCKAGE_s_ADE_ROLLING_BUFFER_SIZE],
            f_GlobADEObstacleRange,
            f_LocADEObstacleRange,
            f_ADEHysteresisTime;
    sint8   s_ElevBufferFillCount;
    uint8   au_dummy[3];
  } ALN_MON_PARTBLOCK_t_ADESimInitData;

  typedef struct
  {
    ALN_MON_PARTBLOCK_t_NormTargetSimInitData NormTarget;
    ALN_MON_PARTBLOCK_t_ADESimInitData        ADE;
  } ALN_MON_PARTIAL_BLOCKAGE_t_SimInit;


  /* MonProcessFrameData */
  typedef struct
  {
    float32 f_AmpVarSum;
    float32 f_AmpVarCount;
  } ALN_MON_COMMON_t_SingleTargetSelectData;

  typedef struct
  {
    ALN_MON_COMMON_t_SingleTargetSelectData SingleTargetSelectData_Amp,
                                            SingleTargetSelectData_Phase;
    ALN_MON_COMMON_t_SingleTargetSelectData SingleTargetSelectData_Elev[ALN_MON_COMMON_u_NOF_MOVING_STATES];
  } ALN_MON_PROCESS_FRAME_t_SimInit;


  /* ALN_MON_t_SimInit */
  typedef struct
  {
    SignalHeader_t                                           sSigHeader;
    uint32                                                   u_VersionNumber;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_AZ_t_SimInit     s_Az;
    ALN_MON_ELEV_t_SimInit                                   Elevation;
    ALN_MON_PATH_COMP_t_SimInit                              PathComp;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_TUNNEL_t_SimInit Tunnel;
    ALN_MON_PARTIAL_BLOCKAGE_t_SimInit                       PartialBlockage;
    ALN_MON_PROCESS_FRAME_t_SimInit                          MonProcessFrameData;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_SimInit    s_Vrel;
    ALN_Sevice_t_State                                       e_Service;
    float32                                                  f_MaxProgress;
    boolean                                                  b_AIAFctFullyActivated;
    uint8                                                    a_Dummy[3];
  } ALN_MON_t_SimInit;
}// ALN_MON_t_SimInit version 101


// ALN_MON_t_SimInit version 102
namespace ALN_SimInitMon_t_Radar5xx_V102
{
  /* PathComp */
  typedef struct
  {
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_PATH_COMP_t_CovDiag_SimInitData CovDiags;
    float32                                                                 f_DistSinceAmpReset,
                                                                            f_DistSincePhaseReset;
    t_ComplexPolarf32                                                       a_AdjBuffer[ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE][ALN_SimInitMon_NumOfChannels];
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    uint8                                                                   au_HistRanges[ALN_MON_PATH_COMP_s_RANGEHISTBINS];
#endif                                                                      
    uint8                                                                   u_AdjLevelAmp,
                                                                            u_AdjLevelPhase;
    uint8                                                                   au_dummy[2];
  } ALN_MON_PATH_COMP_t_SimInit;


  /* Tunnel */
  typedef struct
  {
    float32 f_Sum,
            f_SumSq;
    uint32  u_NofMeas;
  } t_VarObserverSimInit;

  typedef struct
  {
    float32 f_Sum;
    uint32  u_NofMeas;
  } t_MeanObserverSimInit;

  typedef struct
  {
    float32 f_Sum;
    uint32  u_NofMeas;
    uint32  au_Hist[ALN_MON_TUNNEL_u_HIST_LENGTH];
  } t_HistObserverSimInit;

  typedef struct
  {
    t_VarObserverSimInit  AmplitudeObserver;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    t_VarObserverSimInit  ElevationObserver;
#endif
    t_MeanObserverSimInit TotalNumberObserver;
    t_MeanObserverSimInit SingleTargetObserver;
    t_HistObserverSimInit HistogramObserver;
    float32               f_TunnelHysteresis;
  } ALN_MON_TUNNEL_t_SimInit;


  /* Monopulse */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  typedef struct
  {
    uint16  au_HistMonopBeamDiff[ALN_MON_MONOPULSE_u_SizeHistogramMonopulseBeamDiff];
    uint32  u_NofSamples;
    float32 f_LastMedian;
  } ALN_MON_MONOPULSE_t_SimInitHistogram;

  typedef struct 
  {
    ALN_MON_MONOPULSE_t_SimInitHistogram a_Histogram[ALN_MON_MONOPULSE_u_SizeHistogramMonopulse];
    boolean                              b_AssignPparsToNvm;
  } ALN_MON_MONOPULSE_t_SimInit;
#endif


  /* PartialBlockage */
  typedef struct
  {
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_PATH_COMP_t_CovDiag_SimInitData CovDiags;
    float32                                                                 f_DistSinceNormTargetReset;
  } ALN_MON_PARTIAL_BLOCKAGE_t_AzZone_SimInitData;

  typedef struct
  {
    ALN_MON_PARTIAL_BLOCKAGE_t_AzZone_SimInitData Az[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
    float32                                       f_HysteresisTime;
    sint8                                         s_GlobErrorLevel,
                                                  as_LocErrorLevelAz[ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES];
#if (ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES == 2u)
    uint8                                         u_Dummy;
#endif
  } ALN_MON_PARTBLOCK_t_NormTargetSimInitData;

  typedef struct
  {
    uint32  au_CovDiag1AltCountZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES];
    float32 af_ElevPhaseSumZone[ALN_MON_PARTIAL_BLOCKAGE_u_ADE_NOF_AZ_ZONES],
            af_ElevRollingBuffer[ALN_MON_PARTIAL_BLOCKAGE_s_ADE_ROLLING_BUFFER_SIZE],
            f_GlobADEObstacleRange,
            f_LocADEObstacleRange,
            f_ADEHysteresisTime;
    sint8   s_ElevBufferFillCount;
    uint8   au_dummy[3];
  } ALN_MON_PARTBLOCK_t_ADESimInitData;


  typedef struct
  {
    ALN_MON_PARTBLOCK_t_NormTargetSimInitData NormTarget;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_MON_PARTBLOCK_t_ADESimInitData        ADE;
#endif
  } ALN_MON_PARTIAL_BLOCKAGE_t_SimInit;

  typedef struct
  {
    float32 f_AmpVarSum;
    float32 f_AmpVarCount;
  } ALN_MON_COMMON_t_SingleTargetSelectData;

  typedef struct
  {
    ALN_MON_COMMON_t_SingleTargetSelectData SingleTargetSelectData_Amp,
                                            SingleTargetSelectData_Phase;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_MON_COMMON_t_SingleTargetSelectData SingleTargetSelectData_Elev[ALN_MON_COMMON_u_NOF_MOVING_STATES];
#endif
  } ALN_MON_PROCESS_FRAME_t_SimInit;

  /* s_Vrel */
  typedef struct
  {
#if (CFG_SRR520_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_MisalignmentAvgSums AzHistogram[ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax_SRR];
#else
    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_MisalignmentAvgSums AzHistogram[ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax];
#endif
    float32                                                           f_LastVegoEstimate;
    float32                                                           f_YawAngle;
    uint32                                                            u_CyclesDrivCondFulfilled;
    uint32                                                            u_CyclesDrivCondFulfilledTotal;
    float32                                                           f_DistanceDrivCondFulfilledTotal;
    uint32                                                            u_TimeStampRSPClustersNearLastCycle;
    float32                                                           f_VegoVdyLastCycle;
  } ALN_AZ_VREL_t_SimInit;

  typedef struct
  {
    SignalHeader_t                                         sSigHeader;
    uint32                                                 u_VersionNumber;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_AZ_t_SimInit   s_Az;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_ELEV_t_SimInit Elevation;
#endif                                                    
    ALN_MON_PATH_COMP_t_SimInit                            PathComp;
    ALN_MON_TUNNEL_t_SimInit                               Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)                       
    ALN_MON_MONOPULSE_t_SimInit                            Monopulse;
#endif                                                     
    ALN_MON_PARTIAL_BLOCKAGE_t_SimInit                     PartialBlockage;
    ALN_MON_PROCESS_FRAME_t_SimInit                        MonProcessFrameData;
    ALN_AZ_VREL_t_SimInit                                  s_Vrel;
    ALN_Sevice_t_State                                     e_Service;
    float32                                                f_MaxProgress;
    boolean                                                b_AIAFctFullyActivated;
    uint8                                                  a_Dummy[3];
  } ALN_MON_t_SimInit;
}// ALN_MON_t_SimInit version 102


// ALN_MON_t_SimInit version 103
namespace ALN_SimInitMon_t_Radar5xx_V103
{
  /* s_Vrel */
  typedef struct
  {
#if (CFG_SRR520_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_MisalignmentAvgSums AzHistogram[ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax_SRR];
#else
    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_MisalignmentAvgSums AzHistogram[ALN_MON_AZ_VREL_u_NofAzHistogramBinsMax];
#endif
    float32                                                           f_LastVegoEstimate;
    float32                                                           f_YawAngle;
    float32                                                           f_TimeDrivCondFulfilled;
    float32                                                           f_TimeDrivCondFulfilledTotal;
    float32                                                           f_DistanceDrivCondFulfilledTotal;
  } ALN_MON_AZ_VREL_t_SimInit;

  typedef struct
  {
    SignalHeader_t                                                     sSigHeader;
    uint32                                                             u_VersionNumber;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_AZ_t_SimInit               s_Az;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_ELEV_t_SimInit             Elevation;
#endif
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PATH_COMP_t_SimInit        PathComp;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_TUNNEL_t_SimInit           Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_MONOPULSE_t_SimInit        Monopulse;
#endif
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PARTIAL_BLOCKAGE_t_SimInit PartialBlockage;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PROCESS_FRAME_t_SimInit    MonProcessFrameData;
    ALN_MON_AZ_VREL_t_SimInit                                          s_Vrel;
    ALN_Sevice_t_State                                                 e_Service;
    float32                                                            f_MaxProgress;
    boolean                                                            b_AIAFctFullyActivated;
    uint8                                                              a_Dummy[3];
  } ALN_MON_t_SimInit;
}// ALN_MON_t_SimInit version 103

// ALN_MON_t_SimInit version 104
namespace ALN_SimInitMon_t_Radar5xx_V104
{
  /* Monopulse */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  typedef struct
  {
    uint32  u_NofSamples;
    float32 f_LastMedian;
    float32 f_Median;
    uint16  au_HistMonopBeamDiff[ALN_MON_MONOPULSE_u_SizeHistogramMonopulseBeamDiff];
    uint8   a_dummy[2];
  } ALN_MON_MONOPULSE_t_SimInitHistogram;

  typedef struct 
  {
    ALN_MON_MONOPULSE_t_SimInitHistogram a_Histogram[ALN_MON_MONOPULSE_u_SizeHistogramMonopulse];
  } ALN_MON_MONOPULSE_t_SimInit;
#endif

  typedef struct
  {
    SignalHeader_t                                                     sSigHeader;
    uint32                                                             u_VersionNumber;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_AZ_t_SimInit               s_Az;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_ELEV_t_SimInit             Elevation;
#endif
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PATH_COMP_t_SimInit        PathComp;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_TUNNEL_t_SimInit           Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_MON_MONOPULSE_t_SimInit                                        Monopulse;
#endif
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PARTIAL_BLOCKAGE_t_SimInit PartialBlockage;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PROCESS_FRAME_t_SimInit    MonProcessFrameData;
    ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_AZ_VREL_t_SimInit          s_Vrel;
    ALN_Sevice_t_State                                                 e_Service;
    float32                                                            f_MaxProgress;
    boolean                                                            b_AIAFctFullyActivated;
    uint8                                                              a_Dummy[3];
  } ALN_MON_t_SimInit;
}// ALN_MON_t_SimInit version 104

// Generic ARS5xx & SRR5xx ALN_MON_t_SimInit
// Holds all possible structure members from all possible namespaces
namespace ALN_SimInitMon_t_Radar5xx_Gen
{
  typedef struct
  {
    SignalHeader_t                                                      sSigHeader;
    unsigned long                                                       u_VersionNumber;

    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_AZ_t_SimInit                s_Az_V100;

    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_ELEV_t_SimInit              s_Elevation_V101;
    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_PATH_COMP_t_SimInit         s_PathComp_V100;
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_PATH_COMP_t_SimInit         s_PathComp_V101;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PATH_COMP_t_SimInit         s_PathComp_V102;

    ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_TUNNEL_t_SimInit            s_Tunnel_V100;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_TUNNEL_t_SimInit            s_Tunnel_V102;
    
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_MONOPULSE_t_SimInit         s_Monopulse_V102;
    ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_MONOPULSE_t_SimInit         s_Monopulse_V104;
#endif

    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_PARTIAL_BLOCKAGE_t_SimInit  s_PartialBlockage_V101;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PARTIAL_BLOCKAGE_t_SimInit  s_PartialBlockage_V102;
    
    ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_PROCESS_FRAME_t_SimInit     s_MonProcessFrameData_V101;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_PROCESS_FRAME_t_SimInit     s_MonProcessFrameData_V102;

    ALN_SimInitMon_t_Radar5xx_V100::ALN_AZ_VREL_t_SimInit               s_Vrel_V100;
    ALN_SimInitMon_t_Radar5xx_V102::ALN_AZ_VREL_t_SimInit               s_Vrel_V102;
    ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_AZ_VREL_t_SimInit           s_Vrel_V103;

    ALN_Sevice_t_State                                                  e_Service;
    float32                                                             f_MaxProgress;
    boolean                                                             b_AIAFctFullyActivated;
  } ALN_MON_t_SimInit;
}

class CConvAlnSimInitMon : public CSimConverterBase
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

  ALN_SimInitMon_t_Radar5xx_Gen::ALN_MON_t_SimInit   m_BufGen;
  ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit  m_BufV100;
  ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit  m_BufV101;
  ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit  m_BufV102;
  ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit  m_BufV103;
  ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit  m_BufV104;

  // Initialization
  template <typename T> static void InitVersion (T & Dest, uint32 VersionNumber)
  {
    ::memset(&Dest, 0, sizeof(Dest));
    Dest.u_VersionNumber = VersionNumber;
  }

  // Conversions from provide port (input) to generic buffer
  void Convert_V100_to_Gen(const ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Src);
  void Convert_V101_to_Gen(const ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Src);
  void Convert_V102_to_Gen(const ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Src);
  void Convert_V103_to_Gen(const ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Src);
  void Convert_V104_to_Gen(const ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Src);

  // Conversions form generic buffer to receive port (output)
  void Convert_Gen_to_V100(ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Dest);
  void Convert_Gen_to_V101(ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Dest);
  void Convert_Gen_to_V102(ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Dest);
  void Convert_Gen_to_V103(ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Dest);
  void Convert_Gen_to_V104(ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Dest);

public:

  static const char *GetConverterTypeName()
  {
    return "ALN_SimInitMon";
  }

  CConvAlnSimInitMon(void);
  virtual ~CConvAlnSimInitMon(void);

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
  static CVersionInfoImpl VERSION100;
  static CVersionInfoImpl VERSION101;
  static CVersionInfoImpl VERSION102;
  static CVersionInfoImpl VERSION103;
  static CVersionInfoImpl VERSION104;

  enum AlnSImInitMonVersions
  {
    ALN_SIMINITMON_V100,
    ALN_SIMINITMON_V101,
    ALN_SIMINITMON_V102,
    ALN_SIMINITMON_V103,
    ALN_SIMINITMON_V104,
    ALNSIMINITMON_VERSION_COUNT
  };

  static const unsigned long SUPPORTED_SIZE[ALNSIMINITMON_VERSION_COUNT];

  static CVersionInfoImpl * const ALNSIMINITMON_VERSION_NUMBERS[ALNSIMINITMON_VERSION_COUNT];

  bool PortSupported (SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo = NULL) const;

};

CVersionInfoImpl CConvAlnSimInitMon::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvAlnSimInitMon::VERSION100(0, 0, 100);
CVersionInfoImpl CConvAlnSimInitMon::VERSION101(0, 0, 101);
CVersionInfoImpl CConvAlnSimInitMon::VERSION102(0, 0, 102);
CVersionInfoImpl CConvAlnSimInitMon::VERSION103(0, 0, 103);
CVersionInfoImpl CConvAlnSimInitMon::VERSION104(0, 0, 104);

const unsigned long CConvAlnSimInitMon::SUPPORTED_SIZE[CConvAlnSimInitMon::ALNSIMINITMON_VERSION_COUNT] =
{
  sizeof(ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit),
  sizeof(ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit),
  sizeof(ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit),
  sizeof(ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit),
  sizeof(ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit)
};

CVersionInfoImpl * const CConvAlnSimInitMon::ALNSIMINITMON_VERSION_NUMBERS[CConvAlnSimInitMon::ALNSIMINITMON_VERSION_COUNT]=
{
  &VERSION100,
  &VERSION101,
  &VERSION102,
  &VERSION103,
  &VERSION104
};


CConvAlnSimInitMon::CConvAlnSimInitMon(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), 
  m_BufGen(), m_BufV100(), m_BufV101(), m_BufV102(), m_BufV103(), m_BufV104()
{
}

CConvAlnSimInitMon::~CConvAlnSimInitMon(void)
{
}

bool CConvAlnSimInitMon::PortSupported(SimPortDataTypes_t ePortType, unsigned long ulPortSize, const IVersionInfo * pPortVersionInfo) const
{
  bool bResult = false;
  unsigned int i;

  if (ePortType == simOPAQUE_t)
  {
    for (i=0; (i<CConvAlnSimInitMon::ALNSIMINITMON_VERSION_COUNT) && (false == bResult); i++)
    {
      if (ulPortSize == SUPPORTED_SIZE[i])
      {
        // Check if version information is compatible - with extra care for simulators that do not set the version number at all...
        if ((pPortVersionInfo == NULL) || (pPortVersionInfo->Equals(ALNSIMINITMON_VERSION_NUMBERS[i])) || (pPortVersionInfo->Equals(&BASE_VERSION)))
        {
          bResult = true;
        }
      }
    }
  }
  return bResult;
}

void CConvAlnSimInitMon::Convert_V100_to_Gen (const ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Src)
{   
  m_BufGen.sSigHeader             = Src.sSigHeader;
  m_BufGen.u_VersionNumber        = Src.u_VersionNumber;
  m_BufGen.e_Service              = Src.e_Service;
  m_BufGen.f_MaxProgress          = Src.f_MaxProgress;
  m_BufGen.b_AIAFctFullyActivated = Src.b_AIAFctFullyActivated;


  /* V100 */
  m_BufGen.s_Az_V100       = Src.s_Az;
  m_BufGen.s_PathComp_V100 = Src.s_PathComp;
  m_BufGen.s_Tunnel_V100   = Src.s_Tunnel;
  m_BufGen.s_Vrel_V100     = Src.s_Vrel;
  

  /* V101 */
  memset(&(m_BufGen.s_Elevation_V101), 0, sizeof(m_BufGen.s_Elevation_V101));
  memset(&(m_BufGen.s_PathComp_V101), 0, sizeof(m_BufGen.s_PathComp_V101));
  memset(&(m_BufGen.s_PartialBlockage_V101), 0, sizeof(m_BufGen.s_PartialBlockage_V101));
  memset(&(m_BufGen.s_MonProcessFrameData_V101), 0, sizeof(m_BufGen.s_MonProcessFrameData_V101));

  memcpy(m_BufGen.s_Elevation_V101.au_ElevPhaseHist,m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist,sizeof(m_BufGen.s_Elevation_V101.au_ElevPhaseHist));
  memcpy(m_BufGen.s_Elevation_V101.au_CovDiag1AltCount,m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount,sizeof(m_BufGen.s_Elevation_V101.au_CovDiag1AltCount));
  memcpy(m_BufGen.s_Elevation_V101.af_DistSinceElevReset,m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset,sizeof(m_BufGen.s_Elevation_V101.af_DistSinceElevReset));
  memcpy(m_BufGen.s_Elevation_V101.af_MisAlnElevAdjBuffer,m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer,sizeof(m_BufGen.s_Elevation_V101.af_MisAlnElevAdjBuffer));
  m_BufGen.s_Elevation_V101.f_OutputElev = m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElev;
  m_BufGen.s_Elevation_V101.f_OutputElevStd = m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElevStd;
  m_BufGen.s_Elevation_V101.e_DrivingLvl = m_BufGen.s_PathComp_V100.s_ElevScan.e_DrivingLvl;
  m_BufGen.s_Elevation_V101.u_AdjLevel = m_BufGen.s_PathComp_V100.s_ElevScan.u_AdjLevel;

  memcpy(m_BufGen.s_PathComp_V101.au_HistRanges,m_BufGen.s_PathComp_V100.s_ElevScan.au_HistRanges,sizeof(m_BufGen.s_PathComp_V101.au_HistRanges));

  memcpy(m_BufGen.s_PartialBlockage_V101.ADE.au_CovDiag1AltCountZone,m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.u_CovDiag1AltCountZone,sizeof(m_BufGen.s_PartialBlockage_V101.ADE.au_CovDiag1AltCountZone));
  memcpy(m_BufGen.s_PartialBlockage_V101.ADE.af_ElevPhaseSumZone,m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevPhaseSumZone,sizeof(m_BufGen.s_PartialBlockage_V101.ADE.af_ElevPhaseSumZone));
  memcpy(m_BufGen.s_PartialBlockage_V101.ADE.af_ElevRollingBuffer,m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevRollingBuffer,sizeof(m_BufGen.s_PartialBlockage_V101.ADE.af_ElevRollingBuffer));
  m_BufGen.s_PartialBlockage_V101.ADE.f_GlobADEObstacleRange = m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange;
  m_BufGen.s_PartialBlockage_V101.ADE.f_LocADEObstacleRange = m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange;
  m_BufGen.s_PartialBlockage_V101.ADE.f_ADEHysteresisTime = m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ElevErrorPresentTime;
  m_BufGen.s_PartialBlockage_V101.ADE.s_ElevBufferFillCount = m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.s_ElevBufferFillCount;

  memcpy(&m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Elev[0],&m_BufGen.s_PathComp_V100.s_ElevScan.a_SingleTargetSelectData_Elev[0],sizeof(m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Elev));

  memcpy(&m_BufGen.s_PathComp_V101.CovDiags,&m_BufGen.s_PathComp_V100.s_Scan.a_AzZone[0], sizeof(m_BufGen.s_PathComp_V101.CovDiags));
  m_BufGen.s_PathComp_V101.f_DistSinceAmpReset = m_BufGen.s_PathComp_V100.s_Scan.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V101.f_DistSincePhaseReset = m_BufGen.s_PathComp_V100.s_Scan.f_DistSincePhaseReset;
  memcpy(m_BufGen.s_PathComp_V101.a_AdjBuffer,m_BufGen.s_PathComp_V100.s_Scan.a_AdjBuffer, sizeof(m_BufGen.s_PathComp_V101.a_AdjBuffer));
  m_BufGen.s_PathComp_V101.u_AdjLevelAmp    = m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V101.u_AdjLevelPhase  = m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelPhase;
  for (uint8 u_AzZone = 0u; u_AzZone < ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES; u_AzZone++)
  {
    memcpy(m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0,m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].af_CovDiag0,sizeof(m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0));
    memcpy(m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1,m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].a_CovDiag1,sizeof(m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1));
    m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag0Count = m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag0Count;
    m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag1Count = m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag1Count;
    m_BufGen.s_PartialBlockage_V101.NormTarget.Az[u_AzZone].f_DistSinceNormTargetReset = m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].f_DistSinceErrorMonReset;
    m_BufGen.s_PartialBlockage_V101.NormTarget.as_LocErrorLevelAz[u_AzZone]= m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.as_ErrorLevelAz[u_AzZone];
  }
  m_BufGen.s_PartialBlockage_V101.NormTarget.f_HysteresisTime = m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.f_ErrorPresentTime;
  m_BufGen.s_PartialBlockage_V101.NormTarget.s_GlobErrorLevel = m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.s_ErrorLevel;

  memcpy(&m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Amp,&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Amp[0],sizeof(m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Amp));
  memcpy(&m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Phase,&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Phase[0],sizeof(m_BufGen.s_MonProcessFrameData_V101.SingleTargetSelectData_Phase));
  
  
  /* V102 */
  memset(&(m_BufGen.s_PathComp_V102), 0, sizeof(m_BufGen.s_PathComp_V102));
  memset(&(m_BufGen.s_Tunnel_V102), 0, sizeof(m_BufGen.s_Tunnel_V102));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset(&(m_BufGen.s_Monopulse_V102), 0, sizeof(m_BufGen.s_Monopulse_V102));
#endif
  memset(&(m_BufGen.s_PartialBlockage_V102), 0, sizeof(m_BufGen.s_PartialBlockage_V102));
  memset(&(m_BufGen.s_MonProcessFrameData_V102), 0, sizeof(m_BufGen.s_MonProcessFrameData_V102));
  memset(&(m_BufGen.s_Vrel_V102), 0, sizeof(m_BufGen.s_Vrel_V102));

  memcpy(&(m_BufGen.s_PathComp_V102.CovDiags),&(m_BufGen.s_PathComp_V101.CovDiags),sizeof(m_BufGen.s_PathComp_V102.CovDiags));
  m_BufGen.s_PathComp_V102.f_DistSinceAmpReset = m_BufGen.s_PathComp_V101.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V102.f_DistSincePhaseReset = m_BufGen.s_PathComp_V101.f_DistSincePhaseReset;
  memcpy(&(m_BufGen.s_PathComp_V102.a_AdjBuffer),&(m_BufGen.s_PathComp_V101.a_AdjBuffer),sizeof(m_BufGen.s_PathComp_V102.a_AdjBuffer));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.s_PathComp_V102.au_HistRanges),&(m_BufGen.s_PathComp_V101.au_HistRanges),sizeof(m_BufGen.s_PathComp_V102.au_HistRanges));
#endif
  m_BufGen.s_PathComp_V102.u_AdjLevelAmp = m_BufGen.s_PathComp_V101.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V102.u_AdjLevelPhase = m_BufGen.s_PathComp_V101.u_AdjLevelPhase;
  
  memcpy(&(m_BufGen.s_PartialBlockage_V102), &(m_BufGen.s_PartialBlockage_V101), sizeof(m_BufGen.s_PartialBlockage_V102));
  memcpy(&(m_BufGen.s_MonProcessFrameData_V102), &(m_BufGen.s_MonProcessFrameData_V101), sizeof(m_BufGen.s_MonProcessFrameData_V102));
  if (sizeof(m_BufGen.s_Vrel_V102) == sizeof(Src.s_Vrel))
  {
    memcpy(&(m_BufGen.s_Vrel_V102), &(Src.s_Vrel), sizeof(m_BufGen.s_Vrel_V102));
  }
  m_BufGen.s_Vrel_V102.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V102.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V103 */
  memset(&(m_BufGen.s_Vrel_V103), 0, sizeof(m_BufGen.s_Vrel_V103));
  if (sizeof(m_BufGen.s_Vrel_V103.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V103.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V103.AzHistogram));
  }
  m_BufGen.s_Vrel_V103.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V103.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V104 */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset((&m_BufGen.s_Monopulse_V104.a_Histogram), 0, sizeof(m_BufGen.s_Monopulse_V104.a_Histogram));
#endif
}

void CConvAlnSimInitMon::Convert_V101_to_Gen (const ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Src)
{   
  m_BufGen.sSigHeader             = Src.sSigHeader;
  m_BufGen.u_VersionNumber        = Src.u_VersionNumber;
  m_BufGen.e_Service              = Src.e_Service;
  m_BufGen.f_MaxProgress          = Src.f_MaxProgress;
  m_BufGen.b_AIAFctFullyActivated = Src.b_AIAFctFullyActivated;


  /* V101 */
  m_BufGen.s_Elevation_V101           = Src.Elevation;
  m_BufGen.s_PathComp_V101            = Src.PathComp;
  m_BufGen.s_PartialBlockage_V101     = Src.PartialBlockage;
  m_BufGen.s_MonProcessFrameData_V101 = Src.MonProcessFrameData;


  /* V100 */
  m_BufGen.s_Az_V100     = Src.s_Az;
  m_BufGen.s_Tunnel_V100 = Src.Tunnel;
  m_BufGen.s_Vrel_V100   = Src.s_Vrel;
  memset(&(m_BufGen.s_PathComp_V100), 0, sizeof(m_BufGen.s_PathComp_V100));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist, Src.Elevation.au_ElevPhaseHist, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount, Src.Elevation.au_CovDiag1AltCount, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount));
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElev = Src.Elevation.f_OutputElev;
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElevStd = Src.Elevation.f_OutputElevStd;
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset, Src.Elevation.af_DistSinceElevReset, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer, Src.Elevation.af_MisAlnElevAdjBuffer, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.u_AdjLevel = Src.Elevation.u_AdjLevel;
  m_BufGen.s_PathComp_V100.s_ElevScan.e_DrivingLvl = Src.Elevation.e_DrivingLvl;

  memcpy(&m_BufGen.s_PathComp_V100.s_ElevScan.a_SingleTargetSelectData_Elev[0],&Src.MonProcessFrameData.SingleTargetSelectData_Elev[0],sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Elev));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_HistRanges,Src.PathComp.au_HistRanges,sizeof(Src.PathComp.au_HistRanges));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevPhaseSumZone, Src.PartialBlockage.ADE.af_ElevPhaseSumZone,sizeof(Src.PartialBlockage.ADE.af_ElevPhaseSumZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.u_CovDiag1AltCountZone, Src.PartialBlockage.ADE.au_CovDiag1AltCountZone,sizeof(Src.PartialBlockage.ADE.au_CovDiag1AltCountZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevRollingBuffer, Src.PartialBlockage.ADE.af_ElevRollingBuffer,sizeof(Src.PartialBlockage.ADE.af_ElevRollingBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange = Src.PartialBlockage.ADE.f_LocADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange = Src.PartialBlockage.ADE.f_GlobADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ElevErrorPresentTime = Src.PartialBlockage.ADE.f_ADEHysteresisTime;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.s_ElevBufferFillCount = Src.PartialBlockage.ADE.s_ElevBufferFillCount;

  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.a_AzZone[0],&Src.PathComp.CovDiags, sizeof(Src.PathComp.CovDiags));
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSinceAmpReset = Src.PathComp.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSincePhaseReset = Src.PathComp.f_DistSincePhaseReset;
  memcpy(m_BufGen.s_PathComp_V100.s_Scan.a_AdjBuffer,Src.PathComp.a_AdjBuffer, sizeof(Src.PathComp.a_AdjBuffer));
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelAmp    = Src.PathComp.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelPhase  = Src.PathComp.u_AdjLevelPhase;
  for (uint8 u_AzZone = 0u; u_AzZone < ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES; u_AzZone++)
  {
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].af_CovDiag0,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0));
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].a_CovDiag1,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1));
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag0Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag0Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag1Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag1Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].f_DistSinceErrorMonReset = Src.PartialBlockage.NormTarget.Az[u_AzZone].f_DistSinceNormTargetReset;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.as_ErrorLevelAz[u_AzZone]= Src.PartialBlockage.NormTarget.as_LocErrorLevelAz[u_AzZone];
  }
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.f_ErrorPresentTime = Src.PartialBlockage.NormTarget.f_HysteresisTime;
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.s_ErrorLevel = Src.PartialBlockage.NormTarget.s_GlobErrorLevel;
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Amp[0],&Src.MonProcessFrameData.SingleTargetSelectData_Amp,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Amp));
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Phase[0],&Src.MonProcessFrameData.SingleTargetSelectData_Phase,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Phase));
  

  /* V102 */
  memset(&(m_BufGen.s_PathComp_V102), 0, sizeof(m_BufGen.s_PathComp_V102));
  memset(&(m_BufGen.s_Tunnel_V102), 0, sizeof(m_BufGen.s_Tunnel_V102));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset(&(m_BufGen.s_Monopulse_V102), 0, sizeof(m_BufGen.s_Monopulse_V102));
#endif
  memset(&(m_BufGen.s_PartialBlockage_V102), 0, sizeof(m_BufGen.s_PartialBlockage_V102));
  memset(&(m_BufGen.s_MonProcessFrameData_V102), 0, sizeof(m_BufGen.s_MonProcessFrameData_V102));
  memset(&(m_BufGen.s_Vrel_V102), 0, sizeof(m_BufGen.s_Vrel_V102));

  memcpy(&(m_BufGen.s_PathComp_V102.CovDiags),&(m_BufGen.s_PathComp_V101.CovDiags),sizeof(m_BufGen.s_PathComp_V102.CovDiags));
  m_BufGen.s_PathComp_V102.f_DistSinceAmpReset = m_BufGen.s_PathComp_V101.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V102.f_DistSincePhaseReset = m_BufGen.s_PathComp_V101.f_DistSincePhaseReset;
  memcpy(&(m_BufGen.s_PathComp_V102.a_AdjBuffer),&(m_BufGen.s_PathComp_V101.a_AdjBuffer),sizeof(m_BufGen.s_PathComp_V102.a_AdjBuffer));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.s_PathComp_V102.au_HistRanges),&(m_BufGen.s_PathComp_V101.au_HistRanges),sizeof(m_BufGen.s_PathComp_V102.au_HistRanges));
#endif
  m_BufGen.s_PathComp_V102.u_AdjLevelAmp = m_BufGen.s_PathComp_V101.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V102.u_AdjLevelPhase = m_BufGen.s_PathComp_V101.u_AdjLevelPhase;

  memcpy(&(m_BufGen.s_PartialBlockage_V102), &(m_BufGen.s_PartialBlockage_V101), sizeof(m_BufGen.s_PartialBlockage_V102));
  memcpy(&(m_BufGen.s_MonProcessFrameData_V102), &(m_BufGen.s_MonProcessFrameData_V101), sizeof(m_BufGen.s_MonProcessFrameData_V102));
  if (sizeof(m_BufGen.s_Vrel_V102) == sizeof(Src.s_Vrel))
  {
    memcpy(&(m_BufGen.s_Vrel_V102), &(Src.s_Vrel), sizeof(m_BufGen.s_Vrel_V102));
  }
  m_BufGen.s_Vrel_V102.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V102.f_YawAngle           = Src.s_Vrel.f_YawAngle;
  
  /* V103 */
  memset(&(m_BufGen.s_Vrel_V103), 0, sizeof(m_BufGen.s_Vrel_V103));
  if (sizeof(m_BufGen.s_Vrel_V103.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V103.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V103.AzHistogram));
  }
  m_BufGen.s_Vrel_V103.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V103.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V104 */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset((&m_BufGen.s_Monopulse_V104.a_Histogram), 0, sizeof(m_BufGen.s_Monopulse_V104.a_Histogram));
#endif
}

void CConvAlnSimInitMon::Convert_V102_to_Gen (const ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Src)
{   
  m_BufGen.sSigHeader             = Src.sSigHeader;
  m_BufGen.u_VersionNumber        = Src.u_VersionNumber;
  m_BufGen.e_Service              = Src.e_Service;
  m_BufGen.f_MaxProgress          = Src.f_MaxProgress;
  m_BufGen.b_AIAFctFullyActivated = Src.b_AIAFctFullyActivated;

  
  /* V102 */
  m_BufGen.s_PathComp_V102  = Src.PathComp;
  m_BufGen.s_Tunnel_V102    = Src.Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Monopulse_V102 = Src.Monopulse;
#endif
  m_BufGen.s_PartialBlockage_V102     = Src.PartialBlockage;
  m_BufGen.s_MonProcessFrameData_V102 = Src.MonProcessFrameData;
  m_BufGen.s_Vrel_V102 = Src.s_Vrel;


  /* V100 */
  m_BufGen.s_Az_V100 = Src.s_Az;
  memset(&(m_BufGen.s_PathComp_V100), 0, sizeof(m_BufGen.s_PathComp_V100));
  memset(&(m_BufGen.s_Tunnel_V100), 0, sizeof(m_BufGen.s_Tunnel_V100));
  memset(&(m_BufGen.s_Vrel_V100), 0, sizeof(m_BufGen.s_Vrel_V100));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist, Src.Elevation.au_ElevPhaseHist, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount, Src.Elevation.au_CovDiag1AltCount, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount));
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElev = Src.Elevation.f_OutputElev;
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElevStd = Src.Elevation.f_OutputElevStd;
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset, Src.Elevation.af_DistSinceElevReset, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer, Src.Elevation.af_MisAlnElevAdjBuffer, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.u_AdjLevel = Src.Elevation.u_AdjLevel;
  m_BufGen.s_PathComp_V100.s_ElevScan.e_DrivingLvl = Src.Elevation.e_DrivingLvl;

  memcpy(&m_BufGen.s_PathComp_V100.s_ElevScan.a_SingleTargetSelectData_Elev[0],&Src.MonProcessFrameData.SingleTargetSelectData_Elev[0],sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Elev));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_HistRanges,Src.PathComp.au_HistRanges,sizeof(Src.PathComp.au_HistRanges));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevPhaseSumZone, Src.PartialBlockage.ADE.af_ElevPhaseSumZone,sizeof(Src.PartialBlockage.ADE.af_ElevPhaseSumZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.u_CovDiag1AltCountZone, Src.PartialBlockage.ADE.au_CovDiag1AltCountZone,sizeof(Src.PartialBlockage.ADE.au_CovDiag1AltCountZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevRollingBuffer, Src.PartialBlockage.ADE.af_ElevRollingBuffer,sizeof(Src.PartialBlockage.ADE.af_ElevRollingBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange = Src.PartialBlockage.ADE.f_LocADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange = Src.PartialBlockage.ADE.f_GlobADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ElevErrorPresentTime = Src.PartialBlockage.ADE.f_ADEHysteresisTime;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.s_ElevBufferFillCount = Src.PartialBlockage.ADE.s_ElevBufferFillCount;
#endif

  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.a_AzZone[0],&Src.PathComp.CovDiags, sizeof(Src.PathComp.CovDiags));
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSinceAmpReset = Src.PathComp.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSincePhaseReset = Src.PathComp.f_DistSincePhaseReset;
  memcpy(m_BufGen.s_PathComp_V100.s_Scan.a_AdjBuffer,Src.PathComp.a_AdjBuffer, sizeof(Src.PathComp.a_AdjBuffer));
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelAmp    = Src.PathComp.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelPhase  = Src.PathComp.u_AdjLevelPhase;
  for (uint8 u_AzZone = 0u; u_AzZone < ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES; u_AzZone++)
  {
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].af_CovDiag0,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0));
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].a_CovDiag1,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1));
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag0Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag0Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag1Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag1Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].f_DistSinceErrorMonReset = Src.PartialBlockage.NormTarget.Az[u_AzZone].f_DistSinceNormTargetReset;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.as_ErrorLevelAz[u_AzZone]= Src.PartialBlockage.NormTarget.as_LocErrorLevelAz[u_AzZone];
  }
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.f_ErrorPresentTime = Src.PartialBlockage.NormTarget.f_HysteresisTime;
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.s_ErrorLevel = Src.PartialBlockage.NormTarget.s_GlobErrorLevel;
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Amp[0],&Src.MonProcessFrameData.SingleTargetSelectData_Amp,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Amp));
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Phase[0],&Src.MonProcessFrameData.SingleTargetSelectData_Phase,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Phase));
  if (sizeof(m_BufGen.s_Vrel_V100) == sizeof(Src.s_Vrel))
  {
    memcpy(&(m_BufGen.s_Vrel_V100), &(Src.s_Vrel), sizeof(m_BufGen.s_Vrel_V100));
  }
  m_BufGen.s_Vrel_V100.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V100.f_YawAngle           = Src.s_Vrel.f_YawAngle;
  
  
  /* V101 */
  memset(&(m_BufGen.s_Elevation_V101), 0, sizeof(m_BufGen.s_Elevation_V101));
  memset(&(m_BufGen.s_PathComp_V101), 0, sizeof(m_BufGen.s_PathComp_V101));
  memset(&(m_BufGen.s_PartialBlockage_V101), 0, sizeof(m_BufGen.s_PartialBlockage_V101));
  memset(&(m_BufGen.s_MonProcessFrameData_V101), 0, sizeof(m_BufGen.s_MonProcessFrameData_V101));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Elevation_V101 = Src.Elevation;
#endif
  memcpy(&(m_BufGen.s_PathComp_V101.CovDiags),&(m_BufGen.s_PathComp_V102.CovDiags),sizeof(m_BufGen.s_PathComp_V101.CovDiags));
  m_BufGen.s_PathComp_V101.f_DistSinceAmpReset = m_BufGen.s_PathComp_V102.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V101.f_DistSincePhaseReset = m_BufGen.s_PathComp_V102.f_DistSincePhaseReset;
  memcpy(&(m_BufGen.s_PathComp_V101.a_AdjBuffer),&(m_BufGen.s_PathComp_V102.a_AdjBuffer),sizeof(m_BufGen.s_PathComp_V101.a_AdjBuffer));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.s_PathComp_V101.au_HistRanges),&(m_BufGen.s_PathComp_V102.au_HistRanges),sizeof(m_BufGen.s_PathComp_V101.au_HistRanges));
#endif
  m_BufGen.s_PathComp_V101.u_AdjLevelAmp = m_BufGen.s_PathComp_V102.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V101.u_AdjLevelPhase = m_BufGen.s_PathComp_V102.u_AdjLevelPhase;
  memcpy(&(m_BufGen.s_PartialBlockage_V101), &(m_BufGen.s_PartialBlockage_V102), sizeof(m_BufGen.s_PartialBlockage_V101));
  memcpy(&(m_BufGen.s_MonProcessFrameData_V101), &(m_BufGen.s_MonProcessFrameData_V102), sizeof(m_BufGen.s_MonProcessFrameData_V101));
  

  /* V103 */
  memset(&(m_BufGen.s_Vrel_V103), 0, sizeof(m_BufGen.s_Vrel_V103));
  if (sizeof(m_BufGen.s_Vrel_V103.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V103.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V103.AzHistogram));
  }
  m_BufGen.s_Vrel_V103.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V103.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V104 */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset((&m_BufGen.s_Monopulse_V104.a_Histogram), 0, sizeof(m_BufGen.s_Monopulse_V104.a_Histogram));
#endif
}

void CConvAlnSimInitMon::Convert_V103_to_Gen (const ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Src)
{   
  m_BufGen.sSigHeader             = Src.sSigHeader;
  m_BufGen.u_VersionNumber        = Src.u_VersionNumber;
  m_BufGen.e_Service              = Src.e_Service;
  m_BufGen.f_MaxProgress          = Src.f_MaxProgress;
  m_BufGen.b_AIAFctFullyActivated = Src.b_AIAFctFullyActivated;

  
  /* V103 */
  m_BufGen.s_Vrel_V103 = Src.s_Vrel;


  /* V102 */
  m_BufGen.s_PathComp_V102            = Src.PathComp;
  m_BufGen.s_Tunnel_V102              = Src.Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Monopulse_V102           = Src.Monopulse;
#endif
  m_BufGen.s_PartialBlockage_V102     = Src.PartialBlockage;
  m_BufGen.s_MonProcessFrameData_V102 = Src.MonProcessFrameData;
  memset(&(m_BufGen.s_Vrel_V102), 0, sizeof(m_BufGen.s_Vrel_V102));
  if (sizeof(m_BufGen.s_Vrel_V102.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V102.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V102.AzHistogram));
  }
  m_BufGen.s_Vrel_V102.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V102.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V100 */
  m_BufGen.s_Az_V100 = Src.s_Az;
  memset(&(m_BufGen.s_PathComp_V100), 0, sizeof(m_BufGen.s_PathComp_V100));
  memset(&(m_BufGen.s_Tunnel_V100), 0, sizeof(m_BufGen.s_Tunnel_V100));
  memset(&(m_BufGen.s_Vrel_V100), 0, sizeof(m_BufGen.s_Vrel_V100));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist, Src.Elevation.au_ElevPhaseHist, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount, Src.Elevation.au_CovDiag1AltCount, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount));
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElev = Src.Elevation.f_OutputElev;
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElevStd = Src.Elevation.f_OutputElevStd;
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset, Src.Elevation.af_DistSinceElevReset, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer, Src.Elevation.af_MisAlnElevAdjBuffer, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.u_AdjLevel = Src.Elevation.u_AdjLevel;
  m_BufGen.s_PathComp_V100.s_ElevScan.e_DrivingLvl = Src.Elevation.e_DrivingLvl;

  memcpy(&m_BufGen.s_PathComp_V100.s_ElevScan.a_SingleTargetSelectData_Elev[0],&Src.MonProcessFrameData.SingleTargetSelectData_Elev[0],sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Elev));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_HistRanges,Src.PathComp.au_HistRanges,sizeof(Src.PathComp.au_HistRanges));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevPhaseSumZone, Src.PartialBlockage.ADE.af_ElevPhaseSumZone,sizeof(Src.PartialBlockage.ADE.af_ElevPhaseSumZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.u_CovDiag1AltCountZone, Src.PartialBlockage.ADE.au_CovDiag1AltCountZone,sizeof(Src.PartialBlockage.ADE.au_CovDiag1AltCountZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevRollingBuffer, Src.PartialBlockage.ADE.af_ElevRollingBuffer,sizeof(Src.PartialBlockage.ADE.af_ElevRollingBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange = Src.PartialBlockage.ADE.f_LocADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange = Src.PartialBlockage.ADE.f_GlobADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ElevErrorPresentTime = Src.PartialBlockage.ADE.f_ADEHysteresisTime;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.s_ElevBufferFillCount = Src.PartialBlockage.ADE.s_ElevBufferFillCount;
#endif

  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.a_AzZone[0],&Src.PathComp.CovDiags, sizeof(Src.PathComp.CovDiags));
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSinceAmpReset = Src.PathComp.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSincePhaseReset = Src.PathComp.f_DistSincePhaseReset;
  memcpy(m_BufGen.s_PathComp_V100.s_Scan.a_AdjBuffer,Src.PathComp.a_AdjBuffer, sizeof(Src.PathComp.a_AdjBuffer));
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelAmp    = Src.PathComp.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelPhase  = Src.PathComp.u_AdjLevelPhase;
  for (uint8 u_AzZone = 0u; u_AzZone < ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES; u_AzZone++)
  {
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].af_CovDiag0,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0));
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].a_CovDiag1,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1));
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag0Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag0Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag1Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag1Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].f_DistSinceErrorMonReset = Src.PartialBlockage.NormTarget.Az[u_AzZone].f_DistSinceNormTargetReset;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.as_ErrorLevelAz[u_AzZone]= Src.PartialBlockage.NormTarget.as_LocErrorLevelAz[u_AzZone];
  }
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.f_ErrorPresentTime = Src.PartialBlockage.NormTarget.f_HysteresisTime;
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.s_ErrorLevel = Src.PartialBlockage.NormTarget.s_GlobErrorLevel;
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Amp[0],&Src.MonProcessFrameData.SingleTargetSelectData_Amp,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Amp));
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Phase[0],&Src.MonProcessFrameData.SingleTargetSelectData_Phase,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Phase));
  if (sizeof(m_BufGen.s_Vrel_V100.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V100.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V100.AzHistogram));
  }
  m_BufGen.s_Vrel_V100.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V100.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V101 */
  memset(&(m_BufGen.s_Elevation_V101), 0, sizeof(m_BufGen.s_Elevation_V101));
  memset(&(m_BufGen.s_PathComp_V101), 0, sizeof(m_BufGen.s_PathComp_V101));
  memset(&(m_BufGen.s_PartialBlockage_V101), 0, sizeof(m_BufGen.s_PartialBlockage_V101));
  memset(&(m_BufGen.s_MonProcessFrameData_V101), 0, sizeof(m_BufGen.s_MonProcessFrameData_V101));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Elevation_V101 = Src.Elevation;
#endif
  memcpy(&(m_BufGen.s_PathComp_V101.CovDiags),&(m_BufGen.s_PathComp_V102.CovDiags),sizeof(m_BufGen.s_PathComp_V101.CovDiags));
  m_BufGen.s_PathComp_V101.f_DistSinceAmpReset = m_BufGen.s_PathComp_V102.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V101.f_DistSincePhaseReset = m_BufGen.s_PathComp_V102.f_DistSincePhaseReset;
  memcpy(&(m_BufGen.s_PathComp_V101.a_AdjBuffer),&(m_BufGen.s_PathComp_V102.a_AdjBuffer),sizeof(m_BufGen.s_PathComp_V101.a_AdjBuffer));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.s_PathComp_V101.au_HistRanges),&(m_BufGen.s_PathComp_V102.au_HistRanges),sizeof(m_BufGen.s_PathComp_V101.au_HistRanges));
#endif
  m_BufGen.s_PathComp_V101.u_AdjLevelAmp = m_BufGen.s_PathComp_V102.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V101.u_AdjLevelPhase = m_BufGen.s_PathComp_V102.u_AdjLevelPhase;

  memcpy(&(m_BufGen.s_PartialBlockage_V101), &(m_BufGen.s_PartialBlockage_V102), sizeof(m_BufGen.s_PartialBlockage_V101));
  memcpy(&(m_BufGen.s_MonProcessFrameData_V101), &(m_BufGen.s_MonProcessFrameData_V102), sizeof(m_BufGen.s_MonProcessFrameData_V101));

  /* V104 */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset((&m_BufGen.s_Monopulse_V104.a_Histogram), 0, sizeof(m_BufGen.s_Monopulse_V104.a_Histogram));
#endif
}

void CConvAlnSimInitMon::Convert_V104_to_Gen (const ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Src)
{   
  m_BufGen.sSigHeader             = Src.sSigHeader;
  m_BufGen.u_VersionNumber        = Src.u_VersionNumber;
  m_BufGen.e_Service              = Src.e_Service;
  m_BufGen.f_MaxProgress          = Src.f_MaxProgress;
  m_BufGen.b_AIAFctFullyActivated = Src.b_AIAFctFullyActivated;


  /* V103 */
  m_BufGen.s_Vrel_V103 = Src.s_Vrel;

  /* V102 */
  m_BufGen.s_PathComp_V102            = Src.PathComp;
  m_BufGen.s_Tunnel_V102              = Src.Tunnel;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memset(&(m_BufGen.s_Vrel_V102), 0, sizeof(m_BufGen.s_Vrel_V102));
#endif
  m_BufGen.s_PartialBlockage_V102     = Src.PartialBlockage;
  m_BufGen.s_MonProcessFrameData_V102 = Src.MonProcessFrameData;
  memset(&(m_BufGen.s_Vrel_V102), 0, sizeof(m_BufGen.s_Vrel_V102));
  if (sizeof(m_BufGen.s_Vrel_V102.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V102.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V102.AzHistogram));
  }
  m_BufGen.s_Vrel_V102.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V102.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V100 */
  m_BufGen.s_Az_V100 = Src.s_Az;
  memset(&(m_BufGen.s_PathComp_V100), 0, sizeof(m_BufGen.s_PathComp_V100));
  memset(&(m_BufGen.s_Tunnel_V100), 0, sizeof(m_BufGen.s_Tunnel_V100));
  memset(&(m_BufGen.s_Vrel_V100), 0, sizeof(m_BufGen.s_Vrel_V100));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist, Src.Elevation.au_ElevPhaseHist, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.au_ElevPhaseHist));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount, Src.Elevation.au_CovDiag1AltCount, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.u_CovDiag1AltCount));
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElev = Src.Elevation.f_OutputElev;
  m_BufGen.s_PathComp_V100.s_ElevScan.f_OutputElevStd = Src.Elevation.f_OutputElevStd;
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset, Src.Elevation.af_DistSinceElevReset, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_DistSinceElevReset));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer, Src.Elevation.af_MisAlnElevAdjBuffer, sizeof(m_BufGen.s_PathComp_V100.s_ElevScan.af_MisAlnElevAdjBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.u_AdjLevel = Src.Elevation.u_AdjLevel;
  m_BufGen.s_PathComp_V100.s_ElevScan.e_DrivingLvl = Src.Elevation.e_DrivingLvl;

  memcpy(&m_BufGen.s_PathComp_V100.s_ElevScan.a_SingleTargetSelectData_Elev[0],&Src.MonProcessFrameData.SingleTargetSelectData_Elev[0],sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Elev));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.au_HistRanges,Src.PathComp.au_HistRanges,sizeof(Src.PathComp.au_HistRanges));

  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevPhaseSumZone, Src.PartialBlockage.ADE.af_ElevPhaseSumZone,sizeof(Src.PartialBlockage.ADE.af_ElevPhaseSumZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.u_CovDiag1AltCountZone, Src.PartialBlockage.ADE.au_CovDiag1AltCountZone,sizeof(Src.PartialBlockage.ADE.au_CovDiag1AltCountZone));
  memcpy(m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.af_ElevRollingBuffer, Src.PartialBlockage.ADE.af_ElevRollingBuffer,sizeof(Src.PartialBlockage.ADE.af_ElevRollingBuffer));
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange = Src.PartialBlockage.ADE.f_LocADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange = Src.PartialBlockage.ADE.f_GlobADEObstacleRange;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.f_ElevErrorPresentTime = Src.PartialBlockage.ADE.f_ADEHysteresisTime;
  m_BufGen.s_PathComp_V100.s_ElevScan.a_SimInitElevErrorMon.s_ElevBufferFillCount = Src.PartialBlockage.ADE.s_ElevBufferFillCount;
#endif

  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.a_AzZone[0],&Src.PathComp.CovDiags, sizeof(Src.PathComp.CovDiags));
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSinceAmpReset = Src.PathComp.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V100.s_Scan.f_DistSincePhaseReset = Src.PathComp.f_DistSincePhaseReset;
  memcpy(m_BufGen.s_PathComp_V100.s_Scan.a_AdjBuffer,Src.PathComp.a_AdjBuffer, sizeof(Src.PathComp.a_AdjBuffer));
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelAmp    = Src.PathComp.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V100.s_Scan.u_AdjLevelPhase  = Src.PathComp.u_AdjLevelPhase;
  for (uint8 u_AzZone = 0u; u_AzZone < ALN_MON_PARTIAL_BLOCKAGE_u_NOF_AZ_ZONES; u_AzZone++)
  {
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].af_CovDiag0,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.af_CovDiag0));
    memcpy(m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].a_CovDiag1,Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1,sizeof(Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.a_CovDiag1));
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag0Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag0Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].u_CovDiag1Count = Src.PartialBlockage.NormTarget.Az[u_AzZone].CovDiags.u_CovDiag1Count;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.Az[u_AzZone].f_DistSinceErrorMonReset = Src.PartialBlockage.NormTarget.Az[u_AzZone].f_DistSinceNormTargetReset;
    m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.as_ErrorLevelAz[u_AzZone]= Src.PartialBlockage.NormTarget.as_LocErrorLevelAz[u_AzZone];
  }
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.f_ErrorPresentTime = Src.PartialBlockage.NormTarget.f_HysteresisTime;
  m_BufGen.s_PathComp_V100.s_Scan.ErrorMon.s_ErrorLevel = Src.PartialBlockage.NormTarget.s_GlobErrorLevel;
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Amp[0],&Src.MonProcessFrameData.SingleTargetSelectData_Amp,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Amp));
  memcpy(&m_BufGen.s_PathComp_V100.s_Scan.SingleTargetSelectData_Phase[0],&Src.MonProcessFrameData.SingleTargetSelectData_Phase,sizeof(Src.MonProcessFrameData.SingleTargetSelectData_Phase));
  if (sizeof(m_BufGen.s_Vrel_V100.AzHistogram) == sizeof(Src.s_Vrel.AzHistogram))
  {
    memcpy(m_BufGen.s_Vrel_V100.AzHistogram, Src.s_Vrel.AzHistogram, sizeof(m_BufGen.s_Vrel_V100.AzHistogram));
  }
  m_BufGen.s_Vrel_V100.f_LastVegoEstimate   = Src.s_Vrel.f_LastVegoEstimate;
  m_BufGen.s_Vrel_V100.f_YawAngle           = Src.s_Vrel.f_YawAngle;

  /* V101 */
  memset(&(m_BufGen.s_Elevation_V101), 0, sizeof(m_BufGen.s_Elevation_V101));
  memset(&(m_BufGen.s_PathComp_V101), 0, sizeof(m_BufGen.s_PathComp_V101));
  memset(&(m_BufGen.s_PartialBlockage_V101), 0, sizeof(m_BufGen.s_PartialBlockage_V101));
  memset(&(m_BufGen.s_MonProcessFrameData_V101), 0, sizeof(m_BufGen.s_MonProcessFrameData_V101));

#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Elevation_V101 = Src.Elevation;
#endif
  memcpy(&(m_BufGen.s_PathComp_V101.CovDiags),&(m_BufGen.s_PathComp_V102.CovDiags),sizeof(m_BufGen.s_PathComp_V101.CovDiags));
  m_BufGen.s_PathComp_V101.f_DistSinceAmpReset = m_BufGen.s_PathComp_V102.f_DistSinceAmpReset;
  m_BufGen.s_PathComp_V101.f_DistSincePhaseReset = m_BufGen.s_PathComp_V102.f_DistSincePhaseReset;
  memcpy(&(m_BufGen.s_PathComp_V101.a_AdjBuffer),&(m_BufGen.s_PathComp_V102.a_AdjBuffer),sizeof(m_BufGen.s_PathComp_V101.a_AdjBuffer));
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  memcpy(&(m_BufGen.s_PathComp_V101.au_HistRanges),&(m_BufGen.s_PathComp_V102.au_HistRanges),sizeof(m_BufGen.s_PathComp_V101.au_HistRanges));
#endif
  m_BufGen.s_PathComp_V101.u_AdjLevelAmp = m_BufGen.s_PathComp_V102.u_AdjLevelAmp;
  m_BufGen.s_PathComp_V101.u_AdjLevelPhase = m_BufGen.s_PathComp_V102.u_AdjLevelPhase;

  memcpy(&(m_BufGen.s_PartialBlockage_V101), &(m_BufGen.s_PartialBlockage_V102), sizeof(m_BufGen.s_PartialBlockage_V101));
  memcpy(&(m_BufGen.s_MonProcessFrameData_V101), &(m_BufGen.s_MonProcessFrameData_V102), sizeof(m_BufGen.s_MonProcessFrameData_V101));

  /* V104 */
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  m_BufGen.s_Monopulse_V104 = Src.Monopulse;
#endif
}

void CConvAlnSimInitMon::Convert_Gen_to_V100 (ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Dest)
{
  Dest.sSigHeader         = m_BufGen.sSigHeader;
  Dest.u_VersionNumber    = 100u;
  Dest.s_Az               = m_BufGen.s_Az_V100;
  Dest.s_PathComp         = m_BufGen.s_PathComp_V100;
  Dest.s_Tunnel           = m_BufGen.s_Tunnel_V100;
  Dest.s_Vrel             = m_BufGen.s_Vrel_V100;
  Dest.e_Service          = m_BufGen.e_Service;
  Dest.f_MaxProgress      = m_BufGen.f_MaxProgress;
  Dest.b_AIAFctFullyActivated = m_BufGen.b_AIAFctFullyActivated;

  /*  Assign Default Values to Adjustment buffers. Else, FPE in Simulation */
  {
    uint8 ubuf,ui;
    
    for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
    {
      if(Dest.s_PathComp.s_Scan.a_AdjBuffer[ubuf][0u].f_Amplitude==0.f)
      {
        for (ui=0u;ui<ALN_SimInitMon_NumOfChannels;ui++)
        {
          Dest.s_PathComp.s_Scan.a_AdjBuffer[ubuf][ui].f_Amplitude=1.f;
          Dest.s_PathComp.s_Scan.a_AdjBuffer[ubuf][ui].f_Phase=0.f;
        }
      }
    }
    if(Dest.s_PathComp.s_ElevScan.af_MisAlnElevAdjBuffer[0u]==0.f)
    {
      for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
      {
        Dest.s_PathComp.s_ElevScan.af_MisAlnElevAdjBuffer[ubuf]=ALN_F_INVALID;
      }
    }
    if(Dest.s_PathComp.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange==0.f)
    {
      Dest.s_PathComp.s_ElevScan.a_SimInitElevErrorMon.f_ADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
      Dest.s_PathComp.s_ElevScan.a_SimInitElevErrorMon.f_GlobADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
    }
  }
}

void CConvAlnSimInitMon::Convert_Gen_to_V101 (ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Dest)
{
  Dest.sSigHeader         = m_BufGen.sSigHeader;
  Dest.u_VersionNumber    = 101u;
  Dest.s_Az               = m_BufGen.s_Az_V100;
  Dest.Elevation          = m_BufGen.s_Elevation_V101;
  Dest.PathComp           = m_BufGen.s_PathComp_V101;
  Dest.Tunnel             = m_BufGen.s_Tunnel_V100;
  Dest.PartialBlockage    = m_BufGen.s_PartialBlockage_V101;
  Dest.MonProcessFrameData  = m_BufGen.s_MonProcessFrameData_V101;
  Dest.s_Vrel             = m_BufGen.s_Vrel_V100;
  Dest.e_Service          = m_BufGen.e_Service;
  Dest.f_MaxProgress      = m_BufGen.f_MaxProgress;
  Dest.b_AIAFctFullyActivated = m_BufGen.b_AIAFctFullyActivated;
  /*  Assign Default Values to Adjustment buffers. Else, FPE in Simulation */
  {
    uint8 ubuf,ui;
    
    for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
    {
      if(Dest.PathComp.a_AdjBuffer[ubuf][0u].f_Amplitude==0.f)
      {
        for (ui=0u;ui<ALN_SimInitMon_NumOfChannels;ui++)
        {
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Amplitude=1.f;
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Phase=0.f;
        }
      }
    }
    if(Dest.Elevation.af_MisAlnElevAdjBuffer[0u]==0.f)
    {
      for(ubuf=0u;ubuf<ALN_MON_ELEV_u_RESULT_BUFFER_SIZE;ubuf++)
      {
        Dest.Elevation.af_MisAlnElevAdjBuffer[ubuf]=ALN_F_INVALID;
      }
    }
    if(Dest.PartialBlockage.ADE.f_GlobADEObstacleRange==0.f)
    {
      Dest.PartialBlockage.ADE.f_LocADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
      Dest.PartialBlockage.ADE.f_GlobADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
    }
  }
}

void CConvAlnSimInitMon::Convert_Gen_to_V102 (ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Dest)
{
  Dest.sSigHeader         = m_BufGen.sSigHeader;
  Dest.u_VersionNumber    = 102u;
  Dest.s_Az               = m_BufGen.s_Az_V100;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Elevation          = m_BufGen.s_Elevation_V101;
#endif
  Dest.PathComp           = m_BufGen.s_PathComp_V102;
  Dest.Tunnel             = m_BufGen.s_Tunnel_V102;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Monopulse          = m_BufGen.s_Monopulse_V102;
#endif
  Dest.PartialBlockage    = m_BufGen.s_PartialBlockage_V102;
  Dest.MonProcessFrameData= m_BufGen.s_MonProcessFrameData_V102;
  Dest.s_Vrel             = m_BufGen.s_Vrel_V102;
  Dest.e_Service          = m_BufGen.e_Service;
  Dest.f_MaxProgress      = m_BufGen.f_MaxProgress;
  Dest.b_AIAFctFullyActivated = m_BufGen.b_AIAFctFullyActivated;
  /*  Assign Default Values to Adjustment buffers. Else, FPE in Simulation */
  {
    uint8 ubuf,ui;

    for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
    {
      if(Dest.PathComp.a_AdjBuffer[ubuf][0u].f_Amplitude==0.f)
      {
        for (ui=0u;ui<ALN_SimInitMon_NumOfChannels;ui++)
        {
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Amplitude=1.f;
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Phase=0.f;
        }
      }
    }
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    if(Dest.Elevation.af_MisAlnElevAdjBuffer[0u]==0.f)
    {
      for(ubuf=0u;ubuf<ALN_MON_ELEV_u_RESULT_BUFFER_SIZE;ubuf++)
      {
        Dest.Elevation.af_MisAlnElevAdjBuffer[ubuf]=ALN_F_INVALID;
      }
    }
    if(Dest.PartialBlockage.ADE.f_GlobADEObstacleRange==0.f)
    {
      Dest.PartialBlockage.ADE.f_LocADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
      Dest.PartialBlockage.ADE.f_GlobADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
    }
#endif
  }
}

void CConvAlnSimInitMon::Convert_Gen_to_V103 (ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Dest)
{
  Dest.sSigHeader         = m_BufGen.sSigHeader;
  Dest.u_VersionNumber    = 103u;
  Dest.s_Az               = m_BufGen.s_Az_V100;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Elevation          = m_BufGen.s_Elevation_V101;
#endif
  Dest.PathComp           = m_BufGen.s_PathComp_V102;
  Dest.Tunnel             = m_BufGen.s_Tunnel_V102;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Monopulse          = m_BufGen.s_Monopulse_V102;
#endif
  Dest.PartialBlockage    = m_BufGen.s_PartialBlockage_V102;
  Dest.MonProcessFrameData  = m_BufGen.s_MonProcessFrameData_V102;
  Dest.s_Vrel             = m_BufGen.s_Vrel_V103;
  Dest.e_Service          = m_BufGen.e_Service;
  Dest.f_MaxProgress      = m_BufGen.f_MaxProgress;
  Dest.b_AIAFctFullyActivated = m_BufGen.b_AIAFctFullyActivated;
  /*  Assign Default Values to Adjustment buffers. Else, FPE in Simulation */
  {
    uint8 ubuf,ui;

    for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
    {
      if(Dest.PathComp.a_AdjBuffer[ubuf][0u].f_Amplitude==0.f)
      {
        for (ui=0u;ui<ALN_SimInitMon_NumOfChannels;ui++)
        {
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Amplitude=1.f;
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Phase=0.f;
        }
      }
    }
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    if(Dest.Elevation.af_MisAlnElevAdjBuffer[0u]==0.f)
    {
      for(ubuf=0u;ubuf<ALN_MON_ELEV_u_RESULT_BUFFER_SIZE;ubuf++)
      {
        Dest.Elevation.af_MisAlnElevAdjBuffer[ubuf]=ALN_F_INVALID;
      }
    }
    if(Dest.PartialBlockage.ADE.f_GlobADEObstacleRange==0.f)
    {
      Dest.PartialBlockage.ADE.f_LocADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
      Dest.PartialBlockage.ADE.f_GlobADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
    }
#endif
  }
}

void CConvAlnSimInitMon::Convert_Gen_to_V104 (ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Dest)
{
  Dest.sSigHeader         = m_BufGen.sSigHeader;
  Dest.u_VersionNumber    = 104u;
  Dest.s_Az               = m_BufGen.s_Az_V100;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Elevation          = m_BufGen.s_Elevation_V101;
#endif
  Dest.PathComp           = m_BufGen.s_PathComp_V102;
  Dest.Tunnel             = m_BufGen.s_Tunnel_V102;
#if (CFG_ARS510_SWITCH == SWITCH_ON)
  Dest.Monopulse          = m_BufGen.s_Monopulse_V104;
#endif
  Dest.PartialBlockage    = m_BufGen.s_PartialBlockage_V102;
  Dest.MonProcessFrameData  = m_BufGen.s_MonProcessFrameData_V102;
  Dest.s_Vrel             = m_BufGen.s_Vrel_V103;
  Dest.e_Service          = m_BufGen.e_Service;
  Dest.f_MaxProgress      = m_BufGen.f_MaxProgress;
  Dest.b_AIAFctFullyActivated = m_BufGen.b_AIAFctFullyActivated;
  /*  Assign Default Values to Adjustment buffers. Else, FPE in Simulation */
  {
    uint8 ubuf,ui;

    for(ubuf=0u;ubuf<ALN_MON_PATH_COMP_u_RESULT_BUFFER_SIZE;ubuf++)
    {
      if(Dest.PathComp.a_AdjBuffer[ubuf][0u].f_Amplitude==0.f)
      {
        for (ui=0u;ui<ALN_SimInitMon_NumOfChannels;ui++)
        {
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Amplitude=1.f;
          Dest.PathComp.a_AdjBuffer[ubuf][ui].f_Phase=0.f;
        }
      }
    }
#if (CFG_ARS510_SWITCH == SWITCH_ON)
    if(Dest.Elevation.af_MisAlnElevAdjBuffer[0u]==0.f)
    {
      for(ubuf=0u;ubuf<ALN_MON_ELEV_u_RESULT_BUFFER_SIZE;ubuf++)
      {
        Dest.Elevation.af_MisAlnElevAdjBuffer[ubuf]=ALN_F_INVALID;
      }
    }
    if(Dest.PartialBlockage.ADE.f_GlobADEObstacleRange==0.f)
    {
      Dest.PartialBlockage.ADE.f_LocADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
      Dest.PartialBlockage.ADE.f_GlobADEObstacleRange = ALN_MON_COMMON_f_ObstacleRangeMax;
    }
#endif
  }
}

long CConvAlnSimInitMon::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  typedef struct
  {
    SignalHeader_t sSigHeader;
    uint32 u_VersionNumber;
  } ALN_Input_SimInitMon_Start_t;

  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  bool bGenBufferFilled = false;
  const ALN_Input_SimInitMon_Start_t InputStart = (*reinterpret_cast<ALN_Input_SimInitMon_Start_t*>(pPPortData));
  const uint32 uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))? InputStart.u_VersionNumber : (0);
  const CVersionInfoImpl uDataReqVersionInfo(0, 0, uDataVer);
  // If direct one:one copy possible then do that
  if ((ulPPortSize == ulRPortSize)
    && ((pProvidePortVersionInfo == NULL) /*|| (pProvidePortVersionInfo->Equals(&VERSION11)) */
    || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    /* do not explicitly check data version -> if size fits, just use it */
    && (requestPortVersionInfo.Equals(&uDataReqVersionInfo))
    )
  {
    lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION104)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 104u) || (uDataVer == 1u)))
  {
    // Source Port V104
    InitVersion(m_BufGen, 104u);
    const ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Src = *reinterpret_cast<::ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit*>(pPPortData);
    Convert_V104_to_Gen(Src);
    bGenBufferFilled = true;
  }
  // First decide from which version we are converting and fill the generic buffer accordingly
  else if ((ulPPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION103)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 103u) || (uDataVer == 1u)))
  {
    // Source Port V103
    InitVersion(m_BufGen, 103u);
    const ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Src = *reinterpret_cast<::ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit*>(pPPortData);
    Convert_V103_to_Gen(Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION102)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 102u) || (uDataVer == 1u)))
  {
    // Source Port V102
    InitVersion(m_BufGen, 102u);
    const ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Src = *reinterpret_cast<::ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit*>(pPPortData);
    Convert_V102_to_Gen(Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION101)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 101u) || (uDataVer == 1u)))
  {
    // Source Port V101
    InitVersion(m_BufGen, 101u);
    const ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Src = *reinterpret_cast<::ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit*>(pPPortData);
    Convert_V101_to_Gen(Src);
    bGenBufferFilled = true;
  }
  else if ((ulPPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit))
    && ((pProvidePortVersionInfo == NULL) || (pProvidePortVersionInfo->Equals(&VERSION100)) || (pProvidePortVersionInfo->Equals(&BASE_VERSION)))
    && ((uDataVer == 100u) || (uDataVer == 1u)))
  {
    // Source Port V100
    InitVersion(m_BufGen, 100u);
    const ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Src = *reinterpret_cast<::ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit*>(pPPortData);
    Convert_V100_to_Gen(Src);
    bGenBufferFilled = true;
  }

  if (bGenBufferFilled == true)
  {
    // Second decide to which version we are converting
    // and take the generic buffer to fill the destination buffer
    if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit)) && ((requestPortVersionInfo.Equals(&VERSION104)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
  {
    // Destination port of V104
    InitVersion(m_BufV104, 104u);
    ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit & Dest = /*reinterpret_cast<ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit &>*/(m_BufV104);
    Convert_Gen_to_V104(Dest);
    *pOutData = &Dest;
    ulOutSize = sizeof(Dest);
    lRet = SIM_ERR_OK;
  }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit)) && ((requestPortVersionInfo.Equals(&VERSION103)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V103
      InitVersion(m_BufV103, 103u);
      ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit & Dest = /*reinterpret_cast<ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit &>*/(m_BufV103);
      Convert_Gen_to_V103(Dest);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit)) && ((requestPortVersionInfo.Equals(&VERSION103)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V102
      InitVersion(m_BufV102, 102u);
      ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit & Dest = /*reinterpret_cast<ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit &>*/(m_BufV102);
      Convert_Gen_to_V102(Dest);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit)) && ((requestPortVersionInfo.Equals(&VERSION101)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V101
      InitVersion(m_BufV101, 101u);
      ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit & Dest = /*reinterpret_cast<ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit &>*/(m_BufV101);
      Convert_Gen_to_V101(Dest);
      *pOutData = &Dest;
      ulOutSize = sizeof(Dest);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit)) && ((requestPortVersionInfo.Equals(&VERSION100)) || (requestPortVersionInfo.Equals(&BASE_VERSION))))
    {
      // Destination port of V100
      InitVersion(m_BufV100, 100u);
      ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit & Dest = /*reinterpret_cast<ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit &>*/(m_BufV100);
      Convert_Gen_to_V100(Dest);
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
long CConvAlnSimInitMon::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V100::ALN_MON_t_SimInit)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION100))))
    {
      InitVersion(m_BufV100, 100u);
      *pDefaultData = &m_BufV100;
      ulDefaultSize = sizeof(m_BufV100);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V101::ALN_MON_t_SimInit)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION101))))
    {
      InitVersion(m_BufV101, 101u);
      *pDefaultData = &m_BufV101;
      ulDefaultSize = sizeof(m_BufV101);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V102::ALN_MON_t_SimInit)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION102))))
    {
      InitVersion(m_BufV102, 102u);
      *pDefaultData = &m_BufV102;
      ulDefaultSize = sizeof(m_BufV102);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V103::ALN_MON_t_SimInit)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION103))))
    {
      InitVersion(m_BufV103, 103u);
      *pDefaultData = &m_BufV103;
      ulDefaultSize = sizeof(m_BufV103);
      lRet = SIM_ERR_OK;
    }
  else if ((ulRPortSize == sizeof(ALN_SimInitMon_t_Radar5xx_V104::ALN_MON_t_SimInit)) && ((BASE_VERSION.Equals(&requestPortVersionInfo)) || (requestPortVersionInfo.Equals(&VERSION104))))
  {
    InitVersion(m_BufV104, 104u);
    *pDefaultData = &m_BufV104;
    ulDefaultSize = sizeof(m_BufV104);
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
bool CConvAlnSimInitMon::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize))
  {
    bResult = true;
  }
  else
  {
    bResult = (PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize));
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvAlnSimInitMon::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Always allow same type/size ports to be bound together
  if ((eRPortType == ePPortType) && (ulRPortSize == ulPPortSize) && (providePortVersionInfo.Equals(&requestPortVersionInfo)))
  {
    bResult = true;
  }
  else
  {
    // Ports are different: conversion necessary and possible if provide & request port known
    bResult = PortSupported(eRPortType, ulRPortSize, &requestPortVersionInfo) && PortSupported(ePPortType, ulPPortSize, &providePortVersionInfo);
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreateAlnSimInitMonConvClass(void)
{
  return new CConvAlnSimInitMon();
}
