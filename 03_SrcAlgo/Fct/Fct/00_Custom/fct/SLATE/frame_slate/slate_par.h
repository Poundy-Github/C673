/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE (Situation Lane Association Trajectory Estimation)

PACKAGENAME:               slate_par.h

DESCRIPTION:               Parameter File for SLATE

AUTHOR:                    Shang Hanyu (uid32100)

CREATION DATE:             29.03.2017

VERSION:                   $Revision: 1.7 $

LEGACY VERSION:            None

---*/ /*---
CHANGES:                    $Log: slate_par.h  $
CHANGES:                    Revision 1.7 2018/05/23 12:55:42CEST SUNDARAMURTHY, PRABHU (uidj1615) (uidj1615) 
CHANGES:                    Remove Compiler warning
CHANGES:                    Revision 1.6 2018/05/22 13:27:40CEST Daniel, Midhun (uidk2010) 
CHANGES:                    [SLATE] : Add module description to all SLATE code files
CHANGES:                    Revision 1.4 2018/03/26 10:05:34CEST Gobichettipalayam Sankar, Bharadwaj (uidk9952) 
CHANGES:                    QAC fix
CHANGES:                    Revision 1.3 2017/12/19 15:38:51CET Gobichettipalayam Sankar, Bharadwaj (uidk9952) 
CHANGES:                    [SLATE] IO restructuring without SyncRef
CHANGES:                    Revision 1.2 2017/11/20 11:14:45CET Mudhol, Madhusudan (uidp1439) 
CHANGES:                    Adapting header inclusion strategy so that the headers are self-sufficient
CHANGES:                    Revision 1.1 2017/04/26 14:59:39CEST Umesh Babu, Harsha (uidj3583) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/SLATE_SituationLaneAssociationTrajectoryEstimation/04_Engineering/00_Projects/MFC431/SLATE/frame_slate/project.pj

**************************************************************************** */

#ifndef SLATE_PAR_H_INCLUDED
#define SLATE_PAR_H_INCLUDED

#include "slate_types.h"
#include "fct_par.h"
/******************************************************************************
  MODULE DESCRIPTION
******************************************************************************/
/*!
@defgroup slate_par Parameter
@ingroup frame
@{
*/
#if (SLATE_CFG_USE_EXT_OBJ_ID)
/******************************************************************************
  slate_sen_calc_ext_obj_id.c parameters
******************************************************************************/

/* The number of external object-IDs available */
#define FCT_NR_EXTERN_OBJECT_ID     (255)

/*! Definition of the extern object ID to assign if no extern object ID has
been assigned */
#define FCT_EXTERN_OBJ_ID_NO_OBJECT   255

#if (SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO)
/*! Parameter defining modulo which value the external object IDs are to be
assigned (only takes an effect when SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO on */
#define FCT_PAR_OBJ_EXT_ID_MODULO     64

/*! Parameter defining the offset to add to get modulo object IDs (only has an
effect when SLATE_CFG_EXTERN_ID_FROM_INTERN_ID_MODULO enabled */
#define FCT_PAR_OBJ_EXT_ID_OFFSET     1
#endif

/******************************************************************************
  fct_sen_calc_ext_obj_id.c parameters end
******************************************************************************/
#endif

#if FCT_CFG_INPUT_PORT_MEASCYCLE_MONITORING
/******************************************************************************
  slate_io.c parameters
******************************************************************************/
#define FCT_SEN_TARGET_CYCLE_TIME   0.06f
#define FCT_VEH_TARGET_CYCLE_TIME   0.02f
#define FCT_NORM_TARGET_CYCLE_TIME  FCT_VEH_TARGET_CYCLE_TIME 
#define MILLION             1000000u
#endif

/*  @brief  Used to convert the given timestamp to Microseconds*/
#define SLATE_TIMESTAMP_TO_MICROSECONDS                   1000000.0f
/* Number of acceptable frame drops (1 means error flag if more than one frame drops) */
#define SLATE_INPUT_ACCEPTABLE_DROPS 1u
///@}
#endif /* SLATE_PAR_H_INCLUDED */

