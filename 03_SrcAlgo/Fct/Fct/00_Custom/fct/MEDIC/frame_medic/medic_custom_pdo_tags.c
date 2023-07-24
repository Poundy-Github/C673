/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_custom_pdo_tags.c

DESCRIPTION:               This module contains MEDIC custom PDO tags 

AUTHOR:                    $Author: Ramachandra, Rashmi (uids9858) $

CREATION DATE:             $Date: 2019/11/22 10:43:20CET $

VERSION:                   $Revision: 1.4.1.8 $
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

#if MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION
#if MEDIC_CFG_HEAD20
#include "head20/head20_int.h"
#else
#include "head/head_int.h"
#endif

#ifdef __PDO__
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         medic_pdo pdo tags for medic custom
@ingroup          frame_medic
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/

/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/
#if (MEDIC_ARCHITECTURE_VERSION < 0x10)
typedef HEADModuleOutputStruct_t    PDO_HEADModuleOutputStruct_t;       /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_OUTFUNC_DATA
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   HEADModuleOutputData */

typedef HEADCustomCodingInfo_t      PDO_HEADCustomCodingInfo_t;         /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_CUSTOM_DATA
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   HEADCodingInfo */

typedef HEADMTSCustHypData_t        PDO_HEADMTSCustHypData_t;           /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_CUSTOM_HYP_PAR
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   HEADCustHypPar */

typedef HEADMTSSpecificData_t       PDO_HEADMTSSpecificData_t;          /*!< @VADDR:   FCT_MEAS_ID_CGEB_HEAD_GSM_DATA
                                                                             @CYCLEID: FCT_VEH
                                                                             @VNAME:   HEADExtData */
#else
/*! @VADDR: MEDIC_VA_ASILB_SLOW_INTRA_CYCLE_MEAS @CYCLEID: MEDIC_ENV @VNAME: MEDIC_IntraMeas */
typedef MEDIC_DataWrapperIntraMeas_t PDO_MEDIC_IntraMeas;

/*! @VADDR: MEDIC_VA_ASILB_SLOW_INTER_CYCLE_MEAS @CYCLEID: MEDIC_ENV @VNAME: MEDIC_InterMeas */
typedef MEDIC_DataWrapperInterMeas_t PDO_MEDIC_InterMeas;
#endif /* MEDIC_ARCHITECTURE_VERSION */
#endif // __PDO__
#endif // MEDIC_CFG_HYPOTHESIS_EVAL_AND_DECISION

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}

