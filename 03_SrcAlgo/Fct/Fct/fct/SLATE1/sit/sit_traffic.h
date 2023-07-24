/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_traffic.h

DESCRIPTION:               Header file for traffic density calculation (sit_traffic_density.c, sit_traffic_estimation.c)

AUTHOR:                    Simon Sinnstein

CREATION DATE:             2012.03.28

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 2.0

**************************************************************************** */
/* Bedingte Einbindung */
#ifndef SIT_TRAFFICDENCITY_H_INCLUDED
#define SIT_TRAFFICDENCITY_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "sit.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENTENEXTERN)
*****************************************************************************/

/*****************************************************************************
  MACROS (COMPONENTENEXTERN)
*****************************************************************************/

#if (SIT_CFG_TRAFFIC_DENSITY)
	/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup sit_traffic_density
@{ */
#define SIT_TE_VALID_CONFIDENCE  (49)
#endif
/*****************************************************************************
  TYPEDEFS (COMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENTENEXTERN)
*****************************************************************************/

#if (SIT_CFG_TRAFFIC_DENSITY)
extern void SIT_v_CreateActiveObjectList(const ObjNumber_t iObj, t_ActObject* a_ActObjList, const uint8 uiLength, t_ActObject* a_ActObjListEXT, 
                                      const uint8 uiLengthEXT, t_ActObject* a_ActObjListEXT2, const uint8 uiLengthEXT2);
extern boolean SIT_b_LaneChangeHandling( const ObjNumber_t iObj, t_ActObject* a_ActObjListEXT, const uint8 uiLengthEXT );
extern void SIT_v_CalculateTrafficDensity_mainloop( t_LaneDensityData* pLaneDensityData, uint8 *puiOldObjCellID, uint8 *puiMinObjIDX, uint8 *puiMaxObjIDX,
                                                uint8 *puiMemoryListCounter, uint8 uiSITimer, float32 *pfMinObj, float32 *pfMaxObj, float32 *pfTempDensity);

extern void SIT_v_ConfChangeState(sint16* piTempConfidence, sint8* piConfidence, uint8* puiConfidenceCounter);
extern void SIT_v_uiSITTimer(uint8 new_uiSITTimer);
#endif

/*****************************************************************************
  FUNCTIONS (COMPONENTENEXTERN)
*****************************************************************************/

#if (SIT_CFG_TRAFFIC_DENSITY)
extern void SIT_v_CalculateTrafficDensityEgo( t_LaneDensityDataE* pLaneDensityDataE );
///@}
#endif /*!< SIT_CFG_TRAFFIC_DENSITY*/

#endif /*!< FCT_CFG_ACC_SITUATION */

#ifdef __cplusplus
};
#endif

#else /*!< _SIT_TRAFFICDENCITY_H_INCLUDED */

#endif /*!< _SIT_TRAFFICDENCITY_H_INCLUDED */
