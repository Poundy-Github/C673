/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 SLATE_CP (Course Prediction)

MODULNAME:                 cp_par.c

DESCRIPTION:               Course prediction parameters

AUTHOR:                    $Author: Vemula, Radhakrishna (uidj7535) $

CREATION DATE:             09.11.2009

  VERSION:                $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.9

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cp.h"
#if (FCT_CFG_COURSE_PREDICTION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup cp_par
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
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
static void CP_v_DummyForCompiler (void);


/*****************************************************************************
  FUNCTIONS
*****************************************************************************/


/* **********************************************************************
  @fn              CP_v_DummyForCompiler */ /*! 

  @brief           Dummy

  @description     --

                    @startuml
                        Start
                            Partition CP_v_DummyForCompiler {
                                -Dummy function for compilation purpose
                            }
                        End
                    @enduml

  @todo            remove if any other functionality is implemented in this module
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @author          N.Apel
**************************************************************************** */
static void CP_v_DummyForCompiler (void)//PRQA S 3219
  /* date: 2015-05-07, reviewer: Gangadhar Badiger, reason: No side effect */

{
  return;
}
/* <ln_offset:-4 PCLINT Error 528: reviewer name: Norman Apel date: 14-09-2012 reason: Dummy function is defined to avoid empty C file */
/// @} 
#endif /* FCT_CFG_COURSE_PREDICTION */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
