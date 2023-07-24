/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA

  MODULNAME:              hla_measfreeze_data.h

  DESCRIPTION:            Everything related to measfreezes.

  CREATION DATE:          2016-09-22
  
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */
#ifndef H_HLA_MEASFREEZE_DATA_H
#define H_HLA_MEASFREEZE_DATA_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hlaf_type.h"
#include "HLA_DecisionParameters.h"
#include "HLA_MatrixParameters.h"
#include "hlaf_matrix.h"
#include "hla_errorhandling.h"

/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define HLA_MEAS_VADDR_PADDING_BYTES 128u                                                                                                                               ///< padding byes, which are added meas freeze address
/* Virtual addresses for internal measfreezes */
#define HLA_MEAS_VADDR_HLAF_DATA                       ((uint32)HLA_MEAS_VADDR_REQ_PORT_RADAR_OBJECT_LIST  + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(Hla_SyncRef_t))              ///< meas freeze address of hlaf data
#define HLA_MEAS_VADDR_HLAF_PARAMETER                  (HLA_MEAS_VADDR_HLAF_DATA                   + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(HLAFData_t))                 ///< meas freeze address of hlaf parameter
#define HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER           (HLA_MEAS_VADDR_HLAF_PARAMETER              + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(t_DecisionParameters))       ///< meas freeze address of hlaf decison parameters
#define HLA_MEAS_VADDR_HLAF_MATRIX_DATA                (HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER       + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(t_MatrixParameters))         ///< meas freeze address of hlaf matrix parameters
#define HLA_MEAS_VADDR_ERROR_STACK                     (HLA_MEAS_VADDR_HLAF_MATRIX_DATA            + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(HLAFMatrixData_t))           ///< meas freeze address of error stack
 
#define HLA_MEAS_VADDR_LAST_ITEM                       (HLA_MEAS_VADDR_ERROR_STACK                 + HLA_MEAS_VADDR_PADDING_BYTES + sizeof(t_ErrorHandling_ErrorStack)) ///< Just a placeholder macro for an easy calculation of next virtual address for SIL only measfreezes.
#define HLA_MEAS_VADDR_LAST_ITEM_ALIGNED               (((HLA_MEAS_VADDR_LAST_ITEM / 0x100) + 1) * 0x100)                                                               ///< Just a placeholder macro with an aligned address for an easy calculation of next virtual address for SIL only measfreezes.


/* Virtual addresses for internal measfreezes that are only triggered in certain situations (debug mode, simulation, etc.) */

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  FUNCTIONS 
*****************************************************************************/

#endif /* #ifndef H_HLA_MEASFREEZE_DATA_H */
