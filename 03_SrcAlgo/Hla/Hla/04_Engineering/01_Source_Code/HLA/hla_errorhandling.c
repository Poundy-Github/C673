/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_errorhandling.c
 
  DESCRIPTION:            Error handling stuff like error stack, error handler,
                          error types, etc.
 
  CREATION DATE:          2016-08-09
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.10 $
*************************************************************************** */

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include <string.h>
#include "hla_defs.h" 
#include "hla_errorhandling.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/

/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
static t_ErrorHandling_ErrorStack errorStack;    ///< \brief global error stack used for error handling
static AlgoCycleCounter_t softErrorMeasCnt = 0u; ///< \brief counter of soft error state

/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/
#ifdef _TASKING_C_TRICORE_
static inline void HLA_ErrorHandling_SetBit( const uint8        bit, 
                                                     uint8* const pCounter,
                                                     uint32 array[]
                                              );
#else
static __inline void HLA_ErrorHandling_SetBit( const uint8        bit, 
                                                     uint8* const pCounter,
                                                     uint32 array[]
                                              );
#endif

/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/
/* *******************************************************************************
  Internal error stack is initialized
******************************************************************************** */
void HLA_ErrorHandling_Init(void)
{
  /* Reset error stack */
  /* PRQA S 0315 1 # 2019-05-06 A.Manz: Implicit conversion intended, only way how this is working */
  (void)memset( &errorStack, 0, sizeof(errorStack));

  /* Set 32-bit hashes representing all elements of each enum */
  errorStack.hashErrors      = HLA_ERROR_HASH_ERRORS;
  errorStack.hashWarnings    = HLA_ERROR_HASH_WARNINGS;
  errorStack.hashInformation = HLA_ERROR_HASH_INFORMATION;
}

/* *******************************************************************************
  Error bit is set in error array of error stack
******************************************************************************** */
void HLA_ErrorHandling_SetError(const e_ErrorHandling_Errors errorBit)
{
  HLA_ErrorHandling_SetBit( (uint8)errorBit, 
                            &errorStack.numErrors,
                            &errorStack.errors[0]
                           );
}

/* *******************************************************************************
  Checks whether errorBit is set in error array of error stack
******************************************************************************** */
boolean HLA_ErrorHandling_GetError(const e_ErrorHandling_Errors errorBit)
{
  /* Right shift by 5 is equal to integer division by 32, 
   * i.e. we can extract which bit field is affected .
   * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
   */
  /* <ArrayOOBCheck> 2016-08-19 # 2019-05-28 M.Mutschler: type of errorBit is coupled to error array */
  const boolean bErrorSet = (CML_GetBit(errorStack.errors[(uint32)errorBit >> 5u], (uint32)1u << ((uint32)errorBit & 31u)) == b_TRUE);  

  return bErrorSet;
}

/* *******************************************************************************
  Warning bit is set in warning array of error stack
******************************************************************************** */
void HLA_ErrorHandling_SetWarning(const e_ErrorHandling_Warnings warningBit)
{
  HLA_ErrorHandling_SetBit( (uint8)warningBit, 
                            &errorStack.numWarnings,
                            &errorStack.warnings[0]
                           );
}

/* *******************************************************************************
  Checks whether warningBit is set in error array of error stack
******************************************************************************** */
boolean HLA_ErrorHandling_GetWarning(const e_ErrorHandling_Warnings warningBit)
{
  /* Right shift by 5 is equal to integer division by 32, 
   * i.e. we can extract which bit field is affected .
   * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
   */
  /* <ArrayOOBCheck> 2016-08-19 # 2019-05-28 M.Mutschler: type of warningBit is coupled to error array */
  const boolean bWarningSet = (CML_GetBit(errorStack.warnings[(uint32)warningBit >> 5u], (uint32)1u << ((uint32)warningBit & 31u)) == b_TRUE);  

  return bWarningSet;
}

/* *******************************************************************************
  Information bit is set in information array of error stack
******************************************************************************** */
void HLA_ErrorHandling_SetInformation(const e_ErrorHandling_Information informationBit)
{
  HLA_ErrorHandling_SetBit( (uint8)informationBit, 
                            &errorStack.numInformation,
                            &errorStack.information[0]
                           );
}


/* *******************************************************************************
  Checks whether informationBit is set in error array of error stack
******************************************************************************** */
boolean HLA_ErrorHandling_GetInformation(const e_ErrorHandling_Information informationBit)
{
  /* Right shift by 5 is equal to integer division by 32, 
   * i.e. we can extract which bit field is affected .
   * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
   */
  /* <ArrayOOBCheck> 2016-08-19 # 2019-05-28 M.Mutschler: type of informationBit is coupled to error array */
  const boolean bInformationSet = (CML_GetBit(errorStack.information[(uint32)informationBit >> 5u], (uint32)1u << ((uint32)informationBit & 31u)) == b_TRUE);  

  return bInformationSet;
}

/* *******************************************************************************
  Since we increase number of errors each time a new one is set we can simply
  return number of errors, i.e. set bits in error array.
******************************************************************************** */
uint8 HLA_ErrorHandling_GetNumErrors(void)
{
  return errorStack.numErrors;
}

/* *******************************************************************************
  Since we increase number of warnings each time a new one is set we can simply
  return number of warnings, i.e. set bits in warnings array.
******************************************************************************** */
uint8 HLA_ErrorHandling_GetNumWarnings(void)
{
  return errorStack.numWarnings;
}

/* *******************************************************************************
  Since we increase number of information each time a new one is set we can simply
  return number of information, i.e. set bits in information array.
******************************************************************************** */
uint8 HLA_ErrorHandling_GetNumInformation(void)
{
  return errorStack.numInformation;
}

/* *******************************************************************************
  Simply returns constant pointer to error stack needed for measfreeze.
******************************************************************************** */
const t_ErrorHandling_ErrorStack* HLA_ErrorHandling_GetErrorStack(void)
{
  return &errorStack;
}

/* *******************************************************************************
  Store measurement counter from which soft error state persists.
  If measCnt is zero soft error state is left.
******************************************************************************** */
void HLA_ErrorHandling_SetSoftErrorState(const AlgoCycleCounter_t measCnt)
{
  softErrorMeasCnt = measCnt;
}

/* *******************************************************************************
  Returns measurement counter when soft error state was entered.
  If errorStack.softErrorMeasCnt is zero it means that we are currently not in a
  soft error state.
******************************************************************************** */
AlgoCycleCounter_t HLA_ErrorHandling_GetSoftErrorState(void)
{
  return softErrorMeasCnt;
}

/* *******************************************************************************
  servicesReturnValue  Return code of algo service function
******************************************************************************** */
void HLA_ErrorHandling_SetServicesReturnValue(const uint32 servicesReturnValue)
{
  errorStack.serviceFunctRetValue = servicesReturnValue;
}

/* *******************************************************************************
  Returns stored return code of algo service function.
******************************************************************************** */
uint32 HLA_ErrorHandling_GetServicesReturnValue(void)
{
  return errorStack.serviceFunctRetValue;
}

/* *******************************************************************************
  Stores bus signal state flag of corresponding vdy signals 
******************************************************************************** */
void HLA_ErrorHandling_SetBusSigState( const VDYIoStateTypes_t stateFlag, 
                                       const ptrdiff_t         structOffset
                                      )
{
  errorStack.busSigStateFlag   = stateFlag;
  /* Offset should be small enough to fit into 16-bit integer */
  errorStack.busSigStateOffset = (uint16)structOffset;
}

/* *******************************************************************************
  Returns bus signal state flag of corresponding vdy signals 
******************************************************************************** */
uint8 HLA_ErrorHandling_GetBusSigStateFlag(void)
{
  return errorStack.busSigStateFlag;
}

/* *******************************************************************************
  Returns bus signal state offset of corresponding vdy signals 
******************************************************************************** */
uint16 HLA_ErrorHandling_GetBusSigStateOffset(void)
{
  return errorStack.busSigStateOffset;
}

/* *******************************************************************************
  Adds numBytes to internal counter of measfreezed bytes of this cycle.
******************************************************************************** */
void HLA_ErrorHandling_AddMeasfreezeAmount(const uint32 numBytes)
{
  errorStack.measfreezeAmount += numBytes;
}

/****************************************************************************
* LOCAL FUNCTIONS DEFINTION
*****************************************************************************/
/* *******************************************************************************
  Bit is set in corresponding array of error stack
******************************************************************************** */
#ifdef _TASKING_C_TRICORE_
static inline void HLA_ErrorHandling_SetBit( const uint8        bit, 
                                                     uint8* const pCounter,
                                                     uint32 array[]
                                              )
#else
static __inline void HLA_ErrorHandling_SetBit( const uint8        bit, 
                                                     uint8* const pCounter,
                                                     uint32 array[]
                                              )
#endif
{
  /* Right shift by 5 is equal to integer division by 32, 
   * i.e. we can extract which bit field is affected .
   * Bit-wise AND of 31 (0x1F) extracts which bit shall be set 
   */
  const uint8  arrayIndex = bit >> 5u;
  const uint32 bitToSet   = (uint32)1u << (bit & (uint32)31u);

  /* <ArrayOOBCheck> 2016-08-19 # 2019-05-28 M.Mutschler: HLA_ErrorHandling_SetBit() is called with 
   *                                               "bit" and "array" are of compatible types 
   */
  if(CML_GetBit(array[arrayIndex], bitToSet) == b_FALSE)
  {
    /* Set bit as it wasn't set already. */
    CML_SetBit(array[arrayIndex], bitToSet);
    (*pCounter)++;
  }
}
