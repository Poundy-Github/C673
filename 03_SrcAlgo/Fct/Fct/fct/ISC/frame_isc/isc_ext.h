/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   ARS4xx

CPU:                       CPU-Independent

COMPONENT:                 ACC/ISC (Adaptive Cruise Control - Interface and State Coordinator)

PACKAGENAME:               isc_ext.h

DESCRIPTION:               External header file for Adaptive Cruise Control (ACC) ISC module in FCT_VEH task

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.10 $

---*/ /*---
CHANGES:                    $Log: isc_ext.h  $
CHANGES:                    Revision 1.10 2018/06/11 15:00:59CEST uidj5069 
CHANGES:                    New Ports added for LOPC based Start Coordination
CHANGES:                    Revision 1.9 2018/04/05 15:02:13CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    <FCT_MEAS_ID_ISC_INPUT_SIGHEADERS> moved to <isc.h>
CHANGES:                    Revision 1.8 2018/02/28 11:53:47CET Mistry, Niraj (uidq5738) 
CHANGES:                    Sigheader and Versionnumber for ports made generic
CHANGES:                    Revision 1.7 2018/02/26 12:00:48CET Mistry, Niraj (uidq5738) 
CHANGES:                    PDO tags moved to new file
CHANGES:                    Revision 1.6 2017/11/20 09:23:32CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Renaming to RTE Port Type Names
CHANGES:                    Revision 1.5 2017/10/12 16:22:59CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Ports for Target Control (ACC) added
CHANGES:                    Revision 1.4 2017/10/11 08:43:22CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Updated <FCT_MEAS_ID_ISC_INPUT_SIGHEADERS>
CHANGES:                    Revision 1.3 2017/10/09 17:00:02CEST Mistry, Niraj (uidq5738) 
CHANGES:                    Switch added
CHANGES:                    Revision 1.2 2017/10/05 08:32:30CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Initial Revision for ACC GEN 4
CHANGES:                    Revision 1.1 2017/03/10 10:48:12CET Koschalka, Mike (uidg3250) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOKMC_LongitudinalKinematicMotionControl/04_Engineering/01_Source_Code/LOKMC/frame_lokmc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lokmc/project.pj
**************************************************************************** */
#ifndef ISC_EXT_H
#define ISC_EXT_H

/*!
   @defgroup isc
   @ingroup fct_veh
@{ */ 

/* Only process rest of file if ACC enabled and long control enabled */
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT))
/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

  
/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! ISC require ports struct */
typedef struct ISC_ReqPortList
{
  const FCTCtrlData_t                     *pt_ISC_IN_Ctrl;

  const ACT_ISC_InformationPort_t         *pt_ISC_IN_IIP;
  const ACT_ISC_CommandPort_t             *pt_ISC_IN_ICP;

#if (FCT_CFG_LOCC_COMPONENT)
  const ACT_CruiseControlStatePort_t      *pt_ISC_IN_CCSP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  const TargetControlStatePort_t          *pt_ISC_IN_TCSP;
#endif

  const ACT_LogicVehicleStatePort_t       *pt_ISC_IN_LVSP;
}
ISC_ReqPortList_t;


/*! ISC provide ports struct */
typedef struct ISC_ProPortList
{
#if (FCT_CFG_LOCC_COMPONENT)
  ACT_CruiseControlCommandPort_t          *pt_ISC_OUT_CCCP;
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  TargetControlCommandPort_t              *pt_ISC_OUT_TCCP;
#endif

  ACT_LogicVehicleCommandPort_t           *pt_ISC_OUT_LVCP;

  ACT_ISC_StatusPort_t                    *pt_ISC_OUT_ISP;
}
ISC_ProPortList_t;


/*! ISC Sync-ref structure. Declared here so that simulation can instantiate */
typedef struct
{
  SignalHeader_t sSigHeader;       /*!<sSigHeader */
  SignalHeader_t t_SH_CTRL;         /*!< Signal Header of control port */

  SignalHeader_t t_ISC_IN_IIP;      /* Signal Header of ISC InformationPort */
  SignalHeader_t t_ISC_IN_ICP;      /* Signal Header of ISC CommandPort */

#if (FCT_CFG_LOCC_COMPONENT)
  SignalHeader_t t_ISC_IN_CCSP;     /* Signal Header of ISC CruiseControlStatePort */
#endif

#if (FCT_CFG_LOHP_COMPONENT)
  SignalHeader_t t_ISC_IN_TCSP;     /* Signal Header of ISC TargetControlStatePort */
#endif

  SignalHeader_t t_ISC_IN_LVSP;     /* Signal Header of ISC LogicVehicleStatusPort */
}
ISC_SyncRef_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
extern void ISC_v_Exec(const ISC_ReqPortList_t *p_RequirePorts, const ISC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_FCTVehFrameFCTOpMode, const AS_t_ServiceFuncts *p_ServiceFuncts);
#else
extern void ISC_v_Exec(const ISC_ReqPortList_t *p_RequirePorts, const ISC_ProPortList_t *p_ProvidePorts, const FCT_OP_MODE_t t_FCTVehFrameFCTOpMode);
#endif


#ifdef __cplusplus
};
#endif


#endif /*!< (FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ISC_COMPONENT) */
#endif  /*!< _ISC_EXT_INCLUDED */

/** @} end defgroup */
