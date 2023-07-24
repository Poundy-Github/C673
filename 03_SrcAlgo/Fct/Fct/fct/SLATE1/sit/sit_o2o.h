/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SIT

PACKAGENAME:               sit_o2o.h

DESCRIPTION:               ACC Object-to-Object Lane Association

AUTHOR:                    Bharadwaj Gobichettipalayam Sankar (uidk9952)

CREATION DATE:             03.03.2017

VERSION:                   $Revision: 1.3 $

*****************************************************************************/


#ifndef SIT_O2O_H_INCLUDED
#define SIT_O2O_H_INCLUDED


#include "sit.h"
#include "sit_custom.h"
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#if (FCT_CFG_ACC_SITUATION)
#if (SIT_O2O_ANALYSIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_o2o
@{ */
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/


  /*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  EXTERN VARIABLES
*****************************************************************************/
///@}
#endif /* END IF SIT_O2O_ANALYSIS */
#endif /* END IF FCT_CFG_ACC_SITUATION */

#ifdef __cplusplus
};
#endif

#endif /* END of #ifndef SIT_O2O_H_INCLUDED */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
