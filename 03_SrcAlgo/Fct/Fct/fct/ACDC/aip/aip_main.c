/*! \file *********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_main.c

DESCRIPTION:               main process for the ACDC Input Processing module

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 06:37:14CEST $

VERSION:                   $Revision: 1.15 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "aip_int.h"

/* needed for memset*/
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */


#if(ACDC_CFG_AIP)
/************************************************************************/
/*                      MODULE DESCRIPTION                              */
/************************************************************************/
/*!
@defgroup aip_main  Main
@ingroup aip
@brief          Main Module of the AIP Subcomponent.\n\n
@description    Provides the main function of AIP
                -  @ref AIP_v_Process
@{
*/

/************************************************************************/
/*                     FUNCTION DECLARATIONS                            */
/************************************************************************/
static void AIP_v_CalcMotionMatrices(fTime_t fCycleTime, const VehDyn_t * pEgoDyn);
static void AIP_v_InitTrafoMatrices(void);

/*************************************************************************************************************************
  Functionname:         AIP_v_CalcMotionMatrices                                                                    */ /*!

  @brief                Calculates the matrices used to transfer positions from former cycles to the current 
                        coordinate system.

  @description          At first it is checked if the ego vehicle is driving backwards. If this is the case the 
                        ego velocity is inverted. Subsequently the function @ref GDBmathCalculateCOFEgomotionMatrices \n
                        is called. The result is stored in the global variables @ref ACDC_p_GetTrafoMatForward and 
                        @ref ACDC_p_GetTrafoMatBackward.
                        @startuml AIP_v_CalcMotionMatrices_activity.png
                        start
                          :Get Ego kinematics;
                          if(Motion state is backward\nAND Velocity is positive?) then (Yes)
                            :1}
                            note left
                              As the here used corrected velocity does 
                              not have a sign, it has to be defined
                              according to the Motion state
                            end note
                            :Invert sign of velocity;
                          else(No)
                            :2}
                          endif
                          #Orange:Calculate matrices to compensate the ego 
                          movement regarding the previous cycle:
                          <b>GDBmathCalculateCOFEgomotionMatrices</b> >
                        stop
                        @enduml

  @return               void

  @param[in]            fCycleTime :  Current cycle time. @phys_unit [s] @range ]0,+...[
  @param[in]            *pEgoDyn :    Dynamics of the ego vehicle.

  @glob_in              None
  @glob_out             @ref ACDC_p_ModTrafoMatForward \n
                        @ref ACDC_p_ModTrafoMatBackward

  @c_switch_part        @ref VDY_VEH_DYN_INTFVER
  @c_switch_full        @ref ACDC_CFG_AIP

  @pre                  None
  @post                 Transformation matrices updated

  @InOutCorrelation     see description

  @author               Gergely Ungvary


  @testmethod           @ref TEST_AIP_V_CALCMOTIONMATRICES_001 \n
                        @ref TEST_AIP_V_CALCMOTIONMATRICES_002 \n
						@ref TEST_AIP_V_CALCMOTIONMATRICES_003

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_CalcMotionMatrices(fTime_t fCycleTime, const VehDyn_t * pEgoDyn)
{
  fYawRate_t  fYawRate      = pEgoDyn->Lateral.YawRate.YawRate;
#if (VDY_VEH_DYN_INTFVER >= 32)
  fAccel_t    fAcceleration = pEgoDyn->Longitudinal.Accel;
  fVelocity_t fCorrVelo     = pEgoDyn->Longitudinal.Velocity;
#else
  fAccel_t    fAcceleration = pEgoDyn->Longitudinal.MotVar.Accel;
  fVelocity_t fCorrVelo     = pEgoDyn->Longitudinal.MotVar.Velocity;
#endif

  /* Since corrected speed is unsigned, correct for sign if moving reverse */
  if ((pEgoDyn->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD) &&
      (fCorrVelo > 0.0f))
  {
    fCorrVelo = -fCorrVelo;
  }

  /* calculate matrices for ego motion compensation */
  GDBmathCalculateCOFEgomotionMatrices(ACDC_p_ModTrafoMatForward() ,
                                       ACDC_p_ModTrafoMatBackward(),
                                       fCorrVelo,
                                       fAcceleration,
                                       fYawRate,
                                       fCycleTime );
}



/*************************************************************************************************************************
  Functionname:         AIP_v_InitTrafoMatrices                                                                      */ /*!

  @brief                Initializes the global variables @ref AIP_TrafoMat2DForward and @ref AIP_TrafoMat2DBackward.

  @return               void

  @param[in]            void

  @glob_in              None
  @glob_out             @ref ACDC_p_ModTrafoMatForward \n
                        @ref ACDC_p_ModTrafoMatBackward \n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  None
  @post                 Global trafo matrix variables are initialized

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995


  @testmethod           @ref TEST_AIP_V_INITTRAFOMATRICES_001

  @traceability         Design Decision
*************************************************************************************************************************/
static void AIP_v_InitTrafoMatrices(void)
{
  /* Do this for safety sake only. It�s not necessary as long as the data is in not in INTERCYCLE data.*/
  /*PRQA S 0315 2*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  (void)memset(ACDC_p_ModTrafoMatForward(), 0,sizeof(GDBTrafoMatrix2D_t));
  (void)memset(ACDC_p_ModTrafoMatBackward(),0,sizeof(GDBTrafoMatrix2D_t));
}

/*************************************************************************************************************************
  Functionname:         AIP_v_Process                                                                                */ /*!

  @brief                Main function of the AIP subcomponent.

  @description          Calls several functions to preprocess Input data of the ACDC component:
                        1. Calculate the Motion matrices for the transformation from the last to the current 
                           coordinate system: @ref AIP_v_CalcMotionMatrices
                        2. Write the ego data from e.g. the VDY inputs into the @ref ACDC_p_ModEgoData: @ref AIP_v_PreProcessEgoData
                        3. Write the object data coming from EM into the ACDC internal object list and calculate additional 
                           information like Trajectory relation and certain object positions: @ref AIP_v_PreProcessObjectList
                        @startuml AIP_v_Process_activity.png
                        start
                          #Orange:Calculate the motion matrices for the position 
                          conversion from the previous cycle:
                          <b>AIP_v_CalcMotionMatrices</b> >
                          #Orange:Preprocess the Ego data and copy it 
                          into a internal structure:
                          <b>AIP_v_PreProcessEgoData</b> >
                          #Orange:Preprocess the object data and copy 
                          it into a internal structure:
                          <b>AIP_v_PreProcessObjectList</b> >
                        stop
                        @enduml

  @return               void

  @glob_in              @ref ACDC_e_GetSubCompState \n
                        @ref ACDC_f_GetCycleTime \n
                        @ref ACDC_p_GetVDYDynObjSync
  @glob_out             @ref ACDC_v_SetSubComponentStates \n
                        @ref ACDC_p_ModEgoData \n

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_AIP\n

  @pre                  None
  @post                 @ref ACDC_p_GetEgoData and @ref ACDC_ObjectList are filled

  @InOutCorrelation     see description

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995

  @testmethod           @ref TEST_AIP_V_PROCESS_001 \n
                        @ref TEST_AIP_V_PROCESS_002 \n
						@ref TEST_AIP_V_PROCESS_003

  @traceability         Design Decision
*************************************************************************************************************************/
void AIP_v_Process(void)
{
  ACDCCompState_t AIPState = ACDC_e_GetSubCompState(ACDC_SUB_COMP_AIP);

  switch(AIPState)
  {
    case COMP_STATE_RUNNING:

      AIP_v_CalcMotionMatrices(ACDC_f_GetCycleTime(), ACDC_p_GetVDYDynObjSync());

      AIP_v_PreProcessEgoData(ACDC_p_ModEgoData());

      #if(ACDC_AIP_CFG_SHIFT_COORDINATE)
      
			AIP_v_ShiftObjMinAxisToEgoFrontCenter();//For Shift Coordinate .....@Cheng Long

    	#endif

      #if (ACDC_CFG_USE_FPS)
	    
	    AIP_v_PreProcessEBAObjectQuality(); //For FPS .....@Cheng Long

      #endif

      AIP_v_PreProcessObjectList();

      break;

    case COMP_STATE_NOT_INITIALIZED:
    default:

      AIP_v_InitTrafoMatrices();

      AIP_v_InitEgoData();

	  #if (ACDC_CFG_USE_FPS)

	  AIP_v_InitEBAObjectQuality(); //For FPS .....@Cheng Long

	  #endif

      AIP_v_InitObjectList();

      break;
  }

  ACDC_v_SetSubComponentStates(ACDC_SUB_COMP_AIP,AIPState);
}

/*!@}*/
#endif /* (ACDC_CFG_AIP) */

