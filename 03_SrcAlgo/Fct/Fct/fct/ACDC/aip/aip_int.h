/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_int.h

DESCRIPTION:               internal header for the ACDC Input Processing module

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:15:08CEST $

VERSION:                   $Revision: 1.9 $
**************************************************************************** */

#ifndef AIP_INT_H_INCLUDED
#define AIP_INT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_int.h"

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

/*----- aip_ego.c -----*/
  extern void AIP_v_PreProcessEgoData(ACDCEgoData_t * const pEgoData);
  extern void AIP_v_InitEgoData(void);

/*----- aip_shapepoints.c -----*/
  extern void AIP_v_CalcObjectCenterFromShapePoints(ObjNumber_t const iObjectIndex, SFLVector2D_t  * const pObjectCenter);
  extern void AIP_v_CalcGeometryFromShapePoints(    ObjNumber_t const iObjectIndex, ACDCGeometry_t * const pGeometry);
  extern void AIP_v_CalcShapePointQualities(        ObjNumber_t const iObjectIndex, float32                afQualities[]);
  extern void AIP_v_CalculateLimitedShapePoints(    ObjNumber_t const iObjectIndex, ACDCGeometry_t *const pGeometry, SFLVector2D_t *const pPosObjCenter, SFLVector2D_t aLimitedShapePoints[]);

/*----- aip_object.c -----*/
  extern void AIP_v_PreProcessObjectList(void);
  extern void AIP_v_InitObject(ACDCObject_t *const pObject);
  extern void AIP_v_GetClassBasedDimensionLimits(EM_t_GenEbaObjClass const eEbaClass,float32 * const fLengthMin,float32 * const fLengthMax, float32 * const fWidthMin ,float32 * const fWidthMax);

/*----- aip_shiftcoordinate.c -----*/
  extern SFLVector2D_t CalculateMinAxisDist(ObjNumber_t const iObjectIndex);
  extern void ShiftShapePointSequence(ObjNumber_t const iObjectIndex);
  extern void AIP_v_ShiftObjMinAxisToEgoFrontCenter(void);
  extern void ShiftShapePointCoordinate(ObjNumber_t const iObjectIndex, SFLVector2D_t const sMinDist);
  extern void ShiftObjDistToEgoFrontCenter(ObjNumber_t const iObjectIndex, SFLVector2D_t const sMinDist);

/*----- aip_FPS.c -----*/
  extern void AIP_v_PreProcessEBAObjectQuality(void);
  extern void AIP_v_InitEBAObjectQuality(void);

#ifdef __cplusplus
};
#endif



/// @}

#endif/* (ACDC_CFG_AIP) */
/* End of conditional inclusion */
#endif  /*!< AIP_INT_H_INCLUDED */


