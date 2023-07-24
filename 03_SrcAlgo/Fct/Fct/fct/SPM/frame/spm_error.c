/*! \file **********************************************************************

// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.6 $

---*/ /*---
CHANGES:                   $Log: spm_error.c  $
CHANGES:                   Revision 1.6 2020/06/25 08:10:00CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.5 2018/09/24 15:16:06CEST Pallo, Istvan (palloi) 
CHANGES:                   Add config switch for SRR
CHANGES:                   Revision 1.4 2017/12/05 18:43:52CET Pallo, Istvan (palloi) 
CHANGES:                   Update error out port name
CHANGES:                   Revision 1.3 2017/11/16 14:53:50CET Pallo, Istvan (palloi) 
CHANGES:                   Remove setting error out sig status as is already set in SPMSen_Exec.
CHANGES:                   Revision 1.2 2017/06/21 09:55:26CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove function header.
CHANGES:                   New file header.
CHANGES:                   Revision 1.1 2017/03/17 13:16:56CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "spm_main.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)

/*****************************************************************************
  GLOBAL CONSTANTS (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  GLOBAL VARIABLES (MODULE SCOPE)
*****************************************************************************/


/*****************************************************************************
  LOCAL SYMOBLIC CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL MACROS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPES
*****************************************************************************/


/*****************************************************************************
  LOCAL CONSTANTS
*****************************************************************************/


/*****************************************************************************
  LOCAL TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  LOCAL VARIABLES
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/


/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/

void FCTSen_v_SPMFillErrorOut(SPMErrorOutProPort_t * pt_ErrorOut)
{
  /* Fill in version number */
  pt_ErrorOut->uiVersionNumber = FCT_SEN_ERROR_OUT_INTFVER;
  /* Fill error out; signal status was set previous */
  SPMFillSenErrors(pt_ErrorOut);
}
#endif /*!< #if (FCT_CFG_SIGNAL_PERF_MONITORING) */
#endif /*SPM_SRR_TECHNOLOGY*/
