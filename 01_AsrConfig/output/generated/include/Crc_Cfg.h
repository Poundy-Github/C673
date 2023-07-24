/**
 * \file
 *
 * \brief AUTOSAR Crc
 *
 * This file contains the implementation of the AUTOSAR
 * module Crc.
 *
 * \version 6.11.14
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef CRC_CFG_H
#define CRC_CFG_H

/* !LINKSTO SWS_Crc_00024,1 */

/* This file contains the generated Crc module configuration. */

/*==================[includes]===============================================*/

/*==================[macros]=================================================*/

#if (defined CRC_DEV_ERROR_DETECT)
# error CRC_DEV_ERROR_DETECT already defined
#endif
/** \brief Macro switch for DET usage */
#define CRC_DEV_ERROR_DETECT             STD_ON

/*------------------[CRC calculation method options]-------------------------*/

#if (defined CRC_8_ENABLED)
# error CRC_8_ENABLED already defined
#endif
/** \brief Switch to en/disable the CRC8 routine */
#define CRC_8_ENABLED         STD_ON

#if (defined CRC_8_TABLE_SIZE)
# error CRC_8_TABLE_SIZE already defined
#endif
/** \brief Number of elements in CRC8 lookup table
 *
 * If size is 0 table based calculation is deactivated. */
#define CRC_8_TABLE_SIZE      16U


#if (defined CRC_8H2F_ENABLED)
# error CRC_8H2F_ENABLED already defined
#endif
/** \brief Switch to en/disable the CRC8H2F routine */
#define CRC_8H2F_ENABLED      STD_ON

#if (defined CRC_8H2F_TABLE_SIZE)
# error CRC_8H2F_TABLE_SIZE already defined
#endif
/** \brief Number of elements in CRC8H2F lookup table
 *
 * If size is 0 table based calculation is deactivated. */
#define CRC_8H2F_TABLE_SIZE   16U


#if (defined CRC_16_ENABLED)
# error CRC_16_ENABLED already defined
#endif
/** \brief Switch to en/disable the CRC16 routine */
#define CRC_16_ENABLED        STD_ON

#if (defined CRC_16_TABLE_SIZE)
# error CRC_16_TABLE_SIZE already defined
#endif
/** \brief Number of elements in CRC16 lookup table
 *
 * If size is 0 table based calculation is deactivated. */
#define CRC_16_TABLE_SIZE     16U


#if (defined CRC_32_ENABLED)
# error CRC_32_ENABLED already defined
#endif
/** \brief Switch to en/disable the CRC32 routine */
#define CRC_32_ENABLED        STD_ON

#if (defined CRC_32_TABLE_SIZE)
# error CRC_32_TABLE_SIZE already defined
#endif
/** \brief Number of elements in CRC32 lookup table
 *
 * If size is 0 table based calculation is deactivated. */
#define CRC_32_TABLE_SIZE     16U


#if (defined CRC_64_ENABLED)
# error CRC_64_ENABLED already defined
#endif
/** \brief Switch to en/disable the CRC64 routine */
#define CRC_64_ENABLED        STD_OFF

#if (defined CRC_64_TABLE_SIZE)
# error CRC_64_TABLE_SIZE already defined
#endif
/** \brief Number of elements in CRC64 lookup table
 *
 * If size is 0 table based calculation is deactivated. */
#define CRC_64_TABLE_SIZE     0U

/*------------------[API configuration options]------------------------------*/

/*==================[type definitions]=======================================*/

/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CRC_CFG_H */
/*==================[end of file]============================================*/
