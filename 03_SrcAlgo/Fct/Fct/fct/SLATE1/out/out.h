/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OUT (Output)

PACKAGENAME:               out.h

DESCRIPTION:               Internal header file for ACC Output (OUT) module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.5 $

LEGACY VERSION:            Revision: 2.0.1.1

**************************************************************************** */
#ifndef OUT_H_INCLUDED
#define OUT_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "slate.h"
#include "out_par.h"
#if (FCT_CFG_ACC_OUTPUT)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup out
@{ */
#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMOBLIC CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  CONSTANTS (COMPONENT INTERNAL SCOPE)
*****************************************************************************/


/*****************************************************************************
  VARIABLES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/
/*! External declaration of component internal pointer to OUT Input structure for global access within OUT */
extern MEMSEC_REF OUTInputConst_t * pt_OUTInput;

/*! External declaration of OUT output structure whose content is filled in this component*/
extern MEMSEC_REF OUTOutput_t * pt_OUTOutput;


/*****************************************************************************
  FUNCTION PROTOTYPES (COMPONENT INTERNAL SCOPE)
*****************************************************************************/

/*--- out_main.c ---*/
extern void OUT_v_MeasCallback(void);

/*---out_output.c---------*/
extern void OUT_v_GenerateOutputData(void);

#if (FCT_MEASUREMENT)
extern void OUT_v_FreezeData(OUT_t_Meas * const pMeasObjs); /* Remark: freeze to be done in component */
#endif

/*--- out_customfunctions.c ---*/
extern void OUT_v_CustomProcess(void);
extern void OUT_v_InitCustom(void);
extern void OUT_v_MergeCustomObjects( ObjNumber_t uiObjectToKeep,ObjNumber_t uiObjectToDelete );
#if (OUT_CFG_CUSTOM_OOI_MEAS_DATA)
extern void OUT_v_CustFillMeasOOI(ObjNumber_t ObjId, OUT_t_CustMeasOOI * pDestMeasData);
#endif
#if (FCT_CFG_SEN2VEH_ACC_OOI_PORT)
extern void OUT_v_CustomInitSEN2VEHOOI(void);
extern void OUT_v_CustomInitOOIAttributes(AccOOIGenAttributes_t * pt_AccOOIAttributes);
extern void OUT_v_CustomInitOOIKinematic(AccOOIGenKinematics_t * pt_AccOOIKinematic);
#endif

#ifdef __cplusplus
};
#endif
///@}
#endif /*!< FCT_CFG_ACC_LANE_OUTPUT */

/* End of conditional inclusion */
#endif  /*!< _OUT_H_INCLUDED */
