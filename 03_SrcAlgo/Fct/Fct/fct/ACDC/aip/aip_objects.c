/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_object.c

DESCRIPTION:               Functions for the preprocessing of object specific data for the ACDC component

AUTHOR:                    Almalih Ayman (uid6193)

CREATION DATE:             03.12.2018

VERSION:                   $Revision: 1.17 $

**************************************************************************** */
#include "aip_int.h"

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

#pragma PRQA_NO_SIDE_EFFECTS SFL_b_IntersectPositionVectors //function can be marked as being free from side effects(Needed for Helix QAC warning fix).

#if(ACDC_CFG_AIP)

/************************************************************************/
/*                      MODULE DESCRIPTION                              */
/************************************************************************/
/*!
@addtogroup aip_objects Objects
@ingroup aip
@brief            Module for the calculation of object specific pre processing. \n\n
@description      The following functions are provided by this module:
                  - Filling of the @ref ACDC_ObjectList : @ref AIP_v_PreProcessObjectList
                  - Initialization of a single ACDC Object: @ref AIP_v_InitObject
                  - Initialization of the entire ACDC_ObjectList : @ref AIP_v_InitObjectList
@{
*/

/************************************************************************/
/*                    FUNCTION DECLARATIONS                             */
/************************************************************************/

static void       AIP_v_CalcPosClosestInCorridor(ObjNumber_t const iObjectIndex, SFLVector2D_t *const pPosClosestInCorr);
static void       AIP_v_FillObjectMovement(ObjNumber_t const iObjectIndex, ACDCObjMovement_t * const pObjMovement, ACDCObjPositions_t * const pPositions);
static void       AIP_v_CalcObjPositions(ObjNumber_t const iObjectIndex, ACDCObjPositions_t *const pPositions  );
static float32    AIP_f_CalcDistInCorridor(SFLPolyDeg2_t const * const pEgoTraj   , float32 fWidthRight, float32 fWidthLeft, SFLVector2D_t const * const pPos);
static void       AIP_v_CalcClosestPosToTraj( SFLPolyDeg2_t const * const pTrajectory, SFLVector2D_t const * const pPos1, SFLVector2D_t const * const pPos2, SFLVector2D_t * const pPosClosest);

#if(ACDC_CFG_USE_EBA_BOX_OBJECTS)
static boolean    AIP_b_GenerateEBABoxedObject(ACDCGeometry_t * const pGeometry, SFLVector2D_t * const pBoxPosition, EM_t_GenObject const * const pEMObject);
#if (ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE)
static void       AIP_v_LimitBoxedObjectDimensions(ACDCGeometry_t * pEBAGeometry, const EM_t_GenObject * const pEMObject, const EM_t_ARSObject * const pARSObject);
#endif /* #if (ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE) */
#endif /* #if (ACDC_CFG_USE_EBA_BOX_OBJECTS)*/

#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
static void       AIP_v_ShiftObjectByOffset(ACDCObject_t * const pACDCObj, float32 const fOffsetLong, float32 const fOffsetLat);
#endif

/************************************************************************/
/*                    FUNCTION DEFINITIONS                              */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:         AIP_v_PreProcessObjectList                                                                     */ /*!

  @brief                Fills the ACDC Object with all data that is required for the further calculation.

  @description          Resets and fills the entire @ref ACDC_ObjectList with all data that is required for 
                        the further calculation. \n
                        At this state of the code not all object related values have been calculated. Therefore access 
                        to the ACDC object has to be handled with care. It has to be assured that all preconditions \n
                        of a function are fulfilled before it is called.
                        @startuml AIP_v_PreProcessObjectList_activity.png
                        start
                          partition "Execute for each object" {
                            #Orange:Initialize the ACDC internal object:
                            <b>AIP_v_InitObject</b> >
                            if(Object is deleted?) then (Yes)
                              :1}
                            else (No)
                              :2}
                              #Orange:Fill the objects movement structure. 
                              Also fill the positions measured and var:
                              <b>AIP_v_FillObjectMovement</b> >
                              note left: **Preconditions:**\nNone
                              #Orange:Calculate the objects center position:
                              <b>AIP_v_CalcObjectCenterFromShapePoints</b> >
                              note left: **Preconditions:**\nNone
                              #Orange:Calculate the qualities of the objects shape points:
                              <b>AIP_v_CalcShapePointQualities</b> >
                              note left: **Preconditions:**\nNone
                              #Orange:Calculate the objects geometry on base of the shape points:
                              <b>AIP_v_CalcGeometryFromShapePoints</b> >
                              note left: **Preconditions:**\nNone
                              #Orange:Limit the shape points and the geometry 
                              according to the object class. Also shift the center position:
                              <b>AIP_v_CalculateLimitedShapePoints</b> >
                              note left
                                **Preconditions:**
                                  - ShapePoint Geometry has been calculated
                                  - ShapePoint Qualities have been calculated
                              end note

partition #LightBlue **ACDC_CFG_USE_EBA_BOX_OBJECTS** {
                              #Orange:Calculate the objects geometry and position by 
                              applying the Boxed objects attempt:
                              <b>AIP_b_GenerateEBABoxedObject</b> >
                              note left: **Preconditions:**\nNone
partition #LightBlue **ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE** {
                              #Orange:Limit the objects extensions according to its class:
                              <b>AIP_v_LimitBoxedObjectDimensions</b> >
                              note left: **Preconditions:**\n - Box Object Geometry has been calculated
}
                              :Overwrite the Measured position with the object box position;
}
                              #Orange:Calculate the objects trajectory relation:
                              <b>EMP_v_CalcObjToEgoTrajRelation</b> >
                              note left
                                **Preconditions**
                                  - Positions Center, Measured and Var are filled
                                  - Movement Abs and Var are filled
                                  - Geometry has been calculated
                                  - Shape Point Qualities have been calculated
                              end note
                          
                              #Orange:Calculate the additional object positions ClosestInCorridor and ClosestInX:
                              <b>AIP_v_CalcObjPositions</b> >
                              note left 
                                **Preconditions**:
                                  - Limited Shape points have been calculated
                                  - Trajectory Relation is filled
                              end note
                            endif
                          }
                        stop
                        @enduml

  @return               void

  @param[in,out]        void

  @glob_in              @ref ACDC_p_GetEMARSObj \n
                        @ref ACDC_p_GetEMGenObj \n
  @glob_out             ACDC_p_ModObjDesc\n

  @c_switch_part        @ref ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE \n
                        @ref ACDC_CFG_USE_EBA_BOX_OBJECTS \n
                        @ref ACDC_CFG_USE_ADD_OFFSET_SIMU
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 Access functions to the ACDC objects can be used.

  @InOutCorrelation     see description

  @remark               At this point of the code the access functions to the ACDC object have to be handled with care, as the 
                        data structure is filled step by step. Before using an access function, make sure the corresponding 
                        value has already been filled!

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_PREPROCESSOBJECTLIST_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_PreProcessObjectList(void)
{

  ObjNumber_t iObjectIndex;
  boolean bBoxFlag;

  for (iObjectIndex = 0; iObjectIndex < EM_N_OBJECTS; iObjectIndex++)
  {
   
    ACDCObject_t         * const pCurrACDCObj     = ACDC_p_ModObjDesc(iObjectIndex);
    EM_t_GenObject const * const pCurrentEMObject = ACDC_p_GetEMGenObj(iObjectIndex);
	bBoxFlag = TRUE;

    AIP_v_InitObject(pCurrACDCObj);

    if (pCurrentEMObject->General.eMaintenanceState != ((uint8)EM_GEN_OBJECT_MT_STATE_DELETED) )
    {
      SFLVector2D_t  PositionObjBox = {0};
      ACDCGeometry_t GeometryObjBox = {0};

      

      /* Fill the objects movement structure and Positions: Measured and Var*/
      AIP_v_FillObjectMovement(iObjectIndex, &(pCurrACDCObj->ObjDescMain.Movement), &(pCurrACDCObj->ObjDescMain.Positions));
      
      /* Calculate the objects center position*/
      AIP_v_CalcObjectCenterFromShapePoints(iObjectIndex, &(pCurrACDCObj->ObjDescMain.Positions.Center));

      /* Calculate the qualities of the shape points */
      AIP_v_CalcShapePointQualities    (iObjectIndex, (pCurrACDCObj->ObjDescAdd.afShapePointQualities));

      /* Calculate the objects geometry from its shape points */
      AIP_v_CalcGeometryFromShapePoints(iObjectIndex, &pCurrACDCObj->ObjDescMain.Geometry);

      /* Limit the objects geometry according to its object class. Shift object positions if necessary. */
      AIP_v_CalculateLimitedShapePoints(iObjectIndex, &pCurrACDCObj->ObjDescMain.Geometry, &(pCurrACDCObj->ObjDescMain.Positions.Center), pCurrACDCObj->ObjDescAdd.asLimitedShapePoints);


#if (ACDC_CFG_USE_EBA_BOX_OBJECTS)
      /************************************************************************/
      /* Calculate BoxObjects                                                 */
      /************************************************************************/
      /* Calculate the objects geometry and position by using the object boxes */
      (void)AIP_b_GenerateEBABoxedObject(&GeometryObjBox, &PositionObjBox, pCurrentEMObject);
#if (ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE)
      /* Limit the boxed objects dimensions */
      AIP_v_LimitBoxedObjectDimensions(&GeometryObjBox, pCurrentEMObject, ACDC_p_GetEMARSObj(iObjectIndex));
#endif
      /* Overwrite the position calculated on base of the shape points. Do this before calling 
      EMP_v_CalcObjToEgoTrajRelation, as the measured position is used there*/
      pCurrACDCObj->ObjDescMain.Positions.GenObject   = PositionObjBox;
#endif

#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
      AIP_v_ShiftObjectByOffset(pCurrACDCObj, ACDC_LONG_OFFSET_SIMU, ACDC_LAT_OFFSET_SIMU);
      PositionObjBox.fX += ACDC_LONG_OFFSET_SIMU;
      PositionObjBox.fY += ACDC_LAT_OFFSET_SIMU;
#endif

      /* Calculate the relation of the objects kinematics and the ego trajectory */
      EMP_v_CalcObjToEgoTrajRelation(iObjectIndex, &(pCurrACDCObj->ObjDescMain.TrajRelation));

      /* Calculate all remaining object related positions: Closest In X and Closest in Corridor */
      AIP_v_CalcObjPositions(iObjectIndex, &(pCurrACDCObj->ObjDescMain.Positions));


#if (ACDC_CFG_USE_EBA_BOX_OBJECTS)
      /* Overwrite the geometry calculated on base of the shape points */
      /* Do this AFTER the call of EMP_v_CalcObjToEgoTrajRelation and AIP_v_CalcObjPositions to assure that the circles are 
         calculated on base of the shape point geometry */
	  // Used for Orientation_CCRS C385
	  if ((fABS(pCurrACDCObj->ObjDescMain.Positions.Center.fY) < 0.9)
		  && (pCurrACDCObj->ObjDescMain.Geometry.fOrientation < 0.75 && pCurrACDCObj->ObjDescMain.Geometry.fOrientation > 0.55)
		  && (pCurrentEMObject->Attributes.eClassification == EM_GEN_OBJECT_CLASS_CAR)
		  && (pCurrentEMObject->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
		  && (pCurrentEMObject->General.uiLifeCycles > 60))
	  {
		  bBoxFlag = FALSE;
	  }

	  if (bBoxFlag)
	  {
		  pCurrACDCObj->ObjDescMain.Positions.ClosestInX = PositionObjBox;
		  pCurrACDCObj->ObjDescMain.Geometry = GeometryObjBox;
	  }
      
#else
      _PARAM_UNUSED(PositionObjBox);
      _PARAM_UNUSED(GeometryObjBox);
#endif

    }
  }

}


/*************************************************************************************************************************
  Functionname:         AIP_v_InitObject                                                                         */ /*!

  @brief                Initializes the ACDC Object structure.

  @description          Initializes the entire ACDC Object structure: @ref ACDCObject_t

  @return               void

  @param[in,out]        pObject: Customer specific object data.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Christian Obst

  @testmethod           @ref TEST_AIP_V_INITOBJECT_001 

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_InitObject(ACDCObject_t *const pObject)
{
  uint32 uSPPosition;
  /*PRQA S 0315 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  (void)memset(pObject, 0, sizeof(ACDCObject_t) );

  for (uSPPosition = 0; uSPPosition < ACDC_NOF_SP_POSITIONS; uSPPosition++)
  {
    pObject->ObjDescAdd.aiShapePointPositions[uSPPosition]  = ACDC_SP_POSITIONS_INIT;
  }

}

/*************************************************************************************************************************
  Functionname:         AIP_v_InitObjectList                                                                       */ /*!

  @brief                Initializes the ACDC Object structure.

  @description          Initializes the entire ACDC Object structure: @ref ACDCObject_t

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjDesc

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Christian Obst

  @testmethod           @ref TEST_AIP_V_INITOBJECTLIST_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_InitObjectList(void)
{
  ObjNumber_t iObjectIndex;
  for (iObjectIndex = 0; iObjectIndex < EM_N_OBJECTS; ++iObjectIndex)
  {
    AIP_v_InitObject(ACDC_p_ModObjDesc(iObjectIndex));
  }

}

/*************************************************************************************************************************
  Functionname:         AIP_v_FillObjectMovement                                                                        */ /*!

  @brief                Writes data from the input structure to the ACDC internal object structure.

  @description          The function follows the subsequent steps:
                        @startuml AIP_v_FillObjectMovement_activity.png
                          start
                          if(Dynamic property is stationary or stopped\nAND Class is not pedestrian or cyclist) then (Yes)
                            :1}
                            :Set velocities and
                            accelerations to 0;
                            note left
                                Stationary objects shall have velocity 0,
                                for pedestrian and cyclists, stationary
                                detection is not reliable
                            end note
                          else(No)
                            :Calculate absolute X/Y-velocities and 
                            accelerations under consideration of 
                            the yaw rate;
                            note left: >see Formula 1 & 2
                            
                            if (Dynamic property is moving\nAND X-velocity / X-acceleration below 0?) then (Yes)
                              :2}
                              :Object X-velocity = 0 / X-acceleration = 0;
                              note left
                                  Correct speed / acceleration 
                                  to a secure value in case 
                                  the measurement is incorrect
                              end note
                            else (No)
                              :3}
                            endif
                            
                            if (Object is an oncoming pedestrian?) then (Yes)
                              :4}
                              :Object X-acceleration = 0;
                              note left
                                  Necessary until Anec calculation 
                                  for oncomings is clarified
                              end note
                            else(No)
                              :5}
                            endif
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[
  @param[in,out]        pObjMovement : Pointer to movement of the object.
  @param[in]            pPositions :   Pointer to the positions structure to fill the GenObject and the Var position.

  @glob_in              @ref ACDC_p_GetEMGenObj \n
                        @ref ACDC_p_GetEgoKinematics        \n
                        @ref ACDC_p_GetEgoMovementObjSync   \n
  @glob_out             None

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER\n
                        @ref ACDC_CFG_FILTER_UNKNOWN_DYNAMIC\n
                        @ref ACDC_CFG_FILTER_OBJ_KINEMATIC_OF_VRUS\n
                        @ref ACDC_CFG_FILTER_OBJ_KINEMATIC_IF_EGO_IS_BRAKING\n
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  Ego Data is filled
  @post                 Object positions Var and GenObject filled. All object Movements filled.

  @InOutCorrelation     
                        - **Formula 1**: Yaw-Rate corrected absolute velocities: \n
                          \f$V_{X,Obj,Abs} = V_{X,Obj,Rel} + V_{X,Ego,Abs} - Dist_{Y,Obj} \cdot YawRate_{Ego}\f$ \n
                          \f$V_{Y,Obj,Abs} = V_{Y,Obj,Rel} + V_{Y,Ego,Abs} + Dist_{X,Obj} \cdot YawRate_{Ego}\f$
                        - **Formula 2**: Absolute accelerations:\n
                          \f$A_{X,Obj,Abs} = A_{X,Obj,Rel} + A_{X,Ego,Abs}\f$ \n
                          \f$A_{Y,Obj,Abs} = A_{Y,Obj,Rel} + A_{Y,Ego,Abs}\f$

  @author               Andreas Hartmann | andreas.hartmann@continental-corporation.com

  @testmethod           @ref TEST_AIP_V_FILLOBJECTMOVEMENT_001 \n
                        @ref TEST_AIP_V_FILLOBJECTMOVEMENT_002 \n
                        @ref TEST_AIP_V_FILLOBJECTMOVEMENT_003 \n
						@ref TEST_AIP_V_FILLOBJECTMOVEMENT_004 \n
                        @ref TEST_AIP_V_FILLOBJECTMOVEMENT_005 \n
                        @ref TEST_AIP_V_FILLOBJECTMOVEMENT_006 \n
						@ref TEST_AIP_V_FILLOBJECTMOVEMENT_007 \n
                        @ref TEST_AIP_V_FILLOBJECTMOVEMENT_008
                        

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_FillObjectMovement(ObjNumber_t       const        iObjectIndex, 
                                     ACDCObjMovement_t       * const pObjMovement ,
                                     ACDCObjPositions_t      * const pPositions)
{

  EM_t_GenObject const * const pEmObj         = ACDC_p_GetEMGenObj(iObjectIndex);
  SFLMovement_t  const * const pEgoMovObjSync = ACDC_p_GetEgoMovementObjSync();
  float32        const         fEgoYawRate    = ACDC_p_GetEgoKinematics()->fYawRate;

  float32 const fEgoAccelX    = pEgoMovObjSync->Accel.fX;
  float32 const fEgoAccelY    = pEgoMovObjSync->Accel.fY;
  float32 const fEgoVelX      = pEgoMovObjSync->Vel.fX;
  float32 const fEgoVelY      = pEgoMovObjSync->Vel.fY;


  pObjMovement->Var.Vel.fX   = SQR(pEmObj->Kinematic.fVabsXStd);
  pObjMovement->Var.Vel.fY   = SQR(pEmObj->Kinematic.fVabsYStd);
  pObjMovement->Var.Accel.fX = SQR(pEmObj->Kinematic.fAabsXStd);
  pObjMovement->Var.Accel.fY = SQR(pEmObj->Kinematic.fAabsYStd);


  if (    (    (pEmObj->Attributes.eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
            || (pEmObj->Attributes.eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED   ) )
       && (     pEmObj->Kinematic.fVabsX            <= ACDC_VEL_THRESHOLD_FORCE_STAT_OBJ_KIN_ZERO                           )
#if (EM_GEN_OBJECT_INTFVER > 12u)
       && (    (pEmObj->Qualifiers.eEbaObjClass     != FPS_EBA_CLASS_CYCLIST                                            )
            && (pEmObj->Qualifiers.eEbaObjClass     != FPS_EBA_CLASS_PEDESTRIAN                                         ) ) )
#else
       && (     pEmObj->Attributes.eClassification  != (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_PEDESTRIAN          )
       && (     pEmObj->Attributes.eClassification  != (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_BICYCLE             ) ) /* prevent artefacts in ANec-LongCalculation*/
#endif
  { /* stationary objects do not move */

    pObjMovement->Rel.Vel.fX   =   (pEmObj->Kinematic.fDistY * fEgoYawRate) - fEgoVelX;
    pObjMovement->Rel.Vel.fY   = - (pEmObj->Kinematic.fDistX * fEgoYawRate) - fEgoVelY;
    pObjMovement->Rel.Accel.fX = - fEgoAccelX;
    pObjMovement->Rel.Accel.fY = - fEgoAccelY;

    pObjMovement->Abs.Vel.fX   = 0.f;
    pObjMovement->Abs.Vel.fY   = 0.f;
    pObjMovement->Abs.Accel.fX = 0.f;
    pObjMovement->Abs.Accel.fY = 0.f;

  }
  else 
  {

    pObjMovement->Rel.Vel.fX   = pEmObj->Kinematic.fVrelX;
    pObjMovement->Rel.Vel.fY   = pEmObj->Kinematic.fVrelY;
    pObjMovement->Rel.Accel.fX = pEmObj->Kinematic.fArelX;
    pObjMovement->Rel.Accel.fY = pEmObj->Kinematic.fArelY;

    /* Absolute speeds */
    pObjMovement->Abs.Vel.fX   = pEmObj->Kinematic.fVabsX;
    pObjMovement->Abs.Vel.fY   = pEmObj->Kinematic.fVabsY;
    /* Absolute acceleration */
    pObjMovement->Abs.Accel.fX = pEmObj->Kinematic.fAabsX;
    pObjMovement->Abs.Accel.fY = pEmObj->Kinematic.fAabsY;


 /* Moving Objects => correct Speed to more secure value if sensor measurement is incorrect*/
    if(    (    (          pEmObj->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_MOVING                            )
#if (defined ACDC_CFG_FILTER_UNKNOWN_DYNAMIC) && (ACDC_CFG_FILTER_UNKNOWN_DYNAMIC != SWITCH_OFF)
             || (    (     pEmObj->Attributes.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN                         )
                  && (    (pEmObj->Attributes.eClassification  != (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_PEDESTRIAN)
                       && (pEmObj->Attributes.eClassification  != (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_BICYCLE   ) ) )
#endif
                                                                                                                                     )
        && (               pObjMovement->Abs.Vel.fX                  <  0.f                                                            ) )
    {
      pObjMovement->Abs.Vel.fX     =   0.f;
      pObjMovement->Rel.Vel.fX   =   (pEmObj->Kinematic.fDistY * fEgoYawRate) - fEgoVelX;

      if (pObjMovement->Abs.Accel.fX < 0.f)
      {
        pObjMovement->Abs.Accel.fX =   0.f;
        pObjMovement->Rel.Accel.fX = - fEgoAccelX;
      }
    }


#if (ACDC_CFG_FILTER_OBJ_KINEMATIC_OF_VRUS)
    /* Artificially set the longitudinal acceleration for pedestrians and oncoming cyclists to zero as not to destroy 
    Anec calculation (rework if concept for Anec for oncomings is clarified and/or if oncoming cyclists are considered as use-cases)*/
    if (    (     pEmObj->Qualifiers.eEbaObjClass == FPS_EBA_CLASS_PEDESTRIAN  )
         || (    (pEmObj->Kinematic.fVabsX        <= 0.f                       )
              && (pEmObj->Qualifiers.eEbaObjClass == FPS_EBA_CLASS_CYCLIST   ) ) )
    {
      pObjMovement->Abs.Accel.fX =   0.f;
      pObjMovement->Rel.Accel.fX = - fEgoAccelX;
    }
#endif

#if (ACDC_CFG_FILTER_OBJ_KINEMATIC_IF_EGO_IS_BRAKING)
    /*pin close stationary objects longitudinal to the ground when ego is braking*/
    if(    (fEgoAccelX                                                          <  -2.0f )
        && (pEmObj->Kinematic.fDistX                                            <  12.0f )
        &&( CML_GetBit(pEmObj->Qualifiers.eEbaHypCat, FPS_EBA_HYP_CAT_STAT) == TRUE  ) )
    {
      pObjMovement->Abs.Accel.fX =   0.f;
      pObjMovement->Rel.Accel.fX = - fEgoAccelX;

      pObjMovement->Abs.Vel.fX   =   0.f;
      pObjMovement->Rel.Vel.fX   =   (pEmObj->Kinematic.fDistY * fEgoYawRate) - fEgoVelX;
    }
#endif

  }


  pPositions->GenObject.fX = pEmObj->Kinematic.fDistX;
  pPositions->GenObject.fY = pEmObj->Kinematic.fDistY;

  /* Position variances are set to zero until the further handling of variances is clarified */
  pPositions->Var.fX       = 0.f;
  pPositions->Var.fY       = 0.f;

}

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcObjPositions                                                                      */ /*!

  @brief                Calculate all positions attached to the ACDC object structure.

  @description          The following positions are attached to each object:
                        - Measured: \n
                          The raw object position provided by the gen object list
                        - Var: \n
                          The X and Y variances of the provided positions
                        - ClosestInX: \n
                          The Edge of the object which is the closest to the ego vehicle in x direction.
                          (ATTENTION: The y-coordinate of this position might jump due to changes in the objects orientation)
                        - Object center: (filled in a previous function call)\n
                          The center of the objects limited shape points.
                          (ATTENTION: The position might jump, as changes in the object class influence the objects size.)

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range[0,+...[
  @param[in,out]        pPositions   : Structure containing all relevant object positions.

  @glob_in              @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_a_GetObjLimitedShapePoints
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  Object center is already calculated in the functions @ref AIP_v_CalcObjectCenterFromShapePoints 
                        and @ref AIP_v_CalculateLimitedShapePoints.
  @post                 None

  @InOutCorrelation     see description

  @todo                 Think about calculating the closest in X position by using the object circles

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCOBJPOSITIONS_001 \n
                        @ref TEST_AIP_V_CALCOBJPOSITIONS_002 \n
						@ref TEST_AIP_V_CALCOBJPOSITIONS_003

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_CalcObjPositions(ObjNumber_t        const        iObjectIndex, 
                                   ACDCObjPositions_t       *const pPositions  )
{
  SFLVector2D_t           const * const aLimitedShapePoints = ACDC_a_GetObjLimitedShapePoints(iObjectIndex);
  ACDCObjToTrajRelation_t const * const pTrajRelation       = ACDC_p_GetObjTrajRelation(iObjectIndex);
  ACDCGeometry_t          const * const pEgoGeometry        = ACDC_p_GetEgoGeometry();
  float32                               fX_Min              = ACDC_DIST_DEFAULT;
  uint32                                uSpNo;

  /* Measured and Var are already filled in AIP_v_FillObjectMovement */


  pPositions->ClosestInX.fX = ACDC_DIST_DEFAULT;
  pPositions->ClosestInX.fY = ACDC_DIST_DEFAULT;

  for (uSpNo = 0u; uSpNo < (uint32)EM_GEN_OBJ_N_SHAPE_POINTS; ++uSpNo)
  {
    if(aLimitedShapePoints[uSpNo].fX < fX_Min)
    {
      fX_Min = aLimitedShapePoints[uSpNo].fX;
      pPositions->ClosestInX = aLimitedShapePoints[uSpNo];
    }
  }


  if(    (pTrajRelation->fDistToTrajMin <  ( 0.5f * pEgoGeometry->fWidth) )
      && (pTrajRelation->fDistToTrajMax  > (-0.5f * pEgoGeometry->fWidth) ) )
  {
    AIP_v_CalcPosClosestInCorridor(iObjectIndex, &(pPositions->ClosestInCorr));
  }
  else
  {
    pPositions->ClosestInCorr.fX = ACDC_DIST_DEFAULT;
    pPositions->ClosestInCorr.fY = ACDC_DIST_DEFAULT;
  }


}


#if (ACDC_CFG_USE_ADD_OFFSET_SIMU)
/*************************************************************************************************************************
  Functionname:         AIP_v_ShiftObjectByOffset                                                                   */ /*!

  @brief                Shifts the entire object by adding a longitudinal and a lateral offset to all position values.

  @description          Shifts the objects limited shape points, its center and its GenObject position. This function has
                        to be called after the calculation of the limited shape points and before the calculation of the \n
                        traj relation and all other object positions.

  @return               void

  @param[in,out]        pACDCObj :    Object which shall be shifted
  @param[in]            fOffsetLong : Longitudinal offset by which the object shall be shifted. @phys_unit[m]
  @param[in]            fOffsetLat :  Lateral offset by which the object shall be shifted. @phys_unit [m]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_FRAME\n
                        @ref ACDC_CFG_AIP \n
                        @ref ACDC_CFG_USE_ADD_OFFSET_SIMU

  @pre                  Limited shape points, gen object position and center position have been calculated.
  @post                 Traj relation, object positions closest in x and closest in corridor can be calculated.

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void AIP_v_ShiftObjectByOffset(ACDCObject_t       * const pACDCObj, 
                                      float32      const         fOffsetLong, 
                                      float32      const         fOffsetLat)
{
  uint32 uSPNo;

  /* Shift the previously calculated limited shape points */
  for (uSPNo = 0; uSPNo < EM_GEN_OBJ_N_SHAPE_POINTS; ++uSPNo)
  {
    pACDCObj->ObjDescAdd.asLimitedShapePoints[uSPNo].fX += fOffsetLong;
    pACDCObj->ObjDescAdd.asLimitedShapePoints[uSPNo].fY += fOffsetLat;
  }


  /* Shift Center and GenObject position, ClosestInX and ClosestInCorr are later 
     on calculated on base of the limited Shape points*/
  pACDCObj->ObjDescMain.Positions.Center.fX += fOffsetLong;
  pACDCObj->ObjDescMain.Positions.Center.fY += fOffsetLat;

  pACDCObj->ObjDescMain.Positions.GenObject.fX += fOffsetLong;
  pACDCObj->ObjDescMain.Positions.GenObject.fY += fOffsetLat;

  /* Trajectory relation is calculated afterwards on base of these positions and the limited shape points */

}
#endif

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcClosestPosToTraj                                                                  */ /*!

  @brief                Calculates the closest point to a trajectory on a line between two positions.

  @description          Calculates the closest point to a trajectory on a line between two positions.
                        If the Intersection point between the line and the trajectory is not between the given 
                        positions, the positions which is closer to the intersection point is returned.
                        @startuml AIP_v_CalcClosestPosToTraj_activity.png
                        start
                          #Orange:Set up a line going through the two edge points:
                          <b>SFL_b_SetupLine</b> >
                          if(Positions are identical?) then (Yes)
                            :1}
                            :Return Default Position;
                          else(No)
                            :2}
                            #Orange:Calculate the intersection point of 
                            the trajectory and the line:
                            <b>SFL_v_SolveQuadrEquation</b>
                            <b>SFL_f_SelectMinValue</b>
                            <b>SFL_f_EvalPolyDeg2</b> >
                            note left:> see **Formula Intersection**
                            :Limit the found position to the line;
                          endif

                        stop
                        @enduml

  @return               void

  @param[in]            pTrajectory : Trajectory to which the closest position shall be found.
  @param[in]            pPos1 :       First edge point.
  @param[in]            pPos2 :       Second edge point.
  @param[in,out]        pPosClosest : Position on the line between the two edge points which is the closest to the given trajectory.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Intersection:** \n
                        \f$ 0 = (C_{2,Traj} * C_{B,Line}) \cdot x^2 + ((C_{1,Traj} * C_{B,Line}) + C_{A,Line}) \cdot x + ((C_{0,Traj} * C_{B,Line}) - C_{C,Line}) \f$

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCCLOSESTPOSTOTRAJ_001 \n
                        @ref TEST_AIP_V_CALCCLOSESTPOSTOTRAJ_002 \n
                        @ref TEST_AIP_V_CALCCLOSESTPOSTOTRAJ_003 \n
                        @ref TEST_AIP_V_CALCCLOSESTPOSTOTRAJ_004

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_CalcClosestPosToTraj(SFLPolyDeg2_t const * const pTrajectory,
                                       SFLVector2D_t const * const pPos1, 
                                       SFLVector2D_t const * const pPos2,
                                       SFLVector2D_t       * const pPosClosest)
{

  SFLLine_t Line;
  /* Set up a line through the two edge points */
  boolean const bLineValid = SFL_b_SetupLine(pPos1, pPos2, &Line);

  if(bLineValid == b_TRUE)
  {
    SFLPolynomialSolutions_t Solutions;
    float32 const fX_Min   = CML_f_Min(pPos1->fX,pPos2->fX);
    float32 const fX_Max   = CML_f_Max(pPos1->fX,pPos2->fX);
    float32 const fY_Min   = CML_f_Min(pPos1->fY,pPos2->fY);
    float32 const fY_Max   = CML_f_Max(pPos1->fY,pPos2->fY);

    /* Intersect the trajectory with a line through the two edge points */
    float32 const fC2      = (pTrajectory->fC2 * Line.fB);
    float32 const fC1      = (pTrajectory->fC1 * Line.fB) + Line.fA;
    float32 const fC0      = (pTrajectory->fC0 * Line.fB) - Line.fC;

    SFL_v_SolveQuadrEquation(fC2, fC1, fC0, &Solutions);

    /* Select the closest of the intersection positions */
    pPosClosest->fX = SFL_f_SelectMinValue(Solutions.afSolutions,Solutions.uNofSolutions,ACDC_DIST_DEFAULT,b_TRUE);
    pPosClosest->fY = SFL_f_EvalPolyDeg2(pTrajectory,pPosClosest->fX);
    
    /* Assure that the position is on one of the edge points or between them */
    pPosClosest->fX = CML_f_MinMax(fX_Min,fX_Max,pPosClosest->fX);
    pPosClosest->fY = CML_f_MinMax(fY_Min,fY_Max,pPosClosest->fY);
  }
  else
  {
    pPosClosest->fX = ACDC_DIST_DEFAULT;
    pPosClosest->fY = ACDC_DIST_DEFAULT;
  }

}


/*************************************************************************************************************************
  Functionname:         AIP_f_CalcDistInCorridor                                                                    */ /*!

  @brief                Calculates the distance of a point inside of the ego corridor.

  @description          Checks if a position is inside of the given corridor. If yes, calculates the distance 
                        to the position along the corridors trajectory.
                        @image html DistInCorridor.svg
                        @startuml AIP_f_CalcDistInCorridor_activity.png
                        start
                          if(Position is inside of the corridor) then (Yes)
                            :1}
                            #Orange:Calculate the Arc length of 
                            the polynomial up to the point:
                            <b>SFL_v_CalcLinearApproximation</b> >
                            #Orange:Calculate an approximated DistToTraj and 
                            compensate the error caused by the 
                            lateral shifting of the trajectory:
                            <b>SFL_f_CalcDistPointToLine</b> >
                          else (No)
                            :2}
                            :Return Maximum value;
                          endif
                        stop
                        @enduml

  @return               float32 : Distance of the position. @phys_unit [m]

  @param[in]            pEgoTraj :    Trajectory in which the position shall be calculated.
  @param[in]            fWidthRight : Right width of the trajectory. @phys_unit [m], @range[0,+...[
  @param[in]            fWidthLeft :  Left width of the trajectory. @phys_unit[m]  , @range [0,+...[
  @param[in]            pPos :        Position to which the distance shall be calculated.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_F_CALCDISTINCORRIDOR_001 \n
                        @ref TEST_AIP_F_CALCDISTINCORRIDOR_002 \n
						@ref TEST_AIP_F_CALCDISTINCORRIDOR_003

  @traceability         Design Decision
*************************************************************************************************************************/
static float32 AIP_f_CalcDistInCorridor(SFLPolyDeg2_t const * const pEgoTraj,
                                        float32                     fWidthRight, 
                                        float32                     fWidthLeft,
                                        SFLVector2D_t const * const pPos)
{

  float32       fDistInCorr = ACDC_DIST_DEFAULT;
  float32 const fYLimLeft   = SFL_f_EvalPolyDeg2(pEgoTraj, pPos->fX) + fWidthLeft;
  float32 const fYLimRight  = SFL_f_EvalPolyDeg2(pEgoTraj, pPos->fX) - fWidthRight;

  /* Check if the position is inside of the corridor */
  if(    (pPos->fY <  (fYLimLeft  + C_F32_DELTA) )
      && (pPos->fY  > (fYLimRight - C_F32_DELTA) ) )
  {
    float32       fDistToTraj;
    SFLPolyDeg1_t LinearApproximation;

    SFL_v_CalcLinearApproximation(pPos->fX, pEgoTraj, &LinearApproximation);
    fDistToTraj = SFL_f_CalcDistPointToLine(&LinearApproximation, pPos );

    fDistInCorr = SFL_f_CalcArcLengthPolynomial(pEgoTraj, pPos->fX) + (fDistToTraj * LinearApproximation.fC1);

  }

  return fDistInCorr;
}


/*************************************************************************************************************************
  Functionname:         AIP_v_CalcPosClosestInCorridor                                                             */ /*!

  @brief                Calculates the closest position of an object which is inside of the corridor

  @description          Calculates the closest position of an object inside of the ego corridor.
                        Returns a default value if the object is entirely outside of the corridor.
                        @image html PosClosestInCorridor.svg
                        @startuml AIP_v_CalcPosClosestInCorridor_activity.png
                        start
                          partition "Execute for all shape points" {
                            #Orange:Calculate closest position on the edge between 
                            the current and the next shape point to the left edge 
                            of the ego trajectory:
                            <b>AIP_v_CalcClosestPosToTraj</b> >
                            #Orange:Calculate the Distance on trajectory of this point:
                            <b>AIP_f_CalcDistInCorridor</b> >

                            #Orange:Calculate closest position on the edge between 
                            the current and the next shape point to the Right edge 
                            of the ego trajectory:
                            <b>AIP_v_CalcClosestPosToTraj</b> >
                            #Orange:Calculate the Distance on trajectory of this point:
                            <b>AIP_f_CalcDistInCorridor</b> >
                          }
                          :Select the position with the minimum distance on trajectory;
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex      : Index of the considered object. @range [0,+...[
  @param[in,out]        pPosClosestInCorr : Closest position inside of the ego corridor.

  @glob_in              @ref ACDC_a_GetObjLimitedShapePoints \n
                        @ref ACDC_p_GetEgoGeometry           \n
                        @ref ACDC_p_GetVDYDynObjSync
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  Limited Shape Points are filled, Ego geometry is filled.
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCPOSCLOSESTINCORRIDOR_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_CalcPosClosestInCorridor(ObjNumber_t   const        iObjectIndex,
                                           SFLVector2D_t       *const pPosClosestInCorr)
{
  SFLVector2D_t const * const aLimitedShapePoints = ACDC_a_GetObjLimitedShapePoints(iObjectIndex);
  SFLPolyDeg2_t               EgoTraj             = {0};
  SFLPolyDeg2_t               CorrRightEdge       = {0};
  SFLPolyDeg2_t               CorrLeftEdge        = {0};
  float32       const         fEgoTrajWidthHalf   = 0.5f * ACDC_p_GetEgoGeometry()->fWidth;
  uint32                      uSpNo               = 0u;
  float32                     fDistInCorrMin      = ACDC_DIST_DEFAULT;

  /* Initialize all relevant structures  */
  pPosClosestInCorr->fX = ACDC_DIST_DEFAULT;
  pPosClosestInCorr->fY = ACDC_DIST_DEFAULT;

  EgoTraj.fC2       =  0.5f *  ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve;

  CorrLeftEdge      =  EgoTraj;
  CorrLeftEdge.fC0  =  fEgoTrajWidthHalf;

  CorrRightEdge     =  EgoTraj;
  CorrRightEdge.fC0 = -fEgoTrajWidthHalf;

  /* Loop through all shape points and calculate the closest point in the corridor */
  for (uSpNo = 0u ; uSpNo < (uint32)EM_GEN_OBJ_N_SHAPE_POINTS; ++uSpNo)
  {
    uint32  const uNext              = (uSpNo + 1u)%((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);
    SFLVector2D_t PosClosestRight;
    SFLVector2D_t PosClosestLeft;
    float32       fDistInCorr;

    /* Right Corridor Edge */
    AIP_v_CalcClosestPosToTraj(&CorrRightEdge, &aLimitedShapePoints[uSpNo], &aLimitedShapePoints[uNext], &PosClosestRight);

    fDistInCorr = AIP_f_CalcDistInCorridor(&EgoTraj, fEgoTrajWidthHalf, fEgoTrajWidthHalf, &PosClosestRight);

    if(fDistInCorr < fDistInCorrMin)
    {
      fDistInCorrMin = fDistInCorr;
      *pPosClosestInCorr = PosClosestRight;
    }


    /* Left Corridor Edge*/
    AIP_v_CalcClosestPosToTraj(&CorrLeftEdge, &aLimitedShapePoints[uSpNo], &aLimitedShapePoints[uNext], &PosClosestLeft);

    fDistInCorr = AIP_f_CalcDistInCorridor(&EgoTraj, fEgoTrajWidthHalf, fEgoTrajWidthHalf, &PosClosestLeft);

    if(fDistInCorr < fDistInCorrMin)
    {
      fDistInCorrMin = fDistInCorr;
      *pPosClosestInCorr = PosClosestLeft;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         AIP_v_GetClassBasedDimensionLimits                                                          */ /*!

  @brief                Returns dimension limits for a given eba object class.

  @description          Returns Minimum Length, Maximum Length, Minimum Width and Maximum Width for a given object class.

  @return               void

  @param[in]            eEbaClass :  Objects Class, relevant for the limitations.
  @param[in,out]        fLengthMin : Minimum length of the object. @phys_unit [m]
  @param[in,out]        fLengthMax : Maximum length of the object. @phys_unit [m]
  @param[in,out]        fWidthMin :  Minimum width of the object.  @phys_unit [m]
  @param[in,out]        fWidthMax :  Maximum width of the object.  @phys_unit [m]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Size Limitations:**\n
                        |              |Cyclist|Pedestrian|Motorbike| Truck |  Car  | Unknown |
                        |:-------------|:------|:---------|:--------|:------|:------|:--------|
                        |Maximum Length|  2.0  |   1.0    |   2.5   | 25.0  |  6.0  |  1000.0 |
                        |Maximum Width |  1.0  |   1.0    |   1.2   |  2.55 |  2.0  |  1000.0 |
                        |Minimum Length|  1.2  |   0.5    |   1.2   |  4.0  |  2.5  |     0.0 |
                        |Minimum Width |  0.5  |   0.5    |   0.5   |  1.7  |  1.5  |     0.0 |

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_GETCLASSBASEDDIMENSIONLIMITS_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_GetClassBasedDimensionLimits(EM_t_GenEbaObjClass const         eEbaClass,
                                         float32                   * const fLengthMin,
                                         float32                   * const fLengthMax,
                                         float32                   * const fWidthMin,
                                         float32                   * const fWidthMax)
{
  switch (eEbaClass)
  {
  case FPS_EBA_CLASS_CYCLIST:
    *fLengthMax = 2.0F;
    *fWidthMax  = 1.0F;
    *fLengthMin = 1.2F;
    *fWidthMin  = 0.5F;
    break;
  case FPS_EBA_CLASS_PEDESTRIAN:
    *fLengthMax = 1.0F;
    *fWidthMax  = 1.0F;
    *fLengthMin = 0.5F;
    *fWidthMin  = 0.5F;
    break;
  case FPS_EBA_CLASS_MOTORBIKE:
    *fLengthMax = 2.5F;
    *fWidthMax  = 1.2F;
    *fLengthMin = 1.2F;
    *fWidthMin  = 0.5F;
    break;
  case FPS_EBA_CLASS_TRUCK:
    *fLengthMax = 25.0F;
    *fWidthMax  = 2.55F;
    *fLengthMin = 4.0F;
    *fWidthMin  = 1.7F;
    break;
  case FPS_EBA_CLASS_CAR:
    *fLengthMax = 6.0F;
    *fWidthMax  = 2.0F;
    *fLengthMin = 2.5F;
    *fWidthMin  = 1.5F;
    break;
  case FPS_EBA_CLASS_UNKNOWN:
  default:
    *fLengthMax = 1000.0F;
    *fWidthMax  = 1000.0F;
    *fLengthMin = 0.0F   ;
    *fWidthMin  = 0.0F   ;
    break;
  }
}

#if (ACDC_CFG_USE_EBA_BOX_OBJECTS)
/*************************************************************************************************************************
  Functionname:         AIP_b_GenerateEBABoxedObject                                                                  */ /*!

  @brief                Calculates a rectangular box from an EM-Object

  @description          Calculates a box on base of the shape points of an object. It is used to simplify 
                        calculation regarding e.g. distance and collision time by transforming the objects \n
                        shape points into a rectangular box aligned with the ego vehicle orientation.
                        @startuml AIP_b_GenerateEBABoxedObject_activity.png
                        start
                          :Calculate absolute position 
                          of all shape points;
                          note left: EM Reference point\n+ ShapePoint Coordinates
                          if (1 valid shape point?) then (Yes)
                            :1}
                            :Calculate position and geometry 
                            of the boxed object;
                            note left: >see formula\n"1 Shape Point"
                          elseif (2 valid shape points?) then (Yes)
                            :2}
                            :Calculate position and geometry 
                            of the boxed object;
                            note left: >see formula\n"2 Shape Points"
                          elseif (3 or 4 valid shape points?) then (Yes)
                            if (3 valid shape points?) then (Yes)
                              :3}
                              :Calculate 4th shape point 
                              based on existing 3;
                              note left: >see formula\n"3 Shape Points"
                            else (No)
                              :4}
                            endif
                            :Calculate position and geometry 
                            of the boxed object;
                            note left: >see illustration\n"4 Shape Points"
                          else (No)
                            :5}
                            :Error;
                          endif
                        stop
                        @enduml

  @return               boolean : Flag indicating whether calculation succeeded.

  @param[in,out]        pGeometry : Box object geometry, to be calculated by this function.
  @param[in,out]        pBoxPosition : Box object position, to be calculated by this function.
  @param[in]            pEMObject    : EM generic object.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_USE_KINEMATIC_STDDEV
  @c_switch_full        @ref ACDC_CFG_USE_EBA_BOX_OBJECTS \n
                        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **1 Shape Point:**\n
                          \f$ Pos_{boxed} = Pos_{EM}\f$ \n
                          \f$ Length_{boxed} = 0\f$ \n
                          \f$ Width_{boxed} = 0\f$ \n
                          \f$ Orientation_{boxed} = 0\f$ \n\n
                        - **2 Shape Points:**\n
                          \f$ Pos_{boxed} = \frac{\left(\begin{array}{c}X_1\\ Y_1\end{array}\right) +
                          \left(\begin{array}{c}X_2\\ Y_2\end{array}\right)}{2} \f$ \n
                          \f$ Length_{boxed} = X_2 - X_1\f$ \n
                          \f$ Width_{boxed} = Y_2 - Y_1\f$ \n
                          \f$ Orientation_{boxed} = 0\f$ \n\n
                        - **3 Shape Points:**\n
                          \f$ Pos_{SP4} = Pos_{SP3} + Pos_{SP2} - Pos_{SP1}\f$ \n\n
                        - **4 Shape Points:**\n
                        \image html CDGenerateEBABoxedObject.svg width=2000

  @todo                 - standard deviations have to be considered (not implemented completely)
                        - Is the following correct? Shouldn't here be used the shape point numbers previously stored in uiQuadrant? :\n
                        Helper = SFL_s_SubVector2(AbsShapePoint[uiPointNext], AbsShapePoint[uiPointCounter] );
                        sHelperPosVector1 = SFL_s_SetupPositionVector2(AbsShapePoint[uiPointCounter], Helper );

  @author               Christian Obst

  @testmethod           @ref TEST_AIP_V_GETCLASSBASEDDIMENSIONLIMITS_001 \n
                        @ref TEST_AIP_B_GENERATEEBABOXEDOBJECT_002

  @traceability         Design Decision
*************************************************************************************************************************/
static boolean AIP_b_GenerateEBABoxedObject(ACDCGeometry_t       * const pGeometry, 
                                            SFLVector2D_t        * const pBoxPosition, 
                                            EM_t_GenObject const * const pEMObject)
{
  SFLVector2D_t         sCoG = {0.f,0.f};                     /*point of center of gravity*/
  SFLVector2D_t         EMReferencePoint;         /*EM Object reference point*/
  uint8                 uiValidShapePoints = 0;   /*number of existing shape points*/
  SFLVector2D_t         AbsShapePoint[4u];        /*absolute shape point (EM reference + EM relative shape)*/
                        
  SFLVector2D_t         sEBAx[2u]  = {0};         /*intersection in x direction*/
  SFLVector2D_t         sEBAy[2u]  = {0};         /*intersection in y direction*/
  uint8                 uiXcounter = 0;           /*Element counter for sEBAx*/
  uint8                 uiYcounter = 0;           /*Element counter for sEBAy*/
  SFLPositionVector2D_t sHelperPosVector1;        /*helper vector*/
  SFLPositionVector2D_t sHelperPosVector2;        /*helper vector*/
  SFLVector2D_t         sHelperCDVector;          /*helper vector*/

  uint8   uiQuadrant[4u];                         /*stores information of location of the points*/
  uint8   uiPointCounter;                         /*generic running variable for points*/
  boolean bIntersectionFound = b_TRUE;              /*computation error state*/

  if ((pEMObject != NULL) )
  {
    /*pointers are valid*/
    EMReferencePoint = SFL_s_SetupVector2(pEMObject->Kinematic.fDistX, pEMObject->Kinematic.fDistY);
    /*check shape point status and calculate the Vectors to the points*/
    for (uiPointCounter=0; uiPointCounter < 4u; uiPointCounter++)
    {
#if (FCT_CFG_SENSOR_TYPE_CAMERA)
      if(pEMObject->Geometry.aShapePointStates[uiPointCounter] != EM_GEN_OBJECT_SHAPE_POINT_STATE_INVALID)
#endif
      {
        /*setup vector to shape points*/
        AbsShapePoint[uiValidShapePoints] = SFL_s_AddVector2(SFL_s_SetupVector2(pEMObject->Geometry.aShapePointCoordinates[uiPointCounter].fPosX,
                                                                                pEMObject->Geometry.aShapePointCoordinates[uiPointCounter].fPosY),
                                                             EMReferencePoint);

        uiValidShapePoints++;
      }
    }
      /******* calculate CoG *******/

    switch (uiValidShapePoints)
    {
    case 1u:
      /*single point easy to go, one point, one distance, no dimension*/
      *pBoxPosition                  = AbsShapePoint[0u]; /*PRQA S 3353*/ /*AbsShapePoint is definitely set at this point */

      pGeometry->fLength             = 0.f;
      pGeometry->fOrientation        = 0.f;
      pGeometry->fWidth              = 0.f;

      break;
    case 2u:
      /*one line make outer box*/
      pGeometry->fLength             = fABS(AbsShapePoint[1u].fX - AbsShapePoint[0].fX);
      pGeometry->fWidth              = fABS(AbsShapePoint[1u].fY - AbsShapePoint[0].fY);
      pGeometry->fOrientation        = 0.f;

      pBoxPosition->fX               = MIN_FLOAT(AbsShapePoint[1u].fX, AbsShapePoint[0].fX); /* closest point to our subject */
      pBoxPosition->fY               = (MAX_FLOAT(AbsShapePoint[1u].fY, AbsShapePoint[0].fY) + MIN_FLOAT(AbsShapePoint[1u].fY, AbsShapePoint[0].fY) ) / 2.0f; /*middle of line*/

      break;
    case 3u:
      /*create 4th shape point*/
      AbsShapePoint[3u] = SFL_s_AddVector2( AbsShapePoint[2u], SFL_s_SubVector2( AbsShapePoint[0], AbsShapePoint[1] ) );

      /* -- no break needed here! Case 3 only generates the 4th point --*/
    /*PRQA S 2003 1*/ /*20150319 Christian Obst: intended to fall through*/
    case 4u:
      /******* start box calculation *******/
      /*two diagonal vectors*/
      sHelperCDVector     = SFL_s_SubVector2(AbsShapePoint[2u], AbsShapePoint[0]); /*PRQA S 3354*/ /*AbsShapePoint is definitely set at this point*/
      sHelperPosVector1   = SFL_s_SetupPositionVector2( AbsShapePoint[0], sHelperCDVector); /*represents 1st EM box crossing vector*/
      sHelperCDVector     = SFL_s_SubVector2(AbsShapePoint[3u], AbsShapePoint[1u]);
      sHelperPosVector2   = SFL_s_SetupPositionVector2(AbsShapePoint[1u], sHelperCDVector); /*represents 2nd EM box crossing vector*/
      /*intersection*/
      bIntersectionFound  = SFL_b_IntersectPositionVectors(&sHelperPosVector1, &sHelperPosVector2, &sCoG);
      /*intersection can lead to error if vectors are parallel*/
      /*calculate intersections of shape with x and y vectors from CoG*/
      if ( bIntersectionFound == b_TRUE )
      {
        /*CoG valid*/
        /*setup quadrant information for later calculation*/
        for (uiPointCounter=0u; uiPointCounter<4u; uiPointCounter++)
        {
          SFLVector2D_t Helper;
          Helper = SFL_s_SubVector2(AbsShapePoint[uiPointCounter] , sCoG);
          if (((Helper.fX) >= 0.f) && ((Helper.fY) >= 0.f))
          {
            uiQuadrant[uiPointCounter] = 1u;
          }
          else if (((Helper.fX) >= 0.f) && ((Helper.fY) < 0.f))
          {
            uiQuadrant[uiPointCounter] = 2u;
          }
          else if ((((Helper.fX) < 0.f) && ((Helper.fY) < 0.f)))
          {
            uiQuadrant[uiPointCounter] = 3u;
          }
          else
          {
            uiQuadrant[uiPointCounter] = 4u;
          }
        }
        /*setup vectors point[i]->point[i+1] and intersect*/
        for (uiPointCounter=0u; uiPointCounter<4u; uiPointCounter++)
        {
          SFLVector2D_t Helper;
          uint8 uiPointNext = 0u;
          if (uiPointCounter == 3u)
          {
            uiPointNext = 0u;
          }
          else
          {
            uiPointNext = uiPointCounter + 1u;
          }
          /*setup vector point[i]->point[i+1]*/
          Helper = SFL_s_SubVector2(AbsShapePoint[uiPointNext], AbsShapePoint[uiPointCounter] );
          sHelperPosVector1 = SFL_s_SetupPositionVector2(AbsShapePoint[uiPointCounter], Helper ); /*represents ONE edge of the EBA box*/
          /*check quadrant transient and setup CoG-Vector*/
          if ( ( (((uiQuadrant[uiPointCounter]) == 1u) || ((uiQuadrant[uiPointCounter]) == 4u)) && (((uiQuadrant[uiPointNext]) == 2u) || ((uiQuadrant[uiPointNext]) == 3u)) )
            || ( (((uiQuadrant[uiPointCounter]) == 2u) || ((uiQuadrant[uiPointCounter]) == 3u)) && (((uiQuadrant[uiPointNext])== 1u) || ((uiQuadrant[uiPointNext]) ==4u)) ) ) 
          {
            /*cuts x axis*/
            SFLVector2D_t         Helper1;
            SFLPositionVector2D_t Helper2;
            Helper1 = SFL_s_SetupVector2(1.f,0.f);
            Helper2 = SFL_s_SetupPositionVector2(sCoG, Helper1);
            if (uiYcounter < 2u)
            {
              bIntersectionFound = (bIntersectionFound) && (SFL_b_IntersectPositionVectors(&sHelperPosVector1, &Helper2, &(sEBAy[uiYcounter])));
            }
            else
            {
              bIntersectionFound = b_FALSE; /* Objects are not rectangular shaped */
            }
            uiYcounter++;
          }
          if ( ( (((uiQuadrant[uiPointCounter]) == 1u) || ((uiQuadrant[uiPointCounter]) == 2u)) && (((uiQuadrant[uiPointNext]) == 3u) || ((uiQuadrant[uiPointNext]) == 4u)) )
            || ( (((uiQuadrant[uiPointCounter]) == 3u) || ((uiQuadrant[uiPointCounter]) == 4u)) && (((uiQuadrant[uiPointNext]) == 1u) || ((uiQuadrant[uiPointNext]) == 2u)) ) )
          {
            /*cuts y axis*/
            SFLVector2D_t         Helper1;
            SFLPositionVector2D_t Helper2;
            Helper1 = SFL_s_SetupVector2(0.f,1.f);
            Helper2 = SFL_s_SetupPositionVector2(sCoG, Helper1);
            if (uiXcounter < 2u)
            {
              bIntersectionFound = (bIntersectionFound) && (SFL_b_IntersectPositionVectors(&sHelperPosVector1, &Helper2, &(sEBAx[uiXcounter])));
            }
            else
            {
              bIntersectionFound = b_FALSE; /* Objects are not rectangular shaped */
            }
            uiXcounter++;
          }
        } /*for*/
      }
      if ((bIntersectionFound == b_TRUE) && (uiXcounter == 2u) && (uiYcounter == 2u))
      {
        pGeometry->fLength         = fABS(sEBAy[0].fX - sEBAy[1].fX);
        pGeometry->fWidth          = fABS(sEBAx[0].fY - sEBAx[1].fY);
        pGeometry->fOrientation    = 0.f;

        if (sEBAy[0].fX < sEBAy[1].fX)
        {
          *pBoxPosition            = sEBAy[0];
        }
        else
        {
          *pBoxPosition            = sEBAy[1];
        }
      }
      else
      {
        bIntersectionFound = b_FALSE;
      }
      break;/*uiValidShapePoints >= 3*/
    default:
      /*no shape point valid or more than 4*/
      bIntersectionFound = b_FALSE;
      break;
    }
  }
  else
  {
    /*pointers are invalid*/
    bIntersectionFound = b_FALSE;
  }
  return (boolean)(bIntersectionFound == b_FALSE);
}/* PRQA S 7002,7004 # Date:2020-06-03, Reviewer: Praveen Annareddy , Reason: suppressing cyclomatic complexity for better code maintainability*/

#if (ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE)
/*************************************************************************************************************************
  Functionname:         AIP_v_LimitBoxedObjectDimensions                                                               */ /*!

  @brief                Limits the dimensions of an object according to its EBA ObjectClass

  @description          Limits the width and the length of an object according to the previously determined class.
                        The limits are adapted according to the objects orientation.
                        @startuml AIP_v_LimitBoxedObjectDimensions_activity.png
                        start
                          #Orange:Determine geometry limits 
                          based on object class:
                          <b> AIP_v_GetClassBasedDimensionLimits</b> >
                          :Adapt limits according 
                          to objects orientation;
                          note left: >see "Orientation Adaption"
                          :Limit object geometry to
                          the calculated values;
                        stop
                        @enduml

  @return               void

  @param[in,out]        pEBAGeometry : Geometry calculated by the function @ref AIP_b_GenerateEBABoxedObject
  @param[in]            pEMObject :    EM objects related to the given geometry.
  @param[in]            pARSObject :   ARS object related to the given geometry

  @glob_in              None
  @glob_out             None

  @c_switch_part        None  
  @c_switch_full        @ref ACDC_CFG_USE_EBA_BOX_OBJECTS  \n
                        @ref ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE \n
                        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Orientation Adaption:**\n
                        \f$Length_{Max} = \sqrt{(\cos(\alpha_{Orient})\cdot Length_{Max})^2 + (\sin(\alpha_{Orient})\cdot Width_{Max})^2} \f$\n
                        \f$Width_{Max}  = \sqrt{(\cos(\alpha_{Orient})\cdot Width_{Max})^2  + (\sin(\alpha_{Orient})\cdot Length_{Max})^2}\f$\n
                        \f$Length_{Min} = \sqrt{(\cos(\alpha_{Orient})\cdot Length_{Min})^2 + (\sin(\alpha_{Orient})\cdot Width_{Min})^2} \f$\n
                        \f$Width_{Min}  = \sqrt{(\cos(\alpha_{Orient})\cdot Width_{Min})^2  + (\sin(\alpha_{Orient})\cdot Length_{Min})^2}\f$\n

  @author               Andreas Kramer

  @testmethod           @ref TEST_AIP_V_GETCLASSBASEDDIMENSIONLIMITS_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_LimitBoxedObjectDimensions(ACDCGeometry_t * pEBAGeometry, const EM_t_GenObject * const pEMObject, const EM_t_ARSObject * const pARSObject)
{
  EM_t_GenEbaObjClass const eEbaClass  = pEMObject->Qualifiers.eEbaObjClass;
  float32             const fSinOrient = SIN_(pARSObject->Geometry.fOrientation);
  float32             const fCosOrient = COS_(pARSObject->Geometry.fOrientation);
  float32                   fLengthMin;
  float32                   fLengthMax;
  float32                   fWidthMin;
  float32                   fWidthMax;
  float32                   fLengthMinOrient;
  float32                   fLengthMaxOrient;
  float32                   fWidthMinOrient;
  float32                   fWidthMaxOrient;

  /* Set the dimension limits according to the object class*/
  AIP_v_GetClassBasedDimensionLimits(eEbaClass, &fLengthMin, &fLengthMax, &fWidthMin, &fWidthMax);

  /* Calculate width and length values limits according to orientation */
  fLengthMinOrient = SQRT(SQR(fCosOrient * fLengthMin) + SQR(fSinOrient * fWidthMin));
  fLengthMaxOrient = SQRT(SQR(fCosOrient * fLengthMax) + SQR(fSinOrient * fWidthMax));

  fWidthMinOrient  = SQRT(SQR(fCosOrient * fWidthMin) + SQR(fSinOrient * fLengthMin));
  fWidthMaxOrient  = SQRT(SQR(fCosOrient * fWidthMax) + SQR(fSinOrient * fLengthMax));

  /* Limit the dimension values according to the calculated limits */
  pEBAGeometry->fLength = CML_f_MinMax(fLengthMinOrient, fLengthMaxOrient, pEBAGeometry->fLength);
  pEBAGeometry->fWidth  = CML_f_MinMax(fWidthMinOrient,  fWidthMaxOrient,  pEBAGeometry->fWidth );

}
#endif /* ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE */
#endif /* ACDC_CFG_USE_EBA_BOX_OBJECTS */


/*!@}*/
#endif /* ACDC_CFG_AIP */
