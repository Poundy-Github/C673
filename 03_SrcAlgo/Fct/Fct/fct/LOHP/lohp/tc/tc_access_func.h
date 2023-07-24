/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                     Mistry Niraj (uidq5738)

CREATION DATE:             25.04.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef TC_ACCESS_FUNC_H_INCLUDED
#define TC_ACCESS_FUNC_H_INCLUDED

#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
//ALGO_INLINE boolean const * TC_pb_GetDummy(void);


/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    TC_pb_GetDummy                                                                                  */ /*!

  @brief           Returns dummy

  @description     Returns dummy

  @return          CP_t_TrajectoryData : trajectory data

  @param[in]       void : 
*************************************************************************************************************************/
/*
ALGO_INLINE boolean const * TC_pb_GetDummy(void)
{
  return &(t_TC_Output.b_Dummy);
}
*/
#endif /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */
#endif /* END IF TC_ACCESS_FUNC_H_INCLUDED */
