/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_ego.c

DESCRIPTION:               Functions for the handling of shape points for the ACDC component

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             05.07.2018

VERSION:                   $Revision: 1.11 $

**************************************************************************** */

#include "aip_int.h"

#if(ACDC_CFG_AIP)
/************************************************************************/
/*                         MODULE DESCRIPTION                           */
/************************************************************************/
/*!
@defgroup aip_shapepoints Shapepoints
@ingroup aip
@brief            Contains functions for calculations related to the shape points \n\n
@description      Provides the following functionalities:
                  - Calculate the object center on base of the shape points: @ref AIP_v_CalcObjectCenterFromShapePoints
                  - Calculate the objects width, length & orientation on base of the shape points: @ref AIP_v_CalcGeometryFromShapePoints
                  - Calculate the qualities of each shape point: @ref AIP_v_CalcShapePointQualities
                  - Limit the shape points of an object on base of its class: @ref AIP_v_CalculateLimitedShapePoints
                  - Get the index of a shape point at a given position: @ref AIP_i_GetShapePointIdx

@{
*/

/************************************************************************/
/*                      MACRO DEFINITIONS                               */
/************************************************************************/

/*! @brief  Angle above which the Shape Point quality reaches its minimum value (= 0)
            @typical 135.f, @phys_unit [deg]*/
#define AIP_SHAPEPOINT_MIN_QUALITY_ANGLE 135.f

/*! @brief  Angle below which the Shape Point quality reaches its maximum value (= 1)
            @typical 90.f, @phys_unit [deg]*/
#define AIP_SHAPEPOINT_MAX_QUALITY_ANGLE 90.f

/************************************************************************/
/*                     FUNCTION DECLARATIONS                            */
/************************************************************************/
static void AIP_v_CalculateShapePointPositions(ObjNumber_t const iObjectIndex, sint8 iShapePointPositions[]);

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcObjectCenterFromShapePoints                                                          */ /*!

  @brief                Calculates the center point of a given object from its Shape Points.

  @description          Calculates the center of an object on base of its Shape Points. Therefore 
                        the average of all shape points in x and y direction is calculated.
                        @startuml AIP_v_CalcObjectCenterFromShapePoints_activity.png
                        start
                          :Sum up the X and Y Values 
                          of all Shape Points;
                          :Calculate the Average in 
                          X and Y direction;
                          note left: >see Formula "Object Center"
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :  Index of the considered object. @range [0,EM_N_OBJECTS]
  @param[in,out]        pObjectCenter : Center position of the object.

  @glob_in              @ref ACDC_p_GetEMGenObj
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  None
  @post                 None

  @InOutCorrelation     **Formulas Object Center:** \n
                          \f$X_{Center} = X_{Object} + \frac{\sum{X_{ShapePoints}} }{N_{ShapePoints}}\f$ \n
                          \f$Y_{Center} = Y_{Object} + \frac{\sum{Y_{ShapePoints}} }{N_{ShapePoints}}\f$

  @remark               This function does only work properly in case 4 valid shape points are provided.
                        Adapt this function in case this is not guaranteed anymore.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCOBJECTCENTERFROMSHAPEPOINTS_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_CalcObjectCenterFromShapePoints(ObjNumber_t const         iObjectIndex, 
                                           SFLVector2D_t     * const pObjectCenter)
{
  EM_t_GenObject const * const pCurrObj      = ACDC_p_GetEMGenObj(iObjectIndex);
  float32                      fSumX         = 0.f;
  float32                      fSumY         = 0.f;
  uint32                       uShapePointNo = 0u;

  for (uShapePointNo = 0u; uShapePointNo < ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS); uShapePointNo++)
  {
    fSumX += pCurrObj->Geometry.aShapePointCoordinates[uShapePointNo].fPosX;
    fSumY += pCurrObj->Geometry.aShapePointCoordinates[uShapePointNo].fPosY;
  }
  pObjectCenter->fX = pCurrObj->Kinematic.fDistX + (fSumX / ((float32)EM_GEN_OBJ_N_SHAPE_POINTS));
  pObjectCenter->fY = pCurrObj->Kinematic.fDistY + (fSumY / ((float32)EM_GEN_OBJ_N_SHAPE_POINTS));

}

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcGeometryFromShapePoints                                                           */ /*!

  @brief                Calculates the Objects geometry (Width / Length / orientation) from the ShapePoints in the 
                        GenObject List.

  @description          The function calculates the objects width and length by calculating the distance of the two 
                        shape points at the front (=Width) respectively at the left side (= Length).
                        @startuml AIP_v_CalcGeometryFromShapePoints_activity.png
                        start
                          :Calculate the **Length** (=distance of the **Front Left**
                          and the **Rear Left** Shape Point);
                          note left: >see **Formula Length**
                          :Calculate the **Width** (=distance of the **Front Left**
                          and the **Front Right** Shape Point);
                          note left: >see **Formula Width**
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object. @range[0,EM_N_OBJECTS]
  @param[out]           pGeometry:            Geometry structure that is filled with the information 
                                              extracted from the shape points.

  @glob_in              @ref ACDC_p_GetEMGenObjGeometry \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  The Shape Points describe a rectangular object

  @post                 None

  @InOutCorrelation     
                        - **Formula Length:**\n
                          \f$Length = \sqrt{(\Delta X_{Left})^2 + (\Delta Y_{Left})^2}\f$
                        - **Formula Width:**\n
                          \f$Width  = \sqrt{(\Delta X_{Front})^2 + (\Delta Y_{Front})^2}\f$

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCGEOMETRYFROMSHAPEPOINTS_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_CalcGeometryFromShapePoints(ObjNumber_t    const         iObjectIndex,
                                       ACDCGeometry_t       * const pGeometry)
{

  EM_t_GenObjShapePointCoord const *const aShapePoints = (ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates);
  sint32  const iSPFrontLeft  = AIP_i_GetShapePointIdx(iObjectIndex,SP_FRONT_LEFT);
  sint32  const iSPRearLeft   = AIP_i_GetShapePointIdx(iObjectIndex,SP_REAR_LEFT);
  sint32  const iSPFrontRight = AIP_i_GetShapePointIdx(iObjectIndex,SP_FRONT_RIGHT);
  float32 const fLengthDistX  = aShapePoints[iSPFrontLeft].fPosX - aShapePoints[iSPRearLeft].fPosX;
  float32 const fLengthDistY  = aShapePoints[iSPFrontLeft].fPosY - aShapePoints[iSPRearLeft].fPosY;
  float32 const fWidthDistX   = aShapePoints[iSPFrontLeft].fPosX - aShapePoints[iSPFrontRight].fPosX;
  float32 const fWidthDistY   = aShapePoints[iSPFrontLeft].fPosY - aShapePoints[iSPFrontRight].fPosY;

  pGeometry->fLength      = SQRT(SQR(fLengthDistX) + SQR(fLengthDistY));
  pGeometry->fWidth       = SQRT(SQR(fWidthDistX ) + SQR(fWidthDistY ));
  pGeometry->fOrientation = SFL_f_CalcAngleFromVector(fLengthDistX, fLengthDistY,b_TRUE);

}

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcShapePointQualities                                                                */ /*!

  @brief                Calculates a quality for each shape point.

  @description          This function uses the geometrical visibility of an object to determine the measurement 
                        quality of each shape point. This means: A shape point which is clearly visible for the \n
                        sensor gets a high quality. A shape point that is partly or entirely covered by the object 
                        itself gets a low quality. For the calculation it is not considered if other objects than \n
                        the current one cover a shape point.
                        @image html ShapePointQualities.svg "Shapepoint Qualities"
                        @startuml AIP_v_CalcShapePointQualities_activity.png
                        start
                          :Store the indices of the shape points in 
                          a sorted order to ease looping;
                          partition "Execute for each shape point" {
                          #Orange:Calculate a vector from (0|0) to 
                          the position of the shape point: 
                          <b>SFL_s_SetupVector2</b> >
                          note left: The result is the **ShapePointVector**
                          #Orange:Calculate normalized vectors to the
                          previous and to the next shape point:
                          <b>SFL_s_CalculateNormalizedVector</b> >
                          #Orange:Add the vectors to the previous and the 
                          next shape point and normalize the result:
                          <b>SFL_s_CalculateNormalizedVector</b> >
                          note left
                          The result, the **EdgeVector**, is a 
                          vector that bisects the angle at the 
                          considered shape point.
                          end note
                          :Calculate the Angle delta between the 
                          **EdgeVector** and the **ShapePointVector**.
                          The quality is based on this delta. The bigger it 
                          is, the lower is the **Shape Point Quality**;
                          note left: see **Formula Angle Delta**
                          }
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        afQualities :  Qualities assigned to each shape point. @range [0,1]

  @glob_in              @ref ACDC_p_GetEMGenObjGeometry   \n
                        @ref ACDC_p_GetEMGenObjKinematics \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Angle Delta:** \n
                          \f$ \alpha = \arccos(\frac{\vec{a}\cdot \vec{b}}{|\vec{a}| \cdot |\vec{b}|})\f$

  @remark               The Shape point qualities are calculated on base of the original shape points. Therefore they do 
                        not apply 100% to the limited shape points. To be 100% correct the qualities would have to be 
                        recalculated after the limitation was done. Nevertheless according to the current results this 
                        would not lead to any significant functional improvement.

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCSHAPEPOINTQUALITIES_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_CalcShapePointQualities(ObjNumber_t const iObjectIndex, float32 afQualities[])
{
  EM_t_GenObjShapePointCoord const *const aShapePoints = (ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates);
  float32                    const        fDistY       =  ACDC_p_GetEMGenObjKinematics(iObjectIndex)->fDistY;
  float32                    const        fDistX       =  ACDC_p_GetEMGenObjKinematics(iObjectIndex)->fDistX;
  sint8                                   iSortedShapePoints[EM_GEN_OBJ_N_SHAPE_POINTS];
  uint32                                  uSPNo;

  /* Store the shape point indices in a sorted array */
  iSortedShapePoints[0] = AIP_i_GetShapePointIdx(iObjectIndex,SP_FRONT_LEFT );
  iSortedShapePoints[1] = AIP_i_GetShapePointIdx(iObjectIndex,SP_FRONT_RIGHT);
  iSortedShapePoints[2] = AIP_i_GetShapePointIdx(iObjectIndex,SP_REAR_RIGHT );
  iSortedShapePoints[3] = AIP_i_GetShapePointIdx(iObjectIndex,SP_REAR_LEFT  );

  /* Calculate a Quality for each Shape Point */
  for(uSPNo = 0; uSPNo <  ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS); uSPNo++)
  {
    SFLVector2D_t ShapePointVector;
    SFLVector2D_t PrevVector;
    SFLVector2D_t NextVector;
    SFLVector2D_t EdgeVector;
    EM_t_GenObjShapePointCoord currShapePoint;
    EM_t_GenObjShapePointCoord prevShapePoint;
    EM_t_GenObjShapePointCoord nextShapePoint;

    float32       fEdgeAngleDelta = 180.f;  /* Init to 180 to assure a quality of 0 in case of Div by 0 */
    float32       fVectorLengthProduct;

    /* Get the previous and the next shape point index */
    uint32 const  uPrev = (uSPNo + (((uint32)EM_GEN_OBJ_N_SHAPE_POINTS) - 1u))% ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);
    uint32 const  uNext = (uSPNo + (1u                                      ))% ((uint32)EM_GEN_OBJ_N_SHAPE_POINTS);

    /* Get all relevant shape points for the next steps */
    currShapePoint = aShapePoints[iSortedShapePoints[uSPNo]];
    prevShapePoint = aShapePoints[iSortedShapePoints[uPrev]];
    nextShapePoint = aShapePoints[iSortedShapePoints[uNext]];

    /* Calculate a vector from (0|0) to the position of the Shape Point. */
    ShapePointVector   = SFL_s_SetupVector2(fDistX + currShapePoint.fPosX, fDistY + currShapePoint.fPosY);
    /* Calculate a normalized vector from the current Shape point to the previous one. */
    PrevVector         = SFL_s_CalculateNormalizedVector(SFL_s_SetupVector2(prevShapePoint.fPosX - currShapePoint.fPosX, prevShapePoint.fPosY - currShapePoint.fPosY));
    /* Calculate a normalized vector from the current Shape point to the next one. */
    NextVector         = SFL_s_CalculateNormalizedVector(SFL_s_SetupVector2(nextShapePoint.fPosX - currShapePoint.fPosX, nextShapePoint.fPosY - currShapePoint.fPosY));
    /* Add the two vectors and normalize the result. The resulting Vector bisects the angle at the current shape point. */
    EdgeVector         = SFL_s_CalculateNormalizedVector(SFL_s_AddVector2(PrevVector, NextVector));

    /* Calculate the angle between the Edge vector and the vector to the shape point position 
       This angle is an indicator of how good an edge can be seen by the radar sensor */
    fVectorLengthProduct = SFL_f_GetVector2Length(ShapePointVector) * SFL_f_GetVector2Length(EdgeVector);
    if(fABS(fVectorLengthProduct) > C_F32_DELTA)
    {
      float32 const fDotProduct = (ShapePointVector.fY * EdgeVector.fY) + (ShapePointVector.fX * EdgeVector.fX);
      float32 const fCosAngle   = fDotProduct/fVectorLengthProduct;
      fEdgeAngleDelta           = CML_Rad2Deg(ACOS_(fCosAngle));
    }

    /* Calculate the shape point qualities on base of the calculated Angle */
    afQualities[iSortedShapePoints[uSPNo]]  = CML_f_BoundedLinInterpol2(fEdgeAngleDelta, AIP_SHAPEPOINT_MIN_QUALITY_ANGLE, AIP_SHAPEPOINT_MAX_QUALITY_ANGLE, 0.f, 1.f);

  }
}


/*************************************************************************************************************************
  Functionname:         AIP_v_CalculateLimitedShapePoints                                                            */ /*!

  @brief                Limits the dimensions of objects used for the Object circle calculation.

  @description          Limits the width and length of an object to a minimum and a maximum value. The width limitation 
                        is for both sides equal, the length limitation refers only to the direction of the objects orientation. \n
                        This assures that non oncoming objects do not get a higher or lower x distance towards the ego vehicle 
                        by means of this limitation. Nevertheless this causes wrong values for oncoming objects which are limited. \n
                        @image html ShapePointLimitation.svg "Shapepoint Limitation"
                        @startuml AIP_v_CalculateLimitedShapePoints_activity.png
                        start
                          #Orange:Select the Min/Max Limitation values 
                          according to the object class:
                          <b>AIP_v_GetClassBasedDimensionLimits</b> >
                          :Limit the objects width and length 
                          to the min and max values;
                          #Orange: Shift the position of the object center to compensate
                          the delta caused by the length limitation:
                          <b>SFL_s_ShiftPositionAlongAngle</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pGeometry :           Width, Length and orientation of the considered object.
  @param[in,out]        pPosObjCenter :       Center position of the considered object.
  @param[in,out]        aLimitedShapePoints : Array with the positions of the limited shape points. To be filled by this function.

  @glob_in              @ref ACDC_p_GetEMGenObjQualifiers \n
                        @ref ACDC_a_GetObjShapePointQualities \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        @ref ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE
  @c_switch_full        @ref ACDC_CFG_AIP\n
                        

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCULATELIMITEDSHAPEPOINTS_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_CalculateLimitedShapePoints(ObjNumber_t    const         iObjectIndex,
                                       ACDCGeometry_t       * const pGeometry,
                                       SFLVector2D_t        * const pPosObjCenter,
                                       SFLVector2D_t                aLimitedShapePoints[])
{

  float32                   fLimitedWidth       = pGeometry->fWidth;
  float32                   fLimitedLength      = pGeometry->fLength;
  float32                   fLongitudinalShift  = 0.f;
  float32                   fLateralShift       = 0.f;

#if (ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE)
  EM_t_GenEbaObjClass const         eEbaClass         = ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->eEbaObjClass;
  float32             const * const afQualities       = ACDC_a_GetObjShapePointQualities(iObjectIndex);

  /* Get the indices of the shape points at the defined edges */
  sint8               const         iSPIdx_FrontLeft  = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_LEFT  );
  sint8               const         iSPIdx_RearLeft   = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_LEFT   );
  sint8               const         iSPIdx_RearRight  = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_RIGHT  );
  sint8               const         iSPIdx_FrontRight = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_RIGHT );

  /* Get the qualities of each object side (= minimum quality of the corresponding edges)*/
  float32             const         fQualityFront     = CML_f_Min(afQualities[iSPIdx_FrontLeft ] , afQualities[iSPIdx_FrontRight]);
  float32             const         fQualityRear      = CML_f_Min(afQualities[iSPIdx_RearLeft  ] , afQualities[iSPIdx_RearRight ]);
  float32             const         fQualityLeft      = CML_f_Min(afQualities[iSPIdx_FrontLeft ] , afQualities[iSPIdx_RearLeft  ]);
  float32             const         fQualityRight     = CML_f_Min(afQualities[iSPIdx_FrontRight] , afQualities[iSPIdx_RearRight ]);
  
  float32                           fLengthMin;
  float32                           fLengthMax;
  float32                           fWidthMin;
  float32                           fWidthMax;

  /* Get the length and width limitation values for the object */
  AIP_v_GetClassBasedDimensionLimits(eEbaClass, &fLengthMin, &fLengthMax, &fWidthMin, &fWidthMax);
  
  fLimitedWidth         = CML_f_MinMax(fWidthMin ,fWidthMax ,pGeometry->fWidth);
  fLimitedLength        = CML_f_MinMax(fLengthMin,fLengthMax,pGeometry->fLength);

  fLongitudinalShift    = ((fQualityRear - fQualityFront) * 0.5f * (fLimitedLength - pGeometry->fLength));
  fLateralShift         = ((fQualityRight - fQualityLeft) * 0.5f * (fLimitedWidth  - pGeometry->fWidth ));
#else
  _PARAM_UNUSED(iObjectIndex); /* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if this statement/code is removed */
#endif

  /* Shift the objects center according to the qualities of the shape point. The higher the quality, the less 
     will the limitation affect the corresponding object side*/
  (*pPosObjCenter)      = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation, fLongitudinalShift, fLateralShift);

  pGeometry->fWidth     = fLimitedWidth;
  pGeometry->fLength    = fLimitedLength;

  /* Calculate the limited shape points from the new geometry */
  aLimitedShapePoints[SP_FRONT_LEFT ] = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation,  0.5f * fLimitedLength,  0.5f * fLimitedWidth);
  aLimitedShapePoints[SP_FRONT_RIGHT] = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation,  0.5f * fLimitedLength, -0.5f * fLimitedWidth);
  aLimitedShapePoints[SP_REAR_RIGHT ] = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation, -0.5f * fLimitedLength, -0.5f * fLimitedWidth);
  aLimitedShapePoints[SP_REAR_LEFT  ] = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation, -0.5f * fLimitedLength,  0.5f * fLimitedWidth);

}


/*************************************************************************************************************************
  Functionname:         AIP_v_CalculateShapePointPositions                                                          */ /*!

  @brief                Calculates the relative positioning of the objects shape points by relating the indices 
                        with the four object edges.

  @description          Calculates the shape point index for each of the objects edges: 
                        - FRONT_LEFT
                        - FRONT_RIGHT
                        - REAR_LEFT
                        - REAR_RIGHT
                        .
                        Therefore the shapepoints are transformed into a coordinate system where the object has an 
                        orientation of 0°. Afterwards the center position of this new object is calculated. \n
                        In a last step the transfered positions are compared with the center position to determine their 
                        relative positioning regarding the object.\n
                        In some cases the shape points might not describe a rectangular shape (e.g. all shape points = 0). 
                        In that case the positions can not be determined and default values are assigned.
                        @startuml AIP_v_CalculateShapePointPositions_activity.png
                        start
                          #Orange:Transform the Shapepoints into the 
                          objects coordinate system:
                          <b>CML_v_TransformPosition2D</b> >
                          :Calculate the **Center Position** of the transformed object;
                          partition "Execute for each Shape Point"{
                            if(Shape Points X position is further away than Center X position?) then (Yes)
                              if(Shape Points Y position is further left than Center Y position?) then (Yes)
                                :1}
                                :The shape point is at the 
                                **FRONT LEFT** Edge;
                              else(No)
                                :2}
                                :The shape point is at the 
                                **FRONT RIGHT** Edge;
                              endif
                            else (No)
                              if(Shape Points Y position is further left than Center Y position?) then (Yes)
                                :3}
                                :The shape point is at the 
                                **REAR LEFT** Edge;
                              else(No)
                                :4}
                                :The shape point is at the 
                                **REAR RIGHT** Edge;
                              endif
                            endif
                            if(Shape point position has already been filled?) then (Yes)
                              :5}
                              :Object is **not rectangular**, 
                              assign **default values**;
                              note left:Possible if all shape points are 0
                            else(No)
                              :6}
                              :Assign the current shape point 
                              index to the determined Edge;
                            endif
                          }
                        stop
                        @enduml


  @return               void

  @param[in]            iObjectIndex :          Index of the considered object @range [0, EM_N_OBJECTS]
  @param[in,out]        iShapePointPositions :  Array of ShapePointPositions which shall be filled.

  @glob_in              @ref ACDC_p_GetEMGenObjGeometry \n
                        @ref ACDC_p_GetEMARSObjGeometry \n
                        @ref ACDC_p_GetEMCAMObj
  @glob_out             None

  @c_switch_part        @ref FCT_USE_EM_ARS_TECH_OBJECT_LIST \n
                        @ref FCT_USE_EM_CAM_TECH_OBJECT_LIST
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  Array iShapePointPositions has to be initialized to -1. Otherwise the default values will be returned in any case.
                        The Orientation (Radar) or Yaw (Camera) have to directly correlate with the orientation of the shape points!!
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_CALCULATESHAPEPOINTPOSITIONS_001 \n
                        @ref TEST_AIP_V_CALCULATESHAPEPOINTPOSITIONS_002

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_CalculateShapePointPositions(ObjNumber_t const iObjectIndex, 
                                               sint8             iShapePointPositions[])
{
  EM_t_GenObjShapePointCoord const *const aShapePoints = (ACDC_p_GetEMGenObjGeometry(iObjectIndex)->aShapePointCoordinates);
  EM_t_GenObjShapePointCoord              aTransformedShapePoints[EM_GEN_OBJ_N_SHAPE_POINTS];
  CML_t_TrafoMatrix2D                     TrafoMatrix;
  float32                                 fAvgX        = 0.f;
  float32                                 fAvgY        = 0.f;
  sint8                                   iSPNo        = 0;
  boolean                                 bRectangularObject = b_TRUE;
#if(FCT_USE_EM_ARS_TECH_OBJECT_LIST)
  float32                    const        fOrientation = ACDC_p_GetEMARSObjGeometry(iObjectIndex)->fOrientation;
#elif(FCT_USE_EM_CAM_TECH_OBJECT_LIST)
  float32                    const        fOrientation = ACDC_p_GetEMCAMObj(iObjectIndex)->Kinematic.fYaw;
#else
  float32                    const        fOrientation = 0.f;
  #pragma message(__FILE__ "(" STRING_QUOTE(__LINE__)"): warning : Cam and ARS object list are disabled. The Position of the shape points can not be determined correctly! ACDC object data is wrong!")
#endif

  /* Fill the trafo matrix that is used to transform the shape points into a coordinate system where the objects orientation is 0° */
  TrafoMatrix.TrafoType  = ROTATION_;
  TrafoMatrix.f00        = COS_(-fOrientation);
  TrafoMatrix.f02        = 0.f;
  TrafoMatrix.f10        = SIN_(-fOrientation);
  TrafoMatrix.f12        = 0.f;

  /* Transform all shape points and calculate the center position of the transformed shape points */
  for (iSPNo = 0; iSPNo < EM_GEN_OBJ_N_SHAPE_POINTS; ++iSPNo)
  {
    aTransformedShapePoints[iSPNo] = aShapePoints[iSPNo];
    CML_v_TransformPosition2D(&TrafoMatrix,&(aTransformedShapePoints[iSPNo].fPosX), &(aTransformedShapePoints[iSPNo].fPosY));
    fAvgX += aTransformedShapePoints[iSPNo].fPosX;
    fAvgY += aTransformedShapePoints[iSPNo].fPosY;
  }

  fAvgX *= (1.f/(float32)EM_GEN_OBJ_N_SHAPE_POINTS);
  fAvgY *= (1.f/(float32)EM_GEN_OBJ_N_SHAPE_POINTS);

  /* Calculate the ShapePointPosition for each shape point */
  for (iSPNo = 0; (iSPNo < EM_GEN_OBJ_N_SHAPE_POINTS) && (bRectangularObject == b_TRUE); ++iSPNo)
  {
    ACDCShapePointPositions_e eCurrSPPosition;

    if(fAvgX < aTransformedShapePoints[iSPNo].fPosX)
    {
      /* The shape point is at the front end of the object */
      if(fAvgY < aTransformedShapePoints[iSPNo].fPosY)
      {
        /* The shape point is on the left side of the object */
        eCurrSPPosition = SP_FRONT_LEFT;
      }
      else
      {
        /* The shape point is on the right side of the object */
        eCurrSPPosition = SP_FRONT_RIGHT;
      }
    }
    else
    {
      /* The shape point is at the rear end of the object */
      if(fAvgY < aTransformedShapePoints[iSPNo].fPosY)
      {
        /* The shape point is on the left side of the object */
        eCurrSPPosition = SP_REAR_LEFT;
      }
      else
      {
        /* The shape point is on the right side of the object */
        eCurrSPPosition = SP_REAR_RIGHT;
      }
    }

    /* Check if the Position has been filled before. 
    If no (index == -1), fill the position with the current shape point index.
    If yes, the object is not rectangular and the shape point positions are set to their default values. */
    if(iShapePointPositions[eCurrSPPosition] == ACDC_SP_POSITIONS_INIT)
    {
      iShapePointPositions[eCurrSPPosition] = iSPNo;
    }
    else
    {
      /* This path is currently only reached if all shape points are 0. In this case the 
         EM standard positioning is applied.*/
      iShapePointPositions[SP_FRONT_LEFT ] =  1;
      iShapePointPositions[SP_FRONT_RIGHT] =  2;
      iShapePointPositions[SP_REAR_LEFT  ] =  0;
      iShapePointPositions[SP_REAR_RIGHT ] =  3;
      bRectangularObject = b_FALSE;
    }
  }
}


/*************************************************************************************************************************
  Functionname:         AIP_i_GetShapePointIdx                                                                      */ /*!

  @brief                Returns the index of the shape point which is at the considered position of the given object.

  @description          Checks if the ShapePoint positions have been calculated for the given object. If no, calculate 
                        them by calling the function @ref AIP_v_CalculateShapePointPositions. \n
                        Possible Inputs for the requested shape point position are:
                        - FRONT_LEFT
                        - FRONT_RIGHT
                        - REAR_LEFT
                        - REAR_RIGHT
                        @startuml AIP_i_GetShapePointIdx_activity.png
                        start
                          if(ShapePointPositions have already been calculated) then (Yes)
                            :1}
                          else(No)
                            :2}
                            #Orange:Calculate the Shape point positions for this object:
                            <b>AIP_v_CalculateShapePointPositions</b> >
                          endif
                          :Return the Shape Point index of 
                          the desired shape point position;
                        stop
                        @enduml

  @return               sint8: Index of the shape point at the requested edge. @range [0,3]

  @param[in]            iObjectIndex :   Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in]            eShapePointPos : Position for which the Shape Point Index shall be returned. @range [0,3]

  @glob_in              @ref ACDC_p_ModObjDesc
  @glob_out             @ref ACDC_p_ModObjDesc

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_I_GETSHAPEPOINTIDX_001 \n
                        @ref TEST_AIP_I_GETSHAPEPOINTIDX_002

  @traceability         Design Decision

*************************************************************************************************************************/
sint8 AIP_i_GetShapePointIdx(ObjNumber_t               const iObjectIndex,
                             ACDCShapePointPositions_e const eShapePointPos)
{

  ACDCObject_t *const pCurrACDCObject = ACDC_p_ModObjDesc(iObjectIndex);

  /* Check if the Shapepoint Positions have already been calculated */
  if(pCurrACDCObject->ObjDescAdd.aiShapePointPositions[eShapePointPos] == ACDC_SP_POSITIONS_INIT)
  {
    AIP_v_CalculateShapePointPositions(iObjectIndex, pCurrACDCObject->ObjDescAdd.aiShapePointPositions);
  }

  /* Assure that the returned ShapePointPosition is in range! Might be problematic if not, as the output will be used for access to arrays. */
  /* PRQA S 3119 2 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for avoiding compiler warnings and hence cannot be removed */
  ACDC_ASSERT(    (pCurrACDCObject->ObjDescAdd.aiShapePointPositions[eShapePointPos]  >  ACDC_SP_POSITIONS_INIT)
               && (pCurrACDCObject->ObjDescAdd.aiShapePointPositions[eShapePointPos] <   ACDC_NOF_SP_POSITIONS ) );

  return pCurrACDCObject->ObjDescAdd.aiShapePointPositions[eShapePointPos];

}

/*!@}*/
#endif /* (ACDC_CFG_AIP) */

