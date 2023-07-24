/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_ext.h

DESCRIPTION:               external EMP data

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:28:52CEST $

VERSION:                   $Revision: 1.31 $

**************************************************************************** */

#ifndef EMP_EXT_H_INCLUDED
#define EMP_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_types.h"

#if (ACDC_CFG_EMP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup emp
\{ */

/*****************************************************************************
  PUBLIC FUNCTIONS
*****************************************************************************/
extern boolean  EMP_b_CalcTrajectoryRefPoint(SFLVector2D_t   const * const pPosition, ACDCTrajPred_t const * const pTrajectory, SFLVector2D_t * const pRefPoint, SFLVector2D_t * const pVelAtRefPoint);
extern void     EMP_v_CalcDistToRefPoint(SFLVector2D_t const *const pPosition, SFLVector2D_t const *const pRefPoint,float32 *const pfDistToTraj, float32 *const pfDistOnTraj);

extern void     EMPPredictEgoTraj( ACDCKinEgo_t const *const pIn_KinEgo, ACDCManeuverType_e ManeuverType, ACDCTrajPred_t*const pOut_TrajPred );

extern boolean  EMPPredictObjTraj( ACDCObjDescMain_t const *const pIn_KinObj, ACDCManeuverType_e eAssumption, ACDCTrajPred_t*const pOut_TrajPred );

extern boolean  EMPCalcMinDistTime(ACDCTrajPred_t const *const pIn_Obj1, ACDCTrajPred_t const *const pIn_Obj2, float32 *const pOut_MinDistTime );
extern float32  EMPCalcObjObjDistAtTime( float32 fTime, ACDCTrajPred_t const *const pIn_Obj1, ACDCTrajPred_t const *const pIn_Obj2 );

extern boolean  EMPCalcCollProbObjObj(float32 fTime, ACDCObjPred_t const *const pIn_Obj1, ACDCObjPred_t const *const pIn_Obj2, float32 *const pOut_CollisionProb );

extern void     EMP_v_CalcObjToEgoTrajRelation(ObjNumber_t const iObjectIndex, ACDCObjToTrajRelation_t *const pObjToTrajRelation);
extern void     EMP_v_CalcDistBasedObjToEgoTrajRelation(ObjNumber_t const iObjectIndex, ACDCObjToTrajRelation_t *const pObjToTrajRelation);

extern void     EMPPredictTrajRelation(ACDCObjToTrajRelation_t const * const pTrajRel, float32 fPredTime, ACDCObjToTrajRelation_t * const pTrajRelPred);

extern void     EMP_v_CalcNumofCircles(ACDCObjDesc_t const * const pObject, uint8 * const uNofCircles);
extern void     EMP_v_CalculateCurrentCircle(ACDCObjDesc_t const * const pObject, uint8 uCurrentCircleID, uint8 uNofCircles, SFLCircle_t * const pCircle);

/* Utility Functions */

extern void EMPResetTrajPred( ACDCTrajPred_t *const pIn_TrajPred );

extern void EMPCalcPositionAtTime( float32 fTime, ACDCTrajPred_t const *const pIn_Obj, SFLVector2D_t *const pOut_Position );
extern void EMPCalcVelocityAtTime( float32 fTime, ACDCTrajPred_t const *const pIn_Obj, SFLVector2D_t *const pOut_Velocity );
extern float32 EMPGetStopTime(ACDCTrajPred_t const * const p_traj);
#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
extern void EMPCalcDynObjToEgoFrontRelation( ObjNumber_t    const         iObjectIndex,
                                             float32              * const pfMinDistTime,
                                             SFLVector2D_t        * const pMinDistEgoPos,
                                             float32              * const pfTargetMinDist,
                                             float32              * const pfTargetCurDist );
#endif /* (CD_USE_TURNINTOVRU_HYPOTHESIS) */

#endif /* ACDC_CFG_EMP */

#endif /* EMP_EXT_H_INCLUDED */

///\}
