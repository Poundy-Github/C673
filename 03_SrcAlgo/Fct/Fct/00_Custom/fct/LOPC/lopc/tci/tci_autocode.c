/*
 * File: tci_autocode.c
 *
 * Code generated for Simulink model 'tci'.
 *
 * Model version                  : 1.281
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Jul 11 17:38:08 2018
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 *    3. Safety precaution
 *    4. Debugging
 *    5. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "tci.h"

/* Named constants for Chart: '<S5>/NotificationStateFlow' */
#define IN_NOTICE                      ((uint8)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8)0U)
#define IN_STBY                        ((uint8)2U)

/* Named constants for Chart: '<S6>/TciStateFlow' */
#define IN_EgoVehStop                  ((uint8)1U)
#define IN_INI                         ((uint8)1U)
#define IN_INI_DIST                    ((uint8)1U)
#define IN_INI_DIST_EVAL               ((uint8)2U)
#define IN_INI_n                       ((uint8)2U)
#define IN_LeadVehMove                 ((uint8)1U)
#define IN_LeadVehStop                 ((uint8)2U)
#define IN_NOTICE_STBY                 ((uint8)2U)
#define IN_STOP                        ((uint8)2U)

#if (TCIOutput_INTFVER < 5)
#define TCI_State_INI_DIST_EVAL        ((uint8)4U)
#endif
#define TCI_OOI0_STOPPED_VEL           (0.2f)
#define TCI_OOI0_STOPPED_VEL_HYST      (0.3f)

/* user code (top of source file) */
/* System '<Root>' */
#if (TCI_CFG_AUTOCODE)

/* Model step function */
void tci_step(tci_RT_MODEL *const rtM, TCIInput_t *rtU_TCIInput, TCI_ActInput_t *
              rtU_TCI_ActInput, TCIOutput_t *rtY_TCIOutput)
{
  tci_D_Work *rtDWork = ((tci_D_Work *) rtM->ModelData.dwork);
  float32 tmp_TCI_f_DeltaDistNotice;
  boolean tmp_TCI_b_Permit;
  sint32 tmp_sint32;

  /* MultiPortSwitch: '<S4>/Delta dist selection' incorporates:
   *  Constant: '<S2>/TCI_f_DeltaDistModFast[m]'
   *  Constant: '<S2>/TCI_f_DeltaDistModLate[m]'
   *  Constant: '<S2>/TCI_f_DeltaDistModNorm[m]'
   *  Delay: '<S4>/TCI_f_DeltaDistNoticeOld'
   *  Inport: '<Root>/TCIInput'
   */
  switch (rtU_TCIInput->TCI_NoticeMode) {
   case 1:
    tmp_TCI_f_DeltaDistNotice = (float32)TCI_f_DeltaDistModFast;
    break;

   case 2:
    tmp_TCI_f_DeltaDistNotice = (float32)TCI_f_DeltaDistModNorm;
    break;

   case 3:
    tmp_TCI_f_DeltaDistNotice = (float32)TCI_f_DeltaDistModLate;
    break;

   default:
    tmp_TCI_f_DeltaDistNotice = rtDWork->TCI_f_DeltaDistNoticeOld_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S4>/Delta dist selection' */

  /* Logic: '<S6>/logic operator' incorporates:
   *  Inport: '<Root>/TCIInput'
   *  Inport: '<Root>/TCI_ActInput'
   *  Logic: '<S6>/OR'
   */
  tmp_TCI_b_Permit = !((rtU_TCI_ActInput->b_SensSelfTest) ||
                       (rtU_TCIInput->TCI_b_IGPOff) || (rtU_TCIInput->TCI_b_Malf));

  /* Chart: '<S6>/TciStateFlow' incorporates:
   *  Constant: '<S2>/TCI_DlyDistIniClc[s]'
   *  Constant: '<S2>/TCI_DlyReActDistIniClc[s]'
   *  Constant: '<S2>/TCI_f_DistMaxActThd[m]'
   *  Delay: '<S6>/TCI_b_AccActOld'
   *  Delay: '<S6>/TCI_b_DriveOffAccOld'
   *  Inport: '<Root>/TCIInput'
   *  Inport: '<Root>/TCI_ActInput'
   */
  /* Gateway: tci/tci/TCI State Machine/TciStateFlow */
  /* During: tci/tci/TCI State Machine/TciStateFlow */
  if (rtDWork->is_active_c3_tci == 0U) {
    /* Entry: tci/tci/TCI State Machine/TciStateFlow */
    rtDWork->is_active_c3_tci = 1U;

    /* Entry Internal: tci/tci/TCI State Machine/TciStateFlow */
    /* Entry Internal 'EgoVeh': '<S8>:52' */
    /* Transition: '<S8>:61' */
    rtDWork->is_EgoVeh = IN_INI;

    /* Entry 'INI': '<S8>:62' */
    rtDWork->TCI_TimerEgoVehStop = 0U;

    /* Entry Internal 'LeadVeh': '<S8>:70' */
    /* Transition: '<S8>:72' */
    rtDWork->is_LeadVeh = IN_INI;

    /* Entry 'INI': '<S8>:74' */
    rtDWork->TCI_TimerLeadVehStop = 0U;

    /* Entry Internal 'TciNotice': '<S8>:75' */
    /* Transition: '<S8>:65' */
    rtDWork->is_TciNotice = IN_INI_n;

    /* Entry 'INI': '<S8>:53' */
    rtDWork->TCI_State = (uint8)TCI_State_INI;
    rtDWork->TCI_b_Notice = false;
  } else {
    /* During 'EgoVeh': '<S8>:52' */
    if (rtDWork->is_EgoVeh == IN_INI) {
      /* During 'INI': '<S8>:62' */
      if (rtU_TCI_ActInput->b_EgoVehStop) {
        /* Transition: '<S8>:64' */
        rtDWork->is_EgoVeh = IN_STOP;
      }
    } else {
      /* During 'STOP': '<S8>:63' */
      if (!rtU_TCI_ActInput->b_EgoVehStop) {
        /* Transition: '<S8>:60' */
        rtDWork->is_EgoVeh = IN_INI;

        /* Entry 'INI': '<S8>:62' */
        rtDWork->TCI_TimerEgoVehStop = 0U;
      } else {
        tmp_sint32 = (sint32)rtDWork->TCI_TimerEgoVehStop + 1;
        if (tmp_sint32 > 65535) {
          tmp_sint32 = 65535;
        }

        rtDWork->TCI_TimerEgoVehStop = (uint16)tmp_sint32;
      }
    }

    /* During 'LeadVeh': '<S8>:70' */
    if (rtDWork->is_LeadVeh == IN_INI) {
      /* During 'INI': '<S8>:74' */
      if (rtU_TCI_ActInput->b_LeadVehStop) {
        /* Transition: '<S8>:69' */
        rtDWork->is_LeadVeh = IN_STOP;
      }
    } else {
      /* During 'STOP': '<S8>:73' */
      if ((!rtU_TCI_ActInput->b_LeadVehStop) || (rtU_TCI_ActInput->b_LostLeadVeh) ||
          (rtU_TCI_ActInput->b_ChgLeadVeh)) {
        /* Transition: '<S8>:71' */
        rtDWork->is_LeadVeh = IN_INI;

        /* Entry 'INI': '<S8>:74' */
        rtDWork->TCI_TimerLeadVehStop = 0U;
      } else {
        tmp_sint32 = (sint32)rtDWork->TCI_TimerLeadVehStop + 1;
        if (tmp_sint32 > 65535) {
          tmp_sint32 = 65535;
        }

        rtDWork->TCI_TimerLeadVehStop = (uint16)tmp_sint32;
      }
    }

    /* During 'TciNotice': '<S8>:75' */
    if (rtDWork->is_TciNotice == IN_EgoVehStop) {
      /* During 'EgoVehStop': '<S8>:50' */
      if ((!tmp_TCI_b_Permit) || (!rtU_TCIInput->TCI_b_On) ||
          (!rtU_TCI_ActInput->b_EgoVehStop) || (rtU_TCI_ActInput->b_LostLeadVeh) ||
          (rtU_TCI_ActInput->b_ChgLeadVeh) || (rtDWork->TCI_f_DistIni > (float32)
           TCI_f_DistMaxActThd) || (rtU_TCI_ActInput->b_AccAct !=
           rtDWork->TCI_b_AccActOld_DSTATE)) {
        /* Transition: '<S8>:67' */
        /* Exit Internal 'EgoVehStop': '<S8>:50' */
        /* Exit Internal 'LeadVehMove': '<S8>:84' */
        rtDWork->is_LeadVehMove = IN_NO_ACTIVE_CHILD;
        rtDWork->is_EgoVehStop = IN_NO_ACTIVE_CHILD;

        /* Exit Internal 'LeadVehStop': '<S8>:86' */
        rtDWork->is_LeadVehStop = IN_NO_ACTIVE_CHILD;
        rtDWork->is_TciNotice = IN_INI_n;
        rtDWork->TCI_TimerLeadVehDriveOff = 0U;

        /* Entry 'INI': '<S8>:53' */
        rtDWork->TCI_State = (uint8)TCI_State_INI;
        rtDWork->TCI_b_Notice = false;
      } else if (rtDWork->is_EgoVehStop == IN_LeadVehMove) {
        /* During 'LeadVehMove': '<S8>:84' */
        if ((rtU_TCI_ActInput->b_LeadVehStop) && (rtU_TCI_ActInput->f_VabsXOOI0 <= TCI_OOI0_STOPPED_VEL)) {
          /* Transition: '<S8>:54' */
          if (rtU_TCI_ActInput->b_AccAct) {
            /* Transition: '<S8>:85' */
            /* Exit Internal 'LeadVehMove': '<S8>:84' */
            rtDWork->is_LeadVehMove = IN_NO_ACTIVE_CHILD;
            rtDWork->is_EgoVehStop = IN_NO_ACTIVE_CHILD;
            rtDWork->is_TciNotice = IN_INI_n;

            /* Entry 'INI': '<S8>:53' */
            rtDWork->TCI_State = (uint8)TCI_State_INI;
            rtDWork->TCI_b_Notice = false;
          } else {
            /* Transition: '<S8>:90' */
            /* Exit Internal 'LeadVehMove': '<S8>:84' */
            rtDWork->is_LeadVehMove = IN_NO_ACTIVE_CHILD;
            rtDWork->is_EgoVehStop = IN_LeadVehStop;
            rtDWork->is_LeadVehStop = IN_INI_DIST_EVAL;
            rtDWork->TCI_TimerLeadVehDriveOff = 0U;

            /* Entry 'INI_DIST_EVAL': '<S8>:87' */
            rtDWork->TCI_State = (uint8)TCI_State_INI_DIST_EVAL;
          }
        } else if ((rtDWork->is_LeadVehMove != IN_NOTICE) &&
                   (rtU_TCI_ActInput->f_DistLeadVeh - (float32)
                    rtDWork->TCI_f_DistIni > (float32)tmp_TCI_f_DeltaDistNotice)) {
          /* During 'NOTICE_STBY': '<S8>:58' */
          /* Transition: '<S8>:55' */
          rtDWork->is_LeadVehMove = IN_NOTICE;

          /* Entry 'NOTICE': '<S8>:57' */
          rtDWork->TCI_State = (uint8)TCI_State_NOTICE;
          rtDWork->TCI_b_Notice = true;
        } else {
          /* During 'NOTICE': '<S8>:57' */
        }
      } else {
        /* During 'LeadVehStop': '<S8>:86' */
          if ((!rtU_TCI_ActInput->b_LeadVehStop) || (rtU_TCI_ActInput->f_VabsXOOI0 >= (TCI_OOI0_STOPPED_VEL + TCI_OOI0_STOPPED_VEL_HYST))) {
          /* Transition: '<S8>:56' */
          /* Exit Internal 'LeadVehStop': '<S8>:86' */
          rtDWork->is_LeadVehStop = IN_NO_ACTIVE_CHILD;
          rtDWork->is_EgoVehStop = IN_LeadVehMove;
          rtDWork->is_LeadVehMove = IN_NOTICE_STBY;
          rtDWork->TCI_TimerLeadVehDriveOff = 0U;

          /* Entry 'NOTICE_STBY': '<S8>:58' */
          rtDWork->TCI_State = (uint8)TCI_State_NOTICE_STBY;
        } else if ((rtDWork->is_LeadVehStop != IN_INI_DIST) &&
                   (rtDWork->TCI_TimerLeadVehDriveOff > ((uint16)
                     TCI_DlyReActDistIniClc))) {
          /* During 'INI_DIST_EVAL': '<S8>:87' */
          /* Transition: '<S8>:88' */
          rtDWork->is_LeadVehStop = IN_INI_DIST;
          rtDWork->TCI_TimerLeadVehDriveOff = 0U;

          /* Entry 'INI_DIST': '<S8>:59' */
          rtDWork->TCI_State = (uint8)TCI_State_INI_DIST;
          rtDWork->TCI_f_DistIni = (float32)rtU_TCI_ActInput->f_DistLeadVeh;
          rtDWork->TCI_b_Notice = false;
        } else if(rtDWork->is_LeadVehStop == IN_INI_DIST_EVAL) {
          tmp_sint32 = (sint32)rtDWork->TCI_TimerLeadVehDriveOff + 1;
          if (tmp_sint32 > 65535) {
            tmp_sint32 = 65535;
          }
          rtDWork->TCI_TimerLeadVehDriveOff = (uint16)tmp_sint32;
        } else {
          /* During 'INI_DIST': '<S8>:59' */
        }
      }
    } else {
      /* During 'INI': '<S8>:53' */
      if ((tmp_TCI_b_Permit) && (rtU_TCIInput->TCI_b_On) &&
          (rtDWork->TCI_TimerEgoVehStop >= ((uint16)TCI_DlyDistIniClc)) &&
          (rtU_TCI_ActInput->f_DistLeadVeh <= TCI_f_DistMaxActThd) &&
          (((!rtU_TCI_ActInput->b_AccAct) && (rtDWork->TCI_TimerLeadVehStop >=
             ((uint16)TCI_DlyDistIniClc))) || ((rtU_TCI_ActInput->b_AccAct) &&
            (!rtDWork->TCI_b_DriveOffAccOld_DSTATE) &&
            (rtU_TCI_ActInput->b_DriveOffAcc)))) {
        /* Transition: '<S8>:66' */
        rtDWork->is_TciNotice = IN_EgoVehStop;
        rtDWork->is_EgoVehStop = IN_LeadVehStop;
        rtDWork->is_LeadVehStop = IN_INI_DIST;
        rtDWork->TCI_TimerLeadVehDriveOff = 0U;

        /* Entry 'INI_DIST': '<S8>:59' */
        rtDWork->TCI_State = (uint8)TCI_State_INI_DIST;
        rtDWork->TCI_f_DistIni = (float32)rtU_TCI_ActInput->f_DistLeadVeh;
        rtDWork->TCI_b_Notice = false;
      }
    }
  }

  /* End of Chart: '<S6>/TciStateFlow' */

  /* Chart: '<S5>/NotificationStateFlow' incorporates:
   *  Constant: '<S2>/TCI_TiNoticeThdMax[s]'
   *  Constant: '<S2>/TCI_TiNoticeThdMin[s]'
   *  Delay: '<S5>/TCI_b_NoticeOld'
   *  Inport: '<Root>/TCIInput'
   *  Logic: '<S5>/!TCI_b_NoticeInh'
   *  Logic: '<S5>/!TCI_b_NoticeOld'
   *  Logic: '<S5>/!b_ObjBlockEgoLane'
   *  Logic: '<S5>/AND1'
   *  Logic: '<S5>/AND2'
   */
  /* Gateway: tci/tci/Notification/NotificationStateFlow */
  /* During: tci/tci/Notification/NotificationStateFlow */
  if (rtDWork->is_active_c1_tci == 0U) {
    /* Entry: tci/tci/Notification/NotificationStateFlow */
    rtDWork->is_active_c1_tci = 1U;

    /* Entry Internal: tci/tci/Notification/NotificationStateFlow */
    /* Transition: '<S7>:6' */
    rtDWork->is_c1_tci = IN_STBY;

    /* Entry 'STBY': '<S7>:5' */
    rtDWork->TCI_IndiReq = (uint8)TCI_IndiReq_NO_REQ;
    rtDWork->TCI_b_BuzReq = false;
  } else if (rtDWork->is_c1_tci == IN_NOTICE) {
    /* During 'NOTICE': '<S7>:1' */
    if ((rtDWork->TCI_TimerIndi >= ((uint16)TCI_TiNoticeThdMin)) &&
        ((rtDWork->TCI_TimerIndi >= ((uint16)TCI_TiNoticeThdMax)) ||
         (!rtDWork->TCI_b_Notice))) {
      /* Transition: '<S7>:4' */
      rtDWork->is_c1_tci = IN_STBY;

      /* Entry 'STBY': '<S7>:5' */
      rtDWork->TCI_IndiReq = (uint8)TCI_IndiReq_NO_REQ;
      rtDWork->TCI_b_BuzReq = false;
    } else {
      tmp_sint32 = (sint32)rtDWork->TCI_TimerIndi + 1;
      if (tmp_sint32 > 65535) {
        tmp_sint32 = 65535;
      }

      rtDWork->TCI_TimerIndi = (uint16)tmp_sint32;
    }
  } else {
    /* During 'STBY': '<S7>:5' */
    if ((rtDWork->TCI_b_Notice) && (!rtDWork->TCI_b_NoticeOld_DSTATE) &&
        (!rtU_TCIInput->TCI_b_NoticeInh) && (!rtU_TCIInput->b_ObjBlockEgoLane))
    {
      /* Transition: '<S7>:7' */
      rtDWork->is_c1_tci = IN_NOTICE;

      /* Entry 'NOTICE': '<S7>:1' */
      rtDWork->TCI_TimerIndi = 1U;
      rtDWork->TCI_IndiReq = (uint8)TCI_IndiReq_NOTICE_REQ;
      rtDWork->TCI_b_BuzReq = true;
    }
  }

  /* End of Chart: '<S5>/NotificationStateFlow' */

  /* BusCreator: '<Root>/BusConversion_InsertedFor_TCIOutput_at_inport_0' */
  rtY_TCIOutput->TCI_State = rtDWork->TCI_State;
  rtY_TCIOutput->TCI_IndiReq = rtDWork->TCI_IndiReq;
  rtY_TCIOutput->TCI_b_BuzReq = rtDWork->TCI_b_BuzReq;

  /* Update for Delay: '<S6>/TCI_b_DriveOffAccOld' incorporates:
   *  Update for Inport: '<Root>/TCI_ActInput'
   */
  rtDWork->TCI_b_DriveOffAccOld_DSTATE = rtU_TCI_ActInput->b_DriveOffAcc;

  /* Update for Delay: '<S6>/TCI_b_AccActOld' incorporates:
   *  Update for Inport: '<Root>/TCI_ActInput'
   */
  rtDWork->TCI_b_AccActOld_DSTATE = rtU_TCI_ActInput->b_AccAct;

  /* Update for Delay: '<S4>/TCI_f_DeltaDistNoticeOld' */
  rtDWork->TCI_f_DeltaDistNoticeOld_DSTATE = tmp_TCI_f_DeltaDistNotice;

  /* Update for Delay: '<S5>/TCI_b_NoticeOld' */
  rtDWork->TCI_b_NoticeOld_DSTATE = rtDWork->TCI_b_Notice;
}/* PRQA S 7004 */
/* date: 2019-05-05, reviewer: Rasish Verma(uib25204), reason : Cyclomatic complexity. Not Safety critical*/



/* Model initialize function */
void tci_initialize(tci_RT_MODEL *const rtM)
{
  tci_D_Work *rtDWork = ((tci_D_Work *) rtM->ModelData.dwork);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)rtDWork, 0,
                sizeof(tci_D_Work));

  /* InitializeConditions for Delay: '<S4>/TCI_f_DeltaDistNoticeOld' */
  rtDWork->TCI_f_DeltaDistNoticeOld_DSTATE = 4.0F;

  /* SystemInitialize for Chart: '<S6>/TciStateFlow' */
  rtDWork->is_EgoVeh = IN_NO_ACTIVE_CHILD;
  rtDWork->is_LeadVeh = IN_NO_ACTIVE_CHILD;
  rtDWork->is_TciNotice = IN_NO_ACTIVE_CHILD;
  rtDWork->is_EgoVehStop = IN_NO_ACTIVE_CHILD;
  rtDWork->is_LeadVehMove = IN_NO_ACTIVE_CHILD;
  rtDWork->is_LeadVehStop = IN_NO_ACTIVE_CHILD;
  rtDWork->is_active_c3_tci = 0U;
  rtDWork->TCI_TimerLeadVehStop = 0U;
  rtDWork->TCI_TimerLeadVehDriveOff = 0U;
  rtDWork->TCI_TimerEgoVehStop = 0U;
  rtDWork->TCI_f_DistIni = 0.0F;
  rtDWork->TCI_State = 0U;
  rtDWork->TCI_b_Notice = false;

  /* SystemInitialize for Chart: '<S5>/NotificationStateFlow' */
  rtDWork->is_active_c1_tci = 0U;
  rtDWork->is_c1_tci = IN_NO_ACTIVE_CHILD;
  rtDWork->TCI_TimerIndi = 0U;
  rtDWork->TCI_IndiReq = 0U;
  rtDWork->TCI_b_BuzReq = false;
}

/* user code (bottom of source file) */
/* System '<Root>' */
#endif                                 /* TCI_CFG_AUTOCODE */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
