
#ifndef ACDC_FPS_MAIN
#define ACDC_FPS_MAIN
#include "acdc_int.h"
#include "acdc_fps_access_func.h"
#include "acdc_fps_type.h"

/*****Variables******/
//FPSEBA_MovementData_t              FPSEBA_MovData;
FPSEBA_ObjQualityData_t            FPSEBA_BaseObjQualityData;
extern EMData_t                           EMData;
COF_t_ObjectData                   COF_ObjData[EM_NR_PUBLIC_OBJECTS];
COF_t_CamObjList                   COF_CamObjList;
/*****************************************************************************
  MACROS
*****************************************************************************/
/* EBA pre-Selection and Quality set computation*/


void ACDCEBA_ProcessObjects(void);

void ACDCEBA_PostProcess(void);

void ACDCEBA_ObjMovProc(ObjNumber_t ObjNr);

void ACDCEBA_ObjClassProc(ObjNumber_t ObjNr);

void ACDCEBA_HypCatProc(ObjNumber_t ObjNr);

void ACDCEBA_ObjQualProc(ObjNumber_t ObjNr);

FPSEBA_ObjectMovState_t       FPSEBA_CalcCurrObjMovement(EM_t_ObjNumber const ObjNr);
FPSEBA_ObjectMovState_t       FPSEBA_SetStationaryOrStopped(EM_t_ObjNumber const ObjNr, ODObj_t_DynamicProperty const eDynamicProperty);
void                          FPSEBA_UpdatePreviousMovement(EM_t_ObjNumber const ObjNr, FPSEBA_ObjectMovState_t const eCurrMovState);
FPSEBA_ObjectCrossingState_t  FPSEBA_CheckCrossingProperty(EM_t_ObjNumber const ObjNr, FPSEBA_ObjectMovState_t const eLastCycleMovState);
void                          FPSEBA_ObjectQualDataProcess(EM_t_ObjNumber ObjNr, FPSEBA_Observer_t const * const FPSEBA_aObserver[], FPSEBA_ObsResults_t uLastObsResults, sint32 iNumOfObservers,
	FPSEBA_ObsResults_t * const puObserverResults, float32 afObserverQuality[],
	float32 * pfQuality, EM_t_GenEbaInhibit * puInhibit);
COF_t_CamObject * COF_GetCamObj4ObjID(EM_t_ObjNumber iObject);
void FPSEBA_SetObsFulfilled(sint32 iObserver, FPSEBA_ObsResults_t * const pObsFullfilledMask);
boolean FPSEBA_GetObsFulfilled(sint32 iObserver, FPSEBA_ObsResults_t const * const pObsFullfilledMask);
void FPSInitEBAObject(EM_t_ObjNumber ObjNr);
#if FPS_EBA_ENABLE_OBS_OBSERVER
float32 FPSEBA_OBS_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
float32 FPSEBA_OBS_FusionObserver(EM_t_ObjNumber ObjNr, boolean bObsFulfilled, float32 fProb);
#endif
#if FPS_EBA_ENABLE_POE_OBSERVER
float32 FPSEBA_POE_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
#endif
#if FPS_EBA_ENABLE_LFT_OBSERVER
float32 FPSEBA_LFT_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
#endif
#if (FPS_EBA_ENABLE_UPDQUAL_OBSERVER)
float32 FPSEBA_UpdateQual_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
#endif
#if FPS_EBA_ENABLE_FOV_OBSERVER
float32 FPSEBA_FoV_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
#endif
#if FPS_EBA_ENABLE_DRIVEOFFSTAT_OBSERVER
float32 FPSEBA_DriveOffStat_Observer(EM_t_ObjNumber ObjNr, boolean bObsFulfilled);
#endif

#define OBJ_GET_CAMERA_CONFIRMATION_QUAL(uiObj)  COF_ObjData[uiObj].CamConfirmationProb

#endif