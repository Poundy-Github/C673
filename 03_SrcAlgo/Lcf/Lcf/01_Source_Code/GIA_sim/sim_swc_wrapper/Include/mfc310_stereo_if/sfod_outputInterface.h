/*! \file **********************************************************************

  COMPANY:        Continental AG

  PROJECT:        MFC300

  CPU:

  COMPONENT:      SFOD - Stereo Fast Object Detection

  MODULNAME:      sfod_outputInterface.h

  DESCRIPTION:    subset of input/output structure handling for SFOD data
                  /temporary interface to SPOD

  AUTHOR:         A. Bachmann

  CREATION DATE:  24.09.2010

  VERSION:

  CHANGES:

**************************************************************************** */

#ifndef SFOD_OUTPUTINTERFACE_H
#define SFOD_OUTPUTINTERFACE_H

#if defined(PC_SIM) && !defined(GUYS_BUILD_MESSAGE_COMPRESSOR)
    #pragma message ("- Including [" __TIMESTAMP__ "] " __FILE__ )
#endif //#ifdef PC_SIM

#include "common_interface_defines.h"

//include elements of output structure
#include "sfod_outputInterface_baseTypes.h"
#include "sfod_outputInterface_carpet.h"
#include "sfod_outputInterface_corridor.h"
#include "sfod_outputInterface_object.h"
#include "sfod_outputInterface_floxelParams.h"


#ifdef __cplusplus
  extern "C" {
#endif // __cplusplus

/*****************************************************************************************************************
 * output struct define
*****************************************************************************************************************/

static const ui32_t SFODOutputData_VersionNumber = 9; /*!< version of structure SFODOutputData_t */
                                                      /*!< 2: temporary, no records, */
                                                      /*!<    set version number in constructor (pilot); Ba */
                                                      /*!< 3: extended signal list accoring to FROP REL2.4.0, cast time stamp to 64 bit, rename, reorganize object structure */
                                                      /*!< 4: added FloxelParameterSet */
                                                      /*!< 5: subst FloxelParameterSet by HarvesterParameterSet*/
                                                      /*!< 6: added DebugData*/
                                                      /*!< 7: added ErrorCode*/
                                                      /*!< 8: added DiagOutput*/
                                                      /*!< 9: added VisualOdometry*/
/*! 
 * Type defintion for diagnosis data output message
 */
typedef ui64_t SFODDiagOutput_t;

/*! \brief tbd */
typedef struct _SFODOutputData_t
{
  DEFINE_VERSION_MEMBER(SFODOutputData);

  ui8_t                Status;                          /*!< status information of SFOD (to be (re-)set by Adapter) */
  f32_t                YawRateEgoVehicle;               /*!< yaw rate of own vehicle in [rad/sec]*/
  SFODSignalState_t    SignalStateTimeStamp;            /*!< signal state of TimeStamp */
  ui64_t               Timestamp_usec;                  /*!< time stamp witch input data were the base for the Object generation in micro sec */
  SFODObject_t         SFODObject;                      /*!< object struct, contains object relevant data */
  SFODCorridor_t       Corridor;                        /*!< Corridor information relative to sensor */
  SFODCarpet_t         Carpet;                          /*!< Carpet information relative to sensor */
  SFODHarvesterSimParams_t HarvesterParameterSet;       /*!< dynamic+static Floxel Parameter Set => used in FPGA to create baer floxels*/
  ui64_t               DebugData;                       /*!< reserved 64bit value per cycle, optioally sent to Flexray */
  i32_t                ErrorCode;                       /*!< error code of algo */
  SFODDiagOutput_t     DiagOutput;                      /*!< diagnosis data output message*/
  SFODVisualOdometry_t VisualOdometry;                  /*!< 6 dof motion vector*/
} SFODOutputData_t;


#ifdef __cplusplus
  }
#endif // __cplusplus




#endif /* SFOD_OUTPUTINTERFACE_H */

