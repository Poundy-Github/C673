/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypcyclecoll.c

DESCRIPTION:               Implementation of the cyclecoll hypothesis

AUTHOR:                    $Author: P, Sivaprakash (uib03389) (uib03389) $

CREATION DATE:             $Date: 2020/07/20 13:08:49CEST $

VERSION:                   $Revision: 1.27 $

LEGACY VERSION:            Revision: 2.13

*****************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_BICYCLE_COLL_HYPOTHESIS)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hypcyclecoll HypCycleColl
@ingroup cd
@brief          The Cycle Collision Hypothesis describes a possible collision with a crossing cyclist.\n\n

@description    The only main function of this module is: @ref CDHypoCycleCollMain. It handles the main 
                processing steps of the Cycle Collision hypothesis.
@{
*/

/*****************************************************************************
  MACROS 
*****************************************************************************/
#if !CD_USE_GEN_PSC 
#error "CD_USE_GEN_PSC" has to be activated
#endif
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  (SYMBOLIC) CONSTANTS 
*****************************************************************************/

/*! @brief      Oldest factor used in calculating weights for y distance history */
#define BICYCLE_VELO_WEIGHT_OLDEST (1.0f)


/*! @brief      Youngest factor used in calculating weights for y distance history */
#define BICYCLE_VELO_WEIGHT_YOUNGEST (3.0f)


/*! @brief      standard deviation of 0.7m for camera measured distances expected */
#define BICYCLE_VELO_WEIGHT_STD_B (0.7f) 


/*! @brief     Constant used to calculate allowed error */
#define BICYCLE_VELO_ALLOWED_CONST_ERROR_M (0)


/*! @brief     Probability constant A used to map error to Probability */
#define BICYCLE_VELO_MAP_ERROR_PROB_CONST_A (0.0031f)


/*! @brief     Probability constant B used to map error to Probability */
#define BICYCLE_VELO_MAP_ERROR_PROB_CONST_B (0.0015f)


/*! @brief      Path factor used for calculation of collision corridor velocity */
#define BICYCLE_VELO_VEHICLE_PATH_FACTOR (1.0f)

/*! @brief      Maximum weight of measured Bicycle velocity added to velocity probability density function */
#define BICYCLE_VELO_ADD_MEASURED_VELO_MAX_WEIGHT (0.8f)

/*****************************************************************************
  VARIABLES 
*****************************************************************************/

/*****************************************************************************
  LOCAL FUNCTIONS Declarations
*****************************************************************************/

static boolean CDHypoBicycleCollObjectFilter    ( ObjNumber_t                      iObjectIndex ); 
static void CDHypoBicycleCollCalculateProb( ObjNumber_t       const         iObjectIndex, 
                                            CDIntHypothesis_t       * const pHypothesis);

#if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
static void CDBicycleCollDowngradeProbDominantVelo(float32 * out_fDownGradeFac, const float32 fObjVrelToEgoTraj_mps, const float32 fObjVrelOnEgoTraj_mps, 
                                               const float32 fObjDistToEgoTraj_m, const float32 fEgoVeloDepWidth_m);
#endif

/*****************************************************************************
  LOCAL FUNCTIONS Definitions
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         CDHypoBicycleCollObjectFilter                                                                */ /*!

  @brief                Checks whether an object is relevant for the Pedestrian Collision Hypothesis

  @description          To open a Cycle Collision hypothesis, the following criteria have to be fulfilled :
                        - The Objects TTC3 has to be below threshold
                        .
                        Additionally the following criteria are required (in the previous step) by the 
                        generic object filter:
                        - The Objects HypCat is Crossing or Stationary
                        - The Object has to be of EBA-Class Cyclist

  @return               boolean : True if Object passes the filter

  @param[in]            iObjectIndex : Index of the considered object @range [0,...]

  @glob_in              @ref CD_f_GetTTC3
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD  \n
                        @ref CD_USE_BICYCLE_COLL_HYPOTHESIS 

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Matthias Thomi

  @testmethod           @ref TEST_CDHYPOBICYCLECOLLOBJECTFILTER_001 \n
                        @ref TEST_CDHYPOBICYCLECOLLOBJECTFILTER_002

  @traceability         Design Decision

*************************************************************************************************************************/
static boolean CDHypoBicycleCollObjectFilter(ObjNumber_t iObjectIndex)
{
  boolean bAcceptObj = b_TRUE;

  if ((CD_f_GetTTC3(iObjectIndex) > CD_BICYCLE_MAX_TTC_FILTER) || (ACDC_p_GetEMGenObj(iObjectIndex)->Attributes.eClassification != EM_GEN_OBJECT_CLASS_BICYCLE))
  {
    bAcceptObj = b_FALSE;
  }

  /* Check for Class Bicycle is already done in generic Class filter */

  return bAcceptObj;
}

/*************************************************************************************************************************
  Functionname:         CDHypoBicycleCollCalculateProb                                                               */ /*!

  @brief                Calculates the probability for the bicycle collision hypothesis.

  @description          The collision probability is calculated by means of the probability of 
                        speed concept: @ref CDPSCGetProbCollision\n
                        The therefore required width of the ego corridor is calculated by adding a velocity dependent 
                        polygon value based on the variable @ref CD_EGO_ADD_WIDTH_VELO_DEP_M to the ego vehicle width. \n
                        All following actions are optional and can be decoded by configuration switches:
                        - The probability is set to 0 if the bicycle is detected to be outside 
                          of the estimated road: @ref CDPedIsOutsideRoadEstimation \n
                        - The probability is decreased if the main movement direction of the bicycle is not
                          crossing in relation to the ego vehicle. The factor by which it is decreased 
                          is calculated by the function @ref CDBicycleCollDowngradeProbDominantVelo.
                        .
                        @startuml CDHypoBicycleCollCalculateProb_activity.png
                        start
                          :Calculate width of ego corridor;
                          note left: Linearly depending on the ego velocity
                          #Orange:Calculate collision probability:
                          <b>CDPSCGetProbCollision</b> >
                          note left: Based on the probability of speed concept
                          #Orange:Set probability to zero if bicycle 
                          is outside of estimated road
                          <b>CDPedIsOutsideRoadEstimation</b> >
                          note left: Configuration dependent step
                          #Orange:Reduce probability by a factor if main movement 
                          direction of bicycle is not crossing
                          <b>CDBicycleCollDowngradeProbDominantVelo</b> >
                          note left: Configuration dependent step
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex :        Index of the considered object. @range [0,...]
  @param[in,out]        *pHypothesis :        Pointer to the hypothesis for which the probability shall be calculated

  @glob_in              @ref ACDC_p_GetObjTrajRelation
  @glob_out             None

  @c_switch_part        @ref CD_BICYCLE_USE_EM_ROAD_ESTIMATION \n
                        @ref CD_BICYCLE_USE_LIMITED_DIMENSIONS \n
                        @ref CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE
  @c_switch_full        @ref ACDC_CFG_CD  \n
                        @ref CD_USE_BICYCLE_COLL_HYPOTHESIS 

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Matthias Thomi

  @testmethod           @ref TEST_CDHYPOBICYCLECOLLCALCULATEPROB_001

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDHypoBicycleCollCalculateProb( ObjNumber_t       const         iObjectIndex, 
                                            CDIntHypothesis_t       * const pHypothesis)
{
  /* Collect Object Informations */
  ACDCObjToTrajRelation_t const * const pTrajRelation = ACDC_p_GetObjTrajRelation(iObjectIndex);
  const float32 fObjDistToEgoTraj_m   = pTrajRelation->fDistToTraj;
#if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE) 
  const float32 fObjVrelToEgoTraj_mps = pTrajRelation->fVelocityToTraj;
  const float32 fObjVrelOnEgoTraj_mps = pTrajRelation->fVelocityOnTraj;
#endif /* #if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)  */
  /* Probability of Speed Concept */
  float32 fPSCProb                    = 0.0f;
  float32 fCorrApproachProb           = 1.0f;
  float32 fObjCollProb                = 1.0f;
  float32 fEgoVeloDepWidthLeft_m;
  float32 fEgoVeloDepWidthRight_m;
  

  /* calculate the asymmetric ego vehicle corridor */
  CDPSCCalcCorridorWidthCrossVru ( iObjectIndex, &fEgoVeloDepWidthLeft_m, &fEgoVeloDepWidthRight_m);

  /* get PSC probability using the generic calculation */
  fPSCProb = CDPSCGetProbCollision(iObjectIndex, fEgoVeloDepWidthLeft_m,fEgoVeloDepWidthRight_m, CD_PSC_USE_TO_TRAJ);

  /***********************************/
  /* Fuse Probs                      */
  /***********************************/
  pHypothesis->fHypothesisProbability = fPSCProb * fCorrApproachProb;


#if (defined(CD_BICYCLE_USE_EM_ROAD_ESTIMATION) && (CD_BICYCLE_USE_EM_ROAD_ESTIMATION == SWITCH_ON))
  if ( CDPedIsOutsideRoadEstimation(iObjectIndex) != FALSE )
  {
    fObjCollProb = 0.f;
  }
#endif
  pHypothesis->fHypothesisProbability *= fObjCollProb;
   
#if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
  {
  /* Downgrade hypothesis probability in case of dominant velocity direction is not crossing! */
    float32 out_fDownGradeFac  = 1.0f;
    float32 fEgoVeloDepWidth_m = fEgoVeloDepWidthLeft_m + fEgoVeloDepWidthRight_m;
    CDBicycleCollDowngradeProbDominantVelo(&out_fDownGradeFac, fObjVrelToEgoTraj_mps, fObjVrelOnEgoTraj_mps, fObjDistToEgoTraj_m, fEgoVeloDepWidth_m);
    pHypothesis->fHypothesisProbability *= out_fDownGradeFac;
  }
#endif /* #if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE) */
}

#if (SWITCH_ON == CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE)
/*************************************************************************************************************************
  Functionname:         CDBicycleCollDowngradeProbDominantVelo                                                       */ /*!

  @brief                Calculates a factor by which the probability for the bicycle hypothesis is downgraded 
                        if the movement direction of the bicycle is not crossing.

  @description          The function downgrades the Bicycle Collision Probability when the dominant
                        object velocity direction is not crossing in relation to the ego vehicle path. \n
                        This ensures that some of the FalsePositives are suppressed. \n
                        Original Idea: \n
                        Downgrading the bicycle collision probability is a workaround, to use the ped hypothesis 
                        also for bicycles. Downgrading an object, which moves on a trajectory with the ego-vehicle \n
                        means: near overtake scenarios with bicycles are suppressed. \n
                        Possible FalsePositive suppressions are:
                        - Pedestrian/Bicycle standing -> a minimum velocity required
                        - Pedestrian/Bicycle moving inside the ego vehicle path
                        .

  @return               void

  @param[in,out]        out_fDownGradeFac :     Calculated factor by which the collision probability shall be downgraded. @range [0,1]
  @param[in]            fObjVrelToEgoTraj_mps : Velocity by which the object is closing up to the ego trajectory. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fObjVrelOnEgoTraj_mps : Velocity by which the object is driving along the ego trajectory. @phys_unit [m/s] @range ]-...,+...[
  @param[in]            fObjDistToEgoTraj_m :   Distance of the Object and the ego trajectory. @phys_unit [m] @range ]-...,+...[
  @param[in]            fEgoVeloDepWidth_m :    Width of the ego vehicle corridor. @phys_unit [m] @range ]0,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_BICYCLE_COLL_HYPOTHESIS \n
                        @ref CD_BICYCLE_COLL_USE_DOMINANT_VELOCITY_DOWNGRADE

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     - **Formula Downgrade Factor:** \n
                          \f$ Fctr = \frac{V_{ToTraj}}{V_{OnTraj}} \cdot \frac{1}{MaxRate}, Fctr >= MinFactor\f$ \n
                          With \n
                          \f$ MinFactor = - |D_{ToTraj} - 0.5 \cdot Width_{Corr,Ego}|, 0 <= MinFactor <= 1 \f$ \n
                          \f$ MaxRate = A \cdot |D_{ToTraj} - 0.5 \cdot Width_{Corr,Ego}|, 0 < MaxRate <= 1 \f$\n
                          \n
                          If a bicycle is detected with no relative velocity, with no absolute velocity or as outside 
                          of the ego vehicle corridor, the down grade factor is set to 1. This means the calculated 
                          probability is NOT downgraded.

  @author               Gregor Powarzynski

  @testmethod           @ref TEST_CDBICYCLECOLLDOWNGRADEPROBDOMINANTVELO_001\n
                        @ref TEST_CDBICYCLECOLLDOWNGRADEPROBDOMINANTVELO_002\n
                        @ref TEST_CDBICYCLECOLLDOWNGRADEPROBDOMINANTVELO_003\n
						@ref TEST_CDBICYCLECOLLDOWNGRADEPROBDOMINANTVELO_004

  @traceability         Design Decision

*************************************************************************************************************************/
static void CDBicycleCollDowngradeProbDominantVelo(float32 * out_fDownGradeFac, const float32 fObjVrelToEgoTraj_mps, const float32 fObjVrelOnEgoTraj_mps, 
                                               const float32 fObjDistToEgoTraj_m, const float32 fEgoVeloDepWidth_m)
{

  const float32 fBicycleDistToVehiclePath_m = MAX_FLOAT(0.0f, fABS(fObjDistToEgoTraj_m) - (fEgoVeloDepWidth_m*0.5f));
  const float32 fMaxRate   = CML_f_CalculatePolygonValue(CD_NUMBER_OF_DOMINANTDOWNGRADE_MAX_RATE_VALUES, CD_PED_COLL_DOM_DG_MAX_RATE_VEC, fBicycleDistToVehiclePath_m);
  const float32 fMinFactor = CML_f_CalculatePolygonValue(CD_NUMBER_OF_DOMINANTDOWNGRADE_MIN_FACTOR_VALUES, CD_PED_COLL_DOM_DG_MIN_FACTOR_VEC, fBicycleDistToVehiclePath_m);


  const float32 fObjVelo_mps = SQR(fObjVrelOnEgoTraj_mps) + SQR(fObjVrelToEgoTraj_mps); /* Be careful: not the real velocity of the object. SQRT not done because of efficiency */
  const boolean bBicycleIsMoving = (boolean) (fObjVelo_mps > CD_BICYCLE_COLL_DOMINANT_DOWNGRADE_MIN_OBJ_VELO_MPS);
    
  const boolean bBicycleIsNotInVehiclePath = (boolean) (fABS(fObjDistToEgoTraj_m) > (fEgoVeloDepWidth_m*0.5f));

  float32 fVrelToOnTrajRate;

  *out_fDownGradeFac = 1.0f;

  if (fABS(fObjVrelOnEgoTraj_mps) > C_F32_DELTA)
  {
    fVrelToOnTrajRate = fABS(fObjVrelToEgoTraj_mps) / fABS(fObjVrelOnEgoTraj_mps);
    if ( ( b_FALSE!=bBicycleIsMoving ) && ( b_FALSE!=bBicycleIsNotInVehiclePath ) )
    {
      *out_fDownGradeFac = MAX_FLOAT(fMinFactor, MIN_FLOAT(1.0f,fVrelToOnTrajRate/fMaxRate));
    }
  }
}
#endif

/*************************************************************************************************************************
  Functionname:         CDHypoCycleCollMain                                                                          */ /*!

  @brief                Handles the main processing steps of the bicycle collision hypothesis

  @description          Handles ACC Hypothesis by executing the three common steps for a hypothesis generation 
                        (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoBicycleCollObjectFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoBicycleCollCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram can be 
                        found in the description of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex :      The index of the object. @range [0,...]
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history.
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n
                        

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_CD \n
                        @ref CD_USE_BICYCLE_COLL_HYPOTHESIS

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @author               Matthias Thomi | Matthias.Thomi@continental-corporation.com

  @testmethod           @ref TEST_CDHYPOCYCLECOLLMAIN_001 \n
                        @ref TEST_CDHYPOCYCLECOLLMAIN_002 \n
                        @ref TEST_CDHYPOCYCLECOLLMAIN_003 \n
                        @ref TEST_CDHYPOCYCLECOLLMAIN_004

  @traceability         Design Decision

*************************************************************************************************************************/
void CDHypoCycleCollMain(      ObjNumber_t const   iObjectIndex, 
                               boolean     const   bObjFilterMatched)
{
  CDIntHypothesis_t Hypothesis;

  CDObj_Hypothesis_t * pObjHypData       = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CyclColl);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CyclColl);

  /* Default Hypothesis Prob Calculation calling */
  if( bObjFilterMatched != b_FALSE )
  {
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoStart,  ACDC_RTA_CD_HYP_BICYCLECOLL_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */
    if( CDHypoBicycleCollObjectFilter(iObjectIndex) != b_FALSE )  
    {
      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_CyclColl);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_CyclColl);

      CDHypoBicycleCollCalculateProb(iObjectIndex, &Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > 0.2f)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_CyclColl);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.BicycleColl = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.BicycleColl = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.BicycleColl = 0u;
    }
    ACDC_SERVICE_ADD_EVENT( e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_BICYCLECOLL_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.BicycleColl = 0u;
  }
}
//! @}
#endif /* (CD_USE_BICYCLE_COLL_HYPOTHESIS)  */
#endif /* (ACDC_CFG_CD) */

