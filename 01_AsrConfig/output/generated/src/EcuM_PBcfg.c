


/**
 * \file
 *
 * \brief AUTOSAR EcuM
 *
 * This file contains the implementation of the AUTOSAR
 * module EcuM.
 *
 * \version 1.4.1
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */


/* MISRA-C:2012 Deviation List
 *
 * MISRAC2012-1) Deviated Rule: 1.3 (required)
 *    There shall be no occurrence of undefined or critical unspecified behaviour.
 *
 *    Reason:
 *    The postbuild macro TS_MAKEREF2CFG requires the usage of the
 *    C standard macro 'offsetof'.
 *    According to the C90 standard, the usage of 'offsetof' produces
 *    an undefined behaviour when the member designator parameter
 *    is a bit-field or when it is an invalid right operator of the
 *    '.' operator for the type parameter.
 *    This is not the case here as the parameter of TS_MAKEREF2CFG
 *    is always a member of TS_PB_CFG_LAYOUT_TYPE and bitfields are
 *    never used when defining the postbuild structure members.
 *
 * MISRAC2012-2) Deviated Rule: 11.4 (advisory)
 *    A cast should not be performed between a pointer type and an integral
 *    type.
 *
 *    Reason:
 *    Relocatable postbuild macro requires the cast between pointer and
 *    integral type.
 *
 * MISRAC2012-3) Deviated Rule: 11.9 (required)
 *    The macro NULL shall be the only permitted form of integer null pointer constant.
 *
 *    Reason:
 *    Macros are used in order to check the alignment for different data types.
 *
 */

/*==================[inclusions]=============================================*/

#include <EcuM_PBcfg.h>
#include <TSAutosar.h>
#include <Compiler.h>
#define TS_RELOCATABLE_CFG_ENABLE STD_ON
#define TS_PB_CFG_NAME EcuM_Configuration
#define TS_PB_CFG_LAYOUT_TYPE EcuM_ConstConfigLayoutType
#include <TSPBConfig_Init.h>

/*==================[macros]=================================================*/


/*==================[type definitions]=======================================*/


/*==================[external function declarations]=========================*/


/*==================[internal function declarations]=========================*/


/*==================[external constants]=====================================*/

#define ECUM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include <EcuM_MemMap.h>

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <START> */
EcuM_ConstConfigLayoutType EcuM_Configuration = {
    { /* RootCfg */
        UINT32_C( 2281703698 ), /* PlatformSignature */
        UINT32_C( 2949684411 ), /* LcfgSignature */
        UINT32_C( 2576289525 ), /* CfgSignature */
        UINT32_C( 1985246510 ), /* PublicInfoSignature */
        UINT8_C( 0 ), /* DefaultAppMode */
        TS_MAKEREF2CFG( DriverInitListOne[0] ), /* PtrDriverInitListOne */
        UINT8_C( 14 ), /* NumDriversInitListOne */
        UINT8_C( 128 ), /* DefaultShutdownTarget */
        UINT8_C( 0 ) /* DefaultMode */
    },
    { /* DriverInitListOne */
        UINT8_C( 0 ), /* DriverInitListOne[0] */
        UINT8_C( 1 ), /* DriverInitListOne[1] */
        UINT8_C( 2 ), /* DriverInitListOne[2] */
        UINT8_C( 3 ), /* DriverInitListOne[3] */
        UINT8_C( 4 ), /* DriverInitListOne[4] */
        UINT8_C( 5 ), /* DriverInitListOne[5] */
        UINT8_C( 6 ), /* DriverInitListOne[6] */
        UINT8_C( 7 ), /* DriverInitListOne[7] */
        UINT8_C( 8 ), /* DriverInitListOne[8] */
        UINT8_C( 9 ), /* DriverInitListOne[9] */
        UINT8_C( 10 ), /* DriverInitListOne[10] */
        UINT8_C( 11 ), /* DriverInitListOne[11] */
        UINT8_C( 12 ), /* DriverInitListOne[12] */
        UINT8_C( 13 ) /* DriverInitListOne[13] */
    }
};

/* Deviation MISRAC2012-1, MISRAC2012-2, MISRAC2012-3 <STOP> */

#define ECUM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include <EcuM_MemMap.h>

/*==================[internal constants]=====================================*/


/*==================[external data]==========================================*/


/*==================[internal data]==========================================*/


/*==================[external function definitions]==========================*/


/*==================[internal function definitions]==========================*/


/*==================[end of file]============================================*/

