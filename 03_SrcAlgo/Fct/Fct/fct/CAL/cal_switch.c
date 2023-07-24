/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS5xx

CPU:                       CPU-Independent

COMPONENT:                 CAL (Common ACC Library)

PACKAGENAME:               cal_switch.c

DESCRIPTION:               All function concerning the handling of switches 

AUTHOR:                    Shang, Hanyu

CREATION DATE:             27.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.21.1.2


**************************************************************************** */
#include "cal_int.h"/* PRQA S 0380
date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

/* PRQA S 1863 450
 date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */

#if ((FCT_CFG_ACC_CAL) && (FCT_CFG_BUTTON_SWITCH_EVALUATION))
/*************************************************************************************************************************
  Functionname:    SWITCH_INIT_SWITCH                                                                               */ /*!

  @brief           Initialize switches

  @description     Switch values are set to default

                    @startuml
                    Start
                    Partition SWITCH_INIT_SWITCH {

                    : Initialize the current status and last status of switch to 0;
                    : Initialize timer for active switch for 0 cycle and inactive switch for 1023 cycles; 
                    : Initialize timer of switch cycle to 0;
                    : Intialize the boolean indicating switch was off state to False;
                    }
                    Stop
                    @enduml

  @return          void

  @param[in,out]   pSwitch : Pointer to switch that shall be initialized [switch_t as per cal_switch_ext.h]
                    AKT_STATUS : Current status of switch [TRUE, FALSE]
                    LAST_STATUS : Last cycle status of switch [TRUE, FALSE]
                    CYCLE_TIMER : Timer of switch cycle [0u ... switch_cycletimer_init]
                    DURATION_TIME_ACTIVE : Cycles for which switch is active [0u ... switch_dta_max_val)
                    DURATION_TIME_INACTIVE : Cycles for which switch is inactive [0u ... switch_dtia_max_val)
                    OK_WHILE_SWITCHED_ON : Boolean indicating that switch was in off state when condition was true [TRUE, FALSE]
  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-568-0009fc80">CAL_568</a> \n

*************************************************************************************************************************/
void SWITCH_INIT_SWITCH(switch_t * const pSwitch)
{
  pSwitch->AKT_STATUS = FALSE;
  pSwitch->LAST_STATUS = FALSE;
  pSwitch->CYCLE_TIMER = switch_cycletimer_init;
  pSwitch->DURATION_TIME_INACTIVE = switch_dtia_max_val;
  pSwitch->DURATION_TIME_ACTIVE = 0u;
  pSwitch->OK_WHILE_SWITCHED_ON = FALSE;
}

/*************************************************************************************************************************
  Functionname:    SWITCH_SET_STATE                                                                                 */ /*!

  @brief           Sets a new switch state for a specific switch

  @description     State of the switch is set to a new value.
                   Number of cycles of (in)activity are refreshed 

                    @startuml
                    Start
                    Partition SWITCH_SET_STATE {

                    : Save the current switch status as the last switch status;
                    If (**Is the switch pressed ?**) then  (yes)
                      : increment active cycles till it reaches the maximum active cycle count;
                    Else (no)
                      : count inactive cycles till it reaches the maximum inactive count;
                    Endif
                    If (**If Switch was not pressed in the last cycle **) then (yes)
                      : Reset the active cycle count;
                    Else (no)
                      : reset inactive cycle count;
                    Endif

                    }
                    Stop
                    @enduml

  @return          void

  @param[in,out]   pSwitch : Pointer to switch to be set [switch_t as per cal_switch_ext.h]
                    AKT_STATUS :  Current status of switch [TRUE, FALSE]
                    LAST_STATUS : Last cycle status of switch [TRUE, FALSE]
                    DURATION_TIME_ACTIVE : Cycles for which switch is active [0u ... switch_dta_max_val)
                    DURATION_TIME_INACTIVE : Cycles for which switch is inactive [0u ... switch_dtia_max_val)
  @param[in]       State : The new state for the switch [TRUE, FALSE]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-569-0009fc80">CAL_569</a> \n

*************************************************************************************************************************/
void SWITCH_SET_STATE(switch_t * const pSwitch, const boolean State)
{
  const boolean lastState = (boolean)pSwitch->AKT_STATUS;

  /*save old value*/
  pSwitch->LAST_STATUS = pSwitch->AKT_STATUS;
  /*Set new value*/
  pSwitch->AKT_STATUS  = State;

  /*count cycles of (in)activity*/
  if (State == TRUE)
  {
    if(pSwitch->DURATION_TIME_ACTIVE < switch_dta_max_val)/* PRQA S 1862 
    date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */
    {
      pSwitch->DURATION_TIME_ACTIVE++;
    }
  }
  else
  {
    if(pSwitch->DURATION_TIME_INACTIVE < switch_dtia_max_val)/* PRQA S 1862
    date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */
    {
      pSwitch->DURATION_TIME_INACTIVE++;
    }
  }

  if (lastState == FALSE)
  {
    pSwitch->DURATION_TIME_ACTIVE = (uint16) 0;
  }
  else
  {
    pSwitch->DURATION_TIME_INACTIVE = (uint16) 0;
  }
}

/*************************************************************************************************************************
  Functionname:    SWITCH_RISING_EDGE                                                                               */ /*!

  @brief           Checks if the switch was switched on

  @description     Checks if switch has changed state to true, 
                   as well as if condition is true.

                    @startuml
                    Start
                    Partition SWITCH_RISING_EDGE {

                    If (**If switch is pressed in current cycle and not pressed in last cycle**) then (yes)
                      if (**condition for setting switch to On is satisfied**) then (yes)
                        : switch is set to ON state;
                      Else (no)
                        : switch is set to action off state;
                      Endif
                    Else (no)
                      : the switch is set to OFF state;
                    Endif

                    }
                    Stop
                    @enduml

  @return          Switch state based on condition given [switch_state_t]
                    SWITCH_STATE_OFF(0) = FALSE,
                    SWITCH_STATE_ON(1) = TRUE,
                    SWITCH_STATE_ACTION_OFF(2) = switched on, but the condition is not fulfilled

  @param[in]       pSwitch : Pointer to switch to be checked [switch_t as per cal_switch_ext.h]
                    AKT_STATUS :  Current status of switch [TRUE, FALSE]
                    LAST_STATUS : Last cycle status of switch [TRUE, FALSE]
  @param[in]       Condition : Condition that allows the switch to be switched on [TRUE, FALSE] (0 = FALSE, 1 = TRUE)

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-570-0009fc80">CAL_570</a> \n

*************************************************************************************************************************/
switch_state_t SWITCH_RISING_EDGE(const switch_t * const pSwitch, const boolean Condition)
{
  switch_state_t retValue = SWITCH_STATE_OFF;

  if ((pSwitch->AKT_STATUS == TRUE) && (pSwitch->LAST_STATUS == FALSE))
  {
    if (Condition != FALSE)
    {
      retValue = SWITCH_STATE_ON;
    }
    else
    {
      retValue = SWITCH_STATE_ACTION_OFF;
    }
  }
  return retValue;
}

/*************************************************************************************************************************
  Functionname:    SWITCH_FALLING_EDGE                                                                              */ /*!

  @brief           Checks is the switch was switched off

  @description     Checks if switch has changed state to false, 
                   as well as if condition is true. Returns SWITCH_STATE_ON 
                   only if switch was previously false when condition was true.

                    @startuml
                    Start
                    Partition SWITCH_FALLING_EDGE {

                    If(** Condition to switch Off is False ?**) then (Yes)
                    : Set the switch status will be in OFF state;
                    Endif
                    If (**If switch status changes from ON to OFF**) then (yes)
                      if (**condition for setting switch to Off is satisfied and the switch is OFF**) then (yes)
                        : switch is set to ON state;
                      Else (no)
                        : switch is set to action off state;
                      Endif
                    Else (no)
                      : the switch is set to OFF state;
                    : The flag indicating switch OFF when conditions are satisfied shall be set when \n  switch status is Off and conditions are satisfied;
                    Endif
                    }
                    Stop
                    @enduml

  @return          Switch state based on condition given [switch_state_t]
                    SWITCH_STATE_OFF(0) = FALSE,
                    SWITCH_STATE_ON(1) = TRUE,
                    SWITCH_STATE_ACTION_OFF(2) = switched off, but the condition is not fulfilled

  @param[in,out]   pSwitch : Pointer to switch to be checked [switch_t as per cal_witch_ext.h]
                    AKT_STATUS : Current status of switch [TRUE, FALSE]
                    LAST_STATUS : Last cycle status of switch [TRUE, FALSE]
                    OK_WHILE_SWITCHED_ON : Boolean indicating that switch was in off state when condition was true [TRUE, FALSE]
  @param[in]       Condition : Condition that allows the switch to be switched off [TRUE, FALSE] (0 = FALSE, 1 = TRUE)

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-571-0009fc80">CAL_571</a> \n

*************************************************************************************************************************/
switch_state_t SWITCH_FALLING_EDGE(switch_t * const pSwitch, const boolean Condition)
{
  switch_state_t retValue = SWITCH_STATE_OFF;

  if (Condition == FALSE)
  {
    pSwitch->OK_WHILE_SWITCHED_ON = FALSE;
  }

  if ((pSwitch->AKT_STATUS == FALSE) && (pSwitch->LAST_STATUS == TRUE))
  {
    if ((Condition == TRUE) && (pSwitch->OK_WHILE_SWITCHED_ON == TRUE))
    {
      retValue = SWITCH_STATE_ON;
    }
    else
    {
      retValue = SWITCH_STATE_ACTION_OFF;
    }
  }

  if((pSwitch->AKT_STATUS == FALSE) && (Condition == TRUE))
  {
    /*switch was in off state while the condition is true*/
    pSwitch->OK_WHILE_SWITCHED_ON = TRUE;
  }

  return retValue;
}

/*************************************************************************************************************************
  Functionname:    SWITCH_HOLD_REPEAT                                                                               */ /*!

  @brief           Returns SWITCH_STATE_ON, if the switch was held long enough to get repeated signals from that switch

  @description     Tests if switch is held for required time if HoldCondition is true. 
                   Timer is started only if StartCondition is true. Time for which switch must be held determined
                   by initial value of StartTime and later by RepeatTime

                    @startuml
                    Start
                    Partition SWITCH_HOLD_REPEAT {

                    if (**switch is off or start conditions are not satisfied or timer \n is not initialized with hold conditions not satisfied**) then (yes)
                      : timer is initialized;
                    else (no)
                      if (**switch is pressed and timer is initialized**) then (yes)
                        : initialize the timer to start time;
                      else (no)
                        : Decrement timer if timer is non-zero and hold conditions is true;
                        : Initialize the timer to repeat timer value and switch is set to ON state;
                      endif
                    endif
                    }
                    Stop
                    @enduml

  @return          Switch state indicating if switch is held true for given condition [switch_state_t]
                      SWITCH_STATE_OFF(0) = FALSE,
                      SWITCH_STATE_ON(1) = TRUE,
                      SWITCH_STATE_ACTION_OFF(2) = currently not returned

  @param[in,out]   pSwitch : Pointer to switch to be checked [switch_t as per cal_switch_ext.h]
                    AKT_STATUS : Current status of switch [TRUE, FALSE]
                    CYCLE_TIMER : Timer of switch cycle [0u ... switch_cycletimer_init]
  @param[in]       StartCondition : Condition that allows the switch to be switched on [TRUE, FALSE]
  @param[in]       HoldCondition : Condition that allows the switch to send repeated signals after has been switched on [TRUE, FALSE]
  @param[in]       StartTime : Time, the switch needs to be in "on"-state before it returns true for the first time [0u ... 60000u] ms
  @param[in]       RepeatTime : Time, between the repeated signals after the switch has returned true the first time 
                                (if 0 -> function returns only one true after start time) [0u ... 60000u] ms

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-572-0009fc80">CAL_572</a> \n

*************************************************************************************************************************/
switch_state_t SWITCH_HOLD_REPEAT(switch_t * const pSwitch, const boolean StartCondition, const boolean HoldCondition, uint16 StartTime, uint16 RepeatTime)
{
  switch_state_t retValue = SWITCH_STATE_OFF;

  if(
     (pSwitch->AKT_STATUS == FALSE)  /*switch off*/
     ||
     ((HoldCondition == FALSE) && (pSwitch->CYCLE_TIMER != switch_cycletimer_init))
     ||
     (StartCondition != TRUE)       /*not all conditions true*/
    )
  {
    /*init cycle timer*/
    pSwitch->CYCLE_TIMER = switch_cycletimer_init;
  }
  else    /*button pressed with all conditions met*/
  {
    const switch_state_t StartOK = SWITCH_RISING_EDGE(pSwitch, StartCondition);

    if(
       (pSwitch->CYCLE_TIMER == switch_cycletimer_init) /*cycle timer not initialized*/
       &&
       (StartOK == SWITCH_STATE_ON)              /*start conditions true*/
      )
    { /*initialize cycle with startTime*/
      pSwitch->CYCLE_TIMER = (uint16) MIN(switch_cycletimer_init - 1, (sint32)StartTime);
    }
    else
    {
      if(
         (pSwitch->CYCLE_TIMER > (uint16)0) /*cycle timer > 0*/
         && 
         (pSwitch->CYCLE_TIMER < switch_cycletimer_init) /*cycle timer is initialized*//* PRQA S 1862
          date: 28/06/2019 author: Pruthvi Reason: Can be ignored as no functional impact */
         &&
         (HoldCondition == TRUE) /*hold condition true*/
        )
      {
        pSwitch->CYCLE_TIMER--; /*decrease cycle timer*/
      }

      if(pSwitch->CYCLE_TIMER == (uint16)0) /*cycle timer 0ed*/
      { /*initialize cycle timer with repeat time*/
        pSwitch->CYCLE_TIMER = (uint16) MIN(switch_cycletimer_init - 1, (sint32)RepeatTime); 
        if(pSwitch->CYCLE_TIMER == (uint16)0)
        {
          pSwitch->CYCLE_TIMER = switch_cycletimer_init; /*reinitialize cycle timer (returns only one true after start time if repeattime=0)*/
        }
        retValue = SWITCH_STATE_ON;
      }
    }
  }
  return retValue;
}


/*************************************************************************************************************************
  Functionname:    SWITCH_SET_COND_COUNTER                                                                          */ /*!

  @brief           Counter decrement based on condition

  @description     Decreases a counter until it is 0 in a specific condition, otherwise the counter will be reseted. 
                   if the system is not engaged, the counter will be set to 0.

                    @startuml
                    Start
                    Partition SWITCH_SET_COND_COUNTER {

                    If (** IS the condition to decrement timer is satisfied ?**) then
                      If (**Is the function selected not active ?**) then (yes)
                        : counter for the selected function is reset;
                      Else (no)
                            : counter for selected function is decremented each cycle by decrement \n  stepvalue until counter is more than decrement step value;
                      endif
                    Else (no)
                      : counter for selected function is set to Initvalue;
                    Endif
                    }
                    Stop
                    @enduml

  @return          void

  @param[in]       Condition : Condition to test if counter should be decremented [TRUE, FALSE]
  @param[in]       InitValue : An initialization value, the Counter will be set to, if the condition is false [full range of uint16]
  @param[in]       DecValue : Decrement value the counter will be decremented with if condition is true [full range of uint16]
  @param[in,out]   pCounter : A pointer to a counter with pointer content [full range of uint16]
  @param[in]       SelectedFunctionActive : Condition, which if FALSE, resets the counter to 0 [TRUE, FALSE]

  @glob_in         No global input variable used
  @glob_out        No global output variable used

  @c_switch_part   - 
  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-573-0009fc80">CAL_573</a> \n

*************************************************************************************************************************/
void SWITCH_SET_COND_COUNTER(const boolean Condition, const uint16 InitValue, const uint16 DecValue, uint16 * const pCounter, const boolean SelectedFunctionActive)
{
  if (Condition == TRUE)
  {
    if(SelectedFunctionActive == FALSE)
    {
      (*pCounter) = (uint16)0;
    }
    else
    {
      if((*pCounter) > DecValue)
      {
        (*pCounter) = (uint16)(*pCounter - DecValue);
      }
      else
      {
        (*pCounter) = (uint16)0;
      }
    }
  }
  else
  {
    (*pCounter) = InitValue;
  }
}

/*************************************************************************************************************************
  Functionname:    SWITCH_SET_COUNTER                                                                               */ /*!

  @brief           decreases a counter until it is 0, the counter will not be reseted

  @description     decreases a counter until it is 0, the counter will not be reseted.

                    @startuml
                    Start
                    Partition SWITCH_SET_COUNTER {

                    If (**Is the counter more than or equal to decrement step value ?**) then (yes) 
                      : decrement the counter by the decrement step value;
                    Else (no)
                      : counter is reset;
                    Endif
                    }
                    Stop
                    @enduml

  @return          void

  @param[in]       DecValue :  the decrement value the counter will be decremented with [full range of uint16]
  @param[in,out]   pCounter : a pointer to a counter with its content [uint16]

  @c_switch_full   FCT_CFG_ACC_CAL : FCT Support for common ACC Library
  @c_switch_full   FCT_CFG_BUTTON_SWITCH_EVALUATION : Configuration switch for usage of switch function library

  @pre             None
  @post            None

  @InOutCorrelation   None

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis). \n
                   Test of run time error/warnings (Static code analysis).

  @traceability    <a href="doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-574-0009fc80">CAL_574</a> \n

*************************************************************************************************************************/
void SWITCH_SET_COUNTER(const uint16 DecValue, uint16 * const pCounter)
{
  if((*pCounter) >= DecValue)
  {
    (*pCounter) = (uint16)(*pCounter - DecValue);
  }
  else
  {
    (*pCounter) = (uint16)0;
  }
}

#endif /* (FCT_CFG_ACC_CAL) && (FCT_CFG_BUTTON_SWITCH_EVALUATION) */

