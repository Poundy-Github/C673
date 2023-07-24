/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 CD Collision Detection (CG situation analysis)

PACKAGENAME:               cd_ext.h

DESCRIPTION:               External Header of the Colision Detection component

AUTHOR:                    $Author: uidn4751 $

CREATION DATE:             $Date: 2019/06/03 16:41:22CEST $

VERSION:                   $Revision: 1.12 $

LEGACY VERSION:            Revision: 1.35

**************************************************************************** */

#ifndef CD_EXT_INCLUDED
#define CD_EXT_INCLUDED

#include "acdc_types.h"

#if (ACDC_CFG_CD)
/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
\addtogroup cd

\{ */

/*****************************************************************************
  FUNCTION PROTOTYPES
*****************************************************************************/
extern void CDInit( void );
extern void CDProcess( void );

extern void CDMergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void CDDeleteObject (ObjNumber_t iObjectToDelete);
extern void CDMergeDeleteObjectsSameFCTID(ObjNumber_t const ObjNr);

#endif /*(ACDC_CFG_CD)*/

/** \} */
#endif /* CD_EXT_INCLUDED */


