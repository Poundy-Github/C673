/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx
 
  COMPONENT:              HLA
 
  FILENAME:               hla_ver.h
 
  DESCRIPTION:            Algo version number controlling.
 
  CREATION DATE:          2016-09-07
 
  CPU:                    Independent
 
  VERSION:                $Revision: 1.41.1.11 $
**************************************************************************** */
/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_VER_H
#define H_HLA_VER_H


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/


/* Component version number as 4 byte value: AA.BB.CC_INT-DD
  AA: Generation version, i.e. MFC431, MFC500, etc.
  BB: Release cycle version, i.e. R4.0, R4.1, R5.0, etc.
  CC: Incremental counter for each checkpoint during one release cycle
  DD: Hot fix counter, shall only be used for hot fixes of older checkpoints, i.e. only if HLAALL_SW_BUG_FIX_LEV is not the most recent version
*/

#define HLAALL_SW_MAIN_VER_NO                 6U       ///< Generation version, i.e. MFC431, MFC500, etc.
#define HLAALL_SW_SUB_VER_NO                 39U       ///< Component release cycle version, i.e. every second week
#define HLAALL_SW_BUG_FIX_LEV                 0U       ///< Incremental counter for manual component releases created in between
#define HLAALL_SW_BUG_FIX_LEV2               11U       ///< Incremental counter for checkpoints on branches

/*! HLA version number: */
#define HLA_SW_VERSION_NUMBER (((AlgoComponentVersionNumber_t)HLAALL_SW_MAIN_VER_NO << 24) | ((AlgoComponentVersionNumber_t)HLAALL_SW_SUB_VER_NO << 16) | ((AlgoComponentVersionNumber_t)HLAALL_SW_BUG_FIX_LEV << 8) | ((AlgoComponentVersionNumber_t)HLAALL_SW_BUG_FIX_LEV2)) ///< HLA version number as 4 byte BCD (binary coded decimal) AA.BB.CC.DD. But for checkpoint name it is used like this SW_LSD_AA.BB.CD

#define HLA_SW_VERSION_INFO  "HLA for MFC431x projects" ///< Version information string

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_VER_H */
