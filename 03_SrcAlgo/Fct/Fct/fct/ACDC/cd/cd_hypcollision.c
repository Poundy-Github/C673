/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypcollision.c

DESCRIPTION:               Implementation of the collision hypothesis

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/08 11:56:58CEST $

VERSION:                   $Revision: 1.32 $

LEGACY VERSION:            Revision: 2.6

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_COLL_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hypcollision HypCollision
@ingroup cd
    
@brief          The Collision Hypothesis describes a scenario in which a collision in close future 
                (<<1s) is highly probable.\n\n
@description    The only external function of the HypCollision module is @ref CDHypoCollisionMain. It handles 
                the main processing steps of the hypothesis.
@{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */

/*! @brief  Data type for the description of an ellipse*/
typedef struct
{ 
  SFLVector2D_t center; /*!< Center of ellipse */
  float32       fSizeX; /*!< major axis of ellipse */
  float32       fSizeY; /*!< minor of ellipse */
} CDHyp_PosiblePositionArea_t;


/*! @brief Datatype for the representation of the temporal behavior of a position area*/
typedef struct
{

  float32 fSpeedX;  /*!< Movement in x direction. @phys_unit: [m/s] */
  float32 fSpeedY;  /*!< Movement in y direction. @phys_unit: [m/s] */
  float32 fAccelX;  /*!< Acceleration in x direction.@phys_unit: [m/s^2] */
  
  /* growing */
  float32 fAccelGrowX;  /*!< Maximum acceleration in x direction. @phys_unit [m/s^2]*/
  float32 fAccelGrowY;  /*!< Maximum acceleration in y direction. @phys_unit [m/s^2]*/
  
  /* position */
  SFLVector2D_t startPositon;  /*!< start position */
} CDHyp_PositionAreaBehavior_t;   


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoCollisionObjectFilter (ObjNumber_t const iObjectIndex);
static float32 CDHypoCollisionCalculateProb (const CDHyp_PositionAreaBehavior_t* pPAB, float32 fcollisionSize );
static boolean GetYtoXOfPPPA(const CDHyp_PosiblePositionArea_t *pPPA, float32 x, float32 *y);
static boolean GetStartEndTimeCollision(const CDHyp_PosiblePositionArea_t *pPPA, const CDHyp_PositionAreaBehavior_t *pPAB, 
                                       float32* fstarttime, float32* fendtime);
static void CDMovePositionArea (CDHyp_PosiblePositionArea_t *pPPA, const CDHyp_PositionAreaBehavior_t *pPAB, 
                                float32 ftime);

static float32 CDGetObjectWidthSecure(ACDCGeometry_t        const * const pObjDim, 
                                      EM_t_GenObjAttributes const * const  pObjAttr);

/*************************************************************************************************************************
  Functionname:         GetYtoXOfPPPA                                                                                */ /*!

  @brief                Calculate the width y of an ellipse at the position x.

  @description          The function calculates the half width of an ellipse at a given X-position (see formula "Ellipse width").
                        @image html CD_GetYtoXOfPPPA.svg width=1200

  @return               boolean : False if X exceeds the limits of the position area.

  @param[in]            *pPPA : Pointer to the position area
  @param[in]            x :     X-position    @range[0, SizeX of the position area]
  @param[in,out]        *y :    Y-size at X-position

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Pointers are valid
  @post                 None

  @InOutCorrelation     - **Formula Ellipse Width:**\n
                          \f$ 1 = \frac{Y^2}{Y_{max}^2}+\frac{X^2}{X_{max}^2} \f$ \n
                          => \f$ Y = Y_{Max} \cdot \sqrt{1 - (\frac{X}{X_{max}})^2} \f$

  @author               Martin Kallnik

  @testmethod           @ref TEST_GETYTOXOFPPPA_001 \n
                        @ref TEST_GETYTOXOFPPPA_002 \n
						@ref TEST_GETYTOXOFPPPA_003 \n

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static boolean GetYtoXOfPPPA(const CDHyp_PosiblePositionArea_t *pPPA, float32 x, float32 *y)
{
  boolean found;

  if (
         (fABS(x) > pPPA->fSizeX)
       ||(pPPA->fSizeX < C_F32_DELTA)
     )
  {
    found = b_FALSE;
  }
  else
  {
    found = b_TRUE;
    *y= pPPA->fSizeY* SQRT_(1.f-SQR(x / pPPA->fSizeX));
  }
  
  return found;
}

/*************************************************************************************************************************
  Functionname:         GetStartEndTimeCollision                                                                     */ /*!

  @brief                Determines the earliest and latest possible time of collision based on a given position 
                        area and position movement.

  @description          The calculation follows the subsequent steps:
                        @startuml GetStartEndTimeCollision_activity.png
                        start
                          partition "Starttime" {
                          if (Object acceleration is higher\nthan positive assumed acceleration?) then (No)
                            :1}
                            :Calculate earliest possible 
                            time of collision;
                            note left
                              Assumption: Object accelerates 
                              immediately with the assumed 
                              acceleration towards the ego vehicle
                              > see formulas start time 1.+ 2.
                            end note
                          else (Yes)
                            :2}
                            :Calculate earliest time of collision 
                            based on position area center;
                            note left
                              >see formulas start time 3.
                            end note
                          endif
                          }
                          partition "Endtime" {
                          if (Object acceleration is lower\nthan negative assumed acceleration?) then (No)
                            :3}
                            :Calculate latest possible 
                            time of collision;
                            note left
                              Assumption: Object accelerates 
                              immediately with the assumed 
                              acceleration away from the ego vehicle
                              > see formulas end time 1.+ 2.
                            end note
                          else(Yes)
                            :4}
                            :Set latest time of collision 
                            to maximum;
                          endif
                          }
                          :Limit and return results;
                        stop
                        @enduml
                        
  @return               boolean: true if situation must be checked (position area is totally behind ego vehicle front)

  @param[in]            *pPPA :       Pointer to the position area.
  @param[in]            *pPAB :       Pointer to the position area behavior.
  @param[in,out]        fstarttime :  Earliest possible time of collision. @phys_unit [s] @range [0,+...[
  @param[in,out]        fendtime :    Latest possible time of collision. @phys_unit [s] @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     Used symbols: \n
                          \f$ t_{start} = \f$ Earliest possible time of collision. \n
                          \f$ t_{end} = \f$ Latest possible time of collision. \n
                          \f$ A_{assu,x} = \f$ Assumed acceleration that the object can use in (positive and negative) X direction. \n
                          \f$ A_{assu,y} = \f$ Assumed acceleration that the object can use in (positive and negative) Y direction.
                        - **Formulas start time:**
                          1. For discriminant >= 0: \f$t_{start} = \frac{-V_x - \sqrt{V_x^2 - 2 \cdot (A_x-A_{assu,x})\cdot D_x)}}{2 \cdot 0.5 \cdot (A_x - A_{assu,x})}\f$
                          2. For discriminant <  0: \f$t_{start} = \f$ @ref CD_COLL_MAX_TIME
                          3. \f$t_{start} = - \frac{D_x}{V_x}\f$
                        - **Formulas end time:**\n
                          1. For discriminant >= 0: \f$t_{end} = \frac{-V_x + \sqrt{V_x^2-2\cdot (A_x + A_{assu,x})\cdot D_x}}{2 \cdot 0.5 \cdot (A_x + A_{assu,x})} \f$
                          2. For discriminant <  0: \f$t_{end} = - \frac{V_x}{2 \cdot 0.5 \cdot (A_x + A_{assu,x})}\f$

  @todo                 - Review entire function!
                        - change: \n
                        if (pPAB->fSpeedX < C_F32_DELTA)
                        {
                          *fstarttime = CD_COLL_MAX_TIME; 
                        } \n
                        to\n
                        if (pPAB->fSpeedX > -C_F32_DELTA)
                        {
                        *fstarttime = CD_COLL_MAX_TIME; 
                        }
                        -  Secure against division by 0 for: \n
                        *fstarttime = (- pPAB->fSpeedX - SQRT_(fdiscriminant))/ (pPAB->fAccelX - pPAB->fAccelGrowX);

  @author               Martin Kallnik

  @testmethod           @ref TEST_GETSTARTENDTIMECOLLISION_001 \n
                        @ref TEST_GETSTARTENDTIMECOLLISION_002 \n
                        @ref TEST_GETSTARTENDTIMECOLLISION_003 \n
						@ref TEST_GETSTARTENDTIMECOLLISION_004 \n
						@ref TEST_GETSTARTENDTIMECOLLISION_005 \n
						@ref TEST_GETSTARTENDTIMECOLLISION_006 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean GetStartEndTimeCollision(const CDHyp_PosiblePositionArea_t *pPPA, const CDHyp_PositionAreaBehavior_t *pPAB, 
                                       float32* fstarttime, float32* fendtime)
{
  boolean bResult;
  float32 fdiscriminant;

  /* starttime is point of time where positionarea first hits vehicle front */
  /* 0 = distx + RelSpeedX * t + 0.5 (pPAB->fAccelX - pPAB->fAccelGrowX)  * t² */
  /* case a : (pPAB->fAccelX - pPAB->fAccelGrowX) >=0 (unlike but possible -> use only RelSpeedX as estimation)*/
  if ((pPAB->fAccelX - pPAB->fAccelGrowX) > - C_F32_DELTA)
  {
    if (pPAB->fSpeedX < C_F32_DELTA)
    {
      *fstarttime = CD_COLL_MAX_TIME; 
    }
    else
    {
      *fstarttime = - pPPA->center.fX / pPAB->fSpeedX;
    }
  }
  else
  { /* case b: (fObjectAccelX -CD_COLL_EGO_MAX_ACCEL_X_PLUS_LIKE) < 0 -> use right root*/
    fdiscriminant =  SQR(pPAB->fSpeedX)
                   - (2.0f * (pPAB->fAccelX - pPAB->fAccelGrowX) * pPPA->center.fX);/*PRQA S 3121*//*physical constant*/

    if (fdiscriminant < 0.0f)
    { /*should not happen*/
      *fstarttime = CD_COLL_MAX_TIME;
    }   
    else
    {
      *fstarttime = (- pPAB->fSpeedX 
                    - SQRT_(fdiscriminant)
                   )
                   / (pPAB->fAccelX - pPAB->fAccelGrowX);
    }
  }
  
  if (*fstarttime < 0.0f)
  { 
    *fstarttime = 0.0f;
  }

  
  /* endtime is point of time where positionarea first lefts vehicle front */
  /* 0 = distx + RelSpeedX * t + 0.5 (pPAB->fAccelX + pPAB->fAccelGrowX)  * t² */
  /* case a : (pPAB->fAccelX + pPAB->fAccelGrowX) <=0 (unlike but possible -> use maxtime as estimation)*/
  if ((pPAB->fAccelX + pPAB->fAccelGrowX) < C_F32_DELTA)
  {
    *fendtime = CD_COLL_MAX_TIME;
  }
  else
  {
    fdiscriminant =    SQR(pPAB->fSpeedX)
                         - (2.0f * (pPAB->fAccelX + pPAB->fAccelGrowX) * pPPA->center.fX);/*PRQA S 3121*//*physical constant*/

    if (fdiscriminant < 0.0f)
    { /*positin area will not be behind ego vehicle front in total.
         end if collision area upper bound is nearest to ego vehicle front. Finding maximum (-b / 2a)*/
      *fendtime = - (pPAB->fSpeedX) / (pPAB->fAccelX + pPAB->fAccelGrowX);
    }   
    else
    {  
      *fendtime =   (- pPAB->fSpeedX
                    + SQRT_(fdiscriminant)
                   )
                   / (pPAB->fAccelX + pPAB->fAccelGrowX);
    }
  }
  
  
  /* check must be done if:
     - starttime smaller than CD_COLL_MAX_TIME
     - endtime smaller than CD_COLL_MAX_TIME
     - starttime smaller than endtime */
  
  if (  (*fstarttime < CD_COLL_MAX_TIME)
      &&(*fstarttime < *fendtime)
     )
  {
    bResult = b_TRUE;
  }
  else
  {
    bResult = b_FALSE;
  }
  return bResult; 
}

/*************************************************************************************************************************
  Functionname:         CDMovePositionArea                                                                           */ /*!

  @brief                Predicts a given position area up to a given time.

  @description          Predicts a given position area by:
                        1. **Predicting the size:**\n
                          An acceleration is assumed for the object. The size of the position area describes where 
                          the object can be, if it applies this acceleration for the given time.\n
                          The applied formula is "Size Position Area".
                        2. **Predicting the position:**\n
                          The center is predicted by applying the current relative kinematics.
                          The applied formula is "Center Position Area".
                        
  @return               static void

  @param[in,out]        *pPPA : Pointer to the position area.
  @param[in]            *pPAB : Pointer to the position area behavior.
  @param[in]            ftime : @phys_unit [s]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     
                        - **Formula Size Position Area:** \n
                          \f$ Size_{t,X/Y} = \frac{1}{2} \cdot A_{assu,X/Y}\cdot t^2 \f$
                        - **Formula Center Position Area:**\n
                          \f$P_{rel,t,X/Y} = P_{rel,0,X/Y} + V_{rel,0,X/Y}\cdot t+\frac{1}{2}\cdot A_{rel,0,X/Y}\cdot t^2\f$

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDMOVEPOSITIONAREA_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDMovePositionArea (CDHyp_PosiblePositionArea_t *pPPA, const CDHyp_PositionAreaBehavior_t *pPAB, float32 ftime)
{
  float32 ftimeSqr;

  ftimeSqr = SQR (ftime);
  /*TODO: add influence of variances*/
  pPPA->fSizeX = 0.5f * (pPAB->fAccelGrowX) * ftimeSqr;/*PRQA S 3121*//*physical constant*/
  pPPA->fSizeY = 0.5f * (pPAB->fAccelGrowY) * ftimeSqr;/*PRQA S 3121*//*physical constant*/
  

  /* move position area by relatve velocity*/
  pPPA->center.fX =    pPAB->startPositon.fX
                    + (pPAB->fSpeedX * ftime) 
                    + (0.5f * pPAB->fAccelX * ftimeSqr);/*PRQA S 3121*//*physical constant: 0.5*a_x*t^2+v_x*t+t */
  pPPA->center.fY =    pPAB->startPositon.fY
                    + (pPAB->fSpeedY * ftime);                      
}

/*************************************************************************************************************************
  Functionname:         CDGetObjectWidthSecure                                                                       */ /*!

  @brief                Calculates a "secure" width of the object

  @description          The function is used to get a "secure" object size. A small width is secure 
                        (smaller values for collision probability, TTS, ...) and will lead to less false activations. \n
                        The function uses the measured width and the object class. The widths listed in the table limit 
                        the object width if an object has a class confidence of more than @ref CD_OBJ_CLASS_MIN_CONF_WIDTH_SEC.\n
                        If it has less confidence, its secure width is limited to @ref CD_OBJECT_NO_CLASS_WIDTH_SEC.
                        |Class          |Maximum Width                      |
                        |:--------------|:----------------------------------|
                        |Car            | @ref CD_CAR_WIDTH_SEC             |
                        |Truck          | @ref CD_TRUCK_WIDTH_SEC           |
                        |Bicycle        | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Point          | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Motorcycle     | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Pedestrian     | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Wide           | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Unclassified   | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |
                        |Max Diff Types | @ref CD_OBJECT_NO_CLASS_WIDTH_SEC |

  @return               float32: "Secure" width of the object. @phys_unit [m] @range [0,+...[

  @param[in]            *pObjDim : Pointer to the current object dimensions.
  @param[in]            *pObjAttr : Pointer to the object attributes.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDGETOBJECTWIDTHSECURE_001 \n
                        @ref TEST_CDGETOBJECTWIDTHSECURE_002 

  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CDGetObjectWidthSecure(ACDCGeometry_t        const * const pObjDim, 
                                      EM_t_GenObjAttributes const * const  pObjAttr)
{
  float32 fObjectWidth;

  if (pObjAttr->uiClassConfidence > CD_OBJ_CLASS_MIN_CONF_WIDTH_SEC)
  {
    switch (pObjAttr->eClassification)
    {
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_CAR:
        fObjectWidth = MIN_FLOAT(CD_CAR_WIDTH_SEC, pObjDim->fWidth);
        break;
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_TRUCK:
        fObjectWidth = MIN_FLOAT(CD_TRUCK_WIDTH_SEC, pObjDim->fWidth);
        break;
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_POINT:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_PEDESTRIAN:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_MOTORCYCLE:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_BICYCLE:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_WIDE:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_UNCLASSIFIED:
      case (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES:
      default:
        fObjectWidth = MIN_FLOAT(CD_OBJECT_NO_CLASS_WIDTH_SEC, pObjDim->fWidth);
        break;
    }
  }
  else
  { /* object classification not sure, reduce object width to CD_OBJECT_WIDTH_NO_CLASS*/
    fObjectWidth = MIN_FLOAT(pObjDim->fWidth, CD_OBJECT_NO_CLASS_WIDTH_SEC);
  }

  return fObjectWidth;
}

/*************************************************************************************************************************
  Functionname:         CDHypoCollisionObjectFilter                                                                  */ /*!

  @brief                Checks if the object is relevant for the hypothesis collision

  @description          To pass the internal Object filter, objects need to fulfill the following criteria:
                        - The Objects TTC needs to be below threshold.
                        - The Objects TTS needs to be below threshold.
                        - The Objects TTB needs to be below threshold.
                        - The Objects class must not be wide, unless it is stationary or stopped.
                        - The Objects has to be before the vehicle, unless a RunUpMoving, RunUpStationary or \n
                          CutIn Hypothesis were calculated on it in the last cycle
                        - The Objects relative speed has to be negative.
                        - The Object has to be assigned to the ego lane for a certain number of cycles.

  @return               boolean : True if the object is relevant for the collision hypothesis.

  @param[in]            iObjectIndex :        Index of the considered object. @range[0,...]
  @param[in]            *pCurrentObjIntern :  Structure containing all internal information.

  @glob_in              @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref CD_f_GetTTC             \n
                        @ref ACDC_p_GetObjPositions\n
                        @ref CD_f_GetTTBDynAcute     \n
                        @ref CD_f_GetTTSAcute\n
                        @ref ACDC_p_GetObjHypothesisData\n
                        @ref ACDC_p_GetObjStaticEvasionData\n
                        @ref ACDC_p_GetObjMovement
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOCOLLISIONOBJECTFILTER_001 \n
                        @ref TEST_CDHYPOCOLLISIONOBJECTFILTER_002 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_003 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_004 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_005 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_006 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_007 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_008 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_009 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_010 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_011 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_012 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_013 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_014 \n
						@ref TEST_CDHYPOCOLLISIONOBJECTFILTER_015 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoCollisionObjectFilter (ObjNumber_t        const        iObjectIndex)
{
  boolean bReturn;
  /* Get local variables for the given object for quick (and debugable) access */
  EM_t_GenObjAttributes const * const pObjAttribs   = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
  SFLMovement_t         const * const pObjMovRel    = &(ACDC_p_GetObjMovement(iObjectIndex)->Rel);
  CDObj_Hypothesis_t    const * const pObjHypData   = ACDC_p_GetObjHypothesisData(iObjectIndex);
  CDObj_EvasionStatic_t const * const pEvasion      = ACDC_p_GetObjStaticEvasionData(iObjectIndex);
  float32 const fObjDistX                           = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;
  float32 const fTTC_iObjectIndex                   = CD_f_GetTTC(iObjectIndex);
  float32 const fTTBDynAcute_iObjectIndex           = CD_f_GetTTBDynAcute(iObjectIndex);
  float32 const fTTSAcute_iObjectIndex              = CD_f_GetTTSAcute(iObjectIndex);
  
  if (    (    (      fTTC_iObjectIndex                                 <  CD_COLL_TTC_THRES                                                ) /* small TTC*/
            && (      fTTBDynAcute_iObjectIndex                         <  CD_COLL_TTB_TTS_THRES                                            ) /* small TTB pre to get also coll likely situations*/
            && (      fTTSAcute_iObjectIndex                            <  CD_COLL_TTB_TTS_THRES                                            ) ) /* small TTS pre to get also coll likely situations*/
       && (    (      pObjAttribs->eClassification                      != (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_WIDE              )
            || (      pObjAttribs->eDynamicProperty                     == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY)
            || (      pObjAttribs->eDynamicProperty                     == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED   ) )
       && (           fObjDistX                                          > 0.f                                                                )
       && (    (      fObjDistX                                          > CD_COMMON_MIN_DISTX                                              )
            || (      pObjHypData->HypothesisHist.RunUpMoving           == (ubit16_t)1u                                                                )
            || (      pObjHypData->HypothesisHist.RunUpStationary       == (ubit16_t)1u                                                                )
            || (      pObjHypData->HypothesisHist.CutIn                 == (ubit16_t)1u                                                                ) )
       && (           pObjMovRel->Vel.fX                                 <  0.f                                                               )
       && (           pEvasion->TrackAssigned                           >= (uint8) CD_COLL_MIN_TRACK_ASSIGNED                                 ) )
  {
    bReturn = b_TRUE;
  }
  else
  {
    bReturn = b_FALSE;
  }

  return bReturn;
}


/*************************************************************************************************************************
  Functionname:         CDHypoCollisionCalculateProb                                                                 */ /*!

  @brief                Calculates the probability of the collision hypothesis for a certain object.

  @description          The calculation includes various steps:
                        @startuml CDHypcollision_activity.png
                        start
                          #Orange: Move the position area according 
                          to the given prediction:
                          <b>CDMovePositionArea </b> >
                          #Orange:Calculate earliest and latest 
                          possible collision time
                          <b>GetStartEndTimeCollision</b> >
                          if(Start/End-time calculation is valid?) then (Yes)

                            #Orange:Predict Object stepwise from earliest 
                            to latest possible collision time
                            <b>CDMovePositionArea</b> >

                            partition "Execute for each prediction step" {
                               #Orange:Calculate Escape Area:
                               <b>GetYtoXOfPPPA</b> >
                               note left: >see formula "Escape Area"
                            }
                            :Select the biggest of the found escape areas;

                            :Calculate Hypothesis Probability;
                            note left: >see formula "Collision Probability"

                            if(Collision can be avoided by braking?) then (Yes)
                              :1}
                              :Decrease calculated probability;
                              note left: >see formula "Decreased Collision Probability"
                            else(No)
                              :2}
                            endif
                          else(No)
                            :3}
                            :Hypothesis Probability = 0;
                          endif
                        stop
                        @enduml
                        In the first step the latest and the earliest time at which a collision could occur 
                        are calculated. The calculation is based on assumed maximal and minimal \n
                        accelerations of an object (see illustration "Calculation of collision times"). 
                        The resulting time period then is divided in several prediction time steps. \n
                        E.g. if the latest possible collision time is at 1.0 s and the earliest is at 0.45 s, 
                        the time period is 0.55 s. If the number of time steps is 10, one \n
                        prediction step equals 0.055 s. \n
                        @image html CollHypCalcCollTimes.jpg "Calculation of collision times" width=700cm
                        \n
                        The object is now predicted stepwise from the earliest to the latest possible collision 
                        time (see illustration "Creation of position areas"). During each step a so called position \n
                        area is calculated. It describes where a object can be at the predicted time if it accelerates 
                        with maximum possible acceleration. As the maximum possible acceleration is assumed to be \n
                        higher in x-Direction the resulting position areas usually are shaped like ellipses. \n
                        @image html CollHypPosAreas.jpg "Creation of position areas" width=800cm
                        For each position area the intersection with the y-axis of the ego vehicle is calculated. 
                        The distance between the two intersection points is set in relation \n
                        to the collision size (= 0.5* Ego Vehicle Width + 0.5 * Object width) and depicts the 
                        Escape Area (see illustration "Determination of intersection").\n
                        Of all found escape areas the biggest one is chosen. The probability then is calculated by 1 - max(EscapeArea).
                        If the last prediction step shows, that a collision could still be prevented if the object brakes\n
                        with maximum deceleration, the probability is decreased.
                        @image html CD_CollHypIntersection.jpg "Probability Calculation" width=1200cm

  @return               float32 : Probability that an object will collide with the ego vehicle. @range [0,1]

  @param[in]            pPAB :            the behavior of the position area.
  @param[in]            fcollisionSize :  the maximal distance between the object center an the 
                                          ego vehicle center at collision. @phys_unit [m] @range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS 

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     The following symbols are used in the probability calculation: \n
                        \f$ d_{e0} = \f$ X-Position of the Ego vehicle in relation to the ellipse center\n
                        \f$ a_{{assumed}_{x/y}} = \f$ Assumed maximal possible acceleration of an object \n
                        \f$ t_{min/max} = \f$ Earliest / Latest possible collision time \n
                        \f$ Dist_{Collision} = \f$ Ego - Object center distance at which a collision occurs \n
                        \n
                        - **Formula Collision Times:** \n
                          Red: \f$ t_{min}=\frac{-V_{{rel}_x}-\sqrt{V_{{rel}_x}^2-2 \cdot X \cdot (A_{{abs}_x}-A_{{assumed}_x})}}{(A_{{abs}_x}-A_{{assumed}_x})} \f$ \n
                          Green: \f$ t_{max}=\frac{-V_{{rel}_x}-\sqrt{V_{{rel}_x}^2-2 \cdot X \cdot (A_{{abs}_x}-A_{{assumed}_x})}}{(A_{{abs}_x}+A_{{assumed}_x})} \f$
                        - **Formula Escape Area:** \n
                          \f$Width_{Ellipse,X0} = \f$ Width of the position area at the position line X = 0  \n
                          \f$Y_{Left}  = Y_{PosArea} + Width_{PosArea,X0}\f$ \n
                          \f$Y_{Right} = Y_{PosArea} - Width_{PosArea,X0}\f$ \n
                          \f$EscapeArea =  1 - \frac{ (MIN(Y_{Left}, Dist_{Collision}) - MAX(Y_{Right}, -Dist_{Collision}) }{2 \cdot Width_{PosArea,X0}}\f$
                        - **Formula Collision Probability:** \n
                          \f$P_{Coll} = 1 - EscapeArea_{Max}\f$
                        - **Formula Decreased Collision Probability:** \n
                          \f$P_{Coll} = (1 - EscapeArea_{Max}) \cdot \frac{-X_{PosArea}}{Width_{PosArea,X}}\f$

  @author               Martin Kallnik | martin.kallnik@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOCOLLISIONCALCULATEPROB_001 \n
                        @ref TEST_CDHYPOCOLLISIONCALCULATEPROB_002 \n
                        @ref TEST_CDHYPOCOLLISIONCALCULATEPROB_003 \n
						@ref TEST_CDHYPOCOLLISIONCALCULATEPROB_004 \n
						@ref TEST_CDHYPOCOLLISIONCALCULATEPROB_005 \n


  @traceability         Design Decision

*************************************************************************************************************************/
static float32 CDHypoCollisionCalculateProb (const CDHyp_PositionAreaBehavior_t* pPAB, float32 fcollisionSize )
{

  float32 fstarttime;
  float32 fendtime;
 
  float32 fLeftPosition;
  float32 fRightPosition;
  float32 fSizeYatZero;
  
  float32 fEscapeArea;
  float32 fMaxEscapeArea = 0.0f;

  CDHyp_PosiblePositionArea_t positionArea;

  float32 fhypothesisProbability = 0.0f;


  CDMovePositionArea(&positionArea, pPAB, 0.0f);


  if  (GetStartEndTimeCollision(&positionArea,pPAB,&fstarttime,&fendtime) != b_FALSE)
  {
    float32 fcurrenttime = fstarttime;
    float32 ftimestep = MAX(CD_COLL_TIME_STEP_WIDTH, (fendtime - fstarttime) / ((float32) CD_COLL_NUM_SIM_STEPS));
    boolean end = (fcurrenttime <  fendtime)? b_FALSE : b_TRUE;

    while ((end == b_FALSE))
    {

      CDMovePositionArea(&positionArea,pPAB,fcurrenttime);

      /* check if position area intersects with y axis */
      if (GetYtoXOfPPPA(&positionArea,-positionArea.center.fX,&fSizeYatZero) != b_FALSE)
      {
        if (fSizeYatZero > C_F32_DELTA)
        {
          fLeftPosition  = positionArea.center.fY + fSizeYatZero;
          fRightPosition = positionArea.center.fY - fSizeYatZero; 
          
          /*PRQA S 3121 2*//*physical constant*/
          fEscapeArea =  1.0f - (   (MIN_FLOAT(fLeftPosition, fcollisionSize) - MAX_FLOAT(fRightPosition, -fcollisionSize))
                                  / (2.0f * fSizeYatZero)
                                );

          if (fEscapeArea > fMaxEscapeArea)
          {
            fMaxEscapeArea = fEscapeArea;
          }
        }
      }
      if (positionArea.center.fX < -positionArea.fSizeX)
      {
        end = b_TRUE;
      }
      else
      {
        fcurrenttime += ftimestep;
        end = (fcurrenttime <  fendtime)? b_FALSE : b_TRUE;
      }
    }

    /* check if position area is behind ego vehicle front*/
    if (positionArea.center.fX > -positionArea.fSizeX)
    { /* not behind front (in total) -> reduce probability by braking probability
         braking probability:  (size outside)/ size*/
      if (positionArea.center.fX >= 0.0f)
      {
        /* no collision in case of not braking -> collision probability = 0.0*/
        fhypothesisProbability = 0.0f;
      }
      else
      {
        if (positionArea.fSizeX < C_F32_DELTA)
        {
          fhypothesisProbability = 0.0f;
        }
        else
        {
          /*PRQA S 3121 1*//*physical constant*/
          fhypothesisProbability =   ((1.0f - fMaxEscapeArea) * (-positionArea.center.fX)) / positionArea.fSizeX;
        }
      }
    }
    else
    {
      fhypothesisProbability = 1.0f - fMaxEscapeArea;/*PRQA S 3121*//*physical constant*/
    }
  }
  else
  {
    fhypothesisProbability = 0.0f;
  }

  return fhypothesisProbability;
  
}

/*************************************************************************************************************************
  Functionname:         CDHypoCollisionMain                                                                          */ /*!

  @brief                Handles the main processing steps of the collision hypothesis

  @description          Handles the collision hypothesis by executing the main steps for a hypothesis generation:
                          1. Call of the Hypothesis object filter: @ref CDHypoCollisionObjectFilter
                          2. Call of the Hypothesis probability calculation: @ref CDHypoCollisionCalculateProb
                          3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses

                          Additionally to the common three steps, the collision hypothesis contains a check for a collision 
                          unavoidable hypothesis. The calculation process is depicted in the diagram below.
                          @startuml CDHypoCollisionMain_activity.png
                          start
                          #Orange:Check object filter
                          <b>CDHypoCollisionObjectFilter</b> >
                          if(Object filters passed?) then (Yes)
                            :Select hypothesis type **Collision**;
                            #Orange:Initialize hypothesis structure:
                            <b>CDHypCommonInitHypothesisInt</b> >
                            #Orange:Predict ego and object movement:
                            <b>CDPredictMovement</b> >
                            #Orange:Calculate relevant distance for hypothesis
                            probability calculations using:
                            <b>CDGetObjectWidthSecure</b> >
                            #Orange:Calculate the hypothesis probability:
                            <b>CDHypoCollisionCalculateProb</b> >
                            if (Hypothesis probability > Threshold) then (Yes)
                              #Orange:Append the hypothesis to the existing ones:
                              <b>CDHypSelCreateInternalHypotheses</b> >
                              :Select hypothesis type **Collision Unavoidable**;
                              #Orange:Calculate the hypothesis probability:
                              <b>CDHypoCollisionCalculateProb</b> >
                              if (Hypothesis probability > Threshold) then (Yes)
                                :1}
                                #Orange:Append the hypothesis to the existing ones:
                                <b>CDHypSelCreateInternalHypotheses</b> >
                              else(No)
                                :2}
                              endif
                            else(No)
                              :3}
                              :Discard hypothesis;
                            endif
                          else(No)
                            :4}
                            :Discard hypothesis;
                          endif
                          stop
                          @enduml
                        
  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,EM_N_OBJECTS[
  @param[in]            bObjFilterMatched : Flag indicating whether an object matched the external hypothesis object filter.

  @glob_in              @ref CD_s_GetEgoMov\n
                        @ref CD_s_GetObjMov\n
                        @ref ACDC_p_GetEMGenObjAttributes\n
                        @ref ACDC_p_GetObjGeometry
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Martin Kallnik

  @testmethod           @ref TEST_CDHYPOCOLLISIONMAIN_001 \n
                        @ref TEST_CDHYPOCOLLISIONMAIN_002 \n
                        @ref TEST_CDHYPOCOLLISIONMAIN_003 \n
                        @ref TEST_CDHYPOCOLLISIONMAIN_004 \n
						ref TEST_CDHYPOCOLLISIONMAIN_005 \n

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoCollisionMain( ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched)
{
  /*PRQA S 1031 STDSTRUCTINIT*//* 2018-11-16, reviewer: Oliver Brand, Initialization with non standard structures is allowed in ISO C99 */
  CDObj_Hypothesis_t       * const pObjHypData      = ACDC_p_ModObjHypothesisData(iObjectIndex);
  CDIntHypothesis_t                Hypothesis;
  CDMovement_t       const         CDEgoMovement    = CD_s_GetEgoMov();
  CDMovement_t       const         CDAbsObjMovement = CD_s_GetObjMov(iObjectIndex, POS_GEN_OBJECT, KIN_ABS);
  CDHyp_PositionAreaBehavior_t     posAreaBehave;
  float32                          fcollisionSize;
  CDMovement_t                     predObjMovement;
  CDMovement_t                     predEgoMovement;
  CDMovement_t                     histEgoMovement;
  /*PRQA L: STDSTRUCTINIT*/

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CollisionUnavoidable);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Collision);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CollisionUnavoidable);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Collision);

  /* handle only hypothesis relevant objects */
  if( bObjFilterMatched != b_FALSE )
  {
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_COLLISION_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoCollisionObjectFilter(iObjectIndex ) != b_FALSE)
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Collision);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_Collision);

      /* calculate history values for Ego */
      CDPredictMovement(&CDEgoMovement   , &histEgoMovement, -CD_LATENCY_OBJ_ACQUISITION, b_TRUE, b_FALSE);
      /* calculate predicted values for Ego */
      CDPredictMovement(&CDEgoMovement   , &predEgoMovement, CD_LATENCY_FCT2BRAKE, b_TRUE, b_FALSE);
      /* calculate predicted values for Object */
      CDPredictMovement(&CDAbsObjMovement, &predObjMovement, CD_LATENCY_SYSTEM, b_TRUE, b_FALSE);

      /* set values for collision likely*/
      posAreaBehave.fAccelGrowX     = CD_COLL_EGO_MAX_ACCEL_X_LIKE;
      posAreaBehave.fAccelGrowY     = CD_COLL_EGO_MAX_ACCEL_Y_LIKE;
      posAreaBehave.fAccelX         = predObjMovement.fAx;
      /* consider also fAy ? */
      posAreaBehave.fSpeedX         = predObjMovement.fVx - predEgoMovement.fVx;
      posAreaBehave.fSpeedY         = predObjMovement.fVy - predEgoMovement.fVy;
      posAreaBehave.startPositon.fX = predObjMovement.fX - ( predEgoMovement.fX - histEgoMovement.fX );
      posAreaBehave.startPositon.fY = predObjMovement.fY - ( predEgoMovement.fY - histEgoMovement.fY );

      /*PRQA S 3121 2*//*physical constant*/
      fcollisionSize = CD_COLL_EGO_COLL_WIDTH 
        + (0.5f * CDGetObjectWidthSecure(ACDC_p_GetObjGeometry(iObjectIndex), ACDC_p_GetEMGenObjAttributes(iObjectIndex)));
      
      /* calculate Hypothesis probability */
      Hypothesis.fHypothesisProbability = CDHypoCollisionCalculateProb(&posAreaBehave, fcollisionSize);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > 0.0f)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CollisionUnavoidable);
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Collision);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
               
        /* if collision likely check also collision unavoidable */

        /* set hypothesis type */
        Hypothesis.eType = CDHypothesisType_CollisionUnavoidable;
        
        /* set values */
        posAreaBehave.fAccelGrowX     = CD_COLL_EGO_MAX_ACCEL_X_UNAV + CD_COLL_OBJ_MAX_ACCEL_UNAV ;
        posAreaBehave.fAccelGrowY     = CD_COLL_EGO_MAX_ACCEL_Y_UNAV + CD_COLL_OBJ_MAX_ACCEL_UNAV;
        posAreaBehave.fAccelX         = MAX_FLOAT(0.0f,posAreaBehave.fAccelX); /*Allow positive Acceleration*/


        fcollisionSize = CD_COLL_EGO_COLL_WIDTH;

        /* calculate Hypothesis probability */
        Hypothesis.fHypothesisProbability = CDHypoCollisionCalculateProb(&posAreaBehave, fcollisionSize);

        if (Hypothesis.fHypothesisProbability > 0.0f)
        {
          CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CollisionUnavoidable);

          CDHypSelCreateInternalHypotheses(&Hypothesis);
        }
      }
    }
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYP_COLLISION_SINGLE, (uint8)(iObjectIndex));
  } /*bObjFilterMatched != FALSE*/

  /* done */


}

//!@}

#endif  /* #if (CD_USE_COLL_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

