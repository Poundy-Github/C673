/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               slate_obj_main.c

DESCRIPTION:               Main functions for Adaptive Cruise Control (ACC) object evaluation module in SLATE task

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.54 $

LEGACY VERSION:            Revision: 2.3

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

//#include "fct_sen.h"
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Doesnot have any effect on functionality  */
#include "slate.h" /*  PRQA S 0380 */
#include "slate_types.h"

#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
// Neede for memset
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup frame_main Main
@ingroup frame
@brief          This module provides amongst others the main function of the SLATE Component. \n\n

@description    The following functionalities are provided by this module:
                - Main function of the SLATE Component which calls the main routines of all subcomponents: @ref SLATE_v_Exec.
                - Setting of the OpMode of the SLATE Component: @ref SLATE_v_SetOperationMode.
                - Determination of the runtime of the SLATE Component: @ref FCTSEN_SLATE_SERVICE_ADD_EVENT.
@{
*/

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/

/*! Fame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(t_SLATEFrame)
SLATEFrame_t t_SLATEFrame;

/* Meas freeze reference */
SET_MEMSEC_VAR(t_SLATESyncRef)
SLATESyncRef_t t_SLATESyncRef;

///*! Fct sen ACC and it's subcomponents initialization status */
//SET_MEMSEC_VAR(b_FCTSenSLATEIsInitialized)
//boolean b_FCTSenSLATEIsInitialized = FALSE;

/* distance from Bumper to Center of Gravity */
SET_MEMSEC_VAR(FCT_fBumperToCoG)
float32 FCT_fBumperToCoG;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(pSLATE_ServiceFuncts)
const AS_t_ServiceFuncts *pSLATE_ServiceFuncts;
#endif

SET_MEMSEC_VAR(t_SLATEPortHandlerList)
  SLATEPortHandlerList_t                 t_SLATEPortHandlerList;

/* Pointers to the input/output data of the FCT component */
SET_MEMSEC_CONST(pSLATE_SenCtrlData)
#if (FCT_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t        * pSLATE_SenCtrlData;        /*!< FCT control data */
#else
  const FCTCtrlData_t         * pSLATE_SenCtrlData;        /*!< FCT control data */
#endif
SET_MEMSEC_CONST(pSLATE_EgoDynObjSync)
const VehDyn_t                * pSLATE_EgoDynObjSync;/* PRQA S 2200 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning is suppressed as Indentation does not have any critical impact  on the functionality. */ 
SET_MEMSEC_CONST(pSLATE_EgoDynRaw)
const VehDyn_t                * pSLATE_EgoDynRaw;          /*!< The dynamic vehicle ego data raw */ 
SET_MEMSEC_CONST(pSLATE_EgoStaticData)
const VehPar_t                * pSLATE_EgoStaticData;      /*!< the static vehicle ego data */

#if (FCT_CFG_EM_FCT_CYCLEMODE)
SET_MEMSEC_CONST(pSLATE_EmFctCycleMode)
const EmFctCycleMode_t        * pSLATE_EmFctCycleMode;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
SET_MEMSEC_CONST(pSLATE_EmGenObjList)
const EM_t_GenObjectList      * pSLATE_EmGenObjList;
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
SET_MEMSEC_CONST(pSLATE_EmCustObjList)
const EM_t_ObjectList_Custom  * pSLATE_EmCustObjList;
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(pSLATE_EmARSObjList)
const EM_t_ARSObjectList      * pSLATE_EmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
SET_MEMSEC_CONST(pSLATE_EmCamObjList)
const EM_t_CamObjectList      * pSLATE_EmCamObjList;
#endif
#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
SET_MEMSEC_CONST(pSLATE_MovObjTraces)
const MovingObjectTraces_t    * pSLATE_MovObjTraces;
#endif /* SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES */
#endif /* FCT_CFG_OBJECT_LIST_PROC */

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
SET_MEMSEC_CONST(pSLATE_PerfDegrData)
const PerfDegr_t              * pSLATE_PerfDegrData;
#endif /* FCT_CFG_SIGNAL_PERF_MONITORING */

#if (FCT_CFG_ROAD_INPUT)
SET_MEMSEC_CONST(pSLATE_RoadData)
const Road_t                  * pSLATE_RoadData;
#endif

#if (FCT_CFG_RSP_CONTEXT_INPUT)
SET_MEMSEC_CONST(pSLATE_RSPContextData)
const RSPKontextData_t        * pSLATE_RSPContextData;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/* customer specific input/output */
SET_MEMSEC_CONST(pSLATE_CustomInput)
const FCTCustomInput_t        * pSLATE_CustomInput;
#endif

#if (FCT_CFG_CAMERA_OBJECT_DETECTION)
SET_MEMSEC_CONST(pSLATE_CameraObjData)
const EM_t_ObjectList_Custom  * pSLATE_CameraObjData;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_CONST(pSLATE_AlignmentMonInput)
const ALN_S_Monitoring_t      * pSLATE_AlignmentMonInput; /*!< Alignment monitoring output data */
#endif

#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
SET_MEMSEC_CONST(pSLATE_ME_in)
const ME_in_t                 * pSLATE_ME_in;            /*!< FCT mobil-eye input */
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
SET_MEMSEC_CONST(pSLATE_BswAlgoParameters)
const BSW_s_AlgoParameters_t  * pSLATE_BswAlgoParameters; /*!< Input algo parameters from BSW */
#endif

#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE)
SET_MEMSEC_CONST(pSLATE_NaviData)
const t_NaviInputData         * pSLATE_NaviData;           /*!< Simple navi input data */
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
SET_MEMSEC_CONST(pSLATE_FusionObjList)
  const EM_t_FusionObjectList  * pSLATE_FusionObjList;     /*! EM Fusion Object List */
#endif

#if (SLATE_CFG_CAM_LANE_INTERFACE)
SET_MEMSEC_CONST(pSLATE_CamLaneData)
const t_CamLaneInputData      * pSLATE_CamLaneData;        /*!< Camera lane input data */
#endif

#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER))
SET_MEMSEC_CONST(pSLATE_TSAInputData)
const TSA_SLATE_Input_t  * pSLATE_TSAInputData;            /*!< Required port pointer, TSA input data from camera */
#elif (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER))
SET_MEMSEC_CONST(pSLATE_CamSLAInputData)
const CamSLAInputData_t   * pSLATE_CamSLAInputData;       /*!< Required port pointer, SLA input data from camera */
#endif

#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
SET_MEMSEC_CONST(pSLATE_LongCtrlResp)
const LongCtrlInput_t  * pSLATE_LongCtrlResp;             /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /*(FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)*/


/* Provide ports */

#if (FCT_CFG_LOHP_COMPONENT)
SET_MEMSEC_VAR(pSLATE_HC_Data)
SLATE_HC_Data_t * pSLATE_HC_Data;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
SET_MEMSEC_VAR(pSLATE_SPM_Data)
SLATE_SPM_Data_t *       pSLATE_SPM_Data;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
SET_MEMSEC_VAR(pSLATE_CD_Data)
SLATE_CD_Data_t *       pSLATE_CD_Data;
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(pSLATE_SenCompState)
AlgoCompState_t             * pSLATE_SenCompState;
#endif

#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
/* TJA ooi object data */
SET_MEMSEC_VAR(pSLATE_TJAOOIData)
  TJATargetObj_t * pSLATE_TJAOOIData;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
SET_MEMSEC_VAR(pSLATE_PubFctObjList)
AssessedObjList_t           * pSLATE_PubFctObjList;
#endif
#endif /* FCT_CFG_OBJECT_LIST_PROC */

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
/* customer specific output */
SET_MEMSEC_VAR(pSLATE_CustomOutput)
FCTCustomOutput_t             * pSLATE_CustomOutput;
#endif

#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
SET_MEMSEC_VAR(pSLATE_ErrorOut)
SLATEErrorOutProPort_t             * pSLATE_ErrorOut;
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
//BusDebugData_t              * pFCTSenBusDebugData; /*!< Debug data */
SET_MEMSEC_VAR(pSLATE_FCTSenBusDebugData)
BusDebugData_t             * pSLATE_FCTSenBusDebugData;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
SET_MEMSEC_VAR(pSLATE_AccOOIData)
FCTSenAccOOI_t             * pSLATE_AccOOIData;
#endif
#if (FCT_CFG_SLA_FEATURE)
SET_MEMSEC_VAR(pSLATE_SLAData)
SLAData_t                 * pSLATE_SLAData;               /*!< Provide port pointer, SLA speed limit data from SLATE */
#endif


#if (FCT_CFG_RUNTIME_MEAS)
/*! FCT ACC time measurement info */
SET_MEMSEC_VAR(t_SLATERuntimeInfo)
SLATERuntimeInfo_t t_SLATERuntimeInfo;
#endif

#if (FCT_CFG_RUNTIME_MEAS)
/* Meas freeze structure for FCT ACC runtime info */ 
SET_MEMSEC_VAR(t_SLATERuntime_MeasInfo)
static const MEASInfo_t t_SLATERuntime_MeasInfo = {// PRQA S 3207
  /* date: 2017-11-02, reviewer: Dyuthi Varier, reason: currently the variable is not used, but may be used in future.*/
  FCT_MEAS_ID_ACC_RUNTIME_DEBUG,      /* VirtualAddress */
  sizeof(SLATERuntimeInfo_t),      /* Length */
  FCT_ACC_MEAS_FUNC_ID,               /* FuncID */
  FCT_ACC_MEAS_FUNC_CHAN_ID           /* FuncChannelID */
};
#endif

/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/
/*! Definition of merge delete object information */
/* Merge Delete Object List */
FCTSen_MergeDeleteList_t t_FCTSen_MDObjList;

/*! Definition of ACC component outputs */
/*! ACC_FIP output structures */
#if (FCT_CFG_INPUT_PREPROCESSSING)
/*! Definition of FIP ALL output structure which is filled in this component */
SET_MEMSEC_VAR(t_FIP_ALL_Output) 
FIP_ALL_Output_t t_FIP_ALL_Output;
#endif /* END IF FCT_CFG_INPUT_PREPROCESSSING */

/*! Definition of CP Output structure which is filled in this component */
#if (FCT_CFG_COURSE_PREDICTION)
SET_MEMSEC_VAR(t_CP_Output)
CPOutput_t t_CP_Output;
#endif /* END IF FCT_CFG_COURSE_PREDICTION */

/*! ACC LA output structures*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*! Definition of LA output structure which is filled in this component */
SET_MEMSEC_VAR(t_LA_Output) 
LAOutput_t t_LA_Output;
#endif /* END IF FCT_CFG_ACC_LANE_ASSOCIATION */

/*! ACC OOI output structure */
#if (FCT_CFG_ACC_OOI)
/*! Definition of OOI output structure which is filled in this component */
SET_MEMSEC_VAR(t_OOI_Output)
OOIOutput_t t_OOI_Output;
#endif /* END IF FCT_CFG_ACC_OOI */

/*! ACC OUT output structures */
#if (FCT_CFG_ACC_OUTPUT)
/*! Definition of OUT output structure which is filled in this component */
SET_MEMSEC_VAR(t_OUTOutput)
OUTOutput_t t_OUTOutput;
#endif /* END IF FCT_CFG_ACC_OUTPUT */

/*! ACC_SIT output structures */
#if (FCT_CFG_ACC_SITUATION)
/*! Definition of SIT output structure which is filled in this component */
SET_MEMSEC_VAR(t_SITOutput)
SITOutput_t t_SITOutput;
#endif /* END IF FCT_CFG_ACC_SITUATION */

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES - Device Freezes
*****************************************************************************/
#if (FCT_CFG_ACC_SITUATION)
/*! SIT Device meas info */
SET_MEMSEC_VAR(SIT_DeviceMeasInfo)
#ifndef FASTSIM
#ifdef ALGO_ALIGNED_4
       ALGO_ALIGNED_4 static SIT_t_DeviceMeasInfo SIT_DeviceMeasInfo;
#else
       static SIT_t_DeviceMeasInfo SIT_DeviceMeasInfo;
#endif
#else
       SIT_t_DeviceMeasInfo SIT_DeviceMeasInfo;
#endif
/* Structure for SIT device meas freeze */
static const MEASInfo_t SIT_DeviceMeasInfoFreeze =// PRQA S 3218, 2200
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_SIT_DEVICE,            /*!<.VirtualAddress */
  sizeof(SIT_DeviceMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif /* END IF FCT_CFG_ACC_SITUATION */

#if (FCT_CFG_INPUT_PREPROCESSSING)
SET_MEMSEC_VAR(FIP_DeviceMeasInfo)

#ifndef FASTSIM
#ifdef ALGO_ALIGNED_4
       ALGO_ALIGNED_4 static FIP_DeviceMeasInfo_t FIP_DeviceMeasInfo;
#else
       static FIP_DeviceMeasInfo_t FIP_DeviceMeasInfo;
#endif
#else
       FIP_DeviceMeasInfo_t FIP_DeviceMeasInfo;
#endif
/* Structure for FIP device meas freeze */
static const MEASInfo_t t_FIP_DeviceMeasInfoFreeze =// PRQA S 3218
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_FIP_DEVICE,            /*!<.VirtualAddress */
  sizeof(FIP_DeviceMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif /* FCT_CFG_INPUT_PREPROCESSSING */

#if (FCT_CFG_COURSE_PREDICTION)
/*! CP Device meas info */
SET_MEMSEC_VAR(CP_DeviceMeasInfo)
#ifndef FASTSIM
#ifdef ALGO_ALIGNED_4
       ALGO_ALIGNED_4 static CP_t_DeviceMeasInfo CP_DeviceMeasInfo;
#else
       static CP_t_DeviceMeasInfo CP_DeviceMeasInfo;
#endif
#else
       CP_t_DeviceMeasInfo CP_DeviceMeasInfo;
#endif

/* Structure for CP device meas freeze */
static const MEASInfo_t CP_DeviceMeasInfoFreeze =// PRQA S 3218
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_CP_DEVICE,            /*!<.VirtualAddress */
  sizeof(CP_DeviceMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif /* END IF FCT_CFG_COURSE_PREDICTION */


#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*! LA Device meas info */
SET_MEMSEC_VAR(t_LA_DeviceMeasInfo)
#ifdef ALGO_ALIGNED_4
       ALGO_ALIGNED_4 static LA_DeviceMeasInfo_t t_LA_DeviceMeasInfo;
#else
       static LA_DeviceMeasInfo_t t_LA_DeviceMeasInfo;
#endif

/* Structure for LA device meas freeze */
static const MEASInfo_t t_LA_DeviceMeasInfoFreeze =// PRQA S 3218
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_LA_DEVICE,            /*!<.VirtualAddress */
  sizeof(t_LA_DeviceMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif /* END IF FCT_CFG_ACC_LANE_ASSOCIATION */


#if (FCT_CFG_ACC_OUTPUT)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
/* Structure for Public Object List (carried out in OUT) freeze */
static const MEASInfo_t t_OUT_PubObjListMeasInfoFreeze =// PRQA S 3218
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_PUBLIC_OBJECT_LIST,       /*!<.VirtualAddress */
  sizeof(AssessedObjList_t),          /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif

/*! OUT Device meas info */
SET_MEMSEC_VAR(OUT_DeviceMeasInfo)
#ifndef FASTSIM
#ifdef ALGO_ALIGNED_4
       ALGO_ALIGNED_4 static OUT_DeviceMeasInfo_t OUT_DeviceMeasInfo;
#else
       static OUT_DeviceMeasInfo_t OUT_DeviceMeasInfo;
#endif
#else
       OUT_DeviceMeasInfo_t OUT_DeviceMeasInfo;
#endif

/* Structure for OUT device meas freeze */
static const MEASInfo_t t_OUT_DeviceMeasInfoFreeze =// PRQA S 3218
/* date: 2017-11-02, reviewer: Dyuthi Varier, reason: static local required for saving data across function calls */
{
  FCT_MEAS_ID_OUT_DEVICE,            /*!<.VirtualAddress */
  sizeof(OUT_DeviceMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,                 /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID             /*!<.FuncChannelID */
};
#endif /* END IF FCT_CFG_ACC_OUTPUT */

/*****************************************************************************
  MODULE LOCAL VARIABLES - Simulation Freezes
*****************************************************************************/

/*! CP Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(CP_SimMeasInfo)
static CP_SimMeasInfo_t CP_SimMeasInfo;

/* Structure for CP simulation meas freeze */
static const MEASInfo_t t_CP_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_CP_SIM,            /*!<.VirtualAddress */
  sizeof(CP_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,              /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID          /*!<.FuncChannelID */
};
#endif

/*! FIP Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(FIP_SimMeasInfo)
static FIP_SimMeasInfo_t FIP_SimMeasInfo;

/* Structure for FIP simulation meas freeze */
static const MEASInfo_t t_FIP_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_FIP_SIM,            /*!<.VirtualAddress */
  sizeof(FIP_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,               /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID           /*!<.FuncChannelID */
};
#endif

/*! LA Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(LA_SimMeasInfo)
static LA_SimMeasInfo_t LA_SimMeasInfo;

/* Structure for LA simulation meas freeze */
static const MEASInfo_t t_LA_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_LA_SIM,            /*!<.VirtualAddress */
  sizeof(LA_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,              /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID          /*!<.FuncChannelID */
};
#endif

/*! OOI Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(OOI_SimMeasInfo)
static OOI_SimMeasInfo_t OOI_SimMeasInfo;

/* Structure for OOI simulation meas freeze */
static const MEASInfo_t t_OOI_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_OOI_SIM,            /*!<.VirtualAddress */
  sizeof(OOI_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,               /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID           /*!<.FuncChannelID */
};
#endif

/*! OUT Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(OUT_SimMeasInfo)
static OUT_SimMeasInfo_t OUT_SimMeasInfo;

/* Structure for OUT simulation meas freeze */
static const MEASInfo_t t_OUT_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_OUT_SIM,            /*!<.VirtualAddress */
  sizeof(OUT_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,               /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID           /*!<.FuncChannelID */
};
#endif

/*! SIT Simulation meas info */
#ifdef FCT_SIMU
SET_MEMSEC_VAR(SIT_SimMeasInfo)
static SIT_SimMeasInfo_t SIT_SimMeasInfo;

/* Structure for SIT simulation meas freeze */
static const MEASInfo_t t_SIT_SimMeasInfoFreeze =
{
  FCT_MEAS_ID_SIT_SIM,            /*!<.VirtualAddress */
  sizeof(SIT_SimMeasInfo),      /*!<.Length */
  FCT_MEAS_FUNC_ID,               /*!<.FuncID */
  FCT_MEAS_FUNC_CHAN_ID           /*!<.FuncChannelID */
};
#endif


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static void SLATE_v_PreProcessing(const reqSLATEPortList_t * pRequirePorts);

#if (FCT_CFG_RUNTIME_MEAS)
static void SLATE_v_RuntimeMeasInit(void);
#endif
#if (FCT_CFG_RUNTIME_MEAS)
#if (defined(RTA_INTERFACE_VERSION))
 #if (RTA_INTERFACE_VERSION >= 4)
static void SLATE_SERVICE_ADD_EVENT( const RTA_t_Events       t_RuntimeEvtType, const sint32 u_EventID);
 #else
static void SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID);
 #endif
#else
static void SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID);
#endif
#endif


static void SLATE_v_SetFrameData(FCTSenFrame_t * p_FCTSenFrame);

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void FCTSen_v_SLATESetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
static void SLATE_v_InitAssessedObjList(AssessedObjList_t * pFctObjList, AlgoSignalState_t eSigState);
#endif

static void SLATE_v_MergeDeleteObj( const EM_t_GenObjectList * pObjList);

#endif

static void SLATE_v_PostProcessing(const reqSLATEPortList_t * pRequirePorts, const provSLATEPortList_t * pProvidePorts); // ACC only

#if (FCT_CFG_USE_DEM)
static void SLATE_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus);
#endif /*FCT_CFG_USE_DEM*/

static void SLATE_v_SetupSyncRef(const reqSLATEPortList_t * pRequirePorts);
static void SLATE_v_SetSigHeaderError(SignalHeader_t * const pSigHeader);
static void SLATE_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void SLATE_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void SLATE_v_SetErrorProvidePorts (const provSLATEPortList_t * pProvidePorts);
#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
static void FCTSen_v_SLATECheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void FCTSen_v_ACCCheckProvideHeaders(reqSLATEPortList_t const * const pRequirePorts, provSLATEPortList_t const * const pProvidePorts);
#endif

/*! Initialize FCT_SEN SLATE provide ports */
static void SLATE_v_InitProvidePorts(provSLATEPortList_t * pt_ProvidePort);

static void SLATE_v_InitMergeDeleteLists(void);
/*! @endcond Doxygen_Suppress */
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    SLATE_v_Exec                                                                             */ /*!

  @brief           SLATE component main execution function for sensor data cycle

  @description     The main SLATE Routine is called by the main FCT function @ref FCTSen_Exec. It executes 
                   pointer checks for the require and provide ports and calls all SLATE subcomponents. \n
                   The require pointers are stored in global variables that can be accessed via inline 
                   functions that are defined in @ref slate_access_func.h.
                   @startuml 
                   Partition SLATE_v_Exec {
                   Start
                   If(Service function pointer is valid)then (Yes)
                   -Save service function pointer
                   Endif
                   #Orange:Init global FCT runtime measurement array:
                   <b>SLATE_v_RuntimeMeasInit</b> >
                   -Sends RTA-Start Event for whole procedure runtime 
                   #Orange:Fill the SLATE global frame 
                   Variable with the current data:
                   <b>SLATE_v_SetFrameData</b> >
                   
                   #Orange: Process external OpMode and set internal states:
                   <b>SLATE_v_ProcessStates</b> >
                   #Orange:Check and set up all ports,
                   fill port handler structure:
                   <b>SLATE_v_ProcessPorts</b> >
                   #Orange: setup sync ref no even if sync in running and non running mode:
                   <b>SLATE_v_SetupSyncRef</b> >
                   
                   if(SLATE State is NOT INITIALIZED or RUNNING ) then (No)
                   -call SLATE_v_InitProvidePorts function
                   - Send RTA-End Event for data preparation runtime in non-error state
                   - Send RTA-Start Event for data preprocessing runtime in non-error state
                   #Orange: Initialize FCT Merge Delete objects:
                   <b>SLATE_v_InitMergeDeleteLists</b> >
                   
                   #Orange: Execute SLATE PreProcessing:
                   <b>SLATE_v_PreProcessing</b> >
                   - Send RTA-End Event for data preprocessing runtime in non-error state
                   - Send RTA-Start Event for ACC Situation module runtime
                   - Pass reference freeze structures in INPUT to module
                   -call SIT_v_PreProcessPRE function
                   partition #LightBlue **FCT_CFG_ACC_SITUATION** {
                   #Orange:Call the SIT subcomponent:
                   <b>SIT_v_ProcessPRE</b> >
                   }
                   - Send RTA-End Event for ACC Situation module runtime
                   - Send RTA-Start Event for Course Prediction runtime
                   - Pass reference freeze structures in INPUT to module
                   -call CP_v_PreProcess function 
                   partition #LightBlue **FCT_CFG_COURSE_PREDICTION** {
                      #Orange:Call the CP subcomponent:
                      <b>CP_v_Process</b> >
                   }
                   - FCT ACC runtime measurement: Start event for FCT_ACC_TIME_LA
                   - Pass reference freeze structures in INPUT to module
                   - call LA_v_PreProcess function
                   partition #LightBlue **FCT_CFG_ACC_LANE_ASSOCIATION** {
                      #Orange: Call the LA subcomponent:
                      <b>LA_v_Process</b> >
                   }
                   - Storing outputs from LA to output ports
                   - FCT ACC runtime measurement: End event for FCT_ACC_TIME_LA
                   - FCT ACC runtime measurement: Start event for SLATE_RTA_OOI
                   - Pass reference freeze structures in INPUT to module
                   - call OOI_v_PreProcess function
                   partition #LightBlue **FCT_CFG_ACC_OOI** {
                      #Orange: Call the OOI subcomponent:
                      <b>OOI_v_Process</b> >
                   }
                   -Storing outputs from OOI to output ports
                   - FCT ACC runtime measurement: End event for SLATE_RTA_OOI
                   -Send RTA-Start Event for ACC Situation module runtime
                   partition #LightBlue **FCT_CFG_ACC_SITUATION** {
                      #Orange: Call the SIT subcomponent:
                      <b>SIT_v_ProcessPOST</b> >
                   }
                   -Storing outputs from SIT to output ports
                   -Send RTA-End Event for ACC Situation module runtime
                   -Add runtime for SIT PRE to runtime for SIT POST
                   - FCT ACC runtime measurement: Start event for SLATE_RTA_APM
                   partition #LightBlue **SLATE_CFG_ACC_PERF_MONITORING** {
                      #Orange: Call the APM subcomponent:
                      <b>APM_v_Process</b> >
                   }
                   -FCT ACC runtime measurement: End event for SLATE_RTA_APM
                   -Calculate external object ID
                   partition #LightBlue **FCT_CFG_ACC_OUTPUT** {
                   #Orange: Call the OUT subcomponent:
                   <b>OUT_v_Process</b> >
                   }
                   partition #LightBlue **POST_PROCESSING** {
                      #Orange: Call Post Processing:
                      <b>SLATE_v_PostProcessing</b> >
                   }
                   partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                      #Orange: Set Slate Comp State:
                      <b>FCTSen_v_SLATESetCompState</b> >
                   }
                   else(Yes)
                   -call SLATE_v_SetErrorProvidePorts function
                      #Orange:Initialize all SLATE specific data:
                      <b>SLATE_v_AlgoInit</b> >
                   partition #LightBlue **FCT_CFG_USE_ALGOCOMPSTATE** {
                      #Orange:Set the SLATE Component state:
                      <b>FCTSen_v_SLATESetCompState</b> >
                   }
                   endif
                   #Orange:Fill the signal headers of the provide ports:
                   <b>SLATE_v_FillProPortHeaders</b> >
                   partition #LightBlue **FCT_MEASUREMENT** {
                   #Orange:Freeze information for mts
                   <b>FCTSen_v_ACCProcessMeasFreeze</b> >
                   }
                   - Send RTA-End Event for Process Measfreeze runtime
                   - Send RTA-Start Event for Frame Measfreeze runtime
                   -Freeze frame meas data in all cases, even in case of Error
                   -call FCTSen_v_ACCFrameFreeze function
                   -Send RTA-End Event for Frame Measfreeze runtime
                   -Sends RTA-End Event for whole procedure runtime
                   - Freeze FCT ACC runtime info
                   Stop
                   }
                   @enduml


  @return          -

  @param[in]       pRequirePorts : The input data used by FCT component
  @param[in]       pProvidePorts : The output data provided by FCT component
                      Note: this is also used to store state information of FCT,
                      thus the same buffer shall be used or care should be taken
                      to copy data from previous cycle!
  @param[in]       pServiceFuncts : Service functions provided by the frame SW
  @param[in]       p_FCTSenFrame : FCT Frame data of current cycle
  @glob_in         FCTSenFrame : FCT frame data
                      SLATEOpMode  [FCT_OP_MODE_t as in fct_sen.h]
                      SLATEState   [FCTSenState_t as in fct_sen.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS : FCT switch to use third parameter in Exec methods to call the Function. 
                    Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_RTA_PROFILING : Configuration switch for enabling profiling on ECU
  @c_switch_part   FCT_CFG_USE_FREEZE_CYCLE_START : FCT switch to enable setting of Measfreeze Cycle Start Service
  @c_switch_part   FCT_CFG_COURSE_PREDICTION : FCT support for CP sub-component
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT uses direct access to vehicle signals
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_part   FCT_MEASUREMENT : Activate Measurement Output Code
                        FCT_SEN processing has taken place
  @c_switch_full   -

  @pre             FCT component initialized!
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         04.11.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void SLATE_v_Exec(const reqSLATEPortList_t * p_SLATERequirePorts, 
                        provSLATEPortList_t * p_SLATEProvidePorts,
                  const AS_t_ServiceFuncts *p_ServiceFuncts,
                        FCTSenFrame_t * p_FCTSenFrame)
#else
void SLATE_v_Exec(const reqSLATEPortList_t * p_SLATERequirePorts, 
                        provSLATEPortList_t * p_SLATEProvidePorts,
                        FCTSenFrame_t * p_FCTSenFrame)
#endif
{
  ObjNumber_t t_ObjNr;
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif

#if (FCT_CFG_RUNTIME_MEAS) && (FCT_CFG_ACC_SITUATION)
  uint32 u_SITRuntimeInfoPRE = 0u; /* Local variable to store runtime for SIT PRE processing */// Shang 17.02.2017 why this runtime was used and only for SIT. In ARS400PR it has not been used
#endif

  /*! Set memory for SLATE input structures */
  /*! Definition of CP Input structure */
#if (FCT_CFG_COURSE_PREDICTION)
  CPInputConst_t t_CPInput;
#endif
  /*! Definition of LA Input structure */
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  LAInputConst_t t_LAInput;
#endif /* END IF FCT_CFG_ACC_LANE_ASSOCIATION */

  /*! Definition of OOI Input structure */
#if (FCT_CFG_ACC_OOI)
  OOIInputConst_t t_OOI_Input;
#endif /* END IF FCT_CFG_ACC_OOI */

/*! Definition of SIT Input structure */
#if (FCT_CFG_ACC_SITUATION)
  SITInputConst_t t_SITInput;
  SITInputModify_t t_SITInputModify;
#endif /* END IF FCT_CFG_ACC_SITUATION */

/*! Definition of OUT Input structure */
#if (FCT_CFG_ACC_OUTPUT)
  OUTInputConst_t t_OUTInput;
#endif /* END IF FCT_CFG_ACC_OUTPUT */

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  if (p_ServiceFuncts != NULL)
  {
    pSLATE_ServiceFuncts = p_ServiceFuncts;
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  SLATE_v_RuntimeMeasInit();
#endif

  /* Sends RTA-Start Event for whole procedure runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */

  /*---------------------------------------------------------------------------*/
  /* Start data preparation                                                    */
  /*---------------------------------------------------------------------------*/

  /* Set the SLATE Frame Data for Sensor */
  SLATE_v_SetFrameData(p_FCTSenFrame);

  /************************************************************************/
  /*           Process external OpMode and set internal states            */
  /************************************************************************/
  SLATE_v_ProcessStates(t_SLATEFrame.SLATEOpMode);

  /************************************************************************/
  /*                  Process request and provide ports                   */
  /************************************************************************/
  SLATE_v_ProcessPorts( p_SLATERequirePorts, p_SLATEProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                      , p_ServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                      , &AlgoErrorBuffer
#endif
    );

   /* setup sync ref no matter what (sync in running and non running mode)*/
  SLATE_v_SetupSyncRef(p_SLATERequirePorts);
  if (   (t_SLATEFrame.SLATEState == COMP_STATE_NOT_INITIALIZED)
       ||(t_SLATEFrame.SLATEState == COMP_STATE_RUNNING ) )
  {
  /************************************************************************/
  /*                      Start of NON error path                         */
  /************************************************************************/
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_PREPRE_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    
    /* This function can be removed once the other components use these signals based on the signal state */
    /*! Init provide ports */
    SLATE_v_InitProvidePorts(p_SLATEProvidePorts);

    /* Send RTA-End Event for data preparation runtime in non-error state*/
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_PREPRE_PROCESS, 0u);/* PRQA S 4424 */
    /* Send RTA-Start Event for data preprocessing runtime in non-error state*/
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_PRE_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */

    /*---------------------------------------------------------------------------*/
    /* Start Pre-Processing (FCT)                                                */
    /*---------------------------------------------------------------------------*/
    /* Initialize FCT Merge Delete objects */
#if (FCT_CFG_OBJECT_LIST_PROC) 
    SLATE_v_InitMergeDeleteLists();
#endif /* END IF (FCT_CFG_OBJECT_LIST_PROC) */

    /* FCT SLATE Main Time */
    SLATE_v_PreProcessing(p_SLATERequirePorts);

    /* Send RTA-End Event for data preprocessing runtime in non-error state*/
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_PRE_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */


    /*---------------------------------------------------------------------------*/
    /* Start ACC Situation module processing PRE (SIT)                           */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_ACC_SITUATION)
    /* Send RTA-Start Event for ACC Situation module runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_SIT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    /* Pass reference freeze structures in INPUT to module */
#ifdef FCT_SIMU
    t_SITInput.t_FrameFreezes.pt_SIT_SimMeasInfo = &SIT_SimMeasInfo;
    t_SITInput.t_FrameFreezes.pt_SIT_SimMeasInfoFreeze = &t_SIT_SimMeasInfoFreeze;
#endif
    t_SITInput.t_FrameFreezes.pt_SIT_DeviceMeasInfo = &SIT_DeviceMeasInfo;
    t_SITInput.t_FrameFreezes.pt_SIT_DeviceMeasInfoFreeze = &SIT_DeviceMeasInfoFreeze;

    SIT_v_PreProcessPRE(&t_SITInput, &t_SITInputModify, &t_SITOutput, t_FCTSen_MDObjList);
    SIT_v_ProcessPRE(&t_SITInput, &t_SITInputModify, &t_SITOutput);
    /* Send RTA-End Event for ACC Situation module runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_SIT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif


    /*---------------------------------------------------------------------------*/
    /* Start Course Prediction (CP)                                              */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_COURSE_PREDICTION)
    /* Send RTA-Start Event for Course Prediction runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_CP, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    /* Pass reference freeze structures in INPUT to module */
#ifdef FCT_SIMU
    t_CPInput.t_FrameFreezes.pt_CP_SimMeasInfo = &CP_SimMeasInfo;
    t_CPInput.t_FrameFreezes.pt_CP_SimMeasInfoFreeze = &t_CP_SimMeasInfoFreeze;
#endif
    t_CPInput.t_FrameFreezes.pt_CP_DeviceMeasInfo = &CP_DeviceMeasInfo;
    t_CPInput.t_FrameFreezes.pt_CP_DeviceMeasInfoFreeze = &CP_DeviceMeasInfoFreeze;
    
    CP_v_PreProcess(&t_CPInput);
    CP_v_Process(&t_CPInput, &t_CP_Output);
    /* Send RTA-End Event for Course Prediction runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_CP, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif  /* (FCT_CFG_COURSE_PREDICTION) */

    /*---------------------------------------------------------------------------*/
    /* ACC Lane Association (LA)                                                 */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    /* FCT ACC runtime measurement: Start event for FCT_ACC_TIME_LA */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_LA, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    /* Pass reference freeze structures in INPUT to module */
#ifdef FCT_SIMU
    t_LAInput.t_FrameFreeze.pt_LA_SimMeasInfo = &LA_SimMeasInfo;
    t_LAInput.t_FrameFreeze.pt_LA_SimMeasInfoFreeze = &t_LA_SimMeasInfoFreeze;
#endif
    t_LAInput.t_FrameFreeze.pt_LA_DeviceInfo = &t_LA_DeviceMeasInfo;
    t_LAInput.t_FrameFreeze.pt_LA_DeviceInfoFreeze = &t_LA_DeviceMeasInfoFreeze;
    
    LA_v_PreProcess(&t_LAInput, &t_LA_Output, t_FCTSen_MDObjList);
    LA_v_Process(&t_LAInput, &t_LA_Output);
    /*Storing outputs from LA to output ports*/
    for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
    {
      FCTSEN_pPubFctObjList->ObjList[t_ObjNr].LaneInformation.eAssociatedLane = t_LA_Output.t_LAObjOutputList[t_ObjNr].ObjAssociatedLane;
      FCTSEN_pPubFctObjList->ObjList[t_ObjNr].LaneInformation.eFuncAssociatedLane = t_LA_Output.t_LAObjOutputList[t_ObjNr].ObjFuncLane;
      FCTSEN_pPubFctObjList->ObjList[t_ObjNr].Legacy.fDistToRef = t_LA_Output.t_LAObjOutputList[t_ObjNr].TrajDist.TrajDistMeas.Y.f0;
    }
    /* FCT ACC runtime measurement: End event for FCT_ACC_TIME_LA */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_LA, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif  /* (FCT_CFG_ACC_LANE_ASSOCIATION) */


    /*---------------------------------------------------------------------------*/
    /* ACC Object Of Interest selection (OOI)                                    */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_ACC_OOI)
    /* FCT ACC runtime measurement: Start event for SLATE_RTA_OOI */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_OOI, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#ifdef FCT_SIMU
    /* Pass reference freeze structures in INPUT to module */
    t_OOI_Input.t_FrameSimFreeze.pt_OOI_SimMeasInfo = &OOI_SimMeasInfo;
    t_OOI_Input.t_FrameSimFreeze.pt_OOI_SimMeasInfoFreeze = &t_OOI_SimMeasInfoFreeze;
    /* Currently no device freezes have been identified in OOI */
#endif
    OOI_v_PreProcess(&t_OOI_Input, &t_OOI_Output, t_FCTSen_MDObjList);
    OOI_v_Process(&t_OOI_Input,&t_OOI_Output);
    /*Storing outputs from OOI to output ports*/
    for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < OOI_NUMBER_OF_OOI; t_ObjNr++)
    {
      FCTSEN_pPubFctObjList->HeaderAssessedObjList.aiOOIList[t_ObjNr] = t_OOI_Output.OOI_ObjNumber[t_ObjNr];
    }
    /* FCT ACC runtime measurement: End event for SLATE_RTA_OOI */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_OOI, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif  /* (FCT_CFG_ACC_OOI) */


    /*---------------------------------------------------------------------------*/
    /* Start ACC Situation module processing POST (SIT)                          */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_ACC_SITUATION)
#if (FCT_CFG_RUNTIME_MEAS)
    /* Store runtime for SIT PRE locally */
    u_SITRuntimeInfoPRE = t_SLATERuntimeInfo.uRuntime[SLATE_RTA_SIT];
    t_SLATERuntimeInfo.uRuntime[SLATE_RTA_SIT] = 0u;
#endif
    /* Send RTA-Start Event for ACC Situation module runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_SIT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    SIT_v_ProcessPOST(&t_SITInput, &t_SITInputModify, &t_SITOutput);
    /*Storing outputs from SIT to output ports*/
    for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
    {
      FCTSEN_pPubFctObjList->ObjList[t_ObjNr].LaneInformation.uiCutInProbability = t_SITOutput.t_ObjList[t_ObjNr].u_ObjCutInPotential;
      FCTSEN_pPubFctObjList->ObjList[t_ObjNr].LaneInformation.uiCutOutProbability = t_SITOutput.t_ObjList[t_ObjNr].u_ObjCutOutPotential;
    }
    /* Send RTA-End Event for ACC Situation module runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_SIT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#if (FCT_CFG_RUNTIME_MEAS)
    /* Add runtime for SIT PRE to runtime for SIT POST */
    t_SLATERuntimeInfo.uRuntime[SLATE_RTA_SIT] += u_SITRuntimeInfoPRE;
#endif
#endif

#if (SLATE_CFG_ACC_PERF_MONITORING)
    /*---------------------------------------------------------------------------*/
    /* Start APM performance monitoring                                          */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_RUNTIME_MEAS)
    /* FCT ACC runtime measurement: Start event for SLATE_RTA_APM */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_APM, 0);
#endif

    APM_v_Process();

#if (FCT_CFG_RUNTIME_MEAS)
    /* FCT ACC runtime measurement: End event for SLATE_RTA_APM */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_APM, 0);
#endif
#endif /* (SLATE_CFG_ACC_PERF_MONITORING) */

#if (SLATE_CFG_USE_EXT_OBJ_ID)
    /* Calculate external object ID */
    FCTSenDetermineExternObjID();
#endif

    /*---------------------------------------------------------------------------*/
    /* ACC Output (OUT)                                                          */
    /*---------------------------------------------------------------------------*/
#if (FCT_CFG_ACC_OUTPUT)
    /* FCT ACC runtime measurement: Start event for SLATE_RTA_OUT */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_OUT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
    /* Pass reference freeze structures in INPUT to module */
#ifdef FCT_SIMU
    t_OUTInput.t_FrameFreeze.pt_OUT_SimMeasInfo = &OUT_SimMeasInfo;
    t_OUTInput.t_FrameFreeze.pt_OUT_SimMeasInfoFreeze = &t_OUT_SimMeasInfoFreeze;
#endif
    t_OUTInput.t_FrameFreeze.pt_OUT_DeviceMeasInfo = &OUT_DeviceMeasInfo;
    t_OUTInput.t_FrameFreeze.pt_OUT_DeviceMeasInfoFreeze = &t_OUT_DeviceMeasInfoFreeze;
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    t_OUTInput.t_FrameFreeze.pt_OUT_PubObjListMeasInfoFreeze = &t_OUT_PubObjListMeasInfoFreeze;
#endif
    OUT_v_PreProcess(&t_OUTInput, &t_OUTOutput, t_FCTSen_MDObjList);
    OUT_v_Process(&t_OUTInput,&t_OUTOutput);
    /* FCT ACC runtime measurement: End event for SLATE_RTA_OUT */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_OUT, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif  /* (FCT_CFG_ACC_OUTPUT) */


  /*---------------------------------------------------------------------------*/
  /* Start Nachbearbeitung Targetprocessing                                    */
  /*---------------------------------------------------------------------------*/

    /* Send RTA-Start Event for Post processing runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_POST_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */

    /*! Fill SLATE Error Output structure */
#if (FCT_CFG_ERROR_OUTPUT_SEN)
    SLATE_v_FillErrorOut(p_SLATEProvidePorts->pt_SLATEErrorOut);
#endif

    SLATE_v_PostProcessing(p_SLATERequirePorts, p_SLATEProvidePorts);

    /* Send RTA-End Event for Post processing runtime */
    FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_POST_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTSen_v_SLATESetCompState (p_SLATEProvidePorts->pSenCompState, t_SLATEFrame.SLATEOpMode, AlgoErrorBuffer);
#endif

    /*! Computation chain ran through. FCT Sensor is initialized or running.*/
    t_SLATEFrame.bIsInitialized = TRUE;

  }
  else
  {
    /************************************************************************/
    /*                        Start of error path                           */
    /************************************************************************/
    /* Remark: Everything in this else-case runs now before HC */

    /* error occurred, set available provide ports */
    SLATE_v_SetErrorProvidePorts(p_SLATEProvidePorts);

    SLATE_v_AlgoInit(); /* Remark: All this*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /*ERROR path! need to check existence of pointers*/
    if (p_SLATEProvidePorts != NULL) 
    {
      if ( (p_SLATERequirePorts != NULL) && (p_SLATERequirePorts->pSenCtrlData != NULL) )
      {
        FCTSen_v_SLATESetCompState (p_SLATEProvidePorts->pSenCompState, t_SLATEFrame.SLATEOpMode, AlgoErrorBuffer);
      }
      else
      {
        /*assuming running status from scheduler ==> pointer error, Frame-mode is INIT ==> Input error is set*/
        FCTSen_v_SLATESetCompState (p_SLATEProvidePorts->pSenCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif

  } /* ---------------------------------------------------- end of ERROR path  -------------------------------------------------*/

#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
  /* if enabled this function checks all SigHeaders */
  FCTSen_v_ACCCheckProvideHeaders(p_SLATERequirePorts, p_SLATEProvidePorts);
#endif

  SLATE_v_FillProPortHeaders();

  /* Output Meas Freezes */
#if (FCT_MEASUREMENT)
  /* Send RTA-Start Event for Process Measfreeze runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_PROCESSFREEZE, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
  /* Process other meas freezes */
  FCTSen_v_ACCProcessMeasFreeze();
  /* Send RTA-End Event for Process Measfreeze runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_PROCESSFREEZE, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#endif /* FCT_MEASUREMENT */

  /* Send RTA-Start Event for Frame Measfreeze runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_FRAMEFREEZE, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */

#if (FCT_MEASUREMENT)
  /* Freeze frame meas data in all cases, even in case of Error*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ((p_ServiceFuncts != NULL) 
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    && (p_ServiceFuncts->pfMeasStartFuncCycle != NULL)
#endif
    && (p_ServiceFuncts->pfMeasFreeze != NULL)
    && (pSLATE_ServiceFuncts != NULL)
    && (pSLATE_ServiceFuncts->pfMeasFreeze != NULL) )
  {
    FCTSen_v_ACCFrameFreeze();
  }
#else
  FCTSen_v_ACCFrameFreeze();
#endif
#endif

  /* Send RTA-End Event for Frame Measfreeze runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_FRAMEFREEZE, 0u);/* PRQA S 4424 */
  /* Sends RTA-End Event for whole procedure runtime */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_PROCESS, 0u);/* PRQA S 4424 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Conversion is safe, as enum is within the range of unsigned char */
#if (FCT_CFG_RUNTIME_MEAS)
  /* Freeze FCT ACC runtime info */
  Meas_Freeze_Stack_Var(FCT_MEAS_ID_ACC_RUNTIME_DEBUG, &t_SLATERuntimeInfo, sizeof(SLATERuntimeInfo_t));
#endif

}

/*************************************************************************************************************************
  Functionname:    SLATE_v_AlgoInit                                                                                   */ /*!

  @brief           Initialization of SLATE variables/states

  @description     Initialization of SLATE frame (note: resets global FCTSenFrame.bFirstCycleDone flag.)
                    - Init external object IDs
					@startuml
                    Partition SLATE_v_AlgoInit {
                    Start
                       #Orange: Initialize FCT Merge Delete objects:
                       <b>SLATE_v_InitMergeDeleteLists</b> >
                       #Orange: Initialize external object IDs:
                       <b>FCTSen_v_SLATEInitExternObjID</b> >
                    -Initialize a default non-zero Sensor Position Relative to CoG

                    end
                    }
                    @enduml


  @return          -

  @param[in]       -

  @glob_in         -

  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment
  @c_switch_full   -

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2010
  @changed         12.02.2016

  @author          Jochen Spruck & Gergely Ungvary
*************************************************************************************************************************/
void SLATE_v_AlgoInit (void) /* Remark: At the end of ACC-EBA-SPM split, this function might be static in ACC frame */
{
  /* Reset bIsInitialized */
  t_SLATEFrame.bIsInitialized  = FALSE;

  /* Initialize FCT Merge Delete objects */
#if (FCT_CFG_OBJECT_LIST_PROC)
  SLATE_v_InitMergeDeleteLists();
#endif /* END IF (FCT_CFG_OBJECT_LIST_PROC) */

#if (SLATE_CFG_USE_EXT_OBJ_ID)
  /* Init external object IDs */
  FCTSen_v_SLATEInitExternObjID();
#endif

  /* Initialize a default non-zero Sensor Position Relative to CoG
 (real distance will be calculated each cycle when not in init mode) */
  FCT_fBumperToCoG = FCT_SEN_BUMPER2COG_DIST_DEFAULT;
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of ACC sub-component in FCT_SEN task

  @description     Set operation mode of ACC sub-component in FCT_SEN task based on given value
                   @startuml
                   Partition SLATE_v_SetOperationMode {
                   Start
                   -Set operation mode of ACC sub-component in FCT_SEN task based on given value
                   end
                   }
                   @enduml
                   

  @return          -

  @param[in]       t_ACCOpModeValue : ACC operation mode value in FCT_SEN task [full range of datatype SLATECompState_t as in slate_types.h]

  @glob_in         -
  @glob_out        @ref t_SLATEFrame

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control)

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         28.10.2016
  @changed         28.10.2016

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
void SLATE_v_SetOperationMode(SLATECompState_t const t_ACCOpModeValue)
{
  t_SLATEFrame.SLATEState = t_ACCOpModeValue;
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_PreProcessing                                                                      */ /*!

  @brief           Do FCT sensor SLATE information pre-processing

  @description     Do pre-processing needed by FCT component SLATE. 
                    - Calls function for setting the interface versions of the provide ports
                    - Checks signal header status
                    - Calls function for calculation of the sensor position relative to CoG and 
                      for updating ego motion matrices based on current motion data
                    - Calls function for preprocessing of object list
                    - Calls FIPProcess
                    - Preprocessing based on FCT state
                    - Checking of input measurement counters for service pointer
					@startuml
                    Partition SLATE_v_PreProcessing {
                    Start
                       #Orange: Calculates the sensor position relative to CoG and Updates ego motion matrices based on current motion data:
                       <b>SLATE_v_ProcessInput</b> >
                    
                    If(SLATE is in Running state) then (Yes)
                       #Orange: Merge and Delete or Delete fct Object data:
                       <b>SLATE_v_MergeDeleteObj</b> >
                    Elseif(SLATE is not initialized)
                       #Orange: Initialization of SLATE variables/states:
                       <b>SLATE_v_AlgoInit</b> >
                       #Orange: Merge and Delete or Delete fct Object data:
                       <b>SLATE_v_MergeDeleteObj</b> >
                    Else(SLATE is in Permanent error state or Temporary error state)
                       #Orange: Initialization of SLATE variables/states:
                       <b>SLATE_v_AlgoInit</b> >
                     
                    endif
                       #Orange: preprocesses inputs before the actual module begins process:
                       <b>FIP_v_PreProcess</b> >                                                 
                    
                       #Orange: FCT Input Preprocessing Main:
                       <b>FIP_v_Process</b> >  
                    
                    end
                    }
                    @enduml


  @return          -

  @param[in]       pRequirePorts : the inputs passed to FCT_SEN
                    pEmGenObjList->sSigHeader.eSigStatus  [AlgoSignalState_t as in Rte_Type.h]
                    pPubEmObj->eSigStatus                 [AlgoSignalState_t as in Rte_Type.h]
  @param[out]      pErrorBuffer : Pointer to the buffered error

  @glob_in         FCTSenFrame : FCT frame data
                      SLATEState : FCT current operation mode        [FCTSenState_t as in fct_seh.h]
                   FCTObjectList : FCT specific list of Objects     [FCTPrivObjectList_t as defined in fct_sen.h]
  @glob_out        FCTSenFrame : FCT frame data
                      bFirstCycleDone [TRUE, FALSE]

  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_USE_SIG_HEADER : FCT switch to enable the generic Signal Header in Interfaces
  @c_switch_part   FCT_CFG_INPUT_PREPROCESSSING : FCT support for FCT Input Preprocessing (FIP)
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c_switch_part   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.06.2013
  @changed         22.10.2015

  @author          Jochen Spruck, Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_PreProcessing(const reqSLATEPortList_t * pRequirePorts)

{
#if (FCT_CFG_INPUT_PREPROCESSSING)
  /*! Definition of FIP ALL Input structure */
  FIP_ALL_InputConst_t t_FIP_ALL_InputConst;
#endif /* END IF FCT_CFG_INPUT_PREPROCESSSING */

  SLATE_v_ProcessInput(SLATE_f_GetCPCycleTime(), pRequirePorts->pEgoDynObjSync);

  switch (t_SLATEFrame.SLATEState)
  {
  case COMP_STATE_RUNNING:
    /*! Set information: cycle was processed */
#if (FCT_CFG_OBJECT_LIST_PROC)
    /* Merge and Delete or Delete fct Object data*/

    SLATE_v_MergeDeleteObj(pRequirePorts->pEmGenObjList);

#endif
    break;

  case COMP_STATE_NOT_INITIALIZED:
    /* init TP frame */
    SLATE_v_AlgoInit();
#if (FCT_CFG_OBJECT_LIST_PROC)
    /* Keep object list up-to-date even in shutdown: merge and delete or delete fct Object data*/

    SLATE_v_MergeDeleteObj(pRequirePorts->pEmGenObjList);

#endif
    break;

  case COMP_STATE_PERMANENT_ERROR:
  case COMP_STATE_TEMPORARY_ERROR:
  default:
    /* init EM frame */
    SLATE_v_AlgoInit();
    break;
  } /* endswitch */

#if (FCT_CFG_RUNTIME_MEAS)
  /* FCT ACC runtime measurement: Start event for SLATE_RTA_FIP */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  SLATE_RTA_FIP, 0);
#endif

  /*! Do FCT Input Preprocessing */
#if (FCT_CFG_INPUT_PREPROCESSSING)
#ifdef FCT_SIMU
  t_FIP_ALL_InputConst.t_FrameFreeze.pt_FIP_SimMeasInfo = &FIP_SimMeasInfo;
  t_FIP_ALL_InputConst.t_FrameFreeze.pt_FIP_SimMeasInfoFreeze = &t_FIP_SimMeasInfoFreeze;
#endif
  t_FIP_ALL_InputConst.t_FrameFreeze.pt_FIP_DeviceMeasInfo = &FIP_DeviceMeasInfo;
  t_FIP_ALL_InputConst.t_FrameFreeze.pt_FIP_DeviceMeasInfoFreeze = &t_FIP_DeviceMeasInfoFreeze;
  FIP_v_PreProcess(&t_FIP_ALL_InputConst, t_FCTSen_MDObjList);
  FIP_v_Process(&t_FIP_ALL_InputConst, &t_FIP_ALL_Output);
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* FCT ACC runtime measurement: End event for SLATE_RTA_FIP */
  FCTSEN_SLATE_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  SLATE_RTA_FIP, 0);
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTSEN_SLATE_SERVICE_ADD_EVENT                                                                   */ /*!

  @brief           Determine runtime of SLATE component based on service functions provided by Base SW.

  @description     Determine runtime of SLATE component based on service functions depending on wheter pfRTAAlgoServiceAddEvent are available or not
                    If it is available this function is used otherwise the function FCTSEN_SERVICE_ADD_EVENT_FCT is called which determines the time difference between start and end events
					@startuml
                    Partition FCTSEN_SLATE_SERVICE_ADD_EVENT {
                    Start
                    
                    end
                    }
                    @enduml

  @return          -

  @param[in]       RtaEvtType : 
  @param[in]       u_IdLocal : 
  @param[in]       u_OptData : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_RUNTIME_MEAS : CT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 
  @c_switch_full   FCT_CFG_RTA_PROFILING FCT_CFG_USE_SERVICE_POINTER_FUNCTS: Compiler switch used around this function/file

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.05.2016
  @changed         04.05.2016


  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
void FCTSEN_SLATE_SERVICE_ADD_EVENT( const RTA_t_Events      RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#else
void FCTSEN_SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
#else
void FCTSEN_SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType RtaEvtType, const uint8 u_IdLocal, const uint8 u_OptData)
#endif
{
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))// PRQA S 3332
  if (    (pSLATE_ServiceFuncts                           != NULL)
       && (pSLATE_ServiceFuncts->pfRTAAlgoServiceAddEvent != NULL) )
  {
	#ifdef RTA_GLOBALID_SLATE
		pSLATE_ServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, RTA_GLOBALID_SLATE, u_IdLocal, u_OptData);
	#else
		pSLATE_ServiceFuncts->pfRTAAlgoServiceAddEvent(RtaEvtType, COMP_ID_FCT60, u_IdLocal + SLATE_RTA_OFFSET, u_OptData);
	#endif
  }
#endif

#if (FCT_CFG_RUNTIME_MEAS)
  /* Check NULL pointer. 
  Check whether additional parameter (i.e. Object ID) is defined. This cannot be handled */
  if (    (pSLATE_ServiceFuncts                     != NULL)
       && (pSLATE_ServiceFuncts->pfGetTimestampuS32 != NULL) 
       && (u_OptData                                           == 0   ))
  {
    SLATE_SERVICE_ADD_EVENT( RtaEvtType, (sint32)u_IdLocal);
  }
#endif
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Required by software design to avoid compiler warning*/
/* PRQA S 3119 3*/
  _PARAM_UNUSED(RtaEvtType);
  _PARAM_UNUSED(u_IdLocal);
  _PARAM_UNUSED(u_OptData);
}

#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    SLATE_v_RuntimeMeasInit                                                                           */ /*!

  @brief           Init global FCT runtime measurement array (SLATE)

  @description     Init global FCT runtime measurement array (SLATE)
                   @startuml
                   Partition SLATE_v_RuntimeMeasInit {
                   Start
                   -Init global FCT runtime measurement array 
                   end
                   }
                   @enduml
  @return          -

  @param[in]       -

  @glob_in        -
  @glob_out         t_SLATERuntimeInfo.uRuntime : Array of size FCTSEN_RTA_NOF_CHECKPOINTS containing the runtime 
                        of FCT_SEN subcomponents (microseconds) [0u ... 1s]

  @c_switch_part   -
  @c_switch_full   FCT_CFG_RUNTIME_MEAS : FCT switch to enable runtime measurement for FCT (ONLY for radar projects); only possible with service pointers 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.05.2016
  @changed         04.05.2016

  @author          Veronika Huber | veronika.huber@continental-corporation.com | +49 (8382) 9699-490
*************************************************************************************************************************/
static void SLATE_v_RuntimeMeasInit(void)
{
  uint32 i;
  /* Init global FCT runtime measurement array */
  for (i = 0u; i < SLATE_RTA_NOF_CHECKPOINTS; i++)
  {
    t_SLATERuntimeInfo.uRuntime[i] = 0u;
  }
}
#endif /* FCT_CFG_RUNTIME_MEAS */


#if (FCT_CFG_RUNTIME_MEAS)
/*************************************************************************************************************************
  Functionname:    SLATE_SERVICE_ADD_EVENT                                                                         */ /*!

  @brief           Determine runtime of FCT (Radar) component based on service functions provided by Base SW.

  @description     Determine runtime of FCT (Radar)  component based on service functions provided by Base SW.
                   The time difference is determined between start and end events.
				   @startuml
				   Partition SLATE_SERVICE_ADD_EVENT {
				   Start
				     if(RuntimeEvtType is equal to e RTA EVT AlgoStart) then (yes)
						 -In case of a start event, the current timestamp is stored in the array
					 elseif(RuntimeEvtType is equal to e RTA EVT AlgoEnd) then (yes)
					     - In case of an end event, the time difference between the start and end event is stored in the array. 
                     else
						 -Reset runtime info
				   end
				   }
				   @enduml


  @return          -

  @param[in]       *pServiceFuncts : Service pointer provided by frame SW
                        pfGetTimestampuS32 [full range of AS_t_GetTimestampuS32 as in algo_service_types.h]
  @param[in]       t_RuntimeEvtType : Event type [full range of datatype FCT_t_ACCRuntimeCheckpointTypeEnum as in fct_sen.h]
  @param[in]       u_IdGlobal : Dummy variable which is unused. Necessary for compatibility with camera projects.
                                [full range of datatype uint8]
  @param[in]       u_IdLocal : Index in FCT ACC runtime measurement array [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[
  @param[in]       u_OptData : Dummy variable which is unused. Necessary for compatibility with camera projects. 
                                [full range of datatype uint8]

  @glob_in         -
  @glob_out        t_FCT_ACCTimeArray : FCT ACC runtime info
                            t_FCT_ACCTimeArray[i] [full range of datatype uint32] with i in [0...FCT_ACC_TIME_NUMER_OF_CHECKPOINTS[

  @c_switch_part   -
  @c_switch_full   FCT_CFG_RUNTIME_MEAS : FCT switch to enable runtime measurement for ACC
                           (ONLY for radar projects); only possible with service pointers

  @pre             Start and End Events for each runtime measurement have to be called in the code.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.11.2015
  @changed         24.11.2015

  @author          Marie-Theres Boll | marie-theres.boll@continental-corporation.com | +49 (8382) 9699-632
*************************************************************************************************************************/
#if (defined(RTA_INTERFACE_VERSION))
#if (RTA_INTERFACE_VERSION >= 4)
 static void SLATE_SERVICE_ADD_EVENT( const RTA_t_Events       t_RuntimeEvtType, const sint32 u_EventID)
#else
 static void SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
#else
 static void SLATE_SERVICE_ADD_EVENT( const AS_t_RtaEventType  t_RuntimeEvtType, const sint32 u_EventID)
#endif
{
  if(t_RuntimeEvtType == e_RTA_EVT_AlgoStart) 
  {
    SLATE_ASSERT(t_SLATERuntimeInfo.uRuntime[u_EventID] == 0u);
    /* In case of a start event, the current timestamp is stored in the array. */
    t_SLATERuntimeInfo.uRuntime[u_EventID] = pSLATE_ServiceFuncts->pfGetTimestampuS32();
  }
  else if(t_RuntimeEvtType == e_RTA_EVT_AlgoEnd)
  {
    SLATE_ASSERT(t_SLATERuntimeInfo.uRuntime[u_EventID] > 0u);
    /* In case of an end event, the time difference between the start and end event is stored in the array. 
        Precondition: Valid start event must have been called before. */
    t_SLATERuntimeInfo.uRuntime[u_EventID] = pSLATE_ServiceFuncts->pfGetTimestampuS32() - t_SLATERuntimeInfo.uRuntime[u_EventID];
  }
  else
  {
    /* Reset runtime info:
    if no valid event type
    if no valid start event has been called before the end event. */
    t_SLATERuntimeInfo.uRuntime[u_EventID] = 0u;
    SLATE_ASSERT(FALSE);
  }
}
#endif /*FCT_CFG_RUNTIME_MEAS*/

/*************************************************************************************************************************
  Functionname:    SLATE_v_SetFrameData                                                                        */ /*!

  @brief           Set the SLATE Frame Data

  @description     Checks if the FCTSenFrame State is not in ERROR state. If not, sets the flag 
                   @ref ALGO_QUAL_CRITICAL_INPUT_ERROR of the error buffer and calls the function 
                   @ref SLATE_v_SignalErrorShutdown.\n
                   Otherwise the current Operation mode is written to the variable @ref t_SLATEFrame which is then 
                   filled with the information about the current software version. Additionally the cycle 
                   counter is increased.
                   @startuml 
                   Partition SLATE_v_SetFrameData{
                   start
                   if (FCT state is not ERROR) then (Yes)
                   :Set the SLATE OpMode according to the FCT Frame OpMode;
                   else (No)
                   :Set SLATE OpMode to Shutdown;
                   Endif
                   -update version number for CP,APM,FIP,SIT,OUT,OOI,LA and CAL
                   stop
                   }
                   @enduml
  @return          void

  @param[in]       p_FCTSenFrame : FCT Frame data in the current cycle

  @glob_in         -
  @glob_out        @ref t_SLATEFrame

  @c_switch_part   @ref FCT_CFG_COURSE_PREDICTION \n
  @c_switch_part   @ref SLATE_CFG_ACC_PERF_MONITORING \n
  @c_switch_part   @ref FCT_CFG_INPUT_PREPROCESSSING \n
  @c_switch_part   @ref FCT_CFG_ACC_OUTPUT \n
  @c_switch_part   @ref FCT_CFG_ACC_SITUATION \n
  @c_switch_part   @ref FCT_CFG_ACC_LANE_ASSOCIATION \n
  @c_switch_part   @ref FCT_CFG_ACC_OOI \n
  @c_switch_part   @ref FCT_CFG_ACC_CAL \n
  @c_switch_full   @ref FCT_CFG_ADAPTIVE_CRUISE_CONTROL

  @pre             -
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.02.2018

  @author          Bharadwaj Gobichettipalayam Sankar| bharadwaj.gobichettipalayam.sankar@continental-corporation.com | +49 (8382) 9699-4977
*************************************************************************************************************************/
static void SLATE_v_SetFrameData(FCTSenFrame_t * p_FCTSenFrame) 
{
  /* Store operation mode received from outside in sen frame for freezing */
  if ( (p_FCTSenFrame->eFCTState != COMP_STATE_TEMPORARY_ERROR)
    && (p_FCTSenFrame->eFCTState != COMP_STATE_NOT_RUNNING))
  {
    t_SLATEFrame.SLATEOpMode = p_FCTSenFrame->eFCTOpMode;
  }
  else
  {
    /*No error handling (e.g. DEM, CompState) is required here as all 
    ports are checked later on in SLATE_v_ProcessPorts*/
    t_SLATEFrame.SLATEOpMode = FCT_MOD_SHUTDOWN;
  }
  t_SLATEFrame.uiCycleCounter++;

#if (FCT_CFG_COURSE_PREDICTION)
  t_SLATEFrame.Versions.uiCP                =   CP_SW_VERSION_NUMBER;
#endif
#if (SLATE_CFG_ACC_PERF_MONITORING)
  t_SLATEFrame.Versions.uiAPM               =   APM_SW_VERSION_NUMBER;
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
  t_SLATEFrame.Versions.uiFIP               =   FIP_SW_VERSION_NUMBER;
#endif
#if (FCT_CFG_ACC_SITUATION)
  t_SLATEFrame.Versions.uiSIT               =   SIT_SW_VERSION_NUMBER;
#endif
#if (FCT_CFG_ACC_OUTPUT)
  t_SLATEFrame.Versions.uiOUT               =   OUT_SW_VERSION_NUMBER;
#endif
#if (FCT_CFG_ACC_OOI)
  t_SLATEFrame.Versions.uiOOI               =   OOI_SW_VERSION_NUMBER;
#endif
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  t_SLATEFrame.Versions.uiLA                =   LA_SW_VERSION_NUMBER;
#endif
/*  PRQA S 4243,4543   SHIFT_OPERATION*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe as values doesnot cross limits  */
/*  PRQA S 4542   BIT_WISE_OPERATION*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: safe as values doesnot cross limits  */
/*  PRQA S 0499   LEFT_SHIFT*/
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Left shift is safe due to integral promotion  */
#if (FCT_CFG_ACC_CAL)
  t_SLATEFrame.Versions.uiCAL                  =   (uint32) CAL_SW_VERSION_NUMBER;
#endif
  t_SLATEFrame.Versions.uProjectID             =   (uint32) SLATE_SW_PROJ_ID;

  t_SLATEFrame.Versions.SLATE_VERSION_AS_TEXT  =   (uint32) SLATE_SW_VERSION_NUMBER;

  t_SLATEFrame.Versions.uSLATESwVersion        =   (uint32) SLATE_SW_VERSION_NUMBER;
/* PRQA L:LEFT_SHIFT */
/* PRQA L: BIT_WISE_OPERATION */
/* PRQA L: SHIFT_OPERATION */
}

#if (FCT_CFG_USE_ALGOCOMPSTATE)
/*************************************************************************************************************************
  Functionname:    FCTSen_v_SLATESetCompState                                                                        */ /*!

  @brief           Setup SLATE AlgoCompState

  @description     Setup SLATE AlgoCompState (output to Scheduler)
                   @startuml
                   Partition FCTSen_v_SLATESetCompState {
                   Start
                   If(Algo Component State interface scheduler is not valid ) then (yes)
                         - Fill the array Algo Version Information  with the predefined string
                       If(SLATE state is not initialized) then (Yes)
                          If(Scheduled Op Mode is not in RUNNING mode) then (Yes)
                          - Set component state to RUNNING ,Error code to NO ERROR and Algo qualifier to OK
                         Else(no)
                         - Set component state to TEMPORARY ERROR and Error code to ERROR UNKNOWN
                          If (Buffered Qualifier is not ok) then (yes)
                            -Fill buffer with qualifier 
                          Else (No)
                         -buffer is empty,set algo qualifier to GENERAL FUNCTION ERROR
                          Endif
                       endif
                        
                   
                        Else if(SLATE state is RUNNING) then(Yes)
                   	- Set component state to RUNNING ,Error code to NO ERROR and Algo Qualifier to Buffered Qualifier
                   
                        Else if(SLATE state is NOT RUNNING) then (yes)
                           If(Scheduled Op Mode is not in RUNNING mode) then (Yes)
                           - Set component state to RUNNING ,Error code to NO ERROR and Algo qualifier to OK
                   	   Else(no)
                             - Set component state to TEMPORARY ERROR and Error code to ERROR UNKNOWN
                             If (Buffered Qualifier is not ok) then (yes)
                               -Fill buffer with qualifier 
                              Else (No)
                               -buffer is empty,set algo qualifier to GENERAL FUNCTION ERROR
                             Endif
                         endif

                      else (no)
                         if(SLATE state is TEMPORARY ERROR) then (yes)
                          - Set component state to TEMPORARY ERROR and Error code to ERROR UNKNOWN
                           If (Buffered Qualifier is not ok) then (yes)
                             -Fill buffer with qualifier 
                            Else (No)
                             -buffer is empty,set algo qualifier to GENERAL FUNCTION ERROR
                           Endif
                        Endif
                       endif
                     endif
                     
                     end
                     }
                     @enduml

  @return          static void

  @param[in,out]   pSenCompState : 
  @param[in]       ScheduledOpMode : 
  @param[in]       BufferedQualifier : 

  @author          Christian Obst
*************************************************************************************************************************/
static void FCTSen_v_SLATESetCompState (AlgoCompState_t * const pSenCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
{
#if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
#endif
#ifndef MFC_VERSION_INFO_LENGTH
#define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif 

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used thechnology */
#if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_SLATE_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_SLATE_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
#endif
  if (pSenCompState != NULL) 
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pSenCompState->AlgoVersionInfo, VERSION_SLATE_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pSenCompState->uiAlgoVersionNumber = t_SLATEFrame.Versions.uSLATESwVersion;
#if COMP_STATE_INTFVER > 2u
    pSenCompState->uiApplicationNumber = 0u;
    pSenCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pSenCompState->ApplicationNumber = 0u;
    pSenCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (t_SLATEFrame.SLATEState)
    {
    case COMP_STATE_NOT_INITIALIZED:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pSenCompState->eCompState = COMP_STATE_RUNNING;
        pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_RUNNING:
      /*everything's fine*/
      pSenCompState->eCompState = COMP_STATE_RUNNING;
      pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pSenCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case COMP_STATE_NOT_RUNNING:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pSenCompState->eCompState = COMP_STATE_RUNNING;
        pSenCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case COMP_STATE_TEMPORARY_ERROR:
      /*triggered with input interface errors*/
    default:
      pSenCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
      pSenCompState->eErrorCode = COMP_ERROR_UNKNOWN;
      if (BufferedQualifier != ALGO_QUAL_OK)
      {
        pSenCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
      }
      else
      {
        pSenCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
/*************************************************************************************************************************
  Functionname:    SLATE_v_InitAssessedObjList                                                                 */ /*!

  @brief           Initialize assessed object list (SLATE)

  @description     Reset assessed object list to default state
                   @startuml
                   Partition SLATE_v_InitAssessedObjList {
                   Start
                   - Reset header array with indexs of OOI objects
                   - set default object loss information to none
                   Repeat
                   - Reset lane information
                   - Reset object of interest information
                   Repeat while(for all objects )
                   end
                   }
                   @enduml


  @return          -

  @param[in,out]   pFctObjList : assessed object list
                      pFctObjList->uiVersionNumber            [all valid entries are defined bz typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                      pFctObjList->HeaderAssessedObjList.iNumOfUsedObjects  [ObjNumber_t as defined in Rte_Type.h]
                      pFctObjList->sSigHeader.uiTimeStamp                   [AlgoDataTimeStamp_t as defined in Rte_Type.h]
                      pFctObjList->sSigHeader.uiMeasurementCounter          [AlgoCycleCounter_t as defined in Rte_Type.h]
                      pFctObjList->sSigHeader.uiCycleCounter                [AlgoCycleCounter_t as defined in Rte_Type.h]
                      pFctObjList->sSigHeader.eSigStatus                    [AlgoSignalState_t as defined in Rte_Type.h]
                      pFctObjList->HeaderAssessedObjList.aiOOIList[i](i = [0:SiAnzOOI[)	[ObjNumber_t as defined in Rte_Type.h]
                      pFctObjList->HeaderAssessedObjList.eRelObjLossReason  [eRelObjLossReason_t as defined in Rte_Type.h]
                      pFctObjList->ObjList[j].LaneInformation.eAssociatedLane (j=[0:EM_N_OBJECTS[)    [eAssociatedLane_t as defined in Rte_Type.h]
                      pFctObjList->ObjList[j].LaneInformation.uiCutInProbability(j=[0:EM_N_OBJECTS[)  [0u ... 100u]
                      pFctObjList->ObjList[j].LaneInformation.uiCutOutProbability(j=[0:EM_N_OBJECTS[) [0u ... 100u]
                      pFctObjList->ObjList[j].ObjOfInterest.cExternalID(j=[0:EM_N_OBJECTS[)           [full range of datatype unsigned char]
                      pFctObjList->ObjList[j].ObjOfInterest.eObjOOI(j=[0:EM_N_OBJECTS[)		          [eObjOOI_t as defined in Rte_Type.h]

  @param[in]       eSigState : the signal state to set for the object list (Reference - AlgoSignalState_t as defined in Rte_Type.h)
                      [AL_SIG_STATE_INIT=0, AL_SIG_STATE_INVALID=2]

  @glob_in         FCTSenFrame.uiCycleCounter [AlgoCycleCounter_t as defined in Rte_Type.h]
  @glob_out        -

  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t
  @c_switch_full   FCT_CFG_OBJECT_LIST_PROC       : Object list processing interface input/output
  @c_switch_full   FCT_CFG_ASSESSED_OBJ_OUT_INTF  : Interface switch

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         18.10.2011
  @changed         09.11.2015

  @author          Gergely Ungvary | gergely.ungvary@continental-corporation.com
*************************************************************************************************************************/
static void SLATE_v_InitAssessedObjList(AssessedObjList_t * pFctObjList, AlgoSignalState_t eSigState) // ACC
{
  eObjOOI_t i;
  ObjNumber_t j;
  pFctObjList->uiVersionNumber  = FCT_ASSESSED_OBJ_INTFVER;
  pFctObjList->HeaderAssessedObjList.iNumOfUsedObjects  = 0;

  pFctObjList->sSigHeader.uiCycleCounter        = FCTSenFrame.uiCycleCounter;
  pFctObjList->sSigHeader.eSigStatus            = eSigState;

  /* Reset header array with indices of OOI objects */
  for (i=OBJ_NEXT_OOI; i<OBJ_NEXT_LAT_RIGHT_OOI; i++)
  {
    pFctObjList->HeaderAssessedObjList.aiOOIList[i] = OBJ_INDEX_NO_OBJECT;
  }
  /* Default object loss information is none */
  pFctObjList->HeaderAssessedObjList.eRelObjLossReason  = OBJ_LOSS_NO_INFO;
  /* Go through all objects */
  for (j=0; j<EM_N_OBJECTS; j++)
  {
    /* Reset lane information */
    pFctObjList->ObjList[j].LaneInformation.eAssociatedLane     = ASSOC_LANE_UNKNOWN;
    pFctObjList->ObjList[j].LaneInformation.uiCutInProbability  = 0u;
    pFctObjList->ObjList[j].LaneInformation.uiCutOutProbability = 0u;
    /* Reset object of interest information */
    pFctObjList->ObjList[j].ObjOfInterest.cExternalID           = 255u;
    pFctObjList->ObjList[j].ObjOfInterest.eObjOOI               = OBJ_NOT_OOI;
  }
}
#endif
#endif

/*************************************************************************************************************************
  Functionname:    SLATE_v_PostProcessing                                                                      */ /*!

  @brief           Do SLATE information post-processing

  @description     Do post-processing needed by SLATE component: Call initialization function for assessed object list 
                    in case of FCTSen initialization state or FCTSen Shutdown state. Call sensor specific 
                    post processing.
					@startuml
                    Partition SLATE_v_PostProcessing {
                    Start
                    If(SLATE state is RUNNING or NOT INITIALIZED) then (Yes)
                    - Initialize external object IDs
                    - set the status of the assessed object list to init
                    Elseif (SLATE state is TEMPORARY ERROR) then (yes)
                    - Initialize external object IDs
                    - set the status of the assessed object list to invalid
                    Elseif(SLATE state is PERMANENT ERROR or REDUCED AVAILABILITY)then (Yes)
                    -do nothing 
                    endif
                    end
                    }
                    @enduml


  @return          -

  @param[in]       pRequirePorts : Inputs passed to FCT_SEN
  @param[in]       pProvidePorts : Outputs of FCT_SEN

  @glob_in         FCTSenFrame : FCT frame data
                        SLATEState : FCT current operation mode        [FCTSenState_t as in fct_seh.h]
  @glob_out        -

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2010
  @changed         29.10.2015

  @author          Jochen Spruck, Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_PostProcessing (const reqSLATEPortList_t * pRequirePorts, const provSLATEPortList_t * pProvidePorts) // ACC only
{
  _PARAM_UNUSED(pRequirePorts);/* PRQA S 3119 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Required by software design to avoid compiler warning*/
#if (!FCT_CFG_OBJECT_LIST_PROC) || (!FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  _PARAM_UNUSED(pProvidePorts);
#endif 

  switch (t_SLATEFrame.SLATEState)
  {
  case COMP_STATE_RUNNING:
    break;
  case COMP_STATE_NOT_INITIALIZED:
#if (SLATE_CFG_USE_EXT_OBJ_ID)
    /* Init external object IDs */
    FCTSen_v_SLATEInitExternObjID();
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    /* In shutdown/init mode set the status of the assessed object list to init */
    SLATE_v_InitAssessedObjList(pProvidePorts->pPubFctObj, AL_SIG_STATE_INIT);
#endif
#endif
    break;
  case COMP_STATE_TEMPORARY_ERROR:
#if (SLATE_CFG_USE_EXT_OBJ_ID)
    /* Init external object IDs */
    FCTSen_v_SLATEInitExternObjID();
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    /* In shutdown/init mode set the status of the assessed object list to invalid */
    SLATE_v_InitAssessedObjList(pProvidePorts->pPubFctObj, AL_SIG_STATE_INVALID);
#endif
#endif
    break;
  case COMP_STATE_PERMANENT_ERROR:
  case COMP_STATE_REDUCED_AVAILABILITY:
  default: /* PRQA S 3218 */
   /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: not safety critical*/
    break;
  } /* endswitch */

#if (FCT_CFG_SENSOR_CONTROL_INTF)
  /* Call sensor-specific processing */
  FCTSensorSpecificProc(pProvidePorts->pErrorOut, pProvidePorts->pSensorCtrl); // raus // talk to Norman shall call this function or not 09.03.2017 Shang
#endif

}
#if (FCT_CFG_OBJECT_LIST_PROC)
/*************************************************************************************************************************
  Functionname:    SLATE_v_MergeDeleteObj                                                                        */ /*!

  @brief           Handle merge/delete operations on objects in SLATE marked by EM

  @description     Go through EM object list, and if EM marked object as merged
                   or deleted then update/reinitialize internal FCT states bound
                   to that object
				   @startuml
                   Partition SLATE_v_MergeDeleteObj {
                   Start
                    Partition For_All_EM_objects {
                       If(object has a merge reference to a "NEW" object and object have no merge    information from the last cycle) then (yes)
                       - Delete the FCT-content of "NEW"-objects
                       endif
                    }
                   
                   Partition For_All_EM_objects {
                     If (Merge object ID is valid and Split Merge ID is not ID of object) then (Yes)
                          If(merge flag is valid) then (Yes)
                             -Merge External Object ID
                         Endif
                   Else (No)
                   -Store the information which is copied during the merge
                   - Merge the old object into the new object at the same position in the FCT-list
                   endif
                   }
                   
                   end
                   }
                   @enduml


  @return          -

  @param[in]       pObjList : pointer to the EM object list containing the merge/delete flags
                      pObjList->aObject[iObj].General.eMaintenanceState     [EM_t_GenObjMaintenanceState as defined in Rte_Type.h]
                      pObjList->aObject[iObj].General.eSplitMergeState      [EM_t_GenObjSplitMergeState as defined in Rte_Type.h]
                      pObjList->aObject[iObj].General.uiMergeID             [full range of datatype unsigned char]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_COLLISION_DETECTION : FCT collision detection (CD) switch
  @c_switch_part   SLATE_CFG_USE_EXT_OBJ_ID : Configuration switch to enable SI external object ID assignment
  @c_switch_full   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2010
  @changed         09.11.2015

  @author          Jochen Spruck, Gergely Ungvary | gergely.ungvary@continental-corporation.com
*************************************************************************************************************************/
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Split Logic is missing completely, unclear behaviour in case of split!")// PRQA S 3116
/* date: 2015-05-18, reviewer: Lonard jaison Manohar(uidj2547), reason: Non QAC related but required.*/
#endif

static void SLATE_v_MergeDeleteObj( const EM_t_GenObjectList * pObjList)

{
  ObjNumber_t iObj;
  /*! First: Delete the FCT-content of "NEW"-objects which have no merge information from the last cycle (eSplitMergeState = EM_GEN_OBJECT_SM_STATE_NONE). 
      Necessary, if another object has a merge reference to a "NEW" object. */
  for (iObj = (ObjNumber_t)0; iObj < EM_N_OBJECTS; iObj++)
  {
    if( (pObjList->aObject[iObj].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW) && 
        (pObjList->aObject[iObj].General.eSplitMergeState == EM_GEN_OBJECT_SM_STATE_NONE) 
      )
    {
      t_FCTSen_MDObjList[iObj].b_ObjectToDelete = TRUE;  /* 1 indicates Object to be deleted */
    }
  }
  /*! Second: Do the "merge" operation (copy information of the last cycle if necessary) */
  for (iObj = (ObjNumber_t)0; iObj < EM_N_OBJECTS; iObj++)
  {

    const EM_t_GenObject * pCurObj = &(pObjList->aObject[iObj]);
    const uint8 uiObjMergeFlag = pCurObj->General.uiMergeID;

    /*! If the object's merge-split ID is a valid ID (range between 0 and EM_N_OBJECTS -1), then a merge 
    operation took place in the current EM cycle. If the merge ID is not equal the object ID iObj, 
    the object is merged into another object. If the merge ID is equal the object ID iObj, the object in merged into a new object on the same 
    FCT-list position and a special handing is necessary. 
    If in case if no merge the merge ID is EM_GEN_OBJECT_SM_ID_NONE, in case of merge to unknown object the merge ID is EM_GEN_OBJECT_SM_ID_NONE. 
    Both cases are handled as if no merge took place since no information about the object in FCT available. */
    /*! Behavior as on the old version: If no merge or a merge into an unknown object (uiMergeID >= EM_N_OBJECTS) or "normal" merge (valid ID in uiMergeID and if uiMergeID != ID of object),
        First the merge takes place and then the old FCT object can be deleted */

      /*! Merge, if valid ID in uiMergeID and if uiSplitMergeID != ID of object */
 /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Intergral promotion is fine.  */
    if ( (uiObjMergeFlag >= EM_N_OBJECTS) || (uiObjMergeFlag != (ObjNumber_t)(iObj)) )/* PRQA S 1863, 1862 */
    {
        /* For safeties sake verify that the merge flag is valid */
 /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Intergral promotion is fine.  */
/* PRQA S 1862 1 */
      if (uiObjMergeFlag < EM_N_OBJECTS)
      {
        /* Cast is save as validity is checked */
        const ObjNumber_t iObjToKeep = (ObjNumber_t) uiObjMergeFlag;
        t_FCTSen_MDObjList[iObj].t_ObjectToKeep = iObjToKeep;
#if (SLATE_CFG_USE_EXT_OBJ_ID)
        /* external object ID must be kept */
        /* <ln_offset:+1 MISRA Rule 14.2: reviewer name: Hanel date: 07-09-2012 reason: depending on algo configuration, the merge function may not change anything */
        FCTSenMergeExtObjID(iObjToKeep,iObj);
#endif
      }
    }
    else
    {
      /*! The old object is merged into the new object at the same position in the FCT-list 
        ->  First, the information which is copied during the merge, has to be stored locally. 
            Than, the old FCT-object can be deleted and afterwards the "merge"-information can be considered. */
#if (SLATE_CFG_USE_EXT_OBJ_ID)
      const FCTSenExtObjId_t ExtObjId = FCTSenGetObjExtID(iObj);
#endif
      t_FCTSen_MDObjList[iObj].t_ObjectToKeep = iObj; /* Same ID indicates Object to be retained */
#if (SLATE_CFG_USE_EXT_OBJ_ID)
      /*! External object ID must be kept: In case of a new object (iObjectToKeep is a new object without an external ID), the external ID of the old FCT-object is kept 
          -> SISetExtID(...) instead of SIMergeExtObjID(...) in SIMergeObjects(...)*/
      /* <ln_offset:+1 MISRA Rule 14.2: reviewer name: Hanel date: 07-09-2012 reason: depending on algo configuration, the merge function may not change anything */
       FCTSenSetObjExtID(iObj, ExtObjId);
#endif

    }
  } /* END of merge operation : Loop over EM_N_OBJECTS */
}

#endif  /* #if (FCT_CFG_OBJECT_LIST_PROC) */

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             SLATE_v_SetDem                               */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch
                  @startuml
                  Partition SLATE_v_SetDem {
                  Start
                  If (pSLATE Service Function is valid and Set Event Status is not NULL) then (Yes)
                  - set DEM message
                  endif
                  end
                  }
                  @enduml

  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTSenServiceFuncts connected to input service ports
  @todo           review
  @author         Christian Obst
**************************************************************************** */
static void SLATE_v_SetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pSLATE_ServiceFuncts != NULL) && (pSLATE_ServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pSLATE_ServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif /*FCT_CFG_USE_DEM*/

/*************************************************************************************************************************
  Functionname:    SLATE_v_SetupSyncRef                                                                        */ /*!

  @brief           Creates SLATE sync data for Simulation synchronization

  @description     1. Puts signal headers of all input ports into one structure 
                   2. Checks validity of interface
                   3. Sets sSigHeader of SyncRef structure (any NullPointer -> INVALID)
				   @startuml
                   Partition SLATE_v_SetupSyncRef {
                   Start
                   If (pRequired Ports is Valid)then (yes)
                        Partition For_All_Members_of_RequiredPorts {
                        If(Required ports member is VALID) then (yes)
                          -copy the signal header of respective Required port member to SyncRef structure
                        Else(no)
                         -Set signal status of SyncRef to invalid
                        Endif
                        }
                        If(pSenCtrlData of Required ports is valid)then (Yes)
                   	- fill signal header of SyncRef with pSenCtrlData signal header of Required ports 
                   	- Set signal status of SyncRef to OK
                        Else(no)
                   	- Set signal status of SyncRef to INVALID
                        endif
                   
                   
                   Else(No)
                   -Set signal status to Invalid
                   endif
                   end
                   }
                   @enduml


  @return          -

  @param[in]       pRequirePorts : The input data used by FCT component
                      pSenCtrlData : FCT COntrol data [FCTCtrlData_t as defined in Rte_Type.h]
                      pEgoDynObjSync : The dynamic vehicle ego data object sync [VehDyn_t as defined in Rte_Type.h]
                      pEgoDynRaw : The dynamic vehicle ego data raw [VehDyn_t as defined in Rte_Type.h]
                      pEgoStaticData : The static vehicle ego data [VehPar_t as defined in Rte_Type.h]
                      pEmGenObjList : EM generic object list [EM_t_GenObjectList as defined in Rte_Type.h]
                      pEmCustObjList : EM customer specific object list [EM_t_ObjectList_Custom as defined in Rte_Type.h]
                      pEmARSObjList : EM ARS-technology-specific object list [EM_t_ARSObjectList as defined in Rte_Type.h]
                      pEmCamObjList : EM Camera-technology-specific object list [EM_t_CamObjectList as defined in Rte_Type.h]
                      pPubEmObj : The public EM object data [ObjectList_t as defined in Rte_Type.h]
                      pMovObjTraces : Moving object traces [MovingObjectTraces_t as defined in Rte_Type.h]
                      pRSPOutputPD : RSP roadbeam information [RSPOutputPD_t as defined in Rte_Type.h]
                      pPerfDegrData : Performance degradation input data [PerfDegr_t as defined in Rte_Type.h]
                      pRoadData : Road/lane information [Road_t as defined in Rte_Type.h]
                      pRSPContextData : RSP Kontext data [RSPKontextData_t as defined in interfacerspkontextdata.h]
                      pFctVehLongOut : Longitudinal control internal buffer for passing information from FCT_VEH to FCT_SEN [FctVeh2SenInfo_t as defined in Rte_Type.h]
                      pFCTCustomInput : Custom input [FCTCustomInput_t as defined in Rte_Type.h]
                      pCameraObjData : EM Camera fusion output data [EM_t_ObjectList_Custom as defined in Rte_Type.h]
                      pAlignmentMonInput : Alignment monitoring output data [ALN_Monitoring_t as defined in Rte_Type.h]
                      pVehSig : Direct access to vehicle signals [VehSig_t as defined in Rte_Type.h
                      pME_in : Input from mobil-eye directly for debugging [ME_in_t as defined in Rte_Type.h]
                      pCPAR_FCT_Parameters : FCT Coding parameters [CPAR_FCT_Parameters_t as defined in Rte_Type.h]
                      pPerfDegrExtInput : Performance degradation external input [PerfDegrExtInput_t  as defined in Rte_Type.h]
                      pDIMOutputCustom : Custom DIM input [DIMOutputCustom_t as defined in Rte_Type.h]
                      pNaviData : Navi input data to FCT [t_NaviInputData as defined in Rte_Type.h]
                      pCamLaneData : Camera lane input data [t_CamLaneInputData as defined in Rte_Type.h]
                      pSenCtrlData : FCT control data [FCTCtrlData_t as defined in Rte_Type.h]
                      pCamSLAInputData : SLA Input data from camera [CamSLAInputData_t as defined in Rte_Type.h]
					  pTSAInputData : TSA Input data from camera [TSA_SLATE_Input_t as defined in Rte_Type.h]
                      sSigHeader : Signal Headers of every Input Port defined above is also an input to this function [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         t_SLATESyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]

  @glob_out        t_SLATESyncRef : Simulation sync structure contains Signal Headers of every Input Port
                      sSigHeader.eSigStatus : [AlgoSignalState_t as defined by Rte_Type.h]
                      SenCtrlData : [SignalHeader_t as defined in Rte_Type.h]
                      EgoDynObjSync : [SignalHeader_t as defined in Rte_Type.h]
                      EgoDynRaw : [SignalHeader_t as defined in Rte_Type.h]
                      EgoStaticData : [SignalHeader_t as defined in Rte_Type.h]
                      EmFctCycleMode : [SignalHeader_t as defined in Rte_Type.h]
                      EmGenObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmCustObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmARSObjList : [SignalHeader_t as defined in Rte_Type.h]
                      EmCamObjList : [SignalHeader_t as defined in Rte_Type.h]
                      PubEmObj : [SignalHeader_t as defined in Rte_Type.h]
                      MovObjTraces : [SignalHeader_t as defined in Rte_Type.h]
                      RSPOutputPD : [SignalHeader_t as defined in Rte_Type.h]
                      PerfDegrData : [SignalHeader_t as defined in Rte_Type.h]
                      RoadData : [SignalHeader_t as defined in Rte_Type.h]
                      RSPContextData : [SignalHeader_t as defined in Rte_Type.h]
                      FctVehLongOut : [SignalHeader_t as defined in Rte_Type.h] 
                      FCTCustomInput : [SignalHeader_t as defined in Rte_Type.h]
                      CameraObjData : [SignalHeader_t as defined in Rte_Type.h]
                      AlignmentMonInput : [SignalHeader_t as defined in Rte_Type.h]
                      VehSig : [SignalHeader_t as defined in Rte_Type.h]
                      ME_in : [SignalHeader_t as defined in Rte_Type.h]
                      BswAlgoParameters : [SignalHeader_t as defined in Rte_Type.h]
                      CPAR_FCT_Parameters : [SignalHeader_t as defined in Rte_Type.h]
                      PerfDegrExtInput : [SignalHeader_t as defined in Rte_Type.h]
                      DIMOutputCustom : [SignalHeader_t as defined in Rte_Type.h]
                      NaviData : [SignalHeader_t as defined in Rte_Type.h]
                      CamLaneData : [SignalHeader_t as defined in Rte_Type.h]
                      CamSLAInputData : [SignalHeader_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_EM_FCT_CYCLEMODE : FCT input EM/FCT cycle-mode configuration switch
  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output
  @c_switch_part   FCT_USE_EM_GENERIC_OBJECT_LIST : Configuration switch enables EM-Generic_Object list and disables ObjectList_t 
  @c_switch_part   FCT_USE_EM_CUSTOM_OBJECT_LIST : Configuration switch enabling EM custom object list 
  @c_switch_part   FCT_USE_EM_ARS_TECH_OBJECT_LIST : Configuration switch that enables ARS-technology specific object list 
  @c_switch_part   FCT_USE_EM_CAM_TECH_OBJECT_LIST : Configuration switch that enables Camera-technology specific object list
  @c_switch_part   SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES : Configuration switch for EM old traces
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_ROAD_INPUT : Road estimation input to FCT
  @c_switch_part   FCT_CFG_RSP_CONTEXT_INPUT : RSP Context data as input to FCT
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface
  @c_switch_part   FCT_CFG_CAMERA_OBJECT_DETECTION : FCT camera object/lane detection inputs
  @c_switch_part   FCT_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_SEN
  @c_switch_part   FCT_SEN_CFG_VEH_SIG_INPUT : FCT direct access to vehicle signals
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS : Configuration switch enabling the passing of ALGO parameters to the FCT component
  @c_switch_part   FCT_CFG_CPAR_PARAMS : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT : Configuration switch enabling DIMOutputCustom to FCT_SEN
  @c_switch_part   SLATE_CFG_SIMPLE_NAVI_INTERFACE : Configuration switch enabling simple navi input data to FCT_SEN
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   CamSLAInputData_INTFVER : Interface version number for port CamSLAInputData

  @pre             None
  @post            No changes

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         24.05.2013
  @changed         02.02.2016

  @author          Christian Obst | Christian.Obst@continental-corporation.com 
*************************************************************************************************************************/
static void SLATE_v_SetupSyncRef(const reqSLATEPortList_t * pRequirePorts)// PRQA S 3219
/* date: 2018-01-18, reviewer: Shruthi Ramaiah, reason: Will be used in future.*/
{
  /*setting whole syncref to zero */
  (void)memset(&t_SLATESyncRef, 0, sizeof(t_SLATESyncRef));/*PRQA S 0315 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason:Its safe to convert a pointer-to-object to a pointer-to-void  */
  if (pRequirePorts != NULL)
  {
    /*pSenCtrlData*/
    if (pRequirePorts->pSenCtrlData != NULL)
    {
      t_SLATESyncRef.SenCtrlData          = pRequirePorts->pSenCtrlData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pEgoDynObjSync*/
    if (pRequirePorts->pEgoDynObjSync != NULL)
    {
      t_SLATESyncRef.EgoDynObjSync         = pRequirePorts->pEgoDynObjSync->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoDynRaw*/
    if (pRequirePorts->pEgoDynRaw != NULL)
    {
      t_SLATESyncRef.EgoDynRaw               = pRequirePorts->pEgoDynRaw->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*EgoStaticData*/
    if (pRequirePorts->pEgoStaticData != NULL)
    {
      t_SLATESyncRef.EgoStaticData           = pRequirePorts->pEgoStaticData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_EM_FCT_CYCLEMODE)
    /*pEmFctCycleMode*/
    /* Cycle mode struct currently has no signal header, reset to zero */
    /*t_SLATESyncRef.EmFctCycleMode        = pRequirePorts->pEmFctCycleMode->sSigHeader;*/
    SLATE_v_SetSigHeaderError(&t_SLATESyncRef.EmFctCycleMode);
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)

    if (pRequirePorts->pEmGenObjList != NULL)
    {
      t_SLATESyncRef.EmGenObjList          = pRequirePorts->pEmGenObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
    /*pEmCustObjList*/
    if (pRequirePorts->pEmCustObjList != NULL)
    {
      t_SLATESyncRef.EmCustObjList         = pRequirePorts->pEmCustObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
    /*pEmARSObjList*/
    if (pRequirePorts->pEmARSObjList != NULL)
    {
      t_SLATESyncRef.EmARSObjList          = pRequirePorts->pEmARSObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
    /*pEmCamObjList*/
    if (pRequirePorts->pEmCamObjList != NULL)
    {
      t_SLATESyncRef.EmCamObjList          = pRequirePorts->pEmCamObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif



#if (SLATE_CFG_USE_EM_MOVING_OBJECT_TRACES)
    if (pRequirePorts->pMovObjTraces != NULL)
    {
      t_SLATESyncRef.MovObjTraces          = pRequirePorts->pMovObjTraces->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

//#if (FCT_CFG_NEW_TRACES_INTERFACE)
//    /*pObjectTraces*/
//    if (pRequirePorts->pObjectTraces != NULL)
//    {
//      t_SLATESyncRef.ObjectTraces          = pRequirePorts->pObjectTraces->sSigHeader;
//    }
//    else
//    {
//      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
//    }
//#endif
#endif

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    /*pPerfDegrData*/
    if (pRequirePorts->pPerfDegrData != NULL)
    {
      t_SLATESyncRef.PerfDegrData            = pRequirePorts->pPerfDegrData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ROAD_INPUT)
    /*pRoadData*/
    if (pRequirePorts->pRoadData != NULL)
    {
      t_SLATESyncRef.RoadData                = pRequirePorts->pRoadData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_RSP_CONTEXT_INPUT)
    /*pRSPContextData*/
    if (pRequirePorts->pRSPContextData != NULL)
    {
      t_SLATESyncRef.RSPContextData          = pRequirePorts->pRSPContextData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    /*pFCTCustomInput*/
    if (pRequirePorts->pFCTCustomInput != NULL)
    {
      t_SLATESyncRef.FCTCustomInput          = pRequirePorts->pFCTCustomInput->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    /* pEmFusionObjList */
    if (pRequirePorts->pEmFusionObjList != NULL)
    {
      t_SLATESyncRef.EmFusionObjList        = pRequirePorts->pEmFusionObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if ((FCT_CFG_CAMERA_OBJECT_DETECTION) &&  (!FCT_USE_EM_CUSTOM_OBJECT_LIST))
    /*pCameraObjData*/
    if (pRequirePorts->pCameraObjData != NULL)
    {
      t_SLATESyncRef.CameraObjData           = pRequirePorts->pCameraObjData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ALIGNMENT_MONITORING_INPUT)
    /*pAlignmentMonInput*/
    if (pRequirePorts->pAlignmentMonInput != NULL)
    {
      t_SLATESyncRef.AlignmentMonInput       = pRequirePorts->pAlignmentMonInput->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_ME_INPUT_FOR_DEBUG)
    /*pME_in*/
    if (pRequirePorts->pME_in != NULL)
    {
      t_SLATESyncRef.ME_in                  = pRequirePorts->pME_in->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
  /* BSW algo parameters currently has no signal header */
  /*t_SLATESyncRef.BswAlgoParameters       = pRequirePorts->pBswAlgoParameters->sSigHeader;*/
  SLATE_v_SetSigHeaderError(&t_SLATESyncRef.BswAlgoParameters);
#endif

#if (SLATE_CFG_SIMPLE_NAVI_INTERFACE)
    /*pNaviData*/
    if (pRequirePorts->pNaviData != NULL)
    {
      t_SLATESyncRef.NaviData                = pRequirePorts->pNaviData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (SLATE_CFG_CAM_LANE_INTERFACE)
    /*pCamLaneData*/
    if (pRequirePorts->pCamLaneData != NULL)
    {
      t_SLATESyncRef.CamLaneData             = pRequirePorts->pCamLaneData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
/*
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
    //pEmFusionObjList//
    if (pRequirePorts->pEmFusionObjList != NULL)
    { 
      t_SLATESyncRef.EmFusionObjList         = pRequirePorts->pEmFusionObjList->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
*/
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    /*pTSAInputData*/
    if (pRequirePorts->pTSAInputData != NULL)
    {
      t_SLATESyncRef.CamTSAInputData          = pRequirePorts->pTSAInputData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#elif ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    /*pCamSLAInputData*/
    if (pRequirePorts->pCamSLAInputData != NULL)
    {
      t_SLATESyncRef.CamSLAInputData          = pRequirePorts->pCamSLAInputData->sSigHeader;
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
	if (pRequirePorts->pLongCtrlResp != NULL)
	{
		t_SLATESyncRef.LongCtrlResp          = pRequirePorts->pLongCtrlResp->sSigHeader;
	}
	  else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    if (pRequirePorts->pSenCtrlData != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      SLATE_v_FillSigHeader(&t_SLATESyncRef.sSigHeader, &pRequirePorts->pSenCtrlData->sSigHeader);
      SLATE_v_SetSigHeaderState(&t_SLATESyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
  }
  else
  {
    t_SLATESyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}


/*************************************************************************************************************************
  Functionname:    SLATE_v_SetSigHeaderError                                                                          */ /*!

  @brief           Set signal header with error values

  @description     Init SignalHeader_t struct with default values for FCT_SEN.
                    These default values are the cycle counter of FCT_SEN and the signal state invalid. 
                    Timestamp and measurement counter are set to zero.
                    @startuml
                    Partition SLATE_v_FillSigHeader  {
                    Start
                    -Assign Timestamp and measurement counter of source signal header to signal header Timestamp and measurement counter
                    - Set Cycle Counter to cycle counter value of FCT_SEN
                    end
                    }
                    @enduml


  @return          -

  @param[out]      pSigHeader : The signal header to be filled
                        uiTimeStamp           [AlgoDataTimeStamp_t as in Rte_Type.h]
                        uiMeasurementCounter  [AlgoCycleCounter_t as in Rte_Type.h]
                        uiCycleCounter        [AlgoCycleCounter_t as in Rte_Type.h]
                        eSigStatus            [AlgoSignalState_t as in Rte_Type.h]

  @glob_in         FCTSenFrame : Global FctSen frame data
                      uiCycleCounter [AlgoCycleCounter_t as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         28.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_SetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiTimeStamp           = 0u;
  pSigHeader->uiMeasurementCounter  = 0u;
  pSigHeader->uiCycleCounter        = t_SLATEFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_FillSigHeader                                                                      */ /*!

  @brief           Fill SLATE signal header with default values

  @description     Fill SignalHeader_t struct with default values for SLATE. These default values are the 
                    cycle counter of FCT_SEN, and the signal state based on the passed parameter.
					@startuml
                    Partition SLATE_v_FillSigHeader  {
                    Start
                    -Assign Timestamp and measurement counter of source signal header to signal header Timestamp and measurement counter
                    - Set Cycle Counter to cycle counter value of FCT_SEN
                    end
                    }
                    @enduml


  @return          -

  @param[in]       pSourceHdr : The source signal header (measurement cycle counter and timestamp are 
                                copied from this source)
                      uiTimeStamp [AlgoDataTimeStamp_t as in Rte_Type.h]
                      uiMeasurementCounter [AlgoCycleCounter_t as in Rte_Type.h]
  @param[in]       eSigState : The state to set for the 'eSigStatus' field [AlgoSignalState_t as in Rte_Type.h]
  @param[out]      pSigHeader : The signal header to be filled
                      uiTimeStamp           [AlgoDataTimeStamp_t as in Rte_Type.h]
                      uiMeasurementCounter  [AlgoCycleCounter_t as in Rte_Type.h]
                      uiCycleCounter        [AlgoCycleCounter_t as in Rte_Type.h]
                      eSigStatus            [AlgoSignalState_t as in Rte_Type.h]

  @glob_in         FCTSenFrame : Global FctSen frame data
                      uiCycleCounter         [AlgoCycleCounter_t as in Rte_Type.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             FCT component initialized
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22.10.2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void SLATE_v_FillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr) ////Shang 30.01.2017 rename to slate
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = t_SLATEFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_SetSigHeaderState                                                                          */ /*!

  @brief           Set signal header state
                   @startuml
                   Partition SLATE_v_SetSigHeaderState {
                   Start
                   - Set signal header state
                   end
                   }
                   @enduml

  @return          -

  @param[in,out]   pSigHeader : pointer to signal header struct
  @param[in]       eSigState : signal state to be set

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void SLATE_v_SetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState) //Shang 30.01.2017 Rename to slate
{
  pSigHeader->eSigStatus            = eSigState;
}

/*************************************************************************************************************************
  Functionname:    SLATE_v_SetErrorProvidePorts                                                               */ /*!

  @brief           Setup available provide ports in SLATE ERROR case

  @description     Setup sigHeaders of available provide ports in SLATE ERROR case invalidates the Signal Status and setup version number
                   @startuml
                   Partition SLATE_v_SetErrorProvidePorts {
                   Start
                   If (pProvide Ports is Valid)then (yes)
                         If(Provide ports of pSenCompState is VALID) then (yes)
                          -Set pSLATE Component State to Provide ports of pSenCompState
                          -Set Version Number of pSen Component State to COMPONENT STATE INTFVER
                         Else(no)
                          -Set pSLATE Component State to NULL
                         Endif
                     
                         Partition For_All_Members_of_ProvidePorts {
                         If (provide ports member is VAILD)then (yes)
                                   - Set corresponding Assessed Object List slate to provide ports member
                                   -  set version number of provide port to FCT ASSESSED OBJECT INTFVER
                           - Set signal header of provide port with error values
                         Else(No)
                           - Set pSLATE Component State to NULL
                         endif
                         }
                   
                   
                   
                   
                   endif
                   
                   end
                   }
                   @enduml


  @return          -

  @param[in]       pProvidePorts : Outputs of FCT_SEN
                      pProvidePorts->pPubFctObj                         [AssessedObjList_t as defined in Rte_Type.h]
                      pProvidePorts->pSysPerfMonStates                  [SysPerfMonStates_t as defined in Rte_Type.h]
                      pProvidePorts->pCollDetOutput                     [FCTCDOutputCustom_t as defined in Rte_Type.h]
                      pProvidePorts->pFCTCDHypotheses                   [HypothesisIntf_t as defined in Rte_Type.h]
                      pProvidePorts->pAccDisplayObj                     [acc_object_t as defined in Rte_Type.h]
                      pProvidePorts->pFCTCustomOutput                   [FCTCustomOutput_t as defined in Rte_Type.h]
                      pProvidePorts->pErrorOut                          [FCTSenErrorOut_t as defined in Rte_Type.h]
                      pProvidePorts->pSensorCtrl                        [FCTSensorControl_t as defined in fct_types.h]
                      pProvidePorts->pFCTSenBusDebugData                [Camera project definition]
                      pProvidePorts->pSLAData                           [SLAData_t as defined in Rte_Type.h]
                      
  @glob_in         -
  @glob_out        FCTSEN_pPubFctObjList      [AssessedObjList_t as defined in Rte_Type.h]
  @glob_out        FCTSEN_pSysPerfMonStates   [SysPerfMonStates_t as defined in Rte_Type.h]
  @glob_out        FCT_pCDHypothesesSen       [HypothesisIntf_t as defined in Rte_Type.h]
  @glob_out        pSLATE_SLAData         [SLAData_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_OBJECT_LIST_PROC           : Object list processing interface input/output
  @c_switch_part   FCT_CFG_ASSESSED_OBJ_OUT_INTF      : Interface switch
  @c_switch_part   FCT_CFG_SIGNAL_PERF_MONITORING     : FCT signal performance monitoring
  @c_switch_part   FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE : FCT CD sub-component custom output interface
  @c_switch_part   FCT_CFG_COLLISION_DETECTION        : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE        : FCT custom I/O interface
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_SEN           : FCT error output from FCT_SEN
  @c_switch_part   FCT_CFG_LONG_CTRL_SLA_SUPPORT : Activation switch for SLA support
  @c_switch_part   SLAData_INTFVER : Interface version number for port SLAData
  @c_switch_part   FCT_CFG_LOPC_COMPONENT : FCT Support for LOPC Component
  @c_switch_full   -

  @pre             SLATEOpMode == FCT_MOD_SHUTDOWN
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         01.07.2013
  @changed         02.11.2015

  @author          Christian Obst | Christian.Obst@continental-corporation.com 
*************************************************************************************************************************/
static void SLATE_v_SetErrorProvidePorts (const provSLATEPortList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pSenCompState != NULL)
    {
      pSLATE_SenCompState      = pProvidePorts->pSenCompState;
#if COMP_STATE_INTFVER > 2u
      pProvidePorts->pSenCompState->uiVersionNumber = COMP_STATE_INTFVER;
#else
      pProvidePorts->pSenCompState->uVersionNumber = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      pSLATE_SenCompState = NULL;
    }
#endif

#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    if (pProvidePorts->pPubFctObj != NULL)
    {
      pSLATE_PubFctObjList                      = pProvidePorts->pPubFctObj;
      pProvidePorts->pPubFctObj->uiVersionNumber = FCT_ASSESSED_OBJ_INTFVER;
      SLATE_v_SetSigHeaderError(&pProvidePorts->pPubFctObj->sSigHeader);
    }
    else
    {
      pSLATE_PubFctObjList = NULL;
    }
#endif
#endif
//#if (FCT_CFG_SIGNAL_PERF_MONITORING)
//    if (pProvidePorts->pSysPerfMonStates != NULL)
//    {
//      FCTSEN_pSysPerfMonStates                          = pProvidePorts->pSysPerfMonStates;
//      pProvidePorts->pSysPerfMonStates->uiVersionNumber = SYS_PERF_MON_OUT_INTFVER;
//      FCTSenSetSigHeaderError(&pProvidePorts->pSysPerfMonStates->sSigHeader);
//    }
//    else
//    {
//      FCTSEN_pSysPerfMonStates = NULL;
//    }
//#endif

//#if (FCT_CFG_LONG_PROCESSING)
//    if (pProvidePorts->pAccDisplayObj != NULL)
//    {
//#if (defined(_MSC_VER))
//#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Check if error management is working!")
//#endif
//      pProvidePorts->pAccDisplayObj->uiVersionNumber  = ACC_DISPLAY_OBJECT_INTFVER;
//      FCTSenSetSigHeaderError(&pProvidePorts->pAccDisplayObj->sSigHeader);
//    }
//    if (pProvidePorts->pAccOutput != NULL)
//    {
//      pProvidePorts->pAccOutput->uiVersionNumber      = FCT_ACC_OUTPUT_DATA_INTFVER;
//      FCTSenSetSigHeaderError(&pProvidePorts->pAccOutput->sSigHeader);
//    }
//#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    if (pProvidePorts->pFCTCustomOutput != NULL)
    {
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Check if error management is working!")// PRQA S 3116
/* date: 2015-05-18, reviewer: Lonard jaison Manohar(uidj2547), reason: Non QAC related but required.*/
#endif
      /* customer specific input/output */
      pSLATE_CustomOutput = pProvidePorts->pFCTCustomOutput;
      pProvidePorts->pFCTCustomOutput->uiVersionNumber  = FCT_CUSTOM_OUTPUT_INTFVER;
      SLATE_v_SetSigHeaderError(&pProvidePorts->pFCTCustomOutput->sSigHeader);
    }
    else
    {
      pSLATE_CustomOutput = NULL;
    }
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
    if (pProvidePorts->pt_SLATEErrorOut != NULL)
    {
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Check if error management is working!")// PRQA S 3116
/* date: 2015-05-18, reviewer: Lonard jaison Manohar(uidj2547), reason: Non QAC related but required.*/
#endif
      pSLATE_ErrorOut = pProvidePorts->pt_SLATEErrorOut;
      pProvidePorts->pt_SLATEErrorOut->uiVersionNumber = FCT_SEN_ERROR_OUT_INTFVER;
      SLATE_v_SetSigHeaderError(&pProvidePorts->pt_SLATEErrorOut->sSigHeader);
    }
    else
    {
      pSLATE_ErrorOut = NULL;
    }
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    /* Seutp Bus debug port for Sensor in error case */
    if (pProvidePorts->pFCTSenBusDebugData != NULL)
    {
      FCTSEN_pACCBusDebugData          = pProvidePorts->pFCTSenBusDebugData;
    }
    else
    {
      FCTSEN_pACCBusDebugData = NULL;
    }
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
    if(pProvidePorts->pFCTAccOOIData != NULL)
    {
      //GET_FCT_ACC_OOI_DATA_PTR = pProvidePorts->pFCTAccOOIData;
      pSLATE_AccOOIData = pProvidePorts->pFCTAccOOIData;
      pProvidePorts->pFCTAccOOIData->uiVersionNumber = FCT_SEN_ACC_OOI_INTFVER;
      SLATE_v_SetSigHeaderError(&pProvidePorts->pFCTAccOOIData->sSigHeader);
    }
    else
    {
      pSLATE_AccOOIData = NULL;
    }
#endif
#if (FCT_CFG_LOHP_COMPONENT)
    if(pProvidePorts->pSLATE_HC_Data != NULL)
    {
      pSLATE_HC_Data = pProvidePorts->pSLATE_HC_Data;
#if 0 // disabled since signal header and interface not available yet
      pProvidePorts->pSLATE_HC_Data->uiVersionNumber = ;
      FCTSen_v_ACCSetSigHeaderError(&pProvidePorts->pSLATE_HC_Data->sSigHeader);
#endif
    }
    else
    {
      pSLATE_HC_Data = NULL;
    }
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    if(pProvidePorts->pSLATE_SPM_Data != NULL)
    {
      pSLATE_SPM_Data = pProvidePorts->pSLATE_SPM_Data;
#if 0 // disabled since signal header and interface not available yet
      pProvidePorts->pSLATE_SPM_Data->uiVersionNumber = ;
      FCTSen_v_ACCSetSigHeaderError(&pProvidePorts->pSLATE_SPM_Data->sSigHeader);
#endif
    }
    else
    {
      pSLATE_SPM_Data = NULL;
    }
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    if(pProvidePorts->pSLATE_CD_Data != NULL)
    {
      pSLATE_CD_Data = pProvidePorts->pSLATE_CD_Data;
#if 0 // disabled since signal header and interface not available yet
      pProvidePorts->pSLATE_CD_Data->uiVersionNumber = ;
      FCTSen_v_ACCSetSigHeaderError(&pProvidePorts->pSLATE_CD_Data->sSigHeader);
#endif
    }
    else
    {
      pSLATE_CD_Data = NULL;
    }
#endif
#if (FCT_CFG_SLA_FEATURE)
    if(pProvidePorts->pSLAData != NULL)
    {
      pSLATE_SLAData = pProvidePorts->pSLAData;
#if 0 // disabled since signal header and interface not available yet
      pProvidePorts->pSLAData->uiVersionNumber = ;
      FCTSen_v_ACCSetSigHeaderError(&pProvidePorts->pSLAData->sSigHeader);
#endif
    }
    else
    {
      pSLATE_SLAData = NULL;
    }
#endif /* ENDIF FCT_CFG_SLA_FEATURE */
  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    pSLATE_SenCompState = NULL;
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
    pSLATE_PubFctObjList = NULL;
#endif
#endif
//#if (FCT_CFG_SIGNAL_PERF_MONITORING)
//    FCTSEN_pSysPerfMonStates = NULL;
//#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    FCTSEN_pACCBusDebugData = NULL;
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
    pSLATE_CustomOutput = NULL;
#endif
#if (FCT_CFG_ERROR_OUTPUT_SEN)
    pSLATE_ErrorOut = NULL;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    /* Provide OOI Objects from SEN to VEH */
    pSLATE_AccOOIData = NULL;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
    pSLATE_HC_Data = NULL;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
    pSLATE_SPM_Data = NULL;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    pSLATE_CD_Data = NULL;
#endif
#if (FCT_CFG_SLA_FEATURE)
    pSLATE_SLAData = NULL;
#endif /* ENDIF FCT_CFG_SLA_FEATURE */
  }
}

#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTSen_v_SLATECheckProvideHeader                                                                 */ /*!

  @brief           Check whether the signal header has changed during the call of the components SLATE

  @description     Check whether the signal header has changed during the call of the components SLATE
                   @startuml
                   Partition FCTSen_v_SLATECheckProvideHeader {
                   Start
                   - Check whether the signal header has changed during the call of the components SLATE
                   end
                   }
                   @enduml


  @return          -

  @param[in]       pProvidedSigHeader : 
  @param[in]       pReceivedSigHeader : 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSen_v_SLATECheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         )
            /*&& (pProvidedSigHeader->eSigStatus           != AL_SIG_STATE_INVALID                    )*/ );
}
#endif


#if (FCT_CFG_ACTIVATE_SIGHEADER_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTSenCheckProvideHeaders                                                                        */ /*!

  @brief           Call the check of the SigHeader for all used ports
                   @startuml
                   Partition FCTSenCheckProvideHeaders {
                   Start
                   - check of the SigHeader for all used ports
                   end
                   }
                   @enduml


  @return          -

  @param[in]       pRequirePorts : 
  @param[in]       pProvidePorts : 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTSen_v_ACCCheckProvideHeaders(reqSLATEPortList_t const * const pRequirePorts, provSLATEPortList_t const * const pProvidePorts)
{
#if ((FCT_CFG_OBJECT_LIST_PROC) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if ((FCT_CFG_ASSESSED_OBJ_OUT_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pPubFctObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#endif
//#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//  FCTSen_v_ACCCheckProvideHeader(&pProvidePorts->pSysPerfMonStates->sSigHeader, &pRequirePorts->pPerfDegrData->sSigHeader);
//#endif
//#if ((FCT_CFG_LONG_PROCESSING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//  FCTSen_v_ACCCheckProvideHeader(&pProvidePorts->pAccDisplayObj->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
//  FCTSen_v_ACCCheckProvideHeader(&pProvidePorts->pAccOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
//#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pFCTCustomOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
//#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//  FCTSen_v_ACCCheckProvideHeader(&pProvidePorts->pCollDetOutput->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
//#endif
//#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//  FCTSen_v_ACCCheckProvideHeader(&pProvidePorts->pFCTCDHypotheses->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
//#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pFCTAccOOIData->sSigHeader, &pRequirePorts->pEmGenObjList->sSigHeader);
#endif
#if (defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_SLA_FEATURE))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pTSAInputData->sSigHeader);
#elif (FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_SLA_FEATURE))
  FCTSen_v_SLATECheckProvideHeader(&pProvidePorts->pSLAData->sSigHeader, &pRequirePorts->pCamSLAInputData->sSigHeader);
#endif
  //#if (FCT_CFG_USE_ALGOCOMPSTATE)
  //  NO sigheader in AlgoCompState!!!
  //#endif
  //#if (FCT_CFG_USE_BUS_DEBUG)
  //  NO sigheader in BusDebugData!!!
  //#endif
}
#endif /* FCT_CFG_ACTIVATE_SIGHEADER_CHECK */

// Added the header Shang 22.02.2017 
static void SLATE_v_InitProvidePorts(provSLATEPortList_t * pt_ProvidePort)
{

#if (FCT_CFG_SIGNAL_PERF_MONITORING) 
  ObjNumber_t t_ObjNr;
#endif /* END IF FCT_CFG_SIGNAL_PERF_MONITORING */

#if (FCT_CFG_LOHP_COMPONENT)
  uint8 i;


#if (SLATE_CFG_ACC_PERF_MONITORING)
  pt_ProvidePort->pSLATE_HC_Data->t_APM_Data.f_MaxDistPerfMin = 0.f; /* PRQA S 2982  2*/
  pt_ProvidePort->pSLATE_HC_Data->t_APM_Data.f_MaxDistPerfMin = 0.f; /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: not safety critical  */
#endif
 /* date: 2019-07-01, reviewer: Karthik Chittepu, reason: Intergral promotion is fine.  */
/* PRQA S 1862 1 */
  for (i = 0u; i < OOI_NUMBER_OF_OOI; i++)
  {
    pt_ProvidePort->pSLATE_HC_Data->t_ObjLossReasonACCOOI[i] = OBJ_LOSS_NO_INFO;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE)
    pt_ProvidePort->pSLATE_HC_Data->t_OOILCState[i] = SLATE_LC_NONE;
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */
  }

  pt_ProvidePort->pSLATE_HC_Data->t_SLATE_LC.b_AllowOvertake = FALSE;
  pt_ProvidePort->pSLATE_HC_Data->t_SLATE_LC.e_LCDirection = SLATE_LC_NONE;
  pt_ProvidePort->pSLATE_HC_Data->t_SLATE_LC.e_LCPhase = SLATE_LC_NO_LANECHANGE;
  pt_ProvidePort->pSLATE_HC_Data->t_SLATE_LC.u_LCPhaseProb = 0u;

#endif /* (FCT_CFG_LOHP_COMPONENT) */

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  pt_ProvidePort->pSLATE_SPM_Data->FctPreselTGACCLastRelObj = 0u;
  pt_ProvidePort->pSLATE_SPM_Data->t_ObjLossReasonACCRelObj = OBJ_LOSS_NO_INFO;
  pt_ProvidePort->pSLATE_SPM_Data->f_Dist2TrajACCRelObj = 0.f;
  pt_ProvidePort->pSLATE_SPM_Data->f_Dist2TrajVarACCRelObj = 0.f;
  for (t_ObjNr = (ObjNumber_t)0; t_ObjNr < EM_N_OBJECTS; t_ObjNr++)
  {
    pt_ProvidePort->pSLATE_SPM_Data->t_ObjList[t_ObjNr].fWidth = 0.f;
  }
#endif

#if (FCT_CFG_COLLISION_DETECTION)
  pt_ProvidePort->pSLATE_CD_Data->t_ACCRelObjID = OBJ_INDEX_NO_OBJECT;
#endif
}

// Temporary:

//ubit32_t ACC_b_TempGetDataToSPM(ObjNumber_t t_ObjNr)
//{
//  return OBJ_GET_SI(t_ObjNr).Bool.FctPreselTG;
//}

#if (FCT_CFG_OBJECT_LIST_PROC)
/*************************************************************************************************************************
  Functionname:    SLATE_v_InitMergeDeleteLists                                                                     */ /*!

  @brief           Initialize Merge Delete list for SLATE objects

  @description     Initialize Merge Delete list for SLATE objects
                   @startuml
                   Partition SLATE_v_InitMergeDeleteLists {
                   Start
                   
                   Repeat 
                   - Initialize Merge Delete list for SLATE objects
                   Repeat while (For all EM object list )
                   end
                   }
                   @enduml


  @return          

  @param[in]       

  @glob_in         None 
  @glob_out        t_MergeDeleteObjectList[i].t_ObjectsToKeep : Reference to Object ID that has to be merged/retained
  @glob_out        t_MergeDeleteObjectList[t_Obj].b_ObjectToDelete : Flag indicating object to be deleted

  @c_switch_part   None 
  @c_switch_full   FCT_CFG_OBJECT_LIST_PROC : Object list processing interface input/output 

  @pre             None 
  @post            No changes 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         08.11.2016
  @changed         08.11.2016

  @author          Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474
*************************************************************************************************************************/
static void SLATE_v_InitMergeDeleteLists(void)
{
  ObjNumber_t t_Obj;
  for (t_Obj = 0; t_Obj < EM_N_OBJECTS; t_Obj++)
  {
    t_FCTSen_MDObjList[t_Obj].b_ObjectToDelete = FALSE;
    t_FCTSen_MDObjList[t_Obj].t_ObjectToKeep = OBJ_INDEX_NO_OBJECT;
  }
}
#endif /* END IF (FCT_CFG_OBJECT_LIST_PROC) */
/// @}
#endif /*!< FCT_CFG_ADAPTIVE_CRUISE_CONTROL */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

