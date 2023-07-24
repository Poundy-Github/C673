/*! \file **********************************************************************

COMPANY:              Continental

PROJECT:              Simulation

COMPONENT:            sim_adapter_fct

MODULNAME:            sim_conv_rhc_adj_hw_config

DESCRIPTION:          Converter class for RHC_t_AdjHwConfig

AUTHOR:               Ovidiu Raicu

CREATION DATE:        23.03.2010

VERSION:              $Revision: 1.1 $

---*/ /*---
CHANGES:              $Log: sim_conv_rhc_adj_hw_config.cpp  $
CHANGES:              Revision 1.1 2021/12/13 17:21:34CET Wang, David (Wangd3) 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/rhc/project.pj
CHANGES:              Revision 1.1 2017/08/10 13:15:28CEST uid34177 
CHANGES:              Initial revision
CHANGES:              Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/rhc/project.pj
CHANGES:              Revision 1.9 2014/11/28 11:45:36CET Berndt, Thomas01 (berndtt1) 
CHANGES:              * Bugfix GetDeps: ">=" ---> "=="
CHANGES:              - Added comments -  berndtt1 [Nov 28, 2014 11:48:28 AM CET]
CHANGES:              Change Package : 221167:41 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:              Revision 1.8 2014/11/12 12:58:58CET Berndt, Thomas01 (berndtt1) 
CHANGES:              for CFG_ARS400_EN_SWITCH: typedef t_Complex16 as_PathCompensation_array_t[6];
CHANGES:              --- Added comments ---  berndtt1 [Nov 12, 2014 1:25:10 PM CET]
CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:              Revision 1.7 2014/11/11 15:30:12CET Manea, Gabriela (ManeaG) 
CHANGES:              Update: adapted also for SRR projects
CHANGES:              --- Added comments ---  ManeaG [Nov 11, 2014 3:30:12 PM CET]
CHANGES:              Change Package : 278885:1 http://mks-psad:7002/im/viewissue?selection=278885
CHANGES:              Revision 1.6 2014/10/24 11:26:37CEST Berndt, Thomas01 (berndtt1) 
CHANGES:              Update of V5 (AlgoTypesAUTOSAR4.ecuextract V1.63)
CHANGES:              --- Added comments ---  berndtt1 [Oct 24, 2014 11:29:21 AM CEST]
CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:              Revision 1.5 2014/10/06 16:38:58CEST Berndt, Thomas01 (berndtt1) 
CHANGES:              Added V5
CHANGES:              --- Added comments ---  berndtt1 [Oct 6, 2014 4:40:21 PM CEST]
CHANGES:              Change Package : 221167:34 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:              Revision 1.4 2014/08/13 16:02:06CEST Berndt, Thomas01 (berndtt1) 
CHANGES:              Simulation adapter changes - AL_ARS400EN_01.14.00
CHANGES:              --- Added comments ---  berndtt1 [Aug 13, 2014 4:33:43 PM CEST]
CHANGES:              Change Package : 221167:24 http://mks-psad:7002/im/viewissue?selection=221167
CHANGES:              Revision 1.3 2014/07/10 16:37:42CEST Berndt, Thomas01 (berndtt1) 
CHANGES:              + Dependencies
CHANGES:              + Workaround for corrupted RCS
CHANGES:              --- Added comments ---  berndtt1 [Jul 10, 2014 4:39:46 PM CEST]
CHANGES:              Change Package : 246752:1 http://mks-psad:7002/im/viewissue?selection=246752
CHANGES:              Revision 1.2 2013/11/14 12:51:00CET Stolle, Ulf Eike (uidv1902) 
CHANGES:              - Added Adapter from V3 to V4
CHANGES:              --- Added comments ---  uidv1902 [Nov 14, 2013 12:51:01 PM CET]
CHANGES:              Change Package : 191346:6 http://mks-psad:7002/im/viewissue?selection=191346
CHANGES:              Revision 1.1 2013/08/02 19:18:25CEST Ungvary, Gergely (ungvaryg) 
CHANGES:              Initial revision
CHANGES:              Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/rhc/project.pj
**************************************************************************** */
/* includes ---------------------------------------------------------------- */
#include "stdafx.h"
#include "sim_adapter_cfg.h"
#include "sim_conv_rhc_adj_hw_config.h"
#include "sim_versioninfo_impl.h"
#include "interface_base.h"

typedef enum eAlgoSignalState_t {
  AL_SIG_STATE_INIT=0,
  AL_SIG_STATE_OK=1,
  AL_SIG_STATE_INVALID=2,
} eAlgoSignalState_t;

typedef struct t_Complex16
{
  sint16 s_Real;
  sint16 s_Imag;
} t_Complex16; /* signed 16 bit integer complex */

//
// Declaration of RSP2 cluster list(s) taken from rte_type.h revision 1.27.1.5.2.5
// (/nfs/projekte1/PROJECTS/ARS400/05_Software/B0_Sample/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 B0)
//
namespace RHCAdjHwCfgV2_B0 {

  static const uint32 RHC_ADJ_HW_CONFIG_VERSION = 2u;
  static const CVersionInfoImpl Version(0, 0, 2);

  typedef struct RHC_t_RampPar
  {
    float32 f_RangeGateLength;
    float32 f_MidFrequ;
  } RHC_t_RampPar;

  typedef struct RHC_t_AdjHwConfig
  {
    uint32 i_VersionNumber;
    RHC_t_RampPar RampPar;
    float32 f_TargetNormS;
    float32 f_TargetNormSN;
    float32 f_RampPeriod;
    float32 f_GainReduction;
    uint32 u_TimeStamp;
    uint8 u_GainReduction;
    uint8 u_WindowBeamIdx;
    boolean DataValid;
    boolean RfChanged;
    boolean PowerReduction;
    boolean AdcOverflow;
    uint8 u_RangeWindowIdx;
    uint8 u_DopplerWindowIdx;
  } RHC_t_AdjHwConfig;

};

//
// Declaration of RHC Adj HW Cfg taken from rte_type.h revision 1.14.1.4
// (/nfs/projekte1/SW/SW_ARS4xx/SW_ARS400_PR/M11_Appl/04_Engineering/01_Source_Code/common/rte/Rte_Type.h)
// (ARS400 B1)
//
namespace RHCAdjHwCfgV2 {

  static const uint32 RHC_ADJ_HW_CONFIG_VERSION = 2u;
  static const CVersionInfoImpl Version(0, 0, 2);

  typedef unsigned short AlgoCycleCounter_t     /* Algo cycle counter @min:0 @max:65535 */ /* [Satisfies_rte sws 1188] */;
  typedef unsigned long AlgoDataTimeStamp_t     /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */ /* [Satisfies_rte sws 1188] */;
  typedef uint8 AlgoErrorState_t;               /* Algo error state enumeration @min: 0 @max:2 @values: enum { AL_ERR_STATE_UNKNOWN=0,AL_ERR_STATE_ACTIVE=1,AL_ERR_STATE_INACTIVE=2,} */
  typedef uint32 AlgoInterfaceVersionNumber_t;  /* Algo interface version nummbers @min:0 @max:4294967295 */
  typedef unsigned char AlgoSignalState_t       /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */ /* [Satisfies_rte sws 1188] */;

  typedef struct SignalHeader_t
  {
    AlgoDataTimeStamp_t uiTimeStamp;
    AlgoCycleCounter_t uiMeasurementCounter;
    AlgoCycleCounter_t uiCycleCounter;
    AlgoSignalState_t eSigStatus;
  } SignalHeader_t; /* Common header for all structured data types */

  typedef struct RHC_t_RampPar                                       /* [Satisfies_rte sws 1191] */
  {
    float f_RangeGateLength;
    float f_MidFrequ;
  } RHC_t_RampPar;
#if SRR_SWITCH == SWITCH_OFF
#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef t_Complex16 as_PathCompensation_array_t[6];/* [Satisfies_rte sws 1189] */
#else
  typedef t_Complex16 as_PathCompensation_array_t[12];/* [Satisfies_rte sws 1189] */
#endif
#else
  typedef t_Complex16 as_PathCompensation_array_t[8];
#endif
  typedef unsigned short aui16_AzimuthWindow_array_t[16];

  typedef struct RHC_t_AdjHwConfig
  {
    uint32 i_VersionNumber;
    SignalHeader_t sSigHeader;
    RHC_t_RampPar RampPar;
    float32 f_TargetNormS;
    float32 f_TargetNormSN;
    float32 f_RampPeriod;
    float32 f_GainReduction;
    uint32 u_TimeStamp;
    uint8 u_GainReduction;
    uint8 u_WindowBeamIdx;
    boolean DataValid;
    boolean RfChanged;
    boolean PowerReduction;
    boolean AdcOverflow;
    uint8 u_RangeWindowIdx;
    uint8 u_DopplerWindowIdx;
    as_PathCompensation_array_t as_PathCompensation;
    aui16_AzimuthWindow_array_t aui16_AzimuthWindow;
  } RHC_t_AdjHwConfig;

};

namespace RHCAdjHwCfgV3 {

  static const uint32 RHC_ADJ_HW_CONFIG_VERSION = 3u;
  static const CVersionInfoImpl Version(0, 0, 3);

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    signed short s_Real;
    signed short s_Imag;
  } t_Complex16;			/* signed 16 bit integer complex */

#if SRR_SWITCH == SWITCH_OFF
#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef t_Complex16 as_PathCompensation_array_t[6];/* [Satisfies_rte sws 1189] */
#else
  typedef t_Complex16 as_PathCompensation_array_t[12];/* [Satisfies_rte sws 1189] */
#endif
#else
  typedef t_Complex16               	as_PathCompensation_array_t[8];			/* [Satisfies_rte sws 1189] */
#endif

  typedef struct 			/* [Satisfies_rte sws 1191] */
  {
    unsigned long i_VersionNumber;
    RHCAdjHwCfgV2::SignalHeader_t sSigHeader;
    RHCAdjHwCfgV2::RHC_t_RampPar RampPar;
    float f_TargetNormS;
    float f_TargetNormSN;
    float f_MonopulseBeamOffset;
    float f_RampPeriod;
    float f_GainReduction;
    unsigned long u_TimeStamp;
    unsigned char u_GainReduction;
    unsigned char u_WindowBeamIdx;
    boolean DataValid;
    boolean RfChanged;
    boolean PowerReduction;
    boolean AdcOverflow;
    unsigned char u_RangeWindowIdx;
    unsigned char u_DopplerWindowIdx;
    as_PathCompensation_array_t as_PathCompensation;
    RHCAdjHwCfgV2::aui16_AzimuthWindow_array_t aui16_AzimuthWindow;
  } RHC_t_AdjHwConfig;	
}

namespace RHCAdjHwCfgV4 {

  static const uint32 RHC_ADJ_HW_CONFIG_VERSION = 4u;
  static const CVersionInfoImpl Version(0, 0, 4);

#if SRR_SWITCH == SWITCH_OFF
#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[6];/* [Satisfies_rte sws 1189] */
#else
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[12];/* [Satisfies_rte sws 1189] */
#endif
#else
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[8];/* [Satisfies_rte sws 1189] */
#endif

  typedef float f_MonopulseBeamError_array_t[181];                   /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long i_VersionNumber;
    RHCAdjHwCfgV2::SignalHeader_t sSigHeader;
    RHCAdjHwCfgV2::RHC_t_RampPar RampPar;
    float f_TargetNormS;
    float f_TargetNormSN;
    float f_MonopulseBeamOffset;
    f_MonopulseBeamError_array_t f_MonopulseBeamError;
    float f_RampPeriod;
    float f_GainReduction;
    unsigned long u_TimeStamp;
    unsigned char u_GainReduction;
    unsigned char u_WindowBeamIdx;
    boolean DataValid;
    unsigned char u_CurrentRfIndex;
    boolean PowerReduction;
    boolean AdcOverflow;
    unsigned char u_RangeWindowIdx;
    unsigned char u_DopplerWindowIdx;
    as_PathCompensation_array_t as_PathCompensation;
    RHCAdjHwCfgV2::aui16_AzimuthWindow_array_t aui16_AzimuthWindow;
  } RHC_t_AdjHwConfig;
}

namespace RHCAdjHwCfgV5 {

  static const uint32 RHC_ADJ_HW_CONFIG_VERSION = 5u;
  static const CVersionInfoImpl Version(0, 0, 5);

#if SRR_SWITCH == SWITCH_OFF
#if (CFG_ARS400_EN_SWITCH == SWITCH_ON)
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[6];/* [Satisfies_rte sws 1189] */
#else
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[12];/* [Satisfies_rte sws 1189] */
#endif
#else
  typedef RHCAdjHwCfgV3::t_Complex16 as_PathCompensation_array_t[8];/* [Satisfies_rte sws 1189] */
#endif

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned long i_VersionNumber;
    RHCAdjHwCfgV2::SignalHeader_t sSigHeader;
    RHCAdjHwCfgV2::RHC_t_RampPar RampPar;
    float f_TargetNormS;
    float f_TargetNormSN;
    float f_MonopulseBeamOffset;
    float f_RampPeriod;
    float f_GainReduction;
    unsigned char u_GainReduction;
    unsigned char u_WindowBeamIdx;
    unsigned char DataValid;
    unsigned char u_CurrentRfIndex;
    unsigned char u_RangeWindowIdx;
    unsigned char u_DopplerWindowIdx;
    unsigned char u_MsbCorrIndex;
    as_PathCompensation_array_t as_PathCompensation;
    RHCAdjHwCfgV2::aui16_AzimuthWindow_array_t aui16_AzimuthWindow;
  } RHC_t_AdjHwConfig;
}

//
// Helper functions
//

//
// Main RHC Adj HW config conversion class
//

class CConvRhcAdjHwCfg : public CSimConverterBase
{
  size_t  m_uAllocSize;
  void *  m_pAllocBuffer;

  // the list of dependency names used inside by the converter
  static const TCHAR* DEP_NAMES[];

  // here we define the index of each dependency for quick acces
  // the order here should match with the order from DEP_NAMES array
  enum eDepIdx
  {
    RECVERSION = 0,
    NSORFS,
    // add new dependencies here
    DEP_COUNT
  };

  static void Init(RHCAdjHwCfgV5::RHC_t_AdjHwConfig & Dest)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV5::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = 1.8f;
    Dest.RampPar.f_MidFrequ               = 76.6e9f;

    // Other fields
    Dest.f_TargetNormS      = 0;
    Dest.f_TargetNormSN     = 0;
    // Monopuls
    Dest.f_MonopulseBeamOffset = 0;
    // Other fields
    Dest.f_RampPeriod       = 0;
    Dest.f_GainReduction    = 0;
    Dest.u_GainReduction    = 0;
    Dest.u_WindowBeamIdx    = 0;
    Dest.DataValid          = 0;
    Dest.u_CurrentRfIndex   = 0;
    Dest.u_RangeWindowIdx   = 0;
    Dest.u_DopplerWindowIdx = 0;
    Dest.u_MsbCorrIndex     = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = 0;
      Dest.as_PathCompensation[uPathIdx].s_Imag = 0;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = 0;
    }
  };
  static void Init(RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Dest)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV4::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = 1.8f;
    Dest.RampPar.f_MidFrequ               = 76.6e9f;

    // Other fields
    Dest.f_TargetNormS      = 0;
    Dest.f_TargetNormSN     = 0;
    // Monopuls
    Dest.f_MonopulseBeamOffset = 0;
    for (int ii = 0; ii < (sizeof(Dest.f_MonopulseBeamError)/sizeof(Dest.f_MonopulseBeamError[0])); ii++)
    {
      Dest.f_MonopulseBeamError[ii] = 0;
    }
    // Other fields
    Dest.f_RampPeriod       = 0;
    Dest.f_GainReduction    = 0;
    Dest.u_TimeStamp        = 0;
    Dest.u_GainReduction    = 0;
    Dest.u_WindowBeamIdx    = 0;
    Dest.DataValid          = 0;
    Dest.u_CurrentRfIndex   = 0;
    Dest.PowerReduction     = 0;
    Dest.AdcOverflow        = 0;
    Dest.u_RangeWindowIdx   = 0;
    Dest.u_DopplerWindowIdx = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = 0;
      Dest.as_PathCompensation[uPathIdx].s_Imag = 0;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = 0;
    }

  };
  static void Init(RHCAdjHwCfgV3::RHC_t_AdjHwConfig & Dest)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV3::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = 1.8f;
    Dest.RampPar.f_MidFrequ               = 76.6e9f;

    // Other fields
    Dest.f_TargetNormS      = 0;
    Dest.f_TargetNormSN     = 0;
    // Monopuls
    Dest.f_MonopulseBeamOffset = 0;
    // Other fields
    Dest.f_RampPeriod       = 0;
    Dest.f_GainReduction    = 0;
    Dest.u_TimeStamp        = 0;
    Dest.u_GainReduction    = 0;
    Dest.u_WindowBeamIdx    = 0;
    Dest.DataValid          = 0;
    Dest.RfChanged          = 0;
    Dest.PowerReduction     = 0;
    Dest.AdcOverflow        = 0;
    Dest.u_RangeWindowIdx   = 0;
    Dest.u_DopplerWindowIdx = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = 0;
      Dest.as_PathCompensation[uPathIdx].s_Imag = 0;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = 0;
    }

  };
  static void Init(RHCAdjHwCfgV2::RHC_t_AdjHwConfig & Dest)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV2::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = 0;
    Dest.sSigHeader.uiMeasurementCounter  = 0;
    Dest.sSigHeader.uiCycleCounter        = 0;
    Dest.sSigHeader.eSigStatus            = AL_SIG_STATE_INIT;
    // Ramp parameters
    Dest.RampPar.f_RangeGateLength        = 1.8f;
    Dest.RampPar.f_MidFrequ               = 76.6e9f;
    // Other fields
    Dest.f_TargetNormS      = 0;
    Dest.f_TargetNormSN     = 0;
    Dest.f_RampPeriod       = 0;
    Dest.f_GainReduction    = 0;
    Dest.u_TimeStamp        = 0;
    Dest.u_GainReduction    = 0;
    Dest.u_WindowBeamIdx    = 0;
    Dest.DataValid          = 0;
    Dest.RfChanged          = 0;
    Dest.PowerReduction     = 0;
    Dest.AdcOverflow        = 0;
    Dest.u_RangeWindowIdx   = 0;
    Dest.u_DopplerWindowIdx = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = 0;
      Dest.as_PathCompensation[uPathIdx].s_Imag = 0;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = 0;
    }
  };
  static void Init(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig & Dest)
  {
    Dest.i_VersionNumber  = RHCAdjHwCfgV2_B0::RHC_ADJ_HW_CONFIG_VERSION;
    Dest.RampPar.f_RangeGateLength  = 0.4f;
    Dest.RampPar.f_MidFrequ         = 76.6e9f;
    Dest.f_TargetNormS              = 0;
    Dest.f_TargetNormSN             = 0;
    Dest.f_RampPeriod               = 0;
    Dest.f_GainReduction            = 0;
    Dest.u_TimeStamp                = 0;
    Dest.u_GainReduction            = 0;
    Dest.u_WindowBeamIdx            = 0;
    Dest.DataValid                  = 0;
    Dest.RfChanged                  = 0;
    Dest.PowerReduction             = 0;
    Dest.AdcOverflow                = 0;
    Dest.u_RangeWindowIdx           = 0;
    Dest.u_DopplerWindowIdx         = 0;
  };
  static void ConvertV5ToV4(RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV5::RHC_t_AdjHwConfig & Source, unsigned int uiRecVersion, unsigned char ucNSorFS)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV4::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter  = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter        = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus            = Source.sSigHeader.eSigStatus;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ               = Source.RampPar.f_MidFrequ;

    // Other fields
    Dest.f_TargetNormS      = Source.f_TargetNormS;
    Dest.f_TargetNormSN     = Source.f_TargetNormSN;
    // Monopuls
    Dest.f_MonopulseBeamOffset = Source.f_MonopulseBeamOffset;
    for (int ii = 0; ii < (sizeof(Dest.f_MonopulseBeamError)/sizeof(Dest.f_MonopulseBeamError[0])); ii++)
    {
      Dest.f_MonopulseBeamError[ii] = 0;
    }
    // Other fields
    Dest.f_RampPeriod       = Source.f_RampPeriod;
    Dest.f_GainReduction    = Source.f_GainReduction;
    Dest.u_TimeStamp        = 0;
    Dest.u_GainReduction    = Source.u_GainReduction;
    Dest.u_WindowBeamIdx    = Source.u_WindowBeamIdx;
    Dest.DataValid          = Source.DataValid;
    Dest.u_CurrentRfIndex   = Source.u_CurrentRfIndex;
    Dest.PowerReduction     = 0;
    Dest.AdcOverflow        = 0;
    Dest.u_RangeWindowIdx   = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx = Source.u_DopplerWindowIdx;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = Source.as_PathCompensation[uPathIdx].s_Real;
      Dest.as_PathCompensation[uPathIdx].s_Imag = Source.as_PathCompensation[uPathIdx].s_Imag;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = Source.aui16_AzimuthWindow[uAziWinIdx];
    }
  }
  static void ConvertV4ToV5(RHCAdjHwCfgV5::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Source, unsigned int uiRecVersion, unsigned char ucNSorFS)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV4::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter  = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter        = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus            = Source.sSigHeader.eSigStatus;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ               = Source.RampPar.f_MidFrequ;

    // Other fields
    Dest.f_TargetNormS      = Source.f_TargetNormS;
    Dest.f_TargetNormSN     = Source.f_TargetNormSN;
    // Monopuls
    Dest.f_MonopulseBeamOffset = Source.f_MonopulseBeamOffset;
    // Other fields
    Dest.f_RampPeriod       = Source.f_RampPeriod;
    Dest.f_GainReduction    = Source.f_GainReduction;
    Dest.u_GainReduction    = Source.u_GainReduction;
    Dest.u_WindowBeamIdx    = Source.u_WindowBeamIdx;
    Dest.DataValid          = Source.DataValid;
    Dest.u_CurrentRfIndex   = Source.u_CurrentRfIndex;
    Dest.u_RangeWindowIdx   = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx = Source.u_DopplerWindowIdx;
    Dest.u_MsbCorrIndex     = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = Source.as_PathCompensation[uPathIdx].s_Real;
      Dest.as_PathCompensation[uPathIdx].s_Imag = Source.as_PathCompensation[uPathIdx].s_Imag;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = Source.aui16_AzimuthWindow[uAziWinIdx];
    }
    // Other fields
    if (ucNSorFS == 1)
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNSorFS == 2)
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS - 4.2F;
      }
    }
  }
  static void ConvertV3ToV5(RHCAdjHwCfgV5::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV3::RHC_t_AdjHwConfig & Source)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV4::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter  = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter        = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus            = Source.sSigHeader.eSigStatus;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ               = Source.RampPar.f_MidFrequ;

    // Other fields
    Dest.f_TargetNormS      = Source.f_TargetNormS;
    Dest.f_TargetNormSN     = Source.f_TargetNormSN;
    // Monopuls
    Dest.f_MonopulseBeamOffset = Source.f_MonopulseBeamOffset;
    // Other fields
    Dest.f_RampPeriod       = Source.f_RampPeriod;
    Dest.f_GainReduction    = Source.f_GainReduction;
    Dest.u_GainReduction    = Source.u_GainReduction;
    Dest.u_WindowBeamIdx    = Source.u_WindowBeamIdx;
    Dest.DataValid          = Source.DataValid;
    Dest.u_CurrentRfIndex   = Source.RfChanged;
    Dest.u_RangeWindowIdx   = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx = Source.u_DopplerWindowIdx;
    Dest.u_MsbCorrIndex     = 0;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = Source.as_PathCompensation[uPathIdx].s_Real;
      Dest.as_PathCompensation[uPathIdx].s_Imag = Source.as_PathCompensation[uPathIdx].s_Imag;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = Source.aui16_AzimuthWindow[uAziWinIdx];
    }
  };
  static void ConvertV3ToV4(RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV3::RHC_t_AdjHwConfig & Source)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV4::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = Source.sSigHeader.uiTimeStamp;
    Dest.sSigHeader.uiMeasurementCounter  = Source.sSigHeader.uiMeasurementCounter;
    Dest.sSigHeader.uiCycleCounter        = Source.sSigHeader.uiCycleCounter;
    Dest.sSigHeader.eSigStatus            = Source.sSigHeader.eSigStatus;
    // Ramp Parameter
    Dest.RampPar.f_RangeGateLength        = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ               = Source.RampPar.f_MidFrequ;

    // Other fields
    Dest.f_TargetNormS      = Source.f_TargetNormS;
    Dest.f_TargetNormSN     = Source.f_TargetNormSN;
    // Monopuls
    Dest.f_MonopulseBeamOffset = Source.f_MonopulseBeamOffset;
    for (int ii = 0; ii < (sizeof(Dest.f_MonopulseBeamError)/sizeof(Dest.f_MonopulseBeamError[0])); ii++)
    {
      Dest.f_MonopulseBeamError[ii] = 0;
    }
    // Other fields
    Dest.f_RampPeriod       = Source.f_RampPeriod;
    Dest.f_GainReduction    = Source.f_GainReduction;
    Dest.u_TimeStamp        = Source.u_TimeStamp;
    Dest.u_GainReduction    = Source.u_GainReduction;
    Dest.u_WindowBeamIdx    = Source.u_WindowBeamIdx;
    Dest.DataValid          = Source.DataValid;
    Dest.u_CurrentRfIndex   = Source.RfChanged;
    Dest.PowerReduction     = Source.PowerReduction;
    Dest.AdcOverflow        = Source.AdcOverflow;
    Dest.u_RangeWindowIdx   = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx = Source.u_DopplerWindowIdx;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = Source.as_PathCompensation[uPathIdx].s_Real;
      Dest.as_PathCompensation[uPathIdx].s_Imag = Source.as_PathCompensation[uPathIdx].s_Imag;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = Source.aui16_AzimuthWindow[uAziWinIdx];
    }
  };

  static void ConvertB0V2ToV2(RHCAdjHwCfgV2::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig & Source)
  {
    Dest.i_VersionNumber = RHCAdjHwCfgV2::RHC_ADJ_HW_CONFIG_VERSION;
    // signal header
    Dest.sSigHeader.uiTimeStamp           = Source.u_TimeStamp;
    Dest.sSigHeader.uiMeasurementCounter  = Source.u_TimeStamp;
    Dest.sSigHeader.uiCycleCounter        = Source.u_TimeStamp;
    Dest.sSigHeader.eSigStatus            = ((Source.DataValid == 1)?AL_SIG_STATE_OK:AL_SIG_STATE_INVALID);
    // Ramp parameters
    Dest.RampPar.f_RangeGateLength        = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ               = Source.RampPar.f_MidFrequ;
    // Other fields
    Dest.f_TargetNormS      = Source.f_TargetNormS;
    Dest.f_TargetNormSN     = Source.f_TargetNormSN;
    Dest.f_RampPeriod       = Source.f_RampPeriod;
    Dest.f_GainReduction    = Source.f_GainReduction;
    Dest.u_TimeStamp        = Source.u_TimeStamp;
    Dest.u_GainReduction    = Source.u_GainReduction;
    Dest.u_WindowBeamIdx    = Source.u_WindowBeamIdx;
    Dest.DataValid          = Source.DataValid;
    Dest.RfChanged          = Source.RfChanged;
    Dest.PowerReduction     = Source.PowerReduction;
    Dest.AdcOverflow        = Source.AdcOverflow;
    Dest.u_RangeWindowIdx   = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx = Source.u_DopplerWindowIdx;
    for (unsigned int uPathIdx=0; uPathIdx < (sizeof(Dest.as_PathCompensation)/sizeof(Dest.as_PathCompensation[0])); uPathIdx++)
    {
      Dest.as_PathCompensation[uPathIdx].s_Real = 0;
      Dest.as_PathCompensation[uPathIdx].s_Imag = 0;
    }
    for (unsigned int uAziWinIdx=0; uAziWinIdx < (sizeof(Dest.aui16_AzimuthWindow)/sizeof(Dest.aui16_AzimuthWindow[0])); uAziWinIdx++)
    {
      Dest.aui16_AzimuthWindow[uAziWinIdx] = 0;
    }
  };
  static void ConvertV2ToB0V2(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV2::RHC_t_AdjHwConfig & Source)
  {
    Dest.i_VersionNumber  = RHCAdjHwCfgV2_B0::RHC_ADJ_HW_CONFIG_VERSION;
    Dest.RampPar.f_RangeGateLength  = Source.RampPar.f_RangeGateLength;
    Dest.RampPar.f_MidFrequ         = Source.RampPar.f_MidFrequ;
    Dest.f_TargetNormS              = Source.f_TargetNormS;
    Dest.f_TargetNormSN             = Source.f_TargetNormSN;
    Dest.f_RampPeriod               = Source.f_RampPeriod;
    Dest.f_GainReduction            = Source.f_GainReduction;
    Dest.u_TimeStamp                = ((Source.u_TimeStamp != 0)?(Source.u_TimeStamp):(Source.sSigHeader.uiTimeStamp));
    Dest.u_GainReduction            = Source.u_GainReduction;
    Dest.u_WindowBeamIdx            = Source.u_WindowBeamIdx;
    Dest.DataValid                  = Source.DataValid;
    Dest.RfChanged                  = Source.RfChanged;
    Dest.PowerReduction             = Source.PowerReduction;
    Dest.AdcOverflow                = Source.AdcOverflow;
    Dest.u_RangeWindowIdx           = Source.u_RangeWindowIdx;
    Dest.u_DopplerWindowIdx         = Source.u_DopplerWindowIdx;
  };
  bool AllocBuffer(size_t nSize)
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

  static void ConvertV4ToV4Workaround(RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Dest, const RHCAdjHwCfgV4::RHC_t_AdjHwConfig & Source, unsigned int uiRecVersion, unsigned char ucNSorFS)
  {
    memcpy(&Dest, &Source, sizeof(Dest));

    // Other fields
    if (ucNSorFS == 1)
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS + 7.4F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS - 0.5F;
      }
    }
    else if (ucNSorFS == 2)
    {
      if ((uiRecVersion == 0x40004) || (uiRecVersion == 0x40022) || (uiRecVersion == 0x40100))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS + 3.3F;
      }
      else if ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105))
      {
        Dest.f_TargetNormS = Source.f_TargetNormS - 4.2F;
      }
    }
    // ??? Dest.f_TargetNormSN     = Source.f_TargetNormSN;
  };

  bool GetDeps (unsigned int &uiRecVersion, unsigned char &ucNSorFS)
  {
    bool bRet = false;
    DepInfo *pValUi = GetDependencyInfo(RECVERSION);
    // retrieve dependency for being used
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL))
    {
      uiRecVersion = * (unsigned int *) pValUi->m_pDepData;
    }
    DepInfo *pValUc = GetDependencyInfo(NSORFS);
    // retrieve dependency for being used
    if ((pValUc != NULL) && (pValUc->m_pDepData != NULL))
    {
      ucNSorFS = *((unsigned char *) pValUc->m_pDepData);
    }
    if ((pValUi != NULL) && (pValUi->m_pDepData != NULL) &&
      (pValUc != NULL) && (pValUc->m_pDepData != NULL))
    {
      if ((uiRecVersion == 0x40004) ||
        (uiRecVersion == 0x40022) ||
        (uiRecVersion == 0x40100) ||
        ((uiRecVersion >= 0x40102) && (uiRecVersion <= 0x40105)))
      {
        if ((ucNSorFS == 1) || (ucNSorFS == 2))
        {
          bRet = true;
        }
      }
    }
    return bRet;
  }

public:

  CConvRhcAdjHwCfg(void) : CSimConverterBase(DEP_NAMES, DEP_COUNT), m_uAllocSize(0), m_pAllocBuffer(NULL)
  {
  };
  virtual ~CConvRhcAdjHwCfg(void)
  {
    if (m_pAllocBuffer != NULL)
    {
      ::free(m_pAllocBuffer);
      m_pAllocBuffer = NULL;
    }
  };

  const char* GetTypeName()
  {
    return "RHC_t_AdjHwConfig";
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
    long lRet = SIM_ERR_NO_VERSION_FOR_PORT;
    unsigned int uiRecVersion = 0;
    unsigned char ucNSorFS = 0;
    bool bWorkaroundHandling = false;
    // retrieve dependency for being used
    bWorkaroundHandling = GetDeps(uiRecVersion, ucNSorFS);

    if (eRPortType == ePPortType)
    {
      if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || (requestPortVersionInfo.Equals(pProvidePortVersionInfo))) &&
        (bWorkaroundHandling == false))
      {
        // Use data directly from provide port
        lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
      }
      else
      {
        // Some form of conversion needed, allocate buffer large enough to store converted data
        if (AllocBuffer(ulRPortSize))
        {
          const uint32 src_ver = (ulPPortSize > 4)?(*static_cast<const uint32*>(pPPortData)):0;
          switch (src_ver)
          {
            // WORK-AROUND: Obviously there are measurements where the version number is not filled
          case 0:
          case 2:
            {
              // Source provides rhc adj hw config version 2
              if (sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulPPortSize)
              {
                const RHCAdjHwCfgV2::RHC_t_AdjHwConfig * const pSrc = reinterpret_cast<const RHCAdjHwCfgV2::RHC_t_AdjHwConfig*>(pPPortData);
                if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV2_B0::Version)) && (sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertV2ToB0V2(*pDest, *pSrc);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_DATA_SIZE;
                }
              }
              else if (sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulPPortSize)
              {
                const RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig * const pSrc = reinterpret_cast<const RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig*>(pPPortData);
                if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV2::Version)) && (sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV2::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV2::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertB0V2ToV2(*pDest, *pSrc);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_DATA_SIZE;
                }
              }
              else
              {
                // Provide port size does not match any known 'V2'
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            break;
          case 3:
            {
              if (sizeof(RHCAdjHwCfgV3::RHC_t_AdjHwConfig) == ulPPortSize)
              {
                const RHCAdjHwCfgV3::RHC_t_AdjHwConfig * const pSrc = reinterpret_cast<const RHCAdjHwCfgV3::RHC_t_AdjHwConfig*>(pPPortData);
                if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)) && (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV4::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV4::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertV3ToV4(*pDest, *pSrc);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
                else if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)) && (sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV5::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV5::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertV3ToV5(*pDest, *pSrc);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
                else
                {
                  lRet = SIM_ERR_INVALID_DATA_SIZE;
                }
              }
              else
              {
                // Provide port size does not match any known 'V3'
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            break;
          case 4:
            {
              if (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulPPortSize)
              {
                const RHCAdjHwCfgV4::RHC_t_AdjHwConfig * const pSrc = reinterpret_cast<const RHCAdjHwCfgV4::RHC_t_AdjHwConfig*>(pPPortData);
                if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)) && (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV4::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV4::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertV4ToV4Workaround(*pDest, *pSrc, uiRecVersion, ucNSorFS);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
                else if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)) && (sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                    RHCAdjHwCfgV5::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV5::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                    ConvertV4ToV5(*pDest, *pSrc, uiRecVersion, ucNSorFS);
                    *pOutData = pDest;
                    ulOutSize = sizeof(*pDest);
                    lRet = SIM_ERR_OK;
                }
              }
              else if (ulRPortSize == ulPPortSize)
              {
                lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
              }
              else
              {
                // Provide port size does not match any known 'V4'
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }
            break;
          case 5:
            {
              if (sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulPPortSize)
              {
                const RHCAdjHwCfgV5::RHC_t_AdjHwConfig * const pSrc = reinterpret_cast<const RHCAdjHwCfgV5::RHC_t_AdjHwConfig*>(pPPortData);
                if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)) && (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize))
                {
                  RHCAdjHwCfgV4::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV4::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
                  ConvertV5ToV4(*pDest, *pSrc, uiRecVersion, ucNSorFS);
                  *pOutData = pDest;
                  ulOutSize = sizeof(*pDest);
                  lRet = SIM_ERR_OK;
                }
              }
              else if (ulRPortSize == ulPPortSize)
              {
                lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
              }
              else
              {
                // Provide port size does not match any known 'V5'
                lRet = SIM_ERR_NO_VERSION_FOR_PORT;
              }
            }

            break;
          case 1:
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
    }
    return lRet;
  };

  /** returns: 
  *   SIM_ERR_OK - when this value can be used
  *   SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT - when the default vaule is not implemented here
  *                                            and the default value from Request Port must be used
  */
  long GetDefaultValue(
    SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo& requestPortVersionInfo, 
    void** pDefaultData, unsigned long& ulDefaultSize)
  {
    long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
    if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV2::Version)) && (sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulRPortSize))
    {
      if (AllocBuffer(ulRPortSize))
      {
        RHCAdjHwCfgV2::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV2::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
        Init(*pDest);
        *pDefaultData = pDest;
        ulDefaultSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_INVALID_DATA_SIZE;
      }
    }
    else if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV2_B0::Version)) && (sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulRPortSize))
    {
      if (AllocBuffer(ulRPortSize))
      {
        RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
        Init(*pDest);
        *pDefaultData = pDest;
        ulDefaultSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_INVALID_DATA_SIZE;
      }
    }
    else if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)) && (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize))
    {
      if (AllocBuffer(ulRPortSize))
      {
        RHCAdjHwCfgV4::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV4::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
        Init(*pDest);
        *pDefaultData = pDest;
        ulDefaultSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_INVALID_DATA_SIZE;
      }
    }
    else if ((requestPortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)) && (sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulRPortSize))
    {
      if (AllocBuffer(ulRPortSize))
      {
        RHCAdjHwCfgV5::RHC_t_AdjHwConfig * const pDest = reinterpret_cast<RHCAdjHwCfgV5::RHC_t_AdjHwConfig*>(m_pAllocBuffer);
        Init(*pDest);
        *pDefaultData = pDest;
        ulDefaultSize = sizeof(*pDest);
        lRet = SIM_ERR_OK;
      }
      else
      {
        lRet = SIM_ERR_INVALID_DATA_SIZE;
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
    else if ((sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV2::Version)))
    {
      // Check if request port size checks out for version 2
      if (sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV2_B0::Version)))
    {
      // Check if request port size checks out for version 1
      if (sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)))
    {
      // Check if request port size checks out for version 3
      if (sizeof(RHCAdjHwCfgV3::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
      }
      // Check if request port size checks out for version 5
      if (sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)))
    {
      // Check if request port size checks out for version 3
      if (sizeof(RHCAdjHwCfgV3::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
      }
      // Check if request port size checks out for version 4
      if (sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulPPortSize)
      {
        bRet = true;
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
    else if ((sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV2::Version)))
    {
      // Check if request port size checks out for version 2 B0
      if ((sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulPPortSize) && (providePortVersionInfo.Equals(&RHCAdjHwCfgV2_B0::Version)))
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV2_B0::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV2_B0::Version)))
    {
      // Check if request port size checks out for version 2
      if ((sizeof(RHCAdjHwCfgV2::RHC_t_AdjHwConfig) == ulPPortSize) && (providePortVersionInfo.Equals(&RHCAdjHwCfgV2::Version)))
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV3::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV3::Version)))
    {
      // Check if request port size checks out for version 4
      if ((sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulPPortSize) && (providePortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)))
      {
        bRet = true;
      }
      // Check if request port size checks out for version 5
      if ((sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulPPortSize) && (providePortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)))
      {
        bRet = true;
      }
    }
    else if ((sizeof(RHCAdjHwCfgV4::RHC_t_AdjHwConfig) == ulRPortSize) && (requestPortVersionInfo.Equals(&RHCAdjHwCfgV4::Version)))
    {
      // Check if request port size checks out for version 5
      if ((sizeof(RHCAdjHwCfgV5::RHC_t_AdjHwConfig) == ulPPortSize) && (providePortVersionInfo.Equals(&RHCAdjHwCfgV5::Version)))
      {
        bRet = true;
      }
    }
    else
    {
      bRet = false;
    }
    return bRet;
  };

};

const TCHAR* CConvRhcAdjHwCfg::DEP_NAMES[CConvRhcAdjHwCfg::DEP_COUNT] = {_T("RecVersion"), _T("NSorFS")};

//
// Factory function
//
IConverter * CreateRhcAdjHwConfigConvClass(void)
{
  return new CConvRhcAdjHwCfg();
}
