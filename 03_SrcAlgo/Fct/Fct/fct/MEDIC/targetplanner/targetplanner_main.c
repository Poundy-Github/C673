/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 TP (Target Planner)

PACKAGENAME:               targetplanner_main.c

DESCRIPTION:               External Header of the HEAD component

AUTHOR:                    $Author: Sekar, Balaji02 (uids6618) $

CREATION DATE:             $Date: 2020/11/04 14:49:20CET $

VERSION:                   $Revision: 1.31 $

LEGACY VERSION:            
 
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if (MEDIC_CFG_TARGET_PLANNER)
#include "targetplanner/targetplanner_main.h"

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
/*************************************************************************************************************************
  Functionname:         TPRun                                                                          */ /*!

  @brief                Target Planner Run process

  @description          Target Planner sets the vehicle control signals 
                        @startuml
                         start
                          if(HEADBrakeIntf->bPreBrakeDecelEnabled) then (TRUE)
                            :Get the current Breakmodule state and output Parametrs and 
                             calculate the Max and Min Decelaration request for the Target planner;  
                            :Set the calculated TargetReq Signals; 
                          Else(FALSE) 
                            :Set the Default TargetReq Signals; 
                          Endif
                         stop
                        @enduml

  @return               eGDBError_t

  @param[in]            void


  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_TARGET_PLANNER

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability         
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-0000000000000000-O-1160-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-0000000000000000-O-1161-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-0000000000000000-O-1165-0007e0f8}
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&view=00000009&urn=urn:telelogic::1-0000000000000000-O-1167-0007e0f8}

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
eGDBError_t TPRun(void)
{
  const ACDC2_BrakeTargets* const brakeTargetIntf          = MEDIC_p_GetInput()->ReqPorts.brakeTargets;
  MEDIC_TargetRequest_t* const TargetReq                   = MEDIC_p_GetOutput()->ProPorts.trajPlanerCtrlLimits;
  MEDIC_t_PreBrake const * const HEADBrakeIntf             = MEDIC_p_GetOutput()->ProPorts.preBrake;
  float32 fLongVelocity = 0.0f;                              /* actual longitudinal velocity */
  uint8 activeHypIndex  = HEADBrakeIntf->HypInfo.uActiveHyp; /* Active Hypothesis            */
  float32 fAccelLimMin  = 0.0f;                              /* Maximum allowed deceleration */
  float32 fAccelLimMax  = 0.0f;                              /* Minimum required deceleration*/
  if (HEADBrakeIntf->bPreBrakeDecelEnabled == b_TRUE)
  {
    HEADModule_t const*    pBreakModule          = HEADGetModule(MEDIC_p_GetHEADInputData()->pModuleList,(uint32)HEAD_MOD_Brake);
    const HEADModuleState_t * const pState = HEADGetModuleState(pBreakModule, (HEADSMState_t)((HEADSMState_t)pBreakModule->eDGSMState - (HEADSMState_t)pBreakModule->eNumModuleStateMin));
    const HEADStateOutBrakeFunctionPar_t *pActivePreBrakeFunctionPar = (const HEADStateOutBrakeFunctionPar_t *)pState->pOutputParams;
    const struct HEADInputData_t *pInputData                         = MEDIC_p_GetHEADInputData();
    (void)HEADGetInputValue_float32(pInputData->pInputValueList->LongVelocity, HEAD_DEFAULT_LongVelocity, &fLongVelocity);
    fAccelLimMin = HEADCalculatePolygonValuef32(pActivePreBrakeFunctionPar->AutoBrkParTabCommonDecel_Rows, &pActivePreBrakeFunctionPar->AutoBrkParTabCommonDecel[0], fLongVelocity);
    fAccelLimMax = HEADCalculatePolygonValuef32(pActivePreBrakeFunctionPar->AutoBrkParTabMaxDecel_Rows, &pActivePreBrakeFunctionPar->AutoBrkParTabMaxDecel[0], fLongVelocity);
    TargetReq->b_activateCtrl           = b_TRUE;
    TargetReq->b_aebActivated           = b_TRUE;
    // TargetReq->f_LongJerkLowerBound  = 0.0f;
    // TargetReq->f_LongAccelLowerBound = -10.0f;

    if (activeHypIndex < HEAD_MAX_NUMBER_OF_CD_HYPS)
    {
      // Use brake target to fill the brake requests
      const ACDC2_longTargets  ActiveTarget = brakeTargetIntf->longTargets[activeHypIndex];
      const ACDC2_Hypothesis* const pActHyp = MEDIC_p_GetHypothesis(activeHypIndex);
      TPBreakTargetRequest(pActivePreBrakeFunctionPar->Veh_BrkLevelNr, fAccelLimMin, fAccelLimMax, &ActiveTarget, pActHyp);
      TargetReq->a_tarVeh[0].s_objId           = (sint8)pActHyp->CriticalItem.i_itemID;
      TargetReq->a_tarVeh[0].f_longAccelAbs    = ActiveTarget.f_accelAbsOnTraj; 
      TargetReq->a_tarVeh[0].f_longVeloAbs     = ActiveTarget.f_velAbsOnTraj; 
      TargetReq->a_tarVeh[0].f_longDistRel     = ActiveTarget.f_distOnTraj; 
      TargetReq->a_tarVeh[0].f_objValidTimeMax = ActiveTarget.f_maxTimeTargetValid;
      TargetReq->a_tarVeh[0].f_objValidTimeMin = ActiveTarget.f_minTimeTargetValid;

      TargetReq->a_tarPref[0].f_headway        = 0.0f;
      TargetReq->a_tarPref[0].f_longDistMin    = TPLongDistMinCalc(ActiveTarget.f_angleToTraj);
      TargetReq->a_tarPref[0].f_longIntruAlert = 100.0f;
      TargetReq->a_tarPref[0].f_longIntruMax   = 0.167f;
      TargetReq->a_tarPref[0].f_longIntruMin   = -0.667f;
      TargetReq->a_tarPref[0].e_dynMode        = lopln_DYNMODE_HIGH;
    }
    else
    {
      // #TO-DO: This case may never happen, reaction TBD
      TPBreakTargetRequest(pActivePreBrakeFunctionPar->Veh_BrkLevelNr, fAccelLimMin, fAccelLimMax, NULL, NULL);
      TargetReq->a_tarVeh[0].f_longAccelAbs    = 999.0f; 
      TargetReq->a_tarVeh[0].f_longVeloAbs     = 999.0f;
      TargetReq->a_tarVeh[0].f_longDistRel     = 999.0f;
      TargetReq->a_tarVeh[0].f_objValidTimeMax = 999.0f;
      TargetReq->a_tarVeh[0].f_objValidTimeMin = 0.0f;

      TargetReq->a_tarPref[0].f_headway        = 0.0f;
      TargetReq->a_tarPref[0].f_longDistMin    = 0.0f;
      TargetReq->a_tarPref[0].f_longIntruAlert = 0.0f;
      TargetReq->a_tarPref[0].f_longIntruMax   = 0.0f;
      TargetReq->a_tarPref[0].f_longIntruMin   = 0.0f;
      TargetReq->a_tarPref[0].e_dynMode        = lopln_DYNMODE_LOW;
    }

    /* Setting default values for 1,2 targets as EBA act on only one object */
    TargetReq->a_tarLims[1].longAccelMax     = 0.0f;
    TargetReq->a_tarLims[1].longAccelMin     = 0.0f;
    TargetReq->a_tarLims[1].longJerkMax      = 0.0f;
    TargetReq->a_tarLims[1].longJerkMin      = 0.0f;
    TargetReq->a_tarLims[2].longAccelMax     = 0.0f;
    TargetReq->a_tarLims[2].longAccelMin     = 0.0f;
    TargetReq->a_tarLims[2].longJerkMax      = 0.0f;
    TargetReq->a_tarLims[2].longJerkMin      = 0.0f;
    TargetReq->a_tarPref[1].f_headway        = 0.0f;
    TargetReq->a_tarPref[1].f_longDistMin    = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruAlert = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruMax   = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruMin   = 0.0f;
    TargetReq->a_tarPref[1].e_dynMode        = lopln_DYNMODE_LOW;
    TargetReq->a_tarPref[2].f_headway        = 0.0f;
    TargetReq->a_tarPref[2].f_longDistMin    = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruAlert = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruMax   = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruMin   = 0.0f;
    TargetReq->a_tarPref[2].e_dynMode        = lopln_DYNMODE_LOW;
    TargetReq->a_tarVeh[1].f_longAccelAbs    = 0.0f; 
    TargetReq->a_tarVeh[1].f_longVeloAbs     = 0.0f;
    TargetReq->a_tarVeh[1].f_longDistRel     = 0.0f;
    TargetReq->a_tarVeh[1].s_objId           = -1;
    TargetReq->a_tarVeh[1].f_objValidTimeMax = 0.0f;
    TargetReq->a_tarVeh[1].f_objValidTimeMin = 0.0f;
    TargetReq->a_tarVeh[2].f_longAccelAbs    = 0.0f; 
    TargetReq->a_tarVeh[2].f_longVeloAbs     = 0.0f;
    TargetReq->a_tarVeh[2].f_longDistRel     = 0.0f;
    TargetReq->a_tarVeh[2].s_objId           = -1;
    TargetReq->a_tarVeh[2].f_objValidTimeMax = 0.0f;
    TargetReq->a_tarVeh[2].f_objValidTimeMin = 0.0f;
  }
  else
  {
    TargetReq->b_activateCtrl                 = b_FALSE;
    TargetReq->b_aebActivated                 = b_FALSE;
    //TargetReq->f_LongJerkLowerBound               = 0.0f;
    //TargetReq->f_LongAccelLowerBound              = 0.0f;
    TargetReq->a_tarLims[0].longAccelMax     = 0.0f;
    TargetReq->a_tarLims[0].longAccelMin     = 0.0f;
    TargetReq->a_tarLims[0].longJerkMax      = 0.0f;
    TargetReq->a_tarLims[0].longJerkMin      = 0.0f;
    TargetReq->a_tarLims[1].longAccelMax     = 0.0f;
    TargetReq->a_tarLims[1].longAccelMin     = 0.0f;
    TargetReq->a_tarLims[1].longJerkMax      = 0.0f;
    TargetReq->a_tarLims[1].longJerkMin      = 0.0f;
    TargetReq->a_tarLims[2].longAccelMax     = 0.0f;
    TargetReq->a_tarLims[2].longAccelMin     = 0.0f;
    TargetReq->a_tarLims[2].longJerkMax      = 0.0f;
    TargetReq->a_tarLims[2].longJerkMin      = 0.0f;
    TargetReq->a_tarPref[0].f_headway        = 0.0f;
    TargetReq->a_tarPref[0].f_longDistMin    = 0.0f;
    TargetReq->a_tarPref[0].f_longIntruAlert = 0.0f;
    TargetReq->a_tarPref[0].f_longIntruMax   = 0.0f;
    TargetReq->a_tarPref[0].f_longIntruMin   = 0.0f;
    TargetReq->a_tarPref[0].e_dynMode        = lopln_DYNMODE_LOW;
    TargetReq->a_tarPref[1].f_headway        = 0.0f;
    TargetReq->a_tarPref[1].f_longDistMin    = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruAlert = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruMax   = 0.0f;
    TargetReq->a_tarPref[1].f_longIntruMin   = 0.0f;
    TargetReq->a_tarPref[1].e_dynMode        = lopln_DYNMODE_LOW;
    TargetReq->a_tarPref[2].f_headway        = 0.0f;
    TargetReq->a_tarPref[2].f_longDistMin    = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruAlert = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruMax   = 0.0f;
    TargetReq->a_tarPref[2].f_longIntruMin   = 0.0f;
    TargetReq->a_tarPref[2].e_dynMode        = lopln_DYNMODE_LOW;
    TargetReq->a_tarVeh[0].f_longAccelAbs    = 0.0f; 
    TargetReq->a_tarVeh[0].f_longVeloAbs     = 0.0f;
    TargetReq->a_tarVeh[0].f_longDistRel     = 0.0f;
    TargetReq->a_tarVeh[0].s_objId           = -1;
    TargetReq->a_tarVeh[1].f_longAccelAbs    = 0.0f; 
    TargetReq->a_tarVeh[1].f_longVeloAbs     = 0.0f;
    TargetReq->a_tarVeh[1].f_longDistRel     = 0.0f;
    TargetReq->a_tarVeh[1].s_objId           = -1;
    TargetReq->a_tarVeh[2].f_longAccelAbs    = 0.0f; 
    TargetReq->a_tarVeh[2].f_longVeloAbs     = 0.0f;
    TargetReq->a_tarVeh[2].f_longDistRel     = 0.0f;
    TargetReq->a_tarVeh[2].s_objId           = -1;
  }
  return GDB_ERROR_NONE;
}


/*************************************************************************************************************************
  Functionname:         TPLongDistMinCalc                                                                           */ /*!

  @brief                Target Planner Desired Stopping Dist calculation based on Angle to Trajectory 

  @description          Target Planner Desired Stopping Dist calculation based on Angle to Trajectory 
                        @startuml
                        start
                        :Target Planner Desired Stopping Dist calculation
                         based on Angle to Trajectory;
                        stop
                        @enduml

  @return               float32 : Returns Minimum Long Distance Required based on Angle to Trajectory

  @param[in]            angleToTraj : Angle between object and ego corridor

  @glob_in              None
  @glob_out             None

  @c_switch_part        None
  @c_switch_full        @ref MEDIC_CFG_TARGET_PLANNER

  @pre                  None
  @post                 None

  @InOutCorrelation     See description

  @testmethod           Test of output data (dynamic module test)

  @traceability
                        @satisfy{doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1163-0007e0f8}

  @author               Balaji Sekar | balaji.2.sekar@continental-corporation.com
*************************************************************************************************************************/
float32 TPLongDistMinCalc(float32 angleToTraj)
{
    float32 ObjEgoCorrAngle = CML_f_Half_Pi;
    float32 LongDistMin = DEFAULT_STOP_DISTANCE;
    float32 CosVal = 0.0f;

    if (angleToTraj > CML_f_Half_Pi)
    {
        ObjEgoCorrAngle = angleToTraj - CML_f_Half_Pi;
        CosVal = COS_(ObjEgoCorrAngle);
    }
    else if (angleToTraj < CML_f_Half_Pi)
    {
        ObjEgoCorrAngle = CML_f_Half_Pi - angleToTraj;
        CosVal = COS_(ObjEgoCorrAngle);
    }
    else
    {
       /* Do nothing*/
    }
    
    if (CosVal > 0.0f)
    {
        LongDistMin = (DEFAULT_STOP_DISTANCE / CosVal);
    }
    return LongDistMin;
}
#endif // MEDIC_CFG_TARGET_PLANNER

