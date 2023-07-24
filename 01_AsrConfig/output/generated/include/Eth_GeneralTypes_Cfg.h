#ifndef ETH_GENERALTYPES_CFG_H
#define ETH_GENERALTYPES_CFG_H
/**
 * \file
 *
 * \brief AUTOSAR Base
 *
 * This file contains the implementation of the AUTOSAR
 * module Base.
 *
 * \version 5.1.0
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>          /* AUTOSAR standard type definitions */

/*==================[type definitions]=======================================*/

/** \brief Represents the hardware object handles of a ETH hardware buffer.
 *
 * Range:
 *  - uint32 (if configuration parameter 'EthIf/EthIfPublicCfg/EthIfPublicHandleTypeEnum = UINT32')
 *  - uint8  (otherwise)
 */
 /* !LINKSTO Base.Eth.Eth_BufIdxType,1 */
#define Eth_BufIdxType uint8

/*==================[macros]=================================================*/

/** \brief Invalid buffer index (i.e. max value).
 *
 * Range:
 *  - uint32 (if configuration parameter 'EthIf/EthIfPublicCfg/EthIfPublicHandleTypeEnum = UINT32')
 *  - uint8  (otherwise)
 */
#define ETH_BUFIDXTYPE_INVALID ((Eth_BufIdxType) 0xFFU)

#endif /* ifndef ETH_GENERALTYPES_CFG_H */
/*==================[end of file]============================================*/
