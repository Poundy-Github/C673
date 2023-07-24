/*! \file **********************************************************************
  
COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 DIM (Driver Intention Monitoring)

PACKAGENAME:               dim_mod_activity_par.h

DESCRIPTION:               header of the DIM driver activity parameters

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/03/09 11:32:29CET $

VERSION:                   $Revision: 1.7.1.6 $

LEGACY VERSION:            1.14
 
**************************************************************************** */
/**
@ingroup Medic_dim
@{ **/
#ifndef DIM_MOD_DRV_ACT_PAR_INCLUDED
#define DIM_MOD_DRV_ACT_PAR_INCLUDED

#if(MEDIC_CFG_DRIVER_INTENTION_MONITORING)
/*---- default values ----*/

/*! @brief       DIM_ACTIVITY_DEFAULT_SteeringWheelAngle 
    @typical     0.0f    */
#define DIM_ACTIVITY_DEFAULT_SteeringWheelAngle (0.0f)

/*! @brief       DIM_ACTIVITY_DEFAULT_SteeringWheelGrad 
    @typical     0.0f    */
#define DIM_ACTIVITY_DEFAULT_SteeringWheelGrad  (0.0f) /* PRQA S 0791 *//* uic45572 warning suppressed as this part of software */

/*! @brief       DIM_ACTIVITY_DEFAULT_LongVelocity 
    @typical     0.0f    */
#define DIM_ACTIVITY_DEFAULT_LongVelocity       (0.0f)

/*---- definitions ----*/
/*! @brief       DIM_ACTIVITY_PAR_NormalConfidence 
    @typical     100    */
#define DIM_ACTIVITY_PAR_NormalConfidence       (100)

/*! @brief       DIM_ACTIVITY_PAR_MissingConfidenceDelta 
    @typical     35    */
#define DIM_ACTIVITY_PAR_MissingConfidenceDelta (35)

/*! @brief       DIM_ACTIVITY_PAR_ActivePercentage 
    @typical     30    */
#define DIM_ACTIVITY_PAR_ActivePercentage   (30)  

/*! @brief       DIM_ACTIVITY_PAR_VeryActivePercentage 
    @typical     70    */
#define DIM_ACTIVITY_PAR_VeryActivePercentage   (70)  

/*! @brief       DIM_ACTIVITY_PAR_EmergenySteeringPercentage 
    @typical     100    */
#define DIM_ACTIVITY_PAR_EmergenySteeringPercentage (100)   

/*---- parameters ----*/

/*! @brief       DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS 
    @typical     2    */
#define DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS (2)

/*! @brief       DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS 
    @typical     2    */
#define DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS (2)    /* PRQA S 0791 *//* uic45572 warning suppressed as this part of software */

/*! @brief       DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS 
    @typical     2    */
#define DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS (2)  /* PRQA S 0791 *//* uic45572 warning suppressed as this part of software */

/*! @brief       DIM_ACTIVITY_PAR_FronSteerThres_POINTS 
    @typical     2    */
#define DIM_ACTIVITY_PAR_FronSteerThres_POINTS (2)

/*! @brief       DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS 
    @typical     2    */
#define DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS (2)

/* ****************************************************************
    TYPEDEF STRUCT
    **************************************************************** */
/*! @brief DIM_ACTIVITY_PAR_struct_t

    @general DIM Activity structure, refer to dim_mod_activity_par_eba.c for values of this struct.

    @conseq [ None ]

    @attention [ None ]

    */
typedef struct 
{
  /*! steering wheel angle speed threshold (degree/s) @values: float32[DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS][2]*/
  CML_t_Vector2D fSteerAngleGradLowThres[DIM_ACTIVITY_PAR_SteerAngleGradLowThres_POINTS];
  /*! steering wheel angle speed threshold (degree/s) @values: float32[DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS][2]*/
  CML_t_Vector2D fSteerAngleGradThres[DIM_ACTIVITY_PAR_SteerAngleGradThres_POINTS];
  /*! steering wheel angle speed threshold (degree/s) @values: float32[DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS][2]*/
  CML_t_Vector2D fSteerAngleGradEMThres[DIM_ACTIVITY_PAR_SteerAngleGradEMThres_POINTS]; 
  /*! steering wheel angle threshold (degree) @values: float32[DIM_ACTIVITY_PAR_FronSteerThres_POINTS][2]*/
  CML_t_Vector2D fFronSteerThres[DIM_ACTIVITY_PAR_FronSteerThres_POINTS]; 
  /*! steering wheel angle speed Filter threshold (degree/s) @values: float32[DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS][2]*/
  CML_t_Vector2D fSteeringAngleGradFilterThres[DIM_ACTIVITY_PAR_fSteeringAngleGradFilterThres_POINTS]; 
  float32 fFronSteerThresStraight;      /*!< steering wheel angle in straight position (degree)*/
  float32 fFronSteerGradThresStraight;  /*!< steering wheel position constant (degree/s)*/
  float32 fGradShutDownTime;            /*!< hold time for the hypothesis in case of a detected driver activity due to Steering Wheel Gradient*/
  float32 fGradShutDownTimeLow;         /*!< hold time for the hypothesis in case of a detected low driver activity due to Steering Wheel Gradient*/
  float32 fAngleShutDownTime;           /*!< hold time for the hypothesis in case of a detected driver activity due to Steering Wheel Angle*/
  float32 fGradHoldTime;                /*!< hold time for the probability in case of a detected driver activity due to Steering Wheel Gradient*/
  float32 fAngleHoldTime;               /*!< hold time for the probability in case of a detected driver activity due to Steering Wheel Angle*/
  float32 fGradShutDownTimeEM;          /*!< hold time for the hypothesis in case of a detected emergency steering situation*/
  float32 fGradPeakTime;                /*!< time for which the Steering Wheel Gradient must be over the threshold to sincrease the driver activity (Stabilize DIM against short gradient peak)*/
  float32 fSteeringGradFiltHoldTime;    /*!< hold time for the hypothesis in case of a detected dynamic steering anctions*/
  float32 fFilterFactorSteeringGrad;    /*!< The factor of the low pass filter on the Steering Wheel Gradient */
} DIM_ACTIVITY_PAR_struct_t;


#endif
#endif /*_DIM_MOD_DRV_ACT_PAR_INCLUDED*/
/**@}*/ /* PRQA S 0791,0914*/

