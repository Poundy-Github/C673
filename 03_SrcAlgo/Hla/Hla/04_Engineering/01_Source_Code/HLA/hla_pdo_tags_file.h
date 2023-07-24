/*! @file ******************************************************************
  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH
 
  PROJECT:                MFC4xx

  COMPONENT:              HLA
                      
  MODULNAME:              hla_pdo_tags_file.c
                      
  DESCRIPTION:            Contains type re-definitions for sdl file generation
                      
  CREATION DATE:          2013-12-12
                      
  CPU:                    Independent

  VERSION:                $Revision: 1.7 $
**************************************************************************** */
/* avoid cyclic binding -----------------------------------------------------*/
#ifndef H_HLA_PDO_TAGS_H
#define H_HLA_PDO_TAGS_H

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#ifdef __PDO__

/* Include header files where all to-be-measfreezed types are defined */
#include "hla_measfreeze_data.h"

/* Re-define to-be-measfreezed types */
typedef AlgoCompState_t                PdoHlaAlgoCompState;           /*!< @vaddr: HLA_MEAS_VADDR_PRO_PORT_ALGO_COMP_STATE  @cycleid: HLA_ENV_PVT @vname: HlaAlgoCompState */
typedef Hla_SyncRef_t                  PdoHlaSyncRef;                 /*!< @vaddr: HLA_MEAS_VADDR_SYNC_REF                  @cycleid: HLA_ENV_PVT @vname: Hla_SyncRef */

typedef HLAFData_t                     PdoHlafData;                   /*!< @vaddr: HLA_MEAS_VADDR_HLAF_DATA                 @cycleid: HLA_ENV_PVT @vname: HlafData */
typedef t_DecisionParameters           PdoHlafParameter;              /*!< @vaddr: HLA_MEAS_VADDR_HLAF_PARAMETER            @cycleid: HLA_ENV_PVT @vname: HlafParameter */
typedef t_MatrixParameters             PdoHlafMatrixParameter;        /*!< @vaddr: HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER     @cycleid: HLA_ENV_PVT @vname: HlafMatrixParameter */
typedef HLAFMatrixData_t               PdoHlafMatrixData;             /*!< @vaddr: HLA_MEAS_VADDR_HLAF_MATRIX_DATA          @cycleid: HLA_ENV_PVT @vname: HlafMatrixData */
typedef t_ErrorHandling_ErrorStack     PdoErrorHandling_ErrorStack;   /*!< @vaddr: HLA_MEAS_VADDR_ERROR_STACK               @cycleid: HLA_ENV_PVT @vname: HlaErrorStack */

#endif /* __PDO__ */

#endif /* #ifndef H_HLA_PDO_TAGS_H */
