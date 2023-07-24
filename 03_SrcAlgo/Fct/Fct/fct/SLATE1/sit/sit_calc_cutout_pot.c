/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_calc_cutout_pot.c

DESCRIPTION:               This module inherits algorithms for cut-out potential
                           calculation

AUTHOR:                    Harsha Umesh Babu | harsha.umesh.babu@continental-corporation.com | +49 (8382) 9699-474

CREATION DATE:             14.09.2016

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            Revision: 2.1

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "sit.h"//PRQA S 0380
/* date: 2019-07-28, reviewer:Prabhu Sundaramurthy, reason: Arises due to inclusion of multiple header files in this header file which has multiple macros*/
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/

/**
@defgroup sit_calc_cutout_pot Cutout potential
@ingroup sit
@brief          Calculation of the cutout potential is done in this module. \n\n
@{
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

/*************************************************************************************************************************
  Functionname:    SIT_u_CutOutPotCalcKinematic                                                                   */ /*!

  @brief           Calculate cutOut potential

  @description     Calculates the cutOut potential based on Total time to inlap Drop. 

                    @startuml
                    Partition SIT_u_CutOutPotCalcKinematic{
                    Start
                    : Get Low Threshold and Time factor;
                    : Get High Threshold;
                    : Get the Total time to InlapDrop;
                    : Calculate cutout potential;
                    End
                    }
                    @enduml

  @return          f_CutOutpot : calculated cut out potential value in percent [0u ... 100u]

  @param[in]       iObj :  Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_LAInput.pt_TotalTimeToInlap(ObjId) :              []
  @glob_in         pt_SITInput->t_LAInput.pt_PredTimeThreshold(ObjId) :              []
  @glob_out        

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    389:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-389-00061542 \n
                   383:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-383-00061542 \n
                   384:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-384-00061542 \n
                   387:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-387-00061542 \n

  @created         23.05.2018
  @changed         23.05.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com | 
*************************************************************************************************************************/
uint8 SIT_u_CutOutPotCalcKinematic(const ObjNumber_t ObjId)
{
  float32 f_CutOutpot;
  fTime_t t_TTOFull_Calculated = *(pt_SITInput->t_LAInput.pt_TotalTimeToInlapDrop(ObjId));
  /* 100 percent potential line */
  float32 f_PredTimeLowThres= *(pt_SITInput->t_LAInput.pt_PredTimeThreshold(ObjId)); 
  /* 0 percent potential line */
  float32 f_PredTimeHighThres; 
  float32 f_PredTimeFactor = SIT_POT_PRED_TIME_FAC;
  GDBLFunction_t SIT_CutOut_Potential;

#if (SLATE_CFG_CAMERA_TURN_INDICATOR_USAGE)
  percentage_t TurnLightsStateConf = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].t_CamObjectData.t_TurnLightsStateConf;
  FIP_t_CamTurnLightsState TurnLightsState = pt_SITInput->pt_FIPOA->t_ObjList[ObjId].t_CamObjectData.eTurnLightsState;
  float32 f_ObjVrelY = *pt_SITInput->t_RTE.pf_ObjVrelY(ObjId);

  if ( (TurnLightsStateConf > (percentage_t)LA_TURNIND_CONF_MIN)
     &&( ( (TurnLightsState == FIP_CAM_TURN_LIGHT_RIGHT) 
       &&(f_ObjVrelY < -LA_TURNIND_VRELY_THRES)
         )
       ||( (TurnLightsState == FIP_CAM_TURN_LIGHT_LEFT) 
         &&(f_ObjVrelY > LA_TURNIND_VRELY_THRES)
         )
       )
     )
  {  
    f_PredTimeFactor = SIT_POT_PRED_TIME_FAC_TURNIND;
  }
#endif

  /* Low Threshold already hold information about prediction quality
     We use this information also for the High Threshold */
  f_PredTimeHighThres  = f_PredTimeLowThres * f_PredTimeFactor;

  /* Cut-out potential is computed only in case LA predicts the object lane */
  if (f_PredTimeLowThres < C_F32_DELTA)
  {
    f_CutOutpot = SIT_CUT_IN_OUT_POT_MIN;
  }
  /* Check is added to prevent division-by-zero when f_PredTimeLowThres is above f_PredTimeHighThres */
  else if ( ( f_PredTimeHighThres - f_PredTimeLowThres ) > C_F32_DELTA ) 
  {
    /*!< A1 */
    SIT_CutOut_Potential.dAmax = SIT_CUT_IN_OUT_POT_MIN;

    /*!< A2 */
    SIT_CutOut_Potential.dAmin = SIT_CUT_IN_OUT_POT_MAX;

    /*! (A2-A1)/(E2-E1) */
    SIT_CutOut_Potential.dM = ( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( f_PredTimeLowThres - f_PredTimeHighThres );

    /*! A1 - (A2-A1)/(E2-E1) * E1 */
    SIT_CutOut_Potential.dB = SIT_CUT_IN_OUT_POT_MIN -( (( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( f_PredTimeLowThres - f_PredTimeHighThres ) * f_PredTimeHighThres));

    /*! Calculate cutOut potential */
    f_CutOutpot = dGDBmathLineareFunktion(&SIT_CutOut_Potential, (float32)(t_TTOFull_Calculated));
  }
  else
  {
    /* f_PredTimeLowThres is above f_PredTimeHighThres */
    /* This case shall be avoided by parametrization: f_PredTimeLowThres which is computed in LA should always be less than f_PredTimeHighThres */
    /* In case it happens nevertheless, set potential to maximum. */
    f_CutOutpot = SIT_CUT_IN_OUT_POT_MAX;
  }

  return (uint8)f_CutOutpot;
}


/*************************************************************************************************************************
  Functionname:    SIT_u_CutOutPotCalcDist                                                                 */ /*!

  @brief           Calculate cut-in potential

  @description     Calculates the cut-out potential based on Distance to inlapDrop.

                    @startuml
                    Partition SIT_u_CutOutPotCalcDist{
                    Start
                    : Get the Total Distance to InlapDrop;
                    : Calculate cutout potential;
                    End
                    }
                    @enduml

  @return          f_Cut_in_pot : calculated cut out potential value in percent [0u ... 100u]

  @param[in]       ObjId : Object ID [0 ... EM_N_OBJECTS-1]

  @glob_in         pt_SITInput->t_LAInput.pt_f_DistanceToInlapDrop(ObjId) :              []

  @glob_out        None

  @pre             ObjId passed has to belong to a valid object
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @traceability    385:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-385-00061542 \n
                   386:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-386-00061542 \n
                   388:doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-388-00061542 \n
           
  @created         10.08.2018
  @changed         10.08.2018

  @author          Shruthi Ramaiah | Shruthi.ramaiah@continental-corporation.com |
  *************************************************************************************************************************/
uint8 SIT_u_CutOutPotCalcDist(const ObjNumber_t ObjId)
{
  float32 f_CutOutpot;
  float32 f_TotalDistanceToInlapDrop;
  GDBLFunction_t SIT_CutOut_Potential;

  /*! Get the Total TTO */
  f_TotalDistanceToInlapDrop = *(pt_SITInput->t_LAInput.pt_f_TotalDistanceToInlapDrop(ObjId));

  /*!< A1 */
  SIT_CutOut_Potential.dAmax = SIT_CUT_IN_OUT_POT_MIN;

  /*!< A2 */
  SIT_CutOut_Potential.dAmin = SIT_CUT_IN_OUT_POT_MAX;

  /*! (A2-A1)/(E2-E1) */
  SIT_CutOut_Potential.dM = ( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_LOWER - SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER);

  /*! A1 - (A2-A1)/(E2-E1) * E1 */
  SIT_CutOut_Potential.dB = SIT_CUT_IN_OUT_POT_MIN -( (( SIT_CUT_IN_OUT_POT_MAX - SIT_CUT_IN_OUT_POT_MIN ) / ( SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_LOWER - SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER) * SIT_CUT_IN_OUT_DIST_IN_OUT_LAP_UPPER));

  /*! Calculate cutOut potential */
  f_CutOutpot = dGDBmathLineareFunktion(&SIT_CutOut_Potential, f_TotalDistanceToInlapDrop);

  return (uint8)f_CutOutpot;
}


/*************************************************************************************************************************
  Functionname:    SIT_u_CutOutPotFusion                                                                   */ /*!

  @brief           Fuses all cut out potential information.

  @description     Fuses all cut out potential information from camera and kinematics.

                   @startuml
                   Partition SIT_u_CutOutPotFusion{
                   Start
                   : Get Fused cut out potential information;
                   End
                   }
                   @enduml

  @return          u_Potential_fused: Fused cut out potential information.

  @param[in]       iObj :  Object ID [OBJ_INDEX_NO_OBJECT ... EM_N_OBJECTS-1]
  @param[in]       u_KinematicCutOutPot: Integer containing Kinematic CutOut Potential
  @param[in]       u_PotentialDistanceCutInOut: Integer containing CutOut Potential based on Distance

  @glob_in         None

  @glob_out        None

  @pre             None
  @post            None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         23.05.2018
  @changed         23.05.2018

  @author          Grant Davtjan | Grant.Davtjan@continental-corporation.com | +49-8382-9699-633
*************************************************************************************************************************/
uint8 SIT_u_CutOutPotFusion(const ObjNumber_t ObjId, const uint8 u_KinematicCutOutPot, const uint8 u_PotentialDistanceCutInOut)
{
  uint8 u_Potential_fused;
#if FCT_CFG_CAMERA_CUTOUT_POTENTIAL 
  uint8 u_CameraCutOutPotential;
#endif
  if (u_KinematicCutOutPot < u_PotentialDistanceCutInOut)
  {
    u_Potential_fused = pt_SITOutput->t_ObjList[ObjId].u_ObjCutOutPotential;
    u_Potential_fused = MIN(u_Potential_fused, u_PotentialDistanceCutInOut);
  }
  else
  {
    u_Potential_fused = u_KinematicCutOutPot;
  }

#if FCT_CFG_CAMERA_CUTOUT_POTENTIAL 
  u_CameraCutOutPotential = *(pt_SITInput->t_LAInput.pf_CameraCutOutPotential(ObjId));
  u_Potential_fused = MAX(u_Potential_fused, u_CameraCutOutPotential);
#endif

  /* Lowpass Filter of Cut-Out Potential, only falling Flank is filtered, the false-positive rate of the u_ObjCutInPotential Signal is 
  low enough to consider only "loosing" the Signal (a falsely drop in the Signal).*/
  if (u_Potential_fused < pt_SITOutput->t_ObjList[ObjId].u_ObjCutOutPotential)
  {
    u_Potential_fused = (uint8)GDB_FILTER((float32)u_Potential_fused,(float32)pt_SITOutput->t_ObjList[ObjId].u_ObjCutOutPotential,SIT_CUTOUTPOT_FILT_CONST);
  }

  return u_Potential_fused;
}
///@}
#endif /* (FCT_CFG_ACC_SITUATION) */
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
