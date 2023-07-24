/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypcommon.c

DESCRIPTION:               Implementation of the hypothesis common calculations

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 10:07:06CEST $

VERSION:                   $Revision: 1.14 $

LEGACY VERSION:            Revision: 1.6

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if(CD_USE_HYP_COMMON)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_hypcommon HypCommon
\ingroup cd

\brief The HypCommon module contains all calculations that are executed commonly by all hypotheses.\n\n

The currently provided functionalities are:
- **Class Mapping**: \n
The function \ref CDHypCommonMapFPSToEBAObjClass maps the FPS Object Class to the EBA Object class.
\{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDHypCommonInitHypothesisInt                                                                */ /*!

  @brief                Initialize all necessary values at the entry point of the hypothesis calculation

  @description          Initializes the structure @ref CDIntHypothesis_t according to the given object and hypothesis type.

  @param[out]           pIntHypothesis : Pointer to the current internal hypothesis struct
  @param[in]            iObj : Current object identifier. @range [0,EM_N_OBJECTS]
  @param[in]            eType : Current hypothesis type

  @glob_in              @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetEMGenObjQualifiers
  @glob_out             None 

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER \n
                        @ref CD_USE_EM_FPS_OBJCLASS
  @c_switch_full        @ref CD_USE_HYP_COMMON \n
                        @ref ACDC_CFG_CD

  @pre                  None 
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246

  @testmethod           @ref TEST_CDHYPCOMMONINITHYPOTHESISINT_001 COU_TEST

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
void CDHypCommonInitHypothesisInt (CDIntHypothesis_t * const pIntHypothesis, ObjNumber_t iObj, eCDHypothesisType_t eType)
{
  pIntHypothesis->eType      = eType;
  pIntHypothesis->iObjectRef = iObj;

  pIntHypothesis->fHypothesisLifetime    = 0.0F;
  pIntHypothesis->fHypothesisProbability = 0.0F;
  pIntHypothesis->fRelevance             = 0.0F;
  pIntHypothesis->eEBAInhibitionMask     = FPS_EBA_INH_NONE;
  /* store object class */
#if ( (EM_GEN_OBJECT_INTFVER >= 0x0D) && (CD_USE_EM_FPS_OBJCLASS == SWITCH_ON) )
  pIntHypothesis->eObjectClass= CDHypCommonMapFPSToEBAObjClass(ACDC_p_GetEMGenObjQualifiers(iObj)->eEbaObjClass);
#else
  pIntHypothesis->eObjectClass = ACDC_p_GetEMGenObjAttributes(iObj)->eClassification;
#endif
}


#if( (EM_GEN_OBJECT_INTFVER >= 0x0D) && (CD_USE_EM_FPS_OBJCLASS == SWITCH_ON) )
/*************************************************************************************************************************
  Functionname:         CDHypCommonMapFPSToEBAObjClass                                                               */ /*!

  @brief                Mapping the FPS object classes to the EBA object classes

  @description          Mapping the FPS object classes (\ref EM_t_GenEbaObjClass) to the EBA object classes (\ref eEBAObjectClass_t).

  @return               extern eEBAObjectClass_t

  @param[in]            FPS_ObjectClass : Class of an object, provided by FPS.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FPS_EBA_CLASS_VEHICLE
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_HYP_COMMON \n
                        @ref CD_USE_EM_FPS_OBJCLASS \n
                        @ref EM_GEN_OBJECT_INTFVER

  @pre                  None
  @post                 None

  @InOutCorrelation     | FPS Object Class | EBA Object Class |
                        |:-----------------|:-----------------|
                        |  None            | Not Available    |
                        |  Unknown         | Obstacle         |
                        |  Car             | Vehicle          |
                        |  Truck           | Vehicle          |
                        |  Motorbike       | Vehicle          |
                        |  Cyclist         | Cyclist          |
                        |  Pedestrian      | Pedestrian       |

  @author               Veronika Ehrlinspiel | veronika.ehrlinspiel@continental-corporation.com | +49 (8382) 9699-490

  @testmethod           @ref TEST_CDHYPCOMMONMAPFPSTOEBAOBJCLASS_001 COU_TEST \n
                        @ref TEST_CDHYPCOMMONMAPFPSTOEBAOBJCLASS_002 COU_TEST
  @traceability         Design Decision

*************************************************************************************************************************/
extern eEBAObjectClass_t CDHypCommonMapFPSToEBAObjClass(EM_t_GenEbaObjClass FPS_ObjectClass)
{

  eEBAObjectClass_t EBAObjClass;

  switch (FPS_ObjectClass)
  {
    case FPS_EBA_CLASS_NONE:
      EBAObjClass = EBAObjectClass_NotAvail;
      break;
    case FPS_EBA_CLASS_UNKNOWN:
      EBAObjClass = EBAObjectClass_Obstacle;
      break;
    case FPS_EBA_CLASS_CAR:
    case FPS_EBA_CLASS_TRUCK:
    case FPS_EBA_CLASS_MOTORBIKE:
#ifdef FPS_EBA_CLASS_VEHICLE
    case FPS_EBA_CLASS_VEHICLE:
#endif
      EBAObjClass = EBAObjectClass_Vehicle;
      break;
    case FPS_EBA_CLASS_CYCLIST:
      EBAObjClass = EBAObjectClass_Cyclist;
      break;
    case FPS_EBA_CLASS_PEDESTRIAN:
      EBAObjClass = EBAObjectClass_Pedestrian;
      break;

    default:
      /* Shall never happen. All used classes shall be explicitly handled. */
      EBAObjClass = EBAObjectClass_NotAvail;
      /* Create assertion */
      ACDC_ASSERT(FALSE);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
      break;
  }
  return EBAObjClass;
}
#endif
///\}
#endif
#endif

