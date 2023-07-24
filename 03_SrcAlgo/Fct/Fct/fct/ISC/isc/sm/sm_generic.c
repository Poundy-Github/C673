/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/SM (Adaptive Cruise Control - Interface and State Coordinator - State Machine)

PACKAGENAME:               sm_generic.c

DESCRIPTION:               Functions for ... purpose

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             28.08.2017

VERSION:                   $Revision: 1.5 $

---*/ /*---
CHANGES:                    $Log: sm_generic.c  $
CHANGES:                    Revision 1.5 2018/06/21 08:42:23CEST uidj5069 
CHANGES:                    Routing of Standstill Info updated
CHANGES:                    Revision 1.4 2018/04/17 11:50:49CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of Synchronization with CC and TC - disable command deleted
CHANGES:                    Revision 1.3 2017/10/23 16:31:13CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of State Machine Logic by checking new <b_Ready> state of CruiseControl and TargetControl for conditional activation
CHANGES:                    Revision 1.2 2017/10/12 16:45:46CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports and Functionality for Target Control (ACC) added
CHANGES:                    Revision 1.1 2017/10/05 08:35:22CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/sm/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "sm.h"
#if (FCT_CFG_ISC_COMPONENT)


/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

void SM_v_Generic_Process(void)
{
  /* Select SM System State */
  switch (t_SM_LOC_STATE)
  {
  case ISC_SM_STATE_OFF:
  default:

    /* If system command ON is TRUE and OFF is FALSE */
    if (t_SM_IN_SMCP.pt_SMC->t_SYSC.b_On && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Off)
    {
      /* Set STATE to READY */
      t_SM_LOC_STATE = ISC_SM_STATE_READY;
    }
    
    b_SM_LOC_SYS_Enable = FALSE;

    break;


  case ISC_SM_STATE_READY:

    /* If system command OFF is TRUE */
    if (t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Off)
    {
      /* Set STATE to OFF */
      t_SM_LOC_STATE = ISC_SM_STATE_OFF;
    }
    else
    {
#if (FCT_CFG_LOCC_COMPONENT)
      /* If system command ACTIVATE is TRUE and DEACTIVATE is FALSE and all FUNCS are READY => SYS ENABLE Command is set and held */
      b_SM_LOC_SYS_Enable = (b_SM_LOC_SYS_Enable || t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Activate) && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Deactivate
                          && t_SM_IN_CCSP.pt_CCS->b_Ready
#if (FCT_CFG_LOHP_COMPONENT)
                          && t_SM_IN_TCSP.pt_TCS->b_Ready
#endif
                          ;

#if (FCT_CFG_LOHP_COMPONENT)
      /* If CC and TC has been activated */
      if (t_SM_IN_CCSP.pt_CCS->b_Active &&
          t_SM_IN_TCSP.pt_TCS->b_Active)
#else
      /* If CC has been activated */
      if (t_SM_IN_CCSP.pt_CCS->b_Active)
#endif
      {
        /* If CC is in OVERRIDE */
        if (t_SM_IN_CCSP.pt_CCS->b_Override_Accel)
        {
          /* Set STATE to OVERRIDE */
          t_SM_LOC_STATE = ISC_SM_STATE_OVERRIDE;
        }
        else
        {
          /* Set STATE to ACTIVE */
          t_SM_LOC_STATE = ISC_SM_STATE_ACTIVE;
        }
      }
#endif
    }

    break;


  case ISC_SM_STATE_ACTIVE:

#if (FCT_CFG_LOCC_COMPONENT)
    /* If system command DEACTIVATE or OFF is TRUE or any FUNC is not READY => ENABLE Command is cleared and held off */
    b_SM_LOC_SYS_Enable = b_SM_LOC_SYS_Enable && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Deactivate && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Off
                        && t_SM_IN_CCSP.pt_CCS->b_Ready
#if (FCT_CFG_LOHP_COMPONENT)
                        && t_SM_IN_TCSP.pt_TCS->b_Ready
#endif
                        ;

#if (FCT_CFG_LOHP_COMPONENT)
    /* If CC and TC is still active */
    if (t_SM_IN_CCSP.pt_CCS->b_Active &&
        t_SM_IN_TCSP.pt_TCS->b_Active)
#else
    /* If CC is still active */
    if (t_SM_IN_CCSP.pt_CCS->b_Active)
#endif
    {
      /* If CC is in OVERRIDE */
      if (t_SM_IN_CCSP.pt_CCS->b_Override_Accel)
      {
        /* Set STATE to OVERRIDE */
        t_SM_LOC_STATE = ISC_SM_STATE_OVERRIDE;
      }
    }
    else
    {
      /* Set STATE to READY */
      t_SM_LOC_STATE = ISC_SM_STATE_READY;
    }
#else
    t_SM_LOC_STATE = ISC_SM_STATE_READY;
#endif

    break;


  case ISC_SM_STATE_OVERRIDE:

#if (FCT_CFG_LOCC_COMPONENT)
    /* If system command DEACTIVATE or OFF is TRUE or any FUNC is not READY => ENABLE Command is cleared and held off */
    b_SM_LOC_SYS_Enable = b_SM_LOC_SYS_Enable && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Deactivate && !t_SM_IN_SMCP.pt_SMC->t_SYSC.b_Off
                        && t_SM_IN_CCSP.pt_CCS->b_Ready
#if (FCT_CFG_LOHP_COMPONENT)
                        && t_SM_IN_TCSP.pt_TCS->b_Ready
#endif
                        ;

#if (FCT_CFG_LOHP_COMPONENT)
    /* If CC and TC is still active */
    if (t_SM_IN_CCSP.pt_CCS->b_Active &&
        t_SM_IN_TCSP.pt_TCS->b_Active)
#else
    /* If CC is still active */
    if (t_SM_IN_CCSP.pt_CCS->b_Active)
#endif
    {
      /* If CC is no longer in OVERRIDE */
      if (!t_SM_IN_CCSP.pt_CCS->b_Override_Accel)
      {
        /* Set STATE to ACTIVE */
        t_SM_LOC_STATE = ISC_SM_STATE_ACTIVE;
      }
    }
    else
    {
      /* Set STATE to READY */
      t_SM_LOC_STATE = ISC_SM_STATE_READY;
    }
#else
    t_SM_LOC_STATE = ISC_SM_STATE_READY;
#endif

    break;
  }

#if (FCT_CFG_LOCC_COMPONENT)
  /* Select CC Function */
  switch (t_SM_IN_SMCP.pt_SMC->t_CCC.t_Function)
  {
  /* Cruise Control Function */
  case ISC_SM_CC_FUN_CC:
  default:
    t_SM_OUT_CCCP.pt_CCC->t_Function = ACT_CC_FUN_CC;
    break;

  /* Speed Limiter Function */
  case ISC_SM_CC_FUN_LIM:
    t_SM_OUT_CCCP.pt_CCC->t_Function = ACT_CC_FUN_LIM;
    break;
  }

  /* Select CC Operation */
  switch (t_SM_IN_SMCP.pt_SMC->t_CCC.t_Operation)
  {
  /* No change of SetSpeed */
  case ISC_SM_CC_OP_NOP:
  default:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_NOP;
    break;

  /* Set new actual Speed */
  case ISC_SM_CC_OP_SPEED_SET:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_SET_ACT;
    break;

  /* Clear SetSpeed (if system is switched off) */
  case ISC_SM_CC_OP_SPEED_CLEAR:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_CLEAR;
    break;

  /* Increment SetSpeed by 1 kmh */
  case ISC_SM_CC_OP_SPEED_INC_1:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_INC_1;
    break;

  /* Increment SetSpeed by 10 kmh */
  case ISC_SM_CC_OP_SPEED_INC_2:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_INC_2;
    break;

  /* Decrement SetSpeed by 1 kmh */
  case ISC_SM_CC_OP_SPEED_DEC_1:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_DEC_1;
    break;

  /* Decrement SetSpeed by 10 kmh */
  case ISC_SM_CC_OP_SPEED_DEC_2:
    t_SM_LOC_CC_OP_Gen = ACT_CC_OP_SPEED_DEC_2;
    break;
  }
#endif

  /* Output Local Static System State */
  t_SM_OUT_SMSP.pt_SMS->t_SYSS.t_STATE = t_SM_LOC_STATE;
  t_SM_OUT_SMSP.pt_SMS->t_SYSS.b_StandStill = t_SM_IN_LOCSP.pt_LVS->b_StandStill;
  t_SM_OUT_SMSP.pt_SMS->t_SYSS.b_HoldState = t_SM_IN_LOCSP.pt_LVS->b_HoldState;

#if (FCT_CFG_LOCC_COMPONENT)
  /* Output System Command (State) Variables */
  t_SM_OUT_CCCP.pt_CCC->b_Enable = b_SM_LOC_SYS_Enable;

  /* If Operation has been processed by LOCC */
  if (t_SM_IN_CCSP.pt_CCS->t_Operation == t_SM_LOC_CC_OP_Out)
  {
    /* Copy new Operation to Local Output Store */
    t_SM_LOC_CC_OP_Out = t_SM_LOC_CC_OP_Gen;
  }

  /* Output Operation from Local Output Store */
  t_SM_OUT_CCCP.pt_CCC->t_Operation = t_SM_LOC_CC_OP_Out;

  /* Default CC Command */
  t_SM_OUT_CCCP.pt_CCC->u_SetSpeedExt = 0u;


  /* Output Cruise Control State */
  t_SM_OUT_SMSP.pt_SMS->t_CCS.b_SpeedStored = t_SM_IN_CCSP.pt_CCS->b_SpeedStored;
  t_SM_OUT_SMSP.pt_SMS->t_CCS.u_SetSpeed = t_SM_IN_CCSP.pt_CCS->u_SetSpeed;
#else
  /* Output Cruise Control Default State */
  t_SM_OUT_SMSP.pt_SMS->t_CCS.b_SpeedStored = FALSE;
  t_SM_OUT_SMSP.pt_SMS->t_CCS.u_SetSpeed = 0u;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  /* Output SYstem Command (State) Variables */
  t_SM_OUT_TCCP.pt_TCC->b_Enable = b_SM_LOC_SYS_Enable;

  /* Output Headway Setting */
  t_SM_OUT_TCCP.pt_TCC->u_HeadwaySetting = t_SM_IN_SMCP.pt_SMC->t_TCC.u_HeadwaySet;


  /* Output Target Control State */
  t_SM_OUT_SMSP.pt_SMS->t_TCS.b_TakeOverRequest = t_SM_IN_TCSP.pt_TCS->b_ControlAlert;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.b_TargetDetected = t_SM_IN_TCSP.pt_TCS->b_TargetDetected;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_RequestDistance = t_SM_IN_TCSP.pt_TCS->u_DistanceRequested;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_TargetDistance = t_SM_IN_TCSP.pt_TCS->u_DistanceTarget;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_TargetSpeed = t_SM_IN_TCSP.pt_TCS->u_SpeedTarget;
#else
  /* Output Target Control Default State */
  t_SM_OUT_SMSP.pt_SMS->t_TCS.b_TakeOverRequest = FALSE;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.b_TargetDetected = FALSE;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_RequestDistance = 0u;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_TargetDistance = 0u;
  t_SM_OUT_SMSP.pt_SMS->t_TCS.u_TargetSpeed = 0u;
#endif

}

#endif /* FCT_CFG_ISC_COMPONENT */
