/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_ext.h

DESCRIPTION:               external header for the ACDC Input Processing module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:15:07CEST $

VERSION:                   $Revision: 1.10 $
**************************************************************************** */

#ifndef AIP_EXT_INCLUDED
#define AIP_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "acdc_types.h"


#if(ACDC_CFG_AIP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup aip
@{ */ 


#ifdef __cplusplus
extern "C" {
#endif
  
  /* ----- aip_main.c ----- */
  extern void                       AIP_v_Process(void);


  /* ----- aip_ego.c ----- */
  extern ACDCTrajPred_t     const * AIP_p_GetACDCEgoTraj(ACDCManeuverType_e const ManeuverType );

  /* ----- aip_shapepoints.c ----- */
  extern sint8                      AIP_i_GetShapePointIdx(ObjNumber_t const iObjectIndex, ACDCShapePointPositions_e const eShapePointPos);

  /* ----- aip_object.c ----- */
  extern void AIP_v_InitObjectList(void);

#ifdef __cplusplus
};
#endif


/// @}
/* End of conditional inclusion */
#endif /* (ACDC_CFG_AIP) */

#endif  /*!< AIP_EXT_INCLUDED */
