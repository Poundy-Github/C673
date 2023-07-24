/** \file ******************************************************************
COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

PROJECT:                MFC4xx

COMPONENT:              HLA

FILENAME:               HLA_MatrixParameters.h

DESCRIPTION:            Parameters of matrix module

CREATION DATE:          2018-05-14

CPU:                    Independent

VERSION:                $Revision: 1.14 $
**************************************************************************** */
/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_MATRIX_PARAMETERS_H
#define H_HLA_MATRIX_PARAMETERS_H

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "hlaf_type.h"

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* TYPEDEFS
*****************************************************************************/
/// SAE related parameters
typedef struct  
{
  uint32  minIntTurnOff;            ///< min Intensity for high beam Turn off (SAE-Regulation = 1.5cd in 100ft) \phys_unit lux
  uint32  minIntTurnOffRightOffset; ///< min Intensity for high beam Turn off in 5 degrees lateral offset to the right(SAE-Regulation = 40cd in 100ft) \phys_unit lux
  float32 targetDistance;           ///< distance to the target (SAE-Regulation = 100ft) \phys_unit ft
  float32 targetLateralOffset;      ///< lateral offset to the target (SAE-Regulation = 5 degrees offset in 100ft) \phys_unit degree
} t_MatrixParametersSAE;

/// \brief Glare free parameter
typedef struct
{
  float32 KeepGFAMinTime_s;      ///< Keep GFA for minimal time after vehicle is lost, then delete GFA
  float32 MaxTruckHeight_m;      ///< Height assumption of object for upper GFA border
  float32 AddTruckLightAngle;    ///< Angle offset for truck lights to avoid blinding of the driver
} t_MatrixParametersGFA;

/// \brief Parameter set for clustering of vehicle 2 GFA
typedef struct
{
  float32 dAngPrec;   ///< Min. angle between two lights to cluster preceding with preceding lights \phys_unit rad
  float32 dAngOnc;    ///< Min. angle between two lights to cluster oncoming with oncoming lights \phys_unit rad
  float32 dAng;       ///< Min. angle between two lights to cluster preceding with oncoming lights \phys_unit rad
  float32 WidthPrec;  ///< Min. lateral distance between two lights to cluster preceding with preceding lights \phys_unit m
  float32 WidthOnc;   ///< Min. lateral distance between two lights to cluster oncoming with oncoming lights \phys_unit m
  float32 Width;      ///< Min. lateral distance between two lights to cluster preceding with oncoming lights \phys_unit m
} t_MatrixParametersClusterVeh2GFA;

/// \brief Matrix glare free area parameter
typedef struct
{
  float32 BndryLeft_Ang_Min;     ///< Left boundary angle minimum value    
  float32 BndryLeft_Ang_Max;     ///< Left boundary angle maximum value    

  float32 BndryRight_Ang_Min;    ///< Right boundary angle minimum value   
  float32 BndryRight_Ang_Max;    ///< Right boundary angle maximum value   

  float32 BndryLower_Ang_Min;    ///< Lower boundary angle minimum value   
  float32 BndryLower_Ang_Max;    ///< Lower boundary angle maximum value   

  float32 BndryUpper_Ang_Min;    ///< Upper boundary angle minimum value   
  float32 BndryUpper_Ang_Max;    ///< Upper boundary angle maximum value   

  float32 ClosestObj_Dist_Min;   ///< Closest object distance minimum value
  float32 ClosestObj_Dist_Max;   ///< Closest object distance maximum value

  float32 ClosestObj_Ang_Min;    ///< Closest object angle minimum value   
  float32 ClosestObj_Ang_Max;    ///< Closest object angle maximum value   

  float32 MinLight_Dist_Min;     ///< Minimum light distance minimum value      
  float32 MinLight_Dist_Max;     ///< Minimum light distance maximum value      

  float32 MinLight_Ang_Min;      ///< Minimum light angle minimum value         
  float32 MinLight_Ang_Max;      ///< Minimum light angle maximum value         

  float32 LowBeam_Dist_Default;  ///< Low beam distance default value           
  float32 LowBeam_Dist_Min;      ///< Low beam distance minimum value           
  float32 LowBeam_Dist_Max;      ///< Low beam distance maximum value           

  float32 LowBeam_Dist_Onc_Min;  ///< Low beam distance oncoming minimum value  
  float32 LowBeam_Dist_Onc_Max;  ///< Low beam distance oncoming maximum value  
  float32 LowBeam_Dist_Prec_Min; ///< Low beam distance preceding minimum value 
  float32 LowBeam_Dist_Prec_Max; ///< Low beam distance preceding maximum value 

  float32 LowBeam_Ang_Default;   ///< Low beam angle default value              
  float32 LowBeam_Ang_Min;       ///< Low beam angle minimum value              
  float32 LowBeam_Ang_Max;       ///< Low beam angle maximum value              
} t_MatrixParametersOutput;

/// \brief Matrix parameter for input data
typedef struct
{
  float32 EMObjMaxDist;                   ///< maximum relevance distance for EM objects \phys_unit m
  uint8   EMObjUpperProbabilityThresh;    ///< upper probability threshold for EM objects \min 0 \max 100
  uint8   EMObjLowerProbabilityThresh;    ///< lower probability threshold for EM objects \min 0 \max 100
  uint8   EMObjMinClassConfidence;        ///< min class confidence for EM objects \min 0 \max 100
  float32 RadarObjAngleFusionRegion;      ///< angle of the radar fusion region \phys_unit rad \min 0 \max 1.57
  float32 RadarObjDistFusionRegion;       ///< distance of the radar fusion region \phys_unit m \min 0 \max 200
  float32 RadarObjAngleRadarOnlyRegion;   ///< angle of the radar only region \phys_unit rad \min 0 \max 1.57
  float32 RadarObjDistRadarOnlyRegion;    ///< distance of the radar only region \phys_unit m \min 0 \max 200
  float32 RadarObjLatDistRadarOnlyRegion; ///< lateral distance of the radar only region \phys_unit m \min 0 \max 200
  uint8   RadarObjMinDynConfidence;       ///< minimum dynamic confidence for radar objects \phys_unit % \min 0 \max 100
  uint8   RadarObjMinProbOfEx;            ///< minimum probability of existence for radar objects \phys_unit % \min 0 \max 100
  uint8   RadarObjMinClassConfidence;     ///< minimum class confidence for radar objects \phys_unit % \min 0 \max 100
  float32 RadarObjCloseObjDist;           ///< distance to decide if object is close enough to be relevant without checking the life cycle \phys_unit m \min 0 \max 1000
  uint8   RadarObjMinLifeCycles;          ///< minimum life cycles a radar objects needs if it is not closer than RadarObjCloseObjDist \min 0 \max 128
  float32 RadarOnlyRegionOuterAngle;      ///< outer angle for the object if it is in the radar only region \phys_unit rad \min 0 \max 1.57
  float32 RadarOnlyRegionInnerAngle;      ///< inner angle for the object if it is in the radar only region \phys_unit rad \min 0 \max 1.57
  float32 RadarObjAssumedWidth;           ///< assumed with of radar objects \phys_unit m \min 0 \max 10
  uint8   RadarObjRelCountSmallStep;      ///< small step size to increase relevance counter of radar objects
  uint8   RadarObjRelCountBigStep;        ///< big step size to increase relevance counter of radar objects
  uint8   RadarObjSmallStepCounterThres;  ///< light threshold that need to be in radar object angles to increase counter by small step
  uint8   RadarObjRelevanceThres;         ///< relevance threshold for radar objects
  uint8   RadarObjMinVehProb;             ///< min vehicle probability for LSD objects to increase relevance counter
  float32 RadarFusionMaxAngleDiff;        ///< max angle difference between LSD and radar object \phys_unit rad \min 0 \max 1.57
  float32 LSDRoiRegionCenterRightOffset;  ///< right offset for center ROI region for sticky status for oncoming
  float32 LSDRoiRegionCenterLeftOffset;   ///< left offset for center ROI region for sticky status for oncoming
  float32 LSDRoiRegionCenterXDistance;    ///< distance offset for center ROI region for sticky status for oncoming
} t_MatrixParametersInput;

/// \brief HLA matrix config parameters
typedef struct 
{
  boolean bGFACalculationInTwilight;    ///< indicates if GFA calculation will also be done in twilight scenarios
  boolean bMotionIndOutputGFAData;      ///< indicates if GFA output will also be set in case of standstill or backwards driving
  boolean bUseEMInputforMatrixFunction; ///< indicates if EM objects are used for GFA and HB turn off
}t_MatrixParametersCfg;

/// \brief HLA matrix beam parameters
typedef struct
{
  t_MatrixParametersSAE            SAE;            ///< SAE related parameters
  t_MatrixParametersGFA            GFA;            ///< glare free area parameter                  
  t_MatrixParametersClusterVeh2GFA ClusterVeh2GFA; ///< vehicle cluster to GFA conversion          
  t_MatrixParametersOutput         Output;         ///< defaults, min and max value for output data
  t_MatrixParametersInput          Input;          ///< parameter for input handling e.g. EM object list
  t_MatrixParametersCfg            Cfg;            ///< configuration parameters
} t_MatrixParameters;

/****************************************************************************
* GLOBAL FUNCTIONS DECLARATION
*****************************************************************************/

/** ************************************************************************************************ 
  \brief
    Return pointer to HLA matrix parameters
  
  \pre
    none
  \post
    none
  
  \return
    pointer to analysis parameter
  
  \globals
   None
  
  \InOutCorrelation
   None
  
  \callsequence
  
  \testmethod 
  
  \traceability 
***************************************************************************************************/
const t_MatrixParameters* GetMatrixParameters(void);

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_MATRIX_PARAMETERS_H */
