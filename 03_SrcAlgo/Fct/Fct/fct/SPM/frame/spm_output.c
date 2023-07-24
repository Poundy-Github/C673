/*! \file **********************************************************************
// COMPANY:   Continental Automotive
// COMPONENT: SPM_SensorPerformanceMonitoring
// VERSION:   $Revision: 1.6 $

---*/ /*---
CHANGES:                   $Log: spm_output.c  $
CHANGES:                   Revision 1.6 2020/07/01 07:39:06CEST Pallo, Istvan (palloi) 
CHANGES:                   Fix empty C file warning
CHANGES:                   Revision 1.5 2020/06/25 08:07:02CEST Pallo, Istvan (palloi) 
CHANGES:                   Update code for SPM split - SRR
CHANGES:                   Revision 1.4 2017/08/18 16:40:45CEST uidj3583 
CHANGES:                   Comment out custom functions
CHANGES:                   Revision 1.3 2017/07/28 07:07:13CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove static from function header.
CHANGES:                   Revision 1.2 2017/06/21 09:26:03CEST Pallo, Istvan (palloi) 
CHANGES:                   Remove functions headers.
CHANGES:                   Remove function declaration.
CHANGES:                   Revision 1.1 2017/03/17 13:16:58CET Kober, Manfred (uidv8885) 
CHANGES:                   Initial revision
CHANGES:                   Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/frame/project.pj

**************************************************************************** */


/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "spm.h"

#if(SPM_SRR_TECHNOLOGY == SWITCH_OFF)
#if (FCT_CFG_SIGNAL_PERF_MONITORING)

#if defined __cplusplus
extern "C"{
#endif
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


#if (FCT_CFG_CUSTOM_IO_INTERFACE)
//void SPM_v_CustomProcess(void)
//{
//  /*! Set SPM custom output */
//  SPM_v_SetCustomOuput(FCTSEN_pCustomOutput);
//}
//
//
//void SPM_v_SetCustomOuput(FCTCustomOutput_t * p_SPMCustomOutput)
//{
//  float32 fScaleTemp;
//
//  /* Fill blockage debug information for meas purposes */
//  p_SPMCustomOutput->BlockageInfo.eSPMBlockageState  = SPMData.SPMBlockageState;
//  p_SPMCustomOutput->BlockageInfo.eSPMSelfTestState  = SPMData.SPMSelftestState;
//  p_SPMCustomOutput->BlockageInfo.ucEstiRange        = (uint8)SPMData.SPMBlockageRange;
//  fScaleTemp = SPMData.SPMBlockageRangeConf * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucEstiRangeConf    = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageRangeProb * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucEstiRangeProb    = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageObjLossProb * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucObjLossProb      = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageObjLossConf * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucObjLossConf      = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageProbability * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucOverallProb      = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageConfidence * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucOverallConf      = (uint8)(fScaleTemp);
//  p_SPMCustomOutput->BlockageInfo.usRoadbeamTimeCnt  = 0u;
//  fScaleTemp = MIN(SPMData.SPMBlockageTimeoutWayCounter, 65535.f);
//  p_SPMCustomOutput->BlockageInfo.usTimeoutWayCnt    = (uint16)(fScaleTemp);
//  fScaleTemp = MIN(SPMData.SPMBlockageTimeoutTimeCounter, 255.f);
//  p_SPMCustomOutput->BlockageInfo.ucTimeoutTimeCnt   = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageTimeoutBlockProb * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkProb   = (uint8)(fScaleTemp);
//  fScaleTemp = SPMData.SPMBlockageTimeoutBlockConf * 100.f;
//  p_SPMCustomOutput->BlockageInfo.ucTimeoutBlkConf   = (uint8)(fScaleTemp);
//  fScaleTemp = MIN(SPMData.SPMFullBlockageTimer, 65535.f);
//  p_SPMCustomOutput->BlockageInfo.usFullBlkTimer     = (uint16)(fScaleTemp);
//}

#endif

#if defined __cplusplus
};
#endif

#endif /*!< FCT_CFG_SIGNAL_PERF_MONITORING */
#endif/*SPM_SRR_TECHNOLOGY*/

