/**
 * \file
 *
 * \brief AUTOSAR Dcm
 *
 * This file contains the implementation of the AUTOSAR
 * module Dcm.
 *
 * \version 5.0.10
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#ifndef DCM_TYPES_CFG_H
#define DCM_TYPES_CFG_H

/*==================[includes]===================================================================*/
/*==================[macros]=====================================================================*/

/* !LINKSTO Dcm.EB.SesCtrlType.RteUsageFalse,1 */
#if (DCM_INCLUDE_RTE == STD_OFF)
/*------------------[definitions of session levels]----------------------------------------------*/
#if (defined DcmConf_DcmDspSession_DCM_DEFAULT_SESSION)
#error DcmConf_DcmDspSession_DCM_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_DEFAULT_SESSION 1U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_DEFAULT_SESSION)
#error Dcm_DCM_DEFAULT_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_DEFAULT_SESSION 1U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_EXTENDED_DIAGNOSTIC_SESSION)
#error DcmConf_DcmDspSession_DCM_EXTENDED_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_EXTENDED_DIAGNOSTIC_SESSION 3U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_EXTENDED_DIAGNOSTIC_SESSION)
#error Dcm_DCM_EXTENDED_DIAGNOSTIC_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_EXTENDED_DIAGNOSTIC_SESSION 3U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION)
#error DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_PROGRAMMING_SESSION 2U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_PROGRAMMING_SESSION)
#error Dcm_DCM_PROGRAMMING_SESSION already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_PROGRAMMING_SESSION 2U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#if (defined DcmConf_DcmDspSession_DCM_ALL_SESSION_LEVEL)
#error DcmConf_DcmDspSession_DCM_ALL_SESSION_LEVEL already defined
#endif
/** \brief Export symbolic name value */
#define DcmConf_DcmDspSession_DCM_ALL_SESSION_LEVEL 255U

#if (defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES)
#if (defined Dcm_DCM_ALL_SESSION_LEVEL)
#error Dcm_DCM_ALL_SESSION_LEVEL already defined
#endif
/** \brief Export symbolic name value with module abbreviation as prefix only
 **        (AUTOSAR version <= AUTOSAR 4.0 rev2) */
#define Dcm_DCM_ALL_SESSION_LEVEL 255U
#endif /* defined DCM_PROVIDE_LEGACY_SYMBOLIC_NAMES */

#endif /* #if (DCM_INCLUDE_RTE == STD_OFF) */

/*==================[type definitions]===========================================================*/
/*==================[external function declarations]=============================================*/
/*==================[internal function declarations]=============================================*/
/*==================[external constants]=========================================================*/
/*==================[internal data]==============================================================*/
/*==================[external function definitions]==============================================*/
/*==================[internal function definitions]==============================================*/

#endif /* ifndef DCM_TYPES_CFG_H */
/*==================[end of file]================================================================*/
