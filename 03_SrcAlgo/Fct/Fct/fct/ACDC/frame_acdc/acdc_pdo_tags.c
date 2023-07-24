/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               $Source: acdc_pdo_tags.c $

DESCRIPTION:               This module contains ACDC PDO tags 

AUTHOR:                    $Author: Stein, Lukas (uidq3902) $

CREATION DATE:             $Date: 2018/11/20 17:57:49CET $

VERSION:                   $Revision: 1.14 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "acdc_int.h"
#include "cd_int.h"
#include "espm_int.h"

#if (ACDC_CFG_FRAME)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         acdc_pdo   pdo tags for acdc
@ingroup          frame
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/


/*****************************************************************************
  PDO TYPEDEFS
*****************************************************************************/

/* ACDC */
#if FCT_CFG_USE_ALGOCOMPSTATE                                       
typedef AlgoCompState_t             PDO_AlgoCompState_t             ;  /*!< @VADDR:FCT_MEAS_ID_SEN_EBA_COMP_STATE           
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_CompState        */
#endif                                                              

#if (USE_ACDCWRAPPER_INTERMEAS)
typedef ACDC_DataWrapperInterMeas_t PDO_ACDC_DataWrapperInterMeas_t ;  /*!< @VADDR: GA_ACDC_MEAS_ID_INTER_CYCLE_MEAS_DATA        
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_InterCycleDataMeas */
#endif

#if (USE_ACDCWRAPPER_INTRAMEAS)
typedef ACDC_DataWrapperIntraMeas_t PDO_ACDC_DataWrapperIntraMeas_t ;  /*!< @VADDR: GA_ACDC_MEAS_ID_INTRA_CYCLE_MEAS_DATA   
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_IntraCycleDataMeas */
#endif

#if ACDC_SIMU
#if (USE_ACDCWRAPPER_INTER)
typedef ACDC_DataWrapperInter_t     PDO_ACDC_DataWrapperInter_t ;      /*!< @VADDR: GA_ACDC_MEAS_ID_INTER_CYCLE_DATA        
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_InterCycleData */
#endif

#if (USE_ACDCWRAPPER_STACK)
typedef ACDC_DataWrapperStack_t      PDO_ACDC_DataWrapperStack_t    ;  /*!< @VADDR: GA_ACDC_MEAS_ID_STACK        
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_StackData */
#endif

#if (USE_ACDCWRAPPER_INTRA)
typedef ACDC_DataWrapperIntra_t     PDO_ACDC_DataWrapperIntra_t      ;  /*!< @VADDR: GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA        
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_IntraCycleData */
#endif

#if (USE_ACDCWRAPPER_SIMU)
typedef ACDC_DataWrapperSimu_t      PDO_ACDC_DataWrapperSimu_t      ;  /*!< @VADDR: GA_ACDC_MEAS_ID_SIMU        
                                                                            @CYCLEID:  FCT_ENV    
                                                                            @VNAME: ACDC_SimuData */
#endif

#endif /* #if ACDC_SIMU */

#endif /*ACDC_CFG_FRAME*/
#endif /* #ifdef __PDO__ */


/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}
