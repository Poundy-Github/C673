/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC/HMI (Adaptive Cruise Control - Interface and State Coordinator - Human Machine Interface)

PACKAGENAME:               hmi_ext.h

DESCRIPTION:               External header file for HMI in FCT_VEH task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.3 $

---*/ /*---
CHANGES:                    $Log: hmi_ext.h  $
CHANGES:                    Revision 1.3 2018/06/11 14:55:46CEST uidj5069 
CHANGES:                    New Ports added for LOPC based Start Coordination
CHANGES:                    Revision 1.2 2017/10/12 16:27:40CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port for Target Control (ACC) added
CHANGES:                    Revision 1.1 2017/10/05 08:35:02CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/ISC_InterfaceAndStateCoordinator/04_Engineering/01_Source_Code/ISC/isc/hmi/project.pj
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

/*!
   @defgroup hmi (Human Machine Interface)
   @ingroup isc

@{ */

#ifndef HMI_EXT_H
#define HMI_EXT_H

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
  HMI_INIT ,        /*!< initialize all */
  HMI_OK              /*!< normal processing */
}
HMI_t_State;

#ifdef FCT_SIMU
typedef struct HMI_SimMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
HMI_SimMeasInfo_t;
#endif

typedef struct HMI_DeviceMeasInfo
{
  boolean b_Dummy;    /*!< Dummy member, REMOVE it when no inputs are switch dependent */
}
HMI_t_DeviceMeasInfo;

/*! Typedef of inputs to HMI component from Frame */
typedef struct HMIInputFrame
{
#ifdef FCT_SIMU
  HMI_SimMeasInfo_t * pt_HMI_SimMeasInfo; /*!< Sim Freeze of HMI from Frame */
  const MEASInfo_t * pt_HMI_SimMeasInfoFreeze;
#endif
  HMI_t_DeviceMeasInfo * pt_HMI_DeviceMeasInfo; /*!< Device Freeze of HMI from Frame */
  const MEASInfo_t * pt_HMI_DeviceMeasInfoFreeze;
}
HMIInputFrame_t;


/*! Input Ports required by HMI component for processing */
typedef struct
{
  ISC_HMI_InformationPort_t   t_HMI_IN_HMIP;
  ISC_HMI_CommandPort_t       t_HMI_IN_HMCP;
  ISC_SM_StatusPort_t         t_HMI_IN_SMSP;
  ISC_LOC_StatePort_t         t_HMI_IN_LVSP;
}
HMI_ReqPortList_t;


/*! Output Ports provided by HMI component after processing */
typedef struct
{
  ISC_SM_CommandPort_t        t_HMI_OUT_SMCP;
  ISC_HMI_StatusPort_t        t_HMI_OUT_HMSP;
#if (FCT_CFG_LOCC_COMPONENT)
  ISC_CC_DegradationPort_t    t_HMI_OUT_CCDP;
#endif
#if (FCT_CFG_LOHP_COMPONENT)
  ISC_TC_DegradationPort_t    t_HMI_OUT_TCDP;
#endif
  ISC_LOC_CommandPort_t       t_HMI_OUT_LVCP;
}
HMI_ProPortList_t;


/*****************************************************************************
  CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/
/*! @cond Doxygen_Suppress */
extern MEMSEC_REF HMI_t_State HMI_State;

#ifdef FASTSIM
extern HMI_t_DeviceMeasInfo HMI_DeviceMeasInfo;
#endif

/*****************************************************************************
  FUNCTIONS
*****************************************************************************/
/*
  hmi_main.c
*/
extern void HMI_v_SetOperationMode(const HMI_t_State t_HMIOpModeValue);

extern void HMI_v_Process(const HMI_ReqPortList_t *pRequirePorts, const HMI_ProPortList_t *pProvidePorts);


#ifdef __cplusplus
};
#endif

#endif  /* FCT_CFG_ISC_COMPONENT */



#endif

/** @} end defgroup */


