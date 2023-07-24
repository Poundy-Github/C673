/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC5xx

  COMPONENT:              HLA

  MODULNAME:              hla_project_defs.h

  DESCRIPTION:            Generic defines for MFC5J3

  CREATION DATE:          2022-06-09
  
  CPU:                    Independent

  VERSION:                $Revision: 1.0.0.0 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_MFC5J3_DEFS_H
#define H_HLA_MFC5J3_DEFS_H

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/

#define HLA_REMOVE_VERSIONNUMBER_CHECK       ///< remove version number check 
#define HLA_REMOVE_ALIVE_CHECK               ///< remove timestamp and measurementcounter check 

// #define HLA_REMOVE_SIGSTATUS_CHECK           ///< remove eSigStatus invalid check 
// #define HLA_REMOVE_SERVICEFCT      ///< remove service functions for temp integration




/***************Feature*******************/
#define HLA_Mono_CALIBRATION  STD_OFF      ///< Mono Calibration
#define HLA_DIMMING  STD_OFF      ///< dimming
#define HLA_CAM_ROT  STD_OFF      ///< camera rotation

/***************To Do*******************/
#define HLA_LSD  STD_OFF      ///< LSD object
#define HLA_MATRIX  STD_OFF      ///< camera rotation

/***************Optional*******************/
#define HLA_EM_OBJ  STD_OFF      ///< EM OBJECT LIST
#define HLA_RADAR_OBJ  STD_OFF      ///< HLA RADAR OBJECT LIST

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_PROJECT_DEFS_H */
