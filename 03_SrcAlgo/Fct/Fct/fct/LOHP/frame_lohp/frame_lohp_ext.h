/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_ext.h

DESCRIPTION:               External header file for LOHP frame functions

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.21 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */

#ifndef _FRAME_LOHP_EXT_INCLUDED
#define _FRAME_LOHP_EXT_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lohp_base_frame LOHP_Base_Frame
@ingroup    lohp_base
@brief      Module for generic/frame files
 */

/*!
@defgroup   lohp_base_lohp LOHP_Base_Module
@ingroup    lohp_base
@brief      Module for base function files
 */

/*!
@defgroup   frame_lohp_ext_h Frame_lohp_ext_h
@ingroup    lohp_base_frame
@brief      Main external header file for LOHP component
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_sen_ext.h"
#include "frame_lohp_types.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef FCT_MEAS_ID_LOHP_INPUT_SIGHEADERS
#define FCT_MEAS_ID_LOHP_INPUT_SIGHEADERS (0x20270720u)//FCT_MEAS_ID_SEN_INPUT_SIGHEADERS	(0x20270400u) 0x2027058B
#endif

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

/*! LOHP required port struct */
typedef struct
{
  const FCTCtrlData_t                   *pt_LOHP_IN_Ctrl;

  const TargetControlCommandPort_t      *pt_LOHP_IN_TCCP;

  const LongCtrlInput_t                 *pt_LOHP_IN_EgoVehDynCtrl;
  const VehDyn_t                        *pt_LOHP_IN_EgoVehDynState;
  const FCTSenAccOOI_t                  *pt_LOHP_IN_TarVehDynState;
  const SLATE_HC_Data_t                 *pt_LOHP_IN_HC_Data;
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const SysPerfMonStates_t              *pt_LOHP_IN_SysPerfMonitor;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  const TargetFollowStatePort_t  *pt_LOHP_IN_TFSP;
#endif
}
LOHP_ReqPortList_t;


/*! LOHP provide port struct */
typedef struct
{
  TargetControlStatePort_t          *pt_LOHP_OUT_TCSP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
  TargetFollowCommandPort_t      *pt_LOHP_OUT_TFCP;
#endif
}
LOHP_ProPortList_t;


/*! LOHP Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct
{
  SignalHeader_t sSigHeader;       /*!< SigHeader */
  SignalHeader_t t_SH_CTRL;         /*!< Signal Header of control port */

  SignalHeader_t t_LOHP_IN_TCCP;    /* Signal Header of LOHP TargetControlCommandPort */

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SignalHeader_t t_LOHP_IN_TFSP;    /* Signal Header of LOHP TargetFollowStatePort */
#endif

  SignalHeader_t t_EgoVehDynCtrl;   /*!< The ego vehicle DMC data */
  SignalHeader_t t_EgoVehDynState;  /*!< The ego vehicle VDY data */
  SignalHeader_t t_TarVehDynState;  /*!< The target vehicles OOI data */
}
LOHP_SyncRef_t;

#else   /* GEN 3 */

/*! ACC provide ports struct */
typedef struct LOHPProPort{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pSenCompState;  /*!< AlgoCompState interface to scheduler */
#endif
  acc_object_t                * pAccDisplayObj;     /*!< ACC_DISPLAY_OBJECT output from FCT_SEN */
  acc_output_data_t           * pAccOutput;         /*!< ACC_OUTPUT_DATA from FCT_SEN */
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  LOHP_ObjUsageState_t        * pLOHPUsageState;   /* Object Ids of relevant objects */
#endif
}LOHPProPort_t;


/*! Inputs required by ACC component for sensor cycle processing */
typedef struct reqLOHPPrtList{
  const FCTCtrlData_t           * pSenCtrlData;        /*!< FCT control data */
  const VehDyn_t                * pEgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  const VehPar_t                * pEgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  const EmFctCycleMode_t        * pEmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  const EM_t_GenObjectList      * pEmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  const EM_t_ARSObjectList      * pEmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  const EM_t_CamObjectList      * pEmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#else
  const ObjectList_t            * pPubEmObj;        /*!< The public EM object data */
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  const AssessedObjList_t       * pPubFctObj;
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  const FCTSenAccOOI_t          * pFCTAccOOIData; /* FCT OOI Objects */
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  const FctVeh2SenInfo_t        * pFctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const ALN_S_Monitoring_t      * pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const VehSig_t                * pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  const BSW_s_AlgoParameters_t  * pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if (FCT_CFG_CUSTOM_IO_INTERFACE)
  const FCTCustomInput_t        * pFCTCustomInput;  /*!< customer specific input */
#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
  const FCTCustomOutput_t       * pFCTCustomOutput;   /*!< Custom output (input to LOHP) */
#endif
#endif
#if (FCT_CFG_SLATE_COMPONENT)
  const SLATE_HC_Data_t         * pSLATE_HC_Data;
#endif
#if (FCT_CFG_SIGNAL_PERF_MONITORING)
  const SysPerfMonStates_t      * pSysPerfMonStates;  /*!< System performance monitor output data */
#endif
} reqLOHPPrtList_t;


/*! @brief Simulation sync structure contains Signal Headers of every Input Port */
typedef struct LOHP_SyncRef {
  SignalHeader_t sSigHeader;      /*!<sSigHeader */
  SignalHeader_t SenCtrlData;     /*!< SenCtrlData */
  SignalHeader_t EgoDynRaw;       /*!< The dynamic vehicle ego data raw */
  SignalHeader_t EgoStaticData;   /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
  SignalHeader_t EmFctCycleMode;  /*!< The global sensor state */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
  SignalHeader_t EmGenObjList;    /*!< EM generic object list */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  SignalHeader_t EmARSObjList;    /*!< EM ARS-technology-specific object list */
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  SignalHeader_t EmCamObjList;    /*!< EM Camera-technology-specific object list */
#endif
#else
  SignalHeader_t PubEmObj;        /*!< The public EM object data */
#endif
#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
  SignalHeader_t PubFctObj;       
#endif
#endif
#if (FCT_CFG_LOPC_COMPONENT)
  /* Longitudinal control input ports */
  SignalHeader_t FctVehLongOut; /*!< Internal communication struct from FCT_VEH to FCT_SEN */
#endif
#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t AlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t VehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  SignalHeader_t BswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC))
  SignalHeader_t FCTCustomOutput;   /*!< Custom output (input to LOHP) */
#endif
} LOHP_SyncRef_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */

/*****************************************************************************
  CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

/*--- frame_lohp_main.c ---*/

#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void LOHP_v_Exec(const LOHP_ReqPortList_t *p_RequirePorts, const LOHP_ProPortList_t *p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame, const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
extern void LOHP_v_Exec(const LOHP_ReqPortList_t *p_RequirePorts, const LOHP_ProPortList_t *p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame);
#endif

extern void LOHP_v_AlgoInit(void);

#else   /* GEN 3 */

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void LOHP_v_Exec(const reqLOHPPrtList_t * p_RequirePorts, const LOHPProPort_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame, const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
extern void LOHP_v_Exec(const reqLOHPPrtList_t * p_RequirePorts, const LOHPProPort_t * p_ProvidePorts, const FCTSenFrame_t * p_FCTSenFrame);
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */

#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT)) */

/** @} end defgroup */

#endif  /*!< _FRAME_LOHP_EXT_INCLUDED */

