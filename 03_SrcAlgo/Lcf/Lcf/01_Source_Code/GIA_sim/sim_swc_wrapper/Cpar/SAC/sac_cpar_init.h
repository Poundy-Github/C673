/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Sac

  MODULNAME:                 sac_cpar_init.h

  DESCRIPTION:               Initializer code for CodingParameters (CPar)

  AUTHOR:                    Thomas Ruland

  CREATION DATE:             2013-04-10

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: sac_cpar_init.h  $
  CHANGES:                   Revision 1.1 2021/12/13 17:24:22CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/SAC/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:35:22CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/SAC/project.pj
  CHANGES:                   Revision 1.4 2013/04/11 14:43:32CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   - added missing include guards
  CHANGES:                   - Added comments -  uidw0251 [Apr 11, 2013 2:43:32 PM CEST]
  CHANGES:                   Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:                   Revision 1.3 2013/04/11 13:35:34CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   - set defaults for CPARs
  CHANGES:                   - fixed internal MF IDs
  CHANGES:                   --- Added comments ---  uidw0251 [Apr 11, 2013 1:35:35 PM CEST]
  CHANGES:                   Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:                   Revision 1.2 2013/04/10 18:07:58CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   - added placeholder values
  CHANGES:                   --- Added comments ---  uidw0251 [Apr 10, 2013 6:07:59 PM CEST]
  CHANGES:                   Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:                   Revision 1.1 2013/04/10 18:07:09CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/sac/project.pj


**************************************************************************** */

#ifndef sac_cpar_init_h
#define sac_cpar_init_h

int CParInitSac(CPAR_SacRte_t * pCoding) {

  pCoding->uiVersionNumber = CPAR_SAC_RTE_INTFVER;
  pCoding->sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
  pCoding->sSignalHeader.uiCycleCounter = 0;
  pCoding->sSignalHeader.uiMeasurementCounter = 0;
  pCoding->sSignalHeader.uiTimeStamp = 0;
  for(uint8 k=0; k<SAC_RTE_WSM_COEFFICIENT_COUNT; ++k) {
    pCoding->aWindshieldModelCoefficients[k] = 0.f;
  }
  pCoding->eInputCheckerMode = SAC_RTE_INPUT_CHECKER_MODE_ON;
  pCoding->eOutputCheckerMode = SAC_RTE_OUTPUT_CHECKER_MODE_ON;
  pCoding->fStandaloneModeCalibDistTheshold = 50.f;
  pCoding->fParallelModeCalibDistThreshold = 500.f;
  pCoding->fRectificationErrorThreshold = .7f;
  pCoding->fDisparityDensityThreshold = .9f;

  return 0;
}

#endif