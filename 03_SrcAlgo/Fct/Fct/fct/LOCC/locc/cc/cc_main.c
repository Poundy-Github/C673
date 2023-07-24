/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CCU:                      CPU-Independent

COMPONENT:                 ACC/LOPC/CC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               cc_main.c

DESCRIPTION:               Main functions for CC in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: cc_main.c  $
CHANGES:                    Revision 1.6 2018/06/21 11:23:51CEST uidj5069 
CHANGES:                    Remove residuals of old "Start Coordination"
CHANGES:                    Revision 1.5 2018/06/11 14:11:59CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Remove old "Start Coordination"
CHANGES:                    Revision 1.4 2018/04/17 13:42:02CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    input command <b_Disable> replaced by <!b_Enable>
CHANGES:                    Revision 1.3 2017/11/02 15:46:48CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Implementation of new StateMachine to improve Stop&Go Behaviour
CHANGES:                    Revision 1.2 2017/10/26 17:04:35CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Static Variable <t_CC_StandStillTime> added for Function <CC_v_UpdateStandStill()>
CHANGES:                    Revision 1.1 2017/10/05 08:22:03CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOCC_LongitudinalCruiseControl/04_Engineering/01_Source_Code/LOCC/locc/cc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cc.h"

#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))


/*****************************************************************************
  MODULE CCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE CCAL MACROS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*! @cond Doxygen_Suppress */
SET_MEMSEC_VAR(CC_State)
CC_t_State CC_State;
/*! @endcond Doxygen_Suppress */

/*****************************************************************************
  MODULE CC TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE CC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE CC VARIABLES
*****************************************************************************/

/*! Actual Operation */
  SET_MEMSEC_VAR(t_CC_Operation_Act)
  ACT_CC_OP_t t_CC_Operation_Act;

/*! Activation State */
  SET_MEMSEC_VAR(t_CC_Active_State)
  CC_ActiveState_t t_CC_Active_State;

/*! Engagement State */
  SET_MEMSEC_VAR(t_CC_Engage_State)
  CC_EngageState_t t_CC_Engage_State;

/*! SetSpeed Stored */
  SET_MEMSEC_VAR(b_CC_Speed_Stored)
  boolean b_CC_Speed_Stored;
  
/*! SetSpeed */
  SET_MEMSEC_VAR(u_CC_Set_Speed)
  setspeed_t u_CC_Set_Speed;

/*! Filtered Ego Speed */
  SET_MEMSEC_VAR(f_CC_EgoVeloFilt)
  float f_CC_EgoVeloFilt;


/*! Input Ports required by CC component for processing */
  SET_MEMSEC_VAR(t_CC_IN_CCCP)
  LOCC_CruiseControlCommandPort_t t_CC_IN_CCCP;

  SET_MEMSEC_VAR(t_CC_IN_EVIP)
  LOCC_EgoVehicleInfoPort_t t_CC_IN_EVIP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  SET_MEMSEC_VAR(at_CC_IN_VSSP)
  LOCC_VehicleSpeedStatePort_t at_CC_IN_VSSP[ACT_CFG_CC_VSC_PORT_CNT];

/*! Output Ports provided by CC component after processing */
  SET_MEMSEC_VAR(at_CC_OUT_VSCP)
  LOCC_VehicleSpeedCommandPort_t at_CC_OUT_VSCP[ACT_CFG_CC_VSC_PORT_CNT];
#endif

  SET_MEMSEC_VAR(t_CC_OUT_CCSP)
  LOCC_CruiseControlStatePort_t t_CC_OUT_CCSP;

/*****************************************************************************
  MODULE CC FUNCTIONS
*****************************************************************************/
static void CC_v_SetupPorts(const CC_ReqPortList_t *pRequirePorts, const CC_ProPortList_t *pProvidePorts);

static void CC_v_MeasFreeze(void);
static void CC_v_MeasCallback(void);
static void CC_v_InitEveryCycle(void);
static void CC_v_InitPersistentData(void);

static void CC_v_SetActiveState(void);

/*************************************************************************************************************************
  Functionname:    CC_v_Process                                                                                    */ /*!

  @brief           Main processing function of CC sub-component

  @description     Main processing function of CC sub-component

  @return          void

  @param[in]       pt_CC_InputGlob : Reference to global input struct to CC [defined as per CC_ext.h]

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void CC_v_Process(const CC_ReqPortList_t *pRequirePorts, const CC_ProPortList_t *pProvidePorts)
{
  /* Assign CC port pointers */
  CC_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(CC_State)
  {
  case CC_OK:
    {
      CC_v_InitEveryCycle();

      CC_v_SetActiveState();
      
#if (ACT_CFG_CC_VSC_PORT_CNT >= 1u)
      CC_v_CruiseProcess(0);
#endif

#if (ACT_CFG_CC_VSC_PORT_CNT >= 2u)
      CC_v_CurveProcess(1);
#endif

      break;
    }
  case CC_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    CC_v_InitEveryCycle();
    CC_v_InitPersistentData();
    break;
  }

  /* CC Measurement Freeze */
  CC_v_MeasFreeze();
}

/*************************************************************************************************************************
  Functionname:    CC_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       CC_ReqPortList_pt pRequirePorts
  @param[in]       CC_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         01.06.2017
  @changed         01.06.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void CC_v_SetupPorts(const CC_ReqPortList_t *pRequirePorts, const CC_ProPortList_t *pProvidePorts)
{
/*! Input Ports required by CC component for processing */
  t_CC_IN_CCCP = pRequirePorts->t_CC_IN_CCCP;
  t_CC_IN_EVIP = pRequirePorts->t_CC_IN_EVIP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<ACT_CFG_CC_VSC_PORT_CNT; i++)
  {
    at_CC_IN_VSSP[i] = pRequirePorts->at_CC_IN_VSSP[i];
    at_CC_OUT_VSCP[i] = pProvidePorts->at_CC_OUT_VSCP[i];
  }
}
#endif

/*! Output Ports provided by CC component after processing */
  t_CC_OUT_CCSP = pProvidePorts->t_CC_OUT_CCSP;
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    CC_v_MeasCallback                                                                                   */ /*!

  @brief           Central CC MEASFreezeDataMTS callback function

  @description     Central CC MEASFreezeDataMTS callback function. Since callback information is not used in CC, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CC sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void CC_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */


/*************************************************************************************************************************
  Functionname:    CC_v_MeasFreeze                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       void : 

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         21.04.2017
  @changed         21.04.2017

  @todo            Remove this entire line if not needed

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void CC_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
//  FCT_FREEZE_DATA(pt_CCInput->t_FrameFreezes.pt_CC_DeviceMeasInfoFreeze, pt_CCInput->t_FrameFreezes.pt_CC_DeviceMeasInfo, &CC_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
//  pt_CCInput->t_FrameFreezes.pt_CC_SimMeasInfo->t_CC_FreezeOutput = *(pt_CCOutput);

  /*! Freeze simulation data */
//  FCT_FREEZE_DATA(pt_CCInput->t_FrameFreezes.pt_CC_SimMeasInfoFreeze, pt_CCInput->t_FrameFreezes.pt_CC_SimMeasInfo, CC_v_MeasCallback);
#endif
}


/*************************************************************************************************************************
  Functionname:    CC_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in CC component

  @description     Initialize persistent memory structures in CC component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void CC_v_InitPersistentData(void)
{
  t_CC_Operation_Act = ACT_CC_OP_NOP;
  t_CC_Active_State = CC_AS_PASSIVE;
  t_CC_Engage_State = CC_ES_STANDARD;

  b_CC_Speed_Stored = FALSE;
  u_CC_Set_Speed = 0u;
  f_CC_EgoVeloFilt = 0.0f;
}


/*************************************************************************************************************************
  Functionname:    CC_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for CC component

  @description     Initialize input-output data structures for CC component

  @return          -

  @param[in]       -

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void CC_v_InitEveryCycle(void)
{
  /* Initialize inputs */
}


/*************************************************************************************************************************
  Functionname:    CC_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of CC sub-component

  @description     Set operation mode of CC sub-component based on given value

  @return          -

  @param[in]       t_CCOpModeValue : CC operation mode value [full range of datatype CCState_t as in CC_ext.h]

  @glob_in         CCState : CC operation mode variable [full range of datatype CCState_t as in CC_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOCC_COMPONENT : FCT support for CC sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void CC_v_SetOperationMode(const CC_t_State t_CCOpModeValue)
{
  CC_State = t_CCOpModeValue;
}


/*************************************************************************************************************************
  Functionname:    CC_v_SetActiveState                                                                           */ /*!

  @brief           Set activation state of CC sub-component

  @description     Set activation state of CC sub-component based on command and controller state

  @return          -

  @glob_in         CCState : CC operation mode variable [full range of datatype CCState_t as in CC_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOCC_COMPONENT : FCT support for CC sub-component

  @pre             -
  @post            -

  @created         07.07.2017
  @changed         07.07.2017

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void CC_v_SetActiveState(void)
{
  switch (t_CC_Active_State)
  {
    case CC_AS_PASSIVE:
    default:
      if  (t_CC_IN_CCCP.pt_CCC->b_Enable && !t_CC_IN_CCCP.pt_FD->b_NoEngagement
        && CML_IsInRange(CC_ENG_SPEED_MIN, CC_ENG_SPEED_MAX, (setspeed_t)t_CC_IN_EVIP.pt_EVI->f_LongVeloDisplay))
      {
        t_CC_Active_State = CC_AS_ACTIVE;
        t_CC_Engage_State = CC_ES_AFTER_ENGAGEMENT;
        f_CC_EgoVeloFilt = t_CC_IN_EVIP.pt_EVI->f_LongVeloReal;
      }
      break;

    case CC_AS_ACTIVE:
      if (!t_CC_IN_CCCP.pt_CCC->b_Enable || t_CC_IN_CCCP.pt_FD->b_Disengagement)
      {
        t_CC_Active_State = CC_AS_PASSIVE;
        t_CC_Engage_State = CC_ES_STANDARD;
        f_CC_EgoVeloFilt = 0.0f;
      }
      break;
  }
}


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* (FCT_CFG_LOCC_COMPONENT) && (LOPC_CFG_CC) */

