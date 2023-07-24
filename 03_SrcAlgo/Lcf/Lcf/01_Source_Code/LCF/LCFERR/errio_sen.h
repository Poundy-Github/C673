/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 LCF

  MODULNAME:                 errio.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.7 $


  ---*/ /*---
  CHANGES:                   $Log: errio_sen.h  $
  CHANGES:                   Revision 1.7 2019/11/26 12:11:25CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.6 2019/04/10 03:46:27CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.5 2019/02/19 13:14:26CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.4 2019/01/31 09:24:46CET Grosu, George (uidl9584) 
  CHANGES:                   Add range checks
  CHANGES:                   Revision 1.3 2018/11/15 08:40:21CET Grosu, George (uidl9584) 
  CHANGES:                   ERR: Add Local Freze Frames for Allive checks
  CHANGES:                   ERR: Temporary: No Dem Event for aalive checks
  CHANGES:                   Revision 1.2 2018/10/31 10:03:57CET Grosu, George (uidl9584) 
  CHANGES:                   Add debug signals for Error Handler
  CHANGES:                   Revision 1.1 2018/09/14 16:21:54CEST Grosu, George (uidl9584) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCFERR/project.pj
  CHANGES:                   Revision 1.5 2018/09/11 16:19:51CEST Grosu, George (uidl9584) 
  CHANGES:                   Update error handler
  CHANGES:                   Revision 1.4 2018/07/31 12:24:00CEST Grosu, George (uidl9584) 
  CHANGES:                   Update ERR after review
  CHANGES:                   Revision 1.3 2018/05/25 08:08:42CEST Grosu, George (uidl9584) 
  CHANGES:                   update LCFERR
  CHANGES:                   Revision 1.2 2018/05/24 13:07:16CEST Grosu, George (uidl9584) 
  CHANGES:                   Update LCFERR
  CHANGES:                   Revision 1.1 2018/05/22 16:35:37CEST Grosu, George (uidl9584) 
  CHANGES:                   Reorder files
  CHANGES:                   Revision 1.4 2018/05/18 16:07:13CEST Grosu, George (uidl9584) 
  CHANGES:                   Add Allive counter check
  CHANGES:                   Revision 1.3 2018/05/11 09:06:07CEST Grosu, George (uidl9584) 
  CHANGES:                   Error Handler v1
  CHANGES:                   Revision 1.2 2018/05/10 12:30:21CEST Grosu, George (uidl9584) 
  CHANGES:                   First version of LCFERR

**************************************************************************** */
/* Avoid double inclusion */
#ifndef __ERRIO_SEN_H__
#define __ERRIO_SEN_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "lcf_sen_ext.h"
#include "errio.h"

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
	


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define ERRIOSEN_SIGNAL_SOURCES_CMP_NO  (4u)     /* number of components from which LCF receives input signals that need to be checked */   

/* GeGr: Backward compatibility */
#define LCF_ERRHNDL_LKA  LCF_ERRHNDL_TJA_LC
#define LCF_ERRHNDL_TJA  LCF_ERRHNDL_TJA_OF

#define LCF_RELEVANT_FOR_LKA         ((uint8)((uint8)1u<<LCF_ERRHNDL_LKA)) /* 0x01 */
#define LCF_RELEVANT_FOR_LDP         ((uint8)((uint8)1u<<LCF_ERRHNDL_LDP)) /* 0x02 */
#define LCF_RELEVANT_FOR_RDP         ((uint8)((uint8)1u<<LCF_ERRHNDL_RDP)) /* 0x04 */
#define LCF_RELEVANT_FOR_LDW         ((uint8)((uint8)1u<<LCF_ERRHNDL_LDW)) /* 0x08 */
#define LCF_RELEVANT_FOR_TJA         ((uint8)((uint8)1u<<LCF_ERRHNDL_TJA)) /* 0x10 */
#define LCF_RELEVANT_FOR_ALCA        ((uint8)((uint8)1u<<LCF_ERRHNDL_ALCA))/* 0x20 */
#define LCF_RELEVANT_FOR_SALC        ((uint8)((uint8)1u<<LCF_ERRHNDL_SALC))/* 0x40 */
#define LCF_RELEVANT_FOR_ALL         (0xFFu)

#define LCF_NOTRLVNT_FOR_LKA         (0x00u)
#define LCF_NOTRLVNT_FOR_LDP         (0x00u)
#define LCF_NOTRLVNT_FOR_RDP         (0x00u)
#define LCF_NOTRLVNT_FOR_LDW         (0x00u)
#define LCF_NOTRLVNT_FOR_TJA         (0x00u)
#define LCF_NOTRLVNT_FOR_ALCA        (0x00u)
#define LCF_NOTRLVNT_FOR_SALC        (0x00u)

#define ERRIOSEN_CHECKED_FUNCTIONS_NO   (ERRIO_CHECKED_FUNCTIONS_NO)

#define ERRIOSEN_ALLIVE_MC_FAIL         (0x0001u)
#define ERRIOSEN_ALLIVE_TS_FAIL         (0x0002u)
#define ERRIOSEN_ALLIVE_TSMON_FAIL      (0x0008u)
#define ERRIOSEN_ALLIVE_TSBCD_FAIL      (0x0010u)
#define ERRIOSEN_ALLIVE_CC_FAIL         (0x0004u)

#define ERRIOSEN_CHECK_MC               (0x01u)
#define ERRIOSEN_CHECK_TS               (0x02u)
#define ERRIOSEN_CHECK_CC               (0x04u)

#define GET_ERRIOSEN_AlliveError()      (S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOAllive])
#define SET_ERRIOSEN_AlliveError(val)   (S_ERRSEN_ErrMatrix_btf[ERRSEN_enERRIOAllive] = (val))

#define  SET_D_LCFERR_AlliveFailedMC_btf(i)       (pLCFERR_SenDbgData->D_LCFERR_AlliveFailedMC_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedTSMon_btf(i)    (pLCFERR_SenDbgData->D_LCFERR_AlliveFailedTSMon_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedTSBcd_btf(i)    (pLCFERR_SenDbgData->D_LCFERR_AlliveFailedTSBcd_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedCCMon_btf(i)    (pLCFERR_SenDbgData->D_LCFERR_AlliveFailedCCMon_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedCCConst_btf(i)  (pLCFERR_SenDbgData->D_LCFERR_AlliveFailedCCConst_btf |= ((uint16)1<<(uint16)i))

#define ERRIOSEN_RngChkDbg_btf          pLCFERR_SenDbgData->D_LCFERR_RngChkDbg_btf

#ifndef ERRIOSEN_RANGE_CHECK
#define ERRIOSEN_RANGE_CHECK(signal, min, max, fct, i, btf)     if( ((signal) < (min)) || ((signal)>(max)) ) {ERRIOSEN_RngChkFailed_btf |= (fct); ERRIOSEN_RngChkDbg_btf[(i)]|=(btf);}
#endif

/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/* Output */
extern uint8 ERRIOSEN_ErrStateArray[ERRIOSEN_CHECKED_FUNCTIONS_NO];
/* Needed for debugging */
extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigNormData[];
extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehDynData[];
extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigAddData[];
extern ERRIO_ErrConfigData ERRIOSEN_ErrConfigVehSigMainData[];
extern ERRIO_HeaderParser_t  S_ERRIOSEN_sigHeader[ERRIOSEN_enSigHeadNumber];
extern uint8 ERRIOSEN_size_ErrConfigNormData;
extern uint8 ERRIOSEN_size_ErrConfigVehDynData;
extern uint8 ERRIOSEN_size_ErrConfigVehSigAddData;
extern uint8 ERRIOSEN_size_ErrConfigVehSigMainData;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
//void ERRIOSEN_InputsCheck(const reqLcfSenPrtList_t *reqPorts);
void ERRIOSEN_ResetsigHeaderCnt(void);
void ERRIOSEN_CheckSignalSource(const uint8 *sigStateArray, ERRIO_ErrConfigData configArray[], uint8 sigNumber);

#endif //__ERRIOSEN_H__
