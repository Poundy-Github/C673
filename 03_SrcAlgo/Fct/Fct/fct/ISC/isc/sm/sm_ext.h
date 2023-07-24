/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/SM (Adaptive Cruise Control - Interface and State Coordinator - State Machine)

PACKAGENAME:               sm_ext.h

DESCRIPTION:               External header file for SM in FCT_VEH task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

---*/ /*---
CHANGES:                    $Log: sm_ext.h  $
CHANGES:                    Revision 1.3 2018/06/27 10:07:48CEST uidj5069 
CHANGES:                    Additional State Input Port from LOC
CHANGES:                    Revision 1.2 2017/10/12 16:45:13CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports for Target Control (ACC) added
CHANGES:                    Revision 1.1 2017/10/05 08:35:22CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/sm/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup sm (State Machine)
   @ingroup isc

@{ */

#ifndef SM_EXT_H
#define SM_EXT_H

#if (FCT_CFG_ISC_COMPONENT)


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
  SM_INIT,          /*!< initialize all */
  SM_OK             /*!< normal processing */
}
SM_t_State;

#ifdef FCT_SIMU
typedef struct SM_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
SM_SimMeasInfo_t;
#endif

typedef struct SM_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
SM_t_DeviceMeasInfo;

/*! Typedef of inputs to SM component from Frame */
typedef struct SMInputFrame
{
#ifdef FCT_SIMU
  SM_SimMeasInfo_t * pt_SM_SimMeasInfo; /*!< Sim Freeze of SM from Frame */
  const MEASInfo_t * pt_SM_SimMeasInfoFreeze;
#endif
  SM_t_DeviceMeasInfo * pt_SM_DeviceMeasInfo; /*!< Device Freeze of SM from Frame */
  const MEASInfo_t * pt_SM_DeviceMeasInfoFreeze;
}
SMInputFrame_t;


/*! Input Ports required by SM component for processing */
typedef struct
{
  ISC_SM_CommandPort_t        t_SM_IN_SMCP;
#if (FCT_CFG_LOCC_COMPONENT)
  ISC_CC_StatePort_t          t_SM_IN_CCSP;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  ISC_TC_StatePort_t          t_SM_IN_TCSP;
#endif
  ISC_LOC_StatePort_t         t_SM_IN_LOCSP;
}
SM_ReqPortList_t;


/*! Output Ports provided by SM component after processing */
typedef struct
{
#if (FCT_CFG_LOCC_COMPONENT)
  ISC_CC_CommandPort_t        t_SM_OUT_CCCP;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  ISC_TC_CommandPort_t        t_SM_OUT_TCCP;
#endif
  ISC_SM_StatusPort_t         t_SM_OUT_SMSP;
}
SM_ProPortList_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF SM_t_State SM_State;

#ifdef FASTSIM
extern SM_t_DeviceMeasInfo SM_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/

/*  sm_main.c  */
extern void SM_v_SetOperationMode(const SM_t_State t_SMOpModeValue);
extern void SM_v_Process(const SM_ReqPortList_t *pRequirePorts, const SM_ProPortList_t *pProvidePorts);


#ifdef __cplusplus
};
#endif

#endif  /* FCT_CFG_ISC_COMPONENT */



#endif

/** @} end defgroup */


