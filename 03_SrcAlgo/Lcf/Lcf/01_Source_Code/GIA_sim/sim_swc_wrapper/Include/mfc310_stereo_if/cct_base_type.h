
/*! \file **********************************************************************

  COMPANY:                Continental Temic, PL FAS, A.D.C. GmbH

  PROJECT:                MFC300

  CPU:                    TMS320DM643x / Windows DLL

  COMPONENT:              GLOB

  MODULNAME:              cct_base_type.h

  DESCRIPTION:

  AUTHOR:                 Jochen Spruck

  CREATION DATE:          03.10.2011

  VERSION:                $Revision: 1.1 $

  CHANGES:
  ---*/ /*---
  CHANGE:                 $Log: cct_base_type.h  $
  CHANGE:                 Revision 1.1 2021/12/13 17:26:23CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:37:26CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310_stereo_if/project.pj
  CHANGE:                 Revision 1.2 2014/04/01 10:50:06CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Removed Enums
  CHANGE:                 - Added comments -  uidg3181 [Apr 1, 2014 10:50:06 AM CEST]
  CHANGE:                 Change Package : 217703:2 http://mks-psad:7002/im/viewissue?selection=217703
  CHANGE:                 Revision 1.1 2014/03/13 15:12:56CET Sorge-EXT, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310_stereo_if/project.pj
  CHANGE:                 Revision 1.1 2011/11/04 12:20:32CET Spruck, Jochen (spruckj) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/SAC_StereoAutoCalibration/04_Engineering/01_Source_Code/common/project.pj

**************************************************************************** */

#ifndef __CCT_BASE_TYPE_H_
#define __CCT_BASE_TYPE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "cct_type.h"

/* Real types */
typedef f32_t fAccelAbs_t;              /* Magnitude of translatory acceleration, time-derivative of translatory velocity without sign, increase of velocity: positive, decrease of velocity: negative @min:-18.0 @max:18.0 */
typedef f32_t fAccel_t;                 /* Translatory acceleration, time-derivative of translatory velocity with sign @min:-18.0 @max:18.0 */
typedef f32_t fAngleDeg_t;              /* Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise @min:-360.0 @max:360.0 */
typedef f32_t fAngle_t;                 /* Measure of rotation, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */
typedef f32_t fConfidence_t;            /* Trustiness of value, 0.0: no reliance, 1.0: full realiance @min:0.0 @max:1.0 */
typedef f32_t fCurve_t;                 /* Curvature (inverse radius) of trajectory, left direction: positive, right direction negative @min:-1.0 @max:1.0 */
typedef f32_t fDistance_t;              /* Straight stretch between points or objects @min:-500.0 @max:500.0 */
typedef f32_t fGradient_t;              /* Gradient of a value */
typedef f32_t fProbability_t;           /* Propbability of a hypothesis, 0: no probability, 1: full probability @min:0.0 @max:1.0 */
typedef f32_t fQuality_t;               /* Characteristic of a variable, 0: worst quality, 1.0 best quality @min:0.0 @max:1.0 */
typedef f32_t fRadius_t;                /* Radius of trajectory, left direction: positive, right direction negative @min:-100000.0 @max:100000.0 */
typedef f32_t fRatio_t;                 /* Ratio of a value @min:0.0 @max:10000.0 */
typedef f32_t fTemperature_t;           /* Thermal state @min:-300.0 @max:300.0 */
typedef f32_t fTime_t;                  /* Period of time @min:0.0 */
typedef f32_t fUncertainty_t;           /* Uncertainty of value, 0.0: no reliance, 1.0: full realiance @min:0.0 @max:1.0 */
typedef f32_t fVariance_t;              /* The variance of a value @min:-100000.0 @max:100000.0 */
typedef f32_t fStdDev_t;                /* The standard deviation of a value @min:-100000.0 @max:100000.0 */
typedef f32_t fVelocityAbs_t;           /* Magnitude of translatory velocity, time-derivative of distance without sign @min:0.0 @max:100.0 */
typedef f32_t fVelocity_t;              /* Translatory velocity, time-derivative of distance with sign, forward direction positive, reverse direction negative @min:-100.0 @max:100.0 */
typedef f32_t fWeight_t;                /* Gravity load in unit of mass @min:0.0 @max:50000.0 */
typedef f32_t fYawRate_t;               /* Measure of yaw rate, counterclockwise direction: positive, clockwise direction: negative. Reference is x-axis if not stated otherwise */
typedef f32_t fPixel_t;                 /* Pixel value with sub pixel */

typedef ui64_t Algo64DataTimeStamp_t;   /* 64 bit algo timestamp */
typedef ui32_t AlgoFrameCounter_t;      /* Algo frame counter */

typedef ui16_t ParameterID_t;           /* Parameter Id used to sync/match interfaces */

typedef ui8_t  ObjID_t;                 /* Object ID invalid is 255 */

/* Algo Signal states */
//typedef enum
//{
//  AL_SIG_STATE_INIT     = 0,            /*!< Algo signal state init    */
//  AL_SIG_STATE_OK       = 1,            /*!< Algo signal state ok      */
//  AL_SIG_STATE_INVALID  = 2             /*!< Algo signal state invalid */
//}AlgoSignalState_t;

/* 3x3 matrix type */
typedef union {
  f32_t matrix[9];           /*!< all matrix elements */
  struct {
    f32_t      a00;         /*!< a00 element */
    f32_t      a10;         /*!< a10 element */
    f32_t      a20;         /*!< a20 element */
    f32_t      a01;         /*!< a01 element */
    f32_t      a11;         /*!< a11 element */
    f32_t      a21;         /*!< a21 element */
    f32_t      a02;         /*!< a02 element */
    f32_t      a12;         /*!< a12 element */
    f32_t      a22;         /*!< a22 element */
  }elements;
} mat3_t;

/* 2 Point in cartesian coordinates */
typedef struct {
  fDistance_t X;
  fDistance_t Y;
} Point2D_t;

#ifdef __cplusplus
}
#endif

#endif
/* ************************************************************************* */
/*   Copyright ADC-GmbH, Lindau                                              */
/* ************************************************************************* */
