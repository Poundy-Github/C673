/**
 * \file
 *
 * \brief AUTOSAR CanTp
 *
 * This file contains the implementation of the AUTOSAR
 * module CanTp.
 *
 * \version 6.8.45
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef CANTP_EXITTABLETYPES_H

#if (defined CANTP_EXITTABLETYPES_H) /* to prevent double declaration */
#error CANTP_EXITTABLETYPES_H is already defined
#endif /* if (defined CANTP_EXITTABLETYPES_H) */
#define CANTP_EXITTABLETYPES_H

/*==================[inclusions]=============================================*/

#include <TSAutosar.h>          /* EB specific standard types */
#include <ComStack_Types.h>     /* typedefs for AUTOSAR com stack */

#include <CanTp_Cfg.h>          /* CanTp configuration */

#if(CANTP_DEV_ERROR_DETECT == STD_ON)
#include <Det.h>                /* AUTOSAR Development Error Tracer */
#endif /* CANTP_DEV_ERROR_DETECT == STD_ON */
#include <CanIf.h>              /* AUTOSAR Can Interface */
/* do not indirectly include PduR_SymbolicNames_PBcfg.h via PduR_CanTp.h */

#if (defined PDUR_NO_PBCFG_REQUIRED) /* to prevent double declaration */
#error PDUR_NO_PBCFG_REQUIRED is already defined
#endif /* if (defined PDUR_NO_PBCFG_REQUIRED) */
#define PDUR_NO_PBCFG_REQUIRED

#include <PduR_CanTp.h>         /* AUTOSAR PDU Router */

#undef PDUR_NO_PBCFG_REQUIRED


/*==================[macros]=================================================*/

/*==================[type definitions]=======================================*/

/*==================[external constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[external function declarations]=========================*/

#endif /* ifndef CANTP_EXITTABLETYPES_H */
/*==================[end of file]============================================*/
