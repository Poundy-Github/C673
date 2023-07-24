/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_attention_par_eba.c

DESCRIPTION:               Implementation of the DIM driver activity parameters (as done for BMW)

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/03/09 11:31:44CET $

VERSION:                   $Revision: 1.1.2.12 $

LEGACY VERSION:            1.6.1.2 

**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/

#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)

/*!  @cond Doxygen_Suppress */
const DIM_ATTENTION_PAR_struct_t DIM_ATTENTION_PAR_data_eba =
{
  /*! velocity dependent acceleration for very high attention */
  /*Accel Curve[2*Accel Curve POINTS]*/
  {  /*  m/s, m/s^2*/
     { 8.0f, 3.8f },
     {11.1f, 2.25f},
     {20.0f, 2.25f},
     {50.0f, 1.0f }
  },
  /*! velocity dependent gas pedal position for high attention*/
  /*Gas Pedal Pos Curve[2*Gas Pedal Pos Curve POINTS]*/
  { /*m/s; percent */
     {25.0f, 40.0f},
     {45.0f, 80.0f}
  },
  /*fGasPedalGradLowPositive*/         150.0f, 
  /*fGasPedalGradLowNegative*/        -180.0f,
  /*fGasPedalLowNegMeasured*/           -4.0f,
  /*fGasPedalLowNegMeasuredPos*/         1.0f,
  /*fRobotControlledVelocityThresh*/     0.6f,
  /*fNoGasPedalGradientThresh*/         15.0f,
  /*fSteeringGradLow*/                 100.0f,
  /*fVeryHighTime*/                      1.5f,
  /*fHigherTime */                       1.5f,
  /*fHighTime*/                          1.0f,
  /*fLowTime*/                           2.5f,
  /*fRobotControlledVelocityTime*/       2.0f,
  /*fNoGasPedalGradientTime*/            1.0f,
  /*fLowKeepRobotTime*/                  0.0f,
  /*fTurnIndicatorMinVelocity */   50.0f/3.6f,
  /*fBrakePedalMaxVelocity */      30.0f/3.6f,
  /*DriverBrakingMaxAcceleration*/      -0.1f
};

/*! @endcond */
#endif  /* DIM enable switch */
#endif  /* DIM20 switch */
/**@}*//* PRQA S 0791,0914*/
