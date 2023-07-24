/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_custom_types.h

DESCRIPTION:               Custom Types for MEDIC component

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2020/04/01 15:30:03CEST $

VERSION:                   $Revision: 1.19 $

**************************************************************************** */

#ifndef MEDIC_CUSTOM_TYPES_H_INCLUDED
#define MEDIC_CUSTOM_TYPES_H_INCLUDED

/* PRQA S 3332 EOF */ /* Reviewer: Rashmi Ramachandra, Reason:switches will be defined based on project needs and can take default values as zero*/
#if(MEDIC_CFG_EMERGENCY_BRAKE_ASSIST)
#if (MEDIC_CFG_SENSOR_TYPE_CAMERA)
/*****************************************************************************

  Ego Dynamic Data Raw (VDYN-Raw)

  In order to access any information from the ego dynamic data your component
  has to define the access macro(s):
    GET_EGO_RAW_DATA_PTR    - It shall return the pointer to the raw ego
                              dynamic data buffer
                              type: VehDyn_t *

*****************************************************************************/

/* Raw access macros */
#if (VDY_VEH_DYN_INTFVER >= 32)

/*!  brief ego vehicle velocity along X direction */
#define EGO_SPEED_X_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_VELOCITY, MEDIC_p_GetVDYDynRaw()->State)
/*!  brief ego vehicle raw velocity along X direction */
#define EGO_SPEED_X_RAW                           MEDIC_p_GetVDYDynRaw()->Longitudinal.Velocity
/*!  brief ego vehicle var raw velocity along X direction */
#define EGO_SPEED_X_VAR_RAW                       MEDIC_p_GetVDYDynRaw()->Longitudinal.varVelocity
#else
/*!  brief ego vehicle velocity along X direction */
#define EGO_SPEED_X_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_VEL, MEDIC_p_GetVDYDynRaw()->State)
/*!  brief ego vehicle raw velocity along X direction */
#define EGO_SPEED_X_RAW                           MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.Velocity
/*!  brief ego vehicle var raw velocity along X direction */
#define EGO_SPEED_X_VAR_RAW                       MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.varVelocity
#endif

/*!  brief ego vehicle acceleration along X direction */
#define EGO_ACCEL_X_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_ACCEL, MEDIC_p_GetVDYDynRaw()->State)

#if (VDY_VEH_DYN_INTFVER >= 32)
/*!  brief ego vehicle raw acceleration along X direction */
#define EGO_ACCEL_X_RAW                           MEDIC_p_GetVDYDynRaw()->Longitudinal.Accel
/*!  brief ego vehicle var raw acceleration along X direction */
#define EGO_ACCEL_X_VAR_RAW                       MEDIC_p_GetVDYDynRaw()->Longitudinal.varAccel
#else
/*!  brief ego vehicle raw acceleration along X direction */
#define EGO_ACCEL_X_RAW                           MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.Accel
/*!  brief ego vehicle var raw acceleration along X direction */
#define EGO_ACCEL_X_VAR_RAW                       MEDIC_p_GetVDYDynRaw()->Longitudinal.MotVar.varAccel
#endif

#if (VDY_VEH_DYN_INTFVER >= 32)
/*!  brief ego vehicle acceleration along Y direction */
#define EGO_ACCEL_Y_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_LATERALACCEL, MEDIC_p_GetVDYDynRaw()->State)
#else
/*!  brief ego vehicle acceleration along Y direction */
#define EGO_ACCEL_Y_STATE                         VDY_GET_IO_STATE(VDY_SOUT_POS_LATACC, MEDIC_p_GetVDYDynRaw()->State)
#endif

/*!  brief ego vehicle raw acceleration along Y direction */
#define EGO_ACCEL_Y_RAW                           MEDIC_p_GetVDYDynRaw()->Lateral.Accel.LatAccel
/*!  brief ego vehicle var raw acceleration along Y direction */
#define EGO_ACCEL_Y_VAR_RAW                       MEDIC_p_GetVDYDynRaw()->Lateral.Accel.Variance

#if (VDY_VEH_DYN_INTFVER >= 32)
/*!  brief ego vehicle yaw rate value */
#define EGO_YAW_RATE_STATE                        VDY_GET_IO_STATE(VDY_SOUT_POS_YAWRATE, MEDIC_p_GetVDYDynRaw()->State)
#else
/*!  brief ego vehicle yaw rate value */
#define EGO_YAW_RATE_STATE                        VDY_GET_IO_STATE(VDY_SOUT_POS_YWR, MEDIC_p_GetVDYDynRaw()->State)
#endif

/*!  brief ego vehicle raw yaw rate value */
#define EGO_YAW_RATE_RAW                          MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.YawRate
/*!  brief ego vehicle raw yaw rate variance value */
#define EGO_YAW_RATE_VAR_RAW                      MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.Variance
/*!  brief ego vehicle raw yaw rate quality value */
#define EGO_YAW_RATE_QUALITY_RAW                  MEDIC_p_GetVDYDynRaw()->Lateral.YawRate.Quality

/*!  brief ego vehicle curve state */
#define EGO_CURVE_STATE                           VDY_GET_IO_STATE(VDY_SOUT_POS_CURVE, MEDIC_p_GetVDYDynRaw()->State)
/*!  brief ego vehicle curve state in raw form*/
#define EGO_CURVE_RAW                             MEDIC_p_GetVDYDynRaw()->Lateral.Curve.Curve
/*!  brief ego vehicle curve state */
#define EGO_DRV_INT_CURVE_RAW                     MEDIC_p_GetVDYDynRaw()->Lateral.DrvIntCurve.Curve
/*!  brief ego vehicle motion state */
#define EGO_MOTION_STATE_RAW                      MEDIC_p_GetVDYDynRaw()->MotionState.MotState

#if (VDY_VEH_DYN_INTFVER >= 32)
/*!  brief ego vehicle motion state */
#define EGO_MOTION_STATE_STATE                    VDY_GET_IO_STATE(VDY_SOUT_POS_MOTIONSTATE, MEDIC_p_GetVDYDynRaw()->State)
#else
/*!  brief ego vehicle motion state */
#define EGO_MOTION_STATE_STATE                    VDY_GET_IO_STATE(VDY_SOUT_POS_MSTAT, MEDIC_p_GetVDYDynRaw()->State)
#endif

#ifndef IS_SIGNAL_STATUS_OK
/*!  check for  VDY signal validity */
#define IS_SIGNAL_STATUS_OK(status)     ( VDY_IO_STATE_VALID == (status) )
#endif

#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup     frame_custom_types Custom Types
@ingroup      frame
@brief        Contains all customer specific type definitions. \n\n
@{
*/
/*generate Structure for general custom types*/

/*!
@defgroup custom_type_framework Custom Memory
@ingroup frame_custom_types

@brief    Contains the framework of the memory structure.  \n\n
@description

@{*/

/*!@{
@brief Activate this switch if you want to place a variable in the corresponding struct.*/

#define USE_MEDIC_CUSTHYP_STACK         MEDIC_OFF
#define USE_MEDIC_CUSTGLOB_STACK        MEDIC_OFF

#define USE_MEDIC_CUSTHYP_INTER         MEDIC_OFF
#define USE_MEDIC_CUSTGLOB_INTER        MEDIC_OFF

#define USE_MEDIC_CUSTHYP_INTERMEAS     MEDIC_OFF
#define USE_MEDIC_CUSTGLOB_INTERMEAS    MEDIC_OFF

#define USE_MEDIC_CUSTHYP_INTRAMEAS     MEDIC_OFF
#define USE_MEDIC_CUSTGLOB_INTRAMEAS    MEDIC_OFF

#define USE_MEDIC_CUSTHYP_INTRA         MEDIC_OFF
#define USE_MEDIC_CUSTGLOB_INTRA        MEDIC_OFF


/*!@} */


#if ((MEDIC_CFG_DRIVER_INTENTION_MONITORING)||(MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION))

/************************************************************************/
/* MEDIC Stack custom types                                              */
/************************************************************************/
/* MEDIC Hypothesis data */
#if (USE_MEDIC_CUSTHYP_STACK)
typedef struct  MEDIC_CustHypDataStack_t
{
}MEDIC_HypDataCustStack_t;
#endif /* USE_MEDIC_CUSTOHYP_STACK */

/* MEDIC global object data */
#if (USE_MEDIC_CUSTGLOB_STACK)
typedef struct  MEDIC_CustGlobDataStack_t
{

}MEDIC_GlobDataCustStack_t;
#endif /* USE_MEDIC_CUSTGLOB_STACK */

/************************************************************************/
/* MEDIC Inter custom types                                              */
/************************************************************************/
/* MEDIC Hypothesis data */
#if (USE_MEDIC_CUSTHYP_INTER)
typedef struct  MEDIC_CustObjDataInter_t
{
}MEDIC_ObjDataCustInter_t;
#endif /* USE_MEDIC_CUSTHYP_INTER */

/* MEDIC global object data */
#if (USE_MEDIC_CUSTGLOB_INTER)
typedef struct  MEDIC_CustGlobDataInter_t
{

}MEDIC_GlobDataCustInter_t;
#endif /* USE_MEDIC_CUSTGLOB_INTER */

/************************************************************************/
/* MEDIC InterMeas custom types                                          */
/************************************************************************/
/* MEDIC Hypothesis data */
#if (USE_MEDIC_CUSTHYP_INTERMEAS)
typedef struct  MEDIC_CustHypDataInterMeas_t
{
}MEDIC_HypDataCustInterMeas_t;
#endif /* USE_MEDIC_CUSTHYP_INTERMEAS */

/* MEDIC global object data */
#if (USE_MEDIC_CUSTGLOB_INTERMEAS)
typedef struct  MEDIC_CustGlobDataInterMeas_t
{

}MEDIC_GlobDataCustInterMeas_t;
#endif /* USE_MEDIC_CUSTGLOB_INTERMEAS */



/************************************************************************/
/* MEDIC IntraMeas custom types                                */
/************************************************************************/
/*MEDIC Hypothesis data */
#if (USE_MEDIC_CUSTHYP_INTRAMEAS)
typedef struct  MEDIC_CustHypDataIntraMeas_t
{

}MEDIC_HypDataCustIntraMeas_t;
#endif /* USE_MEDIC_CUSTHYP_INTRAMEAS */

/* MEDIC global object data */
#if (USE_MEDIC_CUSTGLOB_INTRAMEAS)
typedef struct  MEDIC_CustGlobDataIntraMeas_t
{

}MEDIC_GlobDataCustIntraMeas_t;
#endif /* USE_MEDIC_CUSTGLOB_INTRAMEAS */



/************************************************************************/
/* MEDIC Intra custom types                                */
/************************************************************************/
/* MEDIC Hypothesis data */
#if (USE_MEDIC_CUSTHYP_INTRA)
typedef struct  MEDIC_CustHypDataIntra_t
{

}MEDIC_HypDataCustIntra_t;
#endif /* USE_MEDIC_CUSTHYP_INTRA */

/* MEDIC global object data */
#if (USE_MEDIC_CUSTGLOB_INTRA)
typedef struct  MEDIC_CustGlobDataIntra_t
{

}MEDIC_GlobDataCustIntra_t;
#endif /* USE_MEDIC_CUSTGLOB_INTRA */

#endif
#endif
#if (MEDIC_CFG_AUTOSAR_WRAPPER)

#ifndef TP_N_OBJECTS
#define TP_N_OBJECTS ( (sizeof(aObject_array_t)) / (sizeof(CEM_TP_t_Object_t)) )
#endif /* TP_N_OBJECTS */

/*Backward compatibility - gets removed soon:*/
#ifndef COMP_STATE_INTFVER
#define COMP_STATE_INTFVER 3U
#endif

#ifndef ACDC2_MAX_NUM_OF_HYPS
#define ACDC2_MAX_NUM_OF_HYPS 12
#endif

#ifndef CEM_LONG_MOT_STATE_STDST
#define CEM_LONG_MOT_STATE_STDST 3U
#endif

//Backward compatibility - gets removed soon-----

#ifndef RTE_TYPE_Cem200LongMotStates_t
#define RTE_TYPE_Cem200LongMotStates_t
typedef Cem200LongMotStates CEM_Cem200LongMotStates_t;
#endif

typedef void (*AS_t_RTAAlgoServiceAddEvent)();


#ifndef NULL
#ifdef  __cplusplus
#define NULL           (0)
#else //-- __cplusplus
#define NULL           ((void *)0)
#endif //-- __cplusplus
#endif //-- NULL

/* L1 cache line size of ADCU's M3A57 in  bytes,
   information obtained from HW dev Ahmad Essameldin */
#define GA_CACHE_LINE_SIZE                              64

#define GA_AlignToCacheLineSize(n)  \
    ( (((n)%(GA_CACHE_LINE_SIZE)) > 0) ?((((n)+GA_CACHE_LINE_SIZE)/GA_CACHE_LINE_SIZE)*GA_CACHE_LINE_SIZE) :(n) )

// Array sizes taken from ARS540BW11
#ifndef GA_MEDIC_ASILB_SLOW_INTER_MEAS_SIZE_MEM_DATA
#define GA_MEDIC_ASILB_SLOW_INTER_MEAS_SIZE_MEM_DATA GA_AlignToCacheLineSize(8192u)
#endif
#ifndef GA_MEDIC_ASILB_SLOW_INTRA_MEAS_SIZE_MEM_DATA
#define GA_MEDIC_ASILB_SLOW_INTRA_MEAS_SIZE_MEM_DATA GA_AlignToCacheLineSize(2400u)
#endif
#ifndef GA_MEDIC_ASILB_SLOW_INTER_SIZE_MEM_DATA
#define GA_MEDIC_ASILB_SLOW_INTER_SIZE_MEM_DATA      GA_AlignToCacheLineSize(500000u)
#endif

typedef uint32  GA_MEDIC_ASILBSlowInterMeas_Mem_Data[(GA_MEDIC_ASILB_SLOW_INTER_MEAS_SIZE_MEM_DATA+3)/4];
typedef uint32  GA_MEDIC_ASILBSlowIntraMeas_Mem_Data[(GA_MEDIC_ASILB_SLOW_INTRA_MEAS_SIZE_MEM_DATA+3)/4];
typedef uint32  GA_MEDIC_ASILBSlowInter_Mem_Data[(GA_MEDIC_ASILB_SLOW_INTER_SIZE_MEM_DATA+3)/4];

#ifndef ALGO_INLINE
#define ALGO_INLINE static __inline
#endif /* ALGO_INLINE */

#ifndef ALGO_STATIC_INLINE_C
#define ALGO_STATIC_INLINE_C static __inline
#endif /* ALGO_STATIC_INLINE_C */

#endif

#endif /* MEDIC_CUSTOM_TYPES_H_INCLUDED */

