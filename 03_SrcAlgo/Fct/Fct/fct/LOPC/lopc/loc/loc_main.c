/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

LOCU:                      CPU-Independent

COMPONENT:                 ACC/LOPC/LOC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               loc_main.c

DESCRIPTION:               Main functions for LOC in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---
CHANGES:                    $Log: loc_main.c  $
CHANGES:                    Revision 1.2 2018/06/12 10:52:09CEST uidj5069 
CHANGES:                    New Start Coordination Function added
CHANGES:                    Revision 1.1 2017/10/05 09:05:32CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC_LongitudinalPlannerAndController/04_Engineering/01_Source_Code/LOPC/lopc/loc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:44CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.1 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "loc.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC))


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
SET_MEMSEC_VAR(LOC_State)
LOC_t_State LOC_State;
/*! @endcond Doxygen_Suppress */

/*! Declaration of pointers to LOC input ports for access within this component */
SET_MEMSEC_VAR(t_LOC_IN_IVCP)
LOPC_IdealVehicleCommandPort_t t_LOC_IN_IVCP;

SET_MEMSEC_VAR(t_LOC_IN_LVCP)
LOPC_LogicVehicleCommandPort_t t_LOC_IN_LVCP;

SET_MEMSEC_VAR(t_LOC_IN_EVSP)
LOPC_EgoVehicleStatePort_t t_LOC_IN_EVSP;


/*! Declaration of pointers to LOC output ports for access within this component */
SET_MEMSEC_VAR(t_LOC_OUT_IVSP)
LOPC_IdealVehicleStatePort_t t_LOC_OUT_IVSP;

SET_MEMSEC_VAR(t_LOC_OUT_LVSP)
LOPC_LogicVehicleStatePort_t t_LOC_OUT_LVSP;

SET_MEMSEC_VAR(t_LOC_OUT_EVCP)
LOPC_EgoVehicleCommandPort_t t_LOC_OUT_EVCP;

/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL FUNCTIONS
*****************************************************************************/
static void LOC_v_SetupPorts(const LOC_ReqPortList_t *pRequirePorts, const LOC_ProPortList_t *pProvidePorts);

static void LOC_v_MeasFreeze(void);
static void LOC_v_MeasCallback(void);
static void LOC_v_InitEveryCycle(void);
static void LOC_v_InitPersistentData(void);

/*************************************************************************************************************************
  Functionname:    LOC_v_Process                                                                                    */ /*!

  @brief           Main processing function of LOC sub-component

  @description     Main processing function of LOC sub-component

  @return          void

  @param[in]       pt_LOC_InputGlob : Reference to global input struct to LOC [defined as per LOC_ext.h]

  @glob_in         -

  @created         -
  @changed         12/11/2015

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOC_v_Process(const LOC_ReqPortList_t *pRequirePorts, const LOC_ProPortList_t *pProvidePorts)
{
  /* Assign local pointers */
  LOC_v_SetupPorts(pRequirePorts, pProvidePorts);

  switch(LOC_State)
  {
  case LOC_OK:
    {
      LOC_v_InitEveryCycle();

      /* Calling of all functions to be done here in order */
      LOC_v_IdealVehicleControl_Process (FCT_VEH_CYCLE_TIME, &t_LOC_MotState,
                                         &t_LOC_IN_IVCP, &t_LOC_IN_LVCP, &t_LOC_IN_EVSP,
                                         &t_LOC_OUT_IVSP, &t_LOC_OUT_LVSP, &t_LOC_OUT_EVCP);

      LOC_v_Custom_Process();

      break;
    }
  case LOC_INIT:
    /*! Initialization */
    /* DO NOT enter any line of code here !!!
    This case is meant to fall through to DEFAULT, in case this should change, call INIT here!!! */
  default:
    LOC_v_InitEveryCycle();
    LOC_v_InitPersistentData();
    break;
  }

  /* LOC Measurement Freeze */
  LOC_v_MeasFreeze();

  /* Reset local pointers */
}

/*************************************************************************************************************************
  Functionname:    LOC_v_SetupPorts                                                                                 */ /*!

  @brief           Functional Summary

  @description     Detailed Design

  @return          static void

  @param[in]       LOC_ReqPortList_pt pRequirePorts
  @param[in]       LOC_ProPortList_pt pProvidePorts

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -


  @created         01.06.2017
  @changed         01.06.2017

  @todo            Remove this entire line if not needed

  @author          Wolfgang Borgs | wolfgang.borgs@continental-corporation.com | +49-8382-9699-839
*************************************************************************************************************************/
static void LOC_v_SetupPorts(const LOC_ReqPortList_t *pRequirePorts, const LOC_ProPortList_t *pProvidePorts)
{
  t_LOC_IN_IVCP = pRequirePorts->t_LOC_IN_IVCP;
  t_LOC_IN_LVCP = pRequirePorts->t_LOC_IN_LVCP;
  t_LOC_IN_EVSP = pRequirePorts->t_LOC_IN_EVSP;

  t_LOC_OUT_IVSP = pProvidePorts->t_LOC_OUT_IVSP;
  t_LOC_OUT_LVSP = pProvidePorts->t_LOC_OUT_LVSP;
  t_LOC_OUT_EVCP = pProvidePorts->t_LOC_OUT_EVCP;

  return;
}


#if (FCT_MEASUREMENT)
/*************************************************************************************************************************
  Functionname:    LOC_v_MeasCallback                                                                                   */ /*!

  @brief           Central LOC MEASFreezeDataMTS callback function

  @description     Central LOC MEASFreezeDataMTS callback function. Since callback information is not used in LOC, this is 
                   just an empty shell, to keep MEASFreezeDataMTS from buffering SI internal data frozen.

  @c_switch_part   -
  @c_switch_full   FCT_MEASUREMENT : Configuration switch to activate Measurement Output Code
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for LOC sub-component

  @pre             -
  @post            -

  @created         -
  @changed         07.03.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOC_v_MeasCallback(void)
{
  return;
}
#endif /* FCT_MEASUREMENT */


/*************************************************************************************************************************
  Functionname:    LOC_v_MeasFreeze                                                                                 */ /*!

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
static void LOC_v_MeasFreeze(void)
{

  /*! Get data for measurement freeze in device */

  /*! Freeze device data */
//  FCT_FREEZE_DATA(pt_LOCInput->t_FrameFreezes.pt_LOC_DeviceMeasInfoFreeze, pt_LOCInput->t_FrameFreezes.pt_LOC_DeviceMeasInfo, &LOC_v_MeasCallback);

#ifdef FCT_SIMU
  /*! Get data for measurement freeze in simulation */
//  pt_LOCInput->t_FrameFreezes.pt_LOC_SimMeasInfo->t_LOC_FreezeOutput = *(pt_LOCOutput);

  /*! Freeze simulation data */
//  FCT_FREEZE_DATA(pt_LOCInput->t_FrameFreezes.pt_LOC_SimMeasInfoFreeze, pt_LOCInput->t_FrameFreezes.pt_LOC_SimMeasInfo, LOC_v_MeasCallback);
#endif

}
/*************************************************************************************************************************
  Functionname:    LOC_v_InitPersistentData                                                                         */ /*!

  @brief           Initialize persistent memory structures in LOC component

  @description     Initialize persistent memory structures in LOC component

  @return          -

  @param[in]       -


  @created         25.10.2016
  @changed         25.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOC_v_InitPersistentData(void)
{
  /* Initialize Standstill Time */
  t_StandstillTime = (times_t)0u;

  /* Initialize Motion State */
  if (t_LOC_IN_EVSP.pt_EVS->b_Standstill)
  {
    t_LOC_MotState = LOC_MS_HOLD;
  }
  else
  {
    t_LOC_MotState = LOC_MS_MOVE;
  }

}
/*************************************************************************************************************************
  Functionname:    LOC_v_InitEveryCycle                                                                             */ /*!

  @brief           Initialize input-output data structures for LOC component

  @description     Initialize input-output data structures for LOC component

  @return          -

  @param[in]       -

  @pre             None
  @post            No changes

  @created         07.10.2016
  @changed         07.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void LOC_v_InitEveryCycle(void)
{
  /* Initialize inputs */
}

/*************************************************************************************************************************
  Functionname:    LOC_v_SetOperationMode                                                                           */ /*!

  @brief           Set operation mode of LOC sub-component

  @description     Set operation mode of LOC sub-component based on given value

  @return          -

  @param[in]       t_LOCOpModeValue : LOC operation mode value [full range of datatype LOCState_t as in LOC_ext.h]

  @glob_in         LOCState : LOC operation mode variable [full range of datatype LOCState_t as in LOC_ext.h]
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : FCT support for LOC sub-component

  @pre             -
  @post            -

  @created         28.10.2016
  @changed         28.10.2016

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void LOC_v_SetOperationMode(const LOC_t_State t_LOCOpModeValue)
{
  LOC_State = t_LOCOpModeValue;
}

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

#endif /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC) */

