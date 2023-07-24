/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/SM (Adaptive Cruise Control - Interface and State Coordinator - State Machine)

PACKAGENAME:               sm_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                     Mistry Niraj (uidq5738)

CREATION DATE:             25.04.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef SM_ACCESS_FUNC_H_INCLUDED
#define SM_ACCESS_FUNC_H_INCLUDED

#if (FCT_CFG_ISC_COMPONENT)
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
//ALGO_INLINE boolean const * SM_pb_GetDummy(void);


/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    SM_pb_GetDummy                                                                                  */ /*!

  @brief           Returns dummy

  @description     Returns dummy

  @return          CP_t_TrajectoryData : trajectory data

  @param[in]       void : 
*************************************************************************************************************************/
/*ALGO_INLINE boolean const * SM_pb_GetDummy(void)
{
  return &(t_SM_Output.b_Dummy);
}
*/

#endif /* (FCT_CFG_ISC_COMPONENT) */
#endif /* END IF SM_ACCESS_FUNC_H_INCLUDED */
