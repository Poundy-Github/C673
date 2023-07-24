/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_calculateobjproperties.c

DESCRIPTION:               The calculation of object Properties for CD

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/09/08 11:55:55CEST $

VERSION:                   $Revision: 1.50 $
*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_int.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_calculateobjproperties Calculate Obj Properties
@ingroup cd

@brief          The calculation of commonly required object attributes is done in this module \n\n

@description    Provides functions for the calculation of object attributes that are required commonly for all objects: \n
                  @ref CDCalculateObjectProperties\n
                Additionally provides two Get-Functions to determine an objects Sensor Source respectively its closing velocity. \n
                  @ref CD_f_GetClosingVelocity    \n
                  @ref CD_e_GetSensorSource
@{
*/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/
/*! @brief    Collision Detection TimeToCollide safe time. @unit [s] */
#define CD_CALC_TTC_SAFE_TIME_LONG                    ( 1.f )

#if (CD_USE_TTS_OCCUPY_RECOGNITION)
/*! @brief    Maximal number of the objects for searching objects that could become dangerous for ego vehicle. @unit - */
#define CD_CALCULATION_MAX_NOF_OBJS_FOR_ESCAPE_SEARCH ( 5u )
#endif

#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
/*! @brief    Maximal velocity for keeping high quality life time. @unit [m/s] */
#define CD_MAX_VEL_FOR_KEEP_HIGH_QUALITY_LIFETIME     ( 0.2f )
#endif /* CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS */

/*****************************************************************************
  FUNCTION DECLARATIONS
*****************************************************************************/
static void     CDCalculateClosingVelocity( ObjNumber_t                iObjectIndex,
                                           fVelocity_t          * const pfClosingVelocity );

#if (CD_USE_TTS_OCCUPY_RECOGNITION)
static ObjNumber_t CDFindNextCriticalObjForEvasion (fDistance_t       * const pFreeSpace, 
                                                    CDSide_t    const         eSide,
                                                    ObjNumber_t const         iActObj,
                                                    ObjNumber_t const         iCritObj,
                                                    fDistance_t const         fSafetyOffsetLong );
static void CDCheckTimesLatMovValid       (void);
static ObjNumber_t CDCheckMostCritObj     (void);
static ObjNumber_t CDCheckEscapeObj (fDistance_t const fSafetyOffsetLat,
                                     fDistance_t const fSafetyOffsetLong,
                                     ObjNumber_t const iCritObj,
                                     CDSide_t    const eSide);
static boolean CDCheckEscObjLong (fTime_t     const TTS,
                                  ObjNumber_t const actObj,
                                  ObjNumber_t const critObj,
                                  fDistance_t const fSafetyOffsetLong );
#endif

static void CDAssignTrack(ObjNumber_t iObjectIndex);

#if(CD_USE_TURNINTOVRU_HYPOTHESIS)
static void CD_v_UpdatePSCCollProbHist(ObjNumber_t iObjectIndex);
#endif

#if (CD_USE_HIGH_QUALITY_LIFETIME)
static void CDCalculateHiQualityLifetime  ( ObjNumber_t        const         iObjectIndex);
#endif

#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )
static void CDUpdateSensorSource          ( ObjNumber_t                      iObjectIndex );
#endif
/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDCalculateObjectProperties                                                                  */ /*!

  @brief                Calculates all object criticality information that is needed for every object.

  @description          Calculates all object criticality information that is needed for every object.
                        @startuml CDCalculateObjectProperties_activity.png
                        start
                          partition "Calculate for each object" {
                            if(Object is deleted?) then (No)
                              :1}
                              #Orange:Check whether the object is in the 
                              road corridor of the ego vehicle
                              <b>CDAssignTrack</b> >
                              #Orange:Check whether the object PSC
                              collision probability higher than threshold
                              <b>CD_v_UpdatePSCCollProbHist</b> >
                            else(Yes)
                              :2}
                            endif
                            #Orange:Calculate the high quality lifetime
                            <b>CDCalculateHiQualityLifetime</b> >
                            note left
                              Number of cycles in which the 
                              object has had a high quality
                            end note
                            :Increase oncoming counter;
                            note left
                              Is increased if object 
                              is seen as oncoming
                            end note
                          }
                          #Orange:Update history of ego and object 
                          with latest kinematic information
                          <b>CDUpdateHistory</b> >
                          #Orange:Adapt TTS in case there are obstacles 
                          at the sides of the critical object
                          <b>CDCheckTimesLatMovValid</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            None

  @glob_in              @ref ACDC_p_GetEMGenObjAttributes\n
                        @ref ACDC_b_GetEMGenObjIsDeleted\n
                        @ref ACDC_p_ModObjHypothesisData
  @glob_out             @ref ACDC_p_ModObjHypothesisData

  @c_switch_part        @ref CD_USE_HIGH_QUALITY_LIFETIME      \n
                        @ref CD_USE_GEN_PSC                    \n
                        @ref CD_USE_TTS_OCCUPY_RECOGNITION     \n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Robert Thiel | robert.thiel@continental-corporation.com

  @testmethod           @ref TEST_CDCALCULATEOBJECTPROPERTIES_001 \n
                        @ref TEST_CDCALCULATEOBJECTPROPERTIES_002 
  @traceability         Design Decision

*************************************************************************************************************************/
void CDCalculateObjectProperties(void)
{
  ObjNumber_t  iObjectIndex;
  /* for each object calculate relevant information */
  for(iObjectIndex=0; iObjectIndex < EM_N_OBJECTS; iObjectIndex++)
  {
    EM_t_GenObjAttributes const * const pObjAttribs = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
    CDHypothesisHist_t          * const pHypHist    = &(ACDC_p_ModObjHypothesisData(iObjectIndex)->HypothesisHist);

    if (ACDC_b_GetEMGenObjIsDeleted(iObjectIndex)==b_FALSE)
    {

      /* Send RTA-Start Event for Collision Detection runtime */
      ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_CALCULATE_SINGLE_OBJECT_PROP, (uint8)(iObjectIndex));


      /* Send RTA-Start Event for Collision Detection runtime */
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_CALCULATE_ASSIGN, (uint8)(iObjectIndex));

    /* assign track probability */
#if   ( defined(CD_USE_CUSTOM_TRACK_ASSIGNMENT) && (CD_USE_CUSTOM_TRACK_ASSIGNMENT == SWITCH_ON) )
      CDAssignTrackProbabilityCustom( iObjectIndex);
#else
      CDAssignTrack(iObjectIndex);
#endif
#if(CD_USE_TURNINTOVRU_HYPOTHESIS)
      CD_v_UpdatePSCCollProbHist(iObjectIndex);
#endif
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_CALCULATE_ASSIGN, (uint8)(iObjectIndex));

      /*Calculate sensor source for each object*/
#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )
      CDUpdateSensorSource(iObjectIndex);
#endif

      ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_CALCULATE_SINGLE_OBJECT_PROP, (uint8)(iObjectIndex));
    } /* !OBJ_IS_DELETED(iObjectIndex) */


    /* Send RTA-Start Event for Collision Detection runtime */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_CALCULATE_COMMON, (uint8)(iObjectIndex));
#if (CD_USE_HIGH_QUALITY_LIFETIME)
    CDCalculateHiQualityLifetime(iObjectIndex);
#endif


    /*add information for oncoming objects*/
    if(pObjAttribs->eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING)
    {
      pHypHist->WasOncomming = 1u;
    }
    else if(    (pHypHist->WasOncomming         == (ubit16_t)1u                                                            )
             && (pObjAttribs->eDynamicProperty  == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING) )
    {
      pHypHist->WasOncomming = 0u;
    }
    else
    {
      // no reaction!
    }


      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_CALCULATE_COMMON, (uint8)(iObjectIndex));
  }
#if (CD_USE_GEN_PSC)
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_UPDATE_OBJ_HIST, (uint8)(iObjectIndex));
  CDUpdateHistory();
  ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,    ACDC_RTA_CD_UPDATE_OBJ_HIST, (uint8)(iObjectIndex));
#endif

#if (CD_USE_TTS_OCCUPY_RECOGNITION)
  /* occupy recognition on time TTS ( evasion possibility ) */
  CDCheckTimesLatMovValid();
#endif
}

/*************************************************************************************************************************
  Functionname:         CD_f_GetClosingVelocity                                                                      */ /*!

  @brief                Returns the velocity with which an object is closing up to the ego vehicle.

  @description          The function checks if the closing velocity has been calculated for the current object,
                        if not, @ref CDCalculateClosingVelocity is called. After the calculation the closing velocity
                        is returned. \n
                        The function follows the common steps of a 'Get Function' (see diagram below).
                        \image html CommonGetFunction_activity.png

  @return               float32 : Closing velocity of the considered object. @phys_unit [m/s] @range[0,...]

  @param[in]            iObjectIndex : Index of the object for which the value shall be returned. @range [0,EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetObjEvasionData
  @glob_out             @ref ACDC_p_ModObjEvasionData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Ayman Almalih | Ayman.Almalih@continental-corporation.com

  @testmethod           @ref TEST_CD_F_GETCLOSINGVELOCITY_001\n
                        @ref TEST_CD_F_GETCLOSINGVELOCITY_002

  @traceability         Design Decision
*************************************************************************************************************************/
float32 CD_f_GetClosingVelocity( ObjNumber_t const iObjectIndex)
{
  CDObj_Evasion_t    const * const pEvasion = ACDC_p_GetObjEvasionData(iObjectIndex);
 
  if (pEvasion->ClosingVelocity > CD_CLOSINGVELOCITY_CHECK)
  {
    CDCalculateClosingVelocity( iObjectIndex, &(ACDC_p_ModObjEvasionData(iObjectIndex)->ClosingVelocity));
  }
  return pEvasion->ClosingVelocity;
}

/*************************************************************************************************************************
  Functionname:         CD_e_GetSensorSource                                                                         */ /*!

  @brief                Returns the eSensorSource, a bitfield that indicates by which sensors an object has been detected.

  @description          If the fusion list is not used, the eSensorSource is taken directly from the EM_t_GenObjectList.
                        In case of a fusion list the bitfield eSensorSource is updated by the function 
                        @ref CDUpdateSensorSource for all objects at the beginning of each cycle. It can not be \n
                        calculated in the get function directly as the calculation contains a hysteresis.

  @return               EM_t_GenObjSensorSource

  @param[in]            iObjectIndex :index of the considered object. @range [0,EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetObjQualifier\n
                        @ref ACDC_p_GetEMGenObjGeneral
  @glob_out             None

  @c_switch_part        @ref CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  @ref CDUpdateSensorSource has been called in this cycle
  @post                 None

  @author               Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CD_E_GETSENSORSOURCE_001

  @traceability         Design Decision

*************************************************************************************************************************/
EM_t_GenObjSensorSource CD_e_GetSensorSource( ObjNumber_t const iObjectIndex )
{

#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )
  return ACDC_p_GetObjQualifier(iObjectIndex)->eSensorSource;
#else
  return ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource;
#endif
}

/*************************************************************************************************************************
  Functionname:         CDCalculateClosingVelocity                                                                   */ /*!

  @brief                Calculates closing velocity for current kinematics

  @description          Calculates the closing velocity of the ego vehicle and an object. 
                        It is calculated based on their current kinematics.
                        
                        @startuml CDCalculateClosingVelocity_activity.png
                        start
                        if(Objects TTC is valid?) then (Yes)
                          :1}
                          #Orange:Calculate velocity of Vego at TTC
                          <b>CDCalculateVelocity</b> >
                          note left: 0 if ego stops before TTC
                          
                          #Orange:Calculate velocity of Object at TTC
                          <b>CDCalculateVelocity</b> >
                          note left: 0 if object stops before TTC
                          
                          :Calculate closing velocity, 
                          Limit result to positive values;
                          note left: >see formula "Closing velocity"
                        else(No)
                          :2}
                          :Closing velocity = 0;
                        endif
                        stop
                        @enduml

  @return               

  @param[in]            iObjectIndex :      Index of the object for which the value shall be returned.
  @param[out]           pfClosingVelocity : Calculated closing velocity. @phys_unit [m/s] @range [0,+...[

  @glob_in              @ref CD_s_GetEgoMov \n
                        @ref CD_s_GetObjMov \n
                        @ref CD_f_GetTTC
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 No changes

  @InOutCorrelation     - **Closing velocity:**\n
                          \f$V_{Closing} =V_{Ego,TTC} - V_{Obj,TTC}\f$

  @author               Christian Gutmann | christian.gutmann@conti-engineering.com

  @testmethod           @ref TEST_CDCALCULATECLOSINGVELOCITY_001 \n
                        @ref TEST_CDCALCULATECLOSINGVELOCITY_002

  @traceability         Design Decision

*************************************************************************************************************************/
static void    CDCalculateClosingVelocity( ObjNumber_t                iObjectIndex,
                                           fVelocity_t        * const pfClosingVelocity )
{
  /* local variable(s) */
  fTime_t fTTC;
  fVelocity_t EgoPredictVelocityX;
  fVelocity_t ObjPredictVelocityX;
  fTime_t fTimeEgoStop;
  fTime_t fTimeObjStop;

  /* set default value */
  *pfClosingVelocity = 0.0f;

  /* calculate TTC */
  fTTC = CD_f_GetTTC(iObjectIndex);

  /* calculate closing velocity if TTC is valid */
  if (fTTC < CD_TIME_MAX)
  {
    /*Get the movement properties of Ego and Obj*/
    /*PRQA S 1031 2*//* 2018-06-14, reviewer: Andreas Danner, Initialization with non standard structures is allowed in ISO C99 */
    CDMovement_t const EgoMovement = CD_s_GetEgoMov();
    CDMovement_t const ObjMovement = CD_s_GetObjMov(iObjectIndex, POS_CLOSEST_IN_X, KIN_ABS);

    /* calculate stop time for vehicles */
    (void)CDCalculateVehStopTime(EgoMovement.fVx, EgoMovement.fAx , &fTimeEgoStop);
    (void)CDCalculateVehStopTime(ObjMovement.fVx, ObjMovement.fAx , &fTimeObjStop);

    /* predict ego movement if ego stops before TTC */
    if ( fTimeEgoStop < fTTC)
    {
      EgoPredictVelocityX = 0.0f;
    }
    else
    {
      EgoPredictVelocityX = CDCalculateVelocity(EgoMovement.fVx, EgoMovement.fAx, fTTC);
    }

    /* predict object movement if object stops before TTC */
    if ( fTimeObjStop < fTTC)
    {
      ObjPredictVelocityX = 0.0f;
    }
    else
    {
      ObjPredictVelocityX = CDCalculateVelocity(ObjMovement.fVx, ObjMovement.fAx, fTTC);
    }

    /* closing velocity should always be positive, i.e. EgoPredictVelocityX >= ObjPredictVelocityX */
    *pfClosingVelocity = MAX_FLOAT((EgoPredictVelocityX - ObjPredictVelocityX), 0.0f);
  }
}


#if (CD_USE_TTS_OCCUPY_RECOGNITION)
/*************************************************************************************************************************
  Functionname:         CDCheckTimesLatMovValid                                                                      */ /*!

  @brief                Predicts if the area around the relevant object is free at time from TTS = 0 to TTC = 0 
                        for each side. In this case the TTS for the corresponding side will be overtaken for the critical
                        object.

  @description          Examines the environment of the currently most critical object and corrects its TTS 
                        on base of detected objects in the adjacent lanes (see illustration). 
                        \image html CD_CheckTimesLatMovValid.svg width=1600
                        The function follows the subsequent steps:
                        @startuml CDCheckTimesLatMovValid_activity.png
                        start
                          #Orange:Find most critical object
                          <b>CDCheckMostCritObj</b> >
                          note left: Object with the lowest TTS
                          if(Most critical object is valid?) then (Yes)
                            #Orange:Find left and right escape
                            object of the critical object
                            <b>CDCheckEscapeObj</b> >
                            note left
                              Object to the side of the most critical 
                              object that inhibits an evasion
                            end note
                            if(TTS_(Left) of left escape object < \nTTS_(Left) of critical object?) then (Yes)
                              :1}
                              :Adapt TTS:
                              TTS_(Left) of critical object = 
                              TTS_(Left) of left escape object;
                            else (No)
                              :2}
                            endif
                            if(TTS_(Right) of right escape object < \nTTS_(Right) of critical object?) then (Yes)
                              :3}
                              :Adapt TTS:
                              TTS_(Right) of critical object = 
                              TTS_(Right) of right escape object;
                            else (No)
                              :4}
                            endif
                          else(No)
                            :5}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            void

  @glob_in              @ref ACDC_p_GetEgoGeometry\n
                        @ref ACDC_b_GetEMGenObjIsDeleted \n
                        @ref CD_f_GetTTSPreLeft \n
                        @ref CD_f_GetTTSAcuteLeft \n
                        @ref CD_f_GetLatNecAccelLeft \n
                        @ref CD_f_GetTTSAcuteRight \n
                        @ref CD_f_GetLatNecAccelRight
  @glob_out             @ref ACDC_p_ModObjEvasionData\n
                        @ref ACDC_p_ModObjTTXData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTS_OCCUPY_RECOGNITION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Sebastian Heintz

  @testmethod           @ref TEST_CDCHECKTIMESLATMOVVALID_001

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3673 1*/ /* date: 2017-10-19, reviewer: Wenting Huang, reason: pCritObj isn't const */
static void CDCheckTimesLatMovValid (void)
{
  /* find most critical object */
  ObjNumber_t critObj = CDCheckMostCritObj();

  /* only search for satellite objects and recalc  TTS ( and AnecLat ) in case critical object really exists */
  if (ACDC_b_GetEMGenObjIsDeleted(critObj) == b_FALSE)
  {
    ObjNumber_t   escapeObjL;
    ObjNumber_t   escapeObjR;
    float32       TTSPreLeft_escapeObjL;
    float32       TTSPreLeft_critObj;
    float32       TTSPreRight_escapeObjR;
    float32       TTSPreRight_critObj;
    /* Get Ego dimensions*/
    float32 const fSafetyOffsetLat  = 0.5F * ACDC_p_GetEgoGeometry()->fWidth;
    float32 const fSafetyOffsetLong = 0.5F * ACDC_p_GetEgoGeometry()->fLength;

    /* Get local pointer to critical object */
    CDObj_Evasion_t    * const pEvasion = ACDC_p_ModObjEvasionData(critObj);
    CDObj_TTX_t        * const pTTX     = ACDC_p_ModObjTTXData(critObj);

    /* search for satellite objects left and right*/
    escapeObjL = CDCheckEscapeObj(fSafetyOffsetLat, fSafetyOffsetLong, critObj, CD_LEFT );
    escapeObjR = CDCheckEscapeObj(fSafetyOffsetLat, fSafetyOffsetLong, critObj, CD_RIGHT);

    /* Get corresponding TTSPreLeft */
    TTSPreLeft_escapeObjL = CD_f_GetTTSPreLeft(escapeObjL);
    TTSPreLeft_critObj    = CD_f_GetTTSPreLeft(critObj);

    /* take over TTS ( and AnecLat ) from object which does not allow the mitigation */
    if (    (escapeObjL            != critObj             ) 
         && (TTSPreLeft_escapeObjL <  TTSPreLeft_critObj  ) )
    {
      pTTX->TTSPreLeft           = TTSPreLeft_escapeObjL;
      pTTX->TTSAcuteLeft         = CD_f_GetTTSAcuteLeft(escapeObjL);
      pEvasion->LatNecAccelLeft  = CD_f_GetLatNecAccelLeft(escapeObjL);
    }

    /* Get corresponding TTSPreRight */
    TTSPreRight_escapeObjR = CD_f_GetTTSPreRight(escapeObjR);
    TTSPreRight_critObj    = CD_f_GetTTSPreRight(critObj);

    /* take over TTS ( and AnecLat ) from object which doesn`t allow the mitigation */
    if (    (escapeObjR             != critObj             ) 
         && (TTSPreRight_escapeObjR <  TTSPreRight_critObj ) )
    {
      pTTX->TTSPreRight          = TTSPreRight_escapeObjR;
      pTTX->TTSAcuteRight        = CD_f_GetTTSAcuteRight(escapeObjR);
      pEvasion->LatNecAccelRight = CD_f_GetLatNecAccelRight(escapeObjR);
    }
    
    /* Set the TTSs on the initial values, so that they could be calculated for the critical object again 
       due to new left/right values. They will be calculated through the Get-functions if needed
     */
    pTTX->TTSPre          = CD_TTSPRE_INIT;
    pTTX->TTSAcute        = CD_TTSACUTE_INIT;
    pEvasion->LatNecAccel = CD_LATNECACCEL_INIT;
  }
}

/*************************************************************************************************************************
  Functionname:         CDCheckMostCritObj                                                                           */ /*!

  @brief                Finds of all objects with an EbaQuality above threshold the one with the lowest TTS.

  @description          This function searches for the most critical object by checking the TTS for each object 
                        (left for objects on left side and vice versa). The object with the lowest TTS is considered \n
                        as the most critical one. Objects with a low Eba Quality are not considered.
                        @startuml CDCheckMostCritObj_activity.png
                        start
                        partition "Execute for each object" {
                          if(EBAQuality is above threshold?\nAND TTS is below currently smallest TTS?)
                            :1}
                            :Object is the most critical one,
                            Objects TTS is the currently smallest TTS;
                          else(No)
                            :2}
                          endif
                        }
                        stop
                        @enduml
  
  @return               ObjNumber_t : Index of the most critical object. @range [0,EM_N_OBJECTS[

  @param[in]            void

  @glob_in              @ref CD_f_GetTTSAcute \n
                        @ref ACDC_p_GetEMGenObjQualifiers
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTS_OCCUPY_RECOGNITION

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Sebastian Heintz

  @testmethod           @ref TEST_CDCHECKMOSTCRITOBJ_001

  @traceability         Design Decision

*************************************************************************************************************************/
static ObjNumber_t CDCheckMostCritObj (void)
{

  ObjNumber_t       iCheckObj;
  ObjNumber_t       critObj = 0;
  fTime_t           checkLowestTTS = 0.0f;
  fTime_t           proofLowestTTS = CD_TIME_MAX;
  
  /* search for most critical object */
  for(iCheckObj = 0; iCheckObj < EM_N_OBJECTS; iCheckObj++)
  { 
    /* quality of object to check shall have a minimum value (also to exclude non-filled objects */
    if (ACDC_p_GetEMGenObjQualifiers(iCheckObj)->uiEbaObjQuality >= CD_COMMON_MIN_OBJ_QUALITY)
    {
      checkLowestTTS = CD_f_GetTTSAcute(iCheckObj);
      /* search for lowest TTS acute */
      if ( checkLowestTTS < proofLowestTTS) 
      {
        /* actual object TTS is lower than the one to proof so check object is for now the most critical */
        proofLowestTTS = checkLowestTTS;
        critObj = iCheckObj;
      }
    }
  }

  /* return */
  return critObj;
}

/*************************************************************************************************************************
  Functionname:         CDCheckEscapeObj                                                                             */ /*!

  @brief                Finds the object that defines the  minimum lateral distance the ego vehicle has to cover 
                        into a given direction to avoid a collision.

  @description          Checks in the first step if there is an object found next to the critical object on the 
                        side of the given lateral safety distance (Right side for negative safety distance, left side for \n
                        positive safety distance).Afterwards the function @ref CDFindNextCriticalObjForEvasion checks for 
                        up to 5 more objects, if there is another object on the side, that blocks an evasion movement. \n
                        If no more object is found or if the free space between two objects exceeds the width of the 
                        ego vehicles safety zone, the calculation is aborted and the last found object is returned as \n
                        the escape object.
                        \image html CD_CheckEscapeObj.svg width=1600
                        @startuml CDCheckEscapeObj_activity.png
                        start
                          #Orange:Find the next critical object for evasion
                          to the critical object
                          <b>CDFindNextCriticalObjForEvasion</b> >
                          partition "Execute and shift Next Object" {
                            note left
                              exit loop CD_CALCULATION_MAX_NOF_OBJS_FOR_ESCAPE_SEARCH times.
                              Abort if no object blocks the ego vehicles path or the 
                              next object is the previous object
                            end note
                            #Orange:Find the next critical object for evasion relative to the last found
                            <b>CDFindNextCriticalObjForEvasion</b> >
                          }
                          :Return the last found object;
                        stop
                        @enduml

  @return               ObjNumber_t : Index of the last object that blocks the evasion movement. @range [0,EM_N_OBJECTS[

  @param[in]            fSafetyOffsetLat :    Lateral safety offset. @phys_unit [m] @range ]-...,+...[
  @param[in]            fSafetyOffsetLong :   Longitudinal safety offset. @phys_unit [m] @range [0,...[
  @param[in]            iCritObj :            Object for which we want to check the next lateral object. @range [0,EM_N_OBJECTS[
  @param[in]            eSide :               Side for which the escape object shall be found. @range [CD_LEFT,CD_RIGHT]

  @glob_in              @ref ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_TTS_OCCUPY_RECOGNITION

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Determine Blockage**: \n
                          \f$ Dist_{ObjA,ObjB} > (EgoWidth + |SafetyOffset| ) \f$

  @author               Sebastian Heintz

  @testmethod           @ref TEST_CDCHECKESCAPEOBJ_001

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3334 4*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static ObjNumber_t CDCheckEscapeObj (fDistance_t const fSafetyOffsetLat,
                                     fDistance_t const fSafetyOffsetLong,
                                     ObjNumber_t const iCritObj,
                                     CDSide_t    const eSide)
{
  boolean       bloop            = b_TRUE;
  ObjNumber_t   iNextObj         = 0;
  ObjNumber_t   iEscapeObj       = 0;
  fDistance_t   fFreeSpace       = 0.0f;
  uint32        uControl;
  float32 const fEgoVehicleWidth = ACDC_p_GetEgoGeometry()->fWidth;

  iEscapeObj = iCritObj;
  /* for first instance check the next object with relation to handled over object */
  iNextObj   = CDFindNextCriticalObjForEvasion(&(fFreeSpace), eSide, iEscapeObj, iCritObj, fSafetyOffsetLong);
  
  /* search for up to n more objects the next left/right object that could become dangerous for our ego vehicle 
   CD_CALCULATION_MAX_NOF_OBJS_FOR_ESCAPE_SEARCH defines the number for objects to be considered*/
  for (uControl = 0u; (uControl < CD_CALCULATION_MAX_NOF_OBJS_FOR_ESCAPE_SEARCH) && (bloop == b_TRUE); uControl++)
  {
    /* 
    abort the loop in case there is no more left/right object (here shown as returned object is invalid) 
    or there is enough space to drive between the 2 objects 
    */
    if (   ( fFreeSpace >  (fEgoVehicleWidth + fSafetyOffsetLat ) )
        || ( iNextObj   == OBJ_INDEX_NO_OBJECT                  ) )
    {
      bloop = b_FALSE;
    } 
    /* here escape object is set to "last" checked object cause if we find no more object we want to return the last found */
    else
    {
      /* Safe currently found object */
      iEscapeObj = iNextObj;
      /* Check whether another object exists */
      iNextObj   = CDFindNextCriticalObjForEvasion(&(fFreeSpace), eSide, iEscapeObj, iCritObj, fSafetyOffsetLong);
    }
  }

  /* return */
  return iEscapeObj;
}

/*************************************************************************************************************************
  Functionname:         CDFindNextCriticalObjForEvasion                                                                               */ /*!

  @brief                Finds the relevant object that is (laterally) closest to the actual object.

  @description          This function searches for the object that is:
                        - The laterally closest one to the active object
                        - Is on a longitudinal collision distance between TTS and TTC of the critical object
                        - Has a certain Quality and Class
                        - Is not too far away from the active object
                        @startuml CDCheckClosest_activity.png
                        start
                        partition "Execute for each object" {
                          if(Object has required properties?) then (Yes)
                            :Get TTS for the relevant side;
                            note left
                              According to eSide
                            end note
                            #Orange:Check longitudinal criticality
                            <b>CDCheckEscObjLong</b> >
                            note left
                              Critical if the considered object is 
                              closer to the ego vehicle than the 
                              safety distance between TTS and TTC 
                              of the critical object.
                            end note
                            if (Object is longitudinal critical? \nAND Object is the currently closest one in Y-Direction?) then (Yes)
                              :1}
                              :Set Object as closest object;
                              :Calculate the free space 
                              to the previous object;
                              note left: >see "Formula Free Space"
                            else(No)
                              :2}
                            endif
                          else (No)
                            :3}
                          endif
                        }
                        stop
                        @enduml

  @return               ObjNumber_t : Index of the closest lateral object. @range [0,EM_N_OBJECTS[

  @param[in,out]        pFreeSpace :        Space between closest and actual object. @phys_unit [m] @range [0,+...[
  @param[in]            eSide :             Indicates on which side of the ego vehicle we search. @range [CD_LEFT,CD_RIGHT]
  @param[in]            iActObj :           Object for which we want to check the next lateral object.
  @param[in]            iCritObj :          Critical object from which we check lateral distance.
                                            (only to handle over into sub-function no real use here...)
  @param[in]            fSafetyOffsetLong : Longitudinal safety offset. @phys_unit [m] @range [0,+...[

  @glob_in              @ref ACDC_p_GetACDCObjectMain \n
                        @ref CD_f_GetTTSAcuteLeft \n
                        @ref CD_f_GetTTSAcuteRight \n
                        @ref CD_f_GetTTC
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Free Space**: \n
                          \f$|Y_{ObjB} - Y_{ObjA} |\f$

  @author               Sebastian Heintz

  @testmethod           @ref TEST_CDFINDNEXTCRITICALOBJFOREVASION_001 \n
                        @ref TEST_CDFINDNEXTCRITICALOBJFOREVASION_002 \n
						@ref TEST_CDFINDNEXTCRITICALOBJFOREVASION_003 \n
						@ref TEST_CDFINDNEXTCRITICALOBJFOREVASION_004 \n

  @traceability         Design Decision

*************************************************************************************************************************/
/*PRQA S 3334 2*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
static ObjNumber_t CDFindNextCriticalObjForEvasion (fDistance_t       * const pFreeSpace, 
                                                    CDSide_t    const         eSide,
                                                    ObjNumber_t const         iActObj,
                                                    ObjNumber_t const         iCritObj,
                                                    fDistance_t const         fSafetyOffsetLong )
{
  
  ACDCObjDescMain_t const * const pActObj = ACDC_p_GetObjDescMain(iActObj);

  ObjNumber_t            iNextCriticalObjID;
  ObjNumber_t            iCheckObj;
  float32                fNextCriticalObjDistY;
  boolean                bLongCrit;
  fTime_t                fTTS2Check;
  float32                fTTC_iCheckObj;
  float32                fTTC_actObj;
  float32        const   fActObjDistY              = ACDC_p_GetObjPositions(iActObj)->GenObject.fY;
  float32                fActObjDistYEvasionDir    = fActObjDistY;

  /* Calculate the critical edges of the actual object in respect to the evasion direction */
  if (eSide == CD_LEFT )
  {
    fActObjDistYEvasionDir      += (0.5F * pActObj->Geometry.fWidth);
  }
  else
  {
    fActObjDistYEvasionDir      -= (0.5F * pActObj->Geometry.fWidth);
  }

  /* Set initial value for the next evasion object */
  fNextCriticalObjDistY = fActObjDistYEvasionDir;
  iNextCriticalObjID    = OBJ_INDEX_NO_OBJECT;

  for(iCheckObj = 0; (iCheckObj < EM_N_OBJECTS) && (iNextCriticalObjID == OBJ_INDEX_NO_OBJECT); iCheckObj++)
  {
    if (    (ACDC_b_GetEMGenObjIsDeleted(iCheckObj) == b_FALSE  )
         && (iCheckObj                              != iActObj) )
    {
      /* Get local pointer to gen object */
      EM_t_GenObject const * const pGenObj = ACDC_p_GetEMGenObj(iCheckObj);
      
      if(    (    (pGenObj->Qualifiers.uiEbaObjQuality >= CD_COMMON_MIN_OBJ_QUALITY        )
               && (pGenObj->Attributes.eClassification != EM_GEN_OBJECT_CLASS_POINT        )
               && (pGenObj->Attributes.eClassification != EM_GEN_OBJECT_CLASS_UNCLASSIFIED ) )
          || (    (pGenObj->Qualifiers.uiEbaObjQuality >= CD_COMMON_MIN_OBJ_QUALITY_POINT  )
               && (pGenObj->Attributes.eClassification == EM_GEN_OBJECT_CLASS_POINT        ) ) )
      {
        /* decide whether to check left or right side and choose corresponding TTS */
        if (eSide == CD_LEFT)
        {
          fTTS2Check = CD_f_GetTTSAcuteLeft(iCheckObj);
        }
        else
        {
          fTTS2Check = CD_f_GetTTSAcuteRight(iCheckObj);
        }
        /* check for longitudinal criticality */
        bLongCrit      = CDCheckEscObjLong(fTTS2Check, iCheckObj, iCritObj, fSafetyOffsetLong);
        fTTC_iCheckObj = CD_f_GetTTC(iCheckObj);
        fTTC_actObj    = CD_f_GetTTC(iActObj);
      
        if (    ( fTTC_iCheckObj <  (fTTC_actObj + CD_CALC_TTC_SAFE_TIME_LONG ) ) 
             && ( bLongCrit      == b_TRUE                                        ) )
        {
          float32 fCheckObjDistY                          = ACDC_p_GetObjPositions(iCheckObj)->GenObject.fY;
          float32 fCheckObjDistYEvasionDir                = fCheckObjDistY;
          float32 fCheckObjDistYNotEvasionDir             = fCheckObjDistY;
          ACDCGeometry_t const * const pCheckObjGeometry  = ACDC_p_GetObjGeometry(iCheckObj);
          /* Calculate the critical edges in respect to the evasion direction */
          if (eSide == CD_LEFT )
          {
            fCheckObjDistYEvasionDir    += (0.5F * pCheckObjGeometry->fWidth);
            fCheckObjDistYNotEvasionDir -= (0.5F * pCheckObjGeometry->fWidth);
          
            if (fCheckObjDistYEvasionDir > fNextCriticalObjDistY)
            {
              iNextCriticalObjID    = iCheckObj;
              fNextCriticalObjDistY = fCheckObjDistYEvasionDir;
            }
          }
          else
          {
            fCheckObjDistYEvasionDir    -= (0.5F * pCheckObjGeometry->fWidth);
            fCheckObjDistYNotEvasionDir += (0.5F * pCheckObjGeometry->fWidth);
            
            if (fCheckObjDistYEvasionDir < fNextCriticalObjDistY)
            {
              iNextCriticalObjID    = iCheckObj;
              fNextCriticalObjDistY = fCheckObjDistYEvasionDir;
            }
          }

          /* Update the resulting freespace */
          if (iNextCriticalObjID != OBJ_INDEX_NO_OBJECT)
          {
            *pFreeSpace = fABS( fCheckObjDistYNotEvasionDir - fActObjDistYEvasionDir);
          }
        }
      }
    }
  }
  /* return */
  return iNextCriticalObjID;
}

/*************************************************************************************************************************
  Functionname:         CDCheckEscObjLong                                                                            */ /*!

  @brief                Checks if an objects x position overlaps with the ego x-position between TTS and TTC of 
                        the critical object.

  @description          The X-Distance of the considered object and the ego vehicle at the TTC and the TTS of the 
                        critical object are calculated. If one of the resulting distances is below the safety \n
                        distance of the ego vehicle, an object is considered as longitudinal critical.
                        @startuml CDCheckEscObjLong_activity.png
                        start
                          #Orange:Calculate the Ego-Object X-Distance 
                          at TTC and at TTS
                          <b>CDCalculateDistance</b> >
                          if(Object is not behind the Ego vehicle at TTS or TTC) then (Yes)
                            :1}
                            :Object is critical;
                          else(No)
                            :2}
                            :Object is not critical;
                          endif
                        stop
                        @enduml
  @return               boolean : TRUE in case object is longitudinal critical

  @param[in]            TTS :               TTS of actual object (and side to check). @phys_unit [s] @range [0,+...[
  @param[in]            actObj :            Actual object to check. @range [0,EM_N_OBJECTS[
  @param[in]            critObj :           Critical object. @range [0,EM_N_OBJECTS[
  @param[in]            fSafetyOffsetLong : Safety longitudinal offset. @phys_unit [m] @range [0,+...[

  @glob_in              @ref ACDC_p_GetObjPositions\n
                        @ref CD_f_GetTTC \n
                        @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetObjMovement
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @todo                 check for longitudinal gap that may occur in case object is
                        strongly decelerating...actually we do not know how long
                        object is...could be 30m truck or 2m Smart, so we can not
                        know when we would have passed the object...

  @author               Sebastian Heintz

  @testmethod           @ref TEST_CDCHECKESCOBJLONG_001 \n
                        @ref TEST_CDCHECKESCOBJLONG_002 \n
						@ref TEST_CDCHECKESCOBJLONG_003 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDCheckEscObjLong (fTime_t     const TTS,
                                  ObjNumber_t const actObj,
                                  ObjNumber_t const critObj,
                                  fDistance_t const fSafetyOffsetLong )
{
  float32       const         fEgoVehicleLength    = ACDC_p_GetEgoGeometry()->fLength;
  SFLMovement_t const * const pObjectRelKinematics = &(ACDC_p_GetObjMovement(actObj)->Rel);
  boolean                     bIsCrit  =  b_FALSE;

  fDistance_t  const fDx      = ACDC_p_GetObjPositions(actObj)->GenObject.fX;
  float32      const fVx      = pObjectRelKinematics->Vel.fX;
  float32      const fAx      = pObjectRelKinematics->Accel.fX;
  fTime_t      const fTTC     = CD_f_GetTTC(critObj);
  /* calculated longitudinal distances for time TTS and TTC */
  fDistance_t  const fDistTTC = CDCalculateDistance( fDx, fVx, fAx, fTTC );
  fDistance_t  const fDistTTS = CDCalculateDistance( fDx, fVx, fAx, TTS  );

  /* 
  proof at both times TTS and TTC if distance is smaller than ego length + safety offset
  -> means collide (without gap or "driving through" proof by object falls behind us before TTS)
  */
  if (    ( fDistTTC < ( fEgoVehicleLength + fSafetyOffsetLong ) )
       || ( fDistTTS < ( fEgoVehicleLength + fSafetyOffsetLong ) ) )
  {
    bIsCrit = b_TRUE;
  }
  return bIsCrit;
}
#endif /* #if (CD_USE_TTS_OCCUPY_RECOGNITION) */

/*************************************************************************************************************************
  Functionname:         CDAssignTrack                                                                                */ /*!

  @brief                Checks if the given object will be in our way and if so sets the Track Assignment 
                        parameter accordingly

  @description          The Track Assignment is stored in an 8-bit field. Each bit represents one passed cycle, 
                        whereas the highest bit represents the current cycle. If the bit for a certain cycle is 1, 
                        the object was Track assigned in this cycle. \n
                        @startuml CDAssignTrack_activity.png
                        start
                          :Get all relevant object 
                          and ego information;
partition #LightBlue **CD_LIMIT_RADAR_OBJECT_WIDTH** {
                          if(Object is stationary?
                             AND has not changed from moving to stationary?) then (Yes)
                            :1}
                            :Limit the object width;
                          else(No)
                            :2}
                          endif
}
                          #Orange:Calculate the inlap of the object 
                          into the ego trajectory:
                          <b>CDCalculateInlap</b> >

                          :Shift the Track Assigned
                          register for 1 Bit;
                          if(Inlap > 0) then (Yes)
                            :3}
                            :Set the highest bit of the
                            Track Assigned Register to 1;
                          else(No)
                            :4}
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :     Index of the considered object. @range [0,EM_N_OBJECTS[

  @glob_in              @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetEMARSObjMotionAttributes \n
                        @ref ACDC_b_GetObjIsMovingToStationary
  @glob_out             @ref ACDC_p_ModObjStaticEvasionData

  @c_switch_part        @ref CD_LIMIT_RADAR_OBJECT_WIDTH
  @c_switch_full        @ref ACDC_CFG_CD \n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_CDASSIGNTRACK_001 \n
                        @ref TEST_CDASSIGNTRACK_002 \n
						@ref TEST_CDASSIGNTRACK_003 \n
						@ref TEST_CDASSIGNTRACK_004 \n

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDAssignTrack(ObjNumber_t iObjectIndex)
{
  CDObj_EvasionStatic_t         * const pEvasion       = ACDC_p_ModObjStaticEvasionData(iObjectIndex);
  ACDCObjToTrajRelation_t const * const pTrajRelation  = ACDC_p_GetObjTrajRelation(iObjectIndex);
  float32                 const         EgoTrajWidth   = ACDC_p_GetEgoGeometry()->fWidth * (1.f - CD_TRKASGN_CORRIDOR_REDUCTION_PERC);
  float32                               fObjWidth      = MAX(C_F32_DELTA,(pTrajRelation->fDistToTrajMax - pTrajRelation->fDistToTrajMin));
  float32                               fDistToTraj    = (pTrajRelation->fDistToTrajMax + pTrajRelation->fDistToTrajMin) * 0.5f;
  float32                               fDistToTrajVar = pTrajRelation->fDistToTrajVar;
  float32                               fInlap;
  float32                               fInlapVar;

#if defined(CD_LIMIT_RADAR_OBJECT_WIDTH) && (CD_LIMIT_RADAR_OBJECT_WIDTH == SWITCH_ON)
  if(    (ACDC_p_GetEMARSObjMotionAttributes(iObjectIndex)->eDynamicProperty == ARS_OBJECT_PROPERTY_STATIONARY)
      && (ACDC_b_GetObjIsMovingToStationary(iObjectIndex)                    == FALSE                         ) )
  {
    fObjWidth = MIN_FLOAT(CD_MAX_OBJ_WIDTH_STAT, fObjWidth);
  }
#endif

  CDCalculateInlap(fDistToTraj , fDistToTrajVar,
                   EgoTrajWidth, 0.f,
                   fObjWidth   , 0.f,
                   &fInlap     , &fInlapVar);


  /* Shift Track Assignment History */
  pEvasion->TrackAssigned = (pEvasion->TrackAssigned >> 1);
  if(fInlap > 0.f)
  {
    pEvasion->TrackAssigned += 128u;
  }
}


#if(CD_USE_TURNINTOVRU_HYPOTHESIS)
/*************************************************************************************************************************
  Functionname:         CD_v_UpdatePSCCollProbHist                                                                           */ /*!

  @brief                Check the probability of collision with the object and set the bit field 
                        of the collision prediction accordingly.

  @description          The Collision Prediction is stored in an 8-bit field. Each bit represents one passed cycle, 
                        whereas the highest bit represents the current cycle. If the bit for a certain cycle is 1, 
                        the object collision probability for this cycle exceeds predefined threshold. \n
                        @startuml CDUpdatePSCCollProbHist_activity.png
                        start
                        :Get all relevant object 
                        and ego information;
                        :Right shift the PSC coll prob history
                        register for 1 Bit;
                        if(    EgoVelocity < Threshold?
                           and ObjVelAbs < Threshold? ) then (Yes)
                        :1}
                        :Get max dist to traj
                        threshold based on vel to traj;
                        if(    DistToTraj < MaxDistToTraj?
                           and TTC3 < Threshold?) then (Yes)
                        :3}
                        #Orange:Calculate the prob of collision:
                        <b>CDPSCGetProbCollision</b> >
                        if(ProbOfColl > Threshold) then (Yes)
                        :5}
                        :Set the highest bit of the
                        PSC coll prob history Register to 1;
                        else(No)
                        :6}
                        endif
                        else(No)
                        :4}
                        endif
                        else (No)
                        :2}
                        endif
                        stop
                        @enduml
  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0,+...[

  @glob_in              @ref ACDC_p_GetEgoGeometry \n
                        @ref ACDC_p_GetObjTrajRelation \n
                        @ref CD_f_GetTTC3\n
                        @ref ACDC_f_GetEgoVelObjSync\n
                        @ref ACDC_p_GetObjMovement

  @glob_out             @ref ACDC_p_ModObjStaticEvasionData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD\n
                        @ref CD_USE_TURNINTOVRU_HYPOTHESIS\n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description
  @testmethod           @Generic_Testmethods
  @author               Mohamed Abdelkarim | Mohamed.Abdelkarim@continental-corporation.com | +49 (8382) 9699-248

*************************************************************************************************************************/
static void CD_v_UpdatePSCCollProbHist(ObjNumber_t iObjectIndex)
{
  CDObj_EvasionStatic_t         * const pEvasion          = ACDC_p_ModObjStaticEvasionData(iObjectIndex);
  ACDCObjToTrajRelation_t const * const pObjTrajRelation  = ACDC_p_GetObjTrajRelation(iObjectIndex);
  ACDCObjMovement_t       const * const pObjMovement      = ACDC_p_GetObjMovement(iObjectIndex);
  float32                 const         fObjAbsVel        = SQRT( SQR(pObjMovement->Abs.Vel.fX) + SQR(pObjMovement->Abs.Vel.fY) );
  float32                 const         fHalfEgoTrajWidth = 0.5f * ACDC_p_GetEgoGeometry()->fWidth;
  float32                 const         fEgoLongVelocity  = ACDC_f_GetEgoVelObjSync();
  float32                               fPSCProb;
  float32                               fDistToTrajMax;

  /* Shift PSC collision probability history */
  pEvasion->PSCCollProbHist = (pEvasion->PSCCollProbHist >> 1);
  /* The evaluation of collision probability is not performed in high speed situations */
  if (     ( fEgoLongVelocity < CD_MAX_VEL_EGO_PSC_COL_PROB_HIST )
        && ( fObjAbsVel       < CD_MAX_VEL_OBJ_PSC_COL_PROB_HIST ) )
  {
    /* Determine the maximum distance to trajectory, above which the collision probability is not filled for the object */
    fDistToTrajMax = CML_f_boundedLinInterpol2( fABS(pObjTrajRelation->fVelocityToTraj),
                                                CD_VEL_STAT_OBJ_PSC_COL_PROB_HIST  , CD_MAX_VEL_VRU_PSC_COL_PROB_HIST,
                                                CD_DMAX_STAT_OBJ_PSC_COL_PROB_HIST , CD_DMAX_MAX_VEL_PSC_COL_PROB_HIST );

    /* Update the PSC collision probability history only for potentially relevant objects*/
    if (     ( CD_f_GetTTC3(iObjectIndex)          <  CD_MAX_TTC_PSC_COL_PROB_HIST )
          && ( fABS(pObjTrajRelation->fDistToTraj) <  fDistToTrajMax               ) )
    {
      /* Get PSC probability using velocity to collision point from EMP module */
      fPSCProb = CDPSCGetProbCollision(iObjectIndex, fHalfEgoTrajWidth, fHalfEgoTrajWidth, CD_PSC_USE_TO_COLL_POINT);

      /* Update the most significant bit of PSC collision probability history */
      if( fPSCProb > CD_THRSHLD_PSC_COL_PROB_HIST )
      {
        pEvasion->PSCCollProbHist += 128u;
      }
    }
  }
  
}
#endif

#if (CD_USE_HIGH_QUALITY_LIFETIME)
/*************************************************************************************************************************
  Functionname:         CDCalculateHiQualityLifetime                                                                 */ /*!

  @brief                Calculates the time for which an object has had a high EbaQuality.

  @description          Increases the high quality life time of an object by one cycle time if its EbaObject 
                        quality exceeds a certain threshold. The threshold depends on the class of the object. \n
                        If the Quality does not reach this threshold, the high quality lifetime is set to 0. \n
                        If CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS is set, high quality lifetime is not changed, 
                        when Ego and Target vehicle are stationary. 

  @return               void

  @param[in]            iObjectIndex :      Index of the considered Object. @range [0,EM_N_OBJECTS[
  @param[in,out]        pInternalObjData :  Pointer to internal CD objects.

  @glob_in              @ref ACDC_b_GetEMGenObjIsDeleted \n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref ACDC_p_GetEMGenObjQualifiers \n
                        @ref ACDC_f_GetCycleTime \n
                        @ref ACDC_p_GetEgoData \n
                        @ref ACDC_p_GetObjDescMain \n
                        @ref CD_e_GetSensorSource \n
                        @ref ACDC_p_GetObjStaticEvasionData
  @glob_out             @ref ACDC_p_ModObjStaticEvasionData

  @c_switch_part        @ref CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS
                        @ref CD_USE_HIGH_QUALITY_LIFETIME_CROSSING
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_HIGH_QUALITY_LIFETIME

  @pre                  None
  @post                 None

  @InOutCorrelation     |Object Class                             |EbaObjQuality Threshold|
                        |:----------------------------------------|:----------------------|
                        |EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY    |                     97|
                        |EM_GEN_OBJECT_DYN_PROPERTY_MOVING        |                     97|
                        |EM_GEN_OBJECT_DYN_PROPERTY_STOPPED       |                     97|
                        |EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING      |                    100|
                        |EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT|                    100|
                        |EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT |                    100|
                        |EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN       |                    100|

  @todo                 uiObjQualMin = 100u is correct? A high quality life time can never be reached in these cases.

  @author               Thomas Diepolder

  @testmethod           @ref TEST_CDCALCULATEHIQUALITYLIFETIME_001 \n
                        @ref TEST_CDCALCULATEHIQUALITYLIFETIME_002 \n
                        @ref TEST_CDCALCULATEHIQUALITYLIFETIME_003 \n
                        @ref TEST_CDCALCULATEHIQUALITYLIFETIME_004

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDCalculateHiQualityLifetime(ObjNumber_t       const         iObjectIndex)
{
  EM_t_GenObjDynamicProperty const eDynamicProperty = ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eDynamicProperty;
  float32                          fTimeHiQual      = ACDC_p_GetObjStaticEvasionData(iObjectIndex)->fObjLifeCycleTimeHiQual;
  uint8                            uiObjQualMin;
  
  if (ACDC_b_GetEMGenObjIsDeleted(iObjectIndex) == b_FALSE)
  {
    /* Get sensor source to check for camera confirmation for the object */ 
    EM_t_GenObjSensorSource eSensorSource = CD_e_GetSensorSource(iObjectIndex);
    
    switch (eDynamicProperty)
    {
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY:
      uiObjQualMin = CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_STAT;
      break;

    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING:
    case (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_STOPPED:
      uiObjQualMin = CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_MOV_STOP;
      break;

    case (EM_t_GenObjDynamicProperty) EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT:
    case (EM_t_GenObjDynamicProperty) EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT:
#if (CD_USE_HIGH_QUALITY_LIFETIME_CROSSING)
      uiObjQualMin = CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_CROSS;
      break;
#endif /* CD_USE_HIGH_QUALITY_LIFETIME_CROSSING */
 
    case (EM_t_GenObjDynamicProperty) EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING:
    case (EM_t_GenObjDynamicProperty) EM_GEN_OBJECT_DYN_PROPERTY_UNKNOWN:
    default:
      /* Set a threshold above 100 here. This ensures that the following check cannot be passed. */
      uiObjQualMin = CD_CALCULATION_HIGH_QUALITY_LIFETIME_EBA_QUAL_DEFAULT;
      break;
    }

    if (    (ACDC_p_GetEMGenObjQualifiers(iObjectIndex)->uiEbaObjQuality > uiObjQualMin)
         && (GET_BIT(eSensorSource, EM_GEN_OBJECT_MS_CAM)                              ) )
    {
      fTimeHiQual += ACDC_f_GetCycleTime();
    }
    else
    {
      /* Reduce high quality lifetime using gradient */
      if (    (CD_HIGH_QUALITY_LIFETIME_GRAD <  -C_F32_DELTA)
           && (fTimeHiQual                    >  C_F32_DELTA) )
      {
#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)
        float32 const fEgoVelX    = fABS(ACDC_p_GetEgoData()->Kinematics.fVel);
        float32 const fObjAbsVelX = fABS(ACDC_p_GetObjDescMain(iObjectIndex)->Movement.Abs.Vel.fX);
        if (    (fEgoVelX    < CD_MAX_VEL_FOR_KEEP_HIGH_QUALITY_LIFETIME)
             && (fObjAbsVelX < CD_MAX_VEL_FOR_KEEP_HIGH_QUALITY_LIFETIME) )
        {
         /* keep fTimeHiQual if ego and target are both stationary => do nothing */ 
        }
        else
        {
          fTimeHiQual += (ACDC_f_GetCycleTime() * CD_HIGH_QUALITY_LIFETIME_GRAD);
        }
#else
        fTimeHiQual += (ACDC_f_GetCycleTime() * CD_HIGH_QUALITY_LIFETIME_GRAD);
#endif /* CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS */
      }
      else
      {
        fTimeHiQual = 0.0f;
      }
    }
  }
  else
  {
    fTimeHiQual = 0.0f;
  }

  /* Limit high quality lifetime between 0 and defined max. value */
  ACDC_p_ModObjStaticEvasionData(iObjectIndex)->fObjLifeCycleTimeHiQual = MINMAX_FLOAT(0.0f, CD_CALCULATION_HIGH_QUALITY_LIFETIME_MAX, fTimeHiQual);
}
#endif

#if defined(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE) && ( CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE == SWITCH_ON )
/*************************************************************************************************************************
  Functionname:       CDUpdateSensorSource */ /*! 
  
  @brief              Get the eSensorSource bitfield for a given object.
  
  @description        For a given object this function updates the eSensorSource bitfield intended for use in CD and 
                      passed to HEAD. The bits are set based on whether the sensor confirmation (uiSensorConfirmation \n
                      from the fusion object list, @ref EM_t_FusionObjectList) is greater or equal a defined threshold. \n
                      \n
                      The check is done based on the data taken from the global variable @ref CDFusionSenConf which 
                      defines the mapping from the fusion object list data to the eSensorSource bitfield (see definition \n
                      of @ref EM_t_GenObjSensorSource). If the mapping includes multiple fusion sensors setting the same 
                      bit or bits of eSensorSource, the setting of the bits is done using a logical OR. I.e., if the \n
                      threshold condition for one fusion sensor setting a specific bit is fulfilled the bit is set. The 
                      bit for the host sensor, i.e. @ref EM_GEN_OBJECT_MS_LRR or @ref EM_GEN_OBJECT_MS_CAM, is always \n
                      set. It is checked if the fusion object list is available. If it is not available only the bit 
                      for the host sensor is set. \n
                      ATTENTION: This function must only be called once per cycle!
                      @startuml CD_u_GetSensorSource.png
                      start
                      while (Are all sensors handled?) is (No)
                        :Check if 
                        1. Sensor confirmation exceeds threshold
                        (Hysteresis if threshold was exceeded before)?
                        OR 
                        2. Sensor is host sensor?;
                        if (Check passed?) then (Yes)
                          :1}
                          :Set (bitwise logical OR) sensor 
                          specific bit in the eSensorSource 
                          bitfield;
                        else (no)
                          :2}
                          :Clear sensor specific bit in 
                          the eSensorSource bitfield;
                        endif
                      endwhile (Yes)
                      stop
                      @enduml
               
  @return             eSensorSource : Bitfield showing which sensors are confirming the object.
  
  @param[in]          iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS-1]
  
  @glob_in            @ref CDFusionSenConf : project specific structure defining the mapping between the fusion 
                                             object list and the eSensorSource bitfield\n
                      @ref ACDC_p_GetEMFusionObj
  @glob_out           @ref ACDC_p_ModObjQualifier
  
  @c_switch_part      @ref FCT_CFG_SENSOR_TYPE_RADAR : Switch to check for host sensor type radar.\n
                      @ref FCT_CFG_SENSOR_TYPE_CAMERA : Switch to check for host sensor type camera.
  @c_switch_full      @ref CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE: This function is only enabled if the fusion object 
                                                               list is intended to be used to fill the eSensorSource.
  
  @pre                The global variable @ref CDFusionSenConf has to be set according to the project specific fusion setup.
  
  @InOutCorrelation   See description.
  
  @testmethod         @Generic_Testmethods
  
  @author             Andreas Danner | andreas.danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/ 
static void CDUpdateSensorSource(ObjNumber_t iObjectIndex)
{
  CDQualifier_t           * const pObjQualifier      = ACDC_p_ModObjQualifier(iObjectIndex);
  EM_t_GenObjSensorSource         eSensorSource      = 0u;
#ifdef FUSION_SENSOURCE
  uint8                           uFusIdx;
  EM_t_GenObjAttributes const * const pEmObjAttributes = ACDC_p_GetEMGenObjAttributes(iObjectIndex);
#endif
#ifdef FUSION_SENSOURCE // depend on fusion camera confirmation 
	
	/* Set bits for fusion sensors */
  /* PRQA S 2877 1*//* date: 2019-05-14, reviewer:C. Schnurr, reason: EM_N_FUSION_SENSORS == 1 is possible for some configuratoins */
  for (uFusIdx = 0; uFusIdx < (uint8)EM_N_FUSION_SENSORS; uFusIdx++)
  {
    EM_t_FusionSensorIndices uiFusSenRef    = CDFusionSenConf[uFusIdx].eFusionSenIdx;
    /* Check whether the fusion ID is valid */
    if ( uiFusSenRef < (EM_t_FusionSensorIndices)EM_N_FUSION_SENSORS )
    {
      uint8 uiSensorConf                      = ACDC_p_GetEMFusionObj(iObjectIndex)->uiSensorConfirmation[uiFusSenRef];
      boolean bLastCycleSensorConfirmed       = (GET_BIT((pObjQualifier->eSensorSource), CDFusionSenConf[uFusIdx].eSensorSource)) ? TRUE : FALSE;
      
      if(    (     uiSensorConf              >= CDFusionSenConf[uFusIdx].uSenConfThresOn   )
          || (    (bLastCycleSensorConfirmed != FALSE                                    ) 
               && (uiSensorConf              >= CDFusionSenConf[uFusIdx].uSenConfThresOff) ) )
      {
        SET_BIT(eSensorSource, CDFusionSenConf[uFusIdx].eSensorSource);
      }
    }
    else
    {
      /* In this case an CDFusionSenConf contains an invalid configuration */
      ACDC_ASSERT(FALSE);
    }
  }


  /* Set bit for host sensor */
  /* TODO: Replace this part when the fusion list contains host sensor information also. */
#if (FCT_CFG_SENSOR_TYPE_RADAR == SWITCH_ON) 
  SET_BIT(eSensorSource,(ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource & EM_GEN_OBJECT_MS_LRR));
#endif
#if (FCT_CFG_SENSOR_TYPE_CAMERA == SWITCH_ON)
  SET_BIT(eSensorSource,(ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource & EM_GEN_OBJECT_MS_CAM));
#endif

#endif

  SET_BIT(eSensorSource, (ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource));
/*! Using Sensor Bit IR for indicating TRUCK class so at to avoid RTE changes */
#if (FCT_CFG_CLASS_TRUCK == SWITCH_ON)
  if(pEmObjAttributes->eClassification == (EM_t_GenObjClassification)EM_GEN_OBJECT_CLASS_TRUCK)
  {
  //SET_BIT(eSensorSource,(ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource & EM_GEN_OBJECT_MS_IR));
  //SET_BIT(eSensorSource, EM_GEN_OBJECT_MS_IR);
  SET_BIT(eSensorSource, (ACDC_p_GetEMGenObjGeneral(iObjectIndex)->eSensorSource | EM_GEN_OBJECT_MS_IR)); //Used for fusion object

  }
  else{;} 
#endif

  /* Write calculated value to internal object list */
  pObjQualifier->eSensorSource = eSensorSource;

}
#endif /*(CD_USE_FUS_OBJ_LIST_FOR_SEN_SOURCE)*/

//!@}
#endif /* #if (ACDC_CFG_CD) */
