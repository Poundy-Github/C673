/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_activity_par_eba.c

DESCRIPTION:               Implementation of the DIM driver activity parameters (as done for BMW)

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/14 14:43:39CEST $

VERSION:                   $Revision: 1.4.9.3 $

LEGACY VERSION:            1.11
  
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/

#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_DIM20)
#include "dim/dim_int.h"

const DIM_ACTIVITY_PAR_struct_t DIM_ACTIVITY_PAR_data_eba = 
{
/*m/s �/s*/
  /*CML_t_Vector2D fSteerAngleGradLowThres[DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS]*/
  {
    //{(5.0f/3.6f),  45.0f},
    //{(60.0f/3.6f),  20.0f}
    {(5.0f/3.6f),  100.0f},
    {(60.0f/3.6f),  100.0f}
  },
/*m/s �/s*/
  /*CML_t_Vector2D fSteerAngleGradThres[DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS]*/
  {
    // {5.0f,  200.0f},
    // {15.0f,  40.0f}
     {5.0f,  180.0f},
     {15.0f,  180.0f}
  },
/*m/s �/s*/
  /*CML_t_Vector2D fSteerAngleGradEMThres[DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS]*/
  {
    {0.0f, 1000.0f},
    {15.0f, 400.0f}
  },
/*m/s �*/
  /*CML_t_Vector2D fFronSteerThres[DIM_ACTIVITY_PAR_fFronSteerThres_POINTS]*/
  {
    //{0.0f,  120.0f},
    //{13.9f, 120.0f}
    {0.0f,  180.0f},
    {13.9f, 180.0f}
  },
/*m/s �/s*/
  /*CML_t_Vector2D fSteeringAngleGradFilterThres[DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS]*/
  {
    {(5.0f/3.6f),  45.0f},
    {(40.0f/3.6f),  23.0f}
  },
  /*fFronSteerThresStraight*/       15.0f,
  /*fFronSteerGradThresStraight*/   10.0f,
  /*fGradShutDownTime*/              2.0f,
  /*fGradShutDownTimeLow*/           1.0f,
  /*fAngleShutDownTime*/             1.0f,
  /*fGradHoldTime*/                  0.2f,           
  /*fAngleHoldTime*/                 0.2f,
  /*fGradShutDownTimeEM*/            1.0f,
  /*fGradPeakTime*/                  0.1f,
  /*fSteeringGradFiltHoldTime*/      0.1f,
  /* fFilterFactorSteeringGrad*/     0.01f
};

#endif  /* !(MEDIC_CFG_DIM20) */

/**@}*/
