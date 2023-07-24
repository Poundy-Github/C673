/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 FCTVEH (Frame Vehicle)

PACKAGENAME:               frame_veh_customfunctions.c

DESCRIPTION:               File containing customer dependent functions for Frame vehicle

AUTHOR:                    Norman Apel

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3.1.4 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "fct_veh.h"

#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_EMERGENCY_BRAKE_ASSIST))
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       frame_veh_customfunctions FCTVEH Custom
@ingroup        frame
@brief          This module contains customer specific functions for ACC function module.
@{
*/
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
 APPLICATION PARAMETERS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    FCTVEHProcessCustomOutput                                                                        */ /*!

  @brief           This function collates information from ACC and EBA components and fill outs the custom output structure.

  @description     This function collates information from ACC and EBA components and fill outs the custom output structure.

                    @startuml
                        Start
                        Partition FCTVEHProcessCustomOutput {
                            : custom coordination of ACC and EBA output;
                        }
                        End
                    @enduml

  @return          void

  @param[in]       void

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   -

  @pre             -
  @post            -

  @created         -
  @changed         12.7.2015

  @author          Patrick Hielscher
*************************************************************************************************************************/
void FCTVEHProcessCustomOutput (void)
{

}
/** @} end defgroup */
#endif/* (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_EMERGENCY_BRAKE_ASSIST) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

