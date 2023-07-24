/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_project_defs.h

  DESCRIPTION:            Contains project specific defines

  CREATION DATE:          2014-03-21
  
  CPU:                    Independent

  VERSION:                $Revision: 1.8.8.1 $
**************************************************************************** */

/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_PROJECT_DEFS_H
#define H_HLA_PROJECT_DEFS_H

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
/* Macros for projects */
#define HLA_PROJECT_MFC431         1u      ///< MFC431: Mono cam base project.
#define HLA_PROJECT_MFC431TA19     2u      ///< MFC431: Mono cam project for Toyota
#define HLA_PROJECT_MFC431LO19     3u      ///< MFC431: Mono cam project for Lynk & Co (Geely)
#define HLA_PROJECT_MFC431SC19     4u      ///< MFC431: Mono cam project for SAIC
#define HLA_PROJECT_MFC431SW19     5u      ///< MFC431: Mono cam project for SGMW
#define HLA_PROJECT_MFC431VA10     6u      ///< MFC431: Mono cam project for Venucia
#define HLA_PROJECT_MFC431BD10     7u      ///< MFC431: Mono cam project for BYD
#define HLA_PROJECT_MFC510        30u      ///< Mono cam base project for MFC510 platforms
#define HLA_PROJECT_MFC520        40u      ///< Mono cam base project for MFC520 platforms
#define HLA_PROJECT_MFC525        50u      ///< Mono cam base project for MFC525 platforms

/* Defines active project */
#define HLA_PROJECT HLA_PROJECT_MFC431BD10 ///< Active project used to switch on/off features and cope with RTE incompatibilities.

/* avoid cyclic binding -----------------------------------------------------*/
#endif /* #ifndef H_HLA_PROJECT_DEFS_H */
