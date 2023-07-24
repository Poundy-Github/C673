/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTVEH (Frame Vehicle)

MODULNAME:                 fct_veh_error.c

DESCRIPTION:               File containing functions concerning filling of error output for vehicle frame

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.9 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_veh.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer:, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
/**
@defgroup fct_veh_error Fct_Veh_Error
@ingroup frame_veh
@{
*/

/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/


/*****************************************************************************
  MODULLOKALE TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

#if (FCT_CFG_ERROR_OUTPUT_VEH)
/*************************************************************************************************************************
  Functionname:    FCTVehFillErrorOut                                                                               */ /*!

  @brief           Fill FCT error output structure

  @description     Fill FCT error output structure

                    @startuml
                    Start
                      -FCTVehFillErrorOut
                       Note right
                        fct_veh_error.c
                       End note
                      -COU_TEST_FCTVehFillErrorOut
                       Note right
                        test_fct_veh_error.c
                       End note
                    End
                    @enduml

                    <a style="font-weight:bold" href="integrity://ims-adas:7001/si/viewproject?project=%23/ADAS/SW%23Components/FCT_Function%23forceJump%3D%23n%3D%2305_Testing/05_Test_Environment/Dynamic_Tests/FCT/Courage/test_scripts/frame_veh&selection=%22test_fct_veh_error.c%22">Test_Script_path</a>

  @return           void

  @param[in,out]   pDest : the error output structure to fill 
                    pDest->uiVersionNumber         [all valid entries are defined bz typedef InterfaceVersion in Rte_SWCFctSenAdapt_Type.h]
                    pDest->YawRateUnplausible      [AlgoErrorState_t as in Rte_Type.h]
                    pDest->VehicleSpeedUnplausible [AlgoErrorState_t as in Rte_Type.h]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ERROR_OUTPUT_VEH : FCT error output from FCT_VEH

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    -

  @created         -
  @changed         12/7/2015

  @author          Gergely Ungvary | gergely.ungvary@continental-corporation.com
*************************************************************************************************************************/
void FCTVehFillErrorOut(FCTVehErrorOut_t * pDest)
{
  /* Set output version number */
  pDest->uiVersionNumber          = FCT_VEH_ERROR_OUT_INTFVER;
  /* Set output states */
  pDest->YawRateUnplausible       = AL_ERR_STATE_UNKNOWN;
  pDest->VehicleSpeedUnplausible  = AL_ERR_STATE_UNKNOWN;
}
#endif  /* #if (FCT_CFG_ERROR_OUTPUT_VEH) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */

