/*! \file ********************************************************************

  COMPANY:                Continental, BC DAS, A.D.C. GmbH

  PROJECT:                MFC4xx

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_dimming.c

  DESCRIPTION:            Functions for dimming feature.

  AUTHOR:                 Alexander Manz

  CREATION DATE:          22.07.2013

  VERSION:                $Revision: 1.1 $ 

  CHANGES:                

  ---*/ /*---
  CHANGE:  
*****************************************************************************/


/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include "hlaf_dimming.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/
#define X_DELTA             48    /* positive and negative offset in x-direction */
#define Y_DELTA             27    /* positive and negative offset in y-direction */
#define HLA_DIMMING_MIN_TTB 1500u /* min time-to-border for a bright object to react to */

/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/


/*****************************************************************************
  FUNCTION 
*****************************************************************************/


/* ***************************************************************************
  Functionname:     HLA_FillDimmingAreas
  Description:      Loops through available tracks and checks if the track is
                    a very bright area which might blind the driver.

  @param[in]        HLA_t_ObjectList*       pObjectList
                    HLAF_t_RequiredInputs*  ps_In,
                    HLAF_LightDimming_t*    pDimming

  @return           -
  @pre              -
  @post             -
  @author           Alexander Manz
*****************************************************************************/
void HLAF_FillDimmingAreas( const HLA_t_ObjectList*       pObjectList,
                            const HLAF_t_RequiredInputs*  pIn,
                                  HLAF_LightDimming_t*    pDimming
                          )
{

  /* loop through all available objects */
  uint32  iObj;
  uint8   iBorder;
  boolean bAreaSelected = b_FALSE;
  float32 objectAngle = 0.0f;
  const HLA_t_Object* pObj;

  for(iBorder = 0; iBorder < RTE_HLA_NUM_DIMM_AREAS; iBorder++)
  {
    pDimming->DimmingArea[iBorder] = RTE_HLAF_DIMM_LEVEL_NO_REDUCT;
  }

  for(iObj = 0; iObj < pObjectList->ui32_NumObjects; iObj++)
  {
    pObj = &pObjectList->as_Object[iObj];

    if(   (pObj->s_Status.isBrightObject == 1)
       && (pObj->ui16_ttb_ms > HLA_DIMMING_MIN_TTB)
      )
    {
      /* calculate horizontal angle to object */
      objectAngle = atanf( (float32)(pIn->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_X - pObj->si16_xcenter) / pIn->s_Par.ps_CameraParameter->s_FocalLength.f32_x);

      iBorder = 0;
      /* decide in which dimming area the object is */
      while(   (iBorder < RTE_HLA_NUM_DIMM_AREAS_BORDERS)
            && (bAreaSelected == b_FALSE)
           )
      {
        /* if angle is smaller then right border of dimming area */
        if(objectAngle < pIn->s_Par.s_HlafPar.Dimming.AreaRightBorderArray[iBorder])
        {
          /* object is in this area */
          bAreaSelected = b_TRUE;

          /* if there is more than one object in the dimming area increase dimming effort */
          if(pDimming->DimmingArea[iBorder] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
          {
            /* one object in this area */
            pDimming->DimmingArea[iBorder] = RTE_HLAF_DIMM_LEVEL_REDUCT_1;
          }
          else if(pDimming->DimmingArea[iBorder] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
          {
            /* two or more objects */
            pDimming->DimmingArea[iBorder] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
          }
          else
          {
            /* do nothing */
          }
        }
        iBorder++;
      }

      /* if area has not been assigned to a dimming area it is in the last one */
      /* index of last area is same as size of border array => usage of RTE_HLA_NUM_DIMM_AREAS_BORDERS */
      if(bAreaSelected != b_TRUE)
      {
        /* if there is more than one object in the dimming area increase dimming effort */
          if(pDimming->DimmingArea[RTE_HLA_NUM_DIMM_AREAS_BORDERS] == RTE_HLAF_DIMM_LEVEL_NO_REDUCT)
          {
            /* one object in this area */
            pDimming->DimmingArea[RTE_HLA_NUM_DIMM_AREAS_BORDERS] = RTE_HLAF_DIMM_LEVEL_REDUCT_1;
          }
          else if(pDimming->DimmingArea[RTE_HLA_NUM_DIMM_AREAS_BORDERS] == RTE_HLAF_DIMM_LEVEL_REDUCT_1)
          {
            /* two or more objects */
            pDimming->DimmingArea[RTE_HLA_NUM_DIMM_AREAS_BORDERS] = RTE_HLAF_DIMM_LEVEL_REDUCT_2;
          }
          else
          {
            /* do nothing */
          }
      }

      pDimming->eDimmingStatus = RTE_HLAF_DIMM_STATE_AVL;
      pDimming->nDimmingArea = RTE_HLA_NUM_DIMM_AREAS;
#if 0
      /* found a bright object */
      pDimming->eDimmingStatus = RTE_HLAF_DIMM_STATE_AVL;

      if (usedDims < 5)
      {
        pDimming->nDimmingArea = usedDims + 1;
        
        /* add corrected camera angles here */
        /*       center_of_track            */
        /*            __\______ _-y_delta   */
        /*           |   \     |            */
        /*           |    x------ycenter    */
        /*           |____|____|_+y_delta   */
        /*           |    |    |            */
        /*       -x_delta | +x_delta        */
        /*             xcenter              */
        /*                                  */
        pDimming->DimmingArea[usedDims].BndryLeft_Ang_Cam  = atanf( (float32)(pIn->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_X - (pObj->si16_xcenter - X_DELTA)) / pIn->s_Par.ps_CameraParameter->s_FocalLength.f32_y);
        pDimming->DimmingArea[usedDims].BndryLower_Ang_Cam = atanf( (float32)((pObj->si16_ycenter + Y_DELTA) - pIn->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_Y) / pIn->s_Par.ps_CameraParameter->s_FocalLength.f32_y);
        pDimming->DimmingArea[usedDims].BndryRight_Ang_Cam = atanf( (float32)(pIn->s_Sig.ps_ObjectList->s_ObjectFOE.ui16_X - (pObj->si16_xcenter + X_DELTA)) / pIn->s_Par.ps_CameraParameter->s_FocalLength.f32_y);
        pDimming->DimmingArea[usedDims].e_LightOutput = RTE_HLAF_LIGHTOUTPUT_MIN;
        usedDims++;
      }
#endif
    }
  }
}/* PRQA S 861 1 */
