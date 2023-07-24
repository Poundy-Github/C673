/*! \file **********************************************************************

  COMPANY:                Continental AG, BU ADAS, A.D.C. GmbH

  PROJECT:                MFC400

  CPU:                    TI EVE

  COMPONENT:              HLA

  MODULNAME:              hla_eve.c

  DESCRIPTION:            Interface hla EVE functions

  AUTHOR:                 Matthias Mutschler

  CREATION DATE:          2013-06-28

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hla_eve.c  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:52CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:45CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:06:05CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/ti_eve_arp32/src/project.pj
  CHANGES:                Revision 1.6 2014/03/12 18:07:14CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Added LRF on EVE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 12, 2014 6:07:14 PM CET]
  CHANGES:                Change Package : 198642:8 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.5 2013/10/29 18:21:58CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Integration of new segmentation (EVE part)
  CHANGES:                --- Added comments ---  uidv7867 [Oct 29, 2013 6:21:58 PM CET]
  CHANGES:                Change Package : 201787:1 http://mks-psad:7002/im/viewissue?selection=201787
  CHANGES:                Revision 1.4 2013/10/16 14:59:21CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated eve code for support for lrf
  CHANGES:                --- Added comments ---  uidv7867 [Oct 16, 2013 2:59:22 PM CEST]
  CHANGES:                Change Package : 198642:2 http://mks-psad:7002/im/viewissue?selection=198642
  CHANGES:                Revision 1.2 2013/08/05 20:41:03CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed EVE/DSP caching issues
  CHANGES:                Added time meas struct for EVE
  CHANGES:                --- Added comments ---  uidv7867 [Aug 5, 2013 8:41:03 PM CEST]
  CHANGES:                Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.1 2013/07/26 17:12:48CEST Mutschler, Matthias (uidv7867) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/ti_eve_arp32/src/project.pj
  CHANGES:
**************************************************************************** */

#include <string.h>
#include "hla_eve_ext.h"
#include "hla_eve.h"
#include "hla_eve_seg_main.h"
#include "hla_eve_lrf_main.h"

/*---------------------------------------------------*/
/*  TYPEDEFS                                         */
/*---------------------------------------------------*/

typedef union
{
  /* used during segmentation */
  WbufSeg_t seg;
  /* used during lrf classification */
  WbufLrf_t lrf;
} HLAWbuf_t;

typedef union
{
  /* used during segmentation */
  IbufLSeg_t seg;
  /* used during lrf classification */
  IbufLLrf_t lrf;
} HLAIbufL_t;

typedef union
{
  /* used during segmentation */
  IbufHSeg_t seg;
  /* used during lrf classification */
  IbufHLrf_t lrf;
} HLAIbufH_t;

/*---------------------------------------------------*/
/*  GLOBAL VARIABLES                                 */
/*---------------------------------------------------*/
#pragma DATA_ALIGN (HLAWbuf, 32);
#pragma DATA_SECTION  (HLAWbuf, "ALGO_SCRATCHBUFF_WMEM")
HLAWbuf_t HLAWbuf;

/* There is no need to define same variable on IBUFLB since we memory alias view */
#pragma DATA_ALIGN (HLAIbufL, 32);
#pragma DATA_SECTION  (HLAIbufL, "ALGO_SCRATCHBUFF_IMEM_LA")
HLAIbufL_t HLAIbufL;

/* There is no need to define same variable on IBUFHB since we memory alias view */
#pragma DATA_ALIGN (HLAIbufH, 32);
#pragma DATA_SECTION  (HLAIbufH, "ALGO_SCRATCHBUFF_IMEM_HA")
HLAIbufH_t HLAIbufH;


/*---------------------------------------------------*/
/*  GLOBAL FUNCTION DEFINITIONS                      */
/*---------------------------------------------------*/

#pragma FUNC_EXT_CALLED(HLA_Eve_Exec)  /* this pragma prevents removal of below functions by optimizer if option -pm is used */
sint32 HLA_Eve_Exec(const AS_t_EVEContainer *pEveContainer)
{
  uint64 timeStart;
  HLAEveTimeMeas_t HLAEveTimeMeas;
  AS_t_EVEContainer HLAEveContainer;
  HLAEveSegParams_t HLAEveContainerParams;

   /* Enable time measurements */
   _tsc_start();
   /* Reset internal time meas struct */
   memset(&HLAEveTimeMeas, 0x0, sizeof(HLAEveTimeMeas));
   HLAEveTimeMeasStart(&timeStart);

  /* Init return value with ok */
  sint32 retVal = HLA_EVE_RETURN_OK;

  /* Check whether interface between DSP and EVE is matching */
  if (!pEveContainer)
  {
    retVal = HLA_EVE_RETURN_ERR_NULL_POINTER;
  }

  if (retVal == HLA_EVE_RETURN_OK)
  {
    /* copy eve container to local RAM (DMEM) */
    memcpy(&HLAEveContainerParams, pEveContainer->eveParams.parBuf.p_Buff, sizeof(HLAEveContainerParams));
    memcpy(&HLAEveContainer, pEveContainer, sizeof(HLAEveContainer));
    HLAEveContainer.eveParams.parBuf.p_Buff = &HLAEveContainerParams;

    /* Check whether interface between DSP and EVE is matching */
    if (HLAEveContainer.u_VersionNumber != (AS_t_IfVersionNum) HLA_EVE_INTERFACE_VERSION_NUMBER)
    {
      retVal = HLA_EVE_RETURN_ERR_VERSION_MISMATCH;
    }
  }

  if (retVal == HLA_EVE_RETURN_OK)
  {
    /* Check time meas buffer size is large enough */
    if (   (HLAEveContainer.eveParams.dstBuf[0].u_BuffLength < sizeof(HLAEveTimeMeas))
        || (!pEveContainer->eveParams.dstBuf[0].p_Buff)
       )
    {
      retVal = HLA_EVE_RETURN_ERR_TIME_MEAS;
    }
  }

  /* Call corresponding local EVE function */
  if (retVal == HLA_EVE_RETURN_OK)
  {
    switch(HLAEveContainer.eveParams.u_LocalFuncID)
    {
    case HLA_EVE_FUNC_ID_SEGMENTATION:
      if (HLAEveContainer.eveParams.parBuf.u_BuffLength == sizeof(HLAEveSegParams_t))
      {
        uint16 retValSeg;
        /* Call segmentation*/
        retValSeg = HLAEveSegMain((HLAEveSegParams_t*) HLAEveContainer.eveParams.parBuf.p_Buff,
                                   HLAEveContainer.eveParams.srcBuf[0].p_Buff,
                                   HLAEveContainer.eveParams.srcBuf[0].u_BuffLength,
                                   HLAEveContainer.eveParams.dstBuf[1].p_Buff,
                                   HLAEveContainer.eveParams.dstBuf[1].u_BuffLength,
                                   HLAEveContainer.eveParams.dstBuf[2].p_Buff,
                                   HLAEveContainer.eveParams.dstBuf[2].u_BuffLength,
                                   &HLAWbuf.seg,
                                   &HLAIbufL.seg,
                                   &HLAIbufH.seg,
                                   &HLAEveTimeMeas
                                  );
        if (retValSeg != HLA_EVE_SEG_RETURN_OK)
        {
          /* include segmentation error returns into global return value */
          retVal = (retValSeg << 16u);
          retVal |= HLA_EVE_RETURN_ERR_SEGMENTATION;
        }
      }
      else
      {
        retVal = HLA_EVE_RETURN_ERR_SEGMENTATION;
      }
      break;
      case HLA_EVE_FUNC_ID_LRF:
        if (HLAEveContainer.eveParams.parBuf.u_BuffLength == sizeof(HLAEveLrfParams_t))
        {
          uint16 retValLrf;
          /* Call LRF classifier */
          retValLrf = HLAEveLrfMain((HLAEveLrfParams_t*) HLAEveContainer.eveParams.parBuf.p_Buff,
                                     HLAEveContainer.eveParams.srcBuf[0].p_Buff,
                                     HLAEveContainer.eveParams.srcBuf[0].u_BuffLength,
                                     HLAEveContainer.eveParams.srcBuf[1].p_Buff,
                                     HLAEveContainer.eveParams.srcBuf[1].u_BuffLength,
                                     HLAEveContainer.eveParams.srcBuf[2].p_Buff,
                                     HLAEveContainer.eveParams.srcBuf[2].u_BuffLength,
                                     HLAEveContainer.eveParams.dstBuf[1].p_Buff,
                                     HLAEveContainer.eveParams.dstBuf[1].u_BuffLength,
                                     HLAEveContainer.eveParams.dstBuf[2].p_Buff,
                                     HLAEveContainer.eveParams.dstBuf[2].u_BuffLength,
                                     &HLAWbuf.lrf,
                                     &HLAIbufL.lrf,
                                     &HLAIbufH.lrf,
                                     &HLAEveTimeMeas
                                    );
          if (retValLrf != HLA_EVE_LRF_RETURN_OK)
          {
            /* include lrf error returns into global return value */
            retVal = (retValLrf << 16u);
            retVal |= HLA_EVE_RETURN_ERR_LRF;
          }
        }
        else
        {
          retVal = HLA_EVE_RETURN_ERR_LRF;
        }
        break;
      default:
        /* There was no function with this ID -> return error */
        retVal = HLA_EVE_RETURN_ERR_ILLEGAL_FUNC_ID;
        break;
    }
  }

  HLAEveTimeMeas.dTimeEve_us = HLAEveTimeMeasEnd(timeStart);

  /* Save time measurements for DSP */
  memcpy(HLAEveContainer.eveParams.dstBuf[0].p_Buff, &HLAEveTimeMeas, sizeof(HLAEveTimeMeas));
  return retVal;
}

