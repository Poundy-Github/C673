/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_SIT (Situation)

PACKAGENAME:               sit_par.c

DESCRIPTION:               Parameter File for ACC Situation (SIT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.6 $

LEGACY VERSION:            Revision: 1.4

**************************************************************************** */



/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "sit.h"
#include "sit_custom.h"
#if (FCT_CFG_ACC_SITUATION)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@addtogroup sit_par
@{
*/
/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- la_lanechange_cam.c ---*/

/*! Calculation of lane change probability */
const SITLaneChangeProbParameter_t SITLCProbParData = 
#if (SIT_LC_CFG_USE_TURNIND_CAMERA_PROB)
{
  /*! const float32 SIT_LC_PROB_TABLE_TURN_LIGHT;
      (s) -> (%) */
  { 
    {0.f, 100.f},
    {40.f, 51.f},
    {50.f, 0.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER;
     (m/s) -> (&) */
  { 
    {0.2f, 0.f},
    {0.7f, 100.f},
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_CAM_PROB;
      iLatDiffCamCurveProb, iVelLatCamLaneMarkerProb -> (%) */
  { 
    0u,
    22u,
    75u,
    100u,
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_ALL_LATDIFFCURVE_TURNLIGHT; 
      iLatDiffFilteredCurvesProb, iLCProbTemp, iTurnLightProb -> (%) */
  { 
    0u,
    5u,
    10u,
    55u,
    45u,
    70u,
    70u,
    100u,
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_LATDIFFCURVE_TURNLIGHT;
      iLatDiffFilteredCurvesProb, iTurnLightProb -> (%) */
  { 
    0u,
    5u,
    50u,
    100u,
  },
  
  /*! const float32 SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES;
      (s) -> (%) */
  { 
    {0.f,   0.f},
    {0.1f,  10.f},
    {0.2f,  45.f},
    {0.35f, 100.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST;
       (),   (), */
  { 
    {0.0002f, 0.00857142857f}, /* X = 0.30f, -> T = 0,008571428571428571 */
    {0.0009f, 0.38f},          /* X = 0.95f, -> T = 0,38 */
  },

  /*! SIT_LC_PROB_TABLE_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE;
      iDistLatProb, iLatDiffFilteredCurvesProb, iTurnLightProb -> (%) */
  { 
    0u,
    10u,
    10u,
    60u,
    0u,
    80u,
    90u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT;
      iLCProbTemp, iTurnLightProb -> (%) */
  { 
    0u,
    70u,
    90u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE;
      iLCProbTemp, iLatDiffFilteredCurvesProb, iDistLatProb -> (%) */
  { 
    0u,
    60u,
    10u,
    100u,
    0u,
    90u,
    90u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_MARKERCROSSING,
      iLCProbTemp, iCamLaneMarkerCrossedProb -> (%) */
  { 
    0u,
    80u,
    85u,
    100u,
  },

  /*! const float32 SIT_LC_PROB_TABLE_LAT_DIST;
     (m)-> (%) */
  { 
    {0.3f, 0.f},
    {0.6f, 100.f},
    {1.6f, 100.f},
    {3.5f, 0.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_CURVE
      (1/m) ->  (%) */
  { 
    {0.002f, 0.f},
    {0.01f,  100.f},
    {0.018f, 100.f},
    {0.03f,  0.f},
  },

  /*! SIT_LC_PROB_TABLE_COMB_CURVE
      iCurveProb -> (%) */
  { 
    0u,
    70u,
    15u,
    100u,
  },
};

#else
{
  /*! const float32 SIT_LC_PROB_TABLE_TURN_LIGHT;
      (s) -> (%) */
  { 
    {0.f, 100.f},
    {38.f, 51.f},
    {50.f, 0.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_LAT_VEL_CAM_LANE_MARKER;
     (m/s) -> (&) */
  { 
    {0.2f, 0.f},
    {0.7f, 100.f},
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_CAM_PROB;
      iLatDiffCamCurveProb, iVelLatCamLaneMarkerProb -> (%) */
  { 
    0u,
    20u,
    85u,
    100u,
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_ALL_LATDIFFCURVE_TURNLIGHT; 
      iLatDiffFilteredCurvesProb, iLCProbTemp, iTurnLightProb -> (%) */
  { 
    0u,
    5u,
    10u,
    70u,
    5u,
    70u,
    70u,
    100u,
  },

  /*! const uint8 SIT_LC_PROB_TABLE_COMB_LATDIFFCURVE_TURNLIGHT;
      iLatDiffFilteredCurvesProb, iTurnLightProb -> (%) */
  { 
    0u,
    50u,
    5u,
    100u,
  },
  
  /*! const float32 SIT_LC_PROB_TABLE_DIFF_LAT_FILT_CURVES;
      (s) -> (%) */
  { 
    {0.f,   0.f},
    {0.1f,  10.f},
    {0.2f,  45.f},
    {0.35f, 100.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_DRIVER_INT_CURVE_FILTER_CONST;
       (),   (), */
  { 
    {0.0002f, 0.00857142857f}, /* X = 0.30f, -> T = 0,008571428571428571 */
    {0.0009f, 0.38f},          /* X = 0.95f, -> T = 0,38 */
  },

  /*! SIT_LC_PROB_TABLE_COMB_LATDIST_TURNLIGHT_LATDIFFCURVE;
      iDistLatProb, iLatDiffFilteredCurvesProb, iTurnLightProb -> (%) */
  { 
    0u,
    20u,
    20u,
    60u,
    0u,
    80u,
    90u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_LOWSPEED_TURNLIGHT;
      iLCProbTemp, iTurnLightProb -> (%) */
  { 
    0u,
    98u,
    85u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_LATDIST_LATDIFFCURVE;
      iLCProbTemp, iLatDiffFilteredCurvesProb, iDistLatProb -> (%) */
  { 
    0u,
    60u,
    10u,
    100u,
    0u,
    90u,
    90u,
    100u,
  },

  /*! SIT_LC_PROB_TABLE_COMB_MARKERCROSSING,
      iLCProbTemp, iCamLaneMarkerCrossedProb -> (%) */
  { 
    0u,
    80u,
    85u,
    100u,
  },

  /*! const float32 SIT_LC_PROB_TABLE_LAT_DIST;
     (m)-> (%) */
  { 
    {0.3f, 0.f},
    {0.6f, 100.f},
    {1.6f, 100.f},
    {3.5f, 0.f},
  },

  /*! const float32 SIT_LC_PROB_TABLE_CURVE
      (1/m) ->  (%) */
  { 
    {0.002f, 0.f},
    {0.01f,  100.f},
    {0.018f, 100.f},
    {0.03f,  0.f},
  },

  /*! SIT_LC_PROB_TABLE_COMB_CURVE
      iCurveProb -> (%) */
  { 
    0u,
    70u,
    30u,
    100u,
  },
};
#endif /*!< SIT_LC_CFG_USE_TURNIND_CAMERA_PROB */

/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


///@}
#endif  /*!< FCT_CFG_ACC_SITUATION */

