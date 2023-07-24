/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_objcircles.c

DESCRIPTION:               Functions for the description of the objects shape by circles

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             01.03.2018

VERSION:                   $Revision: 1.22 $

**************************************************************************** */
#include "emp_objcircles.h"

#if (ACDC_CFG_EMP)
/************************************************************************/
/* MODULE DESCRIPTION                                                   */
/************************************************************************/
/*! 
@addtogroup emp_objcircles
@{
*/

/************************************************************************
   STATIC FUNCTION DECLARATIONS
************************************************************************/

static void         EMP_v_FillCircleData(ACDCObjectCircle_t const Circles[], uint8 uNofCircles, ACDCObjectCircleData_t *const pCircleData);
static boolean      EMP_b_CalcIntersectionCircle(ACDCObjectCircle_t const *const pFrontObjCircle, ACDCObjectCircle_t  const *const pRearObjCircle, ACDCObjectCircle_t *const pIntersectObjCircle);
static void         EMP_v_CalcDistToTrajCircle(ACDCObjectCircle_t       * const pObjCircle);
static void         EMP_v_CalcFrontAndRearCircleFromShapePoints(ObjNumber_t const iObjectIndex, ACDCObjectCircle_t * const pFrontCircle, ACDCObjectCircle_t * const pRearCircle);
static SFLCircle_t  EMP_s_CalcScaledObjectCircle(SFLVector2D_t const * const pPosObjCenter, ACDCGeometry_t const * const pGeometry, float32 const fQualityLeft, 
                                                 float32 const fQualityRight, boolean const bFront);

/************************************************************************
  EXTERNAL FUNCTIONS
*************************************************************************/
/*************************************************************************************************************************
  Functionname:         EMP_v_CalculateCurrentCircle                                                                */ /*!

  @brief                Calculates the position of the Nth circle of a circle representation of a rectangle.

  @description          For the calculation of the TTM, objects are represented by circles. The number of 
                        circles depends on the factor between length and width of the object. \n
                        When length is smaller than width, the object can only be represented by one circle. 
                        To improve this behavior of this case, the length and width are exchanged. \n
                        This function returns the Nth of the circles (see illustration).
                        @image html CD_CalculateCurrentCircle.jpg width=1200
                        @startuml EMP_v_CalculateCurrentCircle_activity.png
                        start
                          if(Length >= Width) then (yes)
                            :1}
                          else (No)
                            :2}
                            :exchange length and width; 
                          endif
                          :Calculate Position of first and last circle;
                          note left: >see formulas\n"First Circle" and "Last Circle"
                          if (Circle Number is 1?) then (Yes)
                            :3}
                            :Return object center 
                            as circle center;
                          elseif (Requested circle ID < First cycle ID) then (Yes)
                            :4}
                            :Return Coordinates of 
                            start circle;
                          elseif (Requested circle ID >= Last cycle ID) then (Yes)
                            :5}
                            :Return Coordinates of 
                            end circle;
                          else (No)
                            :6}
                            :Calculate coordinates of circle center
                            on base of linear interpolation between
                            first and last circle;
                          endif
                        stop
                        @enduml

  @param[in]            pObject          : Pointer to object to calculate circle representation.
  @param[in]            uCurrentCircleID : ID of requested circle.  @range [0,+...[
  @param[in]            uNofCircles      : Number of circles in total. @range [0,+...[
  @param[in,out]        pCircle          : Pointer to resulting circle.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Call function @ref EMP_v_CalcNumofCircles to determine input parameter uiNumOfCirclesObj.
  @post                 None

  @InOutCorrelation     
                        - **First Circle**: \n
                          \f$X_{First} = X_{Obj,Center} + (\cos(OrientAngle_{Obj}) \cdot Length_{Obj} \cdot 0.5) - (\cos(OrientAngle_{Obj}) \cdot Radius)\f$ \n
                          \f$Y_{First} = Y_{Obj,Center} + (\sin(OrientAngle_{Obj}) \cdot Length_{Obj} \cdot 0.5) - (\sin(OrientAngle_{Obj}) \cdot Radius)\f$
                        - **Last Circle**: \n
                          \f$X_{Last}  = X_{Obj,Center} - (\cos(OrientAngle_{Obj}) \cdot Length_{Obj} \cdot 0.5) + (\cos(OrientAngle_{Obj}) \cdot Radius)\f$ \n
                          \f$X_{Last}  = Y_{Obj,Center} - (\sin(OrientAngle_{Obj}) \cdot Length_{Obj} \cdot 0.5) + (\sin(OrientAngle_{Obj}) \cdot Radius)\f$

  @testmethod          @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_001 \n               
                       @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_002 \n            
                       @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_003 \n             
                       @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_004 \n
					   @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_005 \n             
                       @ref TEST_EMP_V_CALCULATECURRENTCIRCLE_006

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void EMP_v_CalculateCurrentCircle(ACDCObjDesc_t const * const pObject, 
                                  uint8                       uCurrentCircleID,
                                  uint8                       uNofCircles,
                                  SFLCircle_t        * const pCircle)
{
  float32 fDistXStart;
  float32 fDistYStart;
  float32 fDistXEnd;
  float32 fDistYEnd;
  float32 fLength;
  float32 fWidth;
  float32 fOrientation;
  float32 fCos_Orientation;
  float32 fSin_Orientation;
  uint8   uiNumOfCircles = MINMAX(ACDC_MIN_NOF_CIRCLES, ACDC_MAX_NOF_CIRCLES, uNofCircles);
  
  /* As the orientation is not important for the circle calculation, assure that the length equals the
     longer side of the object and the orientation points in direction of the length. */
  if (pObject->Geometry.fLength >= pObject->Geometry.fWidth)
  {
    fLength      = pObject->Geometry.fLength;
    fWidth       = pObject->Geometry.fWidth;
    fOrientation = pObject->Geometry.fOrientation;
  }
  else
  {
    fLength      = pObject->Geometry.fWidth;
    fWidth       = pObject->Geometry.fLength;
    fOrientation = pObject->Geometry.fOrientation + CML_Deg2Rad(90.f);
  }

  /* Calculate the Circle radius; Precalculate Sin and Cos values of the orientation */
  pCircle->fRadius = MAX(ACDC_MIN_CIRCLE_RADIUS, (fWidth/2.f));
  GDBsincos(fOrientation, &fSin_Orientation, &fCos_Orientation);
  
  /* Calculate the first and the last circle that describe the object */
  fDistXStart      = (pObject->ObjectPosCenter.fX + ((fCos_Orientation*fLength)/2.f)) - (fCos_Orientation*pCircle->fRadius);
  fDistYStart      = (pObject->ObjectPosCenter.fY + ((fSin_Orientation*fLength)/2.f)) - (fSin_Orientation*pCircle->fRadius);
  fDistXEnd        = (pObject->ObjectPosCenter.fX - ((fCos_Orientation*fLength)/2.f)) + (fCos_Orientation*pCircle->fRadius);
  fDistYEnd        = (pObject->ObjectPosCenter.fY - ((fSin_Orientation*fLength)/2.f)) + (fSin_Orientation*pCircle->fRadius);
  
  if (uiNumOfCircles == 1u)
  {
    /* Create only one circle in the center of the object */
    pCircle->fX = pObject->ObjectPosCenter.fX;
    pCircle->fY = pObject->ObjectPosCenter.fY;
  }
  else if (uCurrentCircleID < ACDC_MIN_NOF_CIRCLES)
  {
    /* Return the first circle */
    pCircle->fX = fDistXStart;
    pCircle->fY = fDistYStart;
  }
  else if (uCurrentCircleID >= (uiNumOfCircles-1u))
  {
    /* Return the last circle */
    pCircle->fX = fDistXEnd;
    pCircle->fY = fDistYEnd;
  }
  else
  {
    /* Interpolate between the first and the last circle and return the position that corresponds to the given number uCurrentCircleID */
    /*PRQA S 4394 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to float intended as use of generic interface*/
    pCircle->fX = CML_f_LinearInterpolation((float32)(ACDC_MIN_NOF_CIRCLES-1u), fDistXStart, (float32)(uiNumOfCircles-1u), fDistXEnd, (float32)uCurrentCircleID);
    pCircle->fY = CML_f_LinearInterpolation((float32)(ACDC_MIN_NOF_CIRCLES-1u), fDistYStart, (float32)(uiNumOfCircles-1u), fDistYEnd, (float32)uCurrentCircleID);
  }
}


/*************************************************************************************************************************
  Functionname:         EMP_v_CalcNumofCircles                                                                      */ /*!

  @brief                Calculates number of circles.

  @description          For the calculation of the TTM, objects are represented by circles. The number of 
                        circles depends on the factor between length and width of the object. \n
                        This function returns number of the circles.
                        Further information can be found in @ref EMP_v_CalculateCurrentCircle.
                        @startuml EMP_v_CalcNumofCircles_activity.png
                        start
                        if(Length and Width are positive values?) then(yes)
                          if(Length >= Width?) then(yes)
                            :1}
                            :Calculate Number of Circles 
                            according to **Formula 1**;
                          else (No)
                            :2}
                            :Calculate Number of Circles
                            according to **Formula 2**;
                          endif
                        else (No)
                          :3}
                          :NumOfCircles = 1;
                        endif
                        stop
                        @enduml

  @return               void

  @param[in]            pObject     : Pointer to object to calculate circle representation.
  @param[in,out]        uNofCircles : Resulting Number of circles that shall be calculated per object.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  None
  @post                 @ref EMP_v_CalculateCurrentCircle can be called.

  @InOutCorrelation     
                        - **Formula 1:**\n
                          \f$ N_{Circles} = Ceil(\frac{Length}{Width})\f$
                        - **Formula 2:**\n
                          \f$ N_{Circles} = Ceil(\frac{Width}{Length})\f$

  @testmethod          @ref TEST_EMP_V_CALCNUMOFCIRCLES_001  \n              
                       @ref TEST_EMP_V_CALCNUMOFCIRCLES_002  \n            
                       @ref TEST_EMP_V_CALCNUMOFCIRCLES_003                 

  @traceability        Design Decision

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
void EMP_v_CalcNumofCircles(ACDCObjDesc_t const * const pObject, 
                            uint8               * const uNofCircles)
{
  *uNofCircles = 1u;
  if (MIN(pObject->Geometry.fWidth, pObject->Geometry.fLength) > C_F32_DELTA)
  {
    if (pObject->Geometry.fLength >= pObject->Geometry.fWidth)
    {
      *uNofCircles = (uint8)(CML_f_Ceil(pObject->Geometry.fLength/pObject->Geometry.fWidth));
    }
    else
    {
      *uNofCircles = (uint8)(CML_f_Ceil(pObject->Geometry.fWidth/pObject->Geometry.fLength));
    }
  }
}


/*************************************************************************************************************************
  Functionname:         EMP_v_CalcObjectCircles                                                                     */ /*!

  @brief                Calculates the Minimum and the maximum distance to trajectory of an object. Fills the 
                        internal objects circle structure.

  @description          Calculates a circle based object description. On base of these circles a minimum and a maximum 
                        distance to trajectory are calculated. The algorithm distinguishes two different situations:
                        1. (=Standard Case) The object is described by 2 circles: One at each end. The circle radius 
                           depends on the qualities of the single shape points.
                        2. The gradients of the ego trajectory at the reference points distinguish in their orientation 
                           towards the object. (e.g. one gradient pointing towards the object, the other gradient pointing away). \n
                           In this case it is possible that another than the first or the last circle is closer/further away 
                           from the ego trajectory. In this case the so called Intersection Circle is calculated. 
                           (see @ref EMP_b_CalcIntersectionCircle)
                        .
                        The Min and Max DistToTraj are determined by a loop through all calculated circles.
                        @image html EMP_CalcDistToTrajMinMax.svg
                        @startuml EMP_v_CalcObjectCircles_activity.png
                        start
                          #Orange: Calculate the circles describing the front 
                          and the rear end of the object:
                          <b>EMP_v_CalcFrontAndRearCircleFromShapePoints</b> >
                          :Check if an intersection circle 
                          has to be calculated;
                          note left: >see "Checks Intersection Circle"
                          if(Intersection circle calculation is required?) then (Yes)
                            #Orange: Calculate the Intersection Circle:
                            <b>EMP_b_CalcIntersectionCircle</b> >
                            if(Intersection Circle is valid?) then (No)
                              :1}
                              :Reject Intersection circle;
                            else(Yes)
                              :2}
                            endif
                          else(No)
                            :3}
                            note right:The First and the last circle are\nsufficient to describe the obejct;
                          endif
                          #Orange: Fill the Objects Circle data on 
                          base of the calculated circles:
                          <b>EMP_v_FillCircleData</b> >
                        stop
                        @enduml

  @param[in]            iObjectIndex :         Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pCircleData :          Pointer to the object circle data which shall be filled by this function.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n
                        @ref ACDC_CFG_USE_OBJECT_CIRCLES

  @InOutCorrelation     - **Checks Intersection Circle**:
                          - Is the object NOT crossing the ego trajectory? (Check if signs of first and last circle 
                            DistToTraj are equal)
                          - Calculate the angles of the gradients at the reference point of the first and the last circle.
                            Set these angles in relation to the objects orientation. Only if they change their sign, an \n
                            intersection circle is needed. (Check if signs of relative angles are different)

  @testmethod          @ref TEST_EMP_V_CALCOBJECTCIRCLES_001 \n              
                       @ref TEST_EMP_V_CALCOBJECTCIRCLES_002 \n             
                       @ref TEST_EMP_V_CALCOBJECTCIRCLES_003 \n
					   @ref TEST_EMP_V_CALCOBJECTCIRCLES_004 

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void EMP_v_CalcObjectCircles(ObjNumber_t            const         iObjectIndex,
                             ACDCObjectCircleData_t       * const pCircleData)
{
  ACDCObjectCircle_t  FrontCircle, RearCircle;
  ACDCObjectCircle_t  Circles[ACDC_MAX_NOF_OBJECT_CIRCLES];

  float32             fFirstCircleAngleDelta;
  float32             fLastCircleAngleDelta;
  float32             fCircleXDist;
  float32             fCircleYDist;
  float32             fAngleCircleAxis;
  uint8               uNofCircles = 0u;

  /* Calculate two circles: one at the front and one at the rear end of the object */
  EMP_v_CalcFrontAndRearCircleFromShapePoints(iObjectIndex, &FrontCircle, &RearCircle);

  /* Append the first and the last circle to the circle array */
  Circles[uNofCircles]    = FrontCircle;
  uNofCircles++;
  Circles[uNofCircles]    = RearCircle;
  uNofCircles++;

  /* Calculate the Angle of the axis between the front and the rear circle */
  fCircleXDist            = FrontCircle.Circle.fX - RearCircle.Circle.fX;
  fCircleYDist            = FrontCircle.Circle.fY - RearCircle.Circle.fY;
  fAngleCircleAxis        = SFL_f_CalcAngleFromVector(fCircleXDist, fCircleYDist, b_FALSE);

  fFirstCircleAngleDelta  = fAngleCircleAxis - FrontCircle.fRefPointAngle;
  fLastCircleAngleDelta   = fAngleCircleAxis - RearCircle.fRefPointAngle;

  /* Check if the Intersection circle needs to be calculated (for more details see design) */
  if(    ( (RearCircle.fDistToTraj * FrontCircle.fDistToTraj )  > 0.f )
      && ( (fFirstCircleAngleDelta * fLastCircleAngleDelta   ) <  0.f ) )
  {
    /* Calculate the intersection circle */
    ACDCObjectCircle_t  IntersectionCircle;
    boolean bIntersectCircleValid = EMP_b_CalcIntersectionCircle(&FrontCircle, &RearCircle, &IntersectionCircle);

    if(bIntersectCircleValid == b_TRUE)
    {
      /* Intersection circle is valid, append it to the circle array */
      Circles[uNofCircles]    = IntersectionCircle;
      uNofCircles++;
    }
  }


  /* Fill the information from the array into the objects circle data */
  EMP_v_FillCircleData(Circles, uNofCircles, pCircleData);

}

/************************************************************************/
/* STATIC FUNCTIONS                                                     */
/************************************************************************/
/*************************************************************************************************************************
  Functionname:         EMP_v_FillCircleData                                                                            */ /*!

  @brief                Fills the circle data of an object with the given circles.

  @description          Loops through the given circles and determines the ones with the minimum and the maximum 
                        distance to the ego trajectory. Passes the circles to the objects data structure.
                        @startuml EMP_v_FillCircleData_activity.png
                        start
                          :Set Min and Max DistToTraj to Initial Values;
                          partition "Execute for all Circles" {
                          if(DistToTraj < Minimum DistToTraj) then (Yes)
                            :1}
                            :Store circle ID as MinDistCircle;
                            :Minimum DistToTraj = DistToTraj;
                          else (No)
                            :2}
                          endif
                          if(DistToTraj > Maximum DistToTraj) then (Yes)
                            :3}
                            :Store circle ID as MaxDistCircle;
                            :Maximum DistToTraj = DistToTraj;
                          else (No)
                            :4}
                          endif
                          :Copy circle to objects circle data;
                          }
                        stop
                        @enduml

  @param[in]            Circles :     Array of Circles that describe the object.
  @param[in]            uNofCircles : Number of Circles in the Array. @range [0,@ref ACDC_MAX_NOF_OBJECT_CIRCLES]
  @param[in,out]        pCircleData : Objects circle data that shall be filled.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP \n
                        @ref ACDC_CFG_USE_OBJECT_CIRCLES

  @InOutCorrelation     see description

  @testmethod          @ref TEST_EMP_V_FILLCIRCLEDATA_001 \n               
                       @ref TEST_EMP_V_FILLCIRCLEDATA_002                                

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void EMP_v_FillCircleData(ACDCObjectCircle_t      const Circles[], 
                                 uint8                         uNofCircles, 
                                 ACDCObjectCircleData_t *const pCircleData)
{
  float32 fMinDistToTraj =  ACDC_DIST_DEFAULT;
  float32 fMaxDistToTraj = -ACDC_DIST_DEFAULT;
  uint8   uCircleNo;

  /* Initialize relevant values of the Circle Data */
  pCircleData->uNofCircles    = uNofCircles;
  pCircleData->uMinDistCircle = 0u;
  pCircleData->uMaxDistCircle = 0u;

  for(uCircleNo = 0u; uCircleNo < uNofCircles; uCircleNo++)
  {
    ACDCObjectCircle_t const *const currCircle = &Circles[uCircleNo];

    /* Check for each circle if it is the one with the minimum/the maximum DistToTraj (can also be both) */
    if((currCircle->fDistToTraj - currCircle->Circle.fRadius) < fMinDistToTraj )
    {
      /* Find the circle with the minimum Distance to trajectory */
      fMinDistToTraj              = currCircle->fDistToTraj - currCircle->Circle.fRadius;
      pCircleData->uMinDistCircle = uCircleNo;
    }
    if((currCircle->fDistToTraj + currCircle->Circle.fRadius) > fMaxDistToTraj)
    {
      /* Find the circle with the maximum Distance to trajectory */
      fMaxDistToTraj              = currCircle->fDistToTraj + currCircle->Circle.fRadius;
      pCircleData->uMaxDistCircle = uCircleNo;
    }
    /* Copy the circle data to the object */
    pCircleData->ObjectCircles[uCircleNo] = *currCircle;
  }
}

/*************************************************************************************************************************
  Functionname:         EMP_b_CalcIntersectionCircle                                                                    */ /*!

  @brief                Calculates an Intersection circle on base of two given object circles which mark the 
                        end and the beginning of an object.

  @description          For the determination of the intersection circle, the intersection point of the gradient 
                        functions of the given circles Reference Points is calculated. Therefore the functions \n
                        which describe the gradients have to be set up:\n
                        First circle gradient function: \f$Y_1 = M_1 \cdot X_1 + C_1\f$ \n
                        Last circle gradient function:  \f$Y_2 = M_2 \cdot X_2 + C_2\f$ \n
                        These functions are equalized to determine the coordinates of the intersection point:
                        \f$X_{Intersect}\f$ and \f$Y_{Intersect}\f$. \n
                        Subsequently the function of the objects center axis is needed. It is calculated from 
                        the positions of the circles:\n
                        Object axis function: \f$ Y_{Obj} = M_{Obj} \cdot X_{Obj} + C_{Obj}\f$ \n
                        In the next step the position on the object axis at which the distance to the intersection 
                        point is minimal has to be found. Therefore the distance function is set up:\n
                        \f$D_{Obj,Intersect} = \sqrt{(X_{Intersect} - X_{Obj})^2 + (Y_{Intersect} - M_{Obj} \cdot X_{Obj} + C_{Obj})^2}\f$ \n
                        The derivative of this function is equalized with 0. From this function X_{Obj} can be calculated
                        (see InOutCorrelation).
                        \image html EMP_CalcIntersectionCircle.svg
                        @startuml EMP_b_CalcIntersectionCircle_activity.png
                        start
                          :Calculate Y-Axis intercepts 
                          of the gradient functions;
                          note left: >see Formula "Axis Intercept"
                          :Calculate Intersection Point;
                          note left: >see Formula "Intersection Point"
                          :Calculate function of the objects main axis;
                          note left: >see Formula "Object Function"
                          :Calculate Intersection Circle center;
                          note left
                          >see Formula "Intersection circle center"
                          >see Formula "Intersection circle radius"
                          end note
                          #Orange:Calculate DistToTraj of the circle: 
                          <b>EMP_v_CalcDistToTrajCircle</b> >
                          if(Circle center is between the\nfirst and the last circle?) then (Yes)
                            :1}
                            :Return True;
                          else(No)
                            :2}
                            :Return False;
                          endif
                        stop
                        @enduml

  @return               boolean : True if the found Intersection Circle is valid

  @param[in]            *pFrontObjCircle :        Data of the objects first circle.
  @param[in]            *pRearObjCircle :         Data of the objects last circle.
  @param[in,out]        *pIntersectObjCircle :    Data of the calculated intersection circle.

  @glob_in              @ref SFL_f_CalcGradientFromAngle \n
                        @ref SFL_f_CalcAngleFromVector   \n
						@ref SFL_f_CalcGradientFromAngle
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n
                        @ref ACDC_CFG_USE_OBJECT_CIRCLES

  @InOutCorrelation     
                        - **Formula Axis Intercept:** \n
                          \f$C = Y - M \cdot X\f$
                        - **Formula Intersection Point:** \n
                          \f$X_{Intersect} = \frac{C_2 - C_1}{M_1 - M_2}\f$ \n
                          \f$Y_{Intersect} = C_1 - M_1 - X_{Intersect}\f$
                        - **Formula Object Function:** \n
                          \f$M_{Obj} = \frac{\sin(Orientation)}{\cos(Orientation)}\f$ \n
                          \f$C_{Obj} = Y_1 - M_{Obj} \cdot X_1\f$
                        - **Formula Intersection circle center:** \n
                          \f$\frac{(-M_{Obj} \cdot C_{Obj}) + (Y_{Intersect} \cdot M_{Obj}) + (X_{Intersect})}{(M_{Obj})^2 + 1}\f$
                        - **Formula Intersection circle radius:** \n
                          \f$ R_{Intersect} = (1 - \frac{D_{Intersect, Rear}}{D_{Front, Rear}}) \cdot R_{Rear} + 
                                              (1 - \frac{D_{Intersect, Front}}{D_{Front, Rear}}) \cdot R_{Front}\f$

  @testmethod          @ref TEST_EMP_B_CALCINTERSECTIONCIRCLE_001 \n             
                       @ref TEST_EMP_B_CALCINTERSECTIONCIRCLE_002 \n
					   @ref TEST_EMP_B_CALCINTERSECTIONCIRCLE_003 \n             
                       @ref TEST_EMP_B_CALCINTERSECTIONCIRCLE_004 

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static boolean EMP_b_CalcIntersectionCircle(ACDCObjectCircle_t  const *const pFrontObjCircle, 
                                            ACDCObjectCircle_t  const *const pRearObjCircle,
                                            ACDCObjectCircle_t        *const pIntersectObjCircle)
{
  boolean bReturn = b_TRUE;

  float32 fX_Intersect;
  float32 fY_Intersect;
  float32 fDistToFrontCircle;
  float32 fDistToRearCircle;
  float32 fDistFrontRearCircle;

  /* Calculate the Y-axis intercepts of the gradient functions */
  const float32 fGradientRefFirst = SFL_f_CalcGradientFromAngle(pFrontObjCircle->fRefPointAngle);
  const float32 fGradientRefLast  = SFL_f_CalcGradientFromAngle(pRearObjCircle->fRefPointAngle);
  const float32 fC1               = pFrontObjCircle->RefPoint.fY - (fGradientRefFirst * pFrontObjCircle->RefPoint.fX);
  const float32 fC2               = pRearObjCircle->RefPoint.fY  - (fGradientRefLast  * pRearObjCircle->RefPoint.fX );
  
  /* Calculate the gradient and the Y-axis intercept of the object function */
  const float32 fXDist            = pFrontObjCircle->Circle.fX - pRearObjCircle->Circle.fX;
  const float32 fYDist            = pFrontObjCircle->Circle.fY - pRearObjCircle->Circle.fY;
  const float32 fOrientation      = SFL_f_CalcAngleFromVector(fXDist, fYDist,b_FALSE);
  const float32 fM_Obj            = SFL_f_CalcGradientFromAngle(fOrientation);
  const float32 fC_Obj            = pFrontObjCircle->Circle.fY - ( fM_Obj * pFrontObjCircle->Circle.fX );

  /* Calculate the Position (X,Y) of the intersection point of the two functions of the gradients */
  if(fABS(fGradientRefFirst - fGradientRefLast) > C_F32_DELTA)
  {
    fX_Intersect = (fC2 - fC1) / (fGradientRefFirst - fGradientRefLast);
  }
  else
  {
    fX_Intersect = (pFrontObjCircle->RefPoint.fX + pRearObjCircle->RefPoint.fX) / 2.f;
  }
  fY_Intersect = fC1 + (fGradientRefFirst * fX_Intersect);

  /* Calculate the Circle that is closest to the intersection point of the slopes
     (= point of minimum distance between the intersection point and the object function) */
  pIntersectObjCircle->Circle.fX        = (((-fM_Obj) * fC_Obj) + (fY_Intersect * fM_Obj) + (fX_Intersect))/(SQR(fM_Obj) + 1.f);
  pIntersectObjCircle->Circle.fY        = ((fM_Obj * pIntersectObjCircle->Circle.fX) + fC_Obj);
  
  /* Calculate the intersection circle radius by interpolating between the radius of the first and the last object circle */
  fDistToFrontCircle                    = SQRT(SQR(pIntersectObjCircle->Circle.fX - pFrontObjCircle->Circle.fX) + SQR(pIntersectObjCircle->Circle.fY - pFrontObjCircle->Circle.fY));
  fDistToRearCircle                     = SQRT(SQR(pIntersectObjCircle->Circle.fX - pRearObjCircle->Circle.fX ) + SQR(pIntersectObjCircle->Circle.fY - pRearObjCircle->Circle.fY ));
  fDistFrontRearCircle                  = fDistToRearCircle + fDistToFrontCircle;

  if(fDistFrontRearCircle < C_F32_DELTA)
  {
    /* Avoid Div by 0 and negative values (should not be possible) */
    pIntersectObjCircle->Circle.fRadius = pFrontObjCircle->Circle.fRadius;
    ACDC_ASSERT(fDistFrontRearCircle > 0.f);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  }
  else
  {
    pIntersectObjCircle->Circle.fRadius = CML_f_BoundedLinInterpol2(fDistToRearCircle                                              ,
                                                                    0.f                           , fDistFrontRearCircle           ,
                                                                    pRearObjCircle->Circle.fRadius, pFrontObjCircle->Circle.fRadius);
  }
  
  /* Calculate the DistToTraj of the Intersection Circle */
  EMP_v_CalcDistToTrajCircle(pIntersectObjCircle);
  
  /* Check if found intersection circle is REALLY inside of the object
     (for certain gradients it is possible that the found circle is on a position on the object function that is outside of the object) */
  if(    (pIntersectObjCircle->Circle.fX  > MAX(pFrontObjCircle->Circle.fX, pRearObjCircle->Circle.fX ) )
      || (pIntersectObjCircle->Circle.fX <  MIN(pFrontObjCircle->Circle.fX, pRearObjCircle->Circle.fX ) )
      || (pIntersectObjCircle->Circle.fY  > MAX(pFrontObjCircle->Circle.fY, pRearObjCircle->Circle.fY ) )
      || (pIntersectObjCircle->Circle.fY <  MIN(pFrontObjCircle->Circle.fY, pRearObjCircle->Circle.fY ) ) )
  {
    bReturn = b_FALSE;
  }
  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         EMP_v_CalcDistToTrajCircle                                                                      */ /*!

  @brief                Calculates the distance to trajectory for a circle.

  @description          Calculates the distance to trajectory for a circle by calling the functions 
                        @ref EMP_b_CalcTrajectoryRefPoint @ref EMP_v_CalcDistToRefPoint.

  @param[in,out]        pObjCircle :     Object Circle data structure that shall be filled with the DistToTraj information.

  @glob_in              @ref AIP_p_GetACDCEgoTraj
                        @ref SFL_f_CalcAngleFromVector
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP \n
                        @ref ACDC_CFG_USE_OBJECT_CIRCLES

  @InOutCorrelation     see description

  @testmethod          @ref TEST_EMP_V_CALCDISTTOTRAJCIRCLE_001  \n              
                       @ref TEST_EMP_V_CALCDISTTOTRAJCIRCLE_002                                

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void EMP_v_CalcDistToTrajCircle(ACDCObjectCircle_t * const pObjCircle)
{
  ACDCTrajPred_t const * const pEgoTrajPred = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration);
  SFLVector2D_t                ObjPos;
  SFLVector2D_t                RefPoint;
  SFLVector2D_t                VelAtRefPoint;
  float32                      fDistToTraj = ACDC_DIST_DEFAULT;
  float32                      fDistOnTraj = ACDC_DIST_DEFAULT;
  boolean                      bResultOk;

  ObjPos.fX = pObjCircle->Circle.fX;
  ObjPos.fY = pObjCircle->Circle.fY;
  bResultOk = EMP_b_CalcTrajectoryRefPoint(&ObjPos,pEgoTrajPred,&RefPoint,&VelAtRefPoint);

  if(bResultOk == b_TRUE)
  {
    EMP_v_CalcDistToRefPoint(&ObjPos,&RefPoint,&fDistToTraj,&fDistOnTraj);
  }
  /* else keep default values*/

  pObjCircle->RefPoint       = RefPoint;
  pObjCircle->fRefPointAngle = SFL_f_CalcAngleFromVector(VelAtRefPoint.fX,VelAtRefPoint.fY,b_FALSE);
  pObjCircle->fDistToTraj    = fDistToTraj;

}

/*************************************************************************************************************************
  Functionname:         EMP_s_CalcScaledObjectCircle                                                                 */ /*!

  @brief                Calculates a circle that describes either the front or the rear part of an object according 
                        to its shape point qualities.

  @description          Circles are used to describe the extreme extensions of the object. Therefore one circle 
                        describes the objects front and one the rear part. The circles vary in their size and position \n
                        according to the quality of the corresponding shape points. The higher the quality of a shape point, 
                        the bigger the circle next to it.
                        @startuml EMP_s_CalcScaledObjectCircle_activity.png
                        start
                          :Calculate the **Lateral Shift Distance**;
                          note left: >see **Formula Lateral Shift**
                          :Calculate the **Circle radius**;
                          note left: >see **Formula Radius**
                          :Calculate the **Longitudinal Shift Distance**;
                          note left: >see **Formula Longitudinal Shift**
                          if(Front circle shall be calculated?) then (Yes)
                            :1}
                          else (No)
                            :2}
                            :Invert sign of the **Longitudinal Shift Distance**;
                          endif
                          #Orange:Shift the circle position from the object 
                          center to the desired position:
                          <b>SFL_s_ShiftPositionAlongAngle</b> >
                        stop
                        @enduml

  @return               SFLCircle_t : Calculated circle that describes the front / the rear of an object.

  @param[in]            pPosObjCenter : Center position of the considered object,
  @param[in]            pGeometry :     Width, length & orientation of the considered object (calculated from its shape points!).
                                        see @ref AIP_v_CalcGeometryFromShapePoints
  @param[in]            fQualityLeft :  Quality of the left shape point.  @range [0,1]
  @param[in]            fQualityRight : Quality of the right shape point. @range [0,1]
  @param[in]            bFront :        Flag indicating whether the front or the rear circle shall be calculated. (TRUE = Front)

  @glob_in              @ref SFL_s_ShiftPositionAlongAngle
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Lateral Shift:** \n
                          \f$D_{Lateral} = 0.5 \cdot (Q_{Left} - Q_{Right}) \cdot 0.5 \cdot Width\f$
                        - **Formula Radius:** \n
                          \f$Radius      = 0.5 \cdot (Q_{Left} + Q_{Right}) \cdot 0.5 \cdot Width\f$
                        - **Formula Longitudinal Shift:** \n
                          \f$D_{QualityShift} = f(MAX(Q_{Left},Q_{Right}))\f$ \n
                          \f$D_{Longitudinal} = 0.5 \cdot Length - D_{QualityShift}\f$

  @testmethod          @ref TEST_EMP_S_CALCSCALEDOBJECTCIRCLE_001 \n               
                       @ref TEST_EMP_S_CALCSCALEDOBJECTCIRCLE_002 \n
                              

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static SFLCircle_t EMP_s_CalcScaledObjectCircle( SFLVector2D_t  const * const pPosObjCenter,
                                                 ACDCGeometry_t const * const pGeometry,
                                                 float32        const         fQualityLeft,
                                                 float32        const         fQualityRight,
                                                 boolean        const         bFront)
{
  SFLCircle_t        CalculatedCircle;
  SFLVector2D_t      PosCircle;
  
  /* Calculate lateral distance by which the circle shall be shifted from the objects center position */
  float32      const fLateralShift       = 0.25f * ((fQualityLeft - fQualityRight) * pGeometry->fWidth);
  /* Calculate the Radius of the Circle */
  float32      const fRadius             = 0.25f * ((fQualityLeft + fQualityRight) * pGeometry->fWidth);
  /* Calculate longitudinal distance by which the circle shall be shifted from the objects center position */
  float32      const fLongQuality        = MAX(fQualityLeft, fQualityRight);
  /* Minimum longitudinal shift (from object center) = circle radius; Maximum longitudinal shift = Half object length minus circle radius*/
  float32            fLongitudinalShift  = CML_f_BoundedLinInterpol2(fLongQuality, 0.f, 1.f, fRadius, (0.5f * pGeometry->fLength) - fRadius);

  if(bFront == b_FALSE)
  {
    /* Invert the sign of the longitudinal shift for the Rear Circle */
    fLongitudinalShift *= -1.f;
  }

  /* Shift the circle center from the object center to the desired position. */
  PosCircle = SFL_s_ShiftPositionAlongAngle((*pPosObjCenter), pGeometry->fOrientation, fLongitudinalShift, fLateralShift);

  CalculatedCircle.fRadius               = fRadius;
  CalculatedCircle.fX                    = PosCircle.fX;
  CalculatedCircle.fY                    = PosCircle.fY;
  return CalculatedCircle;
}

/*************************************************************************************************************************
  Functionname:         EMP_v_CalcFrontAndRearCircleFromShapePoints                                                  */ /*!

  @brief                Calculates two circles to describe an object. One at the Front and one at the End of the object.

  @description          Uses the objects ShapePoints to calculate two circles that describe the front and the rear end 
                        of the object. The circle size and position depends on the quality with which the shape points 
                        have been measured.
                        @image html ShapePointCircles.svg "Shapepoint Circles"
                        @startuml EMP_v_CalcObjCirclesFromShapePoints_activity.png
                        start
                          :Get the current ACDC object data;
partition #LightBlue **ACDC_CFG_LIMIT_SHAPE_POINT_OBJECT_SIZE** {
                          #Orange:Limit the objects dimensions for 
                          the object circle calculation:
                          <b>EMP_v_LimitShapePointGeometry</b> >
}
                          if(Object Length < Object Width) then (Yes)
                            :1}
                            :Exchange width and length and turn the orientation 
                            by 90 degree to assure that the length equals the 
                            long object side.;
                            note left: The actual orientation is not\nrelevant for the object circle calculation)
                          else (No)
                            :2}
                          endif
                          #Orange:Calculate the circles that describes 
                          the front and the rear of the vehicle:
                          <b>EMP_s_CalcScaledObjectCircle</b> >
                          #Orange:Calculate the Distance to trajectory 
                          for the front and the rear circle:
                          <b>EMP_v_CalcDistToTrajCircle</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex:       Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pFrontCircle :      Structure to be filled with the information of the calculated front circle.
  @param[in,out]        pRearCircle :       Structure to be filled with the information of the calculated rear circle.

  @glob_in              @ref ACDC_p_GetObjGeometry \n
                        @ref ACDC_p_GetObjPositions \n
                        @ref ACDC_a_GetObjShapePointQualities \n
                        @ref AIP_i_GetShapePointIdx
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n

  @pre                  ShapePoint Qualities have been calculated by the function @ref AIP_v_CalcShapePointQualities. \n
                        ShapePoint Positions have been calculated by the function @ref AIP_v_CalcGeometryFromShapePoints
  @post                 None

  @InOutCorrelation     
                        - **Formula lateral shift distance:** \n
                          \f$D_{Shift, LatFront} = 0.5 \cdot (Width \cdot (Q_{FrontLeft} - Q_{FrontRight}))\f$ \n
                          \f$D_{Shift, LatRear}  = 0.5 \cdot (Width \cdot (Q_{RearLeft}  - Q_{RearRight} ))\f$
                        - **Formula circle radius:** \n
                          \f$R_{Front}      = 0.5 \cdot (Width \cdot (Q_{FrontLeft} + Q_{FrontRight}))\f$ \n
                          \f$R_{Rear}       = 0.5 \cdot (Width \cdot (Q_{RearLeft}  + Q_{RearRight} ))\f$
                        - **Formula longitudinal shift distance:** \n
                          \f$Q_{Front}            = MAX(Q_{Front,Right},Q_{Front,Left})\f$ \n
                          \f$Q_{Rear}             = MAX(Q_{Rear,Right} ,Q_{Rear,Left} )\f$

  @testmethod          @ref TEST_EMP_V_CALCFRONTANDREARCIRCLEFROMSHAPEPOINTS_001 \n              
                       @ref TEST_EMP_V_CALCFRONTANDREARCIRCLEFROMSHAPEPOINTS_002                                

  @traceability        Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
static void EMP_v_CalcFrontAndRearCircleFromShapePoints(ObjNumber_t        const         iObjectIndex,
                                                        ACDCObjectCircle_t       * const pFrontCircle,
                                                        ACDCObjectCircle_t       * const pRearCircle)
{
  /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
  ACDCGeometry_t         ShapePointGeometry  = *(ACDC_p_GetObjGeometry(iObjectIndex));
  SFLVector2D_t          PosObjCenter        = ACDC_p_GetObjPositions(iObjectIndex)->Center;
  float32   const *const afQualities         = ACDC_a_GetObjShapePointQualities(iObjectIndex);
  sint8                  aiShapePointPositions[EM_GEN_OBJ_N_SHAPE_POINTS] = {0};


  if(ShapePointGeometry.fLength < ShapePointGeometry.fWidth)
  {
    /* If the objects width is bigger than its length, exchange the two values and turn the orientation so 
       the length equals always the objects long side. */
    float32 const tmp                     = ShapePointGeometry.fLength;
    ShapePointGeometry.fLength            = ShapePointGeometry.fWidth;
    ShapePointGeometry.fWidth             = tmp;
    ShapePointGeometry.fOrientation      += CML_Deg2Rad(90.f);
    aiShapePointPositions[SP_FRONT_LEFT ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_LEFT);
    aiShapePointPositions[SP_FRONT_RIGHT] = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_LEFT);
    aiShapePointPositions[SP_REAR_LEFT  ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_RIGHT);
    aiShapePointPositions[SP_REAR_RIGHT ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_RIGHT);
  }
  else
  {
    /* Get the positioning of the Shape Points */
    aiShapePointPositions[SP_FRONT_LEFT ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_LEFT );
    aiShapePointPositions[SP_FRONT_RIGHT] = AIP_i_GetShapePointIdx(iObjectIndex, SP_FRONT_RIGHT);
    aiShapePointPositions[SP_REAR_LEFT  ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_LEFT  );
    aiShapePointPositions[SP_REAR_RIGHT ] = AIP_i_GetShapePointIdx(iObjectIndex, SP_REAR_RIGHT );
  }

  /* Calculate the Circle that describes the front end of the object (scaled according to the shape point qualities) */
  pFrontCircle->Circle = EMP_s_CalcScaledObjectCircle(&PosObjCenter,
                                                      &ShapePointGeometry,
                                                      afQualities[ aiShapePointPositions[SP_FRONT_LEFT ] ] ,
                                                      afQualities[ aiShapePointPositions[SP_FRONT_RIGHT] ] ,
                                                      b_TRUE);

  /* Calculate the Circle that describes the rear end of the object (scaled according to the shape point qualities) */
  pRearCircle->Circle  = EMP_s_CalcScaledObjectCircle(&PosObjCenter,
                                                      &ShapePointGeometry,
                                                      afQualities[ aiShapePointPositions[SP_REAR_LEFT ] ] ,
                                                      afQualities[ aiShapePointPositions[SP_REAR_RIGHT] ] ,
                                                      b_FALSE);

  /* Calculate the dist to traj of the front and the rear circle */
  EMP_v_CalcDistToTrajCircle(pFrontCircle);
  EMP_v_CalcDistToTrajCircle(pRearCircle);

}


/*!@}*/
#endif /*ACDC_CFG_EMP*/

