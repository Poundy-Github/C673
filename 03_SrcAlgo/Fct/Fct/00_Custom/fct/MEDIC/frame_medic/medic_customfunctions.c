/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_customfunctions.c

DESCRIPTION:               Custom Functions for MEDIC component

AUTHOR:                    $Author: Veerashettappa, Nagaraja (uidp9076) $

CREATION DATE:             $Date: 2020/07/01 13:35:12CEST $

VERSION:                   $Revision: 1.11 $

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
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
  FUNCTION 
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         MEDICProcessCustomOutput                                                             */ /*!

  @brief                Medic customer output function 
                
  @description          Implementation of the Medic process customer function Implementation 
                        @startuml
                        Start
                        :need to be updated;
                        Stop
                        @enduml

  @return               void
 
  @param[in]            void: No Input 


  @glob_in              None 
  @glob_out             None 

  @c_switch_part        None 
  @c_switch_full        MEDIC_CFG_EMERGENCY_BRAKE_ASSIST

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not Applicable
  
  @testmethod           Test of output data (dynamic module test) 

  @traceability         Design Decision
  
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
void MEDICProcessCustomOutput (void)
{
    /*Do Nothing*/
}

#endif  /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */

