#include "aip_int.h"

#if(ACDC_CFG_AIP && ACDC_AIP_CFG_SHIFT_COORDINATE)

#ifndef EM_GEN_OBJ_N_SHAPE_AXIS
#define EM_GEN_OBJ_N_SHAPE_AXIS EM_GEN_OBJ_N_SHAPE_POINTS
#endif

#ifndef EGOREARBUMPERTOFRONT
#define EGOREARBUMPERTOFRONT 3.771f
#endif

void ShiftShapePointSequence(ObjNumber_t const iObjectIndex)
{
	EM_t_GenObjGeometry *pCurrObjGeometry =  ACDC_p_GetEMGenObjGeometry(iObjectIndex);
	EM_t_GenObjGeometry aCurrObjGeometry_temp = *pCurrObjGeometry;
	uint32 uShapePointNo;
	for (uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		//uint8  const   uPrev = (uShapePointNo + (((uint8)EM_GEN_OBJ_N_SHAPE_POINTS) - 1u)) % ((uint8)EM_GEN_OBJ_N_SHAPE_POINTS);
		uint32 const   uCurrentPoint = uShapePointNo;
		uint32 const   uNextPonit = (uShapePointNo + (1u)) % ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);

		pCurrObjGeometry->aShapePointStates[uCurrentPoint] 					= aCurrObjGeometry_temp.aShapePointStates[uNextPonit];
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosX 		= aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].fPosX;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosY 		= aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].fPosY;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].uiPosXStd   = aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].uiPosXStd;
		pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].uiPosYStd   = aCurrObjGeometry_temp.aShapePointCoordinates[uNextPonit].uiPosYStd;
	}
}

SFLVector2D_t CalculateMinAxisDist(ObjNumber_t const iObjectIndex)
{
	// float32                      fSumX = 0.f;
	// float32                      fSumY = 0.f;
	uint32                       uShapePointNo = 0u;
	SFLVector2D_t                sAxisMinDist = {0.f, 0.f};
	SFLVector2D_t				 sAxisDist[EM_GEN_OBJ_N_SHAPE_AXIS];

    EM_t_GenObjGeometry *pCurrObjGeometry =  ACDC_p_GetEMGenObjGeometry(iObjectIndex);

	for (uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		uint32 const  uCurrentPoint = uShapePointNo;
		uint32 const  uNextPonit = (uShapePointNo + (1u)) % ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);

		sAxisDist[uShapePointNo].fX = (pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosX + pCurrObjGeometry->aShapePointCoordinates[uNextPonit].fPosX) / 2.0f;
		sAxisDist[uShapePointNo].fY = (pCurrObjGeometry->aShapePointCoordinates[uCurrentPoint].fPosY + pCurrObjGeometry->aShapePointCoordinates[uNextPonit].fPosY) / 2.0f;

		if (uShapePointNo == 0u)
		{
			sAxisMinDist = sAxisDist[uShapePointNo];
		}
		else
		{
			if ((sAxisDist[uShapePointNo].fX) < (sAxisMinDist.fX))
			{
				sAxisMinDist = sAxisDist[uShapePointNo];
			}
			else if ((sAxisDist[uShapePointNo].fX) == (sAxisMinDist.fX))
			{
				if ((sAxisDist[uShapePointNo].fY) < (sAxisMinDist.fY))
				{
					sAxisMinDist = sAxisDist[uShapePointNo];
				}
			}		
		}
	}
	return sAxisMinDist;
}


void ShiftShapePointCoordinate(ObjNumber_t const iObjectIndex, SFLVector2D_t const sMinDist)
{
	uint32                        uShapePointNo = 0u;
    EM_t_GenObjGeometry *pCurrObjGeometry =  ACDC_p_GetEMGenObjGeometry(iObjectIndex);
	for (uShapePointNo = 0u; uShapePointNo < (EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
	{
		pCurrObjGeometry->aShapePointCoordinates[uShapePointNo].fPosX -= sMinDist.fX;
		pCurrObjGeometry->aShapePointCoordinates[uShapePointNo].fPosY -= sMinDist.fY;
	}
}

void ShiftObjDistToEgoFrontCenter(ObjNumber_t const iObjectIndex, SFLVector2D_t const sMinDist)
{
    EM_t_GenObjKinematics * pCurrObjKinematics = ACDC_p_GetEMGenObjKinematics(iObjectIndex);
	pCurrObjKinematics->fDistX = pCurrObjKinematics->fDistX + sMinDist.fX - EGOREARBUMPERTOFRONT;
	pCurrObjKinematics->fDistY = pCurrObjKinematics->fDistY + sMinDist.fY;
}

/*Shift coordinate: ego near axis to front bumper, object center to closest axis CEM and ACDC1 platform*/

void AIP_v_ShiftObjMinAxisToEgoFrontCenter()
{
	ObjNumber_t ObjNr;
	SFLVector2D_t sMinDist;
		
	/* Go through all objects, checking if individual criteria pass */
	for (ObjNr = (signed char)(EM_N_OBJECTS - 1); ObjNr >= 0L; ObjNr--)
	{
		
		if ( !((ACDC_p_GetEMGenObjList()->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_DELETED) || (ACDC_p_GetEMGenObjList()->aObject[ObjNr].General.eMaintenanceState == ODOBJ_MT_STATE_EMPTY)))
		{
			ShiftShapePointSequence(ObjNr);

			sMinDist = CalculateMinAxisDist(ObjNr);

			ShiftShapePointCoordinate(ObjNr, sMinDist);

			ShiftObjDistToEgoFrontCenter(ObjNr, sMinDist);
	  	}
	}
	
}



#endif