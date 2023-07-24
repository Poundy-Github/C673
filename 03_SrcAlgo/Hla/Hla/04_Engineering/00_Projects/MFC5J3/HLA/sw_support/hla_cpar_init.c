/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_cpar_init.c
 
  DESCRIPTION:            Coding parameter initialization service
 
  CREATION DATE:          2016-11-14
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.10.2.3 $
*************************************************************************** */

/* =============================================================================== */
/* GENERAL INFORMATION:                                                            */
/* HLA algo expects following units:                                               */
/*   - distance: meter  [m]                                                        */
/*   - time:     second [s]                                                        */
/*   - velocity: meter per second [m/s]                                            */
/*   - degree:   radian [rad]                                                      */
/*   - percent:  float32 [%], e.g. as 1% we expect 0.01f                           */
/*                                                                                 */
/* Customers usually define CPARs in km/h or degrees.                              */
/* Corresponding conversion has to be performed before sending to HLA.             */
/* =============================================================================== */

/* PRQA S 3120,3121 EOF # 2019-05-28 M.Mutschler: As this is an initialization file magic numbers are there by intension. */

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "hla_cpar_init.h" 

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/
#define C_HLA_PI (3.14159265359f)


/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
 
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/
static void CParInit_HlafPar_AlgoCfg(RTE_HLAF_ParameterAlgoCfg_t* const pDest);
static void CParInit_HlafPar_VehicleProbabilites(RTE_HLAF_ParameterVehicleProbability_t* const pDest);
static void CParInit_HlafPar_KeepOnDelay(RTE_HLAF_ParameterKeepOnDelay_t* const pDest);
static void CParInit_HlafPar_TurnOnDelay(RTE_HLAF_ParameterTurnOnDelay_t* const pDest);
static void CParInit_HlafPar_TurnOffDelay(RTE_HLAF_ParameterTurnOffDelay_t* const pDest);
static void CParInit_HlafPar_Speed(RTE_HLAF_ParameterSpeed_t* const pDest);
static void CParInit_HlafPar_Matrix(RTE_HLAF_ParameterMatrixBeam_t* const pDest);
static void CParInit_HlafPar_Dimming(RTE_HLAF_ParameterDimming_t* const pDest);
static float32 CParInit_Deg2Rad(const float32 degree);
static float32 CParInit_PerCent2Float(const float32 percent);
static float32 CParInit_Kmph2mps(const float32 kmph);

/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/

/* *******************************************************************************
  Initializes HLAF coding parameters.
******************************************************************************** */
void CParInitCPAR_HLAF_Parameter(CPAR_HLAF_Parameter_t* const pDest)
{
  if(pDest != NULL) 
  { 
    pDest->uiVersionNumber                 = CPAR_HLAF_PARAMETER_INTFVER;
    pDest->sSigHeader.eSigStatus           = AL_SIG_STATE_OK;
    pDest->sSigHeader.uiCycleCounter       = 0u;
    pDest->sSigHeader.uiMeasurementCounter = 0u;
    pDest->sSigHeader.uiTimeStamp          = 0u;
    CParInit_HlafPar_AlgoCfg(&pDest->AlgoCfg);
    CParInit_HlafPar_VehicleProbabilites(&pDest->VehicleProbabilities);
    CParInit_HlafPar_KeepOnDelay(&pDest->KeepOnDelay);
    CParInit_HlafPar_TurnOnDelay(&pDest->TurnOnDelay);
    CParInit_HlafPar_TurnOffDelay(&pDest->TurnOffDelay);
    CParInit_HlafPar_Speed(&pDest->Speed);
    CParInit_HlafPar_Matrix(&pDest->Matrix);
    CParInit_HlafPar_Dimming(&pDest->Dimming);
  }
}

/*****************************************************************************
  LOCAL FUNCTIONS 
*****************************************************************************/

/* *******************************************************************************
  @fn             CParInit_HlafPar_AlgoCfg                                   */ /*!
 
  @brief          Initializes algo config part of HLAF coding parameters.
 
  @description    During initialization of algo config part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to algo config part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */
static void CParInit_HlafPar_AlgoCfg(RTE_HLAF_ParameterAlgoCfg_t* const pDest)
{
  pDest->TestMode            = RTE_HLA_TESTMODE_INACTIVE;
  pDest->FogDetection        = RTE_HLA_FOGDET_ACTIVE;
  pDest->BadWeatherDetection = RTE_HLA_BADWEATHER_DET_ACTIVE;
  pDest->sensitivityMode     = RTE_HLA_CPAR_SENSITIVITY_MODE_DEFAULT;
}

/** ************************************************************************************************
  \brief
    During initialization of algo config part of HLAF coding parameters default values for 
    VehicleProbabilites are set.
  
  \pre
    None

  \post
    VehicleProbabilites parameter are initialized

  \param  [in, out]  pDest  pointer to VehicleProbabilites parameter

  \return
    Void

  \globals
    None

  \InOutCorrelation
    Parameters are set to default values
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static void CParInit_HlafPar_VehicleProbabilites(RTE_HLAF_ParameterVehicleProbability_t* const pDest)
{   
  pDest->thresholdUpperOncoming         = 90u;
  pDest->thresholdUpperPreceding        = 90u;
  pDest->thresholdUpperOncomingHighway  = 90u;
  pDest->thresholdUpperPrecedingHighway = 90u;
  pDest->thresholdUpperOncomingCity     = 90u;
  pDest->thresholdUpperPrecedingCity    = 90u;
  pDest->thresholdLowerOncoming         = 10u;
  pDest->thresholdLowerPreceding        = 10u;
  pDest->thresholdLowerOncomingHighway  = 10u;
  pDest->thresholdLowerPrecedingHighway = 10u;
  pDest->thresholdLowerOncomingCity     = 10u;
  pDest->thresholdLowerPrecedingCity    = 10u;
}

/* *******************************************************************************
  @fn             CParInit_HlafPar_KeepOnDelay                               */ /*!
 
  @brief          Initializes keep-on part of HLAF coding parameters.
 
  @description    During initialization of keep-on part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to keep-on part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */                                                 
static void CParInit_HlafPar_KeepOnDelay(RTE_HLAF_ParameterKeepOnDelay_t* const pDest)
{
  pDest->distanceOncomingVehicle     = 4000u;                              /* m */
  pDest->distancePrecedingVehicleMin = 3000u;                              /* m */
  pDest->distancePrecedingVehicleMax = 4000u;                              /* m */
}

/* *******************************************************************************
  @fn             CParInit_HlafPar_TurnOnDelay                               */ /*!
 
  @brief          Initializes turn-on part of HLAF coding parameters.
 
  @description    During initialization of turn-on part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to turn-on part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */
static void CParInit_HlafPar_TurnOnDelay(RTE_HLAF_ParameterTurnOnDelay_t* const pDest)
{
  pDest->OncomingMin                  = 0.6f;                               /* s */
  pDest->OncomingMax                  = 1.5f;                               /* s */
  pDest->OncomingMinHighway           = 1.5f;                               /* s */
  pDest->OncomingMaxHighway           = 1.5f;                               /* s */
  pDest->PrecedingMin                 = 0.1f;                               /* s */
  pDest->PrecedingMinWiperOn          = 3.0f;                               /* s */
  pDest->PrecedingMaxShort            = 3.0f;                               /* s */
  pDest->PrecedingMaxLong             = 3.0f;                               /* s */
  pDest->SlowOvertaking               = 8.0f;                               /* s */
  pDest->Fog                          = 0.0f;                               /* s */
  pDest->Blockage                     = 2.0f;                               /* s */
}                                                                           

/* *******************************************************************************
  @fn             CParInit_HlafPar_TurnOffDelay                              */ /*!
 
  @brief          Initializes turn-off part of HLAF coding parameters.
 
  @description    During initialization of turn-off part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to turn-off part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */                                                                            
static void CParInit_HlafPar_TurnOffDelay(RTE_HLAF_ParameterTurnOffDelay_t* const pDest)
{                                                                           
  pDest->oncomingVehicle  = 0.0f;                                           /* s */
  pDest->precedingVehicle = 0.0f;                                           /* s */
}

/* *******************************************************************************
  @fn             CParInit_HlafPar_Speed                                     */ /*!
 
  @brief          Initializes speed  part of HLAF coding parameters.
 
  @description    During initialization of speed  part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to speed  part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */
static void CParInit_HlafPar_Speed(RTE_HLAF_ParameterSpeed_t* const pDest)
{                                                                           
  pDest->DeactivateSpeed          = CParInit_Kmph2mps(10.0f);               /* m/s */
  pDest->DeactivateSpeedHigh      = CParInit_Kmph2mps(280.0f);              /* m/s */
  pDest->ActivateSpeed            = CParInit_Kmph2mps(30.0f);               /* m/s */
  pDest->ActivateSpeedHigh        = CParInit_Kmph2mps(270.0f);              /* m/s */
  pDest->AlwaysActiveSpeed        = CParInit_Kmph2mps(30.0f);               /* m/s */
  pDest->KeepOff_VeryLowSpeed     = CParInit_Kmph2mps(12.6f);               /* m/s */
  pDest->KeepOff_LowRadius        = 0.0f;                                   /* m */
  pDest->KeepOff_HighAcceleration = 2.5f;                                   /* m/s^2 */
  pDest->KeepOff_AccTime          = 2.5f;                                   /* s */
  pDest->KeepOff_Delay            = 2.0f;                                   /* s */
}                                                                           

/* *******************************************************************************
  @fn             CParInit_HlafPar_Matrix                                    */ /*!
 
  @brief          Initializes matrix part of HLAF coding parameters.
 
  @description    During initialization of matrix part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to matrix part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */                                                                            
static void CParInit_HlafPar_Matrix(RTE_HLAF_ParameterMatrixBeam_t* const pDest)
{  
  pDest->MaxNumGlarefreeArea = 5u;
}

/* *******************************************************************************
  @fn             CParInit_HlafPar_Dimming                                   */ /*!
 
  @brief          Initializes dimming part of HLAF coding parameters.
 
  @description    During initialization of dimming part of HLAF coding parameters 
                  default values for each element are set.
 
  @param[out]     pDest   Pointer to dimming part of HLAF coding parameters.
 
  @return         void
******************************************************************************** */
static void CParInit_HlafPar_Dimming(RTE_HLAF_ParameterDimming_t* const pDest)
{                                                                           
  pDest->DimmingDetection        = RTE_HLA_DIMMDET_ACTIVE;                     
  pDest->AreaRightBorderArray[0] = CParInit_Deg2Rad(-7.0f);                 /* radian */
  pDest->AreaRightBorderArray[1] = CParInit_Deg2Rad(-3.0f);                 /* radian */
  pDest->AreaRightBorderArray[2] = CParInit_Deg2Rad( 3.0f);                 /* radian */
  pDest->AreaRightBorderArray[3] = CParInit_Deg2Rad( 7.0f);                 /* radian */
  pDest->ReductThreshLevel1      = CParInit_PerCent2Float(80.0f);           /* % */
  pDest->ReductThreshLevel2      = CParInit_PerCent2Float(90.0f);           /* % */
  pDest->TurnOnDelay             = 0.3f;                                    /* s */
}                                                                           
                                                                            
/** ************************************************************************************************
  \brief
    Converts angle values from degree into rad.
  
  \pre
    None

  \post
    None

  \param  [in]     degree   Angle value in degrees

  \return
    Angle value in rad

  \globals
    None

  \InOutCorrelation
    Converts angle values from degree into rad by multiplication of PI followed by division of 180.
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static float32 CParInit_Deg2Rad(const float32 degree)
{
  /* PRQA S 3121 1 # 2019-06-03 M.Mutschler: Magic number described in detailed design of this function. */
  return (degree * (C_HLA_PI / 180.0f));
}

/** ************************************************************************************************
  \brief
    Converts percentage value into a real float. 
  
  \pre
    None

  \post
    None

  \param  [in]     percent   Percent value

  \return
    Real floating representation of percentage value

  \globals
    None

  \InOutCorrelation
    Converts percentage value into a real float by divison of 100.
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static float32 CParInit_PerCent2Float(const float32 percent)
{
  /* PRQA S 3121 1 # 2019-06-03 M.Mutschler: Magic number described in detailed design of this function. */
  return (percent * 0.01f);
}

/** ************************************************************************************************
  \brief
    Converts velocity in kmph (km/h) into mps (m/s). 
  
  \pre
    None

  \post
    None

  \param  [in]     kmph   Velocity in kilometers per hour.

  \return
    Velocity in meter per second.

  \globals
    None

  \InOutCorrelation
    Converts percentage value into a real float by divison of 3.6.
  
  \testmethod
    Module Test

  \traceability
***************************************************************************************************/
static float32 CParInit_Kmph2mps(const float32 kmph)
{
  /* PRQA S 3121 1 # 2019-06-03 M.Mutschler: Magic number described in detailed design of this function. */
  return (kmph * 0.27777778f);
}
