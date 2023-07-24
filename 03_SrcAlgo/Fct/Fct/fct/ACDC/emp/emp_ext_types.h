/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 EMP - Environment Model Prediction

PACKAGENAME:               emp_ext_types.h

DESCRIPTION:               Typdefs of the EMP subcomonent, which shall be usable in the complete ACDC component.

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 15:28:52CEST $

VERSION:                   $Revision: 1.6 $
**************************************************************************** */
#ifndef EMP_TYPES_INCLUDED
#define EMP_TYPES_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "emp_par.h"


#if(ACDC_CFG_EMP)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
\addtogroup emp
\{
*/


/***********************************************************************
      MACROS                                                           
************************************************************************/

#define USE_EMP_OBJ_STACK            SWITCH_OFF
#define USE_EMP_GLOB_STACK           SWITCH_OFF

#define USE_EMP_OBJ_INTER            SWITCH_OFF
#define USE_EMP_GLOB_INTER           SWITCH_OFF

#define USE_EMP_OBJ_INTERMEAS        SWITCH_OFF
#define USE_EMP_GLOB_INTERMEAS       SWITCH_OFF

#define USE_EMP_OBJ_INTRAMEAS        SWITCH_OFF
#define USE_EMP_GLOB_INTRAMEAS       SWITCH_OFF

#define USE_EMP_OBJ_INTRA            SWITCH_OFF
#define USE_EMP_GLOB_INTRA           SWITCH_OFF

#define USE_EMP_OBJ_SIMU             SWITCH_OFF
#define USE_EMP_GLOB_SIMU            SWITCH_OFF

/***********************************************************************
      TYPEDEFS                                                          
************************************************************************/
/*! @brief Data type to store the EMP Object Description*/
typedef struct EMPObjExDesc
{
  SFLVector2D_t  sCenter;      /*!< Position of the object center*/

  SFLVector2D_t  sVar;         /*!< Variance of the center position */

  ACDCGeometry_t sGeometry;    /*!< Geometry represented by width and length */

  float32        fOrientation; /*!< Orientation of the object. \unit [rad], \range ]-...,+...[ */
} EMPObjExDesc_t;


/************************************************************************/
/* EMP Stack types                                                      */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_STACK)
typedef struct  EMP_ObjStack_t  
{

}EMP_ObjStack_t;
#endif /* USE_EMP_OBJ_STACK */

/* EMP global data */
#if (USE_EMP_GLOB_STACK)
typedef struct  EMP_GlobDataStack_t  
{

}EMP_GlobDataStack_t;
#endif /* USE_EMP_GLOB_STACK */

/************************************************************************/
/* EMP Inter types                                                      */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_INTER)
typedef struct  EMP_ObjInter_t  
{

}EMP_ObjInter_t;
#endif /* USE_EMP_OBJ_INTER */

/* EMP global data */
#if (USE_EMP_GLOB_INTER)
typedef struct  EMP_GlobDataInter_t  
{

}EMP_GlobDataInter_t;
#endif /* USE_EMP_GLOB_INTER */


/************************************************************************/
/* EMP InterMeas types                                                  */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_INTERMEAS)
typedef struct  EMP_ObjInterMeas_t  
{

}EMP_ObjInterMeas_t;
#endif /* USE_EMP_OBJ_INTERMEAS */

/* EMP global data */
#if (USE_EMP_GLOB_INTERMEAS)
typedef struct  EMP_GlobDataInterMeas_t  
{

}EMP_GlobDataInterMeas_t;
#endif /* USE_EMP_GLOB_INTERMEAS */



/************************************************************************/
/* EMP IntraMeas types                                                  */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_INTRAMEAS)
typedef struct  EMP_ObjIntraMeas_t  
{

}EMP_ObjIntraMeas_t;
#endif /* USE_EMP_OBJ_INTRAMEAS */

/* EMP global data */
#if (USE_EMP_GLOB_INTRAMEAS)
typedef struct  EMP_GlobDataIntraMeas_t  
{

}EMP_GlobDataIntraMeas_t;
#endif /* USE_EMP_GLOB_INTRAMEAS */



/************************************************************************/
/* EMP Intra types                                                      */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_INTRA)
typedef struct  EMP_ObjIntra_t  
{

}EMP_ObjIntra_t;
#endif /* USE_EMP_OBJ_INTRA */

/* EMP global data */
#if (USE_EMP_GLOB_INTRA)
typedef struct  EMP_GlobDataIntra_t  
{

}EMP_GlobDataIntra_t;
#endif /* USE_EMP_GLOB_INTRA */


#ifdef ACDC_SIMU
/************************************************************************/
/* EMP Simu types                                                       */
/************************************************************************/
/* EMP object data */
#if (USE_EMP_OBJ_SIMU)
typedef struct  EMP_ObjSimu_t  
{

}EMP_ObjSimu_t;
#endif /* USE_EMP_OBJ_SIMU */

/* EMP global data */
#if (USE_EMP_GLOB_SIMU)
typedef struct  EMP_GlobDataSimu_t  
{

}EMP_GlobDataSimu_t;
#endif /* USE_EMP_GLOB_SIMU */
#endif /* ACDC_SIMU */

#else /* (ACDC_CFG_EMP) */

#define USE_EMP_OBJ_STACK            SWITCH_OFF
#define USE_EMP_GLOB_STACK           SWITCH_OFF

#define USE_EMP_OBJ_INTER            SWITCH_OFF
#define USE_EMP_GLOB_INTER           SWITCH_OFF

#define USE_EMP_OBJ_INTERMEAS        SWITCH_OFF
#define USE_EMP_GLOB_INTERMEAS       SWITCH_OFF

#define USE_EMP_OBJ_INTRAMEAS        SWITCH_OFF
#define USE_EMP_GLOB_INTRAMEAS       SWITCH_OFF

#define USE_EMP_OBJ_INTRA            SWITCH_OFF
#define USE_EMP_GLOB_INTRA           SWITCH_OFF

#define USE_EMP_OBJ_SIMU             SWITCH_OFF
#define USE_EMP_GLOB_SIMU            SWITCH_OFF

#endif /* (ACDC_CFG_EMP) */

#endif /* EMP_TYPES_INCLUDED */

///\}

