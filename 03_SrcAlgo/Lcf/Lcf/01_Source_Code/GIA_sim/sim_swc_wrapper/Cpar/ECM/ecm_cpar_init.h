/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 ECM

  MODULNAME:                 ecm_cpar_init.h

  DESCRIPTION:               Initializer code for CodingParameters (CPar)

  AUTHOR:                    Arnaud Faure

  CREATION DATE:             2013-04-11

  VERSION:                   $Revision: 1.1 $


  ---*/ /*---
  CHANGES:                   $Log: ecm_cpar_init.h  $
  CHANGES:                   Revision 1.1 2021/12/13 17:23:57CET Wang, David (Wangd3) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/ECM/project.pj
  CHANGES:                   Revision 1.0 2017/03/03 10:35:13CET Sorge, Sven (uidg3181) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/ECM/project.pj
  CHANGES:                   Revision 1.2 2013/04/19 11:56:45CEST Faure, Arnaud (uidv0442) 
  CHANGES:                   Macro definition for DEG2RAD and C_PI
  CHANGES:                   - Added comments -  uidv0442 [Apr 19, 2013 11:56:46 AM CEST]
  CHANGES:                   Change Package : 174466:1 http://mks-psad:7002/im/viewissue?selection=174466
  CHANGES:                   Revision 1.1 2013/04/11 15:12:13CEST Faure, Arnaud (uidv0442) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ECM_EOLCalibrationMono/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/ecm/project.pj
  CHANGES:                   Revision 1.1 2013/04/11 15:03:25CEST Faure, Arnaud (uidv0442) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ECM_EOLCalibrationMono/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/project.pj
  CHANGES:                   Revision 1.2 2013/04/10 18:07:58CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   - added placeholder values
  CHANGES:                   --- Added comments ---  uidw0251 [Apr 10, 2013 6:07:59 PM CEST]
  CHANGES:                   Change Package : 173649:1 http://mks-psad:7002/im/viewissue?selection=173649
  CHANGES:                   Revision 1.1 2013/04/10 18:07:09CEST Ruland, Thomas (uidw0251) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/sac/project.pj


**************************************************************************** */

#ifndef ecm_cpar_init_h
#define ecm_cpar_init_h

/*! Constant PI */
#ifndef C_PI
#define C_PI  (3.14159265359F)
#endif
/*! Conversion of angle from degree to radian unit */
#ifndef DEG2RAD
#define DEG2RAD(deg_)  ((deg_)*(C_PI/180.F))
#endif

int CParInitEcm(CPAR_EcmRte_t * pCoding) {

	pCoding->fBoardPositionXMax = 5.0f;
	pCoding->fBoardPositionXMin = 0.1f;
	pCoding->fBoardPositionYMax = 1.5f;
	pCoding->fBoardPositionYMin = -1.5f;
	pCoding->fBoardPositionZMax = 4.0f;
	pCoding->fBoardPositionZMin = 0.1f;

	pCoding->fMaxBrightness = 0.8f;
	pCoding->fMinBrightness = 0.2f;

	pCoding->fMaxContrast = 0.98f;
	pCoding->fMinContrast = 0.20f;

	pCoding->fMaxRuntimeCycles = 3000.0f / 0.06f ;
	pCoding->fMaxRuntimeMs = 3000.0f;

	pCoding->fSensorSocketPositionXMax = 1.0f;
	pCoding->fSensorSocketPositionXMin = -3.0f;
	pCoding->fSensorSocketPositionYMax = 1.5f;
	pCoding->fSensorSocketPositionYMin = -1.5f;
	pCoding->fSensorSocketPositionZMax = 4.0f;
	pCoding->fSensorSocketPositionZMin = 0.1f;

	pCoding->sPattern.fWidth	= 0.315f;
	pCoding->sPattern.fHeight	= 0.200f;
	pCoding->sPattern.fDistanceCircle2Circle	= 0.240f;
	pCoding->sPattern.fDistanceCircle2Center	= 0.120f;
	pCoding->sPattern.fOuterCircleDiameter		= 0.045f;
	pCoding->sPattern.fInnerCircleDiameter		= 0.015f;

	pCoding->sSensorOrientationTolerances.sToleranceNegative.f32_Pitch = - DEG2RAD(3.0f);
	pCoding->sSensorOrientationTolerances.sToleranceNegative.f32_Roll  = - DEG2RAD(4.5f);
	pCoding->sSensorOrientationTolerances.sToleranceNegative.f32_Yaw   = - DEG2RAD(4.0f);
	pCoding->sSensorOrientationTolerances.sToleranceNegative.ui32_Quality = 25u;

	pCoding->sSensorOrientationTolerances.sTolerancePositive.f32_Pitch = DEG2RAD(3.0f);
	pCoding->sSensorOrientationTolerances.sTolerancePositive.f32_Roll  = DEG2RAD(4.5f);
	pCoding->sSensorOrientationTolerances.sTolerancePositive.f32_Yaw   = DEG2RAD(4.0f);
	pCoding->sSensorOrientationTolerances.sTolerancePositive.ui32_Quality = 25u;

	pCoding->uiVersionNumber = CPAR_ECM_RTE_INTFVER;	
	pCoding->sSignalHeader.eSigStatus = AL_SIG_STATE_OK;
	pCoding->sSignalHeader.uiCycleCounter = 0u;
	pCoding->sSignalHeader.uiMeasurementCounter = 0u;
	pCoding->sSignalHeader.uiTimeStamp = 0u;

	pCoding->uiMaxCircleListElements = 10u;
	pCoding->uiMaxPatternDimension = 32u;

  return 0;
}

#endif