/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_module_def.h

DESCRIPTION:               Header of the HEAD component - for module definition

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/17 13:55:33CEST $

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            1.26
  
**************************************************************************** */
/**
@ingroup head
@{ **/
#ifndef HEAD_MODULE_DEF_H_INCLUDED
#define HEAD_MODULE_DEF_H_INCLUDED
/*** START OF SINGLE INCLUDE SECTION ****************************************/

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief          Maximum Head Modules Count
    @description    Maximum number of HEAD Modules allowed
                    @typical 31u @unit [Count]
    @conseq         @incp  FCT function will be able to handle one more HEAD Module
                    @decp  FCT function will be able to handle one less HEAD Module
*/
#define HEADModules_Max (31u)
/* ================== MODULES =========================*/

/* ****************************************************************
    TYPEDEF ENUM eHEADSMState_t
    **************************************************************** */
/*! @brief          HEAD State Machine States
    
    @description    This enum defines different states of State Machine in HEAD
    */
typedef enum 
{
  HEADSMState_OFF             = 0,                    /*!< state off - function cannot be activated*/
  HEADSMState_PASSIVE         = 1,                    /*!< state passive - function can be activated*/
  HEADSMState_ACTIVE          = 2,                    /*!< state active - function is activated*/
  HEADSMState_WAIT            = 3,                    /*!< state wait - function is in hold state*/
  HEADSMState_Max             = 4                     /*!< max number of enum elements*/
} eHEADSMState_t;


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADSMState_t
    */
typedef uint8 HEADSMState_t;                          /*!< @values @ref eHEADSMState_t */


/* forward declaration of the type...*/
/*!  @cond Doxygen_Suppress */
/* ****************************************************************
    TYPEDEF STRUCT HEADModule_t
    **************************************************************** */
/*! @brief          Forward declared typedef of @ref HEADModule_t
    */
typedef struct HEADModule_t HEADModule_t;
/*! @endcond */


/* ****************************************************************
    TYPEDEF STRUCT HEADInputData_t
    **************************************************************** */
/*! @brief          Forward declaration typedef of @ref HEADInputData_t
    */
typedef struct HEADInputData_t HEADInputData_t;


/*!  @cond Doxygen_Suppress */
/*****************************************************************************
    TYPEDEF FUNCTION 
*****************************************************************************/
typedef eGDBError_t HEADModuleCustomFunction_ft(uint8 uiModuleNr, const struct HEADInputData_t*pInputData, boolean bInit);


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          Date type to store HEAD Hypothesis Number
    */ 
typedef uint8 HEADHypothesisNr_t;


/*! @brief          Type used for describing HEAD BIT Field
    */
typedef ubit32 HEADBitField_t;
/*! @endcond */


/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief          HEAD_MAX_OR_GROUPS
    @description    Maximum Number of OR_GROUPS
                    @typical 8 @unit [SI-unit] 
    */
#define HEAD_MAX_OR_GROUPS 8U

/*! @brief          HEADNoHypothesis
    @description    HEAD No Hypothesis value
                    @typical 255 @unit [SI-unit] 
    */
#define HEADNoHypothesis          ((HEADHypothesisNr_t)255)

/*! @brief          HEADHypothesisIndependent
    @description    HEAD Hypothesis Independent Signal
                    @typical @ref HEAD_MAX_NUMBER_OF_CD_HYPS @unit [SI-unit] 
    */
#define HEADHypothesisIndependent ((HEADHypothesisNr_t)HEAD_MAX_NUMBER_OF_CD_HYPS)

/*! define the module internal structure (only the interface (empty structure with header ))*/

/* ****************************************************************
    TYPEDEF ENUM eHEADModuleInternalType_t
    **************************************************************** */
/*! @brief          HEAD Module Internal Types

    @description    This enum defines different types of State Machine in HEAD Module
    */
typedef enum 
{
  HEADModuleInternalType_GSM     = 0,                   /*!< Module uses generic state machine (head_generic_sm.c/head_generic_sm.h)*/
  HEADModuleInternalType_Custom  = 1,                   /*!< Module uses custom state machine (????.c/h)*/

  HEADModuleInternalType_Max     = 2                    /*!< max number of enum elements*/
} eHEADModuleInternalType_t;


/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          The numeric type of the enum @ref eHEADModuleInternalType_t
    */
typedef uint8 HEADModuleInternalType_t;                 /*!< @values @ref eHEADModuleInternalType_t */


/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalHeader_t
    **************************************************************** */
/*! @brief          HEAD Module Internal State Machine Type and Function Handler

    @description    This structure defines the type of HEAD SM and its handling function

    @conseq         Changing internal type will change type of SM that head machine use

    @attention      [None]

    */
typedef struct 
{
  eHEADModuleInternalType_t eModuleInternalType;        /*!< ModuleInternalType  @values @ref eHEADModuleInternalType_t*/
  HEADModuleCustomFunction_ft *fpCustom;                /*!< function pointer to the state machine handling function*/
} HEADModuleInternalHeader_t;


/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalInterface_t
    **************************************************************** */
/*! @brief          Abstract ModuleInternal interface

    @description    Abstract ModuleInternal interface - define your own for work
    */
typedef struct 
{
  HEADModuleInternalHeader_t InternalHeader;            /*!< InternalHeader*/
  /*noting else here... but in the specific implementation*/
} HEADModuleInternalInterface_t;


/*****************************************************************************
    TYPEDEF FUNCTION 
*****************************************************************************/
/*! @brief          Module output function
    @description    Module output function - pModule defines the specific module, 
                    bInit defines if the output should be initialized or not
    */
typedef eGDBError_t HEADModuleCustomOutput_ft(const struct HEADInputData_t *pInputData, const struct HEADModule_t *pModule, boolean bInit); 


/*module output structure interface*/
  /* ****************************************************************
    STRUCT HEADModuleOutputInterface_t
    **************************************************************** */
/*! @brief          HEAD Module Output Interface

    @description    HEAD Module Output Interface
    */
struct HEADModuleOutputInterface_t
{
  HEADModuleCustomOutput_ft *fpCustomOutput;        /*!< function pointer to the CustomOutput function*/
};

/* ****************************************************************
    TYPEDEF ENUM eHEADModuleQoS_t
    **************************************************************** */
/*! @brief          HEAD Module QoS definition 

    @description    Defines the states of the QoS for an module 

    @attention      MUST be sorted from most severe to normal running
    */
typedef enum 
{
  HEADModuleQoS_DegradationStop      = 0,           /*!< severe failure mode, direct immediate transition to off*/
  HEADModuleQoS_DegradationShutDown  = 1,           /*!< normal failure mode, there is no active condition anymore --> module will transit from active to wait --> off*/
  HEADModuleQoS_DegradationKeep      = 2,           /*!< light failure mode, module can not transit from passive to active anymore*/
  HEADModuleQoS_NormalRunning        = 3,           /*!< normal mode, module can be running*/
  
  HEADModuleQoS_Max                  = 4            /*!< number of elements in this enum*/
} eHEADModuleQoS_t;

/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          type for bitfield usage of  @ref eHEADModuleQoS_t
    */
typedef uint8 HEADModuleQoS_t;                      /*!< @values @ref eHEADModuleQoS_t */


/* ****************************************************************
    TYPEDEF ENUM eHEADModuleRepError_t
    **************************************************************** */
/*! @brief          HEAD Module SPM reported error types

    @description    Defines the states of the SPM reported error for an module

    @attention      MUST be sorted from most severe to normal
    */
typedef enum 
{
  HEADModuleRepError_Critical         = 0,          /*!< severe error that should be reported*/
  HEADModuleRepError_Normal           = 1,          /*!< normal error that could be reported*/
  HEADModuleRepError_Silent           = 2,          /*!< error that shouldn't be reported*/
  HEADModuleRepError_NoError          = 3,          /*!< normal mode, nothing should be reported*/
  
  HEADModuleRepError_Max              = 4           /*!<  */
} eHEADModuleRepError_t;

/* ****************************************************************
    TYPEDEF
    **************************************************************** */
/*! @brief          type for bitfield usage of @ref eHEADModuleRepError_t
    */
typedef uint8 HEADModuleRepError_t;                 /*!< @values @ref eHEADModuleRepError_t */

/*declaration of the type...*/
/*! @brief          HEAD Module Name Max Length
                    @typical 13u @unit [SI-unit]
  */
#define HEAD_MODULENAME_LENGTH (24u)

/* ****************************************************************
    STRUCT HEADModule_t
    **************************************************************** */
/*! @brief          HEAD Module Structure
    
    @description    Structure to define HEAD Module 
    */
struct HEADModule_t
{
  /*!@publicsection*/
  uint8                 strModuleName[HEAD_MODULENAME_LENGTH+1u];   /*!< module name*/
  uint8                 uiNumOrGroups;                              /*!< defines the number of orGroups for this module @range @ref HEAD_MAX_OR_GROUPS*/
  uint16                uiHypInOrGroup[HEAD_MAX_OR_GROUPS];         /*!< orGroup array with corresponding hypotheses*/
  eHEADSMState_t        eSMState;                                   /*!< global state machine state @values @ref eHEADSMState_t*/
  eHEADSMState_t        eSMLastState;                               /*!< global state machine last state @values @ref eHEADSMState_t*/
  eHEADModuleQoS_t      eQoS;                                       /*!< defines the states of the QoS for a module @values @ref eHEADModuleQoS_t*/
  eHEADModuleRepError_t eReportedError;                             /*!< defines the reported error for a module @values @ref eHEADModuleRepError_t*/
  float32               fStateTimer[HEADSMState_Max];               /*!< counts the seconds how long the module is in the current state*/
  float32               fNotInStateTimer[HEADSMState_Max];          /*!< counts the seconds how long the module is not in the current state*/
  /*!@privatesection*/
  HEADModuleInternalInterface_t        *pInternal;                  /*!< pointer to internal state information @ ref HEADModuleInternalInterface_t*/
  struct HEADModuleOutputInterface_t   *pOutput;                    /*!< pointer to output interface @ref HEADModuleOutputInterface_t*/
  const void                           *pOutputParams;              /*!< pointer to a output parameter structure (is used by the function defined in pOutput)*/
}; /* typedef already forward declared */

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleList_t
   **************************************************************** */
/*! @brief          HEAD Module List

    @description    This structure has no. of HEAD modules and has a pointer to the array of head modules
    */
typedef struct 
{
  uint8                 uiNrOfModules;                  /*!< defines the nr of HEAD modules*/
  struct HEADModule_t   *rgModules;                     /*!< defines pointer to the array of head modules*/
} HEADModuleList_t;


/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

/*** END OF SINLGE INCLUDE SECTION ******************************************/

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */

#endif /* HEAD_MODULE_DEF_H_INCLUDED */
/**@}*/

