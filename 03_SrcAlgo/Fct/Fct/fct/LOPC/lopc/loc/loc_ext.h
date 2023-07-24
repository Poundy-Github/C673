/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/LOC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               loc_ext.h

DESCRIPTION:               External header file for LOC (Longitudinal Coordinator) in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.2 $

---*/ /*---
CHANGES:                    $Log: loc_ext.h  $
CHANGES:                    Revision 1.2 2018/06/12 10:46:58CEST uidj5069 
CHANGES:                    Additional Ports for ISC Communication added
CHANGES:                    Revision 1.1 2017/10/05 09:05:30CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC_LongitudinalPlannerAndController/04_Engineering/01_Source_Code/LOPC/lopc/loc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup loc (Longitudinal Coordinator)
   @ingroup lopc

@{ */

#ifndef LOC_EXT_H
#define LOC_EXT_H

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOC))


/*****************************************************************************
  INCLUDES
*****************************************************************************/

/* Note: the below file is a dependency of this header, but currently through
include hierarchy considerations, this file is only included after that file
has already been pre-processed */

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/

/*! @brief operating modes of sub-component */
typedef enum
{
  LOC_INIT,           /*!< initialize all */
  LOC_OK              /*!< normal processing */
}
LOC_t_State;

/*! Typedef of measure structs for LOC component */
#ifdef FCT_SIMU
typedef struct LOC_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
LOC_SimMeasInfo_t;
#endif

typedef struct LOC_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
LOC_t_DeviceMeasInfo;

typedef struct LOC_MeasFrame
{
#ifdef FCT_SIMU
  LOC_SimMeasInfo_t *pt_LOC_SimMeasInfo; /*!< Sim Freeze of LOC from Frame */
  const MEASInfo_t *pt_LOC_SimMeasInfoFreeze;
#endif
  LOC_t_DeviceMeasInfo *pt_LOC_DeviceMeasInfo; /*!< Device Freeze of LOC from Frame */
  const MEASInfo_t *pt_LOC_DeviceMeasInfoFreeze;
}
LOC_MeasFrame_t;



/*! Input Ports required by LOC component for processing */
typedef struct LOC_ReqPortList
{
  LOPC_IdealVehicleCommandPort_t t_LOC_IN_IVCP;
  LOPC_LogicVehicleCommandPort_t t_LOC_IN_LVCP;
  LOPC_EgoVehicleStatePort_t t_LOC_IN_EVSP;
}
LOC_ReqPortList_t;


/*! Output Ports provided by LOC component after processing */
typedef struct LOC_ProPortList
{
  LOPC_IdealVehicleStatePort_t t_LOC_OUT_IVSP;
  LOPC_LogicVehicleStatePort_t t_LOC_OUT_LVSP;
  LOPC_EgoVehicleCommandPort_t t_LOC_OUT_EVCP;
}
LOC_ProPortList_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF LOC_t_State LOC_State;

#ifdef FASTSIM
extern LOC_t_DeviceMeasInfo LOC_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*
  loc_main.c
*/
extern void LOC_v_SetOperationMode(const LOC_t_State t_LOCOpModeValue);

extern void LOC_v_Process(const LOC_ReqPortList_t *pRequirePorts, const LOC_ProPortList_t *pProvidePorts);


#ifdef __cplusplus
};
#endif

#endif  /* (FCT_CFG_LOPC_COMPONENT && LOPC_CFG_LOC) */

#endif

/** @} end defgroup */


