/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACT/ISC (Adaptive Cruise Control - Interface & State Coordinator)

PACKAGENAME:               isc_types.h

DESCRIPTION:               Types header file for ISC in FCT_VEH task

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             24.08.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---

**************************************************************************** */

#ifndef _ISC_TYPES_INCLUDED
#define _ISC_TYPES_INCLUDED

/**
   @defgroup Headway Control (HC) Frame Veh
   @ingroup fct_sen_hc
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/
//#include "isc_ver.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! Typedef of <ISC_HMI_InformationPort> input port from ISC to HMI component */
typedef struct
{
  const ACT_ISC_Information_t *pt_HMI;
}
ISC_HMI_InformationPort_t;


/*! Typedef of <ISC_HMI_CommandPort> port from ISC to HMI component */
typedef struct
{
  const ACT_ISC_Command_t *pt_HMC;
}
ISC_HMI_CommandPort_t;


/*! Typedef of <ISC_HMI_StatusPort> port from HMI to ISC component */
typedef struct
{
  ACT_ISC_Status_t *pt_HMS;
}
ISC_HMI_StatusPort_t;


/*! Typedef of <ISC_CC_DegradationPort> port from HMI to ISC component */
typedef struct
{
  FunctionDegradation_t *pt_HMD;
}
ISC_CC_DegradationPort_t;


/*! Typedef of <ISC_TC_DegradationPort> port from HMI to ISC component */
typedef struct
{
  FunctionDegradation_t *pt_HMD;
}
ISC_TC_DegradationPort_t;


/*! Typedef of <SM_CommandPort> port from HMI to SM component */
typedef enum
{
  ISC_SM_CC_FUN_CC,               /* Cruise Control Function */
  ISC_SM_CC_FUN_LIM               /* Speed Limiter Function */
}
ISC_SM_CC_FUN_t;                  /* SM CC Function (CC <-> LIM) */
typedef enum
{
  ISC_SM_CC_OP_NOP,               /* No Operation */
  ISC_SM_CC_OP_SPEED_SET,         /* Set actual Display Speed */
  ISC_SM_CC_OP_SPEED_CLEAR,       /* Clear SetSpeed */
  ISC_SM_CC_OP_SPEED_INC_1,       /* Increment SetSpeed by minor Step */
  ISC_SM_CC_OP_SPEED_INC_2,       /* Increment SetSpeed by major Step */
  ISC_SM_CC_OP_SPEED_DEC_1,       /* Decrement SetSpeed by minor Step */
  ISC_SM_CC_OP_SPEED_DEC_2        /* Decrement SetSpeed by major Step */
}
ISC_SM_CC_OP_t;                   /* SM CC Operation */
typedef struct
{
  boolean b_On;                   /* Switch System On */
  boolean b_Off;                  /* Switch System Off */
  boolean b_Activate;             /* Activate System */
  boolean b_Deactivate;           /* Deactivate System */
}
ISC_SM_SYS_CMD_t;                 /* General System Command */
typedef struct
{
  ISC_SM_CC_FUN_t t_Function;     /* SM CC Function (CC <-> LIM) */
  ISC_SM_CC_OP_t t_Operation;     /* SM CC Operation */
}
ISC_SM_CC_CMD_t;                  /* Cruise Control Command */
typedef struct
{
  percentage_t u_HeadwaySet;      /* Requested Headway Setting [0..100]% */
}
ISC_SM_TC_CMD_t;                  /* Target Control Command */
typedef struct
{
  ISC_SM_SYS_CMD_t t_SYSC;        /* General System Command */
  ISC_SM_CC_CMD_t t_CCC;          /* Cruise Control Command */
  ISC_SM_TC_CMD_t t_TCC;          /* Target Control Command */
}
ISC_SM_Command_t;
typedef struct
{
  ISC_SM_Command_t *pt_SMC;
}
ISC_SM_CommandPort_t;


/*! Typedef of <SM_StatusPort> port from SM to HMI component */
typedef enum
{
  ISC_SM_STATE_OFF,
  ISC_SM_STATE_READY,
  ISC_SM_STATE_ACTIVE,
  ISC_SM_STATE_OVERRIDE
}
ISC_SM_STATE_t;
typedef struct
{
  ISC_SM_STATE_t t_STATE;         /* System State */
  boolean b_StandStill;           /* Physical Standstill */
  boolean b_HoldState;            /* Logical Hold (SS > 3s) */
}
ISC_SM_SYS_STS_t;                 /* General System Status */
typedef struct
{
  setspeed_t u_SetSpeed;          /* SetSpeed [kmh|mph] */
  boolean b_SpeedStored;          /* SetSpeed is stored */
}
ISC_SM_CC_STS_t;                  /* Cruise Control Status */
typedef struct
{
  uint8 u_TargetSpeed;            /* Measured Speed of the main control target [kmh] */
  uint8 u_TargetDistance;         /* Measured Distance of the main control target [m] */
  uint8 u_RequestDistance;        /* Requested Distance at current target speed [m] */
  boolean b_TargetDetected;       /* Target Vehicle is being controlled on */
  boolean b_TakeOverRequest;      /* Driver has to take over control - Target distance will fall below the alert distance */
}
ISC_SM_TC_STS_t;                  /* Target Control Status */
typedef struct
{
  ISC_SM_SYS_STS_t t_SYSS;        /* General System Status */  
  ISC_SM_CC_STS_t t_CCS;          /* Cruise Control Status */  
  ISC_SM_TC_STS_t t_TCS;          /* Target Control Status */  
}
ISC_SM_Status_t;
typedef struct
{
  ISC_SM_Status_t *pt_SMS;
}
ISC_SM_StatusPort_t;


/*! Typedef of <ISC_CC_StatePort_t> port from ISC to SM component */
typedef struct
{
  const ACT_CruiseControlState_t *pt_CCS;
}
ISC_CC_StatePort_t;


/*! Typedef of <ISC_TC_StatePort_t> port from ISC to SM component */
typedef struct
{
  const TargetControlState_t *pt_TCS;
}
ISC_TC_StatePort_t;


/*! Typedef of <ISC_LOC_StatePort_t> port from ISC to HMI component */
typedef struct
{
  const ACT_LogicVehicleState_t *pt_LVS;
}
ISC_LOC_StatePort_t;


/*! Typedef of <ISC_CC_CommandPort_t> port from SM to ISC component */
typedef struct
{
  ACT_CruiseControlCommand_t *pt_CCC;
}
ISC_CC_CommandPort_t;


/*! Typedef of <ISC_TC_CommandPort_t> port from SM to ISC component */
typedef struct
{
  TargetControlCommand_t *pt_TCC;
}
ISC_TC_CommandPort_t;


/*! Typedef of <ISC_LOC_CommandPort> port from HMI to ISC component */
typedef struct
{
  ACT_LogicVehicleCommand_t *pt_LVC;
}
ISC_LOC_CommandPort_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


#ifdef __cplusplus
};
#endif

#endif /*!< ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT)) */

/* End of conditional inclusion */
#else
#endif  /*!< _ISC_TYPES_INCLUDED */

/** @} end defgroup */
