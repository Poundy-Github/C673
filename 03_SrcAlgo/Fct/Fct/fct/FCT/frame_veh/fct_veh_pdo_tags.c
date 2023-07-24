/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 FCTVeh

PACKAGENAME:               $Source: fct_veh_pdo_tags.c $

DESCRIPTION:               This module contains FCTVeh PDO tags 

AUTHOR:                    $Author: Ramesh, Sangeetha (uidn1528) $

CREATION DATE:             $Date: 2019/04/15 11:45:07CEST $

VERSION:                   $Revision: 1.2 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#ifdef __PDO__
#include "fct_config.h"
#include "fct_types.h"
#include "fct_veh_ext.h"


/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         fctveh_pdo PDO tags for fct vehicle cycle
@ingroup          frame_veh
@brief            This module contains all tags for the PDO scan.\n\n
@{
*/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/
typedef FCTVehFrame_t          PDO_FCTVehFrame_t                    ;  /*!< @VADDR:FCT_MEAS_ID_VEH_FRAME_DATA       
                                                                            @CYCLEID: FCT_VEH      
                                                                            @VNAME:FCTVehFrameData */
                                                                   
typedef FCTVeh_SyncRef_t       PDO_FCTVeh_SyncRef_t                 ;  /*!< @VADDR:FCT_MEAS_ID_VEH_INPUT_SIGHEADERS 
                                                                            @CYCLEID: FCT_VEH      
                                                                            @VNAME:FCTVeh_SyncRef */
                                                                   
#if FCT_CFG_USE_ALGOCOMPSTATE                                      
typedef AlgoCompState_t        PDO_AlgoCompState_t                  ;  /*!< @VADDR:FCT_MEAS_ID_VEH_COMP_STATE       
                                                                            @CYCLEID:FCT_VEH       
                                                                            @VNAME:FCTVehCompState*/
#endif
#if (FCT_VEH_CFG_FREEZE_CTRL_DATA)
#if (FCT_CFG_USE_BASECTRLDATA)
typedef BaseCtrlData_t         PDO_FCTVeh_FreezeBufferVehCtrlData   ;  /*!< @vaddr:FCT_MEAS_ID_VEH_BASE_CTRL_DATA   
                                                                            @cycleid:FCT_VEH       
                                                                            @vname:FCTVehBaseCtrlData  */
#else                                                                                                                                      
typedef FCTCtrlData_t          PDO_FCTVeh_FreezeBufferVehCtrlData   ;  /*!< @vaddr:FCT_MEAS_ID_VEH_BASE_CTRL_DATA   
                                                                            @cycleid:FCT_VEH       
                                                                            @vname:FCTVehBaseCtrlData  */
#endif /* FCT_CFG_USE_BASECTRLDATA */
#endif


#endif /* #ifdef __PDO__ */

/*! Dummy for the compiler.*/ /* PRQA S 3219,3450 1 */ /* Function definition is only needed to avoid empty translation unit */
static void DummyForCompiler (void) {return;}
