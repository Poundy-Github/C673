/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:            

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface_carpet.h  

  DESCRIPTION:    subset of input/output structure handling for SFOD data
                  /temporary interface to SPOD

  AUTHOR:         A. Bachmann

  CREATION DATE:  09.01.2011

  VERSION:        

  CHANGES:        

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_CARPET_H
#define SFOD_OUTPUTINTERFACE_CARPET_H

#include "common_interface_defines.h"
#include "sfod_outputInterface_baseTypes.h"
#include "cct_type.h"

#define SFOD_CARPETCRAWLER_ELEMENTS 100U                     /*! \brief  max number in m distance in current implementation */
#define SFOD_CARPETCRAWLER_DEFAULTVALUE_HEIGHT  -1000.0F 	  /*! default value for elements of carpet structure [also needen in SPOD!] */

#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * object struct define
 *****************************************************************************************************************/

static const ui32_t SFODCarpetSegment_VersionNumber = 2;                 /*!< version of structure SFODCarpet_t */
                                                                         /*!< 2: negate height profile for versionNumber <2 ; Ba */

/*! \brief tbd */
typedef struct _SFODCarpetSegment_t
{
  // Segment of the carpet
  DEFINE_VERSION_MEMBER(SFODCarpetSegment);

  f32_t HeightProfile;                                  /*!< contains carpet height profile*/
  SFODSensorControlPoint_Image_t BorderPointLeft_Image; /*!< left border control point of carpet in pixel*/
  SFODSensorControlPoint_Image_t BorderPointRight_Image;/*!< right border control point of carpet in pixel*/
} SFODCarpetSegment_t;



static const ui32_t SFODCarpet_VersionNumber = 3;                 /*!< version of structure SFODCarpet_t */
                                                                  /*!< 2: change order of elements ; Ba, TE */
                                                                  /*!<     + added fCarpetStartX, fCarpetSegmentLength; Ba */
                                                                  /*!< 3: added SignalStateCarpetData */
/*! \brief  carpet data container */
typedef struct _SFODCarpet_t
{
  DEFINE_VERSION_MEMBER(SFODCarpet);

  SFODSignalState_t   SignalStateCarpetData;                           /*!< OK if data valid, NOK if data invalid */

  f32_t               fCarpetStartX;                                  /*!< carpet starting point along X in meter (AUTOSAR) */
  f32_t               fCarpetSegmentLength;                           /*!< carpet segment length along X in meter */

  ui32_t              NumberOfCarpetElements_ui32;                    /*!< contains number of valid carpet elements */
  SFODCarpetSegment_t Segment[SFOD_CARPETCRAWLER_ELEMENTS];           /*!< contains carpet height profile, etc. */

} SFODCarpet_t;



#ifdef __cplusplus
  }
#endif // __cplusplus

#endif /* SFOD_OUTPUTINTERFACE_CARPET_H */

