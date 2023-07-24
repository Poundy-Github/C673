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

  VERSION:                   $Revision: 1.8 $


  ---*/ /*---
  CHANGES:                   $Log: errio_veh.h  $
  CHANGES:                   Revision 1.8 2020/01/14 11:36:35CET Grosu, George (uidl9584) 
  CHANGES:                   adapt ALGO_FUSI_DEBOUNCE_TIME
  CHANGES:                   fix some qaf findings
  CHANGES:                   Revision 1.7 2019/11/26 12:11:25CET Grosu, George (uidl9584) 
  CHANGES:                   bring TA19 changes to trunk
  CHANGES:                   Revision 1.6 2019/04/10 03:46:28CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF files for auxcodegen v4.0
  CHANGES:                   Revision 1.5 2019/03/20 10:34:07CET Grosu, George (uidl9584) 
  CHANGES:                   move errio signals
  CHANGES:                   Revision 1.4 2019/03/07 14:51:42CET Grosu, George (uidl9584) 
  CHANGES:                   Update trunk for LCFERR
  CHANGES:                   Revision 1.3 2019/02/24 17:09:24CET Grosu, George (uidl9584) 
  CHANGES:                   Adjust includes for veh
  CHANGES:                   Revision 1.2 2019/02/19 13:14:26CET Grosu, George (uidl9584) 
  CHANGES:                   add Intertask errors. Use algo signal names
  CHANGES:                   Revision 1.1 2018/09/14 16:22:09CEST Grosu, George (uidl9584) 
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
#ifndef __ERRIO_VEH_H__
#define __ERRIO_VEH_H__
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "errio.h"
#include "LCFERR/ERRIO_VehCustom.h"

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
	

/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/
#define ERRIOVEH_SIGNAL_SOURCES_CMP_NO    (4u)     /* number of components from which LCF receives input signals that need to be checked */   

#define ERRIOVEH_CHECKED_FUNCTIONS_NO     (ERRIO_CHECKED_FUNCTIONS_NO)

#define LCF_RELEVANT_FOR_DMC         ((uint32)((uint32)1u<<(uint32)LCF_ERRHNDL_LATDMC)) /* 0x0800 */
#define LCF_RELEVANT_FOR_ALL         ((uint32)LCF_RELEVANT_FOR_DMC)

#define LCF_NOTRLVNT_FOR_DMC         (0x00u)


#define ERRIOVEH_ALLIVE_MC_FAIL         (0x00000001u)
#define ERRIOVEH_ALLIVE_TS_FAIL         (0x00000002u)
#define ERRIOVEH_ALLIVE_TSMON_FAIL      (0x0008u)
#define ERRIOVEH_ALLIVE_TSBCD_FAIL      (0x0010u)
#define ERRIOVEH_ALLIVE_CC_FAIL         (0x00000004u)

#define ERRIOVEH_CHECK_MC               (0x01u)
#define ERRIOVEH_CHECK_TS               (0x02u)
#define ERRIOVEH_CHECK_CC               (0x04u)

#define ALGO_LCF_FUSI_DEBOUNCE_TIME     (245000)/* issue 1250133: ALGO_FUSI_DEBOUNCE_TIME + 60ms */


#define GET_ERRIOVEH_AlliveError()      (S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOAllive])
#define SET_ERRIOVEH_AlliveError(val)   (S_ERRVEH_ErrMatrix_btf[ERRVEH_enERRIOAllive] = (val))

#define  SET_D_LCFERR_AlliveFailedMC_btf(i)       (pLCFERR_VehDbgData->D_LCFERR_AlliveFailedMC_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedTSMon_btf(i)    (pLCFERR_VehDbgData->D_LCFERR_AlliveFailedTSMon_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedTSBcd_btf(i)    (pLCFERR_VehDbgData->D_LCFERR_AlliveFailedTSBcd_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedCCMon_btf(i)    (pLCFERR_VehDbgData->D_LCFERR_AlliveFailedCCMon_btf |= ((uint16)1<<(uint16)i))
#define  SET_D_LCFERR_AlliveFailedCCConst_btf(i)  (pLCFERR_VehDbgData->D_LCFERR_AlliveFailedCCConst_btf |= ((uint16)1<<(uint16)i))


#define ERRIOVEH_RngChkDbg_btf          pLCFERR_VehDbgData->D_LCFERR_RngChkDbg_btf
#ifndef ERRIOVEH_RANGE_CHECK
#define ERRIOVEH_RANGE_CHECK(signal, min, max, fct, i, btf)     if( ((signal) < (min)) || ((signal)>(max)) ) {ERRIOVEH_RngChkFailed_btf |= (fct); ERRIOVEH_RngChkDbg_btf[(i)]|=(btf);}
#endif


#ifndef SET_ERRIOVEH_ErrStateArray
#define SET_ERRIOVEH_ErrStateArray(i,status) ERRIOVEH_ErrStateArray[(i)] = (status)
#endif

#ifndef GET_ERRIOVEH_ErrStateArray
#define GET_ERRIOVEH_ErrStateArray(i) ERRIOVEH_ErrStateArray[(i)]
#endif



/*****************************************************************************
  STRUCTURES AND TYPEDEFS
*****************************************************************************/

/* Output */
extern uint8 ERRIOVEH_ErrStateArray[ERRIOVEH_CHECKED_FUNCTIONS_NO];
/* Needed for debugging */
extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigNormData[];
extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehDynData[];
extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigAddData[];
extern ERRIO_ErrConfigData ERRIOVEH_ErrConfigVehSigMainData[];
extern ERRIO_HeaderParser_t  S_ERRIOVEH_sigHeader[ERRIOVEH_enSigHeadNumber];
extern uint8 ERRIOVEH_size_ErrConfigNormData;
extern uint8 ERRIOVEH_size_ErrConfigVehDynData;
extern uint8 ERRIOVEH_size_ErrConfigVehSigAddData;
extern uint8 ERRIOVEH_size_ErrConfigVehSigMainData;

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
//void ERRIOVEH_InputsCheck(const reqLcfSenPrtList_t *reqPorts);
void ERRIOVEH_ResetsigHeaderCnt(void);
void ERRIOVEH_CheckSignalSource(const uint8 *const sigStateArray, ERRIO_ErrConfigData configArray[], const uint8 sigNumber);

#endif //__ERRIOSEN_H__
