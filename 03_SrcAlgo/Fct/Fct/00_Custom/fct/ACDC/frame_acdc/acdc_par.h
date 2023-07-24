/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC (Advanced collision detection and classification)

PACKAGENAME:               acdc_par.h

DESCRIPTION:               parameter file for ACDC (Advanced collision detection and classification)

AUTHOR:                    $Author: Kramer, Andreas (uidv8254) $

CREATION DATE:             $Date: 2018/09/11 10:09:18CEST $

VERSION:                   $Revision: 1.22 $
**************************************************************************** */

#ifndef ACDC_PAR_H_INCLUDED
#define ACDC_PAR_H_INCLUDED

/******************************************************************************
  INCLUDES
******************************************************************************/
#include "acdc_cfg.h"

#if(ACDC_CFG_FRAME)

/******************************************************************************
  MODULE DESCRIPTION
******************************************************************************/
/*!
@defgroup frame_par Parameter
@ingroup frame
@brief Contains all parameters that are relevant for the ACDC component.\n\n

@{
*/

/************************************************************************/
/*                       COMMON MACROS                                  */
/************************************************************************/

/*! @brief ACDC parameter declaration macro */
#define ACDC_DECL_FIX_PARAM(type_, name_)         FCT_DECL_FIX_PARAM(type_, name_)

/*! @brief ACDC parameter definition macro */
#define ACDC_DEF_FIX_PARAM(type_, name_, value_)  FCT_DEF_FIX_PARAM(type_, name_, value_)

#if (FCT_CFG_ENABLE_RAM_PARAM)

/*! @brief ACDC parameter constant if FCT_CFG_ENABLE_RAM_PARAM is true */
#define ACDC_PAR_CONST

/*! @brief ACDC parameter definition macro*/
#define ACDC_DEF_PARAM(type_, name_, value_)      FCT_DEF_ADJ_PARAM(type_, name_, value_)

/*! @brief ACDC parameter declaration macro*/
#define ACDC_DECL_PARAM(type_, name_)             FCT_DECL_ADJ_PARAM(type_, name_)

#else

/*! @brief CD parameter constant */
#define ACDC_PAR_CONST const

/*! @brief ACDC parameter definition macro*/
#define ACDC_DEF_PARAM(type_, name_, value_)      FCT_DEF_FIX_PARAM(type_, name_, value_)

/*! @brief ACDC parameter declaration macro*/
#define ACDC_DECL_PARAM(type_, name_)             FCT_DECL_FIX_PARAM(type_, name_)

#endif



/*  @brief  Used to convert the given timestamp to Microseconds*/
#define ACDC_TIMESTAMP_TO_MICROSECONDS                   1000000.0f

/*  @brief  Default distance for ACDC and its subcomponents
            @typical 1000.f @unit [m] */
#define ACDC_DIST_DEFAULT                           (1000.f)

/*! @brief  Assumed ego length.
            @typical 4.5f @phys_unit: [m]*/
#define ACDC_COMMON_EGO_LENGTH                        (         4.5f)

/*! @brief  Common width of the ego vehicle.
            @typical 1.8f @unit: [m]*/
#define ACDC_COMMON_EGO_WIDTH                         (         1.8f)

/*! @brief  Plausibility ego width, below this width @ref ACDC_COMMON_EGO_WIDTH is assumed.
            @typical 1.2f @unit: [m]*/
#define ACDC_PLAUS_EGO_WIDTH                          (         1.2f)

/*! @brief  Plausibility ego length, below this width @ref ACDC_COMMON_EGO_WIDTH is assumed.
            @typical 2.0f @unit: [m]*/
#define ACDC_PLAUS_EGO_LENGTH                         (         2.0f)

/*! @brief  Initial value of the EMP Ego Trajectory prediction.
            @typical 1000.0f*/
#define ACDC_TRAJPRED_INIT                         (        1000.0f)

/*! @brief  Assumed check value of the EMP Trajectory Prediction.
            @typical 999.0f, @unit [m]*/
#define ACDC_TRAJPRED_CHECK                         (        999.0F)


/*! @brief Stationary object with a velocity below this threshold 
           are considered to have a velocity and acceleration of 0 */
#define ACDC_VEL_THRESHOLD_FORCE_STAT_OBJ_KIN_ZERO   (           0.05f)
/******************************************************************************
  acdc_io.c parameters
******************************************************************************/
/*! @brief Number of acceptable frame drops (1 means error flag if more than one frame drops) */
#define FCT_INPUT_ACCEPTABLE_DROPS 1u

/*! @brief        Number of subcomponents inside ACDC
    @description  (see enum @ref ACDCSubCompIndices_t)*/
#define ACDC_NOF_SUB_COMPONENTS                      (          6u)

/**@defgroup frame_subcomponents
@description defines to identifiy each subcomponent in the bitfield @ref ACDCSubCompIndices_t
@{*/
#define ACDC_SUB_COMP_NONE       0u
#define ACDC_SUB_COMP_AIP        1u
#define ACDC_SUB_COMP_CD         2u
#define ACDC_SUB_COMP_ESPM       4u
#define ACDC_SUB_COMP_EMP        8u
#define ACDC_SUB_COMP_SFL        16u
#define ACDC_SUB_COMP_ACDC       32u
#define ACDC_SUB_COMP_ALL        255u
/*@} */

/*! @brief  Maximum number of VDY signal errors. If more occur CDState in @ref ACDC_p_GetFrameData is set to @ref COMP_STATE_TEMPORARY_ERROR.
            @typical 5uL*/
#define ACDC_MAX_VDY_SIG_ERRORS                       (             5u)


/************************************************************************/
/*      ACDC Object circle Parameters                                    */
/************************************************************************/
/*! @description  Number of different positions a shape point can take:
                  @ref ACDCShapePointPositions_e*/
#define ACDC_NOF_SP_POSITIONS                      (          4u)

/*! @description  Initial value of all elements of the shape point position structure*/
#define ACDC_SP_POSITIONS_INIT                     (          -1)

/*! @description  Maximum number of circles that are calculated per object 
                  to determine the Min and MaxDistToTraj. \n
                  (=One circle per edge + 1 Intersection Circle)
                  @typical 3u, @unit []*/
#define ACDC_MAX_NOF_OBJECT_CIRCLES                (           3u)

/*! @brief  Minimum number of circles to represent a rectangle. @typical 1*/
#define ACDC_MIN_NOF_CIRCLES                        (           1u)

/*! @brief  Maximum number of circles to represent a rectangle. @typical 10*/
#define ACDC_MAX_NOF_CIRCLES                        (          10u)

/*! @brief  Minimum radius of circle to represent a rectangle. 
            @typical 0.1f, @unit [m]*/
#define ACDC_MIN_CIRCLE_RADIUS                      (         0.1f)

/************************************************************************/
/*                      Testing & Debugging                             */
/************************************************************************/


/****************** Meas Freeze Adresses ***************/
/* For more details see interface sheet: \04_Engineering\00_CodeGen\algo\fct\fct_interface_types.xls */

#if (FCT_CFG_USE_ALGOCOMPSTATE)
#ifndef FCT_MEAS_ID_SEN_EBA_COMP_STATE
#define FCT_MEAS_ID_SEN_EBA_COMP_STATE               (539795300 )
#endif
#endif

#ifndef FCT_MEAS_ID_ACDC_EGO_DATA
#define FCT_MEAS_ID_ACDC_EGO_DATA                     0x202D5EEF
#endif

#ifndef FCT_MEAS_ID_ACDC_INTERNAL_OBJECT_LIST
#define FCT_MEAS_ID_ACDC_INTERNAL_OBJECT_LIST         0x202D1EEF
#endif

#ifndef FCT_MEAS_ID_ACDC_INTERNAL_OBJECT_LIST_SIMU
#define FCT_MEAS_ID_ACDC_INTERNAL_OBJECT_LIST_SIMU    0x202D6300
#endif



///@}
#endif /* ACDC_CFG_FRAME */
#endif
