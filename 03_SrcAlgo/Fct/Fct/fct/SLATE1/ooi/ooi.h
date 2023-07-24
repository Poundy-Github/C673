/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi.h

DESCRIPTION:               Internal header file for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.17 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */

#ifndef OOI_H_INCLUDED
#define OOI_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup ooi
@{ */
#if (FCT_CFG_ACC_OOI)

#include "ooi_access_func.h"
#include "ooi_par.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*! Macro to set the selection of a given object */
#define OOI_OBJ_SET_OBJ_OF_INTEREST(iObj, iOOI)        (GET_FCT_OBJ_PUB(iObj).ObjOfInterest.eObjOOI = (iOOI))

/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*! defined different function types for object selection*/
typedef enum SIObjSelectionTypeTag {
  OOI_OBJ_SELECTION_NEXT_LONG    = 1,
  OOI_OBJ_SELECTION_NEXT_LATERAL = 2
} OOI_ObjSelectionType_t;

typedef struct {
  ObjNumber_t RelTrckObjNr;
  const OOI_RelObject_t *pRelObj;
  float32 TPVehicleSpeed;
  fCurve_t TrackStandardCurve;
  float32 TrackStandardGradient;
  fCurve_t TrackFastCurve;
  uint8 OOINr;

} OOI_ROVDataInput_t;

/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/*! External declaration of component internal pointer to OOI Input structure for global access within OOI */
extern MEMSEC_REF OOIInputConst_t * pt_OOI_Input;

/*! External declaration of OOI output structure, whose content is filled in this component */
extern MEMSEC_REF OOIOutput_t * pt_OOI_Output;

/*! External declaration of Array of timers used in relevant object loss reset , array size */
#if (OOI_ROV_RESET_BY_TIME == SWITCH_ON)
extern MEMSEC_REF float32 OOI_f_rov_reset_time[OBJLOSS_NUMBER_OF_OOI];
#endif

/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- ooi_main.c ---*/
extern void OOI_v_ReInit(void);
extern void OOI_v_MeasCallback(void);

#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
static void OOI_v_SetCrossingObjectFlag(void);
#endif /*!< OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */

/*--- ooi_objselection ---*/
extern void OOI_v_SelectBaseObjectsOfInterest(void);
extern void OOI_v_FillRelevantObjectStructure(void);
extern void OOI_v_SIReSiDaRelObjInit (ObjNumber_t nr);
extern void OOI_v_BlockedPathDecision(ObjNumber_t * const pNextObjId, ObjNumber_t * const pHiddenObjId);

/*--- ooi_objloss.c ---*/
extern void OOI_v_ObReObInit (void);
extern void OOI_v_ObReObRelObjLossReason(const ObjNumber_t NewObjId, const OOI_RelObject_t* pOldObject, OOI_RelObjEnum_t SiOOINr);

/*--- ooi_select_moving.c ---*/
extern ObjNumber_t OOI_t_SelectNextObjectMoving(eAssociatedLane_t Lane, OOI_ObjSelectionType_t SelectionType);

/*--- ooi_select_stationary.c ---*/
extern void OOI_v_SelectStationaryObject(ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType);

/*--- ooi_select_oncoming.c ---*/
extern void OOI_v_SelectOncomingObject(ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType);

/*--- ooi_customfunctions.c ---*/
extern void OOI_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete );
#if (OOI_CFG_OBJLOSS_LOWDIST)
extern eRelObjLossReason_t OOI_v_ObjLossLowDist(void);
#endif /* END IF OOI_CFG_OBJLOSS_LOWDIST */

#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
extern void OOI_v_InitCustomGaurdRailStatObjSuppress(void);
extern void OOI_v_UpdateMovingObjectCounter(const ObjNumber_t * const pNewObjId, OOI_RelObjEnum_t eRelObjType);
extern boolean OOI_b_CheckPartofGaurdRail(OOI_RelObjEnum_t eRelObjType);
#endif

extern void OOI_b_CheckforCriticalObjLossReason(const OOI_ROVDataInput_t *ROVDataInput);

/* OOI-0 loss due to lateral drift of target object during EGO and Target standstill situation */
extern void OOI_b_CheckTargetLossDueToLateralPositionDrift(const OOI_ROVDataInput_t *ROVDataInput);

/* Set custom Object loss reason */
extern void OOI_b_CheckCustomObjLossReason(const OOI_ROVDataInput_t *ROVDataInput);

#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
/*Select OOI-1 as OOI-0 when OOI-0 is a bike and is trying to overtake OOI-1 to avoid late approach of OOI-1 when OOI-0 is cut out*/
extern void OOI_v_BikeOvertake(void);
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)*/

#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_ACC_LANE_OOI */

/* End of conditional inclusion */
///@}
#endif  /*!< _OOI_H_INCLUDED */

