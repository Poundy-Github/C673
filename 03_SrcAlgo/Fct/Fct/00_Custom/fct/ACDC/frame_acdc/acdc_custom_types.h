/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC (Advanced collision detection and classification)

PACKAGENAME:               acdc_custom_types.h

DESCRIPTION:               Custom Types for ACDC (Advanced collision detection and classification)

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:55:24CEST $

VERSION:                   $Revision: 1.18 $

  **************************************************************************** */

#ifndef ACDC_CUSTOM_TYPES_H_INCLUDED
#define ACDC_CUSTOM_TYPES_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "acdc_ver.h"

#if(ACDC_CFG_FRAME)

/************************************************************************/
/* MACROS                                                               */
/************************************************************************/

#ifndef OBJ_INDEX_NO_OBJECT
//TODO Clarify whether this is needed in camera 
#define OBJ_INDEX_NO_OBJECT     ((ObjNumber_t)-1)
#endif

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup     frame_custom_types Custom Types
@ingroup      frame_types
@brief        Contains all customer specific type definitions. \n\n
@{
*/
/*generate Structure for general custom types*/

/*!
@defgroup custom_type_framework Custom Memory
@ingroup frame_custom_types

@brief    Contains the framework of the memory structure.  \n\n
@description

@{*/

/*!@{ 
@brief Activate this switch if you want to place a variable in the corresponding struct.*/
#define USE_ACDC_CUSTOBJ_STACK       SWITCH_OFF
#define USE_ACDC_CUSTGLOB_STACK      SWITCH_OFF

#define USE_ACDC_CUSTOBJ_INTER       SWITCH_OFF
#define USE_ACDC_CUSTGLOB_INTER      SWITCH_OFF

#define USE_ACDC_CUSTOBJ_INTERMEAS   SWITCH_OFF
#define USE_ACDC_CUSTGLOB_INTERMEAS  SWITCH_OFF

#define USE_ACDC_CUSTOBJ_INTRAMEAS   SWITCH_OFF
#define USE_ACDC_CUSTGLOB_INTRAMEAS  SWITCH_OFF

#define USE_ACDC_CUSTOBJ_INTRA       SWITCH_OFF
#define USE_ACDC_CUSTGLOB_INTRA      SWITCH_OFF

#define USE_ACDC_CUSTOBJ_SIMU        SWITCH_OFF
#define USE_ACDC_CUSTGLOB_SIMU       SWITCH_OFF
/*!@} */

/************************************************************************/
/* ACDC Stack custom types                                              */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_STACK)
typedef struct  ACDC_CustObjDataStack_t  
{
}ACDC_ObjDataCustStack_t;
#endif /* USE_ACDC_CUSTOBJ_STACK */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_STACK)
typedef struct  ACDC_CustGlobDataStack_t  
{

}ACDC_GlobDataCustStack_t;
#endif /* USE_ACDC_CUSTGLOB_STACK */

/************************************************************************/
/* ACDC Inter custom types                                              */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_INTER)
typedef struct  ACDC_CustObjDataInter_t  
{
}ACDC_ObjDataCustInter_t;
#endif /* USE_ACDC_CUSTOBJ_INTER */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_INTER)
typedef struct  ACDC_CustGlobDataInter_t  
{

}ACDC_GlobDataCustInter_t;
#endif /* USE_ACDC_CUSTGLOB_INTER */


/************************************************************************/
/* ACDC InterMeas custom types                                          */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_INTERMEAS)
typedef struct  ACDC_CustObjDataInterMeas_t  
{
}ACDC_ObjDataCustInterMeas_t;
#endif /* USE_ACDC_CUSTOBJ_INTERMEAS */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_INTERMEAS)
typedef struct  ACDC_CustGlobDataInterMeas_t  
{

}ACDC_GlobDataCustInterMeas_t;
#endif /* USE_ACDC_CUSTGLOB_INTERMEAS */



/************************************************************************/
/* ACDC IntraMeas custom types                                          */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_INTRAMEAS)
typedef struct  ACDC_CustObjDataIntraMeas_t  
{

}ACDC_ObjDataCustIntraMeas_t;
#endif /* USE_ACDC_CUSTOBJ_INTRAMEAS */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_INTRAMEAS)
typedef struct  ACDC_CustGlobDataIntraMeas_t  
{

}ACDC_GlobDataCustIntraMeas_t;
#endif /* USE_ACDC_CUSTGLOB_INTRAMEAS */



/************************************************************************/
/* ACDC Intra custom types                                              */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_INTRA)
typedef struct  ACDC_CustObjDataIntra_t  
{

}ACDC_ObjDataCustIntra_t;
#endif /* USE_ACDC_CUSTOBJ_INTRA */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_INTRA)
typedef struct  ACDC_CustGlobDataIntra_t  
{

}ACDC_GlobDataCustIntra_t;
#endif /* USE_ACDC_CUSTGLOB_INTRA */


#ifdef ACDC_SIMU
/************************************************************************/
/* ACDC Simu custom types                                               */
/************************************************************************/
/* ACDC object object data */
#if (USE_ACDC_CUSTOBJ_SIMU)
typedef struct  ACDC_CustObjDataSimu_t  
{

}ACDC_ObjDataCustSimu_t;
#endif /* USE_ACDC_CUSTOBJ_SIMU */

/* ACDC global object data */
#if (USE_ACDC_CUSTGLOB_SIMU)
typedef struct  ACDC_CustGlobDataSimu_t  
{

}ACDC_GlobDataCustSimu_t;
#endif /* USE_ACDC_CUSTGLOB_SIMU */
#endif /* ACDC_SIMU */

/*!@} */
/*!@} */

#endif /* ACDC_CFG_FRAME */

#endif /* ACDC_CUSTOM_TYPES_H_INCLUDED */ 

