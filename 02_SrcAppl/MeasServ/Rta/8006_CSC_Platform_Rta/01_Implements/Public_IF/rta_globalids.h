// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - RealTimeAnalysis
/// \file
/// \brief This header contains the enumeration describing all GlobalIDs sent to the RTA_MOs. The file is generated, no manual changes

#ifndef RTA_GLOBALDS_H_INCLUDED
#define RTA_GLOBALDS_H_INCLUDED

#include "rta_types.h"

/// enumeration describing all GlobalIDs sent to the RTA_MOs \n
/// These enumLiterals shall be used by the components as globalIDs for adding their rtaEvents.
/// They are used as second argument in the function \n
/// void RTA_v_AddEvent(const RTA_t_Events EVENT, const uint8 u_GLOBALID, const uint8 u_LOCALID, const uint8 u_OPTDATA)

/// Important: \n
/// - Only the literals of this enumeration shall be used as globalIDs for rtaEvents \n
/// - The literals of this enumeration must not be used for any other purpose!
///   Only exception: They shall be used by the genericAdapter as localIDs to measure the runtime of the related
///   algorithm (adaptorRuntime and algoExecution). \n
/// - In case you need a new RTA_GLOBALID for your component just contact Matthias Kammerl. \n
///   (Matthias.Kammerl@continental-corporation.com) or somebody else of the adas_embed_mon team: \n
///   https://github-am.geo.conti.de/orgs/ADAS/teams/embedded-monitors/members


//Generated file - no manual changes please!****************************************************************************


//___GENERATOR_TAG___RTA_GLOBAL_IDS___START___

//  Number of free globalIDs: 3780
//  Note: For the globalIDs we have a 12 bit range -> 4096 IDs.
//        The range 4000 ... 4095 is reserved for the RTE GlobalIDs.

#ifndef __cplusplus

#define RTA_GLOBALID_INVALID             ((RTA_t_GlobalID)   0)  ///< This GlobalID MUST NOT be used. It is used by the RTA to show that a GlobalID was provided by any user which was out of range.
#define RTA_GLOBALID_INTERRUPTS          ((RTA_t_GlobalID)   1)  ///< All the interrupts - only for RTA internal usage!!
#define RTA_GLOBALID_VDY                 ((RTA_t_GlobalID)   2)  ///< VDY_VehicleDynamics
#define RTA_GLOBALID_FCT_VEH             ((RTA_t_GlobalID)   3)  ///< FCT_Function
#define RTA_GLOBALID_ADP                 ((RTA_t_GlobalID)   4)  ///< ADP_AlgoSWAdapter
#define RTA_GLOBALID_CEM_ARS540          ((RTA_t_GlobalID)   5)
#define RTA_GLOBALID_CEM_APTIV_MFC       ((RTA_t_GlobalID)   6)
#define RTA_GLOBALID_HLA                    7  ///< HLA_HeadLightAssist
#define RTA_GLOBALID_CEM_APTIV_SRR       ((RTA_t_GlobalID)   8)
#define RTA_GLOBALID_CEM_COH             ((RTA_t_GlobalID)   9)
#define RTA_GLOBALID_CEM_EML             ((RTA_t_GlobalID)  10)
#define RTA_GLOBALID_CEM_FSF             ((RTA_t_GlobalID)  11)
#define RTA_GLOBALID_IC                  ((RTA_t_GlobalID)  12)  ///< DPUIC_ImagerControl
#define RTA_GLOBALID_CEM_FDP_BASE        ((RTA_t_GlobalID)  13)
#define RTA_GLOBALID_DPC                 ((RTA_t_GlobalID)  14)  ///< DPC_DataProcessingControl
#define RTA_GLOBALID_RDPC                ((RTA_t_GlobalID)  15)  ///< RDPC_RawDataProcessingControl
#define RTA_GLOBALID_CEM_HANDLER         ((RTA_t_GlobalID)  16)
#define RTA_GLOBALID_CEM_RMF             ((RTA_t_GlobalID)  17)
#define RTA_GLOBALID_FCT_SEN             ((RTA_t_GlobalID)  18)  ///< FCT_Function
#define RTA_GLOBALID_CEM_SEF             ((RTA_t_GlobalID)  19)
#define RTA_GLOBALID_ALN                 ((RTA_t_GlobalID)  20)  ///< ALN Alignment
#define RTA_GLOBALID_CC                  ((RTA_t_GlobalID)  21)  ///< CC Classification Consolidation
#define RTA_GLOBALID_MOS                 ((RTA_t_GlobalID)  22)  ///< MOS Model Output Selection
#define RTA_GLOBALID_OOC                 ((RTA_t_GlobalID)  23)  ///< OOC Object and Obstruction Classification
#define RTA_GLOBALID_RADI                ((RTA_t_GlobalID)  24)  ///< RADI Radar Detection Image
#define RTA_GLOBALID_RDT                 ((RTA_t_GlobalID)  25)  ///< RDT Radar Detection Tracker
#define RTA_GLOBALID_HAX                 ((RTA_t_GlobalID)  26)  ///< HAX Radar Tracking Hardware Accelerator
#define RTA_GLOBALID_RFCOM               ((RTA_t_GlobalID)  27)  ///< RFCOM RadioFrequencyCommunication
#define RTA_GLOBALID_RHC                 ((RTA_t_GlobalID)  28)  ///< RHC RadarHardwareControl
#define RTA_GLOBALID_RIC                 ((RTA_t_GlobalID)  29)  ///< RIC Road Infrastructure Classification
#define RTA_GLOBALID_RMHT                ((RTA_t_GlobalID)  30)  ///< RMHT Radar Multi Hypothesis Tracker
#define RTA_GLOBALID_RMP1                ((RTA_t_GlobalID)  31)  ///< RMP1 Radar Motion Properties 1
#define RTA_GLOBALID_RMP2                ((RTA_t_GlobalID)  32)  ///< RMP2 Radar Motion Properties 2
#define RTA_GLOBALID_RPM1                ((RTA_t_GlobalID)  33)  ///< RPM1 Radar Performance Monitoring 1
#define RTA_GLOBALID_RPM2                ((RTA_t_GlobalID)  34)  ///< RPM2 Radar Performance Monitoring 2
#define RTA_GLOBALID_RPP                 ((RTA_t_GlobalID)  35)  ///< RPP Radar Parameter Processing
#define RTA_GLOBALID_RSP                 ((RTA_t_GlobalID)  36)  ///< RSP RadarSignalProcessing
#define RTA_GLOBALID_SEP1                ((RTA_t_GlobalID)  37)  ///< SEP Static Environment Properties
#define RTA_GLOBALID_SEP2                ((RTA_t_GlobalID)  38)  ///< SEP Static Environment Properties
#define RTA_GLOBALID_SPT                 ((RTA_t_GlobalID)  39)  ///< SPT SignalProcessingToolbox
#define RTA_GLOBALID_SRP1                ((RTA_t_GlobalID)  40)  ///< SRP1 Spatial and Relation Properties 1
#define RTA_GLOBALID_SRP2                ((RTA_t_GlobalID)  41)  ///< SRP2 Spatial and Relation Properties 2
#define RTA_GLOBALID_CEM_TPF             ((RTA_t_GlobalID)  42)
#define RTA_GLOBALID_CEM_VAL             ((RTA_t_GlobalID)  43)
#define RTA_GLOBALID_HOMON               ((RTA_t_GlobalID)  44)
#define RTA_GLOBALID_LOCTR               ((RTA_t_GlobalID)  45)  ///< LOCTR_LongitudinalTrajectoryController
#define RTA_GLOBALID_LOPLN               ((RTA_t_GlobalID)  46)  ///< LOPLN_LongitudinalTrajectoryPlanner
#define RTA_GLOBALID_RD                  ((RTA_t_GlobalID)  47)  ///< RD_RadarRoadDescription
#define RTA_GLOBALID_NONE_OSEK_CORE_1    ((RTA_t_GlobalID)  48)  ///< None_Osek_Core_1 - Radar legacy implementation (ARS410)
#define RTA_GLOBALID_NONE_OSEK_CORE_2    ((RTA_t_GlobalID)  49)  ///< None_Osek_Core_2 - Radar legacy implementation (ARS410)
#define RTA_GLOBALID_GA_WRAPPER          ((RTA_t_GlobalID)  50)  ///< Global architecture wrapper
#define RTA_GLOBALID_ASILBCODING         ((RTA_t_GlobalID)  51)  ///< Asil B coding
#define RTA_GLOBALID_SYNC                ((RTA_t_GlobalID)  52)  ///< synch component which copies the data from vdy cycle to image cycle
#define RTA_GLOBALID_DPUCOM              ((RTA_t_GlobalID)  53)
#define RTA_GLOBALID_PMSD                ((RTA_t_GlobalID)  54)  ///< Parking marker detection for surround view projects
#define RTA_GLOBALID_ECUOMC              ((RTA_t_GlobalID)  55)  ///< Used for ECU Operation Mode Control
#define RTA_GLOBALID_DPUHWIF             ((RTA_t_GlobalID)  56)  ///< DPUHWIF_HardwareInterface
#define RTA_GLOBALID_DPUIA               ((RTA_t_GlobalID)  57)  ///< DPUIA ImageAcquisition
#define RTA_GLOBALID_ACDC                ((RTA_t_GlobalID)  58)  ///< ACDC_CollisionDetectionAndClassification (Also for ACDC2)
#define RTA_GLOBALID_CEM_VDY             ((RTA_t_GlobalID)  59)  ///< SIP_CEM_VehicleDynamics
#define RTA_GLOBALID_CEM_USS             ((RTA_t_GlobalID)  60)  ///< SIP_CEM_UltraSonic
#define RTA_GLOBALID_CEM_FDP2            ((RTA_t_GlobalID)  61)  ///< FDP_CEM_Output2
#define RTA_GLOBALID_EC                  ((RTA_t_GlobalID)  62)  ///< EC_RadarEnvironmentClassification
#define RTA_GLOBALID_ISP_SV_FC           ((RTA_t_GlobalID)  63)  ///< ISP_ImageSignalProcessor - surround view - front camera
#define RTA_GLOBALID_ISP_SV_LSC          ((RTA_t_GlobalID)  64)  ///< ISP_ImageSignalProcessor - surround view - left side camera
#define RTA_GLOBALID_ISP_SV_RC           ((RTA_t_GlobalID)  65)  ///< ISP_ImageSignalProcessor - surround view - rear camera
#define RTA_GLOBALID_ISP_SV_RSC          ((RTA_t_GlobalID)  66)  ///< ISP_ImageSignalProcessor - surround view - right side camera
#define RTA_GLOBALID_EM                  ((RTA_t_GlobalID)  67)  ///< EM_CameraEnvironmentModel
#define RTA_GLOBALID_CEM_GEN1            ((RTA_t_GlobalID)  68)  ///< CEM_GenericID1
#define RTA_GLOBALID_CEM_GEN2            ((RTA_t_GlobalID)  69)  ///< CEM_GenericID2
#define RTA_GLOBALID_CIPP                ((RTA_t_GlobalID)  70)  ///< CIPP_CommonImagePreProcessing
#define RTA_GLOBALID_CB                  ((RTA_t_GlobalID)  71)  ///< CB_CameraBlockage
#define RTA_GLOBALID_ECM                 ((RTA_t_GlobalID)  72)  ///< ECM_EOLCalibrationMono
#define RTA_GLOBALID_CHIPS               ((RTA_t_GlobalID)  73)  ///< CHIPS_CommonHWAcceleratedImgProcSys
#define RTA_GLOBALID_GS                  ((RTA_t_GlobalID)  74)  ///< GS_GlobalScheduler
#define RTA_GLOBALID_LD                  ((RTA_t_GlobalID)  75)  ///< LD_LaneDetection
#define RTA_GLOBALID_EVE_ABORT           ((RTA_t_GlobalID)  76)
#define RTA_GLOBALID_CHIPS_SV_CYL_FC     ((RTA_t_GlobalID)  77)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - front camera
#define RTA_GLOBALID_CHIPS_SV_CYL_LSC    ((RTA_t_GlobalID)  78)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - left side camera
#define RTA_GLOBALID_CHIPS_SV_CYL_RC     ((RTA_t_GlobalID)  79)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - rear camera
#define RTA_GLOBALID_SR                  ((RTA_t_GlobalID)  80)  ///< SR_SignRecognition - Note: This ID shall be also used for SR_A
#define RTA_GLOBALID_TSA                 ((RTA_t_GlobalID)  81)  ///< TSA_TrafficSignAssist
#define RTA_GLOBALID_CHIPS_SV_CYL_RSC    ((RTA_t_GlobalID)  82)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - right side camera
#define RTA_GLOBALID_SR_B                ((RTA_t_GlobalID)  83)  ///< SR_SignRecognition - For SR_B (the low prio part of signRecognition) only!!!
#define RTA_GLOBALID_DGM                 ((RTA_t_GlobalID)  84)  ///< DegradationManager
#define RTA_GLOBALID_SYNC_SV             ((RTA_t_GlobalID)  85)  ///< Synchronization component - surround view
#define RTA_GLOBALID_PFC                 ((RTA_t_GlobalID)  86)  ///< PFC_PowerFlowComputation
#define RTA_GLOBALID_FAMO                ((RTA_t_GlobalID)  87)  ///< FAMO_FunctionalSafetyAlgoMonitor
#define RTA_GLOBALID_ACAL                ((RTA_t_GlobalID)  88)  ///< ACAL_AutoCalibration
#define RTA_GLOBALID_CEM_GEN3            ((RTA_t_GlobalID)  89)  ///< CEM_GenericID3
#define RTA_GLOBALID_LCF_VEH               90  ///< SubComponent of  LCF_LateralControlFunctions
#define RTA_GLOBALID_LCF_SEN               91  ///< SubComponent of LCF_LateralControlFunctions
#define RTA_GLOBALID_LSD                 ((RTA_t_GlobalID)  92)  ///< LSD_LightSourceDetection
#define RTA_GLOBALID_RUM                 ((RTA_t_GlobalID)  93)  ///< RUM_RoadUserMeasurements - Note: This ID is for both RUM and RUM2 !!
#define RTA_GLOBALID_UDW                 ((RTA_t_GlobalID)  94)  ///< UDW_UnsteadyDrivingWarning
#define RTA_GLOBALID_PCA                 ((RTA_t_GlobalID)  95)  ///< PCA_PointCloudAlgorithm
#define RTA_GLOBALID_EMO_SV              ((RTA_t_GlobalID)  96)  ///< EMO_EgoMotion - surround view
#define RTA_GLOBALID_GSM                 ((RTA_t_GlobalID)  97)  ///< GSM_GroundSurfaceModel
#define RTA_GLOBALID_PDM                 ((RTA_t_GlobalID)  98)  ///< PDM_PerformanceDegradationModule
#define RTA_GLOBALID_POC                 ((RTA_t_GlobalID)  99)  ///< POC_POintcloudCorrespondences
#define RTA_GLOBALID_ICU                 ((RTA_t_GlobalID) 100)
#define RTA_GLOBALID_FCU                 ((RTA_t_GlobalID) 101)  ///< FCU_FunctionControlUnit
#define RTA_GLOBALID_CEM_LRR             ((RTA_t_GlobalID) 102)  ///< SIP_CEM_LongRangeRadar
#define RTA_GLOBALID_CEM_CAM             ((RTA_t_GlobalID) 103)  ///< SIP_CEM_Camera
#define RTA_GLOBALID_EMO                 ((RTA_t_GlobalID) 104)  ///< EMO_EgoMotion - Note: This ID is for both EMO and MEMO !!
#define RTA_GLOBALID_GEN                 ((RTA_t_GlobalID) 105)  ///< GEN_GeneralObjectDetection
#define RTA_GLOBALID_GRAPPA              ((RTA_t_GlobalID) 106)  ///< GRAPPA_GenericRedvinePictureAnalysis
#define RTA_GLOBALID_DBD                 ((RTA_t_GlobalID) 107)  ///< Debris Detection
#define RTA_GLOBALID_PC                  ((RTA_t_GlobalID) 108)  ///< PC_PatchCorrelator
#define RTA_GLOBALID_CEM_FDP1            ((RTA_t_GlobalID) 109)  ///< FDP_CEM_Output1
#define RTA_GLOBALID_LIQOR               ((RTA_t_GlobalID) 110)  ///< LIQOR_LidarQuickObjectRecognition
#define RTA_GLOBALID_VODCA               ((RTA_t_GlobalID) 111)  ///< VODCA_VisObjDetClaAlgo
#define RTA_GLOBALID_FS                  ((RTA_t_GlobalID) 112)  ///< FS_FreeSpace
#define RTA_GLOBALID_FCU_ALN             ((RTA_t_GlobalID) 113)  ///< FunctionControlUnit - alignment stuff
#define RTA_GLOBALID_CEM_EMF             ((RTA_t_GlobalID) 114)  ///< CEM_EnvironmentModelFramework
#define RTA_GLOBALID_CHIPS_SV_W_FC       ((RTA_t_GlobalID) 115)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - front camera
#define RTA_GLOBALID_CHIPS_SV_W_LSC      ((RTA_t_GlobalID) 116)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - left side camera
#define RTA_GLOBALID_CHIPS_SV_W_RC       ((RTA_t_GlobalID) 117)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - rear camera
#define RTA_GLOBALID_CHIPS_SV_W_RSC      ((RTA_t_GlobalID) 118)  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - right side camera
#define RTA_GLOBALID_TLR                 ((RTA_t_GlobalID) 119)  ///< TLR_TrafficLightRecognition
#define RTA_GLOBALID_DAP                 ((RTA_t_GlobalID) 120)  ///< DAP_RadarDataProcessing
#define RTA_GLOBALID_GP                  ((RTA_t_GlobalID) 121)  ///< GP_RadarGridProcessing
#define RTA_GLOBALID_OD                  ((RTA_t_GlobalID) 122)  ///< OD_RadarObjectDescription
#define RTA_GLOBALID_ITC                 ((RTA_t_GlobalID) 123)  ///< ITC_InterTaskCommunication
#define RTA_GLOBALID_RPD                 ((RTA_t_GlobalID) 124)  ///< Radar PreDetection
#define RTA_GLOBALID_LMK                 ((RTA_t_GlobalID) 125)  ///< LMK_LandMarks
#define RTA_GLOBALID_VTS                 ((RTA_t_GlobalID) 126)  ///< VehDyn TimeSync
#define RTA_GLOBALID_RDPT                ((RTA_t_GlobalID) 127)  ///< Radar Detection Processiong and Tracking
#define RTA_GLOBALID_GRID                ((RTA_t_GlobalID) 128)  ///< Grid processing
#define RTA_GLOBALID_MSA                 ((RTA_t_GlobalID) 129)  ///< Microdoppler Signature Analysis
#define RTA_GLOBALID_MRP                 ((RTA_t_GlobalID) 130)  ///< Motion Radar Properties
#define RTA_GLOBALID_LOPC                ((RTA_t_GlobalID) 131)  ///< LongitudinalPlannerAndController
#define RTA_GLOBALID_IPC_IUC             ((RTA_t_GlobalID) 132)  ///< IPC_InterProcessorCommunication - IPC IUC
#define RTA_GLOBALID_MTSI                ((RTA_t_GlobalID) 133)  ///< MTSI_MTSInterface
#define RTA_GLOBALID_CEH                 ((RTA_t_GlobalID) 134)  ///< Central Error Handler
#define RTA_GLOBALID_LOHP                ((RTA_t_GlobalID) 135)  ///< LongitudinalHeadwayPlanner
#define RTA_GLOBALID_PRIME               ((RTA_t_GlobalID) 136)  ///< EMtoFunctionsTransformer
#define RTA_GLOBALID_BSD                 ((RTA_t_GlobalID) 137)  ///< Blind Spot Detection
#define RTA_GLOBALID_RTL                 ((RTA_t_GlobalID) 138)  ///< RTL_RealTimeLogging
#define RTA_GLOBALID_LCA                 ((RTA_t_GlobalID) 139)  ///< Lane Change Assist
#define RTA_GLOBALID_DEM                 ((RTA_t_GlobalID) 140)  ///< DiagnosticEventManager
#define RTA_GLOBALID_OSE                 ((RTA_t_GlobalID) 141)  ///< Occupant Safe Exit
#define RTA_GLOBALID_CTM                 ((RTA_t_GlobalID) 142)  ///< Cross Traffic Module
#define RTA_GLOBALID_CTA                 ((RTA_t_GlobalID) 143)  ///< Cross Traffic Assist
#define RTA_GLOBALID_BSIS                ((RTA_t_GlobalID) 144)  ///< Blind Spot Information System
#define RTA_GLOBALID_RPCS                ((RTA_t_GlobalID) 145)  ///< Rear Pre-Crash Prediction
#define RTA_GLOBALID_SID                 ((RTA_t_GlobalID) 146)  ///< Sensor Identification (sensor right/left..., frame-SW component)
#define RTA_GLOBALID_RTA                 ((RTA_t_GlobalID) 147)  ///< RTA_RealTimeAnalysis1
#define RTA_GLOBALID_TSE                 ((RTA_t_GlobalID) 148)  ///< Time Synchronization Engine
#define RTA_GLOBALID_PFC_SV_FC           ((RTA_t_GlobalID) 149)  ///< PFC_PowerFlowComputation - surround view - front camera
#define RTA_GLOBALID_PFC_SV_LSC          ((RTA_t_GlobalID) 150)  ///< PFC_PowerFlowComputation - surround view - left side camera
#define RTA_GLOBALID_PFC_SV_RC           ((RTA_t_GlobalID) 151)  ///< PFC_PowerFlowComputation - surround view - rear camera
#define RTA_GLOBALID_ET                  ((RTA_t_GlobalID) 152)  ///< EventTranceiver  - subComponent of DPUFF_FunctionsFramework
#define RTA_GLOBALID_PMA                 ((RTA_t_GlobalID) 153)  ///< PMA_PostMortemAnalysis
#define RTA_GLOBALID_PFC_SV_RSC          ((RTA_t_GlobalID) 154)  ///< PFC_PowerFlowComputation - surround view - right side camera
#define RTA_GLOBALID_MEDIC               ((RTA_t_GlobalID) 155)  ///< InterventionControl
#define RTA_GLOBALID_GEOS_SV_FC          ((RTA_t_GlobalID) 156)  ///< GEOS_GeometricSegmentation - surround view - front camera
#define RTA_GLOBALID_GEOS_SV_LSC         ((RTA_t_GlobalID) 157)  ///< GEOS_GeometricSegmentation - surround view - left side camera
#define RTA_GLOBALID_GEOS_SV_RC          ((RTA_t_GlobalID) 158)  ///< GEOS_GeometricSegmentation - surround view - rear camera
#define RTA_GLOBALID_GEOS_SV_RSC         ((RTA_t_GlobalID) 159)  ///< GEOS_GeometricSegmentation - surround view - right side camera
#define RTA_GLOBALID_GEN_ADAPT_ADAPTER   ((RTA_t_GlobalID) 160)  ///< Generic adaptor - adaptor runtime
#define RTA_GLOBALID_FCU_CEH             ((RTA_t_GlobalID) 161)  ///< FunctionControlUnit - Central Error Handler
#define RTA_GLOBALID_EVT_MARKER          ((RTA_t_GlobalID) 162)  ///< Software event marker
#define RTA_GLOBALID_FCU_VDY             ((RTA_t_GlobalID) 163)  ///< FunctionControlUnit - Vehicle signal mapping
#define RTA_GLOBALID_FCU_SYSTEM          ((RTA_t_GlobalID) 164)  ///< FunctionControlUnit - reading bus data, signal group checks
#define RTA_GLOBALID_GEN_ADAPT_ALGO_EXEC ((RTA_t_GlobalID) 165)  ///< Generic adaptor - algo runtime
#define RTA_GLOBALID_FCU_RADI            ((RTA_t_GlobalID) 166)  ///< FunctionControlUnit - mapping detection list
#define RTA_GLOBALID_HWI                 ((RTA_t_GlobalID) 167)  ///< MFC4xx  DPUs -> HardwareInterrupts
#define RTA_GLOBALID_SWI                 ((RTA_t_GlobalID) 168)  ///< MFC4xx  DPUs -> SoftwareInterrupts
#define RTA_GLOBALID_GDR_SV_FC           ((RTA_t_GlobalID) 169)  ///< GDR_GeometricDepthReconstruction - surround view - front camera
#define RTA_GLOBALID_GDR_SV_LSC          ((RTA_t_GlobalID) 170)  ///< GDR_GeometricDepthReconstruction - surround view - left side camera
#define RTA_GLOBALID_GDR_SV_RC           ((RTA_t_GlobalID) 171)  ///< GDR_GeometricDepthReconstruction - surround view - rear camera
#define RTA_GLOBALID_GDR_SV_RSC          ((RTA_t_GlobalID) 172)  ///< GDR_GeometricDepthReconstruction - surround view - right side camera
#define RTA_GLOBALID_EVE                 ((RTA_t_GlobalID) 173)
#define RTA_GLOBALID_EVE_TRIGGER         ((RTA_t_GlobalID) 174)
#define RTA_GLOBALID_EVE_LOCKOUT         ((RTA_t_GlobalID) 175)
#define RTA_GLOBALID_DPUSERVICE          ((RTA_t_GlobalID) 176)  ///< DPUSERVICE_Services
#define RTA_GLOBALID_DPUST               ((RTA_t_GlobalID) 177)  ///< DpuSelftest
#define RTA_GLOBALID_GRAPPA_SV_FC        ((RTA_t_GlobalID) 178)  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - front camera
#define RTA_GLOBALID_GRAPPA_SV_LSC       ((RTA_t_GlobalID) 179)  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - left side camera
#define RTA_GLOBALID_GRAPPA_SV_RC        ((RTA_t_GlobalID) 180)  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - rear camera
#define RTA_GLOBALID_GRAPPA_SV_RSC       ((RTA_t_GlobalID) 181)  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - right side camera
#define RTA_GLOBALID_FCU_SSI             ((RTA_t_GlobalID) 182)  ///< FunctionControlUnit - mapping sensor supporting interface
#define RTA_GLOBALID_MDB                 ((RTA_t_GlobalID) 183)  ///< MultiCore database - subComponent of DPUFF_FunctionsFramework
#define RTA_GLOBALID_RUM_SV_FC           ((RTA_t_GlobalID) 184)  ///< RUM_RoadUserMeasurements - surround view - front camera
#define RTA_GLOBALID_RUM_SV_LSC          ((RTA_t_GlobalID) 185)  ///< RUM_RoadUserMeasurements - surround view - left side camera
#define RTA_GLOBALID_DPUINFRA            ((RTA_t_GlobalID) 186)  ///< DPUINFRA_Infrastructure
#define RTA_GLOBALID_RUM_SV_RC           ((RTA_t_GlobalID) 187)  ///< RUM_RoadUserMeasurements - surround view - rear camera
#define RTA_GLOBALID_RUM_SV_RSC          ((RTA_t_GlobalID) 188)  ///< RUM_RoadUserMeasurements - surround view - right side camera
#define RTA_GLOBALID_EDR                 ((RTA_t_GlobalID) 189)  ///< EDR_EventDataRecorder
#define RTA_GLOBALID_PMSD_SV_FC          ((RTA_t_GlobalID) 190)  ///< PMSD_ParkingMarkerDetection - surround view - front camera
#define RTA_GLOBALID_PMSD_SV_LSC         ((RTA_t_GlobalID) 191)  ///< PMSD_ParkingMarkerDetection - surround view - left side camera
#define RTA_GLOBALID_IPC_DPU_RX          ((RTA_t_GlobalID) 192)  ///< IPC_InterProcessorCommunication - DPU RX
#define RTA_GLOBALID_PMSD_SV_RC          ((RTA_t_GlobalID) 193)  ///< PMSD_ParkingMarkerDetection - surround view - rear camera
#define RTA_GLOBALID_PMSD_SV_RSC         ((RTA_t_GlobalID) 194)  ///< PMSD_ParkingMarkerDetection - surround view - right side camera
#define RTA_GLOBALID_PCC                 ((RTA_t_GlobalID) 195)  ///< PCC_RadarPedestrianCyclistClassification
#define RTA_GLOBALID_PD                  ((RTA_t_GlobalID) 196)  ///< PD_RadarPerformanceDegradation
#define RTA_GLOBALID_FCU_OBJECTLIST      ((RTA_t_GlobalID) 197)  ///< FunctionControlUnit - mapping object list.
#define RTA_GLOBALID_FCU_FCT             ((RTA_t_GlobalID) 198)  ///< FunctionControlUnit - for driving functions
#define RTA_GLOBALID_PVS                 ((RTA_t_GlobalID) 199)  ///< PVS_PavementSigns



#else // #ifndef __cplusplus

static const RTA_t_GlobalID RTA_GLOBALID_INVALID             = (RTA_t_GlobalID)   0;  ///< This GlobalID MUST NOT be used. It is used by the RTA to show that a GlobalID was provided by any user which was out of range.
static const RTA_t_GlobalID RTA_GLOBALID_INTERRUPTS          = (RTA_t_GlobalID)   1;  ///< All the interrupts - only for RTA internal usage!!
static const RTA_t_GlobalID RTA_GLOBALID_VDY                 = (RTA_t_GlobalID)   2;  ///< VDY_VehicleDynamics
static const RTA_t_GlobalID RTA_GLOBALID_FCT_VEH             = (RTA_t_GlobalID)   3;  ///< FCT_Function
static const RTA_t_GlobalID RTA_GLOBALID_ADP                 = (RTA_t_GlobalID)   4;  ///< ADP_AlgoSWAdapter
static const RTA_t_GlobalID RTA_GLOBALID_CEM_ARS540          = (RTA_t_GlobalID)   5;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_APTIV_MFC       = (RTA_t_GlobalID)   6;
static const RTA_t_GlobalID RTA_GLOBALID_HLA                 = (RTA_t_GlobalID)   7;  ///< HLA_HeadLightAssist
static const RTA_t_GlobalID RTA_GLOBALID_CEM_APTIV_SRR       = (RTA_t_GlobalID)   8;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_COH             = (RTA_t_GlobalID)   9;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_EML             = (RTA_t_GlobalID)  10;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_FSF             = (RTA_t_GlobalID)  11;
static const RTA_t_GlobalID RTA_GLOBALID_IC                  = (RTA_t_GlobalID)  12;  ///< DPUIC_ImagerControl
static const RTA_t_GlobalID RTA_GLOBALID_CEM_FDP_BASE        = (RTA_t_GlobalID)  13;
static const RTA_t_GlobalID RTA_GLOBALID_DPC                 = (RTA_t_GlobalID)  14;  ///< DPC_DataProcessingControl
static const RTA_t_GlobalID RTA_GLOBALID_RDPC                = (RTA_t_GlobalID)  15;  ///< RDPC_RawDataProcessingControl
static const RTA_t_GlobalID RTA_GLOBALID_CEM_HANDLER         = (RTA_t_GlobalID)  16;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_RMF             = (RTA_t_GlobalID)  17;
static const RTA_t_GlobalID RTA_GLOBALID_FCT_SEN             = (RTA_t_GlobalID)  18;  ///< FCT_Function
static const RTA_t_GlobalID RTA_GLOBALID_CEM_SEF             = (RTA_t_GlobalID)  19;
static const RTA_t_GlobalID RTA_GLOBALID_ALN                 = (RTA_t_GlobalID)  20;  ///< ALN Alignment
static const RTA_t_GlobalID RTA_GLOBALID_CC                  = (RTA_t_GlobalID)  21;  ///< CC Classification Consolidation
static const RTA_t_GlobalID RTA_GLOBALID_MOS                 = (RTA_t_GlobalID)  22;  ///< MOS Model Output Selection
static const RTA_t_GlobalID RTA_GLOBALID_OOC                 = (RTA_t_GlobalID)  23;  ///< OOC Object and Obstruction Classification
static const RTA_t_GlobalID RTA_GLOBALID_RADI                = (RTA_t_GlobalID)  24;  ///< RADI Radar Detection Image
static const RTA_t_GlobalID RTA_GLOBALID_RDT                 = (RTA_t_GlobalID)  25;  ///< RDT Radar Detection Tracker
static const RTA_t_GlobalID RTA_GLOBALID_HAX                 = (RTA_t_GlobalID)  26;  ///< HAX Radar Tracking Hardware Accelerator
static const RTA_t_GlobalID RTA_GLOBALID_RFCOM               = (RTA_t_GlobalID)  27;  ///< RFCOM RadioFrequencyCommunication
static const RTA_t_GlobalID RTA_GLOBALID_RHC                 = (RTA_t_GlobalID)  28;  ///< RHC RadarHardwareControl
static const RTA_t_GlobalID RTA_GLOBALID_RIC                 = (RTA_t_GlobalID)  29;  ///< RIC Road Infrastructure Classification
static const RTA_t_GlobalID RTA_GLOBALID_RMHT                = (RTA_t_GlobalID)  30;  ///< RMHT Radar Multi Hypothesis Tracker
static const RTA_t_GlobalID RTA_GLOBALID_RMP1                = (RTA_t_GlobalID)  31;  ///< RMP1 Radar Motion Properties 1
static const RTA_t_GlobalID RTA_GLOBALID_RMP2                = (RTA_t_GlobalID)  32;  ///< RMP2 Radar Motion Properties 2
static const RTA_t_GlobalID RTA_GLOBALID_RPM1                = (RTA_t_GlobalID)  33;  ///< RPM1 Radar Performance Monitoring 1
static const RTA_t_GlobalID RTA_GLOBALID_RPM2                = (RTA_t_GlobalID)  34;  ///< RPM2 Radar Performance Monitoring 2
static const RTA_t_GlobalID RTA_GLOBALID_RPP                 = (RTA_t_GlobalID)  35;  ///< RPP Radar Parameter Processing
static const RTA_t_GlobalID RTA_GLOBALID_RSP                 = (RTA_t_GlobalID)  36;  ///< RSP RadarSignalProcessing
static const RTA_t_GlobalID RTA_GLOBALID_SEP1                = (RTA_t_GlobalID)  37;  ///< SEP Static Environment Properties
static const RTA_t_GlobalID RTA_GLOBALID_SEP2                = (RTA_t_GlobalID)  38;  ///< SEP Static Environment Properties
static const RTA_t_GlobalID RTA_GLOBALID_SPT                 = (RTA_t_GlobalID)  39;  ///< SPT SignalProcessingToolbox
static const RTA_t_GlobalID RTA_GLOBALID_SRP1                = (RTA_t_GlobalID)  40;  ///< SRP1 Spatial and Relation Properties 1
static const RTA_t_GlobalID RTA_GLOBALID_SRP2                = (RTA_t_GlobalID)  41;  ///< SRP2 Spatial and Relation Properties 2
static const RTA_t_GlobalID RTA_GLOBALID_CEM_TPF             = (RTA_t_GlobalID)  42;
static const RTA_t_GlobalID RTA_GLOBALID_CEM_VAL             = (RTA_t_GlobalID)  43;
static const RTA_t_GlobalID RTA_GLOBALID_HOMON               = (RTA_t_GlobalID)  44;
static const RTA_t_GlobalID RTA_GLOBALID_LOCTR               = (RTA_t_GlobalID)  45;  ///< LOCTR_LongitudinalTrajectoryController
static const RTA_t_GlobalID RTA_GLOBALID_LOPLN               = (RTA_t_GlobalID)  46;  ///< LOPLN_LongitudinalTrajectoryPlanner
static const RTA_t_GlobalID RTA_GLOBALID_RD                  = (RTA_t_GlobalID)  47;  ///< RD_RadarRoadDescription
static const RTA_t_GlobalID RTA_GLOBALID_NONE_OSEK_CORE_1    = (RTA_t_GlobalID)  48;  ///< None_Osek_Core_1 - Radar legacy implementation (ARS410)
static const RTA_t_GlobalID RTA_GLOBALID_NONE_OSEK_CORE_2    = (RTA_t_GlobalID)  49;  ///< None_Osek_Core_2 - Radar legacy implementation (ARS410)
static const RTA_t_GlobalID RTA_GLOBALID_GA_WRAPPER          = (RTA_t_GlobalID)  50;  ///< Global architecture wrapper
static const RTA_t_GlobalID RTA_GLOBALID_ASILBCODING         = (RTA_t_GlobalID)  51;  ///< Asil B coding
static const RTA_t_GlobalID RTA_GLOBALID_SYNC                = (RTA_t_GlobalID)  52;  ///< synch component which copies the data from vdy cycle to image cycle
static const RTA_t_GlobalID RTA_GLOBALID_DPUCOM              = (RTA_t_GlobalID)  53;
static const RTA_t_GlobalID RTA_GLOBALID_PMSD                = (RTA_t_GlobalID)  54;  ///< Parking marker detection for surround view projects
static const RTA_t_GlobalID RTA_GLOBALID_ECUOMC              = (RTA_t_GlobalID)  55;  ///< Used for ECU Operation Mode Control
static const RTA_t_GlobalID RTA_GLOBALID_DPUHWIF             = (RTA_t_GlobalID)  56;  ///< DPUHWIF_HardwareInterface
static const RTA_t_GlobalID RTA_GLOBALID_DPUIA               = (RTA_t_GlobalID)  57;  ///< DPUIA ImageAcquisition
static const RTA_t_GlobalID RTA_GLOBALID_ACDC                = (RTA_t_GlobalID)  58;  ///< ACDC_CollisionDetectionAndClassification (Also for ACDC2)
static const RTA_t_GlobalID RTA_GLOBALID_CEM_VDY             = (RTA_t_GlobalID)  59;  ///< SIP_CEM_VehicleDynamics
static const RTA_t_GlobalID RTA_GLOBALID_CEM_USS             = (RTA_t_GlobalID)  60;  ///< SIP_CEM_UltraSonic
static const RTA_t_GlobalID RTA_GLOBALID_CEM_FDP2            = (RTA_t_GlobalID)  61;  ///< FDP_CEM_Output2
static const RTA_t_GlobalID RTA_GLOBALID_EC                  = (RTA_t_GlobalID)  62;  ///< EC_RadarEnvironmentClassification
static const RTA_t_GlobalID RTA_GLOBALID_ISP_SV_FC           = (RTA_t_GlobalID)  63;  ///< ISP_ImageSignalProcessor - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_ISP_SV_LSC          = (RTA_t_GlobalID)  64;  ///< ISP_ImageSignalProcessor - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_ISP_SV_RC           = (RTA_t_GlobalID)  65;  ///< ISP_ImageSignalProcessor - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_ISP_SV_RSC          = (RTA_t_GlobalID)  66;  ///< ISP_ImageSignalProcessor - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_EM                  = (RTA_t_GlobalID)  67;  ///< EM_CameraEnvironmentModel
static const RTA_t_GlobalID RTA_GLOBALID_CEM_GEN1            = (RTA_t_GlobalID)  68;  ///< CEM_GenericID1
static const RTA_t_GlobalID RTA_GLOBALID_CEM_GEN2            = (RTA_t_GlobalID)  69;  ///< CEM_GenericID2
static const RTA_t_GlobalID RTA_GLOBALID_CIPP                = (RTA_t_GlobalID)  70;  ///< CIPP_CommonImagePreProcessing
static const RTA_t_GlobalID RTA_GLOBALID_CB                  = (RTA_t_GlobalID)  71;  ///< CB_CameraBlockage
static const RTA_t_GlobalID RTA_GLOBALID_ECM                 = (RTA_t_GlobalID)  72;  ///< ECM_EOLCalibrationMono
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS               = (RTA_t_GlobalID)  73;  ///< CHIPS_CommonHWAcceleratedImgProcSys
static const RTA_t_GlobalID RTA_GLOBALID_GS                  = (RTA_t_GlobalID)  74;  ///< GS_GlobalScheduler
static const RTA_t_GlobalID RTA_GLOBALID_LD                  = (RTA_t_GlobalID)  75;  ///< LD_LaneDetection
static const RTA_t_GlobalID RTA_GLOBALID_EVE_ABORT           = (RTA_t_GlobalID)  76;
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_CYL_FC     = (RTA_t_GlobalID)  77;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_CYL_LSC    = (RTA_t_GlobalID)  78;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_CYL_RC     = (RTA_t_GlobalID)  79;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_SR                  = (RTA_t_GlobalID)  80;  ///< SR_SignRecognition - Note: This ID shall be also used for SR_A
static const RTA_t_GlobalID RTA_GLOBALID_TSA                 = (RTA_t_GlobalID)  81;  ///< TSA_TrafficSignAssist
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_CYL_RSC    = (RTA_t_GlobalID)  82;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_SR_B                = (RTA_t_GlobalID)  83;  ///< SR_SignRecognition - For SR_B (the low prio part of signRecognition) only!!!
static const RTA_t_GlobalID RTA_GLOBALID_DGM                 = (RTA_t_GlobalID)  84;  ///< DegradationManager
static const RTA_t_GlobalID RTA_GLOBALID_SYNC_SV             = (RTA_t_GlobalID)  85;  ///< Synchronization component - surround view
static const RTA_t_GlobalID RTA_GLOBALID_PFC                 = (RTA_t_GlobalID)  86;  ///< PFC_PowerFlowComputation
static const RTA_t_GlobalID RTA_GLOBALID_FAMO                = (RTA_t_GlobalID)  87;  ///< FAMO_FunctionalSafetyAlgoMonitor
static const RTA_t_GlobalID RTA_GLOBALID_ACAL                = (RTA_t_GlobalID)  88;  ///< ACAL_AutoCalibration
static const RTA_t_GlobalID RTA_GLOBALID_CEM_GEN3            = (RTA_t_GlobalID)  89;  ///< CEM_GenericID3
static const RTA_t_GlobalID RTA_GLOBALID_LCF_VEH             = (RTA_t_GlobalID)  90;  ///< SubComponent of  LCF_LateralControlFunctions
static const RTA_t_GlobalID RTA_GLOBALID_LCF_SEN             = (RTA_t_GlobalID)  91;  ///< SubComponent of LCF_LateralControlFunctions
static const RTA_t_GlobalID RTA_GLOBALID_LSD                 = (RTA_t_GlobalID)  92;  ///< LSD_LightSourceDetection
static const RTA_t_GlobalID RTA_GLOBALID_RUM                 = (RTA_t_GlobalID)  93;  ///< RUM_RoadUserMeasurements - Note: This ID is for both RUM and RUM2 !!
static const RTA_t_GlobalID RTA_GLOBALID_UDW                 = (RTA_t_GlobalID)  94;  ///< UDW_UnsteadyDrivingWarning
static const RTA_t_GlobalID RTA_GLOBALID_PCA                 = (RTA_t_GlobalID)  95;  ///< PCA_PointCloudAlgorithm
static const RTA_t_GlobalID RTA_GLOBALID_EMO_SV              = (RTA_t_GlobalID)  96;  ///< EMO_EgoMotion - surround view
static const RTA_t_GlobalID RTA_GLOBALID_GSM                 = (RTA_t_GlobalID)  97;  ///< GSM_GroundSurfaceModel
static const RTA_t_GlobalID RTA_GLOBALID_PDM                 = (RTA_t_GlobalID)  98;  ///< PDM_PerformanceDegradationModule
static const RTA_t_GlobalID RTA_GLOBALID_POC                 = (RTA_t_GlobalID)  99;  ///< POC_POintcloudCorrespondences
static const RTA_t_GlobalID RTA_GLOBALID_ICU                 = (RTA_t_GlobalID) 100;
static const RTA_t_GlobalID RTA_GLOBALID_FCU                 = (RTA_t_GlobalID) 101;  ///< FCU_FunctionControlUnit
static const RTA_t_GlobalID RTA_GLOBALID_CEM_LRR             = (RTA_t_GlobalID) 102;  ///< SIP_CEM_LongRangeRadar
static const RTA_t_GlobalID RTA_GLOBALID_CEM_CAM             = (RTA_t_GlobalID) 103;  ///< SIP_CEM_Camera
static const RTA_t_GlobalID RTA_GLOBALID_EMO                 = (RTA_t_GlobalID) 104;  ///< EMO_EgoMotion - Note: This ID is for both EMO and MEMO !!
static const RTA_t_GlobalID RTA_GLOBALID_GEN                 = (RTA_t_GlobalID) 105;  ///< GEN_GeneralObjectDetection
static const RTA_t_GlobalID RTA_GLOBALID_GRAPPA              = (RTA_t_GlobalID) 106;  ///< GRAPPA_GenericRedvinePictureAnalysis
static const RTA_t_GlobalID RTA_GLOBALID_DBD                 = (RTA_t_GlobalID) 107;  ///< Debris Detection
static const RTA_t_GlobalID RTA_GLOBALID_PC                  = (RTA_t_GlobalID) 108;  ///< PC_PatchCorrelator
static const RTA_t_GlobalID RTA_GLOBALID_CEM_FDP1            = (RTA_t_GlobalID) 109;  ///< FDP_CEM_Output1
static const RTA_t_GlobalID RTA_GLOBALID_LIQOR               = (RTA_t_GlobalID) 110;  ///< LIQOR_LidarQuickObjectRecognition
static const RTA_t_GlobalID RTA_GLOBALID_VODCA               = (RTA_t_GlobalID) 111;  ///< VODCA_VisObjDetClaAlgo
static const RTA_t_GlobalID RTA_GLOBALID_FS                  = (RTA_t_GlobalID) 112;  ///< FS_FreeSpace
static const RTA_t_GlobalID RTA_GLOBALID_FCU_ALN             = (RTA_t_GlobalID) 113;  ///<  FCU_FunctionControlUnit - alignment stuff
static const RTA_t_GlobalID RTA_GLOBALID_CEM_EMF             = (RTA_t_GlobalID) 114;  ///< CEM_EnvironmentModelFramework
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_W_FC       = (RTA_t_GlobalID) 115;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_W_LSC      = (RTA_t_GlobalID) 116;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_W_RC       = (RTA_t_GlobalID) 117;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_CHIPS_SV_W_RSC      = (RTA_t_GlobalID) 118;  ///< CHIPS_CommonHWAcceleratedImgProcSys - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_TLR                 = (RTA_t_GlobalID) 119;  ///< TLR_TrafficLightRecognition
static const RTA_t_GlobalID RTA_GLOBALID_DAP                 = (RTA_t_GlobalID) 120;  ///< DAP_RadarDataProcessing
static const RTA_t_GlobalID RTA_GLOBALID_GP                  = (RTA_t_GlobalID) 121;  ///< GP_RadarGridProcessing
static const RTA_t_GlobalID RTA_GLOBALID_OD                  = (RTA_t_GlobalID) 122;  ///< OD_RadarObjectDescription
static const RTA_t_GlobalID RTA_GLOBALID_ITC                 = (RTA_t_GlobalID) 123;  ///< ITC_InterTaskCommunication
static const RTA_t_GlobalID RTA_GLOBALID_RPD                 = (RTA_t_GlobalID) 124;  ///< Radar PreDetection
static const RTA_t_GlobalID RTA_GLOBALID_LMK                 = (RTA_t_GlobalID) 125;  ///< LMK_LandMarks
static const RTA_t_GlobalID RTA_GLOBALID_VTS                 = (RTA_t_GlobalID) 126;  ///< VehDyn TimeSync
static const RTA_t_GlobalID RTA_GLOBALID_RDPT                = (RTA_t_GlobalID) 127;  ///< Radar Detection Processiong and Tracking
static const RTA_t_GlobalID RTA_GLOBALID_GRID                = (RTA_t_GlobalID) 128;  ///< Grid processing
static const RTA_t_GlobalID RTA_GLOBALID_MSA                 = (RTA_t_GlobalID) 129;  ///< Microdoppler Signature Analysis
static const RTA_t_GlobalID RTA_GLOBALID_MRP                 = (RTA_t_GlobalID) 130;  ///< Motion Radar Properties
static const RTA_t_GlobalID RTA_GLOBALID_LOPC                = (RTA_t_GlobalID) 131;  ///< LongitudinalPlannerAndController
static const RTA_t_GlobalID RTA_GLOBALID_IPC_IUC             = (RTA_t_GlobalID) 132;  ///< IPC_InterProcessorCommunication - IPC IUC
static const RTA_t_GlobalID RTA_GLOBALID_MTSI                = (RTA_t_GlobalID) 133;  ///< MTSI_MTSInterface
static const RTA_t_GlobalID RTA_GLOBALID_CEH                 = (RTA_t_GlobalID) 134;  ///< Central Error Handler
static const RTA_t_GlobalID RTA_GLOBALID_LOHP                = (RTA_t_GlobalID) 135;  ///< LongitudinalHeadwayPlanner
static const RTA_t_GlobalID RTA_GLOBALID_PRIME               = (RTA_t_GlobalID) 136;  ///< EMtoFunctionsTransformer
static const RTA_t_GlobalID RTA_GLOBALID_BSD                 = (RTA_t_GlobalID) 137;  ///< Blind Spot Detection
static const RTA_t_GlobalID RTA_GLOBALID_RTL                 = (RTA_t_GlobalID) 138;  ///< RTL_RealTimeLogging
static const RTA_t_GlobalID RTA_GLOBALID_LCA                 = (RTA_t_GlobalID) 139;  ///< Lane Change Assist
static const RTA_t_GlobalID RTA_GLOBALID_DEM                 = (RTA_t_GlobalID) 140;  ///< DiagnosticEventManager
static const RTA_t_GlobalID RTA_GLOBALID_OSE                 = (RTA_t_GlobalID) 141;  ///< Occupant Safe Exit
static const RTA_t_GlobalID RTA_GLOBALID_CTM                 = (RTA_t_GlobalID) 142;  ///< Cross Traffic Module
static const RTA_t_GlobalID RTA_GLOBALID_CTA                 = (RTA_t_GlobalID) 143;  ///< Cross Traffic Assist
static const RTA_t_GlobalID RTA_GLOBALID_BSIS                = (RTA_t_GlobalID) 144;  ///< Blind Spot Information System
static const RTA_t_GlobalID RTA_GLOBALID_RPCS                = (RTA_t_GlobalID) 145;  ///< Rear Pre-Crash Prediction
static const RTA_t_GlobalID RTA_GLOBALID_SID                 = (RTA_t_GlobalID) 146;  ///< Sensor Identification (sensor right/left..., frame-SW component)
static const RTA_t_GlobalID RTA_GLOBALID_RTA                 = (RTA_t_GlobalID) 147;  ///< RTA_RealTimeAnalysis1
static const RTA_t_GlobalID RTA_GLOBALID_TSE                 = (RTA_t_GlobalID) 148;  ///< Time Synchronization Engine
static const RTA_t_GlobalID RTA_GLOBALID_PFC_SV_FC           = (RTA_t_GlobalID) 149;  ///< PFC_PowerFlowComputation - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_PFC_SV_LSC          = (RTA_t_GlobalID) 150;  ///< PFC_PowerFlowComputation - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_PFC_SV_RC           = (RTA_t_GlobalID) 151;  ///< PFC_PowerFlowComputation - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_ET                  = (RTA_t_GlobalID) 152;  ///< EventTranceiver  - subComponent of DPUFF_FunctionsFramework
static const RTA_t_GlobalID RTA_GLOBALID_PMA                 = (RTA_t_GlobalID) 153;  ///< PMA_PostMortemAnalysis
static const RTA_t_GlobalID RTA_GLOBALID_PFC_SV_RSC          = (RTA_t_GlobalID) 154;  ///< PFC_PowerFlowComputation - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_MEDIC               = (RTA_t_GlobalID) 155;  ///< InterventionControl
static const RTA_t_GlobalID RTA_GLOBALID_GEOS_SV_FC          = (RTA_t_GlobalID) 156;  ///< GEOS_GeometricSegmentation - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_GEOS_SV_LSC         = (RTA_t_GlobalID) 157;  ///< GEOS_GeometricSegmentation - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_GEOS_SV_RC          = (RTA_t_GlobalID) 158;  ///< GEOS_GeometricSegmentation - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_GEOS_SV_RSC         = (RTA_t_GlobalID) 159;  ///< GEOS_GeometricSegmentation - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_GEN_ADAPT_ADAPTER   = (RTA_t_GlobalID) 160;  ///< Generic adaptor - adaptor runtime
static const RTA_t_GlobalID RTA_GLOBALID_FCU_CEH             = (RTA_t_GlobalID) 161;  ///< FCU_FunctionControlUnit - Central Error Handler
static const RTA_t_GlobalID RTA_GLOBALID_EVT_MARKER          = (RTA_t_GlobalID) 162;  ///< Software event marker
static const RTA_t_GlobalID RTA_GLOBALID_FCU_VDY             = (RTA_t_GlobalID) 163;  ///< FunctionControlUnit - Vehicle signal mapping
static const RTA_t_GlobalID RTA_GLOBALID_FCU_SYSTEM          = (RTA_t_GlobalID) 164;  ///< FunctionControlUnit - reading bus data, signal group checks
static const RTA_t_GlobalID RTA_GLOBALID_GEN_ADAPT_ALGO_EXEC = (RTA_t_GlobalID) 165;  ///< Generic adaptor - algo runtime
static const RTA_t_GlobalID RTA_GLOBALID_FCU_RADI            = (RTA_t_GlobalID) 166;  ///< FunctionControlUnit - mapping detection list
static const RTA_t_GlobalID RTA_GLOBALID_HWI                 = (RTA_t_GlobalID) 167;  ///< MFC4xx  DPUs -> HardwareInterrupts
static const RTA_t_GlobalID RTA_GLOBALID_SWI                 = (RTA_t_GlobalID) 168;  ///< MFC4xx  DPUs -> SoftwareInterrupts
static const RTA_t_GlobalID RTA_GLOBALID_GDR_SV_FC           = (RTA_t_GlobalID) 169;  ///< GDR_GeometricDepthReconstruction - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_GDR_SV_LSC          = (RTA_t_GlobalID) 170;  ///< GDR_GeometricDepthReconstruction - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_GDR_SV_RC           = (RTA_t_GlobalID) 171;  ///< GDR_GeometricDepthReconstruction - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_GDR_SV_RSC          = (RTA_t_GlobalID) 172;  ///< GDR_GeometricDepthReconstruction - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_EVE                 = (RTA_t_GlobalID) 173;
static const RTA_t_GlobalID RTA_GLOBALID_EVE_TRIGGER         = (RTA_t_GlobalID) 174;
static const RTA_t_GlobalID RTA_GLOBALID_EVE_LOCKOUT         = (RTA_t_GlobalID) 175;
static const RTA_t_GlobalID RTA_GLOBALID_DPUSERVICE          = (RTA_t_GlobalID) 176;  ///< DPUSERVICE_Services
static const RTA_t_GlobalID RTA_GLOBALID_DPUST               = (RTA_t_GlobalID) 177;  ///< DpuSelftest
static const RTA_t_GlobalID RTA_GLOBALID_GRAPPA_SV_FC        = (RTA_t_GlobalID) 178;  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_GRAPPA_SV_LSC       = (RTA_t_GlobalID) 179;  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_GRAPPA_SV_RC        = (RTA_t_GlobalID) 180;  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_GRAPPA_SV_RSC       = (RTA_t_GlobalID) 181;  ///< GRAPPA_GenericRedvinePictureAnalysis - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_FCU_SSI             = (RTA_t_GlobalID) 182;  ///< FunctionControlUnit - mapping sensor supporting interface
static const RTA_t_GlobalID RTA_GLOBALID_MDB                 = (RTA_t_GlobalID) 183;  ///< MultiCore database - subComponent of DPUFF_FunctionsFramework
static const RTA_t_GlobalID RTA_GLOBALID_RUM_SV_FC           = (RTA_t_GlobalID) 184;  ///< RUM_RoadUserMeasurements - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_RUM_SV_LSC          = (RTA_t_GlobalID) 185;  ///< RUM_RoadUserMeasurements - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_DPUINFRA            = (RTA_t_GlobalID) 186;  ///< DPUINFRA_Infrastructure
static const RTA_t_GlobalID RTA_GLOBALID_RUM_SV_RC           = (RTA_t_GlobalID) 187;  ///< RUM_RoadUserMeasurements - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_RUM_SV_RSC          = (RTA_t_GlobalID) 188;  ///< RUM_RoadUserMeasurements - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_EDR                 = (RTA_t_GlobalID) 189;  ///< EDR_EventDataRecorder
static const RTA_t_GlobalID RTA_GLOBALID_PMSD_SV_FC          = (RTA_t_GlobalID) 190;  ///< PMSD_ParkingMarkerDetection - surround view - front camera
static const RTA_t_GlobalID RTA_GLOBALID_PMSD_SV_LSC         = (RTA_t_GlobalID) 191;  ///< PMSD_ParkingMarkerDetection - surround view - left side camera
static const RTA_t_GlobalID RTA_GLOBALID_IPC_DPU_RX          = (RTA_t_GlobalID) 192;  ///< IPC_InterProcessorCommunication - DPU RX
static const RTA_t_GlobalID RTA_GLOBALID_PMSD_SV_RC          = (RTA_t_GlobalID) 193;  ///< PMSD_ParkingMarkerDetection - surround view - rear camera
static const RTA_t_GlobalID RTA_GLOBALID_PMSD_SV_RSC         = (RTA_t_GlobalID) 194;  ///< PMSD_ParkingMarkerDetection - surround view - right side camera
static const RTA_t_GlobalID RTA_GLOBALID_PCC                 = (RTA_t_GlobalID) 195;  ///< PCC_RadarPedestrianCyclistClassification
static const RTA_t_GlobalID RTA_GLOBALID_PD                  = (RTA_t_GlobalID) 196;  ///< PD_RadarPerformanceDegradation
static const RTA_t_GlobalID RTA_GLOBALID_FCU_OBJECTLIST      = (RTA_t_GlobalID) 197;  ///< FunctionControlUnit - mapping object list.
static const RTA_t_GlobalID RTA_GLOBALID_FCU_FCT             = (RTA_t_GlobalID) 198;  ///< FunctionControlUnit - for driving functions
static const RTA_t_GlobalID RTA_GLOBALID_PVS                 = (RTA_t_GlobalID) 199;  ///< PVS_PavementSigns


#endif // #ifndef __cplusplus

// ___GENERATOR_TAG___RTA_GLOBAL_IDS___END___


// Generated file - no manual changes please!****************************************************************************

#endif // RTA_GLOBALDS_H_INCLUDED
