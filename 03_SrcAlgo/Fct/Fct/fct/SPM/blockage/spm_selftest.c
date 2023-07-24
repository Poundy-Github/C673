/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.10 $

---*/ /*---
CHANGES:                   $Log: spm_selftest.c  $
CHANGES:                   Revision 1.10 2021/02/04 11:32:41CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.9 2020/06/25 08:14:12CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.8 2020/04/27 15:17:13CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix level 3  QAC warnings
CHANGES:                   Revision 1.6 2020/03/05 08:10:33CET Pallo, Istvan (palloi) 
CHANGES:                   Update CBO with new config switches
CHANGES:                   Revision 1.5 2018/09/24 14:57:20CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR technology
CHANGES:                   Revision 1.4 2018/02/23 14:26:03CET Pallo, Istvan (palloi) 
CHANGES:                   Replace old component states with the new ones
CHANGES:                   Revision 1.3 2017/07/28 06:54:21CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functionality from AL_FCT_ARS400_02.86.00. Code refactoring & QAC cleaning.
CHANGES:                   Revision 1.2 2017/06/21 09:05:00CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove functions headers.
CHANGES:                   Move functions declaration in h file
CHANGES:                   Revision 1.1 2017/03/17 13:16:52CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_par.h"
#include "spm.h"


#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#if(SPM_USE_ONEMIN_SELFTEST_TIME_THLD == SWITCH_OFF)
  #if(SPM_USE_DIFF_SELFTEST_TIME_THRES == SWITCH_OFF)
    #define SPM_SELFTEST_TIME_COUNTER_MAX_LIMIT      (120.0F)
  #else
    #define SPM_SELFTEST_TIME_COUNTER_MAX_LIMIT      (45.0F)
  #endif
#else
  #define SPM_SELFTEST_TIME_COUNTER_MAX_LIMIT        (60.0F)
#endif

#define SPM_SELFTEST_CONF_STAT_LOW_MULTIPLY_FACTOR   (2.0F)
#define SPM_SELFTEST_CONF_STAT_HIGH_MULTIPLY_FACTOR  (4.0F)
#define SPM_SELFTEST_STANDSTILL_SPEED_THLD           (0.0F)

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULEGLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULELOKAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*****************************************************************************
  FUNCTION
*****************************************************************************/


void SPMSelftest(const PerfDegr_t *pPerfDegrData
                #if((SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON) )
                , float32 fOwnspeed
                #endif
                , const boolean bRollerTestBenchState
                , AlgoErrorState_t  *puiBlockageEvent
                , AlgoErrorState_t  *puiSelftestEvent)
{
  switch(SPMState)
  {
    case COMP_STATE_TEMPORARY_ERROR:
      /* EOL mode with PD in INIT mode -> Event "Object Not Measured" is manipulated to AL_ERR_STATE_INACTIVE */
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED ,AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE ,AL_ERR_STATE_INACTIVE);
      *puiSelftestEvent = AL_ERR_STATE_INACTIVE; /* Selftest shall be reported as passed in EOL mode */
      *puiBlockageEvent = AL_ERR_STATE_INACTIVE;
      break;

    case COMP_STATE_RUNNING:
    case COMP_STATE_SUCCESS:
      /* execute selftest if ego speed is above threshold or blockage is disabled or Rollerbenchtest is active
        -> selftest is reported as passed immediately after startup */
      if(
      #if(SPM_USE_SELFTEST_STANDSTILL != SWITCH_ON) 
          (fEgoSpeed > SPM_SPEED_MIN_SELFTEST)
      #else
          (fEgoSpeed >= SPM_SPEED_MIN_SELFTEST)
      #endif
        ||(SPMBlockageParameters.bEnableSelftest == b_FALSE)
        ||(bRollerTestBenchState == b_TRUE))
      {
        /* Determine selftest state */
        SPMSelftestDetermination(pPerfDegrData
                                #if( (SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON) )
                                , fOwnspeed
                                #endif
                                , bRollerTestBenchState);
      }
      else
      {
        /* Selftest only over vehicle speed min */
        /*go back to to old state in case of Rollbenchtest was activ and Ego speed is under Speed min*/
        SPMData.SPMSelftestState = SPMData.SPMSelftestStateLast;
      }

      /* Set events for Selftest */
      SPMSelftestSetDEMEvents(SPMData.SPMSelftestState, puiBlockageEvent, puiSelftestEvent);
      break;

    /* just for a happy Misra add SPM_INIT */
    /* also in case of SPM_FREEZE which signals a freeze of BlockageInformation */
    case COMP_STATE_NOT_INITIALIZED:
    case COMP_STATE_NOT_RUNNING:
    default:
      // for QAC 
      break;
  }
}


void SPMSelftestDetermination(const PerfDegr_t *pPerfDegrData
                                    #if( (SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON) )
                                     , float32     fOwnspeed
                                    #endif
                                     , const boolean     bRollerTestBenchState )
{      
  uint8 uScanIndex = SYS_SCAN_NEAR;
  float32 fTimeCounterLimit;
#if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
  float32 fHelpFactor = 1.0F;
  GDB_Math_Point_t DownFactor, UpFactor;
  DownFactor.X = 0.1F;
  DownFactor.Y = 0.5F;
  UpFactor.X = 0.9F;
  UpFactor.Y = 1.0F;
  if(pPerfDegrData->Camera.fQuality > SPM_CAMERA_MIN_QUALITY_THLD)
  {
    fHelpFactor = GDB_Math_LinInterpol(DownFactor, UpFactor, pPerfDegrData->Camera.fRatio);
  }
#endif
  
  /* Determine selftest only if blockage is enabled */
  if(
      (SPMBlockageParameters.bEnableSelftest == b_TRUE)
    &&(bRollerTestBenchState == b_FALSE)
    )
  {
    #if (EM_PERF_DEGR_INTFVER  >= EM_PERF_INT_VER_THLD)
      SPMData.SPMSelftestInput.SPMSelftestRangeMov = pPerfDegrData->RangeRaw[uScanIndex].fMovingMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeSta = pPerfDegrData->RangeRaw[uScanIndex].fStationaryMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaMax = pPerfDegrData->RangeRaw[uScanIndex].fStationaryMaxRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeMovConf = pPerfDegrData->RangeRaw[uScanIndex].fMovingConfRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaConf = pPerfDegrData->RangeRaw[uScanIndex].fStationaryConfRaw;
    #else
      SPMData.SPMSelftestInput.SPMSelftestRangeMov = pPerfDegrData->RangeRaw.fMovingMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeSta = pPerfDegrData->RangeRaw.fStationaryMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaMax = pPerfDegrData->RangeRaw.fStationaryMaxRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeMovConf = pPerfDegrData->RangeRaw.fMovingConfRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaConf = pPerfDegrData->RangeRaw.fStationaryConfRaw;
    #endif

    #if( (SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON) )
      /* be sure that velocity is positive -> selftest also available with negative velocity in reverse */
      fOwnspeed = CML_f_Abs(fOwnspeed); // PRQA S 3199
    #endif

    /*go back to to old state in case of Rollbenchtest was activ */
    SPMData.SPMSelftestState = SPMData.SPMSelftestStateLast;
    /* start selftest state machine */
    switch(SPMData.SPMSelftestState)
    {
      /********************************************************/
      /* Continue here if Current Selftest State is GDB_PD_ON */
      /********************************************************/
      case GDB_PD_ON:
        SPMSetErrorState( SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP, AL_ERR_STATE_INACTIVE);
        break;

      /*************************************************************/
      /* Continue here if Current Selftest State is GDB_PD_STARTUP */
      /*************************************************************/
      case GDB_PD_STARTUP:
        /* Roadbeam not active */
        SPMSetErrorState(SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP, AL_ERR_STATE_INACTIVE);
        /* "weak" criteria to activate the function after system start */

        if( /* first possible condition: activation by moving objects */
            (((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_RANGE_MIN) && (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf > SPM_SELFTEST_CONFIDENCE_MIN))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_RANGE_MIN) || (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf < SPM_SELFTEST_CONFIDENCE_MIN)))
          ||
            /* second possible condition: activation by stationary objects */
            (((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_RANGE_MIN) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > (SPM_SELFTEST_CONFIDENCE_MIN * SPM_SELFTEST_CONF_STAT_LOW_MULTIPLY_FACTOR)))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_RANGE_MIN) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_CONFIDENCE_MIN)))
          ||
            /* third possible condition: activation by max. of stationary objects (special condition for moving objects here!) */
            (((SPMData.SPMSelftestInput.SPMSelftestRangeStaMax > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > (SPM_SELFTEST_CONFIDENCE_MIN * SPM_SELFTEST_CONF_STAT_HIGH_MULTIPLY_FACTOR)))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_RANGE_MIN) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_CONFIDENCE_MIN)))
        #if(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)
          ||
            (
              (fOwnspeed >= SPM_ROADBEAM_AVAILABILITY_SPEED)
            &&(SPMData.SPMRoadbeamInput[SPM_SCAN_INDEX_USED].SPMRoadVisibility >= SPM_SELFTEST_ROADBEAM_VISIBILITY)
            &&(SPMData.SPMRoadbeamInput[SPM_SCAN_INDEX_USED].SPMRoadVisibilityQuality >= SPM_SELFTEST_ROADBEAM_QUALITY)
            )
        #endif
          )
        {
          /* At least one condition fulfilled, selftest passed */
          SPMData.SPMSelftestState = GDB_PD_ON;
          /*save the last Selftest state to go back to this state in case of Rollbenchtest is finished*/
          SPMData.SPMSelftestStateLast = SPMData.SPMSelftestState;
        }
        else
        {
          #if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
            fTimeCounterLimit = SPM_SELFTEST_TIME_COUNTER_MAX_LIMIT * fHelpFactor;
          #else
            fTimeCounterLimit = SPM_SELFTEST_TIME_COUNTER_MAX_LIMIT;
          #endif
          /* If selftest time counter has reached its maximum... */
          if(SPMData.SPMSelftestTimeCounter > fTimeCounterLimit)
          {
            /* deactivate the system, selftest failed */
            SPMData.SPMSelftestState = GDB_PD_OFF;
            /*save the last Selftest state to go back to this state in case of Rollbenchtest is finished*/
            SPMData.SPMSelftestStateLast = SPMData.SPMSelftestState;
          }
          else
          {
            /* Conditions not fulfilled, selftest not passed, increase selftest time counter */
            #if(SPM_USE_SELFTEST_STANDSTILL == SWITCH_ON)
              if(fOwnspeed <= SPM_SELFTEST_STANDSTILL_SPEED_THLD)
              {
                /* do not increase the counter*/
              }
              else
              {
                SPMData.SPMSelftestTimeCounter += fCycleTime;
              }
            #else
              SPMData.SPMSelftestTimeCounter += fCycleTime;
            #endif
          }
        }
      break;

    /*********************************************************/
    /* Continue here if Current Selftest State is GDB_PD_OFF */
    /*********************************************************/
    case GDB_PD_OFF:
      /* Roadbeam not active */
      SPMSetErrorState( SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP,AL_ERR_STATE_INACTIVE);
    
      /* "hard" criteria to activate the function after failed selftest */
      if(/* first possible condition: activation by moving objects */
         (((SPMData.SPMSelftestInput.SPMSelftestRangeMov> SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf > SPM_SELFTEST_REACTIVATION_CONF))
          &&((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf < SPM_SELFTEST_REACTIVATION_CONF)))
          ||
            /* second possible condition: activation by stationary objects */
            (((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > SPM_SELFTEST_REACTIVATION_CONF))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_REACTIVATION_CONF)))
          ||
            /* third possible condition: activation by max. of stationary objects (special condition for moving objects here!) */
            (((SPMData.SPMSelftestInput.SPMSelftestRangeStaMax > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > SPM_SELFTEST_REACTIVATION_CONF))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_REACTIVATION_CONF)))
        #if(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM == SWITCH_ON)
          ||
            (
              (fOwnspeed >= SPM_ROADBEAM_AVAILABILITY_SPEED)
            &&(SPMData.SPMRoadbeamInput[SPM_SCAN_INDEX_USED].SPMRoadVisibility >= SPM_ROADBEAM_VISIBILITY_STRONG_THRESH)
            &&(SPMData.SPMRoadbeamInput[SPM_SCAN_INDEX_USED].SPMRoadVisibilityQuality >= SPM_ROADBEAM_QUALITY_STRONG_THRESH)
            )
        #endif
        )
      {
        /* Higher reactivation conditions fulfilled, reactivate the system */
        SPMData.SPMSelftestState = GDB_PD_ON;
        /*save the last Selftest state to go back to this state in case of Rollbenchtest is finished*/
        SPMData.SPMSelftestStateLast = SPMData.SPMSelftestState;
      }
      else
      {
        /* increase selftest time counter */
        SPMData.SPMSelftestTimeCounter += fCycleTime;
      }
      break;

    default:
      SPMData.SPMSelftestState = SPMData.SPMSelftestState;
      break;
    }
  }
  /* always report successful selftest if blockage is disabled or Rollbenchtest is activ*/
  else
  {
    SPMData.SPMSelftestState = GDB_PD_ON;
  }
}


void SPMSelftestSetDEMEvents (eGDBPDStates_t State,
                              AlgoErrorState_t *puiBlockageEvent,
                              AlgoErrorState_t *puiSelftestEvent)
{
  switch(State)
  {
    case GDB_PD_STARTUP:
      /* Selftest in process -> no object has been measured yet */
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED ,AL_ERR_STATE_ACTIVE);
      *puiSelftestEvent = AL_ERR_STATE_ACTIVE;
      #if(SPM_BLOCKAGE_STATE_UNKNOWN_IN_STARTUP == SWITCH_ON)
        *puiBlockageEvent = AL_ERR_STATE_UNKNOWN;
        SPMSetErrorState(SPM_ERREV_BLOCKAGE_FULL_DAMP , AL_ERR_STATE_UNKNOWN);
    #else
      *puiBlockageEvent = AL_ERR_STATE_INACTIVE;
    #endif
    break;

    case GDB_PD_ON:
      /* Selftest passed -> object has been measured */
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED ,AL_ERR_STATE_INACTIVE);
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE ,AL_ERR_STATE_INACTIVE);
      *puiSelftestEvent = AL_ERR_STATE_INACTIVE;
      /* Blockage flag is handled in main algo after passed Selftest, do not set here anymore */
      break;

    case GDB_PD_OFF:
      /* Selftest failed -> no object has been measured */
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED ,AL_ERR_STATE_ACTIVE);
      SPMSetErrorState( SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE ,AL_ERR_STATE_ACTIVE);
      *puiSelftestEvent = AL_ERR_STATE_ACTIVE;
      *puiBlockageEvent = AL_ERR_STATE_ACTIVE;
      break;

    default:
      *puiSelftestEvent = AL_ERR_STATE_ACTIVE;
      *puiBlockageEvent = AL_ERR_STATE_ACTIVE;
      break;
  }
}
#endif
#endif // SPM_SRR_TECHNOLOGY

