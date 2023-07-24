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

/*==[deviations]==================================================================================*/

/* tasking Deviation List
 *
 * TASKING-1) Deviated Rule: W560
 * W560: possible truncation at implicit conversion to type "unsigned char"
 *
 * Reason:
 * The minimum value needed for offset.
 * The value will not exceed 255.
 */

/*==[Includes]====================================================================================*/

#include <Std_Types.h>
#include <TSAutosar.h>
#include <Csm_Types.h>
#include <CryIf_Cbk.h>
#include <SchM_Crypto_xVIx_xAIx.h>
#include <TSMem.h>

#include <Crypto_xVIx_xAIx.h>
#include <Crypto_xVIx_xAIx_AL_SHA3.h>
#include <Crypto_xVIx_xAIx_AL_Common.h>
#include <Crypto_xVIx_xAIx_AL_Cfg.h>

#if(                                                    \
       (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)    \
    || (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)    \
   )

/*==[Macros]======================================================================================*/

#if (defined CRYPTO_XVIX_XAIX_SHA3_DEFAULT_CURRENT_MODE)
#error CRYPTO_XVIX_XAIX_SHA3_DEFAULT_CURRENT_MODE is already defined
#endif
/** \brief To set the default current mode */
#define CRYPTO_XVIX_XAIX_SHA3_DEFAULT_CURRENT_MODE 0x00U

#if (defined CRYPTO_XVIX_XAIX_SM_SHA3_TRANSITION_COUNT)
#error CRYPTO_XVIX_XAIX_SM_SHA3_TRANSITION_COUNT is already defined
#endif
/** \brief Number of transitions in HASH SHA3. */
#define CRYPTO_XVIX_XAIX_SM_SHA3_TRANSITION_COUNT 7U

#if (defined CRYPTO_XVIX_XAIX_SM_SHA3_ACTION_COUNT)
#error CRYPTO_XVIX_XAIX_SM_SHA3_ACTION_COUNT is already defined
#endif
/** \brief Number of action functions in HASH SHA3. */
#define CRYPTO_XVIX_XAIX_SM_SHA3_ACTION_COUNT 8U

#if (defined CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS)
#error CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS is already defined
#endif
/** \brief Number of rounds of SHA3 permutation */
#define CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS 24U

#if (defined CRYPTO_XVIX_XAIX_SHA3_STATE_SIZE)
#error CRYPTO_XVIX_XAIX_SHA3_STATE_SIZE is already defined
#endif
/** \brief Size of SHA3 internal state */
#define CRYPTO_XVIX_XAIX_SHA3_STATE_SIZE 25U

#if (defined CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_1)
#error CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_1 is already defined
#endif
/** \brief SHA-3 the first padding byte */
#define CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_1 0x06U

#if (defined CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_2)
#error CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_2 is already defined
#endif
/** \brief SHA-3 the second padding byte */
#define CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_2 0x80U

#if (defined CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX)
#error CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX is already defined
#endif
/** \brief The index for the x coordinate of the state array */
#define CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX 5U

#if (defined CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX)
#error CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX is already defined
#endif
/** \brief The index for the y coordinate of the state array */
#define CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX 5U

#if (defined CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX)
#error CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX is already defined
#endif
/** \brief The index for the z coordinate of the state array */
#define CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX 64U

#if (defined CRYPTO_XVIX_XAIX_ROL64)
#error CRYPTO_XVIX_XAIX_ROL64 is already defined
#endif
/** \brief Rotate a 64-bit type a by a given amount of offset bits to the left **/
#define CRYPTO_XVIX_XAIX_ROL64(a, offset)                                          \
  (                                                                                \
     (((uint64) (a)) << ((offset) % CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX)        )  \
   | (((uint64) (a)) >> (64U - ((offset) % CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX)))  \
  )

#if (defined CRYPTO_XVIX_XAIX_CONV_TO_STATE)
#error CRYPTO_XVIX_XAIX_CONV_TO_STATE is already defined
#endif
/** \brief Converting String to State Array **/
#define CRYPTO_XVIX_XAIX_CONV_TO_STATE(x, y) ((x) + 5U * (y))

#if (defined CRYPTO_XVIX_XAIX_READ_LANE)
#error CRYPTO_XVIX_XAIX_READ_LANE is already defined
#endif
/** \brief Load a 64-bit value **/
#define CRYPTO_XVIX_XAIX_READ_LANE(x, y, array) ((array)[CRYPTO_XVIX_XAIX_CONV_TO_STATE(x, y)])

#if (defined CRYPTO_XVIX_XAIX_WRITE_LANE)
#error CRYPTO_XVIX_XAIX_WRITE_LANE is already defined
#endif
/** \brief Store a 64-bit value **/
#define CRYPTO_XVIX_XAIX_WRITE_LANE(x, y, array, lane) ((array)[CRYPTO_XVIX_XAIX_CONV_TO_STATE(x, y)]) = (lane)

#if (defined CRYPTO_XVIX_XAIX_XOR_LANE)
#error CRYPTO_XVIX_XAIX_XOR_LANE is already defined
#endif
/** \brief XOR into a 64-bit value **/
#define CRYPTO_XVIX_XAIX_XOR_LANE(x, y, array, lane) ((array)[CRYPTO_XVIX_XAIX_CONV_TO_STATE(x, y)]) ^= (lane)

/*--SHA3 224 -------------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

#if (defined CRYPTO_XVIX_XAIX_SHA3_224_HASH_LEN_BYTES)
#error CRYPTO_XVIX_XAIX_SHA3_224_HASH_LEN_BYTES is already defined
#endif
/** \brief The length of a message digest computed with the SHA3-224 algorithm in bytes.*/
#define CRYPTO_XVIX_XAIX_SHA3_224_HASH_LEN_BYTES 28U

#if (defined CRYPTO_XVIX_XAIX_SHA3_224_BLOCK_SIZE)
#error CRYPTO_XVIX_XAIX_SHA3_224_BLOCK_SIZE is already defined
#endif
/** \brief Hash rate length in bytes */
#define CRYPTO_XVIX_XAIX_SHA3_224_BLOCK_SIZE 144U

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 -------------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

#if (defined CRYPTO_XVIX_XAIX_SHA3_256_HASH_LEN_BYTES)
#error CRYPTO_XVIX_XAIX_SHA3_256_HASH_LEN_BYTES is already defined
#endif
/** \brief The length of a message digest computed with the SHA3-256 algorithm in bytes.*/
#define CRYPTO_XVIX_XAIX_SHA3_256_HASH_LEN_BYTES 32U

#if (defined CRYPTO_XVIX_XAIX_SHA3_256_BLOCK_SIZE)
#error CRYPTO_XVIX_XAIX_SHA3_256_BLOCK_SIZE is already defined
#endif
/** \brief Hash rate length in bytes */
#define CRYPTO_XVIX_XAIX_SHA3_256_BLOCK_SIZE 136U

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 -------------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

#if (defined CRYPTO_XVIX_XAIX_SHA3_384_HASH_LEN_BYTES)
#error CRYPTO_XVIX_XAIX_SHA3_384_HASH_LEN_BYTES is already defined
#endif
/** \brief The length of a message digest computed with the SHA3-384 algorithm in bytes.*/
#define CRYPTO_XVIX_XAIX_SHA3_384_HASH_LEN_BYTES 48U

#if (defined CRYPTO_XVIX_XAIX_SHA3_384_BLOCK_SIZE)
#error CRYPTO_XVIX_XAIX_SHA3_384_BLOCK_SIZE is already defined
#endif
/** \brief Hash rate length in bytes */
#define CRYPTO_XVIX_XAIX_SHA3_384_BLOCK_SIZE 104U

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 -------------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

#if (defined CRYPTO_XVIX_XAIX_SHA3_512_HASH_LEN_BYTES)
#error CRYPTO_XVIX_XAIX_SHA3_512_HASH_LEN_BYTES is already defined
#endif
/** \brief The length of a message digest computed with the SHA3-512 algorithm in bytes.*/
#define CRYPTO_XVIX_XAIX_SHA3_512_HASH_LEN_BYTES 64U

#if (defined CRYPTO_XVIX_XAIX_SHA3_512_BLOCK_SIZE)
#error CRYPTO_XVIX_XAIX_SHA3_512_BLOCK_SIZE is already defined
#endif
/** \brief Hash rate length in bytes */
#define CRYPTO_XVIX_XAIX_SHA3_512_BLOCK_SIZE 72U

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

/*--HASH SHA3 States------------------------------------------------------------------------------*/

#if (defined CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB)
#error CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB is already defined
#endif
/** \brief The state for absorbing the input blocks */
#define CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB 5U

#if (defined CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING)
#error CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING is already defined
#endif
/** \brief The state for padding and switching to the squeezing phase */
#define CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING 6U

#if (defined CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE)
#error CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE is already defined
#endif
/** \brief The state for extracting data from the squeezing phase */
#define CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE 7U

/*==[Types]=======================================================================================*/

/** \brief The internal states of the SHA3 computation */
typedef uint8 Crypto_xVIx_xAIx_SHA3StateType;

/** \brief The Keccak lane type */
typedef uint64 Crypto_xVIx_xAIx_KeccakLaneType;

/**
 * \brief The context of the SHA3 hash
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::HashState
 * \brief An Array that is repeatedly updated within a computational procedure
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::DataLength
 * \brief Length of the input data in bytes
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::DataLengthIn
 * \brief Length of the data in bytes, which shall be proccessed
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::HashLength
 * \brief The length of the Hash algorithm
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::ObjId
 * \brief The Driver object ID
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::ResultLengthPtr
 * \brief Pointer to a variable which contains the maximal Result length and
 *        where the length of the result will be stored
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::Offset
 * \brief Number of bytes to process at a time
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::BlockSize
 * \brief Length of a block, which is processed
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::Data
 * \brief Pointer to the input data
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::Result
 * \brief Pointer to the memory location in which to store the result
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::CancelFlag
 * \brief This Flag indicates if processing shall be canceled.
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::CallbackFlag
 * \brief This Flag indicates if a callback shall be called.
 *
 * \brief Crypto_xVIx_xAIx_SHA3CtxType::ProcessDone
 * \var The Flag indicates if the process are done.
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::IsBusy
 * \brief MainFunction is busy
 *
 * \brief Crypto_xVIx_xAIx_SHA3CtxType::CallbackResult
 * \var The value in this variable will be forwarded to the callback.
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::CurrentMode
 * \brief The current processing mode
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::State
 * \brief The current state of the hash computation
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::ResultError
 * \brief Error value of MainFunction
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::Job
 * \brief The processed job
 *
 * \var Crypto_xVIx_xAIx_SHA3CtxType::Crypto_Generic_Callback
 * \brief The pointer to the callback function
 *
 */
typedef struct
{
  uint64                                                           HashState[CRYPTO_XVIX_XAIX_SHA3_STATE_SIZE];

  uint32                                                           DataLength;
  uint32                                                           DataLengthIn;
  uint32                                                           HashLength;
  uint32                                                           ObjId;
  P2VAR(uint32, TYPEDEF, CRYPTO_xVIx_xAIx_APPL_DATA)               ResultLengthPtr;

  uint8                                                            Offset;
  uint8                                                            BlockSize;

  P2CONST(uint8, TYPEDEF, CRYPTO_xVIx_xAIx_APPL_DATA)              Data;
  P2VAR(uint8,  TYPEDEF, CRYPTO_xVIx_xAIx_APPL_DATA)               Result;

  boolean                                                          CancelFlag;
  boolean                                                          CallbackFlag;
  boolean                                                          ProcessDone;
  P2VAR(boolean, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)            IsBusy;

  Std_ReturnType                                                   CallbackResult;
  Crypto_OperationModeType                                         CurrentMode;
  Crypto_xVIx_xAIx_SHA3StateType                                   State;

  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)     ResultError;
  P2VAR(Crypto_JobType, TYPEDEF,   CRYPTO_xVIx_xAIx_APPL_DATA)     Job;

  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE, Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)   Job,
    uint8                                                          Error
  );
}
Crypto_xVIx_xAIx_SHA3CtxType;

/*==[Declaration of functions with internal linkage]==============================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*--SHA3 224 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

/** \brief Call HashMain Synchron
 *
 *         This function calls the HashMainFunction inside the StartCall. The calling Task is
 *         blocked until the Hash is produced.
 *
 * \returns If Main is finished or not
 * \retval  TRUE   finished
 * \retval  FALSE  Not finished
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous}
 */
static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperSynchronousMainCall
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

/** \brief Call HashMain Synchron
 *
 *         This function calls the HashMainFunction inside the StartCall. The calling Task is
 *         blocked until the Hash is produced.
 *
 * \returns If Main is finished or not
 * \retval  TRUE   finished
 * \retval  FALSE  Not finished
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous}
 */
static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperSynchronousMainCall
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

/** \brief Call HashMain Synchron
 *
 *         This function calls the HashMainFunction inside the StartCall. The calling Task is
 *         blocked until the Hash is produced.
 *
 * \returns If Main is finished or not
 * \retval  TRUE   finished
 * \retval  FALSE  Not finished
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous}
 */
static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperSynchronousMainCall
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

/** \brief Call HashMain Synchron
 *
 *         This function calls the HashMainFunction inside the StartCall. The calling Task is
 *         blocked until the Hash is produced.
 *
 * \returns If Main is finished or not
 * \retval  TRUE   finished
 * \retval  FALSE  Not finished
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous}
 */
static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperSynchronousMainCall
(
  void
);

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

/*--SHA3 Common-----------------------------------------------------------------------------------*/

/** \brief Update SHA3 computation.
 *
 *         This function requests the update of the SHA computation for the
 *         given data. The update is performed in Crypto_xVIx_xAIx_SHA3MainFunction().
 *
 * \param[in] DataPtr     A pointer to the start of an array which contains a part of the
 *                        data for which the SHA digest should be created.
 * \param[in] DataLength  The amount of bytes of data
 *
 * \returns  Error code
 * \retval E_OK           If the update was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Update
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) DataPtr,
          uint32                                        DataLength
);

/** \brief Finish SHA3 computation
 *
 *         This function requests the finishing of the SHA computation and
 *         the storing of the hash digest in the given result buffer. The finishing
 *         is performed in Crypto_xVIx_xAIx_SHA3MainFunction().
 *
 * \param[out]    ResultPtr           A pointer to the start of a buffer
 *                                    where the hash digest should be stored
 * \param[in,out] ResultLengthPtr     A pointer to a variable which contains the maximal allowed
 *                                    length in bytes for the hash and where the actual length in
 *                                    bytes of the hash should be stored
 *
 * \returns Error code
 * \retval E_OK           If the finish was successfully requested.
 * \retval CRYPTO_E_BUSY  If the main function is processing a requested service at the moment
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Finish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  ResultLengthPtr
);

/** \brief This is the internal Cancel-Function for SHA3
 *
 * This function actually performs the request for service HASH with algorithm family SHA3.
 * It cancels the Job and removes it from the queue.
 *
 * \returns  void
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Cancel
(
  void
);

/** \brief Sponge absorb operation
 *
 *         Absorb the input blocks
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongeAbsorb
(
  void
);

/** \brief Finish absorbing phase
 *
 *         Do the padding and switch to the squeezing phase
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongePadding
(
  void
);

/** \brief Sponge squeeze operation
 *
 *         Extract data from the squeezing phase
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongeSqueeze
(
  void
);

/** \brief Block permutation
 *
 *         Function that computes the Keccak-f[1600] permutation on the given state.
 *
 * \param[in,out] HashState The current state of the hash computation
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_KeccakF1600_StatePermute
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
);

/** \brief Theta step according Keccak Reference, Section 2.3.2
 *
 *         Function adds to each bit a[x][y][z] the bitwise sum of the parities of
 *         two columns: that of a[x - 1][.][z] and that of a[x + 1][.][z - 1]
 *
 * \param[in,out] HashState The current state of the hash computation
 *
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Theta
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
);

/** \brief Rho and Pi steps according Keccak Reference, Sections 2.3.3 and 2.3.4
 *
 *         The mapping Pi is a transposition of the lanes that provides dispersion aimed at
 *         longterm diffusion. The mapping Rho consists of translations within the lanes
 *         aimed at providing interslice dispersion.
 *
 * \param[in,out] HashState The current state of the hash computation
 *
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Rho_And_Pi
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
);

/** \brief Chi step according Keccak Reference, Section 2.3.1
 *
 *         The effect of Chi is to XOR each bit with a non-linear function of two other
 *         bits in its row. Chi is the only nonlinear mapping in Keccak-f.
 *         Without it, the Keccak-f round function would be linear.
 *
 * \param[in,out] HashState The current state of the hash computation
 *
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Chi
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
);

/** \brief Iota step according Keccak Reference, Section 2.3.5
 *
 *         The mapping Iota consists of the addition of round constants and is
 *         aimed at disrupting symmetry.
 *
 * \param[in,out] HashState The current state of the hash computation
 * \param[in]     Index     The round index
 *
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Iota
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState,
        uint8                                          Index
);

/** \brief Perform the SHA3 tasks
 *
 *         This function performs the actual SHA computation tasks which
 *         have been requested by the service functions. When a task has finished, the
 *         function CRYPTO_HashServiceCallbackNotification() is called to
 *         inform the CRYPTO of the resultError. If the complete SHA3 computation has
 *         finished, additionally the function CRYPTO_HashServiceFinishNotification() is
 *         called.
 *
 * \param[out] ResultError  A pointer to store the result
 * \param[out] Busy         A pointer to store if the Main Function is busy
 *
 * \Reentrancy {Nonreentrant}
 * \Synchronicity {Synchronous/Asynchronous}
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultError,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
);

/** \brief AL Callback for other primitives
 *
 *         This function is a callback function for other primitives
 *
 * \param[in,out] Job      A pointer to the current Job
 * \param[in]     Result   The Result of the process
 *
 * \Reentrancy Nonreentrant
 * \Synchronicity Synchronous/Asynchronous
 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack
(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        uint8                                                  Result
);

#define CRYPTO_xVIx_xAIx_STOP_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*==[Constants with internal linkage]=============================================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_CONST_UNSPECIFIED
#include <Crypto_xVIx_xAIx_MemMap.h>

/* !LINKSTO EB_Crypto_CryptAlgos_1734,1 */
/** \brief SHA3 (Keccak) constants for 24 rounds.
 *
 *  This is the constant padding block used for the SHA3 last block.
 */
static CONST(uint64, CRYPTO_xVIx_xAIx_CONST) Crypto_xVIx_xAIx_KeccakF_RoundConstants[CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS] =
{
  (uint64)0x0000000000000001ULL, (uint64)0x0000000000008082ULL,
  (uint64)0x800000000000808AULL, (uint64)0x8000000080008000ULL,
  (uint64)0x000000000000808BULL, (uint64)0x0000000080000001ULL,
  (uint64)0x8000000080008081ULL, (uint64)0x8000000000008009ULL,
  (uint64)0x000000000000008AULL, (uint64)0x0000000000000088ULL,
  (uint64)0x0000000080008009ULL, (uint64)0x000000008000000AULL,
  (uint64)0x000000008000808BULL, (uint64)0x800000000000008BULL,
  (uint64)0x8000000000008089ULL, (uint64)0x8000000000008003ULL,
  (uint64)0x8000000000008002ULL, (uint64)0x8000000000000080ULL,
  (uint64)0x000000000000800AULL, (uint64)0x800000008000000AULL,
  (uint64)0x8000000080008081ULL, (uint64)0x8000000000008080ULL,
  (uint64)0x0000000080000001ULL, (uint64)0x8000000080008008ULL
};

static CONST(Crypto_xVIx_xAIx_StateTransitionType, CRYPTO_xVIx_xAIx_CONST)
  Crypto_xVIx_xAIx_StateTrans_SHA3[CRYPTO_XVIX_XAIX_SM_SHA3_TRANSITION_COUNT] =
{
  { CRYPTO_XVIX_XAIX_IDLE_STATE,           E_OK,  CRYPTO_XVIX_XAIX_IDLE_STATE          },
  { CRYPTO_XVIX_XAIX_ERROR_STATE,          E_OK,  CRYPTO_XVIX_XAIX_IDLE_STATE          },
  { CRYPTO_XVIX_XAIX_CANCEL_STATE,         E_OK,  CRYPTO_XVIX_XAIX_IDLE_STATE          },
  { CRYPTO_XVIX_XAIX_START_DONE_STATE,     E_OK,  CRYPTO_XVIX_XAIX_START_DONE_STATE    },
  { CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB,   E_OK,  CRYPTO_XVIX_XAIX_UPDATE_DONE_STATE   },
  { CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING,  E_OK,  CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE },
  { CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE,  E_OK,  CRYPTO_XVIX_XAIX_IDLE_STATE          }
};

static CONST(Crypto_xVIx_xAIx_StateFctPtrType, CRYPTO_xVIx_xAIx_CONST)
  Crypto_xVIx_xAIx_Actions_SHA3[CRYPTO_XVIX_XAIX_SM_SHA3_ACTION_COUNT] =
{
  /* CRYPTO_XVIX_XAIX_IDLE_STATE          */  &Crypto_xVIx_xAIx_StateMachineIdle  ,
  /* CRYPTO_XVIX_XAIX_ERROR_STATE         */  &Crypto_xVIx_xAIx_StateMachineIdle  ,
  /* CRYPTO_XVIX_XAIX_CANCEL_STATE        */  &Crypto_xVIx_xAIx_StateMachineIdle  ,
  /* CRYPTO_XVIX_XAIX_START_DONE_STATE    */  &Crypto_xVIx_xAIx_StateMachineIdle  ,
  /* CRYPTO_XVIX_XAIX_UPDATE_DONE_STATE   */  &Crypto_xVIx_xAIx_StateMachineIdle  ,
  /* CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB  */  &Crypto_xVIx_xAIx_SHA3_SpongeAbsorb ,
  /* CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING */  &Crypto_xVIx_xAIx_SHA3_SpongePadding,
  /* CRYPTO_XVIX_XAIX_SHA3_FINISH_SQUEEZE */  &Crypto_xVIx_xAIx_SHA3_SpongeSqueeze
};

#define CRYPTO_xVIx_xAIx_STOP_SEC_CONST_UNSPECIFIED
#include <Crypto_xVIx_xAIx_MemMap.h>

/*==[Variables with internal linkage]=============================================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_VAR_INIT_BOOLEAN
#include <Crypto_xVIx_xAIx_MemMap.h>

/** \brief States if Helper is busy */
static VAR(boolean, CRYPTO_xVIx_xAIx_VAR) Crypto_xVIx_xAIx_HelperBusy = FALSE;

#define CRYPTO_xVIx_xAIx_STOP_SEC_VAR_INIT_BOOLEAN
#include <Crypto_xVIx_xAIx_MemMap.h>

#define CRYPTO_xVIx_xAIx_START_SEC_VAR_CLEARED_UNSPECIFIED
#include <Crypto_xVIx_xAIx_MemMap.h>

/** \brief Result of the Helper */
static VAR(Std_ReturnType,                  CRYPTO_xVIx_xAIx_VAR) Crypto_xVIx_xAIx_HelperResult;

/** \brief SHA3 Ctx
 *
 *         The context variable which is used to store the internal state of the
 *         SHA3 computation.
 */
static VAR(Crypto_xVIx_xAIx_SHA3CtxType,    CRYPTO_xVIx_xAIx_VAR) Crypto_xVIx_xAIx_SHA3Ctx;

#define CRYPTO_xVIx_xAIx_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include <Crypto_xVIx_xAIx_MemMap.h>

/*==[Constants with external linkage]=============================================================*/

/*==[Variables with external linkage]=============================================================*/

/*==[Definition of functions with external linkage]===============================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*--SHA3 Common-----------------------------------------------------------------------------------*/

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset
(
  void
)
{
  SchM_Enter_Crypto_xVIx_xAIx_SCHM_CRYPTO_XVIX_XAIX_EXCLUSIVE_AREA_DRIVEROBJECT();
  TS_MemBZero(&Crypto_xVIx_xAIx_SHA3Ctx, sizeof(Crypto_xVIx_xAIx_SHA3Ctx));
  SchM_Exit_Crypto_xVIx_xAIx_SCHM_CRYPTO_XVIX_XAIX_EXCLUSIVE_AREA_DRIVEROBJECT();
}

/*--SHA3 224 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 224 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_224_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = Crypto_Generic_Callback;

  /* !LINKSTO EB_Crypto_CryptAlgos_1751,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_224_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  if(CRYPTO_PROCESSING_SYNC == ProcessingType)
  {
    /* This function can not fail for the first state */
    (void)Crypto_xVIx_xAIx_SHA3224HelperSynchronousMainCall();
  }
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Update(DataPtr, DataLength);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3224HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(ResultPtr, ResultLengthPtr);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3224HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperMainFunction
(
  void
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 256 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_256_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = Crypto_Generic_Callback;

  /* !LINKSTO EB_Crypto_CryptAlgos_1752,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_256_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  if(CRYPTO_PROCESSING_SYNC == ProcessingType)
  {
    /* This function can not fail for the first state */
    (void)Crypto_xVIx_xAIx_SHA3256HelperSynchronousMainCall();
  }
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Update(DataPtr, DataLength);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3256HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(ResultPtr, ResultLengthPtr);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3256HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperMainFunction
(
  void
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 384 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_384_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = Crypto_Generic_Callback;

  /* !LINKSTO EB_Crypto_CryptAlgos_1753,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_384_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  if(CRYPTO_PROCESSING_SYNC == ProcessingType)
  {
    /* This function can not fail for the first state */
    (void)Crypto_xVIx_xAIx_SHA3384HelperSynchronousMainCall();
  }
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperUpdate
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)  DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Update(DataPtr, DataLength);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3384HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(ResultPtr, ResultLengthPtr);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3384HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperMainFunction
(
  void
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
}

#endif /* (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 Helper-------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperStart
(
  CONST(uint32,                          CRYPTO_xVIx_xAIx_CONST) ObjId,
  P2FUNC(void, CRYPTO_xVIx_xAIx_CODE,   Crypto_Generic_Callback)
  (
    P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
          uint8                                                  Error
  ),
  P2VAR(Crypto_JobType, AUTOMATIC,   CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        boolean                                                  ProcessingType
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 512 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_512_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = Crypto_Generic_Callback;

  /* !LINKSTO EB_Crypto_CryptAlgos_1754,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_512_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  if(CRYPTO_PROCESSING_SYNC == ProcessingType)
  {
    /* This function can not fail for the first state */
    (void)Crypto_xVIx_xAIx_SHA3512HelperSynchronousMainCall();
  }
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperUpdate
(
  P2CONST(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) DataPtr,
          uint32                                         DataLength,
          boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Update(DataPtr, DataLength);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3512HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperFinish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr,
        boolean                                        ProcessingType
)
{
  Std_ReturnType RetVal;

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(ResultPtr, ResultLengthPtr);

  if((CRYPTO_PROCESSING_SYNC == ProcessingType) && (E_OK == RetVal))
  {
    RetVal = Crypto_xVIx_xAIx_SHA3512HelperSynchronousMainCall();
  }
  return RetVal;
}

FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperMainFunction
(
  void
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

/*--SHA3 224 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)

/* !LINKSTO EB_Crypto_CryptAlgos_1270,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 224 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_224_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjectId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = &Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack;

  /* !LINKSTO EB_Crypto_CryptAlgos_1751,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_224_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1271,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Update(
                                        Job->jobPrimitiveInputOutput.inputPtr,
                                        Job->jobPrimitiveInputOutput.inputLength
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1272,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(
                                        Job->jobPrimitiveInputOutput.outputPtr,
                                        Job->jobPrimitiveInputOutput.outputLengthPtr
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1273,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  RetVal = Crypto_xVIx_xAIx_SHA3Cancel();

  TS_PARAM_UNUSED(ObjectId);
  TS_PARAM_UNUSED(Job);

  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1274,1 */
FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(Result, Busy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

/* !LINKSTO EB_Crypto_CryptAlgos_1275,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 256 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_256_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjectId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = &Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack;

  /* !LINKSTO EB_Crypto_CryptAlgos_1752,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_256_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1276,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Update(
                                        Job->jobPrimitiveInputOutput.inputPtr,
                                        Job->jobPrimitiveInputOutput.inputLength
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1277,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(
                                        Job->jobPrimitiveInputOutput.outputPtr,
                                        Job->jobPrimitiveInputOutput.outputLengthPtr
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1278,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  RetVal = Crypto_xVIx_xAIx_SHA3Cancel();

  TS_PARAM_UNUSED(ObjectId);
  TS_PARAM_UNUSED(Job);

  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1279,1 */
FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(Result, Busy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

/* !LINKSTO EB_Crypto_CryptAlgos_1280,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 384 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_384_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjectId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = &Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack;

  /* !LINKSTO EB_Crypto_CryptAlgos_1753,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_384_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1281,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Update(
                                        Job->jobPrimitiveInputOutput.inputPtr,
                                        Job->jobPrimitiveInputOutput.inputLength
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1282,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(
                                        Job->jobPrimitiveInputOutput.outputPtr,
                                        Job->jobPrimitiveInputOutput.outputLengthPtr
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1283,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  RetVal = Crypto_xVIx_xAIx_SHA3Cancel();

  TS_PARAM_UNUSED(ObjectId);
  TS_PARAM_UNUSED(Job);

  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1284,1 */
FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(Result, Busy);
}

#endif /* (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 AL FUNCTIONS-------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

/* !LINKSTO EB_Crypto_CryptAlgos_1285,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Start
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  /* !LINKSTO SWS_Crypto_00017,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Start2Start,1 */
  /* !LINKSTO Crypto.Dsn.JobTransition.Update2Start,1 */
  Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();

  /* Configuration for SHA3 512 */
  Crypto_xVIx_xAIx_SHA3Ctx.HashLength = CRYPTO_XVIX_XAIX_SHA3_512_HASH_LEN_BYTES;
  /* !LINKSTO EB_Crypto_CryptAlgos_1735,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.ObjId                   = ObjectId;
  Crypto_xVIx_xAIx_SHA3Ctx.Job                     = Job;
  Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback = &Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack;

  /* !LINKSTO EB_Crypto_CryptAlgos_1754,1 */
  Crypto_xVIx_xAIx_SHA3Ctx.BlockSize    = CRYPTO_XVIX_XAIX_SHA3_512_BLOCK_SIZE;

  Crypto_xVIx_xAIx_SHA3Ctx.State        = CRYPTO_XVIX_XAIX_START_DONE_STATE;
  Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode  = CRYPTO_OPERATIONMODE_START;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1286,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Update
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Update(
                                        Job->jobPrimitiveInputOutput.inputPtr,
                                        Job->jobPrimitiveInputOutput.inputLength
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1287,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Finish
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  TS_PARAM_UNUSED(ObjectId);

  RetVal = Crypto_xVIx_xAIx_SHA3Finish(
                                        Job->jobPrimitiveInputOutput.outputPtr,
                                        Job->jobPrimitiveInputOutput.outputLengthPtr
                                      );
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1288,1 */
FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Cancel
(
        uint32                                                 ObjectId,
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  RetVal = Crypto_xVIx_xAIx_SHA3Cancel();

  TS_PARAM_UNUSED(ObjectId);
  TS_PARAM_UNUSED(Job);

  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1289,1 */
FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Result,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
)
{
  Crypto_xVIx_xAIx_SHA3MainFunction(Result, Busy);
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

#define CRYPTO_xVIx_xAIx_STOP_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*==[Definition of functions with internal linkage]===============================================*/

#define CRYPTO_xVIx_xAIx_START_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

/*--SHA3 224 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)
static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3224HelperSynchronousMainCall
(
  void
)
{
  Crypto_xVIx_xAIx_HelperBusy = TRUE;
  do
  {
    Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
  }
  while ( TRUE == Crypto_xVIx_xAIx_HelperBusy );
  return Crypto_xVIx_xAIx_HelperResult;
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

/*--SHA3 256 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)

static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3256HelperSynchronousMainCall
(
  void
)
{
  Crypto_xVIx_xAIx_HelperBusy = TRUE;
  do
  {
    Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
  }
  while ( TRUE == Crypto_xVIx_xAIx_HelperBusy );
  return Crypto_xVIx_xAIx_HelperResult;
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

/*--SHA3 384 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)

static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3384HelperSynchronousMainCall
(
  void
)
{
  Crypto_xVIx_xAIx_HelperBusy = TRUE;
  do
  {
    Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
  }
  while ( TRUE == Crypto_xVIx_xAIx_HelperBusy );
  return Crypto_xVIx_xAIx_HelperResult;
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

/*--SHA3 512 Helper ------------------------------------------------------------------------------*/

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)

static FUNC(boolean, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3512HelperSynchronousMainCall
(
  void
)
{
  Crypto_xVIx_xAIx_HelperBusy = TRUE;
  do
  {
    Crypto_xVIx_xAIx_SHA3MainFunction(&Crypto_xVIx_xAIx_HelperResult, &Crypto_xVIx_xAIx_HelperBusy);
  }
  while ( TRUE == Crypto_xVIx_xAIx_HelperBusy );
  return Crypto_xVIx_xAIx_HelperResult;
}

#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */

/*--SHA3 Common-----------------------------------------------------------------------------------*/

static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Update
(
  P2CONST(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) DataPtr,
          uint32                                        DataLength
)
{
  Std_ReturnType RetVal = CRYPTO_E_BUSY;

  if(
        (CRYPTO_XVIX_XAIX_START_DONE_STATE  == Crypto_xVIx_xAIx_SHA3Ctx.State)
     || (CRYPTO_XVIX_XAIX_UPDATE_DONE_STATE == Crypto_xVIx_xAIx_SHA3Ctx.State)
    )
  {
    /* Store data into context */
    Crypto_xVIx_xAIx_SHA3Ctx.Data        = DataPtr;
    Crypto_xVIx_xAIx_SHA3Ctx.DataLength  = DataLength;

    /* Set state of the state machine to update */
    Crypto_xVIx_xAIx_SHA3Ctx.State       = CRYPTO_XVIX_XAIX_SHA3_SPONGE_ABSORB;
    /* Set current mode to call Callback correctly */
    Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode = CRYPTO_OPERATIONMODE_UPDATE;
    RetVal                               = E_OK;
  }
  else
  {
    Crypto_xVIx_xAIx_SHA3Ctx.State = CRYPTO_XVIX_XAIX_IDLE_STATE;
    Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();
  }

  return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Finish
(
  P2VAR(uint8,  AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultPtr,
  P2VAR(uint32, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultLengthPtr
)
{
  Std_ReturnType RetVal = CRYPTO_E_BUSY;

  if(
        (CRYPTO_XVIX_XAIX_UPDATE_DONE_STATE == Crypto_xVIx_xAIx_SHA3Ctx.State      )
     && (CRYPTO_OPERATIONMODE_UPDATE        == Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode)
    )
  {
    /* Store data into context */
    Crypto_xVIx_xAIx_SHA3Ctx.Result          = ResultPtr;
    Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr = ResultLengthPtr;

    /* Set state of the state machine to finish */
    Crypto_xVIx_xAIx_SHA3Ctx.State           = CRYPTO_XVIX_XAIX_SHA3_FINISH_PADDING;
    /* Set current mode to call Callback correctly */
    Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode     = CRYPTO_OPERATIONMODE_FINISH;
    RetVal                                   = E_OK;
  }
  else
  {
    Crypto_xVIx_xAIx_SHA3Ctx.State = CRYPTO_XVIX_XAIX_IDLE_STATE;
    Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();
  }

  return RetVal;
}

static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3Cancel
(
  void
)
{
  Std_ReturnType RetVal = E_NOT_OK;

  /* This state indicates, that the Primitive is currently waiting for an Update/Finish call */
  if(
        (CRYPTO_XVIX_XAIX_START_DONE_STATE  == Crypto_xVIx_xAIx_SHA3Ctx.State)
     || (CRYPTO_XVIX_XAIX_UPDATE_DONE_STATE == Crypto_xVIx_xAIx_SHA3Ctx.State)
    )
  {
    /* !LINKSTO SWS_Crypto_00122_CORRECTION,1 */
    Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();
    /* !LINKSTO EB_Crypto_00063,1 */
    RetVal = E_OK;
  }
  else
  {
    /* Job can not be canceled immediately */
    Crypto_xVIx_xAIx_SHA3Ctx.CancelFlag = TRUE;
    /* !LINKSTO SWS_Crypto_00143_CORRECTION_SWS_Crypto_00183,1 */
    RetVal = CRYPTO_E_JOB_CANCELED;
  }
  return RetVal;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1736,1 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongeAbsorb
(
  void
)
{
  uint32 i;

  P2VAR(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Buffer =
      (P2VAR(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)) &Crypto_xVIx_xAIx_SHA3Ctx.HashState;

  /* Absorbing phase */
  while (0U < Crypto_xVIx_xAIx_SHA3Ctx.DataLength)
  {
    /* Number of bytes to process at a time */
    /* !LINKSTO EB_Crypto_CryptAlgos_1737,1 */
    /* Deviation TASKING-1 */
    Crypto_xVIx_xAIx_SHA3Ctx.Offset =
      CRYPTO_XVIX_XAIX_MINIMUM(Crypto_xVIx_xAIx_SHA3Ctx.DataLength, Crypto_xVIx_xAIx_SHA3Ctx.BlockSize);

    /* Absorb the input */
    for (
          i = 0U;
         ((i < Crypto_xVIx_xAIx_SHA3Ctx.Offset) && (Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn < Crypto_xVIx_xAIx_SHA3Ctx.BlockSize));
          i++
        )
    {
      Buffer[Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn] ^= Crypto_xVIx_xAIx_SHA3Ctx.Data[i];
      Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn++;
    }

    /* Adapt remaining bytes to process and advance the data pointer */
    if (i < Crypto_xVIx_xAIx_SHA3Ctx.Offset)
    {
      Crypto_xVIx_xAIx_SHA3Ctx.DataLength -= i;
      Crypto_xVIx_xAIx_SHA3Ctx.Data       += i;
    }
    else
    {
      Crypto_xVIx_xAIx_SHA3Ctx.DataLength -= Crypto_xVIx_xAIx_SHA3Ctx.Offset;
      Crypto_xVIx_xAIx_SHA3Ctx.Data       += Crypto_xVIx_xAIx_SHA3Ctx.Offset;
    }

    /* Check if a full block is absorbed */
    /* !LINKSTO EB_Crypto_CryptAlgos_1758,1 */
    if (
           (Crypto_xVIx_xAIx_SHA3Ctx.Offset       == Crypto_xVIx_xAIx_SHA3Ctx.BlockSize)
        || (Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn == Crypto_xVIx_xAIx_SHA3Ctx.BlockSize)
       )
    {
      /* Apply block permutation function */
      Crypto_xVIx_xAIx_SHA3_KeccakF1600_StatePermute(Crypto_xVIx_xAIx_SHA3Ctx.HashState);
      /* The input buffer is empty */
      Crypto_xVIx_xAIx_SHA3Ctx.Offset       = 0U;
      Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn = 0U;
    }
  }

  Crypto_xVIx_xAIx_SHA3Ctx.CallbackResult = E_OK;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag   = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1738,1 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongePadding
(
  void
)
{
  P2VAR(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Buffer =
      (P2VAR(uint8, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA)) &Crypto_xVIx_xAIx_SHA3Ctx.HashState;

  /* Add the first byte of padding */
  /* !LINKSTO EB_Crypto_CryptAlgos_1739,1 */
  Buffer[Crypto_xVIx_xAIx_SHA3Ctx.DataLengthIn] ^= CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_1;

  /* Add the second byte of padding */
  /* !LINKSTO EB_Crypto_CryptAlgos_1740,1 */
  Buffer[(Crypto_xVIx_xAIx_SHA3Ctx.BlockSize - 1U)] ^= CRYPTO_XVIX_XAIX_SHA3_KECCAK_PAD_2;

  /* Apply block permutation function */
  Crypto_xVIx_xAIx_SHA3_KeccakF1600_StatePermute(Crypto_xVIx_xAIx_SHA3Ctx.HashState);

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1741,1 */
static FUNC(Std_ReturnType, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_SpongeSqueeze
(
  void
)
{
  uint32 HashLength;
  uint32 ResultLength;

  HashLength = Crypto_xVIx_xAIx_SHA3Ctx.HashLength;

  /* !LINKSTO EB_Crypto_CryptAlgos_1750,2 */
  if(HashLength <= *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr))
  {
    *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr) = HashLength;
    ResultLength                                = HashLength;
  }
  /* !LINKSTO EB_Crypto_CryptAlgos_1757,1 */
  else
  {
    ResultLength = *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr);
  }

  /* Squeeze out all the output blocks */
  while (0U < *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr))
  {
    /* Number of bytes to process at a time */
    /* !LINKSTO EB_Crypto_CryptAlgos_1742,1 */
    /* Deviation TASKING-1 */
    Crypto_xVIx_xAIx_SHA3Ctx.Offset =
      CRYPTO_XVIX_XAIX_MINIMUM(*(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr), Crypto_xVIx_xAIx_SHA3Ctx.BlockSize);

    /* Copy the output string */
    TS_MemCpy(Crypto_xVIx_xAIx_SHA3Ctx.Result, Crypto_xVIx_xAIx_SHA3Ctx.HashState, Crypto_xVIx_xAIx_SHA3Ctx.Offset);

    /* Number of bytes available in the output buffer */
    *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr) -= Crypto_xVIx_xAIx_SHA3Ctx.Offset;
    /* Advance the data pointer */
    Crypto_xVIx_xAIx_SHA3Ctx.Result             += Crypto_xVIx_xAIx_SHA3Ctx.Offset;

  }

  *(Crypto_xVIx_xAIx_SHA3Ctx.ResultLengthPtr) = ResultLength;

  Crypto_xVIx_xAIx_SHA3Ctx.CallbackResult = E_OK;
  Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag   = TRUE;
  Crypto_xVIx_xAIx_SHA3Ctx.ProcessDone    = TRUE;

  return E_OK;
}

/* !LINKSTO EB_Crypto_CryptAlgos_1743,1 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_KeccakF1600_StatePermute
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
)
{
  uint8  i;

  /* Each round consists of a sequence of five transformations,
   * which are called the step mappings
   */
  /* !LINKSTO EB_Crypto_CryptAlgos_1744,1 */
  for (i = 0U; i < CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS; i++)
  {
    /* Apply Theta step mapping */
    Crypto_xVIx_xAIx_SHA3_Theta(HashState);
    /* Apply Rho and Pi steps mapping */
    Crypto_xVIx_xAIx_SHA3_Rho_And_Pi(HashState);
    /* Apply Chi step mapping */
    Crypto_xVIx_xAIx_SHA3_Chi(HashState);
    /* Apply Iota step mapping */
    Crypto_xVIx_xAIx_SHA3_Iota(HashState, i);
  }
}

/* !LINKSTO EB_Crypto_CryptAlgos_1745,1 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Theta
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
)
{
  uint8  x;
  uint8  y;

  Crypto_xVIx_xAIx_KeccakLaneType C[CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX];
  Crypto_xVIx_xAIx_KeccakLaneType D;

  /* Compute the parity of the columns */
  for (x = 0U; x < CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX; x++)
  {
    C[x] =   CRYPTO_XVIX_XAIX_READ_LANE(x, 0U, HashState)
           ^ CRYPTO_XVIX_XAIX_READ_LANE(x, 1U, HashState)
           ^ CRYPTO_XVIX_XAIX_READ_LANE(x, 2U, HashState)
           ^ CRYPTO_XVIX_XAIX_READ_LANE(x, 3U, HashState)
           ^ CRYPTO_XVIX_XAIX_READ_LANE(x, 4U, HashState);
  }

  for (x = 0U; x < CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX; x++)
  {
    /* Compute the Theta effect for a given column */
    D =  C[(x + 4U) % CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX]
       ^ CRYPTO_XVIX_XAIX_ROL64(C[(x + 1U) % CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX], 1U);

    /* Add the Theta effect to the whole column */
    for (y = 0U; y < CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX; y++)
    {
      CRYPTO_XVIX_XAIX_XOR_LANE(x, y, HashState, D);
    }
  }

}

/* !LINKSTO EB_Crypto_CryptAlgos_1746,1 */
/* !LINKSTO EB_Crypto_CryptAlgos_1747,1 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Rho_And_Pi
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
)
{
  uint8 t;
  uint8 x;
  uint8 y;
  uint8 yTmp;
  uint8 r;

  Crypto_xVIx_xAIx_KeccakLaneType Current;
  Crypto_xVIx_xAIx_KeccakLaneType Temp;

  /* start at coordinate (1 0) */
  x = 1U;
  y = 0U;
  Current = CRYPTO_XVIX_XAIX_READ_LANE(x, y, HashState);

  /* Iterate over ((0 1)(2 3)) ^ t * (1 0) for 0 <= t < 24 */
  for (t = 0U; t < CRYPTO_XVIX_XAIX_SHA3_NUMBER_OF_ROUNDS; t++)
  {
    /* Compute the rotation constant r = (t+1)(t+2)/2 */
    r = ((t + 1U) * (t + 2U) / 2U) % CRYPTO_XVIX_XAIX_Z_COORDINATE_INDEX;
    /* Compute ((0 1)(2 3)) * (x y) */
    yTmp = ((2U * x) + (3U * y)) % CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX;
    /* x = ((0 * x) + (1 * y)) */
    x = y;
    y = yTmp;

    /* Swap current and state(x,y), and rotate */
    Temp = CRYPTO_XVIX_XAIX_READ_LANE(x, y, HashState);
    CRYPTO_XVIX_XAIX_WRITE_LANE(x, y, HashState, CRYPTO_XVIX_XAIX_ROL64(Current, r));
    Current = Temp;
  }
}

/* !LINKSTO EB_Crypto_CryptAlgos_1748,1 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Chi
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState
)
{
  uint8  x;
  uint8  y;

  Crypto_xVIx_xAIx_KeccakLaneType A;
  Crypto_xVIx_xAIx_KeccakLaneType Temp[CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX];

  for (y = 0U; y < CRYPTO_XVIX_XAIX_Y_COORDINATE_INDEX; y++)
  {
    /* Take a copy of the plane */
    for (x = 0U; x < CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX; x++)
    {
      Temp[x] = CRYPTO_XVIX_XAIX_READ_LANE(x, y, HashState);
    }

    /* Compute Chi on the plane */
    for (x = 0U; x < CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX; x++)
    {
      A = (~(uint64)(Temp[((x + 1U) % CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX)]));
      A &= Temp[((x + 2U) % CRYPTO_XVIX_XAIX_X_COORDINATE_INDEX)];
      A ^= Temp[x];
      CRYPTO_XVIX_XAIX_WRITE_LANE(x, y, HashState, A);
    }
  }

}

/* !LINKSTO EB_Crypto_CryptAlgos_1749,1 */
static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3_Iota
(
  P2VAR(uint64, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) HashState,
        uint8                                          Index
)
{
  /* Add the predefined RoundConstants[i] constant to the lane at location State[0U] */
  HashState[0U] ^= Crypto_xVIx_xAIx_KeccakF_RoundConstants[Index];
}

static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_SHA3MainFunction
(
  P2VAR(Std_ReturnType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) ResultError,
  P2VAR(boolean,        AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Busy
)
{
  if(FALSE == Crypto_xVIx_xAIx_CheckSkipMain(
                                              ResultError,
                                              Busy,
                                              Crypto_xVIx_xAIx_SHA3Ctx.ObjId
                                            )
    )
  {
    Crypto_xVIx_xAIx_SHA3Ctx.ResultError = ResultError;
    Crypto_xVIx_xAIx_SHA3Ctx.IsBusy      = Busy;

    if(NULL_PTR != Busy)
    {
      *Busy = TRUE;
    }

    CRYPTO_XVIX_XAIX_DOTRANSITION
    (
      CRYPTO_XVIX_XAIX_SM_SHA3_TRANSITION_COUNT,
      Crypto_xVIx_xAIx_SHA3Ctx.State,
      Crypto_xVIx_xAIx_Actions_SHA3,
      Crypto_xVIx_xAIx_StateTrans_SHA3
    );

    /* !LINKSTO SWS_Crypto_00144_CORRECTION, 1 */
    if (TRUE == Crypto_xVIx_xAIx_SHA3Ctx.CancelFlag)
    {
      if ((NULL_PTR != ResultError) && (NULL_PTR != Busy))
      {
        *ResultError = CRYPTO_E_JOB_CANCELED;
        *Busy = FALSE;
      }
      else
      {
        Crypto_xVIx_xAIx_SHA3Ctx.ProcessDone = TRUE;
      }

      Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback
      (
        Crypto_xVIx_xAIx_SHA3Ctx.Job,
        CRYPTO_E_JOB_CANCELED
      );

      /* !LINKSTO EB_Crypto_CryptAlgos_1755,1 */
      Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();
    }
    else
    {
      if (TRUE == Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag)
      {
        if ((NULL_PTR != ResultError) && (NULL_PTR != Busy))
        {
          *ResultError = Crypto_xVIx_xAIx_SHA3Ctx.CallbackResult;
          *Busy = FALSE;
        }

        Crypto_xVIx_xAIx_SHA3Ctx.Crypto_Generic_Callback
        (
          Crypto_xVIx_xAIx_SHA3Ctx.Job,
          Crypto_xVIx_xAIx_SHA3Ctx.CallbackResult
        );

        Crypto_xVIx_xAIx_SHA3Ctx.CallbackFlag = FALSE;
        /* reset the context if finished or error */
        if (TRUE == Crypto_xVIx_xAIx_SHA3Ctx.ProcessDone)
        {
          /* !LINKSTO EB_Crypto_CryptAlgos_1756,1 */
          Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_Reset();
        }
      }
    }
  }
}

static FUNC(void, CRYPTO_xVIx_xAIx_CODE) Crypto_xVIx_xAIx_AL_HASH_SHA3_NOT_SET_CallBack
(
  P2VAR(Crypto_JobType, AUTOMATIC, CRYPTO_xVIx_xAIx_APPL_DATA) Job,
        uint8                                                  Result
)
{
  if(TRUE == Crypto_xVIx_xAIx_SHA3Ctx.ProcessDone)
  {
    /* !LINKSTO EB_Crypto_01050, 1 */
    SchM_Enter_Crypto_xVIx_xAIx_SCHM_CRYPTO_XVIX_XAIX_EXCLUSIVE_AREA_DRIVEROBJECT();
    Crypto_xVIx_xAIx_DriverObjects[Crypto_xVIx_xAIx_SHA3Ctx.ObjId].DriverObjectState =
      CRYPTO_XVIX_XAIX_DRIVER_OBJECT_STATE_IDLE;
    Crypto_xVIx_xAIx_DriverObjects[Crypto_xVIx_xAIx_SHA3Ctx.ObjId].CurrentJob = NULL_PTR;
    Crypto_xVIx_xAIx_DriverObjects[Crypto_xVIx_xAIx_SHA3Ctx.ObjId].SkipPeriodicMainFunction = TRUE;
    SchM_Exit_Crypto_xVIx_xAIx_SCHM_CRYPTO_XVIX_XAIX_EXCLUSIVE_AREA_DRIVEROBJECT();

    /* !LINKSTO Crypto.Dsn.JobTransition.ActiveError2Idle, 1 */
    /* !LINKSTO Crypto.Dsn.JobTransition.Finish2Idle, 1 */
    /* !LINKSTO Crypto.Dsn.JobTransition.ActiveCancel2Idle, 1 */
    Job->jobState = CRYPTO_JOBSTATE_IDLE;
    CryIf_CallbackNotification(Job, Result);
  }
  else
  {
    if(
        (
          ((Job->jobPrimitiveInputOutput.mode) & ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)) !=
            ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)
        ) &&
        (
          (
            ((Job->jobPrimitiveInputOutput.mode) & ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)) !=
              ((uint8) CRYPTO_OPERATIONMODE_STREAMSTART)
          ) || (CRYPTO_OPERATIONMODE_START != Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode)
        )
      )
    {
      CryIf_CallbackNotification(Job, Result);
    }
  }

  /* processing for async SingleCall and StreamStart */
  if(CRYPTO_PROCESSING_ASYNC == Job->jobPrimitiveInfo->processingType)
  {
    if(
        (
          (
            ((Job->jobPrimitiveInputOutput.mode) & ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)) ==
              ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)
          ) ||
          (
            ((Job->jobPrimitiveInputOutput.mode) & ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)) ==
              ((uint8) CRYPTO_OPERATIONMODE_STREAMSTART)
          )
        ) && (CRYPTO_OPERATIONMODE_START == Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode)
      )
    {
      switch(Crypto_xVIx_xAIx_SHA3Ctx.Job->jobPrimitiveInfo->primitiveInfo->algorithm.family)
      {
      /* Update always returns OK */
#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)
        case CRYPTO_ALGOFAM_SHA3_224:
        (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Update
              (
                Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                Job
              );
        break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)
        case CRYPTO_ALGOFAM_SHA3_256:
        (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Update
              (
                Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                Job
              );
        break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)
        case CRYPTO_ALGOFAM_SHA3_384:
        (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Update
              (
                Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                Job
              );
        break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)
        case CRYPTO_ALGOFAM_SHA3_512:
        (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Update
              (
                Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                Job
              );
        break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */
        /* CHECK: NOPARSE */
        /*All the possible valid algorithm families addressed in the cases above.*/
        default:
        {
          /* Caution: this 'default' is required by MISRA-C:2012 */
        }
        break;
        /* CHECK: PARSE */
      }
    }
    else
    {
      if(
          (
            ((Job->jobPrimitiveInputOutput.mode) & ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)) ==
              ((uint8) CRYPTO_OPERATIONMODE_SINGLECALL)
          ) && (CRYPTO_OPERATIONMODE_UPDATE == Crypto_xVIx_xAIx_SHA3Ctx.CurrentMode)
        )
      {
        switch(Crypto_xVIx_xAIx_SHA3Ctx.Job->jobPrimitiveInfo->primitiveInfo->algorithm.family)
        {
        /* Finish always returns OK */
#if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)
          case CRYPTO_ALGOFAM_SHA3_224:
          (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_224_NOT_SET_Finish
                (
                  Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                  Job
                );
          break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)
          case CRYPTO_ALGOFAM_SHA3_256:
          (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_256_NOT_SET_Finish
                (
                  Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                  Job
                );
          break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)
          case CRYPTO_ALGOFAM_SHA3_384:
          (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_384_NOT_SET_Finish
                (
                  Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                  Job
                );
          break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON) */

#if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)
          case CRYPTO_ALGOFAM_SHA3_512:
          (void)Crypto_xVIx_xAIx_AL_HASH_SHA3_512_NOT_SET_Finish
                (
                  Crypto_xVIx_xAIx_SHA3Ctx.ObjId,
                  Job
                );
          break;
#endif /* #if (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON) */
          /* CHECK: NOPARSE */
          /*All the possible valid algorithm families addressed in the cases above.*/
          default:
          {
            /* Caution: this 'default' is required by MISRA-C:2012 */
          }
          break;
          /* CHECK: PARSE */
        }
      }
    }
  }

}

#define CRYPTO_xVIx_xAIx_STOP_SEC_CODE
#include <Crypto_xVIx_xAIx_MemMap.h>

#else /* #if(                                                    \
                (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)    \
             || (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)    \
             || (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)    \
             || (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)    \
            )
      */

/* Dummy type definition to prevent compiler warnings about empty translation units */
typedef uint8 Crypto_xVIx_xAIx_SHA3_PrvtEmptyTranslationUnitType;

#endif /* #if(                                                    \
                 (CRYPTO_XVIX_XAIX_SHA3_224_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_256_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_384_ENABLED == STD_ON)    \
              || (CRYPTO_XVIX_XAIX_SHA3_512_ENABLED == STD_ON)    \
             )
       */

/*==[end of file]=================================================================================*/


