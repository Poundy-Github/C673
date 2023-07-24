/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 SPM - Sensor Performance Monitoring

PACKAGENAME:               spm_cfg.h

DESCRIPTION:               SPM internal configuration header

AUTHOR:                    $Author: Oprea, Ionut02 (OpreaI01) $

CREATION DATE:             $Date: 2021/03/04 13:52:12CET $

VERSION:                   $Revision: 1.26.25.2 $

  ---*/ /*---
  CHANGES:                $Log: spm_cfg.h  $
  CHANGES:                Revision 1.26.25.2 2021/03/04 13:52:12CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Set SPM_USE_SELFTEST_STANDSTILL with SWITH_ON
  CHANGES:                Revision 1.26.25.1 2021/01/25 10:50:10CET Pallo, Istvan (palloi) 
  CHANGES:                Add new config switch for filter pedestrians
  CHANGES:                Revision 1.25.25.1 2020/11/10 13:07:31CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Update revision for ARS410BD10
  CHANGES:                Revision 1.23.25.1 2020/06/29 12:51:08CEST Pallo, Istvan (palloi) 
  CHANGES:                Update configuration for blockage custom output
  CHANGES:                Revision 1.23 2020/06/29 09:34:11CEST Pallo, Istvan (palloi) 
  CHANGES:                Replace all configurations for features with one config switch
  CHANGES:                Revision 1.22 2020/06/23 11:42:35CEST Pallo, Istvan (palloi) 
  CHANGES:                Add new configuration switches for SPM split SRR
  CHANGES:                Revision 1.21 2020/05/28 12:36:44CEST Pallo, Istvan (palloi) 
  CHANGES:                Add new config switches and remove veh sig port count
  CHANGES:                Revision 1.20 2020/03/04 07:52:19CET Pallo, Istvan (palloi) 
  CHANGES:                Split CBO config switch
  CHANGES:                Revision 1.19 2020/03/02 06:08:09CET Pallo, Istvan (palloi) 
  CHANGES:                Add new configuration switch and update port count
  CHANGES:                Revision 1.18 2020/02/11 11:01:52CET Pallo, Istvan (palloi) 
  CHANGES:                Add new configuration switch for Partial blockage check without relevant object
  CHANGES:                Revision 1.17 2020/02/04 08:24:15CET Oprea, Ionut02 (OpreaI01) 
  CHANGES:                Initial configuration file for ARS410BD10
  CHANGES:                Revision 1.16 2019/04/22 12:52:35CEST Pallo, Istvan (palloi) 
  CHANGES:                Update port count
  CHANGES:                Revision 1.15 2019/04/22 08:42:54CEST Pallo, Istvan (palloi) 
  CHANGES:                Merge ARS510 branch to trunk and add new port count
  CHANGES:                Revision 1.14 2019/03/07 11:06:22CET Pallo, Istvan (palloi) 
  CHANGES:                Add new config switch for missalignment check
  CHANGES:                Revision 1.13 2018/09/24 14:13:20CEST Pallo, Istvan (palloi) 
  CHANGES:                Add SRR config switches and removed duplicates
  CHANGES:                Revision 1.12 2018/08/03 13:42:38CEST Pallo, Istvan (palloi) 
  CHANGES:                Add config switches for blockage state histeresis and and blockage observers history
  CHANGES:                Revision 1.10.11.3 2018/08/03 10:59:13CEST Pallo, Istvan (palloi) 
  CHANGES:                Switch off usage of logical AND between timeout counters
  CHANGES:                Revision 1.10.11.2 2018/06/21 16:35:39CEST Olaru, Marian (OlaruM02) 
  CHANGES:                merge with revision 1.9.11.1
  CHANGES:                Revision 1.10.11.1 2018/06/21 15:40:07CEST Olaru, Marian (OlaruM02) 
  CHANGES:                add configuration for object loss observer and set it to ON
  CHANGES:                Revision 1.9.11.1 2018/04/13 08:49:27CEST Pallo, Istvan (palloi) 
  CHANGES:                Rework of request port counting for port changes
  CHANGES:                Revision 1.8.11.1 2018/04/04 07:01:13CEST Pallo, Istvan (palloi) 
  CHANGES:                New configuration switch for initialize SPM simulation data with recording data
  CHANGES:                Revision 1.6.11.5 2018/03/28 06:37:28CEST Pallo, Istvan (palloi) 
  CHANGES:                Switch ON usage of partial blockage probability and confidence
  CHANGES:                Revision 1.6.11.4 2018/03/15 13:51:14CET Pallo, Istvan (palloi) 
  CHANGES:                Add req port counting for partial blockage prob & conf
  CHANGES:                Revision 1.6.11.3 2018/03/12 13:53:48CET Hanumantharayappa, Ranjitha (uids3459) 
  CHANGES:                Custom Changes updated from VW18 to Initial setup of VW19
  CHANGES:                Revision 1.6.11.2 2018/02/26 15:23:37CET Pallo, Istvan (palloi) 
  CHANGES:                Remove port counting of egoDynSync and rollerBenchState.
  CHANGES:                Revision 1.6.11.1 2018/02/23 13:15:27CET Pallo, Istvan (palloi) 
  CHANGES:                Add defines for no of request and provide ports
  CHANGES:                Revision 1.6 2018/02/23 12:36:47CET Pallo, Istvan (palloi) 
  CHANGES:                Add defines for no of request and provide ports
  CHANGES:                Revision 1.5 2017/08/18 10:16:31CEST Pallo, Istvan (palloi) 
  CHANGES:                Use custom object list - switch off
  CHANGES:                Revision 1.4 2017/08/09 14:50:51CEST Olaru, Marian (OlaruM02) 
  CHANGES:                added configuartion switch for ALN information and set it to OFF
  CHANGES:                Revision 1.3 2017/08/01 11:36:04CEST Olaru, Marian (OlaruM02) 
  CHANGES:                Config switch for range probability/confidence fusion using convolution method
  CHANGES:                Revision 1.2 2017/07/27 12:11:31CEST Pallo, Istvan (palloi) 
  CHANGES:                New config switches for ported functionalities
  CHANGES:                Revision 1.1 2017/03/17 13:16:30CET Kober, Manfred (uidv8885) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/00_Projects/ARS510/SPM/project.pj

**************************************************************************** */
#ifndef SPM_CFG_H_INCLUDED
#define SPM_CFG_H_INCLUDED

/*****************************************************************************
  Config: SPM System performace monitoring
*****************************************************************************/

/* SPM number of request ports. This has to be aligned with structure reqFCTSenSPMPrtList */
                                                                   /* pSLATE_SPM_Data */
#define SPM_NO_OF_REQ_PORTS (   ( (uint8) (0) )                                                                                                                                \
                              + ( (uint8) (1) )                                                                                                      /* pt_BSWAlgoBlockage */  \
                              + ( (uint8) (1) )                                                                                                      /* pSenCtrlData */        \
                              + ( (uint8) (1) )                                                                                                      /* pEgoDynRaw */          \
                              + ( (uint8) (1) )                                                                                                      /* pPerfDegrData */       \
                              + ( (uint8) (1) )                                                                                                      /* pEgoDynObjSync */      \
                              + ( (uint8) ( (FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF) ) )                                            /* pFctVehLongOut*/       \
                              + ( (uint8) ( FCT_CFG_EM_FCT_CYCLEMODE ) )                                                                             /* pEmFctCycleMode */     \
                              + ( (uint8) ( (FCT_CFG_OBJECT_LIST_PROC) && (FCT_USE_EM_GENERIC_OBJECT_LIST) ) )                                       /* pEmGenObjList */       \
                              + ( (uint8) ( (FCT_CFG_OBJECT_LIST_PROC) && (FCT_USE_EM_GENERIC_OBJECT_LIST) && (FCT_USE_EM_ARS_TECH_OBJECT_LIST) ) )  /* pEmARSObjList */       \
                              + ( (uint8) ( (FCT_CFG_OBJECT_LIST_PROC) && (FCT_USE_EM_GENERIC_OBJECT_LIST) && (!FCT_USE_EM_ARS_TECH_OBJECT_LIST) ) ) /* pPubEmObj */           \
                              + ( (uint8) ( (FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF) ) )                                       /* pPerfDegrExtInput */   \
                              + ( (uint8) ( (FCT_CFG_OBJECT_LIST_PROC) && (FCT_CFG_ASSESSED_OBJ_OUT_INTF) ) )                                        /* pPubFctObj */          \
                              + ( (uint8) ( FCT_CFG_ADAPTIVE_CRUISE_CONTROL ) )                                                                      /* pSLATE_SPM_Data */     \
                              + ( (uint8) ( (FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF) ) )                                /* pt_ALNMonitoring */    \
                            )

#define SPM_NO_OF_PRO_PORTS (   ( (uint8) (0) )                                                                                              \
                              + ( (uint8) (FCT_CFG_ERROR_OUTPUT_SEN) )                                               /* pErrorOut */         \
                              + ( (uint8) ( (SYS_PERF_MON_OUT_INTFVER >= 3u) && (!FCT_CFG_SHORT_RANGE_FUNCTIONS) &&                          \
                                            ( (FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF)) ) ) /* pSysPerfMonStates */ \
                              + ( (uint8) (FCT_CFG_LOHP_COMPONENT) ) )                                               /* pSPM_HC_Data*/

/*ARS config switches - all OFF for SRR technology*/

/* SPM filter pedestrian objects*/
#define SPM_FILTER_PEDESTRIANS                         SWITCH_OFF

/*SPM custom features output*/
#define SPM_SET_CUSTOM_FEATURES_OUTPUT                 SWITCH_OFF

/* Use weather signals for blockage sensibilization */
#define SPM_USE_WEATHER_SIGNALS_FOR_BLOCKAGE           SWITCH_OFF

/* Check partial blockage state if relevant object is not present*/
#define SPM_CHECK_PB_WO_OOI0                           SWITCH_OFF

/* Check of missalignment */
#define SPM_CHECK_MISSALIGNMENT                        SWITCH_OFF

/* Keep history of which observer was active when blockage was triggered */
#define SPM_OBSERVERS_HISOTRY                          SWITCH_OFF

/* Delay the reactivation of system if switch is active*/
#define SPM_DELAY_REACTIVATION                         SWITCH_OFF

/* Initialize SPM sim data with data from recording */
#define SPM_INIT_WITH_REC_DATA                         SWITCH_OFF

/*! use cusom object selection for SPM */
#define SPM_USE_CUSTOM_OBJECT_SELECTION                SWITCH_OFF

/*! use the convolution area for fusion of range probaility*/
#define SPM_USE_AREA_CONVOLUTION_FOR_RANGE_FUSION      SWITCH_OFF

/*! check for lane association of relevant object if was lost*/
#define SPM_USE_LANE_ASSOCIATION                   		 SWITCH_OFF

/*! use RCS criteria when determine damping probability*/
#define SPM_USE_RCS_CRITERION                      		 SWITCH_ON

/*! prevent counting of objects if speed is below 8kph*/
#define SPM_PREVENT_LOW_SPEED_LOSSES               		 SWITCH_OFF

/*! increase range observer confidence if there are losses of relevant object*/
#define SPM_INCREASE_RANGE_CONF                    		 SWITCH_OFF

/*! use custom object loss parameter filter */
#define SPM_OBJLOSS_USE_CUSTOM_FILTER_PARAMETER    		 SWITCH_OFF

/*! enable object loss check when relevance changes*/
#define SPM_CHECK_OBJ_LOSS_REL_CHANGE         			 SWITCH_OFF

/*enable blockage trigger at fast objects lost*/
#define SPM_ENABLE_FAST_BLOCKAGE_TRIGGER      			 SWITCH_OFF

/* Camera observer usage in blockage decision*/
#define SPM_USE_CAMERA_OBSERVER_BLK                  SWITCH_OFF

/* Camera observer usage for blockage sensibilization */
#define SPM_USE_CAMERA_OBSERVER_PARAMS               SWITCH_OFF

/*use ALN information(probability and confidence) */
#define SPM_USE_ALN_PARTIAL_BLOCKAGE_PROB_AND_CONF       SWITCH_OFF

/* Use partial blockage in blockage state set */
#define SPM_USE_PARTIALBLOCKAGE_IN_BLK_STATE             SWITCH_ON

/* Use selftest in standstill */
#define SPM_USE_SELFTEST_STANDSTILL           			 SWITCH_ON

/* Use different selftest time tresholds*/
#define SPM_USE_DIFF_SELFTEST_TIME_THRES       			 SWITCH_OFF

/*set blockage DEM event as unknown during the selftest execution*/
#define SPM_BLOCKAGE_STATE_UNKNOWN_IN_STARTUP            SWITCH_OFF

/*! Configuration switch, OOI_2 and 3 will only be taken into account if OOI_0 with same ID existed one cycle before
in the next cycle OOI_2 or 3 needs to have the same ID as the cycle before to prevent full blockage or OOI_0 is present
 */
#define SPM_NO_FULL_DAMP_TARGET_TO_NEIGHBOUR_OBJ         SWITCH_OFF

/*configuration switch for usage of range gradient*/
#define SPM_USE_RANGE_GRADIENT                		     SWITCH_OFF

/*configuration switch for usage of wipers in range gradient*/
#define SPM_USE_WIPERS_RANGE_GRADIENT		  			 SWITCH_OFF

/*config switch for using custom threshold of selftest for ARS4Gx projects*/
#define SPM_USE_ONEMIN_SELFTEST_TIME_THLD     			 SWITCH_OFF

/*configuration switch for usage of last classification*/
#define SPM_USE_LAST_CLASSIFICATION			  			 SWITCH_OFF

/* This switch activate increase damping when it there is at least a loss of relevance*/
#define SPM_INC_DAMP_WITH_REL_OBJ_LOST        			 SWITCH_OFF

/*! Integration of a continuous roadbeam when computing blockage probability 
Should not be used with SPM_BLOCKAGE_ROADBEAM_TEST_ACTIVE*/
#define SPM_SELFTEST_USE_CONTINUOUS_ROADBEAM  			 SWITCH_OFF

/*! This switch activates the roadbeam blockage test for reactivation after an
detected blockage */
#define SPM_BLOCKAGE_USE_CONTINUOUS_ROADBEAM  			 SWITCH_OFF

/*! Switch for enabling unsing ALN Partial Blockage */
#define SPM_CFG_USE_ALN_PARTIAL_BLOCKAGE      			 SWITCH_ON

/*Switch for enabling using Temperature and wiper Signal for prevention of Blockage activation*/
#define SPM_CFG_USE_TEMPERATURE_AND_WIPER     			 SWITCH_OFF

/*An extra possibility to switch off blockage and selftest regardless of algoparameters*/
#define SPM_SWITCH_BLOCKAGE_AND_SELFTEST_OFF  			 SWITCH_OFF

/*! Switch activates the elevation range in the degradation concept */
#define SPM_USE_ELEVATION_DEGR_DIST           			 SWITCH_ON

/*! Fill interface for EBA Safety Distance with calculated max allowed distance */
#define SPM_CFG_SAFETY_DIST_2_RTE             			 SWITCH_OFF

/*!  spm use object loss observer*/
#define SPM_USE_OBJECTLOSS_OBSERVER                      SWITCH_ON


/*SRR config switches - all OFF for ARS technology*/

/*Config switch for activate SRR*/
#define SPM_SRR_TECHNOLOGY                           SWITCH_OFF

/*! make Roadbeam available also in RDC_DAMP mode, if switched off Roadbeam is
only available in FULL_DAMP mode */
#define SPM_USE_ROADBEAM_IN_RDC_MODE                 SWITCH_OFF

/*! This switch activates the roadbeam blockage test for reactivation after an
detected blockage */
#define SPM_BLOCKAGE_ROADBEAM_TEST_ACTIVE            SWITCH_OFF

/*! This switch activates the roadbeam blockage test for selftest */
#define SPM_SELFTEST_ROADBEAM_TEST_ACTIVE            SWITCH_OFF

/*! This switch activates the azimuth misalignment monitoring */
#define SPM_AZIMUTH_MISALIGNMENT_MONITORING          SWITCH_OFF

/*! Switch to enable interference evaluation */
#define SPM_CFG_INTERFERENCE                         SWITCH_OFF

#define SPM_CFG_EGO_CHECK_QUALITY                    SWITCH_OFF

/*swith to enable object loss observer for blockage state determination*/
#define SPM_CFG_USE_OBJECTLOSS                       SWITCH_OFF

/*switch to adapt the Blockage State depending on Wiper Signal*/
#define SPM_CFG_USE_WIPER_ADAPT                      SWITCH_OFF

/*use ALN input*/
#define SPM_CFG_ALIGNMENT_MONITORING_INPUT           SWITCH_OFF

/*use serveice pointer*/
#define SPM_USE_SERVICE_POINTER_FUNCTS               SWITCH_OFF

/*use control data*/
#define SPM_CFG_USE_CTRLDATA                         SWITCH_OFF


/*Common config switches*/

/*! activate Blockage detection for Stop and Go situations with Vego < 10km/h */
#define SPM_USE_STOPNGO_BLOCKAGE                     SWITCH_ON

/*! activate selftest for Stop and Go situations with Vego < 10km/h */
#define SPM_USE_STOPNGO_SELFTEST                     SWITCH_ON

/*! Configuration switch, when set full damp mode can only be entered when there is no relevant object */
#define SPM_FULL_DAMP_WITH_NO_REL_OBJ                SWITCH_OFF

/*! Switch for enabling short range sensor input processing (in ARS300: VDATA_CFG_INCLUDE_SHORT_RANGE_INFO) */
#define SPM_CFG_SHORT_RANGE_SENSOR_INFO              SWITCH_OFF

/*! Switch which indicates if blockage thresholds are taken from BSW or if hard coded defines shall be used */
#define SPM_USE_EXTERNAL_BLOCKAGE_PARAMETERS         SWITCH_ON

/*! Switch if logical "or" connection for timeout counters shall be used (switch_off = standard case), if switch == on -> logical "and" is used */
#define SPM_USE_LOGICAL_AND_FOR_TIMEOUT              SWITCH_OFF

#endif
