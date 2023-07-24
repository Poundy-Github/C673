/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_ego.c

DESCRIPTION:               Functions for the preprocessing of ego data for the ACDC component

AUTHOR:                    Danner Andreas (uid41765)

CREATION DATE:             05.07.2018

VERSION:                   $Revision: 1.13 $

**************************************************************************** */

#include "aip_int.h"

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */

#if(ACDC_CFG_AIP)

/************************************************************************/
/*                         MODULE DESCRIPTION                           */
/************************************************************************/
/*!
@defgroup aip_ego Ego
@ingroup aip
@brief            Contains functions for the preprocessing of all data related to the ego vehicle. \n\n
@description      Provides the following functionalities:
                  - Get function for the access the the possible ego trajectories: @ref AIP_p_GetACDCEgoTraj
                  - Filling of the ACDC_EgoData: @ref AIP_v_PreProcessEgoData
@{
*/

/************************************************************************/
/*                     FUNCTION DECLARATIONS                            */
/************************************************************************/
static void AIP_v_InitTrajPred(ACDCTrajPred_t aTrajPred[]);

/************************************************************************/
/*                     FUNCTION DEFINITIONS                             */
/************************************************************************/

/*************************************************************************************************************************
  Functionname:         AIP_v_PreProcessEgoData                                                                     */ /*!

  @brief                Fills the ACDC structure containing the data related to the ego vehicle.

  @description          Fills the substructures of the ACDC ego data:
                        - Geometry       : Vehicle width, length and orientation
                        - Kinematics     : Velocity, Acceleration and Yaw Rate
                        - MovementRaw    : Raw movement mapped onto X and Y velocities and accelerations
                        - MovementObjSync: object synced movement mapped onto X and Y velocities and accelerations
                        - aTrajPred      : Trajectories based on the movement. (Is filled by calling the get 
                                           function @ref AIP_p_GetACDCEgoTraj )

  @return               void

  @param[in,out]        pEgoData : Data of the ego vehicle to be initialized.

  @glob_in              @ref ACDC_p_GetVehPar          \n
                        @ref ACDC_f_GetEgoVelObjSync   \n
                        @ref ACDC_f_GetEgoAccelObjSync \n
                        @ref ACDC_p_GetVDYDynObjSync   \n
                        @ref ACDC_f_GetEgoVelRaw       \n
                        @ref ACDC_p_GetVDYDynRaw       \n
                        @ref ACDC_f_GetEgoVelRaw       \n
                        @ref ACDC_f_GetEgoAccelRaw
  @glob_out             None

  @c_switch_part        @ref ACDC_CFG_USE_REAL_EGO_DIMENSION\n
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 Ego Data structure is initialized and filled. (Exception: the substructure aTrajPred is filled 
                        directly when the get function @ref AIP_p_GetACDCEgoTraj is called

  @InOutCorrelation     see description

  @todo                 Clarify the future Ego structure. Is movementXY needed or can it be replaced? 
                        Is the use of Raw kinematics still required?

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995


  @testmethod           @ref TEST_AIP_V_PREPROCESSEGODATA_001 \n
                        @ref TEST_AIP_V_PREPROCESSEGODATA_002 

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_PreProcessEgoData(ACDCEgoData_t * const pEgoData)
{

  /********** Initialize the Ego vehicle geometry **********/
  float32 fEgoLength;
  float32 fEgoWidth;

#if (ACDC_CFG_USE_REAL_EGO_DIMENSION)
  fEgoWidth  = ACDC_p_GetVehPar()->VehParAdd.VehicleWidth;
  fEgoLength = ACDC_p_GetVehPar()->VehParAdd.VehicleLength;
  
  /*set default values in case of implausible input data*/
  if(fEgoWidth < ACDC_PLAUS_EGO_WIDTH)
  {
    fEgoWidth  = ACDC_COMMON_EGO_WIDTH;
  }
  if(fEgoLength < ACDC_PLAUS_EGO_LENGTH)
  {
    fEgoLength = ACDC_COMMON_EGO_LENGTH;
  }
#else
  fEgoWidth    = ACDC_COMMON_EGO_WIDTH;
  fEgoLength   = ACDC_COMMON_EGO_LENGTH;
#endif

  pEgoData->Geometry.fLength      = fEgoLength;
  pEgoData->Geometry.fWidth       = fEgoWidth;
  pEgoData->Geometry.fOrientation = 0.f;

  /********** Initialize the Ego kinematics **********/
  /* Update Ego Kinematics */
  pEgoData->Kinematics.fVel         = ACDC_f_GetEgoVelObjSync();
  pEgoData->Kinematics.fAccel       = ACDC_f_GetEgoAccelObjSync();
  pEgoData->Kinematics.fYawRate     = ACDC_p_GetVDYDynObjSync()->Lateral.YawRate.YawRate;


  /********** Initialize the Raw Ego movement structure (used in certain calculations) **********/
  pEgoData->MovementRaw.Vel.fX       = ACDC_f_GetEgoVelRaw();
  pEgoData->MovementRaw.Vel.fY       = 0.f;

  pEgoData->MovementRaw.Accel.fY     = ACDC_p_GetVDYDynRaw()->Lateral.YawRate.YawRate * ACDC_f_GetEgoVelRaw();
  pEgoData->MovementRaw.Accel.fX     = ACDC_f_GetEgoAccelRaw();

  /********** Initialize the Obj synced Ego movement structure (used in certain calculations) **********/
  pEgoData->MovementObjSync.Vel.fX   = ACDC_f_GetEgoVelObjSync();
  pEgoData->MovementObjSync.Vel.fY   = 0.f;

  pEgoData->MovementObjSync.Accel.fY = ACDC_p_GetVDYDynObjSync()->Lateral.YawRate.YawRate * ACDC_f_GetEgoVelObjSync();
  pEgoData->MovementObjSync.Accel.fX = ACDC_f_GetEgoAccelObjSync();


  if(fABS(ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve) > C_F32_DELTA )
  {
    pEgoData->TrajCircle.fRadius = fABS(1.f / ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve);
    pEgoData->TrajCircle.fY      = pEgoData->TrajCircle.fRadius *  (float32)CML_f_Sign(ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve);
  }
  else
  {
    pEgoData->TrajCircle.fRadius = 1.f/C_F32_DELTA;
    pEgoData->TrajCircle.fY      = (1.f/C_F32_DELTA) * (float32)CML_f_Sign(ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve);
  }
  pEgoData->TrajCircle.fX = -0.5f * fEgoLength;

  /********** Initialize the trajectory prediction structure. Is later on filled by a calling the function AIP_p_GetACDCEgoTraj **********/
  AIP_v_InitTrajPred(pEgoData->aTrajPred);

}

/*************************************************************************************************************************
  Functionname:         AIP_v_InitTrajPred                                                                         */ /*!

  @brief                Resets the trajectory prediction array.

  @description          The Traj Pred array contains different possible future ego trajectories for different 
                        Maneuvers (see @ref ACDCManeuverType_e). All predictions are set to 0. The C0 coefficient 
                        of each prediction is set to @ref ACDC_TRAJPRED_INIT.

  @return               void

  @param[in,out]        aTrajPred: Trajectory Prediction structure to be initialized

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP \n

  @pre                  None
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer

  @testmethod           @ref TEST_AIP_V_INITTRAJPRED_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_InitTrajPred(ACDCTrajPred_t aTrajPred[])
{
  uint32 uManType;
  ACDCTrajPred_t sTrajPredInitStructure = {0};
  /* Set one of the variables to a checkable value */
  sTrajPredInitStructure.XofT.fC0 = ACDC_TRAJPRED_INIT;

  for (uManType = 0u; uManType < (uint32)ACDC_MANEUVER_NumOfTypes; uManType++)
  {
    /* Init the complete list with the init structure */
    aTrajPred[uManType] = sTrajPredInitStructure;
  }
}


/*************************************************************************************************************************
  Functionname:         AIP_v_InitEgoData                                                                            */ /*!

  @brief                Initialized the @ref ACDC_p_ModEgoData

  @description          Initialized the ACDC_EgoData and set the Trajectory prediction Substructure to its initial values: 
                        @ref AIP_v_InitTrajPred.

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref ACDC_p_ModEgoData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  None
  @post                 ACDC_EgoData is initialized

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_INITEGODATA_001

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_InitEgoData(void)
{
  ACDCEgoData_t * pEgoData = ACDC_p_ModEgoData();
  /*PRQA S 0315 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  (void)memset(pEgoData, 0, sizeof(ACDCEgoData_t) );
  AIP_v_InitTrajPred(pEgoData->aTrajPred);
}

/*************************************************************************************************************************
  Functionname:         AIP_p_GetACDCEgoTraj                                                                       */ /*!

  @brief                Returns the pointer to the predicted trajectory structure

  @description          Returns the pointer to the trajectory structure of the requested maneuver type.

  @return               ACDCTrajPred_t * : pointer to the trajectory structure

  @param[in]            ManeuverType: Enum to specify which maneuver type shall be assumed

  @glob_in              @ref ACDC_p_GetEgoData
  @glob_out             @ref ACDC_p_ModEgoData

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP \n

  @pre                  @ref AIP_v_InitTrajPred has been called at the beginning of the cycle
  @post                 None

  @InOutCorrelation     see description

  @author               Andreas Kramer

  @testmethod           @ref TEST_AIP_P_GETACDCEGOTRAJ_001 \n
                        @ref TEST_AIP_P_GETACDCEGOTRAJ_002 \n
						@ref TEST_AIP_P_GETACDCEGOTRAJ_003


  @traceability         Design Decision
*************************************************************************************************************************/
ACDCTrajPred_t const * AIP_p_GetACDCEgoTraj(ACDCManeuverType_e const ManeuverType )
{
  ACDCTrajPred_t * pTrajPred;

  ACDCEgoData_t * const pEgoData = ACDC_p_ModEgoData();
  if (ManeuverType < ACDC_MANEUVER_NumOfTypes)
  {
    pTrajPred = &(pEgoData->aTrajPred[ManeuverType]);
  }
  else
  {
    /* This is an error path which may never occur */
    pTrajPred = &(pEgoData->aTrajPred[0]);
    ACDC_ASSERT(FALSE); /* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: This code is placed for assertive failure and hence cannot be removed */
  }

  /* Update the trajectory structure only if not necessary */
  if (pTrajPred->XofT.fC0 > ACDC_TRAJPRED_CHECK)
  {
    EMPPredictEgoTraj(&(pEgoData->Kinematics), ManeuverType, pTrajPred);
  }

  return pTrajPred;
}

/*!@}*/
#endif /* (ACDC_CFG_AIP)*/
