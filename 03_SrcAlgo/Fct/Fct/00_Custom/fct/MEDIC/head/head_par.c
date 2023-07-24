/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 HEAD (Hypothesis Evaluation And Decision)

PACKAGENAME:               head_par.c

DESCRIPTION:               HEAD parameters 

AUTHOR:                    $Author: Vogl, Armin (uid19462) $

CREATION DATE:             $Date: 2019/07/26 14:49:27CEST $

VERSION:                   $Revision: 1.5.2.4 $

LEGACY VERSION:            1.24

**************************************************************************** */

/**
@defgroup head_par HEAD_PAR
@ingroup Medic_head
@{ **/

/*****************************************************************************
INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"
#if !(MEDIC_CFG_HEAD20)
#include "head/head_int.h"
#if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION)

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*****************************************************************************
  CONSTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*!--- Dynamic pre warning parameters TTB early state---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTBPRE_EARLY_STAT[HEAD_PAR_NO_FUSION_VAR] = {
  2.7F,  /* iBrake5 */
  2.4F   /* iBrake3 */
};


/*!--- Dynamic pre warning parameters TTB late state ---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTBPRE_LATE_STAT[HEAD_PAR_NO_FUSION_VAR] = {
  2.3F,  /* iBrake5 */
  2.1F   /* iBrake3 */
};

/*!--- Dynamic pre warning parameters  TTS early state ---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTSPRE_EARLY[HEAD_PAR_NO_FUSION_VAR]= { 
  1.9F,  /* iBrake5 */
  1.6F   /* iBrake3 */
};

/*!--- Dynamic pre-warning parameters TTS late state ---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNPRE_TTSPRE_LATE[HEAD_PAR_NO_FUSION_VAR] = {
  1.7F,  /* iBrake5 */
  1.4F   /* iBrake3 */
};

/*!--- Dynamic acute warning parameters TTB acute state ---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNACUTE_TTBACUTE_STAT[HEAD_PAR_NO_FUSION_VAR] = {
  1.9F,  /* iBrake5 */
  1.7F   /* iBrake3 */
};

SET_MEMSEC_CONST(HEAD_PAR_DYNACUTE_TTSACUTE)
/*!--- Dynamic acute warning parameters TTS acute ---*/
HEAD_PAR_CONST float32 HEAD_PAR_DYNACUTE_TTSACUTE[HEAD_PAR_NO_FUSION_VAR]= {
  1.8F,  /* iBrake5 */
  1.3F   /* iBrake3 */
};

/*! Latent pre-warning: country 0 / Early, object distance over velocity */
HEAD_PAR_CONST float32 LatPreDistVel_Cntr0[2u*LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS] /*!<@values:float32[LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS][2]*/ = {
  3.5f,   2.1f,     /* ego velocity, longitudinal object distance */
  7.0f,   3.2f, 
  21.0f,  9.5f, 
  45.5f, 16.0f, 
  59.5f, 18.0f, 
  66.5f, 18.8f
};

/*! Latent pre-warning: country 1 / Early , object distance over velocity */
HEAD_PAR_CONST float32 LatPreDistVel_Cntr1[2u*LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS] /*!<@values:float32[LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS][2]*/ = {
  3.5f,   2.1f,   /* ego velocity, longitudinal object distance */
  7.0f,   3.2f, 
  21.0f,  9.5f, 
  45.5f, 16.0f, 
  59.5f, 18.0f, 
  66.5f, 18.8f
};

/*! Latent pre-warning: country 0 / late , object distance over velocity */
HEAD_PAR_CONST float32 LatAcuteDistVel_Cntr0[2u*LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS] /*!<@values:float32[LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS][2]*/ = {
  3.5f,   1.0f,  /* ego velocity, longitudinal object distance */
  7.0f,   1.6f, 
  21.0f,  4.75f, 
  45.5f,  8.0f, 
  59.5f,  9.0f, 
  66.5f,  9.4f
};

/*! Latent pre-warning: country 1 / late , object distance over velocity */
HEAD_PAR_CONST float32 LatAcuteDistVel_Cntr1[2u*LAT_ACUTE_DIST_OVER_VELOCITY_TAB_POINTS] /*!<@values:float32[LAT_PRE_DIST_OVER_VELOCITY_TAB_POINTS][2]*/ = {
  3.5f,   1.0f,  /* ego velocity, longitudinal object distance */
  7.0f,   1.6f, 
  21.0f, 4.75f, 
  45.5f,  8.0f, 
  59.5f,  9.0f, 
  66.5f,  9.4f
};


/*! @brief      Max. allowed distance to brake
    @general    Maxim allowed long. object distance where pre-braking is started
    @conseq     @incp  Earlier braking during run-up
                @decp  Later braking during run-up
    @attention  -
    @typical 100  @unit  m   @min 0.0   @max 200   */
SET_MEMSEC_VAR(HEAD_PAR_MAX_BRAKE_DISTANCE)
HEAD_DEF_PARAM(float32, HEAD_PAR_MAX_BRAKE_DISTANCE,HEAD_PAR_MAX_BRAKE_DISTANCE_VALUE)

/*! Confidence Level for Video confirmation */
HEAD_DEF_PARAM(float32, HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST, HEAD_PAR_MAX_VIDEO_SELF_CONF_DIST_VALUE)

#endif  /* #if (MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION) */
#endif  /* !(MEDIC_CFG_HEAD20) */

/**@}*/
