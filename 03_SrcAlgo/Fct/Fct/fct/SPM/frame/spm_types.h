/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.23 $

---*/ /*---
**************************************************************************** */

#ifndef SPM_TYPES_H_INCLUDED
#define SPM_TYPES_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "algo_type.h"
#include "spm_cfg.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#include "fct_config.h"
#include "fct_types.h"
#endif


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)

#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)
/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef enum
{
	SPM_CATEGORY_NO_BLOCKAGE = 0U,
	SPM_BLOCKAGE_CAT_TEMPORARY = 1U,
	SPM_BLOCKAGE_CAT_PERM_CLEANING = 2U,
	SPM_BLOCKAGE_CAT_PERM_NOT_CLEANING = 3U,
	SPM_BLOCKAGE_CAT_UNKNOWN = 255U
}SPMBlockageCategory_t;

typedef enum
{
	SPM_NO_PARTIAL_BLOCKAGE       = 0U,
	SPM_UPCOMING_PARTIAL_BLOCKAGE = 1U,
	SPM_FULL_PARTIAL_BLOCAKGE     = 2U,
	SPM_UNKNOWN_PARTIAL_BLOCKAGE  = 255
}SPMPartialBlockageLevel_t;

typedef enum
{
	SPM_BLOCKAGE_TYPE_EARLY   = 0U,
	SPM_BLOCKAGE_TYPE_NORMAL  = 1U,
	SPM_BLOCKAGE_TYPE_LATE    = 2U,
	SPM_BLOCKAGE_TYPE_UNKNOWN = 255U
}SPMBlockageType_t;

typedef uint8 SPMCompState_t;

/*! @brief Type used for describing an FCT sub-component version */
typedef uint32 SPMSwVersion_t;

typedef struct SPMReqPortHandler{
   void const           * pReqPort;             /* Pointer to the require port */
   SignalHeader_t const * pReqPortSigHeader;    /* Pointer to the signal header of the require port */
   void const          ** ppGlobal;             /* Pointer to the global pointer. Will be bend to the require port pointer*/
   uint32                 uSize;                /* Size of the require port */
   SignalHeader_t       * pReqSigHeaderSyncRef; /* Pointer to the corresponding sig header in t_FCTSenSPMSyncRef */
   sMeasCycleMonitor      MeasCycleMonitor;     /* MeasCycleInformation of the port*/
}SPMReqPortHandler_t;

typedef struct SPMProPortHandler{
  void                 * pProPort;             /* Pointer to the provide port*/
  SignalHeader_t       * pProPortSigHeader;    /**/
  void                ** ppGlobal;             /**/
  uint32                 uSize;                /**/
  SignalHeader_t const * pReqPortSigHeader;    /**/
  uint32                 uMeasFreezeAddress;   /**/
  uint32               * pProVersionNumber;    /**/
  SPMCompState_t       * pProNewSigState;      /**/
  uint32                 uPorNewVersionNumber; /**/
}SPMProPortHandler_t;

typedef struct SPM_PortHandlerList{
  SPMProPortHandler_t ProPortHandler[SPM_NO_OF_PRO_PORTS];
  SPMReqPortHandler_t ReqPortHandler[SPM_NO_OF_REQ_PORTS];
  uint8 uNoOfProPorts;
  uint8 uNoOfReqPorts;
} SPMPortHandlerList_t;

/*! FCT sub-component version structure */
typedef struct FCTSenSPMVersions
{
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SPMSwVersion_t  uiSPM;
#endif
  uint32          uProjectID;
#ifdef __PDO__
  SPMSwVersion_t  SPM_VERSION_AS_TEXT;
#else
  SPMSwVersion_t  SPMVersionNumVar;
#endif
  SPMSwVersion_t  SPMSwVersion;
} SPMVersions_t;

typedef struct
{
  float32        fObjectLossProbability;            /*!< Probability of blockage detected with object loss algorithm */
  float32        fObjectLossConfidence;             /*!< Confidence of blockage detected with object loss algorithm */
  #if(SPM_USE_RANGE_GRADIENT)
  float32        fObjectLossProbabilityUsingRangeGradient[SYS_NUM_OF_SCANS];
  float32        fObjectLossMapGradient[SYS_NUM_OF_SCANS];
  #endif
  float32        fRelObjRCSFiltered;
  #if((ALGO_SensorType != ALGO_CFG_ARS400Entry) && (ALGO_SensorType != ALGO_CFG_ARS510))
   float32        fRelObjRCSNear;
   float32        fRelObjRCSFar;
  #endif
  float32        fLastRelObjDistX;
  float32        fLastRelObjDistY;
  float32        fLastRelObjDistFromLane;
  float32        fResetTimer;
  float32        fDampingProbability;
  float32        fDeadTimeCounter;
  float32        fPredictAngleMin;
  float32        fPredictAngleMax;
  float32        fExRelObjPosFollowTimer;           /* Maximum time period for position prediction of deleted relevant objects */ 
  float32        fLastRelObjVrelX;                  /* x-velocity of the relevant object in the last cycle */
  float32        fLastRelObjVrelY;                  /* y-velocity of the relevant object in the last cycle */
  float32        fLastRelObjArelX;                  /* X-acceleration of the relevant object in the last cycle */
  float32        fLastRelObjArelY;                  /* Y-acceleration of the relevant object in the last cycle */
  float32        fLastWidth;
  float32        fRelObjObsTimer;
  ubit32         uRelObjPresInAccRange;
#if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
  float32 fDeselectionTimer;                        /*used for measure of deselection of relevant object*/ 
  boolean bObjWasSelected;                          /* Flag for indicate that relevant object was selected */
  boolean bObjNowSelected;                          /* Flag for indicate that relevant object is selected */
#endif
  ObjNumber_t    cCurrRelObjID;
  ObjNumber_t    cLastRelObjID;
  boolean        bObjectWasPresent;
  boolean        bObjectNowPresent;                 /* A moving object is now present at the position of the deleted object */
  boolean        bPredictPositionOverlap;
  boolean        bRelevanceLossDetected;
  uint8          uiNoOfObjLosses;
#if(SPM_USE_LAST_CLASSIFICATION)
  uint8          uCurrentClasification;
  uint8          uLastClasification;
#endif

  boolean        bRelObjWasMov; 
} SPMObjectLoss_t;

/* selftest data */
typedef struct
{
  float32 SPMSelftestRangeMov;             /* [m] */
  float32 SPMSelftestRangeMovConf;         /* (0...1) */
  float32 SPMSelftestRangeSta;             /* [m] */
  float32 SPMSelftestRangeStaMax;          /* [m] */
  float32 SPMSelftestRangeStaConf;         /* (0...1) */
} SPMSelftest_t;

#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
/* roadbeam data */
typedef struct SPMRoadbeamData
{
  uint8   SPMRoadVisibility;           /* (0...100) */
  uint8   SPMRoadVisibilityQuality;    /* (0...100) */
  boolean SPMSensorTilted;             /* (0, 1) */
} SPMRoadbeamData_t;
#endif

typedef struct
{
  /*****************/
  /* Blockage data */
  /*****************/
  float32         SPMBlockageProbability;          /* (0...1) */
  float32         SPMBlockageConfidence;           /* (0...1) */
  float32         SPMFullBlockageTimer;            /* Timer in FULL DAMP mode before mode can be exited again (e.g. 1 minute) [s] */
  float32         SPMReactivationDelayTimerSRR;    /* Delay timer for system reactivation after SRR damping */
#if(SPM_DELAY_REACTIVATION)
  float32         SPMDelayReactivationTimer;       /* Delay timer for system reactivation after damping*/
  bool_t          bSPMDelayTimerSet;
#endif

  /* Range result members */
  float32 SPMBlockageRange;                /* [m] */
  float32 SPMBlockageRangeProb;            /* (0...1) */
  float32 SPMBlockageRangeConf;            /* (0...1) */
  float32 SPMRangeHoldCounter;
#if (SPM_USE_RANGE_GRADIENT == SWITCH_ON)
  float32 SPMBlockagePreviousRange[SYS_NUM_OF_SCANS];           /* [m] */
  float32 SPMBlockageCurrentRange[SYS_NUM_OF_SCANS];            /* SPM blockage current range for each scan */
  float32 SPMBlockageRangeGradient [SYS_NUM_OF_SCANS];          /* SPM blockage range gradient on each scan */
  float32 SPMBlockageRangeConfidenceGradient[SYS_NUM_OF_SCANS]; /* SPM blockage range gradient confidence */
  float32 SPMScanRangeConfidencePrevious[SYS_NUM_OF_SCANS];     /* SPM blockage previous range confidence*/
#endif
  float32 SPMScanRangeConfidence[SYS_NUM_OF_SCANS];    /*confidence of near/far increased*/

  /* Object Loss result members */
  float32 SPMBlockageObjLossProb;          /* (0...1) */
  float32 SPMBlockageObjLossConf;          /* (0...1) */

  /* Timeout result members */
  float32 SPMBlockageTimeoutTimeCounter;   /* [s] */
  float32 SPMBlockageTimeoutWayCounter;    /* [m] */
  float32 SPMBlockageTimeoutBlockProb;     /* (0...1) */
  float32 SPMBlockageTimeoutBlockConf;     /* (0...1) */

  /* current criteria weights for blockage fusion */
  float32 SPMCurrentRangeWeight;                 /* (0...1) */
  float32 SPMCurrentObjLossWeight;               /* (0...1) */
  float32 SPMCurrentTimeoutWeight;               /* (0...1) */

  float32        SPMSelftestTimeCounter;          /* [s] */
  float32        SPMSelftestTimeCounterThld;      /* [s] */
  SPMSelftest_t  SPMSelftestInput;                /* Range Move and Range Sta */
  float32 SPMInterferenceRange;
  uint32 SPMInterference;
  uint32 SPMInterferenceHoldCnt;

#if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
  float32 fFactorCBO;
#endif
#if (SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
  float32          SPMALNPartialDampDelayTimer;
  SYSDampState_t   SPMALNPartialDamp;
#endif
#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
  SYSDampState_t  SPMSRDSysDamp;                   /* Damping state of SRR (NO, INC, FULL, RDC) */
#endif
  SYSDampState_t  SPMBlockageState;                /* States: NO_DAMP - INC_DAMP - FULL_DAMP - RDC_DAMP */

  /*can only set to true if Temperature and Wiper Signal are used*/
  boolean bSPMPreventBlckIfHighTempNoRain;

  #if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
    ObjNumber_t SPMLastRelObjID;
  #endif

  /*****************/
  /* Roadbeam data */
  /*****************/
#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
  SPMRoadbeamData_t SPMRoadbeamInput[SYS_NUM_OF_SCANS];            /* Visible, Quality and Tilted */
#endif

  /* SPM flag that shows if partial blockage was set */
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)
  boolean SPMFullBlockageGenByALN;
  float32 fALNFactor;
#endif

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
  SPMBlockageType_t BlockageType;
  SPMPartialBlockageLevel_t PartialBlockageLevel;
  SPMBlockageCategory_t BlockageCategory;
  float32 fBlkLvlDebounceTimer;
#endif

  /*parameters update factor*/
  float32 fParametersUpdateFactor;

  /*****************/
  /* Selftest data */
  /*****************/
  eGDBPDStates_t SPMSelftestState;                /* States: STARTUP - ON - OFF - ROADBEAM */  
  eGDBPDStates_t SPMSelftestStateLast;            /*used to save the last Selftest to go back to this state in case of Rollbenchtest */

  /*********************/
  /* Interference data */
  /*********************/
  boolean SPMInterferenceState;

#if(SPM_CHECK_MISSALIGNMENT)
  boolean bIncreasePartialBlockage;
  boolean bMissalignment;
  times_t tMissalignmentCounter;
#endif
} SPMData_t;
#endif

#endif /* SPM_SRR_TECHNOLOGY*/

#endif /* SPM_TYPES_H_INCLUDED */
