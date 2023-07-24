/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               slate_ext.h

DESCRIPTION:               External header file for Adaptive Cruise Control (ACC) object evaluation module in SLATE task

AUTHOR:                    $Author: P, Gowthama (uib47932) (uib47932) $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.40 $

LEGACY VERSION:            Revision: 2.42

**************************************************************************** */
#ifndef SLATE_EXT_INCLUDED
#define SLATE_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_sen_ext.h"
#if (FCT_CFG_ADAPTIVE_CRUISE_CONTROL)
#include "slate_types.h"
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
  /**
  @addtogroup slate
  @{ */ 

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/
/*! configuration switch for enabling absolute speed calculation
per object in SI */
#define SIT_CFG_FILTER_ABS_OBJ_SPEED               SWITCH_ON  /*Moved from fip_custom_ext.h*/
/*! configuration switch for enabling filtered absolute acceleration
calculation per object in SI */
#define SIT_CFG_FILTER_ABS_OBJ_ACCEL               SWITCH_ON /*Moved from fip_custom_ext.h*/ 
/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

#ifndef FCT_MEAS_ID_SEN_ACC_INPUT_SIGHEADERS
#define FCT_MEAS_ID_SEN_ACC_INPUT_SIGHEADERS (0x20270508u)//FCT_MEAS_ID_SEN_INPUT_SIGHEADERS	(0x20270400u)
#endif

/*SI*/
/*! defines the number of objects of interest*/
#define OOI_NUMBER_OF_OOI 6

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/
/*! Lane change phase */
typedef enum SLATE_LC_LaneChangePhase{
  SLATE_LC_NO_LANECHANGE = 0,        /*!< no lane change possible or intended */
  SLATE_LC_PRELANECHANGE = 1,         /*!< lane change possible or might be intended by driver */
  SLATE_LC_LANECHANGE = 2,            /*!< Lane change underway */
  SLATE_LC_STEERBACK = 3              /*!< Lane change steerback underway */
} SLATE_LC_LaneChangePhase_t_e;

/*!< Information for lane change */
typedef struct SLATE_LC_LaneChangePhaseInfo{
  SLATE_LC_Direction_t_e e_LCDirection;         /*!< Lane change direction */
  SLATE_LC_LaneChangePhase_t_e e_LCPhase;       /*!< Lane change phase */
  uint8 u_LCPhaseProb;                          /*!< Lane change probability */
  boolean b_AllowOvertake;                      /*!< Boolean to indicate overtake support is possible */
}SLATE_LC_LaneChangePhaseInfo_t;

#if (FCT_CFG_LOHP_COMPONENT)
#if (FCT_CFG_ACC_PERF_MONITORING)
typedef struct APM_HC_Data{
  float32 f_MaxDistPerfMin;
  float32 f_MaxDistALN;
}APM_HC_Data_t;
#endif


typedef struct SLATE_HC_Data
{
  unsigned long uiVersionNumber;
  SignalHeader_t sSigHeader;

#if (FCT_CFG_ACC_PERF_MONITORING)
  APM_HC_Data_t t_APM_Data;
#endif
  eRelObjLossReason_t t_ObjLossReasonACCOOI[OOI_NUMBER_OF_OOI];
  SLATE_LC_LaneChangePhaseInfo_t t_SLATE_LC;
#if (SLATE_CFG_PARALLEL_LANE_CHANGE) 
  SLATE_LC_Direction_t_e t_OOILCState[OOI_NUMBER_OF_OOI];
#endif /* (SLATE_CFG_PARALLEL_LANE_CHANGE) */ 
#if (OUT_CFG_FUNC_LANEASSOC_LA)
  eAssociatedLane_t t_FuncLaneAss_LC[OOI_NUMBER_OF_OOI];
#endif /* OUT_CFG_FUNC_LANEASSOC_LA */
}SLATE_HC_Data_t;
#endif

/*! Typedef of object specific output of FIP Object attributes */
typedef struct SLATE_FIP_OAObj_Output{
  float32 fWidth;   /*Length of object using camera shape points*/
}SLATE_FIP_OAObj_Output_t;

#if (FCT_CFG_SIGNAL_PERF_MONITORING)
typedef struct SLATE_SPM_Data{
  unsigned long uiVersionNumber;
  SignalHeader_t sSigHeader;
  ubit32_t FctPreselTGACCLastRelObj;
  //ObjNumber_t t_ACCRelObjID;
  eRelObjLossReason_t t_ObjLossReasonACCRelObj;
  SLATE_FIP_OAObj_Output_t t_ObjList[EM_N_OBJECTS]; /*!< Object specific output of FIP Object attributes */
  float32 f_Dist2TrajACCRelObj;
  float32 f_Dist2TrajVarACCRelObj;
//#define SPM_OBJ_GET_OOI_POS(iObj)                 FCTSEN_pSPMPubFctObj->ObjList[iObj].ObjOfInterest.eObjOOI // SPM, ACC, Simulation
//#define SPM_OBJ_GET_OOI_LIST_OBJ_IDX(iOoiPos)     FCTSEN_pSPMPubFctObj->HeaderAssessedObjList.aiOOIList[iOoiPos] // SPM, ACC, Sim
}SLATE_SPM_Data_t;
#endif

/*! ACC provide ports struct */
typedef struct SLATEProPort{
#if (FCT_CFG_ERROR_OUTPUT_SEN)
  SLATEErrorOutProPort_t * pt_SLATEErrorOut;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pSenCompState;  /*!< AlgoCompState interface to scheduler */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  AssessedObjList_t           * pPubFctObj;         /*!< The public FCT object data */
#endif
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF) || (FCT_CFG_SHORT_RANGE_FUNCTIONS))
  /* customer specific input/output */
  FCTCustomOutput_t           * pFCTCustomOutput;   /*!< Custom output */
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
  BusDebugData_t              * pFCTSenBusDebugData; /*!< Debug data */
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  FCTSenAccOOI_t             * pFCTAccOOIData; /* FCT OOI Objects */
#endif
#if (FCT_CFG_SEN2TJA_ACC_OOI_PORT)
  TJATargetObj_t * pFCTTJAOOIData;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  SLATE_HC_Data_t             * pSLATE_HC_Data; //shang 26.01.2016 intermedia soultion and later need to remane
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  SLATE_SPM_Data_t * pSLATE_SPM_Data;
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  SLATE_CD_Data_t * pSLATE_CD_Data;
#endif
#if (FCT_CFG_SLA_FEATURE)
  SLAData_t                 * pSLAData;   /*!< SLA speed limit data from FCT_SEN */
#endif
}provSLATEPortList_t;


/*! Inputs required by ACC component for sensor cycle processing */
typedef struct reqSLATEPortList{
#if (FCT_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t        * pSenCtrlData;        /*!< FCT control data */
#else
  const FCTCtrlData_t         * pSenCtrlData;        /*!< FCT control data */
#endif
#if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  const VehDyn_t              * pEgoDynObjSync;   /*!< The dynamic vehicle ego data object sync */
#endif
  const VehDyn_t              * pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  const VehPar_t              * pEgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  const EmFctCycleMode_t      * pEmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)

  const EM_t_GenObjectList    * pEmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_CUSTOM_OBJECT_LIST)
  const EM_t_ObjectList_Custom  * pEmCustObjList;   /*!< EM customer specific object list */
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
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  const FCTCustomInput_t        * pFCTCustomInput;  /*!< Custom input */
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) &&  (!FCT_USE_EM_CUSTOM_OBJECT_LIST)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  const EM_t_ObjectList_Custom  * pCameraObjData;   /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const ALN_S_Monitoring_t      * pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  const ME_in_t                 * pME_in;             /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  const BSW_s_AlgoParameters_t  * pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const t_NaviInputData         * pNaviData;          /*!< Simple navi input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  const EM_t_FusionObjectList   * pEmFusionObjList; /* EM Fusion Object List */
#endif
#if ((SLATE_CFG_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const t_CamLaneInputData      * pCamLaneData;       /*!< Camera lane input data */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const TSA_SLATE_Input_t       * pTSAInputData;      /*!< TSA input data from camera */
#elif ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER) && (FCT_CFG_TSA_INTF)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const CamSLAInputData_t       * pCamSLAInputData;   /*!< SLA input data from camera */
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
  const LongCtrlInput_t         * pLongCtrlResp;      /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
} reqSLATEPortList_t;


/*! @brief Simulation sync structure contains Signal Headers of every Input Port */
typedef struct SLATESyncRef {
//#if (FCT_CFG_SHORT_RANGE_FUNCTIONS)
//  uint32 uVersionNumber;           /*!< FCTSenSyncRef Version number */
//#endif
  SignalHeader_t sSigHeader;      /*!<sSigHeader */
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
#if (FCT_CFG_USE_EM_MOVING_OBJECT_TRACES)
  SignalHeader_t MovObjTraces;    /*!< Moving object traces */
#endif
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
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* customer specific input/output */
  SignalHeader_t FCTCustomInput;  /*!< Custom input */
#endif
#if (((FCT_CFG_CAMERA_OBJECT_DETECTION) &&  (!FCT_USE_EM_CUSTOM_OBJECT_LIST)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Fusion output information from camera */
  SignalHeader_t CameraObjData;   /*!< EM Camera fusion output data */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t AlignmentMonInput; /*!< Alignment monitoring output data */
#endif
//#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
//  SignalHeader_t VehSig;            /*!< Direct access to vehicle signals */
//#endif
#if ((FCT_CFG_ME_INPUT_FOR_DEBUG) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Mobil-eye raw input for debugging */
  SignalHeader_t ME_in;             /*!< Input from mobil-eye directly for debugging */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  SignalHeader_t BswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t NaviData;          /*!< Simple navi input data */
#endif
#if (FCT_CFG_INCLUDE_FUSION_OBJECT_LIST)
  SignalHeader_t EmFusionObjList;     /*!< Em fusion object list */
#endif
#if ((FCT_CFG_SEN_CAM_LANE_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamLaneData;       /*!< Camera lane input data */
#endif
#if ((defined(TSA_SLATE_INPUT_ENABLE) && defined(TSA_SLATE_Input_INTFVER)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamTSAInputData;   /*!< TSA input data from camera */
#elif ((FCT_CFG_LONG_CTRL_SLA_SUPPORT && defined(CamSLAInputData_INTFVER)) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CamSLAInputData;   /*!< SLA input data from camera */
#endif
#if ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT))
  SignalHeader_t LongCtrlResp;      /* Dynamic controller response, in SLATE currently used to get drivemode input */
#endif /* ((FCT_CFG_ACT_CODE_VERSION) && (FCT_CFG_LOHP_COMPONENT)) */
} SLATESyncRef_t;

/*! 6 object interface object enumeration, aliasing RTE type */
typedef eObjOOI_t SIRelObjEnum_t;

#if 0
/*! @brief CPTrajectoryConfig_t */
typedef struct  // PRQA S 635
{ /* date: 2015-09-23, reviewer: Harsha Umesh Babu, reason: Project specific type definition */
  ubit8_t UseRoadEstim  : 1;  /*!< Bit indicating if road estimation shall be used for fusion */
  ubit8_t UseObjTraces  : 1;  /*!< Bit indicating if object traces shall be used for fusion */
#if (CP_CFG_LANE_CHG_CAM_FUSION) 
  ubit8_t UseCamLane    : 1;  /*!< Bit indicating if camera lane shall be used for trajectory fusion */
#endif
#if (FCT_CFG_SEN_SIMPLE_NAVI_INTERFACE) && (FCT_CFG_INPUT_PREPROCESSSING)
  ubit8_t UseNaviPath   : 1; /*!< Bit indicating if Navi path shall be used for trajectory fusion */
#endif
} CPTrajectoryConfig_t; // EBA

/*! @brief CPTrajectoryState_t */
typedef struct // PRQA S 635
{ /* date: 2015-09-23, reviewer: Harsha Umesh Babu, reason: Project specific type definition */
  /* !!!ATTENTION!!! Do not change order of bitfield entries because of initialization downward compatibility */
  ubit16_t EgoCourseOnly             : 1;  /*!< Bit indicating that only ego course used for trajectory (fusion off) */
  ubit16_t FusionRoadstimation       : 1;  /*!< Bit indicating that RE is used for trajectory fusion */
  ubit16_t FusionTraces              : 1;  /*!< Bit indicating that Traces are used for trajectory fusion */
  ubit16_t FusionTraceHystEgoSpeed   : 1;  /*!< Bit indicating that ego speed is sufficient for Traces fusion */
  ubit16_t FusionHystLRoadRangeConf  : 1;  /*!< Bit indicating that features from left side of road estimation fulfill fusion criteria */
  ubit16_t FusionHystRRoadRangeConf  : 1;  /*!< Bit indicating that features from right side of road estimation fulfill fusion criteria */
  ubit16_t FusionHystEgoSpeed        : 1;  /*!< Bit indicating that ego speed fusion criteria is fulfilled */
  ubit16_t FusionHystEgoRadius       : 1;  /*!< Bit indicating that ego radius fusion criteria is fulfilled */
  ubit16_t FusTraceCrit              : 1;  /*!< Bit set when if CPMOTraceFusionCriterion returns TRUE */
  ubit16_t FusionPlaus               : 1;  /*!< Bit to non-zero if CPFusionPlausibilityCheck returns TRUE */
  ubit16_t CamLaneQualityHigh        : 1;  /*!< Bit indicating if camera lane foresight/quality criteria met */
  ubit16_t CamLaneFusion             : 1;  /*!< Bit when camera lane fusion is active */
  ubit16_t NaviPathFusion            : 1;  /*!< Bit when navi path fusion is active */
} CPTrajectoryState_t; // EBA

/*! @brief CPTrajectoryMeas_t */
typedef struct CPTrajectoryMeas
{
  float32 fx;/*!<fx */
  float32 fy;/*!<fy */
  float32 fphi;/*!<fphi */
  float32 fc0;/*!<fc0 */
  float32 fc1;/*!<fc1 */
  CPTrajectoryConfig_t  Config;/*!<Config */
  CPTrajectoryState_t   State;/*!<State */
} CPTrajectoryMeas_t; // EBA

/*! @brief Structure used to freeze course data for a given component */
typedef struct CPTrajMeasInfo
{
  CPTrajectoryMeas_t  Trajectory;/*!<Trajectory */
  CPTrajectoryMeas_t  FiltCourse;/*!<FiltCourse */
  float32             LaneWidth;/*!<LaneWidth */
} CPTrajMeasInfo_t; // EBA
#endif /* Used in EBA only */

/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- slate_obj_main.c ---*/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void SLATE_v_Exec(const reqSLATEPortList_t * p_SLATERequirePorts, provSLATEPortList_t * p_SLATEProvidePorts, const AS_t_ServiceFuncts *p_ServiceFuncts, FCTSenFrame_t * p_FCTSenFrame);
#else
extern void SLATE_v_Exec(const reqSLATEPortList_t * p_SLATERequirePorts, provSLATEPortList_t * p_SLATEProvidePorts, FCTSenFrame_t * p_FCTSenFrame);
#endif

extern void SLATE_v_AlgoInit(void);

#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_ADAPTIVE_CRUISE_CONTROL */
/// @} 
/* End of conditional inclusion */

#endif  /*!< _SLATE_EXT_INCLUDED */


