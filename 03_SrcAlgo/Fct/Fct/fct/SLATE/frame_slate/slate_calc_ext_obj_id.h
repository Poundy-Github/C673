/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE

MODULNAME:                 slate_calc_ext_obj_id.h

DESCRIPTION:               External object ID calculation module header

AUTHOR:                    $Author: uia80245 $

CREATION DATE:             26.01.2017

VERSION:                   $Revision: 1.3 $

LEGACY VERSION:            Revision: 1.6.1.2

**************************************************************************** */


/* Bedingte Einbindung */
#ifndef SLATE_CALC_EXT_OBJ_ID_H_INCLUDED
#define SLATE_CALC_EXT_OBJ_ID_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

//#include "fct_par.h" /*!< Remark: fct_par.h need to be split */
#include "slate_par.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENTENEXTERN)
*****************************************************************************/

///*! If configuration does not define the number of external object-IDs available,
//then assume the ARS310 default of 31 possibilities [0 .. 30] */
//#ifndef FCT_NR_EXTERN_OBJECT_ID
//#define FCT_NR_EXTERN_OBJECT_ID     (31)
//#endif

/*! Definition of the extern object ID to assign if no extern object ID has
been assigned */
#ifndef FCT_EXTERN_OBJ_ID_NO_OBJECT
#define FCT_EXTERN_OBJ_ID_NO_OBJECT   255
#endif

/*****************************************************************************
  MACROS (COMPONENTENEXTERN)
*****************************************************************************/



/*****************************************************************************
  TYPEDEFS (COMPONENTENEXTERN)
*****************************************************************************/

/*! The numeric type of the external object ID assigned to objects */
typedef uint8 FCTSenExtObjId_t;


/*****************************************************************************
  CONSTANTS (COMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENTENEXTERN)
*****************************************************************************/

#if (SLATE_CFG_USE_EXT_OBJ_ID)
extern void FCTSen_v_SLATEInitExternObjID(void);
extern void FCTSenDetermineExternObjID(void);
extern void FCTSenMergeExtObjID(ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete);
extern FCTSenExtObjId_t FCTSenGetObjExtID(ObjNumber_t const ObjNr);
extern void FCTSenSetObjExtID(ObjNumber_t const ObjNr, FCTSenExtObjId_t const u_ExtID);
#if 0
extern FCTSenExtObjId_t FCTSenGetAssignObjExtID(ObjNumber_t const ObjNr);
#endif
#endif

#ifdef __cplusplus
};
#endif

/* Ende der bedingten Einbindung */
#else
#endif

