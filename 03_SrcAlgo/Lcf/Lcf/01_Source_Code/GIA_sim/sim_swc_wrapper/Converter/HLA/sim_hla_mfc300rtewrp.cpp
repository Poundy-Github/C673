#include <string.h>
#include "sim_hla_mfc300rtewrp.h"
//#include "sim_hla_meas.h"
//#include "cml_ext.h"


void HLA_SetReqPorts_frm_HLAR(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{    
  /* Filling ReqPorts from HLAR Input Parameters */
  HLA_SetReqPortsHLARParam(pReqPorts, pHLAR_InWrite);

  /* Filling ReqPorts from HLAR Input Signals */
  HLA_SetReqPortsHLARSig(pReqPorts, pHLAR_InWrite);

  HLA_SetSigStatus(pReqPorts, pHLAR_InWrite);

}


/* Set Reqports from HLAR Param */
static void HLA_SetReqPortsHLARParam( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{  
  HLA_SetReqPortsHLARParamCamParam(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARParamSensorSocket(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARParamSensorAngles(pReqPorts, pHLAR_InWrite);

    
  //memcpy(pReqPorts->pCPar_HlaPar, &pHLAR_InWrite->s_Par.s_HlaPar , sizeof(CPAR_HLA_Parameter_t));
  //memcpy(pReqPorts->pCPar_HlarPar, &pHLAR_InWrite->s_Par.s_HlarPar, sizeof(CPAR_HLAR_Parameter_t));                                            
}

/* Fills ReqPorts from structure HLAR_t_InputSignals */
static void HLA_SetReqPortsHLARSig( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  HLA_SetReqPortsHLARSigAvl(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARSigImgState(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARSigHeadlightState(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARSigCaliOnline(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARSigDefPixList(pReqPorts, pHLAR_InWrite);

  HLA_SetReqPortsHLARSigTrafStyle(pReqPorts, pHLAR_InWrite);
}


/* Fill ReqPorts from structure HLA_t_CameraParameter */
static void HLA_SetReqPortsHLARParamCamParam(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  switch(pHLAR_InWrite->s_Par.s_CameraParameter.e_bayerPattern)
  {
  case HLA_BAYERPATTERN_UNKNOWN:
    pReqPorts->pSig_ImgCharOdd->e_ImagerCFA = IC_IMAGER_CFA_UNKNOWN;
    break;
  case HLA_BAYERPATTERN_RGGB:
    pReqPorts->pSig_ImgCharOdd->e_ImagerCFA = IC_IMAGER_CFA_RGGB;
    break;
  case HLA_BAYERPATTERN_GRBG:
    pReqPorts->pSig_ImgCharOdd->e_ImagerCFA = IC_IMAGER_CFA_GRBG;
    break;
  case HLA_BAYERPATTERN_GBRG:
    pReqPorts->pSig_ImgCharOdd->e_ImagerCFA = IC_IMAGER_CFA_GBRG;
    break;
  case HLA_BAYERPATTERN_BGGR:
    pReqPorts->pSig_ImgCharOdd->e_ImagerCFA = IC_IMAGER_CFA_BGGR;
    break;
  case HLA_BAYERPATTERN_INVALID:
  default:    
    break;
  }

  pReqPorts->pSig_HlaSig->CycleTime = pHLAR_InWrite->s_Par.s_CameraParameter.f32_cycleTime;
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fFocalX = pHLAR_InWrite->s_Par.s_CameraParameter.s_FocalLength.f32_x; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fFocalY = pHLAR_InWrite->s_Par.s_CameraParameter.s_FocalLength.f32_y; /* NEW CALI */
  pReqPorts->pSig_ImgCharOdd->s_ImagerSize.ui16_Width = pHLAR_InWrite->s_Par.s_CameraParameter.s_ImageSize.ui32_x;
  pReqPorts->pSig_ImgCharOdd->s_ImagerSize.ui16_Height = pHLAR_InWrite->s_Par.s_CameraParameter.s_ImageSize.ui32_y;
  pReqPorts->pSig_ImgCharOdd->s_ImagerCroi.ui16_Width = pHLAR_InWrite->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_x;
  pReqPorts->pSig_ImgCharOdd->s_ImagerCroi.ui16_Height = pHLAR_InWrite->s_Par.s_CameraParameter.s_CroppedRoiSize.ui32_y;
  pReqPorts->pSig_ImgCharOdd->s_ImagerCroi.ui16_X = pHLAR_InWrite->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_x;
  pReqPorts->pSig_ImgCharOdd->s_ImagerCroi.ui16_Y = pHLAR_InWrite->s_Par.s_CameraParameter.s_CroppedRoiX1.ui32_y;
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fCenterX = pHLAR_InWrite->s_Par.s_CameraParameter.s_LensCenter.f32_x; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fCenterY = pHLAR_InWrite->s_Par.s_CameraParameter.s_LensCenter.f32_y; /* NEW CALI */
#if(MFC_MONO_CALIBRATION_DIST_COEFFICIENT_COUNT < 5u)
#error MFC_MONO_CALIBRATION_DIST_COEFFICIENT_COUNT is smaller than number of distorition coefficients
#endif
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fDistortionCoefficients[0] = pHLAR_InWrite->s_Par.s_CameraParameter.s_Distortion.f32_K1; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fDistortionCoefficients[1] = pHLAR_InWrite->s_Par.s_CameraParameter.s_Distortion.f32_K2; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fDistortionCoefficients[2] = pHLAR_InWrite->s_Par.s_CameraParameter.s_Distortion.f32_K3; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fDistortionCoefficients[3] = pHLAR_InWrite->s_Par.s_CameraParameter.s_Distortion.f32_K4; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sIntrinsic.fDistortionCoefficients[4] = pHLAR_InWrite->s_Par.s_CameraParameter.s_Distortion.f32_K5; /* NEW CALI */

  HLA_SetReqPortsHLARParamRGBLuxTable(pReqPorts, pHLAR_InWrite);
}


/* Fills Reqports from  structure HLA_t_SensorSocket */
void HLA_SetReqPortsHLARParamSensorSocket(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{ 
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fTx = pHLAR_InWrite->s_Par.s_SensorSocket.f32_X; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fTy = pHLAR_InWrite->s_Par.s_SensorSocket.f32_Y; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fTz = pHLAR_InWrite->s_Par.s_SensorSocket.f32_Z; /* NEW CALI */
}


/* Fills Reqports from structure HLA_t_SensorAngles */
void HLA_SetReqPortsHLARParamSensorAngles(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{  
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fPitch      = pHLAR_InWrite->s_Par.s_SensorAngles.f32_Pitch; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fRoll       = pHLAR_InWrite->s_Par.s_SensorAngles.f32_Roll; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fYaw        = pHLAR_InWrite->s_Par.s_SensorAngles.f32_Yaw; /* NEW CALI */
  pReqPorts->pSig_MonoCalibrationLaneImager->sPoseCalibration.fPitchSigma = pHLAR_InWrite->s_Par.s_SensorAngles.f32_Quality; /* NEW CALI */ 
}


/* Fills ReqPorts from structure HLA_t_Availability */
static void HLA_SetReqPortsHLARSigAvl( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite )
{
  pReqPorts->pSig_HlaSig->HLAType = pHLAR_InWrite->s_Sig.s_Avl.e_Type;
  pReqPorts->pSig_HlaSig->HLAState = pHLAR_InWrite->s_Sig.s_Avl.e_State;
  pReqPorts->pSig_HlaSig->USSensitivity = pHLAR_InWrite->s_Sig.s_Avl.e_USSens;
}


/* Fills ReqPorts from structure HLA_t_ImagerState */
static void HLA_SetReqPortsHLARSigImgState(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  switch(pHLAR_InWrite->s_Sig.s_ImagerState.e_ActiveChar)
  {
  case HLA_ACTIVE_CHAR_NIGHT:
    pReqPorts->pSig_ImgCharOdd->e_IntradayState = IC_INTRADAY_STATE_NIGHT;
    break;
  case HLA_ACTIVE_CHAR_DAY:
    pReqPorts->pSig_ImgCharOdd->e_IntradayState= IC_INTRADAY_STATE_DAY;
    break; 
  case HLA_ACTIVE_CHAR_INVALID:
  default:
    break;
  }

  pReqPorts->pSig_ImgStatResOdd->f32_Brightness = pHLAR_InWrite->s_Sig.s_ImagerState.f32_Brightness_Lux;
  pReqPorts->pSig_ImgCharOdd->f32_ExpTimeTotal = (float32) (pHLAR_InWrite->s_Sig.s_ImagerState.ui32_ExposureTime_us / 1E6f); 
  pReqPorts->pSig_ImgCharOdd->sSignalHeader.uiMeasurementCounter = pHLAR_InWrite->s_Sig.s_ImagerState.ui32_FrameNumber;
  pReqPorts->pSig_ImgCharOdd->f32_NoiseStdDev = pHLAR_InWrite->s_Sig.s_ImagerState.f32_Noise;

  HLA_SetReqPortsHLARSigImgChar(pReqPorts, pHLAR_InWrite);
}


/* Fills ReqPorts from structure HLA_t_ImagerCharacteristic */
static void HLA_SetReqPortsHLARSigImgChar( reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{   
  pReqPorts->pSig_ImgCharOdd->ui16_RequestedSlopeR1 = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R1;
  pReqPorts->pSig_ImgCharOdd->ui16_RequestedSlopeR2 = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.ui32_R2;
  pReqPorts->pSig_ImgCharOdd->f32_ExpTimeT1         = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T1_us / 1E6f;

  pReqPorts->pSig_ImgCharOdd->f32_ExpTimeT2       = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T2_us / 1E6f;
  pReqPorts->pSig_ImgCharOdd->f32_ExpTimeT3       = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_T3_us / 1E6f;
  pReqPorts->pSig_ImgCharOdd->f32_ImagerGainTotal = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.f32_Gain;

  HLA_SetReqPortsHLARSigImgRespCurve(pReqPorts, pHLAR_InWrite);
}


/* Fills ReqPorts from structure HLA_t_ImagerResponseCurve */
static void HLA_SetReqPortsHLARSigImgRespCurve(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[0].ui16_GrayValue = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_R_Greyvalue;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[0].ui16_GrayValue = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_G_Greyvalue;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[0].ui16_GrayValue = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Blacklevel_B_Greyvalue;

  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[1].ui16_GrayValue                      = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint1_Greyvalue;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[1].f32_BrightnessR                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_R_Lux / CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[1].f32_BrightnessG                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_G_Lux/ CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[1].f32_BrightnessB                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint1_B_Lux/ CML_f_Pi;

  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[2].ui16_GrayValue                      = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Kneepoint2_Greyvalue;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[2].f32_BrightnessR                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_R_Lux/ CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[2].f32_BrightnessG                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_G_Lux/ CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[2].f32_BrightnessB                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Kneepoint2_B_Lux/ CML_f_Pi;

  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[3].ui16_GrayValue                      = (uint16) pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.ui16_Saturation_Greyvalue;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[3].f32_BrightnessR                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_R_Lux / CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[3].f32_BrightnessG                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_G_Lux/ CML_f_Pi;
  pReqPorts->pSig_ImgCharOdd->s_ResponseCurve[3].f32_BrightnessB                     = pHLAR_InWrite->s_Sig.s_ImagerState.s_ImagerCharacteristic.s_ResponseCurve.f32_Saturation_B_Lux/ CML_f_Pi;

  pReqPorts->pSig_ImgCharOdd->ui16_ResponseCurveLen = 4;
}

/* Fills ReqPorts from structure HLA_t_HeadlightState */
static void HLA_SetReqPortsHLARSigHeadlightState(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  
  /* not so important stuff */
  //pHLAR_InWrite->s_Sig.s_HeadlightState.e_HighBeamState         = RTE_HLAF_HB_STATE_INVALID;
  pReqPorts->pSig_HeadlightState->CurveLightRotAng_Lt             = pHLAR_InWrite->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Lt;
  pReqPorts->pSig_HeadlightState->CurveLightRotAng_Rt             = pHLAR_InWrite->s_Sig.s_HeadlightState.f32_CurveLightRotAngle_Rt;
  pReqPorts->pSig_HeadlightState->GlareReductionState             = pHLAR_InWrite->s_Sig.s_HeadlightState.e_GlareReductionState;
  pReqPorts->pSig_HeadlightState->LightOutput                     = pHLAR_InWrite->s_Sig.s_HeadlightState.f32_LightOutput;

  /* important stuff */
  pReqPorts->pSig_HeadlightState->LightModuleState = pHLAR_InWrite->s_Sig.s_HeadlightState.e_LightModuleState;
  pReqPorts->pSig_HeadlightState->nGFA             = pHLAR_InWrite->s_Sig.s_HeadlightState.nGFA;

  for (uint8 i=0; i<RTE_HLAF_MATRIX_MAX_NUM_GLARE_FREE_AREAS; i++)
  {
    pReqPorts->pSig_HeadlightState->GFA[i].PartHBCutOffAng_Lt           = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Lt;
    pReqPorts->pSig_HeadlightState->GFA[i].PartHBCutOffAng_Rt           = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].f32_PartHBCutoffAng_Rt;
    pReqPorts->pSig_HeadlightState->GFA[i].HorCutOffAng                 = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].f32_HorCutOffAng;
    pReqPorts->pSig_HeadlightState->GFA[i].LightDistance                = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].f32_LightDistance;
    pReqPorts->pSig_HeadlightState->GFA[i].HorCutOffAngStatus           = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].e_HorCutOffAngState;
    pReqPorts->pSig_HeadlightState->GFA[i].LightDistanceStatus          = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].e_LightDistanceState;
    pReqPorts->pSig_HeadlightState->GFA[i].LightStyle_Lt                = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Lt;
    pReqPorts->pSig_HeadlightState->GFA[i].LightStyle_Rt                = pHLAR_InWrite->s_Sig.s_HeadlightState.GFA[i].e_LightStyle_Rt;
  }
}

/* Fills Reqports from structure HLA_t_CalibratedRGBLuxTable */
static void HLA_SetReqPortsHLARParamRGBLuxTable(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{ 
  uint32 i;
  //float32 f32_gain;
  if(  (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 16) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 16))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 0;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 8) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 16))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 1;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 4) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 16))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 2;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 16) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 8))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 3;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 8) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 8))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 4;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 4) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 8))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 5;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 16) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 4))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 6;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 8) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 4))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 7;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 4) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 4))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 8;
  }
  else if (   (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 1) 
    && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 1))
  {
    pReqPorts->pParPPAR_ImgCharRight->ui16_ResponseCurveIndex = 9;
  }
  /* Error */
  else if(    (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R1 == 99) 
          && (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_R2 == 99)
         )
  {
    /* Do nothing */
  }

  pReqPorts->pParPPAR_ImgCharRight->ui16_T1_Production = (uint16) (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_T1_us / HLA_LINE_TIME_US);
  pReqPorts->pParPPAR_ImgCharRight->ui16_Actual_T2_right = (uint16) (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_T2_us / HLA_LINE_TIME_US);
  pReqPorts->pParPPAR_ImgCharRight->ui16_Actual_T3_right = (uint16) (pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_T3_us / HLA_PIXEL_TIME_US);

  pReqPorts->pParPPAR_ImgCharRight->f32_DCG_Factor = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_Gain;
  pReqPorts->pParPPAR_ImgCharRight->ui16_AnalogGainPlus25 = 1;
  pReqPorts->pParPPAR_ImgCharRight->ui16_ConversionGainPlus25 = 1;

  pReqPorts->pParPPAR_ProdIntrinsicRight->f32_RedGreenRatio = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_RatioRedGreen;
  pReqPorts->pParPPAR_ProdIntrinsicRight->f32_BlueGreenRatio = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_RatioBlueGreen;
  pReqPorts->pParPPAR_ProdIntrinsicRight->f32_GreenRefRatio = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.f32_RatioGreenRef;

  //pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.ui32_tableLength = FLSP_RESPONSE_CURVE_LENGTH;
#if(FLSP_RESPONSE_CURVE_LENGTH > HLA_MAX_RGBL_ELEM)
#error FLSP_RESPONSE_CURVE_LENGTH is greater than HLA_ui8_MAX_RGBL_ELEM
#endif
  memset(pReqPorts->pParPPAR_RespCurveRight->s_Buffer, 0, sizeof(s_Buffer_array_t));

  for(i = 0; i < FLSP_RESPONSE_CURVE_LENGTH; i++)
  {
    pReqPorts->pParPPAR_RespCurveRight->s_Buffer[i].f32_Brightness = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[i].f32_lux / C_PI;
    pReqPorts->pParPPAR_RespCurveRight->s_Buffer[i].f32_RedPixMean = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[i].f32_avgR;
    pReqPorts->pParPPAR_RespCurveRight->s_Buffer[i].f32_GreenPixMean = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[i].f32_avgG;
    pReqPorts->pParPPAR_RespCurveRight->s_Buffer[i].f32_BluePixMean = pHLAR_InWrite->s_Par.s_CameraParameter.s_RGBLuxTable.as_table[i].f32_avgB;
  }
}



/* Fills ReqPorts from structure HLA_t_CaliOnline */
static void HLA_SetReqPortsHLARSigCaliOnline(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  pReqPorts->pNvm_SigLearningValues->CaliOnline.Pitch     = pHLAR_InWrite->s_Sig.s_CaliOnline.f32_Pitch;
  pReqPorts->pNvm_SigLearningValues->CaliOnline.Yaw       = pHLAR_InWrite->s_Sig.s_CaliOnline.f32_Yaw;
  pReqPorts->pNvm_SigLearningValues->CaliOnline.Roll      = pHLAR_InWrite->s_Sig.s_CaliOnline.f32_Roll;
  pReqPorts->pNvm_SigLearningValues->CaliOnline.OdoCali_m = pHLAR_InWrite->s_Sig.s_CaliOnline.f32_OdoCali_m;
} 

/* Fills ReqPorts from structure HLA_t_DefectPixelList */
static void HLA_SetReqPortsHLARSigDefPixList(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{ 
  uint32 i;
  
  pReqPorts->pNvm_SigLearningValues->DefectPixel.DefectsListLength = pHLAR_InWrite->s_Sig.s_DefectPixelList.ui8_DefectsListLength;
  pReqPorts->pNvm_SigLearningValues->Header.eSigStatus             = pHLAR_InWrite->s_Sig.s_DefectPixelList.e_DefectsListLengthSigStat;

  for(i = 0; i < RTE_HLAR_DEFECT_PIXEL_LIST_LENGTH; i++)
  {
    pReqPorts->pNvm_SigLearningValues->DefectPixel.DefectList[i].xPos               = pHLAR_InWrite->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_xPos;
    pReqPorts->pNvm_SigLearningValues->DefectPixel.DefectList[i].yPos               = pHLAR_InWrite->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_yPos;
    pReqPorts->pNvm_SigLearningValues->DefectPixel.DefectList[i].DefectType         = pHLAR_InWrite->s_Sig.s_DefectPixelList.as_DefectList[i].e_DefectType;
    pReqPorts->pNvm_SigLearningValues->DefectPixel.DefectList[i].Count              = pHLAR_InWrite->s_Sig.s_DefectPixelList.as_DefectList[i].ui16_Count;
  }

}


/* Fills ReqPorts from structure HLA_t_TrafficStyle */
static void HLA_SetReqPortsHLARSigTrafStyle(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{ 
  pReqPorts->pNvm_SigLearningValues->TrafficStyle.LastLearned   = pHLAR_InWrite->s_Sig.s_TrafficStyle.e_TrafficStyleLastLearned;
  pReqPorts->pNvm_SigLearningValues->TrafficStyle.LearningState = pHLAR_InWrite->s_Sig.s_TrafficStyle.e_TrafficStyleLearningState;
}



static void HLA_SetSigStatus(reqHlaPrtList_t *pReqPorts, HLAR_t_RequiredInputs *pHLAR_InWrite)
{
  //pReqPorts->pCPar_HlaPar->VersionNumber                                        = CPAR_HLA_PARAMETER_INTFVER;
  //pReqPorts->pCPar_HlaPar->Header.eSigStatus                                    = AL_SIG_STATE_OK;
  //pReqPorts->pCPar_HlaPar->Header.uiCycleCounter                                = 0;
  //pReqPorts->pCPar_HlaPar->Header.uiMeasurementCounter                          = pHLAR_InWrite->uiFrameCnt;
  //pReqPorts->pCPar_HlaPar->Header.uiTimeStamp                                   = pHLAR_InWrite->uiTimeStamp_Image_us;
 
  //pReqPorts->pCPar_HlarPar->VersionNumber                                       = CPAR_HLAR_PARAMETER_INTFVER;
  //pReqPorts->pCPar_HlarPar->Header.eSigStatus                                   = AL_SIG_STATE_OK;
  //pReqPorts->pCPar_HlarPar->Header.uiCycleCounter                               = 0;
  //pReqPorts->pCPar_HlarPar->Header.uiMeasurementCounter                         = pHLAR_InWrite->uiFrameCnt;
  //pReqPorts->pCPar_HlarPar->Header.uiTimeStamp                                  = pHLAR_InWrite->uiTimeStamp_Image_us;
 
  pReqPorts->pSig_HeadlightState->VersionNumber                                 = RTE_HLA_HEADLIGHT_STATE_INTFVER;
  pReqPorts->pSig_HeadlightState->Header.eSigStatus                             = AL_SIG_STATE_OK;
  pReqPorts->pSig_HeadlightState->Header.uiCycleCounter                         = 0;
  pReqPorts->pSig_HeadlightState->Header.uiMeasurementCounter                   = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pSig_HeadlightState->Header.uiTimeStamp                            = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pSig_HlaSig->VersionNumber                                         = RTE_HLA_SIGNALS_INTFVER;
  pReqPorts->pSig_HlaSig->Header.eSigStatus                                     = AL_SIG_STATE_OK;
  pReqPorts->pSig_HlaSig->Header.uiCycleCounter                                 = 0;
  pReqPorts->pSig_HlaSig->Header.uiMeasurementCounter                           = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pSig_HlaSig->Header.uiTimeStamp                                    = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pSig_ImgCharOdd->uiVersionNumber                                   = IC_IMAGE_CHARACTERISTICS_INTFVER;
  pReqPorts->pSig_ImgCharOdd->sSignalHeader.eSigStatus                          = AL_SIG_STATE_OK;
  pReqPorts->pSig_ImgCharOdd->sSignalHeader.uiCycleCounter                      = 0;
  pReqPorts->pSig_ImgCharOdd->sSignalHeader.uiMeasurementCounter                = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pSig_ImgCharOdd->sSignalHeader.uiTimeStamp                         = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pSig_ImgStatResOdd->uiVersionNumber                                = IC_IMAGE_STATISTIC_INTFVER;
  pReqPorts->pSig_ImgStatResOdd->sSignalHeader.eSigStatus                       = AL_SIG_STATE_OK;
  pReqPorts->pSig_ImgStatResOdd->sSignalHeader.uiCycleCounter                   = 0;
  pReqPorts->pSig_ImgStatResOdd->sSignalHeader.uiMeasurementCounter             = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pSig_ImgStatResOdd->sSignalHeader.uiTimeStamp                      = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pSig_MonoCalibrationLaneImager->uiVersionNumber                    = MONO_CALIBRATION_INTFVER;
  pReqPorts->pSig_MonoCalibrationLaneImager->sSignalHeader.eSigStatus           = AL_SIG_STATE_OK;
  pReqPorts->pSig_MonoCalibrationLaneImager->sSignalHeader.uiCycleCounter       = 0;
  pReqPorts->pSig_MonoCalibrationLaneImager->sSignalHeader.uiMeasurementCounter = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pSig_MonoCalibrationLaneImager->sSignalHeader.uiTimeStamp          = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pParPPAR_ImgCharRight->uiVersionNumber                             = FLSP_IMAGER_CHAR_RIGHT_INTFVER;
  pReqPorts->pParPPAR_ImgCharRight->sSignalHeader.eSigStatus                    = AL_SIG_STATE_OK;
  pReqPorts->pParPPAR_ImgCharRight->sSignalHeader.uiCycleCounter                = 0;
  pReqPorts->pParPPAR_ImgCharRight->sSignalHeader.uiMeasurementCounter          = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pParPPAR_ImgCharRight->sSignalHeader.uiTimeStamp                   = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pParPPAR_RespCurveRight->uiVersionNumber                           = FLSP_RESPONSE_CURVES_INTFVER;
  pReqPorts->pParPPAR_RespCurveRight->sSignalHeader.eSigStatus                  = AL_SIG_STATE_OK;
  pReqPorts->pParPPAR_RespCurveRight->sSignalHeader.uiCycleCounter              = 0;
  pReqPorts->pParPPAR_RespCurveRight->sSignalHeader.uiMeasurementCounter        = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pParPPAR_RespCurveRight->sSignalHeader.uiTimeStamp                 = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pParPPAR_ProdIntrinsicRight->uiVersionNumber                       = FLSP_PROD_INTR_INTFVER;
  pReqPorts->pParPPAR_ProdIntrinsicRight->sSignalHeader.eSigStatus              = AL_SIG_STATE_OK;
  pReqPorts->pParPPAR_ProdIntrinsicRight->sSignalHeader.uiCycleCounter          = 0;
  pReqPorts->pParPPAR_ProdIntrinsicRight->sSignalHeader.uiMeasurementCounter    = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pParPPAR_ProdIntrinsicRight->sSignalHeader.uiTimeStamp             = pHLAR_InWrite->uiTimeStamp_Image_us;

  pReqPorts->pNvm_SigLearningValues->VersionNumber                  = NVM_HLAR_LEARNING_VALUES_INTFVER;
  pReqPorts->pNvm_SigLearningValues->Header.eSigStatus              = AL_SIG_STATE_OK;
  pReqPorts->pNvm_SigLearningValues->Header.uiCycleCounter          = 0;
  pReqPorts->pNvm_SigLearningValues->Header.uiMeasurementCounter    = pHLAR_InWrite->uiFrameCnt;
  pReqPorts->pNvm_SigLearningValues->Header.uiTimeStamp             = pHLAR_InWrite->uiTimeStamp_Image_us;

}

