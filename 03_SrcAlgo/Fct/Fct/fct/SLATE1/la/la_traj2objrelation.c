/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_LA (Lane Association)

PACKAGENAME:               la_traj2objrelation.c

DESCRIPTION:               Calculation of object relation to ACC trajectory which along-with 
                           other criteria determines object association to ego/adjacent lane

AUTHOR:                    Norman Apel

CREATION DATE:             02.11.2009

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.1.1.3

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "la.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup la_traj2objrelation Trajectory to object relation
@ingroup la
@brief         Calculation of object relation to ACC trajectory which along-with 
                           other criteria which determines object association to diffrent lanes.  \n\n

@{

*/
/*****************************************************************************
  MODULGLOBALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULGLOBALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE SYMBOLISCHE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE MAKROS
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE KONSTANTEN
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  MODULLOKALE VARIABLEN
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/* Default value of Inlap variance */
#define LA_INLAP_SMALL_VARIANCE_DEFAULT                        (0.001f)

/* Object angle thresholds for strong curve */
#define LA_INLAP_SP_STRONG_CURVE                               (0.005f)

/* Object angle thresholds for medium strong curve */
#define LA_INLAP_SP_MILD_CURVE                                 (0.001f)

/* Object orientation standard dev factor for shape point plausibilization */
#define LA_INLAP_SP_OBJ_ORNT_STDV_MARGIN_FACT                  (2.5f)

/* Object angle forty five degrees */
#define LA_INLAP_ANGLE_FORTY_FIVE                              (45.0f)

/* Object angle one hundred thirty five degrees */
#define LA_INLAP_ANGLE_HUNDRED_THIRTY_FIVE                     (135.0f)

/* Object angle one hundred eighty degrees */
#define LA_INLAP_ANGLE_HUNDRED_EIGHTY                          (180.0f)

/* Index zero used to access Shape Point array */
#define LA_INLAP_INDEX_ZERO                                    (0u)

/* Index one used to access Shape Point array */
#define LA_INLAP_INDEX_ONE                                     (1u)

/* Index two used to access Shape Point array */
#define LA_INLAP_INDEX_TWO                                     (2u)

/* Index three used to access Shape Point array */
#define LA_INLAP_INDEX_THREE                                   (3u)

/* Object class confidence for shape point plausibilization */
#define LA_MIN_CLASS_CONFIDNCE_FOR_SHAPEPOINT                  (90u)

/* Object long distance for shape point plausibilization */
#define LA_MIN_LONG_DIST_FOR_SHAPEPOINT                        (25.0f)

/* Min object width for shape point plausibilization */
#define LA_INLAP_SP_VALID_OBJECT_WIDTH_FOR_ARSOBJ_CLASS_POINT  (0.8f)

/* Difference of angles between an Object and Trajectory w.r.t the object
   to establish if object is parallel to trajectory @unit radian, current threshold is equal to ~10 degree */
#define LA_ANGLE_DIFF_FOR_OBJECT_TRAJECTORY_PARALLELISM 0.174533f

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION DECLARATION
*****************************************************************************/
#if (FCT_CFG_COURSE_PREDICTION)
static void LA_v_CalculateObjectReference(ObjNumber_t iObj, CP_t_TrajectoryData const *pTrajData, 
  CAL_t_TrajRefPoint *pTrajRefPoint, CAL_t_TrajRefPoint *pTrajLastCycRefPoint, 
  CAL_t_TrajRefPoint *pTrajRefPointLastCycle);
#endif /* FCT_CFG_COURSE_PREDICTION */

#if (LA_CFG_USE_SHAPEPOINT_WITH_INLAP)
static float32 LA_f_GetTrajectoryAngleAtObject( float32 f_ShapePointCordXRear,float32 f_ShapePointCordYRear,float32 f_ShapePointCordXFront,
                                                float32 f_ShapePointCordYFront);

static boolean LA_b_FindRelevantShapePoint(ObjNumber_t iObj,const float32 f_ShapePointsCordsX[EM_GEN_OBJ_N_SHAPE_POINTS],
                                                const float32 f_ShapePointsCordsY[EM_GEN_OBJ_N_SHAPE_POINTS],
                                                const float32 f_ObjOrientation, uint8 *p_IdxFirstRelvShapePoint, 
                                                uint8 *p_IdxSecRelvShapePoint);
#endif /* LA_CFG_USE_SHAPEPOINT_WITH_INLAP */

/*************************************************************************************************************************
  Functionname:    LA_v_CalculateInlap                                                                                 */ /*!

  @brief           Calculates the Inlap value, Inlap variance, Inlap Probability of the object. These parameters are used for Lane association.

  @description     Calculates the Inlap value of the object with respect to ego lane. 
                   Inlap is the distance between border of the corridor to the inner edge of the object. It is calculated in two ways, first with
                   ObjectWidth and Trajectory Width and secornd with location of ShapePoints. If ShapePoints are valid then It replaces the value 
                   calculated by Object Width based menthod.

                   Description of parameters are the following:
                   pDistanceWidth->fObjectWidth     : width of the object based on the object classification.
                          For Car    : 1.8m
                          For truck  : 2.5m
                          For Others : 0.8m
                      pDistanceWidth->fTrajectoryWidth : width of the Corridor.
                      pDistanceWidth->fDistance        : Distance between center of the corridor and the center of the object.
                   Calculation of Inlap value is: InLap = (ObjectWidth/2) + (TrajectoryWidth/2) - (Distance)

                   Shape point based Inlap calculation:
                       Object center is calculated from the y coordinates of Front edge of Object. This center is compared with the center
                       of trace brackets. Based on its location ( on left side or right side of center ) :
                       If on right side:
                          Inlap = Left edge of Object - Right Trace Bracket
                       If on left side:
                          Inlap = Left Trace Bracket - Right Edge of Object
                    @startuml 
                    partition LA_v_CalculateInlap {
                    Start
                        - Find the shift in shape point coordinates w.r.t to the orientation of object
                    	- Translate Shape Point Coordinates with fDistX and fDistY
                    	
                    	if(Object's orientation is less than its standard deviation multiply by Object orientation standard dev factor for shape point plausibilization or if Ego vehicle is in strong curve (curvature > 1/200 LA INLAP SHAPE POINT STRONG TRAJECTORY or Absolute Difference b/w Y coordinate of 0th and 3rd Shapepoints is more than width of point objects Object classification confidence is less than or equal to 90 or Long_Displacement is less than or equal to 90) then (yes)
                    	  - Shape Points are not plausible
                    	 else
                          - set the boolean flag if the shapepoints are valid to use or not based its corelation with orientation and closeness with trajectory
                           if(shape points are valid) then (yes)
                             -calculate inlap using shape points
                    	      if(Object is in right lane) then (yes)
                    		   -set  Inlap  to ShapePointsCordsY of IdxFirstRelvShapePoint minus RightBracketPos
                    		  else
                    		   -set  Inlap to LeftBracketPos minus ShapePointsCordsY of IdxFirstRelvShapePoint
                    		  Endif
                               endif
                    	endif
                    	
                    	if(shape points are not valid) then (yes)
                    	 -calculate inlap using ObjectWidth, Trajectory Width and Distance b/w object and trajectory
                    	endif
                    	-Calculation of Inlap Variance. Since there is no variance of shape point available as of now, for shape point case also variance of Inlap is calculated with Object Width, Trajectory width and distance
                    	if (variance is very less)then (yes)
                          -make it small non zero
                          endif
                                        
                    End
                    }
                    @enduml

  @return          void

  @param[in]       pDistanceWidth : Pointer to structure of type LADistanceWidth_t, defined in cp_ext.h
                        pDistanceWidth->fObjectWidth : width of the object based on the object classification.           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                          For Example,  Car    : SI_OBJ_WIDTH_CAR_MOVE [ Defined in la_par.h]
                                        truck  : SI_OBJ_WIDTH_TRUCK    [ Defined in la_par.h]
                        pDistanceWidth->fObjectWidthVar : variance of fObjectWidth.                                      [full range of data type float32]
                        pDistanceWidth->fDistance : Distance between center of the corridor and the center of the object.[-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pDistanceWidth->fDistanceVar : Variance of fDistance.                                            [full range of data type float32]
                        pDistanceWidth->fTrajectoryWidth : width of the object's Corridor.                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pDistanceWidth->fTrajectoryWidthVar : Variance of fTrajectoryWidth.                              [full range of data type float32]
  @param[in,out]   pInlap : Pointer to structure of type LA_t_TrajInlap, defined in cp_ext.h
                        pInlap->fInlap       : Inlap value of the object.                                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pInlap->fInlapVar    : Variance of Inlap value.                                                  [full range of data type float32]
                     
  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/12/2016

  @todo            -

  @author          Christopher Knievel | Christopher Knievel@continental-corporation.com | +49-(8382)-9699-399
*************************************************************************************************************************/
void LA_v_CalculateInlap(ObjNumber_t iObj, const LADistanceWidth_t *p_DistanceWidth,const float32 f_LeftBracketPos, const float32 f_RightBracketPos, LA_t_TrajInlap *p_Inlap)
{
  /* Local variables for Object width, Trajectory width (corridor width) and Distance between the center of the corridor and center of the object. These values are updated in Corridor function */
  const float32 f_ObjectWidth    = p_DistanceWidth->fObjectWidth;
  const float32 f_TrajWidth      = p_DistanceWidth->fTrajectoryWidth;
  const float32 f_Distance       = p_DistanceWidth->fDistance;

  /* Local variables for Absolute values of Object width, Trajectory width (corridor width) and Distance between the center of the corridor and center of the object. */
  const float32 f_AbsObjectWidth = fABS(p_DistanceWidth->fObjectWidth);
  const float32 f_AbsTrajWidth   = fABS(p_DistanceWidth->fTrajectoryWidth);
  const float32 f_ABSDistance    = fABS(f_Distance);

  /* Local variables for Variances of Object width, Trajectory width (corridor width) and Distance between the center of the corridor and center of the object. */
  const float32 f_ObjectWidthVar = p_DistanceWidth->fObjectWidthVar;
  const float32 f_TrajWidthVar   = p_DistanceWidth->fTrajectoryWidthVar;
  const float32 f_DistanceVar    = p_DistanceWidth->fDistanceVar;

#if (LA_CFG_USE_SHAPEPOINT_WITH_INLAP == 0)

  _PARAM_UNUSED(f_LeftBracketPos);
  _PARAM_UNUSED(f_RightBracketPos);
  _PARAM_UNUSED(iObj);

#else
  /* flag to hold validity of shape points */
  boolean b_AreShapePointsValid = FALSE;
  uint8 index = 0u;
  
  /* Shape Points of the object */
  float32 f_ShapePointsCordsX[EM_GEN_OBJ_N_SHAPE_POINTS];
  float32 f_ShapePointsCordsY[EM_GEN_OBJ_N_SHAPE_POINTS];

  /* Shape Point coordinates are relative to the Object's Reference point (fDistX, fDistY) coordinates */
  const float32 f_RefPointX = *SLATE_pf_GetObjLongDisp(iObj);
  const float32 f_RefPointY = *SLATE_pf_GetObjLatDisp(iObj);
  
  /* Location to store center of Y coordinate of trace bracket */
  float32 f_BracketCenter;

  /* Location to store center of Y coordinate of the object. This is now the front edge of object as it assists( in comparison to 
  rear end of car in almost  all conditions including early cut in and cut out detection.  */
  float32 f_ObjectCenter;

  /* Indexes to store relevant shape points */
  uint8 u_IdxFirstRelvShapePoint, u_IdxsecRelvShapePoint;

  uint8 u_Shift = 0u;

  uint8 u_IdxLeftFrontPoint = LA_INLAP_INDEX_ZERO;
  uint8 u_IdxRightFrontPoint = LA_INLAP_INDEX_THREE;

  uint8 u_ClassConfidence = SLATE_p_GetEMGenObjAttributes(iObj)->uiClassConfidence;

  float32 f_ObjLongDisp = *pt_LAInput->t_RTE.pf_ObjLongDisp(iObj);
  float32 f_Orientation = pt_LAInput->t_RTE.pf_ObjOrientation(iObj);
  float32 f_OrientationStd = pt_LAInput->t_RTE.pf_ObjOrientationStd(iObj);
  const EM_t_GenObjGeometry* p_GenObjDataGeometry = SLATE_p_GetEMGenObjGeometry(iObj);

  /* Finding the shift in shape point coordinates w.r.t to the orientation of object */
  if((RAD2DEG(f_Orientation) >= LA_INLAP_ANGLE_FORTY_FIVE) &&
    (RAD2DEG(f_Orientation) < LA_INLAP_ANGLE_HUNDRED_THIRTY_FIVE)) /* 45 to 135 degree */
  {
    u_Shift = LA_INLAP_INDEX_THREE;
  }
  else if ((RAD2DEG(f_Orientation) >= LA_INLAP_ANGLE_HUNDRED_THIRTY_FIVE) && 
           (RAD2DEG(f_Orientation) <= LA_INLAP_ANGLE_HUNDRED_EIGHTY)) /* 135 to 180 degree */
  {
    u_Shift = LA_INLAP_INDEX_TWO;
  }
  else if((RAD2DEG(f_Orientation) <= -1*LA_INLAP_ANGLE_FORTY_FIVE) && 
          (RAD2DEG(f_Orientation) >  -1*LA_INLAP_ANGLE_HUNDRED_THIRTY_FIVE)) /* (-45) to (-135) degree */
  {
    u_Shift = LA_INLAP_INDEX_ONE;
  }
  else if ((RAD2DEG(f_Orientation) <= -1*LA_INLAP_ANGLE_HUNDRED_THIRTY_FIVE) && 
           (RAD2DEG(f_Orientation) >= -1*LA_INLAP_ANGLE_HUNDRED_EIGHTY)) /* (-135) to (-180) degree */
  {
    u_Shift = LA_INLAP_INDEX_TWO;
  }
  else
  {
    u_Shift = LA_INLAP_INDEX_ZERO;
  }

  /* Translating Shape Point Coordinates with fDistX and fDistY */
  for( index = 0; index < EM_GEN_OBJ_N_SHAPE_POINTS; index++ )
  {
    f_ShapePointsCordsX[( index + u_Shift ) % EM_GEN_OBJ_N_SHAPE_POINTS] = f_RefPointX + p_GenObjDataGeometry->aShapePointCoordinates[index].fPosX;
    f_ShapePointsCordsY[( index + u_Shift ) % EM_GEN_OBJ_N_SHAPE_POINTS] = f_RefPointY + p_GenObjDataGeometry->aShapePointCoordinates[index].fPosY;
  }
  
  /* Plausibilation of Shape Points - 
      Shape Points are not plausible if Object's orientation is less than its standard deviation * LA_INLAP_SP_OBJ_ORNT_STDV_MARGIN_FACT
      or if Ego vehicle is in strong curve (curvature > 1/200 LA_INLAP_SHAPE_POINT_STRONG_TRAJECTORY) 
      or Absolute Difference b/w Y coordinate of 0th and 3rd Shapepoints should be more than width of point objects
      Object classification confidence : shapepoint co-ordinates depends directly on object classification as object W, H are used for its calculation.
      Long_Displacement : Shape points accuracy drops down for slow moving objects and to avoid critical scenarios, shape points are not used for near 
                      distance objects. To be updated once accuracy of shape points are better.
  */
  if((fABS(f_Orientation) < (f_OrientationStd * LA_INLAP_SP_OBJ_ORNT_STDV_MARGIN_FACT)) 
      || (fABS(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0) > LA_INLAP_SP_STRONG_CURVE) 
      || (fABS(f_ShapePointsCordsY[u_IdxLeftFrontPoint] - f_ShapePointsCordsY[u_IdxRightFrontPoint]) < LA_INLAP_SP_VALID_OBJECT_WIDTH_FOR_ARSOBJ_CLASS_POINT)
      || (u_ClassConfidence <= LA_MIN_CLASS_CONFIDNCE_FOR_SHAPEPOINT)
      || (f_ObjLongDisp <= LA_MIN_LONG_DIST_FOR_SHAPEPOINT)) 
  {
    b_AreShapePointsValid = FALSE;
  }
  else
  {
    /* Based on orientation and position calculate relevant shape points among LeftRear, LeftFront, RightFront or RightRear 
    Also set the boolean flag if the shapepoints are valid to use or not based its corelation with orientation and closeness with trajectory */
    b_AreShapePointsValid = LA_b_FindRelevantShapePoint(iObj,f_ShapePointsCordsX, f_ShapePointsCordsY,f_Orientation,&u_IdxFirstRelvShapePoint,&u_IdxsecRelvShapePoint); 

    /* If shape points are valid, calculate inlap using shape points */
    if( b_AreShapePointsValid == TRUE )
    {
      f_BracketCenter = (f_LeftBracketPos + f_RightBracketPos)/2.0f;

      f_ObjectCenter = (f_ShapePointsCordsY[u_IdxFirstRelvShapePoint] + f_ShapePointsCordsY[u_IdxsecRelvShapePoint])/2.0f;

      /* Object is in right lane */
      if( f_BracketCenter > f_ObjectCenter)
      {
        p_Inlap->fInlap = f_ShapePointsCordsY[u_IdxFirstRelvShapePoint] - f_RightBracketPos;
      }
      else /* Object is in left lane */
      {
        p_Inlap->fInlap = f_LeftBracketPos - f_ShapePointsCordsY[u_IdxsecRelvShapePoint];
      }
    }
  }
#endif

#if (LA_CFG_USE_SHAPEPOINT_WITH_INLAP)
  /* If shape points are not valid, calculate inlap using ObjectWidth, Trajectory Width and Distance b/w object and trajectory */
  if( b_AreShapePointsValid == FALSE)
#endif
  {
    /* for removing the values very near to zero */
    if( (f_AbsTrajWidth < C_F32_DELTA) || (f_AbsObjectWidth < C_F32_DELTA) )
    {
      p_Inlap->fInlap      = LA_INVALID_INLAP;
    }
    else
    {
      /* Calculation of Inlap of the object. Inlap is the distance between border of the corridor to the inner edge of the object */
      p_Inlap->fInlap = (0.5f * f_ObjectWidth) + (0.5f * f_TrajWidth) - f_ABSDistance;
    }
  }
  /*Inlap value cannot be greater than the trajectory width*/
  p_Inlap->fInlap = CML_f_Min(p_Inlap->fInlap, f_TrajWidth);

  /* Calculation of Inlap Variance. Since there is no variance of shape point available as of now, for shape point case also variance of 
  Inlap is calculated with Object Width, Trajectory width and distance*/
  if( (f_AbsTrajWidth < C_F32_DELTA) || (f_AbsObjectWidth < C_F32_DELTA) )
  {
    p_Inlap->fInlapVar   = LA_INVALID_INLAP_VAR;
  }
  else
  {
    p_Inlap->fInlapVar = (0.25f * f_ObjectWidthVar) + (0.25f * f_TrajWidthVar) + (0.5f * f_DistanceVar);
  }

  /* if variance is very less ( close to zero ) make it small non zero */
  if(p_Inlap->fInlapVar < C_F32_DELTA)
  {
    p_Inlap->fInlapVar = LA_INLAP_SMALL_VARIANCE_DEFAULT;
  }

} /* PRQA S 7004 */
  /* date: 2015-10-01, reviewer: Saurabh Pandey, reason : Cyclomatic complexity. Not Safety critical*/

#if (LA_CFG_USE_SHAPEPOINT_WITH_INLAP)
/*************************************************************************************************************************
  Functionname:    LA_b_FindRelevantShapePoint                                                                      */ /*!

  @brief           Select relevant Shape Points and check its validity

  @description     Select ( LeftFront & RightFront )-  If Object is on the right side of trajectory and its orientation is +ve 
                          ( LeftRear & RightRear )  -  If Object is on the right side of trajectory and its orientation is -ve
                          ( LeftFront & RightFront ) - If Object is on the left side of trajectory and its orientation is -ve
                          ( LeftRear & RightRear )   - If Object is on the left side of trajectory and its orientation is +ve 
                   Check sanity of shape point by finding the corelation with orientation and relative closeness of shapeponts 
                   with trajectory
                   @startuml 
                   partition LA_b_FindRelevantShapePoint {
                   Start
                     -Calculate distance of object from trajectory
                     -Select relevant shape points and also verify its sanity
                     if(ego vehicle is moving in curvature ) then (yes)
                       -use rear end shape points
                     elseif( object's angle relative to trajectory angle ( on object ) is very less) then (yes)
                       -take rear end shape point for inlap calculation
                      elseif(Object is on right lane and orientation is +ve) then (yes)
                        -select LeftFront & RightFront
                         if(LeftFront Point is closer to ego vehicle than LeftRear Point) then (yes)
                        -set AreShapePointsValid to true
                   	 endif
                      elseif(Object is on right lane and orientation is +ve) then (yes)
                         -select LeftRear & RightRear
                   	  if(LeftRear Point is closer to ego vehicle than LeftFront Point) then (yes)
                          -set AreShapePointsValid to true
                   	 endif
                      elseif(Object is on left lane and orientation is +ve) then (yes)
                        -select LeftRear & RightRear
                   	 if(RightRear Point is closer to ego vehicle than RightFront Point) then (yes)
                   	  -set AreShapePointsValid to true
                   	 endif
                      elseif(Object is on left lane and orientation is -ve )
                        - select LeftFront & RightFront
                   	 if(RightFront Point is closer to ego vehicle than RightRear Point) then (yes)
                   	   -set AreShapePointsValid to true
                   	 endif
                      else
                      endif	 
                   End
                   }
                   @enduml

  @return          b_AreShapePointsValid : Flag to hold if selected shape points are valid or not                                 [FALSE, TRUE]

  @param[in]       iObj : FCT object ID                                                                                           [0 ... 39]
  @param[in]       f_ShapePointsCordsX[EM_GEN_OBJ_N_SHAPE_POINTS] : Array of floats to hold x cordinates of shape points          [0 ... 5*RW_FCT_MAX]m
  @param[in]       f_ShapePointsCordsY[EM_GEN_OBJ_N_SHAPE_POINTS] : Array of floats to hold y cordinates of shape points          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX]m
  @param[in]       f_ObjOrientation : Orientation of the object                                                                   [-PI ... PI]
  @param[in,out]   p_IdxFirstRelvShapePoint : Pointer to store index of selected shape point                                      [0...3]
  @param[in,out]   p_IdxSecRelvShapePoint : Pointer to store index of selected shape point                                        [0...3]
  @param[in]       p_TrajectoryData :Pointer to structure of type CPTrajectoryData_t, defined in cp_ext.h
                        p_TrajData->Current.fTrajC0 : trajectory C0 parameter value                                               [-1.f ... 1.f]

  @glob_in         OBJ_GET_CP(iObj).TrajDist.TrajDistMeas.Y.f0 : Distance of object from trajectory                               [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SI_CFG_USE_SHAPEPOINT_WITH_INLAP : Configuration switch to enable Shape Point for Inlap Calculation
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         8/25/2016
  @changed         8/25/2016

  @author          Saurabh Pandey | saurabh.pandey-ext@continental-corporation.com | 
*************************************************************************************************************************/
static boolean LA_b_FindRelevantShapePoint(ObjNumber_t iObj,const float32 f_ShapePointsCordsX[EM_GEN_OBJ_N_SHAPE_POINTS],
                                                const float32 f_ShapePointsCordsY[EM_GEN_OBJ_N_SHAPE_POINTS],
                                                const float32 f_ObjOrientation, uint8 *p_IdxFirstRelvShapePoint, 
                                                uint8 *p_IdxSecRelvShapePoint)
{
    /* set this flag after checking sanity of the selected shape point */
  boolean b_AreShapePointsValid = FALSE;
  
  /* define indexes of shape points */
  const uint8 u_IdxLeftRearPoint    = LA_INLAP_INDEX_ZERO;
  const uint8 u_IdxLeftFrontPoint   = LA_INLAP_INDEX_ONE;
  const uint8 u_IdxRightFrontPoint  = LA_INLAP_INDEX_TWO;
  const uint8 u_IdxRightRearPoint   = LA_INLAP_INDEX_THREE;

  float32 f_TrajAngleAtObject = 0.0f;
  
  /* Calculate distance of object from trajectory */
  float32 f_DistFromTrajectory = pt_LAOutput->t_LAObjOutputList[iObj].TrajDist.TrajDistMeas.Y.f0;

  f_TrajAngleAtObject = LA_f_GetTrajectoryAngleAtObject(f_ShapePointsCordsX[LA_INLAP_INDEX_ZERO], f_ShapePointsCordsY[LA_INLAP_INDEX_ZERO],
                                                    f_ShapePointsCordsX[LA_INLAP_INDEX_ONE], f_ShapePointsCordsY[LA_INLAP_INDEX_ONE]);

  /* Select relevant shape points and also verify its sanity */


  /* If ego vehicle is moving in curvature [1/200,1/1000), use rear end shape points */
  if((fABS(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0) > LA_INLAP_SP_MILD_CURVE) && (fABS(pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0) <= LA_INLAP_SP_STRONG_CURVE)) 
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftRearPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightRearPoint;
    b_AreShapePointsValid = TRUE;
  }
  /* For mostly straight road, curvature > 1/1000 and If object's angle relative to trajectory angle ( on object ) is very less(Less than half degree/0.008 radians)
  which implies that object is moving parallel to trajectory take rear end shape point for inlap calculation */
  else if( fABS( f_TrajAngleAtObject - f_ObjOrientation ) < LA_ANGLE_DIFF_FOR_OBJECT_TRAJECTORY_PARALLELISM)
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftRearPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightRearPoint;
    b_AreShapePointsValid = TRUE;
  }
  /* Object is on right lane and orientation is +ve -> Object is moving towards trajectory - select LeftFront & RightFront */
  else if( (f_DistFromTrajectory < 0.0f) && (f_ObjOrientation > 0.0f))
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftFrontPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightFrontPoint;

    /* In this scenario, LeftFront Point would be closer to ego vehicle than LeftRear Point  Note, these points would be -ve */
    if( f_ShapePointsCordsY[u_IdxLeftFrontPoint] > f_ShapePointsCordsY[u_IdxLeftRearPoint])
    {
      b_AreShapePointsValid = TRUE;
    }
  }
  /* Object is on right lane and orientation is -ve -> Object is moving away from trajectory - select LeftRear & RightRear */
  else if ( (f_DistFromTrajectory < 0.0f) && (f_ObjOrientation < 0.0f))
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftRearPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightRearPoint;

    /* In this scenario, LeftRear Point would be closer to ego vehicle than LeftFront Point. Note, these points would be -ve */
    if( f_ShapePointsCordsY[u_IdxLeftRearPoint] > f_ShapePointsCordsY[u_IdxLeftFrontPoint])
    {
      b_AreShapePointsValid = TRUE;
    }
  }
  /* Object is on left lane and orientation is +ve -> Object is moving away from trajectory - select LeftRear & RightRear */
  else if ((f_DistFromTrajectory > 0.0f) && (f_ObjOrientation > 0.0f) )
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftRearPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightRearPoint;

    /* In this scenario, RightRear Point would be closer to ego vehicle than RightFront Point */
    if( f_ShapePointsCordsY[u_IdxRightRearPoint] < f_ShapePointsCordsY[u_IdxRightFrontPoint])
    {
      b_AreShapePointsValid = TRUE;
    }
  }
  /* Object is on left lane and orientation is -ve ->  Object is moving towards trajectory - select LeftFront & RightFront */
  else if ((f_DistFromTrajectory > 0.0f) && (f_ObjOrientation < 0.0f) )
  {
    *p_IdxFirstRelvShapePoint = u_IdxLeftFrontPoint;
    *p_IdxSecRelvShapePoint   = u_IdxRightFrontPoint;

    /* In this scenario, RightFront Point would be closer to ego vehicle than RightRear Point */
    if( f_ShapePointsCordsY[u_IdxRightFrontPoint] < f_ShapePointsCordsY[u_IdxRightRearPoint])
    {
      b_AreShapePointsValid = TRUE;
    }
  }
  else
  {
    /* QAC Error fix */
  }
  return b_AreShapePointsValid;
}

/*************************************************************************************************************************
  Functionname:    LA_f_GetTrajectoryAngleAtObject                                                                  */ /*!

  @brief           Calculate Trajectory Angle with reference to given Object 

  @description     Given that Object is rigid body, based on Object's reference points on trajectory calculate angle.

                    * Trajectory 
                     *
                      *                     _______
                       * <------------------\      \ Object Left Side, Front End ( fShapePointCordXFront, float32 fShapePointCordYFront )
                        *                    \      \
                         *                    \      \
                          * <------------------\______\ Object Left Side, Rear End ( fShapePointCordXRear, float32 fShapePointCordYRear )
                           *
                           *
                           *
                           *
                           * Trajectory

                    @startuml 
                    partition LA_f_GetTrajectoryAngleAtObject {
                    Start
                      -Calculate reference point on trajectory with respect to object rear end Shape points
                      -Calculate reference point on trajectory with respect to object front end Shape points
                      -Check for divide by zero scenario though it is highly unlikely given the object will have some lenght
                      -Derivative of trajectory at Reference point for rear end of object
                      - Derivative of trajectory at Reference point for front end of object
                      -Average of the above angles 
                      - Update the angle to be returned
                    End
                    }
                    @enduml

  @return          f_TrajAngleAtObject : Trajectory's angle with respect to object

  @param[in]       f_ShapePointCordXRear : Left Side, Object's Rear-end Shape Point X Coorinate
  @param[in]       f_ShapePointCordYRear : Left Side, Object's Rear-end Shape Point Y Coorinate
  @param[in]       f_ShapePointCordXFront : Left Side, Object's Front-end Shape Point X Coorinate
  @param[in]       f_ShapePointCordYFront : Left Side, Object's Front-end Shape Point Y Coorinate

  @param[in]       p_TrajectoryData :Pointer to structure of type CPTrajectoryData_t, defined in cp_ext.h
                        p_TrajData->Current.fTrajC0 : trajectory C0 parameter value                                      [-1.f ... 1.f]
                        p_TrajData->Current.fTrajC1 : trajectory C1 parameter value                                      [-1.f ... 1.f]

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   SI_CFG_USE_SHAPEPOINT_WITH_INLAP : Configuration switch to enable Shape Point for Inlap Calculation
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         8/26/2016
  @changed         8/26/2016

  @author          Saurabh Pandey | saurabh.pandey-ext@continental-corporation.com | 
*************************************************************************************************************************/

static float32 LA_f_GetTrajectoryAngleAtObject( float32 f_ShapePointCordXRear,float32 f_ShapePointCordYRear,
                                                 float32 f_ShapePointCordXFront, float32 f_ShapePointCordYFront)
{
  CAL_t_TrajRefPoint TrajRefPoint_Rear, TrajRefPoint_Front;
  float32 f_TrajAngleAtObject = 0.0f;

  float32 f_TrajAngle_Rear = 0.0f;
  float32 f_TrajAngle_Front = 0.0f;
  float32 f_AvgAngle = 0.0f;

  /* Calculate reference point on trajectory with respect to object rear end Shape points */
  TrajRefPoint_Rear = CAL_t_CalculateDistancePoint2Clothoid(f_ShapePointCordXRear, f_ShapePointCordYRear, 
                                                        pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0, pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1);

  /* Calculate reference point on trajectory with respect to object front end Shape points */
  TrajRefPoint_Front = CAL_t_CalculateDistancePoint2Clothoid(f_ShapePointCordXFront,f_ShapePointCordYFront,
                                                         pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0, pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1);

  /* Check for divide by zero scenario though it is highly unlikely given the object will have some lenght  */
  if(fABS(TrajRefPoint_Front.fX - TrajRefPoint_Rear.fX) > C_F32_DELTA)
  {
    /* Calculate Inverse TAN of the slope TODO Check for ATAN_ module about restriction of argument range*/
    f_TrajAngleAtObject = ATAN_((TrajRefPoint_Front.fY - TrajRefPoint_Rear.fY)/(TrajRefPoint_Front.fX - TrajRefPoint_Rear.fX));
  }

  /* Approximation of clothoide based trajectory is given equation:  [ 1/6*fC1*x^3 + 1/2*fC0*x^2 ] 
     derivative w.r.t. x : 1/2*fC1*x^2 + fC0*x where x is the ref. point on trajectory for the object   */

  /* Derivative of trajectory at Reference point for rear end of object.*/ 
  f_TrajAngle_Rear  = ((0.5f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1 * SQR(TrajRefPoint_Rear.fX))+ pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0 * TrajRefPoint_Rear.fX );
  
  /* Derivative of trajectory at Reference point for front end of object */
  f_TrajAngle_Front = ((0.5f * pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC1 * SQR(TrajRefPoint_Front.fX))+ pt_LAInput->t_CP.pt_TrajectoryData->Current.fTrajC0 * TrajRefPoint_Front.fX );
  
  /* Average of the above angles */
  f_AvgAngle = (f_TrajAngle_Rear + f_TrajAngle_Front + f_TrajAngleAtObject)/3.0f;

  /* Update the angle to be returned */
  f_TrajAngleAtObject = f_AvgAngle;

  return f_TrajAngleAtObject;
}

#endif /* LA_CFG_USE_SHAPEPOINT_WITH_INLAP */

/*************************************************************************************************************************
  Functionname:    LA_v_InitObjDist2Traj                                                                               */ /*!

  @brief           Init distance filter with measured distance

  @description     Initializes the kalman Matrices and distance to the trajectory params.
                                                                          

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------
                    @startuml
                    partition LA_v_InitObjDist2Traj {
                    Start
                      -Initializes the kalman Matrices and distance to the trajectory params
                      
                    End
                    }
                    @enduml

  @return          void

  @param[in]       pObjDist2TrajMeas : Pointer to structure of type CPObjDist2Traj_tMeas, defined in cp_ext.h
  @param[in,out]   pObjDist2TrajDist : Pointer to structure of type LAObjDist2Traj_t, defined in cp_ext.h
                        pObjDist2TrajDist->TrajDistFilt     pointer to structure type CPTrajDistKalmanData_t, defined in cp_ext.h
                        pObjDist2TrajDist->TrajDistMeas.Y.f0                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistMeas.Y.f1                     [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistMeas.R.f00                    [full range of data type float32]
                        pObjDist2TrajDist->ObjDistOnTraj                         [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistGradRel                       [full range of data type float32]
                        pObjDist2TrajDist->TrajDistGradAbs                       [full range of data type float32]

  @glob_in         -
  @glob_out        -

  @c_switch_part   FCT_SIMU : Switch for simulation purpose.
  @c_switch_part   LA_CFG_DIST2TRAJ_EM : Configuration switch for disabling Kalman filter
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/12/2016

  @todo            -

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
void LA_v_InitObjDist2Traj(const CPObjDist2Traj_tMeas * pObjDist2TrajMeas , LAObjDist2Traj_t *pObjDist2TrajDist)
{
#if (!LA_CFG_DIST2TRAJ_EM)
  LA_v_KalmanInit( pObjDist2TrajMeas , &pObjDist2TrajDist->TrajDistFilt );
#endif

  /*Initialization of the below fields was done in LA_v_KalmanInit */
  pObjDist2TrajDist->TrajDistFilt.P.f00 = pObjDist2TrajMeas->R.f00;
  pObjDist2TrajDist->TrajDistFilt.X.f0 = pObjDist2TrajMeas->Y.f0;
  pObjDist2TrajDist->TrajDistFilt.P.f00 = pObjDist2TrajMeas->R.f00;
  pObjDist2TrajDist->TrajDistFilt.P.f01 = 0.0F;
  pObjDist2TrajDist->TrajDistFilt.P.f11 = SQR(LA_MAX_VREL);  /* max expected lateral speed */

  /* Initialization of the below fields was not present in ARS300, and strictly speaking
  is not necessary (since these fields will be automatically filled with new measurement
  value when an object realy exists) */
  pObjDist2TrajDist->TrajDistMeas.Y.f0  = 0.0f;
#ifdef FCT_SIMU
  pObjDist2TrajDist->TrajDistMeas.Y.f1  = 0.0f;
#endif
  pObjDist2TrajDist->TrajDistMeas.R.f00 = 0.0f;

  /* Initialization of the dist on trajectory field also not necessary in theory, but it's
  better to have a well-defined initial state */
  pObjDist2TrajDist->ObjDistOnTraj  = 0.0f;

#ifdef FCT_SIMU
  /* Initialization of these variables wouldn't be strictly necessary either, since when
  an object is marked 'NEW' (OBJ_MAINTENANCE_STATE(iObj) == EM_GEN_OBJECT_MT_STATE_NEW), then it gets
  reset */
  pObjDist2TrajDist->TrajDistGradRel  = 0.0f;
  pObjDist2TrajDist->TrajDistGradAbs  = 0.0f;
#endif
}

#if ((LA_CFG_DIST2TRAJ_EM) && (FCT_CFG_COURSE_PREDICTION)) /* LA_CFG_DIST2TRAJ_EM == 1*/
/*************************************************************************************************************************
  Functionname:    CPUpdateObjDist2Traj                                                                             */ /*!

  @brief           Updates the Distance to Trajectory structure.

  @description     Determines the object distance to trajectory using object dynamics from EM.
                                                                          

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------
                    @startuml 
                    partition CPUpdateObjDist2Traj {
                    Start
                      partition LA_v_CalculateObjectReference{
                       -call LA_v_CalculateObjectReference function
                      }
                      -calculate time to reference point
                      if(ego velocity is greater than C F32 DELTA) then (yes)
                        -calculate ego angle at reference point
                    	-calculate Y vector of ego at reference point
                    	-calculate projection on ego Y vector for object velocity
                       else
                        -set velocity to trajectory to 0
                       endif
                       - store variance 
                       -store measured distance to trajectory at object
                       -ObjDistOnTraj and fDistOnTraj refer to center of gravity of ego vehicle
                      
                    End
                    }
                    @enduml

  @return          void

  @param[in]       iObj : Object Number (Object ID)                                                   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fMaxAccelDist2Traj : Assumed maximal relative Acceleration of Object to Trajecory  [-100.0f ... 100.0f] m/s^2
  @param[in]       pTrajData : Trajectory representation, Pointer to structure of type CP_t_TrajectoryData, defined in cp_ext.h
  @param[in,out]   pObjDist2TrajDist : pointer to Distance Filter private Data, Pointer to structure of type LAObjDist2Traj_t, defined in cp_ext.h
                        pObjDist2TrajDist->TrajDistMeas.Y.f1                                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistFilt.X.f1                                          [-330.f ... +330.f] m^-1
                        pObjDist2TrajDist->TrajDistFilt.P.f00                                         [full range of data type float32]
                        pObjDist2TrajDist->TrajDistFilt.P.f11                                         [full range of data type float32]
                        pObjDist2TrajDist->TrajDistMeas.Y.f0                                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistMeas.R.f00                                         [full range of data type float32]
                        pObjDist2TrajDist->ObjDistOnTraj                                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_in         pt_LAInput->t_RTE.pf_EgoVelObjSync                                                               [-330.f ... 330.f] m/s
  @glob_in         SLATE_f_GetEgoYawRateObjSync() : ego yaw rate                                               [-100.f ... 100.f]
  @glob_in         OBJ_KINEMATIC(iObj).fVrelY                                                         [-330.f ... 330.f] m/s
  @glob_in         OBJ_KINEMATIC(iObj).fDistYStd                                                      [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         OBJ_KINEMATIC(iObj).fVrelYStd                                                      [-330.f ... 330.f] m/s
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp   _VAR(iObj)                                                     [full range of data type float32]
  @glob_in         EgoYDirRef.f0                                                                      [-1.0 ... +1.0]
  @glob_in         EgoYDirRef.f1                                                                      [-1.0 ... +1.0]
  @glob_out        -

  @c_switch_part   FCT_SIMU : Switch for simulation purpose.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_DIST2TRAJ_EM : Configuration switch to use EM kinematics instead of Kalman calculation for Dist2Traj.
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure CP sub-component of FCT

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/12/2016

  @todo            !!!!
                   This function is temporarily renamed to the old prefix structure (with SI) due to compatibility issues with 
                   EBA. Several files in EBA are using this function. Once FCT400 code is completely restructured (including
                   input/output variables), this function as well as the EBA file have to be updated.
                   !!!!


  @author          Christian Gutmann,  christian.gutmann@conti-engineering.com
*************************************************************************************************************************/
void CPUpdateObjDist2Traj(const ObjNumber_t iObj , const float32 fMaxAccelDist2Traj , CP_t_TrajectoryData const *pTrajData , LAObjDist2Traj_t *pObjDist2TrajDist)
{
  CAL_t_TrajRefPoint TrajRefPoint, TrajLastCycRefPoint, TrajRefPointLastCycle;
#ifdef FCT_SIMU
  LA_t_TrajDistKalmanMeas ObjDistMeas;
#endif
  float32 fTime2Ref;
  float32 fAngleRef;
  float32 fEgoVelObjSync;
  CML_t_Vector2D EgoYDirRef;
  float32 fVel2Traj, fObjVrelX, fObjVrelY;
  float32 f_ObjDistYStd, f_ObjVrelYStd;
  _PARAM_UNUSED(fMaxAccelDist2Traj);

  fObjVrelX = *SLATE_pf_GetObjVrelX(iObj);
  fObjVrelY = *SLATE_pf_GetObjVrelY(iObj);

  LA_v_CalculateObjectReference(iObj , pTrajData , &TrajRefPoint , &TrajLastCycRefPoint , &TrajRefPointLastCycle); 

  /* calculate time to reference point */
  fEgoVelObjSync = fABS(*pt_LAInput->t_RTE.pf_EgoVelObjSync);
  if (fEgoVelObjSync > C_F32_DELTA)
  {
    fTime2Ref = TrajRefPoint.fDistOnTraj / *pt_LAInput->t_RTE.pf_EgoVelObjSync;
    /* calculate ego angle at reference point */
    fAngleRef = SLATE_f_GetEgoYawRateObjSync() * fTime2Ref;
    /* calculate Y vector of ego at reference point */
    EgoYDirRef.f0 = -SIN_(fAngleRef);
    EgoYDirRef.f1 = COS_(fAngleRef);
    /* calculate projection on ego Y vector for object velocity */
    fVel2Traj = (EgoYDirRef.f0 * fObjVrelX) + (EgoYDirRef.f1 * fObjVrelY);
  }
  else
  {
    fVel2Traj = 0.0f;
  }
#ifdef FCT_SIMU
  ObjDistMeas.Y.f1 = fVel2Traj;
  pObjDist2TrajDist->TrajDistMeas.Y.f1 = fVel2Traj;
#endif
  pObjDist2TrajDist->TrajDistFilt.X.f1 = fVel2Traj;
  
  /* store variance */
  f_ObjDistYStd = *SLATE_pf_GetObjDistYStd(iObj);
  f_ObjVrelYStd = *SLATE_pf_GetObjVrelYStd(iObj);
  pObjDist2TrajDist->TrajDistFilt.P.f00 = SQR(f_ObjDistYStd);
  pObjDist2TrajDist->TrajDistFilt.P.f11 = SQR(f_ObjVrelYStd);
  
  /*store measured distance to trajectory at object*/
  pObjDist2TrajDist->TrajDistMeas.Y.f0  = TrajRefPoint.fDistToTraj;
  pObjDist2TrajDist->TrajDistMeas.R.f00 = SLATE_f_GetObjDistYVar(iObj);

  /*ObjDistOnTraj and fDistOnTraj refer to center of gravity of ego vehicle!!!*/
  pObjDist2TrajDist->ObjDistOnTraj = TrajRefPoint.fDistOnTraj;

}
#if (!LA_CFG_DIST2TRAJ_EM)
/*************************************************************************************************************************
  Functionname:    CPUpdateObjDist2Traj                                                                             */ /*!

  @brief           Updates the Distance to Trajectory structure.

  @description     Determines the object distance to trajectory using Kalman filtering.
                                                                          

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------
                    @startuml 
                    partition CPUpdateObjDist2Traj {
                    Start
                     partition LA_v_CalculateObjectReference{
                      -call LA_v_CalculateObjectReference function
                     }
                      -determine model error matrix
                      -control of Q Matrix if RefPoint moved since last cycle
                      partition LA_v_KalmanFiltering{
                      -determine filtered distance to trajectory at object
                      }
                      -calculate 2 diffrent fast TrajDistGradients for performance comparation
                      -store measured distance to trajectory at object
                      -ObjDistOnTraj and fDistOnTraj refer to center of gravity of ego vehicle
                    End
                    }
                    @enduml

  @return          void

  @param[in]       iObj : Object Number (Object ID)                                                   [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       fMaxAccelDist2Traj : Assumed maximal relative Acceleration of Object to Trajecory  [-100.0f ... 100.0f] m/s^2
  @param[in]       pTrajData : Trajectory representation, Pointer to structure of type CP_t_TrajectoryData, defined in cp_ext.h
  @param[in,out]   pObjDist2TrajDist : pointer to Distance Filter private Data, Pointer to structure of type LAObjDist2Traj_t, defined in cp_ext.h
                        pObjDist2TrajDist->TrajDistMeas.Y.f0                                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistMeas.R.f00                                         [full range of data type float32]
                        pObjDist2TrajDist->ObjDistOnTraj                                              [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m
                        pObjDist2TrajDist->TrajDistGradRel                                            [full range of data type float32]
                        pObjDist2TrajDist->TrajDistGradAbs                                            [full range of data type float32]

  @glob_in         SLATE_f_GetObjDistYVar(iObj)                                                     [full range of data type float32]
  @glob_in         SLATE_f_GetCPCycleTime()                                                                      [type fTime_t, defined in Rte_Type.h]
  @glob_in         SLATE_b_GetObjIsNew(iObj)                                                                   [0 or 1]
  @glob_out        -

  @c_switch_part   FCT_SIMU : Switch for simulation purpose.
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component
  @c_switch_full   LA_CFG_DIST2TRAJ_EM : Configuration switch for disabling Kalman filter

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/12/2016

  @todo            initial version

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
void CPUpdateObjDist2Traj(const ObjNumber_t iObj , const float32 fMaxAccelDist2Traj , CP_t_TrajectoryData const *pTrajData , LAObjDist2Traj_t *pObjDist2TrajDist)
{
  GDBSymMatrix2_t  Q;
  LA_t_TrajDistKalmanMeas ObjDistMeas;
  float32 fCycleTime;
  float32 fCycleTimeInv;
  CAL_t_TrajRefPoint TrajRefPoint, TrajLastCycRefPoint, TrajRefPointLastCycle;
  float32 RefPosVar;
  float32 RefSpeedVar;
  fCycleTime = SLATE_f_GetCPCycleTime();
  fCycleTimeInv = (1.f / fCycleTime);

  LA_v_CalculateObjectReference(iObj , pTrajData , &TrajRefPoint , &TrajLastCycRefPoint , &TrajRefPointLastCycle); 

  /*determine model error matrix*/
  Q.f11 = SQR(fCycleTime) * SQR( fMaxAccelDist2Traj * ( 1.0F / 3.0F));
  Q.f00 = Q.f11 * fCycleTime * 0.5F;
  Q.f01 = 0.0F;
  /* control of Q Matrix if RefPoint moved since last cycle */
  RefPosVar   = SQR(TrajRefPoint.fX-TrajLastCycRefPoint.fX)+SQR(TrajRefPoint.fY-TrajLastCycRefPoint.fY);
  RefSpeedVar = RefPosVar * SQR(fCycleTimeInv);
  Q.f00+=RefPosVar;
  Q.f11+=RefSpeedVar;

  ObjDistMeas.Y.f0             = TrajRefPoint.fDistToTraj;
#ifdef FCT_SIMU
  ObjDistMeas.Y.f1             = TrajRefPoint.fDistToTraj-TrajRefPointLastCycle.fDistToTraj;
#endif
  /* @todo should be Sum of Variances of RefPoint and Object in Normal Direction */
  ObjDistMeas.R.f00            = SLATE_f_GetObjDistYVar(iObj);

  /*determine filtered distance to trajectory at object*/
  LA_v_KalmanFiltering ( iObj, &ObjDistMeas, &Q , fCycleTime , &pObjDist2TrajDist->TrajDistFilt );

#ifdef FCT_SIMU /*calculate 2 diffrent fast TrajDistGradients for performance comparation*/
  if ( SLATE_b_GetObjIsNew(iObj)) /* functional change with introducing the macro!! state MERGE_NEW was not considered before!!  */
  {
    pObjDist2TrajDist->TrajDistGradRel = 0.0F;
    pObjDist2TrajDist->TrajDistGradAbs = 0.0F;
  }
  else
  {
    pObjDist2TrajDist->TrajDistGradRel = GDB_FILTER( ((ObjDistMeas.Y.f0-pObjDist2TrajDist->TrajDistMeas.Y.f0)*fCycleTimeInv)  , pObjDist2TrajDist->TrajDistGradRel , 5.0F );
    pObjDist2TrajDist->TrajDistGradAbs = GDB_FILTER( ((ObjDistMeas.Y.f1)*fCycleTimeInv)  , pObjDist2TrajDist->TrajDistGradAbs , 5.0F );
  }
#endif

  /*store measured distance to trajectory at object*/
  pObjDist2TrajDist->TrajDistMeas.Y.f0  = ObjDistMeas.Y.f0;
  pObjDist2TrajDist->TrajDistMeas.R.f00 = ObjDistMeas.R.f00;

  /*ObjDistOnTraj and fDistOnTraj refer to center of gravity of ego vehicle!!!*/
  pObjDist2TrajDist->ObjDistOnTraj = TrajRefPoint.fDistOnTraj;

}
#endif /* LA_CFG_DIST2TRAJ_EM*/
#endif /* LA_CFG_DIST2TRAJ_EM && FCT_CFG_COURSE_PREDICTION*/


#if (FCT_CFG_COURSE_PREDICTION)
/*************************************************************************************************************************
  Functionname:    LA_v_CalculateObjectReference                                                                       */ /*!

  @brief           Calculates the object reference.

  @description     Calculates the distance to trajectory of the object for current cycle and updates the corresponding structure for the last cycle.
                                                                          

                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------
                    @startuml 
                    partition LA_v_CalculateObjectReference {
                    Start
                     -Calculates the distance to trajectory of the object for current cycle and updates the corresponding structure for the last cycle
                    End
                    }
                    @enduml

  @return          void

  @param[in]       iObj : Object Number (Object ID)                                                   [0 ... EM_N_OBJECTS-1]
  @param[in]       pTrajData : Trajectory representation, Pointer to structure of type CP_t_TrajectoryData, defined in cp_ext.h 
                        pTrajData->KafiEst.XVec.pdData[]                                              [Full range of float32]
                        pTrajData->State.EgoCourseOnly                                                [type ubit16_t defined in algo_type.h][TRUE,FALSE]
                        pTrajData->LastCycle : pointer to type CP_GDBTrajectoryData, defined in cp_ext.h
  @param[in,out]   *pTrajRefPoint : Pointer to structure of type CAL_t_TrajRefPoint, defined in cp_ext.h 
                        pTrajRefPoint->fX                                                             [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
                        pTrajRefPoint->fY                                                             [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @param[in,out]   *pTrajLastCycRefPoint : Pointer to structure of type CAL_t_TrajRefPoint, defined in cp_ext.h 
  @param[in,out]   *pTrajRefPointLastCycle : Pointer to structure of type CAL_t_TrajRefPoint, defined in cp_ext.h 
                        pTrajRefPointLastCycle->fDistToTraj                                           [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
                        pTrajRefPointLastCycle->fDistOnTraj                                           [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
                        pTrajRefPointLastCycle->fX                                                    [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
                        pTrajRefPointLastCycle->fY                                                    [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @glob_in         *pt_LAInput->t_RTE.pf_ObjLongDisp                                                                [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @glob_in         *pt_LAInput->t_RTE.pf_ObjLatDisp                                                                  [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         OBJ_LONG_DISPLACEMENT_LAST                                                         [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @glob_in         OBJ_LAT_DISPLACEMENT_LAST                                                          [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m
  @glob_in         FCT_fBumperToCoG                                                                   [-100.f ... 100.f] m
  @glob_out        -

  @c_switch_part   FCT_SIMU : Switch for simulation purpose.
  @c_switch_part   CP_CFG_TRAJECTORY_USE_LAST_OBJ_POS : Configuration switch to enable calculation of last object position in function LA_v_CalculateObjectReference.
  @c_switch_full   FCT_CFG_COURSE_PREDICTION : Switch to configure FCT support for CP sub-component
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/12/2016

  @todo            -

  @author          Norman Apel | norman.apel@continental-corporation.com | +49-(8382)-9699-365
*************************************************************************************************************************/
static void LA_v_CalculateObjectReference(ObjNumber_t iObj, CP_t_TrajectoryData const * pTrajData, 
                                CAL_t_TrajRefPoint *pTrajRefPoint, CAL_t_TrajRefPoint *pTrajLastCycRefPoint, 
                                CAL_t_TrajRefPoint *pTrajRefPointLastCycle)
{
  /* CAUTION!! this function is AutoSAR !!! */
  /*--- (SYMBOLIC) CONSTANTS ---*/

  /*--- VARIABLES ---*/
#ifdef FCT_SIMU
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  CAL_t_TrajRefPoint TrajRefPointCmp;
#endif
#endif

  CP_t_GDBTrajectoryData   CurTraj;
  /*COM2COMlc*/
  const GDBTrafoMatrix2D_t * pBackMat = SLATE_p_GetTrafoMatrix2DCOFBackward();
  /*COF2COG Trafo*/

  float32 fObjDistX          = (*pt_LAInput->t_RTE.pf_ObjLongDisp(iObj)) + FCT_fBumperToCoG;
  float32 fObjDistY          = *pt_LAInput->t_RTE.pf_ObjLatDisp   (iObj);
#if (LA_CFG_TRAJECTORY_USE_LAST_OBJ_POS)
  float32 fObjDistXLastCycle = OBJ_LONG_DISPLACEMENT_LAST(iObj) + FCT_fBumperToCoG;
  float32 fObjDistYLastCycle = OBJ_LAT_DISPLACEMENT_LAST(iObj);
#endif

  pTrajRefPointLastCycle->fDistToTraj = 0.0f;
  pTrajRefPointLastCycle->fDistOnTraj = 0.0f;
  pTrajRefPointLastCycle->fX          = 0.0f;
  pTrajRefPointLastCycle->fY          = 0.0f;

/* PRQA S 0491 3 *//* Date: 2020-04-02, Reviewer:Tejaswini M , Reason:This warning does not have any critical impact on the functionality. */
  CurTraj.fTrajC0     = pTrajData->KafiEst.XVec.pdData[CP_sTRAJ_C0];
  CurTraj.fTrajC1     = pTrajData->KafiEst.XVec.pdData[CP_sTRAJ_C1];
  CurTraj.fTrajAngle  = 0.0f;

  LA_v_CalculateDistance2Traj(fObjDistX, fObjDistY, (boolean) pTrajData->State.EgoCourseOnly, &CurTraj, pTrajRefPoint);

#ifdef FCT_SIMU
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    /* Copy trajectory reference point */
    TrajRefPointCmp = *pTrajRefPoint;
    /*COG2COF Trafo*/
    TrajRefPointCmp.fX-=FCT_fBumperToCoG;
    /* And save for display purposes */
    LA_SET_OBJ_TRAJ_REF_POINT(iObj,TrajRefPointCmp);
#endif
#endif

#if (LA_CFG_TRAJECTORY_USE_LAST_OBJ_POS)
  LA_v_CalculateDistance2Traj(fObjDistXLastCycle, fObjDistYLastCycle, pTrajData->State.EgoCourseOnly, &CurTraj, pTrajRefPointLastCycle);

#ifdef FCT_SIMU
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
    /* Copy trajectory reference point */
    TrajRefPointCmp = *pTrajRefPointLastCycle;
    TrajRefPointCmp.fX-=FCT_fBumperToCoG;
    LA_SET_OBJ_TRAJ_REF_POINT_LAST(iObj,TrajRefPointCmp);
#endif
#endif
#endif
  /*COG2COGlc Trafo*/
  GDBmathTrafoPos2D(pBackMat , &pTrajRefPoint->fX, &pTrajRefPoint->fY);
  GDBmathTrafoPos2D(pBackMat , &fObjDistX, &fObjDistY);

  LA_v_CalculateDistance2Traj(fObjDistX, fObjDistY, (boolean) pTrajData->State.EgoCourseOnly, &pTrajData->LastCycle, pTrajLastCycRefPoint);
}
#endif  /* END IF (FCT_CFG_COURSE_PREDICTION) */

/*************************************************************************************************************************
  Functionname:    LA_v_CalculateDistance2Traj                                                                         */ /*!

  @brief           Get trajectory reference point

  @description      Get the trajectory reference point information for given
                    (fX,fY) point using the passed trajectory


                                X

                                ^
                                |
                                |              AUTOSAR coordinate system
                                |
                      Y  <-------
                    @startuml 
                    partition LA_v_CalculateDistance2Traj {
                    Start
                        -Get the trajectory reference point information for given (fX,fY) point using the passed trajectory
                    End
                    }
                    @enduml

  @return          void

  @param[in]       fX : X coordinate to get trajectory distance of            [-5*RW_FCT_MAX        5*RW_FCT_MAX] m
  @param[in]       fY : Y coordinate to get trajectory distance of            [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m
  @param[in]       bUseEgoCourseOnly : boolean indicating if ego course (C0)shall be only used for calculation      [0 or 1]
  @param[in]       pTrajData : The trajectory object to use
                    pTrajData->fTrajC0               [-1   +1] m^-1
                    pTrajData->fTrajC1               [-1   +1] m^-2
  @param[in,out]   pDist2Traj :The calculated distance to trajectory          [-PI/2*RW_FCT_MAX     PI/2*RW_FCT_MAX] m

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_ACC_LANE_ASSOCIATION : FCT switch for ACC LA (Lane Association) sub-component

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         2/26/2016

  @author          Norman Apel,  norman.apel@contiautomotive.com
*************************************************************************************************************************/
void LA_v_CalculateDistance2Traj(const float32 fX, const float32 fY, const boolean bUseEgoCourseOnly, const CP_t_GDBTrajectoryData * pTrajData, CAL_t_TrajRefPoint * pDist2Traj)
{
  if(bUseEgoCourseOnly != FALSE)
  {
    *pDist2Traj = CAL_t_CalculateDistancePoint2Circle(fX, fY, pTrajData->fTrajC0);
  }
  else
  {
    *pDist2Traj = CAL_t_CalculateDistancePoint2Clothoid(fX, fY, pTrajData->fTrajC0, pTrajData->fTrajC1);
  }
}

/** @} end defgroup */
#endif

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
