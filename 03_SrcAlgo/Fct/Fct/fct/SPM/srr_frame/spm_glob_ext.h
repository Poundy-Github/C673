/*! \file **********************************************************************

  COPYRIGHT (C) CONTINENTAL

  $FILENAME:                 spm_glob_ext.h $

  $PROJECT:                  SRR5xx $

  $DESCRIPTION:              This file contains all defines that are global for spm functions $

  LAST REVISION:             $Revision: 1.1 $

  LAST AUTHOR:               $Author: Pallo, Istvan (palloi) $

  CHANGES:          $Log: spm_glob_ext.h  $
  CHANGES:          Revision 1.1 2020/06/25 18:12:37CEST Pallo, Istvan (palloi) 
  CHANGES:          Initial revision
  CHANGES:          Member added to project /ADAS/SW/Components/SPM_SensorPerformanceMonitoring/04_Engineering/01_Source_Code/SPM/srr_frame/project.pj
  CHANGES:          Initial revision

*****************************************************************************/
/** @defgroup frame FRAME (Global Variable Framework)
   @ingroup sim_swc_spm

@{ */ 

#ifndef SPM_GLOB_EXT_H
#define SPM_GLOB_EXT_H

/*use internal global header files*/
#include "algo_glob.h"
#include "spm_cfg.h"


/*****************************************************************************
  MACROS 
*****************************************************************************/
  /* Makros for declaration and definition of TP application parameters 
    @description:

    TP_DECL_ADJ_PARAM : use in [sub-comp]_par.h file to DECLARE a     "adjustable" parameter in RAM 
    TP_DECL_FIX_PARAM : use in [sub-comp]_par.h file to DECLARE a "NOT adjustable" parameter in ROM 
      usage: 
           \#define <sub-comp>_PARAM_NAME   <sub-comp>_PARAM_NAME_c      // ( \#define parameter name and map it to variable
                                                                         //   in code only name of parameter is used, NOT variable name (_c)
            TP_DECL_FIX_PARAM( [type],      <sub-comp>_PARAM_NAME_c )    // ( declaration of fix/adjustable parameter )

    TP_DEF_ADJ_PARAM : use in <sub-comp>_par.c file to DEFINE a     "adjustable" parameter in RAM 
    TP_DEF_FIX_PARAM : use in <sub-comp>_par.c file to DEFINE a "NOT adjustable" parameter in ROM 
      usage: 
            TP_DEF_FIX_PARAM( [type] , <sub-comp>_PARAM_NAME_c , [value] )                                   
            
     notice: declaration AND definition must be of same type (data type and FIX/ADJ)!!            */

/*****************************************************/
/* date: 2014-07-07, reviewer: D. Stenmanns, reason: */
/* The following macros are proven in use.           */
/*****************************************************/
/* PRQA S 3410, 3412 L1 */
#define FCT_DECL_ADJ_PARAM(type_, name_)       extern       type_ name_;
#define FCT_DECL_FIX_PARAM(type_, name_)       extern const type_ name_;

#define FCT_DEF_ADJ_PARAM(type_, name_, value_)             type_ name_ = (value_);
#define FCT_DEF_FIX_PARAM(type_, name_, value_)       const type_ name_ = (value_);
/* PRQA L:L1 */

#endif
/** @} end defgroup */
