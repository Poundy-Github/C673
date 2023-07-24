/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTVEH (Frame Vehicle)

PACKAGENAME:               fct_veh_ext.h

DESCRIPTION:               FCT Component external header file for FCTVEH

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.20 $

LEGACY VERSION:            Revision: 1.59
    
**************************************************************************** */

#ifndef FCT_VEH_EXT_H_INCLUDED
/*!
  @defgroup fct_veh FCT_VEH

  @ingroup sim_swc_fct

  Receives input data as explicit parameter passed to the main FCTSen_Exec
  function. This function also gets pointers to all output parameters.

  fct_veh revise naming of functions and component itself.

@{ */
#define FCT_VEH_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_glob_ext.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN 
*****************************************************************************/

/* Workaround, shall be removed if available in RTE for all projects */
#ifndef FCT_CFG_SEN2VEH_ACC_OOI_PORT
#define FCT_CFG_SEN2VEH_ACC_OOI_PORT SWITCH_OFF
#endif

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*! Inputs required by FCT component for vehicle cycle processing */
typedef struct
{
#if (FCT_CFG_USE_BASECTRLDATA)
  const BaseCtrlData_t        * pVehCtrlData;       /*!< FCT_VEH operation mode control data */
#else
  const FCTCtrlData_t         * pVehCtrlData;       /*!< FCT_VEH operation mode control data */
#endif
  const VehDyn_t              * pEgoDynRaw;         /*!< The dynamic vehicle ego data raw */
  const VehPar_t              * pEgoStaticData;     /*!< the static vehicle ego data */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  const AccLeverInput_t       * pAccLever;          /*!< ACC lever information (input from driver) */
  const LongCtrlInput_t       * pLongCtrlResp;      /*!< Dynamic controller response */
  const acc_object_t          * pAccDisplayObj;     /*!< Display object data output by FCT_SEN */
  const acc_output_data_t     * pAccOutput;         /*!< ACC output data by FCT_SEN */
#if (FCT_CFG_TCI)
  const TCIInput_t            * pTCIInput;          /*!< Input for TCI Feature */
#endif
#if (FCT_CFG_SLA_FEATURE)
  const SLAData_t             * pSLAData;           /*!< Speed limit input for SLA Feature */
#endif
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const FCTSenAccOOI_t        * pFCTAccOOIData;
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const DIMInputGeneric_t     * pDIMInputGeneric;   /*!< Generic DIM input */
  const DIMInputCustom_t      * pDIMInputCustom;    /*!< Custom DIM input */
#endif 
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const t_HMI_Data_t          * pHMIData;           /*!< HMI data output */
#endif

#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const HypothesisIntf_t      * pFCTCDHypotheses;   /*!< CD hypotheses */
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const HEADInputGeneric_t    * pHEADInputGeneric;  /*!< Generic HEAD input */
  const HEADInputCustom_t     * pHEADInputCustom;   /*!< Custom HEAD input */
#endif

/**************DW ADDED****************************************/
#if ((FCT_CFG_DW_PROCESSING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const FCTDWInputCustom_t    * pDWInputCustom;  /*!< Custom DW input */
  const CPAR_DW_Parameters_t  * pDWCPAR;  /*!< Custom DW input */
  const FCTCustomOutput_t     * pFCTCustomACCOutput_DWIn;
#endif

/**********************************************************/

#if ((FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const ALN_S_Monitoring_t    * pAlignmentMonInput; /*!< Alignment monitoring output data */
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  const BSW_s_AlgoParameters_t * pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const CPAR_FCT_Parameters_t * pCPAR_FCT_Parameters;    /*!< FCT Coding Parameters */
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const VehSig_t              * pVehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_VEH_CFG_EM_CLD_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  const EM_CLD_Output_t       * pEM_CLD_Output;     /*!< EM camera lane detection output */
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  const FCTVehCustomInput_t   * pFctVehCustInput;   /*!< Custom input for FCT_VEH */
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
/*
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
*/
  const TargetControlStatePort_t *pt_FCT_IN_TCSP;     /* Status Input from LOHP to ISC */

#if (FCT_CFG_HP_TFC_PORT_CNT)
  const TargetFollowCommandPort_t *pt_FCT_IN_TFCP; /* Command Input from LOHP to LOPC */
#endif

#endif /* FCT_CFG_ACT_CODE_VERSION */
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  const Lodmc_output_t *pLoDmcOutput;    /*Lodmc output for FCT_VEH */
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */
}
reqFCTVehPrtList_t;

/*! Outputs generated by FCT component for vehicle cycle processing */
typedef struct
{
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  AlgoCompState_t             * pVehCompState;  /*!< AlgoCompState interface to scheduler */
#endif
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FctVeh2SenInfo_t            * pFctVehLongOut;   /*!< Internal info passed from FCT_VEH to FCT_SEN */
  LongCtrlOutput_t            * pLongCtrlOutput;  /*!< Longitudinal controller output data */
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  DIMOutputCustom_t           * pDIMOutputCustom;   /*!< Custom DIM output */
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  HEADOutputGeneric_t         * pHEADOutputGeneric; /*!< Generic HEAD output */
  HEADOutputCustom_t          * pHEADOutputCustom;  /*!< Custom HEAD output */
#endif

/*******************************DW ADDED********************************/

#if ((FCT_CFG_DW_PROCESSING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTDWOutputCustom_t         * pDWOutputCustom; /*!< Custom DW output */
#endif
/*********************************************************************/

#if (FCT_CFG_ERROR_OUTPUT_VEH)
  FCTVehErrorOut_t            * pErrorOut;          /*!< FCT error output */
#endif

#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  FCTVehOutArbitrated_t       * pFCTVehOutArbitrated; /*!< Aribrated output for vehicle functions */
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
  BusDebugData_t              * pEbaBusDebugData; /*!< Eba Debug data */
#endif

#if (FCT_CFG_TCI)
  TCIOutput_t                 * pTCIOutput;  /*!< Output for TCI Feature */
#endif

#if (FCT_CFG_ACT_CODE_VERSION)

/*
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
*/

  TargetControlCommandPort_t *pt_FCT_OUT_TCCP;  /* Command Output from ISC to LOHP */

#if (FCT_CFG_HP_TFC_PORT_CNT)
  TargetFollowStatePort_t *pt_FCT_OUT_TFSP;  /* Status Output from LOPC to LOHP */
#endif

  //ACT_EgoVehicleCommandPort_t *pt_LOPC_OUT_EVCP;
#endif /* FCT_CFG_ACT_CODE_VERSION */
  #if ((!FCT_CFG_USE_ALGOCOMPSTATE) && (!FCT_CFG_INCLUDE_UNUSED_INTF) && (!FCT_CFG_LOPC_COMPONENT) && (!FCT_CFG_DRIVER_INTENTION_MONITORING) && (!FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) && \
       (!FCT_CFG_ERROR_OUTPUT_VEH) && (!FCT_VEH_CFG_CUSTOMOUTPUT) && (!FCT_CFG_USE_BUS_DEBUG) && (!FCT_CFG_TCI) && (!FCT_CFG_ACT_CODE_VERSION))
#if !defined(__NO_ARS_COMPILER_MESSAGES)
#pragma COMPILEMSG("Find more elegant way of disabling FCT_VEH when not needed!")// PRQA S 3116
/* date: 2015-09-23, reviewer: Gangadhar Badiger, reason: Non QAC Related*/
#endif
  uint8 dummy;
#endif
}
proFCTVehPrtList_t;

/*! FCT-Veh Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct FCTVeh_SyncRef
{
  SignalHeader_t sSigHeader;          /*!< Signal Header of Veh_SyncRef */
#if (FCT_CFG_USE_BASECTRLDATA)
  BaseCtrlData_t sBaseCtrl;           /*!< sBaseCtrl */
#endif
  SignalHeader_t FCTCtrlData;         /*!< FCT_VEH operation mode control data */
  SignalHeader_t VehDyn;              /*!< The dynamic vehicle ego data raw */
  SignalHeader_t VehPar;              /*!< the static vehicle ego data */
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  SignalHeader_t AccLeverInput;     /*!< ACC lever information (input from driver) */
  SignalHeader_t LongCtrlInput;     /*!< Dynamic controller response */
  SignalHeader_t acc_object;        /*!< Display object data output by FCT_SEN */
  SignalHeader_t acc_output_data;   /*!< ACC output data by FCT_SEN */
#if (FCT_CFG_TCI)
  SignalHeader_t TCIInput;  /*!< Input for TCI Feature */
#endif
#if (FCT_CFG_SLA_FEATURE)
  SignalHeader_t SLAData;   /*!< SLA Input from SLATE */
#endif
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t FCTAccOOIData       /*! OOI Data from FCT_SEN cycle */;
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t DIMInputGeneric;   /*!< Generic DIM input */
  SignalHeader_t DIMInputCustom;    /*!< Custom DIM input */
#endif
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t FCTHmiData;        /*!< HMI data output */
#endif
#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t HypothesisIntf;    /*!< CD hypotheses */
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t HEADInputGeneric;  /*!< Generic HEAD input */
  SignalHeader_t HEADInputCustom;   /*!< Custom HEAD input */
#endif
#if ((FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t ALN_S_Monitoring;  /*!< Alignment monitoring output data */
#endif
/*********************DW ADDED****************************************/
#if ((FCT_CFG_DW_PROCESSING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
    SignalHeader_t DWInputGeneric;  /*!< Generic DW input */
    SignalHeader_t DWFCTCustomOutput;
	SignalHeader_t DWCPAR;
#endif

/*******************************************************************/
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* algo parameters from BSW */
  SignalHeader_t BSW_s_AlgoParameters;  /*!< Input algo parameters from BSW */
#endif
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t CPAR_FCT_Parameters;   /*!< FCT Coding Parameters */
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t VehSig;            /*!< Direct access to vehicle signals */
#endif
#if ((FCT_VEH_CFG_EM_CLD_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  SignalHeader_t EM_CLD_Output;     /*!< EM camera lane detection output */
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  SignalHeader_t  FctVehCustInput;  /*!< FCTVehCustomInput */
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
  SignalHeader_t t_FCT_IN_SH_TCSP; /* Status Input from LOHP to ISC */
#if (FCT_CFG_HP_TFC_PORT_CNT)
  SignalHeader_t t_FCT_IN_SH_TFCP; /* Command Input from LOHP to LOPC */
#endif
#endif /* FCT_CFG_ACT_CODE_VERSION */
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  SignalHeader_t LoDmcOutput;    /*Lodmc output for FCT_VEH */
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */
}
FCTVeh_SyncRef_t; 

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

/*! Main FCT_VEH Process function */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void FCTVeh_Exec(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts, const AS_t_ServiceFuncts *pServiceFuncts);
#else/*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/
extern void FCTVeh_Exec(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts);
#endif/*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/



#ifdef __cplusplus
}
#endif

/*! @} end defgroup */
#endif /* _FCT_VEH_EXT_H_INCLUDED */
