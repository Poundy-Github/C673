#include "acdc_fps_main.h"
#include "acdc_access_func.h"

/***************************************
OBSERVERS
************************************/
/* PRQA S 2217 OBSERVER_DEFINES */
 /*                                                           ObserverName,  UpdateFunction                             ,  FusionFunction              ,          Init Function                             GroupID                              , Fulfilled Thresh,                     InhibitionMask                */
#if FPS_EBA_ENABLE_OBS_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sOBSObserver = { "OBS"        ,  FPS_EBA_OBS_OBSERVER_FUNCTION            ,  FPS_EBA_OBS_OBSERVER_FUSION ,            FPS_EBA_OBS_OBSERVER_INIT          ,  FPS_EBA_OBS_OBSERVER_GROUP           , FPS_EBA_OBS_OBSERVER_THRES,           FPS_EBA_OBS_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_RCS_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sRCSObserver = { "RCS"        ,  FPS_EBA_RCS_OBSERVER_FUNCTION            ,  FPS_EBA_RCS_OBSERVER_FUSION ,            FPS_EBA_RCS_OBSERVER_INIT          ,  FPS_EBA_RCS_OBSERVER_GROUP           , FPS_EBA_RCS_OBSERVER_THRES,           FPS_EBA_RCS_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_POE_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sPOEObserver = { "POE"        ,  FPS_EBA_POE_OBSERVER_FUNCTION            ,  FPS_EBA_POE_OBSERVER_FUSION ,            FPS_EBA_POE_OBSERVER_INIT          ,  FPS_EBA_POE_OBSERVER_GROUP           , FPS_EBA_POE_OBSERVER_THRES,           FPS_EBA_POE_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_LFT_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sLFTObserver = { "LFT"        ,  FPS_EBA_LFT_OBSERVER_FUNCTION            ,  FPS_EBA_LFT_OBSERVER_FUSION ,            FPS_EBA_LFT_OBSERVER_INIT          ,  FPS_EBA_LFT_OBSERVER_GROUP           , FPS_EBA_LFT_OBSERVER_THRES,           FPS_EBA_LFT_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_ROAD_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sRoadObserver = { "Road"       ,  FPS_EBA_ROAD_OBSERVER_FUNCTION           ,  FPS_EBA_ROAD_OBSERVER_FUSION ,           FPS_EBA_ROAD_OBSERVER_INIT         ,  FPS_EBA_ROAD_OBSERVER_GROUP          , FPS_EBA_ROAD_OBSERVER_THRES,          FPS_EBA_ROAD_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_MTF_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sMTFObserver = { "MTF"        ,  FPS_EBA_MTF_OBSERVER_FUNCTION            ,  FPS_EBA_MTF_OBSERVER_FUSION ,            FPS_EBA_MTF_OBSERVER_INIT          ,  FPS_EBA_MTF_OBSERVER_GROUP           , FPS_EBA_MTF_OBSERVER_THRES,           FPS_EBA_MTF_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_SHADOW_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sShadowObserver = { "Shadow"     ,  FPS_EBA_SHADOW_OBSERVER_FUNCTION         ,  FPS_EBA_SHADOW_OBSERVER_FUSION ,         FPS_EBA_SHADOW_OBSERVER_INIT       ,  FPS_EBA_SHADOW_OBSERVER_GROUP        , FPS_EBA_SHADOW_OBSERVER_THRES,        FPS_EBA_SHADOW_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_DEGRADATION_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sDegradationObserver = { "Degrade"    ,  FPS_EBA_DEGRAD_OBSERVER_FUNCTION         ,  FPS_EBA_DEGRAD_OBSERVER_FUSION ,         FPS_EBA_DEGRAD_OBSERVER_INIT       ,  FPS_EBA_DEGRAD_OBSERVER_GROUP        , FPS_EBA_DEGRAD_OBSERVER_THRES,        FPS_EBA_DEGRAD_OBSERVER_INHIBMASK };/* PRQA S 4397 *//* Date: 2019-02-01, Reviewer:Komala Boraiah , Reason:This warning is suppressed as this warning does not have any critical impact the functionality. */
#endif
#if FPS_EBA_ENABLE_UPDQUAL_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sUpdQualObserver = { "UpdQual"    ,  FPS_EBA_UPDQUAL_OBSERVER_FUNCTION        ,  FPS_EBA_UPDQUAL_OBSERVER_FUSION,         FPS_EBA_UPDQUAL_OBSERVER_INIT      ,  FPS_EBA_UPDQUAL_OBSERVER_GROUP       , FPS_EBA_UPDQUAL_OBSERVER_THRES,       FPS_EBA_UPDQUAL_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_LASTUPDATE_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sLastUpdateObserver = { "LastUpdate" ,  FPS_EBA_LUPD_OBSERVER_FUNCTION           ,  FPS_EBA_LUPD_OBSERVER_FUSION ,           FPS_EBA_LUPD_OBSERVER_INIT         ,  FPS_EBA_LUPD_OBSERVER_GROUP          , FPS_EBA_LUPD_OBSERVER_THRES,          FPS_EBA_LUPD_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_MOVSAFE_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sMovSafeObserver = { "MovSafe"    ,  FPS_EBA_MOSA_OBSERVER_FUNCTION           ,  FPS_EBA_MOSA_OBSERVER_FUSION ,           FPS_EBA_MOSA_OBSERVER_INIT         ,  FPS_EBA_MOSA_OBSERVER_GROUP          , FPS_EBA_MOSA_OBSERVER_THRES,          FPS_EBA_MOSA_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_FOV_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sFoVObserver = { "FoV"        ,  FPS_EBA_FOV_OBSERVER_FUNCTION            ,  FPS_EBA_FOV_OBSERVER_FUSION ,            FPS_EBA_FOV_OBSERVER_INIT          ,  FPS_EBA_FOV_OBSERVER_GROUP           , FPS_EBA_FOV_OBSERVER_THRES,           FPS_EBA_FOV_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_STOPPED_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sStoppedUnsafeObserver = { "StopUnsafe" ,  FPS_EBA_STOPPED_OBSERVER_FUNCTION        ,  FPS_EBA_STOPPED_OBSERVER_FUSION ,        FPS_EBA_STOPPED_OBSERVER_INIT      ,  FPS_EBA_STOPPED_OBSERVER_GROUP       , FPS_EBA_STOPPED_OBSERVER_THRES,       FPS_EBA_STOPPED_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sDriveOffStatObserver = { "DrvOffStat" ,  FPS_EBA_DRIVEOFFSTAT_OBSERVER_FUNCTION   ,  FPS_EBA_DRIVEOFFSTAT_OBSERVER_FUSION ,   FPS_EBA_DRIVEOFFSTAT_OBSERVER_INIT ,  FPS_EBA_DRIVEOFFSTAT_OBSERVER_GROUP  , FPS_EBA_DRIVEOFFSTAT_OBSERVER_THRES,  FPS_EBA_DRIVEOFFSTAT_OBSERVER_INHIBMASK };
#endif
#if FPS_EBA_ENABLE_MIRRORGHOST_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sMirrorghostObserver = { "MirrGhost" ,    FPS_EBA_MIRRORGHOST_OBSERVER_FUNCTION    ,  FPS_EBA_MIRRORGHOST_OBSERVER_FUSION ,    FPS_EBA_MIRRORGHOST_OBSERVER_INIT  ,  FPS_EBA_MIRRORGHOST_OBSERVER_GROUP   , FPS_EBA_MIRRORGHOST_OBSERVER_THRES,   FPS_EBA_MIRRORGHOST_OBSERVER_INHIBMASK };/* PRQA S 4397 *//* Date: 2019-02-01, Reviewer:Komala Boraiah , Reason:This warning is suppressed as this warning does not have any critical impact the functionality. */
#endif
#if FPS_EBA_ENABLE_VRELAMBIG_OBSERVER
STATIC_VAR const FPSEBA_Observer_t sVrelAmbigObserver = { "VrelAmbig" ,    FPS_EBA_VRELAMBIG_OBSERVER_FUNCTION      ,  FPS_EBA_VRELAMBIG_OBSERVER_FUSION ,      FPS_EBA_VRELAMBIG_OBSERVER_INIT    ,  FPS_EBA_VRELAMBIG_OBSERVER_GROUP     , FPS_EBA_VRELAMBIG_OBSERVER_THRES,     FPS_EBA_VRELAMBIG_OBSERVER_INHIBMASK };
#endif
/*PRQA S 3408 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
const FPSEBA_Observer_t * const FPSEBA_aBaseObserver[FPS_EBA_NUMBER_OF_BASE_OBSERVERS] =
{
#if FPS_EBA_ENABLE_OBS_OBSERVER
 &sOBSObserver,
#endif
#if FPS_EBA_ENABLE_RCS_OBSERVER
 &sRCSObserver,
#endif
#if FPS_EBA_ENABLE_POE_OBSERVER
 &sPOEObserver,
#endif
#if FPS_EBA_ENABLE_LFT_OBSERVER
 &sLFTObserver,
#endif
#if FPS_EBA_ENABLE_ROAD_OBSERVER
 &sRoadObserver,
#endif
#if FPS_EBA_ENABLE_MTF_OBSERVER
 &sMTFObserver,
#endif
#if FPS_EBA_ENABLE_SHADOW_OBSERVER
 &sShadowObserver,
#endif
#if FPS_EBA_ENABLE_DEGRADATION_OBSERVER
 &sDegradationObserver,
#endif
#if FPS_EBA_ENABLE_UPDQUAL_OBSERVER
 &sUpdQualObserver,
#endif
#if FPS_EBA_ENABLE_LASTUPDATE_OBSERVER
 &sLastUpdateObserver,
#endif
#if FPS_EBA_ENABLE_MOVSAFE_OBSERVER
 &sMovSafeObserver,
#endif
#if FPS_EBA_ENABLE_FOV_OBSERVER
 &sFoVObserver,
#endif
#if FPS_EBA_ENABLE_STOPPED_OBSERVER
 &sStoppedUnsafeObserver,
#endif
#if FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER
 &sDriveOffStatObserver,
#endif
#if FPS_EBA_ENABLE_MIRRORGHOST_OBSERVER
 &sMirrorghostObserver,
#endif
#if FPS_EBA_ENABLE_VRELAMBIG_OBSERVER
 &sVrelAmbigObserver,
#endif

};
/*PRQA S 3408 2*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
float32 EBAObjQualityArray[EM_N_OBJECTS];
FPSEBA_MovementData_t              FPSEBA_MovData;


/* Function EBA quality for the object list */
void AIP_v_PreProcessEBAObjectQuality(void)
{


	/* Call for function pre- processing for EBA objects*/
	ACDCEBA_ProcessObjects();
}


void AIP_v_InitEBAObjectQuality(void)
{
	
#if(ACDC_CFG_USE_FPS)
	ObjNumber_t ObjNr;
	EM_t_GenObjQualifiers * pObjPresel;
	for (ObjNr = (signed char)(EM_N_OBJECTS - 1); ObjNr >= 0L; ObjNr--)
	{
		pObjPresel = ACDC_p_GetEMGenObjQualifiers(ObjNr);
		pObjPresel->uiEbaObjQuality = 0;
	}
#endif

	
}

void ACDCEBA_ProcessObjects(void)
{
	ObjNumber_t ObjNr;	
	
		
	  /* Go through all objects, checking if individual criteria pass */
	  for (ObjNr = (signed char)(EM_N_OBJECTS - 1); ObjNr >= 0L; ObjNr--)
	  {
		
		  if ( !((ACDC_p_GetEMGenObjList()->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_DELETED) || (ACDC_p_GetEMGenObjList()->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_EMPTY)))
	  {
			
			/* determine the current and historical movement properties of the object as well as the object class */
			ACDCEBA_ObjMovProc(ObjNr);

			/* Determine the Object class*/
			ACDCEBA_ObjClassProc(ObjNr);

			/* set EBA HypCat */
			ACDCEBA_HypCatProc(ObjNr);

			/* calculate (object quality) */
			ACDCEBA_ObjQualProc(ObjNr);
	    }
	    else
	    {
	      /* Object is deleted reset everything */
	     FPSInitEBAObject(ObjNr);
	    }
	  }
}
void ACDCEBA_ObjMovProc(ObjNumber_t ObjNr)
{
	  FPSEBA_ObjectMovState_t ObjectMovingState;

	  //#if(EM_GEN_OBJECT_INTFVER >= 0x10)
	  //EBAPresel_t *pObjPresel = &gObjPresel;
	  
	  //#endif
	  /* Determine the current movement state */
	  ObjectMovingState = FPSEBA_CalcCurrObjMovement( ObjNr );

	  /* Set the object movement history based on comparison between current and former movement state */
	  FPSEBA_UpdatePreviousMovement( ObjNr, ObjectMovingState);

	  /* Set the object current moving state*/
	  FPSEBA_MovData.Movement.aFPSObjCurrMovState[ObjNr] = ObjectMovingState;

}
FPSEBA_ObjectMovState_t FPSEBA_CalcCurrObjMovement( EM_t_ObjNumber const ObjNr )
{
	  FPSEBA_ObjectMovState_t               eObjMovingState = FPS_EBA_MOVSTATE_UNKNOWN;
	  EM_t_GenObjAttributes      const * const pObjAttrib      = ACDC_p_GetEMGenObjAttributes(ObjNr);
	 
	 /* Check objects which are stationary over ground. */
	 switch (pObjAttrib->eDynamicProperty)
	 {
	 case EM_GEN_OBJECT_DYN_PROPERTY_MOVING:
		 eObjMovingState = FPS_EBA_MOVSTATE_COMOVING;
		 break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING:
		 eObjMovingState = FPS_EBA_MOVSTATE_ONCOMING;
		 break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY:
		eObjMovingState = FPS_EBA_MOVSTATE_STATIC;
		break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_STOPPED:
		eObjMovingState = FPS_EBA_MOVSTATE_STOPPED;
		break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN:
		eObjMovingState = FPS_EBA_MOVSTATE_UNKNOWN;
		break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_MAX_DIFF_TYPES:
		eObjMovingState = FPS_EBA_MOVSTATE_MAX_VALUE;
		break;
	 case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT:
	 case EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT:
		eObjMovingState = FPS_EBA_MOVSTATE_CROSSING;
		break;	 
	 default:
	 	eObjMovingState = FPS_EBA_MOVSTATE_UNKNOWN;
		 break;
	 }


	  return eObjMovingState;
}
void    FPSEBA_UpdatePreviousMovement( EM_t_ObjNumber const ObjNr, FPSEBA_ObjectMovState_t const eCurrMovState)
{
	 FPSEBA_ObjectMovement_t   * const pObjMov         = &FPSEBA_MovData.Movement;
	 FPSEBA_ObjectMovState_t     const eSavedMovState  = pObjMov->aFPSObjCurrMovState[ObjNr];

	  /* Check if the movement state changed */
	  if (eSavedMovState != eCurrMovState)
	  {
	    pObjMov->aFPSObjPrevMovState[ObjNr] = eSavedMovState;
	  }
}
FPSEBA_ObjectCrossingState_t FPSEBA_CheckCrossingProperty( EM_t_ObjNumber const ObjNr, FPSEBA_ObjectMovState_t const eLastCycleMovState)
{
  
  EM_t_ARS_Geometry		const * const   pObjGeo						= ACDC_p_GetEMARSObjGeometry(ObjNr);

  float32                               fOrientationStdThresh   = DEG2RAD( 45.0F);
  float32                               fLowerOrientationThresh = DEG2RAD( 45.0F);
  float32                               fUpperOrientationThresh = DEG2RAD(135.0F);
  FPSEBA_ObjectCrossingState_t          eIsCrossing             = FPSEBA_CROSS_STATE_UNKNOWN;
  float32 fCrossingOrientation =fABS(pObjGeo->fOrientation);
  /* Apply hysteresis */
  if (eLastCycleMovState == FPS_EBA_MOVSTATE_CROSSING)
  {
    fOrientationStdThresh     = DEG2RAD(180.0F);
    fLowerOrientationThresh  -= DEG2RAD(22.5F);
    fUpperOrientationThresh  += DEG2RAD(22.5F);
  }


  /* Check crossing conditions */
  if ( (pObjGeo->fOrientation <  CML_Sqr(fOrientationStdThresh)   )
    && ((fCrossingOrientation)  > (1.2F * fLowerOrientationThresh) )
    && ((fCrossingOrientation) <  (0.8F * fUpperOrientationThresh) ) )
  {
    eIsCrossing = FPSEBA_CROSS_STATE_CROSSING;
  }
  else if ((pObjGeo->fOrientation <  CML_Sqr(fOrientationStdThresh)   )
        && ((fCrossingOrientation)  > fLowerOrientationThresh)
        && ((fCrossingOrientation) <  fUpperOrientationThresh))
  {
    eIsCrossing = FPSEBA_CROSS_STATE_CROSSING_SOFT;
  }
  else
  {
    eIsCrossing = FPSEBA_CROSS_STATE_NOT_CROSSING;
  }
  return eIsCrossing;
}
FPSEBA_ObjectMovState_t FPSEBA_SetStationaryOrStopped(EM_t_ObjNumber const ObjNr, ODObj_t_DynamicProperty const eDynamicProperty)
{
  FPSEBA_ObjectMovState_t         eObjMovingState = FPS_EBA_MOVSTATE_UNKNOWN;

 
  boolean bIsStopped = False;

  if (ACDC_p_GetEMGenObjAttributes(ObjNr)->eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)
  {
	  if (ACDC_p_GetEMGenObjAttributes(ObjNr)->uiDynConfidence > 80U)
	  {
		  bIsStopped = True;
	  }
  }

  /* Objects shall only be set to stopped based on the x-direction information. Otherwise handle as stationary.*/
  if (    ( eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
       && ( bIsStopped       == TRUE                     ) )
  {
   
    eObjMovingState = FPS_EBA_MOVSTATE_STATIC;
  }
  else
  {
   
    eObjMovingState = FPS_EBA_MOVSTATE_STOPPED;
  }

  return eObjMovingState;
}


void ACDCEBA_ObjClassProc(ObjNumber_t ObjNr)
{

	EM_t_GenObjClassification eAttributesClass = ACDC_p_GetEMGenObjAttributes(ObjNr)->eClassification;
	EM_t_GenObjClassification eClass =  EM_GEN_OBJECT_CLASS_UNCLASSIFIED;
	switch(eAttributesClass)
	{
	case EM_GEN_OBJECT_CLASS_POINT:
		eClass = FPS_EBA_CLASS_UNKNOWN;
		break;
	case EM_GEN_OBJECT_CLASS_CAR:
		eClass = FPS_EBA_CLASS_CAR;
		break;
	case EM_GEN_OBJECT_CLASS_TRUCK:
		eClass = FPS_EBA_CLASS_TRUCK;
		break;
	case EM_GEN_OBJECT_CLASS_PEDESTRIAN:
		eClass = FPS_EBA_CLASS_PEDESTRIAN;
		break;
	case EM_GEN_OBJECT_CLASS_MOTORCYCLE:
		eClass = FPS_EBA_CLASS_MOTORBIKE;
		break;
	case EM_GEN_OBJECT_CLASS_BICYCLE:
		eClass = FPS_EBA_CLASS_CYCLIST;
		break;
	case EM_GEN_OBJECT_CLASS_OTHER_VEHICLE:
		eClass = FPS_EBA_CLASS_VEHICLE;
		break;
	case EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES:
		eClass = FPS_EBA_CLASS_MAX_VALUE;
		break;
	default:
		eClass = FPS_EBA_CLASS_UNKNOWN;
		break;
	}
#if(ACDC_CFG_USE_FPS)
	ACDC_p_GetEMGenObjQualifiers(ObjNr)->eEbaObjClass = eClass;
#endif

}

void ACDCEBA_HypCatProc(ObjNumber_t ObjNr)
{
	  EM_t_GenEbaHypCat						ObjHypCat  = FPS_EBA_HYP_CAT_NONE;
	  EM_t_GenEbaHypCat                     eObjHypCat = FPS_EBA_HYP_CAT_NONE;
	  
	  FPSEBA_ObjectMovement_t const * const pObjMov    			= &FPSEBA_MovData.Movement;
	  FPSEBA_ObjectMovState_t const         eCurrMov   			= pObjMov->aFPSObjCurrMovState[ObjNr];
	  FPSEBA_ObjectMovState_t const         ePrevMov   			= pObjMov->aFPSObjPrevMovState[ObjNr];
	  //EM_t_GenObject 		  const * const pEMObjAttribute 	= ACDC_p_GetEMGenObj(ObjNr);
	  //EM_t_GenEbaHypCat                     CompareHypCat 		= pEMObjAttribute->Qualifiers.eEbaHypCat;
	    /* Based on the current object movement state, the Hyp_Cat is to be set */	 

	    switch(eCurrMov)
	    {
	    case FPS_EBA_MOVSTATE_COMOVING:
	      SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_COMOV);
	      break;


	    case FPS_EBA_MOVSTATE_STOPPED:
	      /* For all stopped objects static HYP_CAT has to be set */
	      SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_STAT);

	      /* Objects with dynamic property "oncoming->stopped" and "crossing->stopped" should not be used in the vehicle hypothesis */
	      if(    (ePrevMov == FPS_EBA_MOVSTATE_COMOVING      )
	        )
	      {
	        SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_COMOV);
	      }	 

	      break;

	    case FPS_EBA_MOVSTATE_STATIC:
	      SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_STAT);
	      break;

	    case FPS_EBA_MOVSTATE_ONCOMING:
	      SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_ONC);
	      break;

	    case FPS_EBA_MOVSTATE_CROSSING:
	    case FPS_EBA_MOVSTATE_CROSSING_SOFT:
	      SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_XING);

	      /* For objects which had a comoving or oncoming state previously. Keep this HypCat also. */
	      if ( ePrevMov == FPS_EBA_MOVSTATE_COMOVING )
	      {
	        SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_COMOV);
	      }
	      else if ( ePrevMov == FPS_EBA_MOVSTATE_ONCOMING )
	      {
	        SET_BIT(eObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_ONC);
	      }
	      else
	      {
	        /* do nothing */
	      }
	      break;

	    case FPS_EBA_MOVSTATE_UNKNOWN:
	    default: /*do nothing*/
	      break;
	    } /*PRQA S 2016*//* date: 2019-Feb-1, reviewer: Pronnoy Chowdhury, Reason: The switch-case need to have a default case for catching undetected case ,  even if it is empty  */

	  /* Write result to public obj list */
	  ObjHypCat = eObjHypCat;
	  //ObjHypCat = FPS_EBA_HYP_CAT_STAT;
	#if (ACDC_CFG_USE_FPS)  //for compiler
	  ACDC_p_GetEMGenObjQualifiers(ObjNr)->eEbaHypCat = ObjHypCat;
	#endif
}

void ACDCEBA_ObjQualProc(ObjNumber_t ObjNr )
{
#if(ACDC_CFG_USE_FPS)
	  EM_t_GenObjQualifiers * pObjPresel = ACDC_p_GetEMGenObjQualifiers(ObjNr);
#endif
	  float32                     fObjectQualityFiltered = EBAObjQualityArray[ObjNr];
	  EM_t_GenEbaInhibit          uInhibitionMask        = FPS_EBA_INH_NONE;
	  float32                     fObjectQuality;
	  /* Add variable for base observer calculations */
	  FPSEBA_ObjQuality_t * const pBaseQuality           = &FPSEBA_BaseObjQualityData.Quality[ObjNr];
	  float32                     afBaseQuality[FPS_EBA_NUMBER_OF_BASE_OBSERVERS] = {0};
	  FPSEBA_ObsResults_t         uBaseObserverResults  = 0u;
	  float32                     fBaseQuality = 0.0F;
	  EM_t_GenEbaInhibit          uBaseInhibit = FPS_EBA_INH_NONE;
	  float32 fFilterSpeed;
	  /************************************************************************/
	  /* Calculate quality and inhibition mask of base      */
	  /************************************************************************/

	  /* Calculate the object quality data and inhibition mask for the base part */
	  FPSEBA_ObjectQualDataProcess(ObjNr, FPSEBA_aBaseObserver, pBaseQuality->uObserverResults, (sint32)FPS_EBA_NUMBER_OF_BASE_OBSERVERS,
	                               &uBaseObserverResults, afBaseQuality, &fBaseQuality, &uBaseInhibit);


	  /************************************************************************/
	  /* Fusion of the Quality and inhibition mask of base    */
	  /************************************************************************/
	  fObjectQuality  =  fBaseQuality;
	  uInhibitionMask =  uBaseInhibit;
	  
	  if ((ACDC_p_GetEMGenObjAttributes(ObjNr)->eClassification == EM_GEN_OBJECT_CLASS_CAR)
		  || (ACDC_p_GetEMGenObjAttributes(ObjNr)->eClassification == EM_GEN_OBJECT_CLASS_TRUCK)
		  || (ACDC_p_GetEMGenObjAttributes(ObjNr)->eClassification == EM_GEN_OBJECT_CLASS_OTHER_VEHICLE))
	  {
		  if (ACDC_p_GetEMFusionObjList()->aObject[ObjNr].CamData.eAssociatedLane == EM_CAM_OBJ_ASSOC_LANE_LEFT)
		  {
			  uInhibitionMask = FPS_EBA_INH_ALL;
		  }
		  else if (ACDC_p_GetEMFusionObjList()->aObject[ObjNr].CamData.eAssociatedLane == EM_CAM_OBJ_ASSOC_LANE_RIGHT)
		  {
			  uInhibitionMask = FPS_EBA_INH_ALL;
		  }
		  else if (ACDC_p_GetEMFusionObjList()->aObject[ObjNr].CamData.eAssociatedLane == EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_LEFT)
		  {
			  uInhibitionMask = FPS_EBA_INH_ALL;
		  }
		  else if (ACDC_p_GetEMFusionObjList()->aObject[ObjNr].CamData.eAssociatedLane == EM_CAM_OBJ_ASSOC_LANE_OUTSIDE_RIGHT)
		  {
			  uInhibitionMask = FPS_EBA_INH_ALL;
		  }
		  else
		  {
		  }

	  }

	  /* Saturate the value of object quality */
	  //fObjectQuality = MINMAX(0.0f, 1.0f, fObjectQuality);	
	  
	  /* Set different filter speeds for increase and decrease of the object probability */
	  if (fObjectQuality > fObjectQualityFiltered)
	  {
	    fFilterSpeed = FPSEBA_QUALITY_FILTERCONSTANT_UP;
	  }
	  else
	  {
	    fFilterSpeed = FPSEBA_QUALITY_FILTERCONSTANT_DOWN;
	  }
	  /* Call low pass filter */
	  CML_f_LowPassFilter2(&fObjectQualityFiltered, fObjectQuality, fFilterSpeed);

	  /************************************************************************/
	  /* Output calculated values                                             */
	  /************************************************************************/
	  pBaseQuality->uInhibitMask     = uBaseInhibit;
	  pBaseQuality->uObserverResults = uBaseObserverResults;
#if(ACDC_CFG_USE_FPS)
	  pObjPresel->uiEbaObjQuality    = (unsigned char)(fObjectQualityFiltered * 100.0F);
	  pObjPresel->eEbaInhibitionMask = uInhibitionMask;
#endif

	  EBAObjQualityArray[ObjNr] = fObjectQualityFiltered;
	/* Fill additional debug data for simulation */
	#ifdef EM_SIMU
	  FPSEBA_SimuFillDebugData(pBaseQuality, afBaseQuality, FPS_EBA_NUMBER_OF_BASE_OBSERVERS, fBaseQuality);
	#endif

}

void FPSEBA_ObjectQualDataProcess(EM_t_ObjNumber ObjNr, FPSEBA_Observer_t const * const FPSEBA_aObserver[], FPSEBA_ObsResults_t uLastObsResults, sint32 iNumOfObservers,
                                         FPSEBA_ObsResults_t * const puObserverResults,  float32 afObserverQuality[],
                                         float32 * pfQuality, EM_t_GenEbaInhibit * puInhibit)

{

  /************************************************************************/
  /* Calculate the results for all configured observers                   */
  /************************************************************************/

	  sint32 iObserver;
	  float32 fObsProb=0.0F;
	  FPSEBA_Observer_t const * pObs;

	  FPSEBA_Observer_t const * pObs1;
	  float32                   fObjectQuality = 1.0F;
	  EM_t_GenEbaInhibit        uInhibitionMask = FPS_EBA_INH_NONE;
	  sint32                    iiObserver;

	  /* Loop over all observers */
	  for(iObserver = 0 ; iObserver < iNumOfObservers ; iObserver++)
	  {
		  //FPSEBA_ObsResults_t const * const pObsFullfilledMask = &uLastObsResults;
		  /* PRQA S 3220 2 */ /* Implicit bObserverFulfilled declaration for easier maintainability.*/
		  boolean bObserverFulfilled = FPSEBA_GetObsFulfilled(iObserver, &uLastObsResults);

	    /* Get local pointer to the observer */
	    pObs     = FPSEBA_aObserver[iObserver];

		if (pObs->fptUpdate != NULL)
		{
			/* Update the observer probability result is always between 0 and 1*/
			fObsProb = pObs->fptUpdate(ObjNr, bObserverFulfilled);
		}

	    if (pObs->fptFusion != NULL)
	    {
	      fObsProb = pObs->fptFusion(ObjNr, bObserverFulfilled, fObsProb);
	    }

	    /* Check whether the calculated probability is over the given threshold. */
	    if( fObsProb > ((float32)pObs->uCondFulfilledThres * 0.01f) )
	    {
	      /* Set the observer to fulfilled */
	    	FPSEBA_SetObsFulfilled(iObserver, puObserverResults);
	    }
	    /* Save the quality of every observer */
		afObserverQuality[iObserver] = fObsProb;
	  }
  /************************************************************************/
  /* Fuse the observer results                                            */
  /************************************************************************/

	 

	  for(iiObserver = 0; iiObserver < iNumOfObservers ; iiObserver++)
	  {
	    pObs1 = FPSEBA_aObserver[iiObserver];

	    /* Fuse quality */
	    if (    (pObs1->uiGroupID == FPS_EBA_OBSGROUP_QUAL      )
	         || (pObs1->uiGroupID == FPS_EBA_OBSGROUP_QUAL_INHIB) )
	    {
	      fObjectQuality *= afObserverQuality[iiObserver];
	    }

	    /* Fuse inhibitions */
	    if (    (pObs1->uiGroupID == FPS_EBA_OBSGROUP_INHIB     )
	         || (pObs1->uiGroupID == FPS_EBA_OBSGROUP_QUAL_INHIB) )
	    {
	      /* Set the Inhibition mask based if  */
	      if(FPSEBA_GetObsFulfilled(iiObserver, puObserverResults) == FALSE)
	      {
	        uInhibitionMask |= pObs1->uInhibitMask;
	      }
	    }
	  }
	  /* Saturate the value of object quality */
	  fObjectQuality = MINMAX(0.0f,1.0f,fObjectQuality);

	  /* write calculated data to the output pointer */
	  *pfQuality = fObjectQuality;
	  *puInhibit = uInhibitionMask;
}
#if (FPS_EBA_ENABLE_OBS_OBSERVER)
float32 FPSEBA_OBS_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled)
{
  float32                 fProb          = 0.0F;
  uint8                   uiOBSThresh;
  EM_t_GenObject const * const pObj = ACDC_p_GetEMGenObj(ObjNr);
  
    if (pObj->Attributes.eDynamicProperty == ODOBJ_DYNPROP_STATIONARY)
    {
      if (EM_b_IsPrivObjStopped(ObjNr) == TRUE)
      {
         /* Object is stopped */

        /* Apply hysteresis */
        if (bObsFulfilled == TRUE)
        {
          uiOBSThresh = FPS_EBA_OBSPROB_THRES_STOPPED_DROP;
        }
        else
        {
          uiOBSThresh = FPS_EBA_OBSPROB_THRES_STOPPED_PICKUP;
        }
      }
      else
      {
        /* Object is stationary */

        /* Apply hysteresis */
        if (bObsFulfilled == TRUE)
        {
          uiOBSThresh = FPS_EBA_OBSPROB_THRES_STAT_DROP;
        }
        else
        {
          uiOBSThresh = FPS_EBA_OBSPROB_THRES_STAT_PICKUP;
        }
      }
    }
    else
    {
      /* Object is moving */

      /* Apply hysteresis */
      if (bObsFulfilled == TRUE)
      {
        uiOBSThresh = FPS_EBA_OBSPROB_THRES_MOVE_DROP;
      }
      else
      {
        uiOBSThresh = FPS_EBA_OBSPROB_THRES_MOVE_PICKUP;
      }
    }

    /* Check threshold */

	if (ACDC_p_GetEMGenObjList()->aObject[ObjNr].Attributes.uiClassConfidence >= uiOBSThresh)
	{
		fProb = 1.0F;
	}

    

  return fProb;
}

 float32 FPSEBA_OBS_FusionObserver( EM_t_ObjNumber ObjNr, boolean bObsFulfilled, float32 fProb)
{
  float32 fProbFusion                = 0.0F;
  uint8   uCamConfirmationProb = ACDC_p_GetEMGenObjList()->aObject[ObjNr].Attributes.uiClassConfidence;

  uint8   uCamConfirmationProbThresh = FPS_EBA_OBS_FUSE_MIN_CAM_CONFIRMATION_PROB;

  uint8   uCamConfirmationClass = ACDC_p_GetEMGenObjList()->aObject[ObjNr].Attributes.eClassification;

  /* Apply hysteresis */
  if (bObsFulfilled == TRUE)
  {
    uCamConfirmationProbThresh = FPS_EBA_OBS_FUSE_MIN_CAM_CONFIRMATION_PROB_HYST;
  }

  /* Check whether camera object is associated with enough confidence*/
  if ( uCamConfirmationProb > uCamConfirmationProbThresh )
  {
      /* Check whether the camera class indicates a VRU */
      if ((uCamConfirmationClass == EM_GEN_OBJECT_CLASS_BICYCLE)
	  ||  (uCamConfirmationClass == EM_GEN_OBJECT_CLASS_PEDESTRIAN))
      {

		fProbFusion = 1.0F;

      }
	  
#if (FPS_EBA_OBSTPROB_LOWER_THRESHOLD_FUSED_OBJECT)
      /* For stationary fused objects a lower obstacle threshold should be used. */
      else if (ACDC_p_GetEMGenObjList()->aObject[ObjNr].Attributes.eDynamicProperty == ODOBJ_DYNPROP_STATIONARY )
      {

			fProbFusion = 1.0F;
      }
      else
      {
        /* Do nothing. */
      }
#endif /* FPS_EBA_OBSTPROB_LOWER_THRESHOLD_FUSED_OBJECT */
    }

  /* The camera fusion should be used to support the obstacle observer.
      Take the maximum of the camera result and the radar obstacle observer */
      fProbFusion = MAX(fProb, fProbFusion);
	  return fProbFusion;

}
#endif /* #if FPS_EBA_ENABLE_OBS_OBSERVER */

COF_t_CamObject * COF_GetCamObj4ObjID(EM_t_ObjNumber iObject)
{

  COF_t_CamObject*  pRet = NULL;
  ui8_t ObjectEntry;

  /* get index of associated camera object (async. safe version) */
  ObjectEntry = COF_ObjData[iObject].ucVideoIdx;

  /* do we have an associated camera object */
  if (ObjectEntry < (ui8_t)COF_NUM_CAM_OBJECTS)
  {
    pRet = &(COF_CamObjList.camObj[ObjectEntry]);
  }
  else
  {
    pRet = NULL;
  }
  return pRet;
}
void FPSEBA_SetObsFulfilled(sint32 iObserver, FPSEBA_ObsResults_t * const pObsFullfilledMask)
{
  CML_SetBit(*pObsFullfilledMask,1u<<(FPSEBA_ObsResults_t)iObserver);/* PRQA S 4397 *//* Date: 2019-02-01, Reviewer:Komala Boraiah , Reason:This warning is suppressed as this warning does not have any critical impact the functionality. */

}
boolean FPSEBA_GetObsFulfilled(sint32 iObserver, FPSEBA_ObsResults_t const * const pObsFullfilledMask)
{
  return (boolean)(CML_GetBit(*pObsFullfilledMask,1u<<(FPSEBA_ObsResults_t)iObserver));/* PRQA S 4397,4304 *//* Date: 2019-02-01, Reviewer:Komala Boraiah , Reason:This warning is suppressed as this warning does not have any critical impact the functionality. */
}

void FPSInitEBAObject( EM_t_ObjNumber ObjNr )
{
#if(ACDC_CFG_USE_FPS)
	EM_t_GenObjQualifiers * pEBAPresel = ACDC_p_GetEMGenObjQualifiers(ObjNr);
#endif
	FPSEBA_ObjectMovement_t   * pObjMovData = &FPSEBA_MovData.Movement;
  /* Reset public output */
#if(ACDC_CFG_USE_FPS)
	  EBAObjQualityArray[ObjNr]			= 0;

	  /* Reset public output */
	  pEBAPresel->uiEbaObjQuality       = 0;
	  pEBAPresel->eEbaHypCat            = FPS_EBA_HYP_CAT_NONE;
	  pEBAPresel->eEbaInhibitionMask    = FPS_EBA_INH_ALL;
#endif

	  /*Initialize current and previous movement state*/
	  pObjMovData->aFPSObjCurrMovState[ObjNr] = FPS_EBA_MOVSTATE_UNKNOWN;
	  pObjMovData->aFPSObjPrevMovState[ObjNr] = FPS_EBA_MOVSTATE_UNKNOWN;
}
#if (FPS_EBA_ENABLE_POE_OBSERVER)

float32 FPSEBA_POE_Observer( EM_t_ObjNumber ObjNr, boolean bObsFulfilled)
{
#if(ACDC_CFG_USE_FPS)
  EM_t_GenObjQualifiers * pObj = ACDC_p_GetEMGenObjQualifiers(ObjNr);
#else
  const	EM_t_GenObjQualifiers * const pObj = ACDC_p_GetEMGenObjQualifiers(ObjNr);
#endif

  float32             fProb;

  /* Map probability of existence to observer probability */
  fProb = CML_f_BoundedLinInterpol2 (((float32)(pObj->uiProbabilityOfExistence)),
                                     FPS_EBA_POE_OBS_MIN_POE_FOR_OBS_PROB,
                                     FPS_EBA_POE_OBS_MAX_POE_FOR_OBS_PROB,
                                     0.0F, 1.0F);

  _PARAM_UNUSED(bObsFulfilled);
  return fProb;
}

/** @cond */
#endif /* FPS_EBA_ENABLE_POE_OBSERVER */

#if (FPS_EBA_ENABLE_LFT_OBSERVER)
 float32 FPSEBA_LFT_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled)
{
	 
	 float32 fProb = CML_f_BoundedLinInterpol2(((float32)(ACDC_p_GetEMGenObjGeneral(ObjNr)->uiLifeCycles)),
                                            (float32)FPS_EBA_LFT_OBS_MIN_LIFETIME, (float32)FPS_EBA_LFT_OBS_MAX_LIFETIME,
                                            FPS_EBA_LFT_OBS_MIN_PROB, FPS_EBA_LFT_OBS_MAX_PROB);

	

  _PARAM_UNUSED(bObsFulfilled);
  return fProb;
}

/** @cond */
#endif

#if (FPS_EBA_ENABLE_FOV_OBSERVER)
float32 FPSEBA_FoV_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled)
{
	float32                             	fProb = 1.0F;
	EM_t_GenObjKinematics  const * const 	pObjKin = ACDC_p_GetEMGenObjKinematics(ObjNr);
	float32                             	fRangeSqr = FPSSQR(pObjKin->fDistX) + FPSSQR(pObjKin->fDistY);
	if (fRangeSqr < FPSSQR(FPS_EBA_FOV_MIN_OBJDIST))
	{
		/* For very close objects set inhibition */
		fProb = 0.0F;
	}
	else if (fRangeSqr > FPSSQR(FPS_EBA_FOV_MAX_OBJDIST))
	{
		/* Do not check the FOV position for far objects */
	}
	else
	{
		/* Calculate the angle of the object */
		float32 fObjAngleRAD = FPSfABS(ATAN2_(pObjKin->fDistY, pObjKin->fDistX));

		/* Check whether object angle is outside FoV */
		if (fObjAngleRAD > (ALGO_f_AzMaxSpecNear - DEG2RAD(FPS_EBA_FOV_EGDGE_ANGLE)))
		{
			fProb = 0.0F;
		}
	}

	_PARAM_UNUSED(bObsFulfilled);

	return fProb;
}
#endif


#if (FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER)
float32 FPSEBA_DriveOffStat_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled)
{
	float32                               		fProb = 1.0F;
	EM_t_GenObject       		const * const 	pObj = ACDC_p_GetEMGenObj(ObjNr);
	//VehDyn_t                	const * const 	pVehDyn = EMData.pEgoDynRaw;
	//MotState_t              	const         eEgoMotState = pVehDyn->MotionState.MotState;
	MotState_t              	const         	eEgoMotState = ACDC_u_GetEgoMotionState();
	FPSEBA_ObjectMovState_t  	const         	eObjMovState = FPSEBA_MovData.Movement.aFPSObjCurrMovState[ObjNr];

	/* The object is currently not suppressed or it is new. Check whether the suppression should be activated */
	if ((bObsFulfilled == TRUE)
		//|| (pObj->General.e_MaintenanceState == ODOBJ_MT_STATE_NEW) )
		|| (pObj->General.eMaintenanceState == ODOBJ_MT_STATE_NEW))
	{
		/* Observer if we and the object are standing still and the object is not to far away */
		if ((eEgoMotState == VDY_LONG_MOT_STATE_STDST)
			&& ((eObjMovState == FPS_EBA_MOVSTATE_STATIC)
				|| (eObjMovState == FPS_EBA_MOVSTATE_STOPPED))
			&& (pObj->Kinematic.fDistX < FPS_EBA_DRIVEOFFSTAT_MAX_DISTX)
			&& (FPSfABS(pObj->Kinematic.fDistY) < FPS_EBA_DRIVEOFFSTAT_MAX_DISTY))
		{
			fProb = 0.0F;
		}
	}
	else if(bObsFulfilled == FALSE)
	{
		/* The suppression is active, keep it if the object is stationary and we are not moving backwards.*/
		if ((eEgoMotState != VDY_LONG_MOT_STATE_MOVE_RWD)
			&& ((eObjMovState == FPS_EBA_MOVSTATE_STATIC)
				|| (eObjMovState == FPS_EBA_MOVSTATE_STOPPED)))
		{
			fProb = 0.0F;
		}
	}
	else{}
	return fProb;
}
#endif