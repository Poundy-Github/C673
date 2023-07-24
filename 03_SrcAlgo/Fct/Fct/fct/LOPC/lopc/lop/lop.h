/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACC/LOPC/LOP (Adaptive Cruise Control - Longitudinal Planner & Coordinator - Longitudinal Coordinator)

PACKAGENAME:               lop.h

DESCRIPTION:               Internal header file for LOP in LOPC

AUTHOR:                    Mistry Niraj (uidq5738)

CREATION DATE:             24.02.2017

VERSION:                   $Revision: 1.11 $

---*/ /*---
CHANGES:                    $Log: lop.h  $
CHANGES:                    Revision 1.11 2018/11/07 14:54:01CET uidj5069 
CHANGES:                    Struct Type <LOP_ControlOutput_t> and Function Type <LOP_v_TFC_ControlArbitration()> updated
CHANGES:                    Revision 1.10 2018/07/12 17:38:59CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Naming of Functions updated
CHANGES:                    Revision 1.9 2018/06/13 15:59:44CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Unused Function Parameter <const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP> removed
CHANGES:                    Revision 1.8 2017/12/01 10:52:31CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Update of Function <LOP_v_TFC_ControlArbitration()>
CHANGES:                    Revision 1.7 2017/11/30 10:46:16CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Various improvements of <TargetFollowControl> <VehicleSpeedControl>
CHANGES:                    Revision 1.6 2017/11/21 10:52:15CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Port array size renamed to RTE define
CHANGES:                    Update of various function prototypes
CHANGES:                    Revision 1.5 2017/11/13 15:35:26CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    General Improvement of Target Follow Control (GEN 4)
CHANGES:                    Revision 1.4 2017/11/02 15:25:56CET Borgs, Wolfgang (uidj5069) 
CHANGES:                    Integration of Info <b_StartTrial> of Target Follow Controller into Vehicle Speed Control State
CHANGES:                    Revision 1.3 2017/10/26 10:14:21CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Additional Input Port <EgoVehicleStatePort> for LOP
CHANGES:                    Revision 1.2 2017/10/10 15:33:57CEST Borgs, Wolfgang (uidj5069) 
CHANGES:                    Target Follow Controller added
CHANGES:                    Revision 1.1 2017/03/15 20:58:43CET Berendes, Ignacius (uid41806) 
CHANGES:                    Initial revision
CHANGES:                    Member added to project /ADAS/SW/Components/LOPC/04_Engineering/01_Source_Code/LOPC/hc/project.pj
CHANGES:                    Derived from Version 2.0 in /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/FCT_Function/04_Engineering/01_Source_Code/algo/fct/lopc/hc/project.pj

**************************************************************************** */

#ifndef LOP_H_INCLUDED
#define LOP_H_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/

#include "frame_lopc.h"
#include "lop_cfg.h"
#include "lop_par.h"

#if ((FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP))
/*****************************************************************************
  SYMBOLISCHE KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  MACROS (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS (KOMPONENTENINTERN)
*****************************************************************************/

/*! Typedef of <VehicleSpeedOutputPort> local output port inside LOP component */
#if (LOP_CFG_VSC_PORT_CNT)
typedef struct
{
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_ArbitDriverMin;                                       /* Minimum arbitration against driver request (speed limiter function) */
  boolean b_Active;                                               /* Control is active */
}
LOP_VehicleSpeedOutput_t;
typedef struct
{
  LOP_VehicleSpeedOutput_t at_LOP_LOC_VSO[LOP_CFG_VSC_PORT_CNT];  /* Output struct array */
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_ArbitDriverMin;                                       /* Minimum arbitration against driver request (speed limiter function) */
  boolean b_Active;                                               /* Control is active */
}
LOP_VehicleSpeedOutputPort_t;
#endif

/*! Typedef of <DistanceSpeedOutputPort> local output port inside LOP component */
#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
typedef struct
{
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_Active;                                               /* Control is active */
}
LOP_DistanceSpeedSegment_t;
typedef struct
{
  LOP_DistanceSpeedSegment_t at_LOP_LOC_DSS[ACT_CFG_DSC_PORT_SEG_CNT];  /* Speed segment struct array */
  float32 f_LongAccelGrad;                                              /* Longitudinal acceleration gradient */
  boolean b_Active;                                                     /* Control is active */
}
LOP_DistanceSpeedOutput_t;
typedef struct
{
  LOP_DistanceSpeedOutput_t at_LOP_LOC_DSO[LOP_CFG_DSC_PORT_CNT]; /* Output struct array */
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_Active;                                               /* Control is active */
}
LOP_DistanceSpeedOutputPort_t;
#endif

/*! Typedef of <DistanceCurveOutputPort> local output port inside LOP component */
#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
typedef struct
{
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_Active;                                               /* Control is active */
}
LOP_DistanceCurveSegment_t;
typedef struct
{
  LOP_DistanceCurveSegment_t at_LOP_LOC_DCS[ACT_CFG_DCC_PORT_SEG_CNT];  /* Curve segment struct array */
  float32 f_LongAccelGrad;                                              /* Longitudinal acceleration gradient */
  boolean b_Active;                                                     /* Control is active */
}
LOP_DistanceCurveOutput_t;
typedef struct
{
  LOP_DistanceCurveOutput_t at_LOP_LOC_DCO[LOP_CFG_DCC_PORT_CNT]; /* Output struct array */
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_Active;                                               /* Control is active */
}
LOP_DistanceCurveOutputPort_t;
#endif

/*! Typedef of <TargetFollowOutputPort> local output port inside LOP component */
#if (FCT_CFG_HP_TFC_PORT_CNT)
typedef struct
{
  float32 f_LongAccelGrad;                                        /* Longitudinal acceleration gradient */
  boolean b_Active;                                               /* Control is active */
}
LOP_TargetFollowOutput_t;
typedef struct
{
  LOP_TargetFollowOutput_t at_LOP_LOC_TFO[FCT_CFG_HP_TFC_PORT_CNT]; /* Output struct array */
  float32 f_LongAccelGrad;                                          /* Longitudinal acceleration gradient */
  boolean b_Active;                                                 /* Control is active */
}
LOP_TargetFollowOutputPort_t;

typedef struct
{
  float32 f_LongVelo;
  float32 f_LongAccel;
  float32 f_LongAccelGrad;
}
LOP_MotionProfile_t;

typedef struct
{
  float32 f_LongVelo;
  float32 f_AccelGrad;
  boolean b_Limited;
}
LOP_ControlOutput_t;

#endif


/*****************************************************************************
  KONSTANTEN (KOMPONENTENINTERN)
*****************************************************************************/


/*****************************************************************************
  VARIABLEN (KOMPONENTENINTERN)
*****************************************************************************/

/*! External declaration of pointer to LOP output structure for usage in this module */

/*! External declaration of pointer to LOP input structure for usage in this module */

/*****************************************************************************
  FUNKTIONEN (KOMPONENTENINTERN)
*****************************************************************************/
#ifdef __cplusplus
  extern "C" {
#endif

/* lop_main.c */

/* lop_generic.c */



extern void LOP_v_GEN_SpeedProfileControl (const LOP_MotionProfile_t *pt_MP_IN,
                                           const ControlLimitations_t *pt_CL_IN,
                                           const LOPC_IdealVehVeloState_t *pt_IVVS_IN,
                                           LOP_ControlOutput_t *pt_CO_OUT);

extern void LOP_v_GEN_AccelProfileControl (const LOP_MotionProfile_t *pt_MP_IN,
                                           const ControlLimitations_t *pt_CL_IN,
                                           const LOPC_IdealVehVeloState_t *pt_IVVS_IN,
                                           LOP_ControlOutput_t *pt_CO_OUT);


#if (LOP_CFG_VSC_PORT_CNT)

extern void LOP_v_VehicleSpeedControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                               const LOPC_VehicleSpeedCommandPort_t at_LOP_IN_VSCP[],
                                               LOP_VehicleSpeedOutputPort_t *pt_LOP_LOC_VSOP,
                                               LOPC_VehicleSpeedStatePort_t at_LOP_OUT_VSSP[]);

extern void LOP_v_VehicleSpeedControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                       const LOPC_VehicleSpeedCommandPort_t *pt_LOP_IN_VSCP,
                                       LOP_VehicleSpeedOutput_t *pt_LOP_LOC_VSO,
                                       LOPC_VehicleSpeedStatePort_t *pt_LOP_OUT_VSSP);

#endif

#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)

extern void LOP_v_DistanceSpeedControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                                const LOPC_DistanceSpeedCommandPort_t at_LOP_IN_DSCP[],
                                                LOP_DistanceSpeedOutputPort_t *pt_LOP_LOC_DSOP,
                                                LOPC_DistanceSpeedStatePort_t at_LOP_OUT_DSSP[]);

extern void LOP_v_DistanceSpeedControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                        const LOPC_DistanceSpeedCommandPort_t *pt_LOP_IN_DSCP,
                                        LOP_DistanceSpeedOutput_t *pt_LOP_LOC_DSO,
                                        LOPC_DistanceSpeedStatePort_t *pt_LOP_OUT_DSSP);
#endif

#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)

extern void LOP_v_DistanceCurveControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                                const LOPC_DistanceCurveCommandPort_t at_LOP_IN_DCCP[],
                                                LOP_DistanceCurveOutputPort_t *pt_LOP_LOC_DCOP,
                                                LOPC_DistanceCurveStatePort_t at_LOP_OUT_DCSP[]);

extern void LOP_v_DistanceCurveControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                        const LOPC_DistanceCurveCommandPort_t *pt_LOP_IN_DCCP,
                                        LOP_DistanceCurveOutput_t *pt_LOP_LOC_DCO,
                                        LOPC_DistanceCurveStatePort_t *pt_LOP_OUT_DCSP);

#endif

#if (FCT_CFG_HP_TFC_PORT_CNT)

extern void LOP_v_TargetFollowControl_Process (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                               const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP,
                                               const LOPC_TargetFollowCommandPort_t at_LOP_IN_TFCP[],
                                               LOP_TargetFollowOutputPort_t *pt_LOP_LOC_TFOP,
                                               LOPC_TargetFollowStatePort_t at_LOP_OUT_TFSP[]);

extern void LOP_v_TargetFollowControl (const LOPC_IdealVehicleStatePort_t *pt_LOP_IN_IVSP,
                                       const LOPC_EgoVehicleStatePort_t *pt_LOP_IN_EVSP,
                                       const LOPC_TargetFollowCommandPort_t *pt_LOP_IN_TFCP,
                                       LOP_TargetFollowOutput_t *pt_LOP_LOC_TFO,
                                       LOPC_TargetFollowStatePort_t *pt_LOP_OUT_TFSP);

extern void LOP_v_TFC_RelativeToTargetTransformation (const LOPC_IdealVehDistState_t *pt_IVDS_IN,
                                                      const LOPC_EgoVehicleState_t *pt_EVS_IN,
                                                      const TargetFollowCommand_t *pt_TFC_IN,
                                                      TargetVehicle_t *pt_TE_OUT);

extern void LOP_v_TFC_SpeedProfileGeneration (const TargetVehicle_t *pt_TE_IN,
                                              const float32 *pf_RelLongDistErr,
                                              const float32 *pf_RelLongRefAcc,
                                              uint8 u_RelLongDynSize,
                                              uint8 u_RelLongZeroIndex,
                                              float32 f_RelLongIntrusion,
                                              LOP_MotionProfile_t *pt_MP_OUT);

extern void LOP_v_TFC_AccelProfileGeneration (const TargetPreferences_t *pt_TP_IN,
                                              const TargetVehicle_t *pt_TE_IN,
                                              LOP_MotionProfile_t *pt_MP_OUT);

extern void LOP_v_TFC_AccelProfileInterpolation (const TargetVehicle_t *pt_TV_IN,
                                                 const LOP_MotionProfile_t *pt_MP_SPD_MIN_IN,
                                                 const LOP_MotionProfile_t *pt_MP_SPD_MAX_IN,
                                                 LOP_MotionProfile_t *pt_MP_ACC_OUT);

extern void LOP_v_TFC_TargetToGroundTransformation (const TargetVehicle_t *pt_TV_IN,
                                                    const LOP_MotionProfile_t *pt_MP_IN,
                                                    const LOPC_EgoVehicleState_t *pt_EVS_IN,
                                                    LOP_MotionProfile_t *pt_MP_OUT);

extern void LOP_v_TFC_ControlArbitration (const TargetVehicle_t *pt_TE_IN,
                                          const TargetFollowCommand_t *pt_TFC_IN,
                                          const LOPC_IdealVehDistState_t *pt_IVDS_IN,
                                          const LOP_ControlOutput_t *pt_CO_SPC_Prf_Base,
                                          const LOP_ControlOutput_t *pt_CO_SPC_Prf_Intr,
                                          const LOP_ControlOutput_t *pt_CO_SPC_Max_Intr,
                                          const LOP_ControlOutput_t *pt_CO_APC_Prf,
                                          const LOP_ControlOutput_t *pt_CO_APC_Max,
                                          LOP_ControlOutput_t *pt_CO_OUT);

#endif

extern void LOP_v_ControlArbitration_Process (
#if (LOP_CFG_VSC_PORT_CNT)
                                              const LOP_VehicleSpeedOutputPort_t *pt_LOP_LOC_VSOP,
#endif
#if (LOP_CFG_DSC_PORT_CNT) && (ACT_CFG_DSC_PORT_SEG_CNT)
                                              const LOP_DistanceSpeedOutputPort_t *pt_LOP_LOC_DSOP,
#endif
#if (LOP_CFG_DCC_PORT_CNT) && (ACT_CFG_DCC_PORT_SEG_CNT)
                                              const LOP_DistanceCurveOutputPort_t *pt_LOP_LOC_DCOP,
#endif
#if (FCT_CFG_HP_TFC_PORT_CNT)
                                              const LOP_TargetFollowOutputPort_t *pt_LOP_LOC_TFOP,
#endif
                                              LOPC_IdealVehicleCommandPort_t *pt_LOP_OUT_IVCP);




/*--- lop_customfunctions.c ---*/
extern void LOP_v_Custom_Process(void);

#ifdef __cplusplus
};
#endif

#endif /* (FCT_CFG_LOPC_COMPONENT) && (LOPC_CFG_LOP) */
#endif /* LOP_H_INCLUDED */

