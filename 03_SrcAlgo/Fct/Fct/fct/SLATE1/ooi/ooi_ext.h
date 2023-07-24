/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Adaptive Cruise Control (ACC)

CPU:                       CPU-Independent

COMPONENT:                 SLATE_OOI (Object of Interest selection)

PACKAGENAME:               ooi_ext.h

DESCRIPTION:               Extern header file for ACC Object Of Interest (OOI) selection module

AUTHOR:                    Boll Marie-Theres (uidu1091)

CREATION DATE:             17.06.2016

VERSION:                   $Revision: 1.26 $

LEGACY VERSION:            Revision: 2.3.1.1

**************************************************************************** */

#ifndef OOI_EXT_INCLUDED
#define OOI_EXT_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/


#include "ooi_ver.h"
#include "slate_ext.h"
#include "ooi_cfg.h"
#include "ooi_par.h"

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/**
@addtogroup ooi
@{ */

#if (FCT_CFG_ACC_OOI)

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
  SYMBOLIC CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (COMPONENT EXTERN)
*****************************************************************************/

/*! 6 object interface object enumeration, aliasing RTE type */
typedef eObjOOI_t OOI_RelObjEnum_t;

/*****************************************************************************
  TYPEDEFS (COMPONENT EXTERN)
*****************************************************************************/

/*! bit by bit history type (used for whole lifetime valid informations )*/
typedef struct OOI_Bool {
  ubit8_t SelectedAsOOI              :1; /*!< Object is candidate for the OOI list */
  ubit8_t AlreadyOOI                 :1; /*!< Object is already in OOI list */
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
  ubit8_t                            :0;
}OOI_Bool_t;

typedef struct OOI_Object{
  OOI_Bool_t t_Bool;
}OOI_Object_t;

typedef OOI_Object_t OOI_ObjectList_t[EM_N_OBJECTS];



/*! Typedef of output of OOI */
typedef struct OOIOutput{
  OOI_RelObject_t t_OOI_RelObject[OBJLOSS_NUMBER_OF_OOI];  /*Information about OOIs*/
  float32 f_PredictedLatDispl[EM_N_OBJECTS];
  eRelObjLossReason_t OOI_t_eRelObjVerlustGrund[OOI_NUMBER_OF_OOI];   /* Object loss reason */
  ObjNumber_t OOI_ObjNumber[OOI_NUMBER_OF_OOI]; /* Object numbers of the OOI vehicles */
#if (OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD)
  /* This value is not used outside OOI but it is placed here to avoid component local global/static variables. 
  Need to restructure once memory from Frame is provided and corresponding config switch moved from custom_ext to _cfg. */
  boolean OOI_CrossingFlag[EM_N_OBJECTS]; /* Crossing status for all Objects */ 
#endif/*! OOI_CFG_OBJCROSSING_INCREASED_THRESHOLD */
#if (OOI_CFG_STAT_OBJ_FROM_GUARDRAIL_SUPRESS)
  uint8 OOI_uOOIObjCount;
#endif
 } OOIOutput_t;

#ifdef FCT_SIMU
typedef struct OOI_SimMeasInfo{
  OOI_ObjectList_t t_OOI_ObjectList;
  OOIOutput_t      t_OOI_FreezeOutput; 
}OOI_SimMeasInfo_t;
#endif

#if (FCT_CFG_ACC_LANE_ASSOCIATION)
typedef struct OOIInputLAConst
{
  const float32 * (*pf_ObjToRefDistMeas)(ObjNumber_t);
  const float32 * (*pf_ObjToRefDistGradFilt)(ObjNumber_t);
  const boolean * (*pb_BasePreselObjList)(ObjNumber_t);
  const LAObjOutput_t  * (*pt_LAObjectList)(ObjNumber_t);
}OOIInputLAConst_t;
#endif

#if (FCT_CFG_ACC_SITUATION)
typedef struct OOIInputSITConst
{
  const float32 * pf_DistXFarObjId;
#if (SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH)
  const float32 * pf_DistXCloseObjId;
#endif /* SLATE_CFG_EGO_LANE_DEPENDENT_BLOCKED_PATH */
  const float32 * pf_FarObjDistTraj;
  const float32 * pf_CloseObjDistTraj;
  const uint8 * (*pu_BlockedPathSelectionTimer)(const ObjNumber_t);
  const ObjNumber_t * pt_BlockedPathFarObjID;
  const ObjNumber_t * pt_BlockedPathCloseObjID;
  const sint16 * pt_GetLaneChangeProb;
  const SIT_LC_t_LaneChangePhaseInfo * pt_GetLaneChangePhase;
}OOIInputSITConst_t;
#endif

/*! Typedef of inputs to OOI component from Frame */
typedef struct OOIInputFrame{
#ifdef FCT_SIMU
  OOI_SimMeasInfo_t * pt_OOI_SimMeasInfo; /*!< Sim Freeze of SIT from Frame */
  const MEASInfo_t * pt_OOI_SimMeasInfoFreeze;
#else
  boolean dummy;
#endif
}OOIInputFrame_t;

/*! Typedef of constant input to OOI component from RTE Input Ports */
typedef struct OOIInputRTEConst{
  const float32 * (*pf_ObjLongDisp)(ObjNumber_t);   /* Longitudinal displacement of object */
  const float32 * (*pf_ObjLatDisp)(ObjNumber_t);    /* Lateral displacement of object */
  const float32 * (*pf_ObjVRelX)(ObjNumber_t);      /* Object relative longitudinal velocity */
  const float32 * (*pf_ObjVRelY)(ObjNumber_t);      /* Object relative longitudinal velocity */
  const float32 * (*pf_ObjArelX)(ObjNumber_t);      /* Object relative longitudinal acceleration */
  const float32 * pf_EgoVelObjSync;                 /* EGO Velocity sync */
  const float32 * pf_EgoCurve;                      /* Curvature of ego vehicle path */
  const SLATE_t_Obj_DynamicProperty * (*pf_ObjDynProperty)(ObjNumber_t);/* Object Dynamic property */
#if(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)
  const SLATE_t_Obj_CLassification * (*pf_ObjClassification)(ObjNumber_t);/* Object Classification */
#endif /*(OOI_CFG_REL_OBJ_CHANGE_DURING_BIKE_OVERTAKE)*/
}OOIInputRTEConst_t; 

/*! Typedef of constant input to OOI component */
typedef struct OOIInputConst
{
  OOIInputFrame_t t_FrameSimFreeze;
#if (FCT_CFG_ACC_LANE_ASSOCIATION)
  OOIInputLAConst_t t_LAInput;
#endif
#if (FCT_CFG_INPUT_PREPROCESSSING)
  const FIP_OA_Output_t *pt_FIPInput;
#endif
#if (FCT_CFG_ACC_SITUATION)
  OOIInputSITConst_t t_SITInput;
#endif
   OOIInputRTEConst_t t_RTE;

} OOIInputConst_t;


/*****************************************************************************
  CONSTANTS (COMPONENT EXTERN)
*****************************************************************************/
/*! External declaration of OOI output structure */
extern MEMSEC_REF OOIOutput_t t_OOI_Output;

/*****************************************************************************
  VARIABLES (COMPONENT EXTERN)
*****************************************************************************/

extern MEMSEC_REF SLATECompState_t OOI_State;

extern OOI_ObjectList_t t_OOI_ObjectList;

/*! External declaration of last cycle OOI array */
extern ObjNumber_t t_OOI_LastCycleOOIObjID[OOI_NUMBER_OF_OOI];


/*****************************************************************************
  FUNCTIONS (COMPONENT EXTERN)
*****************************************************************************/

/*--- ooi_main.c ---*/
extern void OOI_v_PreProcess(OOIInputConst_t * pt_OOI_InputGlobal, OOIOutput_t * pt_OOI_OutputGlobal, FCTSen_MergeDeleteObject_t t_MergeDeleteObjList[]);
extern void OOI_v_Process(OOIInputConst_t * pt_OOI_InputGlobal, OOIOutput_t * pt_OOI_OutputGlobal);
extern void OOI_v_DeleteObject(ObjNumber_t ObjId);
extern void OOI_v_MergeObjects(ObjNumber_t iObjectToKeep, ObjNumber_t iObjectToDelete);
extern void OOI_v_MergeDeleteObjectSameFCTID(ObjNumber_t ObjNr);
extern void OOI_v_SetOperationMode(SLATECompState_t const t_OOIOpModeValue);



#ifdef __cplusplus
};
#endif

#endif /*!< FCT_CFG_ACC_OOI */

/* End of conditional inclusion */

#endif  /*!< _OOI_EXT_INCLUDED */
