/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Memo

  MODULNAME:                 memo_cpar_init.h

  DESCRIPTION:            

  AUTHOR:                    Bertrand Godreau

  CREATION DATE:             2013-04-10

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGE:                    $Log: memo_cpar_init.h  $
  CHANGE:                    Revision 1.1 2021/12/13 17:24:14CET Wang, David (Wangd3) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/MEMO/project.pj
  CHANGE:                    Revision 1.0 2017/03/03 10:35:20CET Sorge, Sven (uidg3181) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/MEMO/project.pj
  CHANGE:                    Revision 1.11 2014/03/19 16:21:01CET Godreau, Bertrand (uid28828) 
  CHANGE:                    modify default values for pitch angle
  CHANGE:                    - Added comments -  uid28828 [Mar 19, 2014 4:21:02 PM CET]
  CHANGE:                    Change Package : 210429:2 http://mks-psad:7002/im/viewissue?selection=210429
  CHANGE:                    Revision 1.10 2014/03/11 19:25:10CET Godreau, Bertrand (uid28828) 
  CHANGE:                    update cpar converter and initializerto new Rte CPAR I390
  CHANGE:                    --- Added comments ---  uid28828 [Mar 11, 2014 7:25:11 PM CET]
  CHANGE:                    Change Package : 210429:2 http://mks-psad:7002/im/viewissue?selection=210429
  CHANGE:                    Revision 1.9 2014/01/30 16:13:04CET Godreau, Bertrand (uid28828) 
  CHANGE:                    update signal header
  CHANGE:                    --- Added comments ---  uid28828 [Jan 30, 2014 4:13:05 PM CET]
  CHANGE:                    Change Package : 196596:1 http://mks-psad:7002/im/viewissue?selection=196596
  CHANGE:                    Revision 1.8 2013/10/17 16:14:39CEST Lugez, Boris (uidt2765) 
  CHANGE:                    sync with semo
  CHANGE:                    --- Added comments ---  uidt2765 [Oct 17, 2013 4:14:39 PM CEST]
  CHANGE:                    Change Package : 177526:1 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.7 2013/09/04 15:43:34CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    Complete memo/semo code reorganization
  CHANGE:                    --- Added comments ---  uid28828 [Sep 4, 2013 3:43:35 PM CEST]
  CHANGE:                    Change Package : 177526:4 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.6 2013/08/01 17:12:55CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    remove usage of EMO_DEG2RAD macro is CPar
  CHANGE:                    --- Added comments ---  uid28828 [Aug 1, 2013 5:12:55 PM CEST]
  CHANGE:                    Change Package : 177526:2 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.5 2013/07/26 15:32:49CEST Lugez, Boris (uidt2765) 
  CHANGE:                    update to I310 RTE
  CHANGE:                    --- Added comments ---  uidt2765 [Jul 26, 2013 3:32:49 PM CEST]
  CHANGE:                    Change Package : 177526:1 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.4 2013/05/17 11:57:12CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    trigger cali every frame
  CHANGE:                    --- Added comments ---  uid28828 [May 17, 2013 11:57:12 AM CEST]
  CHANGE:                    Change Package : 177526:2 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.3 2013/04/19 10:59:14CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    remove "Rte_type.h" dependancy
  CHANGE:                    --- Added comments ---  uid28828 [Apr 19, 2013 10:59:15 AM CEST]
  CHANGE:                    Change Package : 177526:2 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.2 2013/04/16 13:03:11CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    force trigger of calibration output every km
  CHANGE:                    --- Added comments ---  uid28828 [Apr 16, 2013 1:03:11 PM CEST]
  CHANGE:                    Change Package : 177526:2 http://mks-psad:7002/im/viewissue?selection=177526
  CHANGE:                    Revision 1.1 2013/04/10 18:46:08CEST Godreau, Bertrand (uid28828) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/EMO_EgoMotion/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/memo/project.pj
**************************************************************************** */
#ifndef memo_cpar_init_h__
#define memo_cpar_init_h__

/*****************************************************************************
  INCLUDES
*****************************************************************************/


sint32 CParInitEmo(CPAR_Emo_t * pCoding)
{
  pCoding->uiVersionNumber                    = CPAR_EMO_INTFVER;

  pCoding->sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
  pCoding->sSignalHeader.uiCycleCounter       = 0;
  pCoding->sSignalHeader.uiMeasurementCounter = 0;
  pCoding->sSignalHeader.uiTimeStamp          = 0;

  pCoding->fCalibCamStartYaw    = 0.0f;
  pCoding->fCalibCamStartRoll   = 0.0f;
  pCoding->fCalibCamStartPitch  = -0.1f;
  pCoding->fCalibCamAbsDevYaw   = 4.0f;
  pCoding->fCalibCamAbsDevRoll  = 4.0f;
  pCoding->fCalibCamMinDevPitch = -4.0f;
  pCoding->fCalibCamMaxDevPitch = 4.0f;

  pCoding->fThreshCaliRollSigmaOk2Nok = 0.003490f;
  pCoding->fThreshCaliRollSigmaNok2Ok = 0.001745f;/*EMO_DEG2RAD(0.1f);*/
 	pCoding->fCaliRollSigmaWindowSize = 350.0f;

 	pCoding->fThreshCaliPitchSigmaOk2Nok = 0.003490f;/*EMO_DEG2RAD(0.2f);*/
 	pCoding->fThreshCaliPitchSigmaNok2Ok = 0.001745f;/*EMO_DEG2RAD(0.1f);*/
 	pCoding->fCaliPitchSigmaWindowSize = 350.0f;

 	pCoding->fThreshCaliYawSigmaOk2Nok = 0.003490f;/*EMO_DEG2RAD(0.2f);*/
 	pCoding->fThreshCaliYawSigmaNok2Ok = 0.001745f;/*EMO_DEG2RAD(0.1f);*/
 	pCoding->fCaliYawSigmaWindowSize = 350.0f;

 	pCoding->fThreshCaliHeightSigmaOk2Nok = 0.02f;
 	pCoding->fThreshCaliHeightSigmaNok2Ok = 0.01f;
 	pCoding->fCaliHeightSigmaWindowSize = 10000.0f;

 	pCoding->fCalibMaxInitialDistance = 350.0f;

  return(0);
}


#endif // memo_cpar_init_h__
