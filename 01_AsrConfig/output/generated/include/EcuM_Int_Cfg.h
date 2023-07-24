/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \version 5.15.8
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef ECUM_INT_CFG_H
#define ECUM_INT_CFG_H

/*==================[includes]==============================================*/

/*==================[macros]================================================*/

#if (defined ECUM_STORED_SHUTDOWN_OPERATIONS)
#error ECUM_STORED_SHUTDOWN_OPERATIONS already defined
#endif
/** \brief Size of the array which contains all the recent
 shutdown information. Used to implement EcuM_GetNextRecentShutdown() */
#define ECUM_STORED_SHUTDOWN_OPERATIONS   1U

/*------------------[EcuM Multi-Core implementation macros]-----------------------*/









#define ECUM_AL_DRIVERINITZERO() EcuM_AL_DriverInitZero()



#define ECUM_AL_DRIVERINITONE() EcuM_AL_DriverInitOne(EcuM_ConfigPtr)


#if (defined ECUM_NUM_CORES)
#error ECUM_NUM_CORES already defined
#endif
/** \brief Preprocessor macro defining the number of cores configured. */
#define ECUM_NUM_CORES 4U

#if (defined ECUM_CORE_ID_MASTER)
#error ECUM_CORE_ID_MASTER already defined
#endif
/** \brief Preprocessor macro defining the core configured as master core. */
#define ECUM_CORE_ID_MASTER 0U

#if (defined ECUM_CORE_ID_INITIAL)
#error ECUM_CORE_ID_INITIAL already defined
#endif
/** \brief Preprocessor macro defining the initially active core . */
#define ECUM_CORE_ID_INITIAL 0U

#if (defined ECUM_SLAVE_SYNC_MASK)
#error ECUM_SLAVE_SYNC_MASK already defined
#endif
/** \brief a bit mask  for the slave core Ids. */
#define ECUM_SLAVE_SYNC_MASK \
  ( \
((uint32)1U << OS_CORE_ID_1) | ((uint32)1U << OS_CORE_ID_2) | ((uint32)1U << OS_CORE_ID_3) | \
  0U)


/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define ECUM_START_SEC_CODE
#include <EcuM_MemMap.h>
/** \brief Starts all Os cores except the designated initial core. */
extern FUNC(void, ECUM_CODE) EcuM_StartAllCores(void);
#define ECUM_STOP_SEC_CODE
#include <EcuM_MemMap.h>

/*==================[internal function declarations]========================*/

/*==================[external constants]====================================*/

/*==================[internal constants]====================================*/

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/

#endif /* ifndef ECUM_INT_CFG_H */
/*==================[end of file]===========================================*/
