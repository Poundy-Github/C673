/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC (Adaptive Cruise Control - Longitudinal Planner and Controller)

PACKAGENAME:               kmc_cart.c

DESCRIPTION:               This file contains functions concerning CARTRONIC interface definition

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.9.1.2

**************************************************************************** */

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/** 
@defgroup   kmc_cart Kmc_cart
@ingroup    kmc
@brief      KMC cartronic interface functions
@{ */ 

#include "kmc.h"


#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC))

/*************************************************************************************************************************
  Functionname:    KMC_v_InitDASInputData                                                                           */ /*!

  @brief           Initialize DAS_INPUT_DATA

  @description     Initialisation of values of inputs to DAS from LODM (i.e. structure cart_das_input_data_t)

@startUML
Start
Partition KMC_v_InitDASInputData(){
: Initialisation of values of inputs to DAS from LODMC;
		Note right
	Initialisation of values of inputs to DAS from LODMC\n
	Initialisation of Validity of Vehicle Acceleration and Speed\n
	Initialisation of ESP_actuator, TCS Actuator, ABS_actuator\n
	Initialisation of Override_acceleration and deceleration\n
	Initialisation of Accel_decel\n
	Initialisation of standstill\n
End note
}
end
@enduml

  @return          -

  @param[in,out]   das_input_data : Pointer to input from longitudinal dynamics management to driver assistance system [cart_das_input_data_t as per cart_ext.h]
                    A_INIT : Vehicle initialisation acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    BRAKE_STAT.PEDAL_INIT_TRAVEL : Boolean indicating if brake pedal is pressed [TRUE, FALSE]
                    DATA_VALID.VEHICLE_ACCEL : Boolean indicating validity of ego acceleration from LODM to DAS [TRUE, FALSE]
                    DATA_VALID.VEHICLE_SPEED : Boolean indicating validity of ego speed from LODM to DAS        [TRUE, FALSE]
                    LODM_STAT.DAS_ENABLE : Boolean enabling driver assistance systems for previous cycle        [TRUE, FALSE]
                    CHASSIS_STAT.ABS_ACT : Boolean indicating ABS active                                        [TRUE, FALSE]
                    CHASSIS_STAT.ESP_ACT : Boolean indicating ESP active                                        [TRUE, FALSE]
                    CHASSIS_STAT.TCS_ACT : Boolean indicating TCS active                                        [TRUE, FALSE]
                    CHASSIS_STAT.TCS_ESP_OFF : Boolean indicating TCS and ESP off                               [TRUE, FALSE]
                    CHASSIS_STAT.PB_ACT : Boolean, if TRUE indicates Park Brake active                          [TRUE, FALSE]
                    LODM_STAT.DC_FAIL : (Currently not used)                                                    [TRUE, FALSE]
                    LODM_STAT.DC_LIM_ACCEL : Boolean, if TRUE indicating acceleration request is limited        [TRUE, FALSE]
                    LODM_STAT.DC_LIM_DECEL : Boolean, if TRUE indicating deceleration request is limited        [TRUE, FALSE]
                    LODM_STAT.DAS_SHUTOFF_ACQ : Bit indicating DAS shutoff acknowledged by LODM                 [TRUE, FALSE]
                    LODM_STAT.BRAKE_LIGHT_REQ : Bit indicating brake light request                              [TRUE, FALSE]
                    LODM_STAT.OVERRIDE_ACCEL : Boolean indicating driver override by accelerator pedal          [TRUE, FALSE]
                    LODM_STAT.OVERRIDE_DECEL : Boolean indicating driver override by decelerator pedal          [TRUE, FALSE]
                    LODM_STAT.STANDSTILL : Boolean indicating if vehicle standstill is detected                 [TRUE, FALSE]
                    PT_STAT.CLUTCH_OPEN : Boolean, if TRUE indicates open clutch                                [TRUE, FALSE]
                    PT_STAT.KICKDOWN : Boolean, if TRUE indicates kickdown mode                                 [TRUE, FALSE]
                    VEHICLE_ACCEL : Ego longitudinal acceleration [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    VEHICLE_SPEED : Ego speed with factor Velocity_s [-30000u ... 30000u] cm/s

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-156-0008a220
*************************************************************************************************************************/
void KMC_v_InitDASInputData(cart_das_input_data_t* das_input_data)
{
  das_input_data->A_INIT = (acceleration_t)0;
  das_input_data->DATA_VALID.VEHICLE_ACCEL = FALSE;
  das_input_data->DATA_VALID.VEHICLE_SPEED = FALSE;
  das_input_data->LODM_STAT.DAS_ENABLE = TRUE;
  das_input_data->CHASSIS_STAT.ABS_ACT = FALSE;
  das_input_data->CHASSIS_STAT.ESP_ACT = FALSE;
  das_input_data->LODM_STAT.DC_FAIL = FALSE;
  das_input_data->LODM_STAT.DC_LIM_ACCEL = FALSE;
  das_input_data->LODM_STAT.DC_LIM_DECEL = FALSE;
  das_input_data->CHASSIS_STAT.TCS_ACT = FALSE;
  das_input_data->CHASSIS_STAT.TCS_ESP_OFF = FALSE;
  das_input_data->CHASSIS_STAT.PB_ACT = FALSE;
  das_input_data->LODM_STAT.DAS_SHUTOFF_ACQ = FALSE;
  das_input_data->VEHICLE_ACCEL = (acceleration_t)0;
  das_input_data->VEHICLE_SPEED = (velocity_t)0;
  das_input_data->LODM_STAT.BRAKE_LIGHT_REQ = FALSE;
  das_input_data->BRAKE_STAT.PEDAL_INIT_TRAVEL = FALSE;
  das_input_data->PT_STAT.CLUTCH_OPEN = FALSE;
  das_input_data->PT_STAT.KICKDOWN = FALSE;
  das_input_data->LODM_STAT.OVERRIDE_ACCEL = FALSE;
  das_input_data->LODM_STAT.OVERRIDE_DECEL = FALSE;
  das_input_data->LODM_STAT.STANDSTILL = FALSE;
}

/*************************************************************************************************************************
  Functionname:    KMC_v_InitDASOutputData                                                                          */ /*!

  @brief           Initialize DAS_OUTPUT_DATA

  @description     Initialisation of values of inputs to LODM from DAS (i.e. structure cart_das_output_data_t)

@startuml
Start
Partition KMC_v_InitDASOutputData(){
: Initialization of values of inputs to LODMC from DAS;
		Note right
	Initialisation of Output values\n
	Initialisation of drive off\n
	Initialisation of Engaged\n
	Initialisation of Fail_irreversible\n
	Initialisation of Driver Override\n
     Initialisation of Prefill\n
     Initialisation of Standstill\n
	Initialisation of Required Max and Min Accelleration\n
End note
}
end
@enduml


  @return          -

  @param[in,out]   das_output_data : Pointer to inputs to Longitudinal dynamics management from DAS [cart_das_output_data_t as per cart_ext.h]
                    DAS_STAT.DAS_DRIVE_OFF : Boolean indicating if driveoff is confirmed [TRUE, FALSE]
                    DAS_STAT.DAS_ENGAGED : Boolean indicating if DAS is engaged [TRUE, FALSE]
                    DAS_STAT.DAS_FAIL_IRREVERSABLE : Boolean indicating irreversible (technical) DAS failure [TRUE, FALSE]
                    DAS_STAT.DAS_FAIL_REVERSABLE : Boolean indicating reversible (customer) DAS failure [TRUE, FALSE]
                    DAS_STAT.DAS_LIM : Status bit for limiter [TRUE, FALSE]
                    DAS_STAT.DAS_OVERRIDE : Status bit for driver override [TRUE, FALSE]
                    DAS_STAT.DAS_PREFILL : Boolean indicating brake pre-fill [TRUE, FALSE]
                    DAS_STAT.DAS_STAND_STILL : Boolean output indicating if vehicle standstill is detected [TRUE, FALSE]
                    MAX_REQ_ACCEL :  Maximum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)
                    MIN_REQ_ACCEL : Minimum required acceleration output [-30000u ...+30000u] m/s2 (with factor Acceleration_s)

  @glob_in         -
  @glob_out        -

  @c_switch_part   -
  @c_switch_full   FCT_CFG_LOPC_COMPONENT : Configuration switch for enabling LOPC processing
  @traceability    doors://rbgs854a:40000/?version=2&prodID=0&view=00000002&urn=urn:telelogic::1-503e822e5ec3651e-O-155-0008a220
*************************************************************************************************************************/
void KMC_v_InitDASOutputData(cart_das_output_data_t* das_output_data)
{
  das_output_data->DAS_STAT.DAS_DRIVE_OFF = FALSE;
  das_output_data->DAS_STAT.DAS_ENGAGED = FALSE;
  das_output_data->DAS_STAT.DAS_FAIL_IRREVERSABLE = FALSE;
  das_output_data->DAS_STAT.DAS_FAIL_REVERSABLE = FALSE;
  das_output_data->DAS_STAT.DAS_LIM = FALSE;
  das_output_data->DAS_STAT.DAS_OVERRIDE = FALSE;
  das_output_data->DAS_STAT.DAS_PREFILL = FALSE;
  das_output_data->DAS_STAT.DAS_STAND_STILL = FALSE;
  das_output_data->MAX_REQ_ACCEL = (acceleration_t)0;
  das_output_data->MIN_REQ_ACCEL = (acceleration_t)0;
}

#endif  /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_KMC) */

/** @} end defgroup */
