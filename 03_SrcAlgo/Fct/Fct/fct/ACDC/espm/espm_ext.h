/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ESPM (EBA Signal Performance Monitoring)

PACKAGENAME:               espm_ext.h

DESCRIPTION:               External header file for EBA Signal Performance Monitoring (ESPM) module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:27:31CEST $

VERSION:                   $Revision: 1.9 $
**************************************************************************** */

#ifndef ESPM_EXT_INCLUDED
#define ESPM_EXT_INCLUDED


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_types.h"

#if (ACDC_CFG_ESPM)

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup espm
@{
*/

/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- espm_main.c ---*/
extern void ESPM_v_DegradationProcess(HypoIntfDegr_t * const pDegradationOut, ACDCErrorOutProPort_t * const pErrorOut);


#ifdef __cplusplus
};
#endif

///@}
#endif /*!< ACDC_CFG_ESPM */

/* End of conditional inclusion */

#endif  /*!< ESPM_EXT_INCLUDED */

