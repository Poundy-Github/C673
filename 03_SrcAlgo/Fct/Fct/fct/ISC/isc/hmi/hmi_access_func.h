/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi_access_func.h

DESCRIPTION:               Access Functions for external usage purpose

AUTHOR:                     Mistry Niraj (uidq5738)

CREATION DATE:             25.04.2017

VERSION:                   $Revision: 1.2 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */


/*****************************************************************************
  MACROS 
*****************************************************************************/

#ifndef HMI_ACCESS_FUNC_H_INCLUDED
#define HMI_ACCESS_FUNC_H_INCLUDED

#if (FCT_CFG_ISC_COMPONENT)
/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/

/*****************************************************************************
  INLINE FUNCTIONS Declarations
*****************************************************************************/
//ALGO_INLINE boolean const * HMI_pb_GetDummy(void);


/*****************************************************************************
  INLINE FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:    HMI_pb_GetDummy                                                                                  */ /*!

  @brief           Returns dummy

  @description     Returns dummy

  @return          CP_t_TrajectoryData : trajectory data

  @param[in]       void : 
*************************************************************************************************************************/
/*ALGO_INLINE boolean const * HMI_pb_GetDummy(void)
{
  return &(t_HMI_Output.b_Dummy);
}
*/

#endif /* (FCT_CFG_ISC_COMPONENT) */
#endif /* END IF HMI_ACCESS_FUNC_H_INCLUDED */
