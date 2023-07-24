/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC5xx

COMPONENT:              HLA

FILENAME:               HLA_DecisionParameters.c

DESCRIPTION:            Parameters of decision module

CREATION DATE:          2022-06-16

CPU:                    Independent

VERSION:                $Revision: 1.0.0.1 $

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "HLA_ProjectParameters.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/
#define CProPar_HLA_PI (3.14159265359f)
#define CProPar_Kmph2mps( kmph )  (kmph * 0.27777778f)
#define CProPar_Deg2Rad( degree )  ((degree) * (CProPar_HLA_PI / 180.0f))
#define CProPar_PerCent2Float( percent )  (percent * 0.01f)
/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
static const CPAR_HLAF_Parameter_t m_ProjectParameters =
{
  /* uiVersionNumber */                   CPAR_HLAF_PARAMETER_INTFVER,
  
  /* sSigHeader */
  {
    /* uiTimeStamp */                     0,
    /* uiMeasurementCounter */            0,
    /* uiCycleCounter */                  0,
    /* eSigStatus */                      AL_SIG_STATE_OK,
    /* a_reserve */                    
    /* a_reserve[0] */                    0,
    /* a_reserve[1] */                    0,
    /* a_reserve[2] */                    0

  },
  
  /* AlgoCfg */
  {
    /* TestMode */                        0,
    /* FogDetection */                    0,
    /* BadWeatherDetection */             0,
    /* sensitivityMode */                 0
  },

  /* VehicleProbabilities */
  {
    /* thresholdUpperOncoming */          90,
    /* thresholdUpperPreceding */         90,
    /* thresholdUpperOncomingHighway */   90,
    /* thresholdUpperPrecedingHighway */  90,
    /* thresholdUpperOncomingCity */      90,
    /* thresholdUpperPrecedingCity */     90,
    /* thresholdLowerOncoming */          10,
    /* thresholdLowerPreceding */         10,
    /* -thresholdLowerOncomingHighway */  10,
    /* thresholdLowerPrecedingHighway */  10,
    /* thresholdLowerOncomingCity */      10,
    /* thresholdLowerPrecedingCity */     10,
  },

  /* KeepOnDelay */
  {
    /* distanceOncomingVehicle */        4000,
    /* distancePrecedingVehicleMin */    3000,
    /* distancePrecedingVehicleMax */    4000
  },

  /* TurnOnDelay */
  {
    /* OncomingMin */                    0.6f,
    /* OncomingMax */                    1.5f,
    /* OncomingMinHighway */             1.5f,
    /* OncomingMaxHighway */             1.5f,
    /* PrecedingMin */                   0.1f,
    /* PrecedingMinWiperOn */            3.0f,
    /* PrecedingMaxShort */              3.0f,
    /* PrecedingMaxLong */               3.0f,
    /* SlowOvertaking */                 8.0f,
    /* Fog */                            0.0f,
    /* Blockage */                       2.0f
  },

  /* TurnOffDelay */
  {
    /* oncomingVehicle */                0.0f,
    /* precedingVehicle */               0.0f
  },

  /* Speed */
  {
    /* DeactivateSpeed */                CProPar_Kmph2mps(10.0f),               /* m/s */
    /* DeactivateSpeedHigh */            CProPar_Kmph2mps(280.0f),              /* m/s */
    /* ActivateSpeed */                  CProPar_Kmph2mps(30.0f),               /* m/s */
    /* ActivateSpeedHigh */              CProPar_Kmph2mps(270.0f),              /* m/s */
    /* AlwaysActiveSpeed */              CProPar_Kmph2mps(30.0f),               /* m/s */
    /* KeepOff_VeryLowSpeed */           CProPar_Kmph2mps(12.6f),               /* m/s */
    /* KeepOff_LowRadius */              0.0f,                                   /* m */
    /* KeepOff_HighAcceleration */       2.5f,                                   /* m/s^2 */
    /* KeepOff_AccTime */                2.5f,                                   /* s */
    /* KeepOff_Delay */                  2.0f                                    /* s */
  },

  /* Matrix */
  {
    /* MaxNumGlarefreeArea */           0
  },

  /* Dimming */
  {
    /* DimmingDetection */              RTE_HLA_DIMMDET_INVALID,

    /* AreaRightBorderArray */
    {
      CProPar_Deg2Rad(-7.0f),
      CProPar_Deg2Rad(-3.0f),
      CProPar_Deg2Rad(3.0f),
      CProPar_Deg2Rad(7.0f)
    },

    /* ReductThreshLevel1 */              CProPar_PerCent2Float(80.0f),
    /* ReductThreshLevel2 */              CProPar_PerCent2Float(90.0f),
    /* TurnOnDelay */                     0.3f
  },

};
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/
 
/****************************************************************************
* GLOBAL FUNCTIONS DEFINTION
*****************************************************************************/
/* return pointer to HLA project parameters */
const CPAR_HLAF_Parameter_t* GetProjectParameters(void)
{
  return &m_ProjectParameters;
}
 
/****************************************************************************
* LOCAL FUNCTIONS DEFINTION
*****************************************************************************/