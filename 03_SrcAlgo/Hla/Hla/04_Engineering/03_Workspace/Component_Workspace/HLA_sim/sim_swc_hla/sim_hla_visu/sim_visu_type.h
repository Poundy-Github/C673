/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  COMPONENT:              HLA

  MODULNAME:              sim_visu_type.h

  DESCRIPTION:            Type definitions across all visu modules

  CPU:                    Independent

  CREATION DATE:          2015-07-27

  VERSION:                $Revision: 1.3 $

  ---*/ /*---

**************************************************************************** */
#ifndef SIM_VISU_TYPE_H
#define SIM_VISU_TYPE_H

#include "hla_defs.h"

#define VISU_SIL      0
#define VISU_ECU      1
#define VISU_EVM      2
#define VISU_ENET     3
#define VISU_CAN      4
#define VISU_MAX      4
#define VISU_NONE     5

/* Offset for draw rect */
#define DXY2 +0.625f

/* defines for activeImage */
#define ACTIVEIMAGE_RAW_ODD   0
#define ACTIVEIMAGE_CIPP_ODD  1
#define ACTIVEIMAGE_CIPP_EVEN 2
#define ACTIVEIMAGE_NONE      3


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* generic ROI data */
typedef struct
{
  int X1;
  int Y1;
  int X2;
  int Y2;
  int Yu;
  int Yvu;
  int Width;
  int Height;
}RoiData;

/* mouse click track locking */
typedef struct
{
  int oldpTLBTraceTime;
  int oldpTLBxcenter;
  int oldpTLBycenter;
} LockedTrackListItem;

typedef std::vector<LockedTrackListItem> LockedTrackList;

/* mouse click object locking */
typedef struct
{
  int pObjectTrackId;
  int oldpObjectTraceTime;
  int oldpObjectxcenter;
  int oldpObjectycenter;
} LockedObjectListItem;

typedef std::vector<LockedObjectListItem> LockedObjectList;

/* general locking */
typedef struct
{
  int oldClickLeftCount;
  int oldClickMiddleCount;
  LockedTrackList   trackList;
  LockedObjectList  objectList;
} SimuLockedObjects;

#endif /* SIM_VISU_TYPE_H */
