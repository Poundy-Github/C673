/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/CC (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               loc_ext.h

DESCRIPTION:               External header file for CC (Longitudinal Coordinator) in FCT_SEN task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.1 $

---*/ /*---
CHANGES:                    $Log: cc_ext.h  $
CHANGES:                    Revision 1.1 2017/10/05 08:22:03CEST uidj5069 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOCC_LongitudinalCruiseControl/04_Engineering/01_Source_Code/LOCC/locc/cc/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup loc (Longitudinal Coordinator)
   @ingroup lopc

@{ */

#ifndef CC_EXT_H
#define CC_EXT_H

#if ((FCT_CFG_LOCC_COMPONENT) && (LOCC_CFG_CC))


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
  CC_INIT,           /*!< initialize all */
  CC_OK              /*!< normal processing */
}
CC_t_State;


/*! Typedef of measure structs for CC component */
#ifdef FCT_SIMU
typedef struct CC_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
CC_SimMeasInfo_t;
#endif

typedef struct CC_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
CC_t_DeviceMeasInfo;

typedef struct CC_MeasFrame
{
#ifdef FCT_SIMU
  CC_SimMeasInfo_t *pt_CC_SimMeasInfo; /*!< Sim Freeze of CC from Frame */
  const MEASInfo_t *pt_CC_SimMeasInfoFreeze;
#endif
  CC_t_DeviceMeasInfo *pt_CC_DeviceMeasInfo; /*!< Device Freeze of CC from Frame */
  const MEASInfo_t *pt_CC_DeviceMeasInfoFreeze;
}
CC_MeasFrame_t;


/*! Input Ports required by CC component for processing */
typedef struct
{
  LOCC_CruiseControlCommandPort_t t_CC_IN_CCCP;
  LOCC_EgoVehicleInfoPort_t       t_CC_IN_EVIP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  LOCC_VehicleSpeedStatePort_t    at_CC_IN_VSSP[ACT_CFG_CC_VSC_PORT_CNT];
#endif
}
CC_ReqPortList_t;


/*! Output Ports provided by CC component after processing */
typedef struct
{
  LOCC_CruiseControlStatePort_t   t_CC_OUT_CCSP;

#if (ACT_CFG_CC_VSC_PORT_CNT)
  LOCC_VehicleSpeedCommandPort_t  at_CC_OUT_VSCP[ACT_CFG_CC_VSC_PORT_CNT];
#endif
}
CC_ProPortList_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF CC_t_State CC_State;

#ifdef FASTSIM
extern CC_t_DeviceMeasInfo CC_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*  cc_main.c  */
extern void CC_v_SetOperationMode(const CC_t_State t_CCOpModeValue);
extern void CC_v_Process(const CC_ReqPortList_t *pRequirePorts, const CC_ProPortList_t *pProvidePorts);


#ifdef __cplusplus
};
#endif

#endif  /* (FCT_CFG_LOCC_COMPONENT && LOCC_CFG_CC) */

#endif

/** @} end defgroup */


