/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTSen

PACKAGENAME:               $Source: fct_sen_pdo_tags.c $

DESCRIPTION:               This module contains FCTSen PDO tags 

AUTHOR:                    $Author: Ramesh, Sangeetha (uidn1528) $

CREATION DATE:             $Date: 2019/04/15 11:13:03CEST $

VERSION:                   $Revision: 1.3 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "fct_config.h"
#include "fct_types.h"
#include "fct_sen_ext.h"


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         fctsen_pdo PDO tags for FCTSen component
@ingroup          frame_sen
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
#if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ERROR_OUTPUT_SEN))
typedef SLATEErrorOutProPort_t PDO_SLATEErrorOutProPort_t;  /*!< @VADDR:FCT_MEAS_ID_SLATE_ERRORDATA      
                                                                 @CYCLEID: FCT_ENV     
                                                                 @VNAME:SLATEErrorOut   */
#endif /* #if ((FCT_CFG_ADAPTIVE_CRUISE_CONTROL) && (FCT_CFG_ERROR_OUTPUT_SEN)) */

typedef FCTSenFrame_t          PDO_FCTSenFrame_t         ;  /*!< @VADDR:FCT_MEAS_ID_SEN_FRAME_DATA       
                                                                 @CYCLEID: FCT_ENV     
                                                                 @VNAME:FCTSenFrameData */

#if FCT_CFG_USE_ALGOCOMPSTATE
typedef AlgoCompState_t        PDO_AlgoCompState_t       ;  /*!< @vaddr:FCT_MEAS_ID_SEN_COMP_STATE       
                                                                 @CYCLEID:FCT_ENV      
                                                                 @VNAME: FCTSenCompState  */
#endif                                                                                                          
#if FCT_CFG_USE_BUS_DEBUG                                                                                       
typedef BusDebugData_t         PDO_BusDebugData_t        ;  /*!< @vaddr: FCT_MEAS_ID_SEN_BUS_DEBUG       
                                                                 @CYCLEID:FCT_ENV      
                                                                 @VNAME:  FCTSenBusDebugData   */
#endif
#if FCT_CFG_BSW_ALGO_PARAMS
typedef BSW_s_AlgoParameters_t PDO_BSW_s_AlgoParameters_t;  /*!< @vaddr: 0x20900100                      
                                                                 @CYCLEID:FCT_ENV      
                                                                 @VNAME:FCTSenBswAlgoParameters */
#endif

typedef FCTSen_SyncRef_t       PDO_FCTSen_SyncRef_t      ;  /*!< @vaddr:FCT_MEAS_ID_SEN_INPUT_SIGHEADERS 
                                                                 @CYCLEID:FCT_ENV      
                                                                 @VNAME:FCTSenSyncRef */
#if (FCT_CFG_RUNTIME_MEAS)                                                                                                     
typedef FCT_t_RuntimeInfo      PDO_FCT_t_RuntimeInfo     ;  /*!< @VADDR:FCT_MEAS_ID_RUNTIME_DEBUG        
                                                                 @CYCLEID: FCT_ENV     
                                                                 @VNAME:FCTSenRuntimeInfo */
#endif



#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}
