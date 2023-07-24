/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control) 

PACKAGENAME:               medic_memory_interface.h

DESCRIPTION:               MEDIC memory interface

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/11/05 16:18:39CET $

VERSION:                   $Revision: 1.27 $

**************************************************************************** */

#ifndef MEDIC_MEMORY_INTERFACE_H_INCLUDED
#define MEDIC_MEMORY_INTERFACE_H_INCLUDED

/*!
@brief    Contains the framework of the memory structure.  \n\n
@description 
All static memory is handled in this structure. Each subcomponent has a separate substructure where all calculated results shall be stored.\n
All subcomponents have access to everything in the memory structure.\n\n
To put variables into substructures the corresponding switch has to be activated.\n\n
Take care to put the variables into the structure which supports the expected behavior
.
| Memory block           | STACK                                     | INTER                                    | INTERMEAS               | INTRA                                  | INTRAMEAS                              | SIMU                             |
| :-----------           | :----                                     | :----                                    | :-------                | :----                                  | :--------                              | :--                              |
| <b>Purpose        </b> | - Data contains no history \n - It has to be accessed \n in multiple functions. |- Data contains history. \n - It has to be initialized in simulation. \n - It <b>is not</b> needed for visualization \n or debugging of the ECU behavior.|- Data contains history. \n - It has to be initialized in simulation. \n - It <b>is</b> needed for visualization \n or debugging of the ECU behavior.|- Similar to Stack data \n but data is needed for multiple runnables. \n - It <b>is not</b> needed for visualization \n or debugging of the ECU behavior.|- Similar to Stack data \n but data is needed for multiple runnables. \n - It <b>is</b> needed for visualization \n or debugging of the ECU behavior.| - Debugging data \n which is not \n needed in the ECU.|
| <b>Persists during</b> | the execution \n of MEDIC_Exec            | the ECU power cycle                      | the ECU power cycle     | multiple runnables \n of one component | multiple runnables \n of one component | one load cycle \n of the SIM dll |
| <b>ECU Freeze     </b> | None                                      | keyframes are frozen\n in multiple slices| cyclic                  | none                                   | cyclic                                 | none                             |
| <b>SIMU Freeze    </b> | cyclic                                    | cyclic                                   | cyclic                  | cyclic                                 | cyclic                                 | cyclic                           |
| <b>Hints          </b> |                                           |                                          | Should be as small \n as possible | Not to be used \n if component has one runnable | Not to be used \n if component has one runnable. \n Should be as small \n as possible |  |
*/

/* PRQA S 3332 EOF */ /* Reviewer: Rashmi Ramachandra, Reason:switches will be defined based on project needs and can take default values as zero*/

/*********************************************************************/
/* MEDIC Memory                                                       */
/*********************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/
/*! This version numbers has to be adapted on every update of the INTER cycle memory */
#define MEDIC_INTER_CYCLE_MEMORY_VERSION      (1)
#define MEDIC_INTER_CYCLEMEAS_MEMORY_VERSION  (1)


/*! @brief Activate this switch if you want to place a variable in the corresponding struct.*/
#define USE_MEDIC_BASEHYP_INTER       MEDIC_OFF
#define USE_MEDIC_BASEGLOB_INTER      MEDIC_ON

#define USE_MEDIC_BASEHYP_INTERMEAS   MEDIC_OFF
#define USE_MEDIC_BASEGLOB_INTERMEAS  MEDIC_ON

#define USE_MEDIC_BASEHYP_INTRAMEAS   MEDIC_OFF
#define USE_MEDIC_BASEGLOB_INTRAMEAS  MEDIC_ON

#define USE_DIM_HYP_INTER             MEDIC_OFF
#define USE_DIM_GLOB_INTER            MEDIC_OFF

#define USE_DIM_HYP_INTERMEAS         MEDIC_OFF
#define USE_DIM_GLOB_INTERMEAS        MEDIC_ON

#define USE_DIM_HYP_INTRAMEAS         MEDIC_OFF
#define USE_DIM_GLOB_INTRAMEAS        MEDIC_OFF

#define USE_HEAD_HYP_INTER            MEDIC_OFF
#define USE_HEAD_GLOB_INTER           MEDIC_OFF

#define USE_HEAD_HYP_INTERMEAS        MEDIC_OFF
#define USE_HEAD_GLOB_INTERMEAS       MEDIC_ON

#define USE_HEAD_HYP_INTRAMEAS        MEDIC_OFF
#define USE_HEAD_GLOB_INTRAMEAS       MEDIC_OFF



/* Switches for the integration of component substructures */
#define USE_MEDIC_HYP_INTER         (USE_MEDIC_BASEHYP_INTER      || USE_MEDIC_CUSTHYP_INTER     )
#define USE_MEDIC_GLOB_INTER        (USE_MEDIC_BASEGLOB_INTER     || USE_MEDIC_CUSTGLOB_INTER    )
#define USE_MEDIC_HYP_INTERMEAS     (USE_MEDIC_BASEHYP_INTERMEAS  || USE_MEDIC_CUSTHYP_INTERMEAS )
#define USE_MEDIC_GLOB_INTERMEAS    (USE_MEDIC_BASEGLOB_INTERMEAS || USE_MEDIC_CUSTGLOB_INTERMEAS)
#define USE_MEDIC_HYP_INTRAMEAS     (USE_MEDIC_BASEHYP_INTRAMEAS  || USE_MEDIC_CUSTHYP_INTRAMEAS )
#define USE_MEDIC_GLOB_INTRAMEAS    (USE_MEDIC_BASEGLOB_INTRAMEAS || USE_MEDIC_CUSTGLOB_INTRAMEAS)

/* End of switches for the integration of component substructures */

/* Switches for the integration of substructs */
#define USE_MEDICWRAPPER_HYP_INTER       ((USE_MEDIC_HYP_INTER)  || (USE_DIM_HYP_INTER)  || (USE_HEAD_HYP_INTER))
#define USE_MEDICWRAPPER_GLOB_INTER      ((USE_MEDIC_GLOB_INTER) || (USE_DIM_GLOB_INTER) || (USE_HEAD_GLOB_INTER))
#define USE_MEDICWRAPPER_INTER           (USE_MEDICWRAPPER_HYP_INTER || USE_MEDICWRAPPER_GLOB_INTER)

#define USE_MEDICWRAPPER_HYP_INTERMEAS   ((USE_MEDIC_HYP_INTERMEAS)  || (USE_DIM_HYP_INTERMEAS)  || (USE_HEAD_HYP_INTERMEAS))
#define USE_MEDICWRAPPER_GLOB_INTERMEAS  ((USE_MEDIC_GLOB_INTERMEAS) || (USE_DIM_GLOB_INTERMEAS) || (USE_HEAD_GLOB_INTERMEAS))
#define USE_MEDICWRAPPER_INTERMEAS       (USE_MEDICWRAPPER_HYP_INTERMEAS || USE_MEDICWRAPPER_GLOB_INTERMEAS)

#define USE_MEDICWRAPPER_HYP_INTRAMEAS   ((USE_MEDIC_HYP_INTRAMEAS)  || (USE_DIM_HYP_INTRAMEAS)  || (USE_HEAD_HYP_INTRAMEAS))
#define USE_MEDICWRAPPER_GLOB_INTRAMEAS  ((USE_MEDIC_GLOB_INTRAMEAS) || (USE_DIM_GLOB_INTRAMEAS) || (USE_HEAD_GLOB_INTRAMEAS))
#define USE_MEDICWRAPPER_INTRAMEAS       (USE_MEDICWRAPPER_HYP_INTRAMEAS || USE_MEDICWRAPPER_GLOB_INTRAMEAS)

/* End of switches for the integration of substructs */

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! @brief frame structures to organize the memory type specific typedefs of MEDIC and its subcomponents */

/************************************************************************/
/* MEDIC Inter custom types                                              */
/************************************************************************/

/*! MEDIC Hypothesis data */
#if (USE_MEDIC_HYP_INTER)
typedef struct  MEDIC_HypInter_t  
{
  #if (USE_MEDIC_CUSTHYP_INTER)
  MEDIC_HypDataCustInter_t Custom;
  #endif /* USE_MEDIC_CUSTHYP_INTER */
} MEDIC_HypInter_t;
#endif /* USE_MEDIC_HYP_INTER */

/*! MEDIC global data */
#if (USE_MEDIC_GLOB_INTER)
typedef struct  MEDIC_GlobDataInter_t  
{
  #if (USE_MEDIC_CUSTGLOB_INTER)
  MEDIC_GlobDataCustInter_t Custom;
  #endif /* USE_MEDIC_CUSTGLOB_INTER */
  MEDICPortHandlerList_t  MEDIC_PortHandlerList;
} MEDIC_GlobDataInter_t;
#endif /* USE_MEDIC_GLOB_INTER */

/************************************************************************/
/* MEDIC InterMeas types                                                 */
/************************************************************************/

/*! MEDIC Hypothesis data */
#if (USE_MEDIC_HYP_INTERMEAS)
typedef struct  MEDIC_HypInterMeas_t  
{
  #if (USE_MEDIC_CUSTHYP_INTERMEAS)
  MEDIC_HypDataCustInterMeas_t Custom;
  #endif /* USE_MEDIC_CUSTHYP_INTERMEAS */
} MEDIC_HypInterMeas_t;
#endif /* USE_MEDIC_HYP_INTERMEAS */

/*! MEDIC global data */
#if (USE_MEDIC_GLOB_INTERMEAS)
typedef struct  MEDIC_GlobDataInterMeas_t  
{
  #if (USE_MEDIC_CUSTGLOB_INTERMEAS)
  MEDIC_GlobDataCustInterMeas_t Custom;
  #endif /* USE_MEDIC_CUSTGLOB_INTERMEAS */
  MEDICFrame_t    MEDICFrame;
  uint64          uiAlgoTimestamp;
  uint32          uiAlgoCycleTime;
} MEDIC_GlobDataInterMeas_t;
#endif /* USE_MEDIC_GLOB_INTERMEAS */

/************************************************************************/
/* MEDIC IntraMeas types                                       */
/************************************************************************/

/* MEDIC Hypothesis data */
#if (USE_MEDIC_HYP_INTRAMEAS)
typedef struct  MEDIC_HypIntraMeas_t  
{
  #if (USE_MEDIC_CUSTHYP_INTRAMEAS)
  MEDIC_HypDataCustIntraMeas_t Custom;
  #endif /* USE_MEDIC_CUSTHYP_INTRAMEAS */
} MEDIC_HypIntraMeas_t;
#endif /* USE_MEDIC_HYP_INTRAMEAS */

/* MEDIC global data */
#if (USE_MEDIC_GLOB_INTRAMEAS)
typedef struct  MEDIC_GlobDataIntraMeas_t  
{
  #if (USE_MEDIC_CUSTGLOB_INTRAMEAS)
  MEDIC_GlobDataCustIntraMeas_t Custom;
  #endif /* USE_MEDIC_CUSTGLOB_INTRAMEAS */
  MEDICSyncRef_t MEDICSyncRef;
  uint8          dummy  ;
} MEDIC_GlobDataIntraMeas_t;
#endif /* USE_MEDIC_GLOB_INTRAMEAS */

/************************************************************************/
/* DIM Inter custom types                                       */
/************************************************************************/

/* DIM Hypothesis data */
#if (USE_DIM_HYP_INTER)
typedef struct  DIM_HypInter_t  
{

} DIM_HypInter_t;
#endif /* USE_DIM_HYP_INTER */

/* DIM global data */
#if (USE_DIM_GLOB_INTER)
typedef struct  DIM_GlobDataInter_t  
{ 
  uint8 dummy  ;
} DIM_GlobDataInter_t;
#endif /* USE_DIM_GLOB_INTER */

/************************************************************************/
/* DIM InterMeas types                                       */
/************************************************************************/
/* DIM Hypothesis data */
#if (USE_DIM_HYP_INTERMEAS)
typedef struct  DIM_HypInterMeas_t  
{

} DIM_HypInterMeas_t;
#endif /* USE_DIM_HYP_INTERMEAS */

/* DIM global data */
#if (USE_DIM_GLOB_INTERMEAS)
typedef struct  DIM_GlobDataInterMeas_t  
{
  #if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
  boolean                bDIMInitialized;
  DIMData_t              DIMData;
  DIM_HYPOUT_CAL_DATA_t  DIM_HYPOUT_CAL_DATA_EBA;
  DIMHypothesisList_t    DIMHypothesisList ;
  #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
  DimIirFilt_t           DimIirFiltSteeringAngle;
  #endif
  #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
  DimIirFilt_t           DimIirFiltGasPedal;
  #endif
  #endif
  uint8                  dummy  ;
} DIM_GlobDataInterMeas_t;
#endif /* USE_DIM_GLOB_INTERMEAS */

/************************************************************************/
/* DIM IntraMeas types                                       */
/************************************************************************/

/* DIM Hypothesis data */
#if (USE_DIM_HYP_INTRAMEAS)
typedef struct  DIM_HypIntraMeas_t  
{

} DIM_HypIntraMeas_t;
#endif /* USE_DIM_HYP_INTRAMEAS */

/* DIM global data */
#if (USE_DIM_GLOB_INTRAMEAS)
typedef struct  DIM_GlobDataIntraMeas_t  
{

} DIM_GlobDataIntraMeas_t;
#endif /* USE_DIM_GLOB_INTRAMEAS */

/************************************************************************/
/* HEAD Inter custom types                                       */
/************************************************************************/

/* HEAD Hypothesis data */
#if (USE_HEAD_HYP_INTER)
typedef struct  HEAD_HypInter_t  
{

} HEAD_HypInter_t;
#endif /* USE_HEAD_HYP_INTER */

/* HEAD global data */
#if (USE_HEAD_GLOB_INTER)
typedef struct  HEAD_GlobDataInter_t  
{

} HEAD_GlobDataInter_t;
#endif /* USE_HEAD_GLOB_INTER */

/************************************************************************/
/* HEAD InterMeas types                                       */
/************************************************************************/

/* HEAD  Hypothesis data */
#if (USE_HEAD_HYP_INTERMEAS)
typedef struct  HEAD_HypInterMeas_t  
{

} HEAD_HypInterMeas_t;
#endif /* USE_HEAD_HYP_INTERMEAS */

/* HEAD global data */
#if (USE_HEAD_GLOB_INTERMEAS) && (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
typedef struct  HEAD_GlobDataInterMeas_t  
{
  EBASignalState_t       EBASignalState;
  EBAFctChan_t           EBAFctChan;
  HEADCustOutputLocVar_t HEADCustOutputLocVar;
  HEADInputData_t        HEADInputData;
} HEAD_GlobDataInterMeas_t;
#endif /* USE_HEAD_GLOB_INTERMEAS */

/************************************************************************/
/* HEAD IntraMeas types                                       */
/************************************************************************/
/* HEAD  Hypothesis data */
#if (USE_HEAD_HYP_INTRAMEAS)
typedef struct  HEAD_HypIntraMeas_t  
{

} HEAD_HypIntraMeas_t;
#endif /* USE_HEAD_HYP_INTRAMEAS */

/* HEAD global data */
#if (USE_HEAD_GLOB_INTRAMEAS)
typedef struct  HEAD_GlobDataIntraMeas_t  
{

} HEAD_GlobDataIntraMeas_t;
#endif /* USE_HEAD_GLOB_INTRAMEAS */

/************************************************************************/
/* MEDIC wrapper Stack types                                             */
/************************************************************************/
typedef struct  MEDIC_DataWrapperStack_t  
{
  SignalHeader_t             sSigHeader;

  #if (!MEDIC_CFG_MTS_DATA_IN_INTER_MEAS)
  HEADMTSData_t              HEADMTSData; 
  HEADMTSSpecificData_t      HEADMTSExtData;
  HEADMTSCodedInhibition_t   HEADMTSCodedInhibition;
  HEADMTSConditionsOKTimer_t HEADMTSConditionsOKTimer;
  HEADMTSModuleCommonOut_t   HEADMTSModuleCommonOut;
  MEDICCompState_t           HEADState;
  #endif

} MEDIC_DataWrapperStack_t;

/************************************************************************/
/* MEDIC wrapper Inter types                                             */
/************************************************************************/
#if (USE_MEDICWRAPPER_HYP_INTER)
typedef struct MEDIC_HypDataWrapperInterHeader_t
{
  float32 Dummy;
} MEDIC_HypDataWrapperInterHeader_t;

typedef struct MEDIC_HypDataWrapperInterHyp_t
{
  #if (USE_MEDIC_HYP_INTER)
  MEDIC_HypInter_t              MEDIC;
  #endif
  #if (USE_DIM_HYP_INTER)
  DIM_HypInter_t                DIM;
  #endif
  #if (USE_HEAD_HYP_INTER)
  HEAD_HypInter_t               HEAD;
  #endif
} MEDIC_HypDataWrapperInterHyp_t;

typedef struct MEDIC_HypDataWrapperInter_t
{
  MEDIC_HypDataWrapperInterHeader_t sHeader;
  MEDIC_HypDataWrapperInterHyp_t    aHyp[MAX_NUM_OF_HYPS];
} MEDIC_HypDataWrapperInter_t;
#endif // USE_MEDICWRAPPER_HYP_INTER

#if (USE_MEDICWRAPPER_GLOB_INTER)
typedef struct MEDIC_GlobDataWrapperInter_t
{
  #if (USE_MEDIC_GLOB_INTER)
  MEDIC_GlobDataInter_t         MEDIC;
  #endif
  #if (USE_DIM_GLOB_INTER)
  DIM_GlobDataInter_t           DIM;
  #endif
  #if (USE_HEAD_GLOB_INTER)
  HEAD_GlobDataInter_t          HEAD;
  #endif
} MEDIC_GlobDataWrapperInter_t;
#endif // USE_MEDICWRAPPER_GLOB_INTER

#if (USE_MEDICWRAPPER_INTER)
typedef struct  MEDIC_DataWrapperInter_t  
{
  uint32                         uVersion;
  SignalHeader_t                 sSigHeader;
  #if (USE_MEDICWRAPPER_HYP_INTER)
  MEDIC_HypDataWrapperInter_t    sHypData;
  #endif
  #if (USE_MEDICWRAPPER_GLOB_INTER)
  MEDIC_GlobDataWrapperInter_t sGlobData;
  #endif
} MEDIC_DataWrapperInter_t;
#endif // USE_MEDICWRAPPER_INTER

/************************************************************************/
/* MEDIC wrapper InterMeas types                                         */
/************************************************************************/

#if (USE_MEDICWRAPPER_HYP_INTERMEAS)
typedef struct MEDIC_HypDataWrapperInterMeasHeader_t
{
  float32 Dummy;
} MEDIC_HypDataWrapperInterMeasHeader_t;

typedef struct MEDIC_HypDataWrapperInterMeasHyp_t
{
  #if (USE_MEDIC_HYP_INTERMEAS)
  MEDIC_HypInterMeas_t          MEDIC;
  #endif
  #if (USE_DIM_HYP_INTERMEAS)
  DIM_HypInterMeas_t            DIM;
  #endif
  #if (USE_HEAD_HYP_INTERMEAS)
  HEAD_HypInterMeas_t           HEAD;
  #endif
} MEDIC_HypDataWrapperInterMeasHyp_t;

typedef struct MEDIC_HypDataWrapperInterMeas_t
{
  MEDIC_HypDataWrapperInterMeasHeader_t sHeader;
  MEDIC_HypDataWrapperInterMeasHyp_t    aHyp[MAX_NUM_OF_HYPS]
} MEDIC_HypDataWrapperInterMeas_t;
#endif

#if (USE_MEDICWRAPPER_GLOB_INTERMEAS)
typedef struct MEDIC_GlobDataWrapperInterMeas_t
{
  #if (USE_MEDIC_GLOB_INTERMEAS)
  MEDIC_GlobDataInterMeas_t      MEDIC;
  #endif
  #if (USE_DIM_GLOB_INTERMEAS) && (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
  DIM_GlobDataInterMeas_t        DIM;
  #endif
  #if (USE_HEAD_GLOB_INTERMEAS) && (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
  HEAD_GlobDataInterMeas_t       HEAD;
  #endif
} MEDIC_GlobDataWrapperInterMeas_t;
#endif

#if (USE_MEDICWRAPPER_INTERMEAS)
typedef struct  MEDIC_DataWrapperInterMeas_t  
{
  uint32                              uVersion;
  SignalHeader_t                      sSigHeader;
  #if (USE_MEDICWRAPPER_HYP_INTERMEAS)
  MEDIC_HypDataWrapperInterMeas_t     sHypData;
  #endif
  #if (USE_MEDICWRAPPER_GLOB_INTERMEAS)
  MEDIC_GlobDataWrapperInterMeas_t    sGlobData;
  #endif

  #if MEDIC_CFG_MTS_DATA_IN_INTER_MEAS
  HEADMTSData_t              HEADMTSData; 
  HEADMTSSpecificData_t      HEADMTSExtData;
  HEADMTSCodedInhibition_t   HEADMTSCodedInhibition;
  HEADMTSConditionsOKTimer_t HEADMTSConditionsOKTimer;
  HEADMTSModuleCommonOut_t   HEADMTSModuleCommonOut;
  MEDICCompState_t           HEADState;
  #endif

  #if (MEDIC_CFG_DIAGNOSTIC_OUTPUT)
  MEDIC_Diagnostic_t                   MEDICDiag;
  #endif

} MEDIC_DataWrapperInterMeas_t;


#endif // USE_MEDICWRAPPER_INTERMEAS

/************************************************************************/
/* MEDIC wrapper IntraMeas types                                         */
/************************************************************************/

#if (USE_MEDICWRAPPER_HYP_INTRAMEAS)
typedef struct MEDIC_HypDataWrapperIntraMeasHeader_t
{
  float32 Dummy;
} MEDIC_HypDataWrapperIntraMeasHeader_t;

typedef struct MEDIC_HypDataWrapperIntraMeasHyp_t
{
  #if (USE_MEDIC_HYP_INTRAMEAS)
  MEDIC_HypIntraMeas_t           MEDIC;
  #endif
  #if (USE_DIM_HYP_INTRAMEAS)
  DIM_HypIntraMeas_t             DIM;
  #endif
  #if (USE_HEAD_HYP_INTRAMEAS)
  HEAD_HypIntraMeas_t            HEAD;
  #endif
} MEDIC_HypDataWrapperIntraMeasHyp_t;

typedef struct MEDIC_HypDataWrapperIntraMeas_t
{
  MEDIC_HypDataWrapperIntraMeasHeader_t sHeader;
  MEDIC_HypDataWrapperIntraMeasHyp_t    aHyp[MAX_NUM_OF_HYPS]
} MEDIC_HypDataWrapperIntraMeas_t;
#endif

#if (USE_MEDICWRAPPER_GLOB_INTRAMEAS)
typedef struct MEDIC_GlobDataWrapperIntraMeas_t
{
  #if (USE_MEDIC_GLOB_INTRAMEAS)
  MEDIC_GlobDataIntraMeas_t       MEDIC;
  #endif
  #if (USE_DIM_GLOB_INTRAMEAS)
  DIM_GlobDataIntraMeas_t         DIM;
  #endif
  #if (USE_HEAD_GLOB_INTRAMEAS)
  HEAD_GlobDataIntraMeas_t        HEAD;
  #endif
} MEDIC_GlobDataWrapperIntraMeas_t;
#endif

#if (USE_MEDICWRAPPER_INTRAMEAS)
typedef struct  MEDIC_DataWrapperIntraMeas_t  
{
  SignalHeader_t                       sSigHeader;
  #if (USE_MEDICWRAPPER_HYP_INTRAMEAS)
  MEDIC_HypDataWrapperIntraMeas_t      sHypData;
  #endif
  #if (USE_MEDICWRAPPER_GLOB_INTRAMEAS)
  MEDIC_GlobDataWrapperIntraMeas_t     sGlobData;
  #endif
} MEDIC_DataWrapperIntraMeas_t;
#endif

/************************************************************************/
/* Data access types                                                    */
/************************************************************************/

/*! @brief Structure which contains pointers to all input structures used in MEDIC */
typedef struct MEDIC_Input_t 
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  reqMEDICPtrList_t   ReqPorts; /*!< Use a copy of the pointer list here. Using a copy instead of a pointer here, is necessary because otherwise the data access in the draw function is not possible (req   port pointer becomes  invalid if FCTVeh_Exec is left, but not the contained memory addresses). */
  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  AS_t_ServiceFuncts  ServiceFuncts;
  #endif
  #else
  MEDIC01_ReqPorts    ReqPorts;
  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  MEDIC_Services      ServiceFuncts;
  #endif
  #endif
} MEDIC_Input_t;

/*! @brief Structure which contains pointers to all output structures used in MEDIC */
typedef struct MEDIC_Output_t 
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  proMEDICPtrList_t ProPorts; /*!< Use a copy of the pointer list here. Using a copy instead of a pointer here, is necessary because otherwise the data access in the draw function is not possible (pro     port pointer becomes    invalid if FCTVeh_Exec is left, but not the contained memory addresses). */
  #else
  MEDIC01_ProPorts  ProPorts;
  #endif
} MEDIC_Output_t;

/*! @brief Structure which contains pointers to the different memory types used in MEDIC */
typedef struct MEDIC_Working_t
{
  MEDIC_DataWrapperStack_t      * pStackData;
  #if (USE_MEDICWRAPPER_INTER)
  MEDIC_DataWrapperInter_t      * pInterCycle;
  #endif
  #if (USE_MEDICWRAPPER_INTERMEAS)
  MEDIC_DataWrapperInterMeas_t  * pInterCycleMeas;
  #endif
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  MEDIC_DataWrapperIntraMeas_t  * pIntraCycleMeas;
  #endif
  //Todo: remove:
  uint32 uDummy;
} MEDIC_Working_t;

/*! @brief Structure which contains pointers to all data structures used in MEDIC. \n
An instance of this structure is used to grant access in the complete code. */
typedef struct MEDICAccessData_t 
{
  MEDIC_Input_t       Input;
  MEDIC_Working_t     Working;
  MEDIC_Output_t      Output;
} MEDICAccessData_t;

#endif // MEDIC_MEMORY_INTERFACE_H_INCLUDED
