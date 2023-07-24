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

/* !LINKSTO Dcm.Dsn.File.RoutineControlConst.ConfigC,1 */

/*==================[inclusions]=================================================================*/

#include <Dcm_RoutineControl_Cfg.h>                             /*  RoutineControl Configuration */

/*==================[macros]=====================================================================*/

/*==================[type definitions]===========================================================*/

/*==================[external function declarations]=============================================*/

/*==================[internal function declarations]=============================================*/

/*==================[internal constants]=========================================================*/

/*==================[internal data]==============================================================*/

#define DCM_START_SEC_CONST_8
#include <Dcm_MemMap.h>

/* Array of session types for all routines */
STATIC CONST(Dcm_SesCtrlType, DCM_CONST) Dcm_RoutineControl_SessionTypes[19] =
{
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x02U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0x03U,
  0xffU,
  0x03U,
  0x03U,
};

/* Array of security types for all routines */
STATIC CONST(Dcm_SecLevelType,DCM_CONST) Dcm_RoutineControl_SecurityLevel[16] =
{
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
  0x01U,
};

#define DCM_STOP_SEC_CONST_8
#include <Dcm_MemMap.h>

/*==================[external constants]=========================================================*/

#define DCM_START_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/* Configuration parameters for 'Routine Control' service */
CONST(Dcm_DspRoutineServicesType, DCM_CONST) Dcm_DspRoutineConfig[DCM_NUM_ROUTINES] =
{
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x800B_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x800B_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[0],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x800bU,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x800C_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x800C_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[1],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x800cU,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0203_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[2],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x203U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0204_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[3],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x204U,
  },
  {
    /* Pointer to request service handler function */
    NULL_PTR,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0205_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[4],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x205U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x8010_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x8010_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[5],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x8010U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0301_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0301_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[6],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x301U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0303_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0303_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[7],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x303U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0302_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0302_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[8],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x302U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0305_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0305_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[9],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x305U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0306_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0306_Start,
    /* Pointer to stop service handler function */
    &Dcm_DcmDspRoutine_0x0306_Stop,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[10],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x306U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0307_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0307_Start,
    /* Pointer to stop service handler function */
    &Dcm_DcmDspRoutine_0x0307_Stop,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[11],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x307U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0308_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0308_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[12],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x308U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x0309_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x0309_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[13],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x309U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x030A_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x030A_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[14],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x30aU,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0x8011_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0x8011_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[15],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0x8011U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0xF012_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0xF012_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[16],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf012U,
  },
  {
    /* Pointer to request service handler function */
    &Dcm_DcmDspRoutine_0xF013_RequestResults,
    /* Pointer to start service handler function */
    &Dcm_DcmDspRoutine_0xF013_Start,
    /* Pointer to stop service handler function */
    NULL_PTR,
    /* Pointer to assigned RoutineInfo configuration */
    &Dcm_DspRoutineInfoConfig[17],
    /* Routine mode rule */
    NULL_PTR,
    /* RID Identifier */
    0xf013U,
  },
};

/* Contains the configuration (parameters) for Routine's Info */
CONST(Dcm_DspRoutineServicesInfoType, DCM_CONST) Dcm_DspRoutineInfoConfig[18] =
{
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[0]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[0]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[1]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[1]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[2]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[2]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    NULL_PTR,
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[3]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    0U
  },
  {
    /* Pointer to security levels */
    NULL_PTR,
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[4]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    0U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[3]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[5]),
    /* Number of sessions */
    2U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[4]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[7]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[5]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[8]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[6]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[9]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[7]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[10]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[8]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[11]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[9]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[12]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[10]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[13]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[11]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[14]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[12]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[15]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[13]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[16]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[14]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[17]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
  {
    /* Pointer to security levels */
    &(Dcm_RoutineControl_SecurityLevel[15]),
    /* Pointer to sessions */
    &(Dcm_RoutineControl_SessionTypes[18]),
    /* Number of sessions */
    1U,
    /* Number of security levels */
    1U
  },
};

#define DCM_STOP_SEC_CONST_UNSPECIFIED
#include <Dcm_MemMap.h>

/*==================[external data]==============================================================*/

/*==================[external function definitions]==============================================*/

/*==================[internal function definitions]==============================================*/

/*==================[end of file]================================================================*/
