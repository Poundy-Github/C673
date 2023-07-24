/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface_floxelParams.h  

  DESCRIPTION:    Parameters for bare floxel gerenation on FPGA
                  

  AUTHOR:         A. Bachmann

  CREATION DATE:  24.03.2011

  VERSION:        

  CHANGES:        

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_FLOXELPARAMS_H
#define SFOD_OUTPUTINTERFACE_FLOXELPARAMS_H

#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#include "cct_type.h"
#include "common_interface_defines.h"
#include "sfod_outputInterface_baseTypes.h"


#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * object struct define
*****************************************************************************************************************/

typedef ui16_t ParameterAddress_t;
typedef ui16_t ParameterValue_t;

typedef struct _SFODFloxelParamsScalar_t        /*<! single value  */
{
  ParameterAddress_t ParameterAddress;                 
  ParameterValue_t ParameterValue;
} SFODFloxelParamsScalar_t;


#define SFODFloxelParamsScalarVector_MaxNumberOfParamPairs 200

typedef struct _SFODFloxelParamsScalarVector_t  /*<! sequence of values with random addresses */
{
  ui16_t NumberOfParamPairs;
  SFODFloxelParamsScalar_t pairs[SFODFloxelParamsScalarVector_MaxNumberOfParamPairs];
} SFODFloxelParamsScalarVector_t;


typedef struct _SFODFloxelParamsLUT_t         /*!< array of values with subsequent address */
{
  ParameterAddress_t ParameterAddress;
  ParameterValue_t elements[1024];
} SFODFloxelParamsLUT_t;


static const ui32_t SFODFloxelParamsFpga_VersionNumber = 1; /*!< parameters for FPGA harvester */

/*! \brief data structure for FPGA */
typedef struct _SFODFloxelParamsFpga_t
{
  DEFINE_VERSION_MEMBER(SFODFloxelParamsFpga);

  SFODFloxelParamsScalarVector_t randomValues;        /* vector of values with random addres */
  SFODFloxelParamsLUT_t DistanceFromDisparityLUT;

} SFODFloxelParamsFpga_t;


static const ui32_t SFODFloxelParams_VersionNumber = 5; /*!< version of structure SFODFloxelParams_t */
														                            /* version 2:   Several SFODFloxelParamsScalar_t-s ... added */
														                            /* version 3:   element design changed */
														                            /* version 4:   static elements moved to new structure SFODStaticHarvesterParams_t, translation vector removed */
														                            /* version 5:   enable_pedestrian_booster renamed to HV_CTRL */

/*! \brief data structure for Measurement */
typedef struct _SFODFloxelParams_t
{
  DEFINE_VERSION_MEMBER(SFODFloxelParams);

  i16_t HV_CTRL;                                          /* 0x04, i.e. enable_pedestrian_booster, boolean value in bit 2^1 */
  i16_t optical_center_x;                                 /* 0x06 */
  i16_t optical_center_y;                                 /* 0x08 */
  i16_t focal_length_in_pixels;                           /* 0x0A */
  ui16_t reciprocal_of_focal_length_in_pixels;            /* 0x0C, Q24: ui16_t(float wert * 2^24) */
  i16_t max_num_seeds_per_image;                          /* 0x0E */
  i16_t ego_velocity;                                     /* 0x10 */
  i16_t min_pedestrian_distance;                          /* 0x12 */
  i16_t max_pedestrian_distance;                          /* 0x14 */
  i16_t max_pedestrian_lateral_position;                  /* 0x16 */
  i16_t min_pedestrian_height_above_ground;               /* 0x18 */
  i16_t seed_bottom_height;                               /* 0x1A */
  i16_t catch_distance;                                   /* 0x1C */
  i16_t disparity_uncertainty;                            /* 0x1E */
  i16_t pedestrian_to_vehicle_velocity_ratio;             /* 0x20 */  
  i16_t floxel_min_num_valid_pixels;                      /* 0x22, 8 bit */
  i16_t floxel_max_coord_sfod_x;                          /* 0x24 */
  i16_t floxel_min_coord_sfod_x;                          /* 0x26 */ 
  i16_t floxel_max_coord_sfod_z;                          /* 0x2C */
  i16_t floxel_min_coord_sfod_z;                          /* 0x2E */
  i16_t floxel_max_disparity_mad;                         /* 0x30, Q4 */
  i16_t floxel_max_flow_du_mad;                           /* 0x32 */
  i16_t floxel_max_fattening_disparity_jump;              /* 0x34 */
  i16_t floxel_max_fattening_catch_distance;              /* 0x36 */
  i16_t yaw_rate_rad_per_sec;                             /* 0x38 */
  i16_t vehicle_width;                                    /* 0x3A */
  i16_t vehicle_axis_to_front;                            /* 0x3C */
  i16_t camera_height_in_meters;                          /* 0x3E, Q7 */

  i32_t camera_to_sfod_rotation_delta_matrix[3][3];       /* 0x100, Q24 */

  SFODFloxelParamsLUT_t distance_from_disparity_lut;      /* 0x300 */

 
} SFODFloxelParams_t;

static const ui32_t SFODHarvesterImageParams_VersionNumber = 1;  /*!< version of structure SFODHarvesterImageParams_t */

// Image parameters of SFODStaticHarvesterParams_t structure
typedef struct _SFODHarvesterImageParams_t
{
  DEFINE_VERSION_MEMBER( SFODHarvesterImageParams );
  i32_t disparity_start_x; ///< horizontal offset of the disparity image with respect to the top left corner of the full-resolution rectified camera image
  i32_t disparity_start_y; ///< horizontal offset of the disparity image with respect to the top left corner of the full-resolution rectified camera image
  i32_t disparity_width;   ///< width of the disparity image, i.e. the region of the rectified image for which there are disparity measurements
  i32_t disparity_height;  ///< height of the disparity image, i.e. the region of the rectified image for which there are disparity measurements
  i32_t flow_start_x;      ///< horizontal offset of the flow image with respect to the top left corner of the full-resolution rectified camera image
  i32_t flow_start_y;      ///< vertical offset of the flow image with respect to the top left corner of the full-resolution rectified camera image
  i32_t flow_width;        ///< width of the flow image, i.e. the region of the rectified image for which there are flow measurements
  i32_t flow_height;       ///< height of the flow image, i.e. the region of the rectified image for which there are flow measurements
  i32_t sfod_roi_start_x;  ///< horizontal offset of the SFOD ROI with respect to the top left corner of the full-resolution rectified camera image
  i32_t sfod_roi_start_y;  ///< vertical offset of the SFOD ROI with respect to the top left corner of the full-resolution rectified camera image
  i32_t sfod_roi_height;   ///< height of the SFOD ROI, in full-resolution pixels
  i32_t sfod_roi_width;    ///< width of the SFOD ROI, in full-resolution pixels
} SFODHarvesterImageParams_t;


static const ui32_t SFODStaticHarvesterParams_VersionNumber = 1;  /*!< version of structure SFODStaticHarvesterParams_t */

typedef struct _SFODStaticHarvesterParams_t
{
  DEFINE_VERSION_MEMBER( SFODStaticHarvesterParams );

  SFODHarvesterImageParams_t imageParams;

  f32_t ego_velocity_1; /* 10 */
  f32_t ego_velocity_2; /* 20 */
  i32_t floxel_height_in_pixel; /* 12 */
  i32_t floxel_width_in_pixels; /* 12 */
  f32_t frame_period_sec; /* 0.016667 */
  i32_t max_num_startpixels_per_stripe;
  f32_t min_distance_1; /* 3.0f */
  f32_t min_distance_2; /* 6 */

} SFODStaticHarvesterParams_t;


static const ui32_t SFODHarvesterSimParams_VersionNumber = 2; /*!< version of structure SFODHarvesterSimParams__t */
                                                              /*!< 2: added "harvesterParameterSet_FingerPrint" */

typedef struct _SFODHarvesterSimParams_t
{
  DEFINE_VERSION_MEMBER( SFODHarvesterSimParams );

  SFODFloxelParams_t dynamicParams; // --> FPGA-Interface
  SFODStaticHarvesterParams_t staticParams; // --> Harvester Simulation Module

  i16_t   harvesterParameterSet_FingerPrint;                  /* unique finger print of parameter set*/

} SFODHarvesterSimParams_t; // ---> Measfreeze Output Struct



#ifdef __cplusplus
  }
#endif // __cplusplus

#endif /* SFOD_OUTPUTINTERFACE_FLOXELPARAMS_H */

