/**
 * \file
 *
 * \brief AUTOSAR MemIf
 *
 * This file contains the implementation of the AUTOSAR
 * module MemIf.
 *
 * \version 5.11.12
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef MEMIF_CFG_H
#define MEMIF_CFG_H

  /*==================[includes]==============================================*/

/* !LINKSTO MemIf037,1 */
#include <Std_Types.h>                            /* AUTOSAR standard types     */
#include <TSAutosar.h>                            /* EB specific standard types */

/* include lower layer headers */
#include <Fee.h>

/*==================[macros]================================================*/
#if (defined MEMIF_DEV_ERROR_DETECT)
#error MEMIF_DEV_ERROR_DETECT is already defined
#endif /* if (defined MEMIF_DEV_ERROR_DETECT) */
/** \brief En-/disable development error tracer checks */
#define MEMIF_DEV_ERROR_DETECT   STD_ON


#if (defined MEMIF_MAXIMUM_NUMBER_OF_DEVICES)
#error MEMIF_MAXIMUM_NUMBER_OF_DEVICES is already defined
#endif /* if (defined MEMIF_MAXIMUM_NUMBER_OF_DEVICES) */
/** \brief Maximum number of the underlying memory abstraction modules
 **
 ** Largest Driver Index or 1 if only one abstraction module is present */
 #define MEMIF_MAXIMUM_NUMBER_OF_DEVICES 1U
#if (defined MEMIF_VERSION_INFO_API)
#error MEMIF_VERSION_INFO_API is already defined
#endif /* if (defined MEMIF_VERSION_INFO_API) */
/** \brief En-/disable API version information */
#define MEMIF_VERSION_INFO_API   STD_OFF

/* !LINKSTO MemIf019,1 */

/*
 * Since only one underlaying device is configured, the partmeter DeviceIndex is not used therefore
 * it is cast to void.
 * Direct cast to void is done in MemIf to avoid compilation errors in case of static code checking
 * enabled (EB_STATIC_CHECK is defined).
 */

/* Macro mappings of driver API calls */

#if (defined MemIf_Read)
#error MemIf_Read is already defined
#endif /* if (defined MemIf_Read) */
#define MemIf_Read(DeviceIndex, BlockNumber, BlockOffset, DataBufferPtr, Length) \
  (((void) (DeviceIndex)),Fee_Read(BlockNumber, BlockOffset, DataBufferPtr, Length))

#if (defined MemIf_Write)
#error MemIf_Write is already defined
#endif /* if (defined MemIf_Write) */
#define MemIf_Write(DeviceIndex,  BlockNumber, DataBufferPtr) \
  (((void) (DeviceIndex)),Fee_Write(BlockNumber, DataBufferPtr))

#if (defined MemIf_Cancel)
#error MemIf_Cancel is already defined
#endif /* if (defined MemIf_Cancel) */
#define MemIf_Cancel(DeviceIndex) \
  (((void) (DeviceIndex)),Fee_Cancel())

#if (defined MemIf_GetStatus)
#error MemIf_GetStatus is already defined
#endif /* if (defined MemIf_GetStatus) */
#define MemIf_GetStatus(DeviceIndex) \
  (((void) (DeviceIndex)),Fee_GetStatus())

#if (defined MemIf_GetJobResult)
#error MemIf_GetJobResult is already defined
#endif /* if (defined MemIf_GetJobResult) */
#define MemIf_GetJobResult(DeviceIndex) \
  (((void) (DeviceIndex)),Fee_GetJobResult())

#if (defined MemIf_InvalidateBlock)
#error MemIf_InvalidateBlock is already defined
#endif /* if (defined MemIf_InvalidateBlock) */
#define MemIf_InvalidateBlock(DeviceIndex, BlockNumber) \
  (((void) (DeviceIndex)),Fee_InvalidateBlock(BlockNumber))

#if (defined MemIf_EraseImmediateBlock)
#error MemIf_EraseImmediateBlock is already defined
#endif /* if (defined MemIf_EraseImmediateBlock) */
#define MemIf_EraseImmediateBlock(DeviceIndex, BlockNumber) \
  (((void) (DeviceIndex)),Fee_EraseImmediateBlock(BlockNumber))

#if (defined MemIf_SetMode)
#error MemIf_SetMode is already defined
#endif /* if (defined MemIf_SetMode) */
#define MemIf_SetMode(Mode) \
  Fee_SetMode(Mode)

/* !LINKSTO MemIf020,1 */

/*==================[type definitions]======================================*/

/*==================[external data]=========================================*/

#endif /* ifndef MEMIF_CFG_H */
/*==================[end of file]===========================================*/
