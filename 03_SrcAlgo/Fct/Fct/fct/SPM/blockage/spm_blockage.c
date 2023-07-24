/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.43 $

  ---*/ /*---
  CHANGES:                $Log: spm_blockage.c  $
  CHANGES:                Revision 1.43 2021/03/01 10:26:34CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Add void to SPM_v_SetDelayCounter param
  CHANGES:                Revision 1.42 2021/02/25 10:38:47CET Pallo, Istvan (palloi) 
  CHANGES:                Add implementation for trigger increase blockage state by timeout
  CHANGES:                Revision 1.41 2021/02/24 13:12:58CET Pallo, Istvan (palloi) 
  CHANGES:                Update setting of reactivation delay threshold
  CHANGES:                Revision 1.40 2021/02/15 16:59:48CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Add config switch SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS
  CHANGES:                Revision 1.39 2021/02/05 14:54:20CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Fix QAC issues
  CHANGES:                Revision 1.38 2020/11/10 18:00:12CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Add logic to set partial blockage independently when SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE is SWITCH_OFF
  CHANGES:                Revision 1.37 2020/10/23 15:50:39CEST Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Adaptation for situation when SLATE and ACC are both turned OFF simultaniously
  CHANGES:                Revision 1.36 2020/06/25 08:14:53CEST Pallo, Istvan (palloi) 
  CHANGES:                Update code for SPM split - SRR
  CHANGES:                Revision 1.35 2020/06/02 16:36:07CEST Pallo, Istvan (palloi) 
  CHANGES:                Update set parameters functions. Implement weather factor function.
  CHANGES:                Revision 1.34 2020/04/23 15:49:31CEST Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Fix QAC level 3 warnings
  CHANGES:                Revision 1.33 2020/04/08 13:18:10CEST Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Fix QAC level 4 warnings
  CHANGES:                Revision 1.32 2020/03/17 09:27:43CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Fix QAC
  CHANGES:                Revision 1.31 2020/03/05 08:08:52CET Pallo, Istvan (palloi) 
  CHANGES:                Update implementation with new CBO config switches.
  CHANGES:                Revision 1.30 2020/03/03 07:55:56CET Pallo, Istvan (palloi) 
  CHANGES:                New function implementation for weather factor computation
  CHANGES:                Revision 1.29 2019/06/24 11:14:44CEST Pallo, Istvan (palloi) 
  CHANGES:                Implement function for delay reactivation based on speed. 
  CHANGES:                Implement new logic for delay reactivation
  CHANGES:                Revision 1.28 2019/05/09 08:59:01CEST Pallo, Istvan (palloi) 
  CHANGES:                Add requirement ID for delay reactivation timer and timeout parameters
  CHANGES:                Revision 1.27 2019/04/22 13:20:52CEST Pallo, Istvan (palloi) 
  CHANGES:                Add new speed thresholds for missalignment detection. 
  CHANGES:                Check for ACC to not be deactivate when setting missalignment.
  CHANGES:                Revision 1.26 2019/04/01 10:28:52CEST Pallo, Istvan (palloi) 
  CHANGES:                Update missalignment algo according to TSS2 proposed implementation
  CHANGES:                Revision 1.25 2019/03/22 10:53:19CET Pallo, Istvan (palloi) 
  CHANGES:                Consider only OOI0 when check camera for confirmation. 
  CHANGES:                Remove blockage trigger when missalignment is detected in order to prevent EBA deactivation
  CHANGES:                Revision 1.24 2019/03/15 09:30:12CET Pallo, Istvan (palloi) 
  CHANGES:                Add comment for satisfy requirement
  CHANGES:                Revision 1.23 2019/03/07 14:09:13CET Pallo, Istvan (palloi) 
  CHANGES:                Add necessary defines and implementation for missalignment check
  CHANGES:                Revision 1.22 2019/02/01 12:59:29CET Stanescu, Roxana (StanescuR01) 
  CHANGES:                * Consider deselection timer expired when it is lower or equal with 0(initial value).
  CHANGES:                Revision 1.21 2018/09/24 14:56:01CEST Pallo, Istvan (palloi) 
  CHANGES:                Add config switch for SRR technology
  CHANGES:                Revision 1.20 2018/09/19 08:14:22CEST Pallo, Istvan (palloi) 
  CHANGES:                Add guard for ProbSigma in order to limit value between 0 and 1
  CHANGES:                Revision 1.19 2018/08/31 07:44:25CEST Pallo, Istvan (palloi) 
  CHANGES:                Fix CBO factor computation
  CHANGES:                Revision 1.18 2018/08/17 13:54:05CEST Pallo, Istvan (palloi) 
  CHANGES:                Change CBO factor computation logic and remove perfDegr from function call.
  CHANGES:                Revision 1.17 2018/08/10 13:01:50CEST Pallo, Istvan (palloi) 
  CHANGES:                Replace float comparison with CML function for fix QAC warnings
  CHANGES:                Revision 1.16 2018/08/07 07:33:16CEST Pallo, Istvan (palloi) 
  CHANGES:                Add function for setting blockage observers states
  CHANGES:                Revision 1.15 2018/08/06 10:36:16CEST Pallo, Istvan (palloi) 
  CHANGES:                Add time histeresis for blockage reactivation
  CHANGES:                Revision 1.14 2018/07/27 07:34:27CEST Olaru, Marian (OlaruM02) 
  CHANGES:                change the value of number of allowed object losses based on ALN information
  CHANGES:                Revision 1.13 2018/06/18 08:19:00CEST Pallo, Istvan (palloi) 
  CHANGES:                Fix partial blockage wrong config switch
  CHANGES:                Revision 1.12 2018/05/08 06:57:21CEST Pallo, Istvan (palloi) 
  CHANGES:                Fix spelling bug for partial blockage state checking
  CHANGES:                Revision 1.11 2018/05/08 06:50:07CEST Pallo, Istvan (palloi) 
  CHANGES:                Re add check of partial blockage state when changing from full damp to reduce damp
  CHANGES:                Revision 1.10 2018/05/03 08:41:56CEST Pallo, Istvan (palloi) 
  CHANGES:                Fix blockage toggling when full blockage tirggered by partial blockage
  CHANGES:                Revision 1.9 2018/04/24 09:17:48CEST Pallo, Istvan (palloi) 
  CHANGES:                Correct usage of config switch
  CHANGES:                Revision 1.8 2018/04/19 13:05:10CEST Pallo, Istvan (palloi) 
  CHANGES:                Add new config switch for perfDegrData
  CHANGES:                Revision 1.7 2017/11/14 13:54:40CET Pallo, Istvan (palloi) 
  CHANGES:                Add empty line between functions
  CHANGES:                Revision 1.6 2017/08/11 08:39:19CEST Pallo, Istvan (palloi) 
  CHANGES:                Change functions naming and calls
  CHANGES:                Revision 1.5 2017/08/09 13:55:52CEST Olaru, Marian (OlaruM02) 
  CHANGES:                adde the changes related to ALN(probability and confidence)
  CHANGES:                Revision 1.4 2017/08/01 12:11:45CEST Olaru, Marian (OlaruM02) 
  CHANGES:                range probability/confidence fusion using convolution method
  CHANGES:                Revision 1.3 2017/07/28 06:53:31CEST Pallo, Istvan (palloi) 
  CHANGES:                Add functionality from AL_FCT_ARS400_02.86.00. Code refactoring & QAC cleaning.
  CHANGES:                Revision 1.2 2017/06/21 09:03:37CEST Pallo, Istvan (palloi) 
  CHANGES:                Remove functions headers from file.
  CHANGES:                Move functions declaration in h file
  CHANGES:                Revision 1.1 2017/03/17 13:16:51CET Kober, Manfred (uidv8885) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm.h"
#include "spm_par.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define SPM_CONFIDENCE_ADAPT_FACTOR                   (0.01F)
#define SPM_TIMEOUT_TGTRATE_UPPER_THLD                (20.0F)
#define SPM_TIMEOUT_TGTRATE_LOWER_THLD                (3.0F)
#define SPM_TIMEOUT_PROB_THLD                         (0.76F)
#define SPM_BLOCKAGE_ALPHA_FILTER_FAST_MAX            (0.9F)
#define SPM_BLK_PROB_FACTOR_FULL_DAMP                 (1.0F)
#define SPM_BLK_PROB_FACTOR_INC_DAMP                  (0.5F)
#define SPM_BLK_PROB_FACTOR_RDC_TO_FULL_DAMP          (0.67F)
#define SPM_MINMAX_NONZERO_LOW_VAL                    (0.1F)
#define SPM_RANGE_CONF_SCALE_FACTOR                   (0.9F)
#define SPM_PROB_INVALID_VAL                          (-1.0F)

#define SPM_BLOCKAGE_GDB_INC_DAMP_NO_DAMP_DIV_FACTOR  (2.0F)
#define SPM_BLOCKAGE_GDB_RDC_DAMP_NO_DAMP_DIV_FACTOR  (20.0F)
#define SPM_BLOCKAGE_GDB_RDC_DAMP_DIV_FACTOR          (0.67F)

#define SPM_NUMBER_OF_CONFIDENCE_PARAMS               (3U)

#define SPM_RANGE_PROB_TRUST_THLD                     (2.0F)

#define SPM_TIMEOUT_DOWN_FACTOR_XVAL                  (0.1F)
#define SPM_TIMEOUT_DOWN_FACTOR_YVAL                  (1.0F/3.0F)
#define SPM_TIMEOUT_UP_FACTOR_XVAL                    (0.9F)
#define SPM_TIMEOUT_UP_FACTOR_YVAL                    (1.0F)
#define SPM_TIMEOUT_MIN_PROB                          (0.001F)

#define SPM_ALN_TIMEOUT_DOWN_FACTOR_XVAL              (0.8F)
#define SPM_ALN_TIMEOUT_DOWN_FACTOR_YVAL              (1.0F)
#define SPM_ALN_TIMEOUT_UP_FACTOR_XVAL                (1.0F - CML_f_Delta)
#define SPM_ALN_TIMEOUT_UP_FACTOR_YVAL                (1.0F/3.0F)

#define BSW_INT_VER_THLD                              (19U)
#define BSW_WIPER_INT_VER_THLD                        (23U)

#define SPM_USE_MAX_FAR_NEAR                           (0U)
#define SPM_USE_ONLY_NEAR                              (1U)
#define SPM_USE_ONLY_FAR                               (2U)
#define SPM_USE_FUSED_FAR_NEAR                         (3U)

#define SPM_RANGE_IDX                                  (0U)
#define SPM_TIMEOUT_IDX                                (1U)
#define SPM_OBJLOSS_IDX                                (2U)

#define SPM_WEIGHT_MAX_FACTOR                          (1.0F)
#define SPM_WEIGHT_KEEP_FACTOR                         (0.8F)
#define SPM_WEIGHT_LOW_FACTOR1                         (0.2F)
#define SPM_WEIGHT_LOW_FACTOR2                         (0.1F)
#define SPM_WEIGHT_MIN_FACTOR                          (0.02F)

#define SPM_ONE_OBJECT_LOST                            (1U)

#define SPM_SIGMA_INIT_VALUE                           (1.0F)
#define SPM_SIGMA_DIV_FACTOR                           (1.5F)
#define SPM_SIGMA_MULTIPLY_FACTOR                      (0.5F)

#if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
  #define SPM_GRADIENT_FILTER_FACTOR                   (0.02F)
#endif

#if(SPM_INCREASE_RANGE_CONF == SWITCH_ON)
  #define SPM_TWO_OBJECTS_LOST                         (2U)
  #define SPM_THREE_OBJECTS_LOST                       (3U)
  #define SPM_CONF_ADAPT_FACTOR_ONE_LOSS               (1.6F)
  #define SPM_CONF_ADAPT_FACTOR_TWO_LOSSES             (1.82F)
  #define SPM_CONF_ADAPT_FCTOR_THREE_LOSSES            (2.0F)
#endif

#if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
  #define SPM_DESELECT_TIME_THLD                       (0.0F)
  #define SPM_TARGET_RATE_THLD                         (0.2F)
  #define SPM_DESELECT_TIME_MULTYPLY_FACTOR            (2.0F)
#endif

#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)||(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON))
  #define EM_PERF_INT_VER_THLD_RB                      (5U)
#endif
#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)||(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON) || (SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON))
  #define SPM_REACTIVATION_DELAY_THLD                  (0.0F)
#endif

#define SPM_SHUT_ON_RANGE                              (1U)
#define SPM_SHUT_OFF_RANGE                             (2U)

#if(SPM_CHECK_MISSALIGNMENT)
  #define SPM_MISSALIGNMENT_HIGH_PROB     (0.9F)
  #define SPM_MISSALIGNMENT_LOW_PROB      (0.4F)
  #define SPM_MISSALIGNMENT_MIN_CONF    (0.2F)
  #define SPM_MISSALIGNMENT_MAX_TUNNEL_PROB                        (0.45F)
  #define SPM_PARTIAL_BLOCKAGE_SPEED_THRESHOLD                      (65.0F/C_KMH_MS)
  #define SPM_MISSALIGNMENT_SPEED_THRESHOLD                          (30.0F/C_KMH_MS)
  #define SPM_MISSALIGNMENT_MAX_OBJ_LONG_DIST                   (60.0F)
  #define SPM_INVALID_LONG_DISTANCE                                            (-1.0F)
  #define SPM_MISSALIGNMENT_CAM_CONF_GATE_OOI                   (10U)
  #define SPM_MISSALIGNMENT_CAM_CONF_GATE                            (30U)
  #ifndef   OBJCLASS_UNCLASSIFIED
    #define OBJCLASS_UNCLASSIFIED  (7U)
  #endif
#endif
/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
#if(SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
  /* observer state for SRD damping */
  static SPMObserverStates SRDDampingState;
#endif

/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
  void SPMProcessPreblockage(SYSDampState_t SRDDampState)
  {
    /* Get current SRR damping state */
    SPMData.SPMSRDSysDamp = SRDDampState;

    /*! Save previous SRD PDState */
    SRDDampingState.PreviousState = SRDDampingState.CurrentState;
    /* Macom reports blockage */
    if(SPMData.SPMSRDSysDamp == GDB_FULL_DAMP)
    {
    SRDDampingState.CurrentState      = GDB_FULL_DAMP;
    }
    else if ((SPMData.SPMSRDSysDamp == GDB_NO_DAMP)
          || (SPMData.SPMSRDSysDamp == GDB_INC_DAMP)
          || (SPMData.SPMSRDSysDamp == GDB_RDC_DAMP))
    {
      /* Macom reports no full damping : see what current state is */
      /* Macom reports NO/INC/RDC damping and system was active before -> system remains active */
      if (SRDDampingState.CurrentState == GDB_NO_DAMP)
      {
        /* current SRD state remains in GDB_PD_ON */
      }
      /* Macom reports NO/INC/RDC damping and Macom was in FULL_DAMP before ->
      we will check the state of ARS in SPMBlockageSetDEMEvents*/
      else if(SRDDampingState.CurrentState == GDB_FULL_DAMP)
      {
        if(SPMData.SPMSRDSysDamp == GDB_NO_DAMP)
        {
          /*! Save previous SRD PDState */
          //SRDDampingState.PreviousState = SRDDampingState.CurrentState;
          /* reactivate the system only if Macom reports GDB_NO_DAMP and ARS fulfills the condition for reactivation */
          if(
              (SPMData.SPMBlockageProbability  <  (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / SPM_BLOCKAGE_GDB_RDC_DAMP_NO_DAMP_DIV_FACTOR)) && 
              (SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
            )
            {
              SRDDampingState.CurrentState = GDB_NO_DAMP;
            }
        }
        /* if Macom reports INC/RDC_DAMP the system remains deactivated */
        else
        {
          SRDDampingState.CurrentState = GDB_FULL_DAMP;
        }
      }
      else
      {
        /* keep state */
      }
    }
    else
    {
      /* Macom reports unknown state : usually timeout of sensors or communication error : keep state */
    }
  }
#endif  /* #if (SPM_CFG_SHORT_RANGE_SENSOR_INFO) */


void SPMDetermineBlockProb(const PerfDegr_t *pPerfDegrData)
{
  /* Mapping Parameters */
  GDB_Math_Point_t TimeDown, TimeUp;                /* Time (since last valid Object) Thresholds */
  GDB_Math_Point_t WayDown, WayUp;                  /* Driven Distance (since last valid Object) Thresholds */
  GDB_Math_Point_t ConfDown, ConfUp;                 /* Timeout confidence depending on target rate */
  float32         TimeProbability, WayProbability;  /* Mapped probability values of Timeout criteria */
  float32         TimeoutConfTemp;                  /* current timeout conf. based on target rate, serves as filter input */
  float32         ObjLossConfFactor;
#if(FCT_CFG_SLATE_COMPONENT == SWITCH_ON)  
  ObjNumber_t     uRelevObjIdx;
#endif  

  /* Fusion Parameters */

  float32         NewConf[SPM_NUMBER_OF_CONFIDENCE_PARAMS];     /* Array for weighted confidence (weight*confidence) */
  float32         ProbMean;                                     /* Mean value of all 3 Blockage probabilities */
  float32         ConfSum;                                      /* Sum of all 3 weighted confidences */
  float32         ConfMax;                                      /* The greatest of all 3 weighted confidences */
  float32         ConfSigma, ProbSigma;                         /* standard deviations of confidence and probability */
  float32         ProbOut, ConfOut;                             /* output values for this cycle */
  float32         RangeWeight, ObjLossWeight, TimeoutWeight;    /* Weight factors for all blockage criteria */
  float32         fmax_float_eval;
#if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
  boolean bOOI0ChangedToNeighbour;
#endif
#if(ALGO_CFG_FarScanAvailable)
  uint8           uScanIndex;
  float32         fTempBlkRangeProb[SYS_NUM_OF_SCANS];    /*  Mapped value into probability for near/far range */
#endif
#if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
  float32         fHelpRangeConfGradient;
#endif
  /******************************************************************/
  /*  Copy Range, Timeout and ObjectLoss Data to SPM main structure */
  /******************************************************************/
  SPMData.SPMBlockageTimeoutTimeCounter = pPerfDegrData->Timeout.fTimeCounter;
  SPMData.SPMBlockageTimeoutWayCounter  = pPerfDegrData->Timeout.fWayCounter;

  SPMData.SPMBlockageObjLossProb        = SPMObjectLoss.fObjectLossProbability;
  SPMData.SPMBlockageObjLossConf        = SPMObjectLoss.fObjectLossConfidence;

  if(SPMObjectLoss.uiNoOfObjLosses > SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP)
  {
    ObjLossConfFactor = SPM_CONFIDENCE_ADAPT_FACTOR;
  }
  else
  {
    ObjLossConfFactor = SPM_CONFIDENCE_MAX;
  }
  /*Map near/far range into probability*/

#if(ALGO_CFG_FarScanAvailable)
  for(uScanIndex = SYS_SCAN_NEAR; uScanIndex < SYS_NUM_OF_SCANS; uScanIndex++)
  {
    fTempBlkRangeProb[uScanIndex] = SPMMapRangeToProbability(pPerfDegrData, SPMBlockageParameters.fShutOffRange[uScanIndex], SPMBlockageParameters.fShutOnRange[uScanIndex], uScanIndex);
    #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
      #if(SPM_USE_RANGE_GRADIENT)
        SPMData.SPMScanRangeConfidencePrevious[uScanIndex] = SPMData.SPMScanRangeConfidence[uScanIndex];
      #endif
      SPMData.SPMScanRangeConfidence[uScanIndex] = pPerfDegrData->RangeFused[uScanIndex].fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
      #if(SPM_USE_RANGE_GRADIENT)
        fHelpRangeConfGradient = (SPMData.SPMScanRangeConfidence[uScanIndex] - SPMData.SPMScanRangeConfidencePrevious[uScanIndex]) / fCycleTime;
        GDB_Math_LowPassFilter(&SPMData.SPMBlockageRangeConfidenceGradient[uScanIndex], fHelpRangeConfGradient, SPM_GRADIENT_FILTER_FACTOR);
      #endif
    #else
      SPMData.SPMScanRangeConfidence[uScanIndex] = pPerfDegrData->RangeFused.fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
    #endif
  }
  /*the Blockage Decision used the Max Probability value of the two Scans SPM_USE_MAX_FAR_NEAR=0*/
  if(SPMBlockageParameters.uUseFarNearScanForBlck == SPM_USE_MAX_FAR_NEAR)
  {
#if(SPM_USE_AREA_CONVOLUTION_FOR_RANGE_FUSION == SWITCH_ON)
      SPMFuseRangeScanDataUsingAreaConvolution(fTempBlkRangeProb[SYS_SCAN_NEAR],fTempBlkRangeProb[SYS_SCAN_FAR], SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR], SPMData.SPMScanRangeConfidence[SYS_SCAN_FAR]);
#else
      SPMFuseRangeScanDataNew(fTempBlkRangeProb[SYS_SCAN_NEAR],fTempBlkRangeProb[SYS_SCAN_FAR], SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR], SPMData.SPMScanRangeConfidence[SYS_SCAN_FAR]);
#endif
  }
  /*use only Near Scan SPM_USE_ONLY_NEAR=1*/
  else if(SPMBlockageParameters.uUseFarNearScanForBlck == SPM_USE_ONLY_NEAR)
  {
    SPMData.SPMBlockageRangeProb = SPMMapRangeToProbability(pPerfDegrData, SPMBlockageParameters.fShutOffRange[SYS_SCAN_NEAR], 
                            SPMBlockageParameters.fShutOnRange[SYS_SCAN_NEAR],SYS_SCAN_NEAR);
  }
  /*use only Far Scan SPM_USE_ONLY_FAR=2*/
  else if(SPMBlockageParameters.uUseFarNearScanForBlck == SPM_USE_ONLY_FAR)
  {
    SPMData.SPMBlockageRangeProb = SPMMapRangeToProbability(pPerfDegrData, SPMBlockageParameters.fShutOffRange[SYS_SCAN_FAR], 
                            SPMBlockageParameters.fShutOnRange[SYS_SCAN_FAR],SYS_SCAN_FAR);
  }
  /*the Blockage Decision used the Mean Probability value of the two Scans SPM_USE_FUSED_FAR_NEAR=3*/
  else if(SPMBlockageParameters.uUseFarNearScanForBlck == SPM_USE_FUSED_FAR_NEAR)
  {
    /*TO DO*/
  }
  else
  {
    /*nop*/
  }
#else
  SPMData.SPMBlockageRangeProb = SPMMapRangeToProbability(pPerfDegrData, SPMBlockageParameters.fShutOffRange[SYS_SCAN_NEAR], 
                            SPMBlockageParameters.fShutOnRange[SYS_SCAN_NEAR], SYS_SCAN_NEAR);
  #if (EM_PERF_DEGR_INTFVER  >= EM_PERF_INT_VER_THLD)
    #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
      SPMData.SPMScanRangeConfidencePrevious[SYS_SCAN_NEAR] = SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR];
    #endif
    SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] = pPerfDegrData->RangeFused[SYS_SCAN_NEAR].fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
    #if(SPM_USE_RANGE_GRADIENT)
      fHelpRangeConfGradient = (SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] - SPMData.SPMScanRangeConfidencePrevious[SYS_SCAN_NEAR]) / fCycleTime;
      GDB_Math_LowPassFilter(&SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_NEAR], fHelpRangeConfGradient, SPM_GRADIENT_FILTER_FACTOR);
    #endif
  #else
    SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] = pPerfDegrData->RangeFused.fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
  #endif
#endif
  /********************************************************************************************/
  /*  Map Driven Distance/Time since last valid Object to Blockage Probability and Confidence */
  /********************************************************************************************/
  if(fEgoSpeed > SPM_SPEED_MIN) /* SatisfyReq: ARS510VW19: L3_PS_1809*/
  {
    float32 fTargetRateTemp = 0.0F;
    WayDown.X = 0.0F; /* Lower Driven Distance Threshold */
    WayDown.Y = 0.0F;
    WayUp.X   = SPMBlockageParameters.fTimeoutWayThld; /* Upper Driven Distance Threshold */
    WayUp.Y   = 1.0F;

    TimeDown.X  = 0.0F; /* Lower Timer Threshold */
    TimeDown.Y  = 0.0F;
    TimeUp.X    = SPMBlockageParameters.fTimeoutTimeThld; /* Upper Timer Threshold */
    TimeUp.Y    = 1.0F;

    /* Map Time and Distance into Probability */ 
    TimeProbability = GDB_Math_LinInterpol(TimeDown, TimeUp, SPMData.SPMBlockageTimeoutTimeCounter);
    WayProbability = GDB_Math_LinInterpol(WayDown, WayUp, SPMData.SPMBlockageTimeoutWayCounter);

    /* Adapt Timeout Blockage Probability only if 
    ...new Timeout Blockage Probability is higher than old one
    ...or Range Confidence is above threshold
    ...or system is not in GDB_FULL_DAMP
    to avoid that timeout criterion reactivates the system after GDB_FULL_DAMP, -> only Range is allowed to do this */
    if((TimeProbability >= SPMData.SPMBlockageTimeoutBlockProb) 
      ||(WayProbability >= SPMData.SPMBlockageTimeoutBlockProb)
      ||(SPMData.SPMBlockageRangeConf > SPM_STATE_CONF_MIN)
      ||((SPMData.SPMBlockageState != GDB_FULL_DAMP) && (SPMData.SPMBlockageState != GDB_RDC_DAMP))
      )
    {
#if(SPM_USE_LOGICAL_AND_FOR_TIMEOUT == SWITCH_OFF)
      /* Choose higher Probability if logical "or" for timeout counters is used, 1 of the 2 counters must reach the threshold to report blockage */
      SPMData.SPMBlockageTimeoutBlockProb = CML_f_Max(TimeProbability, WayProbability);
#else
      /* Choose lower Probability if logical "and" for timeout counters is used, both counters must reach their thresholds to report blockage */
      SPMData.SPMBlockageTimeoutBlockProb = CML_f_Min(TimeProbability, WayProbability);
#endif
    }
    else 
    {
      /* freeze Timeout Blockage Probability */
    }

    /**********************/
    /* Compute Confidence */
    /**********************/
    /*

         Confidence
              |
           1  +                                    +------------
              |                                    |
              |                                    |
depending on  +_                                   |
 target rate  | |_                                 | Final Phase
              |   |_                               |
              |     |_                             |
              |       |_                           |
           0  +         |__________________________|
          +----------------------------------------+------------> Timeout Blockage Probability
                      Normal                   FULL_DAMP
                      Phase                 Threshold - 4%
    */

    ConfDown.X = SPM_TIMEOUT_TGTRATE_LOWER_THLD;
    ConfDown.Y = SPM_CONFIDENCE_MIN;
    ConfUp.X   = SPM_TIMEOUT_TGTRATE_UPPER_THLD;
    ConfUp.Y   = SPM_CONFIDENCE_MAX;

    /* Normal Phase: Time and distance counters below 76% (80% - 4%) blockage probability  */
    if(SPMData.SPMBlockageTimeoutBlockProb < SPM_TIMEOUT_PROB_THLD)
    {
        if(SPMData.SPMBlockageTimeoutBlockProb >= SPM_TIMEOUT_MIN_PROB_CONF_THLD)
        {
            //increase timeout confidence to have earlier trigger of INC BLOCKAGE
            GDB_Math_LowPassFilter(&SPMData.SPMBlockageTimeoutBlockConf, SPM_TIMEOUT_CONF_VAL, SPM_LP_FILTER_CONSTANT);
        }
        else
        {
           /* timeout confidence computation depends on target rate */
           #if(ALGO_CFG_FarScanAvailable)
             #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
               fTargetRateTemp = MIN_FLOAT(pPerfDegrData->TargetRate[SYS_SCAN_FAR].fTargetRate, 
                                           pPerfDegrData->TargetRate[SYS_SCAN_NEAR].fTargetRate);
             #else
               fTargetRateTemp = MIN_FLOAT(pPerfDegrData->TargetRate.fTargetRate, pPerfDegrData->TargetRate.fTargetRate);
             #endif
           #else
             #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
               fTargetRateTemp = pPerfDegrData->TargetRate[SYS_SCAN_NEAR].fTargetRate;
             #else
               fTargetRateTemp = pPerfDegrData->TargetRate.fTargetRate;
             #endif
           #endif
           TimeoutConfTemp = GDB_Math_LinInterpol(ConfDown, ConfUp, fTargetRateTemp);
           /* consider local damping only detected by object loss by multiplying the confidence with the TempConfFactor */
           GDB_Math_LowPassFilter(&SPMData.SPMBlockageTimeoutBlockConf, TimeoutConfTemp * ObjLossConfFactor, 
                             MIN(SPM_BLOCKAGE_ALPHA_FILTER_FAST_MAX, (SPM_LP_FILTER_CONSTANT / ObjLossConfFactor)));
        }
    }
    /* Final Phase: Time and Distance near FULL_DAMP end values --> Input Confidence = 100% */
    else
    {
      GDB_Math_LowPassFilter(&SPMData.SPMBlockageTimeoutBlockConf, SPM_CONFIDENCE_MAX, SPM_LP_FILTER_CONSTANT);
    }
  }
  /*****************************************************************************************************************/
  /*  Adapt Criteria Weight, depending on Blockage Confidences and Probabilities of Range, Timeout and Object Loss */
  /*****************************************************************************************************************/
  
  /* Reset ObjLoss weight */
  ObjLossWeight = 0.0F;
  SPMData.SPMCurrentObjLossWeight = 0.0F;
  
  /* Only Range can be trusted */
  /*
    Range Conf > Threshold
    (Range BlockProb - Timeout BlockProb) < Threshold
  */
  fmax_float_eval = CML_f_Max(SPM_TIMEOUT_MIN_PROB, SPMData.SPMBlockageTimeoutBlockProb);
  if(
      (SPMData.SPMBlockageRangeConf >= SPM_BLOCKAGE_LOWEST_RANGE_CONF) 
      &&((SPMData.SPMBlockageRangeProb / fmax_float_eval) > SPM_RANGE_PROB_TRUST_THLD)
    )
  {
    RangeWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;
    SPMData.SPMCurrentRangeWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;

    TimeoutWeight = SPM_WEIGHT_MIN_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
    SPMData.SPMCurrentTimeoutWeight = SPM_WEIGHT_MIN_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
  }

  /* Situation is getting worse but Range must still be trusted until Timeout reports GDB_FULL_DAMP */
  /*
    Range BlockProb > GDB_FULL_DAMP Threshold * 0.67
    Timeout BlockProb < GDB_FULL_DAMP Threshold
  */
  else if(
          (SPMData.SPMBlockageRangeProb >= (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB * SPM_BLK_PROB_FACTOR_RDC_TO_FULL_DAMP))
        &&(SPMData.SPMBlockageTimeoutBlockProb < SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB)
         )
  {
    RangeWeight = SPM_WEIGHT_KEEP_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;
    SPMData.SPMCurrentRangeWeight = SPM_WEIGHT_KEEP_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;

    TimeoutWeight = SPM_WEIGHT_LOW_FACTOR1 * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
    SPMData.SPMCurrentTimeoutWeight = SPM_WEIGHT_LOW_FACTOR1 * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
  }

  /* Only Timeout can be trusted */
  /*
    Range Conf < Threshold
    Timeout Conf > threshold
  */
  else if((SPMData.SPMBlockageRangeConf < SPM_BLOCKAGE_LOWEST_RANGE_CONF)
    &&(SPMData.SPMBlockageTimeoutBlockConf >= SPM_BLOCKAGE_LOWEST_TIMEOUT_CONF))
  {
    RangeWeight = SPM_WEIGHT_LOW_FACTOR2 * SPM_BLOCKAGE_RANGE_WEIGHT;
    SPMData.SPMCurrentRangeWeight = SPM_WEIGHT_LOW_FACTOR2 * SPM_BLOCKAGE_RANGE_WEIGHT;

    TimeoutWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
    SPMData.SPMCurrentTimeoutWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
  }

  /* No inconsistencies, both criteria can be trusted */
  else
  {
    RangeWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;
    SPMData.SPMCurrentRangeWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_RANGE_WEIGHT;

    TimeoutWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
    SPMData.SPMCurrentTimeoutWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_TIMEOUT_WEIGHT;
  }

#if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
  bOOI0ChangedToNeighbour = CheckIfRelevantObjChangedToNeighbour();
#endif

  /* If a relevant object is present, set RangeWeight to 0 to avoid reporting blockage
     while a suitable object for distance control is present. */
 /* Temporary change of prefix to ensure compatibility in EBA */
#if(FCT_CFG_SLATE_COMPONENT == SWITCH_ON)
  // 2021-02-03, reviewer:Opreai01,Popam05,Palloi reason: Is initialized for situation when config is OFF
  uRelevObjIdx = OBJ_INDEX_NO_OBJECT; // PRQA S 2982
#if((FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF))
  uRelevObjIdx = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
#endif

  if(
      (
        (uRelevObjIdx != OBJ_INDEX_NO_OBJECT)
    #if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
      ||(bOOI0ChangedToNeighbour == TRUE)
    #endif
      )
    &&(SPMObjectLoss.uiNoOfObjLosses < SPM_ONE_OBJECT_LOST)
    &&(SPMData.SPMBlockageState != GDB_FULL_DAMP)
    &&(SPMData.SPMBlockageState != GDB_RDC_DAMP)
  #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
    &&(SPMObjectLoss.fDeselectionTimer <= SPM_DESELECT_TIME_THLD)
  #endif
    )
  {
    RangeWeight = 0.0F;
    SPMData.SPMCurrentRangeWeight = 0.0F;
  }
#endif

  /* Handle Object Loss criterion separately */
  /* If ObjLoss reports GDB_FULL_DAMP set ObjLoss weight to 1 and Range/Timeout weight to 0 */
  if((SPMData.SPMBlockageObjLossProb >= SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB) 
    &&(SPMData.SPMBlockageObjLossConf >= SPM_STATE_CONF_MIN))
  {
    ObjLossWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_OBJLOSS_WEIGHT;
    SPMData.SPMCurrentObjLossWeight = SPM_WEIGHT_MAX_FACTOR * SPM_BLOCKAGE_OBJLOSS_WEIGHT;

    RangeWeight                   = 0.0F;
    SPMData.SPMCurrentRangeWeight = 0.0F;

    TimeoutWeight                   = 0.0F;
    SPMData.SPMCurrentTimeoutWeight = 0.0F;
  }

  /********************************************************************************/
  /*  Probabilities, Confidences and Weights are now available for all 3 criteria */
  /********************************************************************************/

  /************************************************************************/
  /*          Start Fusion procedure for all 3 Blockage criteria          */
  /************************************************************************/

  NewConf[SPM_RANGE_IDX] = RangeWeight * SPMData.SPMBlockageRangeConf;
  NewConf[SPM_TIMEOUT_IDX] = TimeoutWeight * SPMData.SPMBlockageTimeoutBlockConf;
  NewConf[SPM_OBJLOSS_IDX] = ObjLossWeight * SPMData.SPMBlockageObjLossConf;

  ProbMean  = NewConf[SPM_RANGE_IDX] * SPMData.SPMBlockageRangeProb;
  ProbMean += NewConf[SPM_TIMEOUT_IDX] * SPMData.SPMBlockageTimeoutBlockProb;
  ProbMean += NewConf[SPM_OBJLOSS_IDX] * SPMData.SPMBlockageObjLossProb;

  ConfSum = NewConf[SPM_RANGE_IDX] + NewConf[SPM_TIMEOUT_IDX] + NewConf[SPM_OBJLOSS_IDX];

  ConfMax = CML_f_Max(NewConf[SPM_RANGE_IDX], NewConf[SPM_TIMEOUT_IDX]);
  ConfMax = CML_f_Max(ConfMax, NewConf[SPM_OBJLOSS_IDX]);

  if(ConfSum > 0.0F)
  {
    ProbMean /= ConfSum;

    ProbSigma  = CML_Sqr(SPMData.SPMBlockageRangeProb - ProbMean) * NewConf[SPM_RANGE_IDX];
    ProbSigma += CML_Sqr(SPMData.SPMBlockageTimeoutBlockProb - ProbMean) * NewConf[SPM_TIMEOUT_IDX];
    ProbSigma += CML_Sqr(SPMData.SPMBlockageObjLossProb - ProbMean) * NewConf[SPM_OBJLOSS_IDX];

    ProbSigma /= ConfSum;
    ProbSigma = CML_f_MinMax(SPM_PROBABILITY_MIN, SPM_PROBABILITY_MAX, ProbSigma);
    ProbSigma = CML_f_Sqrt(ProbSigma);

    ConfSigma = SPM_SIGMA_INIT_VALUE - (ProbSigma / SPM_SIGMA_DIV_FACTOR);
    ConfSigma = CML_f_MinMax(SPM_MINMAX_NONZERO_LOW_VAL, SPM_CONFIDENCE_MAX, ConfSigma);

    /* Output Values */
    ConfOut = ConfMax * ConfSigma;
    ConfOut = MIN_FLOAT(ConfOut, SPM_CONFIDENCE_MAX);

    ProbOut = ProbMean + (ProbSigma * SPM_SIGMA_MULTIPLY_FACTOR);
    ProbOut = MIN_FLOAT(SPM_PROBABILITY_MAX, ProbOut);
  }
  else
  {
    ConfOut = SPM_CONFIDENCE_MIN;
    ProbOut = SPM_PROB_INVALID_VAL;
  }

  /************************/
  /* Filter Output Values */
  /************************/

  /* Standard Cycle: Filtered and Current Values are valid */
  if((SPMData.SPMBlockageConfidence > SPM_CONFIDENCE_MIN) && (ConfOut > SPM_CONFIDENCE_MIN))
  {
    /* If System is in FULL/RDC Blockage Mode and Blockage Probability is falling --> use slow filter dynamics */
    if(
        (
          (SPMData.SPMBlockageState == GDB_FULL_DAMP) 
        ||(SPMData.SPMBlockageState == GDB_RDC_DAMP)
        )
      &&(ProbOut < SPMData.SPMBlockageProbability)
      )
    {
      GDB_Math_LowPassFilter(&SPMData.SPMBlockageProbability, ProbOut, SPM_BLK_A_OUTPUT_FILTER_SLOW);
    }
    /* otherwise use fast standard filter dynamics */
    else
    {
      GDB_Math_LowPassFilter(&SPMData.SPMBlockageProbability, ProbOut, SPM_BLK_A_OUTPUT_FILTER_FAST);
    }
    /* for confidence always fast filtering is used */
    GDB_Math_LowPassFilter(&SPMData.SPMBlockageConfidence, ConfOut, SPM_BLK_A_OUTPUT_FILTER_FAST);
  }
  else
  {
    /* Init Cycle: Filtered Values are 0, Current Values are valid */
    if(ConfOut > SPM_CONFIDENCE_MIN)
    {
      SPMData.SPMBlockageConfidence  = ConfOut;
      SPMData.SPMBlockageProbability = ProbOut;
    }
  }
} /*PRQA S 7002 */ /*2020-04-27, reviewer:Opreai01, PopaM, PalloI, reason: Warning appear due to cyclomatic complexity is to high */

#if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)||(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON))
  void SPMGetRoadBeamData(const PerfDegr_t *pPerfDegrData)
  {
    #if (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD_RB)
      SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibility        = pPerfDegrData->RoadBeam[SYS_SCAN_NEAR].RoadVisibility;
      SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibilityQuality = pPerfDegrData->RoadBeam[SYS_SCAN_NEAR].iQuality;
      #if(ALGO_CFG_FarScanAvailable)
        SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibility        = pPerfDegrData->RoadBeam[SYS_SCAN_FAR].RoadVisibility;
        SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibilityQuality = pPerfDegrData->RoadBeam[SYS_SCAN_FAR].iQuality;
      #endif
    #endif
  }
#endif


void SPMDetermineBlockageState(
                                #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
                                  const PerfDegr_t *pPerfDegrData
                                #else
                                  void
                                #endif
                                )
{
  boolean bIsFullDampCondition = b_FALSE;
  boolean bIsINCDampCondition = b_FALSE;
  boolean bIsRDCtoFullDampCondition = b_FALSE;
  #if(SPM_FULL_DAMP_WITH_NO_REL_OBJ == SWITCH_ON)
    sint32 RelObjID;
    /* Temporary change of prefix to ensure compatibility in EBA */
    RelObjID = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
  #endif

  #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
    boolean bCameraDampCondition;
    bCameraDampCondition = CheckDampConditionbyCamera(pPerfDegrData);
  #endif

  /* Determine blockage state only if blockage is enabled */
  if(SPMBlockageParameters.bEnableBlockage == (boolean)SWITCH_ON)
  {
    /******************************************************/
    /* Start State Machine only after successful Selftest */
    /******************************************************/
    if(SPMData.SPMSelftestState == GDB_PD_ON)
    {
      /* FullBlockageTimer has reached the threshold now */
      switch(SPMData.SPMBlockageState)
      {
        /*********************************************************/
        /* Continue here if current State is GDB_NO_DAMP or GDB_INC_DAMP */
        /*********************************************************/
        case GDB_NO_DAMP:
        case GDB_INC_DAMP:
          /***********************/
          /* GDB_FULL_DAMP criterion */
          /***********************/
          bIsFullDampCondition = CheckDampCondition(SPM_BLK_PROB_FACTOR_FULL_DAMP);
          bIsINCDampCondition  = CheckDampCondition(SPM_BLK_PROB_FACTOR_INC_DAMP);
          if(
              (
                (bIsFullDampCondition == b_TRUE)
                #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
                  &&(bCameraDampCondition == b_TRUE)
                #endif
              )
              #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
              ||(SPMData.SPMALNPartialDamp == GDB_FULL_DAMP )
              #endif
              #if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON))
              ||( SPMData.SPMFullBlockageGenByALN == TRUE)
              #endif
            )
          {
            #if(SPM_FULL_DAMP_WITH_NO_REL_OBJ == SWITCH_ON)
              if(RelObjID == OBJ_INDEX_NO_OBJECT)
              {
                /* go into FULL_DAMP if "wait for new relevance" timer is expired or number of */
                /* relevance losses exceeds the threshold (avoid being in NO_DAMP with toggeling relevance) */
                if(SPMData.SPMFullBlockageTimer >= SPM_SEARCH_FOR_NEW_REL_OBJ_DELAY)
                {
            #endif

            #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON)
                  if(
                      (SPMData.bSPMPreventBlckIfHighTempNoRain == b_FALSE)
                  #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
                    ||(pPerfDegrData->Camera.fQuality >= SPM_CAMERA_MIN_QUALITY_THLD)
                  #endif
                    )
                  {
            #endif

                SPMData.SPMBlockageState = GDB_FULL_DAMP;

            #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON)
                  }
            #endif

            #if(SPM_FULL_DAMP_WITH_NO_REL_OBJ == SWITCH_ON)
                  SPMData.SPMFullBlockageTimer = 0.0F;
                }
                else
                {
                  SPMData.SPMFullBlockageTimer += fCycleTime;
                }
              }
              else
              {
                if(SPM_OBJECT_LOST)
                {
                  SPMData.SPMBlockageState = GDB_FULL_DAMP;
                }
                SPMData.SPMFullBlockageTimer = 0.0F;
              }
            #endif
          }
          /**********************/
          /* GDB_INC_DAMP criterion */
          /**********************/
          else if(bIsINCDampCondition == b_TRUE)
          {
            SPMData.SPMBlockageState = GDB_INC_DAMP;
          }

          /* Report increasing blockage if range observer is reporting blockage but full damp is not triggered,
             which means that the RangeWeight must be 0.0f due to an available relevant object. */
          else if(
                   (SPMData.SPMBlockageRangeProb >= SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB)
                 &&(SPMData.SPMBlockageRangeConf >= SPM_BLOCKAGE_LOWEST_RANGE_CONF)
                 )
          {
            SPMData.SPMBlockageState = GDB_INC_DAMP;
          }
        #if (SPM_INC_DAMP_WITH_REL_OBJ_LOST == SWITCH_ON)
            /* If more than 0 object losses are reported and Temperature and Wiper signal not used
             or High temp and Rain is not detected, trigger increasing damping */
          else if(
                   (SPMData.bSPMPreventBlckIfHighTempNoRain == b_FALSE)
                 &&(SPM_OBJECT_LOST)
                 )
          {
            SPMData.SPMBlockageState = GDB_INC_DAMP;
          }
        #endif
          /*********************/
          /* GDB_NO_DAMP criterion */
          /*********************/
          else if(
                   (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / SPM_BLOCKAGE_GDB_INC_DAMP_NO_DAMP_DIV_FACTOR))
                 &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
                 )
          {
            SPMData.SPMBlockageState = GDB_NO_DAMP;
          }
          /****************************************************/
          /* No criterion is fulfilled, current State is kept */
          /****************************************************/
          else
          {
            /* keep current state */
          }
          break;

        /***********************************************************/
        /* Continue here if current State is GDB_FULL_DAMP or GDB_RDC_DAMP */
        /***********************************************************/
        case GDB_FULL_DAMP:
        case GDB_RDC_DAMP:
          /*********************/
          /* GDB_NO_DAMP criterion */
          /*********************/
          bIsRDCtoFullDampCondition = CheckDampCondition(SPM_BLK_PROB_FACTOR_RDC_TO_FULL_DAMP);

          if(
              (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / SPM_BLOCKAGE_GDB_RDC_DAMP_NO_DAMP_DIV_FACTOR))
            &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
          #if(SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
            &&(SPMData.SPMSRDSysDamp == GDB_NO_DAMP)
            &&(SPMData.SPMReactivationDelayTimer <= SPM_REACTIVATION_DELAY_THLD)
          #endif
          #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
            &&(SPMData.SPMALNPartialDamp == GDB_NO_DAMP)
          #endif
          #if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON))
            &&(SPMData.SPMFullBlockageGenByALN == FALSE)
          #endif
            )
          {
            #if(SPM_DELAY_REACTIVATION)
            if(SPMData.bSPMDelayTimerSet == FALSE)
              {
                SPM_v_SetDelayCounter();
              }
              if(SPMData.SPMDelayReactivationTimer <= 0.0F) /* SatisfyReq: ARS510VW19: UE_1322, UE_3148*/
              {
                SPMData.bSPMDelayTimerSet = FALSE;
            #endif
                SPMData.SPMBlockageState = GDB_NO_DAMP;
            #if(SPM_DELAY_REACTIVATION)
              }
              else if(SPMData.SPMDelayReactivationTimer > 0.0F)
              {
                SPMData.SPMDelayReactivationTimer = SPMData.SPMDelayReactivationTimer - fCycleTime; /* SatisfyReq: ARS510VW19: UE_254 */
              }
              else
              {
                /* nothing to be done here as timer will not be decremented anymore*/
              }
            #endif
          }
          /**************************/
          /* GDB_RDC_DAMP criterion */
          /**************************/
          else if(
                   (
                     (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB * SPM_BLOCKAGE_GDB_RDC_DAMP_DIV_FACTOR))
                   &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
                   #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE)
                   &&(SPMData.SPMALNPartialDamp != GDB_FULL_DAMP)
                   #endif
                   )
                  #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
                   ||(SPMData.SPMALNPartialDamp == GDB_RDC_DAMP)
                  #endif
                  #if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON))
                   &&( SPMData.SPMFullBlockageGenByALN == FALSE)
                  #endif
                 )
          {
            SPMData.SPMBlockageState = GDB_RDC_DAMP;
          }
          /***************************/
          /* GDB_FULL_DAMP criterion */
          /***************************/
          else if(
                   (bIsRDCtoFullDampCondition == b_TRUE)
               #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
                 ||(SPMData.SPMALNPartialDamp == GDB_FULL_DAMP)
               #endif
                 )
          {
            SPMData.SPMBlockageState = GDB_FULL_DAMP;
            #if(SPM_DELAY_REACTIVATION)
              SPMData.SPMDelayReactivationTimer = SPM_DELAY_REACTIVATION_TIME_INVALID;
              SPMData.bSPMDelayTimerSet = FALSE;
            #endif
          }
          else
          {
            /* keep state */
          }
          break;

      #ifdef GDB_UNKNOWN_DAMP  /*!< New state introduced in new RTE versions : check for existence for compatibility with old RTE */
        case GDB_UNKNOWN_DAMP:
      #endif
        default:
          // for misra bIsRDCtoFullDampCondition = FALSE;
          break;  /* error case */
      }
    }
    else
    { 
      /* Not in GDB_PD_ON mode -> Selftest active or Selftest failed */ 
    }
  }
  else 
  {
    // set always "no damp" if blockage is disabled
    SPMData.SPMBlockageState = GDB_NO_DAMP;
  }
}

#if (SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
  void SPMALNPartialBlockageState(const e_AlignState_t eAlignState, const fSpeed_t fOwnSpeed )
  {
    /* ALN activated partial damping first time)*/
    if(
        (eAlignState == ALNMonPartialBlockage)
      &&(SPMData.SPMALNPartialDamp != GDB_FULL_DAMP)
      )
    {
      SPMData.SPMALNPartialDamp = GDB_FULL_DAMP;
      SPMData.SPMALNPartialDampDelayTimer = SPM_BLOCKAGE_REACTIVATION_DELAY;
    }
    /* ALN Partial Blockage is not activ or was deactivated*/
    else if(eAlignState != ALNMonPartialBlockage)
    {
      /* ALN reports no partial damping : see what current state is */
      if(SPMData.SPMALNPartialDamp == GDB_NO_DAMP)
      {
        /* current SPMALNPartialDamp remains in GDB_NO_DAMP */
      }
      /* ALN activated partial damping before -> system remains active -> check delay timer */
      else if(
                (SPMData.SPMALNPartialDamp == GDB_FULL_DAMP)
              ||(SPMData.SPMALNPartialDamp == GDB_RDC_DAMP)
             )
      {
        /* ALN Partial Blockage was deactivated  and delay timer is still active -> system remains deactivated */
        if(SPMData.SPMALNPartialDampDelayTimer > SPM_REACTIVATION_DELAY_THLD)
        {
          SPMData.SPMALNPartialDamp = GDB_RDC_DAMP;
          /* subtract cycle time only if vehicle is moving with min. SPM speed */
          if (fOwnSpeed > SPM_SPEED_MIN)
          {
            SPMData.SPMALNPartialDampDelayTimer -= fCycleTime;   /* subtract cycle time from reactivation delay timer */
          }
        }
        /* ALN Partial Blockage was deactivated and delay timer has expired */
        else
        {
          SPMData.SPMALNPartialDamp =  GDB_NO_DAMP;
        }
      }
      else
      {
        // nop, for MISRA happy
      }
    }
    /* ALN Partial Blockage is still active*/
    else
    {
      /* ALN Partial Blockage and delay timer are still active  */
      if(SPMData.SPMALNPartialDampDelayTimer > SPM_REACTIVATION_DELAY_THLD)
      {
        /* subtract cycle time only if vehicle is moving with min. SPM speed */
        if (fOwnSpeed > SPM_SPEED_MIN)
        {
          SPMData.SPMALNPartialDampDelayTimer -= fCycleTime;   /* subtract cycle time from reactivation delay timer */
        }
      }
    }
  }
#endif


#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
void SPMALNPartialBlockage(float32 f_Probability, float32 f_Confidence)
{
  if( (CML_f_IsZero(f_Probability - 1.0F)) && (CML_f_IsZero(f_Confidence - 1.0F)))
  {
    SPMData.SPMFullBlockageGenByALN = b_TRUE;
  }
  else if((CML_f_IsZero(f_Probability)) && (CML_f_IsZero(f_Confidence - 1.0F)))
  {
    SPMData.SPMFullBlockageGenByALN = b_FALSE;
  }
  else 
  {
    /* do nothing*/
  }
}
#endif

#if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
  boolean CheckDampConditionbyCamera(const PerfDegr_t *pPerfDegrData)
  {
    boolean bResult= FALSE;
    boolean bTargetRate[SYS_NUM_OF_SCANS];
    uint8 idx;
    float32 fTargetRateMov[SYS_NUM_OF_SCANS];
    float32 fTargetRateStat[SYS_NUM_OF_SCANS];
    bTargetRate[SYS_SCAN_NEAR]= FALSE;
    #if(ALGO_CFG_FarScanAvailable)
      bTargetRate[SYS_SCAN_FAR]= FALSE;
    #endif
      for(idx = SYS_SCAN_NEAR; idx < SYS_NUM_OF_SCANS; idx++)
    {
      fTargetRateMov[idx] = pPerfDegrData->TargetRate[idx].fTargetRateMov;
      fTargetRateStat[idx] = pPerfDegrData->TargetRate[idx].fTargetRateStat;
      if(
          (fTargetRateMov[idx] < SPM_TARGET_RATE_THLD)
        &&(fTargetRateStat[idx] < SPM_TARGET_RATE_THLD)
        )
      {
        bTargetRate[idx] = TRUE;
      }
    }

    if(
        (
          (pPerfDegrData->Camera.fQuality > SPM_CAMERA_MIN_QUALITY_THLD)
        &&(pPerfDegrData->Camera.fRatio < SPM_CAMERA_MIN_RATIO_THLD)
        )
      ||(
          (bTargetRate[SYS_SCAN_NEAR] == TRUE)
      #if(ALGO_CFG_FarScanAvailable)
        &&(bTargetRate[SYS_SCAN_FAR] == TRUE)
      #endif
        )
      ||(SPMObjectLoss.fDeselectionTimer > SPM_DESELECT_TIME_MULTYPLY_FACTOR * SPM_CYCLE_TIME)
      ||(SPM_OBJECT_LOST)
      )
    {
      bResult = TRUE;
    }
    return bResult;
  }
#endif


boolean CheckDampCondition(const float32 fProbFactor)
{
  boolean bReturnValue = b_FALSE;

#if (SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM)
  float32 fOwnspeed = fABS(fEgoSpeed);
#endif

#if(SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)
  #if(ALGO_SensorType != ALGO_CFG_ARS400Entry)
    if(
        (SPMBlockageParameters.bUseRoadbeam[SYS_SCAN_FAR] == TRUE)
        &&(fOwnspeed >= SPMBlockageParameters.fRoadbeamSpeedMin[SYS_SCAN_FAR])
        &&(SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibilityQuality > SPMBlockageParameters.uRoadVisibilityQualityThresh[SYS_SCAN_FAR])
      )
  #else
    if(
        (SPMBlockageParameters.bUseRoadbeam[SYS_SCAN_NEAR] == TRUE)
        &&(fOwnspeed >= SPMBlockageParameters.fRoadbeamSpeedMin[SYS_SCAN_NEAR])
        &&(SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibilityQuality > SPMBlockageParameters.uRoadVisibilityQualityThresh[SYS_SCAN_NEAR])
      )
  #endif
    {
      if(
          (SPMData.SPMBlockageProbability >= (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB*fProbFactor))
        &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
     #if(ALGO_SensorType != ALGO_CFG_ARS400Entry)
        &&(SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibility < SPMBlockageParameters.uRoadVisibilityThresh[SYS_SCAN_FAR])
     #else
        &&(SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibility < SPMBlockageParameters.uRoadVisibilityThresh[SYS_SCAN_NEAR])
     #endif
        )
        {
          bReturnValue = b_TRUE;
        }
    }
    else
    {
#endif
      if(
          (SPMData.SPMBlockageProbability >= (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB*fProbFactor))
        &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
        )
        {
          bReturnValue = b_TRUE;
        }
#if (SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)
    }
#endif
  return bReturnValue;
}


float32 SPMMapRangeToProbability( const PerfDegr_t *pPerfDegrData, const float32 ShutOffValue, const float32 ShutOnValue, const uint8 uScanIndex)
{
  float32 fProbability;
  #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
    float32 fHelpRangeGradient;
  #endif
  GDB_Math_Point_t RangeDown, RangeUp;
  /****************************************************************************************/
  /*  Map Range Value from Distance to Blockage Probability, Confidence remains unchanged */
  /****************************************************************************************/

  /*

  BlockProb(y)
      |
    1 +__________
      |          \
      |           \
      |            \                      (example for linear interpolation between 1 and 0)
      |             \
      |              \
    0 +               \________________
      |
      +----------+----+-----------------> Range(x) 
                Down  Up
  */

  RangeDown.X = SPMBlockageParameters.fLowerRange[uScanIndex];/* Lower Range Threshold */
  RangeDown.Y = 1.0F;
  RangeUp.X   = ShutOnValue;/* Upper Range Threshold */
  RangeUp.Y   = 0.0F;

  // Copy range and confidence into SPM structure
  #if(EM_PERF_DEGR_INTFVER >= EM_PERF_INT_VER_THLD)
    SPMData.SPMBlockageRange = pPerfDegrData->RangeFused[uScanIndex].fFusedRange;
    SPMData.SPMBlockageRangeConf = pPerfDegrData->RangeFused[uScanIndex].fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
    #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
      SPMData.SPMBlockagePreviousRange[uScanIndex] = SPMData.SPMBlockageCurrentRange[uScanIndex];
      SPMData.SPMBlockageCurrentRange[uScanIndex] = pPerfDegrData->RangeFused[uScanIndex].fFusedRange;
      if(CML_f_IsNonZero(SPMData.SPMBlockageCurrentRange[uScanIndex] + 1) && CML_f_IsNonZero(SPMData.SPMBlockagePreviousRange[uScanIndex] + 1) )
      {
        fHelpRangeGradient = (SPMData.SPMBlockageCurrentRange[uScanIndex] - SPMData.SPMBlockagePreviousRange[uScanIndex]) / fCycleTime;
        GDB_Math_LowPassFilter(&SPMData.SPMBlockageRangeGradient[uScanIndex], fHelpRangeGradient, SPM_GRADIENT_FILTER_FACTOR);
      }
    #endif
  #else
    SPMData.SPMBlockageRange = pPerfDegrData->RangeFused.fFusedRange;
    SPMData.SPMBlockageRangeConf = pPerfDegrData->RangeFused.fFusedConf / SPM_RANGE_CONF_SCALE_FACTOR;
  #endif
  SPMData.SPMBlockageRangeConf = CML_f_Min(SPM_MINMAX_HIGH_THLD, SPMData.SPMBlockageRangeConf);

  /* if range is below threshold and confidence is good enough, increment hold timer */
  if(
      (SPMData.SPMBlockageRange < ShutOffValue)
    &&(SPMData.SPMBlockageRangeConf > SPM_STATE_CONF_MIN)
    )
  {
    /* shutoff range reached with trustworthy confidence, increment hold timer */
    SPMData.SPMRangeHoldCounter = SPMData.SPMRangeHoldCounter + fCycleTime;
  }

  /* if in FULL_DAMP, reset counter */
  if(    (SPMData.SPMBlockageState == GDB_FULL_DAMP)
      || (SPMData.SPMBlockageState == GDB_RDC_DAMP ) )
  {
    SPMData.SPMRangeHoldCounter = 0.0F;
  }

  /* map range to probability only if hold counter is full or blockage is reported */
  if(
      (SPMData.SPMBlockageRange > 0.0F)
    &&(
        (SPMData.SPMRangeHoldCounter >= SPM_RANGE_HOLD_COUNTER_THLD)
      ||(SPMData.SPMBlockageState == GDB_FULL_DAMP)
      ||(SPMData.SPMBlockageState == GDB_RDC_DAMP)
      )
    )
  {
    fProbability = GDB_Math_LinInterpol(RangeDown, RangeUp, SPMData.SPMBlockageRange);
  }
  else
  {
    fProbability = 0.0F;
  }

  #if(SPM_INCREASE_RANGE_CONF == SWITCH_ON)
    if(SPMObjectLoss.uiNoOfObjLosses == SPM_ONE_OBJECT_LOST)
    {
      SPMData.SPMBlockageRangeConf = CML_MinMax(SPM_MINMAX_LOW_THLD, SPM_MINMAX_HIGH_THLD, 
                                                  (SPMData.SPMBlockageRangeConf * (SPM_CONF_ADAPT_FACTOR_ONE_LOSS)));
    }
    else if(SPMObjectLoss.uiNoOfObjLosses == SPM_TWO_OBJECTS_LOST)
    {
      SPMData.SPMBlockageRangeConf = CML_MinMax(SPM_MINMAX_LOW_THLD, SPM_MINMAX_HIGH_THLD, 
                                                  (SPMData.SPMBlockageRangeConf * (SPM_CONF_ADAPT_FACTOR_TWO_LOSSES)));
    }
    else if(SPMObjectLoss.uiNoOfObjLosses == SPM_THREE_OBJECTS_LOST)
    {
      SPMData.SPMBlockageRangeConf = CML_MinMax(SPM_MINMAX_LOW_THLD, SPM_MINMAX_HIGH_THLD, 
                                                  (SPMData.SPMBlockageRangeConf * (SPM_CONF_ADAPT_FCTOR_THREE_LOSSES)));
    }
    else
    {
      /*do nothing*/
    }
  #endif

  /* limit probability within 0 and 1 */
  fProbability = CML_f_MinMax(SPM_PROBABILITY_MIN, SPM_PROBABILITY_MAX, fProbability);
  return fProbability;
}
 
#if(ALGO_CFG_FarScanAvailable)
  #if(SPM_USE_AREA_CONVOLUTION_FOR_RANGE_FUSION == SWITCH_ON)

    float32 SPMComputationOfFusionCoef(const float32 fProbability, const float32 fConfidence)
    {
      float32 fCoeficient;
      if(CML_f_IsNonZero(fProbability + 1.0f))
      {
        if(fProbability >= fConfidence)
        {
          fCoeficient = fConfidence * fConfidence;
        }
        else
        {
          fCoeficient = fProbability * (2 * fConfidence - fProbability);
        }
      }
      else
      {
        fCoeficient = 0.0f;
      }
      return fCoeficient;
    }


    void SPMFuseRangeScanDataUsingAreaConvolution(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence)
    {
      float32 fAlpha1, fAlpha2;
      fAlpha1 = SPMComputationOfFusionCoef(fNearRangeProbability, fNearRangeConfidence);
      fAlpha2 = SPMComputationOfFusionCoef(fFarRangeProbability, fFarRangeConfidence);
      if(fAlpha1 + fAlpha2 > C_F32_DELTA)
      {
        SPMData.SPMBlockageRangeConf = (fAlpha1 * fNearRangeConfidence + fAlpha2 * fFarRangeConfidence) / (fAlpha1 + fAlpha2);
        SPMData.SPMBlockageRangeProb = (fAlpha1 * fNearRangeProbability + fAlpha2 * fFarRangeProbability) / (fAlpha1 + fAlpha2);
      }
      else
      {
        SPMData.SPMBlockageRangeConf = 0.5F * (fNearRangeConfidence + fFarRangeConfidence);
        SPMData.SPMBlockageRangeProb = 0.5F * (fNearRangeProbability + fFarRangeProbability);
      }
    }
  #else
    void SPMFuseRangeScanDataNew(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence)
    {
      if((fNearRangeConfidence > C_F32_DELTA)||(fFarRangeConfidence > C_F32_DELTA))
      {
        if((fNearRangeProbability >= fFarRangeProbability) && (fNearRangeConfidence >= fFarRangeConfidence))
        {
          SPMData.SPMBlockageRangeProb = fNearRangeProbability;
          SPMData.SPMBlockageRangeConf = fNearRangeConfidence;
        }
        else if ((fNearRangeProbability<=fFarRangeProbability) && (fNearRangeConfidence<=fFarRangeConfidence))
        {
          SPMData.SPMBlockageRangeProb = fFarRangeProbability;
          SPMData.SPMBlockageRangeConf = fFarRangeConfidence;
        }
        else if ((fNearRangeProbability >= fFarRangeProbability) && (fNearRangeConfidence <= fFarRangeConfidence))
        {
          if(fNearRangeConfidence >= SPM_STATE_CONF_MIN)
          {
            SPMData.SPMBlockageRangeProb = fNearRangeProbability;
            SPMData.SPMBlockageRangeConf = fNearRangeConfidence;
          }
          else
          {
            SPMStandardDeviationFuse(fNearRangeProbability, fFarRangeProbability, fNearRangeConfidence, fFarRangeConfidence); 
          }
        }
        else if ((fNearRangeProbability <= fFarRangeProbability) && (fNearRangeConfidence >= fFarRangeConfidence))
        {
          if(fFarRangeConfidence >= SPM_STATE_CONF_MIN)
          {
            SPMData.SPMBlockageRangeProb = fFarRangeProbability;
            SPMData.SPMBlockageRangeConf = fFarRangeConfidence;
          }
          else
          {
            //Call fuse function
            SPMStandardDeviationFuse(fNearRangeProbability, fFarRangeProbability, fNearRangeConfidence, fFarRangeConfidence);
          }
        }
        else
        {
          /*  Dummy 'else' condition, for solving QAC error   */
        }
      }
      else
      {
        /* do nothing*/
      }
    }


    void SPMStandardDeviationFuse(const float32 fNearRangeProbability, const float32 fFarRangeProbability, const float32 fNearRangeConfidence, const float32 fFarRangeConfidence)
    {
      float32 fSum,fMean, fSigma,fConfHelp1,fConfHelp2;
      fSum = fNearRangeConfidence + fFarRangeConfidence; /* sum of confidence */
      fConfHelp1 = CML_f_Max(fNearRangeConfidence, fFarRangeConfidence); /* maximum of confidence */
      /* compute the mean of probabilities and standard deviation */
      if(fSum > C_F32_DELTA)
      {
        fMean  = ((fNearRangeConfidence * fNearRangeProbability) + (fFarRangeConfidence * fFarRangeProbability)) / fSum;
        fSigma = ((fNearRangeConfidence * CML_Sqr(fNearRangeProbability - fMean)) + (fFarRangeConfidence * CML_Sqr(fFarRangeProbability - fMean))) / fSum;
        fSigma = CML_f_Sqrt(fSigma);
        fConfHelp2 = SPM_SIGMA_INIT_VALUE - (fSigma / SPM_SIGMA_DIV_FACTOR);
        SPMData.SPMBlockageRangeConf = fConfHelp1 * fConfHelp2;
        SPMData.SPMBlockageRangeProb = fMean + (fSigma * SPM_SIGMA_MULTIPLY_FACTOR);
      }
    }
  #endif
#endif

void SPMBlockageSetDEMEvents (AlgoErrorState_t *puiBlockageEvent)
{
  /*****************************************************/
  /*          Set current ARS blockage events          */
  /*****************************************************/

  /* Set Events/Inhibitions/SW-Errors */
  switch (SPMData.SPMBlockageState)
  {
    case GDB_NO_DAMP:
      /* No system damping detected */
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
      /* set blockage flag only after passed selftest */
      if(SPMData.SPMSelftestState == GDB_PD_ON)
      {
        *puiBlockageEvent = AL_ERR_STATE_INACTIVE;
      }
    #if(SPM_BLOCKAGE_STATE_UNKNOWN_IN_STARTUP == SWITCH_ON)
      else if(SPMData.SPMSelftestState == GDB_PD_STARTUP)
      {
        *puiBlockageEvent = AL_ERR_STATE_UNKNOWN;
        SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_UNKNOWN);
      }
      else
      {
        // for QAC
      }
    #endif
      break;

    case GDB_INC_DAMP:
      /* Increasing system damping detected */
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_ACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
      /* set blockage flag only after passed selftest */
      if(SPMData.SPMSelftestState == GDB_PD_ON)
      {
        *puiBlockageEvent = AL_ERR_STATE_INACTIVE;
      }
      break;

    case GDB_FULL_DAMP:
      /* System damping detected */
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_ACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
      /* set blockage flag only after passed selftest */
      if(SPMData.SPMSelftestState == GDB_PD_ON)
      {
        *puiBlockageEvent = AL_ERR_STATE_ACTIVE;
      }
      break;

    case GDB_RDC_DAMP:
      /* Reducing system damping detected */
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_ACTIVE);
      /* set blockage flag only after passed selftest */
      if(SPMData.SPMSelftestState == GDB_PD_ON)
      {
        *puiBlockageEvent = AL_ERR_STATE_ACTIVE;
      }
      break;

  #ifdef GDB_UNKNOWN_DAMP  /*!< New state introduced in new RTE versions : check for existence for compatibility with old RTE */
    case GDB_UNKNOWN_DAMP:
  #endif

    default:
      *puiBlockageEvent = AL_ERR_STATE_ACTIVE;
      break;
  }

/******************************************************************/
/* SRR blockage event handling, execute only if SRR is available  */
/*        Precondition: ARS events have to be set                 */
/******************************************************************/
#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
  SPMBlockageSetSRRDEMEvents();
#endif
}

#if(SPM_OBSERVERS_HISOTRY)
void SPMSetObserversState(void)
{
#if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_OFF))
  if(SPMData.SPMFullBlockageGenByALN == b_TRUE)
  {
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_ACTIVE);
  }
  else
  {
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_INACTIVE);
  }
#endif

  /* set as observers as inactive when no blockage is reported*/
  if(SPMData.SPMBlockageState == GDB_NO_DAMP)
  {
    SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_INACTIVE);
    SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_INACTIVE);
    SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_INACTIVE);
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_OFF)
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_INACTIVE);
#else
  #if(SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON)
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_INACTIVE);
  #endif
#endif
  }
  else if(SPMData.SPMBlockageState == GDB_FULL_DAMP)
  {
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_OFF)
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_INACTIVE);
#else
  #if(SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON)
    SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_INACTIVE);
  #endif
#endif
    if( (SPMData.SPMBlockageProbability >= SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB) &&
              (SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
            )
    {
      if(CML_f_IsZero(SPMData.SPMCurrentObjLossWeight - 1.0F))
      {
        SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_ACTIVE);
        SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_INACTIVE);
        SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_INACTIVE);
      }
      else if(  (CML_f_IsZero(SPMData.SPMCurrentRangeWeight - 1.0F) && CML_f_IsZero(SPMData.SPMCurrentTimeoutWeight - 0.02F))
              ||(CML_f_IsZero(SPMData.SPMCurrentRangeWeight - 0.8F) && CML_f_IsZero(SPMData.SPMCurrentTimeoutWeight - 0.2F))
              )
      {
        SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_INACTIVE);
        SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_INACTIVE);
        SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_ACTIVE);
      }
      else if(CML_f_IsZero(SPMData.SPMCurrentTimeoutWeight - 1.0F))
      {
        SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_INACTIVE);
        SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_ACTIVE);
        SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_INACTIVE);
      }
      else
      {
        SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_INACTIVE);
        SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_ACTIVE);
        SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_ACTIVE);
      }
    }
    else
    {
      /* nothing to do here */
    }

#if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE == SWITCH_ON))
    // Check which observer triggered blockage and set corresponding event as active
    if(SPMData.SPMFullBlockageGenByALN == b_TRUE)
    {
      SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE, AL_ERR_STATE_ACTIVE);
      SPMSetErrorState(SPM_ERREV_OBJ_LOSS, AL_ERR_STATE_INACTIVE);
      SPMSetErrorState(SPM_ERREV_TIMEOUT, AL_ERR_STATE_INACTIVE);
      SPMSetErrorState(SPM_ERREV_RANGE, AL_ERR_STATE_INACTIVE);
    }
#endif
  }
  else
  {
    /* nothing to do here */
  }
}
#endif

#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
  void SPMBlockageSetSRRDEMEvents(void)
  {
    /**************************************************/
    /*              SRR reports GDB_FULL_DAMP         */
    /**************************************************/
    if(SPMData.SPMSRDSysDamp == GDB_FULL_DAMP)
    {
      /* always set SRD_DAMP event */
      SPMSetErrorState( SPM_ERREV_SRD_SYS_DAMP,AL_ERR_STATE_ACTIVE);

      /* ARS does not report FULL_DAMP -> reset INC/RDC ARS events */
      if(SPMData.SPMBlockageState != GDB_FULL_DAMP)
      {
        SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
        SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
      }
      /* ARS reports GDB_FULL_DAMP -> do nothing */
      else
      {
        /* GDB_FULL_DAMP event has already been set */
      }
    }
    /****************************************************/
    /*                  SRR reports NO_DAMP/INC_DAMP/RDC_DAMP and the system was deactivate before ->check the ARS algorithm before reactivate the system */
    /****************************************************/
    else if(
             (SRDDampingState.CurrentState == GDB_FULL_DAMP)
      #ifdef GDB_UNKNOWN_DAMP  /*!< New state introduced in new RTE versions : check for existence for compatibility with old RTE */
           &&(SPMData.SPMSRDSysDamp != GDB_UNKNOWN_DAMP)
      #endif
           )
    {
      /* ARS fulfills the condition for reactivation*/
      if(
          (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / SPM_BLOCKAGE_GDB_RDC_DAMP_NO_DAMP_DIV_FACTOR))
        &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
        )
      {
        /* reset SRD DEM event*/
        SPMSetErrorState(SPM_ERREV_SRD_SYS_DAMP,AL_ERR_STATE_INACTIVE);
        /* ARS does not report GDB_FULL_DAMP -> overwrite ARS events with GDB_RDC_DAMP event */
        if(SPMData.SPMBlockageState != GDB_FULL_DAMP)
        {
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_ACTIVE);
        }
        /* ARS reports GDB_FULL_DAMP -> do nothing */
        else
        {
        /* GDB_FULL_DAMP event has already been set */
        }
      }
      /* ARS does not fulfill the condition for reactivation*/
      else
      {
        /* keep the previos SPM_ERREV_SRD_SYS_DAMP state */
        /* ARS does not report GDB_FULL_DAMP */
        if(SPMData.SPMBlockageState != GDB_FULL_DAMP)
        {
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
        }
        /* ARS reports GDB_FULL_DAMP -> do nothing */
        else
        {
          /* GDB_FULL_DAMP event has already been set */
        }
      }
    }

    /******************************************************/
    /*             current SRR state NO_DAMP/INC_DAMP/RDC_DAMP and the state of system based on SRR is different by 2 (increase or reduce)    */
    /******************************************************/
    else
    {
      /* check the previous state in order to see from which state we are comming*/

      /*the system comming from NO_DAMP/INC/RDC*/
      if(SRDDampingState.PreviousState != GDB_FULL_DAMP)
      {
        SPMSetErrorState( SPM_ERREV_SRD_SYS_DAMP,AL_ERR_STATE_INACTIVE);
        /* ARS does not report GDB_FULL_DAMP -> overwrite ARS events with GDB_RDC_DAMP event */
        if(SPMData.SPMBlockageState == GDB_NO_DAMP)
        {
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
          SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
        }
      }
      /* the system is comming from FULL_DAMP -> check the ARS algo in order to reactivate the system*/
      else
      {
        /* ARS fulfills the condition for reactivation */
        if(
            (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / SPM_BLOCKAGE_GDB_RDC_DAMP_NO_DAMP_DIV_FACTOR))
          &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
          )
        {
          /* reset SRD DEM event*/
          SPMSetErrorState(SPM_ERREV_SRD_SYS_DAMP,AL_ERR_STATE_INACTIVE);
          //SRDDampingState.PreviousState = GDB_NO_DAMP;
          if(SPMData.SPMBlockageState == GDB_NO_DAMP)
          {
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_INACTIVE);
          }
        }
        /* ARS does not fulfill the condition for reactivation but the condition for RDC_DAMP -> set RDC active*/
        else if(
                 (SPMData.SPMBlockageProbability < (SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB * SPM_BLK_PROB_FACTOR_RDC_TO_FULL_DAMP))
               &&(SPMData.SPMBlockageConfidence >= SPM_STATE_CONF_MIN)
               )
        {
          SPMSetErrorState(SPM_ERREV_SRD_SYS_DAMP,AL_ERR_STATE_INACTIVE);
          /* ARS does not report GDB_FULL_DAMP -> overwrite ARS events with GDB_RDC_DAMP event */
          if(SPMData.SPMBlockageState != GDB_FULL_DAMP)
          {
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_INC_DAMP,AL_ERR_STATE_INACTIVE);
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_INACTIVE);
            SPMSetErrorState( SPM_ERREV_BLOCKAGE_RDC_DAMP,AL_ERR_STATE_ACTIVE);
          }
        }
        else
        {
          /*keep previos DEM events*/
        }
      }
    }
  }
#endif

#if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
  boolean bCheckIfRelevantObjChangedToNeighbour(void)
  {
    boolean bReturnValue = FALSE;
    /*Save ID of relevance object for the last cycle bevor is loss the relevance */
    if(
        (SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI) != OBJ_NOT_OOI)
      &&(SPMData.SPMLastRelObjID != SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI))
      )
    {
      SPMData.SPMLastRelObjID = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
    }
    /*check if the OOI 0 changed the the status to OOI 2 or 3*/
    else if(
             (SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI) == OBJ_NOT_OOI)
           &&(SPMData.SPMLastRelObjID != OBJ_NOT_OOI)
           &&(
               (SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_LEFT_OOI) == SPMData.SPMLastRelObjID)
             ||(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LONG_RIGHT_OOI) == SPMData.SPMLastRelObjID)
             ||(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_LEFT_OOI) == SPMData.SPMLastRelObjID)
             ||(SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_LAT_RIGHT_OOI) == SPMData.SPMLastRelObjID)
             )
           )
    {
      /*OOI 0 is now OOI 2 or 3*/
      bReturnValue = TRUE;
    }
    else
    {
      /*OOI 0  is not changed to OOI 2 or 3 (no lane change) loss of relevant is in case of other reason*/
      SPMData.SPMLastRelObjID = OBJ_NOT_OOI;
    }
    return bReturnValue;
  }
#endif

void SPMSetBlockageParameters(SPMBlockageParameters_t *ps_blockage_internal_parameters, const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters
                              #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER)
                               , const PerfDegr_t *pPerfDegrData
                              #endif
                              #if((SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON))
                               , const ALN_S_Monitoring_t * pAlignmentMonInput
                              #endif
                              )
{
  uint8 uScanIndex;
  boolean bTemp;
#if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON)
  boolean bAllBSWParameterUsed = b_TRUE;
#endif

  /* check for nullpointer */
  if(ps_blockage_algo_parameters != NULL)
  {
    #if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_OFF)
      SPMSetBlockageParametersUsingDefines(ps_blockage_internal_parameters);
    #else
      /* use parameters provided by BSW via RTE but check every signal for plausibility before setting */

      /******************/
      /* Shut off range */
      /******************/
      bAllBSWParameterUsed = SPMSetShutOffRangeThresholds(ps_blockage_algo_parameters, ps_blockage_internal_parameters);
  
      /******************/
      /* Shut on range  */
      /******************/
      bTemp = SPMSetShutOnRangeThresholds(ps_blockage_algo_parameters, ps_blockage_internal_parameters);
      if(bAllBSWParameterUsed == b_TRUE)
      {
        bAllBSWParameterUsed = bTemp;
      }
      /****************************/
      /* Use roadbeam information */
      /****************************/
  #if(ALGO_CFG_FarScanAvailable)
      for(uScanIndex = SYS_SCAN_NEAR; uScanIndex < SYS_NUM_OF_SCANS; uScanIndex++)
      {
        #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
          if(
              (ps_blockage_algo_parameters->ui8_RoadbeamSpeedMin[uScanIndex] > 0u)
            &&(ps_blockage_algo_parameters->ui8_RoadVisibilityMin[uScanIndex] > 0u)
            &&(ps_blockage_algo_parameters->ui8_RoadQualityMin[uScanIndex] > 0u)
            )
          {
            ps_blockage_internal_parameters->fRoadbeamSpeedMin[uScanIndex] = ((float32)ps_blockage_algo_parameters->ui8_RoadbeamSpeedMin[uScanIndex]) / (C_KMH_MS);
            ps_blockage_internal_parameters->bUseRoadbeam[uScanIndex] = ps_blockage_algo_parameters->b_UseRoadbeam[uScanIndex];
            ps_blockage_internal_parameters->uRoadVisibilityThresh[uScanIndex] = ps_blockage_algo_parameters->ui8_RoadVisibilityMin[uScanIndex];
            ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[uScanIndex] = ps_blockage_algo_parameters->ui8_RoadQualityMin[uScanIndex];

          }
          else
          {
        #endif
            ps_blockage_internal_parameters->bUseRoadbeam[uScanIndex] = FALSE;
            ps_blockage_internal_parameters->fRoadbeamSpeedMin[uScanIndex] = SPM_ROADBEAM_AVAILABILITY_SPEED;
            ps_blockage_internal_parameters->uRoadVisibilityThresh[uScanIndex] = SPM_ROADBEAM_VISIBILITY_STRONG_THRESH;
            ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[uScanIndex] = SPM_ROADBEAM_QUALITY_STRONG_THRESH;
            bAllBSWParameterUsed = FALSE;
        #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
          }
        #endif
      }
  #else
    #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
      if(
          (ps_blockage_algo_parameters->ui8_RoadbeamSpeedMin[SYS_SCAN_NEAR] > 0u)
        &&(ps_blockage_algo_parameters->ui8_RoadVisibilityMin[SYS_SCAN_NEAR] > 0u)
        &&(ps_blockage_algo_parameters->ui8_RoadQualityMin[SYS_SCAN_NEAR] > 0u)
        )
      {
        ps_blockage_internal_parameters->uRoadVisibilityThresh[SYS_SCAN_NEAR] = ps_blockage_algo_parameters->ui8_RoadVisibilityMin[SYS_SCAN_NEAR];
        ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[SYS_SCAN_NEAR] = ps_blockage_algo_parameters->ui8_RoadQualityMin[SYS_SCAN_NEAR];
        ps_blockage_internal_parameters->fRoadbeamSpeedMin[SYS_SCAN_NEAR] = ((float32)ps_blockage_algo_parameters->ui8_RoadbeamSpeedMin[SYS_SCAN_NEAR]) / (C_KMH_MS);
        ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = ps_blockage_algo_parameters->b_UseRoadbeam[SYS_SCAN_NEAR];
      }
      else
      {
    #endif
        ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = b_FALSE;
        ps_blockage_internal_parameters->fRoadbeamSpeedMin[SYS_SCAN_NEAR] = SPM_ROADBEAM_AVAILABILITY_SPEED;
        ps_blockage_internal_parameters->uRoadVisibilityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_VISIBILITY_STRONG_THRESH;
        ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_QUALITY_STRONG_THRESH;
        bAllBSWParameterUsed = b_FALSE;
     #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
      }
    #endif
  #endif

  #if (BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
    #if(ALGO_CFG_FarScanAvailable)
      if(ps_blockage_algo_parameters->ui8_UseFarNearScanForBlck <= SPM_USE_ONLY_FAR)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->uUseFarNearScanForBlck =  ps_blockage_algo_parameters->ui8_UseFarNearScanForBlck;
      }
      else
      {
        /* signal unplausible -> use define SPM_USE_MAX_FAR_NEAR=0 -> the Blockage Decision used the Max Probability value of the two Scans */
        ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_MAX_FAR_NEAR;
      }
    #else
        /*use only near scan SPM_USE_ONLY_NEAR =1*/
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_ONLY_NEAR;
    #endif
  #else
    #if(ALGO_CFG_FarScanAvailable)
      /*use define SPM_USE_MAX_FAR_NEAR=0 -> the Blockage Decision used the Max Probability value of the two Scans */
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_MAX_FAR_NEAR;
    #else
      /*use only near scan*/
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_ONLY_NEAR;
    #endif
  #endif

  /**************************/
  /* Use Wiper and Temperatur Signals */
  /**************************/
    #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_WIPER_INT_VER_THLD)
      ps_blockage_internal_parameters->bBlockageUseTemperature = ps_blockage_algo_parameters->b_BlockageUseTemperature;
      ps_blockage_internal_parameters->bBlockageUseWiper = ps_blockage_algo_parameters->b_BlockageUseWiper;
    #else
      ps_blockage_internal_parameters->bBlockageUseTemperature = FALSE;
      ps_blockage_internal_parameters->bBlockageUseWiper = FALSE;
    #endif

  /**************************/
  /* Timeout thresholds */
  /**************************/
    bTemp = SPMSetShutOffTimeoutThreshold(ps_blockage_algo_parameters, ps_blockage_internal_parameters);
    if(bAllBSWParameterUsed == b_TRUE)
    {
      bAllBSWParameterUsed = bTemp;
    }

    /***********************************************/
    /* Number of allowed ObjectLosses (not for SRR)*/
    /***********************************************/
      if(ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses > 0u)
      {
        //signal plausible -> use it
        ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses;
        //change the value of number of allowed object losses based on temperature and wiper information
        #if((SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_WIPER_TEMP_VER_THLD))
          if(pPerfDegrData->Blockage.bSummerWithHighTemp == b_TRUE)
          {
            ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses + 1u;
          }
          else
          {
            ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses;
          }
        #endif
        //change the value of number of allowed object losses based on ALN information
        #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
          //if partial blockage confidence is > 0.5F and partial probability > 0.8F   object loss blockage parameter shall be reduced by one.
          if(    (pAlignmentMonInput->PartialBlockage.f_Confidence  > SPM_PARTIAL_BLK_MIN_CONF_THLD) 
              && (pAlignmentMonInput->PartialBlockage.f_Probability > SPM_PARTIAL_BLK_MIN_PROB_THLD))
          {
            ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses - 1u;
          }
          else
          {
            ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = ps_blockage_algo_parameters->ui_ShutoffNoOfObjLosses;
          }
        #endif
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP;
        bAllBSWParameterUsed = b_FALSE;
      }

      /************************/
      /* Blockage enable flag */
      /************************/
      /* use this flag only when it is true or if all other parameters were successfully set by BSW */
      if(
          (ps_blockage_algo_parameters->b_BlockageActive == b_TRUE)
        ||(bAllBSWParameterUsed == b_TRUE)
        )
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->bEnableBlockage = ps_blockage_algo_parameters->b_BlockageActive;
        /* set selftest switch */
        ps_blockage_internal_parameters->bEnableSelftest = ps_blockage_algo_parameters->b_BlockageActive;
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->bEnableBlockage = SPM_ENABLE_BLOCKAGE;
        /* set selftest switch */
        ps_blockage_internal_parameters->bEnableSelftest = SPM_ENABLE_SELFTEST;
      }
  #endif
  }
  else
  {
    /* RTE pointer not available -> use defines */
    ps_blockage_internal_parameters->bEnableBlockage = SPM_ENABLE_BLOCKAGE;
    /* ShutOffRange */
    #if(SYS_NUM_OF_SCANS>1)
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_MAX_FAR_NEAR;
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR;
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_FAR] = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_FAR;
    #else
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_ONLY_NEAR;
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR;
    #endif
    /* ShutOnRange*/
    #if(SYS_NUM_OF_SCANS>1)
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_NEAR;
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_FAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_FAR;
    #else
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_NEAR;
    #endif
    
    ps_blockage_internal_parameters->fTimeoutShutOffTime = (float32)SPM_BLOCKAGE_SHUTOFF_TIME;
    ps_blockage_internal_parameters->fTimeoutShutOffWay = (float32)SPM_BLOCKAGE_SHUTOFF_WAY;
    ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP;

    /* set selftest switch */
    ps_blockage_internal_parameters->bEnableSelftest = SPM_ENABLE_SELFTEST;
    /* enabling using Temperature and wiper Signal for prevention of Blockage activation*/
  #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON)
    ps_blockage_internal_parameters->bBlockageUseTemperature = b_TRUE;
    ps_blockage_internal_parameters->bBlockageUseWiper = b_TRUE;
  #endif
  }

  /* calculate necessary parameters from the values above */
  /* PRQA S 2877 1 *//* date: 2020-04-27, Palloi, Opreai, Popam05: suppressing the qac error because number of scans can be bigger than 1*/
  for(uScanIndex=0U;uScanIndex < (uint8)SYS_NUM_OF_SCANS;uScanIndex++)
  {
    ps_blockage_internal_parameters->fLowerRange[uScanIndex] = (float32)ps_blockage_internal_parameters->fShutOnRange[uScanIndex] - 
                  ((((float32)ps_blockage_internal_parameters->fShutOnRange[uScanIndex] - ps_blockage_internal_parameters->fShutOffRange[uScanIndex]) / SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB));
  }

  ps_blockage_internal_parameters->fTimeoutTimeThld = (ps_blockage_internal_parameters->fTimeoutShutOffTime / SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB);
  ps_blockage_internal_parameters->fTimeoutWayThld = (ps_blockage_internal_parameters->fTimeoutShutOffWay / SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB);

  ps_blockage_internal_parameters->fObjLossProbStepWidth = 
                                                        ((float32)SPM_BLOCKAGE_SHUTOFF_BLOCK_PROB / ((float32)ps_blockage_internal_parameters->uiNofOfAllowedObjLosses + 1.0F)) + 0.001F;

  /*an extra define to switch blockage and selftest off regardless of algo parameters*/
  #if (SPM_SWITCH_BLOCKAGE_AND_SELFTEST_OFF==SWITCH_ON)
    ps_blockage_internal_parameters->bEnableBlockage=SWITCH_OFF;
    ps_blockage_internal_parameters->bEnableSelftest=SWITCH_OFF;
  #endif
// 2021-02-03, reviewer:Opreai01,Popam05, PalloI, reason: Cyclomatic complexity is to high
}// PRQA S 7002 

#if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_OFF)
  void SPMSetBlockageParametersUsingDefines(SPMBlockageParameters_t *ps_blockage_internal_parameters)
  {
    /* use hard coded defines */
    ps_blockage_internal_parameters->bEnableBlockage = SPM_ENABLE_BLOCKAGE;

    #if(ALGO_CFG_FarScanAvailable)
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_MAX_FAR_NEAR;

      /*Shutoff Range*/
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR;
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_FAR] = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_FAR;
    #else
      ps_blockage_internal_parameters->uUseFarNearScanForBlck = SPM_USE_ONLY_NEAR;
      ps_blockage_internal_parameters->fShutOffRange[SYS_SCAN_NEAR]           = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR;
    #endif

    /* ShutOnRange*/
    #if(ALGO_CFG_FarScanAvailable)
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_NEAR;
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_FAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_FAR;
    #else
      ps_blockage_internal_parameters->fShutOnRange[SYS_SCAN_NEAR] = (float32)SPM_BLOCKAGE_SHUTON_RANGE_NEAR;
    #endif

    /**************************/
    /* Use roadbeam information */
    /**************************/
    #if(ALGO_CFG_FarScanAvailable)
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = FALSE;
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_FAR] = FALSE;
    #else
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = FALSE;
    #endif

    /******************************/
    /* Minimum spead for roadbeam */
    /******************************/
    #if(ALGO_CFG_FarScanAvailable)
      ps_blockage_internal_parameters->fRoadbeamSpeedMin[SYS_SCAN_NEAR] = SPM_ROADBEAM_AVAILABILITY_SPEED;
      ps_blockage_internal_parameters->fRoadbeamSpeedMin[SYS_SCAN_FAR] = SPM_ROADBEAM_AVAILABILITY_SPEED;
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = FALSE;
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_FAR] = FALSE;
      ps_blockage_internal_parameters->uRoadVisibilityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_VISIBILITY_STRONG_THRESH;
      ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_QUALITY_STRONG_THRESH;
      ps_blockage_internal_parameters->uRoadVisibilityThresh[SYS_SCAN_FAR] = SPM_ROADBEAM_VISIBILITY_STRONG_THRESH;
      ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[SYS_SCAN_FAR] = SPM_ROADBEAM_QUALITY_STRONG_THRESH;
    #else
      ps_blockage_internal_parameters->fRoadbeamSpeedMin[SYS_SCAN_NEAR] = SPM_ROADBEAM_AVAILABILITY_SPEED;
      ps_blockage_internal_parameters->bUseRoadbeam[SYS_SCAN_NEAR] = FALSE;
      ps_blockage_internal_parameters->uRoadVisibilityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_VISIBILITY_STRONG_THRESH;
      ps_blockage_internal_parameters->uRoadVisibilityQualityThresh[SYS_SCAN_NEAR] = SPM_ROADBEAM_QUALITY_STRONG_THRESH;
    #endif

    ps_blockage_internal_parameters->fTimeoutShutOffTime     = (float32)SPM_BLOCKAGE_SHUTOFF_TIME;
    ps_blockage_internal_parameters->fTimeoutShutOffWay      = (float32)SPM_BLOCKAGE_SHUTOFF_WAY;
    ps_blockage_internal_parameters->uiNofOfAllowedObjLosses = SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP;

    /* set selftest switch */
    ps_blockage_internal_parameters->bEnableSelftest = SPM_ENABLE_SELFTEST;

    /*set Temperatur and Wiper Switch*/
    ps_blockage_internal_parameters->bBlockageUseTemperature = b_FALSE;
    ps_blockage_internal_parameters->bBlockageUseWiper       = b_FALSE;
  }
#endif


#if(SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON)
  boolean SPMSetShutOnRangeThresholds(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters
                                      , SPMBlockageParameters_t *ps_blockage_internal_parameters)
  {
    uint8 uScanIndex;
    boolean bBswParamsUsed = b_FALSE;
    float32 fThreshold;
    // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: This loop can be executed more than once for multiscan project
    // PRQA S 2877 1
    for(uScanIndex = SYS_SCAN_NEAR; uScanIndex < (uint8)SYS_NUM_OF_SCANS; uScanIndex++)
    {
      #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
        if(ps_blockage_algo_parameters->f32_ShutonRange[uScanIndex] >= C_F32_DELTA)
        {
         /* signal plausible -> use it */
         ps_blockage_internal_parameters->fShutOnRange[uScanIndex] = ps_blockage_algo_parameters->f32_ShutonRange[uScanIndex] * SPMData.fParametersUpdateFactor;
         bBswParamsUsed = b_TRUE;
        }
        else
        {
      #endif
          /* signal unplausible -> use define */
          fThreshold = SPMGetThreshold(SPM_SHUT_ON_RANGE, uScanIndex);
          ps_blockage_internal_parameters->fShutOnRange[uScanIndex] = (float32)fThreshold * SPMData.fParametersUpdateFactor;
          bBswParamsUsed = b_FALSE;
      #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
        }
      #endif
    }
    return bBswParamsUsed;
  }

  boolean SPMSetShutOffRangeThresholds(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters,
                                       SPMBlockageParameters_t *ps_blockage_internal_parameters)
  {
    uint8 uScanIndex;
    float32 fThreshold;
    boolean bBswParamsUsed = b_FALSE;

    /* PRQA S 2877 1 *//* date: 2020-04-27, Palloi, Opreai, Popam05: suppressing the qac error because number of scans can be bigger than 1*/
    for(uScanIndex = SYS_SCAN_NEAR; uScanIndex < (uint8)SYS_NUM_OF_SCANS; uScanIndex++)
    {
      #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
        if(ps_blockage_algo_parameters->f32_ShutoffRange[uScanIndex] >= C_F32_DELTA)
        {
            /* signal plausible -> use it */
            ps_blockage_internal_parameters->fShutOffRange[uScanIndex] = ps_blockage_algo_parameters->f32_ShutoffRange[uScanIndex] * SPMData.fParametersUpdateFactor;
            bBswParamsUsed = b_TRUE;
        }
        else
        {
      #endif
          /* signal unplausible -> use define */
          fThreshold = SPMGetThreshold(SPM_SHUT_OFF_RANGE, uScanIndex);
          ps_blockage_internal_parameters->fShutOffRange[uScanIndex] = (float32)fThreshold * SPMData.fParametersUpdateFactor;
          bBswParamsUsed = b_FALSE;
      #if(BSW_ALGOPARAMETERS_INTFVER >= BSW_INT_VER_THLD)
        }
      #endif
    }
    return bBswParamsUsed;
  }

  boolean SPMSetShutOffTimeoutThreshold(const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters,
                                        SPMBlockageParameters_t *ps_blockage_internal_parameters)
  {
    float32 fHelpFactor = 1.0F;
    boolean bIsTimeValUse, bIsWayValUse;
    boolean bBSWParamsUsed = b_FALSE;
    #if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
      fHelpFactor = (-8.0F * SPMData.fParametersUpdateFactor + 11.0F) / 3.0F;
    #endif

    /**************************/
    /* Timeout time threshold */
    /**************************/
    if(ps_blockage_algo_parameters->f32_ShutoffTime_Timeout > C_F32_DELTA) /* SatisfyReq: ARS510VW19: L3_PS_1809 */
    {
      /* signal plausible -> use it */
      ps_blockage_internal_parameters->fTimeoutShutOffTime = ps_blockage_algo_parameters->f32_ShutoffTime_Timeout * fHelpFactor;
      bIsTimeValUse = b_TRUE;
    }
    else
    {
      /* signal unplausible -> use define */
      ps_blockage_internal_parameters->fTimeoutShutOffTime = (float32)SPM_BLOCKAGE_SHUTOFF_TIME * fHelpFactor;
      bIsTimeValUse = b_FALSE;
    }

    /*************************/
    /* Timeout way threshold */
    /*************************/
    if(ps_blockage_algo_parameters->f32_ShutoffWay_Timeout > C_F32_DELTA)
    {
      /* signal plausible -> use it */
      ps_blockage_internal_parameters->fTimeoutShutOffWay = ps_blockage_algo_parameters->f32_ShutoffWay_Timeout * fHelpFactor;
      bIsWayValUse = b_TRUE;
    }
    else
    {
      /* signal unplausible -> use define */
      ps_blockage_internal_parameters->fTimeoutShutOffWay = (float32)SPM_BLOCKAGE_SHUTOFF_WAY * fHelpFactor;
      bIsWayValUse = b_FALSE;
    }

    if((bIsTimeValUse == b_TRUE) && (bIsWayValUse == b_TRUE))
    {
      bBSWParamsUsed = b_TRUE;
    }
    return bBSWParamsUsed;
  }

  float32 SPMGetThreshold(uint8 uThldNeed, uint8 uScanIndex)
  {
    float32 fThld = 0.0F;
    switch(uThldNeed)
    {
      case SPM_SHUT_ON_RANGE:
      {
        if(uScanIndex == SYS_SCAN_NEAR)
        {
          fThld = (float32)SPM_BLOCKAGE_SHUTON_RANGE_NEAR;
        }
        else
        {
          fThld = (float32)SPM_BLOCKAGE_SHUTON_RANGE_FAR;
        }
      }
      break;
      case SPM_SHUT_OFF_RANGE:
      {
        if(uScanIndex == SYS_SCAN_NEAR)
        {
          fThld = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_NEAR;
        }
        else
        {
          fThld = (float32)SPM_BLOCKAGE_SHUTOFF_RANGE_FAR;
        }
      }
      break;
      default:
        fThld = 0.0F;
        break;
    }
    return fThld;
  }
#endif

#if((SPM_USE_WEATHER_SIGNALS_FOR_BLOCKAGE == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= 13))
  float32 SPM_f_ComputeHelpFactorBasedWeather(uint8 uCameraWeatherTypeProb)
  {
    float32 fHelp;
    if(uCameraWeatherTypeProb == 0u )
    {
      fHelp = 1.0F;
    }
    else if(uCameraWeatherTypeProb == 25u)
    {
      fHelp = 1.0625F;
    }
    else if(uCameraWeatherTypeProb == 50u)
    {
      fHelp = 1.125F;
    }
    else if(uCameraWeatherTypeProb == 75u)
    {
      fHelp = 1.1875F;
    }
    else
    {
      fHelp = 1.25F;
    }

    return fHelp;
  }

  float32 SPM_f_ComputeWeatherFactor(const PerfDegr_t * pPerfDegr)
  {
    float32 fHelp;
    float32 fFactor = 1.0F;

    if(pPerfDegr != NULL)
    {
      //Spray
      fHelp = SPM_f_ComputeHelpFactorBasedWeather(pPerfDegr->Blockage.uWeatherFrCameraSprayProb);
      fFactor = fFactor * fHelp;

      //Fog
      fHelp = SPM_f_ComputeHelpFactorBasedWeather(pPerfDegr->Blockage.uWeatherFrCameraFogProb);
      fFactor = fFactor * fHelp;

      //Snowfall
      fHelp = SPM_f_ComputeHelpFactorBasedWeather(pPerfDegr->Blockage.uWeatherFrCameraSnowfallProb);
      fFactor = fFactor * fHelp;

      //Rain
      fHelp = SPM_f_ComputeHelpFactorBasedWeather(pPerfDegr->Blockage.uWeatherFrCameraRainProb);
      fFactor = fFactor * fHelp;
    }
    
    //limit the value of factor between 1 and 1.25
    fFactor = CML_f_MinMax(1.0f,1.25f,fFactor);
    return fFactor;
  }
#endif

#if(SPM_CHECK_MISSALIGNMENT)
  void SPMCheckMissalignment(const float32 fTunnelProb, const PartialBlockage_t* pPartialBlockage, fSpeed_t fOwnSpeed)
  {
    ObjNumber_t relObjID;
    boolean bCameraConfirmation = FALSE;
    float32 fDistX = SPM_INVALID_LONG_DISTANCE;

    /* blockage flag judgement */
    if(
        (pPartialBlockage->f_Probability > SPM_MISSALIGNMENT_HIGH_PROB) &&
        (pPartialBlockage->f_Confidence > SPM_MISSALIGNMENT_MIN_CONF) &&
        (fTunnelProb < SPM_MISSALIGNMENT_MAX_TUNNEL_PROB) &&
        (fOwnSpeed  > SPM_PARTIAL_BLOCKAGE_SPEED_THRESHOLD)
      )
    {
      SPMData.bIncreasePartialBlockage = TRUE;
    }
    else
    {
      if(pPartialBlockage->f_Probability <= SPM_MISSALIGNMENT_LOW_PROB)
      {
        SPMData.bIncreasePartialBlockage = FALSE;
      }
    }
  
    relObjID = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
    if(relObjID != OBJ_INDEX_NO_OBJECT)
    {
      bCameraConfirmation = SPMCheckCameraConfirmation(relObjID);
      fDistX = SPM_OBJ_LONG_DISPLACEMENT(relObjID);
    }
  
    if(
        (SPMData.bIncreasePartialBlockage == TRUE) && 
        (bCameraConfirmation == FALSE) &&
        (relObjID != OBJ_INDEX_NO_OBJECT) &&
        ((fDistX < SPM_MISSALIGNMENT_MAX_OBJ_LONG_DIST) && (fDistX > SPM_INVALID_LONG_DISTANCE)) &&
        (fOwnSpeed > SPM_MISSALIGNMENT_SPEED_THRESHOLD) 
        #if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
          &&(pFctVehLongOut->AccNotOff == TRUE)
        #endif
       )
    {
      SPMData.tMissalignmentCounter = (times_t)3000;
      SPMData.bMissalignment = TRUE;
    }

    if(
        (SPMData.bIncreasePartialBlockage == FALSE) &&
        (SPMData.tMissalignmentCounter <=  (times_t)0)
      )
    {
      SPMData.bMissalignment = FALSE;
      SPMData.tMissalignmentCounter = (times_t)0;
    }

    SWITCH_SET_COUNTER((times_t)(SPM_CYCLE_TIME * 1000), &SPMData.tMissalignmentCounter);
  }
  
  boolean SPMCheckCameraConfirmation(const ObjNumber_t ObjNr)
  {
    boolean bRetVal;

     /* Check if camera confirmation over gating */
    if (   (FCTSEN_pEmCustObjList->CustObjects[ObjNr].CamObjectData.CamConfirmationProb >= SPM_MISSALIGNMENT_CAM_CONF_GATE_OOI)
        && (FCTSEN_pEmCustObjList->CustObjects[ObjNr].CamObjectData.e_CamClass != OBJCLASS_UNCLASSIFIED) )
    {
      bRetVal = TRUE;
    }
    else
    {
      bRetVal = FALSE;
    }
  
    return bRetVal;
  }

#endif

#if(SPM_DELAY_REACTIVATION)
  void SPM_v_SetDelayCounter(void)
  {
    SPMData.SPMDelayReactivationTimer = SPM_DELAY_REACTIVATION_TIMER; /* SatisfyReq: ARS510VW19: L3_PS_1807 */
    SPMData.bSPMDelayTimerSet = TRUE;
  }
#endif

#endif /*SPM_SRR_TECHNOLOGY*/
#endif /*FCT_CFG_SIGNAL_PERF_MONITORING*/
//PRQA S 7013 //Pallo I, 20.07.2017: Exceeded number of executable lines due to splits
