/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/LOP (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               lop_ext.h

DESCRIPTION:               External header file for LOP (Longitudinal Coordinator) in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.4 $

---*/ /*---
CHANGES:                    $Log: lop_ext.h  $
CHANGES:                    Revision 1.4 2017/11/21 10:47:07CET uidj5069 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.3 2017/10/26 10:12:00CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional Input Port <EgoVehicleStatePort> for LOP
CHANGES:                    Revision 1.2 2017/10/20 10:04:30CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    GEN 4 Bugfix - Port List Structure
CHANGES:                    Revision 1.1 2017/10/05 10:17:23CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC_LongitudinalPlannerAndController/04_Engineering/01_Source_Code/LOPC/lopc/lop/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup lop (Longitudinal Coordinator)
   @ingroup lopc

@{ */

#ifndef LOP_EXT_H
#define LOP_EXT_H

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP))


/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lop_cfg.h"

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
  LOP_INIT,         /*!< initialize all */
  LOP_OK            /*!< normal processing */
}
LOP_State_t;

/*! Typedef of measure structs for LOP component */
#ifdef FCT_SIMU
typedef struct LOP_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
LOP_SimMeasInfo_t;
#endif

typedef struct LOP_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
LOP_DeviceMeasInfo_t;

typedef struct LOP_MeasFrame
{
#ifdef FCT_SIMU
  LOP_SimMeasInfo_t * pt_LOP_SimMeasInfo; /*!< Sim Freeze of LOP from Frame */
  const MEASInfo_t * pt_LOP_SimMeasInfoFreeze;
#endif
  LOP_DeviceMeasInfo_t * pt_LOP_DeviceMeasInfo; /*!< Device Freeze of LOP from Frame */
  const MEASInfo_t * pt_LOP_DeviceMeasInfoFreeze;
}
LOP_MeasFrame_t;



/*! Input Port Definitions */

/*! Input Ports required by LOP component for processing */
typedef struct LOP_ReqPortList
{
#if (LOP_CFG_VSC_PORT_CNT)
  LOPC_VehicleSpeedCommandPort_t at_LOP_IN_VSCP[LOP_CFG_VSC_PORT_CNT];
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  LOPC_DistanceSpeedCommandPort_t at_LOP_IN_DSCP[LOP_CFG_DSC_PORT_CNT];
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  LOPC_DistanceCurveCommandPort_t at_LOP_IN_DCCP[LOP_CFG_DCC_PORT_CNT];
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  LOPC_TargetFollowCommandPort_t at_LOP_IN_TFCP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

  LOPC_IdealVehicleStatePort_t t_LOP_IN_IVSP;
  LOPC_EgoVehicleStatePort_t t_LOP_IN_EVSP;
}
LOP_ReqPortList_t;


/*! Output Port Definitions */

/*! Output Ports provided by LOP component after processing */
typedef struct LOP_ProPortList
{
#if (LOP_CFG_VSC_PORT_CNT)
  LOPC_VehicleSpeedStatePort_t at_LOP_OUT_VSSP[LOP_CFG_VSC_PORT_CNT];
#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
  LOPC_DistanceSpeedStatePort_t at_LOP_OUT_DSSP[LOP_CFG_DSC_PORT_CNT];
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
  LOPC_DistanceCurveStatePort_t at_LOP_OUT_DCSP[LOP_CFG_DCC_PORT_CNT];
#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)
  LOPC_TargetFollowStatePort_t at_LOP_OUT_TFSP[FCT_CFG_HP_TFC_PORT_CNT];
#endif

  LOPC_IdealVehicleCommandPort_t t_LOP_OUT_IVCP;
}
LOP_ProPortList_t;




/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF LOP_State_t LOP_State;

#ifdef FASTSIM
extern LOP_t_DeviceMeasInfo LOP_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*
  lop_main.c
*/
extern void LOP_v_SetOperationMode(const LOP_State_t t_LOPOpModeValue);

extern void LOP_v_Process(const LOP_ReqPortList_t *pRequirePorts, const LOP_ProPortList_t *pProvidePorts);

#ifdef __cplusplus
};
#endif

#endif  /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP) */



#endif

/** @} end defgroup */


