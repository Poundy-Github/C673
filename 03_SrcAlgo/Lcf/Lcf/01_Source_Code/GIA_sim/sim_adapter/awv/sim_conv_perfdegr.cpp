/*! \file **********************************************************************

  COMPANY:         Continental

  PROJECT:         Simulation

  COMPONENT:       sim_adapter em

  MODULNAME:       sim_conv_perfdegr.cpp

  DESCRIPTION:

  AUTHOR:          Thomas Berndt

  CREATION DATE:   26.2.2015

  VERSION:         $Revision: 1.1 $

  ---*/ /*---
  CHANGES:         $Log: sim_conv_perfdegr.cpp  $
  CHANGES:         Revision 1.1 2021/12/13 17:20:34CET Wang, David (Wangd3) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.1 2017/08/10 13:15:00CEST uid34177 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_adapter/awv/project.pj
  CHANGES:         Revision 1.2 2015/06/16 10:30:14CEST Berndt, Thomas01 (berndtt1) 
  CHANGES:         + V8 (for X140)
  CHANGES:         - Added comments -  berndtt1 [Jun 16, 2015 10:43:27 AM CEST]
  CHANGES:         Change Package : 276620:8 http://mks-psad:7002/im/viewissue?selection=276620
  CHANGES:         Revision 1.1 2015/02/26 08:40:51CET Berndt, Thomas01 (berndtt1) 
  CHANGES:         Initial revision
  CHANGES:         Member added to project /nfs/projekte1/PROJECTS/ARS400/06_Algorithm/04_Engineering/03_Workspace/algo/sim_adapter/awv/project.pj

**************************************************************************** */
/* includes ---------------------------------------------------------------- */

#include "sim_adapter_cfg.h"
#include "sim_conv_perfdegr.h"
#include "sim_versioninfo_impl.h"

/** 
* @brief The standard AUTOSAR type boolean shall be implemented on basis of an eight bits long 
*        unsigned integer.
* @implements boolean_type
*/
typedef unsigned char boolean;
/* Boolean types */
typedef boolean Boolean                                              /* [Satisfies_rte sws 1188] */;
/* Common definitions/declarations */
typedef unsigned long AlgoDataTimeStamp_t                            /* Algo data time-stamp type (32 bit variant) @min:0 @max:4294967295 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned short AlgoCycleCounter_t                            /* Algo cycle counter @min:0 @max:65535 */  /* [Satisfies_rte sws 1188] */;
typedef unsigned char AlgoSignalState_t                              /* Algo signal state enumeration @min: 0 @max:2 @values: enum { AL_SIG_STATE_INVALID=2,AL_SIG_STATE_INIT=0,AL_SIG_STATE_OK=1,} */  /* [Satisfies_rte sws 1188] */;

typedef struct SignalHeader_t                                        /* [Satisfies_rte sws 1191] */
{
  AlgoDataTimeStamp_t uiTimeStamp;
  AlgoCycleCounter_t uiMeasurementCounter;
  AlgoCycleCounter_t uiCycleCounter;
  AlgoSignalState_t eSigStatus;
} SignalHeader_t;                                                    /* Common header for all structured data types */



namespace PerfDegr_V5
{
  typedef unsigned __int8 uFourByteDummy_array_t[2];                 /* dummy for four byte alignment @min:0 @max:1 */ /* [Satisfies_rte sws 1189] */
  typedef unsigned __int8 reserved_array_t[1];                       /* byte alignment */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float fMovingMeanRaw;                                            /* Mean raw range of moving objects */
    float fMovingConfRaw;                                            /* Confidence of moving raw range @min:0 @max:1 */
    float fStationaryMeanRaw;                                        /* Mean raw range of stationary objects */
    float fStationaryMaxRaw;                                         /* Max raw range of stationary objects */
    float fStationaryConfRaw;                                        /* Confidence of stationary raw range @min:0 @max:1 */
  } RangeRaw_t;                                                      /* Raw Results of moving and stationary Range observer */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float fMovingMeanFiltered;                                       /* Mean filtered range of moving objects */
    float fMovingMeanConfFiltered;                                   /* Confidence of moving filtered range @min:0 @max:1 */
    float fStatMeanFiltered;                                         /* Mean filtered range of stationary objects */
    float fStatMeanConfFiltered;                                     /* Confidence of stationary filtered range @min:0 @max:1 */
    float fFLDMeanFiltered;                                          /* Mean filtered range of first/last detection */
    float fFLDMeanConfFiltered;                                      /* Confidence of first/last detection @min:0 @max:1 */
  } RangeFiltered_t;                                                 /* Filtered Results all Range observer */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float fFusedRange;                                               /* Fused range result of all range observers */
    float fFusedConf;                                                /* Fused confidence result of all range observers @min:0 @max:1 */
  } RangeFused_t;                                                    /* Fused result of all range observer */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float fTimeCounter;                                              /* Passed time since last object */
    float fWayCounter;                                               /* Driven distance since last object */
  } Timeout_t;                                                       /* Timeout counters for distance and time */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    boolean bResetAck;                                               /* Acknowledge reset of blockage information. This is the hand-shake signal used by FCT to clear the blockage reset request (since acknowledged by EM) @min:0 @max:1 */
  } Blockage_t;                                                      /* Blockage related signals */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    float fTargetRate;                                               /* Overall target rate of moving and stationary targets */
    float fTargetRateStat;                                           /* Target rate for stationary targets */
    float fTargetRateMov;                                            /* Target rate for moving targets */
  } TargetRate_t;                                                    /* Target rates for stationary and moving targets */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int8 iQuality;                                        /* quality for road visibility @min:0 @max:100 */
    unsigned __int8 RoadVisibility;                                  /* road visibility [%] @min:0 @max:100 */
    unsigned __int8 BeamCrossingCounter;                             /* Number of Crossings of Noise Beam and Road Beam @min:0 @max:255 */
    reserved_array_t reserved;                                       /* byte alignment */
  } RoadBeamScan;                                                    /* Results of the road beam calculation in RSP2 for a single scan */

  typedef RoadBeamScan RoadBeam_array_t[1];                          /* Results of the road beam calculation in RSP2 */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 uiVersionNumber;                                /* Version number of interface @min:1 @max:16777215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    RangeRaw_t RangeRaw;                                             /* Raw Results of moving and stationary Range observer */
    RangeFiltered_t RangeFiltered;                                   /* Filtered Results all Range observer */
    RangeFused_t RangeFused;                                         /* Fused result of all range observer */
    Timeout_t Timeout;                                               /* Timeout counters for distance and time */
    Blockage_t Blockage;                                             /* Blockage related signals */
    TargetRate_t TargetRate;                                         /* Target rates for stationary and moving targets */
    RoadBeam_array_t RoadBeam;                                       /* Results of the road beam calculation in RSP2 */
    float fTunnelProbability;                                        /* TunnelProbability @min:0 @max:1 */
    float fNoiseRange;                                               /* sensor range on a norm target computed from current noise @min:0 @max:1000 */
    boolean bNoiseRangeValid;                                        /* false if fNoiseRange could not be computed in current ignition cycle @min:0 @max:1 */
    unsigned __int8 ucCarparkState;                                  /* if 1, then sensor vehicle is inside a carpark @min:0 @max:1 */
    uFourByteDummy_array_t uFourByteDummy;                           /* dummy for four byte alignment @min:0 @max:1 */
  } PerfDegr_t;                                                      /* Perfermance degredation data @vaddr:0x20112200 @vaddr_defs: EM_MEAS_ID_PERF_DEG_OUT_DATA @cycleid:EM_ENV @vname:EMPerfDegrOut */
} // end of PerfDegr_V5


namespace PerfDegr_V7
{
  typedef PerfDegr_V5::RangeRaw_t RangeRaw_array_t[1];               /* Raw Results of moving and stationary Range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::RangeFiltered_t RangeFiltered_array_t[1];     /* Filtered Results all Range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::RangeFused_t RangeFused_array_t[1];           /* Fused result of all range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::TargetRate_t TargetRate_array_t[1];           /* Target rates for stationary and moving targets */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    boolean bResetAck;                                               /* Acknowledge reset of blockage information. This is the hand-shake signal used by FCT to clear the blockage reset request (since acknowledged by EM) @min:0 @max:1 */
    boolean bSummerParameterset;                                     /* Indicates if Summer or Winter parameterset is used. 0=Winter, 1=Summer @min:0 @max:1 */
    boolean bTemperatureBlockageOff;                                 /* Indicates that Blockage was turned off because of high temperature and no wisher. If bTemperatureBlockageOff is 1, bSummerParameterset is irrelevant. @min:0 @max:1 */
    boolean bWisherIntegrationFeatureOn;                             /* Indicates that wisher integration is active @min:0 @max:1 */
    boolean bWisherRainDetected;                                     /* Indicates that rain was detected based on wisher information @min:0 @max:1 */
    boolean bCameraIntegrationFeatureOn;                             /* Indicates that the camera integration feature is active @min:0 @max:1 */
    boolean bCameraAvailability;                                     /* Indicates that camera is available @min:0 @max:1 */
    boolean bCameraObjectsDetected;                                  /* Indicates that camera detected sufficient number of objects @min:0 @max:1 */
    boolean bDecreaseTimerDecided;                                   /* Indicates that the decrease of timeout timers was decided based on camera information @min:0 @max:1 */
    boolean bCameraWisherRainDetected;                               /* Indicates that rain was detected based on wisher information. This is different than bWisherRainDetected, because in camera integration we have a different threshold. @min:0 @max:1 */
    boolean bUseCameraWiper;                                         /* Indicates that whiper information is used in camera integration @min:0 @max:1 */
  } Blockage_t;                                                      /* Blockage related signals */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 uiVersionNumber;                                /* Version number of interface @min:1 @max:16777215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    RangeRaw_array_t RangeRaw;                                       /* Raw Results of moving and stationary Range observer */
    RangeFiltered_array_t RangeFiltered;                             /* Filtered Results all Range observer */
    RangeFused_array_t RangeFused;                                   /* Fused result of all range observer */
    PerfDegr_V5::Timeout_t Timeout;                                  /* Timeout counters for distance and time */
    Blockage_t Blockage;                                             /* Blockage related signals */
    TargetRate_array_t TargetRate;                                   /* Target rates for stationary and moving targets */
    PerfDegr_V5::RoadBeam_array_t RoadBeam;                          /* Results of the road beam calculation in RSP2 */
    float fTunnelProbability;                                        /* TunnelProbability @min:0 @max:1 */
    float fNoiseRange;                                               /* sensor range on a norm target computed from current noise @min:0 @max:1000 */
    boolean bNoiseRangeValid;                                        /* false if fNoiseRange could not be computed in current ignition cycle @min:0 @max:1 */
    unsigned __int8 ucCarparkState;                                  /* if 1, then sensor vehicle is inside a carpark @min:0 @max:1 */
    PerfDegr_V5::uFourByteDummy_array_t uFourByteDummy;              /* dummy for four byte alignment @min:0 @max:1 */
  } PerfDegr_t;                                                      /* Perfermance degredation data @vaddr:0x20125FF1 @vaddr_defs: EM_MEAS_ID_PERF_DEG_OUT_DATA @cycleid:EM_ENV @vname:EMPerfDegrOut */
} // end of PerfDegr_V7


namespace PerfDegr_V8
{
  typedef PerfDegr_V5::RangeRaw_t RangeRaw_array_t[1];               /* Raw Results of moving and stationary Range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::RangeFiltered_t RangeFiltered_array_t[1];     /* Filtered Results all Range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::RangeFused_t RangeFused_array_t[1];           /* Fused result of all range observer */ /* [Satisfies_rte sws 1189] */
  typedef PerfDegr_V5::TargetRate_t TargetRate_array_t[1];           /* Target rates for stationary and moving targets */ /* [Satisfies_rte sws 1189] */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    boolean bResetAck;                                               /* Acknowledge reset of blockage information. This is the hand-shake signal used by FCT to clear the blockage reset request (since acknowledged by EM) @min:0 @max:1 */
    boolean bSummerParameterset;                                     /* Indicates if Summer or Winter parameterset is used. 0=Winter, 1=Summer @min:0 @max:1 */
    boolean bSummerWithHighTemp;                                     /* Indicates if Summer or Winter is detected 0=Winter, 1=Summer. Temp Thresh is factor*temp therh which used for bSummerParameterset @min:0 @max:1 */
    boolean bSummerWithHighTempNoRain;                               /* Indicates if Summer and no Rain are detcted, 1=Summer and No rain.  Else 0 @min:0 @max:1 */
    boolean bTemperatureBlockageOff;                                 /* Indicates that Blockage was turned off because of high temperature and no wisher. If bTemperatureBlockageOff is 1, bSummerParameterset is irrelevant. @min:0 @max:1 */
    boolean bWisherIntegrationFeatureOn;                             /* Indicates that wisher integration is active @min:0 @max:1 */
    boolean bWisherRainDetected;                                     /* Indicates that rain was detected based on wisher information @min:0 @max:1 */
    boolean bCameraIntegrationFeatureOn;                             /* Indicates that the camera integration feature is active @min:0 @max:1 */
    boolean bCameraAvailability;                                     /* Indicates that camera is available @min:0 @max:1 */
    boolean bCameraObjectsDetected;                                  /* Indicates that camera detected sufficient number of objects @min:0 @max:1 */
    boolean bDecreaseTimerDecided;                                   /* Indicates that the decrease of timeout timers was decided based on camera information @min:0 @max:1 */
    boolean bCameraWisherRainDetected;                               /* Indicates that rain was detected based on wisher information. This is different than bWisherRainDetected, because in camera integration we have a different threshold. @min:0 @max:1 */
    boolean bUseCameraWiper;                                         /* Indicates that whiper information is used in camera integration @min:0 @max:1 */
  } Blockage_t;                                                      /* Blockage related signals */

  typedef struct                                                     /* [Satisfies_rte sws 1191] */
  {
    unsigned __int32 uiVersionNumber;                                /* Version number of interface @min:1 @max:16777215 */
    SignalHeader_t sSigHeader;                                       /* information for synchronisation of SIL simulation */
    RangeRaw_array_t RangeRaw;                                       /* Raw Results of moving and stationary Range observer */
    RangeFiltered_array_t RangeFiltered;                             /* Filtered Results all Range observer */
    RangeFused_array_t RangeFused;                                   /* Fused result of all range observer */
    PerfDegr_V5::Timeout_t Timeout;                                  /* Timeout counters for distance and time */
    Blockage_t Blockage;                                             /* Blockage related signals */
    TargetRate_array_t TargetRate;                                   /* Target rates for stationary and moving targets */
    PerfDegr_V5::RoadBeam_array_t RoadBeam;                          /* Results of the road beam calculation in RSP2 */
    float fTunnelProbability;                                        /* TunnelProbability @min:0 @max:1 */
    float fNoiseRange;                                               /* sensor range on a norm target computed from current noise @min:0 @max:1000 */
    boolean bNoiseRangeValid;                                        /* false if fNoiseRange could not be computed in current ignition cycle @min:0 @max:1 */
    unsigned __int8 ucCarparkState;                                  /* if 1, then sensor vehicle is inside a carpark @min:0 @max:1 */
    PerfDegr_V5::uFourByteDummy_array_t uFourByteDummy;              /* dummy for four byte alignment @min:0 @max:1 */
  } PerfDegr_t;                                                      /* Perfermance degredation data @vaddr:0x20125FF1 @vaddr_defs: EM_MEAS_ID_PERF_DEG_OUT_DATA @cycleid:EM_ENV @vname:EMPerfDegrOut */
} // end of PerfDegr_V8


class CConvPerfDegr : public CSimConverterBase
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

  PerfDegr_V5::PerfDegr_t m_BufV5;
  PerfDegr_V7::PerfDegr_t m_BufV7;
  PerfDegr_V8::PerfDegr_t m_BufV8;

  // Initialization
  template <typename T> static void InitVx (T & Dest)
  {
    ::memset(&Dest, 0, sizeof(Dest));
  }

public:

  static const char *GetConverterTypeName()
  {
    return "EMPerformanceDegr";
  }

  CConvPerfDegr(void);
  virtual ~CConvPerfDegr(void);

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
  enum AVWV_PerfDegr
  {
    PerfDegr_V5,
    PerfDegr_V7,
    PerfDegr_V8,
    PERFDEGR_VERSION_COUNT
  };

  static CVersionInfoImpl BASE_VERSION;
  static CVersionInfoImpl VERSION5;
  static CVersionInfoImpl VERSION7;
  static CVersionInfoImpl VERSION8;

  static const CVersionInfoImpl * const PERFDEGR_VERSIONS[PERFDEGR_VERSION_COUNT];

  static const unsigned long SUPPORTED_SIZE[PERFDEGR_VERSION_COUNT];

  bool IsPortSupported(unsigned long ulPortSize, const IVersionInfo *pPortVersion) const
  {
    for (int nI = 0; nI < PERFDEGR_VERSION_COUNT; nI++)
    {
      if ((pPortVersion == NULL) || pPortVersion->Equals(PERFDEGR_VERSIONS[nI]))
      {
        if (ulPortSize == SUPPORTED_SIZE[nI])
        {
          return true;
        }
      }
    };
    return false;
  };
};

CVersionInfoImpl CConvPerfDegr::BASE_VERSION(0, 0, 0);
CVersionInfoImpl CConvPerfDegr::VERSION5(0, 0, 5);
CVersionInfoImpl CConvPerfDegr::VERSION7(0, 0, 7);
CVersionInfoImpl CConvPerfDegr::VERSION8(0, 0, 8);

const CVersionInfoImpl * const CConvPerfDegr::PERFDEGR_VERSIONS[CConvPerfDegr::PERFDEGR_VERSION_COUNT] =
{
  &VERSION5,
  &VERSION7,
  &VERSION8
};

const unsigned long CConvPerfDegr::SUPPORTED_SIZE[CConvPerfDegr::PERFDEGR_VERSION_COUNT] =
{
  sizeof(PerfDegr_V5::PerfDegr_t),
  sizeof(PerfDegr_V7::PerfDegr_t),
  sizeof(PerfDegr_V8::PerfDegr_t)
};

__inline void v_Convert_v8_to_v7 (PerfDegr_V7::PerfDegr_t * const pDest,
  const PerfDegr_V8::PerfDegr_t * const pSrc)
{
  pDest->uiVersionNumber                      = 7u;
  pDest->sSigHeader                           = pSrc->sSigHeader;
  pDest->RangeRaw[0]                          = pSrc->RangeRaw[0];
  pDest->RangeFiltered[0]                     = pSrc->RangeFiltered[0];
  pDest->RangeFused[0]                        = pSrc->RangeFused[0];
  pDest->Timeout                              = pSrc->Timeout;
  pDest->Blockage.bResetAck                   = pSrc->Blockage.bResetAck;
  pDest->Blockage.bSummerParameterset         = pSrc->Blockage.bSummerParameterset;
  pDest->Blockage.bTemperatureBlockageOff     = pSrc->Blockage.bTemperatureBlockageOff;
  pDest->Blockage.bWisherIntegrationFeatureOn = pSrc->Blockage.bWisherIntegrationFeatureOn;
  pDest->Blockage.bWisherRainDetected         = pSrc->Blockage.bWisherRainDetected;
  pDest->Blockage.bCameraIntegrationFeatureOn = pSrc->Blockage.bCameraIntegrationFeatureOn;
  pDest->Blockage.bCameraAvailability         = pSrc->Blockage.bCameraAvailability;
  pDest->Blockage.bCameraObjectsDetected      = pSrc->Blockage.bCameraObjectsDetected;
  pDest->Blockage.bDecreaseTimerDecided       = pSrc->Blockage.bDecreaseTimerDecided;
  pDest->Blockage.bCameraWisherRainDetected   = pSrc->Blockage.bCameraWisherRainDetected;
  pDest->Blockage.bUseCameraWiper             = pSrc->Blockage.bUseCameraWiper;
  pDest->TargetRate[0]                        = pSrc->TargetRate[0];
  pDest->RoadBeam[0]                          = pSrc->RoadBeam[0];
  pDest->fTunnelProbability                   = pSrc->fTunnelProbability;
  pDest->fNoiseRange                          = pSrc->fNoiseRange;
  pDest->bNoiseRangeValid                     = pSrc->bNoiseRangeValid;
  pDest->ucCarparkState                       = pSrc->ucCarparkState;
  pDest->uFourByteDummy[0]                    = pSrc->uFourByteDummy[0];
  pDest->uFourByteDummy[1]                    = pSrc->uFourByteDummy[1];
}

__inline void v_Convert_v7_to_v5 (PerfDegr_V5::PerfDegr_t * const pDest,
  const PerfDegr_V7::PerfDegr_t * const pSrc)
{
  pDest->uiVersionNumber    = 5u;
  pDest->sSigHeader         = pSrc->sSigHeader;
  pDest->RangeRaw           = pSrc->RangeRaw[0];
  pDest->RangeFiltered      = pSrc->RangeFiltered[0];
  pDest->RangeFused         = pSrc->RangeFused[0];
  pDest->Timeout            = pSrc->Timeout;
  pDest->Blockage.bResetAck = pSrc->Blockage.bResetAck;
  pDest->TargetRate         = pSrc->TargetRate[0];
  pDest->RoadBeam[0]        = pSrc->RoadBeam[0];
  pDest->fTunnelProbability = pSrc->fTunnelProbability;
  pDest->fNoiseRange        = pSrc->fNoiseRange;
  pDest->bNoiseRangeValid   = pSrc->bNoiseRangeValid;
  pDest->ucCarparkState     = pSrc->ucCarparkState;
  pDest->uFourByteDummy[0]  = pSrc->uFourByteDummy[0];
  pDest->uFourByteDummy[1]  = pSrc->uFourByteDummy[1];
}

__inline void v_Convert_v5_to_v7 (PerfDegr_V7::PerfDegr_t * const pDest,
  const PerfDegr_V5::PerfDegr_t * const pSrc)
{
  pDest->uiVersionNumber                      = 7u;
  pDest->sSigHeader                           = pSrc->sSigHeader;
  pDest->RangeRaw[0]                          = pSrc->RangeRaw;
  pDest->RangeFiltered[0]                     = pSrc->RangeFiltered;
  pDest->RangeFused[0]                        = pSrc->RangeFused;
  pDest->Timeout                              = pSrc->Timeout;
  pDest->Blockage.bResetAck                   = pSrc->Blockage.bResetAck;
  pDest->Blockage.bSummerParameterset         = 0;
  pDest->Blockage.bTemperatureBlockageOff     = 0;
  pDest->Blockage.bWisherIntegrationFeatureOn = 0;
  pDest->Blockage.bWisherRainDetected         = 0;
  pDest->Blockage.bCameraIntegrationFeatureOn = 0;
  pDest->Blockage.bCameraAvailability         = 0;
  pDest->Blockage.bCameraObjectsDetected      = 0;
  pDest->Blockage.bDecreaseTimerDecided       = 0;
  pDest->Blockage.bCameraWisherRainDetected   = 0;
  pDest->Blockage.bUseCameraWiper             = 0;
  pDest->TargetRate[0]                        = pSrc->TargetRate;
  pDest->RoadBeam[0]                          = pSrc->RoadBeam[0];
  pDest->fTunnelProbability                   = pSrc->fTunnelProbability;
  pDest->fNoiseRange                          = pSrc->fNoiseRange;
  pDest->bNoiseRangeValid                     = pSrc->bNoiseRangeValid;
  pDest->ucCarparkState                       = pSrc->ucCarparkState;
  pDest->uFourByteDummy[0]                    = pSrc->uFourByteDummy[0];
  pDest->uFourByteDummy[1]                    = pSrc->uFourByteDummy[1];
}

__inline void v_Convert_v7_to_v8 (PerfDegr_V8::PerfDegr_t * const pDest,
  const PerfDegr_V7::PerfDegr_t * const pSrc)
{
  pDest->uiVersionNumber                      = 7u;
  pDest->sSigHeader                           = pSrc->sSigHeader;
  pDest->RangeRaw[0]                          = pSrc->RangeRaw[0];
  pDest->RangeFiltered[0]                     = pSrc->RangeFiltered[0];
  pDest->RangeFused[0]                        = pSrc->RangeFused[0];
  pDest->Timeout                              = pSrc->Timeout;
  pDest->Blockage.bResetAck                   = pSrc->Blockage.bResetAck;
  pDest->Blockage.bSummerParameterset         = pSrc->Blockage.bSummerParameterset;
  pDest->Blockage.bSummerWithHighTemp         = 0;
  pDest->Blockage.bSummerWithHighTempNoRain   = 0;
  pDest->Blockage.bTemperatureBlockageOff     = pSrc->Blockage.bTemperatureBlockageOff;
  pDest->Blockage.bWisherIntegrationFeatureOn = pSrc->Blockage.bWisherIntegrationFeatureOn;
  pDest->Blockage.bWisherRainDetected         = pSrc->Blockage.bWisherRainDetected;
  pDest->Blockage.bCameraIntegrationFeatureOn = pSrc->Blockage.bCameraIntegrationFeatureOn;
  pDest->Blockage.bCameraAvailability         = pSrc->Blockage.bCameraAvailability;
  pDest->Blockage.bCameraObjectsDetected      = pSrc->Blockage.bCameraObjectsDetected;
  pDest->Blockage.bDecreaseTimerDecided       = pSrc->Blockage.bDecreaseTimerDecided;
  pDest->Blockage.bCameraWisherRainDetected   = pSrc->Blockage.bCameraWisherRainDetected;
  pDest->Blockage.bUseCameraWiper             = pSrc->Blockage.bUseCameraWiper;
  pDest->TargetRate[0]                        = pSrc->TargetRate[0];
  pDest->RoadBeam[0]                          = pSrc->RoadBeam[0];
  pDest->fTunnelProbability                   = pSrc->fTunnelProbability;
  pDest->fNoiseRange                          = pSrc->fNoiseRange;
  pDest->bNoiseRangeValid                     = pSrc->bNoiseRangeValid;
  pDest->ucCarparkState                       = pSrc->ucCarparkState;
  pDest->uFourByteDummy[0]                    = pSrc->uFourByteDummy[0];
  pDest->uFourByteDummy[1]                    = pSrc->uFourByteDummy[1];
}

CConvPerfDegr::CConvPerfDegr(void) : CSimConverterBase(NULL/*DEP_NAMES*/, DEP_COUNT), m_BufV5(), m_BufV7(), m_BufV8()
{
  InitVx(m_BufV5);
  InitVx(m_BufV7);
  InitVx(m_BufV8);
}

CConvPerfDegr::~CConvPerfDegr(void)
{
}

long CConvPerfDegr::ConvertData(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo *pProvidePortVersionInfo,
  void *pPPortData,
  void **pOutData, unsigned long &ulOutSize)
{
  long lRet = SIM_ERR_UNADAPTABLE_DATA_PORTS;
  //const unsigned int uDataVer = ((pPPortData != NULL) && (ulPPortSize >= 4) && (ePPortType == simOPAQUE_t))?(*reinterpret_cast<unsigned int*>(pPPortData)):(0);

  if (eRPortType == ePPortType)
  {
    if ((ulRPortSize == ulPPortSize) && ((pProvidePortVersionInfo == NULL) || requestPortVersionInfo.Equals(pProvidePortVersionInfo)))
    {
      // Use data directly from provide port
      lRet = SIM_ERR_USE_VALUE_FROM_PPORT;
    }
    else
    {
      // First decide which version we are converting from
      if ((ulPPortSize == SUPPORTED_SIZE[PerfDegr_V8]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(PERFDEGR_VERSIONS[PerfDegr_V8])))
      {
        const PerfDegr_V8::PerfDegr_t *pSrc = reinterpret_cast<PerfDegr_V8::PerfDegr_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V7]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V7])))
        {
          // Destination port of V7 is m_BufV7
          v_Convert_v8_to_v7(&m_BufV7, pSrc);
          *pOutData = &m_BufV7;
          ulOutSize = sizeof(m_BufV7);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V5]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V5])))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v8_to_v7(&m_BufV7, pSrc);
          v_Convert_v7_to_v5(&m_BufV5, &m_BufV7);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[PerfDegr_V7]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(PERFDEGR_VERSIONS[PerfDegr_V7])))
      {
        const PerfDegr_V7::PerfDegr_t *pSrc = reinterpret_cast<PerfDegr_V7::PerfDegr_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V8]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V8])))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v7_to_v8(&m_BufV8, pSrc);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V5]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V5])))
        {
          // Destination port of V5 is m_BufV5
          v_Convert_v7_to_v5(&m_BufV5, pSrc);
          *pOutData = &m_BufV5;
          ulOutSize = sizeof(m_BufV5);
          lRet = SIM_ERR_OK;
        }
      }
      else if ((ulPPortSize == SUPPORTED_SIZE[PerfDegr_V5]) &&
        ((pProvidePortVersionInfo == NULL) || pProvidePortVersionInfo->Equals(PERFDEGR_VERSIONS[PerfDegr_V5])))
      {
        const PerfDegr_V5::PerfDegr_t *pSrc = reinterpret_cast<PerfDegr_V5::PerfDegr_t *>(pPPortData);
        // The decide which version we are converting to
        if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V8]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V8])))
        {
          // Destination port of V8 is m_BufV8
          v_Convert_v5_to_v7(&m_BufV7, pSrc);
          v_Convert_v7_to_v8(&m_BufV8, &m_BufV7);
          *pOutData = &m_BufV8;
          ulOutSize = sizeof(m_BufV8);
          lRet = SIM_ERR_OK;
        }
        else if ((ulRPortSize == SUPPORTED_SIZE[PerfDegr_V7]) &&
          (requestPortVersionInfo.Equals(PERFDEGR_VERSIONS[PerfDegr_V7])))
        {
          // Destination port of V7 is m_BufV7
          v_Convert_v5_to_v7(&m_BufV7, pSrc);
          *pOutData = &m_BufV7;
          ulOutSize = sizeof(m_BufV7);
          lRet = SIM_ERR_OK;
        }
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
long CConvPerfDegr::GetDefaultValue(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  void **pDefaultData, unsigned long &ulDefaultSize)
{
  long lRet = SIM_ERR_USE_DEFAULT_VALUE_FROM_RPORT;
  if (eRPortType == simOPAQUE_t)
  {
    if ((ulRPortSize == sizeof(PerfDegr_V8::PerfDegr_t)) && (PERFDEGR_VERSIONS[PerfDegr_V8]->Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV8);
      *pDefaultData = &m_BufV8;
      ulDefaultSize = sizeof(PerfDegr_V8::PerfDegr_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(PerfDegr_V7::PerfDegr_t)) && (PERFDEGR_VERSIONS[PerfDegr_V7]->Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV7);
      *pDefaultData = &m_BufV7;
      ulDefaultSize = sizeof(PerfDegr_V7::PerfDegr_t);
      lRet = SIM_ERR_OK;
    }
    else if ((ulRPortSize == sizeof(PerfDegr_V5::PerfDegr_t)) && (PERFDEGR_VERSIONS[PerfDegr_V5]->Equals(&requestPortVersionInfo)))
    {
      InitVx(m_BufV5);
      *pDefaultData = &m_BufV5;
      ulDefaultSize = sizeof(PerfDegr_V5::PerfDegr_t);
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
bool CConvPerfDegr::IsVersionCompatibleWithType(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, NULL)))
    {
      bResult = true;
    }
  }
  return bResult;
}

// used to check if ports are compatible between different versions
bool CConvPerfDegr::AreVersionsCompatible(
  SimPortDataTypes_t eRPortType, unsigned long ulRPortSize, const IVersionInfo &requestPortVersionInfo,
  SimPortDataTypes_t ePPortType, unsigned long ulPPortSize, const IVersionInfo &providePortVersionInfo)
{
  bool bResult = false;
  // Equal ports are always compatible (at least assumed to be)
  if ((ulRPortSize == ulPPortSize) && (eRPortType == ePPortType))
  {
    bResult = true;
  }
  else if ((eRPortType == simOPAQUE_t) && (ePPortType == simOPAQUE_t))
  {
    if ((IsPortSupported(ulRPortSize, &requestPortVersionInfo)) && (IsPortSupported(ulPPortSize, &providePortVersionInfo)))
    {
      bResult = true;
    }
  }
  return bResult;
}

//
// Main factory class returning conversion class
//
IConverter * CreatePerfDegrConvClass(void)
{
  return new CConvPerfDegr();
}
