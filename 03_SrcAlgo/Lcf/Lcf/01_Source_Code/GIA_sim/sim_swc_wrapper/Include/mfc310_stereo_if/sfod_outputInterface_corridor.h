/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface_corridor.h  

  DESCRIPTION:    subset of input/output structure handling for SFOD data
                  /temporary interface to SPOD

  AUTHOR:         A. Bachmann

  CREATION DATE:  09.01.2011

  VERSION:        

  CHANGES:        

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_CORRIDOR_H
#define SFOD_OUTPUTINTERFACE_CORRIDOR_H

#include "common_interface_defines.h"
#include "sfod_outputInterface_baseTypes.h"


#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * object struct define
 *****************************************************************************************************************/
 
static const ui32_t SFODCorridorSegment_VersionNumber = 2;  /*!< version of structure SFODCorridorSegment_t */
                                                            /* version 1: image coordinates */
                                                            /* version 2: pseudo Autosar coordinates */ 
/*! \brief tbd */
typedef struct _SFODCorridorSegment_t
{
  DEFINE_VERSION_MEMBER(SFODCorridorSegment);

  // Segment of the corridor
  SFODSensorControlPoint_t BorderPointLeft;             /*!< left border control point of corridor*/
  SFODSensorControlPoint_t BorderPointRight;            /*!< right border control point of corridor*/
  SFODSensorControlPoint_Image_t BorderPointLeft_Image; /*!< left border control point of corridor in pixel*/
  SFODSensorControlPoint_Image_t BorderPointRight_Image;/*!< right border control point of corridor in pixel*/
} SFODCorridorSegment_t;


static const ui32_t SFODCorridorSegmentSizes_VersionNumber = 1;  /*!< version of enumeration SFODCorridorSegmentSizes_e */

/*! \brief tbd */
typedef enum
{
  /* Dimension of SFODCorridorSegment_t array in SFODCorridor_t */
  SFOD_E_MAX_NUMBER_OF_CORRIDORSEGMENTS = 100u

} SFODCorridorSegmentSizes_e;



static const ui32_t SFODCorridor_VersionNumber = 3;                   /*!< version of structure SFODCorridor_t */
                                                                      /*!< version 2: change of sequence, nNumberOfSegments before array */
                                                                      /* version 3: added SignalStateCorridorData */

/*! \brief tbd */
typedef struct _SFODCorridor_t
{
  DEFINE_VERSION_MEMBER(SFODCorridor);

  SFODSignalState_t   SignalStateCorridorData;          /*!< OK if data valid, NOK if data invalid */

  ui32_t nNumberOfSegments;                       /*!< Number of defined Corridor Segments in array "segments" */
  SFODCorridorSegment_t segments[ SFOD_E_MAX_NUMBER_OF_CORRIDORSEGMENTS ];     /*!< Array of Corridor Segments */

} SFODCorridor_t;


#ifdef __cplusplus
  }
#endif // __cplusplus

#endif /* SFOD_OUTPUTINTERFACE_CORRIDOR_H */

