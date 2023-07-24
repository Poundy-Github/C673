/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection (CG situation analysis)

PACKAGENAME:               cd_int.h

DESCRIPTION:               Internal Header of the Colision Detection component

AUTHOR:                    $Author: Maksuti, Zijad (uid32055) $

CREATION DATE:             $Date: 2020/01/10 14:56:50CET $

VERSION:                   $Revision: 1.87 $

LEGACY VERSION:            Revision: 2.18

**************************************************************************** */

#ifndef CD_INT_INCLUDED
#define CD_INT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_int.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup cd
\{
*/
/*****************************************************************************
  MACROS
*****************************************************************************/
/*! @brief          Bit Mask for u32 Variables 1111 1111 1111 1111 1111 1111 1111 1111 
      - @typical    0xFFFFFFFFu
      - @attention  Do not change!
*/
#define CD_BITMASK_UINT32 (0xFFFFFFFFu)

/*****************************************************************************
  GLOBALS
*****************************************************************************/
/*---cd_par globals---*/

/*PRQA S 3432 2*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
ACDC_DECL_PARAM(MEMSEC_REF float32, CD_LONG_SAFETY_DIST_CUST)
ACDC_DECL_PARAM(MEMSEC_REF float32, CD_COMMON_TRACK_WIDTH_FACT)

#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
/*PRQA S 3432 2*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
  ACDC_DECL_PARAM(MEMSEC_REF float32, ACDC_LONG_OFFSET_SIMU)
  ACDC_DECL_PARAM(MEMSEC_REF float32, ACDC_LAT_OFFSET_SIMU)
#endif

  /*! @brief  This table maps the raw ego velocity to assumed max. x-acceleration for comfort braking.*/
extern MEMSEC_REF const CML_t_Vector2D CD_COMFORT_EGO_ACCEL_X[CD_NUMBER_OF_COMFORT_EGO_ACCEL_X_VALUES];
/*! @brief  This table maps the raw ego velocity to assumed max. y-acceleration for comfort steering.*/
extern MEMSEC_REF const CML_t_Vector2D CD_COMFORT_EGO_VEL_FACTOR_Y[CD_NUMBER_OF_COMFORT_EGO_VEL_FACTOR_Y_VALUES];
/*! @brief  This table maps the raw ego velocity to assumed max. y-acceleration for emergency steering. */
extern MEMSEC_REF const CML_t_Vector2D CD_EMERGENCY_EGO_ACCEL_Y[CD_NUMBER_OF_EMERGENCY_EGO_ACCEL_Y_VALUES];

extern MEMSEC_REF const CML_t_Vector2D CD_RUN_UP_TTC_TRACK_WIDTH[CD_RUN_UP_TTC_WIDTH_NO_POINTS];

extern MEMSEC_REF const CML_t_Vector2D CD_RUN_UP_TTC_TRACK_WIDTH_WIDE[CD_RUN_UP_TTC_WIDTH_FAC_NO_POINTS];

extern MEMSEC_REF const CML_t_Vector2D CD_PED_COLL_DOM_DG_MAX_RATE_VEC[CD_NUMBER_OF_DOMINANTDOWNGRADE_MAX_RATE_VALUES];
/*PRQA S 0777 1 *//*identifier differs clearly from other identifiers */
extern MEMSEC_REF const CML_t_Vector2D CD_PED_COLL_DOM_DG_MIN_FACTOR_VEC[CD_NUMBER_OF_DOMINANTDOWNGRADE_MIN_FACTOR_VALUES];

extern MEMSEC_REF const CML_t_Vector2D CD_EGO_ADD_WIDTH_IN_VELO_DEP_M      [CD_NUMBER_OF_EGO_ADD_WIDTH_IN_VELO_DEP_VALUES ];
extern MEMSEC_REF const CML_t_Vector2D CD_EGO_ADD_WIDTH_OUT_VELO_DEP_M     [CD_NUMBER_OF_EGO_ADD_WIDTH_OUT_VELO_DEP_VALUES];
extern MEMSEC_REF const CML_t_Vector2D CD_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_M  [CD_NOF_EGO_RED_WIDTH_OBJ_LAT_VEL_DEP_VALUES   ];


#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)

/*! @brief  This table maps the object distance to the assumed velocity reduction*/
extern MEMSEC_REF const CML_t_Vector2D CD_BRAKE_JERK_VEL[CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES];
/*! @brief  This table maps the object distance to the assumed minimum duration of a brake jerk.*/
extern MEMSEC_REF const CML_t_Vector2D CD_BRAKE_JERK_TIME[CD_NUMBER_OF_BRAKE_JERK_VEL_TIME_VALUES];

#endif

  /*--- Pass by small objects inhibition parameters ---*/
#if (CD_USE_NAR_TRAJ_RUN_UP_SMALL_OBJ)

  /*! @brief  Minimum required distance for narrowing trajectory width for small objects */
/*PRQA S 3432 1*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
extern MEMSEC_REF ACDC_PAR_CONST CML_t_Vector2D CD_RUNUP_SOBJ_OCC_VEGO_DIST[CD_RUNUP_SOBJ_HYP_OCC_VEGO_DIST_NO];
/*! @brief  Trajectory width narrowing factors */
extern MEMSEC_REF CML_t_Vector2D CD_RUNUP_SOBJ_HYP_OCC_DIST_RED[CD_RUNUP_SOBJ_HYP_OCC_RED_OVER_DIST_NO];
/*PRQA S 3432 2*/ /* date: 2019-05-15, reviewer: Schnurr, Clemens, reason: Macro does not work with paranthesis*/
/*! @brief  Transition section for trajectory width reduction */
FCT_DECL_FIX_PARAM(MEMSEC_REF float32, CD_RUNUP_SOBJ_HYP_OCC_DIST_RED_FACT)

#endif

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
/*! @brief  The curvature threshold over speed for detecting the turn scenario */
extern MEMSEC_REF const CML_t_Vector2D CD_EGO_DRV_CRV_TRN_THRE       [CD_EGO_DRV_CRV_TRN_THRE_NO];
/*! @brief  The curvature threshold over speed for keeping the detected turn scenario */
extern MEMSEC_REF const CML_t_Vector2D CD_EGO_DRV_CRV_KEEP_TRN_THRE  [CD_EGO_DRV_CRV_TRN_THRE_NO];
#if(CD_BLK_DIST_TURN_OPST_DIR)
/*! @brief  The distance, in which the detection of turn scenario in the opposite direction is blocked,
            to avoid the detection of lane change orientation correction phase as turning */
extern MEMSEC_REF const CML_t_Vector2D CD_EGO_DRV_CRV_BLK_OPP_DIR    [CD_EGO_DRV_CRV_BLK_OPP_DIR_NO];
#endif
#endif
/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/* Deactivate QA-C warning 3406; Reviewer: S. Schwarzkopf; Date: 05.12.2014; 
    Reason: Styleguide specifies this as best practice (R231, R238) and 
    ALGO_INLINE is defined compiler dependent for inlining with internal linkage.
    Review-ID: */
/* PRQA S 3406 ALGO_INLINES */

ALGO_INLINE void CD_SET_HYP_BIT(uint32 *var, uint32 hypnr);
ALGO_INLINE void CD_CLEAR_HYP_BIT(uint32 *var, uint32 hypnr);

#if(ACDC_CFG_CALC_TRAJ_OCCUPANCY)
extern void CD_v_CalculateTrajectoryOccupancy(SFLTrajOccupancy_t *const pTrajOccupancy);
extern void CD_v_TrajOccCalcCriticalities(SFLTrajOccupancy_t const *const pTrajOccupancy, float32 *const pfTTC, float32 *const pfTTB);
#endif

extern eGDBError_t CDRun(void);

extern void CDHypSelPrepareCycleHypothesesSelection(void);
extern void CDCalculateObjectProperties(void);

extern void CDHypSelFillHypothesesInterface( void);
extern void CDHypSelCreateInternalHypotheses(CDIntHypothesis_t        *const pHypothesis);
extern void CDHypCommonInitHypothesisInt (CDIntHypothesis_t * const pIntHypothesis, ObjNumber_t iObj, eCDHypothesisType_t eType);
extern void CDCalculateInlap(float32 const        fDistance,
                             float32 const        fDistanceVar,
                             float32 const        fTrajectoryWidth,
                             float32 const        fTrajectoryWidthVar,
                             float32 const        fObjectWidth,
                             float32 const        fObjectWidthVar,
                             float32      * const fInlap,
                             float32      * const fInlapVar);

extern void CDCalculateInlapAtTime(ObjNumber_t const         iObjectIndex,
                                   float32                   fPredTime,
                                   float32                   fCorridorWidth,
                                   float32           * const pfInlap,
                                   float32           * const pfInlapVar);

extern float32 CD_f_CalcEgoCorridorOccupancy(ObjNumber_t const iObjectIndex);

#if (ACDC_CFG_TURN_ASSIST)
extern CDObjectsCenterOfFront_t CDCalculateObjectsCenterOfFront(const ObjNumber_t iObjectIndex);
#endif

#if   ( defined(CD_USE_CUSTOM_TRACK_ASSIGNMENT) && (CD_USE_CUSTOM_TRACK_ASSIGNMENT == SWITCH_ON) )
  extern void CDAssignTrackProbabilityCustom( ObjNumber_t iObjectIndex);
#endif
/*------------ object merge and delete ----------------*/
extern void CDDeleteInternalObject(ObjNumber_t const iObjectIndex);

/*------------ hypotheses ----------------*/

#if (CD_USE_RUN_UP_HYPOTHESIS)
extern void CDHypoRunUpMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
extern void CDHypoRunUpInitInternalData(ObjNumber_t const iObjectIndex, boolean const bKeepIntercycleData);
#endif /* CD_USE_RUN_UP_HYPOTHESIS */

#if (CD_USE_ACC_HYPOTHESIS)
extern void CDHypoAccMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif/* CD_USE_ACC_HYPOTHESIS */

#if (CD_USE_CUT_IN_HYPOTHESIS)
extern void CDHypoCutInMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
extern void CDHypoCutInInitInternalData(ObjNumber_t const iObjectIndex);
#endif /* CD_USE_CUT_IN_HYPOTHESIS */

#if (CD_USE_PASS_HYPOTHESIS)
extern void CDHypoPassMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif /* CD_USE_PASS_HYPOTHESIS */

#if (CD_USE_FOLLOW_HYPOTHESIS)
extern void CDHypoStaticMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif /* CD_USE_FOLLOW_HYPOTHESIS */

#if (CD_USE_COLL_HYPOTHESIS)
extern void CDHypoCollisionMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif /* CD_USE_COLL_HYPOTHESIS */

#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)
extern void CDHypoRunUpStationaryMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
extern void CDHypoRunUpStationaryPost(void);
#endif /* CD_USE_RUN_UP_STAT_HYPOTHESIS */

#if (CD_USE_PED_COLL_HYPOTHESIS)
extern void CDHypoPedCollMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif /* CD_USE_PED_COLL_HYPOTHESIS */

#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)
extern void CDHypoCycleCollMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif

#if (CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS)

extern void CD_v_HypoOncomingMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);

#if (CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION)
extern void CDHypoDrvIntOncInitInternalData(ObjNumber_t const iObjectIndex);
#endif /* CD_HYP_DRIVE_INTO_ONCOMING_USE_SMOOTHENED_ORIENTATION */

#endif /* CD_USE_DRIVE_INTO_ONCOMING_HYPOTHESIS */

#if (CD_USE_TURNINTOVRU_HYPOTHESIS)
extern void CDHypTurnIntoVRUMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
extern void CDEgoTurningEval    (void);
#endif /* CD_USE_TURNINTOVRU_HYPOTHESIS */

#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
extern void CDHypDriveIntoSloMoMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif /* CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS */

extern float32              CD_f_GetTTC                     (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTC2                    (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTC3                    (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTC4                    (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTMLongPre              (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTMLongAcute            (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetLongNecAccel            (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTBDynPre               (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTBDynAcute             (ObjNumber_t const iObjectIndex); 
extern float32              CD_f_GetLatNecAccelLeft         (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetLatNecAccelRight        (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetLatNecAccel             (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetClosingVelocity         (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSPreLeft              (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSPreRight             (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSPre                  (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSAcuteLeft            (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSAcuteRight           (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTSAcute                (ObjNumber_t const iObjectIndex);
#if (ACDC_CFG_TURN_ASSIST)
extern float32              CD_f_GetCorridorStopDistance    (ObjNumber_t const iObjectIndex);
#endif
extern EM_t_GenObjSensorSource CD_e_GetSensorSource         (ObjNumber_t const iObjectIndex);
#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
extern float32              CD_f_GetTTCBrakeJerk            (ObjNumber_t const iObjectIndex);
extern float32              CD_f_GetTTCBrakeJerkFactor      (ObjNumber_t const iObjectIndex);
#endif /* CD_USE_BRAKE_JERK_TTC */


extern CDMovement_t CD_s_GetEgoMov( void );
extern CDMovement_t CD_s_GetObjMov( ObjNumber_t         const iObjectIndex,
                                    ACDCObjPositions_e  const eObjPosition,
                                    ACDCObjKinematics_e const eObjKinematics);


#if (CD_USE_CROSSING_HYPOTHESIS)
extern void CDHypoCrossingMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
extern void CDHypCrossingInitInternalData(ObjNumber_t const iObjectIndex);
#endif /* CD_USE_CROSSING_HYPOTHESIS */
#if(CD_USE_LONG_COLL_HYPOTHESIS)
extern void CDHypoLongMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched);
#endif

#if (CD_USE_LONG_COLL_HYPOTHESIS)
void CDHypoLongCollInitInternalData(ObjNumber_t const iObjectIndex);
#endif

#if (CD_USE_RUN_UP_STAT_HYPOTHESIS)
void CDHypoRunUpStatInitInternalData(ObjNumber_t const iObjectIndex);
#endif

#if (CD_USE_EPF)
extern void EPFProcess(ObjNumber_t const         RelObjID, 
                       EPFOutput_t       * const pEPFOutput);
#endif

#if (CD_USE_GEN_PSC)
extern void     CDPSCInit                 ( ObjNumber_t const iObjectIndex );
extern float32 CDPSCGetProbCollision      ( ObjNumber_t         const iObjectIndex,
                                            float32             const fEgoCorridorWidthLeft,
                                            float32             const fEgoCorridorWidthRight,
                                            CDPSCRefPointType_t const eRefPointType );

/*---------------PSC History function calculation--------------------*/
extern uint8   CDGetCompleteHistory    ( CDHistoryFloat_t const * const   pIn_FloatHistory        ,
                                         float32                          afHistory[]             ,
                                         uint8                            uiArrayLength            );

extern void   CDHistIntegrate          ( float32          const           afXValues[]             ,
                                         float32          const           afYValues[]             ,
                                         float32                          fLeftIntLimX            ,
                                         float32                          fRightIntLimX           ,
                                         uint8            const           uiLenXYVec              ,
                                         float32                *         pOut_fHistIntegralResult );

extern void   CDUpdateHistory          ( void                                                      );

extern void   CDCalcHistDistToTraj     ( CDKinHistObj_t   const * const   pIn_Obj                 ,
                                         uint8                            uiMaxSteps              ,
                                         float32                          afHistDistToTraj[]      ,
                                         float32                          afHistDistOnTraj[]       );

#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)||(CD_USE_PED_COLL_HYPOTHESIS)
extern void CDPSCCalcCorridorWidthCrossVru ( ObjNumber_t  const   iObjectIndex,
                                             float32            * fEgoVeloDepWidthLeft,
                                             float32            * fEgoVeloDepWidthRight );
#endif /* #if (CD_USE_BICYCLE_COLL_HYPOTHESIS)||(CD_USE_PED_COLL_HYPOTHESIS) */
#endif /*#if (CD_USE_GEN_PSC)*/

extern float32 CDCalculateProbOverlap             ( float32                              fTrajOverlapNow ,
                                                    float32                              fTrajOverlapTTC  );
extern void CDCalculateTrajectoryOverlapNowAndPred( ObjNumber_t          const           iObjectIndex    ,
                                                    float32                    * const   pfTrajOverlapNow,
                                                    float32                    * const   pfTrajOverlapTTC );
/*------------ criticality calculations being used externally ----------------*/

void CDPredictMovement( CDMovement_t const * const pMovement, 
                        CDMovement_t       * const pPredictedMovement, 
                        float32                    fPredictTime,
                        boolean                    bStopXDir, 
                        boolean                    bStopYDir );

boolean CDCalculateAnecLongLatency( CDAdjSafeDistance_t const * const pCDAdjSafeDistance,
                                    ObjNumber_t         const         iObjectIndex,
                                    fAccel_t                 * const  pfAnecLong );


#if defined(CD_USE_TTM_LONG) && (CD_USE_TTM_LONG == SWITCH_ON)

extern boolean CDCalculateTTMLongCore(ACDCObjDesc_t  const * const pttmRelObj1,
                                      ACDCObjDesc_t  const * const pttmRelObj2,
                                      float32                      fRelevantAcceleration,
                                      float32                      fEgoVelocity,
                                      fTime_t              * const pfTTMLong,
                                      boolean              * const bCollisionAvoidable);
#endif /* CD_USE_TTM_LONG */

#if(CD_USE_HYP_COMMON)
#if( (EM_GEN_OBJECT_INTFVER >= 0x0D) && (CD_USE_EM_FPS_OBJCLASS == SWITCH_ON) )
extern eEBAObjectClass_t CDHypCommonMapFPSToEBAObjClass(EM_t_GenEbaObjClass FPS_ObjectClass);
#endif
#endif

#if (!CD_USE_CONST_OBJ_GEOMETRY_VAR)
extern void CDCalcGeometryVarianceFromShapePoints(ObjNumber_t iObjectIndex, ACDCGeometry_t * const GeometryVar);
#endif
extern boolean      CDCalculateVehStopTime  ( fVelocity_t fVelocity, fAccel_t fAcceleration, fTime_t* pfStopTime );
extern fDistance_t  CDCalculateDistance     ( fDistance_t fDistance, fVelocity_t fVelocity, fAccel_t fAcceleration, fTime_t fTime );
extern fVelocity_t  CDCalculateVelocity     ( fVelocity_t fVelocity, fAccel_t fAcceleration, fTime_t fTime );
extern boolean      CDCalculateTTC          ( CDMovement_t const * const pEgoMovement, CDMovement_t const * const pObjMovement, fTime_t* const pfTTC);

/*------------- custom functions----------*/
extern void CDInitCustomerData( void );

extern void CDCalcCustomerFunctions (void);

#if CD_USE_GENERIC_HYPOTHIS_HANDLER
extern void CDGenHypothesisHandler(void);
#else
extern void CDCustomerHypothesisHandler(void);
#endif

#if (CD_PED_USE_EM_ROAD_ESTIMATION)
extern boolean CDPedIsOutsideRoadEstimation( ObjNumber_t iObjectIndex );
#endif /* CD_PED_USE_EM_ROAD_ESTIMATION */

/* Check if we are in QA-C: PRQA_SIZE_T is defined in QA-C environment. */
#ifdef PRQA_SIZE_T
/* Switch off QA-C warnings on side effects for functions, which don't have 
     any side effects and will sure never have some. */

#endif

/*------------- variables -----------*/
extern CDAdjSafeDistance_t CDAdjSafeDistance; /*!< CGEB safety distance parameters @allow:oem_bmw */


/*! @brief       maximum number of CD hypotheses types 
  - @typical    16
*/
#define CDHypothesisType_Max (32u)

/*****************************************************************************
  INLINE FUNCTIONS
*****************************************************************************/



/*************************************************************************************************************************
  Functionname:         CD_SET_HYP_BIT                                                                               */ /*!

  @brief                Sets the bit ("hypnr" - 1) in the unsigned integer "var" to 1.

  @description          Is usually used for the setting of hypotheses bits.

  @return               void

  @param[in,out]        *var :  Integer in which the bit shall be set.
  @param[in]            hypnr : Number of the hypothesis.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @author
*************************************************************************************************************************/
ALGO_INLINE void CD_SET_HYP_BIT(uint32 *var, uint32 hypnr)
{
  if ( (hypnr > CDHypothesisType_No) && (hypnr <= CDHypothesisType_Max) )
  {
    (*var)|= ((uint32)1u<<( hypnr - 1u));
  }
  else
  {
    /* do nothing */
  }
}

/*************************************************************************************************************************
  Functionname:         CD_CLEAR_HYP_BIT                                                                             */ /*!

  @brief                Sets the bit ("hypnr" - 1) in the unsigned integer "var" to 0.

  @description          Is usually used for the resetting of hypotheses bits.

  @return               void

  @param[in,out]        *var :  Unsigned integer in which the bit shall be reseted.
  @param[in]            hypnr : Number of the hypothesis bit that shall be reseted.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @author
*************************************************************************************************************************/
ALGO_INLINE void CD_CLEAR_HYP_BIT(uint32 *var, uint32 hypnr)
{
  if ( (hypnr > CDHypothesisType_No) && (hypnr <= CDHypothesisType_Max) )
  {
    (*var)&= ( (~((uint32)1u<<( hypnr - 1u) )) & CD_BITMASK_UINT32);
  }
  else
  {
    /* do nothing */
  }
}


/* PRQA L:ALGO_INLINES */
/** \} */
#endif /*(ACDC_CFG_CD)*/

#endif /*CD_INT_INCLUDED*/


