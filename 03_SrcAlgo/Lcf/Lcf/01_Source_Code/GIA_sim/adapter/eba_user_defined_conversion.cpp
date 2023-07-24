#include "stdafx.h"

uint8 convert_uiEbaObjQuality(uint8 uiEbaMovingObjQuality, uint8 uiEbaStationaryObjQuality)
{
  if(uiEbaMovingObjQuality >= uiEbaStationaryObjQuality)
  {
    return uiEbaMovingObjQuality;
  }
  else
  {
    return uiEbaStationaryObjQuality;
  }
}


uint8 convert_uiEbaHypCat(uint8 uiDynamicProperty, uint8 uiClassificationType)
{
  /* Set Function Cat according to Object class */
  uint8 uiEbaHypCat = 0;
  switch(uiClassificationType)
  {
  case 1/*EM_GEN_OBJECT_CLASS_CAR*/:
  case 2/*EM_GEN_OBJECT_CLASS_TRUCK*/:
  case 4/*EM_GEN_OBJECT_CLASS_MOTORCYCLE*/:
  case 5/*EM_GEN_OBJECT_CLASS_BICYCLE*/:
  case 7/*EM_GEN_OBJECT_CLASS_UNCLASSIFIED*/:
    {
      uiEbaHypCat = 2/*FPS_EBA_HYP_CAT_VCL*/;
      if (uiDynamicProperty == 1/*EM_GEN_OBJECT_DYN_PROPERTY_STATIONARY*/)
      {
        uiEbaHypCat |= 16/*FPS_EBA_HYP_CAT_STAT*/;
      }
      if (uiDynamicProperty == 2/*EM_GEN_OBJECT_DYN_PROPERTY_ONCOMING*/)
      {
        uiEbaHypCat |= 8/*FPS_EBA_HYP_CAT_ONC*/;
      }
      if ( (uiDynamicProperty == 3/*EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_LEFT*/) ||
           (uiDynamicProperty == 4/*EM_GEN_OBJECT_DYN_PROPERTY_CROSSING_RIGHT*/) )
      {
        uiEbaHypCat |= 4/*FPS_EBA_HYP_CAT_XING*/;
      }
    }
    break;
  case 3/*EM_GEN_OBJECT_CLASS_PEDESTRIAN*/:
    {
      uiEbaHypCat = 1/*FPS_EBA_HYP_CAT_PED*/;
    }
    break;
  case 0/*EM_GEN_OBJECT_CLASS_POINT*/:
  case 6/*EM_GEN_OBJECT_CLASS_WIDE*/:
  case 8/*EM_GEN_OBJECT_CLASS_MAX_DIFF_TYPES*/:
  default:
    {
      uiEbaHypCat = 0;
    }
    break;
  } 
  return uiEbaHypCat;
}