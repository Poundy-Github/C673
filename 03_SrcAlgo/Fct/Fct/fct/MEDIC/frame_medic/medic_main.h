/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_main.h

DESCRIPTION:               MEDIC main function header file 

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/04/24 10:17:33CEST $

VERSION:                   $Revision: 1.45 $

**************************************************************************** */

#ifndef MEDIC_MAIN_H_NON_GA_INCLUDED
#define MEDIC_MAIN_H_NON_GA_INCLUDED


#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! MEDIC states */
typedef enum 
{
  MEDIC_STATE_INIT,     /*!< initialize all            */
  MEDIC_STATE_RUN,      /*!< normal processing         */
  MEDIC_STATE_SHUTDOWN  /*!< shutdown (system failure) */
} MEDICState_t;

/*PRQA S 2053 DOXY_HEADER*/
/*! @brief          Define MEDIC Comp state if it is not available already. This improves consistency, as all components work with the same states.
    @description    MEDIC component state. Describes the state in which a (Sub-)component is currently. 
                      @range[0,6], @values: enum { COMP_STATE_NOT_INITIALIZED=0,
                                                   COMP_STATE_RUNNING=1,
                                                   COMP_STATE_TEMPORARY_ERROR=2,
                                                   COMP_STATE_PERMANENT_ERROR=3,
                                                   COMP_STATE_SUCCESS=4,
                                                   COMP_STATE_REDUCEDAVAILABILITY=5,
                                                   COMP_STATE_NOT_RUNNING=6} */
/*PRQA L:DOXY_HEADER*/
typedef uint8 MEDICCompState_t;


/*! @brief medic data frame structure*/
typedef struct MEDICFrame_t 
{
  AlgoCycleCounter_t   uiCycleCounter;      /*!< The MEDIC cycle counter @range: 0 to 65535 */
  boolean              bFirstCycleDone;     /*!< Boolean flag used for first cycle check    */
  MEDICOpMode_t        eMEDICOpMode;        /*!< MEDIC operation mode @range:0 to 4         */
  MEDICVersions_t      Versions;            /*!< MEDIC versions                             */
  MEDICCompState_t     eMEDICState;         /*!< MEDIC Comp state*/
  MEDICCompState_t     eDIMState;           /*!< DIM Comp state*/
  MEDICCompState_t     eHEADState;          /*!< HEAD Comp state*/
  boolean              bIsInitialized;      /*!< Boolean showing if the component has been initialized. */
} MEDICFrame_t;                             /*!< The function frame                         */

/*!< aggregation struct of all input port data update information*/
#if (MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING)
typedef struct
{
  sMeasCycleMonitor pVehCtrlData;           /*!< Vehicle Control Data input */
  sMeasCycleMonitor pEgoDynRaw;             /*!< EgoDynRaw*/
  #if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pDIMInputGeneric;       /*!< Generic DIM input */
  sMeasCycleMonitor pDIMInputCustom;        /*!< Custom DIM input */
  #endif 
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  /* Hypothesis interface */
  sMeasCycleMonitor pFCTCDHypotheses;       /*!< CD hypotheses */
  #endif
  #if ((MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pHEADInputGeneric;      /*!< Generic HEAD input */
  sMeasCycleMonitor pHEADInputCustom;       /*!< Custom HEAD input */
  #endif
  #if ((MEDIC_CFG_CPAR_PARAMS) || (MEDIC_CFG_INCLUDE_UNUSED_INTF))
  sMeasCycleMonitor pCPAR_FCT_Parameters;   /*!< FCT Coding Parameters */
  #endif
} Medic_InputMeasCounter;
#endif /* MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING */

#if (MEDIC_CFG_RTA_PROFILING)
/*!enumeration of RunTimeAssessment events*/
typedef enum
{
  MEDIC_RTA_PROCESS             = 0,         /*!<whole procedure runtime*/
  MEDIC_RTA_PREPRE_PROCESS      = 1,         /*!<data preparation runtime*/
  MEDIC_RTA_DIM_PROCESS         = 2,         /*!<Driver Intention Monitoring runtime*/
  MEDIC_RTA_HEAD_PROCESS        = 3,         /*!<Hypothesis Evaluation and Decision runtime*/
  MEDIC_RTA_PROCESSFREEZE       = 4,         /*!<Process Measfreeze runtime*/
  MEDIC_RTA_FRAMEFREEZE         = 5,         /*!<Frame Measfreeze runtime*/
  MEDIC_RTA_HEAD_GSM            = 6,         /*!<Single HEAD GSM module runtime*/
  MEDIC_RTA_TP_PROCESS          = 7,         /*!<Target Planner runtime*/
  MEDIC_RTA_POSTPROCESS         = 8,         /*!<Postprocessing runtime */
  MEDIC_RTA_HEAD_INIT           = 9,         /*!<HEAD Init call runtime*/
  MEDIC_RTA_HEAD_SPM_CHECK      = 10,        /*!<SPM condition check  runtime*/
  MEDIC_RTA_HEAD_PRECONDITION   = 11,        /*!<Precondtion evaluation runtime*/
  MEDIC_RTA_HEAD_BREAK_SM       = 12,        /*!<Break SM evaluation runtime*/
  MEDIC_RTA_HEAD_TOGGLE_FN      = 13,        /*!<Toggle function evaluation runtime*/
  MEDIC_RTA_HEAD_HBA_FN         = 14,        /*!<HBA function evaluation runtime*/
  MEDIC_RTA_HEAD_WARN_FN        = 15,        /*!<Warn function evaluation runtime*/
  MEDIC_RTA_HEAD_GSM_TRANSITION = 16,        /*!<Transition evaluation runtime*/
  MEDIC_RTA_HEAD_CODING         = 17,        /*!<Custom coding and update params runtime*/
  MEDIC_RTA_LAST_ENTRY          = 18         /*!<max enum*/
} MEDIC_t_RtaMapping; /* RTA_LOCAL_ID_FOR_XML_GENERATION */
#endif 

/*PRQA S 2053 DOXY_HEADER*/
/*! @brief          MEDIC Subcomponent Indices.
    @description    Bitfield with Indices for each subcomponent. Can handle a maximum of 8 subcomponents.
                    The current number of subcomponent is defined by @ref MEDIC_NOF_SUB_COMPONENTS.
                      @range[0,255], 
                      @values: enum { MEDIC_SUB_COMP_DIM=1,
                                      MEDIC_SUB_COMP_HEAD=2,
                                      MEDIC_SUB_COMP_MEDIC=4} */
/*PRQA L:DOXY_HEADER*/
typedef uint8 MEDICSubCompIndices_t;

/*! @brief          Generic Data contained in each Req/Pro Port
    @description    Describes generic data that is contained in each Req/Pro port: The Version Number and the Signal header. 
                    This data type is used to enable a generic handling of all ports. (see @ref MEDICPortHandlerList_t)*/
typedef struct MEDICGenericPortData
{
  AlgoInterfaceVersionNumber_t uiVersionNumber;
  SignalHeader_t sSigHeader;
} MEDICGenericPortData_t;

/*! @brief    Structure of the require port handler. It is filled by the function @ref MEDIC_v_SetupReqPortHandler */
typedef struct MEDICReqPortHandler
{
  void                   const * pReqPort;                 /*!< Pointer to the considered require port.*/
  MEDICGenericPortData_t const * pGenericReqPortData;      /*!< Pointer to the signal header and version number of the considered require port.*/
  SignalHeader_t               * pReqSignalHeaderSyncRef;  /*!< Pointer to the corresponding signal header in @ref MEDICSyncRef.*/
  uint32                         uSize;                    /*!< Size of the structure of the require port. Needed here for freezing.*/
  sMeasCycleMonitor              MeasCycleMonitor;         /*!< MeasCycleInformation of the corresponding port.*/
  MEDICSubCompIndices_t          InfluencedSubComponents;  /*!< Bitfield indicating which subcomponents are affected by the Req Port.*/
} MEDICReqPortHandler_t;

/*! @brief    Structure of the provide port handler. It is filled by the function @ref MEDIC_v_SetupProPortHander */
typedef struct MEDICProPortHandler
{
  void                         * pProPort;                  /*!< Pointer to the considered provide port.*/
  MEDICGenericPortData_t       * pGenericProPortData;       /*!< Pointer to the signal header and version number of the considered provide port.*/
  MEDICGenericPortData_t const * pGenericReqPortData;       /*!< Signal header of the require port which shall be source for the signal header of the provide port.*/
  uint32                         uSize;                     /*!< Size of the structure of the provide port. Needed here for freezing.*/
  uint32                         uMeasFreezeAddress;        /*!< Address to which the information provided by the port shall be frozen.*/
  uint32                         uProNewVersionNumber;      /*!< Version number that shall be written to the provide port.*/
  MEDICSubCompIndices_t          uInfluencingSubComponents; /*!< Bitfield indicating which subcomponents are affecting the content of the Pro Port*/
} MEDICProPortHandler_t;

/*! @brief    Contains two lists of handlers: One for all provide ports and one for all require ports.*/
typedef struct MEDICPortHandlerList
{
  MEDICProPortHandler_t   ProPortHandler[MEDIC_NOF_PRO_PORTS];  /*!< List of all provide port handlers*/ /*PRQA S 4548 *//* uic45572: doesnt impact the software */
  MEDICReqPortHandler_t   ReqPortHandler[MEDIC_NOF_REQ_PORTS];  /*!< List of all require port handlers*/ /*PRQA S 4548 *//* uic45572: doesnt impact the software */
  uint8                   uNofProPorts;                         /*!< Number of Ports stored in the provide port handler list*/
  uint8                   uNofReqPorts;                         /*!< Number of Ports stored in the require port handler list*/
} MEDICPortHandlerList_t;


#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */


#endif /* MEDIC_MAIN_H_INCLUDED */

