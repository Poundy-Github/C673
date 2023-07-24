/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOHP/TC (Adaptive Cruise Control - Longitudinal Headway Planner - Target Control)

PACKAGENAME:               tc_ext.h

DESCRIPTION:               External header file for SM in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

---*/ /*---
CHANGES:                    $Log: tc_ext.h  $
CHANGES:                    Revision 1.3 2018/01/16 17:35:20CET Mistry, Niraj (uidq5738) 
CHANGES:                    Header strategy update for self-sufficiency
CHANGES:                    Revision 1.2 2017/11/20 12:52:32CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Revision 1.1 2017/10/05 09:47:41CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOHP_LongitudinalHeadwayPlanner/04_Engineering/01_Source_Code/LOHP/lohp/tc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup tc (Target Control)
   @ingroup lohp

@{ */

#ifndef TC_EXT_H
#define TC_EXT_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lohp_ext.h"

#if ((FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC))

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
  TC_INIT,          /*!< initialize all */
  TC_OK             /*!< normal processing */
}
TC_t_State;


#ifdef FCT_SIMU
typedef struct TC_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
TC_SimMeasInfo_t;
#endif

typedef struct TC_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
TC_t_DeviceMeasInfo;

/*! Typedef of inputs to TC component from Frame */
typedef struct TCInputFrame
{
#ifdef FCT_SIMU
  TC_SimMeasInfo_t *pt_TC_SimMeasInfo; /*!< Sim Freeze of TC from Frame */
  const MEASInfo_t *pt_TC_SimMeasInfoFreeze;
#endif
  TC_t_DeviceMeasInfo *pt_TC_DeviceMeasInfo; /*!< Device Freeze of TC from Frame */
  const MEASInfo_t *pt_TC_DeviceMeasInfoFreeze;
}
TCInputFrame_t;


/*! Input Ports required by TC component for processing */
typedef struct
{
  LOHP_TargetControlCommandPort_t t_TC_IN_TCCP;
  LOHP_EgoVehicleInfoPort_t       t_TC_IN_EVIP;
  LOHP_TargetVehicleInfoPort_t    t_TC_IN_TVIP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
  LOHP_TargetFollowStatePort_t    at_TC_IN_TFSP[FCT_CFG_HP_TFC_PORT_CNT];
#endif
}
TC_ReqPortList_t;


/*! Output Ports provided by TC component after processing */
typedef struct
{
  LOHP_TargetControlStatePort_t   t_TC_OUT_TCSP;

#if (FCT_CFG_HP_TFC_PORT_CNT)
  LOHP_TargetFollowCommandPort_t  at_TC_OUT_TFCP[FCT_CFG_HP_TFC_PORT_CNT];
#endif
}
TC_ProPortList_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF TC_t_State TC_State;

#ifdef FASTSIM
extern TC_t_DeviceMeasInfo TC_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*  tc_main.c  */
extern void TC_v_SetOperationMode(const TC_t_State t_TCOpModeValue);
extern void TC_v_Process(const TC_ReqPortList_t *pRequirePorts, const TC_ProPortList_t *pProvidePorts);


#ifdef __cplusplus
};
#endif

#endif  /* (FCT_CFG_LOHP_COMPONENT) && (LOHP_CFG_TC) */



#endif

/** @} end defgroup */


