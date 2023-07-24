/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypcutin.c

DESCRIPTION:               Implementation of the cut in hypothesis

AUTHOR:                    $Author: Kramer, Andreas (uidv8254) $

CREATION DATE:             $Date: 2018/10/10 17:57:31CEST $

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.7

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_CUT_IN_HYPOTHESIS)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\defgroup cd_hypcutin HypCutin
\ingroup cd

\brief              The Cut In Hypothesis describes a scenario in which an object changes from an adjacent 
                    lane to the ego lane. On this hypothesis usually follows a Run Up hypothesis.\n\n
\description        The module provides two external functions:
                    - The function \ref CDHypoCutInMain handles the main processing steps of the hypothesis. 
                      It calls the object filter and the probability calculation function.
                    - The function \ref CDHypoCutInInitInternalData initializes all data that is used inside 
                      of the module.
                    \image html RunUpHyp.jpg width=400cm
\{
*/
/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoCutInObjectFilter (ObjNumber_t  const  iObjectIndex);


static void CDHypoCutInCalculateProb (ObjNumber_t       const         iObjectIndex,
                                      CDIntHypothesis_t       * const pHypothesis);


/*************************************************************************************************************************
  Functionname:         CDHypoCutInObjectFilter                                                                      */ /*!

  @brief                Checks if the object is relevant for the cut in hypothesis.

  @description          To open a CutIn Hypothesis, the following criteria have to be fulfilled :
                        - The Objects distance to trajectory has to be below threshold
                        - The Objects Dynamic property has to be moving
                        - The Objects TTC, TTB or ANec Long have to be below threshold
                        - The product of objects distance to trajectory and the variation is below 0

  @return               boolean: True if the object is relevant

  @param[in]            iObjectIndex :        Index of the considered object. \range [0,+...[
  @param[in]            *pCurrentObjIntern :  Array of internal object data.

  @glob_in              @ref ACDC_p_GetObjTrajRelation \n
                        @ref ACDC_p_GetEMGenObjAttributes \n
                        @ref CD_f_GetTTC \n
                        @ref CD_f_GetTTBDynPre \n
                        @ref CD_f_GetTTBDynAcute \n
                        @ref CD_f_GetLongNecAccel
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CUT_IN_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Martin Kallnik
*************************************************************************************************************************/
static boolean CDHypoCutInObjectFilter (ObjNumber_t const iObjectIndex)
{


  float32            const         fDistTraj   = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTraj;
  float32            const         fDistGrad   = ACDC_p_GetObjTrajRelation(iObjectIndex)->fDistToTrajVar;
  CDObj_Hypothesis_t const * const pObjHypData = ACDC_p_GetObjHypothesisData(iObjectIndex);
  boolean                          bReturn;

  /* Allow hypothesis if
  - object has min. required quality
  - object lateral distance is less than max. distance
  - object is car or truck
  - object is in or close to course  
  - object has min. required TTC and TTB
  - braking is required if object was moving before
  - object is moving towards course (not away)
  - previous cut-in hypothesis is kept until long. deceleration is greater than threshold
   */
  if (    (           fABS(fDistTraj)                                              <  CD_PASS_MAX_LAT_DIST         )
       && (           ACDC_p_GetEMGenObjAttributes(iObjectIndex)->eDynamicProperty == (EM_t_GenObjDynamicProperty)EM_GEN_OBJECT_DYN_PROPERTY_MOVING )
       && (    (      CD_f_GetTTC(iObjectIndex)                                    <  CD_CUT_IN_TTC_THRES        )
            || (      CD_f_GetTTBDynPre(iObjectIndex)                              <  CD_CUT_IN_TTB_THRES        )
            || (      CD_f_GetTTBDynAcute(iObjectIndex)                            <  CD_CUT_IN_TTB_THRES        )
            || (    ( CD_f_GetLongNecAccel(iObjectIndex)                           <  CD_CUT_IN_ANECLONG_THRES )
                 && ( pObjHypData->HypothesisHist.CutIn                            == 1                        ) ) )
       && (          (fDistTraj * fDistGrad )                                      <  0                            ) )
  {
    bReturn = TRUE;
  }
  else
  {
    bReturn = FALSE;
  }
  return bReturn;
}


/*************************************************************************************************************************
  Functionname:         CDHypoCutInCalculateProb                                                                     */ /*!

  @brief                Calculates the hypothesis probability for the cut in hypothesis.

  @description          The function follows the subsequently illustrated steps:
                        @startuml CDHypoCutInCalculateProb_activity.png
                        start
                        partition "Quality Now /Quality TTC" {
                          #Orange:Calculate current overlap of ego 
                          trajectory with object:
                          <b>CDCalculateInlapAtTime</b> >
                          note left: Based on ego trajectory width and DistToTrajMin/Max
                          :Add Variance to the VelocityToTrajectory;
                          #Orange:Predict object to TTC:
                          <b>EMPPredictTrajRelation<b> >
                          :Set DistToTraj to 0 if object crosses 
                          the EgoTrajectory during prediction;


                          #Orange:Calculate Inlap at TTC:
                          <b>CDCalculateInlap</b> >

                          :Calculate Quality Now and Quality TTC 
                          based on the current and on the 
                          predicted object occupancies;
                          note left: >see formula "Quality TTC" and "Quality Now"
                        }
                        partition "Trajectory Quality" {
                          :Calculate quality based on current curvature;
                          note left
                            The higher the curvature, the lower the quality
                            >see formula "Trajectory Quality"
                          end note
                        }
                        partition "Kinematic Quality" {
                          :Calculate Quality based on distance,
                          speed and acceleration;
                          note left: >see formula "Kinematic Quality"
                        }
                        :Calculate Overall Hypothesis Probability;
                        note left: >see formula "Cut In Hypothesis Probability"

partition #LightBlue **CD_USE_BRAKE_JERK_TTC**{
                        #Orange:Apply the brake jerk factor to the Probability:
                        <b>CD_f_GetTTCBrakeJerkFactor<b> >
}
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :    Index of the considered object. \range[0,+...[
  @param[in,out]        pHypothesis :     Hypothesis for which the probability shall be calculated.

  @glob_in              @ref ACDC_p_GetVDYDynObjSync\n
                        @ref ACDC_p_GetVDYDynRaw\n
                        @ref CD_f_GetTTC\n
                        @ref CD_f_GetTTCBrakeJerkFactor\n
                        @ref ACDC_p_GetObjTrajRelation\n
                        @ref ACDC_p_GetObjDesc\n
  @glob_out             None

  @c_switch_part        @ref CD_USE_BRAKE_JERK_TTC
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CUT_IN_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     
                        - **Quality Now**: \n
                          Converts the current occupancy into a quality between 0 and 1. \n
                          \f$Q_{now} = \frac{Overlap_{now} - Threshold_{now0}}{Threshold_{now1}-Threshold_{now0}}\f$\n
                        - **Quality TTC**: \n
                          Converts the occupancy at TTC into a quality between 0 and 1. \n
                          \f$Q_{ttc} = \frac{Overlap_{ttc} - Threshold_{ttc0}}{Threshold_{ttc1}-Threshold_{ttc0}}\f$\n
                        - **Kinematic Quality**: \n
                          As the name declames, this quality refers to the objects kinematics. Each of the three \n
                          attributes distance, velocity and acceleration is evaluated by a linear function and converted \n
                          into a quality. The three qualities are multiplied. The Result is the QualityDistSpeedAccel.\n
                          \f$Q_{kin} = Q_{Dist} \cdot Q_{Speed} \cdot Q_{Accel}\f$
                        - **Trajectory Quality**:\n
                          Translates the current curvature into a probability between 0 and 1. \n
                          \f$Q_{traj} = 1 - \frac{Curvature - Threshold_{curv0}}{Threshold_{curv1}-Threshold_{curv0}}\f$
                        - **Cut In Hypothesis Probability:**\n
                          \f$P_{CutIn} = Q_{now} \cdot Q_{ttc} \cdot Q_{traj} \cdot Q_{kin}\f$

  @testmethod           @Generic_Testmethods

  @author               Martin Kallnik
*************************************************************************************************************************/
static void CDHypoCutInCalculateProb (ObjNumber_t      const         iObjectIndex,
                                      CDIntHypothesis_t      * const pHypothesis)
{

  ACDCObjToTrajRelation_t CurrCutInTrajRelation = *ACDC_p_GetObjTrajRelation(iObjectIndex);
  ACDCObjToTrajRelation_t PredCutInTrajRelation = CurrCutInTrajRelation;
  float32 fInlapNow;
  float32 fInlapVarNow;
  float32 fInlapTTC;
  float32 fInlapVarTTC;
  float32 fObjectOccupancyNow;
  float32 fObjectOccupancyTTC;
  float32 fQualityNow;
  float32 fQualityTTC;
  float32 fQualityTraj;
  float32 fQualityDistSpeedAccel;
  float32       fDistToTrajPred;
  /* As only DistToTrajMin and DistToTrajMax are relevant for the overlap, the DistToTraj is considered the average of both values */
  float32 const fDistToTrajCurr       = (CurrCutInTrajRelation.fDistToTrajMax + CurrCutInTrajRelation.fDistToTrajMin) / 2.f;
  float32       fObjectWidthPred;
  float32 const fCurrentCurvature     = ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve; /* Get Curvature at current Position */;
  float32       fTTCPred              = CD_f_GetTTC(iObjectIndex);
  
  /* The function CDCalcGeometryVarianceFromShapePoints can be used instead of CD_CONST_OBJ_WIDTH_VAR but requires more runtime */
  const float32 fObjectWidthVar = CD_CONST_OBJ_WIDTH_VAR;
  const float32 fObjectWidth    = MAX(C_F32_DELTA, CurrCutInTrajRelation.fDistToTrajMax - CurrCutInTrajRelation.fDistToTrajMin); 

  fTTCPred                      = MIN(fTTCPred, CD_CUT_IN_MAX_PRED_TIME);

  CDCalculateInlapAtTime(currObject, 0.f, CD_CUT_IN_TRACK_WIDTH_NOW, &fInlapNow, &fInlapVarNow);

  if (CurrCutInTrajRelation.fVelocityToTraj >= 0.f)
  {
    CurrCutInTrajRelation.fVelocityToTraj = MAX(0.f,CurrCutInTrajRelation.fVelocityToTraj - CurrCutInTrajRelation.fVelocityToTrajVar);
  }
  else
  {
    CurrCutInTrajRelation.fVelocityToTraj = MIN(0.f,CurrCutInTrajRelation.fVelocityToTraj + CurrCutInTrajRelation.fVelocityToTrajVar);
  }

  EMPPredictTrajRelation(&CurrCutInTrajRelation, fTTCPred, &PredCutInTrajRelation);

  /* As only DistToTrajMin and DistToTrajMax are relevant for the overlap, the DistToTraj is considered to be the average of both values */
  fDistToTrajPred = (PredCutInTrajRelation.fDistToTrajMin + PredCutInTrajRelation.fDistToTrajMax)/2.f;
  if ( CML_f_Sign(fDistToTrajPred) != CML_f_Sign(fDistToTrajCurr))
  {
    /* Avoid cut through by checking if the current and the predicted dist to traj are on different sides of the ego trajectory */
    PredCutInTrajRelation.fDistToTrajMax -= fDistToTrajPred;
    PredCutInTrajRelation.fDistToTrajMin -= fDistToTrajPred;
  }

  fObjectWidthPred = MAX(C_F32_DELTA,(PredCutInTrajRelation.fDistToTrajMax - PredCutInTrajRelation.fDistToTrajMin));

  CDCalculateInlap(fDistToTrajPred        , PredCutInTrajRelation.fDistToTrajVar, 
                   CD_CUT_IN_TRACK_WIDTH, 0.f, 
                   fObjectWidthPred,      SQR(fObjectWidthVar),
                   &fInlapTTC,            &fInlapVarTTC);

  //Assure that Object width and ObjectWidthPred are not 0!
  fObjectOccupancyNow = fInlapNow / fObjectWidth     - fInlapVarNow / SQR(fObjectWidth);
  fObjectOccupancyTTC = fInlapTTC / fObjectWidthPred - fInlapVarTTC / SQR(fObjectWidthPred);

  /* calculate quality depending on current occupancy of object */
  fQualityNow = CML_f_BoundedLinInterpol2(fObjectOccupancyNow,CD_CUT_IN_THRES_OCC_0_NOW,CD_CUT_IN_THRES_OCC_1_NOW,0.f,1.f);
  fQualityTTC = CML_f_BoundedLinInterpol2(fObjectOccupancyTTC,CD_CUT_IN_THRES_OCC_0_TTC,CD_CUT_IN_THRES_OCC_1_TTC,0.f,1.f);

  /* calculate quality depending on current occupancy of trajectory */ 
  /* decrease sureness if trajectory curvature has the same sign as the object position*/
  if ( (fCurrentCurvature * fDistToTrajCurr) < 0.f ) 
  {
    /* trajectory point away from object*/
    fQualityTraj = 1.0f;
  }
  else
  {
    fQualityTraj = CML_f_BoundedLinInterpol2(fABS(fCurrentCurvature), CD_CUT_IN_THRES_TRAJC0_1, CD_CUT_IN_THRES_TRAJC0_0, 1.f, 0.f);
  }


  /* calculate quality depending on distance depending acceleration */  
  fQualityDistSpeedAccel = 
      CML_f_BoundedLinInterpol2(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.Positions.GenObject.fX,       CD_RUN_UP_THRES_DIST_X0,  CD_RUN_UP_THRES_DIST_X1,  CD_RUN_UP_THRES_DIST_Y0,  CD_RUN_UP_THRES_DIST_Y1)
    * CML_f_BoundedLinInterpol2(ACDC_p_GetVDYDynRaw()->Longitudinal.VeloCorr.corrVelo, CD_RUN_UP_THRES_SPEED_X0, CD_RUN_UP_THRES_SPEED_X1, CD_RUN_UP_THRES_SPEED_Y0, CD_RUN_UP_THRES_SPEED_Y1)
    * CML_f_BoundedLinInterpol2(ACDC_p_GetObjDesc(iObjectIndex)->ObjDescMain.Movement.Rel.fAccelX,     CD_RUN_UP_THRES_ACCEL_X0, CD_RUN_UP_THRES_ACCEL_X1, CD_RUN_UP_THRES_ACCEL_Y0, CD_RUN_UP_THRES_ACCEL_Y1);
  fQualityDistSpeedAccel = MIN_FLOAT(1.0f, fQualityDistSpeedAccel);/*PRQA S 3121*/ /*the upper limit of qualities are 1*/

  /* final hypothesis probability */
  /*the upper limit of qualities are 1*/
  /*PRQA S 3121 1*/
  pHypothesis->fHypothesisProbability = MIN_FLOAT( 1.0f, ( fQualityNow * fQualityTTC * fQualityTraj ) ) * fQualityDistSpeedAccel;

#if defined(CD_USE_BRAKE_JERK_TTC) && (CD_USE_BRAKE_JERK_TTC == SWITCH_ON)
  /* reduce hypothesis probability in case of brake jerk */
  pHypothesis->fHypothesisProbability *= CD_f_GetTTCBrakeJerkFactor(iObjectIndex);
#endif /* CD_USE_BRAKE_JERK_TTC */
}

/*************************************************************************************************************************
  Functionname:         CDHypoCutInMain                                                                              */ /*!

  @brief                Handles the main processing steps of the Collision hypothesis.

  @description          Handles the cut in hypothesis by executing the common steps for a hypothesis generation 
                        (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: \ref CDHypoCutInObjectFilter
                        2. Call of the Hypothesis probability calculation: \ref CDHypoCutInCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: \ref CDHypSelCreateInternalHypotheses
                        \image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. \range [0,+...[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history.
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        @ref EM_GEN_OBJECT_INTFVER \n
                        @ref CD_USE_EM_FPS_OBJCLASS
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_CUT_IN_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Martin Kallnik
*************************************************************************************************************************/
void CDHypoCutInMain(ObjNumber_t const iObjectIndex, boolean const bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;
  CDObj_Hypothesis_t * const pObjHypData   = ACDC_p_ModObjHypothesisData(iObjectIndex);
    
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CutIn);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CutIn);

  /* handle only hypothesis relevant objects */
  if( bObjFilterMatched != FALSE )
  {
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_CUTIN_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if  ( CDHypoCutInObjectFilter(iObjectIndex) != FALSE )
    {
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CutIn);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_CutIn);

      /* calculate Hypothesis probability */
      CDHypoCutInCalculateProb( iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if ( Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB )
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CutIn);
        pObjHypData->HypothesisHist.CutIn = 1u;
        CDHypSelCreateInternalHypotheses(&Hypothesis);
      }
      else
      {
        pObjHypData->HypothesisHist.CutIn = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.CutIn = 0u;
    }
      ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_CUTIN_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
  }
  else
  {
    pObjHypData->HypothesisHist.CutIn = 0u;
  }
}

/*************************************************************************************************************************
  Functionname:         CDHypoCutInInitInternalData                                                                  */ /*!

  @brief                Clears internal data of the cut In hypothesis object information (Currently not implemented)

  @description          Clears internal data of the cut-in hypothesis object information (Currently not implemented)

  @return               void

  @param[in]            iObjectIndex: Object index

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_CUT_IN_HYPOTHESIS \n
                        @ref ACDC_CFG_CD

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Dominik Froehlich | dominik.1.froehlich@continental-corporation.com
*************************************************************************************************************************/
void CDHypoCutInInitInternalData(ObjNumber_t const iObjectIndex)
{
  _PARAM_UNUSED(iObjectIndex);
}
///\}
#endif  /* #if (CD_USE_CUT_IN_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */
