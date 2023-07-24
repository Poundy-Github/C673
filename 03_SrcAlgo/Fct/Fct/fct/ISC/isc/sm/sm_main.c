/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/SM (Adaptive Cruise Control - Interface and State Coordinator - State Machine)

PACKAGENAME:               sm_main.c

DESCRIPTION:               Main functions for SM in ISC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

---*/ /*---
CHANGES:                    $Log: sm_main.c  $
CHANGES:                    Revision 1.6 2018/06/27 10:08:36CEST uidj5069 
CHANGES:                    Initialization of State Input Port from LOC added
CHANGES:                    Revision 1.5 2018/06/21 08:45:28CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional State Input Port from LOC
CHANGES:                    Revision 1.4 2018/04/16 16:35:06CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Static variable <b_SM_LOC_SYS_Disable> removed
CHANGES:                    Revision 1.3 2017/10/23 16:31:26CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of State Machine Logic by checking new <b_Ready> state of CruiseControl and TargetControl for conditional activation
CHANGES:                    Revision 1.2 2017/10/12 16:46:14CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports and Functionality for Target Control (ACC) added
CHANGES:                    Revision 1.1 2017/10/05 08:35:23CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/sm/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sm.h"

#if (FCT_CFG_ISC_COMPONENT)


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
SET_MEMSEC_VAR(SM_State)
SM_t_State SM_State;
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

/*! Input Ports required by SM component for processing */
SET_MEMSEC_VAR(t_SM_IN_SMCP)
ISC_SM_CommandPort_t t_SM_IN_SMCP;

#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_SM_IN_CCSP)
  ISC_CC_StatePort_t t_SM_IN_CCSP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SET_MEMSEC_VAR(t_SM_IN_TCSP)
  ISC_TC_StatePort_t t_SM_IN_TCSP;
#endif

SET_MEMSEC_VAR(t_SM_IN_LOCSP)
ISC_LOC_StatePort_t t_SM_IN_LOCSP;

/*! Output Ports provided by SM component after processing */
#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_SM_OUT_CCCP)
  ISC_CC_CommandPort_t t_SM_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SET_MEMSEC_VAR(t_SM_OUT_TCCP)
  ISC_TC_CommandPort_t t_SM_OUT_TCCP;
#endif

SET_MEMSEC_VAR(t_SM_OUT_SMSP)
ISC_SM_StatusPort_t t_SM_OUT_SMSP;


/*! Static Local System Command State Variables */
SET_MEMSEC_VAR(b_SM_LOC_SYS_Enable)
boolean b_SM_LOC_SYS_Enable;

/*! Static Local System State Variable */
SET_MEMSEC_VAR(t_SM_LOC_STATE)
ISC_SM_STATE_t t_SM_LOC_STATE;


/*! Static Local CC Command State Variables */
#if (FCT_CFG_LOCC_COMPONENT)
  SET_MEMSEC_VAR(t_SM_LOC_CC_OP_Gen)
  ACT_CC_OP_t t_SM_LOC_CC_OP_Gen;

  SET_MEMSEC_VAR(t_SM_LOC_CC_OP_Out)
  ACT_CC_OP_t t_SM_LOC_CC_OP_Out;
#endif

/*! Static Local TC Command State Variables */
#if (FCT_CFG_LOHP_COMPONENT)
#endif

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void SM_v_SetupPorts(const SM_ReqPortList_t *pRequirePorts, const SM_ProPortList_t *pProvidePorts);

static void SM_v_MeasFreeze(void);
static void SM_v_MeasCallback(void);
static void SM_v_InitEveryCycle(void);
static void SM_v_InitPersistentData(void);

/*************************************************************************************************************************
  Functionname:    SM_v_Process                                                                                    */ /*!

  @brief           Main processing function of SM sub-component

  @description     Main processing function of SM sub-component

  @return          void

  @param[in]       pt_SM_InputGlob : Reference to global input struct to SM [defined as per sm_ext.h]

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void SM_v_Process(const SM_ReqPortList_t *pRequirePorts, const SM_ProPortList_t *pProvidePorts)
{
  /* Assign SM port pointers */
  SM_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(SM_State)
  {
  case SM_OK:
    {
      SM_v_InitEveryCycle();

      /* Calling of all functions to be done here in order */
      SM_v_Generic_Process();
      SM_v_Custom_Process();

      break;
    }
  case SM_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    SM_v_InitEveryCycle();
    SM_v_InitPersistentData();
    break;
  }

  /* SM Measurement Freeze */
  SM_v_MeasFreeze();
}

#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    SM_v_MeasCallback                                                                                   */ /*!

  @brief           Central SM MEASFreezeDataMTS callback function

  @description     Central SM MEASFreezeDataMTS callback function. Since callback information is not used in SM, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for SM sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void SM_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */

/*************************************************************************************************************************
  Functionname:    SM_v_MeasFreeze                                                                                 */ /*!

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
static void SM_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
  //FCT_FREEZE_DATA(pt_SMInput->t_FrameFreezes.pt_SM_DeviceMeasInfoFreeze, pt_SMInput->t_FrameFreezes.pt_SM_DeviceMeasInfo, &SM_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
  //pt_SMInput->t_FrameFreezes.pt_SM_SimMeasInfo->t_SM_FreezeOutput = *(pt_SMOutput);

  /*! Freeze simulation data */
  //FCT_FREEZE_DATA(pt_SMInput->t_FrameFreezes.pt_SM_SimMeasInfoFreeze, pt_SMInput->t_FrameFreezes.pt_SM_SimMeasInfo, SM_v_MeasCallback);
#endif
}

/*************************************************************************************************************************
  Functionname:    SM_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in SM component

  @description     Initialize persistent memory structures in SM component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void SM_v_InitPersistentData(void)
{
  b_SM_LOC_SYS_Enable = FALSE;
  t_SM_LOC_STATE = ISC_SM_STATE_OFF;

#if (FCT_CFG_LOCC_COMPONENT)
  t_SM_LOC_CC_OP_Gen = ACT_CC_OP_NOP;
  t_SM_LOC_CC_OP_Out = ACT_CC_OP_NOP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
#endif
}

/*************************************************************************************************************************
  Functionname:    SM_v_InitEveryCycle                                                                             */ /*!

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
static void SM_v_InitEveryCycle(void)
{
  /* Initialize inputs every cycle */
}

/*************************************************************************************************************************
  Functionname:    SM_v_SetupPorts                                                                                   */ /*!

  @brief           Set/assign values to SM input structure

  @description     Set/assign values to SM input structure

  @return          -

  @param[in]       -

  @glob_in         
  @glob_out        pt_SMInput : SM input data structure

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void SM_v_SetupPorts(const SM_ReqPortList_t *pRequirePorts, const SM_ProPortList_t *pProvidePorts)
{
  /*! Input Ports required by SM component for processing */
  t_SM_IN_SMCP = pRequirePorts->t_SM_IN_SMCP;

#if (FCT_CFG_LOCC_COMPONENT)
  t_SM_IN_CCSP = pRequirePorts->t_SM_IN_CCSP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  t_SM_IN_TCSP = pRequirePorts->t_SM_IN_TCSP;
#endif

  t_SM_IN_LOCSP = pRequirePorts->t_SM_IN_LOCSP;


  /*! Output Ports provided by SM component after processing */
#if (FCT_CFG_LOCC_COMPONENT)
  t_SM_OUT_CCCP = pProvidePorts->t_SM_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  t_SM_OUT_TCCP = pProvidePorts->t_SM_OUT_TCCP;
#endif

  t_SM_OUT_SMSP = pProvidePorts->t_SM_OUT_SMSP;
}

/*************************************************************************************************************************
  Functionname:    SM_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of SM sub-component

  @description     Set operation mode of SM sub-component based on given value

  @return          -

  @param[in]       t_SMOpModeValue : SM operation mode value [full range of datatype SMState_t as in sm_ext.h]

  @glob_in         SMState : SM operation mode variable [full range of datatype SMState_t as in sm_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SMC_COMPONENT : FCT support for SM sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void SM_v_SetOperationMode(const SM_t_State t_SMOpModeValue)
{
  SM_State = t_SMOpModeValue;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* (FCT_CFG_ISC_COMPONENT) */

