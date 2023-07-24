/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi_customfunctions.c

DESCRIPTION:               Custom Functions for ISC Module

AUTHOR:                    Wolfgang Borgs (uidj5069)

CREATION DATE:             31.08.2017

VERSION:                   $Revision: 1.8 $

LEGACY VERSION:            Revision: 1.1

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "hmi.h"

#if (FCT_CFG_ISC_COMPONENT)

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


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

void HMI_v_Custom_Process(void)
{
  /* Output CC Command for State Machine - always CC Function */
  t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Function = ISC_SM_CC_FUN_CC;

  /* Select SM System State */
  switch (t_HMI_IN_SMSP.pt_SMS->t_SYSS.t_STATE)
  {
  case ISC_SM_STATE_OFF:
    /* Output System State depending on SM State */
    t_HMI_OUT_HMSP.pt_HMS->t_STATE = ACT_ISC_STATE_OFF;

    /* Switch ON Command is set TRUE if rising edge of (ON/OFF) button is detected */
//    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_On = (t_HMI_IN_HMCP.pt_HMC->b_OnOff && !t_HMI_LOC_ISCC.b_OnOff);  /* VW native HMI logic */

    /* Switch ON Command is set TRUE if (MainMode) signal is on */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_On = t_HMI_IN_HMCP.pt_HMC->b_Main;  /* Gateway logic of Demo-Passat */

    /* Switch OFF Command is set FALSE since system is already OFF */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off = FALSE;

    /* Activation Command is set FALSE since system is OFF */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Activate = FALSE;

    /* Deactivation Command is set FALSE since system is OFF */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate = FALSE;

    /* CC Operation is NOP since system is OFF */
    t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;

    /* Set Headway Setting Stage to Init Value */
    u_HMI_LOC_Headway_Stage = HMI_ACC_HEADWAY_STAGE_INIT;

    break;

  case ISC_SM_STATE_READY:
    /* Output System State depending on SM State */
    t_HMI_OUT_HMSP.pt_HMS->t_STATE = ACT_ISC_STATE_READY;

    /* Switch ON Command is set FALSE since system is already ON */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_On = FALSE;

    /* Switch OFF Command is set TRUE if rising edge of (ON/OFF) button is detected */
//    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off = (t_HMI_IN_HMCP.pt_HMC->b_OnOff && !t_HMI_LOC_ISCC.b_OnOff);  /* VW native HMI logic */

    /* Switch OFF Command is set TRUE if (Main) signal is off */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off = (t_HMI_IN_HMCP.pt_HMC->b_Main == FALSE);  /* Gateway logic of Demo-Passat */

    /* Activation Command is set TRUE if one ( SET | RESUME | + | - ) button is detected */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Activate =  (t_HMI_IN_HMCP.pt_HMC->b_Set || t_HMI_IN_HMCP.pt_HMC->b_Resume ||
                                                 t_HMI_IN_HMCP.pt_HMC->b_SpeedInc || t_HMI_IN_HMCP.pt_HMC->b_SpeedDec)
                                             &&(!t_HMI_IN_HMIP.pt_HMI->b_BrakePedal || t_HMI_IN_SMSP.pt_SMS->t_SYSS.b_StandStill)
                                             && !t_HMI_IN_HMIP.pt_HMI->b_ParkBrake
                                             && (t_HMI_IN_HMIP.pt_HMI->t_DrivePos == ACT_ISC_DRIVE_POS_FORWARD);

    /* Deactivation Command is set FALSE since system is INACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate = FALSE;

    /* If Switch OFF Command is set TRUE */
    if (t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off == TRUE)
    {
        /* Clear Set Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_CLEAR;
    }
    /* If Activation Command is set TRUE */
    else if (t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Activate == TRUE)
    {
      /* If SET button is pressed or no SetSpeed is stored */
      if ((t_HMI_IN_HMCP.pt_HMC->b_Set && !t_HMI_LOC_ISCC.b_Set) || !t_HMI_IN_SMSP.pt_SMS->t_CCS.b_SpeedStored)
      {
        /* Set actual Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_SET;
      }
      else
      {
        /* Do not change Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
      }
    }
    else
    {
      /* Do not change Speed */
      t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
    }

    /* Headway Stage is incremented if rising edge of (HEADWAY INC) button is detected */
    if (t_HMI_IN_HMCP.pt_HMC->b_HeadwayInc && !t_HMI_LOC_ISCC.b_HeadwayInc)
    {
      if (u_HMI_LOC_Headway_Stage == HMI_ACC_HEADWAY_STAGE_MAX)
      {
        u_HMI_LOC_Headway_Stage = 0u;
      }
      else
      {
        u_HMI_LOC_Headway_Stage++;
      }
    }

    break;

  case ISC_SM_STATE_ACTIVE:
    /* Output System State depending on SM State */
    t_HMI_OUT_HMSP.pt_HMS->t_STATE = ACT_ISC_STATE_ACTIVE;

    /* Switch ON Command is set FALSE since system is ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_On = FALSE;

    /* Switch OFF Command is set FALSE since system is ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off = FALSE;

    /* Activation Command is set FALSE since system is already ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Activate = FALSE;

    /* Deactivation Command is set TRUE if rising edge of (ON/OFF) button is detected or (Parking-)Brake is engaged or [P|R|N] (VW native HMI logic) */
/*    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate = (t_HMI_IN_HMCP.pt_HMC->b_OnOff && !t_HMI_LOC_ISCC.b_OnOff)
                                               ||(t_HMI_IN_HMIP.pt_HMI->b_BrakePedal && !t_HMI_IN_SMSP.pt_SMS->t_SYSS.b_StandStill)
                                               || t_HMI_IN_HMIP.pt_HMI->b_ParkBrake
                                               ||(t_HMI_IN_HMIP.pt_HMI->t_DrivePos != ACT_ISC_DRIVE_POS_FORWARD); */

    /* Deactivation Command is set TRUE if (CANCEL) button is detected or (Parking-)Brake is engaged or [P|R|N] (Gateway logic of Demo-Passat) */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate =  t_HMI_IN_HMCP.pt_HMC->b_Cancel || t_HMI_IN_HMIP.pt_HMI->b_ParkBrake
                                               ||(t_HMI_IN_HMIP.pt_HMI->b_BrakePedal && !t_HMI_IN_SMSP.pt_SMS->t_SYSS.b_StandStill)
                                               ||(t_HMI_IN_HMIP.pt_HMI->t_DrivePos != ACT_ISC_DRIVE_POS_FORWARD);

    /* If Deactivation Command is set FALSE */
    if (t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate == FALSE)
    {
      /* Start Confirmation by Driver through RESUME Button or Accelerator Pedal */
      t_HMI_OUT_LVCP.pt_LVC->b_StartConfirmation = t_HMI_IN_HMCP.pt_HMC->b_Resume || t_HMI_IN_HMIP.pt_HMI->b_AccelPedal;

      /* If (-) button is pressed */
      if (t_HMI_IN_HMCP.pt_HMC->b_SpeedDec && !t_HMI_LOC_ISCC.b_SpeedDec)
      {
        /* Decrement Actual Speed by 10 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_DEC_2;
      }
      /* If (+) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_SpeedInc && !t_HMI_LOC_ISCC.b_SpeedInc)
      {
        /* Increment Actual Speed by 10 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_INC_2;
      }
      /* If (SET-) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_Set && !t_HMI_LOC_ISCC.b_Set)
      {
        /* If Speedometer Speed is greater then Set Speed */
        if (t_HMI_IN_HMIP.pt_HMI->u_SpeedDisplay > t_HMI_IN_SMSP.pt_SMS->t_CCS.u_SetSpeed)
        {
          /* Set new Speedometer Speed */
          t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_SET;
        }
        else
        {
          /* Decrement Actual Speed by 1 kmh */
          t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_DEC_1;
        }
      }
      /* If (RESUME+) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_Resume && !t_HMI_LOC_ISCC.b_Resume)
      {
        /* Increment Actual Speed by 1 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_INC_1;
      }
      /* If no button is pressed */
      else
      {
        /* Do not change Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
      }
    }
    else
    {
      /* No Start Confirmation by Driver */
      t_HMI_OUT_LVCP.pt_LVC->b_StartConfirmation = FALSE;

      /* Do not change Speed */
      t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
    }

    /* Headway Stage is incremented if rising edge of (HEADWAY INC) button is detected */
    if (t_HMI_IN_HMCP.pt_HMC->b_HeadwayInc && !t_HMI_LOC_ISCC.b_HeadwayInc)
    {
      if (u_HMI_LOC_Headway_Stage == HMI_ACC_HEADWAY_STAGE_MAX)
      {
        u_HMI_LOC_Headway_Stage = 0u;
      }
      else
      {
        u_HMI_LOC_Headway_Stage++;
      }
    }

    break;

  case ISC_SM_STATE_OVERRIDE:
    /* Output System State depending on SM State */
    t_HMI_OUT_HMSP.pt_HMS->t_STATE = ACT_ISC_STATE_OVERRIDE;

    /* Switch ON Command is set FALSE since system is ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_On = FALSE;

    /* Switch OFF Command is set FALSE since system is ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Off = FALSE;

    /* Activation Command is set FALSE since system is already ACTIVE */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Activate = FALSE;

    /* Deactivation Command is set TRUE if rising edge of (ON/OFF) button is detected or (Parking-)Brake is engaged or [P|R|N] (VW native HMI logic) */
/*  t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate = (t_HMI_IN_HMCP.pt_HMC->b_OnOff && !t_HMI_LOC_ISCC.b_OnOff)
                                               ||(t_HMI_IN_HMIP.pt_HMI->b_BrakePedal && !t_HMI_IN_SMSP.pt_SMS->t_SYSS.b_StandStill)
                                               || t_HMI_IN_HMIP.pt_HMI->b_ParkBrake
                                               ||(t_HMI_IN_HMIP.pt_HMI->t_DrivePos != ACT_ISC_DRIVE_POS_FORWARD); */

    /* Deactivation Command is set TRUE if (CANCEL) button is detected or (Parking-)Brake is engaged or [P|R|N] (Gateway logic of Demo-Passat) */
    t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate =  t_HMI_IN_HMCP.pt_HMC->b_Cancel || t_HMI_IN_HMIP.pt_HMI->b_ParkBrake
                                               ||(t_HMI_IN_HMIP.pt_HMI->b_BrakePedal && !t_HMI_IN_SMSP.pt_SMS->t_SYSS.b_StandStill)
                                               ||(t_HMI_IN_HMIP.pt_HMI->t_DrivePos != ACT_ISC_DRIVE_POS_FORWARD);

    /* If Deactivation Command is set FALSE */
    if (t_HMI_OUT_SMCP.pt_SMC->t_SYSC.b_Deactivate == FALSE)
    {
      /* Start Confirmation by Driver through RESUME Button or Accelerator Pedal */
      t_HMI_OUT_LVCP.pt_LVC->b_StartConfirmation = t_HMI_IN_HMCP.pt_HMC->b_Resume || t_HMI_IN_HMIP.pt_HMI->b_AccelPedal;

      /* If (SET) button is pressed */
      if (t_HMI_IN_HMCP.pt_HMC->b_Set && !t_HMI_LOC_ISCC.b_Set)
      {
        /* Set new Actual Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_SET;
      }
      /* If (-) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_SpeedDec && !t_HMI_LOC_ISCC.b_SpeedDec)
      {
        /* Decrement Actual Speed by 10 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_DEC_2;
      }
      /* If (+) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_SpeedInc && !t_HMI_LOC_ISCC.b_SpeedInc)
      {
        /* Increment Actual Speed by 10 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_INC_2;
      }
      /* If (RESUME+) button is pressed */
      else if (t_HMI_IN_HMCP.pt_HMC->b_Resume && !t_HMI_LOC_ISCC.b_Resume)
      {
        /* Increment Actual Speed by 1 kmh */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_SPEED_INC_1;
      }
      /* If no button is pressed */
      else
      {
        /* Do not change Speed */
        t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
      }
    }
    else
    {
      /* No Start Confirmation by Driver */
      t_HMI_OUT_LVCP.pt_LVC->b_StartConfirmation = FALSE;

      /* Do not change Speed */
      t_HMI_OUT_SMCP.pt_SMC->t_CCC.t_Operation = ISC_SM_CC_OP_NOP;
    }

    /* Headway Stage is incremented if rising edge of (HEADWAY INC) button is detected */
    if (t_HMI_IN_HMCP.pt_HMC->b_HeadwayInc && !t_HMI_LOC_ISCC.b_HeadwayInc)
    {
      if (u_HMI_LOC_Headway_Stage == HMI_ACC_HEADWAY_STAGE_MAX)
      {
        u_HMI_LOC_Headway_Stage = 0u;
      }
      else
      {
        u_HMI_LOC_Headway_Stage++;
      }
    }

    break;
  }

#if (FCT_CFG_LOCC_COMPONENT)
  /* Generate Degradation Info for Cruise Control Function */
  t_HMI_OUT_CCDP.pt_HMD->b_Disengagement = t_HMI_IN_HMIP.pt_HMI->b_ABS_Failure
                                        || t_HMI_IN_HMIP.pt_HMI->b_TCS_Failure
                                        || t_HMI_IN_HMIP.pt_HMI->b_ESC_Failure;
  t_HMI_OUT_CCDP.pt_HMD->b_NoEngagement = t_HMI_OUT_CCDP.pt_HMD->b_Disengagement;
  t_HMI_OUT_CCDP.pt_HMD->b_Deceleration = FALSE;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  /* Generate Degradation Info for Target Control Function */
  t_HMI_OUT_TCDP.pt_HMD->b_Disengagement = t_HMI_IN_HMIP.pt_HMI->b_ABS_Failure
                                        || t_HMI_IN_HMIP.pt_HMI->b_TCS_Failure
                                        || t_HMI_IN_HMIP.pt_HMI->b_ESC_Failure;
  t_HMI_OUT_TCDP.pt_HMD->b_NoEngagement = t_HMI_OUT_TCDP.pt_HMD->b_Disengagement;
  t_HMI_OUT_TCDP.pt_HMD->b_Deceleration = FALSE;
#endif


  /* Store HMI Input Command locally */
  t_HMI_LOC_ISCC = *(t_HMI_IN_HMCP.pt_HMC);

  /* Acknowledge of stored HMI Command back to requestor (asynchronous com) */
  t_HMI_OUT_HMSP.pt_HMS->t_ISCC = t_HMI_LOC_ISCC;

  /* Output Set Speed */
  t_HMI_OUT_HMSP.pt_HMS->u_SetSpeed = t_HMI_IN_SMSP.pt_SMS->t_CCS.u_SetSpeed;

  /* Output Headway Setting State */
  t_HMI_OUT_HMSP.pt_HMS->u_HeadwaySetting = u_HMI_LOC_Headway_Stage * 100 / HMI_ACC_HEADWAY_STAGE_MAX;

  /* Output Target Control Status */
  t_HMI_OUT_HMSP.pt_HMS->b_TakeOverRequest = t_HMI_IN_SMSP.pt_SMS->t_TCS.b_TakeOverRequest;
  t_HMI_OUT_HMSP.pt_HMS->b_TargetControl = t_HMI_IN_SMSP.pt_SMS->t_TCS.b_TargetDetected;
  t_HMI_OUT_HMSP.pt_HMS->u_RequestDistance = t_HMI_IN_SMSP.pt_SMS->t_TCS.u_RequestDistance;
  t_HMI_OUT_HMSP.pt_HMS->u_TargetDistance = t_HMI_IN_SMSP.pt_SMS->t_TCS.u_TargetDistance;
  t_HMI_OUT_HMSP.pt_HMS->u_TargetSpeed = t_HMI_IN_SMSP.pt_SMS->t_TCS.u_TargetSpeed;

  /* Output Headway Setting Command */
  t_HMI_OUT_SMCP.pt_SMC->t_TCC.u_HeadwaySet = u_HMI_LOC_Headway_Stage * 100 / HMI_ACC_HEADWAY_STAGE_MAX;
}

#endif /*!< FCT_CFG_ISC_COMPONENT */

