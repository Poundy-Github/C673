/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC4xx

  CPU:                    CPU-Independent

  COMPONENT:              HLA

  MODULNAME:              hla_cpar_init.h

  DESCRIPTION:            Coding parameter initialization service

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          05.04.2013

  VERSION:                $Revision: 1.1 $

  CHANGES:                

  ---*/ /*---
  CHANGE:                 $Log: hla_cpar_init.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:24:06CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Cpar/HLA/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:35:17CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Cpar/HLA/project.pj
  CHANGE:                 Revision 1.16 2014/04/15 09:53:12CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Defined HLA specific KMH2MS and DEG2RAD
  CHANGE:                 - Added comments -  uidv7867 [Apr 15, 2014 9:53:12 AM CEST]
  CHANGE:                 Change Package : 207432:64 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.15 2014/03/31 14:25:04CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Reset default value for always active speed
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 31, 2014 2:25:04 PM CEST]
  CHANGE:                 Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.14 2014/03/19 16:31:15CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:16 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.13 2014/03/19 15:17:00CET Fischer, Alexander (uidv8778) 
  CHANGE:                 Set CountryCode Parameter to normal
  CHANGE:                 --- Added comments ---  uidv8778 [Mar 19, 2014 3:17:00 PM CET]
  CHANGE:                 Change Package : 226009:1 http://mks-psad:7002/im/viewissue?selection=226009
  CHANGE:                 Revision 1.12 2014/03/11 16:11:08CET Manz, Alexander (uidv8777) 
  CHANGE:                 Fix:
  CHANGE:                  - fixed missing call to init parameter for dimming areas
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 11, 2014 4:11:08 PM CET]
  CHANGE:                 Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
  CHANGE:                 Revision 1.11 2014/03/10 13:05:14CET Manz, Alexander (uidv8777) 
  CHANGE:                 Update:
  CHANGE:                  - changed DimmingAreas to match the specs of BMW
  CHANGE:                  - implemented visualization
  CHANGE:                 --- Added comments ---  uidv8777 [Mar 10, 2014 1:05:15 PM CET]
  CHANGE:                 Change Package : 224162:1 http://mks-psad:7002/im/viewissue?selection=224162
  CHANGE:                 Revision 1.10 2014/02/20 08:45:07CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Content of revision 1.8 (to keep master file on trunk and branch SRLCam stuff)
  CHANGE:                 --- Added comments ---  uidv7867 [Feb 20, 2014 8:45:07 AM CET]
  CHANGE:                 Change Package : 207432:26 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.9 2014/02/17 13:01:01CET Manz, Alexander (uidv8777) 
  CHANGE:                 Changed parameter to reflect spec of SRLCam4T0
  CHANGE:                 --- Added comments ---  uidv8777 [Feb 17, 2014 1:01:01 PM CET]
  CHANGE:                 Change Package : 219397:1 http://mks-psad:7002/im/viewissue?selection=219397
  CHANGE:                 Revision 1.8 2014/01/22 10:58:03CET Brunn, Marcus (brunnm) 
  CHANGE:                 updated AlwaysActiveSpeed for BMW from 50km/h to 40km/h
  CHANGE:                 --- Added comments ---  brunnm [Jan 22, 2014 10:58:04 AM CET]
  CHANGE:                 Change Package : 207431:1 http://mks-psad:7002/im/viewissue?selection=207431
  CHANGE:                 Revision 1.7 2013/06/18 15:03:32CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Cosmetic changes
  CHANGE:                 --- Added comments ---  uidv7867 [Jun 18, 2013 3:03:32 PM CEST]
  CHANGE:                 Change Package : 167173:30 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.6 2013/04/25 13:36:18CEST Brunn, Marcus (brunnm) 
  CHANGE:                 fixed city speed thresholds (converted from km/h to m/s)
  CHANGE:                 --- Added comments ---  brunnm [Apr 25, 2013 1:36:19 PM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.5 2013/04/19 12:18:38CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed include files
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 19, 2013 12:18:38 PM CEST]
  CHANGE:                 Change Package : 167173:24 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.4 2013/04/18 16:21:38CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed dependency to hla header file
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 18, 2013 4:21:39 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.3 2013/04/12 12:45:11CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:11 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.2 2013/04/11 16:20:55CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 11, 2013 4:20:55 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.1 2013/04/11 15:53:58CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/00_Custom/sw_support/hla/project.pj
  CHANGE:                 Revision 1.1 2013/04/09 16:32:31CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/00_Custom/hla_wrp/project.pj
  CHANGE:                 
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLA_CPAR_INIT_INCLUDED
#define HLA_CPAR_INIT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

/*****************************************************************************
  MACROS 
*****************************************************************************/
#define C_HLA_PI (3.14159265359f)
#define C_HLA_DEG2RAD(x) ((x)*(C_HLA_PI/180.f))
#define C_HLA_PROCENT(x) ((x)/100.0f)
#define C_HLA_KMH2MS(x)  ((x)/3.6f)
/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/
static void CParInit_HlaPar_AlgoCfg(RTE_HLA_ParameterAlgoCfg_t *pDest);
static void CParInit_HlaPar_Headlight(RTE_HLA_ParameterHeadlight_t *pDest);
static void CParInit_HlaPar_Vehicle(RTE_HLA_ParameterVehicle_t *pDest);
static void CParInit_HlaPar_Country(RTE_HLA_ParameterCountry_t *pDest);
static void CParInit_HlarPar_Roi(RTE_HLAR_ParameterRoi_t *pDest);
static void CParInit_HlarPar_City(RTE_HLAR_ParameterCity_t *pDest);
static void CParInit_HlarPar_Highway(RTE_HLAR_ParameterHighway_t *pDest);
static void CParInit_HlarPar_Tunnel(RTE_HLAR_ParameterTunnel_t *pDest);
static void CParInit_HlarPar_TrafficStyle(RTE_HLAR_ParameterTrafficStyle_t *pDest);
static void CParInit_HlarPar_Ambient(RTE_HLAR_ParameterAmbient_t *pDest);
static void CParInit_HlarPar_Vehicle(RTE_HLAR_ParameterVehDet_t *pDest);
static void CParInit_HlarPar_LightPair(RTE_HLAR_ParameterLightPair_t *pDest);
static void CParInit_HlarPar_DistEst(RTE_HLAR_ParameterDistEst_t *pDest);
static void CParInit_HlarPar_TTBEst(RTE_HLAR_ParameterTTBEst_t *pDest);
static void CParInit_HlafPar_TurnOff(RTE_HLAF_ParameterTurnOff_t *pDest);
static void CParInit_HlafPar_KeepOff(RTE_HLAF_ParameterKeepOff_t *pDest);
static void CParInit_HlafPar_TurnOnDelay(RTE_HLAF_ParameterTurnOnDelay_t *pDest);
static void CParInit_HlafPar_Speed(RTE_HLAF_ParameterSpeed_t *pDest);
static void CParInit_HlafPar_Blockage(RTE_HLAF_ParameterBlockage_t *pDest);
static void CParInit_HlafPar_Dimming(RTE_HLAF_ParameterDimming_t *pDest);
static void CParInit_HlafPar_Fog(RTE_HLAF_ParameterFog_t *pDest);
static void CParInit_HlafPar_Matrix(RTE_HLAF_ParameterMatrixBeam_t *pDest);

#ifndef PC_SIM
int CParInit_HlaPar(CPAR_HLA_Parameter_t *pCPar_HlaPar)
{
  sint32 ret_val = 0;
  if (pCPar_HlaPar != NULL) 
  { 
    pCPar_HlaPar->VersionNumber     = CPAR_HLA_PARAMETER_INTFVER;
    pCPar_HlaPar->Header.eSigStatus = SIGNAL_VALID;
    pCPar_HlaPar->HLAType           = RTE_HLA_TYPE_UNKNOWN;
    CParInit_HlaPar_AlgoCfg(&pCPar_HlaPar->AlgoCfg);
    CParInit_HlaPar_Headlight(&pCPar_HlaPar->Headlight);
    CParInit_HlaPar_Vehicle(&pCPar_HlaPar->Vehicle);
    CParInit_HlaPar_Country(&pCPar_HlaPar->Country);
  }
  else
  {
    ret_val = -1;
  }
  return(ret_val);
}

int CParInit_HlarPar(CPAR_HLAR_Parameter_t *pCPar_HlarPar)
{
  sint32 ret_val = 0;
  if (pCPar_HlarPar != NULL) 
  { 
    pCPar_HlarPar->VersionNumber     = CPAR_HLAR_PARAMETER_INTFVER;
    pCPar_HlarPar->Header.eSigStatus = SIGNAL_VALID;
    CParInit_HlarPar_Roi(&pCPar_HlarPar->Roi);
    CParInit_HlarPar_City(&pCPar_HlarPar->City);
    CParInit_HlarPar_Highway(&pCPar_HlarPar->Highway);
    CParInit_HlarPar_Tunnel(&pCPar_HlarPar->Tunnel);
    CParInit_HlarPar_TrafficStyle(&pCPar_HlarPar->TrafficStyle);
    CParInit_HlarPar_Ambient(&pCPar_HlarPar->Ambient);
    CParInit_HlarPar_Vehicle(&pCPar_HlarPar->Vehicle);
    CParInit_HlarPar_LightPair(&pCPar_HlarPar->LightPair);
    CParInit_HlarPar_DistEst(&pCPar_HlarPar->DistEst);
    CParInit_HlarPar_TTBEst(&pCPar_HlarPar->TTBEst);  
  }
  else
  {
    ret_val = -1;
  }
  return(ret_val);
}


int CParInit_HlafPar(CPAR_HLAF_Parameter_t *pCPar_HlafPar)
{
  sint32 ret_val = 0;
  if (pCPar_HlafPar != NULL) 
  { 
    pCPar_HlafPar->VersionNumber     = CPAR_HLAF_PARAMETER_INTFVER;
    pCPar_HlafPar->Header.eSigStatus = SIGNAL_VALID;
    CParInit_HlafPar_TurnOff(&pCPar_HlafPar->TurnOff);
    CParInit_HlafPar_KeepOff(&pCPar_HlafPar->KeepOff);
    CParInit_HlafPar_TurnOnDelay(&pCPar_HlafPar->TurnOnDelay);
    CParInit_HlafPar_Speed(&pCPar_HlafPar->Speed);
    CParInit_HlafPar_Blockage(&pCPar_HlafPar->Blockage);
    CParInit_HlafPar_Dimming(&pCPar_HlafPar->Dimming);
    CParInit_HlafPar_Fog(&pCPar_HlafPar->Fog);
    CParInit_HlafPar_Matrix(&pCPar_HlafPar->Matrix);
  }
  else
  {
    ret_val = -1;
  }
  return(ret_val);
}
#endif /* PC_SIM */

/*****************************************************************************
  LOCAL FUNCTIONS 
*****************************************************************************/
static void CParInit_HlaPar_AlgoCfg(RTE_HLA_ParameterAlgoCfg_t *pDest)
{
    pDest->TestMode          = RTE_HLA_TESTMODE_INACTIVE;
    pDest->CityDetection     = RTE_HLA_CITYDET_ACTIVE;
    pDest->TunnelDetection   = RTE_HLA_TUNNELDET_ACTIVE;
    pDest->BadPixelDetection = RTE_HLA_BADPIXELDET_ACTIVE;
    pDest->FogDetection      = RTE_HLA_FOGDET_ACTIVE;
    pDest->BlockageDetection = RTE_HLA_BLOCKDET_ACTIVE;
}

static void CParInit_HlaPar_Headlight(RTE_HLA_ParameterHeadlight_t *pDest)
{
#if 1
  /* For BMW SMFC4B0 */
  pDest->HeadLightType          = RTE_HLA_LTYPE_LED;
  pDest->HeadLightMechanics     = RTE_HLA_LMECH_ROLLER;
  pDest->SpotLight              = RTE_HLA_SPOTLIGHT_NAVL;
  pDest->SpotLightWidth         = C_HLA_DEG2RAD(0.0f);
  pDest->FullHBDefaultPos_Left  = C_HLA_DEG2RAD(0.0f);
  pDest->FullHBDefaultPos_Right = C_HLA_DEG2RAD(0.0f);
  pDest->HeadLampLatency        = 0.0f;
  pDest->SpotLightTolerance     = C_HLA_DEG2RAD(0.0f);
#else
  /* Daimler MFC3xx values */
  pDest->HeadLightType          = RTE_HLA_LTYPE_XENON;
  pDest->HeadLightMechanics     = RTE_HLA_LMECH_ROLLER;
  pDest->SpotLight              = RTE_HLA_SPOTLIGHT_NAVL;
  pDest->SpotLightWidth         = 0.0f;
  pDest->FullHBDefaultPos_Left  = C_HLA_DEG2RAD(-1.6f);
  pDest->FullHBDefaultPos_Right = C_HLA_DEG2RAD( 1.0f);
  pDest->HeadLampLatency        = 0.1f;
  pDest->SpotLightTolerance     = 0.0f;
#endif
}

static void CParInit_HlaPar_Vehicle(RTE_HLA_ParameterVehicle_t *pDest)
{
  pDest->WindshieldType = RTE_HLA_WTYPE_UNKNOWN;
}

static void CParInit_HlaPar_Country(RTE_HLA_ParameterCountry_t *pDest)
{
  pDest->TrafficStyle                  = RTE_HLA_TRAFFIC_STYLE_RHD;
  pDest->SensitivityMode               = RTE_HLA_SENSMODE_NORMAL;
  pDest->CountryWithMultipleReflectors = RTE_HLA_MREFL_INACTIVE;
  pDest->CountryCode                   = RTE_HLA_COUNTRY_CODE_NORMAL;
}

static void CParInit_HlarPar_Roi(RTE_HLAR_ParameterRoi_t *pDest)
{
  pDest->FOV_Horizontal              = C_HLA_DEG2RAD(38.0f);
  pDest->FOV_FunctionRoiAboveHorizon = C_HLA_DEG2RAD(4.0f);
  pDest->FOV_MinBelowHorizon         = C_HLA_DEG2RAD(4.0f);
  pDest->FOV_MinAboveHorizon         = C_HLA_DEG2RAD(7.0f);
  pDest->PrecVehLight_minDistance    = 3.7f;
  pDest->PrecVehLight_minHeight      = 0.7f;
  pDest->StreetLamp_Distance         = 30.0f;
  pDest->StreetLamp_Height           = 6.0f;
}

static void CParInit_HlarPar_City(RTE_HLAR_ParameterCity_t *pDest)
{
  pDest->SpeedThresholdLow                       = C_HLA_KMH2MS(60.0f);
  pDest->SpeedThresholdHigh                      = C_HLA_KMH2MS(100.0f);
  pDest->NumLeavingStreetlamp_LowSpeed           = 2u;
  pDest->NumLeavingStreetlamp_HighSpeed          = 2u;
  pDest->NumSceneStreetlamp_LowSpeed             = 1u;
  pDest->NumSceneStreetlamp_HighSpeed            = 1u;
  pDest->AmbientLevel_LowSpeed                   = 100u;
  pDest->AmbientLevel_HighSpeed                  = 125u;
  pDest->StreetLampMaxInterDist_LowSpeed         = 105.0f;
  pDest->StreetLampMaxInterDist_HighSpeed        = 105.0f;
  pDest->StreetLampMaxDist_LowSpeed              = 80.0f;
  pDest->StreetLampMaxDist_HighSpeed             = 160.0f;
  pDest->LeavingCityDelay_LowSpeed               = 50.0f;
  pDest->LeavingCityDelay_HighSpeed              = 50.0f;
  pDest->LeavingCityDelaySceneStreetlamp_LowInt  = 60.0f;
  pDest->LeavingCityDelaySceneStreetlamp_HighInt = 140.0f;
  pDest->NumTunnelStreetlamp                     = 3u;
}

static void CParInit_HlarPar_Highway(RTE_HLAR_ParameterHighway_t *pDest)
{
  pDest->SpeedDetThreshold_Fast               = C_HLA_KMH2MS(140.0f);
  pDest->SpeedDetThreshold                    = C_HLA_KMH2MS(120.0f);
  pDest->SpeedDetThresholdDistance            = 400.0f;
  pDest->EgoMotionDetThresholdHigh            = C_HLA_KMH2MS(80.0f);
  pDest->EgoMotionDetThresholdLow             = C_HLA_KMH2MS(65.0f);
  pDest->LateralPositionUsedTracks            = 7u;
  pDest->LateralPositionConfidenceThreshHigh  = C_HLA_PROCENT(75.0f);
  pDest->LateralPositionConfidenceThreshLow   = C_HLA_PROCENT(25.0f);
  pDest->OcclusionOncomingLeavingLightsThresh = 5u;
  pDest->OcclusionConfidenceStep              = C_HLA_PROCENT(15.0f);
}

static void CParInit_HlarPar_Tunnel(RTE_HLAR_ParameterTunnel_t *pDest)
{
  pDest->EntryThreshHigh       = C_HLA_PROCENT(78.0f);
  pDest->EntryThreshLow        = C_HLA_PROCENT(71.0f);
  pDest->EntryDistanceMin      = 10.0f;
  pDest->EntryDistanceMax      = 35.0f;
  pDest->ExitThreshHigh        = C_HLA_PROCENT(175.0f);
  pDest->ExitThreshLow         = C_HLA_PROCENT(170.0f);
  pDest->ExitDistanceMin       = 10.0f;
  pDest->DetectionTypeDistance = 100.0f;
}

static void CParInit_HlarPar_TrafficStyle(RTE_HLAR_ParameterTrafficStyle_t *pDest)
{
  pDest->NumOncLightsThres = 100u;
  pDest->NumOncLightsLock  = 200u;
}

static void CParInit_HlarPar_Ambient(RTE_HLAR_ParameterAmbient_t *pDest)
{
  pDest->SpeedThreshold               = C_HLA_KMH2MS(85.0f);
  pDest->AmbientLevel_LowSpeed        = 100u;
  pDest->AmbientLevel_HighSpeed       = 125u;
  pDest->Day2NightTimeThres_LowSpeed  = 5.0f;
  pDest->Day2NightTimeThres_HighSpeed = 5.0f;
  pDest->Day2NightDistThres_LowSpeed  = 150.0f;
  pDest->Day2NightDistThres_HighSpeed = 150.0f;
  pDest->Night2DayTimeThres_LowSpeed  = 3.0f;
  pDest->Night2DayTimeThres_HighSpeed = 3.0f;
  pDest->Night2DayDistThres_LowSpeed  = 100.0f;
  pDest->Night2DayDistThres_HighSpeed = 100.0f;
}

static void CParInit_HlarPar_Vehicle(RTE_HLAR_ParameterVehDet_t *pDest)
{
  pDest->OncSensitivity  = 100u;
  pDest->PrecSensitivity = 100u;
}

static void CParInit_HlarPar_LightPair(RTE_HLAR_ParameterLightPair_t *pDest)
{
  pDest->TaillightWidth_Min  = 0.6f;
  pDest->TaillightWidth_Max  = 2.2f;
  pDest->HeadlightWidth_Min  = 1.0f;
  pDest->HeadlightWidth_Max  = 2.4f;
  pDest->TaillightHeight_Min = 0.35f;
  pDest->TaillightHeight_Max = 1.5f;
  pDest->HeadlightHeight_Min = 0.5f;
  pDest->HeadlightHeight_Max = 1.2f;
}

static void CParInit_HlarPar_DistEst(RTE_HLAR_ParameterDistEst_t *pDest)
{
  pDest->LightHeight_Min = 0.0f;
  pDest->LightHeight_Max = 0.6f;
  pDest->DistFilterConst = 0.8f;
}

static void CParInit_HlarPar_TTBEst(RTE_HLAR_ParameterTTBEst_t *pDest)
{
  pDest->ttbAngle = C_HLA_DEG2RAD(18.0f);
}

static void CParInit_HlafPar_TurnOff(RTE_HLAF_ParameterTurnOff_t *pDest)
{
  pDest->TTBThreshold    = 1.0f;
  pDest->HorAngThreshold = C_HLA_DEG2RAD(16.0f);
}

static void CParInit_HlafPar_KeepOff(RTE_HLAF_ParameterKeepOff_t *pDest)
{
  pDest->SmallRadius.Radius2TurnsOnThres = 120.0f;
  pDest->SmallRadius.TurnOnDelay         = 0.25f;
}

static void CParInit_HlafPar_TurnOnDelay(RTE_HLAF_ParameterTurnOnDelay_t *pDest)
{
  pDest->OncomingMin_DistThreshold    = 30.0f;
  pDest->OncomingMin_LatDistThreshold = 1.5f;
  pDest->OncomingMin                  = 0.6f;
  pDest->OncomingMax                  = 1.5f;
  pDest->OncomingMaxHighway           = 1.5f;
  pDest->PrecedingMin                 = 0.06f;
  pDest->PrecedingTimeGap_Threshold   = 2.0f;
  pDest->PrecedingTimeGap             = 2.0f;
  pDest->PrecedingMinWiperOn          = 3.0f;
  pDest->PrecedingMaxShort            = 3.0f;
  pDest->PrecedingMaxLong             = 3.0f;
  pDest->SlowOvertaking               = 8.0f;
  pDest->Fog                          = 10.0f;
  pDest->City                         = 10.0f;
  pDest->Tunnel                       = 50.0f;
}

static void CParInit_HlafPar_Speed(RTE_HLAF_ParameterSpeed_t *pDest)
{
  pDest->DeactivateSpeed          = C_HLA_KMH2MS(30.0f);
  pDest->ActivateSpeed            = C_HLA_KMH2MS(40.0f);
  pDest->AlwaysActiveSpeed        = C_HLA_KMH2MS(50.0f);
  pDest->KeepOff_VeryLowSpeed     = C_HLA_KMH2MS(12.6f);
  pDest->KeepOff_LowRadius        = 0.0f;
  pDest->KeepOff_HighAcceleration = 2.5f;
  pDest->KeepOff_AccTime          = 2.5f;
  pDest->KeepOff_Delay            = 2.0f;
}

static void CParInit_HlafPar_Blockage(RTE_HLAF_ParameterBlockage_t *pDest)
{
  pDest->ConfidenceThreshold            = C_HLA_PROCENT(80.0f);
  pDest->ClearMeas2Blockage_DistThres   = 500.0f;
  pDest->ClearMeas2Blockage_TimeThres   = 30.0f;
  pDest->ClearMeas2NoBlockage_DistThres = 50.0f;
  pDest->NoBlockage2Blockage_DistThres  = 50.0f;
  pDest->NoBlockage2Blockage_TimeThres  = 2.5f;
  pDest->Blockage2NoBlockage_TimeThres  = 120.0f;
  pDest->ManualOverwrite                = RTE_HLA_BLOCKMANOW_ACTIVE;
}

static void CParInit_HlafPar_Dimming(RTE_HLAF_ParameterDimming_t *pDest)
{
  pDest->DimmingDetection     = RTE_HLA_DIMMDET_ACTIVE;
  pDest->ReductThreshLevel1   = 90u;
  pDest->ReductThreshLevel2   = 80u;
  pDest->TurnOnDelay          = 0.3f;
  pDest->AreaRightBorderArray[0] = C_HLA_DEG2RAD(-7.0f);
  pDest->AreaRightBorderArray[1] = C_HLA_DEG2RAD(-4.0f);
  pDest->AreaRightBorderArray[2] = C_HLA_DEG2RAD( 4.0f);
  pDest->AreaRightBorderArray[3] = C_HLA_DEG2RAD( 7.0f);
}

static void CParInit_HlafPar_Fog(RTE_HLAF_ParameterFog_t *pDest)
{
  pDest->ConfidenceThreshold = 80u;
  pDest->Sensitivity         = 100u;
}

static void CParInit_HlafPar_Matrix(RTE_HLAF_ParameterMatrixBeam_t *pDest)
{  
  pDest->MaxNumGlarefreeArea = 1u;
}


/* avoid cyclic binding ---------------------------------------------------*/
#endif /* #ifndef HLA_CPAR_INIT_INCLUDED */
