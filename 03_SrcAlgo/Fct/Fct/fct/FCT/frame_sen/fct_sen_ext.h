/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

MODULNAME:                 fct_sen_ext.h

DESCRIPTION:               Function type definition for all generic algo interfaces 

AUTHOR:                    $Author: Raj, Rahul (uid41599) $

CREATION DATE:             $Date: 2020/11/30 14:49:20CET $

VERSION:                   $Revision: 1.21 $

LEGACY VERSION:            Revision: 1.63

**************************************************************************** */

/**
  @defgroup fct_sen FCT_SEN

  @ingroup sim_swc_fct

  Receives input data as explicit parameter passed to the main FCTSen_Exec
  function. This function also gets pointers to all output parameters.

    @todo fct_sen revise naming of functions and component itself.

@{ */


#ifndef FCT_SEN_EXT_H_INCLUDED
#define FCT_SEN_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_glob_ext.h"

#ifdef __cplusplus
extern "C" {
#endif

#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
/* Workaround, shall be removed if available in RTE for all projects */
#ifndef FCT_CFG_ASSESSED_OBJ_OUT_INTF
#define FCT_CFG_ASSESSED_OBJ_OUT_INTF SWITCH_ON
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning : Please make sure that this switch is generated by RTE for your Project configuration.")
#endif
#endif


#endif

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*! Inputs required by FCT component for sensor cycle processing */
typedef struct
{
#if (FCT_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t          * pSenCtrlData;     /*!< FCT control data */
#else
  const FCTCtrlData_t           * pSenCtrlData;     /*!< FCT control data */
#endif
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  const VehDyn_t                * pEgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
#endif
  const VehDyn_t                * pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  const VehPar_t                * pEgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  const EmFctCycleMode_t      * pEmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
  const EM_t_GenObjectList      * pEmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  const EM_t_ObjectList_Custom  * pEmCustObjList;   /*!< EM customer specific object list */
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
  const EM_t_SRRObjectList      * pEmSRRObjList;    /*!< EM SRR specific object list */
  const EMGlobalOutput_t        * pEmGlobalOutput;  /*!< EM Global data */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const EM_t_ARSObjectList      * pEmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  const EM_t_CamObjectList      * pEmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  const MovingObjectTraces_t    * pMovObjTraces;    /*!< Moving object traces */
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
  const ObjectTraceList_t       * pObjectTraces;    /*!< New object traces */
#endif
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
  const RSPOutputPD_t           * pRSPOutputPD;     /*!< RSP roadbeam information */
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const PerfDegr_t              * pPerfDegrData;    /*!< Performance degradation input data */
#endif
#if (FCT_CFG_ROAD_INPUT)
  const Road_t                  * pRoadData;        /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
  const RSPKontextData_t        * pRSPContextData;  /*!< RSP Kontext data */
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  const FctVeh2SenInfo_t        * pFctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  const FCTCustomInput_t        * pFCTCustomInput;  /*!< Custom input */
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) && ((!FCT_USE_EM_CUSTOM_OBJECT_LIST))) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  const EM_t_ObjectList_Custom  * pCameraObjData;   /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const ALN_S_Monitoring_t      * pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const VehSig_t                * pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  const ME_in_t                 * pME_in;             /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  const BSW_s_AlgoParameters_t  * pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const CPAR_FCT_Parameters_t * pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Macom SRD blockage info for SPM */
  const PerfDegrExtInput_t      * pPerfDegrExtInput;   /*!< Performance degradation external input (short range sensor info) */
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const DIMOutputCustom_t       * pDIMOutputCustom;   /*!< DIM output custom from FCT_VEH */
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const t_NaviInputData         * pNaviData;          /*!< Simple navi input data */
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const t_CamLaneInputData      * pCamLaneData;       /*!< Camera lane input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  const EM_t_FusionObjectList   * pEmFusionObjList; /* EM Fusion Object List */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const TSA_SLATE_Input_t       * pTSAInputData; /*!< Traffic Sign input data from camera */
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const CamSLAInputData_t       * pCamSLAInputData;   /*!< SLA input data from camera */
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  const LongCtrlInput_t *pLongCtrlResp;    /* Dynamic controller response */
  const TargetControlCommandPort_t *pt_FCT_IN_TCCP;   /* Command Input from ISC to LOHP */
  const TargetFollowStatePort_t *pt_FCT_IN_TFSP;   /* Status Input from LOPC to LOHP */
#endif
}
reqFCTSenPrtList_t;

/*! Outputs generated by FCT component for sensor cycle processing */
typedef struct
{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pSenCompState;  /*!< AlgoCompState interface to scheduler */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  AssessedObjList_t           * pPubFctObj;         /*!< The public FCT object data */
#endif
#endif
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
#if ((FCT_CFG_SIGNAL_PERF_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SysPerfMonStates_t          * pSysPerfMonStates;  /*!< System performance monitor output data */
#endif
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  acc_object_t                * pAccDisplayObj;     /*!< ACC_DISPLAY_OBJECT output from FCT_SEN */
  acc_output_data_t           * pAccOutput;         /*!< ACC_OUTPUT_DATA from FCT_SEN */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF) || (FCT_CFG_SHORT_RANGE_FUNCTIONS))
  /* customer specific input/output */
  FCTCustomOutput_t           * pFCTCustomOutput;   /*!< Custom output */
#endif
#if ((FCT_CFG_CD_CUSTOM_OUTPUT_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* custom output for CD */
  FCTCDOutputCustom_t         * pCollDetOutput;     /*!< Collision detection custom output */
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
  FCTSrfStates_t              * pFctSRFStates;      /*!< Short radar function states */
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Hypothesis interface */
  HypothesisIntf_t            * pFCTCDHypotheses;   /*!< CD hypotheses */
#endif
#if ((FCT_CFG_ERROR_OUTPUT_SEN) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSenErrorOut_t            * pErrorOut;          /*!< FCT error output */
#endif
#if ((FCT_CFG_SENSOR_CONTROL_INTF) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTSensorControl_t          * pSensorCtrl;        /*!< FCT sensor control */
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
  BusDebugData_t              * pFCTSenBusDebugData; /*!< Debug data */
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  FCTSenAccOOI_t             * pFCTAccOOIData; /* FCT OOI Objects */
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  TJATargetObj_t             * pFCTTJAOOIData;  /* FCT OOI Data to TJA */
#endif
#if ((FCT_CFG_SLA_FEATURE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SLAData_t                  * pSLAData;        /*!< SLA speed limit data from FCT_SEN */
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  TargetControlStatePort_t *pt_FCT_OUT_TCSP;     /* Status Output from LOHP to ISC */
  TargetFollowCommandPort_t *pt_FCT_OUT_TFCP; /* Command Output from LOHP to LOPC */
#endif
}
proFCTSenPrtList_t;

/*! @brief Simulation sync structure contains Signal Headers of every Input Port */
typedef struct FCTSen_SyncRef
{
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
  uint32 uVersionNumber;           /*!< FCTSenSyncRef Version number */
#endif
  SignalHeader_t sSigHeader;      /*!<sSigHeader */
#if (FCT_CFG_USE_BASECTRLDATA)
  BaseCtrlData_t sBaseCtrl;       /*!< sBaseCtrl */
#endif
  SignalHeader_t SenCtrlData;     /*!< SenCtrlData */
#if(!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  SignalHeader_t EgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
#endif
  SignalHeader_t EgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  SignalHeader_t EgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  SignalHeader_t EmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
  SignalHeader_t EmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  SignalHeader_t EmCustObjList;   /*!< EM customer specific object list */
#endif
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SignalHeader_t EmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  SignalHeader_t EmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
  SignalHeader_t EmSRRObjList;    /*!< EM SRR-technology-specific object list */
  SignalHeader_t EmGlobalOutput;  /*!< EM Global data */
#endif
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  SignalHeader_t MovObjTraces;    /*!< Moving object traces */
#endif
#if (FCT_CFG_NEW_TRACES_INTERFACE)
  SignalHeader_t ObjectTraces;    /*!< New object traces */
#endif
#endif
#if (FCT_CFG_RSP_OUTPUT_PD)
  SignalHeader_t RSPOutputPD;     /*!< RSP roadbeam information */
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SignalHeader_t PerfDegrData;    /*!< Performance degradation input data */
#endif
#if (FCT_CFG_ROAD_INPUT)
  SignalHeader_t RoadData;        /*!< Road/lane information */
#endif
#if (FCT_CFG_RSP_CONTEXT_INPUT)
  SignalHeader_t RSPContextData;  /*!< RSP Kontext data */
#endif
#if (FCT_CFG_LOPC_COMPONENT)
  /* Longitudinal control input ports */
  SignalHeader_t FctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  SignalHeader_t FCTCustomInput;  /*!< Custom input */
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) && ((!FCT_USE_EM_CUSTOM_OBJECT_LIST))) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  SignalHeader_t CameraObjData;   /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t AlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t VehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  SignalHeader_t ME_in;             /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  SignalHeader_t BswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CPAR_FCT_Parameters;  /*!< FCT Coding Parameters */
#endif
#if ((FCT_CFG_PERF_DEGR_EXT_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Macom SRD blockage info for SPM */
  SignalHeader_t PerfDegrExtInput;   /*!< Performance degradation external input (short range sensor info) */
#endif
#if ((FCT_CFG_DIM_OUTPUT_CUSTOM_FCT_SEN_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t DIMOutputCustom;   /*!< DIM output custom from FCT_VEH */
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t NaviData;          /*!< Simple navi input data */
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamLaneData;       /*!< Camera lane input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  SignalHeader_t EmFusionObjList;   /*!< EM Fusion Object List */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamTSAInputData; /*! TSA input data from camera */
#endif
#if ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamSLAInputData;   /*!< SLA input data from camera */
#endif
#if (FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)
  SignalHeader_t t_SH_LongCtrlResp;
  SignalHeader_t t_FCT_IN_SH_TCCP;   /* Command Input from ISC to LOHP */
  SignalHeader_t t_FCT_IN_SH_TFSP;   /* Status Input from LOPC to LOHP */
#endif
}
FCTSen_SyncRef_t;

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

/*! Main FCT_SEN Process function */


#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void FCTSen_Exec(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts, const AS_t_ServiceFuncts *pServiceFuncts);
#else/*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/
extern void FCTSen_Exec(const reqFCTSenPrtList_t * pRequirePorts, const proFCTSenPrtList_t * pProvidePorts);
#endif/*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/

#ifdef __cplusplus
}
#endif

#endif /* _FCT_SEN_EXT_H_INCLUDED */
/** @} end defgroup */
