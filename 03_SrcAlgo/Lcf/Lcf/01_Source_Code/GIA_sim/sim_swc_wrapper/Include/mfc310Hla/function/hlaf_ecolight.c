/*! \file ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_ecolight.c

  DESCRIPTION:            Functions for ecolight feature.

  AUTHOR:                 Alexander Manz

  CREATION DATE:          22.07.2013

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:  
*****************************************************************************/


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_ecolight.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
#if (HLA_PROJECT == HLA_PROJECT_SMFC4B0)
void HLAF_FillEcoLight(const HLAF_t_InputSignals  *pObjectInput,
                       float32                    operationDistance,
                       float32                    operationTangent,
                       HLAF_EcoLight_t            *pEcoLightOutput)
{
  uint8 i = 0;
  sint8 currentIndex = 0;
  boolean objectFound = FALSE;

  while (   (objectFound != TRUE)
         && (i<pObjectInput->s_StereoObjectList.numUsedObjects)
         && (pObjectInput->s_StereoObjectList.numUsedObjects <= EM_N_OBJECTS)
        )
  {
    /* get index from sorted list */
    currentIndex = pObjectInput->s_StereoObjectList.iSortedObjectList[i];
    if(pObjectInput->s_StereoObjectList.aObject[currentIndex].Kinematic.fDistX > operationDistance)
    {
      /* nearest object is farther away than algo is requiring */
      pEcoLightOutput->ObjectDist = 255.0f;
      pEcoLightOutput->e_AvailabilityState  = RTE_HLAF_ECOLIGHT_AVST_AVAILABLE;
      /* TODO AlexM: DETST_UNKNOWN is wrong named should be _NOTHING */
      pEcoLightOutput->e_DetectionState     = RTE_HLAF_ECOLIGHT_DETST_UNKNOWN;
      pEcoLightOutput->e_ObjectLightState   = RTE_HLAF_ECOLIGHT_VEHLIGHT_INVALID;
      pEcoLightOutput->e_ObjectType         = RTE_HLAF_ECOLIGHT_VEHTYPE_INVALID;
      
      objectFound = TRUE;
    }
    else if( CML_f_IsNonZero(pObjectInput->s_StereoObjectList.aObject[currentIndex].Kinematic.fDistX))
    {
      if(( CML_f_Abs(pObjectInput->s_StereoObjectList.aObject[currentIndex].Kinematic.fDistY) / pObjectInput->s_StereoObjectList.aObject[currentIndex].Kinematic.fDistX) <= operationTangent)      
      {
        /*nearest object is within specified angle */
        pEcoLightOutput->ObjectDist           = pObjectInput->s_StereoObjectList.aObject[currentIndex].Kinematic.fDistX;
      
        if(   (pObjectInput->s_StereoObjectList.aObject[currentIndex].Attributes.eClassification == EM_GEN_OBJECT_CLASS_CAR)
           || (pObjectInput->s_StereoObjectList.aObject[currentIndex].Attributes.eClassification == EM_GEN_OBJECT_CLASS_TRUCK)
          )
        {
          pEcoLightOutput->e_ObjectType = RTE_HLAF_ECOLIGHT_VEHTYPE_TWOTRACK;
        }
        else if (   (pObjectInput->s_StereoObjectList.aObject[currentIndex].Attributes.eClassification == EM_GEN_OBJECT_CLASS_MOTORCYCLE)
                 || (pObjectInput->s_StereoObjectList.aObject[currentIndex].Attributes.eClassification == EM_GEN_OBJECT_CLASS_BICYCLE)
                )
        {
          pEcoLightOutput->e_ObjectType = RTE_HLAF_ECOLIGHT_VEHTYPE_SINGLETRACK;
        }
        else
        {
          pEcoLightOutput->e_ObjectType = RTE_HLAF_ECOLIGHT_VEHTYPE_UNKNOWN;
        }

        if(pObjectInput->s_StereoObjectList.aObject[currentIndex].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_NEW)
        {
          pEcoLightOutput->e_DetectionState = RTE_HLAF_ECOLIGHT_DETST_NEW_DTCD;
        }
        else if (pObjectInput->s_StereoObjectList.aObject[currentIndex].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_MEASURED)
        {
          pEcoLightOutput->e_DetectionState = RTE_HLAF_ECOLIGHT_DETST_DTCD;
        }
        else if (pObjectInput->s_StereoObjectList.aObject[currentIndex].General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_PREDICTED)
        {
          pEcoLightOutput->e_DetectionState = RTE_HLAF_ECOLIGHT_DETST_ESTIM;
        }
        else
        {
          pEcoLightOutput->e_DetectionState = RTE_HLAF_ECOLIGHT_DETST_UNKNOWN;
        }
      
        /* TODO AlexM: improve states here */
        pEcoLightOutput->e_AvailabilityState  = RTE_HLAF_ECOLIGHT_AVST_AVAILABLE;
        pEcoLightOutput->e_ObjectLightState   = RTE_HLAF_ECOLIGHT_VEHLIGHT_ON;
        objectFound = TRUE;
      }
    }
    else
    {
      /* Do nothing */
    }
    i++;
  }
}
#endif 
