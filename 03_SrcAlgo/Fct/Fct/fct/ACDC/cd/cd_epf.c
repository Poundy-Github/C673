/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT / CD / EPF (Evasion Possibility Front)

PACKAGENAME:               cd_epf.c

DESCRIPTION:               EPF Main Source File

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/07/12 16:40:23CEST $

VERSION:                   $Revision: 1.29 $

LEGACY VERSION:            Revision: 1.18.1.26

**************************************************************************** */
/*PRQA S 3121 EOF*/
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "cd_epf.h"
#if (ACDC_CFG_CD)

#if (CD_USE_EPF)
/**
@addtogroup cd_epf
@{
*/



/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         EPFResetOutput                                                                               */ /*!

  @brief                Resets the EPF output structure.

  @description          Resets the EPF output structure:
                        - Set all General Output Parameters to 0.
                        - Set all information regarding the evasion corridor left/right to 0.
                        - Set the qualifiers of the evasion corridor left and right to their inactive state.

  @return               void

  @param[in,out]        pEPFOutput : EPF Output structure.

  @glob_in              @ref ACDC_p_ModWorkingData
  @glob_out             @ref ACDC_p_ModWorkingData

  @c_switch_part        @ref ACDC_SIMU \n
                        @ref FCT_CD_OUTPUT_CUSTOM_INTFVER
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointer is valid.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFResetOutput(EPFOutput_t* pEPFOutput)
{
#ifdef ACDC_SIMU
  ACDCEPFTargetSimu_t * const pEPFTargetSimuData = &(ACDC_p_ModWorkingData()->pSimuData->sGlobData.CD.sEPFTargetSimuData);
  pEPFTargetSimuData->iTargetID         = 0;
  pEPFTargetSimuData->fSafetyDist       = 0.f;
  pEPFTargetSimuData->sTargetKinNow.fX  = 0.f;
  pEPFTargetSimuData->sTargetKinNow.fY  = 0.f;
  pEPFTargetSimuData->sTargetKinPred.fX = 0.f;
  pEPFTargetSimuData->sTargetKinPred.fY = 0.f;
#endif

  /* General Output Parameters */
  pEPFOutput->fTargetDistX     = 0.f;
  pEPFOutput->fTargetDistXPred = 0.f;
  pEPFOutput->fTargetAx        = 0.f;
  pEPFOutput->fTargetVx        = 0.f;
#if (FCT_CD_OUTPUT_CUSTOM_INTFVER >= 22u)
  pEPFOutput->fTargetAnecLong  = 0.f;
#endif

  /* Evasion Corridor Left */
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fCurvature               = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fHeading                 = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fLatDistEgoToBorder      = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fLatDistObstacleToBorder = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fProb                    = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierCorridor       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierObstacle       = EPF_QUALIFIER_STATE_INACTIVE;

  /* Evasion Corridor Right */
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fCurvature               = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fHeading                 = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fLatDistEgoToBorder      = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fLatDistObstacleToBorder = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fProb                    = 0.f;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierCorridor       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierObstacle       = EPF_QUALIFIER_STATE_INACTIVE;
}

#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         EPFResetCorridors                                                                            */ /*!

  @brief                The function resets the EPF-Freeze Corridor Structures

  @description          Resets the EPF output structure (@ref asFrozenCorridors) by setting its qualifier states to INACTIVE 
                        and all other values to 0.

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref ACDC_p_ModEPFCorridorData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF \n
                        @ref CD_EPF_CORRIDOR_FREEZE

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFResetCorridors(void)
{
  EPFCorridorData_t * const pEPFCOrr = ACDC_p_ModEPFCorridorData();

  pEPFCOrr->asFrozenCorridors[0].eQualifierCorridor       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFCOrr->asFrozenCorridors[0].eQualifierObstacle       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFCOrr->asFrozenCorridors[0].fCurvature               = 0.f;
  pEPFCOrr->asFrozenCorridors[0].fHeading                 = 0.f;
  pEPFCOrr->asFrozenCorridors[0].fLatDistEgoToBorder      = 0.f;
  pEPFCOrr->asFrozenCorridors[0].fLatDistObstacleToBorder = 0.f;
  pEPFCOrr->asFrozenCorridors[0].fProb                    = 0.f;

  pEPFCOrr->asFrozenCorridors[1].eQualifierCorridor       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFCOrr->asFrozenCorridors[1].eQualifierObstacle       = EPF_QUALIFIER_STATE_INACTIVE;
  pEPFCOrr->asFrozenCorridors[1].fCurvature               = 0.f;
  pEPFCOrr->asFrozenCorridors[1].fHeading                 = 0.f;
  pEPFCOrr->asFrozenCorridors[1].fLatDistEgoToBorder      = 0.f;
  pEPFCOrr->asFrozenCorridors[1].fLatDistObstacleToBorder = 0.f;
  pEPFCOrr->asFrozenCorridors[1].fProb                    = 0.f;
}
#endif /* CD_EPF_CORRIDOR_FREEZE */

/*************************************************************************************************************************
  Functionname:         EPFLimitAbsValue                                                                             */ /*!

  @brief                The function limits a float to a certain absolute value while preserving its sign.

  @return               void

  @param[in,out]        fVal :    Value that shall be limited. \range ]-...,+...[
  @param[in]            fMaxAbs : Limitation (absolute). \range [0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointer is valid.
  @post                 None

  @InOutCorrelation     |Val(In) | MaxAbs  |Val(Out)|
                        |:-------|:--------|:-------|
                        |>0      |>Val(In) |Val(In) |
                        |>0      |<Val(In) |MaxAbs  |
                        |<=0     |>-Val(In)|Val(In) |
                        |<=0     |<-Val(In)|-MaxAbs |

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFLimitAbsValue(float32* fVal, float32 fMaxAbs)
{
  if ( *fVal > 0.f )
  {
    *fVal = MIN_FLOAT(*fVal, fMaxAbs);
  }
  else
  {
    *fVal = MAX_FLOAT(*fVal, -fMaxAbs);
  }
}

/*************************************************************************************************************************
  Functionname:         EPFAreasIntersect                                                                            */ /*!

  @brief                Checks whether two areas intersect

  @description          If the following conditions are fulfilled, two areas intersect:
                        - The right edge of area1 is on the right of the left edge of area2.
                        - The left edge of area1 is on the left of the right edge of area2.
                        - The near edge of area1 is closer than the far edge of area2.
                        - The far edge of area1 is further away than the close edge of area2.

  @return               boolean: True if the given areas intersect, False if not.

  @param[in]            psArea1 : Structure describing an area.
  @param[in]            psArea2 : Structure describing another area for which shall be 
                                  checked if it intersects with Area 1.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     |Near1 < Far2|Far1 > Near2|Right1 < Left2|Left1 > Right2|Areas Intersect?|
                        |:-----------|:-----------|:-------------|:-------------|:---------------|
                        |     1      |     1      |      1       |       1      |      Yes       |
                        |     0      |     x      |      x       |       x      |       No       |
                        |     x      |     0      |      x       |       x      |       No       |
                        |     x      |     x      |      0       |       x      |       No       |
                        |     x      |     x      |      x       |       0      |       No       |

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static boolean EPFAreasIntersect(const EPFArea_t* psArea1, const EPFArea_t* psArea2)
{
  boolean bAreasIntersect = FALSE;

  if ((psArea1->fYRight < psArea2->fYLeft) && (psArea1->fYLeft > psArea2->fYRight) &&
      (psArea1->fXNear  < psArea2->fXFar)  && (psArea1->fXFar  > psArea2->fXNear))
  {
    bAreasIntersect = TRUE;
  }
  else
  {
    bAreasIntersect = FALSE;
  }

  return bAreasIntersect;
}

/*************************************************************************************************************************
  Functionname:         EPFAreaInArea                                                                                */ /*!

  @brief                Check whether one area is inside another area

  @description          The smaller area is inside of the bigger area if the following conditions are fulfilled:
                        - Left Edge of the big area is left of the left edge of the small area.
                        - Right Edge of the big area is right of the right edge of the small area.
                        - Near Edge of the big area is closer than the near edge of the small area.
                        - Far edge of the big area is further away than the far edge of the small area.

  @return               boolean : True if the small area is completely inside of the big area.

  @param[in]            psAreaSmall : Area for which shall be found out if it is inside of a bigger area.
  @param[in]            psAreaBig :   Bigger Area.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     |NearBig < NearSmall|FarBig > FarSmall|RightBig < RightSmall|LeftBig > LeftSmall|Small area in big area?|
                        |:------------------|:----------------|:--------------------|:------------------|:----------------------|
                        |          1        |        1        |          1          |          1        |          Yes          |
                        |          0        |        x        |          x          |          x        |           No          |
                        |          x        |        0        |          x          |          x        |           No          |
                        |          x        |        x        |          0          |          x        |           No          |
                        |          x        |        x        |          x          |          0        |           No          |

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static boolean EPFAreaInArea(const EPFArea_t* psAreaSmall, const EPFArea_t* psAreaBig)
{
  boolean bAreaInArea = FALSE;
   
  if ((psAreaBig->fYLeft > psAreaSmall->fYLeft) && (psAreaBig->fYRight < psAreaSmall->fYRight) &&
      (psAreaBig->fXNear < psAreaSmall->fXNear) && (psAreaBig->fXFar   > psAreaSmall->fXFar))
  {
    bAreaInArea = TRUE;
  }
  else
  {
    bAreaInArea = FALSE;
  }

  return bAreaInArea;
}

/*************************************************************************************************************************
  Functionname:         EPFillTargetDimFromSPC                                                                                */ /*!

  @brief                Fill EPF Object Dimensions

  @description          The function fills a struct of the internal EPF Object representation with values from GenObject List SPC Array
                        @startuml EPFillTargetDimFromSPC.png
                        start
                        if(object size measured?) then(Yes)
                          :1}
                          :initialising Position X & Position Y 
                          with their Min and Max values of 
                          Target Width and Length;
                          :set Width and Lenght of target after 
                          differentiating the Position X Max 
                          with Position X Min and Position Y 
                          Max With Position Y Min from GenObject 
                          properties;
                        else(No)
                          :2}
                        endif
                        stop
                        @enduml
  
  @return               void

  @param[in]            ObjID :            Obj ID of Object to be used as source
  @param[in,out]        pOutEPFObj :       Output EPF Structure to be filled

  @glob_in              ACDC_p_GetEMGenObjGeometry
  @glob_out             None

  @pre                  None
  @post                 None

  @testmethod           @Generic_Testmethods

  @author               Ashok Kumar.CH (ashok.7.kumar@continental-corporation.com)
*************************************************************************************************************************/
static void EPFillTargetDimFromSPC(ObjNumber_t const ObjID, EPFObj_t * const pOutEPFObj )
{
  EM_t_GenObjGeometry const * const pobjGeometry = ACDC_p_GetEMGenObjGeometry(ObjID);
  uint8 ui_PointArrayIndex;
  
  if(    (pobjGeometry->aShapePointStates[0]== EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED)
      && (pobjGeometry->aShapePointStates[1]== EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED)
      && (pobjGeometry->aShapePointStates[2]== EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED)
      && (pobjGeometry->aShapePointStates[3]== EM_GEN_OBJECT_SHAPE_POINT_STATE_EDGE_MEASURED) )
  {
    float32 fPosXmin = EPF_SPC_MAX_VAL;
    float32 fPosYmin = EPF_SPC_MAX_VAL;
    float32 fPosXmax = EPF_SPC_MIN_VAL;
    float32 fPosYmax = EPF_SPC_MIN_VAL;

    for(ui_PointArrayIndex=0u; ui_PointArrayIndex < 4u; ui_PointArrayIndex++)
    {
      fPosXmin = CML_f_Min(fPosXmin,pobjGeometry->aShapePointCoordinates[ui_PointArrayIndex].fPosX);
      fPosYmin = CML_f_Min(fPosYmin,pobjGeometry->aShapePointCoordinates[ui_PointArrayIndex].fPosY);
      fPosXmax = CML_f_Max(fPosXmax,pobjGeometry->aShapePointCoordinates[ui_PointArrayIndex].fPosX);
      fPosYmax = CML_f_Max(fPosYmax,pobjGeometry->aShapePointCoordinates[ui_PointArrayIndex].fPosY);
    }
    pOutEPFObj->fLength = fPosXmax-fPosXmin;
    pOutEPFObj->fWidth  = fPosYmax-fPosYmin;
  }
}

/*************************************************************************************************************************
  Functionname:         EPFFillEPFObj                                                                                */ /*!

  @brief                Fills the kinematics of an EPF specific object.

  @description          Converts information from a GenObject structure to an EPF Object structure.
                        Therefore certain values are modified. Concluding the Objects kinematics are \n
                        predicted into the future for a given time and also stored in the EPF structure.
                        @startuml EPFFillEPFObj_activity.png
                        start
                          if(Class is Pedestrian?) then (Yes)
                            :1}
                            :Assume increased safety distance;
                          else (No)
                            :2}
                            :Assume normal safety distance;
                          endif
                          :Calculate current EPF object kinematics;
                          note left: Position, Velocity & Acceleration in X & Y. >see formulas
                          if (EPF Object is stationary or stopped?) then (Yes)
                            :4}
                            :Set velocities and accelerations
                            to negative values of ego kinematics;
                          else(No)
                            :5}
                          endif
                          #Orange:Calculate EPF object kinematics at t = PredTime:
                          <b>EPFPredictObjectKinematic</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            ObjID :           ID of the object used as source for the EPF object. \range [0,+...[
  @param[in]            fPredTime :       Time up to which the object kinematics shall be predicted. \range [0,+...[ \unit [s]
  @param[in,out]        pOutEPFObj :      Structure to store the EPF specific object information.

  @glob_in              @ref ACDC_p_GetACDCObjectMain \n
                        @ref ACDC_p_GetEgoKinematics\n
                        @ref ACDC_p_GetEgoMovementObjSync \n
                        @ref CD_f_GetLongNecAccel \n
                        @ref ACDC_p_GetObjPositions\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Formula Position:**
                          - Y:  Calculated on base of the Distance to trajectory and the actual distance.
                                If the YawRate grows, DistToTraj is taken more into consideration:\n
                                \f$Fctr = MIN(\frac{|YawRate_{Ego}|}{YawRate_{Max}},1)\f$ \n
                                \f$Y_{EPFObj,Now} = Fctr \cdot Y_{Obj,Now,ToTraj} + (1 - Fctr) \cdot Y_{Obj,Now}\f$
                          - X:  \f$X_{EPFObj,Now} = X_{Obj,Now}\f$
                          .
                        - **Formula Velocity:**
                          - Y:  \f$V_{Y,EPFObj,Now} = V_{Y,Obj,Now,ToTraj}\f$
                          - X:  \f$V_{X,EPFObj,Now} = V_{X,Obj,Now,Rel}\f$
                          .
                        - **Formula Acceleration:**
                          - Y: \f$A_{Y,EPFObj,Now} = A_{Y,Obj,Now,Rel}\f$
                          - X: \f$A_{X,EPFObj,Now} = A_{X,Obj,Now,Rel}\f$

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFFillEPFObj(ObjNumber_t const         ObjID, 
                          fTime_t     const         fPredTime, 
                          EPFObj_t          * const pOutEPFObj )
{
  ACDCObjDescMain_t     const * const pACDCObj     = ACDC_p_GetObjDescMain(ObjID);
  EM_t_GenEbaObjClass   const         eEbaObjClass = ACDC_p_GetEMGenObjQualifiers(ObjID)->eEbaObjClass;

  float32 fRatioDistToTraj = MIN_FLOAT(fABS(ACDC_p_GetEgoKinematics()->fYawRate) / CD_EPF_DIST_TO_TRAJ_YAW_RATE, 1.0f);
  float32 fRatioDistY      = 1.0f - fRatioDistToTraj;
  float32 fDistToTraj      = pACDCObj->TrajRelation.fDistToTraj;
  float32 fDistY           = ACDC_p_GetObjPositions(ObjID)->GenObject.fY;

  pOutEPFObj->sKinNow.fX   = ACDC_p_GetObjPositions(ObjID)->GenObject.fX;
  pOutEPFObj->sKinNow.fVx  = pACDCObj->Movement.Rel.Vel.fX;
  pOutEPFObj->sKinNow.fAx  = pACDCObj->Movement.Rel.Accel.fX;
  pOutEPFObj->sKinNow.fAy  = pACDCObj->Movement.Rel.Accel.fY;
  pOutEPFObj->sKinNow.fY   = (fRatioDistToTraj * fDistToTraj) + (fRatioDistY * fDistY);
  pOutEPFObj->sKinNow.fVy  = pACDCObj->TrajRelation.fVelocityToTraj;

  pOutEPFObj->fWidth       = pACDCObj->Geometry.fWidth;
  pOutEPFObj->fLength      = pACDCObj->Geometry.fLength;
  pOutEPFObj->fSafetyDist  = CD_EPF_OBJ_SAFETY_DIST;
  pOutEPFObj->fANec        = CD_f_GetLongNecAccel(ObjID);

  if (eEbaObjClass != FPS_EBA_CLASS_TRUCK)
  {
    pOutEPFObj->fWidth      = MIN_FLOAT(pOutEPFObj->fWidth, CD_EPF_OBJ_WIDTH_LIMIT);
  }

  if (    (eEbaObjClass == FPS_EBA_CLASS_PEDESTRIAN)
       || (eEbaObjClass == FPS_EBA_CLASS_CYCLIST   ) )
  {
    pOutEPFObj->fSafetyDist = CD_EPF_VULNERABLE_OBJ_SAFETY_DIST;
  }
  else
  {
    pOutEPFObj->fSafetyDist = CD_EPF_OBJ_SAFETY_DIST;
  }

  /*PRQA S 2000 1*/
  if( (ACDC_p_GetEMARSObjMotionAttributes(ObjID)->eDynamicProperty == ARS_OBJECT_PROPERTY_STATIONARY) ||
      (ACDC_p_GetEMARSObjMotionAttributes(ObjID)->eDynamicProperty == ARS_OBJECT_MOVSTATE_STOPPED) )
  {
    SFLMovement_t const * const pEgoDynObjSync = ACDC_p_GetEgoMovementObjSync();
    pOutEPFObj->sKinNow.fVx = -pEgoDynObjSync->Vel.fX;
    pOutEPFObj->sKinNow.fVy = -pEgoDynObjSync->Vel.fY;
    pOutEPFObj->sKinNow.fAx = -pEgoDynObjSync->Accel.fX;
    pOutEPFObj->sKinNow.fAy = -pEgoDynObjSync->Accel.fY;
  }

  EPFPredictObjectKinematic( &(pOutEPFObj->sKinNow), fPredTime, &(pOutEPFObj->sKinPred) );
}

/*************************************************************************************************************************
  Functionname:         EPFPredictObjectKinematic                                                                    */ /*!

  @brief                Predicts the kinematics of an object at a given time.

  @description          The function predicts the kinematic properties of an object based on the 
                        current kinematic properties of that object:
                        - \f$X_{Pred} = V_{X,Now} \cdot t_{Pred} + X_{Now}\f$
                        - \f$Y_{Pred} = V_{Y,Now} \cdot t_{Pred} + Y_{Now}\f$
                        - \f$V_{X,Pred} = A_{X,Now} \cdot t_{Pred} + V_{X,Now}\f$
                        - \f$V_{Y,Pred} = A_{Y,Now} \cdot t_{Pred} + V_{Y,Now}\f$
                        - \f$A_{X,Pred} = A_{X,Now}\f$
                        - \f$A_{Y,Pred} = A_{Y,Now}\f$
                        .
                        The lateral position prediction \f$Y_{Pred}\f$ is subsequently limited to a delta of 
                        @ref CD_EPF_MAX_LAT_PRED_OFFSET regarding to \f$Y_{Now}\f$ by the function @ref EPFLimitAbsValue.

  @return               void

  @param[in]            psKinNow :  Given current kinematics.
  @param[in]            predTime :  Time in the future for which the kinematics shall be calculated. @unit [s] @range [0,+...[
  @param[in,out]        psKinPred : Calculated predicted kinematics at t = predTime.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFPredictObjectKinematic( const CDMovement_t* psKinNow, fTime_t predTime, CDMovement_t* psKinPred )
{
  CDMovement_t sKinOffset;
  sKinOffset.fVx = psKinNow->fAx * predTime;
  sKinOffset.fVy = psKinNow->fAy * predTime;
  sKinOffset.fX  = psKinNow->fVx * predTime;
  sKinOffset.fY  = psKinNow->fVy * predTime;


  /* Limit predicted lateral Offset */
  EPFLimitAbsValue(&sKinOffset.fY, CD_EPF_MAX_LAT_PRED_OFFSET);

  psKinPred->fX  = psKinNow->fX  + sKinOffset.fX;
  psKinPred->fY  = psKinNow->fY  + sKinOffset.fY;
  psKinPred->fVx = psKinNow->fVx + sKinOffset.fVx;
  psKinPred->fVy = psKinNow->fVy + sKinOffset.fVy;
  psKinPred->fAx = psKinNow->fAx;
  psKinPred->fAy = psKinNow->fAy;
}

/*************************************************************************************************************************
  Functionname:         EPFCalcOutputTarget                                                                          */ /*!

  @brief                Calculates information regarding the target object of the EPF calculation.

  @description          Calculates the following information regarding the EPF relevant object:
                        - Distance to the target : \n
                          \f$X_{Target,Out}= X_{Target}\f$
                        - Driven distance until TTC = 0: \n
                          \f$XPred_{Target,Out}=(0.5 \cdot A_{X,Ego} \cdot t_{TTC}^2) + V_{Ego} \cdot t_{TTC}\f$
                        - Obstacle Qualifier = @ref EPF_QUALIFIER_STATE_ACTIVE_PFGS or @ref EPF_QUALIFIER_STATE_ACTIVE_IBRAKE, 
                                               depending on the current hypothesis type.
                        - Target X-Velocity : \n
                          \f$V_{X,Target,Out} = V_{X,Target}\f$
                        - Target X-Acceleration : \n
                          \f$A_{X,Target,Out} = A_{X,Target}\f$
  @return               void

  @param[in]            TargetID :        ID of the relevant object. \range [0,+...[
  @param[in,out]        pEPFOutput :      Output structure of the EPF module.

  @glob_in              @ref ACDC_p_GetObjMovement \n
                        @ref ACDC_p_GetObjPositions \n
                        @ref CD_f_GetTTC3 \n
                        @ref ACDC_p_GetMostRelevantEPFHyp \n
                        @ref ACDC_p_GetEgoMovementObjSync \n
                        @ref CD_f_GetLongNecAccel
  @glob_out             None

  @c_switch_part        @ref FCT_CD_OUTPUT_CUSTOM_INTFVER
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFCalcOutputTarget(ObjNumber_t const         TargetID, 
                                EPFOutput_t       * const pEPFOutput)
{
  SFLMovement_t     const * const pObjMovAbs              = &(ACDC_p_GetObjMovement(TargetID)->Abs);
  eCDHypothesisType_t             eMostRelevantEPFHypType = ACDC_p_GetMostRelevantEPFHyp()->eType;
  fDistance_t                     fTargetDistX            = ACDC_p_GetObjPositions(TargetID)->GenObject.fX;
  fTime_t                         fTargetTTC              = CD_f_GetTTC3(TargetID);
  fVelocity_t                     fEgoVelX                = ACDC_p_GetEgoMovementObjSync()->Vel.fX;
  fAccel_t                        fEgoAccelX              = ACDC_p_GetEgoMovementObjSync()->Accel.fX;

  pEPFOutput->fTargetDistX     = fTargetDistX;
  pEPFOutput->fTargetDistXPred = (0.5f * fEgoAccelX * fTargetTTC * fTargetTTC) + (fEgoVelX * fTargetTTC);
  pEPFOutput->fTargetVx        = pObjMovAbs->Vel.fX;
  pEPFOutput->fTargetAx        = pObjMovAbs->Accel.fX;
#if (FCT_CD_OUTPUT_CUSTOM_INTFVER >= 22u)
  pEPFOutput->fTargetAnecLong  = CD_f_GetLongNecAccel(TargetID);
#endif

  if(    ( eMostRelevantEPFHypType == CDHypothesisType_PedCollision )
      || ( eMostRelevantEPFHypType == CDHypothesisType_PedPass      )
      || ( eMostRelevantEPFHypType == CDHypothesisType_CyclColl     ) )
  {
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierObstacle  = EPF_QUALIFIER_STATE_ACTIVE_PFGS;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierObstacle = EPF_QUALIFIER_STATE_ACTIVE_PFGS;
  }
  else
  {
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierObstacle  = EPF_QUALIFIER_STATE_ACTIVE_IBRAKE;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierObstacle = EPF_QUALIFIER_STATE_ACTIVE_IBRAKE; 
  }

}

/*************************************************************************************************************************
  Functionname:         EPFInitCorridors                                                                             */ /*!

  @brief                Initializes the corridors structure by applying the geometry of the target object.

  @description          Initialize Corridors based on current and predicted Target Position:
                        - Left Corridor: 
                          - Right Edge = Left edge of the objects future movement path.
                          - Left Edge = Maximum corridor width added to the Right edge.
                        - Right Corridor:
                          - Left Edge = Right edge of the objects future movement path.
                          - Right Edge = Maximum corridor width subtracted from to the left edge.
                        @image html CD_EPF_InitCorridors.svg width=800

  @return               void

  @param[in]            psInTarget :  Information about the EPF target object.
  @param[in,out]        psCorridors : Information about the corridors.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFInitCorridors(const EPFObj_t* psInTarget, EPFCorridors_t* psCorridors)
{
  float32 fTargetBlockedAreaLeft, fTargetBlockedAreaRight;

  /* Consider left and right expansion of target now and predicted */
  fTargetBlockedAreaLeft  = MAX_FLOAT( psInTarget->sKinNow.fY, psInTarget->sKinPred.fY ) + (( psInTarget->fWidth / 2.0f) + psInTarget->fSafetyDist);
  fTargetBlockedAreaRight = MIN_FLOAT( psInTarget->sKinNow.fY, psInTarget->sKinPred.fY ) - (( psInTarget->fWidth / 2.0f) + psInTarget->fSafetyDist);

  /* Set initial Corridor Area */
  psCorridors->Left.fYRight  = fTargetBlockedAreaLeft;
  psCorridors->Left.fYLeft   = psCorridors->Left.fYRight + CD_EPF_MAX_LAT_CORR_WIDTH;
  psCorridors->Right.fYLeft  = fTargetBlockedAreaRight;
  psCorridors->Right.fYRight = psCorridors->Right.fYLeft - CD_EPF_MAX_LAT_CORR_WIDTH;

  /* Set Probability of Possibility */
  psCorridors->Left.fProb  = 1.0f;
  psCorridors->Right.fProb = 1.0f;
}

/*************************************************************************************************************************
  Functionname:         EPFReduceCorridorBySection                                                                   */ /*!

  @brief                Reduces the width of an existing corridor according to a given section.

  @description          @image html CD_EPF_ReduceCorridor.svg width=1400

  @return               void

  @param[in]            fSectionYLeft :     Left border of the section by which the corridor shall be reduced.  @unit [m] @range ]-...,+...[
  @param[in]            fSectionYRight :    Right border of the section by which the corridor shall be reduced. @unit [m] @range ]-...,+...[
  @param[in]            eSideToReduceFrom : Corridor side to be reduced by the section. EPF_SIDE_LEFT or EPF_SIDE_RIGHT.
  @param[in,out]        psCorridor :        Corridor that is reduced and returned.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointer is valid.
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFReduceCorridorBySection(float32 fSectionYLeft, float32 fSectionYRight, eEPFSideInt_t eSideToReduceFrom, EPFCorridor_t* psCorridor)
{
  if ( eSideToReduceFrom == EPF_SIDE_LEFT )
  {
    /*****************************/
    /* Reduce from the left side */
    /*****************************/
    if (fSectionYRight >= psCorridor->fYLeft )
    {
      /* Case 1 - Blocked Area is completely left of left Corridor. No Overlap => Do nothing */
    }
    else if((fSectionYLeft >= psCorridor->fYLeft) && (fSectionYRight <= psCorridor->fYLeft) && (fSectionYRight >= psCorridor->fYRight) )
    {
      /* Case 2 - Blocked Area extends into left Corridor from the left => Limit left Corridor from the left */
      psCorridor->fYLeft = fSectionYRight;
    }
    else if((fSectionYLeft <= psCorridor->fYLeft) && (fSectionYRight >= psCorridor->fYRight) )
    {
      /* Case 3 - Corridor encloses blocked Area completely => Limit left Corridor from the left */
      psCorridor->fYLeft = fSectionYRight;
    }
    else if((fSectionYLeft >= psCorridor->fYLeft) && (fSectionYRight <= psCorridor->fYRight) )
    {
      /* Case 4 - Blocked Area encloses Corridor completely => Shrink Corridor to Width 0.0 */
      psCorridor->fYLeft = psCorridor->fYRight;
    }
    else if((fSectionYLeft <= psCorridor->fYLeft) && (fSectionYLeft >= psCorridor->fYRight) && (fSectionYRight <= psCorridor->fYRight) )
    {
      /* Case 5 - Blocked Area extends into left Corridor from the right => Shrink Corridor to Width 0.0 */
      psCorridor->fYLeft = psCorridor->fYRight;
    }
    else if( fSectionYLeft <= psCorridor->fYRight )
    {
      /* Case 6 - Blocked Area is completely right of left Corridor. No Overlap => Do nothing */
    }
    else
    {
      /* Something went very wrong => Think about what happend! */
    }
  } 
  else
  {
    /******************************/
    /* Reduce from the right side */
    /******************************/
    if (fSectionYLeft <= psCorridor->fYRight )
    {
      /* Blocked Area is completely right of right Corridor. No Overlap => Do nothing */
    }
    else if((fSectionYRight <= psCorridor->fYRight) && (fSectionYLeft >= psCorridor->fYRight) && (fSectionYLeft <= psCorridor->fYLeft) )
    {
      /* Blocked Area extends into right Corridor from the right => Limit right Corridor from the right */
      psCorridor->fYRight = fSectionYLeft;
    }
    else if((fSectionYRight >= psCorridor->fYRight) && (fSectionYLeft <= psCorridor->fYLeft) )
    {
      /* Corridor encloses blocked Area completely => Limit right Corridor from the right */
      psCorridor->fYRight = fSectionYLeft;
    }
    else if((fSectionYRight <= psCorridor->fYRight) && (fSectionYLeft >= psCorridor->fYLeft) )
    {
      /* Blocked Area encloses Corridor completely => Shrink Corridor to Width 0.0 */
      psCorridor->fYRight = psCorridor->fYLeft;
    }
    else if((fSectionYRight >= psCorridor->fYRight) && (fSectionYRight <= psCorridor->fYLeft) && (fSectionYLeft >= psCorridor->fYLeft) )
    {
      /* Blocked Area extends into right Corridor from the left => Shrink Corridor to Width 0.0 */
      psCorridor->fYRight = psCorridor->fYLeft;
    }
    else if( fSectionYRight >= psCorridor->fYLeft )
    {
      /* Blocked Area is completely left of right Corridor. No Overlap => Do nothing */
    }
    else
    {
      /* Something went very wrong => Think about what happend! */
    }
  }
}

/*************************************************************************************************************************
  Functionname:         EPFApplyObjToCorridors                                                                       */ /*!

  @brief                Modify Corridors based on given Object

  @description          Modifies a corridors width based on the width, the position and the predicted 
                        movement of a given object. Therefore several areas are created. The way by which an object \n
                        influences a corridor is determined by the sections which it interferes with.
                        @startuml EPFApplyObjToCorridors_activity.png
                        start
                          :Calculate all areas;
                          note left
                            ObjAreaNow, ObjBlockedArea,
                            SafetyZone[Left/Right], SafetyZone[Left/Right]Center,
                            ToleratedZone, ANecZone[Left/Right].
                            >see illustration
                          end note
                          :Calculate area intersections;
                          if(ObjAreaNow is entirely inside ToleratedZone ?) then (Yes)
                            :1}
                            :Corridors are not changed;
                          else(No)
                            if(ObjBlockedArea intersects with SafetyZone[Left/Right] ?) then (Yes)
                              :2}
                              :Reduce left/right corridor by the 
                              intersection width;
                            else(No)
                              :3}
                            endif
                            if(ObjBlockedArea intersects with SafetyZone[Left/Right]Center ?) then (Yes)
                              :4}
                              :Reduce left/right corridor by the 
                              intersection width;
                              :Set the left/right corridors probability to 0;
                            else(No)
                              :5}
                            endif
                            if(ObjAreaNow intersects with ANecZone[Left/Right] ?) then (Yes)
                              :6}
                              :Set the left/right corridors probability to 0;
                            else(No)
                              :7}
                            endif
                          endif

                        stop
                        @enduml
                        @image html CD_EPF_Areas.svg width=1400
                        @image html CD_EPF_Areas2.jpg width=1400
  @return               void

  @param[in]            pInObj :      Pointer to the current EPF object.
  @param[in]            pInTarget :   Pointer to the target EPF object.
  @param[in,out]        psCorridors : Calculated corridor based on all objects.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFApplyObjToCorridors(const EPFObj_t* pInObj, const EPFObj_t* pInTarget, EPFCorridors_t* psCorridors)
{
  EPFArea_t sObjAreaNow;
  EPFArea_t sObjBlockedArea;
  EPFArea_t sSafetyZoneLeft;
  EPFArea_t sSafetyZoneLeftCenter;
  EPFArea_t sSafetyZoneRight;
  EPFArea_t sSafetyZoneRightCenter;
  EPFArea_t sToleratedZone;
  EPFArea_t sANecZoneLeft;
  EPFArea_t sANecZoneRight;
  EPFArea_t sTargetNow;

  boolean bObjInSafetyZoneLeft;
  boolean bObjInSafetyZoneLeftCenter;
  boolean bObjInSafetyZoneRight;
  boolean bObjInSafetyZoneRightCenter;
  boolean bObjInToleratedZone;
  boolean bObjInANecZoneLeft;
  boolean bObjInANecZoneRight;
  boolean bObjOverlapWithTarget;

  /* Determine area that is blocked by object */
  sObjAreaNow.fXNear  = pInObj->sKinNow.fX - pInObj->fSafetyDist;
  sObjAreaNow.fXFar   = pInObj->sKinNow.fX + pInObj->fLength + pInObj->fSafetyDist;
  sObjAreaNow.fYLeft  = pInObj->sKinNow.fY + (( pInObj->fWidth / 2.0f) + pInObj->fSafetyDist);
  sObjAreaNow.fYRight = pInObj->sKinNow.fY - (( pInObj->fWidth / 2.0f) + pInObj->fSafetyDist);
  /* Determine area that is blocked by Target */
  sTargetNow.fXNear  =  pInTarget->sKinNow.fX- pInTarget->fSafetyDist;
  sTargetNow.fXFar   =  pInTarget->sKinNow.fX + (pInTarget->fLength + pInTarget->fSafetyDist);
  sTargetNow.fYLeft  =  pInTarget->sKinNow.fY + (( pInTarget->fWidth * 0.5f) + pInTarget->fSafetyDist);
  sTargetNow.fYRight =  pInTarget->sKinNow.fY - (( pInTarget->fWidth * 0.5f) + pInTarget->fSafetyDist);

  /* Determine area that is blocked by object */
  sObjBlockedArea.fXNear  = MIN_FLOAT( pInObj->sKinNow.fX, pInObj->sKinPred.fX ) - pInObj->fSafetyDist;
  sObjBlockedArea.fXFar   = MAX_FLOAT( pInObj->sKinNow.fX, pInObj->sKinPred.fX ) + pInObj->fLength + pInObj->fSafetyDist;
  sObjBlockedArea.fYLeft  = MAX_FLOAT( pInObj->sKinNow.fY, pInObj->sKinPred.fY ) + (( pInObj->fWidth / 2.0f) + pInObj->fSafetyDist);
  sObjBlockedArea.fYRight = MIN_FLOAT( pInObj->sKinNow.fY, pInObj->sKinPred.fY ) - (( pInObj->fWidth / 2.0f) + pInObj->fSafetyDist);

  /* Determine area of left safety zone */  
  sSafetyZoneLeft.fXNear  = -ACDC_COMMON_EGO_LENGTH;
  sSafetyZoneLeft.fXFar   = MAX_FLOAT( pInTarget->sKinNow.fX, pInTarget->sKinPred.fX ) + pInTarget->fLength;
  sSafetyZoneLeft.fYLeft  = psCorridors->Left.fYLeft;
  sSafetyZoneLeft.fYRight = psCorridors->Left.fYRight;

  /* Determine area of the left center safety zone in front of the target */
  sSafetyZoneLeftCenter.fXNear  = 0.0f;
  sSafetyZoneLeftCenter.fXFar   = pInTarget->sKinNow.fX - pInTarget->fSafetyDist;
  sSafetyZoneLeftCenter.fYLeft  = sSafetyZoneLeft.fYRight;
  sSafetyZoneLeftCenter.fYRight = pInTarget->sKinNow.fY - CD_EPF_CENTER_ZONE_OVERLAP;

  /* Determine area of right safety zone */  
  sSafetyZoneRight.fXNear  = -ACDC_COMMON_EGO_LENGTH;
  sSafetyZoneRight.fXFar   = MAX_FLOAT( pInTarget->sKinNow.fX, pInTarget->sKinPred.fX ) + pInTarget->fLength;
  sSafetyZoneRight.fYLeft  = psCorridors->Right.fYLeft;
  sSafetyZoneRight.fYRight = psCorridors->Right.fYRight;

  /* Determine area of the right center safety zone in front of the target */
  sSafetyZoneRightCenter.fXNear  = 0.0f;
  sSafetyZoneRightCenter.fXFar   = pInTarget->sKinNow.fX - pInTarget->fSafetyDist;
  sSafetyZoneRightCenter.fYLeft  = pInTarget->sKinNow.fY + CD_EPF_CENTER_ZONE_OVERLAP;
  sSafetyZoneRightCenter.fYRight = sSafetyZoneRight.fYLeft;

  /* Determine area of center tolerated zone behind the target */  
  sToleratedZone.fXNear  = pInTarget->sKinNow.fX + pInTarget->fLength;
  sToleratedZone.fXFar   = CD_EPF_MAX_LONG_DIST_FACTOR * pInTarget->sKinNow.fX;
  sToleratedZone.fYLeft  = psCorridors->Left.fYRight + CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET;
  sToleratedZone.fYRight = psCorridors->Right.fYLeft - CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET;

  /* Determine area of the left ANec Zone */  
  sANecZoneLeft.fXNear  = sSafetyZoneLeft.fXFar;
  sANecZoneLeft.fXFar   = CD_EPF_MAX_LONG_DIST_FACTOR * pInTarget->sKinNow.fX;
  sANecZoneLeft.fYLeft  = psCorridors->Left.fYRight + CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET + ACDC_COMMON_EGO_WIDTH;
  sANecZoneLeft.fYRight = psCorridors->Left.fYRight + CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET;

  /* Determine area of the right ANec Zone */  
  sANecZoneRight.fXNear  = sSafetyZoneRight.fXFar;
  sANecZoneRight.fXFar   = CD_EPF_MAX_LONG_DIST_FACTOR * pInTarget->sKinNow.fX;
  sANecZoneRight.fYLeft  = psCorridors->Right.fYLeft - CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET;
  sANecZoneRight.fYRight = psCorridors->Right.fYLeft - CD_EPF_TOLERATED_LAT_DIST_BEHIND_TARGET - ACDC_COMMON_EGO_WIDTH;

  bObjInSafetyZoneLeft        = EPFAreasIntersect(&sObjBlockedArea, &sSafetyZoneLeft);
  bObjInSafetyZoneLeftCenter  = EPFAreasIntersect(&sObjBlockedArea, &sSafetyZoneLeftCenter);
  bObjInSafetyZoneRight       = EPFAreasIntersect(&sObjBlockedArea, &sSafetyZoneRight);
  bObjInSafetyZoneRightCenter = EPFAreasIntersect(&sObjBlockedArea, &sSafetyZoneRightCenter);
  bObjInToleratedZone         = EPFAreaInArea(&sObjAreaNow, &sToleratedZone);
  bObjInANecZoneLeft          = EPFAreasIntersect(&sObjAreaNow, &sANecZoneLeft);
  bObjInANecZoneRight         = EPFAreasIntersect(&sObjAreaNow, &sANecZoneRight);
  bObjOverlapWithTarget       = EPFAreasIntersect(&sObjAreaNow, &sTargetNow);  /* Shape Coordinates Overlap with Current Obj: Obect is Part of Target*/

  if( (bObjInToleratedZone == FALSE)&& (bObjOverlapWithTarget== FALSE)  )
  {
    /* Check whether predicted Object is inside left evasion corridor */ /*PRQA S 2000 1*/
    if (bObjInSafetyZoneLeft != FALSE)
    {
      float32 fSafetyZoneLeftWidth = 0.f;
      float32 fMinSafetyZoneWidth  = ACDC_COMMON_EGO_WIDTH + CD_EPF_EGO_CORRIDOR_SAFETY_EXTENSION;
      EPFReduceCorridorBySection(sObjBlockedArea.fYLeft, sObjBlockedArea.fYRight, EPF_SIDE_LEFT, &(psCorridors->Left));
      fSafetyZoneLeftWidth = fABS(psCorridors->Left.fYLeft - psCorridors->Left.fYRight);
      /*PRQA S 2000 1*/
      if ( fSafetyZoneLeftWidth < fMinSafetyZoneWidth )
      {
        psCorridors->Left.fProb = 0.f;
      }
    }

    /* Check whether predicted Object is inside left center safety zone */ /*PRQA S 2000 1*/
    if (bObjInSafetyZoneLeftCenter != FALSE)
    {
      EPFReduceCorridorBySection(sObjBlockedArea.fYLeft, sObjBlockedArea.fYRight, EPF_SIDE_LEFT, &(psCorridors->Left));
      psCorridors->Left.fProb = 0.f;
    }

    /* Check whether predicted Object is inside right evasion corridor */ /*PRQA S 2000 1*/
    if (bObjInSafetyZoneRight != FALSE)
    {
      float32 fSafetyZoneRightWidth = 0.f;
      float32 fMinSafetyZoneWidth   = ACDC_COMMON_EGO_WIDTH + CD_EPF_EGO_CORRIDOR_SAFETY_EXTENSION;
      EPFReduceCorridorBySection(sObjBlockedArea.fYLeft, sObjBlockedArea.fYRight, EPF_SIDE_RIGHT, &(psCorridors->Right));
      fSafetyZoneRightWidth = fABS(psCorridors->Right.fYLeft - psCorridors->Right.fYRight);
      /*PRQA S 2000 1*/
      if ( fSafetyZoneRightWidth < fMinSafetyZoneWidth )
      {
        psCorridors->Right.fProb = 0.f;
      }
    }

    /* Check whether predicted Object is inside right center safety zone */ /*PRQA S 2000 1*/
    if (bObjInSafetyZoneRightCenter != FALSE)
    {
      EPFReduceCorridorBySection(sObjBlockedArea.fYLeft, sObjBlockedArea.fYRight, EPF_SIDE_RIGHT, &(psCorridors->Right));
      psCorridors->Right.fProb = 0.f;
    }

    /* Check whether predicted Object is inside left ANec Zone */ /*PRQA S 2000 1*/
    if (bObjInANecZoneLeft != FALSE)
    {
      /*PRQA S 2000 1*/
      if (pInObj->fANec < CD_EPF_OBJECT_ANECLONG_THRES)
      {
        psCorridors->Left.fProb = 0.f;
      }
    }

    /* Check whether predicted Object is inside right ANec Zone */ /*PRQA S 2000 1*/
    if (bObjInANecZoneRight != FALSE)
    {
      /*PRQA S 2000 1*/
      if (pInObj->fANec < CD_EPF_OBJECT_ANECLONG_THRES)
      {
        psCorridors->Right.fProb = 0.f;
      }
    }
  }
  else
  {
    /* Object is completely inside tolerated zone - do nothing */
  }
}

/*************************************************************************************************************************
  Functionname:         EPFCalcOutputOrientation                                                                     */ /*!

  @brief                Writes the current curvature to the left and the right evasion corridor.

  @description          Uses the longitudinal velocity and the lateral acceleration to calculate the current curvature.\n
                        The result is written to the curvature information of the left and the right corridor.

  @return               void

  @param[in,out]        pEPFOutput :      Output structure of the EPF Module.

  @glob_in              @ref ACDC_p_GetEgoMovementObjSync
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Formula Curvature:**\n
                          \f$Curv = \frac{A_{Y,Ego}}{V_{X,Ego}^2} \f$\n

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFCalcOutputOrientation(EPFOutput_t *const pEPFOutput)
{
  /* Ego course */
  SFLMovement_t const * const pEgoDynObjSync = ACDC_p_GetEgoMovementObjSync();

  if ( (pEgoDynObjSync->Vel.fX < -C_F32_DELTA) || (pEgoDynObjSync->Vel.fX > C_F32_DELTA) )
  {
    const float32 fCurvature = pEgoDynObjSync->Accel.fY / SQR(pEgoDynObjSync->Vel.fX);
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fCurvature  = fCurvature;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fCurvature = fCurvature;
  }
  else
  {
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fCurvature  = 0.f;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fCurvature = 0.f;
  }
}

/*************************************************************************************************************************
  Functionname:         EPFCalcOutputCorridors                                                                       */ /*!

  @brief                Calculates the current corridors and writes the result into the EPF output structure.

  @description          Calculates the current left and right corridors that describe the space that reamins for 
                        the ego vehicle to pass the target object.
                        @startuml EPFCalcOutputCorridors_acitivty.png
                        start
                          :Fill object data of the target Object
                          into an EPF specific object structure;

                          :Initialize the right and left corridor;

                          partition "Execute for every object" {
                            if(Object is valid obstacle ?) then (Yes)
                              :1}
                              :Fill object data of the current Object
                              into an EPF specific object structure;
                              :Apply object to the current corridors;
                            else(No)
                              :2}
                            endif
                          }
                          :Write corridor values into the output structure;
                          :Set Qualifiers according to type
                          of most important hypothesis;
                          :Filter corridor in case the target
                          has a high lateral velocity;
                        stop
                        @enduml

  @return               void

  @param[in]            TargetID :        ID of the Target object. @range [0,+...[
  @param[in,out]        pEPFOutput :      Output structure of the EPF module, is filled with the calculated corridor values.

  @glob_in              @ref CD_f_GetTTC3 \n
                        @ref ACDC_p_GetMostRelevantEPFHyp \n
                        @ref ACDC_p_ModWorkingData
  @glob_out             @ref ACDC_p_ModWorkingData

  @c_switch_part        @ref ACDC_SIMU
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFCalcOutputCorridors(ObjNumber_t const        TargetID, 
                                   EPFOutput_t       *const pEPFOutput)
{
#ifdef ACDC_SIMU
  ACDCEPFTargetSimu_t * const pEPFTargetSimuData = &(ACDC_p_ModWorkingData()->pSimuData->sGlobData.CD.sEPFTargetSimuData);
#endif
  eCDHypothesisType_t         eMostRelevantEPFHypType = ACDC_p_GetMostRelevantEPFHyp()->eType;
  ObjNumber_t                 currObjID;
  EPFCorridors_t              sCorridors;
  EPFObj_t                    sTarget;
  fTime_t                     fTargetTTC = CD_f_GetTTC3(TargetID);

  EPFFillEPFObj( TargetID, fTargetTTC, &sTarget );
  EPFillTargetDimFromSPC(TargetID,&sTarget); /* Object Dimensions are corrected from Shape Coordinations*/

  EPFInitCorridors(&sTarget, &sCorridors);

  /* Check whether an Object is inside the safety zone */
  for (currObjID = 0; currObjID < EM_N_OBJECTS; currObjID++)
  {
    boolean bObjValidObstacle = EPFObjIsValidObstacle(currObjID, TargetID);

    /*PRQA S 2000 1*/
    if (bObjValidObstacle == TRUE)
    {
      EPFObj_t sCurrObj;

      EPFFillEPFObj( currObjID, fTargetTTC, &sCurrObj );

      EPFApplyObjToCorridors(&sCurrObj, &sTarget, &sCorridors);
    }
  }

  /* Transform internal representation of corridors to output data type */
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fLatDistEgoToBorder      = fABS(sCorridors.Left.fYLeft);
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fLatDistObstacleToBorder = fABS(sCorridors.Left.fYLeft - sCorridors.Left.fYRight);
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fProb                    = sCorridors.Left.fProb;
  

  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fLatDistEgoToBorder      = fABS(sCorridors.Right.fYRight);
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fLatDistObstacleToBorder = fABS(sCorridors.Right.fYRight - sCorridors.Right.fYLeft);
  pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fProb                    = sCorridors.Right.fProb;

  if(    ( eMostRelevantEPFHypType == CDHypothesisType_PedCollision )
      || ( eMostRelevantEPFHypType == CDHypothesisType_PedPass      )
      || ( eMostRelevantEPFHypType == CDHypothesisType_CyclColl     ) )
  {
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierCorridor  = EPF_QUALIFIER_STATE_ACTIVE_PFGS;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierCorridor = EPF_QUALIFIER_STATE_ACTIVE_PFGS;
  }
  else
  {
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].eQualifierCorridor  = EPF_QUALIFIER_STATE_ACTIVE_IBRAKE;
    pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].eQualifierCorridor = EPF_QUALIFIER_STATE_ACTIVE_IBRAKE; 
  }
  EPFLateralVelFilter(TargetID,pEPFOutput);
#ifdef ACDC_SIMU
  pEPFTargetSimuData->iTargetID         = TargetID;
  pEPFTargetSimuData->fSafetyDist       = sTarget.fSafetyDist;
  pEPFTargetSimuData->sTargetKinNow.fX  = sTarget.sKinNow.fX;
  pEPFTargetSimuData->sTargetKinNow.fY  = sTarget.sKinNow.fY;
  pEPFTargetSimuData->sTargetKinPred.fX = sTarget.sKinPred.fX;
  pEPFTargetSimuData->sTargetKinPred.fY = sTarget.sKinPred.fY;
#endif
}

/*************************************************************************************************************************
  Functionname:         EPFSceneValid                                                                                */ /*!

  @brief                Evaluates if a given scene is relevant for the EPF calculation.

  @description          The current situation is seen as invalid, if one of the following criteria is fulfilled:
                        - The ID of the Relevant Object is invalid (=below 0).
                        - The TTC of the relevant object is above @ref CD_EPF_MAX_TTC.
                        - The Ego velocity is below @ref CD_EPF_MIN_V_EGO or above @ref CD_EPF_MAX_V_EGO.
                        - The Distance to Target is negative (=below 0) or above @ref CD_EPF_MAX_LONG_DIST_TO_TARGET.
                        .
                        In all other cases the situation is considered as relevant.

  @return               void

  @param[in]            RelObjID :        ID of the relevant object. @range [0,+...[
  @param[in,out]        pbOutSceneValid : Flag indicating if the current situation is relevant for the EPF 
                                          calculation (True) or not (False).

  @glob_in              @ref CD_f_GetTTC3 \n
                        @ref ACDC_p_GetEgoMovementObjSync \n
                        @ref ACDC_p_GetObjPositions\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFSceneValid(ObjNumber_t const        RelObjID, 
                          boolean           *const pbOutSceneValid)
{

  *pbOutSceneValid = TRUE;

  /* Check whether Target is available */ /*PRQA S 2000 1*/
  if ( RelObjID < 0 )
  {
    *pbOutSceneValid = FALSE;
  }
  else
  {
    float32 const fDistX = ACDC_p_GetObjPositions(RelObjID)->GenObject.fX;
    if (    (      CD_f_GetTTC3(RelObjID)                      > CD_EPF_MAX_TTC                   )  /* Limit Calculation of EPF based on TTC of relevant Object*/
         || (    ( ACDC_p_GetEgoMovementObjSync()->Vel.fX <  CD_EPF_MIN_V_EGO               )    /* Limit Calculation of EPF based on minimum and maximum ego velocity */
              || ( ACDC_p_GetEgoMovementObjSync()->Vel.fX  > CD_EPF_MAX_V_EGO               ) )
         || (    ( fDistX                                     <  0.f                            )    /* Avoid reaction on objects with negative or too large longitudinal relative distance */
              || ( fDistX                                      > CD_EPF_MAX_LONG_DIST_TO_TARGET ) ) )
    {
      *pbOutSceneValid = FALSE;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         EPFObjIsValidObstacle                                                                        */ /*!

  @brief                Checks whether a given object is a valid obstacle or not.

  @description          @startuml EPFObjIsValidObstacle_activity.png
                        start
                          if(ObjID is TargetID ?) then (Yes)
                            :1}
                            :Object is no valid obstacle;
                          elseif(Objects is unknown \nAND POE is below a high threshold?) then (Yes)
                            :2}
                            :Object is no valid obstacle;
                          elseif(POE is below a medium threshold?) then (Yes)
                            :3}
                            :Object is no valid obstacle;
                          elseif(Object maintenance state is deleted ?) then (Yes)
                            :4}
                            :Object is no valid obstacle;
                          else (No)
                            :5}
                            :Object is a valid obstacle;
                          endif
                        stop
                        @enduml

  @return               boolean : Indicates if an object is a valid obstacle (True) or not (False).

  @param[in]            ObjID :             ID of the object which shall be checked. \range [0,+...[
  @param[in]            TargetID :          ID of the current target object. \range [0,+...[

  @glob_in              @ref ACDC_p_GetEMGenObj\n
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static boolean EPFObjIsValidObstacle(ObjNumber_t const ObjID,
                                     ObjNumber_t const TargetID)
{
  EM_t_GenObject const * const pEMObject         = ACDC_p_GetEMGenObj(ObjID);
  uint8          const         uiPoE             = pEMObject->Qualifiers.uiProbabilityOfExistence;
  boolean                      bObjValidObstacle = TRUE;
  
  /* Check whether Object is not Target */
  /*PRQA S 2000 1*/
  if ( ObjID == TargetID )
  {
    bObjValidObstacle = FALSE;
  }

  /* Check whether Object is not unknown */
  /* POE is checked to ensure that there is free space for evasion */
  if (pEMObject->Qualifiers.eEbaObjClass == FPS_EBA_CLASS_UNKNOWN)
  {
    /*PRQA S 2000 1*/
    if ( uiPoE < CD_EPF_POINT_OBSTACLE_MIN_POE )
    {
      bObjValidObstacle = FALSE;
    }
  }
  else
  {
    /*PRQA S 2000 1*/
    if ( uiPoE < CD_EPF_OBSTACLE_MIN_POE )
    {
      bObjValidObstacle = FALSE;
    }
  }

  /* Check whether Objects is not deleted */
  /*PRQA S 2000 1*/
  if (pEMObject->General.eMaintenanceState == EM_GEN_OBJECT_MT_STATE_DELETED)
  {
    bObjValidObstacle = FALSE;
  }
  
  return bObjValidObstacle;
}

#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
/*************************************************************************************************************************
  Functionname:         EPFFreezeCorridors                                                                           */ /*!

  @brief                Remembers last corridor in case the TTb or TTS of the target object get to high.

  @description          Checks the TTB and TTS of the target object. If one of both is above a certain threshold, 
                        the current EPF output is stored in the global @ref asFrozenCorridors. In the following cycles \n
                        the value of asFroen Corridors is kept and written to the output structure. This behavior is 
                        ended once the TTB and TTS both drop below their thresholds.

  @return               void

  @param[in]            TargetID :        ID of the EPF target object. @range [0,+...[
  @param[in,out]        pEPFOutput :      Output structure of the EPF module.

  @glob_in              @ref CD_f_GetTTBDynAcute \n
                        @ref CD_f_GetTTSAcute \n
                        @ref ACDC_p_GetEPFCorridorData 
  @glob_out             @ref ACDC_p_ModEPFCorridorData 

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF \n
                        @ref CD_EPF_CORRIDOR_FREEZE

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFFreezeCorridors(ObjNumber_t const        TargetID, 
                               EPFOutput_t       *const pEPFOutput)
{
  fTime_t fTargetTTB   = CD_f_GetTTBDynAcute(TargetID);
  fTime_t fTargetTTS   = CD_f_GetTTSAcute(TargetID);
  boolean  bFreezeValid = TRUE;
  EPFCorridorData_t * const pEPFCOrr = ACDC_p_ModEPFCorridorData();

  /*PRQA S 2000 1*/
  if( fTargetTTB > CD_EPF_CORRIDOR_FREEZE_TTB_THRES )
  {
    bFreezeValid = FALSE;
  }

  /*PRQA S 2000 1*/
  if( fTargetTTS > CD_EPF_CORRIDOR_FREEZE_TTS_THRES )
  {
    bFreezeValid = FALSE;
  }
    
  if (bFreezeValid == TRUE)
  {

    /*PRQA S 2000 1*/
    if (pEPFCOrr->bCorridorFreezeActive == FALSE)
    {
      /* Corridors have not been remembered yet. So remember them */
      pEPFCOrr->asFrozenCorridors[0].eQualifierCorridor       = pEPFOutput->EPFEvasionCorridor[0].eQualifierCorridor;
      pEPFCOrr->asFrozenCorridors[0].eQualifierObstacle       = pEPFOutput->EPFEvasionCorridor[0].eQualifierObstacle;
      pEPFCOrr->asFrozenCorridors[0].fCurvature               = pEPFOutput->EPFEvasionCorridor[0].fCurvature;
      pEPFCOrr->asFrozenCorridors[0].fHeading                 = pEPFOutput->EPFEvasionCorridor[0].fHeading;
      pEPFCOrr->asFrozenCorridors[0].fLatDistEgoToBorder      = pEPFOutput->EPFEvasionCorridor[0].fLatDistEgoToBorder;
      pEPFCOrr->asFrozenCorridors[0].fLatDistObstacleToBorder = pEPFOutput->EPFEvasionCorridor[0].fLatDistObstacleToBorder;
      pEPFCOrr->asFrozenCorridors[0].fProb                    = pEPFOutput->EPFEvasionCorridor[0].fProb;

      pEPFCOrr->asFrozenCorridors[1].eQualifierCorridor       = pEPFOutput->EPFEvasionCorridor[1].eQualifierCorridor;
      pEPFCOrr->asFrozenCorridors[1].eQualifierObstacle       = pEPFOutput->EPFEvasionCorridor[1].eQualifierObstacle;
      pEPFCOrr->asFrozenCorridors[1].fCurvature               = pEPFOutput->EPFEvasionCorridor[1].fCurvature;
      pEPFCOrr->asFrozenCorridors[1].fHeading                 = pEPFOutput->EPFEvasionCorridor[1].fHeading;
      pEPFCOrr->asFrozenCorridors[1].fLatDistEgoToBorder      = pEPFOutput->EPFEvasionCorridor[1].fLatDistEgoToBorder;
      pEPFCOrr->asFrozenCorridors[1].fLatDistObstacleToBorder = pEPFOutput->EPFEvasionCorridor[1].fLatDistObstacleToBorder;
      pEPFCOrr->asFrozenCorridors[1].fProb                    = pEPFOutput->EPFEvasionCorridor[1].fProb;

      pEPFCOrr->bCorridorFreezeActive = TRUE;
    }

    /* Apply frozen Corridors to output */
    pEPFOutput->EPFEvasionCorridor[0].eQualifierCorridor       = pEPFCOrr->asFrozenCorridors[0].eQualifierCorridor;
    pEPFOutput->EPFEvasionCorridor[0].eQualifierObstacle       = pEPFCOrr->asFrozenCorridors[0].eQualifierObstacle;
    pEPFOutput->EPFEvasionCorridor[0].fCurvature               = pEPFCOrr->asFrozenCorridors[0].fCurvature;
    pEPFOutput->EPFEvasionCorridor[0].fHeading                 = pEPFCOrr->asFrozenCorridors[0].fHeading;
    pEPFOutput->EPFEvasionCorridor[0].fLatDistEgoToBorder      = pEPFCOrr->asFrozenCorridors[0].fLatDistEgoToBorder;
    pEPFOutput->EPFEvasionCorridor[0].fLatDistObstacleToBorder = pEPFCOrr->asFrozenCorridors[0].fLatDistObstacleToBorder;
    pEPFOutput->EPFEvasionCorridor[0].fProb                    = pEPFCOrr->asFrozenCorridors[0].fProb;

    pEPFOutput->EPFEvasionCorridor[1].eQualifierCorridor       = pEPFCOrr->asFrozenCorridors[1].eQualifierCorridor;
    pEPFOutput->EPFEvasionCorridor[1].eQualifierObstacle       = pEPFCOrr->asFrozenCorridors[1].eQualifierObstacle;
    pEPFOutput->EPFEvasionCorridor[1].fCurvature               = pEPFCOrr->asFrozenCorridors[1].fCurvature;
    pEPFOutput->EPFEvasionCorridor[1].fHeading                 = pEPFCOrr->asFrozenCorridors[1].fHeading;
    pEPFOutput->EPFEvasionCorridor[1].fLatDistEgoToBorder      = pEPFCOrr->asFrozenCorridors[1].fLatDistEgoToBorder;
    pEPFOutput->EPFEvasionCorridor[1].fLatDistObstacleToBorder = pEPFCOrr->asFrozenCorridors[1].fLatDistObstacleToBorder;
    pEPFOutput->EPFEvasionCorridor[1].fProb                    = pEPFCOrr->asFrozenCorridors[1].fProb;
  }
  else
  {
    pEPFCOrr->bCorridorFreezeActive = FALSE;
    EPFResetCorridors();
  }
}
#endif /* CD_EPF_CORRIDOR_FREEZE */

/*************************************************************************************************************************
  Functionname:         EPFLateralVelFilter                                                                          */ /*!

  @brief                Corrects the corridor probability for a side depending on the targets lateral velocity.

  @description          Sets the corridor probability for a certain side to 0 if the targets lateral velocity to 
                        this side is above @ref CD_EPF_LATERAL_VELOCITY_THRESHOLD.

  @return               void

  @param[in]            TargetID :        ID of the Target object. \range [0,+...[
  @param[in,out]        pEPFOutput :      EPF Output structure.

  @glob_in              @ref ACDC_p_GetObjMovement
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  Assure that pointers are valid.
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
static void EPFLateralVelFilter(ObjNumber_t const         TargetID,
                                EPFOutput_t       * const pEPFOutput)
{
  float32 const fTargetVelY   = ACDC_p_GetObjMovement(TargetID)->Abs.Vel.fY;

  if(fABS(fTargetVelY) > CD_EPF_LATERAL_VELOCITY_THRESHOLD)
  {
    if(fTargetVelY > 0.0f )
    {
       pEPFOutput->EPFEvasionCorridor[EPF_SIDE_LEFT].fProb = 0.0f;
    }
    else 
    {
      pEPFOutput->EPFEvasionCorridor[EPF_SIDE_RIGHT].fProb = 0.0f;
    }
  }
}

/*************************************************************************************************************************
  Functionname:         EPFProcess                                                                                   */ /*!

  @brief                Main function of the EPF module. Calculates a corridor width that can be 
                        used by the ego vehicle for evasion movements.

  @description          Checks if the current scenario is relevant for an EPF calculation. If this is the case, 
                        a curvature is calculated (@ref EPFCalcOutputOrientation) and the output target information 
                        is filled (@ref EPFCalcOutputTarget). \n
                        Subsequently free corridors between the target objects and its neighbor 
                        objects are calculated (@ref EPFCalcOutputCorridors).\n
                        Concluding the function @ref EPFFreezeCorridors approves whether the corridor information should be 
                        updated this cycle, or the information from the last cycle should be used.

  @return               void

  @param[in]            RelObjID :        ID of the EPF target object. @range [0,+...[
  @param[in,out]        pEPFOutput :      Output structure of the EPF module.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModEPFCorridorData

  @c_switch_part        @ref CD_EPF_CORRIDOR_FREEZE
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_EPF

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined

  @testmethod           @Generic_Testmethods

  @author               Matthias Thomi
*************************************************************************************************************************/
void EPFProcess(ObjNumber_t const RelObjID, EPFOutput_t *const pEPFOutput)
{
  boolean bSceneValid;
  EPFResetOutput(pEPFOutput);
  EPFSceneValid(RelObjID, &bSceneValid);

  /*PRQA S 2000 1*/
  if ( bSceneValid == TRUE )
  {
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_EPF, 0);
    EPFCalcOutputOrientation(pEPFOutput);
    EPFCalcOutputTarget(RelObjID, pEPFOutput);
    EPFCalcOutputCorridors(RelObjID, pEPFOutput);
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
    EPFFreezeCorridors(RelObjID, pEPFOutput);
#endif /* CD_EPF_CORRIDOR_FREEZE */
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd,  ACDC_RTA_CD_EPF, 0);
  }
#if defined(CD_EPF_CORRIDOR_FREEZE) && (CD_EPF_CORRIDOR_FREEZE == SWITCH_ON)
  else
  {
    ACDC_p_ModEPFCorridorData()->bCorridorFreezeActive = FALSE;
  }
#endif /* CD_EPF_CORRIDOR_FREEZE */
}

///@}
#endif /* #if (CD_USE_EPF) */
#endif /*(ACDC_CFG_CD)*/

