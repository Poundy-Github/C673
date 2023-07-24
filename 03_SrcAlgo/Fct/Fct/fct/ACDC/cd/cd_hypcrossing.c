/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypcrossing.c

DESCRIPTION:               Implementation of the crossing hypothesis

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:41:29CEST $

VERSION:                   $Revision: 1.23 $

LEGACY VERSION:            Revision: 2.4

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_CROSSING_HYPOTHESIS)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_hypcrossing HypCrossing
\ingroup cd

\brief          The Crossing Hypothesis describes scenarios in which an object (no pedestrians) moves laterally 
                towards the ego trajectory.\n\n

\description    The Crossing Hypothesis describes scenarios in which an object (no pedestrians) moves laterally 
                towards the ego trajectory. It provides two external functions:
                - Main function (@ref CDHypoCrossingMain): \n
                  Executes the main handling of the Crossing hypothesis by calling object filter, environment 
                  filter and probability calculation.
                - Initialization function (@ref CDHypCrossingInitInternalData): \n
                  Initializes all data that is stored for the calculation of the crossing hypothesis.

\{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* ****************************************************************
    TYPEDEF ENUM
   **************************************************************** */
/*! @brief  Enum to identify Crossing Hypothesis directions. */
typedef enum 
{
  CD_CROSSING_DIRECTION_LEFT    = 0, /*!< Crossing Hypothesis object is moving to the Left side of ego object   */
  CD_CROSSING_DIRECTION_RIGHT   = 1, /*!< Crossing Hypothesis object is moving to the Right side of ego object   */
  CD_CROSSING_DIRECTION_ALONG   = 2, /*!< Crossing Hypothesis object is moving along with ego object   */
  CD_CROSSING_DIRECTION_TOWARDS = 3  /*!< Crossing Hypothesis object is moving towards ego object   */
} eCDHypCrossingDirection_t;

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief  Holds all information about Crossing Hypothesis internal Object information. */
typedef struct
{
  float32 fLength;                              /*!< Length of the Object. @unit [m]*/
  float32 fWidth;                               /*!< Width of the Object. @unit [m]*/
  float32 fSensorDistOnTraj;                    /*!< Objects DistOnTraj in relation to the Sensor position. @unit [m]*/
  float32 fSensorDistToTraj;                    /*!< Objects DistToTraj in relation to the Sensor position. @unit [m]*/
  float32 fDistX;                               /*!< X Distance of the Object. @unit [m]*/
  float32 fDistY;                               /*!< Y Distance of the Object. @unit [m]*/
  float32 fVAbsOnTraj;                          /*!< Absolute VelOnTraj of the object. @unit [m/s]*/
  float32 fVAbsToTraj;                          /*!< Absolute VelToTraj of the object. @unit [m/s]*/
  float32 fVAbs;                                /*!< Absolute Velocity of the object. @unit [m/s]*/
  float32 fAAbsY;                               /*!< Absolute Acceleration of the object. @unit [m/s^2]*/
  float32 fPsi;                                 /*!< Objects heading in relation to the X-Axis. @unit [rad] */
  uint8   uiProbabilityOfExistence;             /*!< Probability of existence of the object. @range [0,100]*/
  eCDHypCrossingDirection_t  eHeading;          /*!< Heading of the object.*/
  EM_t_GenObjDynamicProperty eDynamicProperty;  /*!< Dynamic property of the object. (e.g. oncoming, stationary,...)*/
  EM_t_GenObjClassification eObjClassification; /*!< Objects classification coming from EM*/
} CDHypCrossingIntObjData_t;

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*Necessary to calculate ref point (1/4pi=45deg)*/
#define CD_CROSSING_45DEG_IN_RAD                   (0.25f*CML_f_Pi)
/*Necessary to calculate ref point (3/4pi=135deg)*/
#define CD_CROSSING_135DEG_IN_RAD                  (0.75f*CML_f_Pi)
/*Necessary to calculate ref point (5/4pi=225deg)*/
#define CD_CROSSING_225DEG_IN_RAD                  (1.25f*CML_f_Pi)
/*Necessary to calculate ref point (7/4pi=315deg)*/
#define CD_CROSSING_315DEG_IN_RAD                  (1.75f*CML_f_Pi)

/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  LOCAL FUNCTIONS
*****************************************************************************/
static void CDHypCrossingFillIntEgoData(ACDCObjDesc_t       *const pIntEgoDataTTM );
static void CDHypCrossingFillIntObjData(ObjNumber_t               const        iObjectIndex, 
                                        CDHypCrossingIntObjData_t       *const pIntObjData, 
                                        ACDCObjDesc_t                   *const pIntObjDataTTM  );
static boolean CDHypCrossingObjectFilter(ACDCObjDesc_t    const *const pIntEgoDataTTM   ,
                                         CDHypCrossingIntObjData_t const *const pIntObjData      ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                                         EM_t_Cust_ObjectData      const *const pCustObject      ,
#endif
                                         const EM_t_GenEbaHypCat                ObjHypCat        ,
                                               boolean                   *const pbCountAsCrossing );
static boolean CDHypCrossingEnvironmentFilter(const ObjNumber_t     iObjectIndex);
static void CDHypCrossingCalcProb(ACDCObjDesc_t        const *const pIntEgoDataTTM   , 
                                  ACDCObjDesc_t        const *const pIntObjDataTTM   , 
                                  ObjNumber_t          const        iObjectIndex     ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                                  EM_t_Cust_ObjectData const *const pCustObject      ,
#endif
                                  float32                    *const pfHypCrossingProb );

/*************************************************************************************************************************
  Functionname:         CDHypCrossingFillIntEgoData                                                                  */ /*!

  @brief                Converts the input and global ego vehicle information into the required format for the TTM calculation.

  @description          Converts the input and global ego vehicle information in the required format
                        (@ref ACDCObjDesc_t) for the TTM calculation.

  @return               void

  @param[in,out]        pIntEgoDataTTM :  Structure containing data required for the TTM calculation.

  @glob_in              @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetEgoMovementObjSync
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com
*************************************************************************************************************************/
static void CDHypCrossingFillIntEgoData(ACDCObjDesc_t       *const pIntEgoDataTTM )
{
  pIntEgoDataTTM->Movement              = *ACDC_p_GetEgoMovementObjSync();
  pIntEgoDataTTM->Movement.Accel.fX     = 0.f;
  pIntEgoDataTTM->Movement.Accel.fY     = 0.f;
  pIntEgoDataTTM->Geometry              = *ACDC_p_GetEgoGeometry();
  pIntEgoDataTTM->ObjectPosCenter.fX    = -(pIntEgoDataTTM->Geometry.fLength/2.f);
  pIntEgoDataTTM->ObjectPosCenter.fY    = 0.f;
}

/*************************************************************************************************************************
  Functionname:         CDHypCrossingFillIntObjData                                                                  */ /*!

  @brief                Converts the input and global object information into the required format for the TTM calculation.

  @description          @startuml CDHypCrossingFillIntObjData_activity.png
                        start
                            :Copy objects kinematic 
                            and geometry information;
                            #Orange:Calculate object center
                            <b>CDCalculationTransformRefPointToCenter</b> >
                            :Calculate absolute 
                            object velocity;
                            note left: >see Formula "Object Velocity"
                            :Calculate object heading;
                            note left: >see Table "Object Heading"
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :    Index of current object. \range [0,+...[
  @param[in,out]        pIntObjData :     Pointer to object data for function to calculate TTM
  @param[in,out]        pIntObjDataTTM :  Pointer to object data of current object

  @glob_in              @ref ACDC_p_GetObjPositions\n
                        @ref ACDC_p_GetACDCObjectMain \n
                        @ref ACDC_p_GetEMGenObj
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Object Velocity**: \n
                          \f$ V_{Obj,abs} = \sqrt{V_{Obj,X}^2+V_{Obj,Y}^2}\f$ \n
                        - **Object Heading**:\n
                          |    Angle    |   Heading  |
                          |:------------|:-----------|
                          |  45 to 135  |    Left    |
                          | -135 to -45 |    Right   |
                          |  -45 to 45  |    Along   |
                          | 135 to -135 |   Towards  |

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com
*************************************************************************************************************************/
static void CDHypCrossingFillIntObjData(ObjNumber_t               const        iObjectIndex, 
                                        CDHypCrossingIntObjData_t       *const pIntObjData, 
                                        ACDCObjDesc_t                   *const pIntObjDataTTM  )
{
  ACDCObjDescMain_t const * const pCurrObj = ACDC_p_GetObjDescMain(iObjectIndex);
  EM_t_GenObject    const * const pEMObj   = ACDC_p_GetEMGenObj(iObjectIndex);
  SFLVector2D_t     const * const pObjPos  = &(ACDC_p_GetObjPositions(iObjectIndex)->GenObject);
  /* Object Data */
  pIntObjData->fDistX                   = pObjPos->fX;
  pIntObjData->fDistY                   = pObjPos->fY;

  pIntObjData->fSensorDistOnTraj        = pObjPos->fX;

  if (fABS(pCurrObj->TrajRelation.fDistToTraj) < ACDC_DIST_DEFAULT)
  {
    pIntObjData->fSensorDistToTraj = pCurrObj->TrajRelation.fDistToTraj;
  }
  else
  {
    pIntObjData->fSensorDistToTraj = pObjPos->fY;
  }


  pIntObjData->fLength                  = pCurrObj->Geometry.fLength;
  pIntObjData->fWidth                   = pCurrObj->Geometry.fWidth;
  pIntObjData->uiProbabilityOfExistence = pEMObj->Qualifiers.uiProbabilityOfExistence;
  pIntObjData->eDynamicProperty         = pEMObj->Attributes.eDynamicProperty;
  pIntObjData->eObjClassification       = pEMObj->Attributes.eClassification;
  pIntObjData->fAAbsY                   = pCurrObj->Movement.Abs.Accel.fY;

  /*TTM Object Data*/
  pIntObjDataTTM->ObjectPosCenter       = pCurrObj->Positions.Center;
  pIntObjDataTTM->Movement.Accel.fX     = 0.f;
  pIntObjDataTTM->Movement.Accel.fY     = 0.f;
  pIntObjDataTTM->Movement.Vel.fX       = pCurrObj->Movement.Abs.Vel.fX;
  pIntObjDataTTM->Movement.Vel.fY       = pCurrObj->Movement.Abs.Vel.fY;
  pIntObjDataTTM->Geometry              = pCurrObj->Geometry;

  /* Derived Object Data */
  pIntObjData->fVAbsOnTraj      = pCurrObj->Movement.Abs.Vel.fX;
  pIntObjData->fVAbsToTraj      = pCurrObj->TrajRelation.fVelocityToTraj;

  pIntObjData->fVAbs            = SQRT(SQR(pIntObjData->fVAbsOnTraj) + SQR(pIntObjData->fVAbsToTraj));
  pIntObjData->fPsi             = ATAN2_(pIntObjData->fVAbsToTraj, pIntObjData->fVAbsOnTraj);

  /* Calc Heading Direction */
  if ((pIntObjData->fPsi >= CD_CROSSING_45DEG_IN_RAD) && (pIntObjData->fPsi <= CD_CROSSING_135DEG_IN_RAD))
  {
    pIntObjData->eHeading = CD_CROSSING_DIRECTION_LEFT;
  }
  else if ((pIntObjData->fPsi <= -CD_CROSSING_45DEG_IN_RAD) && (pIntObjData->fPsi >= -CD_CROSSING_135DEG_IN_RAD))
  {
    pIntObjData->eHeading = CD_CROSSING_DIRECTION_RIGHT;
  }
  else if ((pIntObjData->fPsi >= -CD_CROSSING_45DEG_IN_RAD) && (pIntObjData->fPsi <= CD_CROSSING_45DEG_IN_RAD))
  {
    pIntObjData->eHeading = CD_CROSSING_DIRECTION_ALONG;
  }
  else
  {
    pIntObjData->eHeading = CD_CROSSING_DIRECTION_TOWARDS;
  }
}

/*************************************************************************************************************************
  Functionname:         CDHypCrossingObjectFilter                                                                    */ /*!

  @brief                Checks whether an object is relevant for the crossing hypothesis

  @description          Checks whether an object is relevant for the crossing hypothesis. Additionally the function 
                        checks whether an object is crossing or not.\n
                        To be considered for a crossing hypothesis, an object has to fulfill the following criteria:
                          1.  The object must not have the classes Point, Pedestrian or Unclassified.
                          2.  The object must have a distance above 0.
                          3.  The object must have a probability of existence above a threshold.
                          4.  The object must not have the dynamic property stopped.
                          5.  The objects heading angle has to be between 45 and 135 or between -45 and -135 degree.
                          6.  The objects velocity has to be above a certain threshold.
                          7.  If the object is of class bicycle its velocity has to be above a higher threshold.
                          8   If the object has not the HypCat XING, its VelToTraj has to be above threshold.
                          9.  The objects TTC has to be below threshold.
                          10. The lateral distance to the object has to be below threshold.
                          11. The objects orientation angle has to be below threshold.
                          .
                        To be considered as crossing in the object history, 
                        an object only has to fulfill the first 6 criteria.

  @return               boolean : True if object is relevant for crossing hypothesis

  @param[in]            pIntEgoDataTTM :    Pointer to Ego data for function to test filter conditions.
  @param[in]            pIntObjData :       Pointer to Object data for function to test filter conditions.
  @param[in]            pCustObject :       Customer related object data.
  @param[in]            ObjHypCat :         Hypothesis category of the object.
  @param[out]           pbCountAsCrossing : Flag indicating if an object is seen as crossing.

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com
*************************************************************************************************************************/
static boolean CDHypCrossingObjectFilter(ACDCObjDesc_t             const *const pIntEgoDataTTM   ,
                                         CDHypCrossingIntObjData_t const *const pIntObjData      ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                                         EM_t_Cust_ObjectData      const *const pCustObject      ,
#endif
                                         const EM_t_GenEbaHypCat                ObjHypCat        ,
                                               boolean                   *const pbCountAsCrossing )
{
  boolean bAcceptObj = TRUE;
  *pbCountAsCrossing = TRUE;

  /* Filter Criterion: Object must not be point */
  /*PRQA S 2000 1*/
  if (pIntObjData->eObjClassification == EM_GEN_OBJECT_CLASS_POINT)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object must not be pedestrian */
  /*PRQA S 2000 1*/
  if (pIntObjData->eObjClassification == EM_GEN_OBJECT_CLASS_PEDESTRIAN)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object must not be unclassified */
  /*PRQA S 2000 1*/
  if (pIntObjData->eObjClassification == EM_GEN_OBJECT_CLASS_UNCLASSIFIED)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object must have minimum PoE */
  /*PRQA S 2000 1*/
  if (pIntObjData->uiProbabilityOfExistence < CD_CROSSING_MIN_POE_QUAL)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object has to be in front of us */
  /*PRQA S 2000 1*/
  if (pIntObjData->fSensorDistOnTraj < 0.f)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object must not be stopped object */
  /*PRQA S 2000 1*/
  if (pIntObjData->eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object heading Angle is suggesting a crossing Course */
  /*PRQA S 2000 1*/
  if (((pIntObjData->eHeading == CD_CROSSING_DIRECTION_LEFT) || (pIntObjData->eHeading == CD_CROSSING_DIRECTION_RIGHT)) == FALSE)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object must have velocity */
  /*PRQA S 2000 1*/
  if (fABS(pIntObjData->fVAbs) < CD_CROSSING_MIN_OBJ_VELOCITY)
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Bicycle is only considered with certain velocity (to avoid pedestrians) */
  /*PRQA S 2000 1*/
  if ( ( (pIntObjData->eObjClassification == EM_GEN_OBJECT_CLASS_BICYCLE)
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
    || (pCustObject->eCamClass == EM_GEN_OBJECT_CLASS_BICYCLE) 
    || (pCustObject->eCamClass == EM_GEN_OBJECT_CLASS_PEDESTRIAN) 
#endif
       )
    && (fABS(pIntObjData->fVAbsToTraj) < CD_CROSSING_MIN_BIKE_VELOCITY) )
  {
    bAcceptObj         = FALSE;
    *pbCountAsCrossing = FALSE;
  }

  /* Filter Criterion: Object does not have Crossing HypCat */
  /*PRQA S 2000 1*/
  if ( (fABS(pIntObjData->fVAbsToTraj) < CD_CROSSING_HYP_CAT_VELOCITY_THRESHOLD) 
   &&  (!GET_BIT(ObjHypCat, (EM_t_GenEbaHypCat) FPS_EBA_HYP_CAT_XING)) )
  {
    bAcceptObj = FALSE;
  }

  /* Filter Criterion: Lower Cam Object Acceleration Threshold if ego velocity is high (DecelDetector) */
  /*PRQA S 2000 1*/
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)  
  if (    (pCustObject->eCamClass                          == EM_GEN_OBJECT_CLASS_UNCLASSIFIED         ) 
       && (pCustObject->CamObjectData.cCamConfirmationProb >= CD_CROSSING_CAM_CONFIRMATION_PROB_THRSHLD)
       && (fABS(pIntEgoDataTTM->Movement.Vel.fX)            > CD_CROSSING_EGO_VEL_CAM_ACCEL_THRSHLD    ) 
       && (CML_f_Sign(pIntObjData->fVAbsToTraj)            != CML_f_Sign(pIntObjData->fAAbsY)          )
       && (fABS(pIntObjData->fAAbsY)                        > CD_CROSSING_CAM_ACCEL_THRSHLD            ) )
  {
    bAcceptObj = FALSE;
  }
#endif

  {
    float32 fObjectAngle = ATAN2_(pIntObjData->fDistY, pIntObjData->fDistX);
    float32 fObjectTTC   = CD_TIME_MAX;

    /* Filter Criterion: Object TTC must be below threshold */
    /*PRQA S 2000 1*/
    if (fABS(pIntObjData->fVAbsToTraj) > C_F32_DELTA)
    {
      fObjectTTC   = fABS(pIntObjData->fSensorDistToTraj)/fABS(pIntObjData->fVAbsToTraj);
    }
    /*PRQA S 2000 1*/
    if ( fObjectTTC > CD_CROSSING_OBJECT_TTC_THRSHLD )
    {
      bAcceptObj = FALSE;
    }

    /* Filter Criterion: Object angle must be below threshold */
    /*PRQA S 2000 1*/
    if ( (fABS(fObjectAngle)) > CD_CROSSING_OBJECT_ANGLE_THRSHLD )
    {
      bAcceptObj = FALSE;
    }

    /* Filter Criterion: Lateral object distance has to be below threshold */
    /*PRQA S 2000 1*/
    if ( (fABS(pIntObjData->fDistY)) > CD_CROSSING_OBJECT_DISTY_THRSHLD )
    {
      bAcceptObj = FALSE;
    }
  }

#if (!FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  _PARAM_UNUSED(pIntEgoDataTTM);
#endif

  return bAcceptObj;
}

/*************************************************************************************************************************
  Functionname:         CDHypCrossingEnvironmentFilter                                                               */ /*!

  @brief                Checks whether an object is relevant for the crossing hypothesis under consideration of other objects.

  @description          The Environment Filter discards the object (Object 1) if another object (Object 2) with the following 
                        attributes is in the field of view:
                        - Object 2 has a high probability of existence.
                        - Object 2 has a high EBA quality.
                        - Object 2 is at a shorter distance than Object 1.
                        - Object 2 is within the trajectory of the ego vehicle.

  @return               boolean: True if object is relevant for crossing Hypothesis

  @param[in]            iObjectIndex :  Index of the considered object. \range [0,+...[

  @glob_in              @ref ACDC_p_GetObjPositions\n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetEMGenObjQualifiers 
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Torben Meier | Torben.Meier@continental-corporation.com
*************************************************************************************************************************/
static boolean CDHypCrossingEnvironmentFilter(const ObjNumber_t iObjectIndex)
{
  boolean     bAcceptObj = TRUE;
  ObjNumber_t iCurrObjIdx;
  float32     fCrossObjectDistOnTraj = ACDC_p_GetObjPositions(iObjectIndex)->GenObject.fX;

  for (iCurrObjIdx = 0; iCurrObjIdx < EM_N_OBJECTS; iCurrObjIdx++)
  {
    /*Check if relevant object is in ego trajectory*/
    float32                 const          fCurrObjectDistOnTraj = ACDC_p_GetObjPositions(iCurrObjIdx)->GenObject.fX;
    float32                 const          fCurrObjectDistToTraj = ACDC_p_GetObjPositions(iCurrObjIdx)->GenObject.fY;
    uint8                   const          uiCurrObjectPOE       = ACDC_p_GetEMGenObjQualifiers(iCurrObjIdx)->uiProbabilityOfExistence;
    uint8                   const          uiCurrObjectObjQual   = ACDC_p_GetEMGenObjQualifiers(iCurrObjIdx)->uiEbaObjQuality;
    EM_t_GenObjClassification const        eCurrObjectClass      = ACDC_p_GetEMGenObjAttributes(iCurrObjIdx)->eClassification;
    
    /*PRQA S 2000 1*/
    if (iCurrObjIdx != iObjectIndex)
    {
      /*PRQA S 2000 1*/
      if (    (eCurrObjectClass    != EM_GEN_OBJECT_CLASS_POINT)
           && (uiCurrObjectObjQual >= CD_CROSSING_FILTER_OBJECT_OBJ_QUAL)
           && (uiCurrObjectPOE     >= CD_CROSSING_FILTER_OBJECT_POE_QUAL) )
      {
        /*PRQA S 2000 1*/
        if (    (fCurrObjectDistOnTraj       < fCrossObjectDistOnTraj               )
             && (fABS(fCurrObjectDistToTraj) < CD_CROSSING_FILTER_EGO_CORRIDOR_WIDTH) )
        {
          bAcceptObj = FALSE;
        }
      }
    }
  }

  return bAcceptObj;
}


/*************************************************************************************************************************
  Functionname:         CDHypCrossingCalcProb                                                                        */ /*!

  @brief                Calculates the Crossing Hypothesis Probability for the given Object

  @description          The crossing hypothesis uses the calculation of the time to mitigation (TTM) to determine its probability. 
                        The TTM is the remaining time for the ego vehicle to avoid a imminent collision by a longitudinal actions
                        (more details see @ref CDCalculateTTMLongCore). \n
                        In opposite to the TTB it focuses on lateral collision situations.
                        The probability is calculated via a linear function on base of the TTM.
                        @startuml CDHypCrossingCalcProb_activity.png
                        start
                          #Orange:Calculate TTM of Ego Vehicle and Object:
                          <b>CDCalculateTTMLongCore</b> >
                          note left
                            TTM: Time until Ego or object have to react
                            with de- or acceleration to avoid a collision
                          end note
                          
                          :Set Probability = 1 - TTM;
                          
                          if(Object is within crossing relevant area?) then (Yes)
                            :1}
                            note left
                              DistX > 12m
                              Position withing angle of 27 degree
                            end note
                          else(No)
                            :2}
                            :Set Probability to 0;
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            pIntEgoDataTTM :    Pointer to ego data for function to calculate TTM
  @param[in]            pIntObjDataTTM :    Pointer to object data for function to calculate TTM
  @param[in]            iObjectIndex :      Index of the current object
  @param[in]            pCustObject :       Pointer to receive info about fusion of current object
  @param[out]           pfHypCrossingProb : Probability of the crossing hypothesis\n
                        @ref ACDC_p_ModObjHypothesisData

  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  
  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
static void CDHypCrossingCalcProb(ACDCObjDesc_t        const *const pIntEgoDataTTM   , 
                                  ACDCObjDesc_t        const *const pIntObjDataTTM   ,
                                  ObjNumber_t          const        iObjectIndex     ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                                  EM_t_Cust_ObjectData const *const pCustObject      ,
#endif
                                  float32                    *const pfHypCrossingProb )
{
  float32 fTTMLongObjDecel               = CD_TIME_MAX;
  float32 fTTMLongObjAccel               = CD_TIME_MAX;
  float32 fTTMLongObj                    = CD_TIME_MAX;
  float32 fHypCrossingProbInterp         = 0.f;
  float32 fObjAngleAbs                   = ATAN2_(fABS(pIntObjDataTTM->ObjectPosCenter.fY), pIntObjDataTTM->ObjectPosCenter.fX);
  boolean bCollisionAvoidable            = TRUE;
  CDObj_Hypothesis_t * const pObjHypData = ACDC_p_ModObjHypothesisData(iObjectIndex);

  (void)CDCalculateTTMLongCore( pIntObjDataTTM, pIntEgoDataTTM, CD_CROSSING_MAX_DECELERATION_OBJECT, pIntEgoDataTTM->Movement.Vel.fX, &fTTMLongObjDecel, &bCollisionAvoidable);
  /*PRQA S 2000 1*/
  if (bCollisionAvoidable == FALSE)
  {
    fTTMLongObjDecel = 0.f;
  }
  (void)CDCalculateTTMLongCore( pIntObjDataTTM, pIntEgoDataTTM, CD_CROSSING_MAX_ACCELERATION_OBJECT, pIntEgoDataTTM->Movement.Vel.fX, &fTTMLongObjAccel, &bCollisionAvoidable);

  fTTMLongObj            = MAX_FLOAT(fTTMLongObjDecel, fTTMLongObjAccel); /* * fFactorMitigationEgo; */
  fHypCrossingProbInterp = CML_f_LinearInterpolation( CD_CROSSING_MAX_TTM_INTERP, 1.0f, CD_CROSSING_MIN_TTM_INTERP, 0.f, fTTMLongObj);
                                                    /*TimeMin->HypValMax              , TimeMax->HypValMin           , ActVal*/
  *pfHypCrossingProb     = MINMAX_FLOAT(0.f, 1.0f, fHypCrossingProbInterp);
  
  /*Confirm fused objects (for filter)*/
  /*PRQA S 2000 1*/
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  if ( (pCustObject->eCamClass == EM_GEN_OBJECT_CLASS_UNCLASSIFIED) 
    && (pCustObject->CamObjectData.cCamConfirmationProb > 0u)       )
  {
    pInternalObject->sHypCrossingData.eObjectStatus = CD_CROSSING_OBJECT_CONFIRMED;
  }
#endif
  /*Filter objects that appear within a certain angle and xDist*/
  /*PRQA S 2000 1*/
  if (pObjHypData->sHypCrossingData.eObjectStatus == CD_CROSSING_NO_STATUS)
  {
    if ( (fObjAngleAbs >= CD_CROSSING_MIN_ANGLE) && (pIntObjDataTTM->ObjectPosCenter.fX >= CD_CROSSING_MIN_DISTX) ) 
    {
      pObjHypData->sHypCrossingData.eObjectStatus = CD_CROSSING_OBJECT_VALID;
    }
    else
    {
      pObjHypData->sHypCrossingData.eObjectStatus = CD_CROSSING_OBJECT_INVALID;
    }
  }
  /*Do not consider invalid objects*/
  /*PRQA S 2000 1*/
  if (pObjHypData->sHypCrossingData.eObjectStatus == CD_CROSSING_OBJECT_INVALID)
  {
    *pfHypCrossingProb = 0.f;
  }
}

/*************************************************************************************************************************
  Functionname:         CDHypCrossingInitInternalData                                                                */ /*!

  @brief                Clears the internal data of the calculation of the crossing hypothesis.

  @description          Clears the internal data of the calculation of the crossing hypothesis. The data is stored 
                        in the structure \ref CDInternalObjHypCrossingData_t.
                        \startuml CDHypCrossingInitInternalData_activity.png
                        start
                         :Set ObjectStatus to "Not Crossing";
                         :Set crossing object counter to 0;
                         :Set "Last Seen As Oncoming" to 0;
                        stop
                        \enduml
  @return               void

  @param[in]            iObjectIndex: Object index

  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void CDHypCrossingInitInternalData(ObjNumber_t const iObjectIndex)
{
  CDInternalObjHypCrossingData_t * const pHypCrossingData = &(ACDC_p_ModObjHypothesisData(iObjectIndex)->sHypCrossingData);

  pHypCrossingData->eObjectStatus        = CD_CROSSING_NO_STATUS;
  pHypCrossingData->uiObjCrossingCounter = 0u;
  pHypCrossingData->uiLastSeenAsOncoming = CD_CROSSING_MAX_COUNTER_INT;
}

/*************************************************************************************************************************
  Functionname:         CDHypoCrossingMain                                                                           */ /*!

  @brief                Handles the main steps of the crossing hypothesis calculation.

  @description          The handling of the crossing hypothesis deviates slightly from the standard hypothesis 
                        calculation process that contains only object filter, probability calculation and hypotheses selection. \n
                        In this hypothesis additionally an environment filter is applied and objects that are discarded 
                        by the object filter can also set up a hypothesis if they fulfill certain requirements.\n\n
                        First the function calls two filters:
                        1. **Object Filter**: \n
                        Checks whether an object fulfills certain conditions. (see \ref CDHypCrossingObjectFilter)
                        2. **Environment Filter**:
                        Considers the object within its environment. It approves whether any other object is located in the 
                        ego trajectory before the considered object. Such an object would inhibit a collision 
                        (see \ref CDHypCrossingEnvironmentFilter)\n\n
                        .
                        If the object passes both filters, its actual probability for the hypothesis is calculated 
                        (see \ref CDHypCrossingCalcProb). If it is above a threshold, a new hypothesis is set up and \n
                        appended to the current hypothesis list (see \ref CDHypSelCreateInternalHypotheses).
                        After this the oncoming and the crossing counter are handled. \n
                        Concluding the probability is calculated for objects that are not crossing in this cycle, 
                        but were during the past cycles.
                        @startuml CDHypoCrossingMain_activity.png
                        start
                          #Orange:Hypothesis PreProcessing:
                          <b>CDHypCommonMapFPSToEBAObjClass</b>
                          <b>CDHypCrossingFillIntEgoData</b>
                          <b>CDHypCrossingFillIntObjData</b> >
                          note left
                            1. Map FPS to EBA class
                            2. Fill structure for TTM calculation
                          end note
                          #Orange:Check object filter:
                          <b>CDHypCrossingObjectFilter</b> >
                          #Orange:Check environment filter
                          <b>CDHypCrossingEnvironmentFilter</b> >
                          note right
                            Looks for other cars driving closely ahead 
                            of the ego vehicle. They would prevent a 
                            collision with a crossing object.
                          end note

                          if(All filters are matched) then (Yes)
                            #Orange:Calculate probability for crossing hypothesis:
                            <b>CDHypCrossingCalcProb</b> >
                            if(Hypothesis Probability > Threshold) then (Yes)
                              :1}
                              #Orange:Call hypotheses selection:
                              <b>CDHypSelCreateInternalHypotheses</b> >
                            else(No)
                              :2}
                            endif
                          else(No)
                            :3}
                          endif
                          
                          :Handle oncoming and 
                          crossing counter;
                          note left
                          **Oncoming**:
                          __De__crease if object was seen 
                          as oncoming, __In__crease if not
                          **Crossing**:
                          __In__crease if object was seen
                          as crossing, __De__crease if not
                          end note
                          
                          :Recalculate probability for objects 
                          that changed Dynamic from crossing 
                          to stationary:
                          <b>CDHypCrossingCalcProb</b> >
                          if(Hypothesis Probability > Threshold) then (Yes)
                            :4}
                            #Orange:Call hypotheses selection:
                            <b>CDHypSelCreateInternalHypotheses</b> >
                          else(No)
                            :5}
                          endif
                          
                        stop
                        @enduml


  @return               void

  @param[in]            iObjectIndex :      Index of the considered object. \range [0,+...[
  @param[in]            bObjFilterMatched : Flag indicating whether a object matched the external hypothesis object filter or not.
  
  @glob_in              @ref ACDC_p_GetEMCustObjList\n
                        @ref ACDC_p_GetEMGenObj\n
                        @ref ACDC_p_GetObjStaticEvasionData\n
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION \n
                        @ref CD_USE_EM_FPS_OBJCLASS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CROSSING_HYPOTHESIS

  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @todo                 Change name of uiLastSeenAsOncoming to uiLastSeenAsNotOncoming

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void CDHypoCrossingMain( ObjNumber_t const   iObjectIndex, 
                         boolean     const   bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;

  boolean bWasCrossingConfirmed       = FALSE;
  boolean bCountAsCrossing            = FALSE;
  CDObj_Hypothesis_t * const pObjHypData = ACDC_p_ModObjHypothesisData(iObjectIndex);
  
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
  const EM_t_Cust_ObjectData const * const pCustObject = &(ACDC_p_GetEMCustObjList()->CustObjects)[iObjectIndex];
#endif

  ACDCObjDesc_t    sIntEgoDataTTM;
  ACDCObjDesc_t    sIntObjDataTTM;
  CDHypCrossingIntObjData_t sIntObjData;
  boolean bCrossingObjectFilterMatched      = FALSE;
  boolean bCrossingEnvironmentFilterMatched = FALSE;
  EM_t_GenEbaHypCat ObjHypCat = ACDC_p_GetEMGenObj(iObjectIndex)->Qualifiers.eEbaHypCat;

  CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_Crossing);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Crossing);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Crossing);

  /* Default Hypothesis Prob Calculation calling */

  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart, ACDC_RTA_CD_HYP_CROSSING_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */

  CDHypCrossingFillIntEgoData(&sIntEgoDataTTM );
  CDHypCrossingFillIntObjData(iObjectIndex, &sIntObjData, &sIntObjDataTTM );

  bCrossingObjectFilterMatched      = CDHypCrossingObjectFilter(&sIntEgoDataTTM  ,
                                                                &sIntObjData     ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                                                                pCustObject      ,
#endif
                                                                ObjHypCat        , 
                                                                &bCountAsCrossing );
  bCrossingEnvironmentFilterMatched = CDHypCrossingEnvironmentFilter(iObjectIndex);
  /*PRQA S 2000 1*/
  if ( (bCrossingObjectFilterMatched != FALSE) && (bCrossingEnvironmentFilterMatched != FALSE) && (bObjFilterMatched != FALSE) )
  {
    /* Default Hypothesis handling */
    CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_Crossing);
    CDHypCrossingCalcProb(&sIntEgoDataTTM                     ,
                          &sIntObjDataTTM                     ,
                          iObjectIndex                        ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)                     
                          pCustObject                         ,
#endif
                          &(Hypothesis.fHypothesisProbability) );
                          
    bWasCrossingConfirmed = TRUE;

    /* store hypothesis (if relevant) */
    /*PRQA S 2000 1*/
    if (Hypothesis.fHypothesisProbability > CD_CROSSING_ACTIVE_THRESHOLD)
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Crossing);
      CDHypSelCreateInternalHypotheses(&Hypothesis);
    }
  }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_HYP_CROSSING_SINGLE, (uint8)(iObjectIndex));
  /*Check oncoming condition*/
  {
    boolean bObjIsOncoming = (boolean)(sIntObjData.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING);
    if (bObjIsOncoming != FALSE)
    {
      pObjHypData->sHypCrossingData.uiLastSeenAsOncoming = 0u;
    }
    else
    {
      /*PRQA S 2000 1*/
      if (pObjHypData->sHypCrossingData.uiLastSeenAsOncoming < CD_CROSSING_MAX_COUNTER_INT)
      {
        pObjHypData->sHypCrossingData.uiLastSeenAsOncoming++;
      }
    }
  }

  /*Check crossing condition for objects stopped in trajectory*/
  if ( (bCountAsCrossing != FALSE) && (bCrossingEnvironmentFilterMatched != FALSE) && (bObjFilterMatched != FALSE) )
  {
    /*PRQA S 2000 1*/
    if (pObjHypData->sHypCrossingData.uiObjCrossingCounter < CD_CROSSING_MAX_COUNTER_INT)
    {
      pObjHypData->sHypCrossingData.uiObjCrossingCounter += CD_CROSSING_COUNTER_INCREASE;
    }
  }
  else
  {
    /*PRQA S 2000 1*/
    if (pObjHypData->sHypCrossingData.uiObjCrossingCounter > 0u)
    {
      pObjHypData->sHypCrossingData.uiObjCrossingCounter--;
    }
  }

  {
    /*PRQA S 4304 9*/
    boolean bObjWasCrossing         = (boolean)(pObjHypData->sHypCrossingData.uiObjCrossingCounter > CD_CROSSING_WASCROSSING_COUNTER_THRESHOLD);
    boolean bObjNotHandledByMainHyp = (boolean)(Hypothesis.fHypothesisProbability <= CD_CROSSING_ACTIVE_THRESHOLD);
    boolean bObjIsStoppedNow        = (boolean)(sIntObjData.eDynamicProperty == EM_GEN_OBJECT_DYN_PROPERTY_STOPPED);
    boolean bObjNotOncomming        = (boolean)(pObjHypData->sHypCrossingData.uiLastSeenAsOncoming > CD_CROSSING_NEEDED_ONCOMMING_CONFIRMATIONS);
    boolean bObjIsTrackAssigned     = (boolean)(ACDC_p_GetObjStaticEvasionData(iObjectIndex)->TrackAssigned > (uint8)CD_CROSSING_STOPPED_OBJ_TRACK_ASSIGNED);
    boolean bObjNotPedestrian       = (boolean)(sIntObjData.eObjClassification != EM_GEN_OBJECT_CLASS_PEDESTRIAN);
    boolean bObjNotPoint            = (boolean)(sIntObjData.eObjClassification != EM_GEN_OBJECT_CLASS_POINT);
    boolean bObjNotUnclassified     = (boolean)(sIntObjData.eObjClassification != EM_GEN_OBJECT_CLASS_UNCLASSIFIED);
    boolean bObjMinPOEok            = (boolean)(sIntObjData.uiProbabilityOfExistence > CD_CROSSING_MIN_POE_QUAL);

    /*PRQA S 2000 1*/
    if ( (bObjWasCrossing         != FALSE) &&
         (bObjNotHandledByMainHyp != FALSE) &&
         (bObjIsStoppedNow        != FALSE) &&
         (bObjNotOncomming        != FALSE) &&
         (bObjIsTrackAssigned     != FALSE) &&
         (bObjNotPedestrian       != FALSE) &&
         (bObjNotPoint            != FALSE) &&
         (bObjNotUnclassified     != FALSE) &&
         (bObjMinPOEok            != FALSE) )
    {
      CDHypCrossingCalcProb(&sIntEgoDataTTM                     ,
                            &sIntObjDataTTM                     ,
                            iObjectIndex                        ,
#if (FCT_CFG_EBA_2ND_SENSOR_CONFIRMATION)
                            pCustObject                         ,
#endif
                            &(Hypothesis.fHypothesisProbability) );
      /*PRQA S 2000 1*/
      if (Hypothesis.fHypothesisProbability > CD_CROSSING_ACTIVE_THRESHOLD)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_Crossing);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
      }
    }
  }
  
  if (bWasCrossingConfirmed != FALSE)
  {
    pObjHypData->HypothesisHist.WasCrossing = 1u;
  }
  else
  {
    pObjHypData->HypothesisHist.WasCrossing = 0u;
  }
}

/**\}*/
#endif  /* #if (CD_USE_CROSSING_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */
/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

