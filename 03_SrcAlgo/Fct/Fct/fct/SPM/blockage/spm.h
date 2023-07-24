// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.48 $

/// This file contains the headers of functions used for blockage determination.
///
/// @file       spm.h
///
/// @page       SPM_SensorPerformanceMonitoring

/***********************************************************************
  CHANGES:                 $Log: spm.h  $
  CHANGES:                 Revision 1.48 2021/03/01 10:29:36CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                 Add void to SPM_v_SetDelayCounter param and update design
  CHANGES:                 Revision 1.47 2021/02/25 10:37:48CET Pallo, Istvan (palloi) 
  CHANGES:                 Add new defines for Timeout increase state
  CHANGES:                 Revision 1.46 2021/02/24 13:15:01CET Pallo, Istvan (palloi) 
  CHANGES:                 Remove unused defines after reactivation delay change
  CHANGES:                 Revision 1.45 2021/02/05 15:13:40CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                 Add SPM_f_ComputeHelpFactorBasedWeather for QAC fix
  CHANGES:                 Revision 1.44 2020/09/24 09:08:27CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new function for init SPM factors
  CHANGES:                 Revision 1.43 2020/07/20 18:01:05CEST Pallo, Istvan (palloi) 
  CHANGES:                 Change bocakge type compute funtion name and return
  CHANGES:                 Revision 1.42 2020/06/30 16:27:42CEST Pallo, Istvan (palloi) 
  CHANGES:                 Revert SRR SPM split changes on trunk
  CHANGES:                 Revision 1.41 2020/06/29 17:34:19CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new function for comput blockage category
  CHANGES:                 Revision 1.40 2020/06/25 08:10:56CEST Pallo, Istvan (palloi) 
  CHANGES:                 Update code for SPM split - SRR
  CHANGES:                 Revision 1.39 2020/06/02 16:27:46CEST Pallo, Istvan (palloi) 
  CHANGES:                 Update set parameters functions headers. Add new defines for interpolation factors. Add new function headers for factors computation.
  CHANGES:                 Revision 1.38 2020/03/05 08:24:46CET Pallo, Istvan (palloi) 
  CHANGES:                 Update CBO config switches
  CHANGES:                 Revision 1.37 2020/02/24 09:30:26CET Pallo, Istvan (palloi) 
  CHANGES:                 Remove define for BSW parameters interface version.
  CHANGES:                 Revision 1.36 2020/02/20 12:50:22CET Pallo, Istvan (palloi) 
  CHANGES:                 Add new define for BSW interface version threshold
  CHANGES:                 Revision 1.35 2019/09/16 15:57:41CEST Motocu, Alexandru Marian02 (MotocuA02) 
  CHANGES:                 Added Interference Detection Logic for SRR
  CHANGES:                 Revision 1.34 2019/06/24 11:13:03CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new defines and function header for reactivation delay
  CHANGES:                 Revision 1.33 2019/05/28 09:52:48CEST Oprea, Ionut02 (OpreaI01) 
  CHANGES:                 Fix QAF warnings
  CHANGES:                 Revision 1.32 2019/04/10 08:20:23CEST Oprea, Ionut02 (OpreaI01) 
  CHANGES:                 Add detailed design for SPMCheckMissalignment and SPMCheckCameraConfirmation functions
  CHANGES:                 Revision 1.31 2019/04/01 10:29:57CEST Pallo, Istvan (palloi) 
  CHANGES:                 Change header of missalignment function in order to be called only with necessary data
  CHANGES:                 Revision 1.30 2019/03/07 14:06:33CET Pallo, Istvan (palloi) 
  CHANGES:                 Add new function headers for missalignment check
  CHANGES:                 Revision 1.29 2018/11/19 13:30:19CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                 Update design
  CHANGES:                 Revision 1.28 2018/10/05 10:33:53CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add define for FCTSenErrorOut interface version threshold
  CHANGES:                 Revision 1.27 2018/09/24 15:09:25CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add config switch and function headers for SRR
  CHANGES:                 Revision 1.26 2018/08/17 13:43:11CEST Pallo, Istvan (palloi) 
  CHANGES:                 Remove perfDegr parameter from function headers and design
  CHANGES:                 Revision 1.25 2018/08/07 07:10:04CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new errors for blockage observers and add new function header
  CHANGES:                 Revision 1.24 2018/08/06 07:45:26CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new define for delay timer.
  CHANGES:                 Revision 1.23 2018/08/01 13:05:50CEST Olaru, Marian (OlaruM02) 
  CHANGES:                 define SPM_PARTIAL_BLK_MIN_PROB_THLD
  CHANGES:                 Revision 1.22 2018/07/27 07:28:41CEST Olaru, Marian (OlaruM02) 
  CHANGES:                 define SPM_PARTIAL_BLK_MIN_CONF_THLD
  CHANGES:                 Revision 1.21 2018/04/24 11:13:53CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add extern declaration of SPMErrStates in order to fix QAC warning
  CHANGES:                 Revision 1.20 2018/04/24 09:17:02CEST Pallo, Istvan (palloi) 
  CHANGES:                 Correct the usage of config switch
  CHANGES:                 Revision 1.19 2018/04/19 14:02:42CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new config switch
  CHANGES:                 Revision 1.18 2018/04/03 10:46:38CEST Pallo, Istvan (palloi) 
  CHANGES:                 Remove paragraph comment for detailed design
  CHANGES:                 Revision 1.17 2018/02/28 12:12:08CET Pallo, Istvan (palloi) 
  CHANGES:                 Remove eba safety distance define as it is no longer computed by SPM
  CHANGES:                 Revision 1.16 2018/01/17 07:37:20CET Pallo, Istvan (palloi) 
  CHANGES:                 Design updates
  CHANGES:                 Revision 1.15 2018/01/16 08:55:39CET Pallo, Istvan (palloi) 
  CHANGES:                 Update design
  CHANGES:                 Revision 1.14 2017/11/23 14:01:11CET Pepenar, Alin (pepenara) 
  CHANGES:                 Update detailed design: added traceability
  CHANGES:                 Revision 1.13 2017/11/22 08:01:56CET Pallo, Istvan (palloi) 
  CHANGES:                 Remove SetCustomOutput function header
  CHANGES:                 Revision 1.12 2017/11/14 13:55:57CET Pallo, Istvan (palloi) 
  CHANGES:                 Update design and add test method for each function.
  CHANGES:                 Revision 1.11 2017/09/13 06:41:50CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add eba safety distante initial value define
  CHANGES:                 Revision 1.10 2017/08/18 16:40:13CEST Umesh Babu, Harsha (uidj3583) 
  CHANGES:                 Remove set custom output function declaration
  CHANGES:                 Revision 1.9 2017/08/18 10:18:41CEST Pallo, Istvan (palloi) 
  CHANGES:                 Remove LA include
  CHANGES:                 Revision 1.8 2017/08/11 08:36:14CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add functions uml diagrams. Remove static and external from function headers. Fix QA-C warnings
  CHANGES:                 Revision 1.7 2017/08/09 13:56:54CEST Olaru, Marian (OlaruM02) 
  CHANGES:                 adde the changes related to ALN(probability and confidence)
  CHANGES:                 Revision 1.6 2017/08/01 12:10:14CEST Olaru, Marian (OlaruM02) 
  CHANGES:                 range probability/confidence fusion using convolution method
  CHANGES:                 Revision 1.5 2017/07/28 06:57:13CEST Pallo, Istvan (palloi) 
  CHANGES:                 New function declarations and headers. New defines.
  CHANGES:                 Revision 1.4 2017/07/10 08:37:18CEST Umesh Babu, Harsha (uidj3583) 
  CHANGES:                 Moved function declarations
  CHANGES:                 Revision 1.3 2017/06/21 10:06:24CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add new function declaration and header
  CHANGES:                 Revision 1.2 2017/06/21 09:08:28CEST Pallo, Istvan (palloi) 
  CHANGES:                 Add headers for all functions.
  CHANGES:                 Add new functions declaration.
  CHANGES:                 Revision 1.1 2017/03/17 13:16:52CET Kober, Manfred (uidv8885) 
  CHANGES:                 Initial revision
  CHANGES:                 Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj

*****************************************************************************/

/* Bedingte Einbindung */
#ifndef SPM_H_INCLUDED
#define SPM_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_main.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_ON)
  #include"fct_sen.h"
#endif

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if(FCT_CFG_SIGNAL_PERF_MONITORING == SWITCH_ON)
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#define SPM_PROBABILITY_MAX                       (1.0F)
#define SPM_PROBABILITY_STATIONARY_LOW            (0.8F)
#define SPM_PROBABILITY_STATIONARY_HIGH           (1.2F)
#define SPM_PROBABILITY_INCREASE_FACTOR           (1.5F)
#define SPM_PROBABILITY_MIN                       (0.0F)
#define SPM_CONFIDENCE_MAX                        (1.0F)
#define SPM_CONFIDENCE_MIN                        (0.0F)
#define SPM_MINMAX_LOW_THLD                       (0.0F)
#define SPM_MINMAX_HIGH_THLD                      (1.0F)

#define SPM_LP_FILTER_CONSTANT                    (0.01F)

#define EM_PERF_INT_VER_THLD                      (6U)
#define VEH_DYN_INT_VER_THLD                      (8U)
#define EM_PERF_INT_WIPER_TEMP_VER_THLD           (8U)
#define EM_PERF_INTERFERENCE_INT_VER_THLD         (4U)

#define SPM_TMAX_ROADBEAM_ACTIVATION     (float32)(SPM_TMAX_UNTIL_OBJ - SPM_ROADBEAM_DURATION)

#define SPM_BLOCKAGE_LOWEST_RANGE_CONF            (0.3F)
#define SPM_BLOCKAGE_LOWEST_TIMEOUT_CONF          (0.3F)

#define SPM_ROADBEAM_AVAILABILITY_SPEED           (2.78F)   /* = 10.0 km/h */

#define SPM_OBJECT_LOST                           (SPMObjectLoss.uiNoOfObjLosses > 0U)

  #define SPM_PARAM_MIN_FACTOR_STEP                 (-0.02F)
  #define SPM_PARAM_MAX_FACTOR_STEP                 (0.02F)
  #define SPM_PARAM_FACTOR_DEFAULT_VAL              (1.0F)

#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
  /* below this velocity threshold (m/s), the roadbeam does not provide any data */
  #if(ALGO_CFG_FarScanAvailable)
    #define SPM_SCAN_INDEX_USED                   (SYS_SCAN_FAR)
  #else
    #define SPM_SCAN_INDEX_USED                   (SYS_SCAN_NEAR)
  #endif
#endif

#if((SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)||(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON))
  #define SPM_CAMERA_MIN_QUALITY_THLD             (0.9F)
  #define SPM_CAMERA_MIN_RATIO_THLD               (0.9F)
#endif

#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
  #define SPM_PARTIAL_BLK_MIN_CONF_THLD           (0.5F)
  #define SPM_PARTIAL_BLK_MIN_PROB_THLD           (0.8F)
#endif

#if(SPM_DELAY_REACTIVATION)
  #define SPM_DELAY_REACTIVATION_TIME_INVALID         (999.0F)
  #define SPM_DELAY_REACTIVATION_TIMER                (10.0F)
#endif

#define SPM_ALN_RANGE_DOWN_FACTOR_XVAL                (0.8F)
#define SPM_ALN_RANGE_DOWN_FACTOR_YVAL                (1.0F)
#define SPM_ALN_RANGE_UP_FACTOR_XVAL                  (1.0F - CML_f_Delta)
#define SPM_ALN_RANGE_UP_FACTOR_YVAL                  (1.25F)

#define SPM_RANGE_DOWN_FACTOR_XVAL                    (0.1F)
#define SPM_RANGE_DOWN_FACTOR_YVAL                    (1.25F)
#define SPM_RANGE_UP_FACTOR_XVAL                      (0.9F)
#define SPM_RANGE_UP_FACTOR_YVAL                      (1.0F)

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
#define SPM_BLK_LVL_TIMER_DEBOUNCE_TIME               (5.0F)
#define SPM_WEATHER_PROB                              (50U)
#endif

#define SPM_TIMEOUT_MIN_PROB_CONF_THLD                (0.4F)
#define SPM_TIMEOUT_CONF_VAL                          (0.8F)
/*****************************************************************************
  TYPEDEFS (KOMPONENTENEXTERN)
*****************************************************************************/
typedef struct 
{
  float32 Probability;
  float32 Confidence;
} SPMExternalBlockage_t;

typedef struct 
{
  uint32 Interference;
  sint32 HoldCnt;
} SPMInterference_t;

/* structure for internal observer states, last and current cycle -> possibility to detect which observers has triggered blockage */
typedef struct
{
  SYSDampState_t PreviousState;
  SYSDampState_t CurrentState;
} SPMObserverStates;


/* structure for blockage parameters which come via RTE BSWAlgoParameters or hard coded defines */
typedef struct {
  float32 fShutOffRange[SYS_NUM_OF_SCANS];
  float32 fShutOnRange[SYS_NUM_OF_SCANS];
  float32 fLowerRange[SYS_NUM_OF_SCANS];
  float32 fRoadbeamSpeedMin[SYS_NUM_OF_SCANS];
  float32 fTimeoutShutOffTime;
  float32 fTimeoutTimeThld;
  float32 fTimeoutShutOffWay;
  float32 fTimeoutWayThld;
  float32 fObjLossProbStepWidth;
  uint8   uiNofOfAllowedObjLosses;
  uint8   uRoadVisibilityQualityThresh[SYS_NUM_OF_SCANS];
  uint8   uRoadVisibilityThresh[SYS_NUM_OF_SCANS];
  uint8   uUseFarNearScanForBlck;
  boolean bUseRoadbeam[SYS_NUM_OF_SCANS];
  boolean bEnableBlockage;
  boolean bEnableSelftest;
  boolean bBlockageUseTemperature;
  boolean bBlockageUseWiper;
} SPMBlockageParameters_t;

/*! Enumeration of errors supported by SPM */
typedef enum SPMErrorEvents {
  SPM_ERREV_OBJECT_NOT_MEASURED,                  /*!< Formerly: DEM_TP_PD_DTR_OBJECT_NOT_MEASURED */
  SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE,          /*!< Formerly: DEM_TP_PD_OBJECT_NOT_MEASURED_FAILURE */
  SPM_ERREV_BLOCKAGE_INC_DAMP,                    /*!< Formerly: DEM_TP_PD_BLOCKAGE_INC_DAMP */
  SPM_ERREV_BLOCKAGE_FULL_DAMP,                   /*!< Formerly: DEM_TP_PD_BLOCKAGE_FULL_DAMP */
  SPM_ERREV_BLOCKAGE_RDC_DAMP,                    /*!< Formerly: DEM_TP_PD_BLOCKAGE_RDC_DAMP */
#if(SPM_CFG_SHORT_RANGE_SENSOR_INFO)
  SPM_ERREV_SRD_SYS_DAMP,                         /*!< Formerly: DEM_TP_PD_BLOCKAGE_SRD_SYS_DAMP */
#endif
  SPM_ERREV_INTERFERENCE_RANGE,                   /*!< Formerly: DEM_SPM_INTERFERENCE_RANGE */
  SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP,             /*!< Formerly: DEM_SPM_ROADBEAM_BLOCKAGE_TEST_STARTUP */
  SPM_ERREV_RB_BLOCKAGE_TEST,                     /*!< Formerly: DEM_SPM_ROADBEAM_BLOCKAGE_TEST */
  SPM_ERREV_PARTIAL_BLOCKAGE,                     /* error for partial blockage observer*/
  SPM_ERREV_OBJ_LOSS,                             /* error for object loss observer*/
  SPM_ERREV_RANGE,                                /* error for range observer */
  SPM_ERREV_TIMEOUT,                              /* error for timeout observer */

  SPM_ERREV_NUM_ERRORS
} SPMErrorEvents_t;
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! data of SPM blockage*/
extern SPMBlockageParameters_t SPMBlockageParameters;
/*! Ego speed used locally in this module */
extern fSpeed_t fEgoSpeed;
/*! Cycle time locally used in this module */
extern fTime_t  fCycleTime;

/*! X distance of the last relevant moving object seen */
extern fDistance_t fLastRelevantObjectDistance;

/**/
extern AlgoErrorState_t SPMErrStates[SPM_ERREV_NUM_ERRORS];

//sub-module state 
//extern MEMSEC_REF StateSPM_t     StateSPM;

/*****************************************************************************
  FUNCTION
*****************************************************************************/

/// @brief Set error state of a given SPM error
///
/// @pre                 None
/// @post                None
///
/// @param[in]           spm_error : SPM error for which the state is set
/// @param[in]           err_state : Error state to be set for the corresponding error
///
/// @return              void
///
/// @globals
///          SPMErrStates : SPM error states as an array of type AlgoErrorState_t and of size SPM_ERREV_NUM_ERRORS
///                   [SPM_ERREV_NUM_ERRORS as in spm.h]
///                   [AlgoErrorState_t as in Rte_Type.h]
///
/// @InOutCorrelation    Given a specific error spm_error set its state according to err_state in SPMErrStates array.
/// @startuml "Call sequence for SPMSetErrorState"
///
/// spm -> spm : SPMInit() calls SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
/// spm_blockage -> spm : SPMBlockageSetDEMEvents() calls SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
/// activate spm 
///   spm --> spm_blockage : 
/// deactivate spm
/// spm_selftest -> spm : SPMSelftest() calls SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
/// activate spm 
///   spm --> spm_selftest : 
/// deactivate spm
/// spm_interference -> spm : SPMInterferenceRange() calls SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
/// activate spm 
///   spm --> spm_interference : 
/// deactivate spm
/// @enduml
///
/// @testmethod          Test for memory access violation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-522-0006e2e0
///
void SPMSetErrorState(SPMErrorEvents_t spm_error, AlgoErrorState_t err_state);

#if ((SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= 8u))
/// @brief Check if summer conditions were detected and set the flag according 
///
/// @pre                None
/// @post               None
///
/// @param[in]          bBlockageUseTemperature : Flag that shows if external temperature data are used [TRUE, FALSE]
/// @param[in]          bBlockageUseWiper : Flag that shows if wiper data are used [TRUE, FALSE]
/// @param[in]          bSummerWithHighTempNoRain : Flag that shows if high temperature and no rain detected [TRUE, FALSE]
///
/// @return             boolean : Flag that shows if blockage decision is overwrite because no damping conditions were 
///                               detected by external sensors - temperature sensor and wiper sensor.
///
/// @globals            None
///
/// @InOutCorrelation   If wiper and temperature data are used and it was detected high temperature and no rain then 
///                     the flag to TRUE in order to prevent blockage triggered in summer conditions. Otherwise set the 
///                     flag to FALSE and let the blockage algorithm to take its decisions.
/// @startuml "Call sequence for SPMBlockagePreventIfHighTempAndNoRain"
///
/// spm -> spm : SPMProcess() calls\nSPMBlockagePreventIfHighTempAndNoRain(boolean, boolean, boolean)
/// activate spm
///   spm --> spm : 
/// deactivate spm
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-496-0006e2e0
///
boolean SPMBlockagePreventIfHighTempAndNoRain(const boolean bBlockageUseTemperature,
                                              const boolean bBlockageUseWiper,
                                              const boolean bSummerWithHighTempNoRain);
#endif

/// @brief Initiazilation of Object loss data structure
///
/// @pre                 None
/// @post                None
///
/// @return              void
///
/// @globals
///          SPMObjectLoss.fObjectLossProbabilityUsingRangeGradient[SYS_NUM_OF_SCANS] : Obhect loss probability using range 
///                   gradinet feature for each scan [0.0F ... 1.0F]\n
///          SPMObjectLoss.fObjectLossMapGradient[SYS_NUM_OF_SCANS] : Gradient value mapped between 0 and 1 for each 
///                   scan [0.0F ... 1.0F]\n
///          SPMObjectLoss.bObjWasSelected : Flag for indicating that object was selected as relevant [TRUE, FALSE]\n
///          SPMObjectLoss.bObjNowSelected : Flag for indicating that object is selected as relevant [TRUE, FALSE]\n
///          SPMObjectLoss.fDeselectionTimer : Number of cycles in which no relevant object was selected
///                   [0 ... 10 * SPM_CYCLE_TIME] \n
///          SPMObjectLoss.cCurrRelObjID : Current ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.cLastRelObjID : Last valid ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.fObjectLossProbability : Object loss blockage probability [0.0F ... 1.0F]\n
///          SPMObjectLoss.fObjectLossConfidence : Object loss blockage confidence[0.0F ... 1.0F]\n
///          SPMObjectLoss.fRelObjRCSNear : RCS of relevant object on near scan [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSFar : RCS of relevant object on far scan [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSFiltered : RCS filtered of relevant object [-30 ... 30]\n
///          SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis
///                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fLastRelObjDistY :Last distance of relevant object on Y axis
///                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fLastRelObjDistFromLane : Distance of relevant object from ego lane
///                    [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fDampingProbability : Object loss damping probability [0.0F ... 1.0F]\n
///          SPMObjectLoss.bRelevanceLossDetected : Flag for indicating that relevant object was detected [TRUE, FALSE]\n
///          SPMObjectLoss.bObjectWasPresent : Flag for indicating that relevant object was present [TRUE, FALSE]\n
///          SPMObjectLoss.bObjectNowPresent : Flag for indicating that relevant object is present [TRUE, FALSE]\n
///          SPMObjectLoss.fResetTimer : Object loss reset counter timer [0 ... 60] s\n
///          SPMObjectLoss.fDeadTimeCounter : Relevant object dead time counter [0 ... 1] s\n
///          SPMObjectLoss.uiNoOfObjLosses :  Number of relevant objects lost and counted [0 ...5]\n
///          SPMObjectLoss.bRelObjWasMov : Flag for indicate that relevant object was moving [TRUE, FALSE]\n
///          SPMObjectLoss.bPredictPositionOverlap : Flag for predicting overlap position of relevant object[TRUE, FALSE]\n
///          SPMObjectLoss.fRelObjObsTimer : Relevant object observe timer [0 ... SPM_OBJLOSS_MINRELOBJ_TIMER]\n
///          SPMObjectLoss.fExRelObjPosFollowTimer : Following timer for ex relevant object [0 ... SPM_OBJLOSS_FOLLOWTIMER_MAX] s\n
///          SPMObjectLoss.fLastRelObjVrelX : Relevant object velocity on X axis [-330.f ... 330.f] m/s\n
///          SPMObjectLoss.fLastRelObjArelX : Relevant object acceleration on X axis [-100.f ... +100.f] m/s2\n
///          SPMObjectLoss.fLastRelObjVrelY : Relevant object velocity on Y axis  [-330.f ... 330.f] m/s\n
///          SPMObjectLoss.fLastRelObjArelY : Relevant object acceleration on Y axis [-100.f ... +100.f] m/s2\n
///          SPMObjectLoss.fLastWidth : Relevant object width [0 ... 6] m\n
///          SPMObjectLoss.fPredictAngleMax : Relevant object predicted angle maxim [-PI ... +PI] rad\n
///          SPMObjectLoss.fPredictAngleMin : Relevant object predicted angle minim [-PI ... +PI] rad\n
///          SPMObjectLoss.uRelObjPresInAccRange : Flag for indicating that relevant object was in ACC range [TRUE, FALSE]\n
///          SPMObjectLoss.uCurrentClasification : Relevant object current classification 
///                   [ARS_OBJCLASS_POINT ... ARS_OBJCLASS_UNCLASSIFIED]\n
///          SPMObjectLoss.uLastClasification : Relevant object previous classification 
///                   [ARS_OBJCLASS_POINT ... ARS_OBJCLASS_UNCLASSIFIED]\n
///
/// @InOutCorrelation   Initializing the SPMObjectLoss structure with the default values
/// @startuml "Call sequence for SPMInitObjectLoss"
///
/// spm -> spm_objectloss :SPMProcess() calls SPMInitObjectLoss()
/// activate spm_objectloss
///   spm_objectloss --> spm : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test for memory access violation (dynamic module test)\n
///                     Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-511-0006e2e0
///
void SPMInitObjectLoss (void);

/// @brief Object Loss main function, detection of loss of relevance
///
/// @pre                None
/// @post               None
///
/// @param[in]          fOwnSpeed : Ego car speed [-100.F ... 100.F]
/// @param[in]          fProbStepWidth : ObjectLoss probability width for each loss of relevant object
/// @param[in]          pPerfDegrData : Performance degradation data from PD component
///
/// @return             void
///
/// @globals
///          SPMObjectLoss.cCurrRelObjID : Current ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.cLastRelObjID : Last valid ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.uRelObjPresInAccRang : Flag for indicating that relevant object was in ACC range [TRUE, FALSE]\n
///          SPMObjectLoss.uCurrentClasification : Object classification [ARS_OBJCLASS_POINT ... ARS_OBJCLASS_UNCLASSIFIED]\n
///          SPMObjectLoss.fRelObjRCSFiltered : RCS filtered of relevant object [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSNear : RCS of relevant object on near scan [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSFar : RCS of relevant object on far scan [-30 ... 30]\n
///          SPMObjectLoss.bRelevanceLossDetected :Flag for indicating that loss of relevance was detected  [TRUE, FALSE]\n
///          SPMObjectLoss.bObjectWasPresent :Flag for indicating that relevant object was present  [TRUE, FALSE]\n
///          SPMObjectLoss.fDeadTimeCounter : Relevant object dead time counter [0 ... 1] s\n
///          SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fLastRelObjDistY : Last distance of relevant object on Y axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fLastRelObjVrelX : Relevant object velocity on X axis  [-330.f ... 330.f] m/s\n
///          SPMObjectLoss.fLastRelObjVrelY : Relevant object velocity on Y axis [-330.f ... 330.f] m/s\n
///          SPMObjectLoss.fLastRelObjArelX : Relevant object acceleration on X axis [-100.f ... +100.f] m/s2\n
///          SPMObjectLoss.fLastRelObjArelY : Relevant object acceleration on Y axis [-100.f ... +100.f] m/s2\n
///          SPMObjectLoss.fLastWidth : Relevant object width[0 ... 6] m\n
///          SPMObjectLoss.fRelObjObsTimer : Relevant object observe timer [0 ... SPM_OBJLOSS_MINRELOBJ_TIMER]\n
///          SPMObjectLoss.bRelObjWasMov : Flag for indicate that relevant object was moving [TRUE, FALSE]\n
///          SPMObjectLoss.fDampingProbability : Probability of damping due to object losses [0.0F ... 1.0F]\n
///          SPMObjectLoss.uiNoOfObjLosses : Number of relevant objects lost and counted [0 ... 5]\n
///          SPMObjectLoss.fResetTimer : Object loss reset counter timer [0 ... 60] s\n
///          SPMObjectLoss.fObjectLossMapGradient[SYS_NUM_OF_SCANS] : Gradient value mapped between 0 and 1 for each scan
///                   [0.0F ... 1.0F]\n
///          SPMObjectLoss.fObjectLossProbability :Probability of damping due to object losses [0.0F ... 1.0F]\n
///          SPMObjectLoss.fObjectLossConfidence : Object loss observer confidence [0.0F ... 1.0F]\n
///          SPMObjectLoss.bObjWasSelected : Flag for indicating that object was selected as relevant [TRUE, FALSE]\n
///          SPMObjectLoss.bObjNowSelected : Flag for indicating that object is selected as relevant [TRUE, FALSE]\n
///          SPMObjectLoss.fDeselectionTimer : Number of cycles in which no relevant object was selected 
///                   [0 ... 10 * SPM_CYCLE_TIME]\n
///
/// @InOutCorrelation   Check for presence of relevant object. If it is present then actualize all the data regarding
///                     relevant object is SPMObjectLoss structure. If no object is present but it was present last
///                     cycle then compute the damping probability based on: distance from ego lane, longitudinal
///                     distance of the revant object, RCS of the relevant object, curve of the road and presence of
///                     the object in ACC range. If daming probability is greater that the considered threshold then
///                     count the relevant object as lost due to damping ad start the reset counter. If the damping
///                     probability is lower than the considered thereshold then cancel the observation for ex relevant
///                     object and reset SPMObjectLoss structure. Check for deletion of relevant object afterwards and
///                     if ex relevant object was deleted then count another loss of relevant object and increase the
///                     reset counter. Subtract the cycle time from reset counter. If the reset counter reached 0 and
///                     there are object losses counted then decrease the number of losses with one unit and set the 
///                     reset counter to it's initial value(20s).
/// @startuml "Call sequence for SPMProcessObjectLoss"
///
/// spm -> spm_objectloss : SPMProcess() calls SPMProcessObjectLoss(fSpeed_t, float32, PerfDegr_t)
/// activate spm_objectloss
///   spm_objectloss -> spm_objectloss : SPMDetermineOverLapFlag()
///   spm_objectloss -> spm_objectloss : SPMDetermineDampProb(PerfDegr_t, fSpeed_t)
///   spm_objectloss -> spm_objectloss : SPMCancelObjLossObservation()
///   spm_objectloss -> spm_objectloss : SPMDetermineOverLapFlag()
///   spm_objectloss -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_objectloss : 
///   spm_objectloss -> cml_misc : CML_f_LowPassFilter2(float32, float32, float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss -> cml_ecu_emul : CML_f_Max(float32, float32, float32)
///   cml_ecu_emul --> spm_objectloss : 
///   spm_objectloss --> spm : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-515-0006e2e0
///
void SPMProcessObjectLoss (const fSpeed_t fOwnSpeed, const float32 fProbStepWidth, const PerfDegr_t *pPerfDegrData);

/// @brief Determine the probability that relevant object was lost because of damping
///
/// @pre                Curent ID of relevant object is -1 but previous ID is different by -1. Check if the relevant 
///                     object was set as relevant for a certain period of time, or if there are already losses of 
///                     relevant object counted or speed is above 60kph.
/// @post               Check if damping probability is above a certain threshold and the object was not occluded by 
///                     another object
///
/// @param[in]          pPerfDegrData : reference to blockage data collected from EM
/// @param[in]          fOwnSpeed : Ego car speed [-100.F ... 100.F]
///
/// @return             float32 : Probability that loss of relevant object to be caused because of damping. [0 ... 1]
///
/// @globals
///          SPMObjectLoss.cLastRelObjID : Last valid ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fRelObjRCSNear : RCS of relevant object on near scan [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSFar : RCS of relevant object on far scan [-30 ... 30]\n
///          SPMObjectLoss.fRelObjRCSFiltered : Filtered RCS of relevant object [-30 ... 30]\n
///          SPMObjectLoss.fLastRelObjDistFromLane : Last distance of relevant object from ego lane [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.uRelObjPresInAccRange : Flag for indicating that relevant object was present in ACC range [TRUE, FALSE]\n
///
/// @InOutCorrelation   Determine the probability that relevant object was lost because of the damping. Check if the 
///                     ex relevant became another ACC object, if it had a high RCS, if was lost in short or high 
///                     distance, if left the eog lane, if left the ACC range or if was lost because of the curve of 
///                     the road. Compute the damping probability based on the data of each criteria and limit it 
///                     between 0 and 1. Return the damping probability computed.
/// @startuml "Call sequence for SPMDetermineDampProb"
///
/// spm_objectloss -> spm_objectloss : SPMProcessObjectLoss() calls SPMDetermineDampProb(PerfDegr_t, fSpeed_t)
/// activate spm_objectloss
///   spm_objectloss -> spm_objectloss : SPMStationaryCriteria(PerfDegr_t, float32, float32, float32, float32, uint8)
///   spm_objectloss -> cml_misc : CML_f_IsNonZero(float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss -> cml_misc : CML_f_IsZero(float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_objectloss : 
///   spm_objectloss -> cml_ecu_emul : CML_f_Max(float32, float32)
///   cml_ecu_emul --> spm_objectloss : 
///   spm_objectloss -> cml_misc : CML_f_MinMax(float32, float32, float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss--> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test of memory corruption (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-503-0006e2e0
///
float32 SPMDetermineDampProb(const PerfDegr_t *pPerfDegrData 
                             #if(SPM_PREVENT_LOW_SPEED_LOSSES == SWITCH_ON)
                             , float32 fOwnSpeed
                             #endif
                            );

/// @brief Detection of object deletions of ex-relevant objects
///
/// @pre                Check if loss of relevance was detected
/// @post               None
///
/// @return             boolean : Flag that indicates if ex relevant object was deleted or not. [TRUE, FALSE]
///
/// @globals
///          SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis[-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.fLastRelObjDistY : Last distance of relevant object on Y axis[-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///          SPMObjectLoss.bObjectNowPresent : Flag for indicating that relevant object is present [TRUE, FALSE]\n
///          SPMObjectLoss.bObjectWasPresent : Flag for indicating that relevant object was present[TRUE, FALSE]\n
///          SPMObjectLoss.fExRelObjPosFollowTimer : Following timer for ex relevant object [0 ... SPM_OBJLOSS_FOLLOWTIMER_MAX] s\n
///
/// @InOutCorrelation   Check if there is an object present at approximative same position as the ex relevant object.
///                     If it was detected then set the falg that object is present on true and reactualize the 
///                     relevant object properties. If object left the field of view then cancel the observation of ex
///                     relevant object. If no object was detected then make a prediction of the relevant object using 
///                     last data available. If the prediciton timer reached it's threshold then cancel the observation 
///                     for relevant object. If no relevant object was detected meantime then object was deteted and 
///                     the flag for deletion will be set according.
/// @startuml "Call sequence for SPMDetectObjectDeletion"
///
/// spm_objectloss -> spm_objectloss : SPMProcessObjectLoss() calls SPMDetectObjectDeletion()
/// activate spm_objectloss
///   spm_objectloss -> spm_objectloss : SPMCancelObjLossObservation()
///   spm_objectloss -> cml_misc : CML_Rad2Deg(float32)
///   cml_misc --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test for arithmetic errors (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-500-0006e2e0
///
boolean SPMDetectObjectDeletion(void);

/// @brief Compute the filter value for Object loss observer confidence
///
/// @pre                Check for SPM operating mode and FCT operating mode
/// @post               None
///
/// @return             float32 : value used in filtering the object loss confidence
///
/// @globals
///          SPMObjectLoss.uiNoOfObjLosses : Number of relevant objects lost and counted 
///                   [0 ...SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP]\n
///          SPMObjectLoss.cCurrRelObjID : Current ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///          SPMObjectLoss.fRelObjRCSFiltered : RCS filtered of relevant object [-30 ... 30]\n
///
/// @InOutCorrelation   Determine the value used to filter the ObjectLoss observer confidence. If there are objects 
///                     lost counted then the filter value is 1.0F. Otherwis, if there are no losses of relevant object 
///                     counted an relevant object is present then cmpute the filter value based on relevant object 
///                     RCS. If no relevant object is present then filter value is set to 0.0F.
/// @startuml "Call sequence for SPMDetermineFilterValue"
///
/// spm_objectloss -> spm_objectloss : SPMProcessObjectLoss() calls SPMDetermineFilterValue()
/// activate spm_objectloss
///   spm_objectloss -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_objectloss : Performance degradation data from PD component
///   spm_objectloss -> cml_misc : CML_f_MinMax(float32, float32, float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-504-0006e2e0
///
float32 SPMDetermineFilterValue(void);

/// @brief Compute damping probability based on stationary statistics
///
/// @pre                Check for SPM operating mode and FCT operating mode
/// @post               None
///
/// @param[in] pPerfDegrData : Performance degradation data from PD component
/// @param[in] RangeMax : Stationary range maximum threshold [full range of float32]
/// @param[in] RangeMin : Stationary range mainumul threshold [full range of float32]
/// @param[in] RateMax : Stationary target rate maximum threshold [full range of float32]
/// @param[in] RateMin : Stationary target rate minimum threshold [full range of float32]
/// @param[in] uScanIndex : Current scan for which the processing is done[SYS_SCAN_NEAR, SYS_SCAN_FAR]
///
/// @return             float32 : Damping probability resulted from stationary criteria
///
/// @globals            None
///
/// @InOutCorrelation   Compute the damping probability based on stationary objects. If stationary statistics are 
///                     available then compute damping probability using stationary statistics and map the data between 
///                     a minimum and a maximum range threshold. It they are not available then use stationary target 
///                     rate and map data btween a minumum and a maximum target rate threshold.
/// @startuml "Call sequence for SPMStationaryCriteria"
///
/// spm_objectloss -> spm_objectloss : SPMDetermineDampProb() calls\nSPMStationaryCriteria(PerfDegr_t, float32, float32, float32, float32, uint8)
/// activate spm_objectloss
///   spm_objectloss -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_objectloss : 
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-527-0006e2e0
///
float32 SPMStationaryCriteria(const PerfDegr_t *pPerfDegrData,
                              const float32 RangeMax,
                              const float32 RangeMin,
                              const float32 RateMax,
                              const float32 RateMin,
                              const uint8 uScanIndex);

/// @brief Compute predicted angle: atan(predicted lateral position/predicted longitudinal position)
///
/// @pre                None
/// @post               None
///
/// @param[in] fCurrLong : Object longitudinal distance [full range of float32]
/// @param[in] fCurrLat : Object lateral distance [full range of float32]
/// @param[in] fVelLong : Object relativ longitudinal speed [full range of float32]
/// @param[in] fVelLat : Object relativ lateral speed [full range of float32]
/// @param[in] fAccLong : Object relativ longitudinal acceleration [full range of float32]
/// @param[in] fAccLat : Object relativ lateral acceleration[full range of float32]
/// @param[in] fWidth : Object width [full range of float32]
///
/// @return             float32 : Predicted angle computed for an object
///
/// @globals            None
///
/// @InOutCorrelation   For a specific ACC object compute the predicted object angle based on object longitudinal and 
///                     lateral distance, speed, acceleration and object width.
/// @startuml "Call sequence for SPMPredictAngleComputation"
///
/// spm_objectloss -> spm_objectloss : SPMDetermineOverLapFlag() calls\nSPMPredictAngleComputation(float32, float32, float32, float32, float32, float32, float32)
/// activate spm_objectloss
///   spm_objectloss -> cml_trigo : GDBatan2_66(float32, float32)
///   cml_trigo --> spm_objectloss : 
///   spm_objectloss -> cml_misc : CML_f_MinMax(float32, float32, float32)
///   cml_misc --> spm_objectloss : 
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-514-0006e2e0
///
float32 SPMPredictAngleComputation(const float32 fCurrLong,
                                   const float32 fCurrLat,
                                   const float32 fVelLong,
                                   const float32 fVelLat,
                                   const float32 fAccLong,
                                   const float32 fAccLat,
                                   const float32 fWidth);

/// @brief Determine if predicted position of relevant object is cover by predicted position of one of  the other ACC objects
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        SPMObjectLoss.bPredictPositionOverlap : Flag for predicting overlap position of relevant object [TRUE, FALSE]\n
///        SPMObjectLoss.fPredictAngleMax : Relevant object predicted angle maxim [-PI ... +PI] rad\n
///        SPMObjectLoss.fPredictAngleMin : Relevant object predicted angle minim [-PI ... +PI] rad\n
///        SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMObjectLoss.fLastRelObjVrelX : Relevant object velocity on X axis [-330.f ... 330.f] m/s\n
///        SPMObjectLoss.fLastRelObjArelX : Relevant object acceleration on X axis [-100.f ... +100.f] m/s2\n
///
/// @InOutCorrelation   Determine if predicted position of relevant object is cover by predicted position of one of 
///                     the other ACC objects(ACC object 2,3,4,5)
/// @startuml "Call sequence for SPMDetermineOverLapFlag"
///
/// spm_objectloss -> spm_objectloss : SPMProcessObjectLoss() calls SPMDetermineOverLapFlag()
/// activate spm_objectloss
///   spm_objectloss -> spm_objectloss : SPMPredictAngleComputation(float32, float32, float32, float32, float32, float32, float32)
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test for memory access violation (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-506-0006e2e0
///
void SPMDetermineOverLapFlag(void);

/// @brief Compute and the predicted angles for ACC objects and determine if relevant object was occluded by other ACC object
///
/// @pre                None
/// @post               None
///
/// @param[in] fMinAngleACCObj : ACC object minim angle [-PI ... +PI] rad
/// @param[in] fMaxAngleACCObj : ACC object maxim angle [-PI ... +PI] rad
/// @param[in] fMinAngleRelObj : Relevant object minim angle [-PI ... +PI] rad
/// @param[in] fMaxAngleRelObj : Relevant object maxim angle [-PI ... +PI] rad
///
/// @return             void
///
/// @globals
///        SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m \n
///        SPMObjectLoss.fLastRelObjVrelX : Relevant object velocity on X axis [-330.f ... 330.f] m/s\n
///        SPMObjectLoss.fLastRelObjArelX : Relevant object acceleration on X axis [-100.f ... +100.f] m/s2\n
///        SPMObjectLoss.fPredictAngleMin : Relevant object predicted angle minim [-PI ... +PI] rad\n
///        SPMObjectLoss.fPredictAngleMax : Relevant object predicted angle maxim [-PI ... +PI] rad\n
///        SPMObjectLoss.bPredictPositionOverlap : Flag for predicting overlap position of relevant object [TRUE, FALSE]\n
///
/// @InOutCorrelation   Compute and check the predicted angles for ACC objects. If the angle for relevant object is 
///                     valid then check if the relevant object was occluded by other ACC object and set the overlap 
///                     flag according.
/// @startuml "Call sequence for SPMDetermineOverlapAngle"
///
/// spm_objectloss -> spm_objectloss : SPMDetermineOverLapFlag() calls SPMDetermineOverlapAngle(float32, float32, float32, float32)
/// activate spm_objectloss
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-505-0006e2e0
///
boolean SPMDetermineOverlapAngle(const float32 fMinAngleACCObj,
                                 const float32 fMaxAngleACCObj,
                                 const float32 fMinAngleRelObj,
                                 const float32 fMaxAngleRelObj);

/// @brief Cancel the observation of the ex-relevant object or the ex-relevant object prediction
///
/// @pre                Check for damping probability and if relevant object was covered by another object
/// @post               None
///
/// @return             void
///
/// @globals
///        SPMObjectLoss.bObjectWasPresent : Flag for indicating that relevant object was present [TRUE, FALSE]\n
///        SPMObjectLoss.bObjectNowPresent : [Flag for indicating that relevant object is present [TRUE, FALSE]\n
///         SPMObjectLoss.bPredictPositionOverlap : [Flag for predicting overlap position of relevant object[TRUE, FALSE]\n
///        SPMObjectLoss.fLastRelObjDistX : Last distance of relevant object on X axis
///                   [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m \n
///        SPMObjectLoss.fLastRelObjDistY : Last distance of relevant object on Y axis [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMObjectLoss.fLastRelObjVrelX : Relevant object velocity on X axis  [-330.f ... 330.f] m/s\n
///        SPMObjectLoss.fLastRelObjVrelY : Relevant object velocity on Y axis [-330.f ... 330.f] m/s\n
///        SPMObjectLoss.fLastWidth : Relevant object width[0 ... 6] m\n
///        SPMObjectLoss.fLastRelObjArelX: Relevant object acceleration on X axis [-100.f ... +100.f] m/s2\n
///        SPMObjectLoss.fLastRelObjArelY :Relevant object acceleration on Y axis [-100.f ... +100.f] m/s2\n
///        SPMObjectLoss.fPredictAngleMin : Relevant object predicted angle minim [-PI ... +PI] rad\n
///        SPMObjectLoss.fPredictAngleMax : Relevant object predicted angle maxim [-PI ... +PI] rad\n
///        SPMObjectLoss.fExRelObjPosFollowTimer : Following timer for ex relevant object [0 ... SPM_OBJLOSS_FOLLOWTIMER_MAX] s\n
///        SPMObjectLoss.fRelObjRCSFar : RCS of relevant object on far scan [-30 ... 30]\n
///        SPMObjectLoss.fRelObjRCSNear : RCS of relevant object on near scan [-30 ... 30]\n
///        SPMObjectLoss.fRelObjRCSFiltered : RCS filtered of relevant object [-30 ... 30]\n
///        SPMObjectLoss.cCurrRelObjID : Current ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///        SPMObjectLoss.cLastRelObjID : Last valid ID of relevant object [full range of ObjNumber_t as defined in Rte_Type.h]\n
///        SPMObjectLoss.uCurrentClasification : Relevant object current classification 
///                   [ARS_OBJCLASS_POINT ... ARS_OBJCLASS_UNCLASSIFIED]\n
///        sSPMObjectLoss.uLastClasification : Relevant object previous classification 
///                   [ARS_OBJCLASS_POINT ... ARS_OBJCLASS_UNCLASSIFIED]\n
///
/// @InOutCorrelation   Call all functions for setting SPM operating mode based on FCT operating, pocess of the data
///                     which are received through the request ports and freeze the SPM data for simulation framework.
///                     After all the computations were done call the functions to set the corresponding output on the
///                     provide ports.
/// @startuml "Call sequence for SPMCancelObjLossObservation"
///
/// spm -> spm_objectloss : SPMProcess() calls SPMCancelObjLossObservation()
/// spm_objectloss --> spm : 
/// spm_objectloss -> spm_objectloss : SPMProcessObjectLoss() calls SPMCancelObjLossObservation()
/// activate spm_objectloss
///   spm_objectloss --> spm_objectloss : 
/// deactivate spm_objectloss
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-498-0006e2e0
///
void SPMCancelObjLossObservation(void);

/// @brief Selftest main processing function, call selftest determination and set the DEM events
///
/// @pre                Check for SPM operating mode
/// @post               None
///
/// @param[in] pPerfDegrData : Performance degradation data from PD component
#if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
/// @param[in] fOwnspeed : Ego car speed [-100.F ... 100.F]
#endif
/// @param[in] bRollerTestBenchState : Flag that indicates if roller bench tests are made [TRUE, FALSE]
///
/// @param[out] puiBlockageEvent : Reference to blockage event [AlgoErrorState_t as defined in Rte_Type.h]
/// @param[out] puiSelftestEvent : Reference to selftest event [AlgoErrorState_t as defined in Rte_Type.h]
///
/// @return             void
///
/// @globals
///        SPMBlockageParameters.bEnableSelftest : Flag that indicates if selftest is enabled [TRUE, FALSE]\n
///        SPMData.SPMSelftestState : Selftest current state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestStateLast : Selftest previous state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///
/// @InOutCorrelation   Check for SPM operating mode. If the operating mode is EOL then set the SPM selftest errors to
///                     inactive. If operating mode is OK, ego speed is greated the considered threshold, rollerBench
///                     is active or selftest was not ativate from the parameters then proceed with selftest
///                     determination. Otherwise go back to the old selftest state. After this set the DEM events for
///                     selftest.
/// @startuml "Call sequence for SPMSelftest"
///
/// spm -> spm_selftest :SPMProcess() calls SPMSelftest(PerfDegr_t, float32, boolean, AlgoErrorState_t, AlgoErrorState_t)
/// activate spm_selftest
///   spm_selftest -> spm : SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
///   spm --> spm_selftest : 
///   spm_selftest -> spm_selftest : SPMSelftestDetermination(PerfDegr_t, float32, boolean)
///   spm_selftest -> spm_selftest : SPMSelftestSetDEMEvents(eGDBPDStates_t, AlgoErrorState_t, AlgoErrorState_t)
///   spm_selftest --> spm : 
/// deactivate spm_selftest
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-517-0006e2e0
///
void SPMSelftest(const PerfDegr_t *pPerfDegrData
               #if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
               , float32 fOwnspeed
               #endif
               , const boolean bRollerTestBenchState
               , AlgoErrorState_t *puiBlockageEvent
               , AlgoErrorState_t *puiSelftestEvent);

/// @brief Generate and communicate selftest data to DEM component
///
/// @pre                None
/// @post               None
///
/// @param[in] State : Current selftest state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]
///
/// @param[out] puiBlockageEvent : reference to blockage event [AlgoErrorState_t as defined in Rte_Type.h]
/// @param[out] puiSelftestEvent : reference to selftest event [AlgoErrorState_t as defined in Rte_Type.h]
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageState : SPM blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestState : SPM selftest state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///
/// @InOutCorrelation   Set the DEM events and errors acording to selftest state. If selftest is running set the 
///                     corresponding DEM as active, selftest error as active and blockage error as inactive. 
///                     If selftest was passed set all DEM events as inactive and selftest error as inactive. 
///                     If selftest was failed then set all selftest DEM's, selftest error and blockage error as active.
/// @startuml "Call sequence for SPMSelftestSetDEMEvents"
///
/// spm_selftest -> spm_selftest : SPMSelftest() calls SPMSelftestSetDEMEvents(eGDBPDStates_t, AlgoErrorState_t, AlgoErrorState_t)
/// activate spm_selftest
///   spm_selftest -> spm : SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
///   spm --> spm_selftest : 
/// deactivate spm_selftest
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-519-0006e2e0
///
void SPMSelftestSetDEMEvents (eGDBPDStates_t State, AlgoErrorState_t *puiBlockageEvent, AlgoErrorState_t *puiSelftestEvent);

#if(SPM_OBSERVERS_HISOTRY)
/// @brief Set the state of each blockage observer when blockage event is triggered
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageState : SPM blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMFullBlockageGenByALN : Flag that shows if blockage was triggered by ALN [TRUE, FALSE]\n
///        SPMData.SPMBlockageProbability : SPM blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blockage confidence [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentObjLossWeight : ObjectLoss observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentRangeWeight : Range observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentTimeoutWeight : Timeout observer weight [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Check blockage state. If blockage event was triggered then check each blockage observer (partial 
///                     blockage, range observer, timeout observer, object loss observer) and set the corresponding error 
///                     as inactive
/// @startuml "Call sequence for SPMSetObserversState"
///
/// spm -> spm_blockage : SPMProcess() calls SPMSetObserversState()
/// activate spm_blockage
///   spm_blockage --> spm :
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///
/// @traceability       
///
  void SPMSetObserversState(void);
#endif

/// @brief Check for selftest conditions and set selftest on passed if at least one of the conditions is meet.
///
/// @pre                Check if ego speed is greater than a minimum threshold, selftest is enabled or roller bench 
///                     tests is active.
/// @post               None
///
/// @param[in] pPerfDegrData : Performance degradation data from PD component
#if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
/// @param[in] fOwnspeed : Ego car speed [full range of float32]
#endif
/// @param[in] bRollerTestBenchState : Flag that shows if there are roller bench tests on going [TRUE, FALSE]
///
/// @return             void
///
/// @globals
///        SPMBlockageParameters.bEnableSelftest : Flag that shows if selftest is enabled or no [TRUE, FALSE]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeMov : Range for moving objects [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeSta : Range for stationary objects [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeStaMax : Maximum range for stationary objects 
///                                 [full range of float32]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeMovConf : Moving range confidence [0.0f ...1.0f]\n
///        SPMData.SPMSelftestInput.SPMSelftestRangeStaConf : Stationary range confidence [0.0f ... 1.0f]\n
///        SPMData.SPMSelftestState : Selftest current state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestStateLast : Selftest last state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestTimeCounter : Current time counter for selftest [full range of float32]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibility : Road visibility [0 ... 100]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibilityQuality : Road visibility quality [0 ... 100]\n
///
/// @InOutCorrelation   Copy the data from performance degradation data into internal data structure. Check if either 
///                     moving range, stationary range, or roadbeam if it is used, reached the minimum thresholds in 
///                     order to set selftest as passed. If the thresholds were not reached for any of the ranges or 
///.                    roadbeam then increase the time counter with cycle time. If the time counter reached the 
///                     considered threshold then set the selftest on off and continue to check for the selftest pass 
///                     conditions until selftest is passed.
/// @startuml "Call sequence for SPMSelftestDetermination"
///
/// spm_selftest -> spm_selftest : SPMSelftest() calls SPMSelftestDetermination(PerfDegr_t, float32, boolean)
/// activate spm_selftest
///   spm_selftest --> spm_selftest : 
/// deactivate spm_selftest
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-518-0006e2e0
///
void SPMSelftestDetermination (const PerfDegr_t *pPerfDegrData
                             #if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
                             , float32 fOwnspeed
                             #endif
                             , const boolean bRollerTestBenchState);

/// @brief Set all DEM Events concerning Blockage
///
/// @pre                None
/// @post               None
///
/// @param[out]         puiBlockageEvent : reference to blockage event  [AlgoErrorState_t as defined in Rte_Type.h]
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageState : SPM blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMSelftestState : SPM selftest state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///
/// @InOutCorrelation   Check blockage state. In case of GDB_NO_DAMP set all the blockage errors inactive and the
///                     blockage event also inactive if selftest was passed. In case of GDB_INC_DAMP set the increase 
///                     damp error active and rest of the errors inactive; the blockage event will also be set to 
///                     inactive if selftest was passed. In case of GDB_FULL_DAMP set the blockage error and blockage 
///                     event active; blockage event will be set only if selftest was passed. The other errors will be 
///                     set to inactive. In case of GDB_RDC_DAMP set the reduce damp error and blockage event active; 
///                     blockage event will be set to active if selftest was passed. Rest of blockage errors will be 
///                     set to inactive. In case of GDB_UNKNOWN_DAMP the blockage event will be set to active.
/// @startuml "Call sequence for SPMBlockageSetDEMEvents"
///
/// spm -> spm_blockage : SPMProcess() calls SPMBlockageSetDEMEvents(AlgoErrorState_t)
/// activate spm_blockage
///   spm_blockage -> spm : SPMBlockageSetDEMEvents(AlgoErrorState_t) calls SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
///   activate spm
///     spm --> spm_blockage : 
///   deactivate spm
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-497-0006e2e0
///
void SPMBlockageSetDEMEvents (AlgoErrorState_t *puiBlockageEvent);

/// @brief Fusion of range, timeout and object loss results to a single blockage probability
///
/// @pre                None
/// @post               None
///
/// @param[in]         pPerfDegrData : Performance degradation data from PD component
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageTimeoutTimeCounter : Timeout time counter [full range of float32]\n
///        SPMData.SPMBlockageTimeoutWayCounter : Timeout way counter [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m\n
///        SPMData.SPMBlockageObjLossProb : Object loss probability in SPMData [0.0f ... 1.0f]\n
///        SPMObjectLoss.fObjectLossProbability : Object loss probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageObjLossConf : Object loss confidence in SPMData [0.0f ... 1.0f]\n
///        SPMObjectLoss.fObjectLossConfidence :  Object loss confidence [0.0f ... 1.0f]
///        SPMBlockageParameters.fShutOffRange[SYS_NUM_OF_SCANS] : Range shutoff threshold for near and
///                                 far scan if used [full range of float32]\n
///        SPMBlockageParameters.fShutOnRange[SYS_NUM_OF_SCANS] : Range shuton threshold for near and
///                                 far scan if used[full range of float32]\n
///        SPMData.SPMScanRangeConfidencePrevious[SYS_NUM_OF_SCANS] : Range confidence for previous cycle [0.0f ... 1.0f]\n
///        SPMData.SPMScanRangeConfidence[SYS_NUM_OF_SCANS] : Current range confidence [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConfidenceGradient[SYS_NUM_OF_SCANS] : Gradient of range conficence [0.0f ... 1.0f]\n
///        SPMBlockageParameters.uUseFarNearScanForBlck : Usage of near or far scan for blockage[0u ... 1u]\n
///        SPMData.SPMBlockageRangeProb : Blockage range probability[0.0f ... 1.0f]\n
///        SPMBlockageParameters.fTimeoutWayThld : Timeout way shutoff thrreshold [full range of float32]\n
///        SPMBlockageParameters.fTimeoutTimeThld : Timeout time shutoff threshold [full range of float32]\n
///        SPMData.SPMBlockageTimeoutBlockProb : Timeout blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConf : Blockage range confidence [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageState : SPM blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMBlockageTimeoutBlockConf : Timeout blockage confidence[0.0f ... 1.0f]\n
///        SPMData.SPMCurrentObjLossWeight : ObjectLoss observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentRangeWeight : Range observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMCurrentTimeoutWeight : Timeout observer weight [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blockage confidence [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageProbability : SPM blockage probability [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Copy the data of all blockage observers into SPMData structure. Determine range and timeout
///                     observers probabilities by mapping of the observers data between the shutoff and shuton
///                     thresholds. Determine the observers weights based on observers probabilities and confidences.
///                     Fuse the observers probabilities and confidences into one blockage probability and one blockage
///                     confidence based on the weights computed.
/// @startuml "Call sequence for SPMDetermineBlockProb"
///
/// spm -> spm_blockage : SPMProcess() calls SPMDetermineBlockProb(PerfDegr_t)
/// activate spm_blockage
///   spm_blockage -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_blockage: 
///   spm_blockage -> spm_blockage : SPMFuseRangeScanDataNew(float32, float32, float32, float32)
///   spm_blockage -> spm_blockage : SPMMapRangeToProbability(PerfDegr_t, float32, float32, uint8)
/// spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-502-0006e2e0
///
void SPMDetermineBlockProb(const PerfDegr_t *pPerfDegrData);

/// @brief Determine blockage state
///
/// @pre                None
/// @post               None
///
///@param[in] pPerfDegrData : Performance degradation data from PD component
///
/// @return             void
///
/// @globals
///        SPMBlockageParameters.bEnableBlockage : Flag that shows if blockage is active [TRUE, FALSE]\n
///        SPMData.SPMSelftestState : SPM selftest state [GDB_PD_OFF...GDB_PD_ON as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMBlockageState : SPM blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMALNPartialDamp : Alignment partial blockage state 
///                   [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMFullBlockageTimer : Full blockage timer [Full range of float32]\n
///        SPMObjectLoss.uiNoOfObjLosses : Number of relevant objects lost and counted 
///                   [0 ...SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP]\n
///        SPMData.SPMBlockageRangeProb : Blockage range probability[0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConf : Blockage range confidence [0.0f ... 1.0f]\n
///        SPMData.bSPMPreventBlckIfHighTempNoRain : Flag for preventing blockage if high temperature and no rain detected [TRUE, FALSE]\n
///        SPMData.SPMBlockageProbability : PM blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blockage confidence [0.0f ... 1.0f]\n
///        SPMData.SPMSRDSysDamp : SRD blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMReactivationDelayTimer : Delay timer for system reactivation after SRR damping [full range of float32]\n
///
/// @InOutCorrelation   Determine the overall blockage state based on the blockage probability, the blockage confidence 
///                     and other external imputs like ALN or SRD damping state, if available.
/// @startuml "Call sequence for SPMDetermineBlockageState"
///
/// spm -> spm_blockage : SPMProcess() calls SPMDetermineBlockageState(PerfDegr_t)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : CheckDampConditionbyCamera(PerfDegr_t)
///   spm_blockage -> spm_blockage : CheckDampCondition(float32)
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test of Input-Output-Correlation (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-501-0006e2e0
///
void SPMDetermineBlockageState(//PRQA S 3001
                               #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
                                const PerfDegr_t *pPerfDegrData
                               #else
                                void
                               #endif
                              );
// PalloI, OlaruM; 11.08.2017, Reason: function has parameters when CBO is in use

#if(SPM_CHECK_MISSALIGNMENT)
/// @brief Check misaligment situation
///
/// @pre                None
/// @post               None
///
/// @param[in]           fTunnelProb : TunnelProbability
/// @param[in]           pPartialBlockage : Information about partial blockage
/// @param[in]           fOwnSpeed : Ego speed
///
/// @return             void
/// @globals
///        SPMData : SPM data\n
///
/// @InOutCorrelation   Check misalignment situation based on informations from partial blockage and camera.
///
/// @startuml "Call sequence for SPMCheckMissalignment"
///
/// spm -> spm_blockage : SPMProcess() calls SPMCheckMissalignment(fTunnelProb, pPartialBlockage, fOwnSpeed)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : SPMCheckCameraConfirmation(ObjNr)
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test of Input-Output-Correlation (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-581-0006e2e0       
///
void SPMCheckMissalignment(const float32 fTunnelProb, const PartialBlockage_t* pPartialBlockage, fSpeed_t fOwnSpeed);

/// @brief  Check if camera confirmation over gating
///
/// @pre                None
/// @post               None
///
/// @param[in]           ObjNr : Object index from OOI list
///
/// @return             boolean
///
/// @InOutCorrelation    Check if camera confirmation over gating
///
/// @startuml "Call sequence for SPMCheckCameraConfirmation"
///
/// spm_blockage -> spm_blockage : SPMCheckMissalignment() calls SPMCheckCameraConfirmation(ObjNr)
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test of Input-Output-Correlation (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-580-0006e2e0   
///
boolean SPMCheckCameraConfirmation(const ObjNumber_t ObjNr);
#endif

/// @brief Copy blockage parameters to internal parameters structure
///
/// @pre                None
/// @post               None
///
/// @param[in] ps_blockage_algo_parameters : Blockage structure parameters
/// @param[in] pPerfDegrData : Performance degradation data from PD component
/// @param[in] pAlignmentMonInput : Partial blockage data structure
///
/// @param[out] ps_blockage_internal_parameters : SPM internal structure parameters
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation   Take blockage parameters from algo parameters structure and copy them into internal SPM 
///                     blockage parameters structure. If the algo parameters are not available then replace the algo
///                     parameters with the hard coded blockage parameters defines.
/// @startuml "Call sequence for SPMSetBlockageParameters"
///
/// spm -> spm_blockage : SPMProcess() calls\nSPMSetBlockageParameters(SPMBlockageParameters_t, Fct_blockage_algo_parameters_t, PerfDegr_t)
/// activate spm_blockage
///   alt #Green SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_OFF
///     spm_blockage -> spm_blockage : SPMSetBlockageParametersUsingDefines(SPMBlockageParameters_t)
///   else SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON
///     spm_blockage -> spm_blockage : SPMSetShutOffRangeThresholds(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
///     spm_blockage -> spm_blockage : SPMSetShutOnRangeThresholds(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
///     spm_blockage -> spm_blockage : SPMSetShutOffTimeoutThreshold(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
///   end
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test order of calls (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-520-0006e2e0
///
void SPMSetBlockageParameters(SPMBlockageParameters_t *ps_blockage_internal_parameters,
                              const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters
                              #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER)
                              , const PerfDegr_t *pPerfDegrData
                              #endif
                              #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON)
                               , const ALN_S_Monitoring_t * pAlignmentMonInput
                              #endif
                              );

#if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON)
/// @brief Set shuton thresholds for range observer
///
/// @pre                None
/// @post               None
///
/// @param[in] ps_blockage_algo_parameters : Blockage structure parameters
/// @param[in] pAlignmentMonInput : Partial blockage data structure
///
/// @param[out] ps_blockage_internal_parameters : SPM internal structure parameters
///
/// @return             boolean : Flag that indicates if BSW parameters were used or not
///
/// @globals            None
///
/// @InOutCorrelation   Based on algo parameters which are took from BSW and stored in ps_blockage_algo_parameters 
///                     set the range observer shuton thresholds in ps_blockage_internal_parameters. If the BSW 
///                     parameters are available and camera quality is over 90% then set the shuton thresholds of range 
///                     observer dynamic based on camera ratio and BSW parameter provided. Otherwise use the parameter 
///                     from BSW. If the BSW parameters are not available set the shuton parameters for range observer 
///                     using hardcoded defines. If camera observer is used and camera quality is over 90% then set the 
///                     shuton thresholds dynamic based on camera ratio and hardcoded define for shuton.Otherwise set 
///                     the shuton threshold using only the hardcoded define. Shuton range parameters are set for eacn 
///                     scan independent. If BSW parameters were used to set the shutoff thresholds then set the 
///                     returning flag on TRUE, otherwise set the flag on FALSE.
/// @startuml "Call sequence for SPMSetShutOnRangeThresholds"
///
/// spm_blockage -> spm_blockage : SPMSetBlockageParameters() calls\nSPMSetShutOnRangeThresholds(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : SPMGetThreshold(uint8, uint8)
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-525-0006e2e0
///
  boolean SPMSetShutOnRangeThresholds(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters,
                                      SPMBlockageParameters_t *ps_blockage_internal_parameters);

/// @brief Set shutoff thresholds for range observer
///
/// @pre                None
/// @post               None
///
/// @param[in] ps_blockage_algo_parameters : Blockage structure parameters
/// @param[in] pAlignmentMonInput : Partial blockage data structure
///
/// @param[out] ps_blockage_internal_parameters : SPM internal structure parameters
///
/// @return             boolean : Flag that indicates if BSW parameters were used or not
///
/// @globals            None
///
/// @InOutCorrelation   Based on algo parameters which are took from BSW and stored in ps_blockage_algo_parameters 
///                     set the timeout shutoff thresholds in ps_blockage_internal_parameters. If the BSW parameters 
///                     are available and camera quality is over 90% then set the shutoff thresholds of timeout 
///                     observer dynamic based on camera ratio and BSW parameter provided. Otherwise use the parameter 
///                     from BSW. If the BSW parameters are not available set the shutoff parameters for timeout 
///                     observer using hardcoded defines. If camera observer is used and camera quality is over 90% 
///                     then set the shutoff thresholds dynamic based on camera ratio and hardcoded define for shutoff.
///                     Otherwise set the shutoff threshold using only the hardcoded define. Shutoff range parameters 
///                     are set for each scan independent. If BSW parameters were used to set the shutoff thresholds 
///                     then set the returning flag on TRUE, otherwise set the flag on FALSE.
/// @startuml "Call sequence for SPMSetShutOffRangeThresholds"
///
/// spm_blockage -> spm_blockage : SPMSetBlockageParameters() calls\nSPMSetShutOffRangeThresholds(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : SPMGetThreshold(uint8, uint8)
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test of code coverage (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-523-0006e2e0
///
  boolean SPMSetShutOffRangeThresholds(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters,
                                       SPMBlockageParameters_t *ps_blockage_internal_parameters);

/// @brief Set the shutoff thresholds for timeout observer
///
/// @pre                None
/// @post               None
///
/// @param[in] ps_blockage_algo_parameters : Blockage structure parameters
/// @param[in] pAlignmentMonInput : Partial blockage data structure
///
/// @param[out] ps_blockage_internal_parameters : SPM internal structure parameters
///
/// @return             boolean : Flag that indicates if BSW parameters were used or not
///
/// @globals            None
///
/// @InOutCorrelation   Based on algo parameters which are took from BSW and stored in ps_blockage_algo_parameters 
///                     set the range observer shutoff thresholds in ps_blockage_internal_parameters. If the BSW 
///                     parameters are available and camera quality is over 90% then set the shutoff thresholds of 
///                     range observer dynamic based on camera ratio and BSW parameter provided. Otherwise use the 
///                     parameter from BSW. If the BSW parameters are not available set the shutoff parameters for 
///                     range observer using hardcoded defines. If camera observer is used and camera quality is over 
///                     90% then set the shutoff thresholds dynamic based on camera ratio and hardcoded define for 
///                     shutoff. Otherwise set the shutoff threshold using only the hardcoded define. If BSW parameters 
///                     were used to set the shutoff thresholds then set the returning flag on TRUE, otherwise set the 
///                     flag on FALSE.
/// @startuml "Call sequence for SPMSetShutOffTimeoutThreshold"
///
/// spm_blockage -> spm_blockage : SPMSetBlockageParameters() calls\nSPMSetShutOffTimeoutThreshold(Fct_blockage_algo_parameters_t, SPMBlockageParameters_t, PerfDegr_t)
/// activate spm_blockage
///    spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-524-0006e2e0
///
  boolean SPMSetShutOffTimeoutThreshold(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters,
                                       SPMBlockageParameters_t *ps_blockage_internal_parameters);

/// @brief Compute and return the shuton or shutoff threshold.
///
/// @pre                Camera quality over 90%
/// @post               None
///
/// @param[in] uThldNeed : Type of threshold needed - shuton threshold or shutoff threshold.
/// @param[in] uScanIndex : Index of the scan for which the threshold is computed.
///
/// @return             float32 : Computed shuton of shutoff threshold for the current scan.\n
///
/// @globals            None
///
/// @InOutCorrelation   Given a type of threshold needed(shuton or shutoff threshold) and the index of the scan needed
///                     the function computes and returns the desired threshold using the hard coded defines of the
///                     shuton/shutoff thresholds of SPM.
/// @startuml "Call sequence for SPMGetThreshold"
///
/// spm_blockage -> spm_blockage : SPMSetShutOnRangeThresholds() calls SPMGetThreshold(uint8, uint8)\n SPMSetShutOffRangeThresholds() calls SPMGetThreshold(uint8, uint8)
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of Input-Output-Correlation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-510-0006e2e0
///
  float32 SPMGetThreshold(uint8 uThldNeed, uint8 uScanIndex);
#endif

#if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_OFF)
/// @brief Set the blockage parameters using hardcoded defines.
///
/// @pre                Blockge algo parameters pointer is not null.
/// @post               None
///
/// @param[out] ps_blockage_internal_parameters : SPM internal structure parameters
///
/// @return             void
///
/// @globals            None
///
/// @InOutCorrelation   Given a type of threshold needed(shuton or shutoff threshold) and the index of the scan needed
///                     the function computes and returns the desired threshold using the hard coded defines of the
///                     shuton/shutoff thresholds of SPM.
/// @startuml "Call sequence for SPMSetBlockageParametersUsingDefines"
///
/// spm_blockage -> spm_blockage : SPMSetBlockageParameters() calls SPMSetBlockageParametersUsingDefines(SPMBlockageParameters_t)
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-521-0006e2e0
///
  void SPMSetBlockageParametersUsingDefines(SPMBlockageParameters_t *ps_blockage_internal_parameters);
#endif

/// @brief Check the necessary condition for blockage state machine transition
///
/// @pre                None
/// @post               None
///
/// @param[in]          fProbFactor : Blockage probability scaling factor [0.0f ... 1.0F]
///
/// @return             boolean : Falg that show if damping conditions were met or not
///
/// @globals
///        SPMBlockageParameters.bUseRoadbeam[SYS_NUM_OF_SCANS] : Boolean array that shows if road beam 
///                   for near scan or far scan is used [TRUE, FALSE]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibilityQuality : Roadbeam data quality 
///                   for each scan [0 ...100]\n
///        SPMData.SPMBlockageProbability : SPM blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blockage confidence [0.0f ... 1.0f]\n
///        SPMBlockageParameters.fRoadbeamSpeedMin[SYS_NUM_OF_SCANS] : Speed thresholds for each scan
///                   [full range of float32]\n
///        SPMBlockageParameters.uRoadVisibilityQualityThresh[SYS_NUM_OF_SCANS] : Roadbeam data quality 
///                   thresholds for each scan [0 ... 100]\n
///        SPMBlockageParameters.uRoadVisibilityThresh[SYS_NUM_OF_SCANS] : Roadbeam data vilibility 
///                   thresholds for each scan [0 ... 100]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibility : Roadbeam data vilibility for 
///                   each scan [0 ... 100]\n
///
/// @InOutCorrelation   Based on the probability factor check if the necessary conditions are met in order to change 
///                     the current blockage state. If available consider also the roadbeam data when taking the 
///                     decision of changing the blockage state.
/// @startuml "Call sequence for CheckDampCondition"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockageState() calls CheckDampCondition(float32)
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test for memory access violation (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-490-0006e2e0
///
boolean CheckDampCondition(const float32 fProbFactor);

/// Map range data into probability and condidence
///
/// @pre                 None
/// @post                None
///
/// @param[in] pPerfDegrData : Performance degradation data from PD component
/// @param[in] ShutOffValue : Range shut off threshold [full range of float32]
/// @param[in] ShutOnValue : Range shut on threshold [full range of float32]
/// @param[in] uScanIndex : Current scan index [SYS_SCAN_NEAR, SYS_SCAN_FAR]
///
/// @return              float32 : Probability resulted by mapping range data
///
/// @globals             None
///
/// @InOutCorrelation    Map the range data for a specific scan between the shut on and shut off values and compute a 
///                      probability between 0 and 1.
/// @startuml "Call sequence for SPMMapRangeToProbability"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockProb() calls SPMMapRangeToProbability(PerfDegr_t, float32, float32, uint8)
/// activate spm_blockage
///   spm_blockage -> cml_ecu_emul : CML_f_Min(float32, float32)
///   cml_ecu_emul --> spm_blockage : 
///   spm_blockage -> cml_misc : CML_f_MinMax(float32, float32, float32)
///   cml_misc --> spm_blockage : 
///   spm_blockage -> cml_interpol : CML_f_BoundedLinInterpol3(CML_t_Point2D, CML_t_Point2D, float32)
///   cml_interpol --> spm_blockage : 
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-513-0006e2e0
///
float32 SPMMapRangeToProbability( const PerfDegr_t *pPerfDegrData, const float32 ShutOffValue, const float32 ShutOnValue, const uint8 uScanIndex);

#if(ALGO_CFG_FarScanAvailable)
  #if(SPM_USE_AREA_CONVOLUTION_FOR_RANGE_FUSION == SWITCH_ON)
/// Fuse the near/far range  probability and confidence into blockage range probability and blockage range confidence
///
/// @pre                None
/// @post               None
///
/// @param[in] fNearRangeProbability : Near scan range probability [0.0f ... 1.0f]
/// @param[in] fFarRangeProbability : Far scan range probability [0.0f ... 1.0f]
/// @param[in] fNearRangeConfidence : Near scan range confidence [0.0f ... 1.0f]
/// @param[in] fFarRangeConfidence :  Far scan range confidence [0.0f ... 1.0f]
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageRangeProb : Blocakge range probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConf : Blocakge range confidence [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Compute the fusion coeficient alpha_1 and alpha 2 and fuse the probabilities/confidence by using \n 
///                     the following formula: \n
///                        fused value = (alpha_1 * near value +alpha_2 * far value) /(alpha_1 +alpha_2)\n
///                     if alpha_1 +alpha_2 = 0 then \n
///                        fused value = (near value + far value)/ 2 \n
/// @startuml "Call sequence for SPMFuseRangeScanDataUsingAreaConvolution"
///
/// spm_blockage -> spm_blockage :SPMDetermineBlockProb() calls\nSPMFuseRangeScanDataUsingAreaConvolution(float32, float32, float32, float32)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : SPMComputationOfFusionCoef(float32, float32)
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test for arithmetic errors (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-508-0006e2e0
///
    void SPMFuseRangeScanDataUsingAreaConvolution(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence);

/// Fuse the near/far range  probability and confidence into blockage range probability and blockage range confidence
///
/// @pre                None
/// @post               None
///
/// @param[in] fProbability : Near/Far scan range probability [0.0f ... 1.0f]
/// @param[in] fConfidence :  Near/Far scan range confidence [0.0f ... 1.0f]
///
/// @return             float32 : the fusion coeficient
///
/// @globals
///
/// @InOutCorrelation   The fusion coeficient is computed by using the following formula: \n 
///                     if fProbability >= fConfidence then \n
///                           fCoeficient = fConfidence * fConfidence \n
///                     else \n
///                           fCoeficient = fProbability * (2* fConfidence -fProbability)\n
///                     if probability is invalid(= -1.0F) then the coeficient is set to zero.\n
/// @startuml "Call sequence for SPMComputationOfFusionCoef"
///
/// spm_blockage -> spm_blockage : SPMFuseRangeScanDataUsingAreaConvolution() calls SPMComputationOfFusionCoef(float32, float32)
/// activate spm_blockage
///   spm_blockage -> cml_misc : CML_f_IsNonZero(float32)
///   cml_misc --> spm_blockage : 
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test for arithmetic errors (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-499-0006e2e0
///
    float32 SPMComputationOfFusionCoef(const float32 fProbability, const float32 fConfidence);
  #else
/// Fuse the near/far range  probability and confidence into blockage range probability and blockage range confidence
///
/// @pre                None
/// @post               None
///
/// @param[in] fNearRangeProbability : Near scan range probability [0.0f ... 1.0f]
/// @param[in] fFarRangeProbability : Far scan range probability [0.0f ... 1.0f]
/// @param[in] fNearRangeConfidence : Near scan range confidence [0.0f ... 1.0f]
/// @param[in] fFarRangeConfidence :  Far scan range confidence [0.0f ... 1.0f]
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageRangeProb : Blocakge range probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConf : Blocakge range confidence [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Check for near and far scan range probability and confidences. If near range confidence and 
///                     probability is greater than far range probability and confidence then take the near scan data. 
///                     Otherwise take the far scan data. If near range probability is greater than far range 
///                     probability, near range confidence is lower than far range condidence and near confidence is 
///                     below the threshold of 40% then take the near range data. Otherwise fuse near and far scan 
///                     range probability and confidence. If near range probability is lower than far range probability, 
///                     near range confidence is greater than far range confidence then take far scan data. Otherwise 
///                     fuse near and far scan range probability and confidence.
/// @startuml "Call sequence for SPMFuseRangeScanDataNew"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockProb() calls SPMFuseRangeScanDataNew(float32, float32, float32, float32)
/// activate spm_blockage
///   spm_blockage -> spm_blockage : SPMStandardDeviationFuse(float32, float32, float32, float32)
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test order of calls (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-507-0006e2e0
///
void SPMFuseRangeScanDataNew(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence);

/// @brief Fuse the near/far range probability and confidence into blockage range probability and blockage range confidence by 
/// calculating the standard deviation.
///
/// @pre                Check if near of far range confidence is lower than 40%
/// @post               None
///
/// @param[in] fNearRangeProbability : Near scan range probability [0.0f ... 1.0f]
/// @param[in] fFarRangeProbability : Far scan range probability [0.0f ... 1.0f]
/// @param[in] fNearRangeConfidence : Near scan range confidence [0.0f ... 1.0f]
/// @param[in] fFarRangeConfidence :  Far scan range confidence [0.0f ... 1.0f]
///
/// @return             void
///
/// @globals
///        SPMData.SPMBlockageRangeProb : Blockage range probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageRangeConf : Blockage range confidence [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Compute the sum of confidences and take the maximim from the two confidences. If the sum of 
///                     confidences is positive then compute a mean of near and far range probabilities and confidences. 
///                     Then compute the sigma and set the blockage range probability and confidence based on the 
///                     maximum confidence and sigma computed.
/// @startuml "Call sequence for SPMStandardDeviationFuse"
///
/// spm_blockage -> spm_blockage : SPMFuseRangeScanDataNew() calls SPMStandardDeviationFuse(float32, float32, float32, float32)
/// activate spm_blockage
///   spm_blockage -> cml_ecu_emul : CML_f_Max(float32, float32, float32)
///   cml_ecu_emul --> spm_blockage : 
///   spm_blockage -> cml_misc : CML_Sqr(float32)
///   cml_misc --> spm_blockage : 
///   spm_blockage -> cml_ecu_emul : CML_f_Sqrt(float32)
///   cml_ecu_emul --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test for arithmetic errors (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-526-0006e2e0
///
    void SPMStandardDeviationFuse(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence);
  #endif
#endif

#if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
/// @brief Check camera observer damping conditions
///
/// @pre                None
/// @post               None
///
/// @param[in]          pPerfDegrData : Performance degradation data from PD component
///
/// @return             boolean : Flag that indicates if camera detected damping conditions\n
///
/// @globals            None
///
/// @InOutCorrelation   Check if camera detects objects and radar does not detect objects or target rate on one of the 
///                     used scans is lower than the used threshold(0.2) or relevant object was deselected for more 
///                     than two cycles or there are objects lost and set the return flag on true if one of the 
///                     conditions is met.
/// @startuml "Call sequnece for CheckDampConditionbyCamera"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockageState() calls CheckDampConditionbyCamera(PerfDegr_t)
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)\n
///                     Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-491-0006e2e0
///
  boolean CheckDampConditionbyCamera(const PerfDegr_t *pPerfDegrData);
#endif

#if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
/// Check if relevant object changed to another OOI
///
/// @pre                None
/// @post               None
///
/// @return             boolean : Flag that indicates if relevant object was switched to another OOI object
///
/// @globals            SPMData.SPMLastRelObjID : Last valid ID of relevant object 
///                            [full range of ObjNumber_t as defined in Rte_Type.h]\n
///
/// @InOutCorrelation   Check if relevant object was switched to another OOI object and set the returning flag to TRUE 
///                     in case it was or FALSE in case that relevant object was not switched to another OOI
/// @startuml "Call sequence for CheckIfRelevantObjChangedToNeighbour"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockProb() calls CheckIfRelevantObjChangedToNeighbour()
/// activate spm_blockage
///   spm_blockage --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-492-0006e2e0
///
  boolean CheckIfRelevantObjChangedToNeighbour(void);
#endif

#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM)||(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
/// @brief Set SPM provide ports based on FCT_SEN provide ports
///
/// @pre                None
/// @post               None
///
/// @param[in]          pPerfDegrData : Performance degradation data from PD component
///
/// @return             void
///
/// @globals
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibility : Roadbeam visibility for each 
///                   scan [full range of uint8]\n
///        SPMData.SPMRoadbeamInput[SYS_NUM_OF_SCANS].SPMRoadVisibilityQuality : Rodabeam quality for 
///                   each scan [full range of uint8]\n
///
/// @InOutCorrelation   Copy the roadbeam data from performance degradation data structure to SPMData internal 
///                     structure
/// @startuml "Call sequence for SPMGetRoadBeamData"
///
/// spm -> spm_blockage : SPMProcess() calls SPMGetRoadBeamData(PerfDegr_t)
/// activate spm_blockage
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of memory corruption (dynamic module test)\n
///                     Test for memory access violation (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-509-0006e2e0
///
  void SPMGetRoadBeamData(const PerfDegr_t *pPerfDegrData);
#endif

#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
/// @brief Analyse and set SRR blockage data
///
/// @pre                None
/// @post               None
///
/// @param[in]          SRDDampState : SRD blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]
///
/// @return             void
///
/// @globals
///        SPMData.SPMSRDSysDamp : SRD blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SRDDampingState.PreviousState : SRD previous blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SRDDampingState.CurrentState : SRD current blockage state [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMBlockageProbability : SPM blockage probability [0.0f ... 1.0f]\n
///        SPMData.SPMBlockageConfidence : SPM blockage confidence [0.0f ... 1.0f]\n
///
/// @InOutCorrelation   Copy SRD damping state to the SPMData structure. Copy the SRDDampingState.CurrentState into the
///                     SRDDampingState.PrevioustState. Set SRDDampingState.CurrentState based on SPMData.SPMSRDSysDamp,
///                     Blockage probability and confidence.
/// @startuml "Call sequence for SPMProcessPreblockage"
///
/// spm -> spm_blockage : SPMProcess() calls SPMProcessPreblockage(SYSDampState_t)
/// activate spm_blockage
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-516-0006e2e0
///
  void SPMProcessPreblockage(SYSDampState_t SRDDampState);
#endif

#if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
/// @brief Check for partial blockage conditions
///
/// @pre                None
/// @post               None
///
/// @param[in] eAlignState : State of the alignment component [e_AlignState_t as in Rte_Type.h]
/// @param[in] fOwnSpeed : Ego car speed [-100.F ... 100.F]
///
/// @return             void
///
/// @globals
///        SPMData.SPMALNPartialDamp : Alignment partial blockage state 
///                   [GDB_NO_DAMP...GDB_UNKNOWN_DAMP as defined in Rte_Algo_Type.h]\n
///        SPMData.SPMALNPartialDampDelayTimer : Partial damping delay reactivation timer [0.0f ... 120.0f]\n
///
/// @InOutCorrelation   Check for align state and set partial blockage if partial blockage is reported by Alignment and 
///                     it was not set before. If the reactivation conditions are met for partial blockage then set 
///                     partial blockage to NO_DAMP. Otherwise subtract cycle time from delay timer.
/// @startuml "Call sequence for SPMALNPartialBlockageState"
///
/// spm -> spm_blockage : SPMProcess() calls SPMALNPartialBlockageState(e_AlignState_t, fSpeed_t)
/// activate spm_blockage
///   spm_blockage --> spm : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-495-0006e2e0
///
  void SPMALNPartialBlockageState(const e_AlignState_t eAlignState, const fSpeed_t fOwnSpeed);
#endif

#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
/// @brief Check if partial blocakge probability and confidence meets the thresholds
///
/// @pre                None
/// @post               None
///
/// @param[in] f_Probability : Partial blockage probability [0.0F ... 1.0F]
/// @param[in] f_Confidence : Partial blockage confidence [0.0F ... 1.0F]
///
/// @return             void
///
/// @globals
///          SPMData.SPMFullBlockageGenByALN : Flag that shows if partial blockage was triggered [TRUE, FALSE]
///
/// @InOutCorrelation   Check if partial blockage probability and confidence meet the thresholds. If they meet the 
///                     the threshold then set the partial blockage flag to TRUE. Otherwise set it on false.
/// @startuml "Call sequence for SPMALNPartialBlockage"
///
/// spm -> spm_blockage : SPMProcess() calls SPMALNPartialBlockage(float32, float32)
/// activate spm_blockage
///   spm_blockage -> cml_misc : CML_f_IsZero(float32)
///   cml_misc --> spm_blockage : 
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-494-0006e2e0
///
  void SPMALNPartialBlockage(float32 f_Probability, float32 f_Confidence);
#endif


/// @brief Generate and communicate interference data to DEM component
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        GDB_CYCLE_MODE : The EM-FCT cycle mode   [eCycleMode_t as defined in Rte_Type.h]\n
///        RSP_GET_DATA_RANGE : Noise range estimated in performance degradation (EM) [full range of datatype float32]\n
///        GET_PERF_DEG_DATA_PTR->bNoiseRangeValid  [TRUE, FALSE]\n
///        fEgoSpeed : Ego speed used locally in SPM module, data type is alias for fVelocity_t [-100.F ... 100.F]\n
///        SPMData.SPMInterferenceRange : Interference range [full range of data type float32]\n
///        SPMData.SPMInterference : Interference on number of cycles before [full range of data type uint32]\n
///        SPMData.SPMInterferenceHoldCnt : Interference range hold count [full range of data type float32 > 0.F]\n
///        SPMData.SPMInterferenceState : Flag to show it interference was or was not detected [TRUE, FALSE]\n
///        fLastRelevantObjectDistance : X distance of the last relevant moving object seen [-500.f ... 500.f]\n
///
/// @InOutCorrelation   Generate and communicate interference data to DEM component, based on interference range 
///                     received from EM and Object loss reason evaluated in SI
/// @startuml "Call sequence for SPMInterferenceRange"
///
/// spm -> spm_interference : SPMProcess() calls SPMInterference()
/// activate spm_interference
///   spm_interference -> cml_misc : CML_f_IsNonZero(float32)
///   cml_misc --> spm_interference : 
///   spm_interference -> cml_misc : CML_f_Min(float32, float32)
///   cml_misc --> spm_interference : 
///   spm_interference -> cml_misc : CML_f_MinMax(float32, float32, float32)
///   cml_misc --> spm_interference : 
///   spm_interference -> spm : SPMSetErrorState(SPMErrorEvents_t, AlgoErrorState_t)
///   spm --> spm_interference : 
///   spm_interference --> spm : 
/// deactivate spm_interference
/// @enduml
///
/// @testmethod         Test of code coverage (dynamic module test)\n
///                     Test for arithmetic errors (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-512-0006e2e0
///
void SPMInterferenceRange (void);

#if (FCT_CFG_CUSTOM_IO_INTERFACE == SWITCH_ON)
/// @brief Process custom specific SPM functionalities
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        FCTSEN_pCustomOutput : Reference to Custom Output structure\n
///
/// @InOutCorrelation   Process custom specific SPM functionalities. Set SPM custom output
/// @startuml "Call sequence for SPM_v_CustomProcess"
///
/// spm -> spm_output : SPMProcess() calls SPM_v_CustomProcess()
/// activate spm_output
///   spm_output -> spm_output : SPM_v_SetCustomOuput(FCTCustomOutput_t)
///   spm_output --> spm : 
/// deactivate spm_output
/// @enduml
///
/// @testmethod         Test order of calls (dynamic module test)
///
/// @traceability       doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-493-0006e2e0
///
  void SPM_v_CustomProcess(void);
#endif

#if(SPM_DELAY_REACTIVATION == SWITCH_ON)
/// @brief Set blockage delay reactivation counter
///
/// @pre                None
/// @post               None
///
/// @return             void
///
/// @globals
///        SPMData.SPMDelayReactivationTimer - Delay reactivation timer
///        SPMData.bSPMDelayTimerSet - Flag that shows if timer was set
///
/// @InOutCorrelation   Set SPMDelayReactivationTimer with 10s.
///                     bSPMDelayTimerSet is set with TRUE.
/// @startuml "Call sequence for SPM_v_SetDelayCounter"
///
/// spm_blockage -> spm_blockage : SPMDetermineBlockageState() calls SPM_v_SetDelayCounter(void)
/// activate spm_blockage
///   spm_blockage --> spm_blockage :
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod         
///
/// @traceability       
///
  void SPM_v_SetDelayCounter(void);
#endif

#if((SPM_USE_WEATHER_SIGNALS_FOR_BLOCKAGE == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= 13))
/// @brief Compute help factor based on weather type
///
/// @pre                None
/// @post               None
/// @param[in]          uCameraWeatherTypeProb : information from camera
/// @return             float32 : help factor based on weather signals
///
/// @globals            None
///
/// @InOutCorrelation    Compute parameters update factor based on camera weather signals:
///                      snow probability, rain probability, fog probability and spray probability.
///
/// @startuml "Call sequence for SPM_f_ComputeHelpFactorBasedWeather"
///
/// spm_blockage -> spm_blockage : SPM_f_ComputeWeatherFactor() calls\n SPM_f_ComputeHelpFactorBasedWeather(WeatherTypeProb)
/// activate spm_blockage
///   spm_blockage --> spm_blockage:
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod
///
/// @traceability
///
  float32 SPM_f_ComputeHelpFactorBasedWeather(uint8 uCameraWeatherTypeProb);

/// @brief Compute factor for dynamic thresholds based weather signals
///
/// @pre                None
/// @post               None
///
/// @param[in] pPerfDegr->Blockage.uWeatherFrCameraSprayProb : road spray information from camera
/// @param[in] pPerfDegr->Blockage.uWeatherFrCameraFogProb : fog information from camera
/// @param[in] pPerfDegr->Blockage.uWeatherFrCameraSnowfallProb : snowfall information from camera
/// @param[in] pPerfDegr->Blockage.uWeatherFrCameraRainProb : rain information from camera
///
/// @param[out] None
///
/// @return             float32 : parameters update factor based on weather signals
///
/// @globals            None
///
/// @InOutCorrelation    Compute parameters update factor based on camera weather signals:
///                      snow probability, rain probability, fog probability and spray probability.
///                      Factor computed is limited in between 1.0F and 1.25F and includes all weather
///                      information.
///
/// @startuml "Call sequence for SPM_f_ComputeWeatherFactor"
///
/// spm -> spm_blockage : SPM_v_ComputeParametersUpdateFactor() calls\n SPM_f_ComputeWeatherFactor(pPerfDegr)
/// activate spm_blockage
///   spm_blockage --> spm :
/// deactivate spm_blockage
/// @enduml
///
/// @testmethod
///
/// @traceability
///
  float32 SPM_f_ComputeWeatherFactor(const PerfDegr_t * pPerfDegr);
#endif

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
  /// @brief Get blockage level based on SPM computed data
  ///
  /// @pre        None
  /// @post       None
  ///
  /// @globals
  ///         SPMData.bSPMPreventBlckIfHighTempNoRain : Flag for preventing blockage if high temperature and no rain detected [TRUE, FALSE]\n
  ///         SPMData.fParametersUpdateFactor : Blockage parameters update factor [1.0F ... 1.25F]
  ///         SPMData.fBlkLvlDebounceTimer : Blockage level debounce timer [0.0F ... 5.0F]
  ///
  /// @return     BlockageType_t : Blockage level computed. [0U ... 2U], [255U]
  ///
  /// @InOutCorrelation    Compute and return blockage level based on parameters update factor
  ///                      and data about rain and outside temperature. If " bSPMPreventBlckIfHighTempNoRain" is true
  ///                      then LATE BLOCKAGE is set. If "fParametersUpdateFactor" is greater than 1.0F then EARLY BLOCKAGE
  ///                      is set. Otherwise NORMAL BLOCKAGE is set as output.
  ///
  /// @startuml "Call sequence for SPM_v_GetBlockageType"
  ///
  /// spm -> spm : SPMFillSenErrors() calls\n SPM_t_GetBlockageType(pPerfDegr)
  /// activate spm
  ///   spm --> spm :
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod
  ///
  /// @traceability
  ///
  void SPM_v_SetBlockageType(void);
#endif

#if((SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON) && (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON))
  /// @brief Compute partial blockage level based on ALN input.
  ///
  /// @pre        None
  /// @post       None
  ///
  /// @param[in]  pAlignmentMonInput->PartialBlockage.f_Confidence: Partial blockage confidence. Range: [0 ... 100]
  ///
  /// @globals    SPMData.SPMFullBlockageGenByALN: Flag that shows if blockage is triggered by ALN. Range: {TRUE, FALSE}
  ///             SPMData.PartialBlockageLevel: Partial blockage level. Range: [0 ... 2], {255}
  ///             SPMData.fALNFactor: Parameters update factor computed based on ALN information. Range:[1.0F ... 1.25F]
  ///
  /// @return     void
  ///
  /// @InOutCorrelation   Compute partial blockage level based on ALN input. SPMData.SPMFullBlockageGenByALN is FALSE
  ///                     then NO PARTIAL BLOCKAGE is set. If SPMData.SPMFullBlockageGenByALN is TRUE
  ///                     then FULL PARTIAL BLOCKAGE is set. If partial blockage confidence is 0.0F, then UNKNOWN PARTIAL
  ///                     BLOCKAGE is set.
  ///
  /// @startuml "Call sequence for SPM_f_ComputeWeatherFactor"
  ///
  /// spm -> spm : SPMProcess() calls\n SPM_u_ComputePartialBlockageLevel()
  /// activate spm
  ///   spm --> spm :
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod
  ///
  /// @traceability
  ///
void SPM_v_ComputePartialBlockageLevel(const ALN_S_Monitoring_t *pAlignmentMonInput);
#endif

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
/// @brief Compute blockage category based on weather signals.
///
/// @pre        None
/// @post       None
///
/// @param[in]          pPerfDegr->Blockage.bSummerParameterset : Flag that show if summer was detected(temperature over 5 degree). Range: {TRUE, FALSE}
/// @param[in]          pPerfDegr->Blockage.uWeatherFrCameraSprayProb: Spray probability. Range: [0 ... 100]
/// @param[in]          pPerfDegr->Blockage.uWeatherFrCameraFogProb: Fog probability. Range: [0 ... 100]
/// @param[in]          pPerfDegr->Blockage.uWeatherFrCameraRainProb: Rain probability. Range: [0 ... 100]
/// @param[in]          pPerfDegr->Blockage.uWeatherFrCameraSnowfallProb: Snow probability. Range: [0 ... 100]
/// @param[in]          pPerfDegr->Blockage.
///
/// @globals     SPMData.BlockageCategory: Blockage category computed based on weather signals. Range: [0 ... 3], {255}
///
/// @return     void
///
/// @InOutCorrelation   Compute blockage category based on weather signals.
///                     If blockage is triggered, temperature is over 5 degree and spray/rain/fog is detected
///                     then blockage is temporary. If temperature is below 5 degree and snow/rain is detected
///                     then blockage is permanent but cleaning. If sensor deadjusted flag is set then blockage
///                     is permanent and not cleaning
///
/// @startuml "Call sequence for SPM_v_ComputeBlockageCategory"
///
/// spm -> spm : SPMProcess() calls\n SPM_v_ComputeBlockageCategory(pPerfDegr)
/// activate spm
///   spm --> spm :
/// deactivate spm
/// @enduml
///
/// @testmethod
///
/// @traceability
///
void SPM_v_ComputeBlockageCategory(const PerfDegr_t *pPerfDegr);
#endif

/// @brief Compute parameters update factor
///
/// @pre                None
/// @post               None
///
/// @param[in] pPerfDegrData : Performance degradation data computed in EM/PD
/// @param[in] pPerfDegrData->Camera.fQuality : Camera quality. [0.0F ... 1.0F]
/// @param[in] pPerfDegrData->Camera.fRatio : Camera Ratio. [0.0F ... 1.0F]
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
/// @param[in] pAlignmentMonInput : ALN input to SPM
/// @param[in] pAlignmentMonInput->PartialBlockage.f_Confidence : Partial blockage confidence. [0.0F ... 1.0F]
/// @param[in] pAlignmentMonInput->PartialBlockage.f_Probability : Partial blockage probability. [0.0F ... 1.0F]
#endif
///
/// @return             void
///
/// @globals
///
/// @InOutCorrelation   Compute parameters update factor based camera input, ALN input and
///                     weather signals if features are active.
///
/// @startuml "Call sequence for SPM_v_ComputeParametersUpdateFactor"
///
/// spm -> spm : SPMProcess() calls SPM_v_ComputeParametersUpdateFactor(pPerfDegrData, pPerfDegrData)
/// activate spm
///   spm --> spm :
/// deactivate spm
/// @enduml
///
/// @testmethod
///
/// @traceability
///
void SPM_v_ComputeParametersUpdateFactor(const PerfDegr_t * pPerfDegrData
                                         #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
                                         , const ALN_S_Monitoring_t *pAlignmentMonInput
                                         #endif
                                        );

/// @brief Initialize parameters update factor.
///
/// @pre        None
/// @post       None
///
/// @globals     SPMData.fALNFactor: Factor computed based on ALN input. Rage: {1.0F}
/// @globals     SPMData.fFactorCBO: Factor computed based on camera input. Range: {1.0F}
/// @globals     SPMData.fParametersUpdateFactor: Factor computed for update blockage parameters. Range: {1.0F}
///
/// @return     void
///
/// @InOutCorrelation   Iitialize parameters update factor, CBO factor and ALN factor with default values.
///
/// @startuml "Call sequence for SPM_v_InitParametersFactors"
///
/// spm -> spm : SPM_v_ComputeParametersUpdateFactor() calls\n SPM_v_InitParametersFactors(void)\nSPM_v_Init() calls SPM_v_InitParametersFactors(void)
/// activate spm
///   spm --> spm :
/// deactivate spm
/// 
/// @enduml
///
/// @testmethod
///
/// @traceability
///
void SPM_v_InitParametersFactors(void);
#endif //FCT_CFG_SIGNAL_PERF_MONITORING
#else
  /*****************************************************************************
    MACROS
  *****************************************************************************/
  #define SPM_CYCLE_TIME                FCT_f_GetTaskCycleTime()
  
  /*****************************************************************************
    TYPEDEFS
  *****************************************************************************/
  #define SPM_PROBABILITY_MAX           1.0F
  #define SPM_PROBABILITY_MIN           0.0F
  #define SPM_CONFIDENCE_MAX            1.0F
  #define SPM_CONFIDENCE_MIN            0.0F
  #define SPM_FUSED_BLOCKAGE_PROB_MAX   10U
  
  /*FCTSenErrorOut Interface vesion min threshold for observers states*/
  #define ERROR_OUT_MIN_INT_VER        (18U)
  
  #define SPM_LP_FILTER_CONSTANT        0.01F
  
  #define SPM_TMAX_ROADBEAM_ACTIVATION      (float32)(SPM_TMAX_UNTIL_OBJ - SPM_ROADBEAM_DURATION)
  
  #define SPM_BLOCKAGE_LOWEST_RANGE_CONF    0.3F
  #define SPM_BLOCKAGE_LOWEST_TIMEOUT_CONF  0.3F
  
  #define SPM_DISTX_FOR_LATERAL_FAILURE   50.0F
  /*Fix QAC issue Hard coded floating constant*/
  #define SPM_FACTOR_CONVERT_MINUTES_IN_SEC 60.0F
  /*****************************************************************************
    TYPEDEFS (KOMPONENTENEXTERN)
  *****************************************************************************/
  typedef struct 
  {
    float32 Probability;
    float32 Confidence;
  } SPMExternalBlockage_t;
  
  typedef struct 
  {
    uint32 Interference;
    sint32 HoldCnt;
  } SPMInterference_t;
  
  typedef struct 
  {
    uint8 VDYVelocityNotSuffForACC;
    uint8 VDYYawRateNotSuffForACC;
    uint8 VDYVelocityNotSuffForEBA;
  } SPMSigChk_t;
  
  /// This structure contains blockage parameters which come via RTE BSWAlgoParameters or hard coded defines
  typedef struct {
    float32   fShutOffBSDRange;
    float32   fShutOffLCARange;
    float32   fBSDRangeHoldCounterTHLD;
    float32   fLCARangeHoldCounterTHLD;
    float32   fTimeoutShutOffTime;
    float32   fTimeoutTimeThld;
    float32   fTimeoutShutOffWay;
    float32   fTimeoutWayThld;
    float32   fWiperDelay;
    float32   fBlockage1VerificationTime;
    float32   fBlockage1BSDAlertCounter;
    boolean   bEnableBlockage;
    boolean   bEnableSelftest;
    uint8   uiNoOfAllowedObjLosses;
  } SPMBlockageParameters_t;
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  
  /*****************************************************************************
    VARIABLES
  *****************************************************************************/
  extern SPMBlockageParameters_t SPMBlockageParameters;
  /*****************************************************************************
    FUNCTION
  *****************************************************************************/
  /// @brief                  Check the interference data and set the blockage output
  ///						    
  /// @pre				      None
  /// @post				      None
  /// @param[out]             puiBlockageEvent     Blockage output
  /// @param[in]              fNoiseRange          Variable used to store the value of the signal f_MaxmimumSensorRange
  /// @param[in]              bNoiseRangeValid     Variable used to set True/False acording with the value of the signal b_MaxRangeInfluencedByLargePeak
  ///						    
  /// @return                 void
  /// 
  /// @InOutCorrelation       Check interference based on RSP signals f_MaximumSensorRange and b_MaxRangeInfluencedByLargePeak,\n
  ///						    and set InterferenceRange on AL_ERR_STATE_ACTIVE if interference was detected.
  ///
  /// @startuml               "Call sequence for  SPMInterferenceRange"
  /// 
  /// spm -> spm_interference: **SPMProcess** call \n **SPMInterferenceRange**(fNoiseRange, bNoiseRangeValid, puiBlockageEvent)
  /// activate spm_interference
  ///		spm_interference -> fct_access_macros:  FCT_f_GetEgoSpeedX()
  ///		spm_interference -> spm:
  /// deactivate spm_interference
  /// @enduml
  /// 
  /// @testmethod             Test of code coverage (dynamic module test) \n 
  ///                         Test order of calls (dynamic module test)              
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-582-0006e2e0 
  ///  
  void SPMInterferenceRange(float32 fNoiseRange, boolean bNoiseRangeValid, FCTSenErrorOut_t *puiBlockageEvent);
  
  /*! spm_objectloss.c */
  #if SPM_CFG_USE_OBJECTLOSS 
  extern void SPMInitObjectLoss (void);
  /// Object Loss main function, detection of loss of relevance for BSD and LCA Objects
  ///
  /// @pre                    None
  /// @post                   None    
  ///
  /// @return                 -
  ///
  /// @InOutCorrelation       Object Loss main function, detection of loss of relevance for BSD and LCA Objects
  ///  
  extern void SPMProcessObjectLoss (const fSpeed_t fOwnSpeed);
  #endif
  
  // spm_blck_adapt
  #if SPM_CFG_USE_WIPER_ADAPT
  extern void SPMInitWiperData(void);
  extern void SPMWiperAdaptBlockageState (const float32 fWiperDelay,
                                          const float32 fBlockage1VerificationTime,
                                          const eBlockageStates_t eSPMBlockageState,
                                          const fTime_t fCurrCycleTime,
                                                uint8 *uBlockageProbability);
  #endif//SPM_CFG_USE_WIPER_ADAPT
#endif//SPM_SRR_TECHNOLOGY

#endif //SPM_H_INCLUDED
  /* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

