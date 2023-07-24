/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_main.c

DESCRIPTION:               Main functions for TC in LOHP

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: tc_main.c  $
CHANGES:                    Revision 1.6 2018/11/06 16:22:52CET uidj5069 
CHANGES:                    Implementation of "Target Follower System" for reference distance generation
CHANGES:                    Revision 1.5 2018/04/17 14:09:36CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Input command <b_Disable> replaced by <!b_Enable>
CHANGES:                    Revision 1.4 2017/11/21 10:39:43CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.3 2017/11/20 12:55:16CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Renaming to RTE Port Type Names
CHANGES:                    Revision 1.2 2017/10/17 13:58:56CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Target Control Functionality
CHANGES:                    Revision 1.1 2017/10/05 09:47:42CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/01_Source_Code/LOHP/lohp/tc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "tc.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))


/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*! @cond Doxygen_Suppress */
SET_MEMSEC_VAR(TC_State)
TC_t_State TC_State;
/*! @endcond Doxygen_Suppress */

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*! Last TimeStamp of Runnable */
  SET_MEMSEC_VAR(u_TC_TimeStamp)
	AlgoDataTimeStamp_t u_TC_TimeStamp;

/*! Last Cycle Time of Runnable */
  SET_MEMSEC_VAR(f_TC_CycleTime)
  float32 f_TC_CycleTime;

/*! Activation State */
  SET_MEMSEC_VAR(t_TC_Active_State)
  TC_ActiveState_t t_TC_Active_State;

/*! Engagement State */
  SET_MEMSEC_VAR(t_TC_Engage_State)
  TC_EngageState_t t_TC_Engage_State;

/*! Reference Target Follower State */
  SET_MEMSEC_VAR(t_TC_Target_Follower)
  TC_RefTargetFollower_t at_TC_Target_Follower[FCT_CFG_HP_TFC_PORT_CNT];

/*! Input Ports required by TC component for processing */
  SET_MEMSEC_VAR(t_TC_IN_TCCP)
  LOHP_TargetControlCommandPort_t t_TC_IN_TCCP;

  SET_MEMSEC_VAR(t_TC_IN_EVIP)
  LOHP_EgoVehicleInfoPort_t t_TC_IN_EVIP;

  SET_MEMSEC_VAR(t_TC_IN_TVIP)
  LOHP_TargetVehicleInfoPort_t t_TC_IN_TVIP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
  SET_MEMSEC_VAR(at_TC_IN_TFSP)
  LOHP_TargetFollowStatePort_t at_TC_IN_TFSP[FCT_CFG_HP_TFC_PORT_CNT];

/*! Output Ports provided by TC component after processing */
  SET_MEMSEC_VAR(at_TC_OUT_TFCP)
  LOHP_TargetFollowCommandPort_t at_TC_OUT_TFCP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

  SET_MEMSEC_VAR(t_TC_OUT_TCSP)
  LOHP_TargetControlStatePort_t t_TC_OUT_TCSP;

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void TC_v_SetupPorts(const TC_ReqPortList_t *pRequirePorts, const TC_ProPortList_t *pProvidePorts);

static void TC_v_MeasFreeze(void);
static void TC_v_MeasCallback(void);
static void TC_v_InitEveryCycle(void);
static void TC_v_InitPersistentData(void);

static void TC_v_SetActiveState(void);

/*************************************************************************************************************************
  Functionname:    TC_v_Process                                                                                    */ /*!

  @brief           Main processing function of TC sub-component

  @description     Main processing function of TC sub-component

  @return          void

  @param[in]       pt_TC_InputGlob : Reference to global input struct to TC [defined as per tc_ext.h]

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void TC_v_Process(const TC_ReqPortList_t *pRequirePorts, const TC_ProPortList_t *pProvidePorts)
{
  /* Assign TC port pointers */
  TC_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(TC_State)
  {
  case TC_OK:
    {
      TC_v_InitEveryCycle();

      TC_v_SetActiveState();
      
      /* Calling of all functions to be done here in order */
      TC_v_Generic_Process();
      TC_v_Custom_Process();

      break;
    }
  case TC_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    TC_v_InitEveryCycle();
    TC_v_InitPersistentData();
    break;
  }

  /* SM Measurement Freeze */
  TC_v_MeasFreeze();
}

/*************************************************************************************************************************
  Functionname:    TC_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       TC_ReqPortList_pt pRequirePorts
  @param[in]       TC_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         07.09.2017
  @changed         07.09.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void TC_v_SetupPorts(const TC_ReqPortList_t *pRequirePorts, const TC_ProPortList_t *pProvidePorts)
{
/*! Input Ports required by TC component for processing */
  t_TC_IN_TCCP = pRequirePorts->t_TC_IN_TCCP;
  t_TC_IN_EVIP = pRequirePorts->t_TC_IN_EVIP;
  t_TC_IN_TVIP = pRequirePorts->t_TC_IN_TVIP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
{
  uint8 i;
  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    at_TC_IN_TFSP[i] = pRequirePorts->at_TC_IN_TFSP[i];
    at_TC_OUT_TFCP[i] = pProvidePorts->at_TC_OUT_TFCP[i];
  }
}
#endif

/*! Output Ports provided by TC component after processing */
  t_TC_OUT_TCSP = pProvidePorts->t_TC_OUT_TCSP;
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    TC_v_MeasCallback                                                                                   */ /*!

  @brief           Central TC MEASFreezeDataMTS callback function

  @description     Central TC MEASFreezeDataMTS callback function. Since callback information is not used in TC, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for TC sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void TC_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */

/*************************************************************************************************************************
  Functionname:    TC_v_MeasFreeze                                                                                 */ /*!

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
static void TC_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
  //FCT_FREEZE_DATA(pt_TCInput->t_FrameFreezes.pt_TC_DeviceMeasInfoFreeze, pt_TCInput->t_FrameFreezes.pt_TC_DeviceMeasInfo, &TC_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  //pt_TCInput->t_FrameFreezes.pt_TC_SimMeasInfo->t_TC_FreezeOutput = *(pt_TCOutput);

  /*! Freeze simulation data */
  //FCT_FREEZE_DATA(pt_SMInput->t_FrameFreezes.pt_TC_SimMeasInfoFreeze, pt_TCInput->t_FrameFreezes.pt_TC_SimMeasInfo, TC_v_MeasCallback);
#endif
}

/*************************************************************************************************************************
  Functionname:    TC_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in TC component

  @description     Initialize persistent memory structures in TC component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void TC_v_InitPersistentData(void)
{
  uint8 i;

  u_TC_TimeStamp = 0u;
  f_TC_CycleTime = 0.06f;

  t_TC_Active_State = TC_AS_PASSIVE;
  t_TC_Engage_State = TC_ES_STANDARD;

  for (i=0; i<FCT_CFG_HP_TFC_PORT_CNT; i++)
  {
    at_TC_Target_Follower[i].s_ObjectID = OBJ_INDEX_NO_OBJECT;
    at_TC_Target_Follower[i].f_Distance = 0.0f;
    at_TC_Target_Follower[i].f_Velocity = 0.0f;
    at_TC_Target_Follower[i].f_Acceleration = 0.0f;
  }
}

/*************************************************************************************************************************
  Functionname:    TC_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for SM component

  @description     Initialize input-output data structures for SM component

  @return          -

  @param[in]       -

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void TC_v_InitEveryCycle(void)
{
  /* Initialize inputs every cycle */

  /* If TimeStamp has Init Value */
  if (u_TC_TimeStamp == 0u)
  {
    /* Set Default Cycle Time */
    f_TC_CycleTime = 0.06f;
  }
  else
  {
    /* Eval Cycle Time from TimeStamp Difference */
    f_TC_CycleTime = (float32)(t_TC_IN_TVIP.pt_SigHeader->uiTimeStamp - u_TC_TimeStamp) * 1e-6f;
  }

  /* Store actual TimeStamp */
  u_TC_TimeStamp = t_TC_IN_TVIP.pt_SigHeader->uiTimeStamp;
}

/*************************************************************************************************************************
  Functionname:    TC_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of SM sub-component

  @description     Set operation mode of SM sub-component based on given value

  @return          -

  @param[in]       t_SMOpModeValue : SM operation mode value [full range of datatype SMState_t as in sm_ext.h]

  @glob_in         SMState : SM operation mode variable [full range of datatype SMState_t as in sm_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SMC_COMPONENT : FCT support for TC sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void TC_v_SetOperationMode(const TC_t_State t_TCOpModeValue)
{
  TC_State = t_TCOpModeValue;
}

/*************************************************************************************************************************
  Functionname:    TC_v_SetActiveState                                                                           */ /*!

  @brief           Set activation state of TC sub-component

  @description     Set activation state of TC sub-component based on command and controller state

  @return          -

  @glob_in         TCState : TC operation mode variable [full range of datatype TCState_t as in TC_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOHP_COMPONENT : FCT support for TC sub-component

  @pre             -
  @post            -

  @created         07.07.2017
  @changed         07.07.2017

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49 (8382) 9699-839
*************************************************************************************************************************/
void TC_v_SetActiveState(void)
{
  switch (t_TC_Active_State)
  {
    case TC_AS_PASSIVE:
    default:
      if  (t_TC_IN_TCCP.pt_TCC->b_Enable &&
          !t_TC_IN_TCCP.pt_FD->b_NoEngagement && t_TC_IN_TVIP.pt_TVI->b_Valid)
      {
        t_TC_Active_State = TC_AS_ACTIVE;
        if (t_TC_IN_TVIP.pt_TVI->AccOOINextLong.Attributes.uiObjectID != OBJ_INDEX_NO_OBJECT)
        {
          t_TC_Engage_State = TC_ES_AFTER_ENGAGEMENT;
        }
        else
        {
          t_TC_Engage_State = TC_ES_STANDARD;
        }
      }
      break;

    case TC_AS_ACTIVE:
      if (!t_TC_IN_TCCP.pt_TCC->b_Enable || t_TC_IN_TCCP.pt_FD->b_Disengagement || !t_TC_IN_TVIP.pt_TVI->b_Valid)
      {
        t_TC_Active_State = TC_AS_PASSIVE;
        t_TC_Engage_State = TC_ES_STANDARD;
      }
      break;
  }
}


/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC)) */

