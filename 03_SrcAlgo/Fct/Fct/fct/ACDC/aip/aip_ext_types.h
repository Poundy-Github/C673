/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 AIP (ACDC Input Processing)

PACKAGENAME:               aip_ext_types.h

DESCRIPTION:               Typdefs of the AIP subcomonent, which shall be usable in the complete ACDC component.


AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:15:07CEST $

VERSION:                   $Revision: 1.7 $
**************************************************************************** */

#ifndef AIP_TYPES_H_INCLUDED
#define AIP_TYPES_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "aip_par.h"

#ifdef __cplusplus
extern "C" {
#endif

#if(ACDC_CFG_AIP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup aip
@{ */

#define USE_AIP_OBJ_STACK            SWITCH_OFF
#define USE_AIP_GLOB_STACK           SWITCH_OFF

#define USE_AIP_OBJ_INTER            SWITCH_OFF
#define USE_AIP_GLOB_INTER           SWITCH_OFF

#define USE_AIP_OBJ_INTERMEAS        SWITCH_OFF
#define USE_AIP_GLOB_INTERMEAS       SWITCH_OFF

#define USE_AIP_OBJ_INTRAMEAS        SWITCH_OFF
#define USE_AIP_GLOB_INTRAMEAS       SWITCH_ON

#define USE_AIP_OBJ_INTRA            SWITCH_ON
#define USE_AIP_GLOB_INTRA           SWITCH_ON

#define USE_AIP_OBJ_SIMU             SWITCH_ON
#define USE_AIP_GLOB_SIMU            SWITCH_OFF



  /************************************************************************/
  /* AIP Stack types                                                      */
  /************************************************************************/
  /* AIP object data */
#if (USE_AIP_OBJ_STACK)
  typedef struct  AIP_ObjStack_t  
  {

  }AIP_ObjStack_t;
#endif /* USE_AIP_OBJ_STACK */

  /* AIP global data */
#if (USE_AIP_GLOB_STACK)
  typedef struct  AIP_GlobDataStack_t  
  {
  }AIP_GlobDataStack_t;
#endif /* USE_AIP_GLOB_STACK */

  /************************************************************************/
  /* AIP Inter types                                                      */
  /************************************************************************/
  /* AIP object data */
#if (USE_AIP_OBJ_INTER)
  typedef struct  AIP_ObjInter_t  
  {

  }AIP_ObjInter_t;
#endif /* USE_AIP_OBJ_INTER */

  /* AIP global data */
#if (USE_AIP_GLOB_INTER)
  typedef struct  AIP_GlobDataInter_t  
  {

  }AIP_GlobDataInter_t;
#endif /* USE_AIP_GLOB_INTER */

  /************************************************************************/
  /* AIP InterMeas types                                                  */
  /************************************************************************/
  /* AIP object data */
#if (USE_AIP_OBJ_INTERMEAS)
  typedef struct  AIP_ObjInterMeas_t  
  {

  }AIP_ObjInterMeas_t;
#endif /* USE_AIP_OBJ_INTERMEAS */

  /* AIP global data */
#if (USE_AIP_GLOB_INTERMEAS)
  typedef struct  AIP_GlobDataInterMeas_t  
  {

  }AIP_GlobDataInterMeas_t;
#endif /* USE_AIP_GLOB_INTERMEAS */



  /************************************************************************/
  /* AIP IntraMeas types                                                  */
  /************************************************************************/

  /* AIP object data */
#if (USE_AIP_OBJ_INTRAMEAS)
  typedef struct  AIP_ObjIntraMeas_t  
  {

  }AIP_ObjIntraMeas_t;
#endif /* USE_AIP_OBJ_INTRAMEAS */

  /* AIP global data */
#if (USE_AIP_GLOB_INTRAMEAS)
  typedef struct  AIP_GlobDataIntraMeas_t  
  {
    ACDCDebugObj_t DebugRelObj;
  }AIP_GlobDataIntraMeas_t;
#endif /* USE_AIP_GLOB_INTRAMEAS */



  /************************************************************************/
  /* AIP Intra types                                                      */
  /************************************************************************/
  /* AIP object data */
#if (USE_AIP_OBJ_INTRA)
  typedef struct  AIP_ObjIntra_t  
  {
    ACDCObject_t ObjDesc;
  }AIP_ObjIntra_t;
#endif /* USE_AIP_OBJ_INTRA */

  /* AIP global data */
#if (USE_AIP_GLOB_INTRA)
  typedef struct  AIP_GlobDataIntra_t  
  {
    ACDCEgoData_t sEgoData;
    GDBTrafoMatrix2D_t AIP_TrafoMat2DForward;   
    GDBTrafoMatrix2D_t AIP_TrafoMat2DBackward;  
  }AIP_GlobDataIntra_t;
#endif /* USE_AIP_GLOB_INTRA */


#ifdef ACDC_SIMU
  /************************************************************************/
  /* AIP Simu types                                                       */
  /************************************************************************/
  /* AIP object data */
#if (USE_AIP_OBJ_SIMU)
  typedef struct  AIP_ObjSimu_t  
  {
    ACDCObjectSimu_t ObjDesc;
  }AIP_ObjSimu_t;
#endif /* USE_AIP_OBJ_SIMU */

  /* AIP global data */
#if (USE_AIP_GLOB_SIMU)
  typedef struct  AIP_GlobDataSimu_t  
  {

  }AIP_GlobDataSimu_t;
#endif /* USE_AIP_GLOB_SIMU */
#endif /* ACDC_SIMU */

/// @}
#else /* (ACDC_CFG_AIP) */

#define USE_AIP_OBJ_STACK            SWITCH_OFF
#define USE_AIP_GLOB_STACK           SWITCH_OFF

#define USE_AIP_OBJ_INTER            SWITCH_OFF
#define USE_AIP_GLOB_INTER           SWITCH_OFF

#define USE_AIP_OBJ_INTERMEAS        SWITCH_OFF
#define USE_AIP_GLOB_INTERMEAS       SWITCH_OFF

#define USE_AIP_OBJ_INTRAMEAS        SWITCH_OFF
#define USE_AIP_GLOB_INTRAMEAS       SWITCH_OFF

#define USE_AIP_OBJ_INTRA            SWITCH_OFF
#define USE_AIP_GLOB_INTRA           SWITCH_OFF

#define USE_AIP_OBJ_SIMU             SWITCH_OFF
#define USE_AIP_GLOB_SIMU            SWITCH_OFF

#endif/* (ACDC_CFG_AIP) */

#ifdef __cplusplus
};
#endif

/* End of conditional inclusion */
#endif  /*!< AIP_TYPES_H_INCLUDED */


