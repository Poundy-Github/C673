/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_module_def.h

DESCRIPTION:               Header of the HEAD component - for module definition

AUTHOR:                    $Author: H U, Minuthi (uia80216) (uia80216) $

CREATION DATE:             $Date: 2020/08/26 14:06:16CEST $

VERSION:                   $Revision: 1.19 $

LEGACY VERSION:            1.25.1.1 (HEAD 2.0)
  
**************************************************************************** */

#ifndef HEAD20_MODULE_DEF_H_INCLUDED
#define HEAD20_MODULE_DEF_H_INCLUDED


#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ================== MODULES =========================*/

/* forward declaration of the type...*/
/*!  @cond Doxygen_Suppress */
typedef struct HEADModule_t HEADModule_t;
typedef struct HEADModuleList_t HEADModuleList_t;

#if HEAD_CFG_PRECONDITION == MEDIC_ON
typedef struct HEADPreConditionList_t HEADPreConditionList_t;
#endif
/*! @endcond */

/* ****************************************************************
    TYPEDEF STRUCT HEADInputData_t
    **************************************************************** */
/*! @brief HEAD Input Data
    
    @general HEAD Input Data
    
    @conseq [None]
    
    @attention [None]
    
    */
typedef struct HEADInputData_t HEADInputData_t;

/* Prototype for state machine handling function such as HEADGenericStateMachine */
/*!  @cond Doxygen_Suppress */
typedef eGDBError_t HEADModuleCustomFunction_ft(uint8 uiModuleNr, const struct HEADInputData_t*pInputData, boolean bInit);

typedef uint8 HEADHypothesisNr_t;

typedef uint32 HEADBitField_t;
/*! @endcond */

/*! @brief       HEADNoHypothesis
    @general     HEADNoHypothesis
    @typical     255
    @unit        SI-unit 
    */
#define HEADNoHypothesis          ((HEADHypothesisNr_t)255)
/*! @brief       HEADHypothesisIndependent
    @general     HEADHypothesisIndependent
    @typical     HEAD_MAX_NUMBER_OF_CD_HYPS
    @unit        SI-unit 
    */
#define HEADHypothesisIndependent ((HEADHypothesisNr_t)HEAD_MAX_NUMBER_OF_CD_HYPS)


/*! define the module internal structure (only the interface (empty structure with header ))*/

/* ****************************************************************
    TYPEDEF ENUM eHEADModuleInternalType_t
    **************************************************************** */
/*! @brief HEAD Module Internal Types

    @general This enum defines different types of State Machine in HEAD Module
   
    @conseq [None]
    
    @attention [None]

    */
typedef enum 
{
  HEADModuleInternalType_GSM     = 0,                  /*!< Module uses generic state machine (head_generic_sm.c/head_generic_sm.h)*/
  HEADModuleInternalType_Custom  = 1,                  /*!< Module uses custom state machine (????.c/h)*/
  HEADModuleInternalType_Max     = 2
} eHEADModuleInternalType_t;

typedef uint8 HEADModuleInternalType_t;                /*!< @values: eHEADModuleInternalType_t */

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalHeader_t
    **************************************************************** */
/*! @brief HEAD Module Internal State Machine Type and Function Handler

    @general This structure defines the type of HEAD SM and its handling function

    @conseq Changing internal type will change type of SM that head machine use

    @attention [None]

    */
typedef struct 
{
  eHEADModuleInternalType_t   eModuleInternalType;     /*!< eModuleInternalType*/
  HEADModuleCustomFunction_ft *fpCustom;               /*!< function pointer to the state machine handling function*/
} HEADModuleInternalHeader_t;

/* ****************************************************************
    TYPEDEF STRUCT HEADModuleInternalInterface_t
    **************************************************************** */
/*! @brief Abstract ModuleInternal interface

    @general Abstract ModuleInternal interface - define your own for work

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  HEADModuleInternalHeader_t InternalHeader;  /*!< InternalHeader*/
  /*noting else here... but in the specific implementation*/
} HEADModuleInternalInterface_t;


/* ****************************************************************
  STRUCT HEADModuleQoSRel_t
  **************************************************************** */
/*! @brief HEAD Module QoS relation structure

    @general HEAD Module QoS relation structure

    @conseq [None]

    @attention [None]

    */
typedef struct 
{
  uint8                  uiModuleNr;
  HEADModuleQoS_t        eModuleQoS;
  HEADModuleRepError_t   eReportedError;
} HEADModuleQoSRel_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief       HEAD_MODULENAME_LENGTH
    @general     HEAD_MODULENAME_LENGTH
    @typical     24u
    @unit        SI-unit
  */
#define HEAD_MODULENAME_LENGTH    (24u)

/*! @brief       HEAD_PRECONDNAME_LENGTH
    @general     HEAD_PRECONDNAME_LENGTH
    @typical     31u
    @unit        SI-unit
  */

#define HEAD_PRECONDNAME_LENGTH    (31u)

/*! @brief       HEAD_STATENAME_LENGTH
    @general     HEAD_STATENAME_LENGTH
    @typical     17u
    @unit        SI-unit
  */
#define HEAD_STATENAME_LENGTH      (17u)

/*! @brief       HEAD_DGSMSTATENAME_LENGTH
    @general     HEAD_DGSMSTATENAME_LENGTH
    @typical     30u
    @unit        SI-unit
  */
#define HEAD_DGSMSTATENAME_LENGTH  (30u)

/*declaration of the type...*/
/*! @brief       HEAD_QOSNAME_LENGTH
    @general     HEAD_QOSNAME_LENGTH
    @typical     20u
    @unit        SI-unit
  */
#define HEAD_QOSNAME_LENGTH        (20u)

/*declaration of the type...*/
/*! @brief       HEAD_SPMNAME_LENGTH
    @general     HEAD_SPMNAME_LENGTH
    @typical     40u
    @unit        SI-unit
  */
#define HEAD_SPMNAME_LENGTH        (40u)

/*declaration of the type...*/
/*! @brief       HEAD_REPERRNAME_LENGTH
    @general     HEAD_REPERRNAME_LENGTH
    @typical     9u
    @unit        SI-unit
  */
#define HEAD_REPERRNAME_LENGTH     (9u)

/*! @brief       Maximum Head Modules Count
    @general     Maximum number of HEAD Modules allowed
    @conseq      @incp  FCT function will be able to handle one more HEAD Module
                 @decp  FCT function will be able to handle one less HEAD Module
    @attention   [None]
    @typical     31u
    @unit        Count     
*/
#define HEADModules_Max            (31u)

SET_MEMSEC_VAR(HEADModule_t)

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES (EXTERNAL SCOPE)
*****************************************************************************/

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_MODULE_DEF_H_INCLUDED */

