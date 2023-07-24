/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface_baseTypes.h  

  DESCRIPTION:    subset of input/output structure handling for SFOD data
                  /temporary interface to SPOD

  AUTHOR:         A. Bachmann

  CREATION DATE:  09.01.2011

  VERSION:        

  CHANGES:        

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_BASETYPES_H
#define SFOD_OUTPUTINTERFACE_BASETYPES_H

#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#include "cct_type.h"
#include "common_interface_defines.h"

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * object struct define
 *****************************************************************************************************************/

/*! \brief tbd */
typedef struct _SFODSensorControlPoint_t // TE: No VersioNumber for this struct
{
  /* position relative to sensor */
  f32_t  PositionX;                              /*!< X-position of control point in meters, direction right */
  f32_t  PositionY;                              /*!< Y-position of control point in meters, direction down  */
  f32_t  PositionZ;                              /*!< Z-position of control point in meters, driving direction */
} SFODSensorControlPoint_t;

static const ui32_t SFODSensorControlPoint_Image_VersionNumber = 1;            /*!< version of structure SFODSensorControlPoint_Image */

/*! \brief tbd */
typedef struct _SFODSensorControlPoint_Image_t
{
  DEFINE_VERSION_MEMBER(SFODSensorControlPoint_Image);

  /* image coordinates of corridor segment */
  ui32_t  ImagePositionX;                               /*!< X-position of control point in pixel */
  ui32_t  ImagePositionY;                               /*!< Y-position of control point in pixel */
} SFODSensorControlPoint_Image_t;

/*! \brief dynamic property */
typedef enum
{
  SFOD_E_DYN_MOVING      = 0u, /*!<  moving object */
  SFOD_E_DYN_STATIONARY  = 1u, /*!<  stationary object */
  SFOD_E_DYN_ONCOMING    = 2u, /*!<  oncoming object */
  SFOD_E_DYN_STOPPED     = 3u, /*!<  stopped object */
  SFOD_E_DYN_CROSSING    = 4u, /*!<  crossing object */
  SFOD_E_DYN_CUT_IN      = 5u, /*!<  cut in */
  SFOD_E_DYN_CUT_OUT     = 6u, /*!<  cut out */
  SFOD_E_DYN_OVERTAKING  = 7u, /*!<  overtaking object */
  SFOD_E_DYN_BREAKING    = 8u, /*!<  breaking */
  SFOD_E_DYN_BACKSLIDING = 9u, /*!<  backsliding */
  SFOD_E_DYN_UNCLASSIFIED= 10u /*!<  unclassified */
}SFODDynamicProperty_e;

/*! \brief  signal/variable state */
typedef enum
{
  SFOD_SIG_NOT_OK = 0u,  /*!< signal not available */
  SFOD_SIG_OK     = 1u   /*!< signal available */
} SFODSignalState_t;


/*! \brief  signal/variable state */
typedef enum
{
  SFOD_SIG_FALSE = 0u,   /*!< signal false */
  SFOD_SIG_TRUE = 1u,  /*!< signal true */
  SFOD_SIG_SNA = 2u  /*!< signal not available */
} SFODSignalTriState_t;

/*! \brief POD relevance {0,1,2,3}
              |       |
          2_  | 1 _   |  3_  
          |_| |  |_|  |  |_|
              |       |
              |       |        */
typedef enum
{
  SFOD_OBJECT_RELEVANCE_NO     = 0u,  /*!< object not relevant for POD */
  SFOD_OBJECT_RELEVANCE_CENTER = 1u,  /*!< center object relevant for POD */
  SFOD_OBJECT_RELEVANCE_LEFT   = 2u,  /*!< left object relevant for POD */
  SFOD_OBJECT_RELEVANCE_RIGHT  = 3u   /*!< right object relevant for POD */
} SFODObjectRelevancePOD_t;

/*! Describes the overall algo status */
typedef enum
{
  SFOD_STATE_FAULT   = 0u, /*!< FOD failed permanently */
  SFOD_STATE_OK      = 1u, /*!< FOD ready and running */
  SFOD_STATE_NA_TEMP = 2u, /*!< FOD temporarily not available */
  SFOD_STATE_NA_IDLE = 3u  /*!< FOD idle */
} SFODStatus_t;

static const ui32_t SFODVisualOdometry_VersionNumber = 1; /*!< version of structure SFODVisualOdometry_t */

/*! \brief tbd */
typedef struct _SFODVisualOdometry_t
{
  DEFINE_VERSION_MEMBER(SFODVisualOdometry);

  /* 6 dof motion vector */
  f32_t  TransX_mps;                            /*!< translational X-component in meters per second */
  f32_t  TransY_mps;                            /*!< translational Y-component in meters per second */
  f32_t  TransZ_mps;                            /*!< translational Z-component in meters per second */
  f32_t  RotX_rps;                              /*!< rotational X-component in rad per second */
  f32_t  RotY_rps;                              /*!< rotational Y-component in rad per second */
  f32_t  RotZ_rps;                              /*!< rotational Z-component in rad per second */
  f32_t  TransVarX;                             /*!< variance translational X-component*/
  f32_t  TransVarY;                             /*!< variance translational Y-component*/
  f32_t  TransVarZ;                             /*!< variance translational Z-component*/
  f32_t  RotVarX;                               /*!< variance rotational X-component*/
  f32_t  RotVarY;                               /*!< variance rotational Y-component*/
  f32_t  RotVarZ;                               /*!< variance rotational Z-component */
} SFODVisualOdometry_t;




#ifdef __cplusplus
  }
#endif // __cplusplus

#endif /* SFOD_OUTPUTINTERFACE_BASETYPES_H */

