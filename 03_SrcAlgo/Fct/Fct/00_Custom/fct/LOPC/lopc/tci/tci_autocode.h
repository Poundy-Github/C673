/*
 * File: tci_autocode.h
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

#ifndef RTW_HEADER_tci_h_
#define RTW_HEADER_tci_h_

#include "tci.h"

#if (TCI_CFG_AUTOCODE)
#ifndef __PDO__
#include <string.h>
#endif /* #ifndef __PDO__ */
#ifndef tci_COMMON_INCLUDES_
# define tci_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* tci_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */

/* Exported data define */

/* Definition for custom storage class: Define */
#define TCI_DlyDistIniClc              50U                       /* Delay to calculate initial distance after ego and leading vehicle are stopped */
#define TCI_DlyReActDistIniClc         250U                      /* Delay to recalculate initial distance after preceding vehicle is stopped again */
#define TCI_TiNoticeThdMax             175U                      /* Maximum time to notice, in case of no action from the driver */
#define TCI_TiNoticeThdMin             75U                       /* Minimum time to notice */
#define TCI_f_DeltaDistModFast         2.0F                      /* Delta distance for fast notice */
#define TCI_f_DeltaDistModLate         6.0F                      /* Delta distance for late notice */
#define TCI_f_DeltaDistModNorm         4.0F                      /* Delta distance for normal notice */
#define TCI_f_DistMaxActThd            7.0F                      /* Maximum distance to activate TCI */

/* Forward declaration for rtModel */
typedef struct tci_tag_RTM tci_RT_MODEL;

/* user code (top of header file) */
/* System '<Root>' */

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  float32 TCI_f_DeltaDistNoticeOld_DSTATE;/* '<S4>/TCI_f_DeltaDistNoticeOld' */
  float32 TCI_f_DistIni;               /* '<S6>/TciStateFlow' */
  uint16 TCI_TimerLeadVehStop;         /* '<S6>/TciStateFlow' */
  uint16 TCI_TimerLeadVehDriveOff;     /* '<S6>/TciStateFlow' */
  uint16 TCI_TimerEgoVehStop;          /* '<S6>/TciStateFlow' */
  uint16 TCI_TimerIndi;                /* '<S5>/NotificationStateFlow' */
  uint8 TCI_State;                     /* '<S6>/TciStateFlow' */
  uint8 TCI_IndiReq;                   /* '<S5>/NotificationStateFlow' */
  uint8 is_active_c3_tci;              /* '<S6>/TciStateFlow' */
  uint8 is_EgoVeh;                     /* '<S6>/TciStateFlow' */
  uint8 is_TciNotice;                  /* '<S6>/TciStateFlow' */
  uint8 is_EgoVehStop;                 /* '<S6>/TciStateFlow' */
  uint8 is_LeadVehStop;                /* '<S6>/TciStateFlow' */
  uint8 is_LeadVehMove;                /* '<S6>/TciStateFlow' */
  uint8 is_LeadVeh;                    /* '<S6>/TciStateFlow' */
  uint8 is_active_c1_tci;              /* '<S5>/NotificationStateFlow' */
  uint8 is_c1_tci;                     /* '<S5>/NotificationStateFlow' */
  boolean TCI_b_Notice;                /* '<S6>/TciStateFlow' */
  boolean TCI_b_BuzReq;                /* '<S5>/NotificationStateFlow' */
  boolean TCI_b_DriveOffAccOld_DSTATE; /* '<S6>/TCI_b_DriveOffAccOld' */
  boolean TCI_b_AccActOld_DSTATE;      /* '<S6>/TCI_b_AccActOld' */
  boolean TCI_b_NoticeOld_DSTATE;      /* '<S5>/TCI_b_NoticeOld' */
} tci_D_Work;

/* Real-time Model Data Structure */
struct tci_tag_RTM {
  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    tci_D_Work *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void tci_initialize(tci_RT_MODEL *const rtM);
extern void tci_step(tci_RT_MODEL *const rtM, TCIInput_t *rtU_TCIInput,
                     TCI_ActInput_t *rtU_TCI_ActInput, TCIOutput_t
                     *rtY_TCIOutput);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('tci_Model/tci')    - opens subsystem tci_Model/tci
 * hilite_system('tci_Model/tci/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'tci_Model'
 * '<S1>'   : 'tci_Model/tci'
 * '<S2>'   : 'tci_Model/tci/TCI Parameter'
 * '<S3>'   : 'tci_Model/tci/tci'
 * '<S4>'   : 'tci_Model/tci/tci/Notice Distance'
 * '<S5>'   : 'tci_Model/tci/tci/Notification'
 * '<S6>'   : 'tci_Model/tci/tci/TCI State Machine'
 * '<S7>'   : 'tci_Model/tci/tci/Notification/NotificationStateFlow'
 * '<S8>'   : 'tci_Model/tci/tci/TCI State Machine/TciStateFlow'
 */

/*-
 * Requirements for '<Root>': tci
 */

/* user code (bottom of header file) */
/* System '<Root>' */
#endif                                 /* TCI_CFG_AUTOCODE */
#endif                                 /* RTW_HEADER_tci_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
