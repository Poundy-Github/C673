/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_main.c

DESCRIPTION:               Implementation of the EMP process

AUTHOR:                    $Author: BORAIAH, KOMALA (uidk2011) (uidk2011) $

CREATION DATE:             $Date: 2020/07/20 07:08:16CEST $

VERSION:                   $Revision: 1.60 $

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* EMP Includes */
#include "emp_main.h"


#if ( ACDC_CFG_EMP )

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup emp_main Main
@{
*/
/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  STATIC FUNCTION DECLARATIONS
*****************************************************************************/
static void EMP_v_CalcVelToRefPoint(SFLMovement_t   const *const pMovement,
                                    SFLVector2D_t   const *const pVelAtRefPoint,
                                    float32               *const pfVelToTraj,
                                    float32               *const pfVelOnTraj);

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*************************************************************************************************************************
  Functionname:         EMPPredictEgoTraj                                                                            */ /*!

  @brief                Predicts the ego (front/center) trajectory based on its current kinematics and returns it as 2nd
                        degree polynomial.
                        The x/y velocity & acceleration are based on the current velocity, acceleration & body slip angle.
                        While this is correct for short-term predictions, it becomes inaccurate for long-term predictions,
                        in particular the predicted position of center and front can become further apart than half vehicle
                        length.

  @description          The Function predicts the trajectory of the ego front or center movement based on a kinematic
                        assumption. Such an assumption can be e.g. kinematics unchanged.
                        @startuml EMPPredictEgoTraj_activity.png
                        start
                          if(Pointers are valid?) then (Yes)
                            if(predict ego center trajectory?) then (Yes)
                              :Calculate slip angle of ego center;
                              note left: >see formula "Slip Angle"
                              :Set trajectory starting position to vehicle center;
                            else(No)
                              :Calculate slip angle of ego front;
                              note right
                                >see formula "Slip Angle"
                                Note that different body positions
                                have different slip angles
                                end note
                              :Set trajectory starting position to vehicle front;
                            endif
                            if (Maneuver Type is "Kinematics unchanged") then (Yes)
                              :1}
                              :Split velocity and acceleration 
                              in x- and y-part;
                              note left: >see formulas\n"Acceleration Split Unchanged"\nand "Velocity Split Unchanged"
                            elseif (Maneuver Type is "Kinematics without acceleration") Then (Yes)
                              :2}
                              :Split velocity and acceleration
                              in x- and y-part;
                              note left: >see formulas\n"Acceleration Split No Accel"\nand "Velocity Split No Accel"
                            else(No)
                              :3}
                              :Should never happen;
                            endif
                            :Set kinematic variances to default values;
                          else(No)
                            :4}
                            #Orange:Return default ego trajectory 
                            (All kinematics 0):
                            <b>EMPResetTrajPred</b> >
                          endif
                        stop
                        @enduml

  @return               void

  @param[in]            *pIn_KinEgo :     Kinematics of ego vehicle.
  @param[in]            ManeuverType :    Assumed maneuver for which the ego trajectory shall be predicted.
  @param[out]           *pOut_TrajPred :   Calculated trajectory.

  @glob_in              @ref ACDC_p_GetEgoGeometry \n
  @glob_out             None

  @c_switch_part        @ref ACDC_CFG_USE_REAL_EGO_DIMENSION
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     
                        - **Formula Slip Angle:**\n
                          \f$\alpha_{Slip,Center} = \frac{Wheelbase_{Ego} \cdot 0.5 \cdot YawRate_{Ego}}{V_{Ego}}\f$
                          \f$\alpha_{Slip,Front} = \frac{Wheelbase_{Ego} \cdot YawRate_{Ego}}{V_{Ego}}\f$
                        - **Formula Acceleration Split Unchanged:** \n
                          \f$0.5 \cdot A_X = -0.5 \cdot V_{Ego} \cdot YawRate_{Ego} \cdot \sin(\alpha_{Slip})\f$\n
                          \f$0.5 \cdot A_Y = 0.5 \cdot V_{Ego} \cdot YawRate_{Ego} \cdot \cos(\alpha_{Slip})\f$
                        - **Formula Velocity Split Unchanged:** \n
                          \f$V_X = V_{Ego} \cdot \cos(\alpha_{Slip})\f$ \n
                          \f$V_Y = V_{Ego} \cdot \sin(\alpha_{Slip})\f$
                        - **Formula Acceleration Split No Accel:** \n
                          \f$0.5 \cdot A_X = (0.5 \cdot A_{Ego} \cdot \cos(\alpha_{Slip})) - (0.5 \cdot V_{Ego} \cdot YawRate_{Ego} \cdot \sin(\alpha_{Slip}))\f$ \n
                          \f$0.5 \cdot A_Y = (0.5 \cdot A_{Ego} \cdot \sin(\alpha_{Slip})) + (0.5 \cdot V_{Ego} \cdot YawRate_{Ego} \cdot \cos(\alpha_{Slip}))\f$
                        - **Formula Velocity Split No Accel:** \n
                          \f$V_X = V_{Ego} \cdot \cos(\alpha_{Slip})\f$\n
                          \f$V_Y = V_{Ego} \cdot \sin(\alpha_{Slip})\f$

  @testmethod           @ref TEST_EMPPREDICTEGOTRAJ_001 \n
                        @ref TEST_EMPPREDICTEGOTRAJ_002 \n
                        @ref TEST_EMPPREDICTEGOTRAJ_003 \n
                        @ref TEST_EMPPREDICTEGOTRAJ_004 \n
						@ref TEST_EMPPREDICTEGOTRAJ_005 \n
                        @ref TEST_EMPPREDICTEGOTRAJ_006 \n
                        @ref TEST_EMPPREDICTEGOTRAJ_007

  @traceability         Design Decision

  @todo                 assure that implementation is according to design => seems that maneuver types in switch...case are swapped.

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
extern void EMPPredictEgoTraj(ACDCKinEgo_t       const *const pIn_KinEgo, 
                              ACDCManeuverType_e              ManeuverType, 
                              ACDCTrajPred_t           *const pOut_TrajPred )
{

  if (pIn_KinEgo != NULL)
  {
    /* Retrieve current Motion States */
    const float32 fCurrEgoVel     = pIn_KinEgo->fVel;
    const float32 fCurrEgoAccel   = pIn_KinEgo->fAccel;
    const float32 fCurrEgoYawRate = pIn_KinEgo->fYawRate;
    const float32 fCurrALat       = fCurrEgoVel * fCurrEgoYawRate;
    float32 fCurrSlipAngle;
    float32 fSinSlipAngle;
    float32 fCosSlipAngle;
    const float32 fEgoVehLength    = ACDC_p_GetEgoGeometry()->fLength;
#if (ACDC_CFG_USE_REAL_EGO_DIMENSION)
    float32 fEgoVehWheelBase = ACDC_p_GetVehPar()->VehParMain.WheelBase;
    /*set default values in case of implausible input data*/
    if(fEgoVehWheelBase < ( 0.5f*fEgoVehLength ) )
    {
      fEgoVehWheelBase = FCT_WHEELBASE_DEFAULT;
    }
#else
    const float32 fEgoVehWheelBase = FCT_WHEELBASE_DEFAULT;
#endif

    switch (ManeuverType)
    {
    case ACDC_MANEUVER_KinematicsWithoutAcceleration_Front:
    case ACDC_MANEUVER_KinematicsUnchanged_Front:
      fCurrSlipAngle = (fABS(fCurrEgoVel) > C_F32_DELTA) ?
        (((fEgoVehWheelBase) * fCurrEgoYawRate) / fCurrEgoVel) : 0.0f;
      pOut_TrajPred->XofT.fC0 = 0.0f;
      break;
    default:
      fCurrSlipAngle = (fABS(fCurrEgoVel) > C_F32_DELTA) ?
        (((fEgoVehWheelBase * 0.5f) * fCurrEgoYawRate) / fCurrEgoVel) : 0.0f;
      pOut_TrajPred->XofT.fC0 = -( fEgoVehLength * 0.5f);
      break;
    }

    GDBsincos(fCurrSlipAngle,&fSinSlipAngle,&fCosSlipAngle);
    pOut_TrajPred->YofT.fC0 = 0.0f;

    switch (ManeuverType)
    {
    case ACDC_MANEUVER_KinematicsWithoutAcceleration:
    case ACDC_MANEUVER_KinematicsWithoutAcceleration_Front:
      pOut_TrajPred->XofT.fC2 =                                        - (0.5f * fCurrALat * fSinSlipAngle);
      pOut_TrajPred->XofT.fC1 =         fCurrEgoVel *  fCosSlipAngle;

      pOut_TrajPred->YofT.fC2 =                                          (0.5f * fCurrALat * fCosSlipAngle);
      pOut_TrajPred->YofT.fC1 =         fCurrEgoVel *  fSinSlipAngle;
      break;
    case ACDC_MANEUVER_KinematicsUnchanged:
    case ACDC_MANEUVER_KinematicsUnchanged_Front:
    default:
      pOut_TrajPred->XofT.fC2 = (0.5f * fCurrEgoAccel * fCosSlipAngle) - (0.5f * fCurrALat * fSinSlipAngle);
      pOut_TrajPred->XofT.fC1 =         fCurrEgoVel *  fCosSlipAngle;

      pOut_TrajPred->YofT.fC2 = (0.5f * fCurrEgoAccel * fSinSlipAngle) + (0.5f * fCurrALat * fCosSlipAngle);
      pOut_TrajPred->YofT.fC1 =         fCurrEgoVel *  fSinSlipAngle;
      break;
    }

    /* Fill the rest of output Structure */
    pOut_TrajPred->VarXofT.fC0 = EMP_DEFAULT_EGO_VAR_X_C0;
    pOut_TrajPred->VarXofT.fC1 = EMP_DEFAULT_EGO_VAR_X_C1;
    pOut_TrajPred->VarXofT.fC2 = EMP_DEFAULT_EGO_VAR_X_C2;

    pOut_TrajPred->VarYofT.fC0 = EMP_DEFAULT_EGO_VAR_Y_C0;
    pOut_TrajPred->VarYofT.fC1 = EMP_DEFAULT_EGO_VAR_Y_C1;
    pOut_TrajPred->VarYofT.fC2 = EMP_DEFAULT_EGO_VAR_Y_C2;
  } 
  else
  {
    EMPResetTrajPred(pOut_TrajPred);
  }
}

/*************************************************************************************************************************
  Functionname:         EMPPredictObjTraj                                                                            */ /*!

  @brief                Predicts the objects trajectory based on its current kinematics and returns it as 2nd degree polynomial.

  @description          The Function predicts the movement of an object based on a kinematic assumption. Such an assumption can 
                        be e.g. object brakes. Unlike the ego trajectory prediction, for the object prediction the acceleration 
                        is not considered. The Reason is that the measured acceleration is not sufficiently reliable.
                        @startuml EMPPredictObjTraj_activity.png
                        start
                          if(Pointers are valid?) then (Yes)
                            :Write input data to coefficients;
                            note left
                              Acceleration is set to 0
                            end note

                            if(Maneuver Assumption is "Comfort braking"?) then (Yes)
                              :1}
                              :Set acceleration to value for comfort braking;
                            elseif (Maneuver Assumption is "Full braking"?) then (Yes)
                              :2}
                              :Set acceleration to value for full braking;
                            else (No)
                              :3}
                              :Leave kinematics unchanged 
                              (=No acceleration);
                            endif
                          else(No)
                            :4}
                            #Orange:Return reseted trajectory prediction &
                            raise error flag:
                            <b>EMPResetTrajPred</b> >
                          endif
                        stop
                        @enduml

  @return               boolean: True if no error occurred.

  @param[in]            *pIn_KinObj :     Kinematics of an object.
  @param[in]            eAssumption :     Assumed maneuver for which the ego trajectory shall be predicted.
  @param[in,out]        *pOut_TrajPred :  Calculated trajectory.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPPREDICTOBJTRAJ_001\n
                        @ref TEST_EMPPREDICTOBJTRAJ_002\n
                        @ref TEST_EMPPREDICTOBJTRAJ_003\n
                        @ref TEST_EMPPREDICTOBJTRAJ_004

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
boolean EMPPredictObjTraj(ACDCObjDescMain_t  const *const pIn_KinObj, 
                          ACDCManeuverType_e              eAssumption, 
                          ACDCTrajPred_t           *const pOut_TrajPred )
{
  boolean bResultOk = b_TRUE;

  if (pIn_KinObj != NULL)
  {
    pOut_TrajPred->XofT.fC0 = pIn_KinObj->Positions.GenObject.fX;
    pOut_TrajPred->XofT.fC1 = pIn_KinObj->Movement.Abs.Vel.fX;
    switch(eAssumption)
    {
    case ACDC_MANEUVER_ComfortBraking:
      {
        pOut_TrajPred->XofT.fC2 = 0.5f * EMP_OBJ_BRAKE_DECEL_COMFORT;
        break;
      }
    case ACDC_MANEUVER_FullBraking:
      {
        pOut_TrajPred->XofT.fC2 = 0.5f * EMP_OBJ_BRAKE_DECEL_FULL;
        break;
      }
    default:
      pOut_TrajPred->XofT.fC2 = 0.0f;
      break;
    }

    pOut_TrajPred->YofT.fC0 = pIn_KinObj->Positions.GenObject.fY;
    pOut_TrajPred->YofT.fC1 = pIn_KinObj->Movement.Abs.Vel.fY;
    pOut_TrajPred->YofT.fC2 = 0.0f;

    /* Fill the rest of output Structure */
    pOut_TrajPred->VarXofT.fC0 = pIn_KinObj->Positions.Var.fX;
    pOut_TrajPred->VarXofT.fC1 = pIn_KinObj->Movement.Var.Vel.fX;
    pOut_TrajPred->VarXofT.fC2 = 0.0f;

    pOut_TrajPred->VarYofT.fC0 = pIn_KinObj->Positions.Var.fY;
    pOut_TrajPred->VarYofT.fC1 = pIn_KinObj->Movement.Var.Vel.fY;
    pOut_TrajPred->VarYofT.fC2 = 0.0f;
  }
  else
  {
    EMPResetTrajPred(pOut_TrajPred);
    bResultOk = b_FALSE;
  }

  return bResultOk;
}

/*************************************************************************************************************************
  Functionname:         EMPCalcCollProbObjObj                                                                        */ /*!

  @brief                Calculates collision probability of two objects at a given time.

  @description          Calculates the collision probability of two objects, by converting their data into the 
                        required format and calling the function @ref EMPCalcCollProbExDesc.
                        @startuml EMPCalcCollProbObjObj_activity.png
                          start
                          if(Pointers are valid?) then (Yes)
                            :1}
                            #Orange:Convert data of object 1 to 
                            existence description format
                            <b>EMPCalcObjExDesc</b> >
                            #Orange:Convert data of object 2 to 
                            existence description format
                            <b>EMPCalcObjExDesc</b> >
                            #Orange:Calculate collision probability based
                            on existence description format
                            <b>EMPCalcCollProbExDesc</b> >
                          else(No)
                            :2}
                            :Raise error flag;
                          endif
                          stop
                        @enduml

  @return               boolean: True if no error occurred

  @param[in]            fTime :               Time at which the collision probability shall be calculated. @phys_unit [s]
  @param[in]            *pIn_Obj1 :           Position and kinematics of object 1
  @param[in]            *pIn_Obj2 :           Position and kinematics of object 2
  @param[out]           *pOut_CollisionProb : Returned collision probability @range [0,1]

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPCALCCOLLPROBOBJOBJ_001 \n
                        @ref TEST_EMPCALCCOLLPROBOBJOBJ_002 \n
						@ref TEST_EMPCALCCOLLPROBOBJOBJ_003

  @traceability         Design Decision


  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
boolean EMPCalcCollProbObjObj(float32                   fTime, 
                              ACDCObjPred_t const *const pIn_Obj1, 
                              ACDCObjPred_t const *const pIn_Obj2, 
                              float32            *const pOut_CollisionProb )
{
  boolean bResultOk = b_TRUE;

  if ((pIn_Obj1 != NULL) && (pIn_Obj2 != NULL) )
  {
    /* Extract Existence Description from Input Objects */
    EMPObjExDesc_t sExDescObj1;
    EMPObjExDesc_t sExDescObj2;
	/*PRQA S 2986,4502,4430 4*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Operation is redundant,but arguments are differnt in each operation.*/
    bResultOk &= EMPCalcObjExDesc( fTime, pIn_Obj1, &sExDescObj1 );
    bResultOk &= EMPCalcObjExDesc( fTime, pIn_Obj2, &sExDescObj2 );

    bResultOk &= EMPCalcCollProbExDesc( &sExDescObj1, &sExDescObj2, pOut_CollisionProb );
  } 
  else
  {
    bResultOk = b_FALSE;
  }

  return bResultOk;
}


/*************************************************************************************************************************
  Functionname:         EMP_v_CalcObjToEgoTrajRelation                                                                  */ /*!

  @brief                Calculates the Relation between a trajectory and an object.
  
  @description          Calculates the Relation between a trajectory and an object and describes it with the following attributes:
                        - **DistToTraj** (Distance To Trajectory): \n
                          Distance of the current object and the predicted ego trajectory
                        - **DistToTrajMin** (Distance To Trajectory Minimum): \n
                          Distance of the predicted ego trajectory and the most right point of the object
                        - **DistToTrajMax** (Distance To Trajectory Maximum): \n
                          Distance of the predicted ego trajectory and the most left point of the object
                        - **DistOnTraj** (Distance On Trajectory): \n
                          Distance of the ego vehicle and the current object projected to the predicted ego trajectory
                        - **VelToTraj**  (Velocity To Trajectory): \n
                          Velocity of the object pointing towards the predicted ego trajectory
                        - **VelOnTraj**  (Velocity On Trajectory): \n
                          Velocity of the object pointing along with the predicted ego trajectory
                        .
                        More details can be found in the description of the functions @ref EMP_v_CalcDistToRefPoint and @ref EMP_v_CalcVelToRefPoint.
                        @startuml EMP_v_CalcObjToTrajRelation_activity.png
                        start
                          #Orange:Calculate Reference Point of the object 
                          position on the ego trajectory:
                          <b>EMP_b_CalcTrajectoryRefPoint</b> >
                          if(Reference Point found?) then (Yes)
                            :1}
                            #Orange:Calculate DistTo/OnTraj, VelDistTo/OnTraj and AngleOnTraj:
                            <b>EMP_v_CalcDistToRefPoint</b>
                            <b>EMP_v_CalcVelToRefPoint</b>
                            <b>SFL_f_CalcAngleFromVector</b> >
                          else
                            :2}
                            :Set traj relation default values;
                          endif
partition #LightBlue **ACDC_CFG_USE_OBJECT_CIRCLES** {
                          #Orange:Use object circle calculation to calculate 
                          a more precise DistToTrajMin and DistToTrajMax:
                          <b>EMP_v_CalcObjectCircles</b> >
}
                          :Write the calculated data 
                          to the TrajRelation structure;
                        stop
                        @enduml

  @return               void

  @param[in]            iObjectIndex       : Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pObjToTrajRelation : Resulting trajectory relation of object and ego vehicle

  @glob_in              @ref ACDC_p_GetObjDescMain \n
                        @ref AIP_p_GetACDCEgoTraj \n
  @glob_out             @ref ACDC_p_ModSimuData

  @c_switch_part        @ref ACDC_CFG_USE_OBJECT_CIRCLES \n
                        @ref ACDC_SIMU
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMP_V_CALCOBJTOEGOTRAJRELATION_001\n
                        @ref TEST_EMP_V_CALCOBJTOEGOTRAJRELATION_002

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void EMP_v_CalcObjToEgoTrajRelation(ObjNumber_t             const         iObjectIndex,
                                    ACDCObjToTrajRelation_t       *const  pObjToTrajRelation)
{
  
#if (ACDC_CFG_USE_OBJECT_CIRCLES)
  ACDCObjectCircle_t     MinDistCircle;
  ACDCObjectCircle_t     MaxDistCircle;
  ACDCObjectCircleData_t CircleData;
#endif

  ACDCObjDescMain_t const * const pObject         = ACDC_p_GetObjDescMain(iObjectIndex);

  ACDCTrajPred_t    const * const pEgoTrajPred     = AIP_p_GetACDCEgoTraj(ACDC_MANEUVER_KinematicsWithoutAcceleration);
  boolean                         bRefPointFound;
  SFLVector2D_t                   RefPoint;
  SFLVector2D_t                   VelAtRefPoint;
  float32                         fDistOnTrajAngle;
  float32                         fDistToTraj;
  float32                         fDistOnTraj;
  float32                         fVelToTraj;
  float32                         fVelOnTraj;

  SFLMovement_t                   ObjMovement;
  SFLVector2D_t                   ObjPosition;

  ObjMovement = pObject->Movement.Abs;
  ObjPosition = pObject->Positions.GenObject;

  /* Calculate the Distance To/On trajectory for the current Object */
  bRefPointFound = EMP_b_CalcTrajectoryRefPoint(&(ObjPosition), pEgoTrajPred, &RefPoint, &VelAtRefPoint);
  
  if(bRefPointFound == b_TRUE)
  {
    /* Calculate the Velocity and Distance To/On trajectory for the current Object */
    EMP_v_CalcDistToRefPoint(&(ObjPosition), &RefPoint     , &fDistToTraj, &fDistOnTraj);

    EMP_v_CalcVelToRefPoint (&(ObjMovement), &VelAtRefPoint, &fVelToTraj , &fVelOnTraj );
    fDistOnTrajAngle = SFL_f_CalcAngleFromVector(VelAtRefPoint.fX, VelAtRefPoint.fY, b_FALSE);
  }
  else
  {
    fVelOnTraj       = 0.f;
    fVelToTraj       = 0.f;
    fDistToTraj      = ACDC_DIST_DEFAULT;
    fDistOnTraj      = ACDC_DIST_DEFAULT;
    fDistOnTrajAngle = 0.f;
  }
  /* Write the calculated data to the output structure */
  pObjToTrajRelation->fDistToTraj         = fDistToTraj;
  pObjToTrajRelation->fDistToTrajVar      = pObject->Positions.Var.fY; /* As an Approximation */
  pObjToTrajRelation->fVelocityToTraj     = fVelToTraj;
  pObjToTrajRelation->fVelocityToTrajVar  = pObject->Movement.Var.Vel.fY; /* As an Approximation */
  pObjToTrajRelation->fDistOnTraj         = fDistOnTraj;
  pObjToTrajRelation->fDistOnTrajVar      = pObject->Positions.Var.fX; /* As an Approximation */
  pObjToTrajRelation->fVelocityOnTraj     = fVelOnTraj;
  pObjToTrajRelation->fVelocityOnTrajVar  = pObject->Movement.Var.Vel.fX; /* As an Approximation */
  pObjToTrajRelation->fDistToTrajAngle    = fDistOnTrajAngle + CML_Deg2Rad(90.f);

#if (ACDC_CFG_USE_OBJECT_CIRCLES)
  /* Calculate Circles to describe the object and determine the DistToTrajMin/Max */
  EMP_v_CalcObjectCircles(iObjectIndex, &(CircleData));
  MinDistCircle = CircleData.ObjectCircles[CircleData.uMinDistCircle];
  MaxDistCircle = CircleData.ObjectCircles[CircleData.uMaxDistCircle];

  /* Calculate the DistToTrajMin/Max on base of the circles */
  pObjToTrajRelation->fDistToTrajMin      = MinDistCircle.fDistToTraj - MinDistCircle.Circle.fRadius;
  pObjToTrajRelation->fDistToTrajMax      = MaxDistCircle.fDistToTraj + MaxDistCircle.Circle.fRadius;
  pObjToTrajRelation->fDistToTrajMinAngle = MinDistCircle.fRefPointAngle + CML_Deg2Rad(90.f);
  pObjToTrajRelation->fDistToTrajMaxAngle = MaxDistCircle.fRefPointAngle + CML_Deg2Rad(90.f);
#ifdef ACDC_SIMU
  ACDC_p_ModSimuData()->sObjData.aObj[iObjectIndex].AIP.ObjDesc.ObjectCircleData = CircleData;
#endif
#else
  /* Calculate the DistToTrajMin/Max on base of the objects DistToTraj and its width. */
  pObjToTrajRelation->fDistToTrajMin      = fDistToTraj - (pObject->Geometry.fWidth * 0.5f);
  pObjToTrajRelation->fDistToTrajMax      = fDistToTraj + (pObject->Geometry.fWidth * 0.5f);
  pObjToTrajRelation->fDistToTrajMinAngle = pObjToTrajRelation->fDistToTrajAngle;
  pObjToTrajRelation->fDistToTrajMaxAngle = pObjToTrajRelation->fDistToTrajAngle;
#endif /* #if (ACDC_CFG_USE_OBJECT_CIRCLES) */

}

/*************************************************************************************************************************
  Functionname:         EMP_v_CalcDistBasedObjToEgoTrajRelation                                                      */ /*!

  @brief                Calculates the Relation between a distance-based trajectory and an object.

  @description          Calculates the Relation between a distance-based trajectory and an object and describes it with the following attributes:
                        - **DistToTraj** (=Distance To Trajectory): \n
                          Describes the minimal distance of the current object position and the ego trajectory. 
                          (absolute distance value, always positive)
                        - **DistOnTraj** (=Distance On Trajectory): \n
                          Describes the distance, the ego vehicle has to cover (if it follows its current trajectory) \n
                          until it reaches the point of minimum distance to the current object position.
                          @startuml EMP_v_CalcDistBasedObjToEgoTrajRelation_activity.png
                          start
                          if(Abs(Curvature) is bigger than C_F32_DELTA?)
                            :Calculate trajectory Radius and Angle;
                            note left:>see **Alpha**
                            if(Angle is not equal pi/2 or - pi/2?) then (Yes)
                            :1}
                            #Orange:Calculate Distance To/On Trajectory:
                            <b>SFL_s_SetupVector2</b> >;
                            note left:>see **DistToTraj** and **DistOnTraj**
                            else (No)
                            :2}
                            :Set traj relation default values;
                            endif
                          else (No)
                            :Set traj relation as trajectory position;
                          endif
                          stop
                          @enduml

  @return               void

  @param[in]            iObjectIndex       : Index of the considered object. @range [0, EM_N_OBJECTS]
  @param[in,out]        pObjToTrajRelation : Resulting trajectory relation of object and ego vehicle

  @glob_in              @ref ACDC_p_GetObjDescMain \n
                        @ref ACDC_p_GetVDYDynObjSync
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure object position in X direction is positive
  @post                 None

  @InOutCorrelation     - **Formula distance-based trajectory relation**: \n
                          \f$\Alpha = \arctan(\frac{X}{|Radius-Y|})\f$\n
                          \f$DistToTraj = \sqrt{(X_{Ref} - X)^2 + (Y_{Ref} - Y)^2}\f$\n
                          \f$DistOnTraj = X_{Ref}\f$

  @testmethod           @ref TEST_EMP_V_CALCDISTBASEDOBJTOEGOTRAJRELATION_001 \n
                        @ref TEST_EMP_V_CALCDISTBASEDOBJTOEGOTRAJRELATION_002 \n
						@ref TEST_EMP_V_CALCDISTBASEDOBJTOEGOTRAJRELATION_003

  @traceability         Design Decision

  @author               Wenting Huang | wenting.huang@continental-corporation.com
*************************************************************************************************************************/
void EMP_v_CalcDistBasedObjToEgoTrajRelation(ObjNumber_t             const         iObjectIndex,
                                             ACDCObjToTrajRelation_t       *const  pObjToTrajRelation)
{
  ACDCObjDescMain_t const * const pObject     = ACDC_p_GetObjDescMain(iObjectIndex);
  /*PRQA S 3334 1*/ /* #date: 2023-02-20, reviewer: Veeresh B, reason: No side effect, Generic Implementation */
  float32           const         fCurvature  = ACDC_p_GetVDYDynObjSync()->Lateral.Curve.Curve;
  float32                         fRadius;
  float32                         fAlpha;
  SFLVector2D_t                   RefPoint;
  SFLVector2D_t                   ObjPosition;
  
  ObjPosition = pObject->Positions.GenObject;

  if( fABS(fCurvature) > C_F32_DELTA )
  {
    fRadius = 1.f / fCurvature;
    fAlpha = ATAN2_(ObjPosition.fX, fABS(fRadius - ObjPosition.fY));
    if ( (fABS(fABS(fAlpha) - (CML_f_Pi * 0.5f)) > C_F32_DELTA) )
    {
      RefPoint = SFL_s_SetupVector2(fABS(fRadius * SIN_HD_(fAlpha)), fRadius * (1.f - COS_HD_(fAlpha)));
      pObjToTrajRelation->fDistToTraj = SQRT(SQR(RefPoint.fX - ObjPosition.fX) + SQR(RefPoint.fY - ObjPosition.fY));
      /* Calculate the Distance on trajectory (= X Distance between 0 and the given position and the ref point on the trajectory)
       => Approximation, no real Distance on Trajectory! (which would be the arc length) */
      pObjToTrajRelation->fDistOnTraj = RefPoint.fX;
    }
    else
    {
      pObjToTrajRelation->fDistToTraj = ACDC_DIST_DEFAULT;
      pObjToTrajRelation->fDistOnTraj = ACDC_DIST_DEFAULT;
    }
  }
  else
  {
    /* ego vehicle drives forward to target*/
    pObjToTrajRelation->fDistToTraj = ObjPosition.fY;
    pObjToTrajRelation->fDistOnTraj = ObjPosition.fX;
  }

  pObjToTrajRelation->fDistToTrajVar = pObject->Positions.Var.fY; /* As an Approximation */
  pObjToTrajRelation->fDistOnTrajVar = pObject->Positions.Var.fX; /* As an Approximation */

}

/*************************************************************************************************************************
  Functionname:         EMPPredictTrajRelation                                                                       */ /*!

  @brief                Predicts a given trajectory relation structure of an object until a given time.

  @description          Predicts the Dist(To/On)Traj, the Dist(To/On)TrajVar, the DistToTrajMax and 
                        the DistToTrajMin and writes the results into the output structure. \n
                        To predict the DistToTrajMin/Max, the angle deltas between the DistToTraj and the 
                        DistToTrajMin/Max are used to project the VelocityTo/OnTraj onto the vectors of the \n
                        DistToTrajMin/Max.
                        @startuml EMPPredictTrajRelation_activity.png
                        start
                          :Predict DistToTraj(Min/Max);
                          note left:>see Formula "DistToTrajMin/MaxPred"
                          :Predict Dist(To/On)Traj;
                          note left:>see Formula "DistTo/OnTrajPred"
                          :Predict Dist(To/On)TrajVar;
                          note left:>see Formula "DistTo/OnTrajVarPred"
                        stop
                        @enduml
  @return               void

  @param[in]            pTrajRel :     Trajectory Relation which shall be predicted.
  @param[in]            fPredTime :    Time for which it shall be predicted. @phys_unit [s], @range ]-...,+...[
  @param[in,out]        pTrajRelPred : Resulting predicted trajectory relation.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     
                        - **Formula fDistTo/OnTrajVarPred:**\n
                          \f$D_{ToTraj,Var,t} = D_{ToTraj,Var,Now} + V_{ToTraj,Var,Now} \cdot t_{Pred}\f$
                          \f$D_{OnTraj,Var,t} = D_{OnTraj,Var,Now} + V_{OnTraj,Var,Now} \cdot t_{Pred}\f$
                        - **Formula fDistTo/OnTrajPred:**\n
                          \f$D_{ToTraj,t} = D_{ToTraj,Now} + V_{ToTraj,Now} \cdot t_{Pred}\f$
                          \f$D_{OnTraj,t} = D_{OnTraj,Now} + V_{OnTraj,Now} \cdot t_{Pred}\f$
                        - **Formula fDistToTrajMin/MaxPred:**\n
                          \f$DeltaAngle_{Max}    = Angle_{DistToTrajMax} - Angle_{DistToTraj}\f$ \n
                          \f$DeltaAngle_{Min}    = Angle_{DistToTrajMin} - Angle_{DistToTraj}\f$ \n
                          \f$D_{ToTrajMax,Delta} = (\cos(DeltaAngle_{Max}) \cdot V_{ToTraj,Now} + \sin(DeltaAngle_{Max}) \cdot V_{OnTraj,Now}) \cdot t_{Pred}\f$\n
                          \f$D_{ToTrajMin,Delta} = (\cos(DeltaAngle_{Min}) \cdot V_{ToTraj,Now} + \sin(DeltaAngle_{Min}) \cdot V_{OnTraj,Now}) \cdot t_{Pred}\f$\n
                          \f$D_{ToTrajMax,t}     = D_{ToTrajMax,Now} + D_{ToTrajMax,Delta}\f$\n
                          \f$D_{ToTrajMin,t}     = D_{ToTrajMin,Now} + D_{ToTrajMin,Delta}\f$

  @testmethod           @ref TEST_EMPPREDICTTRAJRELATION_001

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void EMPPredictTrajRelation(ACDCObjToTrajRelation_t const * const pTrajRel,
                            float32                               fPredTime,
                            ACDCObjToTrajRelation_t       * const pTrajRelPred)
{
  float32 fCosAngleDeltaMax;
  float32 fCosAngleDeltaMin;
  float32 fSinAngleDeltaMax;
  float32 fSinAngleDeltaMin;
  float32 fAngleDeltaMax            = (pTrajRel->fDistToTrajMaxAngle - pTrajRel->fDistToTrajAngle);
  float32 fAngleDeltaMin            = (pTrajRel->fDistToTrajMinAngle - pTrajRel->fDistToTrajAngle);
  
  /* Initialize the TrajRelPred Structure with the values of the TrajRel Structure */
  (*pTrajRelPred) = (*pTrajRel);

  /* Project the VelocityTo/OnTraj onto the angle of the DistToTrajMax/Min, 
     multiply with prediction time and add to DistToTrajMin/Max */
  GDBsincos(fAngleDeltaMax, &fSinAngleDeltaMax, &fCosAngleDeltaMax);
  GDBsincos(fAngleDeltaMin, &fSinAngleDeltaMin, &fCosAngleDeltaMin);

  pTrajRelPred->fDistToTrajMax      =   (pTrajRel->fDistToTrajMax                                   )
                                      + (   (   (fCosAngleDeltaMax * pTrajRel->fVelocityToTraj)
                                              + (fSinAngleDeltaMax * pTrajRel->fVelocityOnTraj) )
                                          * (fPredTime                                            ) );

  pTrajRelPred->fDistToTrajMin      =   (pTrajRel->fDistToTrajMin                                   )
                                      + (   (   (fCosAngleDeltaMin * pTrajRel->fVelocityToTraj)
                                              + (fSinAngleDeltaMin * pTrajRel->fVelocityOnTraj) )
                                          * (fPredTime                                            ) );

  /* Predict the DistTo/OnTraj with the VelocityTo/OnTraj */
  pTrajRelPred->fDistToTraj         = pTrajRel->fDistToTraj    + (pTrajRel->fVelocityToTraj    * fPredTime);
  pTrajRelPred->fDistOnTraj         = pTrajRel->fDistOnTraj    + (pTrajRel->fVelocityOnTraj    * fPredTime);
  
  /* Predict the DistTo/OnTrajVar with the VelocityTo/OnTrajVar */
  pTrajRelPred->fDistToTrajVar      = pTrajRel->fDistToTrajVar + (pTrajRel->fVelocityToTrajVar * fPredTime);
  pTrajRelPred->fDistOnTrajVar      = pTrajRel->fDistOnTrajVar + (pTrajRel->fVelocityOnTrajVar * fPredTime);

}



/*************************************************************************************************************************
  Functionname:         EMP_b_CalcTrajectoryRefPoint                                                                 */ /*!

  @brief                Calculates the point on a given time based trajectory at which the distance to a given 
                        position is minimal.

  @description          
                        @startuml EMP_b_CalcTrajectoryRefPoint_activity.png
                        start
                          #Orange:Set up a help trajectory with 
                          C2 = 0, C1 = 0 and C0 = Position
                          <b>EMPResetTrajPred</b> >
                          #Orange:Calculate the time of minimum 
                          distance of the two trajectories:
                          <b>EMPCalcMinDistTime</b> >
                          if(Found time is valid?)  then (Yes)
                            :1}
                          else (No, e.g. too long, negative, ...)
                            :2}
                            :Set MinDistTime to default value;
                            :Set bRefPointFound to FALSE;
                          endif
                          #Orange:Calculate the position at the MinDistTime:
                          <b>EMPCalcPositionAtTime</b> >
                          :Calculate the ego orientation at the MinDistTime;
                          note left:>see **Orientation at MinDistTime**
                        stop
                        @enduml

  @return               boolean bRefPointFound: Boolean indicating if a reference point was found (TRUE) or not (FALSE)

  @param[in]            pPosition :      Position for which a ref point on the trajectory shall be calculated.
  @param[in]            pTrajectory :    Trajectory on which a ref point shall be found
  @param[in,out]        pRefPoint :      Calculated reference point (= Point of minimal distance to the given position on the trajectory)
  @param[in,out]        pVelAtRefPoint : Calculated orientation at the reference point

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP\n

  @pre                  None
  @post                 None

  @InOutCorrelation     - **Orientation at MinDistTime:**\n
                          \f$X = C_{1,X} + 2 \cdot C_{2,X} \cdot T_{MinDist}\f$
                          \f$Y = C_{1,Y} + 2 \cdot C_{2,Y} \cdot T_{MinDist}\f$

  @testmethod           @ref TEST_EMP_B_CALCTRAJECTORYREFPOINT_001 \n
                        @ref TEST_EMP_B_CALCTRAJECTORYREFPOINT_002 \n
						@ref TEST_EMP_B_CALCTRAJECTORYREFPOINT_003 \n
                        @ref TEST_EMP_B_CALCTRAJECTORYREFPOINT_004

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
boolean EMP_b_CalcTrajectoryRefPoint(SFLVector2D_t  const * const pPosition,
                                     ACDCTrajPred_t const * const pTrajectory,
                                     SFLVector2D_t        * const pRefPoint,
                                     SFLVector2D_t        * const pVelAtRefPoint)
{
  
  boolean       bRefPointFound = b_TRUE;
  ACDCTrajPred_t HelpTrajectory;
  float32       fMinDistTime;
  
  /* Fill Obj of current TimeStep into an artificial trajectory structure */
  EMPResetTrajPred( &HelpTrajectory);
  HelpTrajectory.XofT.fC0 = pPosition->fX;
  HelpTrajectory.YofT.fC0 = pPosition->fY;

  /* Calculate the time at which the distance between the position and the trajectory is minimal */
  /*PRQA S 2986,4502,4430 4*/ /* date: 2019-06-01, reviewer: Praveen Annareddy, reason: Bitwise AND operation can be performed b/n unsigned char types*/
  bRefPointFound &= EMPCalcMinDistTime( pTrajectory, &HelpTrajectory, &fMinDistTime );

  /* Check if the found time is out of the permitted limits */
  if(    (bRefPointFound == b_FALSE                       )
      || (fMinDistTime    >  EMP_PREDICTION_TIME_EGO_MAX)
      || (fMinDistTime   < C_F32_DELTA                ) )
  {
    fMinDistTime   = EMP_PREDICTION_TIME_EGO_MAX;
    bRefPointFound = b_FALSE;
  }
  
  /* Calculate the position and velocity of the trajectory at the MinDistTime */
  EMPCalcPositionAtTime( fMinDistTime, pTrajectory, pRefPoint );
  pVelAtRefPoint->fX     = pTrajectory->XofT.fC1 + ( ( 2.0f * pTrajectory->XofT.fC2 ) * fMinDistTime);
  pVelAtRefPoint->fY     = pTrajectory->YofT.fC1 + ( ( 2.0f * pTrajectory->YofT.fC2 ) * fMinDistTime);

  return bRefPointFound;
}


/*************************************************************************************************************************
  Functionname:         EMP_v_CalcDistToRefPoint                                                                    */ /*!

  @brief                Calculates the distance to trajectory and the distance on trajectory for a given position.\n

  @description          The function requires a position and the corresponding reference position on the trajectory 
                        (calculated by @ref EMP_b_CalcTrajectoryRefPoint).
                        The following distances are calculated by this function:
                        - **DistToTraj** (=Distance To Trajectory): \n
                          Describes the minimal distance of the current object position and the ego trajectory. 
                          (negative if right of the trajectory)
                        - **DistOnTraj** (=Distance On Trajectory): \n
                          Describes the distance, the ego vehicle has to cover (if it follows its current trajectory) \n
                          until it reaches the point of minimum distance to the current object position.
                        .
                        @startuml EMP_v_CalcDistToRefPoint_activity.png
                        start
                          :Calculate the Distance to trajectory
                          (= Distance between the Position and the RefPoint);
                          note left:>see **DistToTraj**
                          if(Position is right of trajectory?) then (Yes)
                            :1}
                            :Invert the Sign of the DistToTraj;
                          else (No)
                            :2}
                          endif
                          :Calculate the Distance On trajectory
                          (= X Distance covered by the trajectory until it reaches the RefPoint);
                          note left:>see **DistOnTraj**\nOnly an Approximation,\nno real Distance on Trajectory!
                        stop
                        @enduml
                        @image html EMP_DistOnToTraj.svg width=1400cm
                        Attention: Currently the DistOnTraj is not implemented as shown in the graphics.
                        To avoid an over complex calculation for this scenario, the DistOnTraj returns the \n
                        X-Distance to the position at which the minimum distance is reached.

  @return               void

  @param[in]            pPosition        :  Position to which the distance shall be calculated.
  @param[in]            pRefPoint        :  Reference Point of the position on the trajectory
  @param[out]           pfDistToTraj     :  Calculated distance to trajectory. 
                                            @phys_unit [m] @range ]- @ref ACDC_DIST_DEFAULT, + @ref ACDC_DIST_DEFAULT[
  @param[out]           pfDistOnTraj     :  Calculated distance on trajectory. 
                                            @phys_unit [m] @range ]- @ref ACDC_DIST_DEFAULT, + @ref ACDC_DIST_DEFAULT[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Ref point is calculated by the function @ref EMP_b_CalcTrajectoryRefPoint
  @post                 None

  @InOutCorrelation     
                        - **Formula DistToTraj:**\n
                          \f$Dist_{ToTraj} = \sqrt{(X_{Ref} - X)^2 + (Y_{Ref} - Y)^2}\f$
                        - **Formula DistOnTraj:**\n
                          \f$Dist_{OnTraj} = X_{Ref}\f$

  @testmethod           @ref TEST_EMP_V_CALCDISTTOREFPOINT_001\n
                        @ref TEST_EMP_V_CALCDISTTOREFPOINT_002

  @traceability         Design Decision

  @author               Andreas Danner | Andreas.Danner@continental-corporation.com | +49 (8382) 9699-4995
*************************************************************************************************************************/
void EMP_v_CalcDistToRefPoint(SFLVector2D_t const * const pPosition, 
                              SFLVector2D_t const * const pRefPoint,
                              float32             * const pfDistToTraj, 
                              float32             * const pfDistOnTraj)
{

  /* Calculate Distance to trajectory (= Distance between given position and the ref point on the trajectory)*/
  *pfDistToTraj = SQRT(SQR(pRefPoint->fX - pPosition->fX) + SQR(pRefPoint->fY - pPosition->fY));
  
  if (pRefPoint->fY > pPosition->fY)
  {
    *pfDistToTraj *= -1.f;
  }

  /* Calculate the Distance on trajectory (= X Distance between 0 and the given position and the ref point on the trajectory)
     => Approximation, no real Distance on Trajectory! (which would be the arc length) */
  *pfDistOnTraj = pRefPoint->fX;

}



/*************************************************************************************************************************
  Functionname:         EMP_v_CalcVelToRefPoint                                                                     */ /*!

  @brief                Calculates the velocity to trajectory and the velocity on trajectory for a given object.

  @description          The following velocities are calculated by this function:
                        - **VelToTraj** (=Velocity To Trajectory): \n
                        Describes the part of the objects velocity that points in a 90 degree angle towards the ego trajectory.
                        - **VelOnTraj** (=Velocity On Trajectory): \n
                        Describes the part of the objects velocity that points in the same direction as the ego trajectory.
                        The calculation follows the steps listed subsequently:
                        @startuml EMP_v_CalcVelToRefPoint_activity.png
                        start

                          #Orange:Calculate the orthogonal vector 
                          of the orientation at RefPoint:
                          <b>CML_f_TransformXPosition2D</b>
                          <b>CML_f_TransformYPosition2D</b> >
                          #Orange:Calculate the length of ego velocity vector:
                          <b>SFL_f_GetVector2Length</b> >
                          if(Velocity at the ref point is not 0?) then (Yes)
                            :1}
                            :Project the object velocity onto the orientation 
                            at RefPoint to get the VelToTraj and VelOnTraj;
                            note left:>see **Velocity Projection**
                          else (No)
                            :2}
                            :Set VelToTraj and VelOnTraj to 0;
                          endif
                          stop
                        @enduml
                        @image html EMP_VelOnToTraj.svg width=1400cm

  @return               void

  @param[in]            *pMovement     : Movement of the object.
  @param[in]            *pVelAtRefPoint: Velocity in X and Y at the RefPoint. (=> equals the orientation at RefPoint)
  @param[in,out]        *pfVelToTraj   : Calculated velocity to trajectory. @phys_unit [m/s] @range ]-...,+...[
  @param[in,out]        *pfVelOnTraj   : Calculated velocity on trajectory. @phys_unit [m/s] @range ]-...,+...[

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointers are valid
  @post                 None

  @InOutCorrelation     
                        - **Velocity Projection:** \n
                          \f$V_{ToTraj} = \frac{V_{Obj,X} \cdot V_{Orth,Ego,X,MinDist} + V_{Obj,Y} \cdot V_{Orth,Ego,Y,MinDist}}{V_{Orth,Ego,MinDist}}\f$ \n
                          \f$V_{OnTraj} = \frac{V_{Obj,X} \cdot V_{Ego,X,MinDist} + V_{Obj,Y} \cdot V_{Ego,Y,MinDist}}{V_{Ego,MinDist}}\f$

  @testmethod           @ref TEST_EMP_V_CALCVELTOREFPOINT_001 \n
                        @ref TEST_EMP_V_CALCVELTOREFPOINT_002

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
static void EMP_v_CalcVelToRefPoint(SFLMovement_t   const *const pMovement,
                                    SFLVector2D_t   const *const pVelAtRefPoint,
                                    float32               *const pfVelToTraj,
                                    float32               *const pfVelOnTraj)
{
  static const CML_t_TrafoMatrix2D ROTATION_MATRIX_ORTHOGONAL= 
  {
    ROTATION_,
    0.0f, /*cos(Pi/2)*/
    0.0f, /*Offset x*/
    1.0f, /*sin(Pi/2)*/
    0.0f /*Offset x*/
  };

  /* calculate orthogonal vector for orientation of ego coordinate y' axes at that time */
  float32 const fEgoVecOrthAtTime_x = CML_f_TransformXPosition2D(&ROTATION_MATRIX_ORTHOGONAL , pVelAtRefPoint->fX, pVelAtRefPoint->fY);
  float32 const fEgoVecOrthAtTime_y = CML_f_TransformYPosition2D(&ROTATION_MATRIX_ORTHOGONAL , pVelAtRefPoint->fX, pVelAtRefPoint->fY);

  /* length of velocity vector */
  float32 const fEgoVel = SFL_f_GetVector2Length(*pVelAtRefPoint);

  /* check division by zero */
  if ( fABS(fEgoVel) < C_F32_DELTA )
  {
    *pfVelToTraj = 0.f;
    *pfVelOnTraj = 0.f;
  }
  else
  {
    /* The vector length of the Ego velocity equals the vector length of the orthogonal ego velocity */
    float32 const fEgoVelOrth = fEgoVel;
    /* projection of object velocity on vector of ego coordinate y' axes or x axes */
    *pfVelToTraj = ((pMovement->Vel.fX * fEgoVecOrthAtTime_x) + (pMovement->Vel.fY * fEgoVecOrthAtTime_y)) / fEgoVelOrth;
    *pfVelOnTraj = ((pMovement->Vel.fX * pVelAtRefPoint->fX ) + (pMovement->Vel.fY * pVelAtRefPoint->fY )) / fEgoVel;
  }
}



/*************************************************************************************************************************
  Functionname:         EMPResetTrajPred                                                                             */ /*!

  @brief                Resets all values of a given Trajectory Prediction

  @description          Resets all values of a given Trajectory Prediction (@ref ACDCTrajPred_t).

  @return               void

  @param[in,out]        pIn_TrajPred : Trajectory prediction that shall be reset.

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref ACDC_CFG_EMP

  @pre                  Assure that pointer is valid
  @post                 None

  @InOutCorrelation     see description

  @testmethod           @ref TEST_EMPRESETTRAJPRED_001\n

  @traceability         Design Decision

  @author               Matthias Thomi | matthias.thomi@continental-corporation.com
*************************************************************************************************************************/
void EMPResetTrajPred( ACDCTrajPred_t *const pIn_TrajPred )
{
  pIn_TrajPred->XofT.fC0 = 0.0f;
  pIn_TrajPred->XofT.fC1 = 0.0f;
  pIn_TrajPred->XofT.fC2 = 0.0f;

  pIn_TrajPred->YofT.fC0 = 0.0f;
  pIn_TrajPred->YofT.fC1 = 0.0f;
  pIn_TrajPred->YofT.fC2 = 0.0f;

  pIn_TrajPred->VarXofT.fC0 = 0.0f;
  pIn_TrajPred->VarXofT.fC1 = 0.0f;
  pIn_TrajPred->VarXofT.fC2 = 0.0f;

  pIn_TrajPred->VarYofT.fC0 = 0.0f;
  pIn_TrajPred->VarYofT.fC1 = 0.0f;
  pIn_TrajPred->VarYofT.fC2 = 0.0f;
}


//! @}
#endif /* ACDC_CFG_EMP */



