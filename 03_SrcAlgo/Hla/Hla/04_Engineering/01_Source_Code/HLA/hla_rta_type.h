/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_rta_type.h

  DESCRIPTION:            RTA (Run Time Analysis) specific definitions

  CREATION DATE:          2016-09-21

  CPU:                    Independent

  VERSION:                $Revision: 1.6 $
  **************************************************************************** */

#ifndef H_HLA_RTA_TYPE_H
#define H_HLA_RTA_TYPE_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/

/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
/// enum for runtime analysis used on ECU and EVM HIL
typedef enum
{
  /// local ID for RTA event for total
  HLA_RTA_TOTAL                                   =   1,
  /// local ID for RTA event for exec
  HLA_RTA_EXEC                                    =   2,
  /// local ID for RTA event for reset
  HLA_RTA_RESET                                   =   3,
  /// local ID for RTA event for run
  HLA_RTA_RUN                                     =   4,
  /// local ID for RTA event for input checks
  HLA_RTA_INPUT_CHECKS                            =   5,
  /// local ID for RTA event for set defaults
  HLA_RTA_SET_DEFAULTS                            =   6,
  /// local ID for RTA event for hlaf
  HLA_RTA_HLAF_EXEC                               =   7,
  /// local ID for RTA event for output checks
  HLA_RTA_OUTPUT_CHECKS                           =   8,
  /// local ID for RTA event for dem events
  HLA_RTA_DEM_EVENTS                              =   9,
  /// local ID for RTA event for hlaf init
  HLA_RTA_HLAF_INIT                               =  20,
  /// local ID for RTA event for hlaf decision
  HLA_RTA_HLAF_DECISION                           =  21,
  /// local ID for RTA event for hlaf matrix
  HLA_RTA_HLAF_MATRIX                             =  22
} HLA_t_RtaEvents; /* RTA_LOCAL_ID_FOR_XML_GENERATION */

#endif /* #ifndef H_HLA_RTA_TYPE_H */
