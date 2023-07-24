/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 Adaptive Cruise Control (ACC)

PACKAGENAME:               slate_error.c

DESCRIPTION:               Adaptive Cruise Control (ACC) error output filling module SLATE

AUTHOR:                    $Author: uib05783 $

CREATION DATE:             15.02.2017

VERSION:                   $Revision: 1.10 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */ 


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h" /*  PRQA S 0380 */
/* date: 2019-07-01, reviewer: Karthik Chittepu, reason: This does not have any effect on functionality */

#if ((FCT_CFG_SLATE_COMPONENT) && (FCT_CFG_ERROR_OUTPUT_SEN))
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup slate_error Error
@ingroup frame
@brief        Contains functions for the error handling of the SLATE component.\n\n
@description  ...
@{
*/

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/


/*************************************************************************************************************************
  Functionname:    SLATE_v_FillErrorOut                                                                               */ /*!

  @brief           Fill SLATE error output structure

  @description     Fill SLATE error output structure
                   @startuml
                   Start
	               Partition SLATE_v_FillErrorOut
                   If(FCT SI sub-componentr is in active state and assessed object list signal status is OK) Then (True)
                    -set object selection active
                   else 
                    -set object selection inactive state
                   Endif
                   Partition APM_v_FillSenErrors
                  -Set ACC error output structure based on APM errors for FCT_SEN task
                  end
                 @enduml


  @return          -

  @param[out]      pt_ErrorOut : Reference to ACC error output structure that is filled in this function
                      pt_ErrorOut->uiVersionNumber : InterfaceVersion                     [Full range of datatype unsigned long]
                      pt_ErrorOut->sSigHeader.eSigStatus : Algo signal state enumeration  [AlgoSignalState_t as defined in Rte_Type.h]
                      pt_ErrorOut->bObjSelectionActive :                                  [TRUE, FALSE]

  @glob_in         GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.eSigStatus        [AlgoSignalState_t as defined in Rte_Type.h]
  @glob_in         SIState : Global state variable for SI sub-component   [SIState_t as defined in si_ext.h]

  @c_switch_part   FCT_CFG_SLATE_ACC_OBJECT_SELECTION : FCT switch for ACC object selection 
  @c_switch_full   FCT_CFG_ERROR_OUTPUT_SEN : FCT error output from FCT_SEN
  @c_switch_full   FCT_CFG_ADAPTIVE_CRUISE_CONTROL : FCT switch for ACC (Adaptive Cruise Control) 

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         09.09.2010
  @changed         22.10.2015

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com
*************************************************************************************************************************/
void SLATE_v_FillErrorOut(SLATEErrorOutProPort_t * pt_ErrorOut)
{
  /* Fill in version number */
  pt_ErrorOut->uiVersionNumber = FCT_SEN_ERROR_OUT_INTFVER;
  pt_ErrorOut->sSigHeader.eSigStatus = AL_SIG_STATE_OK;

  /* Depending on FCT SI sub-component activation states and assessed object list
  signal status set object selection active/not active state */
  if ((LA_t_State == COMP_STATE_RUNNING) 
    && (GET_FCT_PUB_OBJ_DATA_PTR->sSigHeader.eSigStatus == AL_SIG_STATE_OK))
  {
    (pt_ErrorOut->b_ObjSelectionActive) = TRUE;
  }
  else
  {
    (pt_ErrorOut->b_ObjSelectionActive) = FALSE;
  }

  #if (SLATE_CFG_ACC_PERF_MONITORING)
  /* Call APM to fill in errors */
  APM_v_FillSenErrors(pt_ErrorOut);
  #endif /*!< SLATE_CFG_ACC_PERF_MONITORING */

}

/// @}
#endif /*!< FCT_CFG_SLATE_COMPONENT && FCT_CFG_ERROR_OUTPUT_SEN */
