/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT

PACKAGENAME:               fct_veh_main.c

DESCRIPTION:               File containing sequencing and main function for vehicle frame

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.71 $

LEGACY VERSION:            Revision: 1.189

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_veh.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer:, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "fct_par.h"

 /* needed for memset*/
#ifndef __PDO__
 #include <string.h>
#endif /* #ifndef __PDO__ */
/**
@defgroup fct_Veh_main Fct_Veh_Main
@ingroup frame_veh
@{
*/

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*! first version number of pRequirePorts->pHMIData that uses correct sSigHeader and uiVersionNumber naming.*/
#define FCT_HMI_INTFVER_MIN_G30_I390          0x03

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*fct veh and it's subcomponents initialization status*/
SET_MEMSEC_VAR(FCTVehIsInitialized)
static boolean FCTVehIsInitialized = FALSE;                 /*!<flag showing once completed algo cycle (!=shutdown).*/

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
SET_MEMSEC_VAR(FCTVehInputCounters)
static FCTVeh_InputMeasCounter FCTVehInputCounters = {0};   /*!<aggregation struct that keeps update information for all input interfaces.*/
#endif


/* Meas freeze reference */
SET_MEMSEC_VAR(FCTVehSyncRef)
static FCTVeh_SyncRef_t FCTVehSyncRef;                /*!<struct that stores signal headers of all input interfaces for simulation synchronization.*/

/* Meas freeze control data */
SET_MEMSEC_CONST(FCTVeh_pCtrlData)
#if (FCT_CFG_USE_BASECTRLDATA)
static const BaseCtrlData_t * FCTVeh_pCtrlData;        /*!<internal pointer to relevant external control data INPUT interface.*//*PRQA S 3218, 3229 1 */
#else
static const FCTCtrlData_t  * FCTVeh_pCtrlData;        /*!<internal pointer to relevant external control data INPUT interface.*//*PRQA S 3218, 3229 1 */
#endif
/* date: 2015-05-18, reviewer: Rachit Sharma (uidr5426), reason: Static local required for saving data across function calls */

/* frame (cycle time, cycle counter, opmode ...) */
SET_MEMSEC_VAR(FCTVehFrame)
FCTVehFrame_t FCTVehFrame;                            /*!<internal structure that stores the status of the Algo.*/

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/* Soft Error Counter */
SET_MEMSEC_VAR(FCTVehSoftErrorCounter)
FCTVehSoftErrorCounter_t FCTVehSoftErrorCounter;
#endif

/* start of definition for local alias for external ports (shall be same same than provide and receive ports */
SET_MEMSEC_CONST(FCTVEH_pEgoDynRaw)
const VehDyn_t              * FCTVEH_pEgoDynRaw;      /*!<internal pointer to external raw ego dynamics INPUT interface.*/

#if (FCT_VEH_CFG_VEH_PAR_INPUT)
SET_MEMSEC_CONST(FCTVEH_pGlobEgoStatic)
const VehPar_t              * FCTVEH_pGlobEgoStatic;  /*!<internal pointer to external vehicle parameters INPUT interface.*/
#endif


/********************************DW ADDED********************************************/
#if (FCT_CFG_DW_PROCESSING)
SET_MEMSEC_CONST(FCT_pDWCustomDataIn)
const FCTDWInputCustom_t    * FCT_pDWCustomDataIn;  /*!<internal pointer to external DW generic INPUT interface. FCT DW generic input.*/
SET_MEMSEC_CONST(FCT_pVehSig)
SET_MEMSEC_CONST(FCT_pDWCPAR)
const CPAR_DW_Parameters_t  * FCT_pDWCPAR;  /*!<internal pointer to external DW generic INPUT interface. FCT DW generic input.*/
const VehSig_t * FCT_pVehSig; /*!<internal pointer to vehicle signals interface*/
SET_MEMSEC_CONST(FCT_pFCTCustomACCOutput_DWIn)
const FCTCustomOutput_t      * FCT_pFCTCustomACCOutput_DWIn;
SET_MEMSEC_VAR(FCT_pUDWGenericDataOut)
FCTDWOutputCustom_t         * FCT_pDWCustomDataOut; /*!<internal pointer to external DW generic OUTPUT interface. FCT DW generic output.*/
#endif 

/**************************************************************************/



#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
SET_MEMSEC_CONST(pFCTVehServiceFuncts)
const AS_t_ServiceFuncts *pFCTVehServiceFuncts;       /*!<internal pointer to external service functions interface.*/
#endif

#if (FCT_CFG_VEH_HMI_INTERFACE)
SET_MEMSEC_CONST(FCT_pHMIData)
const t_HMI_Data_t          * FCT_pHMIData;           /*!<internal pointer to external HMI INPUT interface. HMI data output.*/
#endif

#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
SET_MEMSEC_CONST(FCTVEH_pAlignmentMonInput)
const ALN_S_Monitoring_t          * FCTVEH_pAlignmentMonInput;      /* internal pointer to external Alignment Input.*/
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
SET_MEMSEC_CONST(FCTVEH_pBswAlgoParameters)
const BSW_s_AlgoParameters_t * FCTVEH_pBswAlgoParameters;  /*!< Input algo parameters from BSW */
#endif

#if (FCT_VEH_CFG_EM_CLD_INPUT)
SET_MEMSEC_CONST(FCTVEH_pEmCldOutput)
const EM_CLD_Output_t *       FCTVEH_pEmCldOutput;        /*!<internal pointer to external Camera Lane Detection INPUT. EM camera lane detection output.*/
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
SET_MEMSEC_VAR(FCTVEH_pVehCompState)
static AlgoCompState_t             * FCTVEH_pVehCompState;  /*!<internal pointer to external Algo Component State OUTPUT interface.*/
#endif

#if (FCT_CFG_LOPC_COMPONENT)
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
SET_MEMSEC_CONST(FCTVEH_pVehSigPowerTrain)
  const PowerTrain_t                * FCTVEH_pVehSigPowerTrain;
#else
#error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
SET_MEMSEC_CONST(FCTVEH_pAccLever)
const AccLeverInput_t             * FCTVEH_pAccLever;
SET_MEMSEC_CONST(FCTVEH_pLongCtrlResp)
const LongCtrlInput_t             * FCTVEH_pLongCtrlResp;
SET_MEMSEC_CONST(FCTVEH_pAccDisplayObj)
const acc_object_t                * FCTVEH_pAccDisplayObj;
SET_MEMSEC_CONST(FCTVEH_pAccOutput)
const acc_output_data_t           * FCTVEH_pAccOutput;
SET_MEMSEC_VAR(FCTVEH_pFctVehLongOut)
FctVeh2SenInfo_t            * FCTVEH_pFctVehLongOut;
#if (FCT_CFG_TCI)
SET_MEMSEC_CONST(FCTVEH_pTCIInput)
const TCIInput_t                  * FCTVEH_pTCIInput;// PRQA S 3408
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
SET_MEMSEC_VAR(FCTVEH_pTCIOutput)
TCIOutput_t                       * FCTVEH_pTCIOutput;// PRQA S 3408
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
SET_MEMSEC_VAR(FCTVEH_pLongCtrlOutput)
LongCtrlOutput_t            * FCTVEH_pLongCtrlOutput;
#if (FCT_CFG_SLA_FEATURE)
SET_MEMSEC_CONST(FCTVEH_pSLAData)
const SLAData_t             * FCTVEH_pSLAData;   /*!< SLA speed limit data from FCT_SEN */// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH && (FCT_CFG_ACT_CODE_VERSION == SWITCH_OFF))
SET_MEMSEC_VAR(FCTVEH_pLOPCErrorOut)
LOPCErrorOut_t            FCTVEH_pLOPCErrorOut;// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
#endif /* ENDIF (FCT_CFG_LOPC_COMPONENT) */

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
SET_MEMSEC_CONST(FCTVEH_pAccOOIData)
const FCTSenAccOOI_t        * FCTVEH_pAccOOIData;
#endif

#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
SET_MEMSEC_CONST(FCTVEH_pLoDmcOutput)
  const Lodmc_output_t        * FCTVEH_pLoDmcOutput;
#endif

#if (FCT_VEH_CFG_CUSTOMINPUT)
SET_MEMSEC_CONST(FCTVEH_pFctVehCustInput)
const FCTVehCustomInput_t    * FCTVEH_pFctVehCustInput;
#endif

#if (FCT_VEH_CFG_CUSTOMOUTPUT)
SET_MEMSEC_VAR(FCTVEH_pFCTVehOutArbitrated)
FCTVehOutArbitrated_t       * FCTVEH_pFCTVehOutArbitrated;
#endif

#if (FCT_CFG_USE_BUS_DEBUG)
SET_MEMSEC_VAR(FCTVEH_pEbaBusDebugData)
BusDebugData_t              * FCTVEH_pEbaBusDebugData; /*!<internal pointer to external EBA Bus Debug data OUTPUT interface.*/
#endif
/* end of definition for local alias for external ports */


#if (FCT_CFG_ACT_CODE_VERSION)
/* Instantiation of (pseudo) RTE ports for component connection (ISC, LOCC, LOPC...) */

/* Ports for Connection FCT <-> ISC */
//FCTCtrlData_t *FCTVeh_pCtrlData;

SET_MEMSEC_VAR(t_ISC_IN_IIP)
ACT_ISC_InformationPort_t t_ISC_IN_IIP;

SET_MEMSEC_VAR(t_ISC_IN_ICP)
ACT_ISC_CommandPort_t t_ISC_IN_ICP;

SET_MEMSEC_VAR(t_ISC_OUT_ISP)
ACT_ISC_StatusPort_t t_ISC_OUT_ISP;


/* RTE Ports for Connection ISC <-> FCT (LOHP) */
SET_MEMSEC_VAR(pt_FCT_OUT_TCCP)
TargetControlCommandPort_t *pt_FCT_OUT_TCCP;

SET_MEMSEC_CONST(pt_FCT_IN_TCSP)
const TargetControlStatePort_t *pt_FCT_IN_TCSP;


/* Ports for Connection FCT <-> LOCC */
//FCTCtrlData_t   *FCTVeh_pCtrlData;
//LongCtrlInput_t *FCTVEH_pLongCtrlResp;
//VehDyn_t        *FCTVEH_pEgoDynRaw;


/* Ports for Connection ISC <-> LOCC */
SET_MEMSEC_VAR(t_ISC_TO_LOCC_CCCP)
ACT_CruiseControlCommandPort_t t_ISC_TO_LOCC_CCCP;

SET_MEMSEC_VAR(t_LOCC_TO_ISC_CCSP)
ACT_CruiseControlStatePort_t t_LOCC_TO_ISC_CCSP;


/* Ports for Connection ISC <-> LOPC */
SET_MEMSEC_VAR(t_ISC_TO_LOPC_LVCP)
ACT_LogicVehicleCommandPort_t t_ISC_TO_LOPC_LVCP;

SET_MEMSEC_VAR(t_LOPC_TO_ISC_LVSP)
ACT_LogicVehicleStatePort_t t_LOPC_TO_ISC_LVSP;


/* Ports for Connection LOCC <-> LOPC */
#if (ACT_CFG_CC_VSC_PORT_CNT)
  SET_MEMSEC_VAR(t_LOCC_TO_LOPC_VSCP)
  ACT_CC_VehicleSpeedCommandPort_t t_LOCC_TO_LOPC_VSCP;

  SET_MEMSEC_VAR(t_LOPC_TO_LOCC_VSSP)
  ACT_CC_VehicleSpeedStatePort_t t_LOPC_TO_LOCC_VSSP;
#endif


/* Ports for Connection FCT(LOHP) <-> LOPC */
#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(pt_FCT_IN_TFCP)
  const TargetFollowCommandPort_t *pt_FCT_IN_TFCP;

  SET_MEMSEC_VAR(pt_FCT_OUT_TFSP)
  TargetFollowStatePort_t *pt_FCT_OUT_TFSP;
#endif


/* Ports for Connection LOPC <-> FCT */

//FCTCtrlData_t   *FCTVeh_pCtrlData;
//LongCtrlInput_t *FCTVEH_pLongCtrlResp;
//VehDyn_t        *FCTVEH_pEgoDynRaw;

SET_MEMSEC_VAR(t_LOPC_TO_FCT_EVCP)
ACT_EgoVehicleCommandPort_t t_LOPC_TO_FCT_EVCP;
/* end of instantiation of pseudo RTE ports for component connection */


/* Instantiation of component port lists (ISC, LOCC, LOPC...) */
#if (FCT_CFG_ISC_COMPONENT)
  SET_MEMSEC_VAR(t_ISC_RequirePorts)
  ISC_ReqPortList_t t_ISC_RequirePorts;
#endif

#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_LOCC_RequirePorts)
  LOCC_ReqPortList_t t_LOCC_RequirePorts;
#endif

#if (FCT_CFG_LOPC_COMPONENT)
  SET_MEMSEC_VAR(t_LOPC_RequirePorts)
  LOPC_ReqPortList_t t_LOPC_RequirePorts;
#endif


#if (FCT_CFG_ISC_COMPONENT)
  SET_MEMSEC_VAR(t_ISC_ProvidePorts)
  ISC_ProPortList_t t_ISC_ProvidePorts;
#endif

#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_LOCC_ProvidePorts)
  LOCC_ProPortList_t t_LOCC_ProvidePorts;
#endif

#if (FCT_CFG_LOPC_COMPONENT)
  SET_MEMSEC_VAR(t_LOPC_ProvidePorts)
  LOPC_ProPortList_t t_LOPC_ProvidePorts;
#endif
/* end of instantiation of component port lists (ISC, LOCC, LOPC...) */

#else

/* Instantiation of component port list for LOPC Gen 3 */
#if (FCT_CFG_LOPC_COMPONENT)
  SET_MEMSEC_CONST(t_LOPC_RequirePorts)
  LOPC_ReqPortList_t t_LOPC_RequirePorts;// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */

  SET_MEMSEC_VAR(t_LOPC_ProvidePorts)
  LOPC_ProPortList_t t_LOPC_ProvidePorts;// PRQA S 3408
/* date: 2018-03-22, reviewer: Ravi Kiran Gurrala, reason: Not Safety critical */
#endif
/* end of instantiation of component port list for LOPC Gen 3 */

#endif

/****************   Buffers for MeasFreezes *******************/
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

  /*input ports*/

#if (FCT_VEH_CFG_FREEZE_CTRL_DATA)
/*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferVehCtrlData)
#if (FCT_CFG_USE_BASECTRLDATA)
    static BaseCtrlData_t FCTVeh_FreezeBufferVehCtrlData;   /*!<   internal data buffer for measfreezing Vehicle Control Data.*/
#else
    static FCTCtrlData_t FCTVeh_FreezeBufferVehCtrlData;    /*!<   internal data buffer for measfreezing Vehicle Control Data.*/
#endif /* FCT_CFG_USE_BASECTRLDATA */
#endif /*FCT_VEH_CFG_FREEZE_CTRL_DATA*/

  /*output ports*/

  /*HEAD*/
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferHeadOutputGeneric)
    static HEADOutputGeneric_t FCTVeh_FreezeBufferHeadOutputGeneric;    /*!<internal data buffer for measfreezing HEAD OUTPUT generic interface.*/
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferHeadOutputCustom)
    static HEADOutputCustom_t FCTVeh_FreezeBufferHeadOutputCustom;      /*!<internal data buffer for measfreezing HEAD OUTPUT custom interface.*/
#endif /*FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION*/

  /*DIM*/
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)  
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferDimOutputCustom)
    static DIMOutputCustom_t FCTVeh_FreezeBufferDimOutputCustom;        /*!<internal data buffer for measfreezing DIM OUTPUT custom interface.*/
#endif /*FCT_CFG_DRIVER_INTENTION_MONITORING*/

/*******************************DW ADDED******************************/
#if (FCT_CFG_DW_PROCESSING) 
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferDWInputCustom)
    static  FCTDWInputCustom_t FCTVeh_FreezeBufferDWInputCustom;    /*!<internal data buffer for measfreezing DW INPUT custom interface.*/
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
//  SET_MEMSEC_VAR(FCTVeh_FreezeBufferDWCPAR)
//	  static  CPAR_DW_Parameters_t FCTVeh_FreezeBufferDWCPAR;    /*!<internal data buffer for measfreezing DW INPUT custom interface.*/
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferDWGenericOutput)
    static  FCTDWOutputCustom_t FCTVeh_FreezeBufferDWGenericOutput;    /*!<internal data buffer for measfreezing DW OUTPUT generic interface.*/

#endif  /*FCT_CFG_DW_PROCESSING*/
/*********************************************************************/

  /*ERROR output*/
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferErrorOutput)
    static  FCTVehErrorOut_t FCTVeh_FreezeBufferErrorOutput;              /*!<internal data buffer for measfreezing FCTVeh error OUTPUT interface.*/
#endif /*FCT_CFG_ERROR_OUTPUT_VEH*/

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferVehCompState)
    static  AlgoCompState_t FCTVeh_FreezeBufferVehCompState;              /*!<internal data buffer for measfreezing Algo Component State OUTPUT interface.*/
#endif /*FCT_CFG_USE_ALGOCOMPSTATE*/

#if (FCT_CFG_USE_BUS_DEBUG)
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferVehEbaBusDebug)
    static  BusDebugData_t FCTVeh_FreezeBufferVehEbaBusDebug;             /*!<internal data buffer for measfreezing EBA Bus Debug OUTPUT interface.*/
#endif /*FCT_CFG_USE_BUS_DEBUG*/

#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  /*PRQA S 3218 2*/ /* 20150626 CO: kept here for better maintainability */
  SET_MEMSEC_VAR(FCTVeh_FreezeBufferVehCustomOut)
    static  FCTVehOutArbitrated_t FCTVeh_FreezeBufferVehCustomOut;        /*!<internal data buffer for measfreezing Arbitrated OUTPUT interface.*/
#endif /*FCT_VEH_CFG_CUSTOMOUTPUT*/

#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/

/****************   end of Buffers for MeasFreezes *******************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/

/* to add states of new function read from bottom to top. Add new ones on top. 
   remember also to adjust FCTVehSetStates function prototype and implementation.*/

   /***************************************DW ADDED********************************/
#if (FCT_CFG_DW_PROCESSING)
/*! macro for scheduler control using additionally DWState*/
#define FCT_VEH_STATE_PARAM(    _DWSTATE_, _HEADSTATE_ ,  _FCTVEHSTATE_) (_DWSTATE_), \
  ( _FCTVEHSTATE_ )
#else
/*! macro for scheduler control NOT using DWState*/
/*#define FCT_VEH_STATE_PARAM(         _DWSTATE_, _DIMSTATE_, _HEADSTATE_, _FCTVEHSTATE_)               \
  FCT_VEH_STATE_PARAM_POST_DW((_DIMSTATE_), (_HEADSTATE_), (_FCTVEHSTATE_)) */

  #define FCT_VEH_STATE_PARAM(  _HEADSTATE_, _FCTVEHSTATE_)           \
      (_FCTVEHSTATE_)
#endif

/************************************************************************************/
/************************************************************************************/

  /*uncomment the below line for ARS510RT10********************/
/*! macro for scheduler control using only VEHState*/
/*#define FCT_VEH_STATE_PARAM(                                                                        _HEADSTATE_, _FCTVEHSTATE_)           \
    //                                                                                       (_FCTVEHSTATE_) */
/****************************************************/
  


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/
/*****************************************************************************
  MODULE LOCAL VARIABLES 
*****************************************************************************/
/* MEDIC process memory */
#if (FCT_CFG_MEDIC_COMPONENT)
#if !FCT_CFG_USE_MEDIC_INTERNAL_MEMORY

static GA_MEDIC_Mem_DataInterCycleMeas  MEDICInterMeas = {0};/*PRQA S 3218  */
/* date: 2019-01-29, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static GA_MEDIC_Mem_DataIntraCycleMeas  MEDICIntraMeas = {0};/*PRQA S 3218  */
/* date: 2019-01-29, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
static GA_MEDIC_Mem_DataInterCycle      MEDICInter     = {0};/*PRQA S 3218  */
/* date: 2019-01-29, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/

/* date: 2019-01-29, reviewer: Ravi Kiran Gurrala, reason: kept here for better maintainability*/
#endif
#endif
/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
#if (FCT_CFG_MEDIC_COMPONENT)
#if (!FCT_CFG_USE_MEDIC_INTERNAL_MEMORY)
static void FCTVeh_FreezeMEDICProcMem(MEDIC_ProcMem_t const * const pMEDICProcMem);
#endif

static void FCTVeh_v_MEDIC_Process( reqMEDICPtrList_t   const * const p_MEDICRequirePorts, 
                                    proMEDICPtrList_t        * const p_MEDICProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                   , AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif
                                                                                 );
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void FCTVehSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier);
#endif
static void FCTVehAlgoInit(void);
/*****DW Changes -> before it was ->static void FCTVehSetStates( FCTVehState_t StFCT);*********/

/**************DW ADDED*************************/
static void FCTVehSetStates( 
	#if (FCT_CFG_DW_PROCESSING)
                            DWState_t      StDW,
    #endif  
	                     FCTVehState_t StFCT);
/************************************************/


static void FCTVehProcessStates (FCT_OP_MODE_t eOpMode);


#if (FCT_MEASUREMENT)
static void FCTVehMeasCallback(void);
static void FCTVehFrameFreeze(void);
static void FCTVehProcessMeasFreeze( reqFCTVehPrtList_t const * const pRequirePorts, proFCTVehPrtList_t const * const pProvidePorts);

/***************************DW ADDED***************/
#if (FCT_CFG_DW_PROCESSING)
static void FCTVehProcessMeasFreezeDW(void);
#endif

/*************************************************/


#endif
/////***************************DW ADDED***************/
////#if (FCT_CFG_DW_PROCESSING)
////static void FCTVehProcessMeasFreezeDW(void);
////#endif
////
/////*************************************************/

static void     FCTSetVehFrameData              ( const reqFCTVehPrtList_t * pRequirePorts );
static void     FCTVehCheckPorts                ( const reqFCTVehPrtList_t * pRequirePorts
                                                , const proFCTVehPrtList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                                              , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                                               );
static boolean  FCTVehCheckRequirePorts         ( const reqFCTVehPrtList_t * pRequirePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                                , const AS_t_ServiceFuncts *pServiceFuncts
#endif
                                                );
static boolean  FCTVehCheckProvidePorts         ( const proFCTVehPrtList_t * pProvidePorts );
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
static boolean  FCTVehCheckSigStateRequirePorts ( const reqFCTVehPrtList_t * pRequirePorts );
static boolean  FCTVehCheckPortsInit            ( const reqFCTVehPrtList_t * pRequirePorts );
static void     FCTVehInitSoftErrorCounter      (void);
static boolean  FCTVehSetSoftErrorCounter       (const AlgoSignalState_t sSigStatus, AlgoCycleCounter_t *pSoftErrorCounter);
#endif
static void     FCTVehSetupPorts                ( const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts );
static void     FCTVehSignalErrorShutdown       ( void );
static void     FCTVehSetupSyncRef              (const reqFCTVehPrtList_t * pRequirePorts);
static void     FCTVehSetProvideHeader          (const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts);
static void     FCTVehSetProvideHeaderStates    (const proFCTVehPrtList_t * pProvidePorts, AlgoSignalState_t eSigState);
static void     FCTVehSetSigHeaderState         (SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState);
static void     FCTVehSetSigHeaderError         (SignalHeader_t * const pSigHeader);
static void     FCTVehFillSigHeader             (SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr);
static void     FCTVehSetErrorProvidePorts      (const proFCTVehPrtList_t * pProvidePorts);
#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
static void     FCTVehCheckProvideHeader        (SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader);
static void     FCTVehCheckProvideHeaders       (const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts);
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
static void FCTVehSetCompState (AlgoCompState_t * const pVehCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier);
#endif

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
static uint32 FCTVehCheckInputUpdate(const reqFCTVehPrtList_t * pRequirePorts, FCTVeh_InputMeasCounter *pFCTVehInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen );
static uint32 FCTVehCheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                     sMeasCycleMonitor *pLastMeasCycle,
                                     float32 fTargetCycleTime, 
                                     uint8 iAcceptableDrops);

#endif

#if (FCT_CFG_ACT_CODE_VERSION)

/* Port List Assignment for Components (ISC, LOCC, LOHP, LOPC, ...) */
#if (FCT_CFG_ISC_COMPONENT)
  static void FCT_v_Set_ISC_Ports(ISC_ReqPortList_t *pRequirePorts, ISC_ProPortList_t *pProvidePorts);
#endif

#if (FCT_CFG_LOCC_COMPONENT)
  static void FCT_v_Set_LOCC_Ports(LOCC_ReqPortList_t *pRequirePorts, LOCC_ProPortList_t *pProvidePorts);
#endif

#if (FCT_CFG_LOPC_COMPONENT)
  static void FCT_v_Set_LOPC_Ports(LOPC_ReqPortList_t *pRequirePorts, LOPC_ProPortList_t *pProvidePorts);
#endif

/* Dynamic Port Content Assignment */
#if (FCT_CFG_ISC_COMPONENT)
  static void FCT_v_Assign_ISC_Input_Ports (const AccLeverInput_t *pt_DrvCtrlInput, const LongCtrlInput_t *pt_VehCtrlInput, const PowerTrain_t *pt_PTInput);
  static void FCT_v_Assign_ISC_Output_Ports (KinDriverOutput_t *pt_KinDrvOutput, KinFctInfo_t *pt_KinFctInfo);
#endif

#if (FCT_CFG_LOPC_COMPONENT)
  static void FCT_v_Assign_LOPC_Output_Ports (KinOutput_t *pt_KinOutput);
#endif

#else

#if (FCT_CFG_LOPC_COMPONENT)
  static void FCT_v_SetLOPCGen3Ports(const reqFCTVehPrtList_t* pRequirePorts, const proFCTVehPrtList_t* pProvidePorts,
                                     LOPC_ReqPortList_t *pLopcRequirePorts, LOPC_ProPortList_t *pLopcProvidePorts);
#endif

#endif

#if (FCT_CFG_MEDIC_COMPONENT)
  /*! Set MEDIC provide ports based on FCT_VEH provide ports */
  static void FCTVeh_v_SetMEDICProPort(const proFCTVehPrtList_t * p_ProvidePorts, proMEDICPtrList_t * p_MedicProvidePorts);
  /*! Set MEDIC request ports based on FCT_VEH request ports */
  static void FCTVeh_v_SetMEDICReqPort(const reqFCTVehPrtList_t * p_RequirePorts, reqMEDICPtrList_t * p_MedicRequirePorts);
  /*! Set MEDIC provide ports based on FCT_VEH provide ports in case of an error */
  #if (FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  static void FCTVeh_v_SetMEDICErrorProPorts(const proFCTVehPrtList_t *p_ProvidePorts, proMEDICPtrList_t *p_MedicProvidePorts);
  #endif
#endif // FCT_CFG_MEDIC_COMPONENT

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* ***********************************************************************
  @fn             FCTVehSetAlgoErrorBuffer */ /*! 
  @brief          Set the Algo Error Buffer
  @description    Set the ErrorQualifier to pErrorBuffer if it is more severe than the stored one.
                  It's not possible to change to a lower priority than already set.

                  @startuml 
                     Start
                        Partition  FCTVehSetAlgoErrorBuffer
                            -   Set the Algo Error Buffer
                                If(pointer to the buffered error is  not NULL AND the Error to set is not zero ) then (true)
                                    If(pointer to the buffered error is zero ) then (true)
                                        - the Error to set is assigned to pointer to the buffered error 
                                    Else (False)
                                        If(the Error to set is less than pointer to the buffered error) then (true)
                                            - the Error to set is assigned to pointer to the buffered error
                                        Endif
                                    Endif
                                endif
                      End 
                   @enduml


  @param[in]      ErrorQualifier : the Error to set
  @param[in,out]  pErrorBuffer   : pointer to the buffered error
  @pre            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @author         Christian Obst
**************************************************************************** */
static void FCTVehSetAlgoErrorBuffer (GenAlgoQualifiers_t *const pErrorBuffer, const GenAlgoQualifiers_t ErrorQualifier)
{
  if ( (pErrorBuffer != NULL) && (ErrorQualifier != ALGO_QUAL_OK) ) /*pointer check and entry condition*/
  {
    if (*pErrorBuffer == ALGO_QUAL_OK)
    {
      *pErrorBuffer = ErrorQualifier;
    }
    else
    {
      if (ErrorQualifier < *pErrorBuffer)
      {
        *pErrorBuffer = ErrorQualifier;
      }
    }
  }
}
#endif


#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/*************************************************************************************************************************
  Functionname:    FCTVehCheckPortUpdated                                                                           */ /*!

  @brief           Check if input interface update is missing.

  @description     Checks if update is older than allowed (target cycle time and acceptable drops).
                   FCTVeh cycle time is taken from FCT_VEH_TARGET_CYCLE_TIME.

                   @startuml 
                      Start
                        Partition  FCTVehCheckPortUpdated
                          -   Check if input interface update is missing
                          If(current timestamp of the interface is less than pLastMeasCycle->uiTimeStamp) then (true)
                            - overflow ( uiDeltaTimeUs is calculated )
                          Else (False)
                            - No overflow (uiDeltaTimeUs is calculated )	
                          Endif
                          If(uiDeltaTimeUs is equal to zero) then (true)
                            If(((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)is less than uiMaxAcceptableDropTimeUs) then (true)
                              - pLastMeasCycle->uiLastUpdateCounter is incremented by one
                            Else (False)
                              - uErrorFlag is assigned to one
                            Endif
                          Else (False)
                            If ( uiDeltaTimeUs is greater than uiMaxAcceptableDropTimeUs)then (true)
                             - uErrorFlag is assigned to one
                            Else (False)
                               - current timestamp of the interface is assigned to uiTimeStamp
                            Endif
                          Endif
                       End 
                    @enduml


  @return          static uint32 

  @param[in]       *pInputPortMeasCycle : current timestamp of the interface. [AlgoDataTimeStamp_t as per Rte_Type.h]
  @param[in,out]   *pLastMeasCycle : pointer to the internal stored update information.
                      pLastMeasCycle->uiTimeStamp : [AlgoDataTimeStamp_t as per Rte_Type.h]
                      pLastMeasCycle->uiLastUpdateCounter : [full range of unsigned char]
  @param[in]       fTargetCycleTime : target cycle time for the input interface to check. [Full range of float32]
  @param[in]       iAcceptableDrops : allowed number of dropped providing frame updates. [Full range of unsigned char]

  @glob_in         -
  @glob_out        -
                   
  @c_switch_part   -
  @c_switch_full   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
                   
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/11/2016

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 FCTVehCheckPortUpdated( const AlgoDataTimeStamp_t *pInputPortMeasCycle, 
                                      sMeasCycleMonitor *pLastMeasCycle,
                                      float32 fTargetCycleTime, 
                                      uint8 iAcceptableDrops)
{
  AlgoDataTimeStamp_t uiDeltaTimeUs = 0u;
  /*20150327 C. Obst: intended behavior to cast float to uInt. fractional part is neglectible.*/
  /*PRQA S 4119 3*/
  const AlgoDataTimeStamp_t uiCycleTimeUs = (AlgoDataTimeStamp_t)(fTargetCycleTime * MILLION);         /*conversion second to microsecond*/
  const AlgoDataTimeStamp_t uiMaxAcceptableDropTimeUs = (AlgoDataTimeStamp_t)( ((float32)iAcceptableDrops + 1.5f) * (float32)uiCycleTimeUs ); /*accepted drops + current Cycle + 0.5 safety margin*/
  AlgoDataTimeStamp_t uiTargetCycleTimeCallUs = (AlgoDataTimeStamp_t)(FCT_VEH_TARGET_CYCLE_TIME * (float32)MILLION);

  uint32 uErrorFlag = 0u;

  /*Calculating Time since last input*/
  if ( *pInputPortMeasCycle < pLastMeasCycle->uiTimeStamp )
  {
    /*OVERFLOW*/
    uiDeltaTimeUs = ( (0u)^(0u)) - (pLastMeasCycle->uiTimeStamp - *pInputPortMeasCycle);
  }
  else 
  {
    /*NO Overflow*/
    uiDeltaTimeUs = *pInputPortMeasCycle - pLastMeasCycle->uiTimeStamp;
  }
  
  if ( uiDeltaTimeUs == 0u)
  {
    /*NO update*/
    if ( ((pLastMeasCycle->uiLastUpdateCounter + 1) * uiTargetCycleTimeCallUs)  < uiMaxAcceptableDropTimeUs)
    {
      /*no update needed (max time including drops not reached)*/
      pLastMeasCycle->uiLastUpdateCounter += 1u;   /*increment update counter*/
    }
    else
    {
      /*update expected*/
      uErrorFlag = 1u;        /*raise error*/
    }
  }
  else
  {
    /*update*/
    if ( uiDeltaTimeUs > uiMaxAcceptableDropTimeUs )
    {
      /*skipped cycle*/
      uErrorFlag = 1u;        /*raise error*/
    }
    else
    {
      /*new cycle received in time*/
      pLastMeasCycle->uiLastUpdateCounter = 0u;    /*reset update counter*/
    }
    pLastMeasCycle->uiTimeStamp = *pInputPortMeasCycle;
  }
  return uErrorFlag;
}

/*************************************************************************************************************************
  Functionname:    FCTVehCheckInputUpdate                                                                           */ /*!

  @brief           Checks for frame drops and frozen input interfaces based on provided timestamps.

  @description     calls the Update Checker function for every used input interface and writes it to the InputCounters struct.

                   @startuml 
                     Start
                       Partition  FCTVehCheckInputUpdate
                         - Checks for frame drops and frozen input interfaces based on provided timestamps.
                         - calls the Update Checker function for every used input interface and writes it to the InputCounters struct.
                         - Updates the Check ports  and controls the input ports of Longitudinal, TCI, SLA, DIM, HMI, Hypothesis interface, CPARs
                     End 
                   @enduml


  @return          static uint32 : number of interfaces which are not updated longer than debounce time.

  @param[in]       pRequirePorts : input interface provided to FCTVeh. 
  @param[in]       pFCTVehInputCounters : internal memory struct to store update information.
  @param[in]       fTargetCycleTimeVeh : target cycle time for the FCTVeh Task. 
  @param[in]       fTargetCycleTimeSen : target cycle time for the Camera (FCTSen) Task (Sensor cycle).

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF : Special configuration switch to include all interfaces in request/provide
                                                 port structures, even if the current configuration does not use them. This 
                                                 enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_COLLISION_DETECTION                : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION       : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the 
                                                            SW environment provides this information
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
  @c_switch_full   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22/09/2017

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update).

  @author          Christian Obst
*************************************************************************************************************************/
static uint32 FCTVehCheckInputUpdate(const reqFCTVehPrtList_t * pRequirePorts, FCTVeh_InputMeasCounter *pFCTVehInputCounters, float32 fTargetCycleTimeVeh, float32 fTargetCycleTimeSen )
{
  static uint8 AcceptableDrops = FCT_INPUT_ACCEPTABLE_DROPS;
  uint32 ErrorCounter = 0;
  /* Check Input Port Measurement Counters */
//  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pVehCtrlData->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pVehCtrlData), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pEgoDynRaw->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pEgoDynRaw), fTargetCycleTimeSen, AcceptableDrops );
//  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pEgoStaticData->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pEgoStaticData), fTargetCycleTimeVeh, AcceptableDrops );
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Longitudinal control input ports */
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pAccLever->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pAccLever), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pLongCtrlResp->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pLongCtrlResp), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pAccDisplayObj->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pAccDisplayObj), fTargetCycleTimeVeh, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pAccOutput->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pAccOutput), fTargetCycleTimeVeh, AcceptableDrops );
#if (FCT_CFG_TCI)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pTCIInput->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pTCIInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if (FCT_CFG_SLA_FEATURE)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pSLAData->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pFctVehCustInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pDIMInputGeneric->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pDIMInputGeneric), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pDIMInputCustom->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pDIMInputCustom), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
#endif 
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pHMIData->s_Header.uiTimeStamp), &(pFCTVehInputCounters->pHMIData), fTargetCycleTimeSen, AcceptableDrops );
#else
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pHMIData->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pHMIData), fTargetCycleTimeSen, AcceptableDrops );
#endif
#endif

#if ((FCT_CFG_COLLISION_DETECTION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  /* Hypothesis interface */
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pFCTCDHypotheses->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pFCTCDHypotheses), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pHEADInputGeneric->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pHEADInputGeneric), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pHEADInputCustom->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pHEADInputCustom), FCT_NORM_TARGET_CYCLE_TIME, AcceptableDrops );
#endif
#if ((FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pAlignmentMonInput->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pAlignmentMonInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pBswAlgoParameters->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pBswAlgoParameters), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if (0) /*no alive counters in CPARs*/
#if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pCPAR_FCT_Parameters), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pVehSig->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pVehSig), fTargetCycleTimeSen, AcceptableDrops );
#endif
#if ((FCT_VEH_CFG_EM_CLD_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pEM_CLD_Output->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pEM_CLD_Output), fTargetCycleTimeVeh, AcceptableDrops );
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  ErrorCounter += FCTVehCheckPortUpdated( &(pRequirePorts->pFctVehCustInput->sSigHeader.uiTimeStamp), &(pFCTVehInputCounters->pFctVehCustInput), fTargetCycleTimeVeh, AcceptableDrops );
#endif

  _PARAM_UNUSED(fTargetCycleTimeVeh);
return ErrorCounter;
}
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/



#if (FCT_CFG_USE_ALGOCOMPSTATE)
/* **********************************************************************
  @fn           FCTVehSetCompState                                  */ /*!
  @brief        Set the Algo Component State.
  @description  Set the Algo Component State based on scheduler request and internal status.

                @startuml 
                Start
                   Partition  FCTVehSetCompState
                    -   Set the Algo Component State based on scheduler request and internal status.
                            If(pVehCompState is not equal to NULL) then (true)
                                - Fill the array AlgoVersionInfo with the predefined string
                            Endif
                            If(FCTVehFrame.eFCTState is equal to FCT_VEH_INIT) then (true)
                                If(ScheduledOpMode is not equal to FCT_MOD_RUNNING) then (true)
                                    -Updates the values
                                    - pVehCompState->eCompState = COMP_STATE_RUNNING;
                                    - pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
                                    - pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
                                Else (False)
                                  - pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
                                  - pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
                                   If(BufferedQualifier is not equal to ALGO_QUAL_OK) then (true)
                                     -buffer is filled, put Qualifier
                                   Else (False)
                                     -buffer is empty, something weird happened
                                   Endif
                                Endif
                            Elseif(FCTVehFrame.eFCTState is equal to FCT_VEH_RUN) then (true)
                              - pVehCompState->eCompState = COMP_STATE_RUNNING;
                              - pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
                              - pVehCompState->eGenAlgoQualifier = BufferedQualifier;
                            Elseif(FCTVehFrame.eFCTState is equal to FCT_VEH_SHUTDOWN) then (true)
                              - This happns with missing input signal pointer or invalid signal 
                            Else
                              If(ScheduledOpMode is not equal to FCT_MOD_RUNNING) then (true)
                                - Updates the values
                                - pVehCompState->eCompState = COMP_STATE_RUNNING;
                                - pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
                                - pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
                              Else (False)
                                 - pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
                                 - pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
                                 If(BufferedQualifier is not equal to ALGO_QUAL_OK) then (true)
                                   -buffer is filled, put Qualifier
                                 Else (False)
                                   -buffer is empty, something weird happened
                                 Endif
                               Endif
                            Endif
                      End
                  @enduml


  @param[out]   pVehCompState : pointer to Algo Component State that shall be set.
  @param[in]    ScheduledOpMode : operation mode given by global scheduler.
  @param[in]    BufferedQualifier : internal buffer for AlgoQualifier (error status).
  @pre          Algo ran, component error states are set.

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @return       none
  @author       Christian Obst
**************************************************************************** */
static void FCTVehSetCompState (AlgoCompState_t * const pVehCompState, const FCT_OP_MODE_t ScheduledOpMode, const GenAlgoQualifiers_t BufferedQualifier)
{
#if ( (defined(_MSC_VER)) && (COMP_STATE_INTFVER > 3) )
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: REMOVE REDEFINITION (obviously the RTE is updated)!")// PRQA S 3116
#endif
#ifndef MFC_VERSION_INFO_LENGTH
#define MFC_VERSION_INFO_LENGTH (ALGO_VERSION_INFO_LENGTH)
#endif 

  /* The define MFC_VERSION_INFO_LENGTH is to be renamed. The name has to be more generalized regarding the used thechnology */
#if COMP_STATE_INTFVER > 3
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(ALGO_VERSION_INFO_LENGTH-1));
#else
  uint8 uiAlgoVersionInfoFillSize = MIN(sizeof(VERSION_INFO_AS_TEXT),(MFC_VERSION_INFO_LENGTH-1));
#endif
  if (pVehCompState != NULL)
  {
    /* Fill the array AlgoVersionInfo with the predefined string */
    (void)memcpy(pVehCompState->AlgoVersionInfo, VERSION_INFO_AS_TEXT, uiAlgoVersionInfoFillSize);
    pVehCompState->uiAlgoVersionNumber = FCTVehFrame.Versions.uiFCTVEH;
#if COMP_STATE_INTFVER > 2u
    pVehCompState->uiApplicationNumber = 0u;
    pVehCompState->eShedulerSubModeRequest = BASE_SSM_NONE;
#else
    pVehCompState->ApplicationNumber = 0u;
    pVehCompState->eShedulerModeRequest = COMP_MODE_REQ_NONE;
#endif
    switch (FCTVehFrame.eFCTState)
    {
    case FCT_VEH_INIT:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pVehCompState->eCompState = COMP_STATE_RUNNING;
        pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*some issue occurred either no pVehCtrlData pointer or internal init*/
        pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pVehCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pVehCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    case FCT_VEH_RUN:
      pVehCompState->eCompState = COMP_STATE_RUNNING;
      pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
      pVehCompState->eGenAlgoQualifier = BufferedQualifier;
      break;
    case FCT_VEH_SHUTDOWN:
      /*in case on missing input signal pointer or invalid signal status*/
    default:
      if (ScheduledOpMode != FCT_MOD_RUNNING)
      {
        /*indicates system wide init, startup or shutdown*/
        /*compstate isn't put on vehicle bus*/
        pVehCompState->eCompState = COMP_STATE_RUNNING;
        pVehCompState->eErrorCode = COMP_ERROR_NO_ERROR;
        pVehCompState->eGenAlgoQualifier = ALGO_QUAL_OK;
      }
      else
      {
        /*internal recoverable error*/
        pVehCompState->eCompState = COMP_STATE_TEMPORARY_ERROR;
        pVehCompState->eErrorCode = COMP_ERROR_UNKNOWN;
        if (BufferedQualifier != ALGO_QUAL_OK)
        {
          pVehCompState->eGenAlgoQualifier = BufferedQualifier;                 /*buffer is filled, put Qualifier*/
        }
        else
        {
          pVehCompState->eGenAlgoQualifier = ALGO_QUAL_GENERAL_FUNCTION_ERROR;  /*buffer is empty, something weird happened*/
        }
      }
      break;
    }
  }
}
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

/*************************************************************************************************************************
  Functionname:    FCTVehSetErrorProvidePorts                                                                       */ /*!

  @brief           Setup available provide ports in ERROR case.

  @description     maps the provided pointers to internal pointer, setup SigHeader of available provide ports in ERROR case, invalidates the Signal Status and fills the                         version number.

                   @startuml 
                      Start
                          Partition  FCTVehSetErrorProvidePorts
                              -  Setup available provide ports in ERROR case.
                       End 
                   @enduml


  @return          static void

  @param[in,out]       pProvidePorts : output interfaces provided by FCTVeh.
                         pProvidePorts->pFctVehLongOut->sSigHeader          [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pLongCtrlOutput->uiVersionNumber    [all valid entries are defined by typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                         pProvidePorts->pLongCtrlOutput->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pFCTVehOutArbitrated->uiVersionNr   [AlgoInterfaceVersionNumber_t as defined in Rte_Type.h]
                         pProvidePorts->pFCTVehOutArbitrated->sSigHeader    [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pDIMOutputCustom->uiVersionNumber   [all valid entries are defined by typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                         pProvidePorts->pDIMOutputCustom->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pHEADOutputGeneric->uiVersionNumber [all valid entries are defined by typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                         pProvidePorts->pHEADOutputGeneric->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pHEADOutputCustom->uiVersionNumber  [all valid entries are defined by typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                         pProvidePorts->pHEADOutputCustom->sSigHeader       [SignalHeader_t as defined in Rte_Type.h]
                         pProvidePorts->pErrorOut->uiVersionNumber          [all valid entries are defined by typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                         pProvidePorts->pErrorOut->sSigHeader               [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         - 
  @glob_out        -

  @c_switch_full   -
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE                  : Configuration switch for enabling the AlgoCompstate interface
  @c_switch_part   FCT_CFG_LOPC_COMPONENT                    : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT                   : FCT veh custom output interface
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING        : FCT driver intention monitoring switch 
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION       : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH                   : FCT error output from FCT_VEH
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG                      : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT                   : FCT veh custom output interface
  @c_switch_part   FCT_CFG_USE_ALGOCOMPSTATE                  : Configuration switch for enabling the AlgoCompstate interface

  @pre             eFCTOpMode == FCT_MOD_SHUTDOWN.
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/3/2015

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst | christian.obst@continental-corporation.com
*************************************************************************************************************************/
static void FCTVehSetErrorProvidePorts (const proFCTVehPrtList_t * pProvidePorts)
{
  /* Provide ports */
  if (pProvidePorts != NULL)
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    if (pProvidePorts->pVehCompState != NULL)
    {
      FCTVEH_pVehCompState                  = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
      FCTVEH_pVehCompState->uiVersionNumber  = COMP_STATE_INTFVER;
#else
      FCTVEH_pVehCompState->uVersionNumber  = COMP_STATE_INTFVER;
#endif
    }
    else
    {
      FCTVEH_pVehCompState = NULL;
    }
#endif

#if (FCT_CFG_LOPC_COMPONENT)
    if (pProvidePorts->pFctVehLongOut != NULL)
    {
      pProvidePorts->pFctVehLongOut->uiVersionNumber = FCT_VEH_2_SEN_INFO_VERSION;
      FCTVehSetSigHeaderError(&pProvidePorts->pFctVehLongOut->sSigHeader);
      FCTVEH_pFctVehLongOut = pProvidePorts->pFctVehLongOut;
    }
    else
    {
      FCTVEH_pFctVehLongOut = NULL;
    }
    if (pProvidePorts->pLongCtrlOutput != NULL)
    {
      pProvidePorts->pLongCtrlOutput->uiVersionNumber = FCT_LONG_CTRL_OUTPUT_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pLongCtrlOutput->sSigHeader);
      FCTVEH_pLongCtrlOutput = pProvidePorts->pLongCtrlOutput;
    }
    else
    {
      FCTVEH_pLongCtrlOutput = NULL;
    }
#if (FCT_CFG_TCI)
    if (pProvidePorts->pTCIOutput != NULL)
    {
      pProvidePorts->pTCIOutput->uiVersionNumber = TCIOutput_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pTCIOutput->sSigHeader);
      FCTVEH_pTCIOutput = pProvidePorts->pTCIOutput;
    }
    else
    {
      FCTVEH_pTCIOutput = NULL;
    }
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    if(pProvidePorts->pFCTVehOutArbitrated != NULL)
    {
      pProvidePorts->pFCTVehOutArbitrated->uiVersionNr = FCT_VEH_OUT_ARBIT_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pFCTVehOutArbitrated->sSigHeader);
      FCTVEH_pFCTVehOutArbitrated = pProvidePorts->pFCTVehOutArbitrated;
    }
    else
    {
      FCTVEH_pFCTVehOutArbitrated = NULL;
    }
#endif
    
/*****************************DW ADDED**************************************************/
#if (FCT_CFG_DW_PROCESSING)
    if (pProvidePorts->pDWOutputCustom != NULL)
    {
      pProvidePorts->pDWOutputCustom->uiVersionNumber = FCT_DW_OUTPUT_CUSTOM_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pDWOutputCustom->sSigHeader);
    }
#endif

/****************************************************************************************/
#if (FCT_CFG_ERROR_OUTPUT_VEH)
    if (pProvidePorts->pErrorOut != NULL)
    {
      pProvidePorts->pErrorOut->uiVersionNumber = FCT_VEH_ERROR_OUT_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pErrorOut->sSigHeader);
    }
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    if (pProvidePorts->pEbaBusDebugData != NULL)
    {
      FCTVEH_pEbaBusDebugData = pProvidePorts->pEbaBusDebugData;
    }
    else
    {
      FCTVEH_pEbaBusDebugData = NULL;
    }
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    if (pProvidePorts->pFCTVehOutArbitrated != NULL)
    {
      pProvidePorts->pFCTVehOutArbitrated->uiVersionNr  = FCT_VEH_OUT_ARBIT_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pFCTVehOutArbitrated->sSigHeader);
      FCTVEH_pFCTVehOutArbitrated = pProvidePorts->pFCTVehOutArbitrated;
    }
    else
    {
      FCTVEH_pFCTVehOutArbitrated = NULL;
    }
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
    if (pProvidePorts->pt_FCT_OUT_TCCP != NULL)
    {
      pProvidePorts->pt_FCT_OUT_TCCP->uiVersionNumber = LOHP_TCCP_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pt_FCT_OUT_TCCP->sSigHeader);
      pt_FCT_OUT_TCCP = pProvidePorts->pt_FCT_OUT_TCCP;
    }
    else
    {
      pt_FCT_OUT_TCCP = NULL;
    }
#if (FCT_CFG_HP_TFC_PORT_CNT)
    if (pProvidePorts->pt_FCT_OUT_TFSP != NULL)
    {
      pProvidePorts->pt_FCT_OUT_TFSP->uiVersionNumber = LOPC_TFSP_INTFVER;
      FCTVehSetSigHeaderError(&pProvidePorts->pt_FCT_OUT_TFSP->sSigHeader);
      pt_FCT_OUT_TFSP = pProvidePorts->pt_FCT_OUT_TFSP;
    }
    else
    {
      pt_FCT_OUT_TFSP = NULL;
    }
#endif
#endif
  }
  else
  {
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTVEH_pVehCompState = NULL;
#endif
#if (FCT_CFG_LOPC_COMPONENT)
    FCTVEH_pFctVehLongOut = NULL;
    FCTVEH_pLongCtrlOutput = NULL;
#if (FCT_CFG_TCI)
    FCTVEH_pTCIOutput = NULL;
#endif
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    FCTVEH_pFCTVehOutArbitrated = NULL;//PRQA S 2982
/* date: 2019-06-28, reviewer:, reason:Assignment is not redundant*/
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    FCTVEH_pEbaBusDebugData = NULL;
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    FCTVEH_pFCTVehOutArbitrated = NULL;
#endif
  }
}


/*************************************************************************************************************************
  Functionname:    FCTVehSetupSyncRef                                                                               */ /*!

  @brief           Creates sync data for Simulation synchronisation

  @description     puts signalheaders of all input ports into one structure. sets sSigHeader of SyncRef structure to invalid if pointer is NULL.

                   @startuml 
                      Start
                          Partition  FCTVehSetupSyncRef
                              -  Creates sync data for Simulation synchronisation
                      End
                   @enduml

  @return          static void

  @param[in]       pRequirePorts : The input interface provided to FCTVeh. 
                      pRequirePorts->pVehCtrlData->sSigHeader          [SignalHeader_t as defined in Rte_Type.h]  
                      pRequirePorts->pEgoDynRaw->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]  
                      pRequirePorts->pEgoStaticData->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]  
                      pRequirePorts->pAccLever->sSigHeader             [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pLongCtrlResp->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pAccDisplayObj->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pAccOutput->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pFCTAccOOIData->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pHMIData->s_Header                [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pDIMInputGeneric->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]  
                      pRequirePorts->pDIMInputCustom->sSigHeader       [SignalHeader_t as defined in Rte_Type.h]  
                      pRequirePorts->pFCTCDHypotheses->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pHEADInputGeneric->sSigHeader     [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pHEADInputCustom->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pAlignmentMonInput->sSigHeader    [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pCPAR_FCT_Parameters->sSigHeader  [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pVehSig->sSigHeader               [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pEM_CLD_Output->sSigHeader        [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pFctVehCustInput->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pSLAData->sSigHeader              [SignalHeader_t as defined in Rte_Type.h]

  @glob_in         - 
  @glob_out        FCTVehSyncRef : fct veh syncronisation structure for simulation  [FCTVehSyncRef as defined in fct_veh_ext.h] 
                      FCTVehSyncRef.FCTCtrlData           [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.sBaseCtrl             [BaseCtrlData_t as defined in Rte_Type.h]
                      FCTVehSyncRef.sSigHeader.eSigStatus [all valid entries are defined by typedef AlgoSignalState_t in Rte_SWCAlnAdapt_Type.h]
                      FCTVehSyncRef.VehDyn                [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.VehPar                [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.AccLeverInput         [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.LongCtrlInput         [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.acc_object            [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.acc_output_data       [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.FCTAccOOIData         [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.FCTHmiData            [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.DIMInputGeneric       [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.DIMInputCustom        [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.HypothesisIntf        [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.HEADInputGeneric      [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.HEADInputCustom       [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.ALN_S_Monitoring      [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.BSW_s_AlgoParameters  [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.CPAR_FCT_Parameters   [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.VehSig                [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.EM_CLD_Output         [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.FctVehCustInput       [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.SLAData               [SignalHeader_t as defined in Rte_Type.h]
                      FCTVehSyncRef.sSigHeader            [SignalHeader_t as defined in Rte_Type.h]

  @c_switch_part   FCT_CFG_LOPC_COMPONENT                : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
  @c_switch_part   FCT_CFG_USE_BASECTRLDATA               : Switch that enables the FCT Base Control Data struct and disables the OPMode-port
  @c_switch_full   -

  @pre             - 
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22/09/2017

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst | christian.Obst@continental-corporation.com
*************************************************************************************************************************/

static void FCTVehSetupSyncRef(const reqFCTVehPrtList_t * pRequirePorts)
{
  /*setting whole syncref to zero */
  (void)memset(&FCTVehSyncRef, 0, sizeof(FCTVehSyncRef));/* PRQA S 0315 */
/* date: 2019-06-28, reviewer:, reason:Case to void intended as use of generic interface */

  if (pRequirePorts != NULL)
  {
    /*pVehCtrlData*/
    if (pRequirePorts->pVehCtrlData != NULL)
    {
      FCTVehSyncRef.FCTCtrlData              = pRequirePorts->pVehCtrlData->sSigHeader;
#if (FCT_CFG_USE_BASECTRLDATA)
      FCTVehSyncRef.sBaseCtrl               = *pRequirePorts->pVehCtrlData;
#endif
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pEgoDynRaw*/
    if (pRequirePorts->pEgoDynRaw != NULL)
    {
      FCTVehSyncRef.VehDyn                   = pRequirePorts->pEgoDynRaw->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pEgoStaticData*/
    if (pRequirePorts->pEgoStaticData != NULL)
    {
      FCTVehSyncRef.VehPar                   = pRequirePorts->pEgoStaticData->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_LOPC_COMPONENT)
#if (CFG_ACC_LEVER_INPUT)
    /*pAccLever*/
    if (pRequirePorts->pAccLever != NULL)
    {
      FCTVehSyncRef.AccLeverInput          = pRequirePorts->pAccLever->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
    /*pLongCtrlResp*/
    if (pRequirePorts->pLongCtrlResp != NULL)
    {
      FCTVehSyncRef.LongCtrlInput          = pRequirePorts->pLongCtrlResp->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
    /*pAccDisplayObj*/
    if (pRequirePorts->pAccDisplayObj != NULL)
    {
      FCTVehSyncRef.acc_object             = pRequirePorts->pAccDisplayObj->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
    /*pAccOutput*/
    if (pRequirePorts->pAccOutput != NULL)
    {
      FCTVehSyncRef.acc_output_data        = pRequirePorts->pAccOutput->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#if (FCT_CFG_TCI)
    /*pTCIInput*/
    if (pRequirePorts->pTCIInput != NULL)
    {
      FCTVehSyncRef.TCIInput              = pRequirePorts->pTCIInput->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#if (FCT_CFG_SLA_FEATURE)
    /*pSLAData*/
    if (pRequirePorts->pSLAData != NULL)
    {
      FCTVehSyncRef.SLAData               = pRequirePorts->pSLAData->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#endif /* FCT_CFG_LOPC_COMPONENT */

#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    /*pFCTAccOOIData*/
    if (pRequirePorts->pFCTAccOOIData != NULL)
    {
      FCTVehSyncRef.FCTAccOOIData          = pRequirePorts->pFCTAccOOIData->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    /*pDIMInputGeneric*/
    if (pRequirePorts->pDIMInputGeneric != NULL)
    {
      FCTVehSyncRef.DIMInputGeneric        = pRequirePorts->pDIMInputGeneric->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    /*pDIMInputCustom*/
    if (pRequirePorts->pDIMInputCustom != NULL)
    {
      FCTVehSyncRef.DIMInputCustom         = pRequirePorts->pDIMInputCustom->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#if (FCT_CFG_VEH_HMI_INTERFACE)
    /*pHMIData*/
    if (pRequirePorts->pHMIData != NULL)
    {
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
      FCTVehSyncRef.FCTHmiData             = pRequirePorts->pHMIData->s_Header;
#else
      FCTVehSyncRef.FCTHmiData             = pRequirePorts->pHMIData->sSigHeader;
#endif
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif



#if (FCT_CFG_COLLISION_DETECTION)
    /*pFCTCDHypotheses*/
    if (pRequirePorts->pFCTCDHypotheses != NULL)
    {
      FCTVehSyncRef.HypothesisIntf         = pRequirePorts->pFCTCDHypotheses->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    /*pHEADInputGeneric*/
    if (pRequirePorts->pHEADInputGeneric != NULL)
    {
      FCTVehSyncRef.HEADInputGeneric       = pRequirePorts->pHEADInputGeneric->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    if (pRequirePorts->pHEADInputCustom != NULL)
    {
      FCTVehSyncRef.HEADInputCustom        = pRequirePorts->pHEADInputCustom->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

/********************************DW ADDED********************************************/

#if (FCT_CFG_DW_PROCESSING)
    /*pDWInputCustom*/
    if (pRequirePorts->pDWInputCustom != NULL)
    {
      FCTVehSyncRef.DWInputGeneric       = pRequirePorts->pDWInputCustom->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

    if (pRequirePorts->pFCTCustomACCOutput_DWIn != NULL)                       
    {
      FCTVehSyncRef.DWFCTCustomOutput       = pRequirePorts->pFCTCustomACCOutput_DWIn->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

	if (pRequirePorts->pDWCPAR != NULL)                       
	{
		FCTVehSyncRef.DWCPAR       = pRequirePorts->pDWCPAR->sSigHeader;
	}
	else
	{
		FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
	}
#endif

/*****************************************************************************************/

#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
    /*pAlignmentMonInput*/
    if (pRequirePorts->pAlignmentMonInput != NULL)
    {
      FCTVehSyncRef.ALN_S_Monitoring       = pRequirePorts->pAlignmentMonInput->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_CFG_BSW_ALGO_PARAMS)
    /* algo parameters from BSW */
    /* Currently BSW algo parameters has no signal header */
    /*FCTVehSyncRef.BSW_s_AlgoParameters   = pRequirePorts->pBswAlgoParameters->sSigHeader;*/
    FCTVehSetSigHeaderError(&FCTVehSyncRef.BSW_s_AlgoParameters);
#endif

#if (FCT_CFG_CPAR_PARAMS)
    /*pCPAR_FCT_Parameters*/
    if (pRequirePorts->pCPAR_FCT_Parameters != NULL)
    {
      FCTVehSyncRef.CPAR_FCT_Parameters     = pRequirePorts->pCPAR_FCT_Parameters->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_VEH_CFG_VEH_SIG_INPUT)
    /*pVehSig*/
    if (pRequirePorts->pVehSig != NULL)
    {
      FCTVehSyncRef.VehSig                 = pRequirePorts->pVehSig->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_VEH_CFG_EM_CLD_INPUT)
    /*pEM_CLD_Output*/
    if (pRequirePorts->pEM_CLD_Output != NULL)
    {
      FCTVehSyncRef.EM_CLD_Output          = pRequirePorts->pEM_CLD_Output->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

#if (FCT_VEH_CFG_CUSTOMINPUT)
    /*pFctVehCustInput*/
    if (pRequirePorts->pFctVehCustInput != NULL)
    {
      FCTVehSyncRef.FctVehCustInput         = pRequirePorts->pFctVehCustInput->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif

    if (pRequirePorts->pVehCtrlData != NULL)
    {
      /* fill signal header of SyncRef with valid data from Control Input */
      FCTVehFillSigHeader(&FCTVehSyncRef.sSigHeader, &pRequirePorts->pVehCtrlData->sSigHeader);
      FCTVehSetSigHeaderState(&FCTVehSyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }

#if (FCT_CFG_ACT_CODE_VERSION)
    if (pRequirePorts->pt_FCT_IN_TCSP != NULL)
    {
      /* fill signal header of SyncRef with valid data from Input */
      FCTVehFillSigHeader(&FCTVehSyncRef.sSigHeader, &pRequirePorts->pt_FCT_IN_TCSP->sSigHeader);
      FCTVehSetSigHeaderState(&FCTVehSyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#if (FCT_CFG_HP_TFC_PORT_CNT)
    if (pRequirePorts->pt_FCT_IN_TFCP != NULL)
    {
      /* fill signal header of SyncRef with valid data from Input */
      FCTVehFillSigHeader(&FCTVehSyncRef.sSigHeader, &pRequirePorts->pt_FCT_IN_TFCP->sSigHeader);
      FCTVehSetSigHeaderState(&FCTVehSyncRef.sSigHeader, AL_SIG_STATE_OK);
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
    if (pRequirePorts->pLoDmcOutput != NULL)
    {
      FCTVehSyncRef.LoDmcOutput = pRequirePorts->pLoDmcOutput->sSigHeader;
    }
    else
    {
      FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
    }
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */
  }
  else
  {
    FCTVehSyncRef.sSigHeader.eSigStatus = AL_SIG_STATE_INVALID;
  }
}/* PRQA S 7004, 7002*/
/* date: 2018-09-11, reviewer: Ravi Kiran Gurrala, reason : Cyclomatic complexity, amount of non-cyclic paths. Not Safety critical*/

/*************************************************************************************************************************
  Functionname:    FCTVehAlgoInit                                                                                   */ /*!

  @brief           Do initialization of FCT algo variables/states

  @description     init FCT frame. (note: reset's global FCTVehFrame.bFirstCycleDone flag)

  @return          static void

  @param[in]       void

  @glob_in         -
  @glob_out        FCTVehFrame.bFirstCycleDone : Boolean flag used for first cycle check [boolean]

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
  @changed         12/7/2015

  @author          Jochen Spruck & Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehAlgoInit (void)
{
  /*--- VARIABLES ---*/

  FCTVehFrame.bFirstCycleDone   = FALSE;
}

#if FCT_CFG_ACTIVATE_SIGHEADER_CHECK
/*************************************************************************************************************************
  Functionname:    FCTVehCheckProvideHeader                                                                         */ /*!

  @brief           Check whether the signal header has changed during the call of the components

  @description     Detailed Design

  @return          static void

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

  @todo            Remove this entire line if not needed

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTVehCheckProvideHeader(SignalHeader_t const * const pProvidedSigHeader, SignalHeader_t const * const pReceivedSigHeader)
{
  _PARAM_UNUSED(pProvidedSigHeader);
  _PARAM_UNUSED(pReceivedSigHeader);

  CML_ASSERT(    (pProvidedSigHeader->uiMeasurementCounter == pReceivedSigHeader->uiMeasurementCounter)
              && (pProvidedSigHeader->uiTimeStamp          == pReceivedSigHeader->uiTimeStamp         )
           /* && (pProvidedSigHeader->eSigStatus           != AL_SIG_STATE_INVALID                    ) */);
}

/*************************************************************************************************************************
  Functionname:    FCTVehCheckProvideHeaders                                                                        */ /*!

  @brief           Call the check of the SigHeader for all used ports
  
                   @startuml 
                      Start
                          Partition  FCTVehCheckProvideHeaders
                              -  Call the check of the SigHeader for all used ports
                      End
                   @enduml


  @return          static void

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
static void FCTVehCheckProvideHeaders(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts) 
{
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehCheckProvideHeader(&pProvidePorts->pFctVehLongOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
  FCTVehCheckProvideHeader(&pProvidePorts->pLongCtrlOutput->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
#endif
#if ((FCT_CFG_TCI) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehCheckProvideHeader(&pProvidePorts->pTCIOutput->sSigHeader, &pRequirePorts->pTCIInput->sSigHeader);
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehCheckProvideHeader(&pProvidePorts->pDIMOutputCustom->sSigHeader, &pRequirePorts->pDIMInputGeneric->sSigHeader);
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehCheckProvideHeader(&pProvidePorts->pHEADOutputGeneric->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
  FCTVehCheckProvideHeader(&pProvidePorts->pHEADOutputCustom->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
#endif

#if (FCT_CFG_ERROR_OUTPUT_VEH)
  FCTVehCheckProvideHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif
#if ((FCT_VEH_CFG_CUSTOMOUTPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehCheckProvideHeader(&pProvidePorts->pFCTVehOutArbitrated->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif

}
#endif

/*************************************************************************************************************************
  Functionname:    FCTVehSetProvideHeader                                                                           */ /*!

  @brief           Set the signal headers of provide ports

  @description     signal header information is set to following values:
                   eSigStatus = invalid
                   uiCycleCounter from FCTVehFrame
                   uiMeasurementCounter and uiTimeStamp from main-provider

                   @startuml 
                     Start
                       Partition  FCTVehSetProvideHeader
                         -  Set the signal headers of provide ports
                         - signal header information is set to following values:
                         - eSigStatus = invalid
                         - uiCycleCounter from FCTVehFrame
                         - uiMeasurementCounter and uiTimeStamp from main-provider			
                     End 
                  @enduml




  @return          static void

  @param[out]       pRequirePorts : output interface provided to FCTVeh
                      pRequirePorts->pLongCtrlResp->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pDIMInputGeneric->sSigHeader   [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pFCTCDHypotheses->sSigHeader   [SignalHeader_t as defined in Rte_Type.h]
                      pRequirePorts->pEgoDynRaw->sSigHeader         [SignalHeader_t as defined in Rte_Type.h]

  @param[in]       pProvidePorts : input interface provided by FCTVeh.
                      pProvidePorts->pFctVehLongOut->sSigHeader       [SignalHeader_t as defined in Rte_Type.h] 
                      pProvidePorts->pLongCtrlOutput->sSigHeader      [SignalHeader_t as defined in Rte_Type.h]
                      pProvidePorts->pDIMOutputCustom->sSigHeader     [SignalHeader_t as defined in Rte_Type.h]
                      pProvidePorts->pHEADOutputGeneric->sSigHeader   [SignalHeader_t as defined in Rte_Type.h]
                      pProvidePorts->pHEADOutputCustom->sSigHeader    [SignalHeader_t as defined in Rte_Type.h]
                      pProvidePorts->pErrorOut->sSigHeader            [SignalHeader_t as defined in Rte_Type.h]
                      pProvidePorts->pFCTVehOutArbitrated->sSigHeader [SignalHeader_t as defined in Rte_Type.h]


  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOPC_COMPONENT              : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF          : Special configuration switch to include all interfaces in request/provide
                                                          port structures, even if the current configuration does not use them. This 
                                                          enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING  : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH             : FCT error output from FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT             : FCT veh custom output interface
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015

  @todo            Review this function

  @author          Christian Obst
*************************************************************************************************************************/
static void FCTVehSetProvideHeader(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts) 
{
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehFillSigHeader(&pProvidePorts->pFctVehLongOut->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
  FCTVehFillSigHeader(&pProvidePorts->pLongCtrlOutput->sSigHeader, &pRequirePorts->pLongCtrlResp->sSigHeader);
#endif
#if ((FCT_CFG_TCI) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehFillSigHeader(&pProvidePorts->pTCIOutput->sSigHeader, &pRequirePorts->pTCIInput->sSigHeader);
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehFillSigHeader(&pProvidePorts->pDIMOutputCustom->sSigHeader, &pRequirePorts->pDIMInputGeneric->sSigHeader);
#endif
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehFillSigHeader(&pProvidePorts->pHEADOutputGeneric->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
  FCTVehFillSigHeader(&pProvidePorts->pHEADOutputCustom->sSigHeader, &pRequirePorts->pFCTCDHypotheses->sSigHeader);
#endif

#if (FCT_CFG_ERROR_OUTPUT_VEH)
  FCTVehFillSigHeader(&pProvidePorts->pErrorOut->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif
#if ((FCT_VEH_CFG_CUSTOMOUTPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehFillSigHeader(&pProvidePorts->pFCTVehOutArbitrated->sSigHeader, &pRequirePorts->pEgoDynRaw->sSigHeader);
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
  FCTVehFillSigHeader(&pProvidePorts->pt_FCT_OUT_TCCP->sSigHeader, &pRequirePorts->pt_FCT_IN_TCSP->sSigHeader);
#if (FCT_CFG_HP_TFC_PORT_CNT)
  FCTVehFillSigHeader(&pProvidePorts->pt_FCT_OUT_TFSP->sSigHeader, &pRequirePorts->pt_FCT_IN_TFCP->sSigHeader);
#endif
#endif
}

/*************************************************************************************************************************
  Functionname:    FCTVehSetProvideHeaderStates                                                                     */ /*!

  @brief           Set the state in the SigHeader for all used provide ports


                     @startuml 
                      Start
                          Partition  FCTVehSetProvideHeaderStates
                              -  Set the state in the SigHeader for all used provide ports	
                      End
                   @enduml

  @return          static void

  @param[in]       pProvidePorts : 
  @param[in]       eSigState : 

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
static void FCTVehSetProvideHeaderStates(const proFCTVehPrtList_t * pProvidePorts, AlgoSignalState_t eSigState) 
{
#if ((FCT_CFG_LOPC_COMPONENT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehSetSigHeaderState(&pProvidePorts->pFctVehLongOut->sSigHeader, eSigState);
  FCTVehSetSigHeaderState(&pProvidePorts->pLongCtrlOutput->sSigHeader, eSigState);
#if (FCT_CFG_TCI)
  FCTVehSetSigHeaderState(&pProvidePorts->pTCIOutput->sSigHeader, eSigState);
#endif
#endif
#if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehSetSigHeaderState(&pProvidePorts->pDIMOutputCustom->sSigHeader, eSigState);
#endif
/*************************DW ADDED****************************************/
#if (FCT_CFG_DW_PROCESSING)
/*! @param[in]       StDW   */
  FCTVehSetSigHeaderState(&pProvidePorts->pDWOutputCustom->sSigHeader, eSigState);
#endif

/**************************************************************************/
#if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehSetSigHeaderState(&pProvidePorts->pHEADOutputGeneric->sSigHeader, eSigState);
  FCTVehSetSigHeaderState(&pProvidePorts->pHEADOutputCustom->sSigHeader, eSigState);
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  FCTVehSetSigHeaderState(&pProvidePorts->pErrorOut->sSigHeader, eSigState);
#endif
#if ((FCT_VEH_CFG_CUSTOMOUTPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  FCTVehSetSigHeaderState(&pProvidePorts->pFCTVehOutArbitrated->sSigHeader, eSigState);
#endif

#if (FCT_CFG_ACT_CODE_VERSION)
  FCTVehSetSigHeaderState(&pProvidePorts->pt_FCT_OUT_TCCP->sSigHeader, eSigState);
#if (FCT_CFG_HP_TFC_PORT_CNT)
  FCTVehSetSigHeaderState(&pProvidePorts->pt_FCT_OUT_TFSP->sSigHeader, eSigState);
#endif
#endif
}


/*************************************************************************************************************************
  Functionname:    FCTVehSetStates                                                                                  */ /*!

  @brief           Set FCT_Veh State Matrix (states of FCT_Veh sub-components)

  @description     Set FCT_Veh State Matrix (states of FCT_Veh sub-components)

                   @startuml 
                      Start
                          Partition  FCTVehSetStates
                              -   Set FCT_Veh State Matrix (states of FCT_Veh sub-components)
                      End
                   @enduml

  @return          static void                                                                                                                                             
  @param[in]       StDIM : operating modes of sub-component DIM [0..1 as per enum DIMState_t  defined in dim_ext.h]     
  @param[in]       StHEAD : operating modes of sub-component HEAD [0..1 as per enum HEADState_t defined in head_ext.h]   
  
  @param[in]       StFCT : operating modes of sub-component FCT [0..1 as per enum FCTVehState_t defined in fct_veh.h]                                                                  

  @glob_in         -
  @glob_out        DIMState : operating modes of sub-component DIM [0..1 as per enum DIMState_t in dim_ext.h]
                   HEADState : operating modes of sub-component HEAD [0..1 as per enum HEADState_t in head_ext.h]
                   FCTVehFrame.eFCTState : operating modes of sub-component FCT [0..2 as per enum FCTVehState_t in fct_veh.h]

  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING  : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION : FCT hypothesis evaluation and decision switch
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/7/2015

  @todo            Add long controller (ACC) state setting!

  @author          Clemens Schnurr
*************************************************************************************************************************/
/************CHANGE FOR DW-> static void FCTVehSetStates( FCTVehState_t StFCT)**********/
/********************DW ADDED********************************/
static void FCTVehSetStates( 


#if (FCT_CFG_DW_PROCESSING)
                            DWState_t      StDW,
#endif
                            FCTVehState_t StFCT)
/*********************************************************/

{
/********************************DW ADDED**********************/
#if (FCT_CFG_DW_PROCESSING)
  DWState  = StDW;
#endif
/***************************************************************/
  FCTVehFrame.eFCTState = StFCT;
}

/*************************************************************************************************************************
  Functionname:    FCTVehProcessStates                                                                              */ /*!

  @brief           Set operation modes of all sub-components

  @description     Sets the states of the sub-components in FCT_VEH based on the global
                   FCT state passed.

                   @startuml 
                   Start
                     Partition  FCTVehProcessStates
                      -   Set operation modes of all sub-components.
                      If(FCTVehIsInitialized is equal to FALSE AND eOpMode not equal to FCT_MOD_SHUTDOWN) then (true)
                      - eOpMode is equal to FCT_MOD_INIT
                      Endif
                      If(eOpMode is FCT_MOD_STARTUP) then (true)
                          - FCTVehSetStates(FCT_VEH_STATE_PARAM( HEAD_STATE_INIT, FCT_VEH_INIT));
                          - FCTVehIsInitialized = FALSE;
                      Elseif(eOpMode is FCT_MOD_INIT) then (true)
                          - FCTVehSetStates(FCT_VEH_STATE_PARAM( HEAD_STATE_INIT, FCT_VEH_INIT));
                          - FCTVehIsInitialized = FALSE;
                      Elseif(eOpMode is FCT_MOD_INIT) then (true)
                          - FCTVehSetStates(FCT_VEH_STATE_PARAM(  HEAD_STATE_OK, FCT_VEH_RUN));
                      Elseif(eOpMode is FCT_MOD_RUNNING) then (true)
                          - Do  nothing
                      Else
                          -  FCTVehSetStates(FCT_VEH_STATE_PARAM(  HEAD_STATE_INIT,  FCT_VEH_SHUTDOWN));
                    End 
                  @enduml


  @return          static void

  @param[in,out]   eOpMode : the operation mode of FCT to use [FCT_OP_MODE_t as in Rte_Type.h]

  @glob_in         FCTVehIsInitialized : fct veh and it's subcomponents initialization status [true, false]
  @glob_out        -

  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION : FCT hypothesis evaluation and decision switch
  @c_switch_full   -

  @pre             ACTL has to set Opmode via FCTSetOpMode() before FCTProcess()
  @post            Changed Opmodes of all (Sub-)Components.

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehProcessStates(FCT_OP_MODE_t eOpMode)
{
  /*! ---  FCT State Matrix ---  */

  if ((FCTVehIsInitialized == FALSE) && (eOpMode != FCT_MOD_SHUTDOWN))//PRQA S 1863
/* date: 2019-06-28, reviewer:, reason:Both operands of equality operator is promoted to  singned int, his has no side affect on functionality */
  {
    eOpMode = FCT_MOD_INIT;
  }

  /*FCTSetOpModeOld(eOpMode);*/
  switch (eOpMode)
  {
  case (FCT_OP_MODE_t)FCT_MOD_STARTUP:
    #if (FCT_CFG_DW_PROCESSING)
	  FCTVehSetStates(FCT_VEH_STATE_PARAM(DW_STATE_INIT,HEAD_STATE_INIT, FCT_VEH_INIT));             /* DW_STATE_INIT IS AADDED*/
      #else
    FCTVehSetStates(FCT_VEH_STATE_PARAM( HEAD_STATE_INIT, FCT_VEH_INIT));
    #endif
    FCTVehIsInitialized = FALSE;
    break;
  case (FCT_OP_MODE_t)FCT_MOD_INIT:
 #if (FCT_CFG_DW_PROCESSING)
    FCTVehSetStates(FCT_VEH_STATE_PARAM(DW_STATE_INIT,HEAD_STATE_INIT,FCT_VEH_INIT));             
	 #else
    FCTVehSetStates(FCT_VEH_STATE_PARAM( HEAD_STATE_INIT, FCT_VEH_INIT));
#endif
    FCTVehIsInitialized = FALSE;
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
    FCTVehInitSoftErrorCounter();
#endif
    break;
  case (FCT_OP_MODE_t)FCT_MOD_RUNNING:
#if (FCT_CFG_DW_PROCESSING)
	  FCTVehSetStates(FCT_VEH_STATE_PARAM(DW_STATE_OK, HEAD_STATE_OK  , FCT_VEH_RUN));   /* DW_STATE_OK IS AADDED*/
      #else
    FCTVehSetStates(FCT_VEH_STATE_PARAM(  HEAD_STATE_OK, FCT_VEH_RUN));
#endif
    break;
  case (FCT_OP_MODE_t)FCT_MOD_SHUTDOWN:
  default:
#if (FCT_CFG_DW_PROCESSING)
	   FCTVehSetStates(FCT_VEH_STATE_PARAM( DW_STATE_INIT, HEAD_STATE_INIT ,  FCT_VEH_SHUTDOWN));     
	  #else
    FCTVehSetStates(FCT_VEH_STATE_PARAM(  HEAD_STATE_INIT,  FCT_VEH_SHUTDOWN));
 #endif
    break;
  }
}

/*************************************************************************************************************************
  Functionname:    FCTVehSignalErrorShutdown                                                                        */ /*!

  @brief           Set operation modes of all sub-components to shutdown in case of Error.

  @description     Set operation modes of all sub-components to shutdown in case of Error.
                   Resets the FCTVehIsInitialized flag.

  @return          static void

  @param[in]       void

  @glob_in         -
  @glob_out        FCTVehIsInitialized : fct veh and it's subcomponents initialization status [true, false]

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
  @changed         12/8/2015

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void FCTVehSignalErrorShutdown( void )
{
  FCTVehProcessStates (FCT_MOD_SHUTDOWN);
  FCTVehIsInitialized = FALSE;
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    FCTVehMeasCallback                                                                               */ /*!

  @brief           Dummy MTS notification callback

  @description     Empty dummy MTS notification callback function

  @return          static void

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Activate Measurement Output Code

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @author          Jochen Spruck, Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehMeasCallback (void) /* PRQA S 3219 */
/* date: 2015-07-15, reviewer: Rachit Sharma (uidr5426), reason: Dummy MTS function */ 
{
  return;
}

/*************************************************************************************************************************
  Functionname:    FCTVehFrameFreeze                                                                                */ /*!

  @brief           Freezes the basic Frame Measurement Data independent from operation mode.

  @description     Freezes the basic Frame Measurement Data independent from operation mode. Freezes the FrameData and Syncref information.

                    @startuml 
                      Start
                          Partition  FCTVehFrameFreeze
                              -  Freezes the basic Frame Measurement Data independent from operation mode.
                      End
                   @enduml

  @return          static void

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_VEH_CFG_FREEZE_USE_CALLBACK : Switches to make local copy of pointer interfaces and use callback measfreeze function
                                                     use this functionality if output pointers are non constant (ringbuffer IPC)
  @c_switch_full   FCT_MEASUREMENT : Activate Measurement Output Code

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @todo            20150611CO: double check which internal data and/or interfaces shall be freezed ALWAYS.

  @author          Jochen Spruck & Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehFrameFreeze(void)
{
  /* Vehicle frame data meas freeze header Info */
  static const MEASInfo_t FCT_VehFrameMeasInfo = 
  {
    FCT_MEAS_ID_VEH_FRAME_DATA,         /* VirtualAddress */
    sizeof(FCTVehFrame_t),              /* Length */
    FCT_MEAS_FUNC_ID,                   /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID               /* FuncChannelID */
  };

  /* Input SyncRef meas freeze header Info */
  static const MEASInfo_t FCT_VehSyncRefMeasInfo = 
  {
    FCT_MEAS_ID_VEH_INPUT_SIGHEADERS,   /* VirtualAddress */
    sizeof(FCTVeh_SyncRef_t),           /* Length */
    FCT_MEAS_FUNC_ID,                   /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID               /* FuncChannelID */
  };

  /* Algo Component State Output */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  static const MEASInfo_t FCT_Veh_CompStateMeasInfo = 
  {
    FCT_MEAS_ID_VEH_COMP_STATE,   /* VirtualAddress */
    sizeof(AlgoCompState_t),      /* Length */
    FCT_MEAS_FUNC_ID,             /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)

  FCT_FREEZE_DATA(&FCT_VehFrameMeasInfo, &FCTVehFrame, &FCTVehMeasCallback);
  FCT_FREEZE_DATA(&FCT_VehSyncRefMeasInfo, &FCTVehSyncRef, &FCTVehMeasCallback);

#else /* FCT_VEH_CFG_FREEZE_USE_CALLBACK */

  FCT_FREEZE_DATA(&FCT_VehFrameMeasInfo, &FCTVehFrame, NULL);//PRQA S 3200, 0315
  /* date: 2018-09-11, reviewer:Ravi Kiran Gurrala, reason: The return value of MEASFreezeDataMTS is not used currently */
  FCT_FREEZE_DATA(&FCT_VehSyncRefMeasInfo, &FCTVehSyncRef, NULL);//PRQA S 3200, 0315
  /* date: 2018-09-11, reviewer:Ravi Kiran Gurrala, reason: The return value of MEASFreezeDataMTS is not used currently */

#endif /* FCT_VEH_CFG_FREEZE_USE_CALLBACK */

  /* Algo Component State Output */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  if (FCTVEH_pVehCompState != NULL)
  {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
    memcpy(&FCTVeh_FreezeBufferVehCompState, FCTVEH_pVehCompState, sizeof(AlgoCompState_t));
    FCT_FREEZE_DATA(&FCT_Veh_CompStateMeasInfo, &FCTVeh_FreezeBufferVehCompState, &FCTVehMeasCallback);
#else
    FCT_FREEZE_DATA(&FCT_Veh_CompStateMeasInfo, &FCTVEH_pVehCompState, NULL);
#endif
  }
#endif /* FCT_CFG_USE_ALGOCOMPSTATE */
}

/****************************DW ADDED*******************************************/
#if (FCT_CFG_DW_PROCESSING)

/*************************************************************************************************************************
 Functionname:    FCTVehProcessMeasFreezeDW                                                                      */ /*!

  @brief           meas freezes the RTE DW outputs

  @description     freezes provided RTE data from DW

  @return          static void

  @param[in]       void

  @glob_in         GET_FCT_DW_CUSTOM_IN_DATA_PTR : internal pointer to external DW custom INPUT interface. FCT DW custom input 
                                                       [FCTDWInputCustom_t as in Rte_Type.h]
  @glob_out        GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR : internal data buffer for measfreezing DW OUTPUT generic interface [FCTDWInputCustom_t as in Rte_Type.h]
                   FCTVeh_FreezeBufferHeadOutputCustom  : internal data buffer for measfreezing HEAD OUTPUT custom interface [FCTDWOutputCustom_t as in Rte_Type.h]
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         16/6/2016

  @author          Sorin Ivascu
*************************************************************************************************************************/
static void FCTVehProcessMeasFreezeDW(void)
{
  /*------------------------------- Input ----------------------------------*/
  static const MEASInfo_t FCT_MeasInfoDWInputGeneric = 
  {
    FCT_MEAS_ID_DW_INPUT_CUSTOM,  /* .VirtualAddress */
    sizeof(FCTDWInputCustom_t),        /* .Length */
    (uint8)FCT_MEAS_FUNC_ID,            /* .FuncID */
    (uint8)FCT_MEAS_FUNC_CHAN_ID        /* .FuncChannelID */
  };
  static const MEASInfo_t FCT_MeasInfoDWCPAR = 
  {
	  FCT_MEAS_ID_DW_PAR,  /* .VirtualAddress */
	  sizeof(CPAR_DW_Parameters_t),        /* .Length */
	  (uint8)FCT_MEAS_FUNC_ID,            /* .FuncID */
	  (uint8)FCT_MEAS_FUNC_CHAN_ID        /* .FuncChannelID */
  };

  /*------------------------------- Output ----------------------------------*/
  static const MEASInfo_t FCT_DWOutputGenericDataMeasInfo = 
  {
    FCT_MEAS_ID_DW_OUTPUT_CUSTOM,    /* .VirtualAddress */
    sizeof(FCTDWOutputCustom_t),				    /* .Length */
    FCT_MEAS_FUNC_ID,					  /* .FuncID */
    FCT_MEAS_FUNC_CHAN_ID				  /* .FuncChannelID */
  };

#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
  (void)memcpy(&FCTVeh_FreezeBufferDWInputCustom, GET_FCT_DW_CUSTOM_IN_DATA_PTR, sizeof(FCTDWInputCustom_t));
  (void)FCT_FREEZE_DATA(&FCT_MeasInfoDWInputGeneric, &FCTVeh_FreezeBufferDWInputCustom, &FCTVehMeasCallback);
  (void)memcpy(&FCTVeh_FreezeBufferDWCPAR, GET_FCT_DW_CPAR_DATA_PTR, sizeof(CPAR_DW_Parameters_t));
  (void)FCT_FREEZE_DATA(&FCT_MeasInfoDWCPAR, &FCTVeh_FreezeBufferDWCPAR, &FCTVehMeasCallback);
  (void)memcpy(&FCTVeh_FreezeBufferDWGenericOutput, GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR, sizeof(FCTDWOutputCustom_t));
  (void)FCT_FREEZE_DATA(&FCT_DWOutputGenericDataMeasInfo, &FCTVeh_FreezeBufferDWGenericOutput, &FCTVehMeasCallback);
#else
  (void)FCT_FREEZE_DATA(&FCT_MeasInfoDWInputGeneric, (void*) GET_FCT_DW_CUSTOM_IN_DATA_PTR, NULL);
  (void)FCT_FREEZE_DATA(&FCT_MeasInfoDWCPAR, (void*) GET_FCT_DW_CPAR_DATA_PTR, NULL);
  (void)FCT_FREEZE_DATA(&FCT_DWOutputGenericDataMeasInfo, (void*) GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR, NULL);
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
}
#endif /* FCT_CFG_DW_PROCESSING */

/*******************************************************************************************/


/*************************************************************************************************************************
  Functionname:    FCTVehProcessMeasFreeze                                                                          */ /*!

  @brief           freezes the FCT vehicle meas freezes if algo is running.

  @description     Do data meas freeze for FCT_VEH

                      @startuml 
                      Start
                          Partition  FCTVehProcessMeasFreeze
                              -  freezes the FCT vehicle meas freezes if algo is running.
                      End
                   @enduml

  @return          static void

  @param[in]       pProvidePorts : output port interface provided to FCTVeh
                    pProvidePorts->pErrorOut : FCT error output [FCTVehErrorOut_t as in Rte_Type.h] 

  @glob_in         FCTVeh_pCtrlData : internal pointer to relevant external control data INPUT interface [FCTCtrlData_t as in Rte_Type.h] 
  @glob_out        FCTVeh_FreezeBufferVehCtrlData : internal data buffer for measfreezing Vehicle Control Data [FCTCtrlData_t as in Rte_Type.h] 
  @glob_out        FCTVeh_FreezeBufferErrorOutput : internal data buffer for measfreezing FCTVeh error OUTPUT interface [FCTVehErrorOut_t as in Rte_Type.h] 

  @c_switch_part   FCT_VEH_CFG_FREEZE_CTRL_DATA         : Switch to Freeze FCTVehCtrlData from ECU code
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH             : FCT error output from FCT_VEH
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG                : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT             : FCT veh custom output interface
  @c_switch_part   FCT_VEH_CFG_FREEZE_USE_CALLBACK      : Switches to make local copy of pointer interfaces and use callback measfreeze function
                                                          use this functionality if output pointers are non constant (ringbuffer IPC)
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING  : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_LOPC_COMPONENT              : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH             : FCT error output from FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT             : FCT veh custom output interface
  @c_switch_full   FCT_MEASUREMENT                      : Activate Measurement Output Code

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @todo            Add any output data to be frozen! add discription in the function header for camera project information

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehProcessMeasFreeze( reqFCTVehPrtList_t const * const pRequirePorts, proFCTVehPrtList_t const * const pProvidePorts)
{
  /*setting up MeasInfo*/

  /*request ports*/
#if (FCT_VEH_CFG_FREEZE_CTRL_DATA)
#if (FCT_CFG_USE_BASECTRLDATA)
  static const MEASInfo_t FCT_VehCtrlMeasInfo = 
  {
    FCT_MEAS_ID_VEH_BASE_CTRL_DATA,    /* VirtualAddress */
    sizeof(BaseCtrlData_t),            /* Length */
    FCT_MEAS_FUNC_ID,                  /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID              /* FuncChannelID */
  };
#else
  static const MEASInfo_t FCT_VehCtrlMeasInfo = 
  {
    FCT_MEAS_ID_VEH_CTRL_DATA,        /* VirtualAddress */
    sizeof(FCTCtrlData_t),            /* Length */
    FCT_MEAS_FUNC_ID,                 /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID             /* FuncChannelID */
  };
#endif /* #if (FCT_CFG_USE_BASECTRLDATA) */
#endif /* #if (FCT_VEH_CFG_FREEZE_CTRL_DATA) */

  /*provide ports*/


  /*ERROR output*/
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  static const MEASInfo_t FCT_VehErrMeasInfo = 
  {
    FCT_MEAS_ID_VEH_ERROR_OUT_VADDR,	/* VirtualAddress */
    sizeof(FCTVehErrorOut_t),			/* Length */
    FCT_MEAS_FUNC_ID,             /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif

  /*(Ethernet) Bus DEBUG signals*/
#if (FCT_CFG_USE_BUS_DEBUG)
  static const MEASInfo_t FCT_EbaBusDebugMeasInfo = 
  {
    FCT_MEAS_ID_EBA_BUS_DEBUG,   /* VirtualAddress */
    sizeof(BusDebugData_t),        /* Length */
    FCT_MEAS_FUNC_ID,             /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif /*FCT_CFG_USE_BUS_DEBUG*/

  /*Arbitrated Output*/
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  static const MEASInfo_t FCTVehOutArbitratedMeasInfo = 
  {
    FCT_MEAS_ID_FCT_VEH_OUT_ARBIT,
    sizeof(FCTVehOutArbitrated_t),
    FCT_MEAS_FUNC_ID,             /* FuncID */
    FCT_MEAS_FUNC_CHAN_ID         /* FuncChannelID */
  };
#endif /* FCT_VEH_CFG_CUSTOMOUTPUT */

  /*Meas Freezing*/
  
  /* Request Port meas freezes */
#if (FCT_VEH_CFG_FREEZE_CTRL_DATA)
  if (pRequirePorts != NULL)
  {
    if (pRequirePorts->pVehCtrlData != NULL)
    {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
#if (FCT_CFG_USE_BASECTRLDATA)
      (void)memcpy(&FCTVeh_FreezeBufferVehCtrlData,pRequirePorts->pVehCtrlData,sizeof(BaseCtrlData_t));
#else
      (void)memcpy(&FCTVeh_FreezeBufferVehCtrlData,pRequirePorts->pVehCtrlData,sizeof(FCTCtrlData_t));
#endif /* FCT_CFG_USE_BASECTRLDATA */
      /* FCTVehCtrl freezes OP-mode and relevant Infos */
      (void)FCT_FREEZE_DATA(&FCT_VehCtrlMeasInfo, &FCTVeh_FreezeBufferVehCtrlData, &FCTVehMeasCallback);
#else
      /* FCTVehCtrl freezes OP-mode and relevant Infos */
      (void)FCT_FREEZE_DATA(&FCT_VehCtrlMeasInfo, pRequirePorts->pVehCtrlData, NULL);
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
    }
  }
#else
  _PARAM_UNUSED(pRequirePorts);//PRQA S 3119 3
 /* date: 2019-06-28, reviewer:, reason:Variable might be used in future*/
#endif /* (FCT_VEH_CFG_FREEZE_CTRL_DATA) */

  /*ERROR output*/
  if (pProvidePorts!= NULL)
  {
#if (FCT_CFG_ERROR_OUTPUT_VEH)
    if (pProvidePorts->pErrorOut != NULL)
    {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
      (void)memcpy(&FCTVeh_FreezeBufferErrorOutput, pProvidePorts->pErrorOut, sizeof(FCTVehErrorOut_t));
      (void)FCT_FREEZE_DATA(&FCT_VehErrMeasInfo, &FCTVeh_FreezeBufferErrorOutput, &FCTVehMeasCallback);
#else
      (void)FCT_FREEZE_DATA(&FCT_VehErrMeasInfo, pProvidePorts->pErrorOut, NULL);// PRQA S 0315 
/* date: 2019-06-28, reviewer:, reason:Case to void intended as use of generic interface */
#endif /*FCT_VEH_CFG_FREEZE_USE_CALLBACK*/
    }
#endif /*FCT_CFG_ERROR_OUTPUT_VEH*/

  /*Arbitrated Output*/
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    if (pProvidePorts->pFCTVehOutArbitrated != NULL)
    {
#if (FCT_VEH_CFG_FREEZE_USE_CALLBACK)
      (void)memcpy(&FCTVeh_FreezeBufferVehCustomOut, pProvidePorts->pFCTVehOutArbitrated, sizeof(FCTVehOutArbitrated_t));
      (void)FCT_FREEZE_DATA(&FCTVehOutArbitratedMeasInfo, &FCTVeh_FreezeBufferVehCustomOut, &FCTVehMeasCallback);
#else
      (void)FCT_FREEZE_DATA(&FCTVehOutArbitratedMeasInfo, pProvidePorts->pFCTVehOutArbitrated, NULL);// PRQA S 0315
/* date: 2019-06-28, reviewer:, reason:Case to void intended as use of generic interface */
#endif
    }
#endif /*FCT_VEH_CFG_CUSTOMOUTPUT*/
#if (FCT_CFG_DW_PROCESSING)
    if (pProvidePorts->pDWOutputCustom != NULL)
    {
		FCTVehProcessMeasFreezeDW();
    }
#endif /*FCT_CFG_DW_PROCESSING*/
  }

#if ((SWITCH_OFF == FCT_CFG_ERROR_OUTPUT_VEH) && (SWITCH_OFF == FCT_CFG_USE_BUS_DEBUG )&& (SWITCH_OFF == FCT_VEH_CFG_CUSTOMOUTPUT))
  _PARAM_UNUSED(pProvidePorts);
#endif
}
#endif  /* #if FCT_MEASUREMENT */

/*************************************************************************************************************************
  Functionname:    FCTSetVehFrameData                                                                               */ /*!

  @brief           Set the Frame Data for Freeze

  @description     Set the FCTVehFrame data structure for status Freeze. This includes CycleCounter, sub component states and versions.

                    @startuml 
                    Start
                      Partition  FCTSetVehFrameData
                      -   Set operation modes of all sub-components.
                      If(pRequirePorts is not equal to NULL AND pRequirePorts->pVehCtrlData not equal to NULL) then (true)
                        If(eOpMode is BASE_OM_IDLE) then (true)
                           - FCTVehFrame.eFCTOpMode is assigned to FCT_MOD_INIT
                        Elseif(eOpMode is BASE_OM_RESET) then (true)
                          - FCTVehFrame.eFCTOpMode is assigned to FCT_MOD_INIT	
                        Elseif(eOpMode is BASE_OM_RUN) then (true)
                          - FCTVehFrame.eFCTOpMode is assigned to FCT_MOD_RUNNING		
                        Else
                          - FCTVehFrame.eFCTOpMode is assigned to FCT_MOD_INIT
                        Endif
                      Else (False)
                       - FCTVehFrame.eFCTOpMode is assigned to FCT_MOD_SHUTDOWN
                       - setup sub-module version numbers
                      Endif
                    End 
                  @enduml


  @return          static void

  @param[in]       pRequirePorts : the input interface passed to the FCT_SEN main function
                    pRequirePorts->pVehCtrlData->OpMode : [FCT_OP_MODE_t as in Rte_Type.h]


  @glob_in         -
  @glob_out        FCTVehFrame.eFCTOpMode                   : FCT operation mode [FCT_OP_MODE_t as in Rte_Type.h] 
  @glob_out        FCTVehFrame.uiCycleCounter               : The FCT_VEH cycle counter [AlgoCycleCounter_t as in Rte_Type.h]
  @glob_out        FCTVehFrame.Versions.uiHEAD              : SW verion of HEAD [0...4294967296]

  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING  : FCT driver intention monitoring switch
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @todo            Review this function

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void FCTSetVehFrameData( const reqFCTVehPrtList_t * pRequirePorts ) 
{
  if ((pRequirePorts != NULL)&&(pRequirePorts->pVehCtrlData != NULL))
  {
#if (FCT_CFG_USE_BASECTRLDATA)
    switch(pRequirePorts->pVehCtrlData->eOpMode)
    {
    case BASE_OM_IDLE:
      FCTVehFrame.eFCTOpMode = FCT_MOD_INIT;
      break;
    case BASE_OM_RESET:
      FCTVehFrame.eFCTOpMode = FCT_MOD_INIT;
      break;
    case BASE_OM_RUN:
      FCTVehFrame.eFCTOpMode = FCT_MOD_RUNNING;
      break;
    default:
      FCTVehFrame.eFCTOpMode = FCT_MOD_INIT;
      break;
    }
#else
    FCTVehFrame.eFCTOpMode   = pRequirePorts->pVehCtrlData->OpMode;
#endif
  }
  else
  {
    FCTVehFrame.eFCTOpMode = FCT_MOD_SHUTDOWN;
    FCTVehSignalErrorShutdown();
  }
  FCTVehFrame.uiCycleCounter++;

  /* setup sub-module version numbers */
  FCTVehFrame.Versions.FCT_VERSION_AS_TEXT  = FCTALL_SW_VERSION_NUMBER;
  FCTVehFrame.Versions.uiFCTVEH             = FCTALL_SW_VERSION_NUMBER;
}

/*************************************************************************************************************************
  Functionname:    FCTVehSetupPorts                                                                                 */ /*!

  @brief           Connect all Ports to local variables aliases and sets the Interface Version Number for output ports.

  @description     Connect all Ports to local Variables aliases and sets the Interface Version Number for output ports.
  
                    @startuml 
                      Start
                          Partition  FCTVehSetupPorts
                              -  Connect all Ports to local variables aliases and sets the Interface Version Number for output ports.
                      End
                   @enduml

  @return          static void

  @param[in]       pRequirePorts : the inputs interface passed to the FCT_Veh main function.
                    pRequirePorts->pEgoDynRaw           : The dynamic vehicle ego data raw [VehDyn_t as in Rte_Type.h]
                    pRequirePorts->pEgoStaticData       : vehicle parameter [VehPar_t as in Rte_Type.h] 
                    pRequirePorts->pAlignmentMonInput   : Alignment monitoring output data [ALN_Monitoring_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputCustom      : Custom DIM input [DIMInputCustom_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputGeneric     : Generic DIM input [DIMInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pDIMOutputCustom     : Custom DIM Output [DIMOutputCustom_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputGeneric    : Generic HEAD input [HEADInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputCustom     : Custom HEAD input [HEADInputCustom_t as in Rte_Type.h]
                    pRequirePorts->pHEADOutputGeneric   : Generic HEAD output [HEADOutputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHEADOutputCustom    : Custom HEAD output [HEADOutputCustom_t as in Rte_Type.h]
                    pRequirePorts->pFCTCDHypotheses     : CD hypotheses [HypothesisIntf_t in Rte_Type.h]
                    pRequirePorts->pBswAlgoParameters   : Input algo parameters from BSW [BSW_s_AlgoParameters_t in Rte_Type.h]
                    pRequirePorts->pCPAR_FCT_Parameters : FCT Coding Parameters [CPAR_FCT_Parameters_t in Rte_Type.h]
                    pRequirePorts->pVehSig              : Direct access to vehicle signals  [sMeasCycleMonitor as in fct_type.h]
                    pRequirePorts->pVehCtrlData         : FCT_VEH operation mode control data  [FCTCtrlData_t as in Rte_Type.h]
                    pRequirePorts->pVehSig->PowerTrain  : [PowerTrain_t as in Rte_Type.h]
                    pRequirePorts->pAccLever            : ACC lever information (input from driver) [AccLeverInput_t as in Rte_Type.h]
                    pRequirePorts->pLongCtrlResp        : Dynamic controller response [LongCtrlInput_t as in Rte_Type.h]
                    pRequirePorts->pAccDisplayObj       : Display object data output by FCT_SEN [acc_object_t as in Rte_Type.h]
                    pRequirePorts->pAccOutput           : ACC output data by FCT_SEN [acc_output_data_t as in Rte_Type.h]
                    pRequirePorts->pFctVehCustInput     : Custom input for FCT_VEH [FCTVehCustomInput_t as in Rte_Type.h]
                    pRequirePorts->pSLAData             : SLA speed limit data from FCT_SEN [SLAData_t as in Rte_Type.h]
  @param[in]       pProvidePorts : the outputs interface passed to FCT_Veh.
                    pProvidePorts->pLongCtrlOutput      : Longitudinal controller output data [LongCtrlOutput_t as in Rte_Type.h]
  @glob_in         -
  @glob_out        GET_EGO_RAW_DATA_PTR : internal pointer to external raw ego dynamics INPUT interface [VehDyn_t as in Rte_Type.h]
  @glob_out        GET_EGO_STATIC_DATA_PTR : The static vehicle ego data [VehPar_t as in Rte_Type.h] 
  @glob_out        FCTVEH_pAlignmentMonInput : internal pointer to external Alignment Input [ALN_Monitoring_t as in Rte_Type.h]
  @glob_out        FCTVEH_pBswAlgoParameters : Input algo parameters from BSW [BSW_s_AlgoParameters_t in Rte_Type.h]
  @glob_out        FCTVeh_pCtrlData : internal pointer to relevant external control data INPUT interface [FCTCtrlData_t as in Rte_Type.h]
  @glob_out        FCTVEH_pFctVehCustInput [FCTVehCustomInput_t as in Rte_Type.h]
  @glob_out        FCTVEH_pSLAData [SLAData_t as in Rte_Type.h]

  @c_switch_part   FCT_VEH_CFG_VEH_PAR_INPUT              : Configuration switch enabling passing of static vehicle parameters (VehPar_t)
                                                            to FCT_VEH. Currently needed by long controllers LODM sub-component. 
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF            : Special configuration switch to include all interfaces in request/provide
                                                            port structures, even if the current configuration does not use them. This 
                                                            enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_CFG_USE_CTRLDATA                   : Switch that enables the FCT Control Data struct and disables the OPMode-port
  @c_switch_part   FCT_CFG_LOPC_COMPONENT                : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT               : FCT veh custom output interface
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG                  : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         22/9/2017

  @todo            Review this function. add discription in the function header for camera project information

  @author          Clemens Schnurr
*************************************************************************************************************************/
static void FCTVehSetupPorts( const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts ) 
{
  _PARAM_UNUSED(pProvidePorts); /* Disable warning in case of no function is activated => todo switch to de-active complete FCT_VEH cycle *///PRQA S 3119 3
 /* date: 2019-06-28, reviewer:, reason:Variable might be used in future*/
  
  FCTVEH_pEgoDynRaw                 = pRequirePorts->pEgoDynRaw;
#if (FCT_VEH_CFG_VEH_PAR_INPUT)
  FCTVEH_pGlobEgoStatic             = pRequirePorts->pEgoStaticData;
#endif

#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT) 
  FCTVEH_pAlignmentMonInput         = pRequirePorts->pAlignmentMonInput;
#endif

#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  GET_FCT_HMI_DATA_PTR              = pRequirePorts->pHMIData;
#endif
/**************************************DW ADDED*********************************/
#if (FCT_CFG_DW_PROCESSING)
  GET_FCT_DW_CUSTOM_IN_DATA_PTR                = pRequirePorts->pDWInputCustom; 
  GET_FCT_DW_CPAR_DATA_PTR					   = pRequirePorts->pDWCPAR;
  GET_FCT_VEH_SIG_DATA_PTR                     = pRequirePorts->pVehSig;
  GET_FCT_DW_FCT_CUSTOM_ACC_OUTPUT_IN_DATA_PTR = pRequirePorts->pFCTCustomACCOutput_DWIn;
  GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR            = pProvidePorts->pDWOutputCustom;

  /* set output interface version */
  GET_FCT_DW_CUSTOM_OUTPUT_DATA_PTR->uiVersionNumber = FCT_DW_OUTPUT_CUSTOM_INTFVER;
#endif /* FCT_CFG_DW_PROCESSING */
/********************************************************************************/

#if (FCT_CFG_BSW_ALGO_PARAMS)
  FCTVEH_pBswAlgoParameters   = pRequirePorts->pBswAlgoParameters;
#endif

#if (FCT_VEH_CFG_EM_CLD_INPUT)
  FCTVEH_pEmCldOutput         = pRequirePorts->pEM_CLD_Output;
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  FCTVEH_pVehCompState                      = pProvidePorts->pVehCompState;
#if COMP_STATE_INTFVER > 2u
  FCTVEH_pVehCompState->uiVersionNumber       = COMP_STATE_INTFVER;
#else
  FCTVEH_pVehCompState->uVersionNumber       = COMP_STATE_INTFVER;
#endif
#endif
  FCTVeh_pCtrlData          = pRequirePorts->pVehCtrlData;

#if (FCT_CFG_LOPC_COMPONENT)
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
    FCTVEH_pVehSigPowerTrain = &pRequirePorts->pVehSig->PowerTrain;
#else
#error FCT_CFG_LOPC_COMPONENT requires access to VehSigs PowerTrain sub-struct!
#endif
    FCTVEH_pAccLever      = pRequirePorts->pAccLever;
    FCTVEH_pLongCtrlResp  = pRequirePorts->pLongCtrlResp;
    FCTVEH_pAccDisplayObj = pRequirePorts->pAccDisplayObj;
    FCTVEH_pAccOutput     = pRequirePorts->pAccOutput;
    FCTVEH_pFctVehLongOut = pProvidePorts->pFctVehLongOut;
#if (FCT_CFG_TCI)
    FCTVEH_pTCIInput      = pRequirePorts->pTCIInput;
    FCTVEH_pTCIOutput     = pProvidePorts->pTCIOutput;
#endif
    FCTVEH_pLongCtrlOutput = pProvidePorts->pLongCtrlOutput;
#if (FCT_CFG_SLA_FEATURE)
    FCTVEH_pSLAData       = pRequirePorts->pSLAData;
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    FCTVEH_pAccOOIData = pRequirePorts->pFCTAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
    FCTVEH_pFctVehCustInput = pRequirePorts->pFctVehCustInput;
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    FCTVEH_pFCTVehOutArbitrated = pProvidePorts->pFCTVehOutArbitrated;
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    FCTVEH_pEbaBusDebugData = pProvidePorts->pEbaBusDebugData;
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
    pt_FCT_IN_TCSP = pRequirePorts->pt_FCT_IN_TCSP;
    pt_FCT_OUT_TCCP = pProvidePorts->pt_FCT_OUT_TCCP;
#if (FCT_CFG_HP_TFC_PORT_CNT)
    pt_FCT_IN_TFCP = pRequirePorts->pt_FCT_IN_TFCP;
    pt_FCT_OUT_TFSP = pProvidePorts->pt_FCT_OUT_TFSP;
#endif
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
    FCTVEH_pLoDmcOutput = pRequirePorts->pLoDmcOutput;
#endif  /*  FCT_VEH_CFG_USE_LODMC_OUTPUT  */
}

/*************************************************************************************************************************
  Functionname:    FCTVehCheckPorts                                                                                 */ /*!

  @brief           Do Checking of Input and output interfaces for valid pointer and signal status.

  @description     Do Checking of input and output interfaces for valid pointer and signal status and trigger the internal error management.

                      @startuml 
                      Start
                          Partition  FCTVehCheckPorts
                              -   Do Checking of Input and output interfaces for valid pointer and signal status.
                      End
                   @enduml

  @return          static void 

  @param[in]       pRequirePorts : the input interfaces to the FCTVeh main function
                    pRequirePorts->pVehCtrlData                                 [FCTCtrlData_t as in Rte_Type.h]
                    pRequirePorts->pEgoDynRaw                                   [VehDyn_t as in Rte_Type.h]
                    pRequirePorts->pEgoStaticData                               [pEgoStaticData as in Rte_Type.h]
                    pRequirePorts->pAccLever                                    [AccLeverInput_t as in Rte_Type.h]
                    pRequirePorts->pLongCtrlResp                                [LongCtrlInput_t as in Rte_Type.h]
                    pRequirePorts->pAccDisplayObj                               [acc_object_t as in Rte_Type.h]
                    pRequirePorts->pAccOutput                                   [acc_output_data_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputCustom                              [DIMInputCustom_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputGeneric                             [DIMInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHMIData                                     [t_HMI_Data_t as in Rte_Type.h]
                    pRequirePorts->pFCTCDHypotheses                             [HypothesisIntf_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputGeneric                            [HEADInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputCustom                             [HEADInputCustom_t  as in Rte_Type.h]
                    pRequirePorts->pAlignmentMonInput                           [ALN_S_Monitoring_t as in Rte_Type.h]
                    pRequirePorts->pBswAlgoParameters                           [BSW_s_AlgoParameters_t as in Rte_Type.h]
                    pRequirePorts->pCPAR_FCT_Parameters                         [CPAR_FCT_Parameters_t as in Rte_Type.h]
                    pRequirePorts->pVehSig                                      [VehSig_t as in Rte_Type.h]
                    pRequirePorts->pEM_CLD_Output                               [EM_CLD_Output_t as in Rte_Type.h]
                    pRequirePorts->pFctVehCustInput                             [FCTVehCustomInput_t as in Rte_Type.h]
                    pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus          [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus            [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccLever->sSigHeader.eSigStatus             [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pLongCtrlResp->sSigHeader.eSigStatus         [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccDisplayObj->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccOutput->sSigHeader.eSigStatus            [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFCTAccOOIData->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pDIMInputCustom->sSigHeader.eSigStatus       [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pDIMInputGeneric->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHMIData->s_Header.eSigStatus                [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHMIData->sSigHeader.eSigStatus              [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFCTCDHypotheses->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHEADInputGeneric->sSigHeader.eSigStatus     [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHEADInputCustom->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus    [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.eSigStatus  [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pVehSig->sSigHeader.eSigStatus               [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEM_CLD_Output->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]

  @param[in]       pProvidePorts : the output interfaces from FCTVeh                    
                    pProvidePorts->pFctVehLongOut           [FctVeh2SenInfo_t as in Rte_Type.h]
                    pProvidePorts->pLongCtrlOutput          [LongCtrlOutput_t as in Rte_Type.h]
                    pProvidePorts->pDIMOutputCustom         [DIMOutputCustom_t as in Rte_Type.h]
                    pProvidePorts->pHEADOutputGeneric       [HEADOutputGeneric_t as in Rte_Type.h]
                    pProvidePorts->pHEADOutputCustom        [HEADOutputCustom_t  as in Rte_Type.h]
                    pProvidePorts->pErrorOut                [FCTVehErrorOut_t as in Rte_Type.h]
                    pProvidePorts->pEbaBusDebugData         [BusDebugData_t as in Rte_Type.h]
                    pProvidePorts->pLkaBusDebugData         [BusDebugData_t as in Rte_Type.h]
                    pProvidePorts->pFCTVehOutArbitrated     [FCTVehOutArbitrated_t as in Rte_Type.h]
  @param[in]       pServiceFuncts : the service function interface passed to FCTVeh [AS_t_ServiceFuncts as in algo_service_types.h]    
                    pServiceFuncts->pfMeasFreeze  [AS_t_MeasHdlr as in algo_service_types.h]
                    pServiceFuncts->pfRTAAlgoServiceAddEvent  [AS_t_RTAAlgoServiceAddEvent as in algo_service_types.h]
  @param[in]       pErrorBuffer  : the internal error buffer element for error communication to global scheduler.  
  
  @glob_in         -
  @glob_out        pFCTVehServiceFuncts [AS_t_ServiceFuncts as in algo_service_types.h]

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS     : FCT switch to use third parameter in Exec methods to call the Function. 
                                                            Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_LOPC_COMPONENT                : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF            : Special configuration switch to include all interfaces in request/provide
                                                            port structures, even if the current configuration does not use them. This 
                                                            enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_part   FCT_CFG_USE_DEM                        : Switch that enables the DEM reporting towards Service Interface
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH               : FCT error output from FCT_VEH
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG                  : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT               : FCT veh custom output interface
  @c_switch_part   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK  : Switch that enables signal status input check
 
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         03/12/2016

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Christian Obst
*************************************************************************************************************************/
static void FCTVehCheckPorts( const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                             , const AS_t_ServiceFuncts *pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                             , GenAlgoQualifiers_t *const pErrorBuffer
#endif
                             ) 
{

  /* Check that all request port pointers are set to non-null */
  const boolean bRequirePortOk = FCTVehCheckRequirePorts(  pRequirePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                                          ,pServiceFuncts
#endif
                                                        );
  /* Check that all Provide port pointers are set to non-null */
  const boolean bProvidePortOk = FCTVehCheckProvidePorts( pProvidePorts );

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
  /* check for SignalState in requestPorts*/
  boolean bSigStateRequirePortNotInvalid;
  boolean bSigStateRequirePortNotInitError;
  
  if ( bRequirePortOk == TRUE)
  {

    bSigStateRequirePortNotInvalid = FCTVehCheckSigStateRequirePorts(pRequirePorts);
    bSigStateRequirePortNotInitError = FCTVehCheckPortsInit(pRequirePorts);

  } 
  else
  {
    bSigStateRequirePortNotInitError = FALSE;
    bSigStateRequirePortNotInvalid = FALSE;
  }
#endif

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /*assign Service functions to internal global alias no matter if NULL or not (used for DEM events)*/
  pFCTVehServiceFuncts = pServiceFuncts;
#endif

  /* Verify that all request port pointers are set to non-null */
  if( bRequirePortOk == FALSE )//PRQA S 1863
/* date: 2019-06-28, reviewer:, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
  {
    /* Some request port pointer is NULL => DEM and shutdown */

#if (FCT_CFG_USE_DEM)
    /*validity of service pointer isn't clear here*/
    FCTVehSetDem(FCT_VEH_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /* setup the Algo Error Buffer */
    FCTVehSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
    /* shutdown the system */
    FCTVehSignalErrorShutdown();
  }
  else
  {
    /* Verify that provide port buffer pointers are set (non-null) */
    if ( bProvidePortOk == FALSE )//PRQA S 1863
/* date: 2019-06-28, reviewer:, reason:Both operands of equality operator is promoted to  singned int, this has no side affect on functionality */
    {
#if (FCT_CFG_USE_DEM)
    /* Some provide port pointer is NULL => DEM -> shutdown */
      FCTVehSetDem(FCT_VEH_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
      FCTVehSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
      FCTVehSignalErrorShutdown();
    }
    else
    {
#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
      /* no NullPointer in request ports*/
      /* check for SignalState in requestPorts*/
      if ( bSigStateRequirePortNotInitError == FALSE)
      {
#if (FCT_CFG_USE_DEM)
        /* Some provide port pointer is NULL => DEM -> shutdown */
        FCTVehSetDem(FCT_VEH_FUSI_ERROR, DEM_EVENT_STATUS_FAILED);
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
        FCTVehSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
        FCTVehSignalErrorShutdown();
      }
      else if( bSigStateRequirePortNotInvalid == FALSE )
      {
#if (FCT_CFG_USE_DEM)
        /* receive and provide ports are fine */
        FCTVehSetDem(FCT_VEH_FUSI_ERROR, DEM_EVENT_STATUS_PASSED);
#endif
        /*signal state broken -> no dem only shutdown*/
#if (FCT_CFG_USE_ALGOCOMPSTATE)
        /* setup the Algo Error Buffer */
        FCTVehSetAlgoErrorBuffer(pErrorBuffer, ALGO_QUAL_CRITICAL_INPUT_ERROR);
#endif
        /* shutdown the system */
        FCTVehSignalErrorShutdown();
      }
      else
#endif /*FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK*/
      {
#if (FCT_CFG_USE_DEM)
        /* receive and provide ports are fine */
        FCTVehSetDem(FCT_VEH_FUSI_ERROR, DEM_EVENT_STATUS_PASSED);
#endif
      }

    }

  }
}

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTVehCheckPortsInit                                                                                */ /*!

  @brief           Check input interfaces for signal state init.

  @description     Check input interfaces for signal state init. If in one interface a signal stays in init state for 
                   more than ALGO_FUSI_DEBOUNCE_TIME, the returned bSigState is set to false. This in consequence shall 
                   trigger a DEM Event.

                   @startuml 
                      Start
                          Partition  FCTVehCheckPortsInit
                              -   Check input interfaces for signal state init.
                      End
                   @enduml

  @return          boolean bSigStateOk : indicates that no signal was in signal state init for more than 
                   ALGO_FUSI_DEBOUNCE_TIME

  @param[in]       pRequirePorts : the input interfaces to the FCTVeh main function
                    pRequirePorts->pVehCtrlData                                 [FCTCtrlData_t as in Rte_Type.h]
                    pRequirePorts->pEgoDynRaw                                   [VehDyn_t as in Rte_Type.h]
                    pRequirePorts->pEgoStaticData                               [pEgoStaticData as in Rte_Type.h]
                    pRequirePorts->pAccLever                                    [AccLeverInput_t as in Rte_Type.h]
                    pRequirePorts->pLongCtrlResp                                [LongCtrlInput_t as in Rte_Type.h]
                    pRequirePorts->pAccDisplayObj                               [acc_object_t as in Rte_Type.h]
                    pRequirePorts->pAccOutput                                   [acc_output_data_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputCustom                              [DIMInputCustom_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputGeneric                             [DIMInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHMIData                                     [t_HMI_Data_t as in Rte_Type.h]
                    pRequirePorts->pFCTCDHypotheses                             [HypothesisIntf_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputGeneric                            [HEADInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputCustom                             [HEADInputCustom_t  as in Rte_Type.h]
                    pRequirePorts->pAlignmentMonInput                           [ALN_S_Monitoring_t as in Rte_Type.h]
                    pRequirePorts->pBswAlgoParameters                           [BSW_s_AlgoParameters_t as in Rte_Type.h]
                    pRequirePorts->pCPAR_FCT_Parameters                         [CPAR_FCT_Parameters_t as in Rte_Type.h]
                    pRequirePorts->pVehSig                                      [VehSig_t as in Rte_Type.h]
                    pRequirePorts->pEM_CLD_Output                               [EM_CLD_Output_t as in Rte_Type.h]
                    pRequirePorts->pFctVehCustInput                             [FCTVehCustomInput_t as in Rte_Type.h]
                    pRequirePorts->pSLAData                                     [SLAData_t as in Rte_Type.h]
  
  @glob_in         FCTVehSoftErrorCounter                 : Global struct containing soft error counters for all require signals

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS     : FCT switch to use third parameter in Exec methods to call the Function. 
                                                            Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_LONG_PROCESSING                : Configuration switch for enabling FCT_LONG processing
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF            : Special configuration switch to include all interfaces in request/provide
                                                            port structures, even if the current configuration does not use them. This 
                                                            enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface  
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
 
  @c_switch_full   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK  : Switch that enables signal status input check
  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.03.2017
  @changed         22.09.2017

  @author          Andreas Danner | andreas.danner@continental-corporation.com
*************************************************************************************************************************/
static boolean FCTVehCheckPortsInit(const reqFCTVehPrtList_t *pRequirePorts)
{
  boolean bSigStateOk = TRUE;
  
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiVehCtrlData);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiEgoDynRaw);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiEgoStaticData);
#if (FCT_CFG_LONG_PROCESSING)
#if (CFG_ACC_LEVER_INPUT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pAccLever->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiAccLever);
#endif
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pLongCtrlResp->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiLongCtrlResp);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pAccDisplayObj->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiAccDisplayObj);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pAccOutput->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiAccOutput);
#if (FCT_CFG_TCI)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pTCIInput->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiTCIInput);
#endif
#if (FCT_CFG_SLA_FEATURE)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pSLAData->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiSLAData);
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pFCTAccOOIData->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiFCTAccOOIData);
#endif
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pDIMInputCustom->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiDIMInputCustom);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pDIMInputGeneric->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiDIMInputGeneric);
#endif
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pHMIData->s_Header.eSigStatus, &FCTVehSoftErrorCounter.uiHMIData);
#else
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pHMIData->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiHMIData);
#endif
#endif
#if (FCT_CFG_COLLISION_DETECTION)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pFCTCDHypotheses->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiFCTCDHypotheses);
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pHEADInputGeneric->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiHEADInputGeneric);
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pHEADInputCustom->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiHEADInputCustom);
#endif
#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiAlignmentMonInput);
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
    /*no signal header*/
#endif
#if (FCT_CFG_CPAR_PARAMS)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiCPAR_FCT_Parameters);
#endif
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pVehSig->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiVehSig);
#endif
#if (FCT_VEH_CFG_EM_CLD_INPUT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pEM_CLD_Output->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiEM_CLD_Output);
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  bSigStateOk = bSigStateOk & FCTVehSetSoftErrorCounter(pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus, &FCTVehSoftErrorCounter.uiFctVehCustInput);
#endif

  return bSigStateOk;

}
#endif /* FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK */

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTVehSetSoftErrorCounter                                                                               */ /*!

  @brief           Check number of following cycles in init state.

  @description     Check number of following cycles in init state.

                    @startuml 
                    Start
                      Partition  FCTVehSetSoftErrorCounter
                       -   Check number of following cycles in init state.
                      If(Signal status of the examined require Signal is equal to 0) then (true)
                        - pSoftErrorCounter is calculated ( MIN((*pSoftErrorCounter+1),(ALGO_FUSI_DEBOUNCE_CYCLES+1));)
                      Else (False)
                          - pSoftErrorCounter is assigned to 0	
                      Endif
                      If(Soft error counter of the examined require signal is greater than ALGO_FUSI_DEBOUNCE_CYCLES) then (true)
                        - bResult is assigned to False	
                      Endif
                   End 
                  @enduml


  @return          boolean bRetPortState : indicated that Require port pointers are set (non-null)

  @param[in]       sSigStatus         : Signal status of the examined require Signal
  @param[in]       pSoftErrorCounter  : Soft error counter of the examined require signal
  @glob_in         -

  @c_switch_part   -
 
  @c_switch_full   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK  : Switch that enables signal status input check

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.03.2017
  @changed         06.03.2017

  @author          Andreas Danner | andreas.danner@continental-corporation.com
*************************************************************************************************************************/
static boolean FCTVehSetSoftErrorCounter(const AlgoSignalState_t sSigStatus, AlgoCycleCounter_t *pSoftErrorCounter)
{
  boolean bResult = TRUE;

  if (sSigStatus == AL_SIG_STATE_INIT)
  {
    *pSoftErrorCounter = MIN((*pSoftErrorCounter+1),(ALGO_FUSI_DEBOUNCE_CYCLES+1));
  }
  else
  {
    *pSoftErrorCounter = 0;
  }

  if (*pSoftErrorCounter > ALGO_FUSI_DEBOUNCE_CYCLES)
  {
    bResult = FALSE;
  }

  return bResult;
}
#endif /* FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK */

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*************************************************************************************************************************
  Functionname:   FCTVehInitSoftErrorCounter                                                                               */ /*!

  @brief          Set soft error counter to zero 

  @description    Each time the status of a request port is found to be INIT, its soft error counter is increased.
                  As it reaches ALGO_FUSI_DEBOUNCE_CYCLES a DEM Error is triggered. FCTVehInitSoftErrorCounter resets 
				          the struct used to store the soft error counters of the request signals

  @return          -

  @param[in]       -
  @param[in]       -

  @glob_in         FctVehSoftErrorCounter: All soft error counters
  @glob_out        FctVehSoftErrorCounter: All soft error counters

  @c_switch_full   FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK  : Switch that enables signal status input check

  @pre              
  @post             

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         06.03.2017
  @changed         06.03.2017

  @author          Andreas Danner | andreas.danner@continental-corporation.com
*************************************************************************************************************************/
static void FCTVehInitSoftErrorCounter(void)
{

  (void)memset(&FCTVehSoftErrorCounter, 0, sizeof(FCTVehSoftErrorCounter) );

}
#endif  /* FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK */
/*************************************************************************************************************************
  Functionname:    FCTVehCheckRequirePorts                                                                                 */ /*!

  @brief           Do Checking of Input interfaces for valid pointer.

  @description     Do Checking of Input interfaces for valid pointer.

                     @startuml 
                      Start
                          Partition  FCTVehCheckRequirePorts
                              -  Do Checking of Input interfaces for valid pointer.
                      End
                   @enduml

  @return          boolean bRetPortState : indicated that Require port pointers are set (non-null)

  @param[in]       pRequirePorts : the input interfaces to the FCTVeh main function
                    pRequirePorts->pVehCtrlData                                 [FCTCtrlData_t as in Rte_Type.h]
                    pRequirePorts->pEgoDynRaw                                   [VehDyn_t as in Rte_Type.h]
                    pRequirePorts->pEgoStaticData                               [pEgoStaticData as in Rte_Type.h]
                    pRequirePorts->pAccLever                                    [AccLeverInput_t as in Rte_Type.h]
                    pRequirePorts->pLongCtrlResp                                [LongCtrlInput_t as in Rte_Type.h]
                    pRequirePorts->pAccDisplayObj                               [acc_object_t as in Rte_Type.h]
                    pRequirePorts->pAccOutput                                   [acc_output_data_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputCustom                              [DIMInputCustom_t as in Rte_Type.h]
                    pRequirePorts->pDIMInputGeneric                             [DIMInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHMIData                                     [t_HMI_Data_t as in Rte_Type.h]
                    pRequirePorts->pFCTCDHypotheses                             [HypothesisIntf_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputGeneric                            [HEADInputGeneric_t as in Rte_Type.h]
                    pRequirePorts->pHEADInputCustom                             [HEADInputCustom_t  as in Rte_Type.h]
                    pRequirePorts->pAlignmentMonInput                           [ALN_S_Monitoring_t as in Rte_Type.h]
                    pRequirePorts->pBswAlgoParameters                           [BSW_s_AlgoParameters_t as in Rte_Type.h]
                    pRequirePorts->pCPAR_FCT_Parameters                         [CPAR_FCT_Parameters_t as in Rte_Type.h]
                    pRequirePorts->pVehSig                                      [VehSig_t as in Rte_Type.h]
                    pRequirePorts->pEM_CLD_Output                               [EM_CLD_Output_t as in Rte_Type.h]
                    pRequirePorts->pFctVehCustInput                             [FCTVehCustomInput_t as in Rte_Type.h]
                    pRequirePorts->pSLAData                                     [SLAData_t as in Rte_Type.h]

  @param[in]       pServiceFuncts : the service function interface passed to FCTVeh [AS_t_ServiceFuncts as in algo_service_types.h]    
                    pServiceFuncts->pfMeasFreeze  [AS_t_MeasHdlr as in algo_service_types.h]
                    pServiceFuncts->pfRTAAlgoServiceAddEvent  [AS_t_RTAAlgoServiceAddEvent as in algo_service_types.h]
  
  @glob_in         -

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS     : FCT switch to use third parameter in Exec methods to call the Function. 
                                                            Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_LOPC_COMPONENT                : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF            : Special configuration switch to include all interfaces in request/provide
                                                            port structures, even if the current configuration does not use them. This 
                                                            enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_part   FCT_CFG_USE_DEM                        : Switch that enables the DEM reporting towards Service Interface
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
 
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         22/09/2017
  @changed         -

  @author          Mohamed Abdelkarim
*************************************************************************************************************************/
static boolean FCTVehCheckRequirePorts(  const reqFCTVehPrtList_t * pRequirePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                        ,const AS_t_ServiceFuncts *pServiceFuncts
#endif
                                      ) 
{
  boolean bRetPortState = TRUE;

  /* Verify that all request port pointers are set to non-null */
  if(
    (pRequirePorts == NULL)
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
/* Save ServiceFunction Pointer */
    || (pServiceFuncts == NULL)
    || (pServiceFuncts->pfMeasFreeze == NULL)
#if (FCT_CFG_USE_FREEZE_CYCLE_START)
    || (pServiceFuncts->pfMeasStartFuncCycle == NULL)
#endif
#if (FCT_CFG_RTA_PROFILING)
    || (pServiceFuncts->pfRTAAlgoServiceAddEvent == NULL)
#endif
#if (FCT_CFG_USE_DEM)
    || (pServiceFuncts->pfDem_SetEventStatus == NULL)
#endif
#endif
    || (pRequirePorts->pVehCtrlData == NULL)
    || (pRequirePorts->pEgoDynRaw == NULL)
    || (pRequirePorts->pEgoStaticData == NULL)
#if (FCT_CFG_LOPC_COMPONENT)
#if (CFG_ACC_LEVER_INPUT)
    || (pRequirePorts->pAccLever == NULL)
#endif
    || (pRequirePorts->pLongCtrlResp == NULL)
    || (pRequirePorts->pAccDisplayObj == NULL)
    || (pRequirePorts->pAccOutput == NULL)
#if (FCT_CFG_TCI)
    || (pRequirePorts->pTCIInput == NULL)
#endif
#if (FCT_CFG_SLA_FEATURE)
    || (pRequirePorts->pSLAData == NULL)
#endif
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    || (pRequirePorts->pFCTAccOOIData == NULL)
#endif
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    || (pRequirePorts->pDIMInputCustom == NULL)
    || (pRequirePorts->pDIMInputGeneric == NULL)
#endif
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
    || (pRequirePorts->pHMIData == NULL)
#else
    || (pRequirePorts->pHMIData == NULL)
#endif
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    || (pRequirePorts->pFCTCDHypotheses == NULL)
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    || (pRequirePorts->pHEADInputGeneric == NULL)
    || (pRequirePorts->pHEADInputCustom == NULL)
#endif
#if (FCT_CFG_DW_PROCESSING)                                       /********DW ADDED*************************/
    || (pRequirePorts->pDWInputCustom == NULL)
    || (pRequirePorts->pDWCPAR == NULL)
	|| (pRequirePorts->pFCTCustomACCOutput_DWIn == NULL)         
#endif                                                           /******************************************/
#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
    || (pRequirePorts->pAlignmentMonInput == NULL)
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
    || (pRequirePorts->pBswAlgoParameters == NULL)
#endif
#if (FCT_CFG_CPAR_PARAMS)
    || (pRequirePorts->pCPAR_FCT_Parameters == NULL)
#endif
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
    || (pRequirePorts->pVehSig == NULL)
#endif
#if (FCT_VEH_CFG_EM_CLD_INPUT)
    || (pRequirePorts->pEM_CLD_Output == NULL)
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
    || (pRequirePorts->pFctVehCustInput == NULL)
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
    || (pRequirePorts->pt_FCT_IN_TCSP == NULL)
#if (FCT_CFG_HP_TFC_PORT_CNT)
    || (pRequirePorts->pt_FCT_IN_TFCP == NULL)
#endif
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
    || (pRequirePorts->pLoDmcOutput == NULL)
#endif
    )
  {
    bRetPortState=FALSE;
  }
  return bRetPortState;
}

/*************************************************************************************************************************
  Functionname:    FCTVehCheckProvidePorts                                                                                 */ /*!

  @brief           Do Checking of output interfaces for valid pointer.

  @description     Do Checking of output interfaces for valid pointer.

                       @startuml 
                      Start
                          Partition  FCTVehCheckProvidePorts
                              -  Do Checking of output interfaces for valid pointer.
                      End
                   @enduml

  @return          boolean bRetPortState : indicated that provide port buffer pointers are set (non-null) 

  @param[in]       pProvidePorts : the output interfaces from FCTVeh                    
                    pProvidePorts->pFctVehLongOut           [FctVeh2SenInfo_t as in Rte_Type.h]
                    pProvidePorts->pLongCtrlOutput          [LongCtrlOutput_t as in Rte_Type.h]
                    pProvidePorts->pDIMOutputCustom         [DIMOutputCustom_t as in Rte_Type.h]
                    pProvidePorts->pHEADOutputGeneric       [HEADOutputGeneric_t as in Rte_Type.h]
                    pProvidePorts->pHEADOutputCustom        [HEADOutputCustom_t  as in Rte_Type.h]
                    pProvidePorts->pErrorOut                [FCTVehErrorOut_t as in Rte_Type.h]
                    pProvidePorts->pEbaBusDebugData         [BusDebugData_t as in Rte_Type.h]
                    pProvidePorts->pLkaBusDebugData         [BusDebugData_t as in Rte_Type.h]
                    pProvidePorts->pFCTVehOutArbitrated     [FCTVehOutArbitrated_t as in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH               : FCT error output from FCT_VEH
  @c_switch_part   FCT_CFG_USE_BUS_DEBUG                  : Configuration switch for enabling BusDebugMessages
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT               : FCT veh custom output interface

  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03/12/2016
  @changed         -

  @todo            20150611CO: Rework for generic interface checking (nullpointer, signal status, update)

  @author          Mohamed Abdelkarim
*************************************************************************************************************************/
static boolean FCTVehCheckProvidePorts( const proFCTVehPrtList_t * pProvidePorts ) 
{
  boolean bRetPortState = TRUE;

  /* Verify that provide port buffer pointers are set (non-null) */
  if (
    (pProvidePorts == NULL)
#if (FCT_CFG_LOPC_COMPONENT)
    || (pProvidePorts->pFctVehLongOut == NULL)
    || (pProvidePorts->pLongCtrlOutput == NULL)
#if (FCT_CFG_TCI)
    || (pProvidePorts->pTCIOutput == NULL)
#endif
#endif
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    || (pProvidePorts->pDIMOutputCustom == NULL)
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    || (pProvidePorts->pHEADOutputGeneric == NULL)
    || (pProvidePorts->pHEADOutputCustom == NULL)
#endif
#if (FCT_CFG_DW_PROCESSING)                           /************************DW ADDED**************************/
    || (pProvidePorts->pDWOutputCustom == NULL)
#endif                                                /**********************************************************/
#if (FCT_CFG_ERROR_OUTPUT_VEH)
    || (pProvidePorts->pErrorOut == NULL)
#endif
#if (FCT_CFG_USE_BUS_DEBUG)
    || (pProvidePorts->pEbaBusDebugData == NULL)
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    || (pProvidePorts->pFCTVehOutArbitrated == NULL)
#endif
#if (FCT_CFG_ACT_CODE_VERSION)
    || (pProvidePorts->pt_FCT_OUT_TCCP == NULL)
#if (FCT_CFG_HP_TFC_PORT_CNT)
    || (pProvidePorts->pt_FCT_OUT_TFSP == NULL)
#endif
#endif
    )
  {
    bRetPortState=FALSE;
  }

  return bRetPortState;
}

#if (FCT_CFG_USE_ALGO_SIGSTATE_INPUT_CHECK)
/*************************************************************************************************************************
  Functionname:    FCTVehCheckSigStateRequirePorts                                                                                 */ /*!

  @brief           Do Checking of signal status of Input interfaces.

  @description     Do Checking of signal status of Input interfaces.

                         @startuml 
                      Start
                          Partition  FCTVehCheckSigStateRequirePorts
                              -  Do Checking of signal status of Input interfaces.
                      End
                   @enduml

  @return          boolean bRetSigStateReqPort : indicates if the signal status of Input interfaces is valid 

  @param[in]       pRequirePorts : the input interfaces to the FCTVeh main function         
                    pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus          [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus            [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccLever->sSigHeader.eSigStatus             [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pLongCtrlResp->sSigHeader.eSigStatus         [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccDisplayObj->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAccOutput->sSigHeader.eSigStatus            [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFCTAccOOIData->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pDIMInputCustom->sSigHeader.eSigStatus       [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pDIMInputGeneric->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHMIData->s_Header.eSigStatus                [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHMIData->sSigHeader.eSigStatus              [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFCTCDHypotheses->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHEADInputGeneric->sSigHeader.eSigStatus     [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pHEADInputCustom->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus    [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.eSigStatus  [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pVehSig->sSigHeader.eSigStatus               [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pEM_CLD_Output->sSigHeader.eSigStatus        [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus      [AlgoSignalState_t Algo signal state enumeration 0...2]
                    pRequirePorts->pSLAData->sSigHeader.eSigStatus              [AlgoSignalState_t Algo signal state enumeration 0...2]
  
  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_CFG_LOPC_COMPONENT                : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_CFG_VEH_HMI_INTERFACE              : Configuration switch enabling HMI Interface Data to FCT_VEH (Needed in DIM distraction module)
  @c_switch_part   FCT_CFG_INCLUDE_UNUSED_INTF            : Special configuration switch to include all interfaces in request/provide
                                                            port structures, even if the current configuration does not use them. This 
                                                            enables the adapter to be unchanged, regardless of the application configuration
  @c_switch_part   FCT_CFG_COLLISION_DETECTION            : FCT collision detection (CD) switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION   : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT : FCT alignment information input to FCT_VEH
  @c_switch_part   FCT_CFG_BSW_ALGO_PARAMS                : Configuration switch enabling the passing of algo parameters to the FCT component. This should be enabled, if the                                                             SW environment provides this information
  @c_switch_part   FCT_CFG_CPAR_PARAMS                    : Configuration switch enabling usage of the FCT Coding Parameters Port
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT              : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_EM_CLD_INPUT               : FCT configuration switch to enable EM_CLD_Output as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMINPUT                : FCT veh custom input interface
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING    : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_SLA_FEATURE                    : Activation switch for SLA support
 
  @c_switch_full   -

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         03/12/2016
  @changed         22/09/2017

  @author          Mohamed Abdelkarim
*************************************************************************************************************************/
static boolean FCTVehCheckSigStateRequirePorts( const reqFCTVehPrtList_t * pRequirePorts ) 
{
  boolean bRetSigStateReqPort = TRUE;

  /* check for SignalState in requestPorts*/
  if(
    (pRequirePorts->pVehCtrlData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pEgoDynRaw->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pEgoStaticData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_LOPC_COMPONENT)
#if (CFG_ACC_LEVER_INPUT)
    || (pRequirePorts->pAccLever->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
    || (pRequirePorts->pLongCtrlResp->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pAccDisplayObj->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pAccOutput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#if (FCT_CFG_TCI)
    || (pRequirePorts->pTCIInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_SLA_FEATURE)
    || (pRequirePorts->pSLAData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
#if FCT_CFG_SENSOR_TYPE_RADAR    /* Check for ACCOOIData is disabled for camera only projects. Better solution need to be provided here */
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
    || (pRequirePorts->pFCTAccOOIData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
#if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    || (pRequirePorts->pDIMInputCustom->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pDIMInputGeneric->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if ((FCT_CFG_VEH_HMI_INTERFACE) || (FCT_CFG_INCLUDE_UNUSED_INTF))
#if (HMI_INPUT_DATA < FCT_HMI_INTFVER_MIN_G30_I390)
    || (pRequirePorts->pHMIData->s_Header.eSigStatus == AL_SIG_STATE_INVALID)
#else
    || (pRequirePorts->pHMIData->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#endif
#if (FCT_CFG_COLLISION_DETECTION)
    || (pRequirePorts->pFCTCDHypotheses->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    || (pRequirePorts->pHEADInputGeneric->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pHEADInputCustom->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_DW_PROCESSING)                                                                          /****************DW ADDED********************/
    || (pRequirePorts->pFCTCustomACCOutput_DWIn->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
    || (pRequirePorts->pDWInputCustom->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif                                                                                               /*************************************/                                
#if (FCT_VEH_CFG_ALIGNMENT_MONITORING_INPUT)
    || (pRequirePorts->pAlignmentMonInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
    /*no signal header*/
#endif
#if (FCT_CFG_CPAR_PARAMS)
    || (pRequirePorts->pCPAR_FCT_Parameters->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_VEH_CFG_VEH_SIG_INPUT)
    || (pRequirePorts->pVehSig->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_VEH_CFG_EM_CLD_INPUT)
    || (pRequirePorts->pEM_CLD_Output->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
    || (pRequirePorts->pFctVehCustInput->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#endif
    )
  {
    bRetSigStateReqPort=FALSE;
  }

  return bRetSigStateReqPort;
}
#endif

#if (FCT_CFG_USE_DEM)
/* ***********************************************************************
  @fn             FCTVehSetDem                                  */ /*!
  @brief          set DEM message
  @description    set DEM Message, furthermore the function acts as access function using FCT_CFG_USE_DEM switch

                    @startuml 
                      Start
                      Partition  FCTVehSetDem
                              -  set DEM message.
                          If(pFCTVehServiceFuncts is not equal to NULL AND pFCTVehServiceFuncts->pfDem_SetEventStatus not equal to NULL) then (true)
                            - pfDem_SetEventStatus function is called
                          Endif
                      End
                   @enduml
  @param[in]      Dem_EventId the DEM EVENT ID
  @param[in]      Dem_EventStatus the DEM EVENT STATUS
  @return         void
  @pre            pFCTVehServiceFuncts connected to input service ports

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @todo           review
  @author         Christian Obst
**************************************************************************** */
void FCTVehSetDem(const AS_t_Dem_EventIDType Dem_EventId, const AS_t_Dem_EventStatusType Dem_EventStatus)
{
  if ((pFCTVehServiceFuncts != NULL) && (pFCTVehServiceFuncts->pfDem_SetEventStatus != NULL))
  {
    pFCTVehServiceFuncts->pfDem_SetEventStatus(Dem_EventId, Dem_EventStatus);
  }
}
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
/* ***********************************************************************
  @fn             VehAlgoServiceAddEvent                                  */ /*!

  @brief          set RTA event via service function

  @description    set RTA event via service function

  @param[in]      RtaEvtType
  @param[in]      u_IdGlobal
  @param[in]      u_IdLocal
  @param[in]      u_OptData

  @param[in,out]  pServiceFuncts: service function pointer

  @pre            none

  @author         Christian Obst
**************************************************************************** */
#if (defined(RTA_INTERFACE_VERSION) && (RTA_INTERFACE_VERSION >= 4))
void VehAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, RTA_t_Events      RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#else
void VehAlgoServiceAddEvent(const AS_t_ServiceFuncts *pServiceFuncts, AS_t_RtaEventType RtaEvtType, uint8 u_IdGlobal, uint8 u_IdLocal, uint8 u_OptData)
#endif
{
  if (pServiceFuncts->pfRTAAlgoServiceAddEvent != NULL)
  {
    (pServiceFuncts->pfRTAAlgoServiceAddEvent) (RtaEvtType, u_IdGlobal, u_IdLocal, u_OptData);
  }
}
#endif

/*************************************************************************************************************************
  Functionname:    FCTVeh_Exec                                                                                      */ /*!

  @brief           FCT component exec function for vehicle data

  @description     Main function for vehicle data cycle. 
                   It updates Frame Data and set OpMode.
                   Sets the process states for all subcomponents.
                   Sets up the input port header sync structure.
                   Sets up port pointers.
                   Sets up the signal headers of all provide ports
                   Starts DIM
                   Processes meas freezes

                    @startuml 
                      Start
                       Partition  FCTVeh_Exec
                              -    FCT component exec function for vehicle data.
                      End
                   @enduml

                   <a style="font-weight:bold" href="http://ims-adas:7001/si/viewrevision?projectName=%23/ADAS/SW%23Components/FCT_Function%23forceJump%3D%23n%3D%2305_Testing/05_Test_Environment/Dynamic_Tests/FCT/Courage/test_scripts/frame_veh&selection=test_fct_veh_main.c&revision=1.5">Test_Script_path</a>

                   @startuml
                    Start
                      -FCTVeh_Exec
                       Note right
                        fct_veh_main.c
                       End note
                         fork
                          : COU_TEST_FCTVeh_Exec_01;
                         fork again
                          : COU_TEST_FCTVeh_Exec_02;
                       Note right
                        test_fct_veh_main.c
                       End note
                       end fork
                    End
                    @enduml


  @return          void

  @param[in]       pRequirePorts : The input data used by FCT component
                    pRequirePorts->pVehCtrlData [FCTCtrlData_t as in Rte_Type.h]
  @param[in]       pProvidePorts : The output data provided by FCT component
                                   Note: this is also used to store state information of FCT,
                                   thus the same buffer shall be used or care should be taken
                                   to copy data from previous cycle!                           
                    pProvidePorts->pLongCtrlOutput->uiVersionNumber [all valid entries are defined bz typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
  
  @param[in]       *pServiceFuncts : the service functions passed to FCTVeh [AS_t_ServiceFuncts as defined in algo_service_types.h]
  
  @glob_in         FCTVehFrame.eFCTState [FCTVehState_t as in fct_veh.h]
  @glob_out        pFCTVehServiceFuncts [AS_t_ServiceFuncts as in algo_service_types.h]
  @glob_out        FCTVehFrame.bFirstCycleDone [true, false]
  @glob_out        FCTVehIsInitialized [true, false]

  @c_switch_part   FCT_CFG_USE_SERVICE_POINTER_FUNCTS      : FCT switch to use third parameter in Exec methods to call the Function. 
                                                             Third parameter is a struct to service functions provided b y the Frame.
  @c_switch_part   FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING : activates the checking of input measurement counters
  @c_switch_part   FCT_CFG_RTA_PROFILING                   : Configuration switch for enabling profiling on ECU
  @c_switch_part   FCT_CFG_USE_FREEZE_CYCLE_START          : FCT switch to enable setting of Measfreeze Cylce Start Servie
  @c_switch_part   CFG_ACC_LEVER_INPUT                     : Configuration switch to use internal/external ACC state machine
  @c_switch_part   FCT_CFG_SEN2VEH_ACC_OOI_PORT            : Switch for OOI port to vehicle task
  @c_switch_part   FCT_MEASUREMENT                         : Activate Measurement Output Code
  @c_switch_part   FCT_CFG_DRIVER_INTENTION_MONITORING     : FCT driver intention monitoring switch
  @c_switch_part   FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION    : FCT hypothesis evaluation and decision switch
  @c_switch_part   FCT_CFG_LOPC_COMPONENT                 : Configuration switch for enabling LOPC processing
  @c_switch_part   FCT_VEH_CFG_VEH_SIG_INPUT               : FCT configuration switch to enable VehSig as input to FCT_VEH
  @c_switch_part   FCT_VEH_CFG_CUSTOMOUTPUT                : FCT veh custom output interface
  @c_switch_part   FCT_CFG_ERROR_OUTPUT_VEH                : FCT error output from FCT_VEH
  @c_switch_full   -

  @pre             FCT component initialized
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).
  @traceability    -

  @created         -
  @changed         12/8/2015

  @todo            Review this function!

  @author          Gergely Ungvary
*************************************************************************************************************************/
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
void FCTVeh_Exec(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts, const AS_t_ServiceFuncts *pServiceFuncts)
#else /*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/
void FCTVeh_Exec(const reqFCTVehPrtList_t * pRequirePorts, const proFCTVehPrtList_t * pProvidePorts)
#endif/*(FCT_CFG_USE_SERVICE_POINTER_FUNCTS)*/
{
#if (defined(_MSC_VER))
#pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning TODO: Fix the cycle time for FCT_VEH!") /*PRQA S 3116 1 */
/* date: 2015-05-18, reviewer: Rachit Sharma (uidr5426), reason: Non-QAC related but required */
#endif

#if (FCT_CFG_USE_ALGOCOMPSTATE)
  /*global Error buffer*/
  GenAlgoQualifiers_t AlgoErrorBuffer = ALGO_QUAL_OK;
#endif
 
#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
  const float32 fCycleTimeSen = FCT_SEN_TARGET_CYCLE_TIME;
#endif


  /*! MEDIC local provide ports */
#if (FCT_CFG_MEDIC_COMPONENT)
  proMEDICPtrList_t t_MedicProvidePorts;
#endif

  /*! MEDIC local require ports */
#if (FCT_CFG_MEDIC_COMPONENT)
  reqMEDICPtrList_t t_MedicRequirePorts;
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  if (pServiceFuncts != NULL)
  {
#ifdef RTA_GLOBALID_FCT_VEH
/* Sends RTA-Start event for whole procedure runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PROCESS, 0);
/* Sends RTA-Start event for data preparation runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PREPRE_PROCESS, 0);
#else
/* Sends RTA-Start event for whole procedure runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_PROCESS, 0);
/* Sends RTA-Start event for data preparation runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_PREPRE_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
  }
#endif

  /* update Frame Data and set OpMode */
  FCTSetVehFrameData(pRequirePorts);

  /* set the process states for all subcomponents */
  FCTVehProcessStates(FCTVehFrame.eFCTOpMode);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Save ServiceFunction Pointer */
  pFCTVehServiceFuncts = pServiceFuncts;
#endif

  /* check for NULLpointer => trigger ErrorShutdown */
  FCTVehCheckPorts(pRequirePorts, pProvidePorts /* Includes Error Management and OP-Mode-Changing */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                  , pServiceFuncts
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
                  , &AlgoErrorBuffer
#endif
                  );
  /* setup the input port header sync structure */
  FCTVehSetupSyncRef(pRequirePorts);

  if ((FCTVehFrame.eFCTOpMode != FCT_MOD_SHUTDOWN) && (FCTVehFrame.eFCTState != FCT_VEH_SHUTDOWN))
  {
    /*Init in init Mode*/
    if (FCTVehFrame.eFCTState == FCT_VEH_INIT)
    {
      FCTVehAlgoInit ();
    }
    else
    {
      FCTVehFrame.bFirstCycleDone = TRUE;
    }

#if (FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
      if ( FCTVehCheckInputUpdate(pRequirePorts, &FCTVehInputCounters,FCT_VEH_CYCLE_TIME, fCycleTimeSen) != 0u )   /*error condition*/
      {
        FCTVehSetAlgoErrorBuffer(&AlgoErrorBuffer, ALGO_QUAL_NOT_CRITICAL_INPUT_ERROR);
      }
#endif /*FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING*/

    /* Opmode indicates liveliness => setup port pointers */
    FCTVehSetupPorts(pRequirePorts, pProvidePorts);

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* send MTS Freeze Cycle Start */
    if ((pServiceFuncts != NULL) && ((pServiceFuncts->pfMeasStartFuncCycle) != NULL))
    {
      (pServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif

    /* set all the signal headers of all provide ports to invalid*/
    FCTVehSetProvideHeaderStates(pProvidePorts, AL_SIG_STATE_INVALID);
    FCTVehSetProvideHeader      (pRequirePorts,pProvidePorts);
    
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-End event for data preparation runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PREPRE_PROCESS, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_PREPRE_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
#endif

#if(FCT_CFG_MEDIC_COMPONENT)
    /*! Set MEDIC require ports */
    FCTVeh_v_SetMEDICReqPort(pRequirePorts, &t_MedicRequirePorts);
    /*! Set MEDIC provide ports */
    FCTVeh_v_SetMEDICProPort(pProvidePorts, &t_MedicProvidePorts);
  
    FCTVeh_v_MEDIC_Process(&t_MedicRequirePorts
                          ,&t_MedicProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                       , pServiceFuncts
#endif
                       );
#endif

#if (FCT_CFG_ACT_CODE_VERSION)

    /*! Run Adaptive Cruise Control (ACC) in Vehicle Task */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))

    /*! Fill Port Lists of ISC Component */
    FCT_v_Set_ISC_Ports(&t_ISC_RequirePorts, &t_ISC_ProvidePorts);

    /*! Assign FCT Ports to generic ISC Input Port Elements dynamically */
    FCT_v_Assign_ISC_Input_Ports (FCTVEH_pAccLever, FCTVEH_pLongCtrlResp, FCTVEH_pVehSigPowerTrain);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    ISC_v_Exec(&t_ISC_RequirePorts, &t_ISC_ProvidePorts, FCTVehFrame.eFCTOpMode, pServiceFuncts);
#else
    ISC_v_Exec(&t_ISC_RequirePorts, &t_ISC_ProvidePorts, FCTVehFrame.eFCTOpMode);
#endif

    /*! Assign generic ISC Output Port Elements to FCT Ports dynamically */
    FCT_v_Assign_ISC_Output_Ports (&FCTVEH_pLongCtrlOutput->DriverData, &FCTVEH_pLongCtrlOutput->KinFctInfo);
#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT) */


#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT))
    /*! Fill Port Lists of LOCC Component */
    FCT_v_Set_LOCC_Ports(&t_LOCC_RequirePorts, &t_LOCC_ProvidePorts);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    LOCC_v_Exec(&t_LOCC_RequirePorts, &t_LOCC_ProvidePorts, FCTVehFrame.eFCTOpMode, pServiceFuncts);
#else
    LOCC_v_Exec(&t_LOCC_RequirePorts, &t_LOCC_ProvidePorts, FCTVehFrame.eFCTOpMode);
#endif
#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOCC_COMPONENT) */


#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))
    /*! Fill Port Lists of LOPC Component */
    FCT_v_Set_LOPC_Ports(&t_LOPC_RequirePorts, &t_LOPC_ProvidePorts);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    LOPC_v_Exec(&t_LOPC_RequirePorts, &t_LOPC_ProvidePorts, FCTVehFrame.eFCTOpMode, pServiceFuncts);
#else
    LOPC_v_Exec(&t_LOPC_RequirePorts, &t_LOPC_ProvidePorts, FCTVehFrame.eFCTOpMode);
#endif
    /*! Assign generic LOPC Output Port Elements to FCT Port dynamically */
    FCT_v_Assign_LOPC_Output_Ports (&FCTVEH_pLongCtrlOutput->KinOutput);
#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

#else  /* (FCT_CFG_ACT_CODE_VERSION) */

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT))
    /*! Fill Port Lists of LOPC Component */
    // FCT_v_SetLOPCGen3Ports(pRequirePorts, pProvidePorts, &t_LOPC_RequirePorts, &t_LOPC_ProvidePorts);

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    LOPC_v_Exec(&t_LOPC_RequirePorts, &t_LOPC_ProvidePorts, FCTVehFrame.eFCTOpMode, pServiceFuncts);
#else
    // LOPC_v_Exec(&t_LOPC_RequirePorts, &t_LOPC_ProvidePorts, FCTVehFrame.eFCTOpMode);
#endif
#endif /* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_LOPC_COMPONENT) */

#endif /* (FCT_CFG_ACT_CODE_VERSION) */

/****************************************DW ADDED*******************************/

#if (FCT_CFG_DW_PROCESSING)// DW general switch
  #if (FCT_CFG_DW_PROCESSING_QM)// DW in another task (if ON)
    // do here either nothing or the new trick to start/activate QM task
  #else// OLD way if QM is OFF
    #if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-Start event for Hypothesis Evaluation and Decision runtime */
  #ifdef RTA_GLOBALID_FCT_VEH
    VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_DW_PROCESS, 0);
  #else
    VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_DW_PROCESS, 0);
  #endif/* (RTA_GLOBALID_FCT_VEH) */
    #endif

    DWProcess(FCT_VEH_CYCLE_TIME, pRequirePorts->pVehSig, pRequirePorts->pDWInputCustom, pProvidePorts->pDWOutputCustom, pRequirePorts->pFCTCustomACCOutput_DWIn, pRequirePorts->pDWCPAR);

    #if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
      /* Sends RTA-End event for Hypothesis Evaluation and Decision runtime */
  #ifdef RTA_GLOBALID_FCT_VEH
    VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_DW_PROCESS, 0);
  #else
    VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_DW_PROCESS, 0);
  #endif/* (RTA_GLOBALID_FCT_VEH) */
    #endif
  #endif// DW exec in FCT_VEH
#endif// DW general switch

/********************************************************************************/

#if (FCT_VEH_CFG_CUSTOMOUTPUT)
    FCTVEHProcessCustomOutput ();
#endif

#if (FCT_CFG_ERROR_OUTPUT_VEH)
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-Start event for Error Out runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_EO_PROCESS, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_EO_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
#endif
    FCTVehFillErrorOut(pProvidePorts->pErrorOut);
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-End event for Error Out runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_EO_PROCESS, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_EO_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
#endif
#endif /* FCT_CFG_ERROR_OUTPUT_VEH */


#if defined(FCT_SIMU) && FCT_CFG_ACTIVATE_SIGHEADER_CHECK
    FCTVehCheckProvideHeaders(pRequirePorts, pProvidePorts); 
#endif
    /* Set all signal header values again to avoid errors if a component accidentally overwrite the SigHeader*/
    FCTVehSetProvideHeader(pRequirePorts, pProvidePorts);

#if (FCT_MEASUREMENT)
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-Start event for Process Meas freeze runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PROCESSFREEZE, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_PROCESSFREEZE, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
#endif
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    FCTVehSetCompState (FCTVEH_pVehCompState, FCTVehFrame.eFCTOpMode, AlgoErrorBuffer);
#endif
    /* Process meas freezes */
    {
      FCTVehProcessMeasFreeze(pRequirePorts, pProvidePorts);
    }

    /*computation chain ran through. FCT Vehicle is initialized or running.*/
    FCTVehIsInitialized = TRUE;

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    /* Sends RTA-End event for Process Meas freeze runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PROCESSFREEZE, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_PROCESSFREEZE, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
#endif
#endif /* FCT_MEASUREMENT */
  }

  else  /************************* end of non-error path, beginning of error path *************************/
  {
    /* FCT_MOD_SHUTDOWN => fill invalidate the available provide ports and fill whole sigHeader */
    FCTVehSetErrorProvidePorts(pProvidePorts);
#if (FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    FCTVeh_v_SetMEDICErrorProPorts(pProvidePorts, &t_MedicProvidePorts);
#endif

#if ((FCT_CFG_USE_FREEZE_CYCLE_START) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    if ((pServiceFuncts != NULL) && (pServiceFuncts->pfMeasStartFuncCycle != NULL))
    {
      /* send MTS Freeze Cycle Start if Service is available */
      (pServiceFuncts->pfMeasStartFuncCycle) ((AS_t_MeasFuncID) (FCT_MEAS_FUNC_CHAN_ID));
    }
#endif

    /* Init Algo */
    FCTVehAlgoInit();
#if (FCT_CFG_USE_ALGOCOMPSTATE)
    /*ERROR path! Need to check existence of pointers*/
    if (FCTVEH_pVehCompState != NULL)
    {
      if ( (pRequirePorts != NULL) && (pRequirePorts->pVehCtrlData != NULL) )
      {
        FCTVehSetCompState (FCTVEH_pVehCompState, FCTVehFrame.eFCTOpMode, AlgoErrorBuffer);
      }
      else
      {
        FCTVehSetCompState (FCTVEH_pVehCompState, FCT_MOD_RUNNING, AlgoErrorBuffer);
      }
    }
#endif

    /*make sure in error case init of sub components is performed next cycle*/
    FCTVehIsInitialized = FALSE;


    /* Process meas freezes */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
    /* Safeguard for NULL-Pointer */
    if ( (pFCTVehServiceFuncts != NULL)
      && (pFCTVehServiceFuncts->pfMeasFreeze != NULL) )
#endif
    {
      FCTVehProcessMeasFreeze(pRequirePorts, pProvidePorts);
    }


#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
    if (pServiceFuncts != NULL)
    {
      /* Sends RTA-End event for data preparation runtime in error case*/
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PREPRE_PROCESS, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_PREPRE_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
    }
#endif
  } /*********************** end of error path, beginning common *******************************/

  /* FCT Veh is processed successfully. Set the signal status of VehCompState to valid */
  /* The VehCompState is independent of input from other components */
#if (FCT_CFG_USE_ALGOCOMPSTATE)
  pProvidePorts->pVehCompState->sSigHeader.eSigStatus = AL_SIG_STATE_OK;
#endif

#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  if (pServiceFuncts != NULL)
  {
    /* Sends RTA-Start event for Frame Meas freeze runtime */
#ifdef RTA_GLOBALID_FCT_VEH
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_FRAMEFREEZE, 0);
#else
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoStart, COMP_ID_FCT, FCTVEH_RTA_FRAMEFREEZE, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
  }
#endif
  /* Freeze frame meas data */
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  /* Safeguard for NULL-Pointer */
  if ( (pFCTVehServiceFuncts != NULL)
    && (pFCTVehServiceFuncts->pfMeasFreeze != NULL) )
  {
    FCTVehFrameFreeze();
  }
#else
  FCTVehFrameFreeze();
#endif
#if ((FCT_CFG_RTA_PROFILING) && (FCT_CFG_USE_SERVICE_POINTER_FUNCTS))
  if (pServiceFuncts != NULL)
  {
#ifdef RTA_GLOBALID_FCT_VEH
/* Sends RTA-End event for Frame Meas freeze runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_FRAMEFREEZE, 0);
/* Sends RTA-End event for whole procedure runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, RTA_GLOBALID_FCT_VEH, FCTVEH_RTA_PROCESS, 0);
#else
/* Sends RTA-End event for Frame Meas freeze runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_FRAMEFREEZE, 0);
/* Sends RTA-End event for whole procedure runtime */
  VehAlgoServiceAddEvent(pServiceFuncts, e_RTA_EVT_AlgoEnd, COMP_ID_FCT, FCTVEH_RTA_PROCESS, 0);
#endif/* (RTA_GLOBALID_FCT_VEH) */
  }
#endif
}
#if (FCT_CFG_MEDIC_COMPONENT)
/*************************************************************************************************************************
  Functionname:         FCTVeh_v_MEDIC_Process                                                                     */ /*!

  @brief                Process function to call MEDIC_v_Exec

  @description          Provide the necessary memory, call MEDIC_v_Exec and freeze the MEDIC data 

                        @startuml 
                          Start
                          Partition  FCTVeh_v_MEDIC_Process
                          -    Process function to call MEDIC_v_Exec.
                           End
                        @enduml

  @return               void
  
  @param[in]            p_MEDICRequirePorts :       Require ports, provided by the RTE.
  @param[in,out]        p_MEDICProvidePorts :       Provide ports, provided towards the RTE.
  @param[in]            p_ServiceFuncts :           Service function pointers provided by the RTE.


  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref FCT_SIMU\n
                        @ref FCT_CFG_USE_SERVICE_POINTER_FUNCTS\n
  @c_switch_full        None

  @pre                  None 
  @post                 None 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     Not defined 


  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
static void FCTVeh_v_MEDIC_Process( reqMEDICPtrList_t   const * const p_MEDICRequirePorts, 
                                   proMEDICPtrList_t        * const p_MEDICProvidePorts
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
                                   , AS_t_ServiceFuncts const * const p_ServiceFuncts
#endif
                                                                                       )
{
  #if !FCT_CFG_USE_MEDIC_INTERNAL_MEMORY
  /* MEDIC process memory */
  MEDIC_ProcMem_t MEDICProcMem    = {0};
  /* Assign memory pointer */
  MEDICProcMem.pMemInterCycle     = &MEDICInter;
  MEDICProcMem.pMemInterCycleMeas = &MEDICInterMeas;
  MEDICProcMem.pMemIntraCycleMeas = &MEDICIntraMeas;

  /* Reset the structure to guarantee the non-persistent behavior of the memory */
  (void) memset (&MEDICIntraMeas, 0, sizeof(GA_MEDIC_Mem_DataIntraCycleMeas));// PRQA S 0315
/* date: 2019-06-28, reviewer:, reason:Case to void intended as use of generic interface */
  #endif
  /*! Run Emergency Brake Assist (EBA) MEDIC execution function */

  MEDIC_v_Exec(p_MEDICRequirePorts, 
               p_MEDICProvidePorts  
  #if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
               ,p_ServiceFuncts
  #endif
  #if (!FCT_CFG_USE_MEDIC_INTERNAL_MEMORY)
               ,&MEDICProcMem
  #endif
  );
  #if !FCT_CFG_USE_MEDIC_INTERNAL_MEMORY
  FCTVeh_FreezeMEDICProcMem(&MEDICProcMem);
  #endif
}
#endif /* FCT_CFG_MEDIC_COMPONENT */

#if (FCT_CFG_MEDIC_COMPONENT)
#if! FCT_CFG_USE_MEDIC_INTERNAL_MEMORY
/*************************************************************************************************************************
  Functionname:         FCTVeh_FreezeMEDICProcMem                                                                     */ /*!

  @brief                Freeze all data from MEDIC 

  @description          Freeze all data from MEDIC 

                         @startuml 
                          Start
                            Partition  FreezeMEDICProcMem
                            -  Freeze all data from MEDIC.
                          End
                         @enduml

  @return               void
  
  @param[in]            pMEDICProcMem : Pointer to the memory used in MEDIC

  @glob_in              None 
  @glob_out             None 

  @c_switch_part        @ref FCT_SIMU\n
  @c_switch_full        None

  @pre                  None 
  @post                 None 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation     Not defined 


  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
static void FCTVeh_FreezeMEDICProcMem(MEDIC_ProcMem_t const * const pMEDICProcMem)
{
  MEASInfo_t MeasInfo = {0, 0, FCT_MEAS_FUNC_ID, FCT_MEAS_FUNC_CHAN_ID };

  MeasInfo.VirtualAddress = GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA;
  MeasInfo.Length         = GA_MEDIC_SIZE_MEM_DATA_INTRA_CYCLE_MEAS;
  FCT_FREEZE_DATA(&MeasInfo, pMEDICProcMem->pMemIntraCycleMeas,   &FCTVehMeasCallback);//PRQA S 3200, 0315
  /* date: 2018-09-11, Reviewer:Nagaraja Veerashettappa, Reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */

  MeasInfo.VirtualAddress = GA_MEDIC_MEAS_ID_INTER_CYCLE_MEAS_DATA;
  MeasInfo.Length         = GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE_MEAS;
  FCT_FREEZE_DATA(&MeasInfo, pMEDICProcMem->pMemInterCycleMeas,  &FCTVehMeasCallback);//PRQA S 3200, 0315
  /* date: 2018-09-11, Reviewer:Nagaraja Veerashettappa, Reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */

#ifdef FCT_SIMU
  MeasInfo.VirtualAddress = GA_MEDIC_MEAS_ID_INTER_CYCLE_DATA;
  MeasInfo.Length         = GA_MEDIC_SIZE_MEM_DATA_INTER_CYCLE;
  FCT_FREEZE_DATA(&MeasInfo, pMEDICProcMem->pMemInterCycle,   &FCTVehMeasCallback);//PRQA S 3200
  /* date: 2018-09-11, Reviewer:Nagaraja Veerashettappa, Reason: The return value of MEASFreezeDataMTS is not used currently, Not Critical */
  #endif
}
#endif
#endif /* FCT_CFG_MEDIC_COMPONENT */
/*************************************************************************************************************************
  Functionname:    FCTVehSetSigHeaderError                                                                          */ /*!

  @brief           Set signal header with error values

  @description     Init SignalHeader_t struct with default values for FCT_VEH.
                   These default values are the cycle counter of FCT_VEH, signal
                   state invalid

                    @startuml 
                       Start
                       Partition  FCTVehSetSigHeaderError
                       -     Set signal header with error values.
                       End
                    @enduml


  @return          static void

  @param[in,out]   pSigHeader : the signal header to be filled
                    pSigHeader->uiTimeStamp [AlgoDataTimeStamp_t as in Rte_Type.h]
                    pSigHeader->uiMeasurementCounter [AlgoCycleCounter_t as in Rte_Type.h]
                    pSigHeader->uiCycleCounter [AlgoCycleCounter_t as in Rte_Type.h]
                    pSigHeader->eSigStatus [AlgoSignalState_t as in Rte_Type.h]

  @glob_in         -
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
  @changed         12/8/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehSetSigHeaderError(SignalHeader_t * const pSigHeader)
{
  pSigHeader->uiCycleCounter        = FCTVehFrame.uiCycleCounter;
  pSigHeader->eSigStatus            = AL_SIG_STATE_INVALID;
}

/*************************************************************************************************************************
  Functionname:    FCTVehFillSigHeader                                                                              */ /*!

  @brief           Fill FCT Veh signal header with default values

  @description     Fill SignalHeader_t struct with default values for FCT_VEH.
                   These default values are the cycle counter of FCT_VEH, and
                   the signal state based on the passed parameter

  @return          static void

  @param[out]      pSigHeader : the signal header to be filled
                    pSigHeader->uiTimeStamp [AlgoDataTimeStamp_t as in Rte_Type.h]
                    pSigHeader->uiMeasurementCounter [AlgoCycleCounter_t as in Rte_Type.h]
                    pSigHeader->uiCycleCounter [AlgoCycleCounter_t as in Rte_Type.h]
                    pSigHeader->eSigStatus [AlgoSignalState_t as in Rte_Type.h]
  @param[in]       pSourceHdr : the source signal header (measurement cycle counter and timestamp are copied from this source) 
                                [AlgoCycleCounter_t as in Rte_Type.h]
                    pSourceHdr->uiTimeStamp [AlgoDataTimeStamp_t as in Rte_Type.h]
                    pSourceHdr->uiMeasurementCounter [AlgoCycleCounter_t as in Rte_Type.h]
  @param[in]       eSigState : the state to set for the 'eSigStatus' field [AlgoSignalState_t  as in Rte_Type.h]

  @glob_in         -
  @glob_out        FCTVehFrame.uiCycleCounter : Algo cycle counter [AlgoCycleCounter_t as in Rte_Type.h]

  @c_switch_part   -
  @c_switch_full   -

  @pre             FCT component initialized!
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         12/8/2015

  @author          Gergely Ungvary
*************************************************************************************************************************/
static void FCTVehFillSigHeader(SignalHeader_t * const pSigHeader, const SignalHeader_t * const pSourceHdr)
{
  pSigHeader->uiTimeStamp           = pSourceHdr->uiTimeStamp;
  pSigHeader->uiMeasurementCounter  = pSourceHdr->uiMeasurementCounter;
  pSigHeader->uiCycleCounter        = FCTVehFrame.uiCycleCounter;
}

/*************************************************************************************************************************
  Functionname:    FCTVehSetSigHeaderState                                                                          */ /*!

  @brief           Set signal header state

  @return          static void

  @param[in,out]   pSigHeader : pointer to signal header struct
  @param[in]       eSigState : signal state to be set

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.02.2016
  @changed         23.02.2016

  @author          Andreas Kramer |  | +49 (8382) 9699-246
*************************************************************************************************************************/
static void FCTVehSetSigHeaderState(SignalHeader_t * const pSigHeader, AlgoSignalState_t eSigState)
{
  pSigHeader->eSigStatus            = eSigState;
}

#if (FCT_CFG_ACT_CODE_VERSION)

#if (FCT_CFG_ISC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_Set_ISC_Ports                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[out]      pRequirePorts : 
  @param[out]      pProvidePorts : 

  @glob_in         FCTVeh_pCtrlData :
  @glob_in         FCTVEH_pLongCtrlResp :
  @glob_in         FCTVEH_pEgoDynRaw :
  @glob_in         &t_LOPC_TO_LOCC_VSSP :
  @glob_in         &t_LOCC_TO_LOPC_VSCP :

  @c_switch_part   ACT_CFG_CC_VSC_PORT_CNT
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.Borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void FCT_v_Set_ISC_Ports(ISC_ReqPortList_t *pRequirePorts, ISC_ProPortList_t *pProvidePorts)
{
  pRequirePorts->pt_ISC_IN_Ctrl = FCTVeh_pCtrlData;

  pRequirePorts->pt_ISC_IN_IIP = &t_ISC_IN_IIP;
  pRequirePorts->pt_ISC_IN_ICP = &t_ISC_IN_ICP;

  pRequirePorts->pt_ISC_IN_LVSP = &t_LOPC_TO_ISC_LVSP;
  pProvidePorts->pt_ISC_OUT_LVCP = &t_ISC_TO_LOPC_LVCP;

#if (FCT_CFG_LOCC_COMPONENT)
  pRequirePorts->pt_ISC_IN_CCSP = &t_LOCC_TO_ISC_CCSP;
  pProvidePorts->pt_ISC_OUT_CCCP = &t_ISC_TO_LOCC_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  pRequirePorts->pt_ISC_IN_TCSP = pt_FCT_IN_TCSP;
  pProvidePorts->pt_ISC_OUT_TCCP = pt_FCT_OUT_TCCP;
#endif

  pProvidePorts->pt_ISC_OUT_ISP = &t_ISC_OUT_ISP;
}
#endif


#if (FCT_CFG_LOCC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_Set_LOCC_Ports                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[out]      pRequirePorts : 
  @param[out]      pProvidePorts : 

  @glob_in         FCTVeh_pCtrlData :
  @glob_in         FCTVEH_pLongCtrlResp :
  @glob_in         FCTVEH_pEgoDynRaw :
  @glob_in         &t_LOPC_TO_LOCC_VSSP :
  @glob_in         &t_LOCC_TO_LOPC_VSCP :

  @c_switch_part   ACT_CFG_CC_VSC_PORT_CNT
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.Borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void FCT_v_Set_LOCC_Ports(LOCC_ReqPortList_t *pRequirePorts, LOCC_ProPortList_t *pProvidePorts)
{
  pRequirePorts->pt_LOCC_IN_Ctrl = FCTVeh_pCtrlData;

  pRequirePorts->pt_LOCC_IN_CCCP = &t_ISC_TO_LOCC_CCCP;

  pRequirePorts->pt_LOCC_IN_EgoVehDynCtrl = FCTVEH_pLongCtrlResp;
  pRequirePorts->pt_LOCC_IN_EgoVehDynState = FCTVEH_pEgoDynRaw;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  pRequirePorts->pt_LOCC_IN_VSSP = &t_LOPC_TO_LOCC_VSSP;
  pProvidePorts->pt_LOCC_OUT_VSCP = &t_LOCC_TO_LOPC_VSCP;
#endif

  pProvidePorts->pt_LOCC_OUT_CCSP = &t_LOCC_TO_ISC_CCSP;
}
#endif


#if (FCT_CFG_LOPC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_Set_LOPC_Ports                                                                          */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[out]      pRequirePorts : 
  @param[out]      pProvidePorts : 

  @glob_in         FCTVeh_pCtrlData :
  @glob_in         FCTVEH_pLongCtrlResp :
  @glob_in         FCTVEH_pEgoDynRaw :
  @glob_in         &t_LOCC_TO_LOPC_VSCP :
  @glob_in         &t_LOPC_TO_LOCC_VSSP :
  @glob_in         &t_LOPC_TO_FCT_EVCP :

  @c_switch_part   ACT_CFG_CC_VSC_PORT_CNT
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.Borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void FCT_v_Set_LOPC_Ports(LOPC_ReqPortList_t *pRequirePorts, LOPC_ProPortList_t *pProvidePorts)
{
  pRequirePorts->pt_LOPC_IN_Ctrl = FCTVeh_pCtrlData;

  pRequirePorts->pt_LOPC_IN_EgoVehDynCtrl = FCTVEH_pLongCtrlResp;
  pRequirePorts->pt_LOPC_IN_EgoVehDynState = FCTVEH_pEgoDynRaw;

  pRequirePorts->pt_LOPC_IN_LVCP = &t_ISC_TO_LOPC_LVCP;
  pProvidePorts->pt_LOPC_OUT_LVSP = &t_LOPC_TO_ISC_LVSP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  pRequirePorts->pt_LOPC_IN_CC_VSCP = &t_LOCC_TO_LOPC_VSCP;
  pProvidePorts->pt_LOPC_OUT_CC_VSSP = &t_LOPC_TO_LOCC_VSSP;
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  pRequirePorts->pt_LOPC_IN_HP_TFCP = pt_FCT_IN_TFCP;
  pProvidePorts->pt_LOPC_OUT_HP_TFSP = pt_FCT_OUT_TFSP;
#endif

  pProvidePorts->pt_LOPC_OUT_EVCP = &t_LOPC_TO_FCT_EVCP;
}
#endif


#if (FCT_CFG_ISC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_Assign_ISC_Input_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of existing FCT Ports to generic ISC Input Ports

                   @startuml 
                    Start
                     Partition  FCT_v_Assign_ISC_Input_Ports
                      -   Transformation and Assignment of existing FCT Ports to generic ISC Input Ports.
                     If(pt_PTInput->ActualGear is equal to DYN_GEAR_NEUTRAL_GEAR ) then (true)
                       - t_ISC_IN_IIP.t_ISCI.t_DrivePos is assigned to ACT_ISC_DRIVE_POS_NEUTRAL
                     Elseif(pt_PTInput->ActualGear is equal to DYN_GEAR_REVERSE_GEAR) then (true)				
                       - t_ISC_IN_IIP.t_ISCI.t_DrivePos is assigned to ACT_ISC_DRIVE_POS_BACKWARD
                     Elseif(pt_PTInput->ActualGear is equal to DYN_GEAR_PARK_GEAR) then (true)				
                       - t_ISC_IN_IIP.t_ISCI.t_DrivePos is assigned to ACT_ISC_DRIVE_POS_PARKING		
                     Else
                       - t_ISC_IN_IIP.t_ISCI.t_DrivePos is assigned to ACT_ISC_DRIVE_POS_FORWARD
                     Endif
                       - Assignment of existing FCT Ports to generic ISC Input Ports		
                   End 
                  @enduml


  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FCT_v_Assign_ISC_Input_Ports (const AccLeverInput_t *pt_DrvCtrlInput, const LongCtrlInput_t *pt_VehCtrlInput, const PowerTrain_t *pt_PTInput)
{
  /* Assign ISC Command Input */
  t_ISC_IN_ICP.t_ISCC.b_Main = pt_DrvCtrlInput->MainMode;
  t_ISC_IN_ICP.t_ISCC.b_Set = pt_DrvCtrlInput->Set;
  t_ISC_IN_ICP.t_ISCC.b_Resume = pt_DrvCtrlInput->Resume;
  t_ISC_IN_ICP.t_ISCC.b_Cancel = pt_DrvCtrlInput->Cancel;
  t_ISC_IN_ICP.t_ISCC.b_SpeedDec = pt_DrvCtrlInput->DecelSwitch;
  t_ISC_IN_ICP.t_ISCC.b_SpeedInc = pt_DrvCtrlInput->AccelSwitch;
  t_ISC_IN_ICP.t_ISCC.b_HeadwayInc = pt_DrvCtrlInput->HeadwayInc;

  /* Assign ISC Information Input */
  switch (pt_PTInput->ActualGear)
  {
  case DYN_GEAR_NEUTRAL_GEAR:
    t_ISC_IN_IIP.t_ISCI.t_DrivePos = ACT_ISC_DRIVE_POS_NEUTRAL;
    break;

  case DYN_GEAR_REVERSE_GEAR:
    t_ISC_IN_IIP.t_ISCI.t_DrivePos = ACT_ISC_DRIVE_POS_BACKWARD;
    break;

  case DYN_GEAR_PARK_GEAR:
    t_ISC_IN_IIP.t_ISCI.t_DrivePos = ACT_ISC_DRIVE_POS_PARKING;
    break;

  default:
    t_ISC_IN_IIP.t_ISCI.t_DrivePos = ACT_ISC_DRIVE_POS_FORWARD;
    break;
  }

  t_ISC_IN_IIP.t_ISCI.u_SpeedDisplay = (uint8)(pt_VehCtrlInput->DisplayOutput.speedometer_speed / Velocity_s);

  t_ISC_IN_IIP.t_ISCI.b_AccelPedal = pt_VehCtrlInput->KinCtrlDynInput.driver_accel;
  t_ISC_IN_IIP.t_ISCI.b_BrakePedal = pt_VehCtrlInput->KinCtrlDynInput.driver_braking;
  t_ISC_IN_IIP.t_ISCI.b_ParkBrake =  pt_VehCtrlInput->KinCtrlDynInput.park_brk_eng;
  t_ISC_IN_IIP.t_ISCI.b_DoorOpen =  (pt_VehCtrlInput->KinCtrlDynInput.door_state != 0u);
  t_ISC_IN_IIP.t_ISCI.b_DriverBeltUnlocked = (pt_VehCtrlInput->KinCtrlDynInput.seatbelt_state != SEATBELT_DRIVER_CLOSED);
  t_ISC_IN_IIP.t_ISCI.b_ABS_Active =  (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ABS_ACTIVE);
  t_ISC_IN_IIP.t_ISCI.b_TCS_Active =  (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_TCS_ACTIVE);
  t_ISC_IN_IIP.t_ISCI.b_ESC_Active =  (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ESP_ACTIVE);
  t_ISC_IN_IIP.t_ISCI.b_ABS_Failure = (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ABS_DEFECTIVE);
  t_ISC_IN_IIP.t_ISCI.b_TCS_Failure = (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_TCS_DEFECTIVE);
  t_ISC_IN_IIP.t_ISCI.b_ESC_Failure = (pt_VehCtrlInput->KinCtrlDynInput.ldm_ctrl_state & LDM_CTRL_ESP_DEFECTIVE);
}

/*************************************************************************************************************************
  Functionname:    FCT_v_Assign_ISC_Output_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of generic ISC Output Ports to existing FCT Ports

                      @startuml 
                       Start
                       Partition  FCT_v_Assign_ISC_Output_Ports
                       -     Transformation and Assignment of generic ISC Output Ports to existing FCT Ports.
                       End
                    @enduml


  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FCT_v_Assign_ISC_Output_Ports (KinDriverOutput_t *pt_KinDrvOutput, KinFctInfo_t *pt_KinFctInfo)
{
  pt_KinDrvOutput->drive_off_possible = FALSE;
  pt_KinDrvOutput->drive_off_request = FALSE;
  pt_KinDrvOutput->failure_state = Cc_no_error;
  pt_KinDrvOutput->operational_mode = Display_op_none;
  pt_KinDrvOutput->ldm_drive_mode = 0u;

  pt_KinFctInfo->object_detected = t_ISC_OUT_ISP.t_ISCS.b_TargetControl;
  pt_KinFctInfo->FCA_alert = FALSE;
  pt_KinFctInfo->FCA_status = FCA_STATUS_OFF;
  pt_KinFctInfo->DM_alert_level = 0u;
  pt_KinFctInfo->DM_status = DM_STATUS_OFF;
  pt_KinFctInfo->headway_control_alert = t_ISC_OUT_ISP.t_ISCS.b_TakeOverRequest;
  pt_KinFctInfo->requested_distance = t_ISC_OUT_ISP.t_ISCS.u_RequestDistance;
  pt_KinFctInfo->obj_interest_distance = t_ISC_OUT_ISP.t_ISCS.u_TargetDistance;
  pt_KinFctInfo->headway_setting = t_ISC_OUT_ISP.t_ISCS.u_HeadwaySetting;
  pt_KinFctInfo->desired_speed = t_ISC_OUT_ISP.t_ISCS.u_SetSpeed;
  pt_KinFctInfo->recommended_speed = 0u;
  pt_KinFctInfo->speed_target = t_ISC_OUT_ISP.t_ISCS.u_TargetSpeed;
}
#endif


#if (FCT_CFG_LOPC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_Assign_LOPC_Output_Ports                                                                        */ /*!

  @brief           Transformation and Assignment of generic LOPC Output Ports to existing FCT Ports

                        @startuml 
                       Start
                       Partition  FCT_v_Assign_LOPC_Output_Ports
                       -     Transformation and Assignment of generic LOPC Output Ports to existing FCT Ports.
                       End
                    @enduml

  @return          -

  @param           - 

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @author          Wolfgang Borgs |  | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FCT_v_Assign_LOPC_Output_Ports (KinOutput_t *pt_KinOutput)
{
  if (t_LOPC_TO_FCT_EVCP.t_EVC.b_Enabled == TRUE)
  {
    pt_KinOutput->DAS_status = DAS_STATUS_ENGAGED;
    pt_KinOutput->MinRequestedLongAcceleration = (signed short)(t_LOPC_TO_FCT_EVCP.t_EVC.f_LongAcceleration * (float32)Acceleration_s);
    pt_KinOutput->MaxRequestedLongAcceleration = (signed short)(t_LOPC_TO_FCT_EVCP.t_EVC.f_LongAcceleration * (float32)Acceleration_s); 
    pt_KinOutput->stand_still_request = t_LOPC_TO_FCT_EVCP.t_EVC.b_Standstill;
  }
  else
  {
    pt_KinOutput->DAS_status = DAS_STATUS_DISENGAGE;
    pt_KinOutput->MinRequestedLongAcceleration = 0u;
    pt_KinOutput->MaxRequestedLongAcceleration = 0u; 
    pt_KinOutput->stand_still_request = FALSE;
  }

  pt_KinOutput->brake_pre_fill = FALSE;
  pt_KinOutput->DAS_accel_limitation_active = FALSE;
  pt_KinOutput->DAS_failure_information = DAS_FAILURE_NONE;
}
#endif

#else /* FCT_CFG_ACT_CODE_VERSION */
#if (FCT_CFG_LOPC_COMPONENT)
/*************************************************************************************************************************
  Functionname:    FCT_v_SetLOPCGen3Ports                                                                           */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          void

  @param[out]      pRequirePorts : 
  @param[out]      pProvidePorts : 

  @glob_in         FCTVeh_pCtrlData :
  @glob_in         FCTVEH_pLongCtrlResp :
  @glob_in         FCTVEH_pEgoDynRaw :
  @glob_in         &t_LOCC_TO_LOPC_VSCP :
  @glob_in         &t_LOPC_TO_LOCC_VSSP :
  @glob_in         &t_LOPC_TO_FCT_EVCP :

  @c_switch_part   ACT_CFG_CC_VSC_PORT_CNT
  @c_switch_full   None ? : Compiler switch used around this function/file

  @pre             None ?
  @post            No changes ?

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         04.07.2017
  @changed         04.07.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.Borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
static void FCT_v_SetLOPCGen3Ports(const reqFCTVehPrtList_t* pRequirePorts, const proFCTVehPrtList_t* pProvidePorts,
                                   LOPC_ReqPortList_t *pLopcRequirePorts, LOPC_ProPortList_t *pLopcProvidePorts)
{
  pLopcRequirePorts->pVehCtrlData = pRequirePorts->pVehCtrlData;                /*!< FCT_VEH operation mode control data */
  pLopcRequirePorts->pEgoDynRaw = pRequirePorts->pEgoDynRaw;                    /*!< The dynamic vehicle ego data raw */

  /* Longitudinal control input ports */
  pLopcRequirePorts->pAccLever = pRequirePorts->pAccLever;                      /*!< ACC lever information (input from driver) */
  pLopcRequirePorts->pLongCtrlResp = pRequirePorts->pLongCtrlResp;              /*!< Dynamic controller response */
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  pLopcRequirePorts->pAccDisplayObj =  pRequirePorts->pAccDisplayObj;            /*!< Display object data output by FCT_SEN */
  pLopcRequirePorts->pAccOutput = pRequirePorts->pAccOutput;                    /*!< ACC output data by FCT_SEN */
#endif
#if (FCT_CFG_SLA_FEATURE)
  pLopcRequirePorts->pSLAData = pRequirePorts->pSLAData;
#endif
#if (FCT_CFG_TCI)
  pLopcRequirePorts->pTCIInput = pRequirePorts->pTCIInput;
#endif
#if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  pLopcRequirePorts->pVehSig = pRequirePorts->pVehSig;                          /*!< Direct access to vehicle signals */
#endif
#if ((FCT_CFG_SEN2VEH_ACC_OOI_PORT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  pLopcRequirePorts->pAccOOIData = pRequirePorts->pFCTAccOOIData;
#endif
#if (FCT_VEH_CFG_CUSTOMINPUT)
  pLopcRequirePorts->pFctVehCustInput = pRequirePorts->pFctVehCustInput;        /*!< Custom input for FCT_VEH */
#endif
#if (FCT_CFG_BSW_ALGO_PARAMS)
  pLopcRequirePorts->pBswAlgoParameters = pRequirePorts->pBswAlgoParameters;    /*!< Input algo parameters from BSW */
#endif
#if (FCT_VEH_CFG_USE_LODMC_OUTPUT)
  pLopcRequirePorts->pLoDmcOutput = pRequirePorts->pLoDmcOutput;
#endif
#if (FCT_VEH_CFG_LOPC_SM_USE_EBA_OUTPUT)
  pLopcRequirePorts->pHEADOutputCustom = pProvidePorts->pHEADOutputCustom;
#endif


#if (FCT_CFG_USE_ALGOCOMPSTATE)
  pLopcProvidePorts->pVehCompState = pProvidePorts->pVehCompState;                      /*!< AlgoCompState interface to scheduler */
#endif
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
  pLopcProvidePorts->pFctVehLongOut = pProvidePorts->pFctVehLongOut;            /*!< Internal info passed from FCT_VEH to FCT_SEN */
#endif
  pLopcProvidePorts->pLongCtrlOutput = pProvidePorts->pLongCtrlOutput;          /*!< Longitudinal controller output data */
#if (FCT_CFG_TCI)
  pLopcProvidePorts->pTCIOutput        = pProvidePorts->pTCIOutput;
#endif
#if (FCT_CFG_ERROR_OUTPUT_VEH)
  pLopcProvidePorts->pErrorOut = &FCTVEH_pLOPCErrorOut;                      /*!< LOPC error output, to be connected to RTE when available for LoPC */
#endif
#if (FCT_VEH_CFG_CUSTOMOUTPUT)
  pLopcProvidePorts->pFCTVehOutArbitrated =pProvidePorts->pFCTVehOutArbitrated;
#endif

}
#endif /* (FCT_CFG_LOPC_COMPONENT) */
#endif /* FCT_CFG_ACT_CODE_VERSION */

#if(FCT_CFG_MEDIC_COMPONENT)
/*************************************************************************************************************************
  Functionname:        FCTVeh_v_SetMEDICProPort                                                                         */ /*!

  @brief               Medic provide ports structure

  @description         Creating medic component level Provide ports and setup provide ports using 
                       values received from FCT.
                       @startuml
                       Start
                       floating note : Maps the Medic Provide ports structure from FCT_Veh Provide ports
                       partition MedicProvidePort {
                         :Update medic Vehcomponent_state;
                         :Update medic DIM_Outputcustom structure;
                         :update medic HEAD_Outputgeneric structure;
                         :Update medic HEAD_Outputcustom structure;
                         :Update medic Error Output;
                         :Update medic FCT_Vehout_Arbitration;
                       }
                       stop
                       @enduml

  @return              void

  @param[in]           p_ProvidePorts : FCT_VEH provide ports
  @param[in,out]       p_MedicProvidePorts :Medic Provide ports 
   
  @glob_in             None 
  @glob_out            None

  @c_switch_part       FCT_CFG_USE_ALGOCOMPSTATE, FCT_CFG_DRIVER_INTENTION_MONITORING, FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION, FCT_CFG_INCLUDE_UNUSED_INTF
                       FCT_CFG_ERROR_OUTPUT_SEN, FCT_VEH_CFG_CUSTOMOUTPUT
  @c_switch_full       FCT_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                 None
  @post                None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined
  
  @author              Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com 
*************************************************************************************************************************/
static void FCTVeh_v_SetMEDICProPort(const proFCTVehPrtList_t *p_ProvidePorts, proMEDICPtrList_t *p_MedicProvidePorts)
{
  #if (FCT_CFG_USE_ALGOCOMPSTATE)
  p_MedicProvidePorts->pVehCompState        = p_ProvidePorts->pVehCompState;
  #endif
  #if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicProvidePorts->pDIMOutputCustom     = p_ProvidePorts->pDIMOutputCustom;
  #endif
  #if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicProvidePorts->pHEADOutputGeneric   = p_ProvidePorts->pHEADOutputGeneric;
  p_MedicProvidePorts->pHEADOutputCustom    = p_ProvidePorts->pHEADOutputCustom;
  #endif
  #if (FCT_CFG_ERROR_OUTPUT_VEH && MEDIC_CFG_ERROR_OUTPUT_VEH)
  p_MedicProvidePorts->pErrorOut            = p_ProvidePorts->pErrorOut;
  #endif
}

/*************************************************************************************************************************
  Functionname:        FCTVeh_v_SetMEDICReqPort                                                                          */ /*!

  @brief               Medic require ports structure 

  @description         Creating medic component level require ports to aquire data. 
                       @startuml
                       Start
                       floating note : Maps the FCT_Veh Require ports to the Medic Require ports structure 
                         partition MedicReqPort {
                         :Update medic Vehcontrol data;
                         :Update medic EgoDynRaw data;
                         :Update medic DIM_Inputgeneric structure;
                         :Update medic DIM_Inputcustom structure;
                         :Update medic FCT_ACDC_Hypothesis structure;
                         :Update medic HEAD_Inputgeneric structure;
                         :Update medic HEAD_Inputcustom structure;
                         :Update medic FCT_CPAR_Parameters structure;
                         :Update medic FCT_Veh_customInput structure;
                       }
                       stop
                       @enduml

  @return              void

  @param[in]           p_RequirePorts : FCT_VEH require ports 
  @param[in,out]       p_MedicRequirePorts : MEDIC require ports 
   
  @glob_in             None  
  @glob_out            None 

  @c_switch_part       @ref FCT_CFG_SHORT_RANGE_FUNCTIONS
                       @ref FCT_CFG_INCLUDE_UNUSED_INTF
                       @ref FCT_CFG_COLLISION_DETECTION
                       @ref FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION 
                       @ref FCT_CFG_CPAR_PARAMS
                       @ref FCT_VEH_CFG_CUSTOMINPUT 
  @c_switch_full       @ref FCT_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                 None
  @post                None 

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined 
  
  @author              Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com 
*************************************************************************************************************************/
static void FCTVeh_v_SetMEDICReqPort(const reqFCTVehPrtList_t *p_RequirePorts,  reqMEDICPtrList_t *p_MedicRequirePorts)
{
  p_MedicRequirePorts->pVehCtrlData         = p_RequirePorts->pVehCtrlData;
  #if (!FCT_CFG_SHORT_RANGE_FUNCTIONS)
  p_MedicRequirePorts->pEgoDynRaw           = p_RequirePorts->pEgoDynRaw;
  #endif
  #if ((FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pDIMInputGeneric     = p_RequirePorts->pDIMInputGeneric;
  p_MedicRequirePorts->pDIMInputCustom      = p_RequirePorts->pDIMInputCustom;
  #endif
  #if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pFCTCDHypotheses     = p_RequirePorts->pFCTCDHypotheses;
  #endif
  #if ((FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pHEADInputGeneric    = p_RequirePorts->pHEADInputGeneric;
  p_MedicRequirePorts->pHEADInputCustom     = p_RequirePorts->pHEADInputCustom;
  #endif
  #if ((FCT_CFG_CPAR_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pCPAR_FCT_Parameters = p_RequirePorts->pCPAR_FCT_Parameters;
  #endif
  #if ((FCT_VEH_CFG_VEH_SIG_INPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pVehSig              = p_RequirePorts->pVehSig;
  #endif
  #if ((FCT_CFG_BSW_ALGO_PARAMS) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pBswAlgoParameters   = p_RequirePorts->pBswAlgoParameters;
  #endif
  #if ((FCT_VEH_CFG_CUSTOMINPUT) || (FCT_CFG_INCLUDE_UNUSED_INTF))
  p_MedicRequirePorts->pFctVehCustInput     = p_RequirePorts->pFctVehCustInput;
  #endif
}

#if (FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*************************************************************************************************************************
  Functionname:        FCTVeh_v_SetMEDICErrorProPorts                                                                      */ /*!

  @brief               Medic provide ports structure in case of error

  @description         Creating medic component level Provide ports and setup provide ports using 
                       values received from FCT.
                       @startuml
                       Start
                       floating note : Maps the Medic Provide ports structure from FCT_Veh Provide ports
                       partition MedicProvidePort {
                         :Update medic Vehcomponent_state;
                         :Update medic DIM_Outputcustom structure;
                         :update medic HEAD_Outputgeneric structure;
                         :Update medic HEAD_Outputcustom structure;
                         :Update medic Error Output;
                         :Update medic FCT_Vehout_Arbitration;
                       }
                       stop
                       @enduml

  @return              void

  @param[in]           p_ProvidePorts : FCT_VEH provide ports
  @param[in,out]       p_MedicProvidePorts :Medic Provide ports 
   
  @glob_in             None 
  @glob_out            None

  @c_switch_part       FCT_CFG_USE_ALGOCOMPSTATE, FCT_CFG_DRIVER_INTENTION_MONITORING, FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION, FCT_CFG_INCLUDE_UNUSED_INTF
                       FCT_CFG_ERROR_OUTPUT_SEN, FCT_VEH_CFG_CUSTOMOUTPUT
  @c_switch_full       FCT_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                 None
  @post                None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @InOutCorrelation    Not defined 
  
  @testmethod          Test of output data (dynamic module test) 

  @traceability        Not defined
  
  @author              Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com 
*************************************************************************************************************************/

static void FCTVeh_v_SetMEDICErrorProPorts(const proFCTVehPrtList_t *p_ProvidePorts, proMEDICPtrList_t *p_MedicProvidePorts)
{
  if (p_ProvidePorts != NULL)
  {
    #if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    if (p_ProvidePorts->pDIMOutputCustom != NULL)
    {
      p_ProvidePorts->pDIMOutputCustom->uiVersionNumber = FCT_DIM_OUTPUT_CUSTOM_INTFVER;
      FCTVehSetSigHeaderError(&p_ProvidePorts->pDIMOutputCustom->sSigHeader);
      p_MedicProvidePorts->pDIMOutputCustom = p_ProvidePorts->pDIMOutputCustom;
    }
    else
    {
      p_MedicProvidePorts->pDIMOutputCustom = NULL;
    }
    #endif

    #if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    if (p_ProvidePorts->pHEADOutputGeneric != NULL)
    {
      p_ProvidePorts->pHEADOutputGeneric->uiVersionNumber = FCT_HEAD_OUTPUT_GENERIC_INTFVER;
      FCTVehSetSigHeaderError(&p_ProvidePorts->pHEADOutputGeneric->sSigHeader);
      p_MedicProvidePorts->pHEADOutputGeneric = p_ProvidePorts->pHEADOutputGeneric;
    }
    else
    {
      p_MedicProvidePorts->pHEADOutputGeneric = NULL;
    }
    if (p_ProvidePorts->pHEADOutputCustom != NULL)
    {
      p_ProvidePorts->pHEADOutputCustom->uiVersionNumber = FCT_HEAD_OUTPUT_CUSTOM_INTFVER;
      FCTVehSetSigHeaderError(&p_ProvidePorts->pHEADOutputCustom->sSigHeader);
      p_MedicProvidePorts->pHEADOutputCustom = p_ProvidePorts->pHEADOutputCustom;
    }
    else
    {
      p_MedicProvidePorts->pHEADOutputCustom = NULL;
    }
    #endif
  }
  else
  {
    #if (FCT_CFG_DRIVER_INTENTION_MONITORING)
    p_MedicProvidePorts->pDIMOutputCustom     = NULL;
    #endif
    #if (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)
    p_MedicProvidePorts->pHEADOutputGeneric   = NULL;
    p_MedicProvidePorts->pHEADOutputCustom    = NULL;
    #endif
  }
}
#endif // (FCT_CFG_DRIVER_INTENTION_MONITORING) || (FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION)

#endif // FCT_CFG_MEDIC_COMPONENT

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
