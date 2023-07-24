/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC_TCI (Traffic Continuation Indication)

PACKAGENAME:               tci_custom.h

DESCRIPTION:               Internal custom specific header file for Traffic Continuation Indication function

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             12.02.2018

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */

#ifndef _TCI_CUSTOM_H_INCLUDED
#define _TCI_CUSTOM_H_INCLUDED

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   tci_custom_h Tci_custom_h
@ingroup    tci_custom
@brief      TCI Custom header file
@description
Internal custom specific header file for Traffic Continuation Indication function
@{ */ 


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#if (FCT_CFG_TCI)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

#if (TCI_CFG_AUTOCODE == SWITCH_ON)
typedef struct {
  boolean b_EgoVehStop;    /* Ego vehicle is stopped */
  boolean b_LeadVehStop;   /* Leading vehicle stopped */
  boolean b_DriveOffAcc;   /* Start is possible, decided by ACC */
  float32 f_DistLeadVeh;   /* Distance between ego and leading vehicle */
  boolean b_ChgLeadVeh;    /* Leading vehicle changed */
  boolean b_AccAct;        /* Cruise control status */
  boolean b_LostLeadVeh;   /* Lost of leading vehicle */
  boolean b_SensSelfTest;  /* Sensor self test */
  float32 f_VabsXOOI0;     /* Lead Vehicle Velocity */
} TCI_ActInput_t;
#endif

/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/



#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_TCI */

/** @} end defgroup*/

/* End of conditional inclusion */
#endif  /*!< _TCI_CUSTOM_H_INCLUDED */

