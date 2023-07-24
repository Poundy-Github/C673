/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head20_spm.h

DESCRIPTION:               Header for the signal performance monitor of the HEAD module

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 16:02:08CEST $

VERSION:                   $Revision: 1.19 $

LEGACY VERSION:            1.24.1.1 (HEAD 2.0)
  
**************************************************************************** */

#ifndef HEAD20_SPM_H_INCLUDED
#define HEAD20_SPM_H_INCLUDED

#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)
/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/* PRQA S 3242,3240 EOF *//* Inline warnings to be suppressed */
/*****************************************************************************
  MACROS 
*****************************************************************************/
/*! @brief       Gives bit number for the corresponding HEAD module 

*/
#define HEADSPMGetModuleBit(modulenr) (1uL<<(modulenr))


/*! @brief       Gives the maximum bit number for the HEAD module 

    @general     Gives the maximum bit number for the HEAD module
*/
#define HEADSPMGetAllModuleBits ((1<<HEADModules_Max)-1)


/*! @brief       Sets the bits to define the HEAD module signal for standard deviation    

    @general     Sets the bits to define the HEAD module signal for standard deviation
*/
#define HEADSPMSetBitsStdDeviation(StdDev) ( ((uint32)(StdDev))   & 3u)


/*! @brief       Sets the bits to define how the HEAD module signal to be used by the function     

    @general     Sets the bits to define how the HEAD module signal to be used by the function
*/
#define HEADSPMSetBitsFunction(Function)   ((((uint32)(Function)) & 3u) << 2u)


/*! @brief       Sets the bits to define which operator to use for the HEAD signal operation    

    @general     Sets the bits to define which operator to use for the HEAD signal operation
*/
#define HEADSPMSetBitsOperator(Operator)   ((((uint32)(Operator)) & 7u) << 4u)


/*! @brief       Sets the bits to define whether the signal or its state needs to be checked    

    @general     Sets the bits to define whether the signal or its state needs to be checked    
*/
#define HEADSPMSetBitsSignal(Signal)       ((((uint32)(Signal))   & 1u) << 7u)


/*! @brief       Gets the bits which define the HEAD module signal for standard deviation    

    @general     Gets the bits which define the HEAD module signal for standard deviation
*/
#define HEADSPMGetBitsStdDeviation(bCheckType) ((HEADSPMCheckBitsStdDeviation_t)((bCheckType) & 3u))


/*! @brief       Gets the bits which define how the HEAD module signal to be used by the function     

    @general     Gets the bits which define how the HEAD module signal to be used by the function
*/
#define HEADSPMGetBitsFunction(bCheckType)     ((HEADSPMCheckBitsFunction_t)(((bCheckType) & 12u)>>2u))


/*! @brief       Gets the bits to define which operator to use for the HEAD signal operation    

    @general     Gets the bits to define which operator to use for the HEAD signal operation
*/
#define HEADSPMGetBitsOperator(bCheckType)     ((HEADSPMCheckBitsOp_t)(((bCheckType) & 112u)>>4u))


/*! @brief       Gets the bits which define whether the signal or its state needs to be checked    

    @general     Gets the bits which define whether the signal or its state needs to be checked    
*/
#define HEADSPMGetBitsSignal(bCheckType)       ((HEADSPMCheckBitsSignal_t)(((bCheckType) & 128u)>>7u))

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief Stores all the HEAD SPM check rules

    @general Stores all the HEAD SPM check rules

    */
typedef struct 
{
  uint32           uiNrOfSPMRules;            /*!< total number of HEAD SPM rules */
  HEADSPMCheck_t  *rgSPMRules;                /*!< pointer to the HEAD SPM rules */
} HEADSPMRules_t;

/*****************************************************************************
  GLOBAL CONSTANTS (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES (EXTERNAL SCOPE)
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
/*PRQA S 1055 EOF*/ /*Reviewer: Nagaraja Veerashettappa , Reason: QAC message suppressed for Inline functions */
extern eGDBError_t HEADSPMAddSigCheck(const HEADSPMRules_t *pRules, uint32 uiRuleNr, struct HEADInputValue_t *pSignal,
                                      HEADMTSInSigIdent_t eHEADMTSInSigIdent, eHEADSPMCheckBitsSignal_t eCheckSignal,
                                      eHEADSPMCheckBitsOp_t eCheckOperator, eHEADSPMCheckBitsFunction_t eCheckFunction,
                                      eHEADSPMCheckBitsStdDeviation_t eCheckStdDev, float32 fValue, float32 fNeededTime,
                                      const HEADModuleQoSRel_t * pModuleQoSRel, uint8 uiNumQoSModules);

extern eGDBError_t HEADSPMRunCheck(const HEADSPMRules_t *pRules, const HEADModuleList_t *pModuleList, float32 fCycleTime);

/*!  @cond Doxygen_Suppress */
ALGO_INLINE HEADSPMCheck_t *HEADSPMGetRule(HEADSPMCheck_t rgSPMRules[], uint32 no);
ALGO_INLINE const HEADModuleQoSRel_t *HEADGetQoSModule(const HEADSPMCheck_t *const pSPMRule, const uint32 uiQoSModuleNo);
/*! @endcond */

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/

/*!  @cond Doxygen_Suppress */
ALGO_INLINE HEADSPMCheck_t *HEADSPMGetRule(HEADSPMCheck_t rgSPMRules[], uint32 no) /*PRQA S 3406 */ /*QAC message suppressed for Inline function */
{
    return &(rgSPMRules[no]); 
}


ALGO_INLINE const HEADModuleQoSRel_t *HEADGetQoSModule(const HEADSPMCheck_t *const pSPMRule, const uint32 uiQoSModuleNo)/*PRQA S 3406 */ /*QAC message suppressed for Inline function */
{
  const HEADModuleQoSRel_t *retPointer = NULL;

  if(pSPMRule->pModuleQoSRel != NULL)
  {
    if (uiQoSModuleNo < pSPMRule->uiNumQoSModules)
    {
      retPointer = &(pSPMRule->pModuleQoSRel[uiQoSModuleNo]); /*PRQA S 0491*//*array of known length*/
    }
  }

  return retPointer;
}

/*! @endcond */

#endif /* MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION */
#endif /* HEAD20_SPM_H_INCLUDED */

