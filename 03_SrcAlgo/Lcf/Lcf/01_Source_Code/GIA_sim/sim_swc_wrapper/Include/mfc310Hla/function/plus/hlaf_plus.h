/*! \file **********************************************************************

  COMPANY:                Continental AG, BU PSAD, Segment ADAS (A.D.C. GmbH)

  PROJECT:                MFC300

  CPU:                    FreeScale Gold Dust

  COMPONENT:              HLA

  MODULNAME:              hlaf_plus.h

  DESCRIPTION:            HLA plus function.

  AUTHOR:                 Marcus Brunn

  CREATION DATE:          2011-02-23

  VERSION:                $Revision: 1.1 $

  ---*/ /*---
  CHANGES:                $Log: hlaf_plus.h  $
  CHANGES:                Revision 1.1 2021/12/13 17:27:26CET Wang, David (Wangd3) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/Projects/MFC5xx/MFC5J3/06_Algorithm/DPU/04_Engineering/01_Source_Code/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.0 2017/03/03 10:39:05CET Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /ADAS/SW/Integration/06_Simulation_Components/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/Component_Workspace/GIA_sim/sim_swc_wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.1 2014/04/17 16:05:45CEST Sorge, Sven (uidg3181) 
  CHANGES:                Initial revision
  CHANGES:                Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ETK_EngineeringToolKit/04_Engineering/GIA_GenericInterfaceAdapter/04_Engineering/03_Workspace/algo/gia_sim/wrapper/Include/mfc310Hla/function/plus/project.pj
  CHANGES:                Revision 1.61 2014/03/25 18:40:37CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Member moved from hlaf_plus.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/project.pj to hlaf_plus.h in project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/HLA_HeadLightAssist/04_Engineering/01_Source_Code/algo/hla/function/plus/project.pj.
  CHANGES:                Revision 1.60 2014/03/05 11:17:11CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed build error from previous check-in
  CHANGES:                --- Added comments ---  uidv7867 [Mar 5, 2014 11:17:12 AM CET]
  CHANGES:                Change Package : 207432:25 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.59 2014/03/04 16:52:25CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Fixed QAC warnings
  CHANGES:                Coding style
  CHANGES:                --- Added comments ---  uidv7867 [Mar 4, 2014 4:52:26 PM CET]
  CHANGES:                Change Package : 207432:35 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.58 2013/12/13 16:44:48CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Service functions are now passed in one struct
  CHANGES:                SDLfile definitions moved to separate file
  CHANGES:                --- Added comments ---  uidv7867 [Dec 13, 2013 4:44:48 PM CET]
  CHANGES:                Change Package : 207432:20 http://mks-psad:7002/im/viewissue?selection=207432
  CHANGES:                Revision 1.57 2013/04/25 11:02:44CEST Brunn, Marcus (brunnm) 
  CHANGES:                implemented hla plus configuration switch 
  CHANGES:                implemented TurnOffLeft_OncOnly, TurnOffLeft_LeftOnly, KeepOffLeft_LeftOnly and AsymmetricMode
  CHANGES:                --- Added comments ---  brunnm [Apr 25, 2013 11:02:44 AM CEST]
  CHANGES:                Change Package : 167112:1 http://mks-psad:7002/im/viewissue?selection=167112
  CHANGES:                Revision 1.56 2013/03/08 10:29:57CET Mutschler, Matthias (uidv7867) 
  CHANGES:                Updated to latest RTE
  CHANGES:                --- Added comments ---  uidv7867 [Mar 8, 2013 10:29:58 AM CET]
  CHANGES:                Change Package : 167173:28 http://mks-psad:7002/im/viewissue?selection=167173
  CHANGES:                Revision 1.55 2012/07/18 07:51:45CEST Brunn, Marcus (brunnm) 
  CHANGES:                - added code review tags
  CHANGES:                --- Added comments ---  brunnm [Jul 18, 2012 7:51:46 AM CEST]
  CHANGES:                Change Package : 94933:1 http://mks-psad:7002/im/viewissue?selection=94933
  CHANGES:                Revision 1.54 2012/04/25 19:23:58CEST Brunn, Marcus (brunnm) 
  CHANGES:                HLAF:
  CHANGES:                - reduced TurnOff_minTTB from 2 to 1sec
  CHANGES:                - fixed maybecity full HB turn off
  CHANGES:                - turn off partial HB for preceding vehicles in less than 25m
  CHANGES:                --- Added comments ---  brunnm [Apr 25, 2012 7:23:59 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.53 2012/04/23 15:49:55CEST Brunn, Marcus (brunnm) 
  CHANGES:                - KeepOffReason: introduced TurnOnDelay_Init, TurnOnDelay_Onc, TurnOnDelay_Prec
  CHANGES:                - delayed HB turn on after vehicles goes lost
  CHANGES:                --- Added comments ---  brunnm [Apr 23, 2012 3:49:56 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.52 2012/04/21 15:04:34CEST Brunn, Marcus (brunnm) 
  CHANGES:                introduced first hla light version
  CHANGES:                --- Added comments ---  brunnm [Apr 21, 2012 3:04:35 PM CEST]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.51 2012/03/14 08:52:30CET Brunn, Marcus (brunnm) 
  CHANGES:                replaced NoVehCnt with NoVehTimer_s
  CHANGES:                Revision 1.50 2012/03/12 06:05:49CET Brunn, Marcus (brunnm) 
  CHANGES:                Endland test drive fixes
  CHANGES:                - change over level (full HB -> off)
  CHANGES:                Revision 1.49 2012/02/23 16:42:06CET Brunn, Marcus (brunnm) 
  CHANGES:                - fixed some issues for left hand traffic
  CHANGES:                - increased HB turn on delay when wiper is on stage 6
  CHANGES:                - symmetric light style: hla plus only available when the traffic style is verified during current ignition cycle
  CHANGES:                - increased HLA plus safety angle (cut off angle) when the camera is not online calibrated
  CHANGES:                --- Added comments ---  brunnm [Feb 23, 2012 4:42:06 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.48 2012/02/20 16:40:34CET Brunn, Marcus (brunnm) 
  CHANGES:                hlaf optimization in curvy roads
  CHANGES:                Revision 1.47 2012/02/13 06:21:17CET Brunn, Marcus (brunnm) 
  CHANGES:                restructed extended object list
  CHANGES:                Revision 1.46 2012/02/08 16:57:50CET Brunn, Marcus (brunnm) 
  CHANGES:                - fixed detection of relevant traffic
  CHANGES:                - hla plus: fast HB on when oncoming traffic passed
  CHANGES:                Revision 1.45 2012/02/06 15:27:42CET Brunn, Marcus (brunnm) 
  CHANGES:                turn off HB when TTB > 2.0sec and ABS(hor.Angle) < 16°
  CHANGES:                --- Added comments ---  brunnm [Feb 6, 2012 3:27:42 PM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                Revision 1.44 2012/01/31 06:39:45CET Brunn, Marcus (brunnm) 
  CHANGES:                restructuring of HLAF Plus
  CHANGES:                --- Added comments ---  brunnm [Jan 31, 2012 6:39:46 AM CET]
  CHANGES:                Change Package : 94870:1 http://mks-psad:7002/im/viewissue?selection=94870
  CHANGES:                
  CHANGES:
  CHANGES:
**************************************************************************** */

/* avoid cyclic binding ---------------------------------------------------*/
#ifndef HLAF_PLUS_INCLUDED
#define HLAF_PLUS_INCLUDED

/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "hla_type.h"
#include "hlaf_type.h"
#include "hlaf_cfg.h"
#include "hlaf_ext.h"
#include "hlaf_pluscfg.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS 
*****************************************************************************/


/*****************************************************************************
  MACROS 
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS 
*****************************************************************************/

/* enum for partial high beam region */
typedef enum 
{
  HLA_PLUS_INIT = 0u,         /*!< init state                                                           */ 
  HLA_PLUS_NO_OBJ = 1u,       /*!< no oncoming/ preceding vehicles detected at all                      */
  HLA_PLUS_DEACT_REGION = 2u, /*!< min. one object in deactivation region                               */
  HLA_PLUS_HOLD_REGION = 3u,  /*!< min. one object in hold region but NO object in deactivation region  */
  HLA_PLUS_ACT_REGION = 4u    /*!< all objects in activation region                                     */
} eHLAplusRegion_t;

typedef struct
{
  eHLAplusRegion_t eRegion;  /* current region                   */

  eHLAplusRegion_t eRegion_TimeDist; /* region of time and distance */
  float32          time_s;   /* time in this region                 */
  float32          dist_m;   /* covered distance in this region     */
} HLAplusRegion_t; 

/* enum for left/ right headlamp */
typedef enum 
{
  HLA_PLUS_LEFT_HEADLAMP  = 0u,       /*!< left  headlamp */ 
  HLA_PLUS_RIGHT_HEADLAMP = 1u        /*!< right headlamp */
} eHLAplusHeadlamp_t;

typedef struct 
{
  /* any relevant vehicle detected */
  boolean       bVehDet;                /* (lost or alive) vehicle detected */
  boolean       bVehDet_Alive;          /* alive vehicle detected           */
  
  HLA_t_Object  VehOutermost;           /* (lost or alive) outermost vehicle left                                     */
  HLA_t_Object  VehOutermost_Alive;     /* (only alive) outermost vehicle left                                        */

  /* predicted angles */
  float32       AngOutermostPred;        /* (lost or alive) predicted angle of outermost vehicle on the left side     */
  float32       AngOutermostPred_Alive;  /* (only alive) predicted angle of outermost vehicle on the left side        */
} HLAplusOutermostData_t;

typedef struct 
{
  HLAplusOutermostData_t Left;       /* outermost vehicle data                */
  HLAplusOutermostData_t Right;      /* outermost vehicle data                */
  /* outermost vehicle data from previous vehicle (Cycle <= (T-1)) */
  /* if vehicle detected in last cycle than the data from previous cycle */
  /* if no vehicle detected in last cycle than the data from previous detected vehicle */
  HLAplusOutermostData_t PrevVeh_left;
  HLAplusOutermostData_t PrevVeh_right;
} HLAplusOutermost_t;

/* deactivation/ hold/ activation region data for partial high beam */
typedef struct 
{
  /* pointer to current activation/ deactivation region parameter set */
  /* preceding vehicle */
  const HLAplusActDeactRegionPar_t   *pActReg_right_preced;
  const HLAplusActDeactRegionPar_t   *pActReg_left_preced;
  const HLAplusActDeactRegionPar_t   *pDeactReg_left_preced;
  const HLAplusActDeactRegionPar_t   *pDeactReg_right_preced;
  /* oncoming vehicle */
  const HLAplusActDeactRegionPar_t   *pActReg_left_oncom;
  const HLAplusActDeactRegionPar_t   *pActReg_right_oncom;
  const HLAplusActDeactRegionPar_t   *pDeactReg_left_oncom;
  const HLAplusActDeactRegionPar_t   *pDeactReg_right_oncom;  
  
  HLAplusRegion_t  RegionOncom_left;             /* (lost or alive) oncoming vehicle mapping to partial high beam region for left  headlamp     */
  HLAplusRegion_t  RegionOncom_right;            /* (lost or alive) oncoming vehicle mapping to partial high beam region for right headlamp     */
    
  HLAplusRegion_t  RegionOncom_Alive_left;       /* (only alive) oncoming vehicle mapping to partial high beam region for left  headlamp     */
  HLAplusRegion_t  RegionOncom_Alive_right;      /* (only alive) oncoming vehicle mapping to partial high beam region for right headlamp     */
  
  HLAplusRegion_t  RegionPreced_left;            /* (lost or alive) preceding vehicle mapping to partial high beam region for left  headlamp    */
  HLAplusRegion_t  RegionPreced_right;           /* (lost or alive) preceding vehicle mapping to partial high beam region for right headlamp    */
  
  HLAplusRegion_t  RegionPreced_Alive_left;      /* (only alive) preceding vehicle mapping to partial high beam region for left  headlamp    */
  HLAplusRegion_t  RegionPreced_Alive_right;     /* (only alive) preceding vehicle mapping to partial high beam region for right headlamp    */
   
  HLA_t_Object *pObjOncom_left;        /* (lost or alive) oncoming vehicle track pointer to the object which set eRegionOncom_left    */
                                              /* must not be the outer most !!!                                              */
  HLA_t_Object *pObjOncom_right;       /* (lost or alive) oncoming vehicle track pointer to the object which set eRegionOncom_right   */
                                              /* must not be the outer most !!!                                              */

  HLA_t_Object *pObjOncom_Alive_left;  /* (only alive) oncoming vehicle track pointer to the object which set eRegionOncom_left    */
                                              /* must not be the outer most !!!                                              */
  HLA_t_Object *pObjOncom_Alive_right; /* (only alive) oncoming vehicle track pointer to the object which set eRegionOncom_right   */
                                              /* must not be the outer most !!!                                              */
  
  HLA_t_Object *pObjPreced_left;       /* (lost or alive) preceding vehicle track pointer to the object which set eRegionPreced_left  */
                                              /* must not be the outer most !!!                                              */
  HLA_t_Object *pObjPreced_right;      /* (lost or alive) preceding vehicle track pointer to the object which set eRegionPreced_right */
                                              /* must not be the outer most !!!                                              */

  HLA_t_Object *pObjPreced_Alive_left; /* (only alive) preceding vehicle track pointer to the object which set eRegionPreced_left  */
                                              /* must not be the outer most !!!                                              */
  HLA_t_Object *pObjPreced_Alive_right;/* (only alive) preceding vehicle track pointer to the object which set eRegionPreced_right */
                                              /* must not be the outer most !!!                                              */
   
  float32           MaxTimeToAct_left_s;
  float32           MaxTimeToAct_right_s;
  float32           MinTimeToDeact_left_s;
  float32           MinTimeToDeact_right_s;
  HLA_t_Object      *pObj_MinTimeToDeact_left;
  HLA_t_Object      *pObj_MinTimeToDeact_right;

  uint8             PotOncoming_left;
  uint8             PotOncoming_right;

  float32           RelevantVehicle; /* maximum ttb of all vehicles */
    
}HLAplusObjRegionData_t;


/* enum for hla plus 2 high beam state */
typedef enum 
{
  /* High beam off ****************************************************************************/
  HLA_PLUS_HB_STATE_INIT           = 0u,            /*!< high beam off, init state                            */ 
  HLA_PLUS_HB_STATE_INIT_2_OFF     = 1u,            /*!< high beam off, coming from init state                */ 
  HLA_PLUS_HB_STATE_FULL_2_OFF     = 2u,            /*!< high beam off, coming from high beam on              */
  HLA_PLUS_HB_STATE_PART_2_OFF     = 3u,            /*!< high beam off, coming from partial High beam on      */
  HLA_PLUS_HB_STATE_OFF            = 4u,            /*!< high beam off                                        */
  /* (full) high beam on **********************************************************************/
  HLA_PLUS_HB_STATE_OFF_2_FULL_ON  = 5u,            /*!< high beam full on, coming from high beam off         */
  HLA_PLUS_HB_STATE_PART_2_FULL_ON = 6u,            /*!< high beam full on, coming from partial high beam on  */
  HLA_PLUS_HB_STATE_FULL_ON        = 7u,            /*!< high beam full on                                    */
  /* partial high beam on *********************************************************************/
  HLA_PLUS_HB_STATE_OFF_2_PART_ON  = 8u,            /*!< high beam partial on, coming from high beam off      */
  HLA_PLUS_HB_STATE_FULL_2_PART_ON = 9u,            /*!< high beam partial on, coming from high beam on       */
  HLA_PLUS_HB_STATE_PART_ON        = 10u            /*!< high beam partial on                                 */
} eHLAplusHBState_t;



/* enum for hla plus spot light state */

typedef enum 
{
  HLA_PLUS_SPOT_STATE_INIT           = 0u,         /*!< init state                                           */
  /* High beam off ******************************************************************************/
  HLA_PLUS_SPOT_STATE_SPOT_2_HB_OFF  = 1u,         /*!< high beam off, coming from spot support              */
  HLA_PLUS_SPOT_STATE_HB_OFF         = 2u,         /*!< high beam off                                        */
  /* (full) high beam on ************************************************************************/
  HLA_PLUS_SPOT_STATE_SPOT_2_FULL_ON = 3u,         /*!< high beam full on, coming from spot support          */
  HLA_PLUS_SPOT_STATE_FULL_ON        = 4u,         /*!< high beam full on                                    */
  /* partial high beam **************************************************************************/
  HLA_PLUS_SPOT_STATE_PART_ON        = 5u,         /*!< high beam partial on                                 */
  /* spot light support -> support the other TFL ************************************************/
  HLA_PLUS_SPOT_STATE_OFF_2_SPOT     = 6u,         /*!< right partial HB on, spot light switched on afterwards */
  HLA_PLUS_SPOT_STATE_SPOT_SUPPORT   = 7u          /*!< spot light support on                                */
} eHLAplusSpotState_t;



/* type definition for hla plus turn off reason for partial HB    */
/* dependent from left/ right headlamp                            */
/* -> turns full and partial HB off                               */
/* ~CodeReview ~ID:794f4483b0f0ad4041ce345559cdaed3 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   OncomingOnly              : 1;  /*!< only oncoming vehicles detected (no preceding vehicles) -> turn of left HB */
    uint32   AngOutermost2Large        : 1;  /*!< the (predicted) outer most angle is too large (e.g. > 15°)             */   
    uint32   OncomingDeactRegion       : 1;  /*!< oncoming traffic in right deactivation region -> left partial HB off   */
    uint32   OncLeftPrec               : 1;  /*!< turn off left partial HB because oncoming vehicle is detected on left side of the preceding car */
    uint32   TTD                       : 1;  /*!< deactivate partial HB in advance when TTD is small */
    uint32   RightOff                  : 1;  /*!< right hand traffic: deactivate left HB when right HB will be deactivated */
    uint32   dAng2Large                : 1;  /*!< left Partial HB wants to move more than 3° -> turn off left partial HB */
    uint32   Bit_07                    : 1;  /*!< Bit_07   */

    uint32   Oncoming                  : 1;  /*!< oncoming  traffic which deactivates full/ partial HB */
    uint32   Preceding                 : 1;  /*!< preceding traffic which deactivates full/ partial HB */
    uint32   MinSpeed                  : 1;  /*!< min activation speed */
    uint32   MayBeCity                 : 1;  /*!< HB on, vehicle detected may be city detected -> partial HB off because city will be detected in the next frames */
    uint32   Bit_12                    : 1;  /*!< Bit_12   */
    uint32   Bit_13                    : 1;  /*!< Bit_13   */
    uint32   Bit_14                    : 1;  /*!< Bit_14   */
    uint32   Bit_15                    : 1;  /*!< Bit_15   */

    uint32   Motorway                  : 1;  /*!< motorway: oncoming or preceding vehicle detected -> turn off left partial HB */
    uint32   Bit_17                    : 1;  /*!< Bit_17   */
    uint32   Bit_18                    : 1;  /*!< Bit_18   */
    uint32   Bit_19                    : 1;  /*!< Bit_19   */
    uint32   Bit_20                    : 1;  /*!< Bit_20   */
    uint32   Bit_21                    : 1;  /*!< Bit_21   */
    uint32   Bit_22                    : 1;  /*!< Bit_22   */
    uint32   Bit_23                    : 1;  /*!< Bit_23   */

    uint32   Bit_24                    : 1;  /*!< Bit_24   */
    uint32   Bit_25                    : 1;  /*!< Bit_25   */
    uint32   Bit_26                    : 1;  /*!< Bit_26   */
    uint32   Bit_27                    : 1;  /*!< Bit_27   */
    uint32   Bit_28                    : 1;  /*!< Bit_28   */
    uint32   Bit_29                    : 1;  /*!< Bit_29   */
    uint32   Bit_30                    : 1;  /*!< Bit_30   */
    uint32   Bit_31                    : 1;  /*!< Bit_31   */
  } Bit;
}HLAplusTurnOffReason_Reason_t;

/* ~CodeReview ~ID:f0f502fc6e641766a2ad8322b22aa237 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct 
{
  uint8   OncomingOnly;
  uint8   AngOutermost2Large;
  uint8   OncomingDeactRegion;
  uint8   OncLeftPrec;
  uint8   TTD;
  uint8   RightOff;
  uint8   dAng2Large;
  uint8   Cnt_07;

  uint8   Oncoming;
  uint8   Preceding;
  uint8   MinSpeed;
  uint8   MayBeCity;
  uint8   Cnt_12;
  uint8   Cnt_13;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   Motorway;
  uint8   Cnt_17;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;

  uint8   Cnt_24;
  uint8   Cnt_25;
  uint8   Cnt_26;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   Cnt_29;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAplusTurnOffReason_Cnt_t;

typedef struct
{
  HLAplusTurnOffReason_Reason_t  Reason;
  HLAplusTurnOffReason_Cnt_t     Cnt;
} HLAplusTurnOffReason_t;



/* type definition for hla plus 2  turn off reason for full HB    */
/* -> turns full HB off                                           */
/* ~CodeReview ~ID:7db367d091a1b3c1a0c15596d1eda08f ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   OncDetected               : 1;  /*!< relevant oncoming  traffic detected which deactivates full HB */
    uint32   PrecDetected              : 1;  /*!< relevant preceding traffic detected which deactivates full HB */   
    uint32   Bit_02                    : 1;  /*!< Bit_02   */
    uint32   Bit_03                    : 1;  /*!< Bit_03   */
    uint32   Bit_04                    : 1;  /*!< Bit_04   */
    uint32   Bit_05                    : 1;  /*!< Bit_05   */
    uint32   Bit_06                    : 1;  /*!< Bit_06   */
    uint32   Bit_07                    : 1;  /*!< Bit_07   */

    uint32   Bit_08                    : 1;  /*!< Bit_08 */
    uint32   Bit_09                    : 1;  /*!< Bit_09 */
    uint32   Bit_10                    : 1;  /*!< Bit_10   */
    uint32   Bit_11                    : 1;  /*!< Bit_11   */
    uint32   Bit_12                    : 1;  /*!< Bit_12   */
    uint32   Bit_13                    : 1;  /*!< Bit_13   */
    uint32   Bit_14                    : 1;  /*!< Bit_14   */
    uint32   Bit_15                    : 1;  /*!< Bit_15   */

    uint32   Bit_16                    : 1;  /*!< Bit_16   */
    uint32   Bit_17                    : 1;  /*!< Bit_17   */
    uint32   Bit_18                    : 1;  /*!< Bit_18   */
    uint32   Bit_19                    : 1;  /*!< Bit_19   */
    uint32   Bit_20                    : 1;  /*!< Bit_20   */
    uint32   Bit_21                    : 1;  /*!< Bit_21   */
    uint32   Bit_22                    : 1;  /*!< Bit_22   */
    uint32   Bit_23                    : 1;  /*!< Bit_23   */

    uint32   Bit_24                    : 1;  /*!< Bit_24   */
    uint32   Bit_25                    : 1;  /*!< Bit_25   */
    uint32   Bit_26                    : 1;  /*!< Bit_26   */
    uint32   Bit_27                    : 1;  /*!< Bit_27   */
    uint32   Bit_28                    : 1;  /*!< Bit_28   */
    uint32   Bit_29                    : 1;  /*!< Bit_29   */
    uint32   Bit_30                    : 1;  /*!< Bit_30   */
    uint32   Bit_31                    : 1;  /*!< Bit_31   */
  } Bit;
}HLAplusTurnOffReasonFullHB_Reason_t;

/* ~CodeReview ~ID:d46ceb709167f82ef2f2c61943fcddb1 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct 
{
  uint8   OncDetected;
  uint8   PrecDetected;
  uint8   Cnt_02;
  uint8   Cnt_03;
  uint8   Cnt_04;
  uint8   Cnt_05;
  uint8   Cnt_06;
  uint8   Cnt_07;

  uint8   Cnt_08;
  uint8   Cnt_09;
  uint8   Cnt_10;
  uint8   Cnt_11;
  uint8   Cnt_12;
  uint8   Cnt_13;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   Cnt_16;
  uint8   Cnt_17;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;

  uint8   Cnt_24;
  uint8   Cnt_25;
  uint8   Cnt_26;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   Cnt_29;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAplusTurnOffReasonFullHB_Cnt_t;

typedef struct
{
  HLAplusTurnOffReasonFullHB_Reason_t  Reason;
  HLAplusTurnOffReasonFullHB_Cnt_t     Cnt;
} HLAplusTurnOffReasonFullHB_t;


/* hla plus 2  keep off reason                    */
/* -> keeps only partial HB off (not full HB !!!) */
/* ~CodeReview ~ID:1f645255eb37b0eba079dfc47e8270d8 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   TimeToDeact            : 1;  /*!< Object is moving from ACT/HOLD to DEACT soon */
    uint32   TimeToBorder           : 1;  /*!< Object in DEACT is lost */   
    uint32   NoOncomingMinTime      : 1;  /*!< after last oncoming vehicle passed keep partial HB off for a minimal time */
    uint32   NoOncoming             : 1;  /*!< keep off HB until no oncoming traffic is detected anymore */
    uint32   OutermostLost          : 1;  /*!< outermost vehicle lost -> keep HB off */
    uint32   Bit_05                 : 1;  /*!< Bit_05 */
    uint32   Bit_06                 : 1;  /*!< Bit_06 */
    uint32   Bit_07                 : 1;  /*!< Bit_06 */
    
    uint32   NoVeh                  : 1;  /*!< no vehicles detected at all -> full HB will be switched on soon    */
                                          /*   do not switch part HB on -> wait until full HB will be switched on */      
    uint32   SpdAcc                 : 1;  /*!< velocity will fall below activation speed in less than 2 to 3 seconds */
    uint32   MaybeCity              : 1;  /*!< "maybe" city detected */
    uint32   minTimeOff             : 1;  /*!< keep partial HB off for a minimum time */
    uint32   Gap2Large              : 1;  /*!< gap between left and right partial HB is too large */
    uint32   TimeToDeactOther       : 1;  /*!< keep partial HB off if opposite partial HB will switch off in a certain time */
    uint32   PrecMinTimeInActRegion : 1;  /*!< preceding car stays minimal time in activation region (left and right) */
    uint32   OncMinTimeInActRegion  : 1;  /*!< oncoming car stays minimal time in activation region (left and right) */

    uint32   OncCoveredByPrec       : 1;  /*!< oncoming detected on the right side and is now covered by a preceding car -> wait until oncoming car is detected on the left side */
    uint32   OncWillLeaveFOV        : 1;  /*!< oncoming will leave the FOV in the next seconds, do not switch on partial HBs */
    uint32   Bit_18                 : 1;  /*!< Bit_18   */
    uint32   Bit_19                 : 1;  /*!< Bit_19   */
    uint32   Bit_20                 : 1;  /*!< Bit_20   */
    uint32   Bit_21                 : 1;  /*!< Bit_21   */
    uint32   Bit_22                 : 1;  /*!< Bit_22   */
    uint32   Bit_23                 : 1;  /*!< Bit_23   */

    /********************************************************************/
    /* partial HB will be switched on in the next cycle                 */
    /* check if there is any reason to refuse the partial HB            */
    /* e.g. potential oncoming vehicle in FOV                           */
    /* -> set penalty timer only once                                   */
    /*    when timer is elapsed and no other reason refuses partial HB  */
    /*  -> turn on partial HB                                           */
    /********************************************************************/
    /* synchronize left and right partial HB                            */
    /********************************************************************/
    uint32   PotentialOncomingDeact : 1;  /*!< Potential oncoming vehicle detected (deactivation/ hold region) */
    uint32   PotentialOncoming      : 1;  /*!< Potential oncoming vehicle detected (deactivation/ activation/ hold region) */
    uint32   Bit_26                 : 1;  /*!< Bit_26   */
    uint32   Bit_27                 : 1;  /*!< Bit_27   */
    uint32   Bit_28                 : 1;  /*!< Bit_28   */
    uint32   SyncSinglePrecCar      : 1;  /*!< synchronously partial HB on when only 1 or 2 preceding lights detected */
                                          /*!< synchronize left with right partial HB */  
    uint32   Wait4OtherPHB          : 1;  /*!< keep left partial HB off until right part.HB will be switched on */   
    uint32   Sync                   : 1;  /*!< synchronize the partial high beams (left <-> right) */
  } Bit;
}HLAplusKeepOffReasonPartHB_Reason_t;

/* ~CodeReview ~ID:19f89de5d66f53a67384c7dab3a8e3c3 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct
{
  uint8   TimeToDeact;
  uint8   TimeToBorder;
  uint8   NoOncomingMinTime;
  uint8   NoOncoming;
  uint8   OutermostLost;
  uint8   Cnt_05;
  uint8   Cnt_06;
  uint8   Cnt_07;
    
  uint8   NoVeh;
  uint8   SpdAcc;
  uint8   MaybeCity;
  uint8   minTimeOff;
  uint8   Gap2Large;
  uint8   TimeToDeactOther;
  uint8   PrecMinTimeInActRegion;
  uint8   OncMinTimeInActRegion;

  uint8   OncCoveredByPrec;
  uint8   OncWillLeaveFOV;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;
  
  uint8   PotentialOncomingDeact;
  uint8   PotentialOncoming;
  uint8   Cnt_26;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   SyncSinglePrecCar;
  uint8   Wait4OtherPHB;
  uint8   Sync;
} HLAplusKeepOffReasonPartHB_Cnt_t;

typedef struct
{
  HLAplusKeepOffReasonPartHB_Reason_t  Reason;
  HLAplusKeepOffReasonPartHB_Cnt_t     Cnt;

  /******************/
  /* turn on delay  */
  /******************/
  /* vehicle will run into deactivation region */
  float32                       TurnOnDelay_TTD_s;
  
  /* vehicle will run out of FOV */
  float32                       TurnOnDelay_TTBOnc_s;  /* oncoming car  */
  float32                       TurnOnDelay_TTBPrec_s; /* preceding car */
  
  /* potential oncoming in deactivation/ hold region */
  float32                       TurnOnDelay_PotOncomDeact_s;
  
  /* potential oncoming anywhere (deactivation/ activation/ hold region) */
  float32                       TurnOnDelay_PotOncom_s;
  
  /* delay to switch on partial HB after last oncoming vehicle is passed */
  float32                       TurnOnDelay_NoOncoming_s;

  /* low beam to partial HB */
  float32                       TurnOnDelay_Low2PartHB_s;
    
  /* oncoming covered by preceding car */
  float32                       TurnOnDelay_OncCoverdByPrec_s;
  
  /* Timer for oncoming vehicle will leave in the next cycles the FOV */
  float32                       TurnOnDelay_OncWillLeaveFOV_s;
  
  /**************************************************/
  /* maximum turn on delay over all keep off reason */
  /**************************************************/
  float32                       TurnOnDelay_Max_s;
} HLAplusKeepOffReasonPartHB_t;

/* hla plus 2  keep Full HB off reason   */
/* -> keeps only full HB off             */
/* ~CodeReview ~ID:974fa9155215c6d7a983b87df20996ea ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef union
{
  uint32  u32;
  struct {
    uint32   HB_Off              : 1;  /*!< HB off from old decision */
    uint32   minTimeOff          : 1;  /*!< minimum time low beam on before switching to full HB   */
    uint32   minTimePartOn       : 1;  /*!< minimum time partial HB on before switching to full HB */   
    uint32   Bit_03              : 1;  /*!< Bit_03   */
    uint32   Bit_04              : 1;  /*!< Bit_04   */
    uint32   Bit_05              : 1;  /*!< Bit_05   */
    uint32   Bit_06              : 1;  /*!< Bit_06   */
    uint32   Bit_07              : 1;  /*!< Bit_07   */

    uint32   Bit_08              : 1;  /*!< Bit_08   */
    uint32   Bit_09              : 1;  /*!< Bit_09   */
    uint32   Bit_10              : 1;  /*!< Bit_10   */
    uint32   Bit_11              : 1;  /*!< Bit_11   */
    uint32   Bit_12              : 1;  /*!< Bit_12   */
    uint32   Bit_13              : 1;  /*!< Bit_13   */
    uint32   Bit_14              : 1;  /*!< Bit_14   */
    uint32   Bit_15              : 1;  /*!< Bit_15   */

    uint32   Bit_16              : 1;  /*!< Bit_16   */
    uint32   Bit_17              : 1;  /*!< Bit_17   */
    uint32   Bit_18              : 1;  /*!< Bit_18   */
    uint32   Bit_19              : 1;  /*!< Bit_19   */
    uint32   Bit_20              : 1;  /*!< Bit_20   */
    uint32   Bit_21              : 1;  /*!< Bit_21   */
    uint32   Bit_22              : 1;  /*!< Bit_22   */
    uint32   Bit_23              : 1;  /*!< Bit_23   */

    uint32   Bit_24              : 1;  /*!< Bit_24   */
    uint32   Bit_25              : 1;  /*!< Bit_25   */
    uint32   Bit_26              : 1;  /*!< Bit_26   */
    uint32   Bit_27              : 1;  /*!< Bit_27   */
    uint32   Bit_28              : 1;  /*!< Bit_28   */
    uint32   Bit_29              : 1;  /*!< Bit_29   */
    uint32   Bit_30              : 1;  /*!< Bit_30   */
    uint32   Bit_31              : 1;  /*!< Bit_31   */
  } Bit;
}HLAplusKeepOffReasonFullHB_Reason_t;

/* ~CodeReview ~ID:e4c82db1f4088cd89b8055eb4f156c08 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct
{
  uint8   HB_Off;
  uint8   minTimeOff;
  uint8   minTimePartOn;
  uint8   Cnt_03;
  uint8   Cnt_04;
  uint8   Cnt_05;
  uint8   Cnt_06;
  uint8   Cnt_07;

  uint8   Cnt_08;
  uint8   Cnt_09;
  uint8   Cnt_10;
  uint8   Cnt_11;
  uint8   Cnt_12;
  uint8   Cnt_13;
  uint8   Cnt_14;
  uint8   Cnt_15;

  uint8   Cnt_16;
  uint8   Cnt_17;
  uint8   Cnt_18;
  uint8   Cnt_19;
  uint8   Cnt_20;
  uint8   Cnt_21;
  uint8   Cnt_22;
  uint8   Cnt_23;
  
  uint8   Cnt_24;
  uint8   Cnt_25;
  uint8   Cnt_26;
  uint8   Cnt_27;
  uint8   Cnt_28;
  uint8   Cnt_29;
  uint8   Cnt_30;
  uint8   Cnt_31;
} HLAplusKeepOffReasonFullHB_Cnt_t;

typedef struct
{
  HLAplusKeepOffReasonFullHB_Reason_t  Reason;
  HLAplusKeepOffReasonFullHB_Cnt_t     Cnt;

  /*****************/
  /* turn on delay */
  /*****************/
  /* low beam to full HB */
  float32 TurnOnDelay_Low2FullHB_left_s;
  float32 TurnOnDelay_Low2FullHB_right_s;
  /* partial to full HB */
  float32 TurnOnDelay_Part2FullHB_left_s;
  float32 TurnOnDelay_Part2FullHB_right_s;
  
} HLAplusKeepOffReasonFullHB_t;

/* enum for  */
typedef enum 
{
  HLA_PLUS_ANG_INIT   = 0u,          /*!< init state                             */ 
  /* vehicle detected */
  HLA_PLUS_ANG_INIT_TARGET = 1u,     /*!< vehicle detected the first time        */
  HLA_PLUS_ANG_RESUME_TARGET = 2u,   /*!< resume vehicle, target detected and lost and redetected again */
  HLA_PLUS_ANG_MOVE_INWARDS = 3u,    /*!< target moves inwards                   */
  HLA_PLUS_ANG_MOVE_OUTWARDS = 4u,   /*!< target moves outwards                  */
  HLA_PLUS_ANG_LOCKED_TARGET = 5u,   /*!< target angle reached and locked        */
  /* no vehicle detected */
  HLA_PLUS_ANG_KEEP_HBANG = 6u,      /*!< left partial HB off, right partial HB on   */
                                     /*!< -> do not change HB angles, wait for HB on or off */  
  HLA_PLUS_ANG_LOST_TARGET = 7u,     /*!< object lost, keep old HB angles for some cycles */
  HLA_PLUS_ANG_CLOSE_GAP = 8u,       /*!< no vehicle detected -> close gap       */
  HLA_PLUS_ANG_MOVE_2_CURVEANG = 9u, /*!< moving to curve angle                  */
  HLA_PLUS_ANG_FOLLOW_CURVEANG = 10u /*!< curve angle reached follow curve angle */
} eHLAplusHBAngState_t;

typedef struct
{
  /* absolute safety angle low pass filtered, WITH initial safety margin */
  float32 Ang_Min;
  float32 Ang_Max;

  /* safety angle low pass filtered, WITHOUT initial safety margin */
  float32 dAng_Min_lp;
  float32 dAng_Max_lp;
  /* safety angle unfiltered, WITHOUT initial safety margin */
  float32 dAng_Min_raw;
  float32 dAng_Max_raw;

  /* keep for defined cycles the initial safety angle */
  uint8 Safety_InitialCnt;
} HLAplusSafetyMargin_t;

/* enum for hla plus 2 high beam state */
typedef enum 
{
  HLA_PLUS_ANG_MINMAX_INIT = 0,
  HLA_PLUS_ANG_MINMAX_IDLE = 1,
  HLA_PLUS_ANG_MINMAX_RUNNING = 2
} eHLAplusHBAngMinMaxFilterState_t;

typedef struct
{
  /* HB angle limited due to curve angle */
  float32 HBAng_Min;
  float32 HBAng_Max;
  /* filter state */
  eHLAplusHBAngMinMaxFilterState_t eFilterState;
} HLAplusHBAngMinMax_t;

typedef struct
{
  float32   Ang_Raw;          /* [rad] high beam angle, raw value         */
  float32   Ang_LP;           /* [rad] high beam angle, low pass filtered */
  float32   FullHBCutOffAng;  /* [rad] cut off angle when full HB are switched on */
  float32   NoVehTargetAng;   /* [rad] no vehicle  */

  HLAplusSafetyMargin_t  SafetyMargin; /* safety margin */
  HLAplusHBAngMinMax_t   MinMax;       /* min/ max HB angle, e.g. curve limit */

  uint16    MoveCnt_Inwards;  /* target moves inwards:  counts number of cycles to reach the target angle position (within tolerances) */
  uint16    MoveCnt_Outwards; /* target moves outwards: counts number of cycles to reach the target angle position (within tolerances) */
  uint8     TargetReachedCnt; /* counts number of cycles the HB angle is within target tolerances               */

  float32   NoVehTimer_s; /* [s] no vehicles are detected since ... */

  uint16    StateCnt; /* cycles in current state */
  
  uint16    DelayCnt; /* delay counter */

  uint16    InitTargetCnt; /* cycles since last HLA_PLUS_ANG_INIT_TARGET state */

  eHLAplusHBAngState_t eState;      /* HB angle state */
  eHLAplusHBAngState_t eStatePrev;  /* HB angle state from previous cycle */
} HLAplusHBAngData_t;

typedef struct
{
  HLAplusHBAngData_t Left;   /* left high beam angle data  */
  HLAplusHBAngData_t Right;  /* right high beam angle data */
}HLAplusHBAng_t;

/* hla plus 2 decision  data */
typedef struct
{
  boolean             bSpotSupportOnHighway;      /* support support on highway is running */
  eHLAplusSpotState_t eSpotState;                 /* current spot light state */
  float32             SpotStateTimer_s;           /* spot state timer, this timer is used to stay for a certain time in a intermediate state  */
} HLAPlusSpotData_t;


typedef struct
{
  HLAplusTurnOffReason_t       Reason_Left;    /* turn off reason for left headlamp  like: ...  */
  HLAplusTurnOffReason_t       Reason_Right;   /* turn off reason for right headlamp like: ...  */
  HLAplusTurnOffReasonFullHB_t Reason_FullHB;  /* turn off reason for full high beam */

  uint8                         dA2L_DelayCnt_left;
  uint8                         dA2L_DelayCnt_right;
} HLAplusTurnOff_t;

typedef struct
{
  HLAplusKeepOffReasonPartHB_t  Reason_Left;    /* only partial HB: keep off reason for left  headlamp like: ...  */
  HLAplusKeepOffReasonPartHB_t  Reason_Right;   /* only partial HB: keep off reason for right headlamp like: ...  */
  HLAplusKeepOffReasonFullHB_t  Reason_FullHB;  /* keep off reason for full HB only */

  float32                       PartHB_SyncTimer_right_s; /* synchronize timer for partial high beam */
  float32                       PartHB_SyncTimer_left_s;  /* synchronize timer for partial high beam */  
  
  /* penalty timer */
  HLAFPenaltyTimer_t            PenaltyTimer_left;
  HLAFPenaltyTimer_t            PenaltyTimer_right;
} HLAplusKeepOff_t;

/* hla plus 2 decision  data */
typedef struct
{
  HLAFSpeed_t   Speed;
} HLAplusDecisionData_t;

typedef struct
{
  eHLAplusHBState_t    eState;     /* current high beam state */
  uint32               Cnt;        /* HB state counter, counts cycles since last HB state transition */
  eHLAplusHBState_t    eStatePrev; /* previous high beam state  (only transitions: off->partOn; off->fullOn; ... NOT: off->off; partOn->partOn) */
} HLAplusHBStateData_t;


typedef struct
{
  HLAplusHBStateData_t    Left;   /* left HB state data  */
  HLAplusHBStateData_t    Right;  /* right HB state data */
} HLAplusHBState_t;

 
/*! object status */
/* ~CodeReview ~ID:0dabb06c820941794600165197df1672 ~Reviewer:CW01\brunnm ~Date:16.07.2012 ~Priority:3 ~Comment:a lot of unused variables */
typedef struct
{
  uint32 isRelevantTraffic              : 1; /* relevant traffic -> turn off HB, change partial HB angle */
  uint32 isOutsideFunctRoi              : 1; /* traffic outside function roi                             */
  uint32 Bit_02                         : 1;
  uint32 Bit_03                         : 1;  
  uint32 Bit_04                         : 1;  
  uint32 Bit_05                         : 1;  
  uint32 Bit_06                         : 1;  
  uint32 Bit_07                         : 1;  

  uint32 Bit_08                         : 1;  
  uint32 Bit_09                         : 1;  
  uint32 Bit_10                         : 1;  
  uint32 Bit_11                         : 1;  
  uint32 Bit_12                         : 1;  
  uint32 Bit_13                         : 1;  
  uint32 Bit_14                         : 1;  
  uint32 Bit_15                         : 1;  

  uint32 Bit_16                         : 1;  
  uint32 Bit_17                         : 1;  
  uint32 Bit_18                         : 1;  
  uint32 Bit_19                         : 1;  
  uint32 Bit_20                         : 1;  
  uint32 Bit_21                         : 1;  
  uint32 Bit_22                         : 1;  
  uint32 Bit_23                         : 1;  

  uint32 Bit_24                         : 1;  
  uint32 Bit_25                         : 1;  
  uint32 Bit_26                         : 1;
  uint32 Bit_27                         : 1;  
  uint32 Bit_28                         : 1;  
  uint32 Bit_29                         : 1;  
  uint32 Bit_30                         : 1;  
  uint32 Bit_31                         : 1;  
} HLAplusObjectStatus_t;

/* headlamp depending object data */  
typedef struct 
{
  eHLAplusRegion_t      eObjRegion;           /* object in ACT_REGION, DEACT_REGION, HOLD_REGION                                  */

  float32               TimeToActRegion_s;    /* >    0 : object in deactivation region -> time to come into activation region    */
                                              /* == 100 : object will go deeper into deactivation region                          */
                                              /* ==   0 : object in activation region                                             */
  float32               TimeToDeactRegion_s;  /* >    0 : object in activation region -> time to come into deactivation region    */
                                              /* == 100 : object will go deeper into activation region                            */
                                              /* ==   0 : object in deactivation region                                           */
                                              
  HLAplusObjectStatus_t Status;
} HLAplusObjectData_t;

typedef struct 
{
  HLAplusObjectData_t Obj[RTE_HLAR_OBJECT_LIST_LENGTH];
  uint8               numRelevantVehicles;
  uint8               numRelevantVehiclesNextFrame;
} HLAplusObject_t;

typedef struct 
{
  HLAplusObject_t Left;   /* left headlamp  */
  HLAplusObject_t Right;  /* right headlamp */
} HLAplusObjectList_t;


typedef struct 
{
  sint16  Left;
  sint16  Right;
} HLAplusChangeOverLevel_t;

/* hla plus data */
typedef struct
{
  HLAplusObjectList_t       Object; /* additional object data */

  HLAplusDecisionData_t     DecisionData;     /* decision data */ 

  HLAplusTurnOff_t          TurnOff;          /* turn off reason */

  HLAplusKeepOff_t          KeepOff;          /* keep off reason */

  HLAplusOutermost_t        Outermost;        /* outermost vehicle data */

  HLAplusObjRegionData_t   Region;            /* vehicle mapping to partial high beam regions           */
                                              /* regions: deactivation, hold or activation region       */


  HLAplusHBState_t          HBState;          /* left/ right High beam state */  

  HLAplusHBAng_t            HBAngle;          /* left/ right high beam angle data  */

  HLAplusChangeOverLevel_t  ChangeOverLevel;  /* left/ right change over level */
  
  HLAPlusSpotData_t         SpotData;

  HLAFPlusOut_t             Out;              /* headlamp request for the next frame                      */
                                              /* traffic style normalized output (for right hand traffic) */
                                              /* for left hand driving the output must be mirrored !!!    */
} HLAplusData_t;



typedef struct
{
  uint8 TurnOffLeft_OncOnly; /* = 1: turn off left partial HB when only oncoming traffic is detected            */  
                             /*      or oncoming on left side of preceding car is detected                      */
                             /* = 0: turn off left partial HB when oncoming traffic is in deactivation region   */
                                        
  uint8 TurnOffLeft_LeftOnly;/* = 1: turn off left partial HB when right partial HB will be switched off        */
                             /* = 0: turn off left partial HB when object in deactivation region                */

  uint8 KeepOffLeft_LeftOnly;/* = 1: keep off left partial HB when right partial HB is off                      */
                             /* = 0: keep off left partial HB when object in deactivation region                */
  
  uint8 AsymmetricMode;      /* = 1: asymmetric mode is enabled                                                 */
                             /*      idea: switch left partial HB on when right partial HB will be switched off */
                             /*            and vice versa                                                       */ 
                             /* = 0: asymmetric mode disabled                                                   */
} HLAplusCfg_t;

/*************************/
/* HLA plus 2 Input Data */
/*************************/
typedef struct
{
  /* traffic style normalized angles !!! */
  /* -> normalized to right hand traffic */

  float32  OffsetAngle_left;       /* offset angle for activation/ deactivation region, left  side */
  float32  OffsetAngle_right;      /* offset angle for activation/ deactivation region, right side */
  
  float32  CurveLightAngle_left;   /* curve light angle from headlamps, left side  */
  float32  CurveLightAngle_right;  /* curve light angle from headlamps, right side */

  HLAplusCfg_t Cfg; /* configuration of HLA plus */
} HLAplusInputData_t;
/********************************/
/* END of HLA plus 2 Input Data */
/********************************/



/*****************************************************************************
  VARIABLES 
*****************************************************************************/
extern HLAplusData_t hlafPlusData;

/*****************************************************************************
  FUNCTION 
*****************************************************************************/
void HLAFPlusInit(HLAFPlusOut_t *pPlusOut);

void HLAFPlusMain( /* input */
                   const HLAF_t_RequiredInputs            *ps_In,
                   const HLAFData_t                       *pFData,
                   const HLAFParameter_t *pFPar, 
                   /* output */ 
                   HLAFPlusOut_t                          *pPlusOut
                 );

void HLAFPlusExit(void);

void HLAFPlusMeasfreeze(AS_t_MeasHdlr pfMeasFreeze);


/* avoid cyclic binding ---------------------------------------------------*/
#endif
