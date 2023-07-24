/*! \file **********************************************************************

  COPYRIGHT (C) CONTINENTAL

  $FILENAME:                 spm_sen_ext.h $

  $PROJECT:                  SRR5xx $

  $DESCRIPTION:              function type definition for all generic algo interfaces  $

  LAST REVISION:             $Revision: 1.1 $

  LAST AUTHOR:               $Author: Pallo, Istvan (palloi) $
  
  CHANGES:                
  ---*/ /*---
  CHANGE:                    $Log: spm_sen_ext.h  $
  CHANGE:                    Revision 1.1 2020/06/25 07:02:34CEST Pallo, Istvan (palloi) 
  CHANGE:                    Initial revision
  CHANGE:                    Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/srr_frame/project.pj
  CHANGE:                    Initial revision
**************************************************************************** */
/**
  @defgroup spm_sen SPM_SEN

  @ingroup sim_swc_spm

  Receives input data as explicit parameter passed to the main FCTSen_Exec
  function. This function also gets pointers to all output parameters.

    @todo fct_sen revise naming of functions and component itself.

@{ */


#ifndef SPM_SEN_EXT_H_INCLUDED
#define SPM_SEN_EXT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "spm_glob_ext.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLISCHE KONSTANTEN 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/

/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/*****************************************************************************
  VARIABLEN (KOMPONENTENEXTERN)
*****************************************************************************/


/*****************************************************************************
  FUNKTIONEN (KOMPONENTENEXTERN)
*****************************************************************************/

#ifdef __cplusplus
}
#endif
#endif /* _SPM_SEN_EXT_H_INCLUDED */
/** @} end defgroup */
