/*! \file **********************************************************************
// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.65 $

---*/ /*---
CHANGES:                   $Log: spm.c  $
CHANGES:                   Revision 1.65 2021/02/15 17:02:10CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add pragma for MEASFreezeDataMTS
CHANGES:                   Revision 1.64 2021/02/04 16:24:07CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC boolean issue
CHANGES:                   Revision 1.63 2021/01/14 09:41:18CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Add SPM_USE_STOPNGO_BLOCKAGE == SWITCH_ON to not use blockage 
CHANGES:                   computation in standstill in some specific situation
CHANGES:                   Revision 1.62 2020/10/26 09:34:06CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Update the  parameter update factor in each case separatly
CHANGES:                   Revision 1.61 2020/10/23 15:46:58CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Fix QAC level 3 warning
CHANGES:                   Revision 1.60 2020/09/24 09:08:52CEST Pallo, Istvan (palloi) 
CHANGES:                   Update logic for compute SPM parameters update factor
CHANGES:                   Revision 1.59 2020/09/01 07:06:55CEST Pallo, Istvan (palloi) 
CHANGES:                   Set blockage category and partial blockage level on output
CHANGES:                   Revision 1.58 2020/08/06 09:46:12CEST Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Change setting of  partial blockage level logic
CHANGES:                   Revision 1.57 2020/07/20 18:18:30CEST Pallo, Istvan (palloi) 
CHANGES:                   Update blockage type literals
CHANGES:                   Revision 1.56 2020/07/20 18:01:46CEST Pallo, Istvan (palloi) 
CHANGES:                   Update blocakge category defines.
CHANGES:                   Change blocakge type function.
CHANGES:                   Revision 1.55 2020/07/20 15:23:06CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove unused function variable.
CHANGES:                   Revision 1.54 2020/07/14 14:19:32CEST Pallo, Istvan (palloi) 
CHANGES:                   Update blockage type config switch
CHANGES:                   Revision 1.53 2020/06/30 16:25:38CEST Pallo, Istvan (palloi) 
CHANGES:                   Revert SPM SRR split changes
CHANGES:                   Revision 1.52 2020/06/29 18:40:26CEST Pallo, Istvan (palloi) 
CHANGES:                   Add missing endif
CHANGES:                   Revision 1.51 2020/06/29 17:38:33CEST Pallo, Istvan (palloi) 
CHANGES:                   Add new implementation for blocakge category.
CHANGES:                   Update blockage type and partial blockage level
CHANGES:                   Revision 1.50 2020/06/25 13:09:28CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix compilation error
CHANGES:                   Revision 1.49 2020/06/25 08:13:20CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.48 2020/06/12 06:28:45CEST Pallo, Istvan (palloi) 
CHANGES:                   Init BlockageType and set it to ErrorOut
CHANGES:                   Revision 1.47 2020/06/02 16:30:29CEST Pallo, Istvan (palloi) 
CHANGES:                   Implement partial blockage and blockage level funnctions. Implement weather factor function. Blockage level on SPM output.
CHANGES:                   Revision 1.46 2020/03/09 13:30:11CET Pallo, Istvan (palloi) 
CHANGES:                   Update blockage over ignition cycle config switch name
CHANGES:                   Revision 1.45 2020/03/05 08:18:02CET Pallo, Istvan (palloi) 
CHANGES:                   Update CBO with new config switches
CHANGES:                   Revision 1.44 2020/03/03 07:50:54CET Pallo, Istvan (palloi) 
CHANGES:                   Initialize new weather factor
CHANGES:                   Revision 1.43 2020/02/20 13:26:43CET Pallo, Istvan (palloi) 
CHANGES:                   Add implementation for set blockage state saved in previous ignition cycle.
CHANGES:                   Revision 1.42 2020/02/14 12:25:51CET Pallo, Istvan (palloi) 
CHANGES:                   Change data type of OOI0 index to fix QAC warning.
CHANGES:                   Revision 1.41 2020/02/12 11:17:50CET Pallo, Istvan (palloi) 
CHANGES:                   Update implementation related to check of partial blockage when relevant object is not present
CHANGES:                   Revision 1.40 2020/02/04 10:52:01CET Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Changed bNoiseRangeValid condition to FALSE for VisibilityRange implementation
CHANGES:                   Revision 1.39 2020/01/16 10:56:51CET Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added VisibilityRange implementation for SRR
CHANGES:                   Revision 1.38 2020/01/15 11:55:51CET Pallo, Istvan (palloi) 
CHANGES:                   Add functionality for check of partial blockage when relevant object is not present.
CHANGES:                   Revision 1.37 2019/09/16 15:57:40CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added Interference Detection Logic for SRR
CHANGES:                   Revision 1.36 2019/06/24 11:13:38CEST Pallo, Istvan (palloi) 
CHANGES:                   Initialize delay reactivation counter and flag
CHANGES:                   Revision 1.35 2019/06/13 07:28:44CEST Motocu, Alexandru Marian02 (MotocuA02) 
CHANGES:                   Added blockage logic for Roller Bench Test
CHANGES:                   Revision 1.33 2019/05/09 08:52:46CEST Pallo, Istvan (palloi) 
CHANGES:                   Add requirement ID for delay timer reactivation
CHANGES:                   Revision 1.32 2019/04/01 10:29:29CEST Pallo, Istvan (palloi) 
CHANGES:                   Call missalignment function only with necessary info
CHANGES:                   Revision 1.31 2019/03/22 11:02:41CET Pallo, Istvan (palloi) 
CHANGES:                   Set SRDDampingState error active if missalignment was detected or inactive otherwise.
CHANGES:                   Revision 1.30 2019/03/07 14:07:13CET Pallo, Istvan (palloi) 
CHANGES:                   Init new SPMData fields and call missalignment check function
CHANGES:                   Revision 1.29 2018/12/10 12:36:21CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Added headers for SPM structures used in SRR
CHANGES:                   Revision 1.28 2018/11/19 13:32:13CET Oprea, Ionut02 (OpreaI01) 
CHANGES:                   Updated desing for SRR specific functions
CHANGES:                   Revision 1.27 2018/10/05 10:32:33CEST Pallo, Istvan (palloi) 
CHANGES:                   Set observers states in FCTSenErrorOut for SRR
CHANGES:                   Revision 1.26 2018/09/24 15:08:53CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch and code for SRR
CHANGES:                   Revision 1.25 2018/08/17 13:43:40CEST Pallo, Istvan (palloi) 
CHANGES:                   Initialize CBO factor
CHANGES:                   Revision 1.24 2018/08/07 07:34:03CEST Pallo, Istvan (palloi) 
CHANGES:                   Copy observers states from SPM internal structure to provide port
CHANGES:                   Revision 1.23 2018/08/07 07:10:47CEST Pallo, Istvan (palloi) 
CHANGES:                   Initialize errors added and call function for processing observers states
CHANGES:                   Revision 1.22 2018/08/06 07:46:03CEST Pallo, Istvan (palloi) 
CHANGES:                   Initialize blockage delay reactivation timer and rename SRR delay timer
CHANGES:                   Revision 1.21 2018/06/27 09:55:39CEST Pallo, Istvan (palloi) 
CHANGES:                   Check for correct data to be on SPM rec data pointer when set selftest data
CHANGES:                   Revision 1.20 2018/06/21 12:45:08CEST Olaru, Marian (OlaruM02) 
CHANGES:                   add configuration for object loss observer
CHANGES:                   Revision 1.19 2018/04/19 14:00:32CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove static and add new config switch
CHANGES:                   Revision 1.18 2018/04/13 10:04:51CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove veh dyn int ver check for roller bench test flag
CHANGES:                   Revision 1.17 2018/04/12 14:41:57CEST Pallo, Istvan (palloi) 
CHANGES:                   Use local variable for align state instead of parameter from function
CHANGES:                   Revision 1.16 2018/04/04 10:19:05CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for init SPMData with recording data function
CHANGES:                   Revision 1.15 2018/03/27 06:43:31CEST Pallo, Istvan (palloi) 
CHANGES:                   Set simulation last selftest state as rec current selftest state in order to avoid missmatches between selftest states
CHANGES:                   Revision 1.14 2018/03/13 14:49:51CET Pallo, Istvan (palloi) 
CHANGES:                   Use correct #if directive for FCT_SIMU
CHANGES:                   Revision 1.13 2018/03/09 10:50:46CET Pallo, Istvan (palloi) 
CHANGES:                   Add new function for init SPMData with rec data
CHANGES:                   Revision 1.12 2018/02/28 12:11:22CET Pallo, Istvan (palloi) 
CHANGES:                   Remove eba safety distance as port is fucntionality was moved to ACDC.
CHANGES:                   Revision 1.11 2018/02/27 17:09:08CET Pallo, Istvan (palloi) 
CHANGES:                   Remove PDO comments
CHANGES:                   Revision 1.10 2018/02/23 14:26:33CET Pallo, Istvan (palloi) 
CHANGES:                   Replace old component states with the new ones.
CHANGES:                   Remove obsolute function.
CHANGES:                   Revision 1.9 2017/12/05 18:43:17CET Pallo, Istvan (palloi) 
CHANGES:                   Proper handling of error out pointer
CHANGES:                   Revision 1.8 2017/09/13 06:41:18CEST Pallo, Istvan (palloi) 
CHANGES:                   Update eba safety distance implementation
CHANGES:                   Revision 1.7 2017/08/18 16:38:13CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                   Bug fix in function parameter
CHANGES:                   Revision 1.6 2017/08/18 10:18:14CEST Pallo, Istvan (palloi) 
CHANGES:                   Replace LA config swithc
CHANGES:                   Revision 1.5 2017/08/11 08:37:23CEST Pallo, Istvan (palloi) 
CHANGES:                   Change blockage probability function call. Remove static from function declaration
CHANGES:                   Revision 1.4 2017/08/09 13:56:18CEST Olaru, Marian (OlaruM02) 
CHANGES:                   adde the changes related to ALN(probability and confidence)
CHANGES:                   Revision 1.3 2017/07/28 06:54:37CEST Pallo, Istvan (palloi) 
CHANGES:                   Add functionality from AL_FCT_ARS400_02.86.00. Code refactoring & QAC cleaning.
CHANGES:                   Revision 1.2 2017/06/21 09:05:50CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove functions headers.
CHANGES:                   Move functions declarations into h file
CHANGES:                   Revision 1.1 2017/03/17 13:16:52CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/blockage/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "spm.h"
#include "spm_main.h"
#include "spm_par.h"
#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
  #if defined(FCT_SIMU)
    #include "spm_simu.h"
  #endif
#endif

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
#define SPM_MEAS_FUNC_ID                FCT_SPM_MEAS_FUNC_ID //Nele (uint8)COMP_ID_FCT
#define SPM_MEAS_FUNC_CHAN_ID           (uint8)60

#ifndef FCT_MEAS_ID_SPM_BLKPAR  /* just to check, could be moved to rte_type.h later */
 #define FCT_MEAS_ID_SPM_BLKPAR         ((MTS_VirtAddrs) 0x20240600)
#endif

#define FCT_SEN_ERROR_OUT_INT_VER_THLD  (14u)

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! X distance of the last relevant moving object seen */
fDistance_t fLastRelevantObjectDistance;

/*! Ego speed used locally in this module */
fSpeed_t fEgoSpeed;
/*! Cycle time locally used in this module */
fTime_t  fCycleTime;

/*! data of SPM */
SPMData_t SPMData;

/*! SPM blockage parameters */
SPMBlockageParameters_t SPMBlockageParameters;

/*! sub-module state */
SPMCompState_t      SPMState;

#if (SPM_CFG_SHORT_RANGE_SENSOR_INFO)
 /* observer state for SRD damping */
 static SPMObserverStates SRDDampingState;
#endif

/*! SPM error states */
AlgoErrorState_t SPMErrStates[SPM_ERREV_NUM_ERRORS];

/*! MTS information for SPMData */
static const MEASInfo_t SPMDataMeasInfo = // PRQA S 3218
/* date: 2015-05-18, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
{
  /* .VirtualAddress = */
  FCT_MEAS_ID_SPM_DATA,
  /* .Length = */
  sizeof(SPMData),
  /* .FuncID = */
  SPM_MEAS_FUNC_ID,
  /* .FuncChannelID = */
  SPM_MEAS_FUNC_CHAN_ID
};

/*! MTS information for SPMObjectLoss */
static const MEASInfo_t SPMObjectLossMeasInfo = // PRQA S 3218
/* date: 2015-05-18, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
{
  /* .VirtualAddress = */
  FCT_MEAS_ID_OBJECTLOSS,
  /* .Length = */
  sizeof(SPMObjectLoss),
  /* .FuncID = */
  SPM_MEAS_FUNC_ID,
  /* .FuncChannelID = */
  SPM_MEAS_FUNC_CHAN_ID
};

/*! MTS information for SPMBlockageParameters */
static const MEASInfo_t SPMBlockageParametersMeasInfo = // PRQA S 3218
/* date: 2015-05-18, reviewer: Lonard jaison manohar, reason: static local for saving data across function calls */
{
  /* .VirtualAddress = */
  FCT_MEAS_ID_SPM_BLKPAR,
  /* .Length = */
  sizeof(SPMBlockageParameters),
  /* .FuncID = */
  SPM_MEAS_FUNC_ID,
  /* .FuncChannelID = */
  SPM_MEAS_FUNC_CHAN_ID
};

#ifdef FCT_SIMU 
  boolean bSPMDataInit = FALSE;
#endif
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
void SPMProcess (const PerfDegr_t *pPerfDegrData,
                 AlgoErrorState_t *puiBlockageEvent,
                 AlgoErrorState_t *puiSelftestEvent,
                 const Boolean bRollerTestBench,
                #if (SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
                 const SYSDampState_t SRDDampState,
                #endif
                #if( ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && ((SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE) || (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)))
                 const ALN_S_Monitoring_t *pAlignmentMonInput,
                #endif
                #if(SPM_USE_CUSTOM_OBJECT_SELECTION == SWITCH_ON)
                 const EM_t_ObjectList_Custom *pEmCustObjList,
                #endif
                 fSpeed_t fOwnSpeed,
                 fTime_t fCurrCycleTime,
                 const Fct_blockage_algo_parameters_t   *ps_blockage_parameters)
{
  #if( ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && (SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE) )
    e_AlignState_t eAlignState;
  #endif
  #if(SPM_CHECK_PB_WO_OOI0 == SWITCH_ON)
    ObjNumber_t uOOI0Idx = SPM_OBJ_GET_OOI_LIST_OBJ_IDX(OBJ_NEXT_OOI);
  #endif
  boolean  bRollerTestBenchState = b_FALSE;
  /* Initialize module local globals with ego speed and cycle time */
  fEgoSpeed  = fOwnSpeed;
  fCycleTime = fCurrCycleTime;
  bRollerTestBenchState = bRollerTestBench;

  #if(((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF)) && (SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE))
    eAlignState = pAlignmentMonInput->e_AlignState;
  #endif

  SPM_v_ComputeParametersUpdateFactor(pPerfDegrData
                                      #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
                                      , pAlignmentMonInput
                                      #endif
                                     );

  /* set blockage parameters, either take external BSW parameter from RTE or hard coded defines
  Note: formerly only done in SPM_INIT, now done each cycle (negligible runtime), which allows
  online coding (changing of blockage parameters) */

  SPMSetBlockageParameters(&SPMBlockageParameters, ps_blockage_parameters
                          #if(SPM_CFG_USE_TEMPERATURE_AND_WIPER)
                           , pPerfDegrData
                          #endif
                          #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON) && (SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON)
                          ,  pAlignmentMonInput
                          #endif
                           );

  #if ((SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_WIPER_TEMP_VER_THLD))
    SPMData.bSPMPreventBlckIfHighTempNoRain = SPMBlockagePreventIfHighTempAndNoRain(SPMBlockageParameters.bBlockageUseTemperature,
                                                                                    SPMBlockageParameters.bBlockageUseWiper,
                                                                                    pPerfDegrData->Blockage.bSummerWithHighTempNoRain);
  #endif

  #if((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM)||(SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
    if(bRollerTestBenchState == b_FALSE)
    {
      SPMGetRoadBeamData(pPerfDegrData);
    }
  #endif
  switch (SPMState)
  {
    case COMP_STATE_RUNNING:
    case COMP_STATE_SUCCESS:
      /*! decision of selftest results (PD_STARTUP, GDB_PD_ON, GDB_PD_OFF, PD_ROADBEAM_TEST) and setting of events/inhibitions */
      SPMSelftest(pPerfDegrData
                  #if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
                  , fOwnSpeed
                  #endif
                  , bRollerTestBenchState
                  , puiBlockageEvent
                  , puiSelftestEvent);

      /* pause SPM (blockage process) in case "bRollerTestBench" is TRUE */
      if(bRollerTestBenchState == b_FALSE) //PRQA S 3355,3358
      {
        #if(SPM_CFG_SHORT_RANGE_SENSOR_INFO)
        /* Process SRR Data, execute only if a Daimler-SRR (MACOM) is present */
        SPMProcessPreblockage( SRDDampState);
        #endif

        /* process object loss, map+fusion and decision only after successful selftest */
        if(SPMData.SPMSelftestState == GDB_PD_ON) 
        {
          /* no object loss for SRR-BSD */
        #if(SPM_USE_OBJECTLOSS_OBSERVER )
          /*! Range of speed for Object Loss criterion */
          if ((fEgoSpeed > SPM_SPEED_MIN) && (fEgoSpeed <= SPM_SPEED_MAX))
          {
            /*! Blockage Detection observing losses of the relevant object */
            SPMProcessObjectLoss(fOwnSpeed, SPMBlockageParameters.fObjLossProbStepWidth, pPerfDegrData);
          }
          else
          {
            /*! Reset Object Loss statistic but keep number of detected losses */
            SPMCancelObjLossObservation();
          }
        #endif

          #if(SPM_USE_STOPNGO_BLOCKAGE == SWITCH_ON)
            /*! process all blockage data and set current blockage state */
            if((fEgoSpeed > SPM_SPEED_MIN) && (fEgoSpeed <= SPM_SPEED_MAX))
          #endif
            {
              #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
                #if(SPM_CHECK_PB_WO_OOI0 == SWITCH_ON)
                if((uOOI0Idx == OBJ_NOT_OOI) || (SPMData.SPMALNPartialDamp == GDB_FULL_DAMP))
                  {
                #endif
                    SPMALNPartialBlockageState(eAlignState, fOwnSpeed);
                #if(SPM_CHECK_PB_WO_OOI0 == SWITCH_ON)
                  }
                #endif
              #endif
              #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
                SPMALNPartialBlockage(pAlignmentMonInput->PartialBlockage.f_Probability, pAlignmentMonInput->PartialBlockage.f_Confidence);
              #endif
              /* map observer data to blockage probability and fuse to a single probability */
              SPMDetermineBlockProb(pPerfDegrData);
              /* state machine for blockage decision */
              SPMDetermineBlockageState(
                                        #if(SPM_USE_CAMERA_OBSERVER_BLK == SWITCH_ON)
                                          pPerfDegrData
                                        #endif
                                       );
#if(SPM_CHECK_MISSALIGNMENT)
              SPMCheckMissalignment(pPerfDegrData->fTunnelProbability, &pAlignmentMonInput->PartialBlockage, fOwnSpeed);
#endif
            }
        }
      }

      #if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
        if(CML_f_IsZero(SPMData.fBlkLvlDebounceTimer))
        {
          SPM_v_SetBlockageType();
        }
        else
        {
          SPMData.fBlkLvlDebounceTimer -= fCycleTime;
          if(SPMData.fBlkLvlDebounceTimer < 0.F)
          {
            SPMData.fBlkLvlDebounceTimer = 0.0F;
          }
        }
        
        SPM_v_ComputeBlockageCategory(pPerfDegrData);

        #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
        /*Compute partial blockage level*/
        SPM_v_ComputePartialBlockageLevel(pAlignmentMonInput);
        #endif
      #endif

      /*! set blockage DEM events */
      SPMBlockageSetDEMEvents(puiBlockageEvent);

      #if(SPM_OBSERVERS_HISOTRY)
        SPMSetObserversState();
      #endif

      /*! process interference range */
      SPMInterferenceRange();

      /*! Process custom specific SPM functionalities */
      #if (FCT_CFG_CUSTOM_IO_INTERFACE)
        SPM_v_CustomProcess();
      #endif
      break;

    case COMP_STATE_TEMPORARY_ERROR:
      /*! decision of selftest results and setting of events/inhibitions */
      SPMSelftest(pPerfDegrData
                 #if(SPM_USE_SELFTEST_STANDSTILL || SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM)
                  , fOwnSpeed
                 #endif
                 , bRollerTestBenchState
                 , puiBlockageEvent
                 , puiSelftestEvent);
      break;

    case COMP_STATE_NOT_INITIALIZED:
      SPMInit(puiBlockageEvent,puiSelftestEvent
#if((BSW_ALGOPARAMETERS_INTFVER >= BSW_PARAMS_BLK_STATE_INT_VER) && (FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION == SWITCH_ON))
        ,ps_blockage_parameters
#endif
        );
      break;

    case COMP_STATE_NOT_RUNNING:
    /**
     * nothing is done here but holding the current SPM data.
     * Freezing SPM data (Blockage) is due to EM_MOD_INVALID_INPUTS in EM module
     * where already collected BlockageInformation must not be 'overwritten'.
     */
    break;

    default:
      SPMInit(puiBlockageEvent,puiSelftestEvent
#if((BSW_ALGOPARAMETERS_INTFVER >= BSW_PARAMS_BLK_STATE_INT_VER) && (FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION == SWITCH_ON))
              ,ps_blockage_parameters
#endif
        );
      break;
  }// end switch

  // 2020-02-10, reviewer:Opreai01, Popam05,Palloi reason: Pointer is a generic type
  // PRQA S 0315 3  
  (void)MEASFreezeDataMTS(&SPMDataMeasInfo, &SPMData, &FCTSen_v_SPMMeasCallback);
  (void)MEASFreezeDataMTS(&SPMObjectLossMeasInfo, &SPMObjectLoss, &FCTSen_v_SPMMeasCallback);
  (void)MEASFreezeDataMTS(&SPMBlockageParametersMeasInfo, &SPMBlockageParameters, &FCTSen_v_SPMMeasCallback);
}


void SPM_v_InitParametersFactors(void)
{
  #if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
    SPMData.fFactorCBO = 1.0F;
  #endif
  #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
    SPMData.fALNFactor = 1.0F;
  #endif
  /*Initialize parameters update factor*/
  SPMData.fParametersUpdateFactor = 1.0F;
}

void SPMInit(AlgoErrorState_t *puiBlockageEvent,
             AlgoErrorState_t *puiSelftestEvent
#if((BSW_ALGOPARAMETERS_INTFVER >= BSW_PARAMS_BLK_STATE_INT_VER) && (FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION == SWITCH_ON))
             ,const Fct_blockage_algo_parameters_t   *ps_blockage_parameters
#endif
             )
{ 
  /* Initialize last relevant object distance to zero */
  fLastRelevantObjectDistance = 0.0F;

  /*********************************************/
  /*! Initialization of Object Loss statistics */
  /*********************************************/
  SPMInitObjectLoss();

  /************************************/
  /*! Initialization of Blockage data */
  /************************************/

  /* Common Parameters */
#if((BSW_ALGOPARAMETERS_INTFVER >= BSW_PARAMS_BLK_STATE_INT_VER) && (FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION == SWITCH_ON))
  if(ps_blockage_parameters->b_BlockageState == TRUE)
  {
    SPMData.SPMBlockageState = GDB_FULL_DAMP;
  }
  else
  {
    SPMData.SPMBlockageState = GDB_NO_DAMP;
  }
  #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)
  if(ps_blockage_parameters->b_PartialBlockageState == TRUE)
  {
    SPMData.SPMFullBlockageGenByALN = TRUE;
  }
  else
  {
    SPMData.SPMFullBlockageGenByALN = FALSE;
  }
  #endif
#else
  SPMData.SPMBlockageState = GDB_NO_DAMP;
  #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF)
    SPMData.SPMFullBlockageGenByALN = b_FALSE;
  #endif
#endif
  #if(SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
    SPMData.SPMSRDSysDamp = GDB_NO_DAMP;
  #endif

  #if(SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE == SWITCH_ON)
    SPMData.SPMALNPartialDamp = GDB_NO_DAMP;
    SPMData.SPMALNPartialDampDelayTimer = 0.0F;
  #endif

  SPMData.SPMFullBlockageTimer = 0.0F;
  SPMData.SPMReactivationDelayTimerSRR = 0.0F;
  #if(SPM_DELAY_REACTIVATION)
  SPMData.SPMDelayReactivationTimer = SPM_DELAY_REACTIVATION_TIME_INVALID;
  SPMData.bSPMDelayTimerSet = b_FALSE;
  #endif
  
  #if((SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)&&(FCT_SEN_ERROR_OUT_INTFVER >= 19U))
    SPMData.fBlkLvlDebounceTimer = 5.0F;
  #endif

  /*! Initializtion of all Blockag criteria */

  /* Range */
  SPMData.SPMBlockageRange = 0.0F;
  SPMData.SPMBlockageRangeConf = SPM_CONFIDENCE_MIN;
  SPMData.SPMBlockageRangeProb = SPM_PROBABILITY_MIN;
  SPMData.SPMRangeHoldCounter = 0.0F;

#if(ALGO_CFG_FarScanAvailable)
  #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
    /* Range gradient*/
    SPMData.SPMBlockagePreviousRange[SYS_SCAN_NEAR] = 0.0F;
    SPMData.SPMBlockagePreviousRange[SYS_SCAN_FAR] = 0.0F;
    SPMData.SPMBlockageCurrentRange[SYS_SCAN_NEAR] = 0.0F;
    SPMData.SPMBlockageCurrentRange[SYS_SCAN_FAR] = 0.0F;
    SPMData.SPMBlockageRangeGradient[SYS_SCAN_NEAR] = 0.0F;
    SPMData.SPMBlockageRangeGradient[SYS_SCAN_FAR] = 0.0F;
    SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_NEAR]= 0.0F;
    SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_FAR] = 0.0F;
    SPMData.SPMScanRangeConfidencePrevious[SYS_SCAN_NEAR]= SPM_CONFIDENCE_MIN;
    SPMData.SPMScanRangeConfidencePrevious[SYS_SCAN_FAR] = SPM_CONFIDENCE_MIN;
  #endif
    SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] = SPM_CONFIDENCE_MIN;
    SPMData.SPMScanRangeConfidence[SYS_SCAN_FAR] = SPM_CONFIDENCE_MIN;
  #else
    #if(SPM_USE_RANGE_GRADIENT == SWITCH_ON)
      /* Range gradient*/
      SPMData.SPMBlockagePreviousRange[SYS_SCAN_NEAR] = 0.0F;
      SPMData.SPMBlockageCurrentRange[SYS_SCAN_NEAR] = 0.0F;
      SPMData.SPMBlockageRangeGradient[SYS_SCAN_NEAR] = 0.0F;
      SPMData.SPMBlockageRangeConfidenceGradient[SYS_SCAN_NEAR]= 0.0F;
      SPMData.SPMScanRangeConfidencePrevious[SYS_SCAN_NEAR]= SPM_CONFIDENCE_MIN;
    #endif
      SPMData.SPMScanRangeConfidence[SYS_SCAN_NEAR] = SPM_CONFIDENCE_MIN;
  #endif

  /* Timeout */
  SPMData.SPMBlockageTimeoutTimeCounter = 0.0F;
  SPMData.SPMBlockageTimeoutWayCounter = 0.0F;
  SPMData.SPMBlockageTimeoutBlockProb = SPM_PROBABILITY_MIN;
  SPMData.SPMBlockageTimeoutBlockConf = SPM_CONFIDENCE_MIN;

  /* current criteria weights for blockage fusion */
  SPMData.SPMCurrentObjLossWeight = 0.0F;
  SPMData.SPMCurrentRangeWeight = 0.0F;
  SPMData.SPMCurrentTimeoutWeight = 0.0F;

  /* Object Loss */
  SPMData.SPMBlockageObjLossProb = SPM_PROBABILITY_MIN;
  SPMData.SPMBlockageObjLossConf = SPM_CONFIDENCE_MIN;

  /* Output */
  SPMData.SPMBlockageProbability = -1.0F; /* new output of SPM Blockage Probability fusion */
  SPMData.SPMBlockageConfidence = SPM_CONFIDENCE_MIN; /* new output of SPM Blockage Probability fusion */
  
  /*Temperature and Wiper*/
  SPMData.bSPMPreventBlckIfHighTempNoRain = b_FALSE;

  #if(SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ == SWITCH_ON)
    SPMData.SPMLastRelObjID = OBJ_NOT_OOI;
  #endif

  /************************************/
  /*! Initialization of Selftest data */
  /************************************/
  SPMData.SPMSelftestState         = GDB_PD_STARTUP;
  SPMData.SPMSelftestStateLast     = GDB_PD_STARTUP;
  SPMData.SPMSelftestTimeCounter   = 0.0F;
  SPMData.SPMSelftestTimeCounterThld = (float32)SPM_TMAX_UNTIL_OBJ;


  SPMData.SPMSelftestInput.SPMSelftestRangeMov      = 0.0F;
  SPMData.SPMSelftestInput.SPMSelftestRangeMovConf  = SPM_CONFIDENCE_MIN;
  SPMData.SPMSelftestInput.SPMSelftestRangeSta      = 0.0F;
  SPMData.SPMSelftestInput.SPMSelftestRangeStaMax   = 0.0F;
  SPMData.SPMSelftestInput.SPMSelftestRangeStaConf  = SPM_CONFIDENCE_MIN;

  /****************************************/
  /*! Initialization of Interference data */
  /****************************************/
  SPMData.SPMInterferenceState   = b_FALSE;
  SPMData.SPMInterferenceRange   = -1.0F;
  SPMData.SPMInterference        = 0UL;
  SPMData.SPMInterferenceHoldCnt = 0u;

  #if ((SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM) || (SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM==SWITCH_ON))
    /************************************/
    /*! Initialization of Roadbeam data */
    /************************************/
    SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibility = 0U;
    SPMData.SPMRoadbeamInput[SYS_SCAN_NEAR].SPMRoadVisibilityQuality = 0U;
    #if (ALGO_CFG_FarScanAvailable)
      SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibility = 0U;
      SPMData.SPMRoadbeamInput[SYS_SCAN_FAR].SPMRoadVisibilityQuality = 0U;
    #endif
  #endif

#if(SPM_CHECK_MISSALIGNMENT)
  SPMData.bIncreasePartialBlockage = FALSE;
  SPMData.bMissalignment = FALSE;
  SPMData.tMissalignmentCounter = (times_t)0;
#endif

  SPM_v_InitParametersFactors();

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
  SPMData.BlockageType = SPM_BLOCKAGE_TYPE_NORMAL;
  SPMData.PartialBlockageLevel = SPM_UNKNOWN_PARTIAL_BLOCKAGE;
  SPMData.BlockageCategory = SPM_BLOCKAGE_CAT_UNKNOWN;
#endif

  /* Initialize error output */
  SPMSetErrorState(SPM_ERREV_OBJECT_NOT_MEASURED, AL_ERR_STATE_UNKNOWN);			// Object of enum type was being modified with an increment or decrement operator.
  SPMSetErrorState(SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_BLOCKAGE_INC_DAMP, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_BLOCKAGE_FULL_DAMP, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_BLOCKAGE_RDC_DAMP, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_INTERFERENCE_RANGE, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_RB_BLOCKAGE_TEST, AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_PARTIAL_BLOCKAGE,            AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_OBJ_LOSS,                    AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_TIMEOUT,                     AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_RANGE,                       AL_ERR_STATE_UNKNOWN);
  SPMSetErrorState(SPM_ERREV_NUM_ERRORS, AL_ERR_STATE_UNKNOWN);
  #if(SPM_CFG_SHORT_RANGE_SENSOR_INFO)
    SPMSetErrorState(SPM_ERREV_SRD_SYS_DAMP, AL_ERR_STATE_UNKNOWN);
  #endif

  *puiBlockageEvent=AL_ERR_STATE_UNKNOWN;
  *puiSelftestEvent=AL_ERR_STATE_UNKNOWN;
}


void SPMSetErrorState(SPMErrorEvents_t spm_error, AlgoErrorState_t err_state)
{
  if (spm_error < SPM_ERREV_NUM_ERRORS)
  {
    SPMErrStates[spm_error] = err_state;
  }
}


void SPMFillSenErrors(SPMErrorOutProPort_t * pDest)
{
  pDest->t_ObjectNotMeasured       = SPMErrStates[SPM_ERREV_OBJECT_NOT_MEASURED_FAILURE];
  pDest->t_ObjectNotMeasTmp        = SPMErrStates[SPM_ERREV_OBJECT_NOT_MEASURED];
  pDest->t_Blockage                = SPMErrStates[SPM_ERREV_BLOCKAGE_FULL_DAMP];
  pDest->t_IncreaseBlockage        = SPMErrStates[SPM_ERREV_BLOCKAGE_INC_DAMP];
  pDest->t_DecreaseBlockage        = SPMErrStates[SPM_ERREV_BLOCKAGE_RDC_DAMP];
  pDest->t_InterferenceRange       = SPMErrStates[SPM_ERREV_INTERFERENCE_RANGE];
  pDest->t_PartialBlockageObserver = SPMErrStates[SPM_ERREV_PARTIAL_BLOCKAGE];
  pDest->t_ObjectLossObserver      = SPMErrStates[SPM_ERREV_OBJ_LOSS];
  pDest->t_RangeObserver           = SPMErrStates[SPM_ERREV_RANGE];
  pDest->t_TimeoutObserver         = SPMErrStates[SPM_ERREV_TIMEOUT];
  #if(FCT_SEN_ERROR_OUT_INTFVER >= FCT_SEN_ERROR_OUT_INT_VER_THLD)
    pDest->u_NoOfObjLosses         = SPMObjectLoss.uiNoOfObjLosses; 
  #endif
  #if (SPM_CFG_SHORT_RANGE_SENSOR_INFO == SWITCH_ON)
    pDest->t_SRDDampingState       = SPMErrStates[SPM_ERREV_SRD_SYS_DAMP];
  #endif
  /* If the SPM error states requesting roadbeam blockage are active, then
  set the request road beam boolean */
  if(
      (SPMErrStates[SPM_ERREV_RB_BLOCKAGE_TEST] == VDY_ERR_STATE_ACTIVE)
    ||(SPMErrStates[SPM_ERREV_RB_BLOCKAGE_TEST_STARTUP] == VDY_ERR_STATE_ACTIVE)
    )
  {
    pDest->b_RequestRoadBeam = b_TRUE;
  }
  else
  {
    pDest->b_RequestRoadBeam = b_FALSE;
  }

#if(SPM_CHECK_MISSALIGNMENT == SWITCH_ON)
  if(SPMData.bMissalignment == b_TRUE)
  {
    pDest->t_SRDDampingState = AL_ERR_STATE_ACTIVE;
  }
  else
  {
    pDest->t_SRDDampingState = AL_ERR_STATE_INACTIVE;
  }
#endif

#if((SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON) && ((FCT_SEN_ERROR_OUT_INTFVER >= 20U) && (ALGO_ARS500Sensor)))
   pDest->t_BlockageType = (BlockageType_t)SPMData.BlockageType;
   pDest->t_BlockageCategory = (BlockageCategory_t)SPMData.BlockageCategory;
   pDest->t_PartialBlockageLevel = (PartialBlockageLevel_t)SPMData.PartialBlockageLevel;
#endif
}

#if ((SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_WIPER_TEMP_VER_THLD))
  boolean SPMBlockagePreventIfHighTempAndNoRain(const boolean bBlockageUseTemperature,
                                                const boolean bBlockageUseWiper, 
                                                const boolean bSummerWithHighTempNoRain)
  {
    boolean bReturnValue = b_FALSE;
    if(
        (bBlockageUseWiper == b_TRUE)
      &&(bBlockageUseTemperature == b_TRUE)
      &&(bSummerWithHighTempNoRain == b_TRUE)
       )
    {
      bReturnValue = b_TRUE;
    }
    return bReturnValue;
  }
#endif /*((SPM_CFG_USE_TEMPERATURE_AND_WIPER == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= EM_PERF_INT_WIPER_TEMP_VER_THLD))*/

#ifdef FCT_SIMU
#if(SPM_INIT_WITH_REC_DATA)
  void InitSPMDataWithRecordingData(SPMData_t * pSPMDataRec)
  {
    if(SPMState == COMP_STATE_NOT_INITIALIZED)
    {
      // if component is in init mode then reset flag
      bSPMDataInit = FALSE;
    }
    if(bSPMDataInit == FALSE)
    { 
      if( (pSPMDataRec->SPMSelftestState == GDB_PD_OFF)
        ||(pSPMDataRec->SPMSelftestState == GDB_PD_ON)
        ||(pSPMDataRec->SPMSelftestState == GDB_PD_STARTUP)
        )
      {
        SPMData.SPMSelftestState = pSPMDataRec->SPMSelftestState;
        SPMData.SPMSelftestStateLast = pSPMDataRec->SPMSelftestState;
        SPMData.SPMSelftestTimeCounter = pSPMDataRec->SPMSelftestTimeCounter;
      }
      else
      {
        SPMData.SPMSelftestState = GDB_PD_STARTUP;
        SPMData.SPMSelftestStateLast = GDB_PD_STARTUP;
        SPMData.SPMSelftestTimeCounter = 0.0F;
      }
      if( SPMState == COMP_STATE_RUNNING)
      {
        // component is in state running - initialization was done
        // set flag on true so no initialization should take place
        bSPMDataInit = TRUE;
      }
    }
  }
#endif
#endif

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
void SPM_v_SetBlockageType(void)
{
  SPMData.BlockageType = SPM_BLOCKAGE_TYPE_NORMAL; 

  if(SPMData.bSPMPreventBlckIfHighTempNoRain == b_TRUE)
  {
    SPMData.BlockageType = SPM_BLOCKAGE_TYPE_LATE;
  }
  else if(SPMData.fParametersUpdateFactor > 1.0F)
  {
    SPMData.BlockageType = SPM_BLOCKAGE_TYPE_EARLY;
  }
  else
  {
    SPMData.BlockageType = SPM_BLOCKAGE_TYPE_NORMAL;
  }
  SPMData.fBlkLvlDebounceTimer = SPM_BLK_LVL_TIMER_DEBOUNCE_TIME;
}
#endif

//Compute parameters update factor
void SPM_v_ComputeParametersUpdateFactor(const PerfDegr_t * pPerfDegrData
                                         #if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
                                         , const ALN_S_Monitoring_t *pAlignmentMonInput
                                         #endif
                                        )
{
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
  float32 fALNFactor;
  GDB_Math_Point_t ALNDownFactor, ALNUpFactor;
#endif

#if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
  float32 fFactorCBO;
  GDB_Math_Point_t CameraDownFactor, CameraUpFactor;
#endif

#if((SPM_USE_WEATHER_SIGNALS_FOR_BLOCKAGE == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= 13))
  float32 fWeatherFactor;
#endif
  float32 fParametersUpdateFactor = 1.0F;

  // init parameters factors as function is called before check states of component.
  if(SPMState == COMP_STATE_NOT_INITIALIZED)
  {
    SPM_v_InitParametersFactors();
  }

#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
  ALNDownFactor.X = SPM_ALN_RANGE_DOWN_FACTOR_XVAL;
  ALNDownFactor.Y = SPM_ALN_RANGE_DOWN_FACTOR_YVAL;
  ALNUpFactor.X   = SPM_ALN_RANGE_UP_FACTOR_XVAL;
  ALNUpFactor.Y   = SPM_ALN_RANGE_UP_FACTOR_YVAL;
  if(pAlignmentMonInput->PartialBlockage.f_Confidence > SPM_PARTIAL_BLK_MIN_CONF_THLD)
  {
    fALNFactor = GDB_Math_LinInterpol(ALNDownFactor, ALNUpFactor, pAlignmentMonInput->PartialBlockage.f_Probability);
    SPMData.fALNFactor += CML_f_MinMax(SPM_PARAM_MIN_FACTOR_STEP, SPM_PARAM_MAX_FACTOR_STEP, (fALNFactor - SPMData.fALNFactor));
  }
  else
  {
    fALNFactor = SPM_PARAM_FACTOR_DEFAULT_VAL;
    SPMData.fALNFactor = fALNFactor;
  }
  fParametersUpdateFactor = CML_f_Max(fParametersUpdateFactor, SPMData.fALNFactor);
#endif

#if(SPM_USE_CAMERA_OBSERVER_PARAMS == SWITCH_ON)
  CameraDownFactor.X = SPM_RANGE_DOWN_FACTOR_XVAL;
  CameraDownFactor.Y = SPM_RANGE_DOWN_FACTOR_YVAL;
  CameraUpFactor.X = SPM_RANGE_UP_FACTOR_XVAL;
  CameraUpFactor.Y = SPM_RANGE_UP_FACTOR_YVAL;
  if(pPerfDegrData->Camera.fQuality > SPM_CAMERA_MIN_QUALITY_THLD)
  {
    fFactorCBO = GDB_Math_LinInterpol(CameraDownFactor, CameraUpFactor, pPerfDegrData->Camera.fRatio);
    SPMData.fFactorCBO += CML_f_MinMax(SPM_PARAM_MIN_FACTOR_STEP, SPM_PARAM_MAX_FACTOR_STEP, fFactorCBO - SPMData.fFactorCBO);
  }
  else
  {
    fFactorCBO = SPM_PARAM_FACTOR_DEFAULT_VAL;
    SPMData.fFactorCBO = fFactorCBO;
  }

  fParametersUpdateFactor = CML_f_Max(SPMData.fFactorCBO, fParametersUpdateFactor);

#endif

#if((SPM_USE_WEATHER_SIGNALS_FOR_BLOCKAGE == SWITCH_ON) && (EM_PERF_DEGR_INTFVER >= 13))
  fWeatherFactor = SPM_f_ComputeWeatherFactor(pPerfDegrData);
  fParametersUpdateFactor = CML_f_Max(fParametersUpdateFactor, fWeatherFactor);
#endif

  SPMData.fParametersUpdateFactor = CML_f_MinMax(1.0F, 1.25F, fParametersUpdateFactor);

  // 2021-02-10, reviewer:Opreai01, Popam05,Palloi reason: variable kept for further implementation
  // PRQA S 3119 3
  _PARAM_UNUSED(pPerfDegrData);
#if(SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON)
  _PARAM_UNUSED(pAlignmentMonInput);
#endif
}

#if((SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON) && (SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF == SWITCH_ON))
void SPM_v_ComputePartialBlockageLevel(const ALN_S_Monitoring_t *pAlignmentMonInput)
{
  if(CML_f_IsZero(pAlignmentMonInput->PartialBlockage.f_Confidence))
  {
    SPMData.PartialBlockageLevel = SPM_UNKNOWN_PARTIAL_BLOCKAGE;
  }
  else if(SPMData.SPMFullBlockageGenByALN == b_TRUE)
  {
    SPMData.PartialBlockageLevel = SPM_FULL_PARTIAL_BLOCAKGE;
  }
  else
  {
    // for SPMData.SPMFullBlockageGenByALN == FALSE case
    if(CML_f_IsNonZero(SPMData.fALNFactor - 1.0F))
    {
      SPMData.PartialBlockageLevel = SPM_UPCOMING_PARTIAL_BLOCKAGE;
    }
    else
    {
      SPMData.PartialBlockageLevel = SPM_NO_PARTIAL_BLOCKAGE;
    }
  }
}
#endif

#if(SPM_SET_CUSTOM_FEATURES_OUTPUT == SWITCH_ON)
void SPM_v_ComputeBlockageCategory(const PerfDegr_t *pPerfDegr)
{
	if((SPMData.SPMBlockageState == GDB_FULL_DAMP) || (SPMData.SPMBlockageState == GDB_RDC_DAMP))
	{
		if(pPerfDegr->Blockage.bSummerParameterset == b_TRUE)
		{
			if(
				(pPerfDegr->Blockage.uWeatherFrCameraSprayProb > SPM_WEATHER_PROB) ||
			    (pPerfDegr->Blockage.uWeatherFrCameraFogProb > SPM_WEATHER_PROB) ||
			    (pPerfDegr->Blockage.uWeatherFrCameraRainProb > SPM_WEATHER_PROB)
			   )
			{
			  SPMData.BlockageCategory = SPM_BLOCKAGE_CAT_TEMPORARY;
			}
	        else
			{
		      SPMData.BlockageCategory = SPM_BLOCKAGE_CAT_UNKNOWN;
			}
		}
		else
		{
		  if(
			  (pPerfDegr->Blockage.uWeatherFrCameraRainProb > SPM_WEATHER_PROB)||
			  (pPerfDegr->Blockage.uWeatherFrCameraSnowfallProb > SPM_WEATHER_PROB)
			)
			{
			  SPMData.BlockageCategory = SPM_BLOCKAGE_CAT_PERM_CLEANING;
			}
			else
			{
		      SPMData.BlockageCategory = SPM_BLOCKAGE_CAT_UNKNOWN;
			}
		}
	}
	else
	{
		SPMData.BlockageCategory = SPM_CATEGORY_NO_BLOCKAGE;
	}
}
#endif
#endif

//SRR
#else
  /*****************************************************************************
    (SYMBOLIC) CONSTANTS
  *****************************************************************************/
  #define SPM_MEAS_FUNC_ID        (uint8)FCT_MEAS_FUNC_ID
  #define SPM_MEAS_FUNC_CHAN_ID   (uint8)FCT_MEAS_FUNC_CHAN_ID
  
  /*************************************************************************/
  /* date: 2016-09-20, reviewer: M. Musat    , reason:                     */
  /* The remaining "magic" constants do not need definitions of their own  */
  /*************************************************************************/
  /* PRQA S 3120, 3121 EOF */
  
  /*****************************************************************************
    VARIABLES
  *****************************************************************************/
  
  /*! Ego speed used locally in this module */
  static fSpeed_t fEgoSpeed;
  /*! Cycle time locally used in this module */
  static fTime_t  fCycleTime;
  
  /*! data of SPM @VADDR:FCT_MEAS_ID_SPM_DATA  @CYCLEID: FCT_ENV */
  SPMData_t SPMData;
  
  /*! data of SPM @VADDR:FCT_MEAS_ID_SPM_BLKPAR  @CYCLEID: FCT_ENV */
  SPMBlockageParameters_t SPMBlockageParameters;
  
  /*! sub-module state */
  StateSPM_t      StateSPM; 
  /*****************************************************************************
    FUNCTION PROTOTYPES
  *****************************************************************************/  
  /// Initializing of SPM data <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None    
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Initializing of SPMData structure which contains information about Blockage data, \n
  ///                         Selftest data, Object Loss Observer data and Partial Blockage from ALN data.
  ///
  /// @startuml               "Call sequence for SPMInit"
  ///
  /// spm -> spm: **SPMProcess()** call \n**SPMInit()**
  ///   activate spm
  ///       spm --> spm:
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             - 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-568-0006e2e0
  ///                                             
  static void SPMInit(void);
  /// Selftest call state machine <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              pPerfDegrData        Blockage data collected by EM
  /// @param[out]             puiBlockageEvent     Blockage event
  /// @param[out]             puiSelftestEvent     Selftest event  
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Selftest call state machine. It calls the selftest determination function if ego speed is above threshold or blockage is disabled -> selftest is reported as passed immediately after startup
  ///
  /// @startuml               "Call sequence for SPMSelftest"
  ///
  /// spm -> spm: **SPMProcess()** call \n**SPMSelftest(pPerfDegrData, puiBlockageEvent, puiSelftestEvent)**
  ///   activate spm
  ///      spm -> spm: **SPMSelftestSetBlockageOutput(SPMData.SPMSelftestState, puiBlockageEvent, puiSelftestEvent)**
  ///         note left: Set Blockage Output for Selftest
  ///      spm -> spm: **SPMSelftestDetermination(pPerfDegrData)**
  ///  note left: Determine selftest state
  ///      spm --> spm:
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test) \n 
  ///                         Test of memory corruption (dynamic module test)
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-573-0006e2e0
  ///   
  static void SPMSelftest(const PerfDegr_t *pPerfDegrData, FCTSenErrorOut_t *puiBlockageEvent, AlgoErrorState_t *puiSelftestEvent, const boolean bRollerTestBenchState);
  /// Generate and communicate selftest data to DEM component <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              State                Selftest state 
  /// @param[out]             puiBlockageEvent     Blockage event
  /// @param[out]             puiSelftestEvent     Selftest event 
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Depending of Selfest State, will comunicate the Selftest Data and Blockage State to DEM component
  ///
  /// @startuml               "Call sequence for SPMSelftestSetBlockageOutput"
  /// 
  /// spm -> spm: **SPMSelftest()** call \n**SPMSelftestSetBlockageOutput(SPMData.SPMSelftestState, puiBlockageEvent, puiSelftestEvent)**
  ///   activate spm
  ///     spm --> spm: 
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) \n
  ///                         Test of memory corruption (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-575-0006e2e0
  /// 
  static void SPMSelftestSetBlockageOutput (eGDBPDStates_t State, FCTSenErrorOut_t *puiBlockageEvent, AlgoErrorState_t *puiSelftestEvent);
  /// Selftest state machine <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              pPerfDegrData     Blockage data collected from EM 
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Selftest state machine at sensor startup/reset.\n
  ///                         The Selftest status is decided based on the Blockage data collected from EM.\n
  ///                         At "ignition on" the system has to detect its functionality. The method for gaining this information: a fast statistic analyses of the \n
  ///                         moving track and stationary cluster range. The range is analized for max 120 s, if there is no positive result an error is reported.
  ///
  /// @startuml               "Call sequence for SPMSelftestDetermination"
  ///            
  /// spm -> spm: **SPMSelftest()** call \n**SPMSelftestDetermination(pPerfDegrData)**
  ///   activate spm
  ///      spm --> spm:
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of Input-Output-Correlation (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test) \n
  ///                         Test of memory corruption (dynamic module test)
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-574-0006e2e0
  /// 
  static void SPMSelftestDetermination (const PerfDegr_t *pPerfDegrData, const boolean bRollerTestBenchState);

  /// Determination of BSD, LCA or FCTA Performance Degradation flag and Full Damping  <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              pPerfDegrData             Blockage data collected by EM
//#if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  /// @param[in]              ps_PartialBlockageInfo    Partial blockage status from ALN
//#endif
  /// @param[in,out]          puiBlockageEvent          Blockage output
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Function to derminate Performace Degradation for BSD, LCA or FCTA, based on the range results and their confidences \n 
  ///                         and Full Damping based on Timeout (Time counter or Way counter)
  ///
  /// @startuml     "Call sequence for  SPMProcessBlockageState"
  ///
  /// spm -> spm: **SPMProcess()** call \n**SPMProcessBlockageState()**
  ///   activate spm
  ///     spm -> spm: **SPMBlockageSetBlockageOutput()**
  ///        note left : Determine BSD Blockage State;\nDetermine FCTA Blockage State;\nDetermine LCA Blockage State.
  ///     spm -> spm: **SPMTimeoutObserver()**
  ///        note left: Process Timeout Observer
  ///     group #LightBlue IF FCT_CFG_ALIGNMENT_MONITORING_INPUT	
  ///       spm -> spm: **SPMALNPartialBlockage((float32)ps_PartialBlockageInfo->f_Probability, (float32)ps_PartialBlockageInfo->f_Confidence)**
  ///     end
  ///     spm --> spm:
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test) \n 
  ///                         Test of memory corruption (dynamic module test)              
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-569-0006e2e0
  ///  
  static void SPMProcessBlockageState(const PerfDegr_t        *pPerfDegrData,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
                                      const PartialBlockage_t *ps_PartialBlockageInfo,
  #endif
                                            FCTSenErrorOut_t  *puiBlockageEvent        );
  
  /// Set Blockage Output <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fFullDampRangeThresh                    ShutOff Range
  /// @param[in]              fFullDampRangeActivationCounterThresh   Range Hold Counter Threshold
  /// @param[in]              fINCBlockageRangeThresh                 Blockage Range for Increase
  /// @param[in]              fSPMBlockageFullRange                   Blockage Range for FullDamp 
  /// @param[in]              bObjectLossObesrverFullDamp             Number of objects loss for FullDamp
  /// @param[in,out]          fFullDampRangeDeterminationCounter      Range Determination Counter
  /// @param[in,out]          bRangeObserverFullDamp                  Range observer for full damp
  /// @param[in,out]          bRangeObserverINCDamp                   Range observer for increase damp
  /// @param[in,out]          bTimeoutFullDamp                        Timeout observer for full damp
  /// @param[in,out]          eSPMBlockageState                       Blockage Output
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Function to determine Performance Degradation for BSD, LCA or FCTA based on Range Observer.\n
  ///                         Here is checked the Blockage Status and check if the Blockage Status can be changed:
  ///                         - from NoBlockage to IncreaseBloakge or FullBlockage
  ///                         - from IncreaseBlockage to NoBlockage or FullBlockage
  ///                         - from FullBlockage to NoBlockage
  ///
  /// @startuml                "Call sequence for SPMBlockageSetBlockageOutput"
  ///
  /// spm -> spm: **SPMProcessBlockageState()** call\n**SPMBlockageSetBlockageOutput()**
  /// activate spm
  ///   spm -> spm: **SPMRangeObserverFullDamp(fFullDampRangeThresh, fFullDampRangeActivationCounterThresh, fFullDampRangeDeterminationCounter)**
  ///     note left: Process Range Observer Full Damp
  ///   spm -> spm: **SPMRangeObserverINCDamp(fINCBlockageRangeThresh)**
  ///     note left: Process Range Observer INC 
  ///   spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test) \n 
  ///                         Test of memory corruption (dynamic module test)              
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-565-0006e2e0
  /// 
  static void SPMBlockageSetBlockageOutput (const float32 fFullDampRangeThresh,
                                            const float32 fFullDampRangeActivationCounterThresh,
                                            const float32 fINCBlockageRangeThresh,
                                            const float32 fSPMBlockageFullRange,
                                            const boolean bObjectLossObesrverFullDamp,
                                                  float32 *fFullDampRangeDeterminationCounter,
                                                  boolean *bRangeObserverFullDamp,
                                                  boolean *bRangeObserverINCDamp,
                                                  boolean *bTimeoutFullDamp,
                                                  eBlockageStates_t *eSPMBlockageState);
  /// Check if Timeout threshold is reached <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  ///
  /// @return                 Return TRUE if Full Damp conditions are fulfilled
  ///
  /// @InOutCorrelation       Check if Timeout threshold is reached (Timeout Time Counter or Timeout Way Counter)
  ///
  /// @startuml               "Call sequence for  SPMTimeoutObserver"
  /// 
  /// spm -> spm: **SPMProcessBlockageState** call\n**SPMTimeoutObserver()**
  /// activate spm
  ///   spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-577-0006e2e0
  ///  
  static boolean SPMTimeoutObserver(void);
  /// Check if  LCA or BSD Damp conditions fulfilled <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fFullDampRangeThresh                       Full Damp Range Threshold
  /// @param[in]              fFullDampRangeActivationCounterThresh      Full Damp Range Activation Counter Thresold
  /// @param[in]              fFullDampRangeActivationCounter            Full Damp Range Activation Counter 
  ///
  /// @return                 Return TRUE if LCA or BSD Damp conditions fulfilled 
  ///
  /// @InOutCorrelation       Check that FullDamp conditions specific to each function are met. \n
  ///                         As long as these conditions are met, a counter will increment, and the event will be detected only when the counter reaches the threshold.  
  ///
  /// @startuml               "Call sequence for SPMRangeObserverFullDamp"
  ///
  /// spm -> spm: **SPMBlockageSetBlockageOutput()** call\n** SPMRangeObserverFullDamp(fFullDampRangeThresh, fFullDampRangeActivationCounterThresh, fFullDampRangeDeterminationCounter)**
  /// activate spm
  ///   spm -> spm: **SPMCheckFullDampRangeConditions(fFullDampRangeThresh)**
  ///   spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test \n
  ///                         Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-570-0006e2e0
  ///
  static boolean SPMRangeObserverFullDamp(const float32 fFullDampRangeThresh,
                                          const float32 fFullDampRangeActivationCounterThresh,
                                                float32 *fFullDampRangeActivationCounter);
  /// Check if  LCA or BSD Damp conditions fulfilled <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fFullBlockageRangeThresh        Full Damp Range Threshold
  ///
  /// @return                 Return TRUE if LCA or BSD Damp conditions fulfilled 
  ///
  /// @InOutCorrelation       Check that FullDamp conditions specific to each function are met: range is below Full Blockage range threshold with trustworthy confidence.
  ///
  /// @startuml               "Call sequence for SPMCheckFullDampRangeConditions"
  ///
  /// spm -> spm: **SPMRangeObserverFullDamp()** call\n**SPMCheckFullDampRangeConditions(fFullDampRangeThresh)**
  /// activate spm
  ///   spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-566-0006e2e0
  ///  
  static boolean SPMCheckFullDampRangeConditions(const float32 fFullBlockageRangeThresh);
  /// Check if  Increase Blockage conditions fulfilled <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None   
  /// @param[in]              fINCBlockageRangeThresh     Increase Blockage Range Threshold
  ///
  /// @return                 Return TRUE if Increase Range Dampf conditions fulfilled
  ///
  /// @InOutCorrelation       Check that Increase Blockage conditions specific to each function are met: range is below Increase Blockage range threshold with trustworthy confidence.
  ///
  /// @startuml               "Call sequence for SPMRangeObserverINCDamp"
  /// 
  /// spm -> spm: **SPMBlockageSetBlockageOutput()** call\n**SPMRangeObserverINCDamp(fINCBlockageRangeThresh)**
  /// activate spm
  ///   spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-571-0006e2e0
  ///  
  static boolean SPMRangeObserverINCDamp(const float32 fINCBlockageRangeThresh);
  /// Check the Recovery Range conditions of Full Blockage <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fSPMBlockageFullRange                 Minimum Range used for recovery
  /// @param[in, out]         fFullDampRangeRecoveryCounter         Recovery Counter
  ///
  /// @return                 Return TRUE if Recovery Range conditions are fulfilled 
  ///
  /// @InOutCorrelation       As long as these conditions are met, a counter will increment, and the recovery will be detected only when the counter reaches the threshold. \n
  ///                         Full Damping Flag will be reseted.
  ///
  /// @startuml               "Call sequence for SPMRangeObserverRecoveryFullDamp"
  ///
  /// spm -> spm: **SPMBlockageSetBlockageOutput()** call\n**SPMRangeObserverRecoveryFullDamp(fSPMBlockageFullRange, fFullDampRangeDeterminationCounter)**
  /// activate spm
  ///   spm -> spm: **SPMCheckFullDampRecoveryRangeConditions(fSPMBlockageFullRange)**
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test order of calls (dynamic module test) \n
  ///                         Test of code coverage (dynamic module test) \n 
  ///                         Test of memory corruption (dynamic module test)            
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-572-0006e2e0
  ///  
  static boolean SPMRangeObserverRecoveryFullDamp(const float32 fSPMBlockageFullRange,
                                                        float32 *fFullDampRangeRecoveryCounter);
  /// Check the Recovery Range conditions of Full Blockage <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[in]              fSPMBlockageFullRange        Minimum Range used for recovery
  ///
  /// @return                 Return TRUE if Recovery Range conditions are fulfilled 
  ///
  /// @InOutCorrelation       Check that the Range value reaches the minimum range used for recovery from Full Blockage state, with trustworthy confidence.
  ///
  /// @startuml               "Call sequence for SPMCheckFullDampRecoveryRangeConditions"
  ///
  /// spm -> spm: **SPMRangeObserverRecoveryFullDamp()** call\n**SPMCheckFullDampRecoveryRangeConditions(fSPMBlockageFullRange)**
  ///   activate spm
  ///      spm --> spm:
  ///   deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-567-0006e2e0
  ///  
  static boolean SPMCheckFullDampRecoveryRangeConditions(const float32 fSPMBlockageFullRange);
  /// Map algo parameters on internal blockage parameters <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None
  /// @param[out]             ps_blockage_internal_parameters     Internal blockage parameters
#if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  /// @param[in]              ps_PartialBlockageInfo              Partial blockage status from ALN
#endif
  /// @param[in]              ps_blockage_algo_parameters         Algo parameters from BSW
  ///
  /// @return                 void
  ///
  /// @InOutCorrelation       Set blockage parameters either from external BSW values or from hard codes defines.
  ///
  /// @startuml               "Call sequence for SPMSetBlockageParameters" 
  ///
  /// spm -> spm: **SPMProcess()** call\n**SPMSetBlockageParameters()**
  /// activate spm
  ///    spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) \n
  ///                         Test of memory corruption (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-576-0006e2e0
  ///  
  static void SPMSetBlockageParameters(      SPMBlockageParameters_t        *ps_blockage_internal_parameters,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
                                       const PartialBlockage_t              *ps_PartialBlockageInfo,
  #endif
                                       const Fct_blockage_algo_parameters_t *ps_blockage_algo_parameters      );
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  /// Check condition for partial blockage from ALN <b>(part of the SRR logic)</b>
  ///
  /// @pre                    None
  /// @post                   None 
  /// @param[in]              f_Probability       Partial Blockage Probability from ALN
  /// @param[in]              f_Confidence        Partial Blockage Confidence from ALN
  ///
  /// @return                 Return TRUE if Partial Blockage conditions are fulfilled 
  ///
  /// @InOutCorrelation       If Partial blockage confidence is 1.0F and Partial blockage probability is 1.0F bSPMFullBlockageGenByALN is set to true.
  ///
  /// @startuml               "Call sequence for SPMALNPartialBlockage"
  ///
  /// spm -> spm: **SPMProcessBlockageState()** call\n**SPMALNPartialBlockage((float32)ps_PartialBlockageInfo->f_Probability, (float32)ps_PartialBlockageInfo->f_Confidence)**
  /// activate spm
  ///    spm --> spm:
  /// deactivate spm
  /// @enduml
  ///
  /// @testmethod             Test of code coverage (dynamic module test) 
  ///
  /// @traceability           doors://rbgs854a:40000/?version=2&prodID=0&view=00000007&urn=urn:telelogic::1-503e822e5ec3651e-O-564-0006e2e0
  /// 
  static boolean SPMALNPartialBlockage(float32 f_Probability, float32 f_Confidence);
  #endif
  
  /********************************************************
  
    Functionname:           SPMProcess
    
    @brief                  System Performance Monitoring main function
    
  *//************************************************************************/
  void SPMProcess (const PerfDegr_t                       *pPerfDegrData         ,
                         FCTSenErrorOut_t                 *puiBlockageEvent      ,
                         AlgoErrorState_t                 *puiSelftestEvent      ,
                         fSpeed_t                          fOwnSpeed             ,
                         fTime_t                           fCurrCycleTime        ,
				   const boolean bRollerTestBench								 ,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
                   const PartialBlockage_t                *ps_PartialBlockageInfo,
  #endif
                   const Fct_blockage_algo_parameters_t   *ps_blockage_parameters  )
  { 
  
    /*MTS information for SPMData */
    static const MEASInfo_t SPMDataMeasInfo =
    {
      /* .VirtualAddress = */
      FCT_MEAS_ID_SPM_DATA,
      /* .Length = */
      sizeof(SPMData),
      /* .FuncID = */
      SPM_MEAS_FUNC_ID,
      /* .FuncChannelID = */
      SPM_MEAS_FUNC_CHAN_ID
    };
  
    /* MTS information for SPMBlockageParameters */
    static const MEASInfo_t SPMBlockageParametersMeasInfo =
    {
      /* .VirtualAddress = */
      FCT_MEAS_ID_SPM_BLKPAR,
      /* .Length = */
      sizeof(SPMBlockageParameters),
      /* .FuncID = */
      SPM_MEAS_FUNC_ID,
      /* .FuncChannelID = */
      SPM_MEAS_FUNC_CHAN_ID
    };
  
	boolean  bRollerTestBenchState = FALSE;
    /* Initialize module local globals with ego speed and cycle time */
    fEgoSpeed  = fOwnSpeed;
    fCycleTime = fCurrCycleTime;
	bRollerTestBenchState = bRollerTestBench;

    /* set blockage parameters, either take external BSW parameter from RTE or hard coded defines
    Note: formerly only done in SPM_INIT, now done each cycle (negligable runtime), which allows
    online coding (changing of blockage parameters) */

    SPMSetBlockageParameters(&SPMBlockageParameters ,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)   
                              ps_PartialBlockageInfo,
  #endif
                              ps_blockage_parameters );
    switch (StateSPM)
    {
    case SPM_OK:
      /* decision of selftest results (PD_STARTUP, GDB_PD_ON, GDB_PD_OFF, PD_ROADBEAM_TEST) and setting of events/inhibitions */
      SPMSelftest(pPerfDegrData, puiBlockageEvent, puiSelftestEvent, bRollerTestBenchState);
      
	  /* pause SPM (blockage process) in case "bRollerTestBench" is TRUE */
	  if(bRollerTestBenchState == FALSE)
	  {
		  /* Start Blockage Determination only after successful Selftest */
		  /*Range of speed for Blockage Detection*/
		  if(    (SPMData.SPMSelftestState == GDB_PD_ON    )
			  && (fEgoSpeed                 > SPM_SPEED_MIN) 
			  && (fEgoSpeed                <= SPM_SPEED_MAX))
		  {
			#if SPM_CFG_USE_OBJECTLOSS 
			/*object loss for SRR */
			/* process object loss,  only Blockage is enable, NoOfAllowedObjLosses is > 0 and after successful selftest */
			/*  Object Loss criterion */
			if (    (SPMBlockageParameters.bEnableBlockage        == (boolean)SWITCH_ON         )
				 && (SPMBlockageParameters.uiNoOfAllowedObjLosses > 0U                          )
			   )
			{
			  /* Blockage Detection observing losses of the relevant object */
			  SPMProcessObjectLoss(fOwnSpeed);
			}
			else
			{
			  /*nop*/
			}
			#endif
  
			#if SPM_CFG_USE_WIPER_ADAPT
			 /* Only call function if wiper delay parameter is > 0 seconds and Blockage Function is enabled */
			if(   (SPMBlockageParameters.bEnableBlockage == (boolean)SWITCH_ON )
				&&(SPMBlockageParameters.fWiperDelay      > C_F32_DELTA        ))
			{
			  /* special Blockage conditions for SRR ford */
			  /* include wiper OFF inhibit, minimum blockage alert time, etc..*/
			  SPMWiperAdaptBlockageState (SPMBlockageParameters.fWiperDelay,
										  SPMBlockageParameters.fBlockage1VerificationTime,
										  puiBlockageEvent->BlockageStateBSD,
										  fCycleTime,
										  &puiBlockageEvent->uFusedBlockageProbability);
			}
			#endif
  
			/* process all blockage data and set current blockage state */
			/* set blockage DEM events */
			SPMProcessBlockageState(pPerfDegrData,
	  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
									ps_PartialBlockageInfo,
	  #endif
									puiBlockageEvent      );
			/* special Blockage conditions for SRR ford */
			/* Only adapt the Blockage event if wiper delay parameter is > 0 seconds and Blockage Function is enabled */
			if(   (SPMBlockageParameters.bEnableBlockage == (boolean)SWITCH_ON )
				&&(SPMBlockageParameters.fWiperDelay      > C_F32_DELTA        ))
			{
			  if ( SPMData.bWiperBlockageHoldOff == TRUE )
			  {
				puiBlockageEvent->BlockageStateFCTA = FCT_NO_BLOCKAGE;
			  }
  
			  if ( SPMData.bWiperBlockageHoldOn == TRUE )
			  {
				puiBlockageEvent->BlockageStateFCTA = FCT_FULL_BLOCKAGE;
			  }
			}
  
		  }
	  }
      #if((EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD) && (FCT_SEN_ERROR_OUT_INTFVER >= 20U))      /* Check RTE version */
		SPMInterferenceRange(pPerfDegrData->fNoiseRange, pPerfDegrData->bNoiseRangeValid, puiBlockageEvent);
		SPMData.SensorFarRangeLimit = SENSOR_FAR_RANGE_LIMIT;
		if((CML_f_IsZero(SPMData.SPMBlockageRange))||(SPMData.SPMBlockageRangeConf < 0.4f)||(pPerfDegrData->bNoiseRangeValid == FALSE))
		{
			puiBlockageEvent->fVisibilityRange = UNKNOWN_RANGE;
		}
		else
		{
			puiBlockageEvent->fVisibilityRange = CML_Min(SPMData.SensorFarRangeLimit,CML_Min(SPMData.SPMBlockageRange, SPMData.SPMInterferenceRange));	
		}
	  #endif
	  break;
    case SPM_EOL:
      /* decision of selftest results and setting of events/inhibitions */
      SPMSelftest(pPerfDegrData, puiBlockageEvent, puiSelftestEvent, bRollerTestBenchState);
      break;
    case SPM_INIT:
      SPMInit();
      break;
    // keep blockage output before PAUSE state 
    case SPM_PAUSE:
      break;
    default:
      SPMInit();
      break;
    }/* end switch */
  
    (void)FCT_FREEZE_DATA(&SPMDataMeasInfo, &SPMData, &FCTSenMeasCallback);
    (void)FCT_FREEZE_DATA(&SPMBlockageParametersMeasInfo, &SPMBlockageParameters, &FCTSenMeasCallback);
  }
  
  /********************************************************
  
    Functionname:           SPMInit
    
    @brief                  Initializing of SPM data
    
  *//************************************************************************/
  static void SPMInit(void)
  {
    #if SPM_CFG_USE_OBJECTLOSS
    /*********************************************/
    /* Initialization of Object Loss statistics */
    /*********************************************/
    SPMInitObjectLoss();
    #endif
  
    #if SPM_CFG_USE_WIPER_ADAPT
    /************************************/
    /*Init Wiper Data parameter which used 
     for adaption of Blockage State*/
    /************************************/
    SPMInitWiperData();
    #endif
    /************************************/
    /* Initialization of Blockage data */
    /************************************/
     /* Initializtion of all Blockag criteria */
    /* Range */
    SPMData.SPMBlockageRange                 = 0.0F;
    SPMData.SPMBlockageRangeConf             = SPM_CONFIDENCE_MIN;
    SPMData.bBSDRangeFullDamp                = FALSE;
    SPMData.bLCARangeFullDamp                = FALSE;
    SPMData.bFCTARangeFullDamp               = FALSE;
    SPMData.bBSDRangeINCDamp                 = FALSE;
    SPMData.bLCARangeINCDamp                 = FALSE;
    SPMData.bFCTARangeINCDamp                = FALSE;
    SPMData.SPMBSDRangeDeterminationCounter  = 0.0F;
    SPMData.SPMLCARangeDeterminationCounter  = 0.0F;
    SPMData.SPMFCTARangeDeterminationCounter = 0.0F;
  
    /* Timeout */
    SPMData.bBSDTimeoutFullDamp = FALSE;
    SPMData.bLCATimeoutFullDamp = FALSE;
    SPMData.bFCTATimeoutFullDamp = FALSE;
    SPMData.SPMFullDampRecoveryCounter    = 0.0F;
    SPMData.SPMBlockageTimeoutTimeCounter = 0.0F;
    SPMData.SPMBlockageTimeoutWayCounter	= 0.0F;
  
	#if((EM_PERF_DEGR_INTFVER >= EM_PERF_INTERFERENCE_INT_VER_THLD) && (FCT_SEN_ERROR_OUT_INTFVER >= 20U))      /* Check RTE version */
	/* Interference */
	SPMData.SPMInterferenceRange	= -1.0F;
	SPMData.SPMInterference			= 0UL;
	SPMData.SPMInterferenceHoldCnt	= 0U;
	SPMData.SPMInterferenceState	= FALSE;
	SPMData.InterferenceRangeThld	= 0.0F;
	SPMData.SensorFarRangeLimit		= 0.0F;
    #endif
    /************************************/
    /* Initialization of Selftest data */
    /************************************/
    SPMData.SPMSelftestState         = GDB_PD_STARTUP;
    SPMData.SPMSelftestTimeCounter   = 0.0F;
  
    SPMData.SPMSelftestTimeCounterThld = SPM_TMAX_UNTIL_OBJ;
  
    SPMData.SPMSelftestInput.SPMSelftestRangeMov      = 0.0F;
    SPMData.SPMSelftestInput.SPMSelftestRangeMovConf  = SPM_CONFIDENCE_MIN;
    SPMData.SPMSelftestInput.SPMSelftestRangeSta      = 0.0F;
    SPMData.SPMSelftestInput.SPMSelftestRangeStaMax   = 0.0F;
    SPMData.SPMSelftestInput.SPMSelftestRangeStaConf  = SPM_CONFIDENCE_MIN;
  
    /************************************/
    /* Initialization of Object Loss Observer data */
    /************************************/
    SPMData.uObjLossBSDNoOfRelObjLosses = 0U;
    SPMData.uObjLossLCANoOfRelObjLosses = 0U;
    SPMData.bObjectLossBSDPerfDegrFlag  = FALSE;
    SPMData.bObjectLossLCAPerfDegrFlag  = FALSE; 
  
     /************************************/
    /* Initialization of Wiper data for the Special Adapt function*/
    /************************************/
    SPMData.bWiperBlockageHoldOn        = TRUE;
    SPMData.bWiperBlockageHoldOff       = FALSE;
  
      /**********************************/
    /* initialization of Partial blockage from ALN data */
    /**********************************/
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT== SWITCH_ON)
    SPMData.bSPMFullBlockageGenByALN    = FALSE;
  #endif
  }
  
  
  
  /********************************************************
  
    Functionname:           SPMSelftestDetermination
    
    @brief                  Selftest state machine
    
  *//************************************************************************/
  /************************************************************************/
  /* date: 2016-04-18, reviewer: M. Musat,  reason:  The default case is  */
  /* empty on purpose, 'switch' statement does not have unknown cases     */
  /************************************************************************/
  /* PRQA S 2016 L1 */
  static void SPMSelftestDetermination(const PerfDegr_t *pPerfDegrData,
									   const boolean bRollerTestBenchState)
  {
    /* Determine selftest only if blockage is enabled */
    if(
		(SPMBlockageParameters.bEnableSelftest == (boolean)SWITCH_ON)
	  &&(bRollerTestBenchState == FALSE)
	)
    {
      SPMData.SPMSelftestInput.SPMSelftestRangeMov      = pPerfDegrData->RangeRaw.fMovingMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeSta      = pPerfDegrData->RangeRaw.fStationaryMeanRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaMax   = pPerfDegrData->RangeRaw.fStationaryMaxRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeMovConf  = pPerfDegrData->RangeRaw.fMovingConfRaw;
      SPMData.SPMSelftestInput.SPMSelftestRangeStaConf  = pPerfDegrData->RangeRaw.fStationaryConfRaw;
  
  
      /* start selftest state machine */
      switch(SPMData.SPMSelftestState)
      {
      /********************************************************/
      /* Continue here if Current Selftest State is GDB_PD_ON */
      /********************************************************/
      case GDB_PD_ON:
        break;
  
      /*************************************************************/
      /* Continue here if Current Selftest State is GDB_PD_STARTUP */
      /*************************************************************/
      case GDB_PD_STARTUP:
        /* "weak" criteria to activate the function aftern system start */
        if/* first possible condition: activation by moving objects */
          (((  (SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_RANGE_MIN) && (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf > SPM_SELFTEST_CONFIDENCE_MIN))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_RANGE_MIN) || (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf < SPM_SELFTEST_CONFIDENCE_MIN)))
            ||
            /* second possible condition: activation by stationary objects */
             (((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_RANGE_MIN) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > (SPM_SELFTEST_CONFIDENCE_MIN * 2.0F)))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_RANGE_MIN) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_CONFIDENCE_MIN)))
            ||
            /* third possible condition: activation by max. of stationary objects (special condition for moving objects here!) */
             (((SPMData.SPMSelftestInput.SPMSelftestRangeStaMax > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > (SPM_SELFTEST_CONFIDENCE_MIN * 4.0F)))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov    > SPM_SELFTEST_RANGE_MIN)          || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_CONFIDENCE_MIN))))
        {
          /* At least one condition fulfilled, selftest passed */
          SPMData.SPMSelftestState = GDB_PD_ON;
        }
        else
        {
          /* Conditions not fulfilled, selftest not passed, increase selftest time counter */
          SPMData.SPMSelftestTimeCounter += fCycleTime;
  
          /* If selftest time counter has reached its maximum... */
          if(SPMData.SPMSelftestTimeCounter >= SPMData.SPMSelftestTimeCounterThld)
          {
            /* ... deactivate the system, selftest failed */
            SPMData.SPMSelftestState = GDB_PD_OFF;
          }
        }
        break;
  
      
      /*********************************************************/
      /* Continue here if Current Selftest State is GDB_PD_OFF */
      /*********************************************************/
      case GDB_PD_OFF:
      
        /* "hard" criteria to activate the function aftern failed selftest */
        if/* first possible condition: activation by moving objects */
           (( ((SPMData.SPMSelftestInput.SPMSelftestRangeMov> SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf > SPM_SELFTEST_REACTIVATION_CONF))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf < SPM_SELFTEST_REACTIVATION_CONF)))
            ||
            /* second possible condition: activation by stationary objects */
             (((SPMData.SPMSelftestInput.SPMSelftestRangeSta > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > SPM_SELFTEST_REACTIVATION_CONF))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_REACTIVATION_CONF)))
            ||
            /* third posible condition: activation by max. of stationary objects (special condition for moving objects here!) */
             (((SPMData.SPMSelftestInput.SPMSelftestRangeStaMax > SPM_SELFTEST_REACTIVATION_RANGE) && (SPMData.SPMSelftestInput.SPMSelftestRangeStaConf > SPM_SELFTEST_REACTIVATION_CONF))
            &&((SPMData.SPMSelftestInput.SPMSelftestRangeMov    > SPM_SELFTEST_REACTIVATION_RANGE) || (SPMData.SPMSelftestInput.SPMSelftestRangeMovConf < SPM_SELFTEST_REACTIVATION_CONF))))
        {
          /* Higher reactivation conditions fulfilled, reactivate the system */
          SPMData.SPMSelftestState = GDB_PD_ON;
        }
        else
        {
          /* increase selftest time counter */
          SPMData.SPMSelftestTimeCounter += fCycleTime;
        }
        break;
      default:
        break;
      }
    }
    /* always report succesful selftest if blockage is disabled */
    else
    {
      SPMData.SPMSelftestState = GDB_PD_ON;
    }
  }
  /* PRQA L:L1 */
  
  /********************************************************
  
    Functionname:           SPMSelftestSetBlockageOutput
    
    @brief                  Generate and communicate selftest data to DEM component
    
  *//************************************************************************/
  static void SPMSelftestSetBlockageOutput (eGDBPDStates_t    State           , 
                                            FCTSenErrorOut_t *puiBlockageEvent,
                                            AlgoErrorState_t *puiSelftestEvent )
  {
    switch(State)
    {
    case GDB_PD_STARTUP:
      /* Selftest in process -> no object has been measured yet */
      *puiSelftestEvent = AL_ERR_STATE_UNKNOWN;
      puiBlockageEvent->BlockageStateLCA  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateBSD  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTA = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTA = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTB = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTB = FCT_NO_BLOCKAGE;
  
      break;
    case GDB_PD_ON:
      *puiSelftestEvent = AL_ERR_STATE_INACTIVE;
      /* Blockage flag is handled in main algo after passed Selftest, do not set here anymore */
      break;
    case GDB_PD_OFF:
      /* Selftest failed -> no object has been measured */
      *puiSelftestEvent = AL_ERR_STATE_ACTIVE;
      puiBlockageEvent->BlockageStateLCA          = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->BlockageStateBSD          = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTA         = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTA         = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTB         = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTB         = FCT_FULL_BLOCKAGE;
      puiBlockageEvent->uFusedBlockageProbability = SPM_FUSED_BLOCKAGE_PROB_MAX;
      break;
    default:
      *puiSelftestEvent = AL_ERR_STATE_UNKNOWN;
      puiBlockageEvent->BlockageStateLCA  = FCT_UNKNOWN_BLOCKAGE;
      puiBlockageEvent->BlockageStateBSD  = FCT_UNKNOWN_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTA = FCT_UNKNOWN_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTA = FCT_UNKNOWN_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTB = FCT_UNKNOWN_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTB = FCT_UNKNOWN_BLOCKAGE;
      break;
    }
  }
  
  /********************************************************
  
    Functionname:           SPMSelftest
    
    @brief                  Selftest call state maching
    
  *//************************************************************************/
  /************************************************************************/
  /* date: 2016-04-18, reviewer: M. Musat,  reason:  The default case is  */
  /* empty on purpose, 'switch' statement does not have unknown cases     */
  /************************************************************************/
  /* PRQA S 2016 L1 */
  static void SPMSelftest(const PerfDegr_t        *pPerfDegrData   , 
                                FCTSenErrorOut_t  *puiBlockageEvent,
                                AlgoErrorState_t  *puiSelftestEvent,
								const boolean bRollerTestBenchState)
  {
    switch(StateSPM)
    {
    case SPM_EOL:
      *puiSelftestEvent = AL_ERR_STATE_INACTIVE;  /* Selftest shall be reported as passed in EOL mode */
      puiBlockageEvent->BlockageStateLCA  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateBSD  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTA = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTA = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTB = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTB = FCT_NO_BLOCKAGE;
      break;
    case SPM_OK:
      /* execute selftest if ego speed is above threshold or blockage is disabled -> selftest is reported as passed immediately after startup */
      if( (fEgoSpeed                             >  SPM_SPEED_MIN_SELFTEST )
        ||(SPMBlockageParameters.bEnableSelftest == FALSE                  ) 
		||(bRollerTestBenchState == TRUE))
      {
        /* Determine selftest state */
        SPMSelftestDetermination(pPerfDegrData,
								 bRollerTestBenchState);
      }
      else
      {
        /* Selftest only over vehicle speed min */
      }
  
      /* Set Blockage Output for Selftest */
      SPMSelftestSetBlockageOutput(SPMData.SPMSelftestState, puiBlockageEvent, puiSelftestEvent);
  
      break;
    /* just for a happy Misra add SPM_INIT */
    case SPM_INIT:
    case SPM_PAUSE:
    default:
      break;
    }
  }
  /* PRQA L:L1 */
  
  /********************************************************
  
    Functionname:           SPMProcessBlockageState
    
    @brief                  Determination of BSD and LCA Performance Degradation flag and Full Damping                          
    
  *//************************************************************************/
  static void SPMProcessBlockageState(const PerfDegr_t        *pPerfDegrData,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT== SWITCH_ON)
                                      const PartialBlockage_t *ps_PartialBlockageInfo,
  #endif
                                            FCTSenErrorOut_t  *puiBlockageEvent        )
  {
  
    boolean bHelpValueTimeoutFullDamp = FALSE;
  
    /******************************************************************/
    /*  Copy Range and Timeout Data to SPM main structure */
    /******************************************************************/
    SPMData.SPMBlockageRange              = pPerfDegrData->RangeFused.fFusedRange;
    SPMData.SPMBlockageRangeConf          = pPerfDegrData->RangeFused.fFusedConf;
  
    SPMData.SPMBlockageTimeoutTimeCounter = pPerfDegrData->Timeout.fTimeCounter;
    SPMData.SPMBlockageTimeoutWayCounter  = pPerfDegrData->Timeout.fWayCounter;
  
    /* increase codomain for confidence from 0-0.9 to 0-1 */
    SPMData.SPMBlockageRangeConf /= 0.9F;
    SPMData.SPMBlockageRangeConf = MIN_FLOAT(1.0F, SPMData.SPMBlockageRangeConf);
    
    /****************************************************************************************/
    /*  Determination of SRR FCT Blockage output */
    /****************************************************************************************/
    /* Determine blockage state only if blockage is enabled */
    if(SPMBlockageParameters.bEnableBlockage == (boolean)SWITCH_ON)
    {
       /******************************************************/
      /* Start State Determination  */
      /******************************************************/
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
      SPMData.bSPMFullBlockageGenByALN = SPMALNPartialBlockage((float32)ps_PartialBlockageInfo->f_Probability,(float32) ps_PartialBlockageInfo->f_Confidence );
  
      if (SPMData.bSPMFullBlockageGenByALN == TRUE)
      {
        puiBlockageEvent->BlockageStateLCA  = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateBSD  = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateFCTA = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateRCTA = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateFCTB = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateRCTB = FCT_FULL_BLOCKAGE;
      }
  #endif
      /* Process Timeout Observer*/
      bHelpValueTimeoutFullDamp = SPMTimeoutObserver(); 
    
      /* Check if Timeout threshold is reached (Time counter or way counter)*/
      if(bHelpValueTimeoutFullDamp == TRUE)
      {
        /*Full Damping*/
        /* Timeout (Time counter or way counter is reached) set all SRR FCT BSD, LCA, RCTA and RCTB toFull Blockage*/
        puiBlockageEvent->BlockageStateLCA  = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateBSD  = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateFCTA = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateRCTA = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateFCTB = FCT_FULL_BLOCKAGE;
        puiBlockageEvent->BlockageStateRCTB = FCT_FULL_BLOCKAGE;
  
        /*reset BSD and LCA Range Hold counter*/
        SPMData.SPMBSDRangeDeterminationCounter  = 0.0F;
        SPMData.SPMLCARangeDeterminationCounter  = 0.0F;
        SPMData.SPMFCTARangeDeterminationCounter = 0.0F;
        /*Timeout Observer Result coppied in SPMData for using in Blockage MO*/
        SPMData.bBSDTimeoutFullDamp = TRUE;
        SPMData.bLCATimeoutFullDamp = TRUE;
        SPMData.bFCTATimeoutFullDamp = TRUE;
      }
  
      /* Range and ObjectLoss Blockage Observer*/
      else  
      {
        /*Determine BSD Blockage State*/ 
        SPMBlockageSetBlockageOutput (SPMBlockageParameters.fShutOffBSDRange,
                                      SPMBlockageParameters.fBSDRangeHoldCounterTHLD,
                                      (float32)SPM_BLOCKAGE_INC_BSD_RANGE,
                                      (float32)SPM_BLOCKAGE_FULL_BSD_RANGE,
                                      SPMData.bObjectLossBSDPerfDegrFlag,
                                      &SPMData.SPMBSDRangeDeterminationCounter,
                                      &SPMData.bBSDRangeFullDamp,
                                      &SPMData.bBSDRangeINCDamp,
                                      &SPMData.bBSDTimeoutFullDamp,
                                      &puiBlockageEvent->BlockageStateBSD);
  
        /*Determine LCA Blockage State*/ 
        SPMBlockageSetBlockageOutput (SPMBlockageParameters.fShutOffLCARange,
                                      SPMBlockageParameters.fLCARangeHoldCounterTHLD,
                                      (float32)SPM_BLOCKAGE_INC_LCA_RANGE,
                                      (float32)SPM_BLOCKAGE_FULL_LCA_RANGE,
                                      SPMData.bObjectLossLCAPerfDegrFlag,
                                      &SPMData.SPMLCARangeDeterminationCounter,
                                      &SPMData.bLCARangeFullDamp,
                                      &SPMData.bLCARangeINCDamp,
                                      &SPMData.bLCATimeoutFullDamp,
                                      &puiBlockageEvent->BlockageStateLCA);
  
        /*Determine FCTA Blockage State*/ 
        SPMBlockageSetBlockageOutput (SPMBlockageParameters.fShutOffLCARange,
                                      SPMBlockageParameters.fLCARangeHoldCounterTHLD,
                                      (float32)SPM_BLOCKAGE_INC_LCA_RANGE,
                                      (float32)SPM_BLOCKAGE_FULL_LCA_RANGE,
                                      SPMData.bObjectLossLCAPerfDegrFlag,
                                      &SPMData.SPMFCTARangeDeterminationCounter,
                                      &SPMData.bFCTARangeFullDamp,
                                      &SPMData.bFCTARangeINCDamp,
                                      &SPMData.bFCTATimeoutFullDamp,
                                      &puiBlockageEvent->BlockageStateFCTA);
  
        /*Set FCTA/RCTA Blockage State*/
        puiBlockageEvent->BlockageStateRCTB = puiBlockageEvent->BlockageStateBSD;
        puiBlockageEvent->BlockageStateRCTA = puiBlockageEvent->BlockageStateBSD;
        puiBlockageEvent->BlockageStateFCTB = puiBlockageEvent->BlockageStateFCTA;
      }
    }
    else
    {
      /* set always "no damp" if blockage is disabled */
      puiBlockageEvent->BlockageStateLCA  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateBSD  = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateFCTA = FCT_NO_BLOCKAGE;
      puiBlockageEvent->BlockageStateRCTA = FCT_NO_BLOCKAGE;
  
      /*Timeout and Range Observer Result coppied in SPMData for using in Blockage MO*/
      SPMData.bBSDTimeoutFullDamp  = FALSE;
      SPMData.bLCATimeoutFullDamp  = FALSE;
      SPMData.bFCTATimeoutFullDamp = FALSE;
      SPMData.bBSDRangeFullDamp    = FALSE;
      SPMData.bLCARangeFullDamp    = FALSE;
    }

  #if((SPM_OBSERVERS_HISOTRY == SWITCH_ON) && (FCT_SEN_ERROR_OUT_INTFVER >= ERROR_OUT_MIN_INT_VER))
	if(SPMData.bSPMFullBlockageGenByALN == TRUE)
    {
 	  puiBlockageEvent->PartialBlockageObserver = AL_ERR_STATE_ACTIVE;
	  puiBlockageEvent->TimeoutObserver = AL_ERR_STATE_INACTIVE;
	  puiBlockageEvent->RangeObserver = AL_ERR_STATE_INACTIVE;
    }
    else
    {
		puiBlockageEvent->PartialBlockageObserver = AL_ERR_STATE_INACTIVE;
    }
  
	if( (SPMData.bBSDTimeoutFullDamp == TRUE)|| 
		(SPMData.bLCATimeoutFullDamp == TRUE)||
		(SPMData.bFCTATimeoutFullDamp == TRUE)
	  )
    {
		puiBlockageEvent->TimeoutObserver = AL_ERR_STATE_ACTIVE;
		puiBlockageEvent->PartialBlockageObserver = AL_ERR_STATE_INACTIVE;
		puiBlockageEvent->RangeObserver = AL_ERR_STATE_INACTIVE;
    }
    else
    {
		puiBlockageEvent->TimeoutObserver = AL_ERR_STATE_INACTIVE;
    }

    if( (SPMData.bBSDRangeFullDamp == TRUE )|| 
	    (SPMData.bFCTARangeFullDamp == TRUE)||
	    (SPMData.bLCARangeFullDamp == TRUE )
	  )
    {
		puiBlockageEvent->RangeObserver = AL_ERR_STATE_ACTIVE;
		puiBlockageEvent->PartialBlockageObserver = AL_ERR_STATE_INACTIVE;
		puiBlockageEvent->TimeoutObserver = AL_ERR_STATE_INACTIVE;
    }
    else
    {
		puiBlockageEvent->RangeObserver = AL_ERR_STATE_INACTIVE;
    }
  #endif
  }
  
  /********************************************************
    Functionname:           SPMBlockageSetBlockageOutput
    
    @brief                  Set Blockage Output
    
  *//************************************************************************/
  static void SPMBlockageSetBlockageOutput (const float32 fFullDampRangeThresh,
                                            const float32 fFullDampRangeActivationCounterThresh,
                                            const float32 fINCBlockageRangeThresh,
                                            const float32 fSPMBlockageFullRange,
                                            const boolean bObjectLossObesrverFullDamp,
                                                  float32 *fFullDampRangeDeterminationCounter,
                                                  boolean *bRangeObserverFullDamp,
                                                  boolean *bRangeObserverINCDamp,
                                                  boolean *bTimeoutFullDamp,
                                                  eBlockageStates_t *eSPMBlockageState)
  {
    /*****************************************************/
    /*          Set current SRR blockage events          */
    /*****************************************************/
     boolean bHelpValueNODamp   = FALSE;
  
    /* Set current Blockage Events */
    switch (*eSPMBlockageState)
    {
      /*********************************************************/
      /* Continue here if current State is NO BLOCKAGE */
      /*********************************************************/
      case FCT_NO_BLOCKAGE:
        
        /* Process Range Observer Full Damp*/
        if(*bRangeObserverFullDamp == FALSE)
        {
          *bRangeObserverFullDamp = SPMRangeObserverFullDamp(fFullDampRangeThresh, fFullDampRangeActivationCounterThresh, fFullDampRangeDeterminationCounter);
        }
        else
        {
        }
        /* Process Range Observer INC Damp*/
        *bRangeObserverINCDamp  = SPMRangeObserverINCDamp(fINCBlockageRangeThresh);
  
        if(    (*bRangeObserverFullDamp     == TRUE)
            || (bObjectLossObesrverFullDamp == TRUE)
          )
        {
          /*Range Observer or Objectloss detect  Full Blockage*/
          *eSPMBlockageState = FCT_FULL_BLOCKAGE;
          /*reset Range Hold counter*/
          *fFullDampRangeDeterminationCounter = 0.0F;
        }
        else if(*bRangeObserverINCDamp == TRUE)
        {
          /*Range Observer detect  INC Blockage*/
          *eSPMBlockageState = FCT_INC_BLOCKAGE;
        }
        else
        {
          /* keep state */
        }
        break;
      /*********************************************************/
      /* Continue here if current State is INC BLOCKAGE */
      /*********************************************************/
      case FCT_INC_BLOCKAGE:
        /* set blockage flag only after passed selftest */
        *bRangeObserverFullDamp = SPMRangeObserverFullDamp(fFullDampRangeThresh, fFullDampRangeActivationCounterThresh, fFullDampRangeDeterminationCounter);
        *bRangeObserverINCDamp  = SPMRangeObserverINCDamp(fINCBlockageRangeThresh);
  
        if(    (*bRangeObserverFullDamp     == TRUE)
            || (bObjectLossObesrverFullDamp == TRUE)
          )
        {
          /*Range Observer or Objectloss detect  Full Blockage*/
          *eSPMBlockageState = FCT_FULL_BLOCKAGE;
          /*reset Range Hold counter*/
          *fFullDampRangeDeterminationCounter = 0.0F;
        }
        else if(*bRangeObserverINCDamp == FALSE)
        {
          /* reset INC Blockage*/
          *eSPMBlockageState = FCT_NO_BLOCKAGE;
        }
        else
        {
          /* keep state */
        }
        break;
      /*********************************************************/
      /* Continue here if current State is FULL BLOCKAGE */
      /*********************************************************/
      case FCT_FULL_BLOCKAGE:
        /* set blockage flag only after passed selftest */
        if(   (*bTimeoutFullDamp == FALSE)
            &&(*bRangeObserverFullDamp  == FALSE)
          )
        {
          bHelpValueNODamp = TRUE;
        }
        else
        {
          bHelpValueNODamp = SPMRangeObserverRecoveryFullDamp(fSPMBlockageFullRange, fFullDampRangeDeterminationCounter);
        }
  
        if(    (bHelpValueNODamp            == TRUE )
            && (bObjectLossObesrverFullDamp == FALSE)
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
            && (SPMData.bSPMFullBlockageGenByALN == FALSE)
  #endif
          )
        {
          /*Range Observer or Objectloss recovery  Full Blockage*/
          *eSPMBlockageState = FCT_NO_BLOCKAGE;
          /*reset Range Recovery counter*/
          *fFullDampRangeDeterminationCounter = 0.0F;
           
          *bTimeoutFullDamp = FALSE;
          *bRangeObserverFullDamp  = FALSE;
          *bRangeObserverINCDamp   = FALSE;
        }
        else
        {
          /* keep state */
        }
        break;
      default:
        *eSPMBlockageState = FCT_UNKNOWN_BLOCKAGE;
        break;
    }
  }
  
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
  /********************************************************
  
    Functionname:           - SPMALNPartialBlockage
    
    @brief                  - check condition for partial blockage from ALN                 
    
  *//************************************************************************/
  static boolean SPMALNPartialBlockage(float32 f_Probability, float32 f_Confidence)
  {
    boolean bReturnValue = FALSE;
  
    if( (CML_f_IsZero(f_Probability - 1.0F)) && (CML_f_IsZero(f_Confidence - 1.0F)))
    {
      bReturnValue = TRUE;
    }
    else if((CML_f_IsZero(f_Probability)) && (CML_f_IsZero(f_Confidence - 1.0F)))
    {
      bReturnValue = FALSE;
    }
    else 
    {
      /* do nothing*/
    }
    return bReturnValue;
  }
  #endif
  /*************************************************************************
  
    Functionname:           boolean SPMTimeoutObserver(void)
    
    @brief                  Check if Timeout threshold is reached                         
    
  *//************************************************************************/
  static boolean SPMTimeoutObserver(void)
  {
    boolean bReturnValue = FALSE;
  
    /* Check if Timeout threshold is reached (Time counter or way counter)*/
    if(   (SPMData.SPMBlockageTimeoutTimeCounter > SPMBlockageParameters.fTimeoutShutOffTime)
        ||(SPMData.SPMBlockageTimeoutWayCounter  > SPMBlockageParameters.fTimeoutShutOffWay )
      )
    {
      /*Timeout threshold is reached*/
      bReturnValue = TRUE;
    }
  
    return bReturnValue;
  }
  
  /********************************************************
  
    Functionname:           boolean SPMRangeObserverFullDamp(const float32 fFullDampRangeThresh,
                                                             const float32 fFullDampRangeActivationCounterThresh,
                                                             float32 *fFullDampRangeActivationCounter)
  
    @brief                  Check if  LCA or BSD Damp conditions fullfilled                         
    
  *//************************************************************************/
  static boolean SPMRangeObserverFullDamp(const float32 fFullDampRangeThresh,
                                          const float32 fFullDampRangeActivationCounterThresh,
                                                float32 *fFullDampRangeActivationCounter)
  {
    boolean bReturnValue = FALSE;
    boolean bFullDampRangeConditions = FALSE;
    bFullDampRangeConditions = SPMCheckFullDampRangeConditions(fFullDampRangeThresh); 
  
    /* if range is below Range Damp threshold and confidence is good enough, increment hold timer for Range Damp */
    if(bFullDampRangeConditions == TRUE)
    {
      
      if(*fFullDampRangeActivationCounter >= fFullDampRangeActivationCounterThresh)
      {
        bReturnValue = TRUE;
      }
      else
      {
        /* shutoff range reached with trustworthy confidence, increment hold timer */
        *fFullDampRangeActivationCounter = *fFullDampRangeActivationCounter + fCycleTime;
      }
    }
    /* reset determination counter if the FullDampRangeConditions are not fullfied */
    else if(SPMData.SPMBlockageRangeConf > SPM_STATE_CONF_MIN)
    {
        if(SPMData.SPMBlockageRange > fFullDampRangeThresh)
        {
          *fFullDampRangeActivationCounter = 0.0f;
        }
        else
        {
          // just MISRA
        }
    }
    else
    {
      // just MISRA
    }
   
    return bReturnValue;
  }
  
  /********************************************************
  
    Functionname:           boolean SPMCheckFullDampRangeConditions(float32 fFullBlockageRangeThresh)
    
    @brief                  Check if  Range Full Damp conditions fullfilled                         
  
  *//************************************************************************/
  static boolean SPMCheckFullDampRangeConditions(const float32 fFullBlockageRangeThresh)
  {
    boolean bReturnValue = FALSE;
  
    if(    (SPMData.SPMBlockageRange     < fFullBlockageRangeThresh) 
        && (SPMData.SPMBlockageRangeConf > SPM_STATE_CONF_MIN      ) 
      )
    {
      /*Range is below Full Blockage range threshold with trustworthy confidence, return True*/
      bReturnValue = TRUE;
    }
   
    return bReturnValue;
  }
  
  /********************************************************
  
    Functionname:           boolean SPMRangeObserverINCDamp(float32 fINCBlockageRangeThresh)
    
    @brief                  Check if  Increase Blockage conditions fullfilled                         
    
  *//************************************************************************/
  static boolean SPMRangeObserverINCDamp(const float32 fINCBlockageRangeThresh)
  {
    boolean bReturnValue = FALSE;
  
    if(    (SPMData.SPMBlockageRange     < fINCBlockageRangeThresh          ) 
        && (SPMData.SPMBlockageRangeConf > SPM_RANGE_CONF_INC_BLOCKANGE_MIN ) 
      )
    {
      /*Range is below Increase Blockage range threshold with trustworthy confidence, return True*/
      bReturnValue = TRUE;
    }
    return bReturnValue;
  }
  
  /********************************************************
  
    Functionname:           SPMRangeObserverRecoveryFullDamp
    
    @brief                  Determination of BSD and LCA Performance Degradation flag and Full Damping                          
  
  *//************************************************************************/
  static boolean SPMRangeObserverRecoveryFullDamp(const float32 fSPMBlockageFullRange,
                                                        float32 *fFullDampRangeRecoveryCounter)
  {
    boolean bReturnValue = FALSE;
    boolean bFullDampRecoveryRangeConditions = FALSE;
   
    /*Check Damping Recovery Range Conditions*/
    bFullDampRecoveryRangeConditions = SPMCheckFullDampRecoveryRangeConditions(fSPMBlockageFullRange);
    
    /* if Full Damping is reported and Recovery Range reached Update Full Damping Flag*/
    if(bFullDampRecoveryRangeConditions == TRUE)
    {
      if(*fFullDampRangeRecoveryCounter >= SPM_BLOCKAGE_REACTIVATION_DELAY)
      {
        /*Full Damping Recovery timer reached, return True (Full Damping Flag will be reseted)*/
        bReturnValue    = TRUE;
      }
      else
      {
        /* increment Recovery Counter */
        *fFullDampRangeRecoveryCounter = *fFullDampRangeRecoveryCounter + fCycleTime;
      }
    }
    
    return bReturnValue;
  }
  
  /********************************************************
  
    Functionname:           boolean SPMCheckFullDampRecoveryRangeConditions(void)
    
    @brief                  Check the  Recovery Range conditions of Full Blockage                        
  
  *//************************************************************************/
  static boolean SPMCheckFullDampRecoveryRangeConditions(const float32 fSPMBlockageFullRange)
  {
    boolean bReturnValue = FALSE;
  
    if(    (SPMData.SPMBlockageRange     >= fSPMBlockageFullRange) 
        && (SPMData.SPMBlockageRangeConf >  SPM_STATE_CONF_MIN   )
      )
    {
      /*Full range reached with trustworthy confidence, return True*/
      bReturnValue = TRUE;
    }
    
    return bReturnValue;
  }
  
  
  /********************************************************
  
    Functionname:           SPMSetBlockageParameters
    
    @brief                  map algo parameters on internal blockage parameters
  
  *//************************************************************************/
  static void SPMSetBlockageParameters(      SPMBlockageParameters_t         *ps_blockage_internal_parameters,
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT)
                                       const PartialBlockage_t               *ps_PartialBlockageInfo,
  #endif
                                       const Fct_blockage_algo_parameters_t  *ps_blockage_algo_parameters     )
  {
  #if SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_ON
    boolean bAllBSWParameterUsed;
  #endif
  
  #if( FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON )
    //define linear interpolation points to set blockage parameters dynamic
    float32 fHelpFactor;
    GDB_Math_Point_t TimeoutDownFactor,TimeoutUpFactor, RangeDownFactor, RangeUpFactor;
    /* dynamic range thresholds */
    RangeDownFactor.X = 0.8F;
    RangeDownFactor.Y = 1.0F;
    RangeUpFactor.X = 1.0F - CML_f_Delta;
    RangeUpFactor.Y = 1.2F;
    /*dynamic timeout theresholds*/
    TimeoutUpFactor.X = 0.8F;
    TimeoutUpFactor.Y = 1.0F;
    TimeoutDownFactor.X = 1.0F - CML_f_Delta;
    TimeoutDownFactor.Y = 1.0F/3.0F;
  #endif
  
    /* check for nullpointer */
    if(ps_blockage_algo_parameters != NULL)
    {
  #if SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS == SWITCH_OFF
      /* use hard coded defines */
      ps_blockage_internal_parameters->bEnableSelftest          = SPM_ENABLE_SELFTEST;
      ps_blockage_internal_parameters->bEnableBlockage          =          SPM_ENABLE_BLOCKAGE;
      ps_blockage_internal_parameters->fShutOffBSDRange         = (float32)SPM_BLOCKAGE_SHUTOFF_BSD_RANGE;
      ps_blockage_internal_parameters->fShutOffLCARange         = (float32)SPM_BLOCKAGE_SHUTOFF_LCA_RANGE;
      ps_blockage_internal_parameters->fBSDRangeHoldCounterTHLD = (float32)SPM_BSD_RANGE_HOLD_COUNTER_THLD;
      ps_blockage_internal_parameters->fLCARangeHoldCounterTHLD = (float32)SPM_LCA_RANGE_HOLD_COUNTER_THLD;
      ps_blockage_internal_parameters->fTimeoutShutOffTime      = (float32)SPM_BLOCKAGE_SHUTOFF_TIME;
      ps_blockage_internal_parameters->fTimeoutShutOffWay       = (float32)SPM_BLOCKAGE_SHUTOFF_WAY;
      ps_blockage_internal_parameters->uiNoOfAllowedObjLosses =        SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP;
  #else
  
      /* use parameters provided by BSW via RTE but check every signal for plausibility before setting */
  
      /************************/
      /* get selftest switch */
      /************************/
      if((ps_blockage_algo_parameters->b_SelfTestActive ==TRUE)||(ps_blockage_algo_parameters->b_SelfTestActive == FALSE))
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->bEnableSelftest = ps_blockage_algo_parameters->b_SelfTestActive;
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->bEnableSelftest = SPM_ENABLE_SELFTEST;
      }
  
      /******************/
      /* Shut off range */
      /******************/
      if(ps_blockage_algo_parameters->f32_ShutoffBSDRange >= C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fShutOffBSDRange = ps_blockage_algo_parameters->f32_ShutoffBSDRange;
        bAllBSWParameterUsed = TRUE;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> increase thresholds for range*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(RangeDownFactor, RangeUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fShutOffBSDRange = ps_blockage_algo_parameters->f32_ShutoffBSDRange * fHelpFactor;
         }
  #endif
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fShutOffBSDRange = (float32)SPM_BLOCKAGE_SHUTOFF_BSD_RANGE;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> increase thresholds for range*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(RangeDownFactor, RangeUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fShutOffBSDRange = (float32)SPM_BLOCKAGE_SHUTOFF_BSD_RANGE * fHelpFactor;
         }
  #endif
        bAllBSWParameterUsed = FALSE;
      }
  
      if(ps_blockage_algo_parameters->f32_ShutoffLCARange >= C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fShutOffLCARange = ps_blockage_algo_parameters->f32_ShutoffLCARange;
        bAllBSWParameterUsed = TRUE;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> increase thresholds for range*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(RangeDownFactor, RangeUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fShutOffLCARange = ps_blockage_algo_parameters->f32_ShutoffLCARange * fHelpFactor;
         }
  #endif
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fShutOffLCARange = (float32)SPM_BLOCKAGE_SHUTOFF_LCA_RANGE;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> increase thresholds for range*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(RangeDownFactor, RangeUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fShutOffLCARange = (float32)SPM_BLOCKAGE_SHUTOFF_LCA_RANGE * fHelpFactor;
         }
  #endif
        bAllBSWParameterUsed = FALSE;
      }
  
      /********************************/
      /*Delays Blockage Time Threshold*/
      /********************************/
      if(ps_blockage_algo_parameters->f32_BSDRangeHoldCounterTHLD >= C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fBSDRangeHoldCounterTHLD = ps_blockage_algo_parameters->f32_BSDRangeHoldCounterTHLD;
        bAllBSWParameterUsed = TRUE;
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fBSDRangeHoldCounterTHLD = SPM_BSD_RANGE_HOLD_COUNTER_THLD;
        bAllBSWParameterUsed = FALSE;
      }
  
      if(ps_blockage_algo_parameters->f32_LCARangeHoldCounterTHLD >= C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fLCARangeHoldCounterTHLD = ps_blockage_algo_parameters->f32_LCARangeHoldCounterTHLD;
        bAllBSWParameterUsed = TRUE;
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fLCARangeHoldCounterTHLD = SPM_LCA_RANGE_HOLD_COUNTER_THLD;
        bAllBSWParameterUsed = FALSE;
      }
  
      /**************************/
      /* Timeout time threshold */
      /**************************/
      if(ps_blockage_algo_parameters->f32_ShutoffTime_Timeout > C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fTimeoutShutOffTime = ps_blockage_algo_parameters->f32_ShutoffTime_Timeout;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> decrease thresholds for timeout*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(TimeoutDownFactor, TimeoutUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fTimeoutShutOffTime = ps_blockage_algo_parameters->f32_ShutoffTime_Timeout * fHelpFactor;
         }
  #endif
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fTimeoutShutOffTime = (float32)SPM_BLOCKAGE_SHUTOFF_TIME;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> decrease thresholds for timeout*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(TimeoutDownFactor, TimeoutUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fTimeoutShutOffTime = (float32)SPM_BLOCKAGE_SHUTOFF_TIME * fHelpFactor;
         }
  #endif
        bAllBSWParameterUsed = FALSE;
      }
      /*************************/
      /* Timeout way threshold */
      /*************************/
      if(ps_blockage_algo_parameters->f32_ShutoffWay_Timeout > C_F32_DELTA)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fTimeoutShutOffWay = ps_blockage_algo_parameters->f32_ShutoffWay_Timeout;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> decrease thresholds for timeout*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(TimeoutDownFactor, TimeoutUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fTimeoutShutOffWay = ps_blockage_algo_parameters->f32_ShutoffWay_Timeout * fHelpFactor;
         }
  #endif
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->fTimeoutShutOffWay = (float32)SPM_BLOCKAGE_SHUTOFF_WAY;
  #if(FCT_CFG_ALIGNMENT_MONITORING_INPUT == SWITCH_ON)
        /*if ALN reports high partial blockage probability and high confidence=> decrease thresholds for timeout*/
        if(ps_PartialBlockageInfo->f_Confidence > 0.5F)
         {
           fHelpFactor = GDB_Math_LinInterpol(TimeoutDownFactor, TimeoutUpFactor, ps_PartialBlockageInfo->f_Probability);
           ps_blockage_internal_parameters->fTimeoutShutOffWay = (float32)SPM_BLOCKAGE_SHUTOFF_WAY * fHelpFactor;
         }
  #endif
        bAllBSWParameterUsed = FALSE;
      }
  
      /************************/
      /* Blockage enable flag */
      /************************/
      /* use this flag only when it is true or if all other parameters were successfully set by BSW */
      if(   (ps_blockage_algo_parameters->b_BlockageActive == TRUE )
          ||(bAllBSWParameterUsed                          == TRUE ) )
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->bEnableBlockage = ps_blockage_algo_parameters->b_BlockageActive;
      }
      else
      {
        /* signal unplausible -> use define */
        ps_blockage_internal_parameters->bEnableBlockage = SPM_ENABLE_BLOCKAGE;
      }
      /***********************************************/
      /* Wiper Parameter */
      /***********************************************/
      if(ps_blockage_algo_parameters->ui8_WiperDelay <= 180U)
      {
        /* signal plausible -> use it */
        ps_blockage_internal_parameters->fWiperDelay = (float32)ps_blockage_algo_parameters->ui8_WiperDelay;
      }
      else
      {
        /* signal unplausible -> set to zero */
        ps_blockage_internal_parameters->fWiperDelay = 0.0F;
      }
  
      /* signal plausible -> use it */
      ps_blockage_internal_parameters->fBlockage1VerificationTime = (float32)ps_blockage_algo_parameters->ui8_Blockage1VerificationTime*SPM_FACTOR_CONVERT_MINUTES_IN_SEC;
  
      /* signal plausible -> use it */
      ps_blockage_internal_parameters->fBlockage1BSDAlertCounter = (float32)ps_blockage_algo_parameters->ui8_Blockage1BSDAlertCounter*SPM_FACTOR_CONVERT_MINUTES_IN_SEC;
   
      /***********************************************/
      /* Number of allowed ObjectLosses */
      /***********************************************/
      /* signal plausible -> use it */
      ps_blockage_internal_parameters->uiNoOfAllowedObjLosses = ps_blockage_algo_parameters->ui8_ShutoffNoOfObjLosses;
  
  #endif
    }
    else
    {
      /* RTE pointer not available -> use defines */
      ps_blockage_internal_parameters->bEnableSelftest          =          SPM_ENABLE_SELFTEST;
      ps_blockage_internal_parameters->bEnableBlockage          =          SPM_ENABLE_BLOCKAGE;
      ps_blockage_internal_parameters->fShutOffBSDRange         = (float32)SPM_BLOCKAGE_SHUTOFF_BSD_RANGE;
      ps_blockage_internal_parameters->fShutOffLCARange         = (float32)SPM_BLOCKAGE_SHUTOFF_LCA_RANGE;
      ps_blockage_internal_parameters->fBSDRangeHoldCounterTHLD =          SPM_BSD_RANGE_HOLD_COUNTER_THLD;
      ps_blockage_internal_parameters->fLCARangeHoldCounterTHLD =          SPM_LCA_RANGE_HOLD_COUNTER_THLD;
      ps_blockage_internal_parameters->fTimeoutShutOffTime      = (float32)SPM_BLOCKAGE_SHUTOFF_TIME;
      ps_blockage_internal_parameters->fTimeoutShutOffWay       = (float32)SPM_BLOCKAGE_SHUTOFF_WAY;
      ps_blockage_internal_parameters->uiNoOfAllowedObjLosses   =          SPM_NUMBER_OBJLOSSES_UNTIL_FULL_DAMP;
    }
  
  }
#endif

