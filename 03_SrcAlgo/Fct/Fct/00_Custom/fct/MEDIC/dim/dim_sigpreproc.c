/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_sigpreproc.c

DESCRIPTION:               Pre conditioning of dim input signals

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/06/14 02:09:06CEST $

VERSION:                   $Revision: 1.22 $

LEGACY VERSION:            1.1.1.6

**************************************************************************** */
/**
@defgroup dim_sigpreproc DIM_SIGPREPROC
  
@ingroup Medic_dim
@{ **/

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

#if (MEDIC_CFG_DRIVER_INTENTION_MONITORING)
#if (DIM_CFG_IN_PREPROC)

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
static void    DimDifferentiatorInit(DimIirFilt_t *pFilt);
static boolean DimDifferentiatorRun(float32 *fOutValue, float32 fInValue, float32 fCycleTime, DimIirFilt_t *pFilt);

/*************************************************************************************************************************
  Functionname:        DimDifferentiatorInit                                                                          */ /*!

  @brief               DIM differentiator initialization 

  @description         Initializes the differentiator values to default values. This is generally done during
                       the initialization of DIM module.
                       @startuml
                       Start
                       :reset the counter for \nnumber of input values;
                       :reset the input value buffer;
                       :reset the cycle time buffer;
                       Stop
                       @enduml

  @return              void

  @param[in]           pFilt :   The static DIM differentiator 
     
  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING,DIM_CFG_IN_PREPROC   

  @pre                 None 
  @post                None

  @InOutCorrelation    Not defined
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        Design Decision
  
  @author              Amr Abdelsabour | Amr Abdelsabour@continental-corporation.com  
*************************************************************************************************************************/
static void DimDifferentiatorInit(DimIirFilt_t *pFilt)
{
  pFilt->uiValues = 0u;

  pFilt->fInputs[2] = 0.0f;
  pFilt->fInputs[1] = 0.0f;
  pFilt->fInputs[0] = 0.0f;

  pFilt->fCycleTimes[0] = 0.0f;
  pFilt->fCycleTimes[1] = 0.0f;
}

/*************************************************************************************************************************
  Functionname:        DimDifferentiatorRun                                                                          */ /*!

  @brief               DIM differentiator function  

  @description         Main function for calculating the differentiation of DIM signals. This function considers the inputs 
                       for 2 consecutive cycles, calculates the delta change in value and time and find out the dx/dt form
                       of differential input. 
                       @startuml
                       Start
                       If (no samples to consider?) then (yes)
                       :diff time t=0,\ndifferential output 0;
                       Elseif (1 sample available?) then (yes)
                       :diff time t=cycle time;
                       :diff value=input sample-immediate previous sample;
                       Elseif (2 samples available?) then (yes)
                       :diff time t=current cycle time+previous cycle time;
                       :diff value=current input sample-immediate previous sample;
                       Else (no)
                       :diff time t=current cycle time+previous 2 cycle times;
                       :diff value= current input sample-immediate previous sample;
                       Endif
                       If(dt is valid, > 0.0001?) then (yes)
                       :diffout=diff value/diff time;
                       Else (no)
                       :diff out is 0;
                       Endif
                       :store the values available till this cycle;
                       :store the time elapsed in each cycle;
                       If(number of values are less then 3?) then (yes)
                       :accommodate next samples;
                       Else (no)
                       :not more than 3 samples to be considered;
                       Endif
                       :return diff output;
                       Stop
                       @enduml

          
  @return              retValid   : A boolean indicating the validity of the calculated output [0:Invalid , 1: Valid]

  @param[in,out]       fOutValue  : The differentiated output signal
  @param[in]           fInValue   : The input signal to be differentiated
  @param[in]           fCycleTime : The function cycle time
  @param[in,out]       pFilt      : The static differentiator structure
     
  @glob_in             None 
  @glob_out            None

  @c_switch_part       None
  @c_switch_full       MEDIC_CFG_DRIVER_INTENTION_MONITORING,DIM_CFG_IN_PREPROC   

  @pre                 None
  @post                None

  @InOutCorrelation    output = d(value)/d(time)
  
  @testmethod          Test of output data (dynamic module test)  

  @traceability        Design Decision
  
  @author              Amr Abdelsabour | Amr Abdelsabour@continental-corporation.com  
*************************************************************************************************************************/
static boolean DimDifferentiatorRun(float32 *fOutValue, float32 fInValue, float32 fCycleTime, DimIirFilt_t *pFilt)
{
  boolean retValid;       /* Indicator of output validity */
  float32 diffTime;       /* difference in time (dt)      */
  float32 diffValue;      /* difference in value (dx)     */

  
  if (pFilt->uiValues == 0uL)
  {
    /* At t == 0 the output shall be equal to zero  */
    diffTime  = fCycleTime;
    diffValue = 0.0f;
  }
  else if (pFilt->uiValues == 1uL)
  {
    /* At t == dt, only 1 previous input value is considered */
    diffTime  = fCycleTime;
    diffValue = fInValue - pFilt->fInputs[0];
  }
  else if (pFilt->uiValues == 2uL)
  {
    /* At t == 2dt, 2 previous input values shall be considered */
    diffTime  = pFilt->fCycleTimes[0] + fCycleTime;
    diffValue = fInValue - pFilt->fInputs[1];
  }
  else 
  {
    /* At t >= 3dt, 3 previous input values shall be considered */
    diffTime = pFilt->fCycleTimes[1] + pFilt->fCycleTimes[0] + fCycleTime;  
    diffValue = fInValue - pFilt->fInputs[2];
  }


  /* Determining the validity of the output and accordingly calculating the output value */
  if (diffTime > C_F32_DELTA)
  {
    *fOutValue = diffValue / diffTime;
    retValid = b_TRUE;
  }
  else
  {
    *fOutValue = 0.0f;
    retValid = b_FALSE;
  }

  /* Storage of the previous input values to be used in later calculations */
  pFilt->fInputs[2] = pFilt->fInputs[1];
  pFilt->fInputs[1] = pFilt->fInputs[0];
  pFilt->fInputs[0] = fInValue;

  /* Storage of the previous cycle times to be used in later calculations */
  pFilt->fCycleTimes[1] = pFilt->fCycleTimes[0];      
  pFilt->fCycleTimes[0] = fCycleTime;

  /* Counter function of the values to be calculated. After t==3dt, no more additional values need to be considered */
  if (pFilt->uiValues < 3U)
  {
    pFilt->uiValues++;
  }

  return retValid;
}

/*************************************************************************************************************************
  Functionname:         DIMInitSigPreProc                                                                        */ /*!

  @brief                DIM-Preprocessing initialization 

  @description          Triggers the initialization of differentiator.

                        @startuml
                        Start
                        :Initialization of the DIM differentiator;
                         Note left 
                          Initializes the previous input samples and previous cycle time samples 
                          (which is used to validate the steering wheel gradient) to zero
                         End note
                        stop
                        @enduml
          
  @return               Void

  @param[in]            Void

  @glob_in              None
  @glob_out             @ref MEDIC_p_GetDimIirFiltSteeringAngle()
                        @ref MEDIC_p_GetDimIirFiltGasPedal()

  @c_switch_part        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT \n
                        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     Not defined
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Amr Abdelsabour | Amr.Abdelsabour@continental-corporation.com
*************************************************************************************************************************/
void DIMInitSigPreProc(void)
{
  /* Initilization of the differentiators */
  #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
  DimDifferentiatorInit(MEDIC_p_GetDimIirFiltSteeringAngle());
  #endif

  #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
  DimDifferentiatorInit(MEDIC_p_GetDimIirFiltGasPedal());
  #endif
}

/*************************************************************************************************************************
  Functionname:         DIMRunSigPreProc                                                      */ /*!

  @brief                DIM-Preprocessing main function

  @description          Main function for the preprocessing of DIM signals. This is mainly used for calculating the
                        gradient values of various signals using the differentiator by measuring the signal values for 
                        consecutive cycles.

                        @startuml
                        Start
                        if (Check signal quality of the steering wheel angle?) then (Ok)
                         :Calculate steering wheel gradient\nfrom steering wheel angle;
                        else (NotOk)
                         :Steering wheel gradient is not valid;
                        Endif
                        if (Is the Steering Wheel Gradient valid?) then (yes)
                         :Set the Signal quality of steering \nwheel gradient as Ok;
                        else (no)
                            if (ReCheck the signal quality of the steering wheel Angle?) then (NotOk)
                                :Set the Signal quality of steering \nwheel gradient as Corresponds \nto Steering Wheel angle;
                            Else (Ok)
                                :Set the Signal quality of steering \nwheel gradient as Missing;
                            Endif
                         :Reinitialize DIM Differentiator;
                          Note right: Reinitialize DIM Differentiator due to invalid gradient
                        Endif
                        if (Gas pedal position sig quality ok?) then (Ok)
                         :Calculate gas pedal gradient\nfrom gas pedal position;
                        else (NotOk)
                         :gas pedal gradient is not valid;
                        Endif
                        if (Is gas pedal Gradient valid?) then (yes)
                         :Set the Signal quality of\gaspedal gradient as Ok;
                        else (no)
                            if (ReCheck the signal quality of the gaspedal pos?) then (NotOk)
                                :Set the Signal quality of\ngaspedal gradient as Corresponds \nto gaspedal pos;
                            Else (Ok)
                                :Set the Signal quality of\ngaspedal gradient as Missing;
                            Endif
                         :Reinitialize DIM Differentiator;
                          Note right: Reinitialize DIM Differentiator due to invalid gradient
                        Endif
                        stop
                        @enduml
          
  @return               void

  @param[in]            fCycleTime : The function cycle time
  @param[in,out]        pDimInput : The pointer to the structure containing all DIM input signals

  @glob_in              @ref MEDIC_p_GetDimIirFiltSteeringAngle()
                        @ref MEDIC_p_GetDimIirFiltGasPedal()
  @glob_out             @ref MEDIC_p_GetDimIirFiltSteeringAngle()
                        @ref MEDIC_p_GetDimIirFiltGasPedal()

  @c_switch_part        @ref DIM_CFG_CALC_STEERING_ANGLE_GRADIENT \n
                        @ref DIM_CFG_CALC_GAS_PEDAL_GRADIENT
  @c_switch_full        @ref MEDIC_CFG_DRIVER_INTENTION_MONITORING \n
                        @ref DIM_CFG_IN_PREPROC

  @pre                  None  
  @post                 None

  @InOutCorrelation     Not defined

  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Amr Abdelsabour | Amr.Abdelsabour@continental-corporation.com
*************************************************************************************************************************/
void DIMRunSigPreProc(float32 fCycleTime, DIMInputDataGlobal_t *pDimInput)
{
  boolean bGradientValidity;

  #if (DIM_CFG_CALC_STEERING_ANGLE_GRADIENT)
  /* Check the validity of the pointer to DIM input structure and the signal quality of the steering wheel angle */
  if((pDimInput != NULL) && (pDimInput->SteeringWheelAngle.eSignalQuality == (uint8)DIMInputSignalState_OK))
  {
    /* Calculate the steering wheel gradient from the steering wheel angle */
    bGradientValidity = DimDifferentiatorRun(&(pDimInput->SteeringWheelGradient.uValue.fValue), pDimInput->SteeringWheelAngle.uValue.fValue, fCycleTime, MEDIC_p_GetDimIirFiltSteeringAngle());
  }
  else
  {
    /* Steering wheel gradient is not valid because of bad steering angle quality or invalid pointer to DIM input structure */
    bGradientValidity = b_FALSE;
  }

  if ((pDimInput != NULL) && (bGradientValidity == (boolean)1))
  {
    /* Gradient is valid */
    pDimInput->SteeringWheelGradient.eSignalQuality = (uint8)DIMInputSignalState_OK;
  }
  else if ((pDimInput != NULL) && (bGradientValidity == (boolean)0))/*PRQA S 2995 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  {
    if(pDimInput->SteeringWheelAngle.eSignalQuality != (uint8)DIMInputSignalState_OK)
    {
      /* Take Quality from Angle (Multiturn-loss is set to BadQuality) */
      pDimInput->SteeringWheelGradient.eSignalQuality = pDimInput->SteeringWheelAngle.eSignalQuality;
    }
    else
    {
      /* Gradient is invalid */
      pDimInput->SteeringWheelGradient.eSignalQuality = (uint8)DIMInputSignalState_Missing;
    }

    /* Reinitialize Differentiator due to invalid gradient */
    DimDifferentiatorInit(MEDIC_p_GetDimIirFiltSteeringAngle());
  }
  else
  {
    /* pointer to DIM input structure is invalid */
  }
  #endif

  #if (DIM_CFG_CALC_GAS_PEDAL_GRADIENT)
  /* Checking the validing of the pointer to DIM input structure and the signal quality of the gas pedal position */
  if((pDimInput != NULL) && (pDimInput->GasPedalPosition.eSignalQuality == (uint8)DIMInputSignalState_OK))
  {
    /* Calculating the gas pedal gradient from the gas pedal position */
    bGradientValidity = DimDifferentiatorRun(&(pDimInput->GasPedalGradient.uValue.fValue), pDimInput->GasPedalPosition.uValue.fValue, fCycleTime, MEDIC_p_GetDimIirFiltGasPedal());
  }
  else
  {
    /* gas pedal gradient is not valid because of bad gas pedal position quality or invalid pointer to DIM input structure */
    bGradientValidity = b_FALSE;
  }

  if ((pDimInput != NULL) && (bGradientValidity == (boolean)1))
  {
    /* Gradient is valid */
    pDimInput->GasPedalGradient.eSignalQuality = (uint8)DIMInputSignalState_OK;
  }
  else if ((pDimInput != NULL) && (bGradientValidity == (boolean)0))/*PRQA S 2995 #date: 2020-06-02, reviewer: Nalina M, reason: No side effect, Generic Implementation */
  {
    if(pDimInput->GasPedalGradient.eSignalQuality != (uint8)DIMInputSignalState_OK)
    {
      /* Take Quality from gaspedal pos (Multiturn-loss is set to BadQuality) */
      pDimInput->GasPedalGradient.eSignalQuality = pDimInput->GasPedalPosition.eSignalQuality;
    }
    else
    {
      /* Gradient is invalid */
      pDimInput->GasPedalGradient.eSignalQuality = (uint8)DIMInputSignalState_Missing;
    }

    /* Reinitialize Differentiator due to invalid gradient */
    DimDifferentiatorInit(MEDIC_p_GetDimIirFiltGasPedal());
  }
  else
  {
    /* pointer to DIM input structure is invalid */
  }
  #endif
}
#endif  /* DIM_CFG_IN_PREPROC                */
#endif  /* DIM enable switch */
#endif  /*   DIM 2.0 switch */

/**@}*/
