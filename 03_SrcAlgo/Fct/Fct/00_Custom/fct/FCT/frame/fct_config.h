/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_config.h

DESCRIPTION:               FCT configuration header

AUTHOR:                    $Author: Pallo, Istvan (palloi) $

CREATION DATE:             09.11.2009

VERSION:                   $Revision: 1.37.23.1 $

LEGACY VERSION:            Revision: 1.33.1.2.1.70.1.9

**************************************************************************** */
/** @defgroup frame_pr FRAME_PR (Global Variable Framework, Premium Version and 4B0)

@{ */ 

#ifndef FCT_CFG_H_INCLUDED
#define FCT_CFG_H_INCLUDED


/************************************************************************/
/*                          INCLUDES                                    */
/************************************************************************/
#include "algo_glob.h"

/*****************************************************************************
  Config: Sensor
*****************************************************************************/
/*! definition of FCT_CFG_SENSOR_TYPE_CAMERA */
#define FCT_CFG_SENSOR_TYPE_CAMERA               SWITCH_OFF
/*! definition of FCT_CFG_SENSOR_TYPE_RADAR */
#define FCT_CFG_SENSOR_TYPE_RADAR                SWITCH_ON
/*! definition of FCT_CFG_CLASS_TRUCK */
/*! Using Sensor Bit IR for indicating TRUCK class so at to avoid RTE changes */
#define FCT_CFG_CLASS_TRUCK               SWITCH_OFF


#ifndef ACDC_CFG_USE_FPS
#define ACDC_CFG_USE_FPS                                     (SWITCH_ON)  //For FPS .....@Cheng Long
#endif

#ifndef ACDC_AIP_CFG_SHIFT_COORDINATE
#define ACDC_AIP_CFG_SHIFT_COORDINATE                        (SWITCH_OFF)  //For Shift Coordinate .....@Cheng Long
#endif


/*! definition of FCT_CFG_DEPENDENT_SWITCH */
#define FCT_CFG_DEPENDENT_SWITCH(bool_condition, switch_value) ((bool_condition) && (switch_value))
/*! definition of FCT_CFG_SWITCH_CAMERA*/
#define FCT_CFG_SWITCH_CAMERA(switch_value) (FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_SENSOR_TYPE_CAMERA) , (switch_value)))
/*! definition of FCT_CFG_SWITCH_RADAR*/
#define FCT_CFG_SWITCH_RADAR(switch_value)  (FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_SENSOR_TYPE_RADAR)  , (switch_value)))


/*****************************************************************************
  Config: Components
*****************************************************************************/
/*! FCT switch for ACC (Adaptive Cruise Control) */
#define FCT_CFG_ADAPTIVE_CRUISE_CONTROL                SWITCH_ON // make dependant switch

/*! FCT switch for SLATE Component for ACC */
#define FCT_CFG_SLATE_COMPONENT                       SWITCH_ON // make dependant switch

/*! @brief Configuration switch for enabling revised ACT Code, 0 stands for legacy long code (KMC) usage, 1 for revised (LOP,LOC) */
#define FCT_CFG_ACT_CODE_VERSION                      SWITCH_OFF

/*! FCT switch for LOHP Component for ACC */
#define FCT_CFG_LOHP_COMPONENT                        SWITCH_ON // make dependant switch

/*! FCT switch for LOPC Component for ACC */
#define FCT_CFG_LOPC_COMPONENT                        SWITCH_ON // make dependant switch

/*! FCT switch for LODMC Component for ACC */
#define FCT_CFG_LODMC_COMPONENT                       SWITCH_OFF // make dependant switch   //ACTIVE
//#define FCT_CFG_LODMC_COMPONENT                       SWITCH_ON // make dependant switch   //BSW

/*! FCT switch for ISC Component for ACC */
#define FCT_CFG_ISC_COMPONENT                         FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION, SWITCH_ON)
/*! FCT switch for LOCC Component for ACC */
#define FCT_CFG_LOCC_COMPONENT                        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_ACT_CODE_VERSION, SWITCH_ON)

/*! FCT switch for EBA (Emergency Brake Assist) */
#define FCT_CFG_EMERGENCY_BRAKE_ASSIST                SWITCH_ON // make dependant switch

/*! Switch for the EBA (Emergency Brake Assist) Component ACDC*/
#define FCT_CFG_ACDC_COMPONENT                        SWITCH_ON

/*! Switch for the EBA (Emergency Brake Assist) Component MEDIC*/
#define FCT_CFG_MEDIC_COMPONENT                       SWITCH_ON

/*! Switch for simulation purpose only. To replicate switch FCT_CFG_COURSE_PREDICTION
in slate_config.h. Brief FCT support for CP sub-component */
#define FCT_CFG_SIM_COURSE_PREDICTION                 SWITCH_ON  

#define FCT_CFG_COURSE_PREDICTION_COLLISION_DETECTION  SWITCH_OFF

//TODO Switch is not working transparent.
/*!  brief Activate usage of algo math libraries*/
#define FCT_CFG_USE_ALGO_MATH                     SWITCH_OFF

/*!  brief Activate usage of new common math library (CML) */
#define FCT_CFG_USE_CML                           SWITCH_ON

/*!  brief FCT driver intention monitoring switch */
#define FCT_CFG_DRIVER_INTENTION_MONITORING       SWITCH_ON

/*!  brief FCT collision detection (CD) switch */
#define FCT_CFG_COLLISION_DETECTION               SWITCH_ON

/*!  brief FCT hypothesis evaluation and decision switch */
#define FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION      SWITCH_ON

/*!  brief FCT lane departure warning switch */
#define FCT_CFG_LANE_DEPARTURE_WARNING            FCT_CFG_SWITCH_CAMERA(SWITCH_ON)

/*! FCT signal performance monitoring */
#define FCT_CFG_SIGNAL_PERF_MONITORING            SWITCH_ON

/*! FCT support for ACC HP (Headway Planner) sub-component. Needed for ACT reaction to objects. GEN-3 ACT */
#define FCT_CFG_ACC_HEADWAY_PLANNER               FCT_CFG_DEPENDENT_SWITCH((FCT_CFG_LOHP_COMPONENT && (FCT_CFG_ACT_CODE_VERSION==SWITCH_OFF)), SWITCH_ON)

/*! FCT support for ACC CAL (Common ACC Library) sub-component if ((FCT_CFG_ACC_LANE_ASSOCIATION) || (FCT_CFG_ACC_OOI) || (FCT_CFG_ACC_OUTPUT) || (FCT_CFG_ACC_SITUATION)) */
#define FCT_CFG_ACC_CAL                           SWITCH_ON

/*! @brief Configuration switch for enabling FCT_LONG processing */
#define FCT_CFG_LONG_PROCESSING                   SWITCH_ON

/*! Activate use of SWITCH function library */
/* @todo : Find a clean position where to put the switch tool */
#define FCT_CFG_BUTTON_SWITCH_EVALUATION          SWITCH_ON

/*! FCT activate Side Rear Functionality */
#define FCT_CFG_SHORT_RANGE_FUNCTIONS             SWITCH_OFF

/***********************DW ADDED*************************/

/*! FCT DW sub-component activation switch */
#define FCT_CFG_DW_PROCESSING                    SWITCH_OFF

/*! FCT DW sub-component activation switch for QM task mode*/
#define FCT_CFG_DW_PROCESSING_QM                    SWITCH_OFF

/******************************************************/

/* activates the checking of input measurement counters */
#define FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING   SWITCH_OFF

/*! activates the calculation of pedestrian preselection in CD */
#define FCT_CFG_COLLISION_DETECTION_PEDPRESEL     SWITCH_OFF

/*! Configuration switch to enable override via XCP */
#define FCT_CFG_EBA_HEAD_ALLOW_XCP_OVERRIDE           SWITCH_OFF


/*! Configuration switch to enable ignoring distance safety check */
#define FCT_CFG_EBA_HEAD_IGNR_SFTY_CHECK              SWITCH_OFF

/*! FCT support for TCI module */
#ifdef TCI_CFG_ENABLE
#define FCT_CFG_TCI                               FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_SLATE_COMPONENT) && (FCT_CFG_LOPC_COMPONENT) && (TCI_CFG_ENABLE)), SWITCH_OFF)
#else
#define FCT_CFG_TCI                               SWITCH_OFF
#endif

/*****************************************************************************
  Config: SLATE RTE 
*****************************************************************************/
/*! Configuration switch enabling simple navi input data to FCT_SEN */
#define FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE         SWITCH_OFF

/*! Configuration switch enabling camera lane input data to FCT_SEN */
#define FCT_CFG_SEN_CAM_LANE_INTERFACE            SWITCH_ON

/*! FCT switch for ACC Performance Monitoring (APM) */
#define FCT_CFG_ACC_PERF_MONITORING               SWITCH_ON

/*! Config switch for using Traces computed in EM, ATTENTION this is mutually exclusive with SLATE_CFG_USE_FCT_STATIC_TRACES */
#define FCT_CFG_USE_EM_MOVING_OBJECT_TRACES       SWITCH_OFF//FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_INPUT_PREPROCESSSING, SWITCH_OFF)



/*****************************************************************************
  Config: Global Interfaces
*****************************************************************************/

/*! Special configuration switch to include all interfaces in request/provide
port structures, even if the current configuration does not use them. This 
enables the adapter to be unchanged, regardless of the application configuration*/
#define FCT_CFG_INCLUDE_UNUSED_INTF               SWITCH_OFF

/*! For including the fusion object list received from EM in the FCT Req Port */
#define FCT_CFG_INCLUDE_FUSION_OBJECT_LIST        SWITCH_ON

/*! Config switch to include TSA support interface in request port structure */
#if ((defined(TSA_SLATE_Input_INTFVER) && defined(TSA_SLATE_INPUT_ENABLE)) || (defined(CamSLAInputData_INTFVER) && (FCT_CFG_LONG_CTRL_SLA_SUPPORT)))
#define FCT_CFG_TSA_INTF                 SWITCH_OFF //ACTIVE
//#define FCT_CFG_TSA_INTF                 SWITCH_ON //BSW
#else
#define FCT_CFG_TSA_INTF                 SWITCH_OFF
#endif

/*! Switch for enabling Provide Port to TJA, this is placed here temporarily to enable compilation
    TODO : Move this to Rte_RadarBase_Type.h */
#if (defined(FCT_TJA_TARGET_OBJ_INTFVER))
#define FCT_CFG_SEN2TJA_ACC_OOI_PORT              SWITCH_ON
#else
#define FCT_CFG_SEN2TJA_ACC_OOI_PORT              SWITCH_OFF
#endif
/*****************************************************************************
  Config: Global Feature Switches
*****************************************************************************/

//TODO Interfaces should be mainly controlled by RTE => add flags to RTE and reuse them internally;

/*! Switch to enable blockage state preservation over ignition cycles  */
#define FCT_CFG_PRESERVE_BLOCKAGE_STATE_OVER_IGNITION   SWITCH_OFF

/*! Switch that enables signal status input check*/
#define FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK     SWITCH_OFF

/*!  brief Switch that enables the DEM reporting towards Service Interface */
//#define FCT_CFG_USE_DEM                           SWITCH_OFF

/*!  brief Switch that enables the FCT Base Control Data struct and disables the OPMode-port */
#define FCT_CFG_USE_BASECTRLDATA                  SWITCH_OFF

/*! Switch that enables the FCT Control Data struct and disables the OPMode-port */
#define FCT_CFG_USE_CTRLDATA                      SWITCH_ON

/*! FCT switch to enable the generic Signal Header in Interfaces */
#define FCT_CFG_USE_SIG_HEADER                    SWITCH_ON

/*!  brief FCT switch to enable the braking decision by second sensor confirmation */
#define FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION       SWITCH_OFF

/*! Max Distance to Object and min Object Quality to keep Object Quality high*/
#define FCT_CFG_EBA_KEEP_QUALITY_NEAR_RANGE       SWITCH_ON

/*! Enable eba object high quality life time */
#define FCT_CFG_EBA_USE_HIGH_QUALITY_LIFETIME     SWITCH_ON

/*! FCT switch to use third parameter in Exec methods to call the Function. 
Third parameter is a struct to service functions provided b y the Frame. */
#define FCT_CFG_USE_SERVICE_POINTER_FUNCTS        SWITCH_OFF

/*! FCT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers */
#define FCT_CFG_RUNTIME_MEAS                  FCT_CFG_SWITCH_RADAR(FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_USE_SERVICE_POINTER_FUNCTS, SWITCH_ON))

/*! FCT switch to enable setting of Measfreeze Cylce Start Service (currently NOT available in radar projects) */
#define FCT_CFG_USE_FREEZE_CYCLE_START            FCT_CFG_SWITCH_CAMERA(FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_USE_SERVICE_POINTER_FUNCTS, SWITCH_ON))

/*! Switch that enables the DEM reporting towards Service Interface (currently NOT available in radar projects) */
#define FCT_CFG_USE_DEM                           FCT_CFG_SWITCH_CAMERA(FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_USE_SERVICE_POINTER_FUNCTS, SWITCH_OFF))

/*! Road estimation input to FCT */
#define FCT_CFG_ROAD_INPUT                        SWITCH_ON

/*!  brief FCT error output from FCT_SEN */
#define FCT_CFG_ERROR_OUTPUT_SEN                  SWITCH_ON

/*!  brief FCT error output from FCT_VEH */
#define FCT_CFG_ERROR_OUTPUT_VEH                  SWITCH_ON

/*! Configuration switch enabling the passing of algo parameters to the FCT
component. This should be enabled, if the SW environment provides this
information */
#define FCT_CFG_BSW_ALGO_PARAMS                   SWITCH_ON

/*! Configuration switch enabling usage of the FCT Coding Parameters Port */
#define FCT_CFG_CPAR_PARAMS                       SWITCH_ON

/*! Configuration switch enabling usage of the FCT LKS Coding Parameters Port */
#define FCT_CFG_LKS_CPAR_PARAMS                   SWITCH_OFF

/*! Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module) */
#define FCT_CFG_VEH_HMI_INTERFACE                 FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_DRIVER_INTENTION_MONITORING, SWITCH_OFF)

/*! FCT configuration switch to enable VehSig as input to FCT_VEH */
#define FCT_VEH_CFG_VEH_SIG_INPUT                 SWITCH_ON

/*! FCT uses direct access to vehicle signals 
 @todo : Find a better name, since this is only for FCT_SEN. Clarification with
long control enabled SW projects necessary (ARS355, ARS4D1) */
#define FCT_SEN_CFG_VEH_SIG_INPUT                 SWITCH_OFF

/*! FCT CD sub-component custom output interface */
#define FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE        SWITCH_ON

/*! FCT custom I/O interface */
#define FCT_CFG_CUSTOM_IO_INTERFACE               SWITCH_ON

/*! Customer Specific MSA Object */
#define FCT_CFG_CD_MSA_SELECTION                  SWITCH_OFF

/*! Configuration switch enabling DIMOutputCustom to FCT_SEN */
#define FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT   SWITCH_OFF

/*! Enable Interface for Traces */
#define FCT_CFG_NEW_TRACES_INTERFACE              SWITCH_OFF//(NEW_TRACES) /* To NOT be switched on */

/*! Configuration switch enabling mapping of certain parameters from ROM
area to RAM in order to allow target calibration (RAM tunable). 0 => ROM, 
 1 => RAM  memory mapping */
#define FCT_CFG_ENABLE_RAM_PARAM                  SWITCH_ON

/*! FCT absolute kinematic data in custom interface */
#define FCT_CFG_CUSTOM_IO_ABS_KINEMATIC           SWITCH_ON

#ifdef FCT_SIMU
/*! Configuration switch for enabling simulation profiling
@todo: Currently only needed, since PDO-tags in fct_sim.h for simulation
only need to be parsed (i.e.: included by a C file). In the long run, add
a simulation-only C source for this kind of issue */
#define FCT_CFG_SIMU_PROFILING                    SWITCH_ON
#endif

/*! Configuration switch for enabling profiling on ECU */
#ifdef FCT_SIMU
#define FCT_CFG_RTA_PROFILING                    SWITCH_OFF
#else
#define FCT_CFG_RTA_PROFILING                    SWITCH_OFF
#endif

/*! Configuration switch for enabling the check of SigHeaders */
#define FCT_CFG_ACTIVATE_SIGHEADER_CHECK          SWITCH_OFF

/*! Configuration switch for enabling the AlgoCompstate interface */
#define FCT_CFG_USE_ALGOCOMPSTATE                 SWITCH_OFF

/*! Configuration switch enabling passing of static vehicle parameters (VehPar_t)
to FCT_VEH. Currently needed by long controllers LODM sub-component. */
#define FCT_VEH_CFG_VEH_PAR_INPUT                 (FCT_CFG_LOPC_COMPONENT)

/*! Configuration switch to enable the usage of LoDMC output variables in FCT VEH task */
#define FCT_VEH_CFG_USE_LODMC_OUTPUT              FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LODMC_COMPONENT, SWITCH_OFF) //active
//#define FCT_VEH_CFG_USE_LODMC_OUTPUT              FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_LODMC_COMPONENT, SWITCH_ON)  //BSW
/*! Configuration switch to enable the usage of EBA signals in LOPC/KMC */
#define FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION, SWITCH_OFF) //active
//#define FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT        FCT_CFG_DEPENDENT_SWITCH(FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION, SWITCH_ON) //BSW

/*! FCT veh custom input interface */
#define FCT_VEH_CFG_CUSTOMINPUT                   (SWITCH_ON)

/*! FCT veh custom output interface */
#define FCT_VEH_CFG_CUSTOMOUTPUT                    SWITCH_OFF //(FCT_CFG_LOPC_COMPONENT)

/*!  @brief Configuration switch for enabling BusDebugMessages */
#define FCT_CFG_USE_BUS_DEBUG                       SWITCH_OFF

/* try to calc a more safe value due to variances for values */
#define FCT_USE_KINEMATIC_STDDEV                    SWITCH_OFF

/*! Configuration switch enabling custom post-processing function call after all other
FCT_SEN processing has taken place */
#define FCT_SEN_CFG_CUSTOM_POST_PROC                SWITCH_OFF

/*! Configuration Switch for Cross Simulation D2_X_T0 (simulate ARS4T0 data in a ARS4D2 Sandbox) */
#define FCT_CFG_SIM_CROSS_D2_T0                    (FCT_SIMU && SWITCH_OFF)
/*! Configuration Switch for Cross Simulation D1_X_B0 (simulate ARS4B0 data in a ARS4D1 Sandbox) */
#define FCT_CFG_SIM_CROSS_D1_B0                    (FCT_SIMU && SWITCH_OFF)
/*! Configuration Switch for Cross Simulation D1_X_D0 (simulate ARS4D0 data in a ARS4D1 Sandbox) */
#define FCT_CFG_SIM_CROSS_D1_D0                    (FCT_SIMU && SWITCH_OFF)

/*! Configuration Switch for Speed Limit Assist (SLA) Feature activation */
/* SLA Config switch used only for provide ports */
#if ((defined(TSA_SLATE_INPUT_ENABLE) || defined( FCT_CFG_LONG_CTRL_SLA_SUPPORT)) && (defined(SLAData_INTFVER)))
#define FCT_CFG_SLA_FEATURE                         FCT_CFG_DEPENDENT_SWITCH(((FCT_CFG_TSA_INTF) && (FCT_CFG_LOPC_COMPONENT)), SWITCH_OFF)
#else
#define FCT_CFG_SLA_FEATURE                         SWITCH_OFF
#endif

/*****************************************************************************
  Config: Measurement Switches
*****************************************************************************/

/*! Activate Measurement Output Code */
#define FCT_MEASUREMENT                           SWITCH_ON

/*! Switch to Freeze FCTSenCtrlData from ECU code */
#define FCT_SEN_CFG_FREEZE_CTRL_DATA              FCT_CFG_SWITCH_CAMERA(SWITCH_ON)

/*! Switch to Freeze FCTVehCtrlData from ECU code */
#define FCT_VEH_CFG_FREEZE_CTRL_DATA              FCT_CFG_SWITCH_CAMERA(SWITCH_ON)

/*! Switches to make local copy of pointer interfaces and use callback measfreeze function */
/* use this functionality if output pointers are non constant (ringbuffer IPC) */
#define FCT_VEH_CFG_FREEZE_USE_CALLBACK           FCT_CFG_DEPENDENT_SWITCH(FCT_MEASUREMENT, SWITCH_OFF)

/* use this functionality if output pointers are non constant (ringbuffer IPC) */
#define FCT_SEN_CFG_FREEZE_USE_CALLBACK           FCT_CFG_DEPENDENT_SWITCH(FCT_MEASUREMENT, SWITCH_OFF)

/*! Activate Fuzzy Controller debugging for MTS simulation */
#define FCT_CFG_DEBUG_FUZZY_CONTROLLER            SWITCH_OFF

/*****************************************************************************
  Config: Technology Specific Switches RADAR
*****************************************************************************/

/*
  Config: Technology dependent interfaces
**************************************************************************/

/*! RSP Context data as input to FCT */
#define FCT_CFG_RSP_CONTEXT_INPUT                 FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! FCT has access to RSP output PD signal */
#define FCT_CFG_RSP_OUTPUT_PD                     FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! FCT camera object/lane detection inputs */
#define FCT_CFG_CAMERA_OBJECT_DETECTION           FCT_CFG_SWITCH_RADAR(CFG_CAMERA_RADAR_FUSION)

/*! FCT configuration switch to enable EM_CLD_Output as input to FCT_SEN */
#define FCT_SEN_CFG_EM_CLD_INPUT                  FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH */
#define FCT_VEH_CFG_EM_CLD_INPUT                  FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! FCT alignment information input to FCT_SEN */
#define FCT_CFG_ALIGNMENT_MONITORING_INPUT        FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*! FCT alignment information input to FCT_VEH */
#define FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT    FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*! FCT sensor control interface */
#define FCT_CFG_SENSOR_CONTROL_INTF               FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! Configuration switch enabling PerfDegrExtInput_t type input to FCT_SEN */
#define FCT_CFG_PERF_DEGR_EXT_INPUT               FCT_CFG_SWITCH_RADAR(SWITCH_OFF)


/*
  Config: Technology dependent Feature Switches
**************************************************************************/

/*! Configuration switch enabling range gate resolution setting based
on relevant object. Note: if disabled (0), then range get resolution is
determined based on ego speed */
#define FCT_CFG_RANGE_GATE_RES_REL_OBJ_DEP            FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*! Configuration switch enabling processing of longitudinal control status
within FCT custom I/O interface (enabled over FCT_CFG_CUSTOM_IO_INTERFACE) */
#define FCT_CFG_CUSTOM_IO_LONG_CTRL_STATUS            FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*! Configuration switch enabling power reduction in stand-still */
#define FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL  FCT_CFG_SWITCH_RADAR(SWITCH_OFF)

/*! Configuration switch enables EM-Generic_Object list and disables ObjectList_t */
#define FCT_USE_EM_GENERIC_OBJECT_LIST                SWITCH_ON

/*! Configuration switch enabling EM custom object list */
#define FCT_USE_EM_CUSTOM_OBJECT_LIST                 FCT_CFG_SWITCH_RADAR(FCT_USE_EM_GENERIC_OBJECT_LIST)

/*! Configuration switch that enables ARS-technology specific object list */
#define FCT_USE_EM_ARS_TECH_OBJECT_LIST               FCT_CFG_SWITCH_RADAR(FCT_USE_EM_GENERIC_OBJECT_LIST)

/*! Configuration switch that enables Camera-technology specific object list */
#define FCT_USE_EM_CAM_TECH_OBJECT_LIST               FCT_CFG_SWITCH_CAMERA(FCT_USE_EM_GENERIC_OBJECT_LIST)

/*! Override EBA modes in simulator frame - @todo: check if best location for switch */
#define FCT_VEH_SIM_CFG_OVERRIDE_EBA_MODE             SWITCH_ON

/*****************************************************************************
  Config: Deprecated
*****************************************************************************/
/*! Object list processing interface input/output */
#define FCT_CFG_OBJECT_LIST_PROC                  SWITCH_ON

/*! FCT input EM/FCT cycle-mode (ARS3xx specific) */
#define FCT_CFG_EM_FCT_CYCLEMODE                  FCT_CFG_SWITCH_RADAR(SWITCH_ON)

/*! FCT configuration for debugging input of mobil-eye data (only meas output) */
#define FCT_CFG_ME_INPUT_FOR_DEBUG                FCT_CFG_SWITCH_RADAR(SWITCH_OFF)  /*FCT_CFG_CAMERA_OBJECT_DETECTION*/

/*****************************************************************************
  Config: Review, currently not in use
*****************************************************************************/

/*! enable Truck specific CMS Level calculation and stationary object selection on static course  (FCT_CD)*/
#define FCT_CFG_TRUCK_CMS_LEVEL                   SWITCH_OFF

/*! enable Truck specific pedestrian CMS level calculation in FCT_CD */
#define FCT_CFG_TRUCK_CMS_PED_LEVEL               SWITCH_OFF

/*! Enable legacy CAM interface. Switch is only a workaround and should be removed as soon as possible*/
#define FCT_CFG_CAM_LEGACY_INTERFACE              SWITCH_OFF



/************************************************************************
  Config: External object ID
**************************************************************************/

/*! Configuration switch to enable SI external object ID assignment */
#define FCT_SEN_CFG_USE_EXT_OBJ_ID                SWITCH_ON

#if (FCT_SEN_CFG_USE_EXT_OBJ_ID)
/*! Configuration switch to enable 1-1 mapping between internal ID
and external ID, simply counting up modulo EM_N_OBJECTS with the
external ID */
#define FCT_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO   1

/*! Configuration switch to enable assignment age based tracking of
external IDs (this means the object that has not been OOI for the
longest time will have it's ID removed if all external IDs are exhausted */
#define FCT_CFG_EXT_ID_ASSIGN_AGE_TRACKING        0

/*! Configuration switch, when not set, only the objects that are in the
OOI list get external object IDs assigned. Otherwise when set all tracked
objects get external object IDs assigned */
#define FCT_CFG_ASSIGN_EXT_OBJ_ID_FOR_ALL_OBJS    0

/*! Configuration switch enabling external ID assignment to all objects
that get a CD hypothesis assigned */
#define FCT_CFG_ASSIGN_EXT_ID_CD_HYPOTHESIS       0

#endif


/************************************************************************
  Config: Port Type Configuration for Components inside FCT frame
**************************************************************************/

/*! Size of Control Preferences Deceleration Curve */
#define ACT_CFG_CP_DEC_CRV_SIZE                                         (2u)

/*! Number of targets for every <TargetFollowControl> Port */
#define ACT_CFG_TFC_PORT_TRG_CNT                                        (6u)

/*! Number of segments for every <DistanceSpeedControl> Port */
#define ACT_CFG_DSC_PORT_SEG_CNT                                        (8u)

/*! Number of segments for every <DistanceCurveControl> Port */
#define ACT_CFG_DCC_PORT_SEG_CNT                                        (8u)

/*****************************************************************************
  Config: LoXYZ (Function Component) <=> LoPC (Longitudinal Planner and Controller)
*****************************************************************************/

/*! Number of <VehicleSpeedControl> Ports for LoCC component */
/*! First Port is assigned to CruiseControl */
/*! Second Port is assigned to CurveControl */
#define ACT_CFG_CC_VSC_PORT_CNT                                        (2u)

/*! Number of <VehicleSpeedControl> Ports for LoSLA component */
#define ACT_CFG_SLA_VSC_PORT_CNT                                       (0u)

/*! Number of <DistanceSpeedControl> Ports for LoSLA component */
#define ACT_CFG_SLA_DSC_PORT_CNT                                       (0u)

/*! Number of <DistanceCurveControl> Ports for LoCP (CurvePlanner) component */
#define ACT_CFG_CP_DCC_PORT_CNT                                        (0u)

/*! Number of <TargetFollowControl> Ports for LoHP (HeadwayPlanner) component */
#define ACT_CFG_HP_TFC_PORT_CNT                                        (6u)

/*! Switch ON to handle allocation and freeze of the static memory internally in ACDC.
    If this switch is OFF the memory and freezes have to be handled outside of ACDC.
    As long as the FCT Frame is used memory and freezes are handled there.*/
#define FCT_CFG_USE_ACDC_INTERNAL_MEMORY                               (SWITCH_OFF)

/*! Switch ON to handle allocation and freeze of the static memory internally in MEDIC.
    If this switch is OFF the memory and freezes have to be handled outside of MEDIC.
    As long as the FCT Frame is used memory and freezes are handled there.*/

#define FCT_CFG_USE_MEDIC_INTERNAL_MEMORY                               (SWITCH_OFF)

#endif
/** @} end defgroup */
