// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT:      ComponentName
// VERSION:        $Revision: 1.12 $
/// @file
/// @brief         contains enumeration describing all GlobalIDs sent to the RTA_MOs, file is generated, no manual changes

// File Name:      $Source: RTA_GlobalIDs.h $
// Author:         Matthias Kammerl
// Last Author:    $Author: Kammerl, Matthias (uidr3468) $
// Last Change:    $Date: 2019/05/20 12:27:58CEST $

/***********************************************************************************************************************

  File History:

  Changes:                $Log: RTA_GlobalIDs.h  $
  Changes:                Revision 1.12 2019/05/20 12:27:58CEST Kammerl, Matthias (uidr3468) 
  Changes:                Add the following globalIDs:
  Changes:                
  Changes:                -   RTA_GLOBALID_DPUCOM        =  53, 
  Changes:                -   RTA_GLOBALID_DEM               = 140,
  Changes:                Revision 1.11 2019/05/16 08:42:03CEST Kammerl, Matthias (uidr3468) 
  Changes:                Add the following globalIDs: 
  Changes:                -  RTA_GLOBALID_LOPC                = 131,  // LongitudinalPlannerAndController
  Changes:                -  RTA_GLOBALID_LOHP                = 135,  // LongitudinalHeadwayPlanner
  Changes:                -  RTA_GLOBALID_MEDIC               = 155,  // InterventionControl
  Changes:                -  RTA_GLOBALID_SPM                 = 231,  // SensorPerformanceMonitoring
  Changes:                Revision 1.10 2019/05/07 14:55:03CEST Kammerl, Matthias (uidr3468) 
  Changes:                Design improvement
  Changes:                Revision 1.9 2019/04/17 16:09:19CEST Kammerl, Matthias (uidr3468) 
  Changes:                Add RTA_GLOBALID_ICU
  Changes:                Revision 1.8 2019/04/03 12:13:56CEST Kammerl, Matthias (uidr3468) 
  Changes:                Remove RTA_GLOBALID_FH
  Changes:                Rename RTA_GLOBALID_CDR in RTA_GLOBALID_EDR
  Changes:                
  Changes:                Background: Both FH and CDR shall use RTA_GLOBALID_EDR
  Changes:                Revision 1.7 2019/03/25 11:26:22CET Kammerl, Matthias (uidr3468) 
  Changes:                - Change the values of DPC and RDPC in order to free the range which is intended for RTE-GlobalIDs
  Changes:                - Correct the name of RTA_GLOBALID_GEN_ADAPT_ALGO_EXEC
  Changes:                Revision 1.6 2019/03/21 08:14:00CET Kammerl, Matthias (uidr3468) 
  Changes:                add RTA_GLOBALID_ISP
  Changes:                Revision 1.5 2019/03/20 10:04:15CET Kammerl, Matthias (uidr3468) 
  Changes:                Add GlobalIDs for algos called by generic adapter
  Changes:                Revision 1.4 2019/03/18 16:39:14CET Kammerl, Matthias (uidr3468) 
  Changes:                Add RtaGlobalIDs according component's feedback
  Changes:                Revision 1.3 2019/01/16 14:02:36CET Kammerl, Matthias (uidr3468) 
  Changes:                Add RTA_GLOBALID_SLATE
  Changes:                Revision 1.2 2018/12/14 07:57:59CET Kammerl, Matthias (uidr3468) 
  Changes:                Prepare the switch to the rtaGlobalIDEnumeration

***********************************************************************************************************************/
#ifndef RTA_GLOBALDS_H_INCLUDED
#define RTA_GLOBALDS_H_INCLUDED

/// enumeration describing all GlobalIDs sent to the RTA_MOs \n
/// These enumLiterals shall be used by the components as globalIDs for adding their rtaEvents.
/// They are used as second argument in the function \n
/// void RTA_v_AddEvent(const RTA_t_Events EVENT, const uint8 u_GLOBALID, const uint8 u_LOCALID, const uint8 u_OPTDATA)

/// Up to now the compIDs defined in glob_comp_id.h are used as globalIDs.
/// But as these compIDs are not only used for RTA we have quite a mess concerning the IDs. \n
/// A further important reason is that we are running out of the 8-bit range. Currently we have
/// ~250 compIDs and we want avoid to extend to 16-bit values.
/// Therefore we decided to introduce an enumeration defining all globalIDs. \n
/// Important: \n
/// - Only the literals of this enumeration shall be used as globalIDs for rtaEvents \n
/// - The literals of this enumeration must not be used for any other purpose!
///   Only exception: They shall be used by the genericAdapter as localIDs to measure the runtime of the related
///   algorithm (adaptorRuntime and algoExecution). \n
/// - In case you need a new RTA_GLOBALID for your component just contact Matthias Kammerl. \n
///   (Matthias.Kammerl@continental-corporation.com)
/// As we just started the enumeration is not complete yet.


//Generated file - no manual changes please!****************************************************************************


//___GENERATOR_TAG___RTA_GLOBAL_ID_ENUM___START___

//  Number of free globalIDs in the 8-bit range: 144
  
typedef enum
{
  RTA_GLOBALID_INTERRUPTS          =   0,  // All the interrupts - only for RTA internal usage!!
  RTA_GLOBALID_VDY                 =   2,  // VDY_VehicleDynamics
  RTA_GLOBALID_FCT_VEH             =   3,  // FCT_Function
  RTA_GLOBALID_ADP                 =   4,  // ADP_AlgoSWAdapter
  RTA_GLOBALID_HLA                 =   7,  // HLA_HeadLightAssist
  RTA_GLOBALID_IC                  =  12,  // DPUIC_ImagerControl
  RTA_GLOBALID_DPC                 =  14,  // DPC_DataProcessingControl
  RTA_GLOBALID_RDPC                =  15,  // RDPC_RawDataProcessingControl
  RTA_GLOBALID_FCT_SEN             =  18,  // FCT_Function
  RTA_GLOBALID_DPUCOM              =  53, 
  RTA_GLOBALID_EC                  =  62,  // EC_RadarEnvironmentClassification
  RTA_GLOBALID_EM                  =  67,  // EM_CameraEnvironmentModel
  RTA_GLOBALID_CIPP                =  70,  // CIPP_CommonImagePreProcessing
  RTA_GLOBALID_CB                  =  71,  // CB_CameraBlockage
  RTA_GLOBALID_ECM                 =  72,  // ECM_EOLCalibrationMono
  RTA_GLOBALID_CHIPS               =  73,  // CHIPS_CommonHWAcceleratedImgProcSys
  RTA_GLOBALID_GS                  =  74,  // GS_GlobalScheduler
  RTA_GLOBALID_LD                  =  75,  // LD_LaneDetection
  RTA_GLOBALID_EVE_ABORT           =  76, 
  RTA_GLOBALID_SR                  =  80,  // SR_SignRecognition - Note: This ID shall be also used for SR_A
  RTA_GLOBALID_TSA                 =  81,  // TSA_TrafficSignAssist
  RTA_GLOBALID_SR_B                =  83,  // SR_SignRecognition - For SR_B (the low prio part of signRecognition) only!!!
  RTA_GLOBALID_PFC                 =  86,  // PFC_PowerFlowComputation
  RTA_GLOBALID_FAMO                =  87,  // FAMO_FunctionalSafetyAlgoMonitor
  RTA_GLOBALID_ACAL                =  88,  // ACDC_CollisionDetectionAndClassification
  RTA_GLOBALID_LCF_VEH             =  90,  // SubComponent of  LCF_LateralControlFunctions
  RTA_GLOBALID_LCF_SEN             =  91,  // SubComponent of LCF_LateralControlFunctions
  RTA_GLOBALID_LSD                 =  92,  // LSD_LightSourceDetection
  RTA_GLOBALID_RUM                 =  93,  // RUM_RoadUserMeasurements - Note: This ID is for both RUM and RUM2 !!
  RTA_GLOBALID_UDW                 =  94,  // UDW_UnsteadyDrivingWarning
  RTA_GLOBALID_PCA                 =  95,  // PCA_PointCloudAlgorithm
  RTA_GLOBALID_GSM                 =  97,  // GSM_GroundSurfaceModel
  RTA_GLOBALID_PDM                 =  98,  // PDM_PerformanceDegradationModule
  RTA_GLOBALID_POC                 =  99,  // POC_POintcloudCorrespondences
  RTA_GLOBALID_ICU                 = 100, 
  RTA_GLOBALID_FCU                 = 101,  // FCU_FunctionControlUnit
  RTA_GLOBALID_EMO                 = 104,  // EMO_EgoMotion - Note: This ID is for both EMO and MEMO !!
  RTA_GLOBALID_GEN                 = 105,  // GEN_GeneralObjectDetection
  RTA_GLOBALID_GRAPPA              = 106,  // GRAPPA_GenericRedvinePictureAnalysis
  RTA_GLOBALID_PC                  = 108,  // PC_PatchCorrelator
  RTA_GLOBALID_LIQOR               = 110,  // LIQOR_LidarQuickObjectRecognition
  RTA_GLOBALID_VODCA               = 111,  // VODCA_VisObjDetClaAlgo
  RTA_GLOBALID_DAP                 = 120,  // DAP_RadarDataProcessing
  RTA_GLOBALID_GP                  = 121,  // GP_RadarGridProcessing
  RTA_GLOBALID_OD                  = 122,  // OD_RadarObjectDescription
  RTA_GLOBALID_ITC                 = 123,  // ITC_InterTaskCommunication
  RTA_GLOBALID_LOPC                = 131,  // LongitudinalPlannerAndController
  RTA_GLOBALID_IPC_IUC             = 132,  // IPC_InterProcessorCommunication - IPC IUC
  RTA_GLOBALID_MTSI                = 133,  // MTSI_MTSInterface
  RTA_GLOBALID_LOHP                = 135,  // LongitudinalHeadwayPlanner
  RTA_GLOBALID_RTL                 = 138,  // RTL_RealTimeLogging
  RTA_GLOBALID_DEM                 = 140,  // DiagnosticEventManager
  RTA_GLOBALID_RTA                 = 147,  // RTA_RealTimeAnalysis1
  RTA_GLOBALID_ET                  = 152,  // EventTranceiver  - subComponent of DPUFF_FunctionsFramework
  RTA_GLOBALID_PMA                 = 153,  // PMA_PostMortemAnalysis
  RTA_GLOBALID_MEDIC               = 155,  // InterventionControl
  RTA_GLOBALID_GEN_ADAPT_ADAPTER   = 160,  // Generic adaptor - adaptor runtime
  RTA_GLOBALID_EVT_MARKER          = 162,  // Software event marker
  RTA_GLOBALID_GEN_ADAPT_ALGO_EXEC = 165,  // Generic adaptor - algo runtime
  RTA_GLOBALID_HWI                 = 167,  // MFC4xx  DPUs -> HardwareInterrupts
  RTA_GLOBALID_SWI                 = 168,  // MFC4xx  DPUs -> SoftwareInterrupts
  RTA_GLOBALID_EVE                 = 173, 
  RTA_GLOBALID_EVE_TRIGGER         = 174, 
  RTA_GLOBALID_EVE_LOCKOUT         = 175, 
  RTA_GLOBALID_DPUSERVICE          = 176,  // DPUSERVICE_Services
  RTA_GLOBALID_DPUST               = 177,  // DpuSelftest
  RTA_GLOBALID_MDB                 = 183,  // MultiCore database - subComponent of DPUFF_FunctionsFramework
  RTA_GLOBALID_DPUINFRA            = 186,  // DPUINFRA_Infrastructure
  RTA_GLOBALID_EDR                 = 189,  // EDR_EventDataRecorder
  RTA_GLOBALID_IPC_DPU_RX          = 192,  // IPC_InterProcessorCommunication - DPU RX
  RTA_GLOBALID_PCC                 = 195,  // PCC_RadarPedestrianCyclistClassification
  RTA_GLOBALID_PD                  = 196,  // PD_RadarPerformanceDegradation
  RTA_GLOBALID_RTE                 = 200,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_1               = 201,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_2               = 202,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_3               = 203,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_4               = 204,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_5               = 205,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_6               = 206,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_7               = 207,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_8               = 208,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_9               = 209,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_10              = 210,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_11              = 211,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_12              = 212,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_13              = 213,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_14              = 214,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_15              = 215,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_16              = 216,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_17              = 217,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_18              = 218,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_19              = 219,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_20              = 220,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_21              = 221,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_22              = 222,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_23              = 223,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RD                  = 224,  // RD_RadarRoadDescription
  RTA_GLOBALID_RTE_25              = 225,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_26              = 226,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_27              = 227,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_28              = 228,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_RTE_29              = 229,  // Reserved for RTE - For RtaVisu the name will be changed by RtaXmlGenerator according project specific RTE setup
  RTA_GLOBALID_SLATE               = 230,  // SLATE_SituationLaneAssociationTrajectoryEstimation - please use this ID also for Slate1 and Slate2
  RTA_GLOBALID_SPM                 = 231,  // SensorPerformanceMonitoring
  RTA_GLOBALID_VC                  = 240,  // VC_RadarVehicleClassification
  RTA_GLOBALID_FPS                 = 241,  // FPS_RadarFunctionPreSelection
  RTA_GLOBALID_ISP                 = 245,  // ISP_ImageSignalProcessor
  RTA_GLOBALID_GFRS                = 246,  // GFRS_GridBasedFreespace
  RTA_GLOBALID_DAP_VEH             = 247,  // RadarDataProcessingVehicle
  RTA_GLOBALID_GEOS                = 248,  // GEOS_GeometricSegmentation
  RTA_GLOBALID_RDBC                = 249,  // RDBC_RoadDataBaseClient
  RTA_GLOBALID_IPC_DPU_TX          = 250   // IPC_InterProcessorCommunication - DPU TX
}RTA_t_GlobalIDs;
//___GENERATOR_TAG___RTA_GLOBAL_ID_ENUM___END___

//Generated file - no manual changes please!****************************************************************************

#endif //RTA_GLOBALDS_H_INCLUDED
