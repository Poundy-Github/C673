/**
 * \file
 *
 * \brief AUTOSAR Crypto
 *
 * This file contains the implementation of the AUTOSAR
 * module Crypto.
 *
 * \version 1.7.47
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CRYPTO_XVIX_XAIX_AL_SHA3_H
#define CRYPTO_XVIX_XAIX_AL_SHA3_H


/*==[Includes]====================================================================================*/

#include <Std_Types.h>
#include <Crypto_xVIx_xAIx_Cfg.h>
#include <Crypto_xVIx_xAIx_AL_Cfg.h>

#if(                                                    \
       (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)    \
   )

/*==[Macros]======================================================================================*/

/*==[Types]=======================================================================================*/

/*==[Constants with external linkage]=============================================================*/

/*==[Variables with external linkage]=============================================================*/

/*==[Declaration of functions with external linkage]==============================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*--SHA3 Common-----------------------------------------------------------------------------------*/

/**  \brief  Crypto SHA3 Reset
 *
 *           This Function resets the Context of SHA3.
 *
 * \Reentrancy{Non-reentrant}
 * \Synchronicity{Synchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset
(
  void
);

/*--SHA3 Helper-----------------------------------------------------------------------------------*/

/*--SHA3 224 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

/** \brief Helper Start Function for SHA3224
 *
 *         This Function provides the SHA3224 Start Function to call from another primitive
 *
 * \param[in]     ObjId                    The Driver object ID
 * \param[in]     Crypto_Generic_Callback  A pointer to the Callback
 * \param[in,out] Job                      A pointer to the processed Job
 * \param[in]     ProcessingType           The processing type for the helper
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
);

/** \brief Helper Update Function for SHA3224
 *
 *         This Function provides the SHA3224 Update Function to call from another primitive
 *
 * \param[in] DataPtr         A pointer to the data
 * \param[in] DataLength      The length of the data
 * \param[in] ProcessingType  The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
);

/** \brief Helper Finish Function for SHA3224
 *
 *         This Function provides the SHA3224 Finish Function to call from another primitive
 *
 * \param[out] ResultPtr          A pointer to where the result is to be stored
 * \param[in]  ResultLengthPtr    A pointer where the length of the result is to be stored
 * \param[in]  ProcessingType     The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
);

/** \brief Helper Main Function for SHA3224
 *
 *         This Function provides the SHA3224 Main Function to call from another primitive
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperMainFunction
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

/** \brief Helper Start Function for SHA3256
 *
 *         This Function provides the SHA3256 Start Function to call from another primitive
 *
 * \param[in]     ObjId                    The Driver object ID
 * \param[in]     Crypto_Generic_Callback  A pointer to the Callback
 * \param[in,out] Job                      A pointer to the processed Job
 * \param[in]     ProcessingType           The processing type for the helper
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
);

/** \brief Helper Update Function for SHA3256
 *
 *         This Function provides the SHA3256 Update Function to call from another primitive
 *
 * \param[in] DataPtr         A pointer to the data
 * \param[in] DataLength      The length of the data
 * \param[in] ProcessingType  The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
);


/** \brief Helper Finish Function for SHA3256
 *
 *         This Function provides the SHA3256 Finish Function to call from another primitive
 *
 * \param[out] ResultPtr          A pointer to where the result is to be stored
 * \param[in]  ResultLengthPtr    A pointer where the length of the result is to be stored
 * \param[in]  ProcessingType     The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
);

/** \brief Helper Main Function for SHA3256
 *
 *         This Function provides the SHA3256 Main Function to call from another primitive
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperMainFunction
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

/** \brief Helper Start Function for SHA3384
 *
 *         This Function provides the SHA3384 Start Function to call from another primitive
 *
 * \param[in]     ObjId                    The Driver object ID
 * \param[in]     Crypto_Generic_Callback  A pointer to the Callback
 * \param[in,out] Job                      A pointer to the processed Job
 * \param[in]     ProcessingType           The processing type for the helper
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
);

/** \brief Helper Update Function for SHA3384
 *
 *         This Function provides the SHA3384 Update Function to call from another primitive
 *
 * \param[in] DataPtr         A pointer to the data
 * \param[in] DataLength      The length of the data
 * \param[in] ProcessingType  The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
);


/** \brief Helper Finish Function for SHA3384
 *
 *         This Function provides the SHA3384 Finish Function to call from another primitive
 *
 * \param[out] ResultPtr          A pointer to where the result is to be stored
 * \param[in]  ResultLengthPtr    A pointer where the length of the result is to be stored
 * \param[in]  ProcessingType     The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
);

/** \brief Helper Main Function for SHA3384
 *
 *         This Function provides the SHA3384 Main Function to call from another primitive
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperMainFunction
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

/** \brief Helper Start Function for SHA3512
 *
 *         This Function provides the SHA3512 Start Function to call from another primitive
 *
 * \param[in]     ObjId                    The Driver object ID
 * \param[in]     Crypto_Generic_Callback  A pointer to the Callback
 * \param[in,out] Job                      A pointer to the processed Job
 * \param[in]     ProcessingType           The processing type for the helper
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
);

/** \brief Helper Update Function for SHA3512
 *
 *         This Function provides the SHA3512 Update Function to call from another primitive
 *
 * \param[in] DataPtr         A pointer to the data
 * \param[in] DataLength      The length of the data
 * \param[in] ProcessingType  The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
);

/** \brief Helper Finish Function for SHA3512
 *
 *         This Function provides the SHA3512 Finish Function to call from another primitive
 *
 * \param[out] ResultPtr          A pointer to where the result is to be stored
 * \param[in]  ResultLengthPtr    A pointer where the length of the result is to be stored
 * \param[in]  ProcessingType     The processing type for the helper
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
);

/** \brief Helper Main Function for SHA3512
 *
 *         This Function provides the SHA3512 Main Function to call from another primitive
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperMainFunction
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

/*--SHA3 224 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

/** \brief AL Start Function for SHA3
 *
 *         This Function provides the SHA3 Start Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If start was successfully requested.
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Update Function for SHA3
 *
 *         This Function provides the SHA3 Update Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Finish Function for SHA3
 *
 *         This Function provides the SHA3 Finish Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Cancel Function for SHA3
 *
 *         This Function provides the SHA3 Cancel Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Result of the cancellation attempt
 * \retval E_OK                   Job was successfully cancelled.
 * \retval E_NOT_OK               Job could not be cancelled.
 * \retval CRYPTO_E_JOB_CANCELED  Job could not be canceled immediately
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Main Function for SHA3
 *
 *         This Function provides the SHA3 Main Function to call from the upper layer
 *
 * \param[out] Result  Pointer where to store the Result of the processing
 * \param[out] Busy    Pointer to where to store if Main Function is busy
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

/** \brief AL Start Function for SHA3
 *
 *         This Function provides the SHA3 Start Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If start was successfully requested.
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Update Function for SHA3
 *
 *         This Function provides the SHA3 Update Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Finish Function for SHA3
 *
 *         This Function provides the SHA3 Finish Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Cancel Function for SHA3
 *
 *         This Function provides the SHA3 Cancel Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Result of the cancellation attempt
 * \retval E_OK                   Job was successfully cancelled.
 * \retval E_NOT_OK               Job could not be cancelled.
 * \retval CRYPTO_E_JOB_CANCELED  Job could not be canceled immediately
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Main Function for SHA3
 *
 *         This Function provides the SHA3 Main Function to call from the upper layer
 *
 * \param[out] Result  Pointer where to store the Result of the processing
 * \param[out] Busy    Pointer to where to store if Main Function is busy
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

/** \brief AL Start Function for SHA3
 *
 *         This Function provides the SHA3 Start Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If start was successfully requested.
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Update Function for SHA3
 *
 *         This Function provides the SHA3 Update Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Finish Function for SHA3
 *
 *         This Function provides the SHA3 Finish Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Cancel Function for SHA3
 *
 *         This Function provides the SHA3 Cancel Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Result of the cancellation attempt
 * \retval E_OK                   Job was successfully cancelled.
 * \retval E_NOT_OK               Job could not be cancelled.
 * \retval CRYPTO_E_JOB_CANCELED  Job could not be canceled immediately
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Main Function for SHA3
 *
 *         This Function provides the SHA3 Main Function to call from the upper layer
 *
 * \param[out] Result  Pointer where to store the Result of the processing
 * \param[out] Busy    Pointer to where to store if Main Function is busy
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

/** \brief AL Start Function for SHA3
 *
 *         This Function provides the SHA3 Start Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If start was successfully requested.
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Update Function for SHA3
 *
 *         This Function provides the SHA3 Update Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Finish Function for SHA3
 *
 *         This Function provides the SHA3 Finish Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Cancel Function for SHA3
 *
 *         This Function provides the SHA3 Cancel Function to call from the upper layer
 *
 * \param[in]     ObjectId  The Driver object ID of the process
 * \param[in,out] Job       The processed Job
 *
 * \returns Result of the cancellation attempt
 * \retval E_OK                   Job was successfully cancelled.
 * \retval E_NOT_OK               Job could not be cancelled.
 * \retval CRYPTO_E_JOB_CANCELED  Job could not be canceled immediately
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
);

/** \brief AL Main Function for SHA3
 *
 *         This Function provides the SHA3 Main Function to call from the upper layer
 *
 * \param[out] Result  Pointer where to store the Result of the processing
 * \param[out] Busy    Pointer to where to store if Main Function is busy
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
extern FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

#define CRYPTO_xVIx_xAIx_STOP_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

#endif /* #if(                                                    \
                 (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)    \
             )
       */

#endif /* CRYPTO_XVIX_XAIX_AL_SHA3_H */

/*==[end of file]=================================================================================*/

