/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection

PACKAGENAME:               cd_hypdriveintoslomo.c

DESCRIPTION:               Implementation of the drive into slow moving hypothesis

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:41:27CEST $

VERSION:                   $Revision: 1.5 $

*******************************************************************************/

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "cd_int.h"

#if (ACDC_CFG_CD)
#if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@defgroup cd_hypdriveintoslomo HypDriveIntoSloMo
@ingroup cd
@brief The Drive Into Slow Moving Hypothesis describes a scenario in which the 
       ego vehicle is closing up to a stationary/slow moving object with sudden 
       unintended acceleration.\n\n

The only extern function of the module is: @ref CDHypDriveIntoSloMoMain \n
Additionally the module contains a function to calculate the hypothesis' object filter (@ref CDHypoDriveIntoSloMoFilter)
and probability (@ref CDHypoDriveIntoSloMoCalculateProb)
@{

*/
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
/*! @brief  Minimum inlap for objects to be considered for a drive into slow moving hypothesis. */
#define CD_DRIVEINTOSLOMO_MIN_INLAP                    ( 0.1f )

/*! @brief  Lower inlap threshold for the probability calculation of the drive into slow moving hypothesis. */
#define CD_DRIVEINTOSLOMO_INLAP_THRES_MIN              ( 0.25f)

/*! @brief  Upper inlap threshold for the probability calculation of the drive into slow moving hypothesis. */
#define CD_DRIVEINTOSLOMO_INLAP_THRES_MAX              ( 0.5f )

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static boolean CDHypoDriveIntoSloMoFilter ( ObjNumber_t const iObjectIndex, float32 * const pfInlap );
static void CDHypoDriveIntoSloMoCalculateProb ( ObjNumber_t const iObjectIndex, float32 const * const pfInlap, CDIntHypothesis_t * const pHypothesis );

/*************************************************************************************************************************
  Functionname:         CDHypoDriveIntoSloMoFilter                                                                   */ /*!

  @brief                Checks if the object is relevant for the drive into slow moving hypothesis.

  @description          To open a drive into slow moving Hypothesis, the following criteria have to be fulfilled :
                        - The Objects HypCat is stationary if it is class Pedestrian or Cyclist.
                        - The Ego Velocity is below threshold.
                        - The Objects Absolute Velocity is below threshold.
                        - The Objects Distance is in a distance range.
                        - The Objects HiQualityLifetime is above a threshold or with camera confirmation.
                        - The Objects Inlap is above threshold.
                        - The Objects Distance is above threshold or object was part of a DriveIntoSloMo, RunUp, RunUpStationary
                          or CutIn Hypothesis in the last cycle.

  @return               boolean : True if the object is relevant

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in,out]        pfInlap :      Inlap of the object into the trajectory (distance based). @phys_unit [m], @range [0,+...[

  @glob_in              ACDC_p_GetObjDescMain \n
                        ACDC_p_GetObjHypothesisData \n
                        ACDC_p_GetEgoData \n
                        ACDC_p_GetEMGenObjQualifiers
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
static boolean CDHypoDriveIntoSloMoFilter (ObjNumber_t const iObjectIndex, float32 * const pfInlap)
{
  float32                 fInlapVar;
  boolean                 bReturn      = FALSE;
  boolean                 bSceneValid  = TRUE;
  ACDCObjToTrajRelation_t TrajRelation = {0};

  ACDCObjDescMain_t       const * const pCurrentObjDesc = ACDC_p_GetObjDescMain(iObjectIndex);
  CDObj_Hypothesis_t      const * const pObjHypData     = ACDC_p_GetObjHypothesisData(iObjectIndex);
  ACDCEgoData_t           const * const pEgoData        = ACDC_p_GetEgoData();
  EM_t_GenObjQualifiers   const * const pObjQualifier   = ACDC_p_GetEMGenObjQualifiers(iObjectIndex);
  float32                         const fObjDist        = pCurrentObjDesc->Positions.GenObject.fX;

  if (    ( GET_BIT(pObjQualifier->eEbaObjClass, FPS_EBA_CLASS_CYCLIST)    )
       || ( GET_BIT(pObjQualifier->eEbaObjClass, FPS_EBA_CLASS_PEDESTRIAN) ) )
  {
    bSceneValid = (GET_BIT(pObjQualifier->eEbaHypCat, FPS_EBA_HYP_CAT_STAT))?TRUE:FALSE;
  }

  if (    (    bSceneValid                          == TRUE                           )
       && (    pEgoData->Kinematics.fVel             < CD_DRIVEINTOSLOMO_MAX_V_EGO    )
       && (    pCurrentObjDesc->Movement.Abs.Vel.fX  < CD_DRIVEINTOSLOMO_MAX_V_ABS    )
       && (    fObjDist                              > 0.f                            )
       && (    fObjDist                              < CD_DRIVEINTOSLOMO_MAX_DISTX    ) )
  {
    EMP_v_CalcDistBasedObjToEgoTrajRelation(iObjectIndex, &TrajRelation);
    CDCalculateInlap(TrajRelation.fDistToTraj        , TrajRelation.fDistToTrajVar,
                     pEgoData->Geometry.fWidth       , 0.f,
                     pCurrentObjDesc->Geometry.fWidth, 0.f,
                     pfInlap                         , &fInlapVar);

    bReturn = (boolean)
      (    (      *pfInlap                                     > CD_DRIVEINTOSLOMO_MIN_INLAP   )
        && (    ( fObjDist                                     > CD_COMMON_MIN_DISTX         )
             || ( pObjHypData->HypothesisHist.DriveIntoSloMo  == 1                           )
             || ( pObjHypData->HypothesisHist.RunUpMoving     == 1                           )
             || ( pObjHypData->HypothesisHist.RunUpStationary == 1                           )
             || ( pObjHypData->HypothesisHist.CutIn           == 1                           ) ) );
  }

  return bReturn;
}

/*************************************************************************************************************************
  Functionname:         CDHypoDriveIntoSloMoCalculateProb                                                            */ /*!

  @brief                Calculates the probability of an object for the drive into slow moving hypothesis.

  @description          The probability for the drive into slow moving hypothesis depends on the Inlap value of the object with respect to the ego lane.

  @return               static void

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in]            pfInlap :      Inlap of the object into the trajectory (distance based). @phys_unit [m], @range [0,+...[
  @param[in,out]        pHypothesis :  Hypothesis for which the probability shall be calculated

  @glob_in              ACDC_p_GetEgoGeometry
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
static void CDHypoDriveIntoSloMoCalculateProb ( ObjNumber_t       const         iObjectIndex,
                                                float32           const * const pfInlap,
                                                CDIntHypothesis_t       * const pHypothesis)
{
  const float32 fEgoWidth = ACDC_p_GetEgoGeometry()->fWidth;
  pHypothesis->fHypothesisProbability = CML_f_BoundedLinInterpol2(*pfInlap, CD_DRIVEINTOSLOMO_INLAP_THRES_MIN*fEgoWidth, CD_DRIVEINTOSLOMO_INLAP_THRES_MAX*fEgoWidth, 0.f, 1.f);
  _PARAM_UNUSED(iObjectIndex);
}

/*************************************************************************************************************************
  Functionname:         CDHypDriveIntoSloMoMain                                                                    */ /*!

  @brief                Handles the main processing steps of the drive into slow moving hypothesis.

  @description          Handles the drive into slow moving hypothesis by executing the three common steps for a hypothesis 
                        generation (see diagram "Common steps of hypothesis creation"):
                        1. Call of the Hypothesis object filter: @ref CDHypoDriveIntoSloMoFilter
                        2. Call of the Hypothesis probability calculation: @ref CDHypoDriveIntoSloMoCalculateProb
                        3. If object with sufficient probability was found: Call of the Hypothesis selection: @ref CDHypSelCreateInternalHypotheses
                        .
                        More information about the three main steps that are described in the diagram
                        can be found in the description of the @ref cd_hyphandler.
                        @image html CommonHypothesisProcess_activity.png "Common steps of hypothesis creation"

  @return               void

  @param[in]            iObjectIndex : Index of the considered object. @range [0, EM_N_OBJECTS[
  @param[in]            bObjFilterMatched : If TRUE out object filter matched so hypothesis shall be calculated. If FALSE reset history (if exists).
  
  @glob_in              None
  @glob_out             @ref ACDC_p_ModObjHypothesisData\n

  @c_switch_part        None
  @c_switch_full        @ref CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @Generic_Testmethods

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
void CDHypDriveIntoSloMoMain(ObjNumber_t const   iObjectIndex,
                             boolean     const   bObjFilterMatched)
{
  float32                    fInlap;
  CDIntHypothesis_t          Hypothesis;
  CDObj_Hypothesis_t * const pObjHypData  = ACDC_p_ModObjHypothesisData(iObjectIndex);

  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_DriveIntoSloMo);
  CD_CLEAR_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_DriveIntoSloMo);

  /* Default Hypothesis Prob Calculation calling */
  if(bObjFilterMatched == TRUE)
  { 
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoStart, ACDC_RTA_CD_HYP_DRIVEINTOSLOMO_SINGLE, (uint8)(iObjectIndex)); /* start profiling for Hypothesis */

    if(CDHypoDriveIntoSloMoFilter(iObjectIndex, &fInlap) == TRUE)
    {
      /* Default Hypothesis handling */
      CD_SET_HYP_BIT(&(pObjHypData->bitHypPresel), (uint32)CDHypothesisType_DriveIntoSloMo);

      CDHypCommonInitHypothesisInt(&Hypothesis, iObjectIndex, CDHypothesisType_DriveIntoSloMo);

      CDHypoDriveIntoSloMoCalculateProb(iObjectIndex, &fInlap, &Hypothesis);

      /* store hypothesis (if relevant) */
      if (Hypothesis.fHypothesisProbability > CD_COMMON_MIN_HYP_PROB)
      {
        CD_SET_HYP_BIT(&(pObjHypData->bitHypActive), (uint32)CDHypothesisType_DriveIntoSloMo);
        CDHypSelCreateInternalHypotheses(&Hypothesis);
        pObjHypData->HypothesisHist.DriveIntoSloMo = 1u;
      }
      else
      {
        pObjHypData->HypothesisHist.DriveIntoSloMo = 0u;
      }
    }
    else
    {
      pObjHypData->HypothesisHist.DriveIntoSloMo = 0u;
    }
    ACDC_SERVICE_ADD_EVENT(e_RTA_EVT_AlgoEnd, ACDC_RTA_CD_HYP_DRIVEINTOSLOMO_SINGLE, (uint8)(iObjectIndex));
  }
  else
  {
    pObjHypData->HypothesisHist.DriveIntoSloMo = 0u;
  }
}

///@}
#endif  /* #if (CD_USE_DRIVE_INTO_SLOMO_HYPOTHESIS) */
#endif  /* #if (ACDC_CFG_CD) */

/* ************************************************************************* */
/*   Copyright Continental Teves AG & Co. oHG, Frankfurt                     */
/* ************************************************************************* */

