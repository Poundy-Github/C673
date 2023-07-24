/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller))

PACKAGENAME:               frame_lopc_ext.h

DESCRIPTION:               External header file for frame lopc

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.21 $

LEGACY VERSION:            Revision: 2.3

**************************************************************************** */
#ifndef FRAME_LOPC_EXT_H
#define FRAME_LOPC_EXT_H

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   lopc_base_frame LOPC_Base_Frame
@ingroup    lopc_base
@brief      Module for generic/frame files
 */

/*!
@defgroup   lopc_base_lopc LOPC_Base_Module
@ingroup    lopc_base
@brief      Module for base function files
 */

/*!
@defgroup   frame_lopc_ext_h Frame_lopc_ext_h
@ingroup    lopc_base_frame
@brief      Main external header file for LOPC
@{ */ 


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_lopc_types.h"

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_ERROR_OUTPUT_VEH)
#ifndef FCT_MEAS_ID_LOPC_ERROR_OUT
#define FCT_MEAS_ID_LOPC_ERROR_OUT        (0x20274700u)
#endif
#endif

#ifndef FCT_MEAS_ID_LOPC_OUT_EVCP
#define FCT_MEAS_ID_LOPC_OUT_EVCP         (0x20021200u)
#endif

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! LOPC provide ports struct */
#if (FCT_CFG_ACT_CODE_VERSION)

typedef struct
{
#if (ACT_CFG_CC_VSC_PORT_CNT)
  ACT_CC_VehicleSpeedStatePort_t *pt_LOPC_OUT_CC_VSSP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  ACT_SLA_VehicleSpeedStatePort_t *pt_LOPC_OUT_SLA_VSSP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  ACT_SLA_DistanceSpeedStatePort_t *pt_LOPC_OUT_SLA_DSSP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  ACT_CP_DistanceCurveStatePort_t *pt_LOPC_OUT_CP_DCSP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  TargetFollowStatePort_t *pt_LOPC_OUT_HP_TFSP;
#endif

  ACT_LogicVehicleStatePort_t *pt_LOPC_OUT_LVSP;
  ACT_EgoVehicleCommandPort_t *pt_LOPC_OUT_EVCP;
}
LOPC_ProPortList_t;

#else /* Legacy code */

typedef struct LOPCErrorOut_t{
  SignalHeader_t sSigHeader;
  AlgoErrorState_t VehicleSpeedUnplausible;
  AlgoErrorState_t PortError;
}LOPCErrorOut_t;

typedef struct
{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pVehCompState;  /*!< AlgoCompState interface to scheduler */
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  FctVeh2SenInfo_t            * pFctVehLongOut;   /*!< Internal info passed from FCT_VEH to FCT_SEN */
#endif
  LongCtrlOutput_t            * pLongCtrlOutput;  /*!< Longitudinal controller output data */
#if (FCT_CFG_TCI)
  TCIOutput_t                 * pTCIOutput;  /*!< Output for TCI Feature */
#endif  
#endif /* FCT_CFG_LOPC_COMPONENT */
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  LOPCErrorOut_t              * pErrorOut;          /*!< LOPC error output */
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  FCTVehOutArbitrated_t       * pFCTVehOutArbitrated; /*!< Arbitrated output for vehicle functions */
#endif
#if ((!FCT_CFG_INCLUDE_UNUSED_INTF) && (!FCT_CFG_LOPC_COMPONENT))
#if !defined(__NO_ARS_COMPILER_MESSAGES)
#pragma COMPILEMSG("Find more elegant way of disabling FCT_VEH when not needed!")// PRQA S 3116
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Non QAC Related*/
#endif
  uint8 dummy;
#endif
} LOPC_ProPortList_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */


/*! LOPC required port struct  Inputs required by LOPC component for vehicle cycle processing */
#if (FCT_CFG_ACT_CODE_VERSION)

typedef struct
{
#if (ACT_CFG_CC_VSC_PORT_CNT)
  const ACT_CC_VehicleSpeedCommandPort_t *pt_LOPC_IN_CC_VSCP;
#endif

#if (ACT_CFG_SLA_VSC_PORT_CNT)
  const ACT_SLA_VehicleSpeedCommandPort_t *pt_LOPC_IN_SLA_VSCP;
#endif

#if (ACT_CFG_SLA_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  const ACT_SLA_DistanceSpeedCommandPort_t *pt_LOPC_IN_SLA_DSCP;
#endif

#if (ACT_CFG_CP_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  const ACT_CP_DistanceCurveCommandPort_t *pt_LOPC_IN_CP_DCCP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  const TargetFollowCommandPort_t *pt_LOPC_IN_HP_TFCP;
#endif

  const ACT_LogicVehicleCommandPort_t *pt_LOPC_IN_LVCP;

  const LongCtrlInput_t *pt_LOPC_IN_EgoVehDynCtrl;
  const VehDyn_t        *pt_LOPC_IN_EgoVehDynState;
  const FCTCtrlData_t   *pt_LOPC_IN_Ctrl;
}
LOPC_ReqPortList_t;

#else /* Legacy code */

typedef struct
{
  const FCTCtrlData_t               * pVehCtrlData;       /*!< FCT_VEH operation mode control data */
  const VehDyn_t                    * pEgoDynRaw;         /*!< The dynamic vehicle ego data raw */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  const AccLeverInput_t       * pAccLever;          /*!< ACC lever information (input from driver) */
  const LongCtrlInput_t       * pLongCtrlResp;      /*!< Dynamic controller response */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  const acc_object_t          * pAccDisplayObj;     /*!< Display object data output by FCT_SEN */
  const acc_output_data_t     * pAccOutput;         /*!< ACC output data by FCT_SEN */
#endif
#if (FCT_CFG_TCI)
  const TCIInput_t            * pTCIInput;  /*!< Input for TCI Feature */
#endif
#if (FCT_CFG_SLA_FEATURE)
  const SLAData_t             * pSLAData;           /*!< SLA speed limit data from FCT_SEN */
#endif
#endif /* FCT_CFG_LOPC_COMPONENT */
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const VehSig_t              * pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const FCTSenAccOOI_t        * pAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  const FCTVehCustomInput_t   * pFctVehCustInput;   /*!< Custom input for FCT_VEH */
#endif
#if(FCT_CFG_BSW_ALGO_PARAMS)
  const BSW_s_AlgoParameters_t* pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  const Lodmc_output_t        * pLoDmcOutput;      /*Lodmc output for LOPC */
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
  const HEADOutputCustom_t    * pHEADOutputCustom;  /*HEAD output for LOPC */
#endif
} LOPC_ReqPortList_t;

#endif /* FCT_CFG_ACT_CODE_VERSION */


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void LOPC_v_Exec(const LOPC_ReqPortList_t * p_RequirePorts, const LOPC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode, const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
extern void LOPC_v_Exec(const LOPC_ReqPortList_t * p_RequirePorts, const LOPC_ProPortList_t * p_ProvidePorts, const FCT_OP_MODE_t t_OpMode);
#endif

#ifdef __cplusplus
};
#endif

#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

/** @} end defgroup */

#endif  /*!< FRAME_LOPC_EXT_H */

