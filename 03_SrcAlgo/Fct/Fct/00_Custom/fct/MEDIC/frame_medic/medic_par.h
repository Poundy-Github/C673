/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_par.h

DESCRIPTION:               parameter File for MEDIC component

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2020/11/13 15:54:30CET $

VERSION:                   $Revision: 1.15 $

**************************************************************************** */

#ifndef MEDIC_PAR_H_INCLUDED
#define MEDIC_PAR_H_INCLUDED

#if(MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)

#if MEDIC_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/******************************************************************************
  fct_io.c parameters
******************************************************************************/
/*PRQA S 3614 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
/*PRQA S 0844 EOF #date: 2020-06-11, reviewer: Nalina M, reason: Supressing because there is no impact on software*/
/* Number of acceptable frame drops (1 means error flag if more than one frame drops) */
#define FCT_INPUT_ACCEPTABLE_DROPS  1u

#define FCT_SEN_TARGET_CYCLE_TIME   0.06f
#define FCT_VEH_TARGET_CYCLE_TIME   0.02f
#define FCT_NORM_TARGET_CYCLE_TIME  FCT_VEH_TARGET_CYCLE_TIME 
#define MILLION                     1000000u

#endif

/************************************************************************/
/*                       COMMON MACROS                                  */
/************************************************************************/

/*  @brief  Used to convert the given timestamp to Microseconds*/
#define MEDIC_TIMESTAMP_TO_MICROSECONDS       (1000000.0f)


/******************************************************************************
  medic_io.c parameters
******************************************************************************/
/*! @brief Number of acceptable frame drops (1 means error flag if more than one frame drops) */
#define FCT_INPUT_ACCEPTABLE_DROPS            (1u)

/*! @brief        Number of subcomponents inside MEDIC
    @description  (see enum @ref MEDICSubCompIndices_t) */
#define MEDIC_NOF_SUB_COMPONENTS              (3u)

/**@defgroup frame_subcomponents
@description defines to identifiy each subcomponent in the bitfield @ref MEDICSubCompIndices_t
@{*/
#define MEDIC_SUB_COMP_NONE                   (0u)
#define MEDIC_SUB_COMP_DIM                    (1u)
#define MEDIC_SUB_COMP_HEAD                   (2u)
#define MEDIC_SUB_COMP_MEDIC                  (4u)
#define MEDIC_SUB_COMP_ALL                    (255u)

/*! @brief      Enables the override of input sensor contribution
    @general    If this external parameter is set to non zero value,
                the senor contribution signal is overriden by all sensors are set.
    @conseq     0: The input sensor contribution is affecting the reaction as designed in HEAD-Cfg
                1: The input sensor contribution has not effect on activation
    @attention  -
    @typical 0  @unit  -   @min 0u   @max 1u   */
#define MEDIC_PAR_SET_ALL_SENS_CONTRIBUTION  MedicParSetAllSensContribution_c

/* The default value is zero, so that the effect of sensor contribition is following
   the design in head configuration*/
#define MEDIC_PAR_SET_ALL_SENS_CONT_VALUE 0u
/* Declare the parameter as extern */
MEDIC_DECL_ADJ_PARAM(MEMSEC_REF uint32, MEDIC_PAR_SET_ALL_SENS_CONTRIBUTION)

/*@} */
#endif/*MEDIC_CFG_EMERGENCY_BRAKE_ASSIST*/
#endif/*MEDIC_PAR_H_INCLUDED*/


