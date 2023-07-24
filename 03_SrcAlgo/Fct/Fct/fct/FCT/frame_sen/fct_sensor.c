/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCT 

MODULNAME:                 fct_sensor.c

DESCRIPTION:               Sensor specific processing

AUTHOR:                    Gergely Ungvary

CREATION DATE:             30.06.2010

VERSION:                   $Revision: 1.4 $

LEGACY VERSION:            Revision 1.17

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "fct_sen.h"//PRQA S 0380 
/* date: 2019-06-28, reviewer: Prabhu Sundaramurthy, reason: This does not effect the functionality*/
#include "fct_par.h"
/*********************************************************************************/
/**
@defgroup fct_sensor Fct_sensor
@ingroup frame_sen
@{
*/
#if (FCT_CFG_SENSOR_CONTROL_INTF)


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/

static boolean FCTSetPowerReduction(void);
static float32 FCTCalcReqRangeGateLength(const boolean bRoadbeamActive);

/*****************************************************************************
  MODULE GLOBAL VARIABLES
*****************************************************************************/

/*****************************************************************************
  MODULE LOCAL SYMBOLIC CONSTANTS
*****************************************************************************/

#ifndef FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL
# pragma COMPILEMSG("New configuration switch FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL not set : defaulting to ON!")
# define FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL 1
#endif

/*****************************************************************************
  MODULE LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  MODULE LOCAL TYPES
*****************************************************************************/

typedef enum
{
  RES_STATE_LOW,
  RES_STATE_HIGH,
  RES_STATE_INTER
} FCTRangeGateLengthState_t;

/*****************************************************************************
  MODULE LOCAL CONSTANTS
*****************************************************************************/

#if (!FCT_CFG_RANGE_GATE_RES_REL_OBJ_DEP)
#define RES_STATE_VELOCITY_HIGHRES     (10.0f/C_KMH_MS)
#define RES_STATE_VELOCITY_LOWRES      (15.0f/C_KMH_MS)
#else
#define EMRANGEGATEVREL        (36.0F/C_KMH_MS) /* 36 kph */ /*! @todo: hysteresis values for this parameter */
#define EMRANGEGATEVEGO        (40.0F/C_KMH_MS) /* 40 kph */
#define EMRANGEGATEVEGOHYST    (2.0F/C_KMH_MS)  /*  2 kph */

#define EMNEARRANGEVEGOLOW     (13.5F) /* 13.5m */
#define EMNEARRANGEVEGOHIGH    (8.0F) /* 8m */
#define EMNEARRANGEHYST        (2.0F) /* 2m */
#define EMCREEPINGVELO         (4.0F/C_KMH_MS) /* 4kph  */
#define EMCREEPINGVELOHYST     (1.0F/C_KMH_MS) /* 1kph  */
#define EMFOLLOWOBJECTSPEED    (10.0F/C_KMH_MS)/* 10kph */
#define EMTAILGATINGRANGEVEGOLOW  (11.0F) /* 4m */
#define EMTAILGATINGRANGEVEGOHIGH (4.0F) /* 4m */
#define EMTAILGATINGRANGEHYST  (1.0F) /* 1m */
#endif

#define FCT_RGLENGTH_RESOLUTION_LOW     1.f
#define FCT_RGLENGTH_RESOLUTION_INTER   0.5f
#define FCT_RGLENGTH_RESOLUTION_HIGH    0.25f

/*****************************************************************************
  MODULE LOCAL VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(FCTRgLenState)
static FCTRangeGateLengthState_t FCTRgLenState;

/*************************************************************************************************************************
  Functionname:    FCTSetPowerReduction                                                                             */ /*!

  @brief           sets PowerReduction flag for  RHC

  @description     The function should set the PowerReduction flag for RHC
                   in case the vehicle is in standstill and also no automatic
                   drive off can take place
                   Note: when stand-still state not OK, then at default no
                   power reduction is performed

                   @startuml 
                     Start
                     Partition  FCTSetPowerReduction
                     -   sets PowerReduction flag for  RHC
                     floating note : Activate PowerReduction if vehicle is in secure standstill and driver has to confirm drive off
                     If(EGO_MOTION_STATE_RAW is equal to VDY_LONG_MOT_STATE_STDST AND IS_SIGNAL_STATUS_OK(EGO_MOTION_STATE_STATE ) then (true)	
                       If(EGO_MOTION_STATE_RAW is equal to VDY_LONG_MOT_STATE_STDST AND IS_SIGNAL_STATUS_OK(EGO_MOTION_STATE_STATE ) then (true)	
                         - Custom I/O interface available
                       Else (False)
                         - Custom I/O interface not available	
                       Endif
                     Else (False)
                       - PowerReduction = FALSE	
                     Endif
                     If(PowerReduction is not zero) then (true)	
                       If(StandStillTime is less than  FCT_PAR_SENSOR_POWER_REDUCTION_DELAY_MS ) then (true)	
                         - Update StandStillTime milisecond counter
                       Else (False)
                         - Reset standstill-time, so that next stop (when power-reduction conditions satisfied, we start counting over again)	
                       Endif
                    Else (False)
                      - Do Nothing
                    Endif
                       - This function returns TRUE if power reduction allowed by FCT, FALSE otherwise
                  End
                 @enduml


  @return          static boolean PowerReduction : TRUE if power reduction allowed by FCT, FALSE otherwise                   [TRUE, FALSE]

  @param[in]       -

  @glob_in         IS_SIGNAL_STATUS_OK : checks the status of signal as defined in frame_sen_custom_types.h                                                      [TRUE, FALSE]
  @glob_in         FCTSEN_pCustomInput->sLongControlStatus.eLongControlStatus : Type definition for the longitudional control status as defined in Rte_Type.h    [0 ... 3]

  @glob_out        -

  @c_switch_part   FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL : Configuration switch enabling power reduction in stand-still as defined in fct_config.h
  @c_switch_part   FCT_CFG_CUSTOM_IO_INTERFACE : FCT custom I/O interface as defined in fct_config.h
  @c_switch_part   FCT_CFG_CUSTOM_IO_LONG_CTRL_STATUS : Configuration switch enabling processing of longitudinal control status within FCT custom 
                                                        I/O interface (enabled over FCT_CFG_CUSTOM_IO_INTERFACE) as defined in fct_config.h

  @c_switch_full   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/22/2016

  @author          Thomas Kleintje | Thomas.Kleintje@continental-corporation.com | 
*************************************************************************************************************************/
static boolean FCTSetPowerReduction(void)
{
  /*Standstill logic*/
  boolean PowerReduction = FALSE;
#if (FCT_CFG_ENABLE_POWER_REDUCTION_IN_STANDSTILL)

#if (FCT_PAR_SENSOR_POWER_REDUCTION_DELAY_MS > 0)
  /*! Milisecond counter for power reduction activation delay @unit:ms */
  static uint16 StandStillTime;
#endif

  /*Activate PowerReduction if vehicle is in secure standstill and driver has to confirm drive off*/
  if ((EGO_MOTION_STATE_RAW ==  VDY_LONG_MOT_STATE_STDST) && (IS_SIGNAL_STATUS_OK(EGO_MOTION_STATE_STATE)))
  {
#if ((FCT_CFG_CUSTOM_IO_INTERFACE) && (FCT_CFG_CUSTOM_IO_LONG_CTRL_STATUS))
    /* Custom I/O interface available: check what the longitudinal control status is */
    const eLongControlStatus_t FSRFunctionStatus = FCTSEN_pCustomInput->sLongControlStatus.eLongControlStatus; 

    switch(FSRFunctionStatus)
    {
    case FSRFunctionInit:         PowerReduction = TRUE;  break;
    case FSRFunctionDisabled:     PowerReduction = TRUE;  break;
    case FSRFunctionEnabledHold:  PowerReduction = TRUE;  break;
    case FSRFunctionEnabled:      PowerReduction = FALSE; break;
    default:                      PowerReduction = TRUE;  break;
    }
#else
    /* Custom I/O interface not available: directly enter power reduction */
    PowerReduction = TRUE;
#endif
  }
  else
  {
    PowerReduction = FALSE;
  }

  /* If power reduction entry delay time configured, then handle delay timer */
#if (FCT_PAR_SENSOR_POWER_REDUCTION_DELAY_MS > 0)
  /* If previous basic logic decided that power reduction shall be enabled,
  then check if the delay timing requirement is already satisifed. While not
  so, keep power-reduction suppressed */
  if (PowerReduction)
  {
    /* FSR ACC function not active, start counting with timer */
    if (StandStillTime < FCT_PAR_SENSOR_POWER_REDUCTION_DELAY_MS)
    {
      PowerReduction = FALSE;
      /* Update StandStillTime milisecond counter */
      StandStillTime += (uint16)ROUND_TO_UINT(FCT_CYCLE_TIME*1000.f);
    }
  }
  else
  {
    /* Reset standstill-time, so that next stop (when power-reduction conditions
    satisfied, we start counting over again) */
    StandStillTime = 0;
  }
#endif

#endif

  return PowerReduction;
}

/*************************************************************************************************************************
  Functionname:    FCTCalcReqRangeGateLength                                                                        */ /*!

  @brief           Calculate range gate length requested by FCT

  @description     This function returns the desired range gate length of FCT

                    @startuml 
                      Start
                          Partition  FCTCalcReqRangeGateLength
                          -   Calculate range gate length requested by FCT
                          floating note : yes
                          If(vehicle speed is invalid ) then (true)		
                              - set RGLength to 1.0 m
                          Else (False)
                             - normal mode when speed is available	
                          Endif
                          If(If relative speed exceeds threshold) then (true)		
                              - ignore it
                          Endif
                          If(  value of FCTRgLenState is equal to RES_STATE_LOW) then (true)
                          floating note :	this is the state with 1m Range gate length
                              - Assign RGLength to RES_STATE_HIGH
                             If(  fVehicleVelocity < (EMCREEPINGVELO - EMCREEPINGVELOHYST)) then (true)
                             floating note : this condition has got the highest priority: v < thr								
                                - transit into state with 0.25m Range gate length		
                              Elseif(iRelObj >= 0)
                                 floating note : there is a relevant object in close range	
                               If (fVehicleVelocity >= (EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST) then (true)
                                  If (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMNEARRANGEVEGOHIGH - EMNEARRANGEHYST) then (true)
                                      - transit into state with 0.5m Range gate length
                                   Endif
                                Else (False)
                                   If (Speed is less then EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST) then (true)
                                      - transit into state with 0.5m Range gate length
                                   Endif
                                Endif
                              Else 
                                - Do Nothing
                              Endif
                            Elseif(  value of FCTRgLenState is equal to RES_STATE_HIGH) then (true)
                              floating note :	this is the state with 0.25m Range gate length
                                - Assign RGLength to 0.25m
                                 if(iRelObj < 0)
                                     If(  fVehicleVelocity > (EMCREEPINGVELO - EMCREEPINGVELOHYST)) then (true)
                                     floating note : vehicle speed increases
                                       - transit into state with 1m Range gate length
                                     Else 
                                       - Do Nothing
                                      Endif

                                  Endif

                              Elseif(  value of FCTRgLenState is equal to RES_STATE_INTER) then (true)
                              floating note :this is the state with 0.5m Range gate length
                                - Assign RGLength to 0.5m
                                 If(  fVehicleVelocity < (EMCREEPINGVELO - EMCREEPINGVELOHYST)) then (true)
                                 floating note : this condition has got the highest priority: v < thr
                                   - transit into state with 0.25m Range gate length
                                 Elseif(iRelObj >= 0)
                                 floating note : there is a relevant object in close range	
                                    If (fVehicleVelocity >= (EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST) then (true)
                                      If (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMNEARRANGEVEGOHIGH - EMNEARRANGEHYST) then (true)
                                        - transit into state with 0.5m Range gate length
                                      Endif
                                    Else (False)
                                      If (Speed is less then EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST) then (true)
                                        - transit into state with 0.5m Range gate length
                                      Endif
                                    Endif
                                  Else 
                                    - Do Nothing
                                  Endif
                                 Else
                                  floating note : default is always 1m Range gate length
                                    - Assign RGLength to 1.0m
                                 Endif
                             If(FCTRgLenState != RES_STATE_LOW) then (true)
                             floating note : if actual state is high
                               If(fVehicleVelocity is greater than 15.0f/C_KMH_MS) then (true)	
                                 floating note : if velocity is above threshold, switch to low
                                 -  Assign RGLength to 1.0m
                               Else (False)
                                 - stay in state high	
                               Endif
                             Else (False)
                             floating note : if actual state is Low
                                If(fVehicleVelocity is Less than 10.0f/C_KMH_MS) then (true)	
                                floating note : if velocity is above threshold, switch to High
                                  -  Assign RGLength to 0.5m
                                Else (False)
                                  - stay in state Low	
                                Endif
                             Endif
                             If(If operation mode is end-of-line or roadbeam is active, then overrule previously set range gate length) then (true)	
                                -  set it to high resolution
                             Endif
                              - This function returns the desired range gate length of FCTotherwise
                        End
                       @enduml  


  @return          static float32 : Requested range gate length                                                                [-PI/2*RW_FCT_MAX ... PI/2*RW_FCT_MAX] m

  @param[in]       bRoadbeamActive : Is Road beam active                                                                       [TRUE, FALSE]

  @glob_in         IS_SIGNAL_STATUS_OK : checks the status of signal as defined in frame_sen_custom_types.h                    [TRUE, FALSE]
  @glob_in         EGO_SPEED_X_STATE : Get Ego speed state in longitudinal direction as defined in frame_sen_custom_types.h    [VDY_IO_STATE_VALID=0,VDY_IO_STATE_SUBSTITUE=4,VDY_IO_STATE_INIT=15,VDY_IO_STATE_DECREASED=3,VDY_IO_STATE_INVALID=1,VDY_IO_STATE_NOTAVAIL=2,VDY_IO_STATE_INPLAUSIBLE=5,VDY_IO_STATE_MAX=255]
  @glob_in         OBJ_GET_RELEVANT_OBJ_NR : Get relevant objects index from OOI list as defined in fct_sen.h                  [0 ... 40]
  @glob_in         OBJ_LONG_VREL(t_ObjNrRel) : Longidudinal relative velocity for the given object                             [-330.f ... 330.f] m/s
  @glob_in         FCTRgLenState : Enum of type FCTRangeGateLengthState_t as defined in fct_sensor.c                           [RES_STATE_LOW, RES_STATE_HIGH, RES_STATE_INTER]
  @glob_in         OBJ_LONG_DISPLACEMENT : Macro to get longitudinal distance of given object                                  [-5*RW_FCT_MAX ... 5*RW_FCT_MAX] m

  @glob_out        -

  @c_switch_part   FCT_CFG_RANGE_GATE_RES_REL_OBJ_DEP : Configuration switch enabling range gate resolution setting based on relevant object. 
                    Note: if disabled (0), then range get resolution is determined based on ego speed as defined in fct_config.h
  @c_switch_full   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/15/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
static float32 FCTCalcReqRangeGateLength(const boolean bRoadbeamActive)
{
  float32 fReqRgLen;

  /* if vehicle speed is invalid, set RGLength to 1.0 m */
  if ( !IS_SIGNAL_STATUS_OK(EGO_SPEED_X_STATE))
  {
    fReqRgLen = FCT_RGLENGTH_RESOLUTION_LOW;
  }
  else
  {
    /* normal mode when speed is available */
    const float32 fVehicleVelocity = EGO_SPEED_X_CORRECTED;

#if (FCT_CFG_RANGE_GATE_RES_REL_OBJ_DEP)
    /* Get relevant object ID */
    ObjNumber_t iRelObj = OBJ_GET_RELEVANT_OBJ_NR;

    /* If relative speed exceeds threshold, then ignore it */
    if(iRelObj > OBJ_INDEX_NO_OBJECT)
    {
      if (fABS( OBJ_LONG_VREL(iRelObj)) >= EMRANGEGATEVREL)
      {
        iRelObj = OBJ_INDEX_NO_OBJECT;
      }
    }

    switch (FCTRgLenState)
    {
    /* EMRequRgLengthState */
    case RES_STATE_LOW: /* this is the state with 1m Range gate length */
      fReqRgLen = FCT_RGLENGTH_RESOLUTION_LOW; /* this determines the RGLength of 1m */

      /* ego is slower than 3kph */
      /* this condition has got the highest priority: v < thr */
      if (fVehicleVelocity < (EMCREEPINGVELO - EMCREEPINGVELOHYST))
      {
        FCTRgLenState = RES_STATE_HIGH; /* transit into state with 0.25m Range gate length */
      }
      /* there is a relevant object in close range */
      else if (iRelObj >= 0)
      {
        if (fVehicleVelocity >= (EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST))
        {
          if (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMNEARRANGEVEGOHIGH - EMNEARRANGEHYST))
          {
            FCTRgLenState = RES_STATE_INTER; /* transit into state with 0.5m Range gate length */
          }
        }
        else
        {
          /* Speed is less then EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST */
          if (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMNEARRANGEVEGOLOW - EMNEARRANGEHYST))
          {
            FCTRgLenState = RES_STATE_INTER; /* transit into state with 0.5m Range gate length */
          }
        }
      }
      /* there is NO relevant object in close range */
      else 
      {
        ; /* do nothing */
      }
      break;

    /* EMRequRgLengthState */
    case RES_STATE_HIGH: /* this is the state with 0.25m Range gate length */
      fReqRgLen = FCT_RGLENGTH_RESOLUTION_HIGH; /* this determines the RGLength of 0.25m */

      if (iRelObj < 0) /* there is NO relevant object */
      {
        if (fVehicleVelocity > (EMCREEPINGVELO + EMCREEPINGVELOHYST)) /* vehicle speed increases */
        {
          FCTRgLenState = RES_STATE_LOW; /* transit into state with 1m Range gate length */
        }
        else /* vehicle speed does NOT increase */
        {
          ; /* do nothing */
        }
      }
      /* there is a relevant object */
      else if (  (fVehicleVelocity > EMFOLLOWOBJECTSPEED)  /* no longer creeping behind relevant object */
              && (  ( (fVehicleVelocity >= (EMRANGEGATEVEGO + EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) > (EMTAILGATINGRANGEVEGOHIGH + EMTAILGATINGRANGEHYST))) /* AND relevant object is no longer in tailgating range */
                 || ( (fVehicleVelocity <  (EMRANGEGATEVEGO + EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) > (EMTAILGATINGRANGEVEGOLOW  + EMTAILGATINGRANGEHYST))))) /* AND relevant object is no longer in tailgating range */
      {
        FCTRgLenState = RES_STATE_INTER;             /* transit into state with 0.5m Range gate length */
      }
      /* creeping behind relevant object OR relevant object is still in tailgating range */
      else 
      {
        ; /* do nothing */
      }
      break;

    /* EMRequRgLengthState */
    case RES_STATE_INTER: /* this is the state with 0.5m Range gate length */
      fReqRgLen = FCT_RGLENGTH_RESOLUTION_INTER; /* this determines the RGLength of 0.5m */

      /* this condition has got the highest priority: v < thr */
      if (fVehicleVelocity < (EMCREEPINGVELO - EMCREEPINGVELOHYST))
      {
        FCTRgLenState = RES_STATE_HIGH; /* transit into state with 0.25m Range gate length */
      }
      /* there is NO relevant object */
      else if (iRelObj < 0) 
      {
        FCTRgLenState = RES_STATE_LOW; /* transit into state with 1m Range gate length */
      }
      /* there is a relevant object */
      else if (  ( (fVehicleVelocity >= (EMRANGEGATEVEGO + EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) > (EMNEARRANGEVEGOHIGH + EMNEARRANGEHYST))) /* relevant object is NOT in near range */
              || ( (fVehicleVelocity <  (EMRANGEGATEVEGO + EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) > (EMNEARRANGEVEGOLOW  + EMNEARRANGEHYST)))) /* relevant object is NOT in near range */
      {
        FCTRgLenState = RES_STATE_LOW; /* transit into state with 1m Range gate length */
      }
      else if (  ( (fVehicleVelocity >= (EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMTAILGATINGRANGEVEGOHIGH - EMTAILGATINGRANGEHYST))) /* relevant object is in tailgating range */
              || ( (fVehicleVelocity <  (EMRANGEGATEVEGO - EMRANGEGATEVEGOHYST)) && (OBJ_LONG_DISPLACEMENT(iRelObj) < (EMTAILGATINGRANGEVEGOLOW  - EMTAILGATINGRANGEHYST))))
      {
        FCTRgLenState = RES_STATE_HIGH; /* transit into state with 0.25m Range gate length */
      }
      /* relevant object is in between tailgating range and near range  */
      else 
      {
        ; /* do nothing */
      }
      break;

    /* EMRequRgLengthState */
    default: /* default is always 1m Range gate length */
      FCTRgLenState = RES_STATE_LOW;
      fReqRgLen     = FCT_RGLENGTH_RESOLUTION_LOW;
      break;
    }      /* EMRequRgLengthState */

#else
    /* if actual state is high */
    if (FCTRgLenState != RES_STATE_LOW)
    {
      /* if velocity is above threshold, switch to low */
      if (fVehicleVelocity > RES_STATE_VELOCITY_LOWRES)
      {
        FCTRgLenState =  RES_STATE_LOW;
        fReqRgLen     = FCT_RGLENGTH_RESOLUTION_LOW;
      }
      else
      {
        /* stay in state high */
      }
    }
    /* if actual state is low */
    else
    {
      /* if velocity is beneath threshold, switch to high */
      if (fVehicleVelocity < RES_STATE_VELOCITY_HIGHRES)
      {
        FCTRgLenState =  RES_STATE_HIGH;
        fReqRgLen       = FCT_RGLENGTH_RESOLUTION_INTER;
      }
      else
      {
        /* stay in state low */
      }
    }
#endif

#if 0
    /*! determine RGLength if RSP Cycle Violation occurred */
    EMCalcRgLengthAtRSPCycVio();
#else
# pragma COMPILEMSG("Verify that RG-Length decrease for RSP cycle-violation not needed in FCT!")
#endif

  }

  /* If operation mode is end-of-line or roadbeam is active, then overrule
  previously set range gate length, and set it to high resolution */
  if ((bRoadbeamActive) || (FCTSenFrame.eFCTState == FCT_SEN_RG_HIGH))
  {
    fReqRgLen = FCT_RGLENGTH_RESOLUTION_HIGH;
  }

  return fReqRgLen;
}

/*************************************************************************************************************************
  Functionname:    FCTSensorSpecificProc                                                                            */ /*!

  @brief           Perform sensor-specific processing

  @description     This function is called after FCT processing to do any additonal sensor specific processing. Currently 
                   on ARS3xx HW this means setting the power reduction allowance flag.

  @return          -

  @param[in]       pSenErrorOut : Pointer to type FCTSenErrorOut_t which describes FCTSen error output structure as defined in Rte_Type.h
                    pSenErrorOut->bRequestRoadBeam : type of boolean, request road beam                             [TRUE, FALSE]
  @param[in,out]   pSensorCtrl : Pointer to type FCTSensorControl_t as defined in fct_types.h, no definition was found for this.
                    pSensorCtrl->uiVersionNumber : Version number
                    pSensorCtrl->ReqRgLength : Req Rg Length
                    pSensorCtrl->ReqPowerReduction : Required power reduction


  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_SENSOR_CONTROL_INTF : FCT sensor control interface as defined in fct_config.h

  @pre             -
  @post            -

  @testmethod      Test of Input-Output-Correlation (dynamic module test). \n
                   Test order of calls (dynamic module test). \n
                   Test of code coverage (dynamic module test). \n  
                   Test of QAC level 3 or above "critical" warnings (static MISRA analysis).
                   Test of run time error/warnings (Static code analysis).

  @created         -
  @changed         3/22/2016

  @author          Gergely Ungvary | Gergely.Ungvary@continental-corporation.com | 
*************************************************************************************************************************/
void FCTSensorSpecificProc(const FCTSenErrorOut_t * pSenErrorOut, FCTSensorControl_t * pSensorCtrl)
{
  pSensorCtrl->uiVersionNumber    = FCT_SENSOR_CTRL_INTFVER;
  pSensorCtrl->ReqRgLength        = FCTCalcReqRangeGateLength(pSenErrorOut->bRequestRoadBeam);
  pSensorCtrl->ReqPowerReduction  = FCTSetPowerReduction();
}

#endif    /* #if (FCT_CFG_SENSOR_CONTROL_INTF) */

/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
