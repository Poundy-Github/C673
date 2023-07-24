/*! \file ****.***************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC400

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_matrix.c

  DESCRIPTION:            HLA matrix beam function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2012-11-05

  VERSION:                $Revision: 1.1 $
   
  ---*/ /*---
  CHANGE:                 $Log: hlaf_matrix.c  $
  CHANGE:                 Revision 1.1 2021/12/13 17:27:21CET Wang, David (Wangd3) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.0 2017/03/03 10:38:59CET Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.1 2014/04/17 16:05:40CEST Sorge, Sven (uidg3181) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/matrix/project.pj
  CHANGE:                 Revision 1.23 2014/03/25 18:38:57CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Member moved from hlaf_matrix.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_matrix.c in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/matrix/project.pj.
  CHANGE:                 Revision 1.22 2014/03/19 16:31:40CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace macros from glob_defs.h by the ones defined in cml_ext.h
  CHANGE:                 Fixed hlar input adapter for old recordings (headlamp type)
  CHANGE:                 Clean-up of no longer needed files in simulation
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 19, 2014 4:31:41 PM CET]
  CHANGE:                 Change Package : 225959:1 http://mks-psad:7002/im/viewissue?selection=225959
  CHANGE:                 Revision 1.21 2014/03/10 13:21:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed some new critical QAC warnings
  CHANGE:                 Moved suppressions from .hoc file to comment in source code
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 10, 2014 1:21:03 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.20 2014/03/04 16:52:23CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Fixed QAC warnings
  CHANGE:                 Coding style
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:23 PM CET]
  CHANGE:                 Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.19 2014/03/04 12:59:02CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Support for I390 RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 4, 2014 12:59:03 PM CET]
  CHANGE:                 Change Package : 207432:32 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.18 2013/12/13 16:45:06CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Service functions are now passed in one struct
  CHANGE:                 SDLfile definitions moved to separate file
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 13, 2013 4:45:06 PM CET]
  CHANGE:                 Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.17 2013/12/05 17:48:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Update to RTE I330
  CHANGE:                 --- Added comments ---  uidv7867 [Dec 5, 2013 5:48:00 PM CET]
  CHANGE:                 Change Package : 207432:13 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGE:                 Revision 1.16 2013/08/29 12:39:40CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Disabled almost all internal measfreezes temporary due 15K budget
  CHANGE:                 --- Added comments ---  uidv7867 [Aug 29, 2013 12:39:40 PM CEST]
  CHANGE:                 Change Package : 167173:32 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.15 2013/06/13 16:26:33CEST Brunn, Marcus (brunnm) 
  CHANGE:                 initial fog detection for I300
  CHANGE:                 --- Added comments ---  brunnm [Jun 13, 2013 4:26:33 PM CEST]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.14 2013/04/12 12:45:16CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Took more coding parameters into use
  CHANGE:                 --- Added comments ---  uidv7867 [Apr 12, 2013 12:45:16 PM CEST]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.13 2013/04/11 16:21:02CEST Mutschler, Matthias (uidv7867) 
  CHANGE:                 Implemented some coding parameters
  CHANGE:                 Tunnel is now global turn off reason
  CHANGE:                 Revision 1.12 2013/03/18 14:13:27CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to new RTE (not yet released)
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 18, 2013 2:13:28 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.11 2013/03/13 19:11:41CET Brunn, Marcus (brunnm) 
  CHANGE:                 HLAF: used Matrix.MaxNumGlarefreeArea from HLAF Parameter input
  CHANGE:                 --- Added comments ---  brunnm [Mar 13, 2013 7:11:42 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.10 2013/03/12 10:59:29CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 12, 2013 10:59:29 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.9 2013/03/11 18:02:04CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replace some types by RTE ones
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 6:02:04 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.8 2013/03/11 16:13:42CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Replaced no longer needed types by RTE ones
  CHANGE:                 - HLA_t_eSignalState
  CHANGE:                 - HLA_t_eLightStyle
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eCityState
  CHANGE:                 - HLA_t_eWeatherState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 11, 2013 4:13:42 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.7 2013/03/11 10:37:35CET Brunn, Marcus (brunnm) 
  CHANGE:                 initial HLAF matrix version with multiple Glare free areas (1-5 GFAs)
  CHANGE:                 --- Added comments ---  brunnm [Mar 11, 2013 10:37:36 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.6 2013/03/08 17:43:09CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Removed HeadlightState and taken RTE type into use
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 5:43:09 PM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.5 2013/03/08 10:31:00CET Mutschler, Matthias (uidv7867) 
  CHANGE:                 Updated to latest RTE
  CHANGE:                 --- Added comments ---  uidv7867 [Mar 8, 2013 10:31:01 AM CET]
  CHANGE:                 Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGE:                 Revision 1.4 2013/01/24 16:37:20CET Brunn, Marcus (brunnm) 
  CHANGE:                 Switched to rte like types for
  CHANGE:                 - HLA_t_eTunnel
  CHANGE:                 - HLA_t_eBrightnessState
  CHANGE:                 - HLA_t_eMotorwayState
  CHANGE:                 --- Added comments ---  brunnm [Jan 24, 2013 4:37:20 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.3 2012/12/10 10:36:17CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixed ObjLower_Ang_Cam
  CHANGE:                 --- Added comments ---  brunnm [Dec 10, 2012 10:36:17 AM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.2 2012/12/04 13:46:22CET Brunn, Marcus (brunnm) 
  CHANGE:                 fixes for initial matrix beam function
  CHANGE:                 --- Added comments ---  brunnm [Dec 4, 2012 1:46:22 PM CET]
  CHANGE:                 Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGE:                 Revision 1.1 2012/12/03 13:02:00CET Brunn, Marcus (brunnm) 
  CHANGE:                 Initial revision
  CHANGE:                 Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj
  CHANGE:                 
  CHANGE:                 
  CHANGE:
**************************************************************************** */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* J.Häfer: Redundant including of math.h is checked */
#include <math.h>
#include <string.h>
#include "hlaf_defs.h"
#include "hlaf_type.h"
#include "hlaf_matrix.h"
#include "hlaf_matrixgfa.h"
#include "hlaf_decision.h"



/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/


/*****************************************************************************
  VARIABLES 
*****************************************************************************/
static HLAFMatrixInput_t   halfMatrixInput;
HLA_GLOBAL_STATIC HLAFMatrixData_t  hlafMatrixData;



/*****************************************************************************
  FUNCTION 
*****************************************************************************/
static void HLAFMatrix_InitData(void);
static void HLAFMatrix_InitOutput(HLAFMatrixOut_t *pOut);
static void HLAFMatrix_InitObjectList(HLAObjectDataInt_t Obj[]);
static void HLAFMatrix_PrepareObjectList( const HLAF_t_RequiredInputs  *ps_In,
                                          HLAFMatrixData_t      *pData
                                        );
static void HLAFMatrix_SetOutput( /* input */
                                  const HLAFMatrixData_t *pData,
                                  /* output */
                                  HLAFMatrixOut_t  *pOutNext
                                );
static void HLAFMatrix_SetTurnOffReason( const HLAFData_t  *pFData,
                                         const HLAFMatrixData_t *pData,
                                         const RTE_HLA_ParameterAlgoCfg_t *pAlgoCfg,
                                         /* output */
                                         HLAFMatrixOut_t  *pOutNext
                                       );
static void HLAFMatrix_SetLowBeamDist( const HLAFData_t *pFData,
                                       const HLAFMatrixData_t *pData,
                                       const RTE_HLAF_HighBeamState HighBeamStateNext,
                                       const HLAFMatrixParameter_t *pMatrixPar,
                                       /* output */
                                       HLAF_t_Matrix *pMatrixNext
                                     );



/* init internal object list */
static void HLAFMatrix_InitObjectList(HLAObjectDataInt_t Obj[])
{
  uint8 i;

  memset(&Obj[0], 0, RTE_HLAR_OBJECT_LIST_LENGTH*sizeof(HLAObjectDataInt_t));
  
  for(i=0; i<RTE_HLAR_OBJECT_LIST_LENGTH; i++)
  {
    Obj[i].ObjID     = UI8_T_MAX;
    Obj[i].ObjIDPair = UI8_T_MAX;
    Obj[i].ObjNext   = UI8_T_MAX;
    Obj[i].TrackID   = UI8_T_MAX;
    Obj[i].TrackIDPair = UI8_T_MAX;
    Obj[i].GFA = UI8_T_MAX;
  }
}



/* prepare internal object list */
static void HLAFMatrix_PrepareObjectList( const HLAF_t_RequiredInputs  *ps_In,
                                          HLAFMatrixData_t      *pData
                                        )
{
  uint8 i;
  
  /* init internal object list */
  HLAFMatrix_InitObjectList(&pData->Object[0]);

  /* go through all detected vehicles */
  for(i=0; i<CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); i++)
  {
    uint8 j;
    uint8 IdPairLight = ps_In->s_Sig.ps_ObjectList->as_Object[i].ui8_IdPairLight;

    pData->Object[i].TrackID = ps_In->s_Sig.ps_ObjectList->as_Object[i].ui8_Id;
    pData->Object[i].TrackIDPair = ps_In->s_Sig.ps_ObjectList->as_Object[i].ui8_IdPairLight;

    pData->Object[i].ObjID = i;
   
    /* pair available ? */
    if(IdPairLight < UI8_T_MAX)
    {
      /* set object id of the pair light */
      for(j=0; j<CML_Min(ps_In->s_Sig.ps_ObjectList->ui32_NumVehicles, RTE_HLAR_OBJECT_LIST_LENGTH); j++)
      {
        if(IdPairLight == ps_In->s_Sig.ps_ObjectList->as_Object[j].ui8_Id)
        {
          pData->Object[i].ObjIDPair = j;
        }
      }
    }
  }
}


static void HLAFMatrix_SetOutput( const HLAFMatrixData_t *pData,
                                  /* output */
                                  HLAFMatrixOut_t  *pOutNext
                                )
{
  uint8 iGFA;


  pOutNext->Matrix.GFAStatus = RTE_HLAF_SIGSTAT_DATA_VALID;

  /* HB off */
  if(pOutNext->Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF)
  {
    /* HB off */

    /* GFA defined -> copy all GFAs */
    if(pData->Matrix.GFA.nGFA > 0)
    {
      /* copy all GFA Data */
      for(iGFA = 0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
      {
        memcpy(&pOutNext->Matrix.GFA[iGFA], &pData->Matrix.GFA.GFA[iGFA].Ext, sizeof(HLAF_t_MatrixGFA));
      }
      pOutNext->Matrix.nGFA = pData->Matrix.GFA.nGFA;
    }
    else
    {
      /* no GFA defined */
    } 
  }
}


static void HLAFMatrix_SetTurnOffReason( const HLAFData_t  *pFData,
                                         const HLAFMatrixData_t *pData,
                                         const RTE_HLA_ParameterAlgoCfg_t *pAlgoCfg,
                                         /* output */
                                         HLAFMatrixOut_t  *pOutNext
                                       )
{
  pOutNext->Matrix.TurnOffReason = RTE_HLAF_TURNOFFREASON_UNKNOWN;

  if(pFData->DecisionData.TurnOffReason_glob.Reason.Bit.City == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_CITY;
  }

  if(pFData->DecisionData.TurnOffReason_glob.Reason.Bit.Brightness == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_BRIGHTNESS;
  }

  if(pFData->DecisionData.TurnOffReason_glob.Reason.Bit.MinSpeed == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_LOW_SPEED;
  }

  if(pData->RelevantVehicle.bOncDetected == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_ONC;
  }

  if(pData->RelevantVehicle.bPrecDetected == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_PREC;
  }
  
  /* blockage detected */
  if(pFData->DecisionOut.Blockage.b_Blockage == b_TRUE)
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_BLOCKAGE;
  }

  /* HB off and no turn off reason set -> set RTE_HLAF_TURNOFFREASON_DELAY */
  if(    (pOutNext->Matrix.TurnOffReason == 0)
      && (pOutNext->Matrix.HighBeamState == RTE_HLAF_HB_STATE_OFF)
    ) 
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_DELAY;
  }

  /* TODO: Move Fog to hlaf_decision.c global turn off reasons */
  /* Fog detected */
  if(    (pFData->DecisionOut.eWeatherState == RTE_HLAR_WEATHER_HEAVY_FOG)
      && (pAlgoCfg->FogDetection == RTE_HLA_FOGDET_ACTIVE)
     )
  {
    pOutNext->Matrix.TurnOffReason |= RTE_HLAF_TURNOFFREASON_FOG;
  }
}


static void HLAFMatrix_SetLowBeamDist( const HLAFData_t *pFData,
                                       const HLAFMatrixData_t *pData,
                                       const RTE_HLAF_HighBeamState HighBeamStateNext,
                                       const HLAFMatrixParameter_t *pMatrixPar,
                                       /* output */
                                       HLAF_t_Matrix *pMatrixNext
                                     )
{
  if(HighBeamStateNext == RTE_HLAF_HB_STATE_FULL_ON)
  {
    pMatrixNext->LowBeam_Dist    = pMatrixPar->Output.LowBeam_Dist_Max;
    pMatrixNext->LowBeam_Ang     = pMatrixPar->Output.LowBeam_Ang_Default;
    pMatrixNext->LowBeam_Status  = RTE_HLAF_OBJSTA_NO_OBJ;
  }
  else if(pData->Matrix.GFA.nGFA > 0)
  {
    uint8 iGFA;
    uint8 iGFAminLightDist = 0;
    float32 minLightDist = pMatrixPar->Output.LowBeam_Dist_Max;
    

    for(iGFA=0; iGFA<pData->Matrix.GFA.nGFA; iGFA++)
    {
      if(pData->Matrix.GFA.GFA[iGFA].Ext.MinLight_Dist < minLightDist)
      {
        minLightDist = pData->Matrix.GFA.GFA[iGFA].Ext.MinLight_Dist;
        iGFAminLightDist = iGFA;
      }
    }
    pMatrixNext->LowBeam_Dist   = pData->Matrix.GFA.GFA[iGFAminLightDist].Ext.MinLight_Dist;
    pMatrixNext->LowBeam_Ang    = pData->Matrix.GFA.GFA[iGFAminLightDist].Ext.MinLight_Ang;
    pMatrixNext->LowBeam_Status = pData->Matrix.GFA.GFA[iGFAminLightDist].Ext.MinLight_Status;
  }
  else if(pFData->DecisionData.TurnOffReason_glob.Reason.u32 > 0)
  {
    /* global turn off reason */
    pMatrixNext->LowBeam_Dist    = pMatrixPar->Output.LowBeam_Dist_Default;
    pMatrixNext->LowBeam_Ang     = pMatrixPar->Output.LowBeam_Ang_Default;
    pMatrixNext->LowBeam_Status  = RTE_HLAF_OBJSTA_NO_OBJ;
  }
  else
  {
    /* keep old distance */
    pMatrixNext->LowBeam_Dist    = pData->Out.Matrix.LowBeam_Dist;
    pMatrixNext->LowBeam_Ang     = pData->Out.Matrix.LowBeam_Ang;
    pMatrixNext->LowBeam_Status  = pData->Out.Matrix.LowBeam_Status;
  }
}


/* **************************************************************************** 
  Functionname:     HLAFMatrixInitData                                     */ /*!
  @brief            initializes data
  @description      initializes data
                    
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFMatrix_InitData(void)
{
  (void)memset((void*)&hlafMatrixData, 0, sizeof(HLAFMatrixData_t));
  (void)memset((void*)&halfMatrixInput, 0, sizeof(HLAFMatrixInput_t));

  /* init glare free areas */
  HLAFMatrixGFAInit(&hlafMatrixData.Matrix.GFA);

  /* init internal object list */
  HLAFMatrix_InitObjectList(&hlafMatrixData.Object[0]);
}

/* **************************************************************************** 
  Functionname:     HLAPlusInitOutput                                    */ /*!
  @brief            initializes output data
  @description      initializes output data
                    
  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
static void HLAFMatrix_InitOutput(HLAFMatrixOut_t *pOut)
{
  memset(pOut, 0, sizeof(HLAFMatrixOut_t));
}


/* **************************************************************************** 
  Functionname:     HLAFMatrixInit                                       */ /*!
  @brief            HLAF matrix beam init function
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFMatrixInit(HLAFMatrixOut_t *pOut)
{
  /* init some vars only once after bootup */
  
  /* init data */
  HLAFMatrix_InitData();

  /* init output data */
  HLAFMatrix_InitOutput(pOut);
  
}

/* **************************************************************************** 
  Functionname:     HLAFMatrixMain                                       */ /*!
  @brief            HLAF matrix beam processing
  @description      

  @param[in]        -
  @param[in,out]    -
  @return           -
  @pre              -
  @post             -
  @author           Marcus Brunn
**************************************************************************** */
void HLAFMatrixMain( /* input */
                      const HLAF_t_RequiredInputs  *ps_In,
                      const HLAFMatrixParameter_t *pPar,
                      const HLAFData_t             *pFData,
                      /* output */
                      HLAFMatrixOut_t             *pOut
                    )
{
  HLAFMatrixOut_t MatrixOut_Next; /* next matrix output data */
  
  
  /* init matrix output */
  HLAFMatrix_InitOutput(&MatrixOut_Next);

  /* prepare internal object list, reset data and set object ID of pair light */
  HLAFMatrix_PrepareObjectList( ps_In,
                                &hlafMatrixData
                              );

  /* cluster vehicle lights to desired number of glare free areas (GFAs) */
  HLAFMatrixGFAMain( ps_In,
                     pPar,
                     pFData,
                     &hlafMatrixData
                   );

  /* HB on time < 3sec -> increase penalty timer +0.5sec */
  HLAFDecisionPenaltyTimer( /* input */
                            hlafMatrixData.Out.Matrix.HighBeamState,
                            pFData->CamData.dtimeFwd_s,
                            /* history/ output */
                            &hlafMatrixData.PenaltyTimer
                          );

  /* check track list for existing target */
  HLAFDecisionFindRelevantVehicle( /* Input */
                                   ps_In,
                                   pFData,
                                   ps_In->s_Sig.ps_ObjectList,
                                   hlafMatrixData.Out.Matrix.HighBeamState,
                                   /* History/ Output */
                                   &hlafMatrixData.RelevantVehicle
                                  );

  /* set turn off reason */
  HLAFDecisionSetTurnOffReason( /* input */
                                &hlafMatrixData.RelevantVehicle,
                                /* output */
                                &hlafMatrixData.TurnOffReason
                              );

  /* set keep off reason */
  HLAFDecisionSetKeepOffReason( /* input */
                                ps_In,
                                pFData,
                                &pPar->KeepOff,
                                &pPar->TurnOnDelay,
                                hlafMatrixData.Out.Matrix.HighBeamState,
                                &hlafMatrixData.RelevantVehicle,
                                &hlafMatrixData.PenaltyTimer,
                                &hlafMatrixData.TurnOffReason,
                                /* history, output */
                                &hlafMatrixData.KeepOffReason
                              );

  /* set HB state {HB on or off} */
  HLAFDecisionSetHBState( /* input */
                          &pFData->DecisionData.TurnOffReason_glob,
                          &hlafMatrixData.TurnOffReason,
                          &hlafMatrixData.KeepOffReason,
                          hlafMatrixData.Out.Matrix.HighBeamState,
                          /* output */
                          &MatrixOut_Next.Matrix.HighBeamState
                        );

  /* set low beam distance recommendation */
  HLAFMatrix_SetLowBeamDist( /* input */
                             pFData,
                             &hlafMatrixData,
                             MatrixOut_Next.Matrix.HighBeamState,
                             &hlafMatrixParameter,
                             /* output */
                             &MatrixOut_Next.Matrix
                           );

  /* set output turn off reason */
  HLAFMatrix_SetTurnOffReason( /* input */
                               pFData,
                               &hlafMatrixData,
                               &ps_In->s_Par.ps_HlaPar->AlgoCfg,
                               /* output */        
                               &MatrixOut_Next
                             );

  /* set output interface */
  HLAFMatrix_SetOutput( /* input */
                        &hlafMatrixData,
                        /* output */        
                        &MatrixOut_Next
                      );

  hlafMatrixData.Out = MatrixOut_Next; 
  *pOut               = MatrixOut_Next;

}


/* ****************************************************************************
  Functionname:     HLAFMatrixMeasfreeze                          */ /*!
  Description:      send internal hla matrix beam data via measfreeze to MTS. 



  @param[in]        

  @pre              -
  @post             -
  @todo             - 
  @author           
**************************************************************************** */
void HLAFMatrixMeasfreeze(AS_t_MeasHdlr pfMeasFreeze)
{
#ifdef HLA_ENABLE_INTERNAL_MEASFREEZES
  AS_t_MeasInfo HlafMatrixParameterMeasInfo = {HLA_MEAS_VADDR_HLAF_MATRIX_PARAMETER, sizeof(hlafMatrixParameter), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafMatrixInputMeasInfo     = {HLA_MEAS_VADDR_HLAF_MATRIX_INPUT, sizeof(halfMatrixInput), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};
  AS_t_MeasInfo HlafMatrixDataMeasInfo      = {HLA_MEAS_VADDR_HLAF_MATRIX_DATA, sizeof(hlafMatrixData), 0 /*COMP_ID_HLA*/, TASK_ID_HLA};

  (void)pfMeasFreeze(&HlafMatrixParameterMeasInfo, (void*)&hlafMatrixParameter, NULL);
  (void)pfMeasFreeze(&HlafMatrixInputMeasInfo, (void*)&halfMatrixInput, NULL);
  (void)pfMeasFreeze(&HlafMatrixDataMeasInfo, (void*)&hlafMatrixData, NULL);
#endif  
}/* PRQA S 861 1 */
