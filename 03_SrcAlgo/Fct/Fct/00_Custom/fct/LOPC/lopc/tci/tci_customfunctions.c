/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 LOPC_TCI (Traffic Continuation Indication)

PACKAGENAME:               tci_customfunctions.c

DESCRIPTION:               Custom Functions for Traffic Continuation Indication (TCI) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             12.02.2018

VERSION:                   $Revision: 1.14 $

LEGACY VERSION:            Revision: 1.0

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup   tci_customfunction_h Tci_Customfunctions
@ingroup    tci_custom
@brief      TCI customfunctions file
@description
This module contains customer specific adaption for the TCI function
@{ */ 

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "tci.h"

#if (FCT_CFG_TCI)

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/

#if (TCI_CFG_AUTOCODE)
/* Inputs to TCI from ACT component */
typedef struct {
  MotState_t VehMotionState;       /*! State of motion of ego vehicle */
  obj_status_t ObjStatus;          /*! Moving status of 00I-0 */
  boolean DriveOffPossible;        /*! Drive off possible flag from ACC */
  float32 DistLeadVeh;             /*! Distance to OOI-0 */
  boolean AccAct;                  /*! ACC On flag */
  boolean ObjDetected;             /*! Flag for object detected */
  INHIBITION_REASON_t SensInhibit; /*! Sensor inhibition */
  float32 f_VabsXOOI0;             /* Lead Vehicle Velocity */
} TCI_ActInputRaw_t;
#endif

/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/

#if (TCI_CFG_AUTOCODE)
SET_MEMSEC_VAR(TCI_rtDWork)
static tci_D_Work TCI_rtDWork;    /*PRQA S 3218  */
/* date: 2019-05-03, reviewer: Rasish Verma(uib25204), reason: kept here for better maintainability*/

              /* Model data */

SET_MEMSEC_VAR(TCI_b_NotFirstCall)
static boolean TCI_b_NotFirstCall = 0;/*PRQA S 3218  */
/* date: 2019-05-03, reviewer: Rasish Verma(uib25204), reason: kept here for better maintainability*/


#endif

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

#if (TCI_CFG_AUTOCODE)
static void TCI_v_CallModel(const TCIInput_t * TCIInput, const TCI_ActInputRaw_t * TCI_ActInputRaw, TCIOutput_t * TCIOutput);
#endif



/*************************************************************************************************************************
  Functionname:    TCI_v_InputWrapper                                                                                 */ /*!

  @brief           Input wrapper for TCI and calling of TCI_v_CallModel()

  @description     Input wrapper for TCI and calling of TCI_v_CallModel()

@startuml
Start
Partition TCI_v_InputWrapper(){
: Input wrapper for TCI and calling of TCI_v_CalModel;
: Parameter to be used for ACC_Output, Headway planner, ACCOOI0 conditions, LongCTRLCommands,TCI Input and output commands;
}
End
@enduml


  @return          -

  @param[in]       pLongCtrlResp : Long control input as defined in RTE of type LongCtrlInput_t
  @param[in]       pVehDyn : Ego vehicle dynamic as defined in RTE of type VehDyn_t
  @param[in]       pAccOutput : ACC output data as port between SEN and VEH defined in RTE of type acc_output_data_t
  @param[in]       pFCTAccOOIData : ACC port between SEN and VEH defined in RTE of type FCTSenAccOOI_t
  @param[in]       pAccDisplayObj : ACC object data define in RTE of type acc_object_t
  @param[in]       pLongCtrlCmd : Long control output defined in RTE of type LongCtrlOutput_t
  @param[in]       pTCIInput : TCI inputs detined in RTE of type TCIInput_t
  @param[in,out]   TCIOutput : TCI outputs defined in RTE of type TCIOutput_t

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_TCI : FCT support for TCI module
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         13.07.2017
  @changed         13.07.2017
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-163-0008a220
  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
void TCI_v_InputWrapper(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
                             const acc_output_data_t* acc_output,
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
                             const FCTSenAccOOI_t* pFCTAccOOIData,
#endif
                             const acc_object_t * pAccDisplayObj,
#endif
                             const LongCtrlOutput_t * pLongCtrlCmd,
                             const TCIInput_t* pTCIInput,
                             TCIOutput_t* pTCIOutput)
{
#if (TCI_CFG_AUTOCODE)
  /* Preparation of input from ACC to TCI module */
  TCI_ActInputRaw_t t_TCIActInputRaw;

  t_TCIActInputRaw.AccAct           = pLongCtrlResp->Custom.EngineEcuInput.XACCACT;
  t_TCIActInputRaw.DistLeadVeh      = pFCTAccOOIData->AccOOINextLong.Kinematic.fDistX;
  t_TCIActInputRaw.DriveOffPossible = pLongCtrlCmd->DriverData.drive_off_possible; 
  t_TCIActInputRaw.ObjDetected      = pLongCtrlCmd->KinFctInfo.object_detected;
  t_TCIActInputRaw.ObjStatus        = pAccDisplayObj->AUTOSAR.OBJECT_STATUS;
  t_TCIActInputRaw.VehMotionState   = pVehDyn->MotionState.MotState;
  t_TCIActInputRaw.SensInhibit      = acc_output->ACC_OUTPUT_STATUS.INHIBITION_REASON;
  t_TCIActInputRaw.f_VabsXOOI0      = pFCTAccOOIData->AccOOINextLong.Kinematic.fVabsX;
  /* Calling TCI process function from tci_main.c */
  TCI_v_CallModel(pTCIInput, &t_TCIActInputRaw, pTCIOutput);
#else
  _PARAM_UNUSED(pLongCtrlResp);
  _PARAM_UNUSED(pVehDyn);
#if (FCT_CFG_ACC_HEADWAY_PLANNER)
   _PARAM_UNUSED(acc_output);
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
  _PARAM_UNUSED(pFCTAccOOIData);
#endif
  _PARAM_UNUSED(pAccDisplayObj);
#endif
  _PARAM_UNUSED(pLongCtrlCmd);
  _PARAM_UNUSED(pTCIInput);
  _PARAM_UNUSED(pTCIOutput);
#endif
}



#if (TCI_CFG_AUTOCODE)
/*************************************************************************************************************************
  Functionname:    TCI_v_CallModel                                                                                 */ /*!

  @brief           Model to determine the TCI output/reaction is called

  @description     First the inputs for the model are set, then the model is called to determine the TCI output

  @return          -

  @param[in]       TCIInput : TCI inputs defined in RTE
  @param[in]       TCI_ActInputRaw : TCI common inputs, defined in tci_ext.h
  @param[in,out]   TCIOutput : TCI outputs defined in RTE

  @glob_in         TCI_b_NotFirstCall : Boolean if function is not called yet [true, false]
  @glob_in         TCI_rtDWork : Model data
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_TCI : FCT support for TCI module
  @c_switch_full   TCI_CFG_AUTOCODE : Configuration switch to Enable/Disable TCI Autocode

  @pre             -
  @post            -

  @created         13.07.2017
  @changed         13.07.2017

  @author          Niraj Mistry | niraj.mistry@continental-corporation.com | +49 (8382) 9699-5631
*************************************************************************************************************************/
static void TCI_v_CallModel(const TCIInput_t * TCIInput, const TCI_ActInputRaw_t * TCI_ActInputRaw, TCIOutput_t * TCIOutput)
{
  
  tci_RT_MODEL tmp_TCI_rtM; /* Real-time model */
  TCIInput_t  tmp_TCIInput;
  TCI_ActInput_t  tmp_TCI_ActInput;

  /* Pack model data into Real-time model */
  tmp_TCI_rtM.ModelData.dwork = &TCI_rtDWork;

  if (TCI_b_NotFirstCall)
  {
    /* Prepares TCIInput */
    tmp_TCIInput.TCI_b_On = TCIInput->TCI_b_On;
    tmp_TCIInput.TCI_b_NoticeInh = TCIInput->TCI_b_NoticeInh;
    tmp_TCIInput.TCI_NoticeMode = TCIInput->TCI_NoticeMode;
    tmp_TCIInput.TCI_b_Malf = TCIInput->TCI_b_Malf;
    tmp_TCIInput.b_ObjBlockEgoLane = TCIInput->b_ObjBlockEgoLane;
    tmp_TCIInput.TCI_b_IGPOff = TCIInput->TCI_b_IGPOff;

    /* Prepares TCI_ActInput */
    tmp_TCI_ActInput.b_EgoVehStop   = (TCI_ActInputRaw->VehMotionState == VDY_LONG_MOT_STATE_STDST);
    tmp_TCI_ActInput.b_LeadVehStop  = ((TCI_ActInputRaw->ObjStatus.STANDING) || (TCI_ActInputRaw->ObjStatus.STOPPED));
    tmp_TCI_ActInput.b_DriveOffAcc  = TCI_ActInputRaw->DriveOffPossible;
    tmp_TCI_ActInput.f_DistLeadVeh  = TCI_ActInputRaw->DistLeadVeh;
    tmp_TCI_ActInput.b_ChgLeadVeh   = TCI_ActInputRaw->ObjStatus.NEW;
    tmp_TCI_ActInput.b_AccAct       = TCI_ActInputRaw->AccAct;
    tmp_TCI_ActInput.b_LostLeadVeh  = (!TCI_ActInputRaw->ObjDetected);
    tmp_TCI_ActInput.f_VabsXOOI0    = TCI_ActInputRaw->f_VabsXOOI0;
    if (TCI_ActInputRaw->SensInhibit & Acc_inhibition_blockage)
    {
      tmp_TCI_ActInput.b_SensSelfTest = TRUE;
    }
    else
    {
      tmp_TCI_ActInput.b_SensSelfTest = FALSE;
    }
    tci_step(&tmp_TCI_rtM, &tmp_TCIInput, &tmp_TCI_ActInput, TCIOutput); /* Execute TCI function */
   
  }
  else
  {
    TCI_b_NotFirstCall = 1;
    
    tci_initialize(&tmp_TCI_rtM); /* Initialize TCI function */
  }

}
#endif  /* TCI_CFG_AUTOCODE */

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

void TCI_b_TCISetInputInhibit(const LongCtrlInput_t * pLongCtrlResp,
                             const VehDyn_t * pVehDyn,
                             const LongCtrlOutput_t * pLongCtrlCmd,
                             TCIInputInhibit_t * pt_TCIInputInhibit)
{
  pt_TCIInputInhibit->b_Airbag= pLongCtrlResp->KinCtrlDynInput.b_airbag_deploy;


  pt_TCIInputInhibit->e_Gear=DYN_GEAR_FIRST_GEAR; // @TODO: pt_TCIInputInhibit->e_Gear to be used

  pt_TCIInputInhibit->e_DoorState=pLongCtrlResp->KinCtrlDynInput.door_state;

  pt_TCIInputInhibit->e_SeatBeltState=pLongCtrlResp->KinCtrlDynInput.seatbelt_state;

  pt_TCIInputInhibit->b_DriverBraking=pLongCtrlResp->KinCtrlDynInput.driver_braking;

  if(DAS_STATUS_ACTIVE == pLongCtrlCmd->KinOutput.DAS_status )
  {
    pt_TCIInputInhibit->b_AccEnable = TRUE;
  }
  else
  {
    pt_TCIInputInhibit->b_AccEnable = FALSE;
  }

  pt_TCIInputInhibit->f_EgoCurve=pVehDyn->Lateral.Curve.Curve;
}
#endif

#if (TCI_CFG_AUTOCODE == SWITCH_OFF) 

boolean TCI_b_TCICheckInhibitStatus(const TCIInputInhibit_t * pTCIInputInhibit)
{
  boolean b_TCIInhibit =FALSE;

  if( (TRUE == pTCIInputInhibit->b_Airbag)
      || ( (DYN_GEAR_PARK_GEAR == pTCIInputInhibit->e_Gear) || (DYN_GEAR_REVERSE_GEAR == pTCIInputInhibit->e_Gear) ) 
      || (SEATBELT_DRIVER_CLOSED != pTCIInputInhibit->e_SeatBeltState) 
      || ( (pTCIInputInhibit->e_DoorState != TCI_ALLDOORSCLOSED ) )
      || ( (FALSE == pTCIInputInhibit->b_DriverBraking) && (FALSE == pTCIInputInhibit->b_AccEnable) ) // Dependency on ACC
      || (fABS(pTCIInputInhibit->f_EgoCurve) > TCI_EGOCURVE)
     )
  {
    b_TCIInhibit=TRUE;
  }
  else
  {
    b_TCIInhibit=FALSE;
  }

  return b_TCIInhibit;
}
#endif


#endif /*!< FCT_CFG_TCI */

/** @} end defgroup*/
