/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP (Adaptive Cruise Control - Longitudinal Headway Planner)

PACKAGENAME:               frame_lohp_access_func.h

DESCRIPTION:               Definitions of inline functions to access global data in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             08.02.2018

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            None
**************************************************************************** */

#ifndef _FRAME_LOHP_ACCESS_FUNC_INCLUDED
#define _FRAME_LOHP_ACCESS_FUNC_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   frame_lohp_accessfunc Frame_lohp_accessfunctions
@ingroup    lohp_base_frame
@brief      Access functions for LOHP
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lohp_types.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT))
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
 APPLICATION PARAMETERS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

extern MEMSEC_REF LOHPFrame_t t_LOHPFrame;

extern MEMSEC_REF LOHP_SyncRef_t t_LOHP_SyncRef;

extern MEMSEC_REF boolean b_LOHPIsInitialized;

#if (FCT_CFG_RUNTIME_MEAS)
/* External declaration of FCT ACC runtime measurement info */
extern MEMSEC_REF FCT_HCRuntimeInfo_t t_LOHP_RuntimeInfo;
#endif

/*! sub-module state */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern MEMSEC_REF const AS_t_ServiceFuncts *LOHP_pServiceFuncts;
#endif


#if (FCT_CFG_ACT_CODE_VERSION)  /* GEN 4 */

#else   /* GEN 3 */

extern MEMSEC_REF const FCTCtrlData_t          * LOHP_pSenCtrlData;      /*!< Pointer to FCT control data */
extern MEMSEC_REF const VehDyn_t               * LOHP_pEgoDynRaw;        /*!< The dynamic vehicle ego data raw */
extern MEMSEC_REF const VehPar_t               * LOHP_pGlobEgoStatic;    /*!< the static vehicle ego data */
#if (FCT_CFG_EM_FCT_CYCLEMODE)
extern MEMSEC_REF const EmFctCycleMode_t       * LOHP_pEmFctCycleMode;   /*!< Global system cycle mode etc. data */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
extern MEMSEC_REF const BSW_s_AlgoParameters_t  * LOHP_pBswAlgoParameters; /*!< Input algo parameters from BSW */
#endif
#if (FCT_CFG_OBJECT_LIST_PROC)
#if (FCT_USE_EM_GENERIC_OBJECT_LIST)
extern MEMSEC_REF const EM_t_GenObjectList     * LOHP_pEmGenObjList;     /*!< The generic EM object data */
#if (FCT_USE_EM_ARS_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_ARSObjectList     * LOHP_pEmARSObjList;
#endif
#if (FCT_USE_EM_CAM_TECH_OBJECT_LIST)
extern MEMSEC_REF const EM_t_CamObjectList     * LOHP_pEmCamObjList;
#endif
#else
extern MEMSEC_REF const ObjectList_t            * LOHP_pEmObjList;
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
/* Provide OOI Objects from SEN to VEH */
extern MEMSEC_REF const FCTSenAccOOI_t          * LOHP_pAccOOIData;
#endif
#if ((FCT_CFG_LOHP_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
/* Longitudinal control input ports */
extern MEMSEC_REF const FctVeh2SenInfo_t         * LOHP_pFctVehLongOut;
#endif

#if ((FCT_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
extern MEMSEC_REF const ALN_S_Monitoring_t     * LOHP_pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif

#if ((FCT_SEN_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
extern MEMSEC_REF const VehSig_t             * LOHP_pVehSig;
#endif

#if (FCT_CFG_ASSESSED_OBJ_OUT_INTF)
extern MEMSEC_REF  const AssessedObjList_t       * LOHP_pPubFctObjList;
#endif
#endif


#if (FCT_CFG_CUSTOM_IO_INTERFACE)

#if (FCT_CFG_CUSTOM_IO_ABS_KINEMATIC)
extern MEMSEC_REF const FCTCustomOutput_t        * LOHP_pCustomOutputInput;     /*!< FCT custom output */
#endif
#endif

#if (FCT_CFG_SLATE_COMPONENT)
extern MEMSEC_REF const SLATE_HC_Data_t     * LOHP_pSLATEData;
#endif

#if (FCT_CFG_CUSTOM_IO_INTERFACE)
extern MEMSEC_REF const FCTCustomInput_t          * LOHP_pCustomInput;
#endif

/* Provide ports */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
extern MEMSEC_REF AlgoCompState_t             * LOHP_pCompState;
#endif
extern MEMSEC_REF acc_object_t                * LOHP_pAccDisplayObj;
extern MEMSEC_REF acc_output_data_t           * LOHP_pAccOutput;
#if (FCT_CFG_USE_BUS_DEBUG)
extern MEMSEC_REF BusDebugData_t              * LOHP_pBusDebugData;
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */
/*****************************************************************************
  STATIC FUNCTION PROTOTYPES
*****************************************************************************/

/*****************************************************************************
  NON-STATIC FUNCTIONs
*****************************************************************************/

/*****************************************************************************
  STATIC FUNCTIONs
*****************************************************************************/



#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOHP_COMPONENT) */

/** @} end defgroup */

/* End of conditional inclusion */
#endif  /*!< _FRAME_LOHP_INCLUDED */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
