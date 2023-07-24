/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_customfunctions.c

DESCRIPTION:               Custom Functions for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision: 1.4

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup       sit_customfunctions Custom functions
@ingroup        sit
@brief          This module contains customer specific functions for ACC SIT module.
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


/*************************************************************************************************************************
  Functionname:    SIT_v_MergeCustomObjects                                                                         */ /*!

  @brief           Handle Merging of customer specified object from object lists 

  @description     Handle Merging of customer specified object from object lists 

                    @startuml
                        Start
                            Partition SIT_v_MergeCustomObjects {
                                - Do nothing, Dummy Function 
                            }
                        End
                    @enduml

  @return          void

  @param[in]       iObjectToKeep : Object Number which is to be keep
  @param[in]       iObjectToDelete : Object Number which is to be deleted

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_SITUATION :  FCT support for ACC SIT (situation) sub-component

  @pre             -
  @post            -

  @created         -
  @changed         -

  @author          -
*************************************************************************************************************************/
void SIT_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete )
{
  /* merge customer specific object data */
  uiObjectToKeep = uiObjectToKeep; // PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
  uiObjectToDelete = uiObjectToDelete;// PRQA S 3199
  /* date: 2015-06-15, reviewer: Lonard jaison Manohar, reason: Redundant.But may be kept for future use */
}
///@}
#endif /*!< FCT_CFG_ACC_SITUATION */

