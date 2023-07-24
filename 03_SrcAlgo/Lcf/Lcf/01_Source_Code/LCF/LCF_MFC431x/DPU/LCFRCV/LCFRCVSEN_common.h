/*! \file **********************************************************************

  TEMPLATE VERSION:          1.2
                             changed parameters in cpp version to be a struct/class
                             added version management for template

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH

  PROJECT:                   MFC4xx

  CPU:                       CPU-Independent

  COMPONENT:                 Lcf

  MODULNAME:                 LCFRCVSEN_common.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.8.1.6 $


  ---*/ /*--- 
  CHANGES:                   $Log: LCFRCVSEN_common.h  $
  CHANGES:                   Revision 1.8.1.6 2020/02/21 12:50:25CET Craciun, Mihaela (uidl9730) (uidl9730) 
  CHANGES:                   Updates after qaf report
  CHANGES:                   Revision 1.8.1.4 2019/12/18 15:54:39CET Nastasa, Elena (uidt4846) 
  CHANGES:                   update wraper for TSA State
  CHANGES:                   Revision 1.8.1.3 2019/08/21 13:11:54CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF wrappers afer workshop review
  CHANGES:                   Revision 1.8.1.2 2019/07/31 14:13:32CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint 10.05
  CHANGES:                   Revision 1.8.1.1 2019/06/07 08:36:41CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update files for Sprint 05.10.01 on LCF variant
  CHANGES:                   Revision 1.8 2019/05/30 13:25:59CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Correct wrapers for ports checks and HLA
  CHANGES:                   Revision 1.7 2019/05/29 08:57:57CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update for AlmostZero parameter
  CHANGES:                   Revision 1.6 2019/05/22 13:47:34CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update LCF for Sprint10
  CHANGES:                   Revision 1.4 2019/05/16 13:32:51CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Remove LD port from wrappers
  CHANGES:                   Revision 1.3 2019/05/15 07:55:58CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrapers for new input signals
  CHANGES:                   Revision 1.2 2019/05/06 16:33:13CEST Nastasa, Elena (uidt4846) 
  CHANGES:                   Update wrappers for new RTE
  CHANGES:                   Revision 1.1 2019/03/24 17:37:14CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/03/24 08:39:32CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Projects/MFC431x/MFC431/DPU/04_Engineering/01_Source_Code/LCF/LCF_MFC431x/DPU/LCFRCV/project.pj
  CHANGES:                   Revision 1.1 2019/02/19 13:54:31CET Asong, Wedndah Asaha (uidj2187) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Components/LCF_LateralControlFunctions/04_Engineering/01_Source_Code/LCF/LCF_MFC/DPU/LCFRCV/project.pj

**************************************************************************** */

#ifndef LCFRCVSEN_COMMON_H_
#define LCFRCVSEN_COMMON_H_

/*---------------------------------------------------------*
   I N C L U D E S
**---------------------------------------------------------*/

#include "LCFERR/LCFERR_SenCustom.h"
#include "LCFERR/lcferr_sen.h"
#include "LCFERR/ERRIO_SenCustom.h"
#include "LCFERR/errio_sen.h"

/*---------------------------------------------------------*
   S T R U C T U R E S
 *---------------------------------------------------------*/

typedef struct
{
	float32 T_LCFRCV_VehVelX_mps;
	const s_LD_Event_t	*apsLaneEvents[4];
} LCFRCV_SenCommonOutType;

/*---------------------------------------------------------*
   F U N C T I O N   P R O T O T Y P E S
**---------------------------------------------------------*/

extern const LCFRCV_SenCommonOutType* Get_LCFRCV_SenCommonOutPtr(void);
extern void  LCFRCV_SenCommonReset  (void);
extern void  LCFRCV_SenCommonProcess(void);

/*---------------------------------------------------------*
   E X T E R N A L   V A R I A B L E S
**---------------------------------------------------------*/
extern volatile uint8 P_LCF_SENCopyVDY2LCFParam_bool; /*Parameter to switch between VDY and LCF values*/

/*---------------------------------------------------------*
   M A C R O S
**---------------------------------------------------------*/
#ifndef LCF_IO_POS_RDWSW /* Must be deleted */
#define LCF_IO_POS_RDWSW LCF_IO_POS_NotAvailable
#endif

/*RO 863759*/
#define T_LCFRCV_AnyBndRoadWorks_btf     (uint8)( ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_MULTIPLE_MARKER) << 0)| \
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_LEFT_BARRIER) << 1) |\
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_RIGHT_BARRIER) << 2)|\
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_CROSSING_MARKER) << 3)|\
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_INHIBIT_SINGLE_LINE) << 4)|\
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_MARKER_COLOR_CHANGE) << 5)|\
                                                  ((pLcfSenReqPorts->pAbdOutputData->sConstructionSite.CS_HOLD) << 6) )
                                                  
/*RO 946177 for the Left side*/
#define T_LCFRCV_IndexLaneBdnLeft_0             (pLcfSenReqPorts->pAbdOutputData->sLaneInformation.aiLaneBoundariesLeft[0]) /*Store the index: aiLaneBoundariesLeft[0] .. Left Ego Lane Boundary*/
#define T_LCFRCV_FeatureCoordsXYLe_met(i)       (pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[T_LCFRCV_IndexLaneBdnLeft_0].sGeometry.sPolygon.afPointCoordinatesYMeter[i])

/*RO 946177 for the Right side*/
#define T_LCFRCV_IndexLaneBdnRight_0            (pLcfSenReqPorts->pAbdOutputData->sLaneInformation.aiLaneBoundariesRight[0]) /*Store the index: aiLaneBoundariesRight[0] .. Right Ego Lane Boundary*/
#define T_LCFRCV_FeatureCoordsXYRi_met(i)       (pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[T_LCFRCV_IndexLaneBdnRight_0].sGeometry.sPolygon.afPointCoordinatesYMeter[i])


/* -------------- SEN Generic Inputs( LCF_GenericInputs_t* pLcfInputData; ) -------------- */
#ifndef	S_LCFRCV_ActiveStateEBA_enum
#define S_LCFRCV_ActiveStateEBA_enum    	(pLcfSenReqPorts->pLcfInputData->EBA_ActiveState_nu)
#define GET_S_LCFRCV_ActiveStateEBA_enum()	S_LCFRCV_ActiveStateEBA_enum
#endif

#ifndef	S_LCFRCV_ActiveStCtrlEBA_bool
#define S_LCFRCV_ActiveStCtrlEBA_bool	 	(pLcfSenReqPorts->pLcfInputData->EBA_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING))
#define GET_S_LCFRCV_ActiveStCtrlEBA_bool()	S_LCFRCV_ActiveStCtrlEBA_bool
#endif

#ifndef	S_LCFRCV_SystemStateEBA_enum
#define S_LCFRCV_SystemStateEBA_enum		(pLcfSenReqPorts->pLcfInputData->EBA_SystemState_nu)
#define GET_S_LCFRCV_SystemStateEBA_enum()	S_LCFRCV_SystemStateEBA_enum
#endif

#ifndef	S_LCFRCV_SysStAvailableEBA_bool
#define S_LCFRCV_SysStAvailableEBA_bool			(pLcfSenReqPorts->pLcfInputData->EBA_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE))
#define GET_S_LCFRCV_SysStAvailableEBA_bool()	S_LCFRCV_SysStAvailableEBA_bool
#endif

#ifndef	S_LCFRCV_SysStErrorEBA_bool
#define S_LCFRCV_SysStErrorEBA_bool	 		(pLcfSenReqPorts->pLcfInputData->EBA_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR))
#define GET_S_LCFRCV_SysStErrorEBA_bool()	S_LCFRCV_SysStErrorEBA_bool
#endif

#ifndef	S_LCFRCV_AccFRObjDetected_bool
#define	S_LCFRCV_AccFRObjDetected_bool			(pLcfSenReqPorts->pLcfInputData->TJATargetObject.SelectedTargetObjDetected_nu)
#define GET_S_LCFRCV_AccFRObjDetected_bool()	S_LCFRCV_AccFRObjDetected_bool
#endif

#ifndef	S_LCFRCV_AccFRObjID_nu
#define	S_LCFRCV_AccFRObjID_nu			(pLcfSenReqPorts->pLcfInputData->TJATargetObject.ObjRecognExtendedQualifier_nu)
#define GET_S_LCFRCV_AccFRObjID_nu()		S_LCFRCV_AccFRObjID_nu
#endif

#ifndef	S_LCFRCV_AccFRObjQuality_perc
#define	S_LCFRCV_AccFRObjQuality_perc		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.ObjQuality_nu)
#define	GET_S_LCFRCV_AccFRObjQuality_perc()	S_LCFRCV_AccFRObjQuality_perc
#endif

#ifndef	S_LCFRCV_AccFRObjMeasState_nu
#define	S_LCFRCV_AccFRObjMeasState_nu		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.ObjRecognMeasState_nu)
#define	GET_S_LCFRCV_AccFRObjMeasState_nu()	S_LCFRCV_AccFRObjMeasState_nu
#endif

#ifndef	S_LCFRCV_AccFRObjPosX_met
#define	S_LCFRCV_AccFRObjPosX_met		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.PositionPosX_m)
#define	GET_S_LCFRCV_AccFRObjPosX_met()	S_LCFRCV_AccFRObjPosX_met
#endif

#ifndef	S_LCFRCV_AccFRObjPosY_met
#define	S_LCFRCV_AccFRObjPosY_met		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.PositionPosY_m)
#define	GET_S_LCFRCV_AccFRObjPosY_met()	S_LCFRCV_AccFRObjPosY_met
#endif

#ifndef	S_LCFRCV_AccFRObjWidth_met
#define	S_LCFRCV_AccFRObjWidth_met          (pLcfSenReqPorts->pLcfInputData->TJATargetObject.DimensionsWidth_m)
#define	GET_S_LCFRCV_AccFRObjWidth_met()	S_LCFRCV_AccFRObjWidth_met
#endif

#ifndef	S_LCFRCV_AccFRObjRelVelX_mps
#define	S_LCFRCV_AccFRObjRelVelX_mps		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.MovementRelVelX_mps)
#define	GET_S_LCFRCV_AccFRObjRelVelX_mps()	S_LCFRCV_AccFRObjRelVelX_mps
#endif

#ifndef	S_LCFRCV_AccFRObjRelVelY_mps
#define	S_LCFRCV_AccFRObjRelVelY_mps		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.MovementRelVelY_mps)
#define	GET_S_LCFRCV_AccFRObjRelVelY_mps()	S_LCFRCV_AccFRObjRelVelY_mps
#endif

#ifndef	S_LCFRCV_AccFRObjRelAclX_mps2
#define	S_LCFRCV_AccFRObjRelAclX_mps2		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.MovementRelAclX_mps2)
#define	GET_S_LCFRCV_AccFRObjRelAclX_mps2()	S_LCFRCV_AccFRObjRelAclX_mps2
#endif

#ifndef	S_LCFRCV_AccFRObjRelAclY_mps2
#define	S_LCFRCV_AccFRObjRelAclY_mps2		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.MovementRelAclY_mps2)
#define	GET_S_LCFRCV_AccFRObjRelAclY_mps2()	S_LCFRCV_AccFRObjRelAclY_mps2
#endif

#ifndef	S_LCFRCV_AccFRObjClassType_nu
#define	S_LCFRCV_AccFRObjClassType_nu		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.ObjRecognClassType_nu)
#define	GET_S_LCFRCV_AccFRObjClassType_nu()	S_LCFRCV_AccFRObjClassType_nu
#endif

#ifndef	S_LCFRCV_AccFRObjSensorSource_btf
#define	S_LCFRCV_AccFRObjSensorSource_btf		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.SensorSource_nu)
#define	GET_S_LCFRCV_AccFRObjSensorSource_btf()	S_LCFRCV_AccFRObjSensorSource_btf
#endif

#ifndef	S_LCFRCV_AccFRObjPosXStdDev_met
#define	S_LCFRCV_AccFRObjPosXStdDev_met         (pLcfSenReqPorts->pLcfInputData->TJATargetObject.PositionPosXStdDev_m)
#define	GET_S_LCFRCV_AccFRObjPosXStdDev_met()	S_LCFRCV_AccFRObjPosXStdDev_met
#endif

#ifndef	S_LCFRCV_AccFRObjPosYStdDev_met
#define	S_LCFRCV_AccFRObjPosYStdDev_met         (pLcfSenReqPorts->pLcfInputData->TJATargetObject.PositionPosYStdDev_m)
#define	GET_S_LCFRCV_AccFRObjPosYStdDev_met()	S_LCFRCV_AccFRObjPosYStdDev_met
#endif

#ifndef	S_LCFRCV_AccFRObjTStamp_usec
#define	S_LCFRCV_AccFRObjTStamp_usec		(pLcfSenReqPorts->pLcfInputData->TJATargetObject.Tstamp_us)
#define	GET_S_LCFRCV_AccFRObjTStamp_usec()	S_LCFRCV_AccFRObjTStamp_usec
#endif

#ifndef	S_LCFRCV_LKASwitch_nu
#define	S_LCFRCV_LKASwitch_nu		(pLcfSenReqPorts->pLcfInputData->LKAMainSwitch_nu)  /* Checked*/
#define GET_S_LCFRCV_LKASwitch_nu()	S_LCFRCV_LKASwitch_nu
#endif

#ifndef	S_LCFRCV_TJASwitch_nu
#define	S_LCFRCV_TJASwitch_nu		(pLcfSenReqPorts->pLcfInputData->TJAMainSwitch_nu) /* Checked*/
#define GET_S_LCFRCV_TJASwitch_nu()	S_LCFRCV_TJASwitch_nu
#endif

#ifndef	S_LCFRCV_LDWSwitch_bool
#define S_LCFRCV_LDWSwitch_bool			(pLcfSenReqPorts->pLcfInputData->LDWSwitch_nu) /* Checked*/
#define GET_S_LCFRCV_LDWSwitch_bool()	S_LCFRCV_LDWSwitch_bool
#endif
 
#ifndef	S_LCFRCV_AoLCSwitch_nu
#define S_LCFRCV_AoLCSwitch_nu			(pLcfSenReqPorts->pLcfInputData->AoLCSwitch_nu) 
#define GET_S_LCFRCV_AoLCSwitch_nu()	S_LCFRCV_AoLCSwitch_nu
#endif

#ifndef	S_LCFRCV_LDWOCSwitch_bool
#define S_LCFRCV_LDWOCSwitch_bool			(pLcfSenReqPorts->pLcfInputData->LDWOncomingSwitch_nu) 
#define GET_S_LCFRCV_LDWOCSwitch_bool()	S_LCFRCV_LDWOCSwitch_bool
#endif	

#ifndef	S_LCFRCV_LDPSwitch_bool
#define S_LCFRCV_LDPSwitch_bool			(pLcfSenReqPorts->pLcfInputData->LDPSwitch_nu) /* Checked*/
#define GET_S_LCFRCV_LDPSwitch_bool()	S_LCFRCV_LDPSwitch_bool
#endif

#ifndef	S_LCFRCV_LDPOCSwitch_bool
#define S_LCFRCV_LDPOCSwitch_bool		(pLcfSenReqPorts->pLcfInputData->LDPOncomingSwitch_nu)  /* Checked*/
#define GET_S_LCFRCV_LDPOCSwitch_bool()	S_LCFRCV_LDPOCSwitch_bool
#endif

#ifndef	S_LCFRCV_ALCASwitch_bool
#define S_LCFRCV_ALCASwitch_bool		(pLcfSenReqPorts->pLcfInputData->ALCASwitch_nu) /* Checked*/
#define GET_S_LCFRCV_ALCASwitch_bool()	S_LCFRCV_ALCASwitch_bool
#endif

#ifndef	S_LCFRCV_RDWSwitch_bool
#define S_LCFRCV_RDWSwitch_bool			(pLcfSenReqPorts->pLcfInputData->RDWSwitch_nu) 
#define GET_S_LCFRCV_RDWSwitch_bool()	S_LCFRCV_RDWSwitch_bool
#endif

#ifndef	S_LCFRCV_RDPSwitch_bool
#define S_LCFRCV_RDPSwitch_bool			(pLcfSenReqPorts->pLcfInputData->RDPSwitch_nu) /* Checked*/
#define GET_S_LCFRCV_RDPSwitch_bool()	S_LCFRCV_RDPSwitch_bool
#endif

#ifndef	S_LCFRCV_LDWMode_nu
#define S_LCFRCV_LDWMode_nu			(pLcfSenReqPorts->pLcfInputData->LDWSensitivity_nu) /* Checked*/
#define GET_S_LCFRCV_LDWMode_nu()	S_LCFRCV_LDWMode_nu
#endif

#ifndef	S_LCFRCV_LDPMode_nu
#define S_LCFRCV_LDPMode_nu			(pLcfSenReqPorts->pLcfInputData->LDPSensitivity_nu) /* Checked*/
#define GET_S_LCFRCV_LDPMode_nu()	S_LCFRCV_LDPMode_nu
#endif

#ifndef	S_LCFRCV_LDPOCMode_nu
#define S_LCFRCV_LDPOCMode_nu			(pLcfSenReqPorts->pLcfInputData->LDPOCSensitivity_nu) /* Checked*/
#define GET_S_LCFRCV_LDPOCMode_nu()	S_LCFRCV_LDPOCMode_nu
#endif

#ifndef	S_LCFRCV_RDPMode_nu
#define S_LCFRCV_RDPMode_nu			(pLcfSenReqPorts->pLcfInputData->RDPSensitivity_nu) /* Checked*/
#define GET_S_LCFRCV_RDPMode_nu()	S_LCFRCV_RDPMode_nu
#endif

#ifndef	S_LCFRCV_RDWMode_nu
#define S_LCFRCV_RDWMode_nu			(pLcfSenReqPorts->pLcfInputData->RDPSensitivity_nu) /* Checked*/
#define GET_S_LCFRCV_RDWMode_nu()	S_LCFRCV_RDWMode_nu
#endif
 
#ifndef	S_LCFRCV_LDWOCSensitivity_nu
#define S_LCFRCV_LDWOCSensitivity_nu			(pLcfSenReqPorts->pLcfInputData->LDWOCSensitivity_nu) 
#define GET_S_LCFRCV_LDWOCSensitivity_nu()	S_LCFRCV_LDWOCSensitivity_nu
#endif

#ifndef	S_LCFRCV_RDWSensitivity_nu
#define S_LCFRCV_RDWSensitivity_nu			(pLcfSenReqPorts->pLcfInputData->RDWSensitivity_nu) 
#define GET_S_LCFRCV_RDWSensitivity_nu()	S_LCFRCV_RDWSensitivity_nu
#endif	

#ifndef	S_LCFRCV_LDPMode_nu
#define S_LCFRCV_LDPMode_nu			(pLcfSenReqPorts->pLcfInputData->LDPMode_nu) 
#define GET_S_LCFRCV_LDPMode_nu()	S_LCFRCV_LDPMode_nu
#endif

#ifndef	S_LCFRCV_LDWMode_nu
#define S_LCFRCV_LDWMode_nu			(pLcfSenReqPorts->pLcfInputData->LDWMode_nu) 
#define GET_S_LCFRCV_LDWMode_nu()	S_LCFRCV_LDWMode_nu
#endif

#ifndef	S_LCFRCV_RDPMode_nu
#define S_LCFRCV_RDPMode_nu			(pLcfSenReqPorts->pLcfInputData->RDPMode_nu) 
#define GET_S_LCFRCV_RDPMode_nu()	S_LCFRCV_RDPMode_nu
#endif

#ifndef	S_LCFRCV_RDWMode_nu
#define S_LCFRCV_RDWMode_nu			(pLcfSenReqPorts->pLcfInputData->RDWMode_nu) 
#define GET_S_LCFRCV_RDWMode_nu()	S_LCFRCV_RDWMode_nu
#endif

#ifndef	S_LCFRCV_LDPOCMode_nu
#define S_LCFRCV_LDPOCMode_nu			(pLcfSenReqPorts->pLcfInputData->LDPOCMode_nu) 
#define GET_S_LCFRCV_LDPOCMode_nu()	S_LCFRCV_LDPOCMode_nu
#endif

#ifndef	S_LCFRCV_LDWOCMode_nu
#define S_LCFRCV_LDWOCMode_nu			(pLcfSenReqPorts->pLcfInputData->LDWOCMode_nu) 
#define GET_S_LCFRCV_LDWOCMode_nu()	S_LCFRCV_LDWOCMode_nu
#endif

#ifndef	S_LCFRCV_AoLCMode_nu
#define S_LCFRCV_AoLCMode_nu			(pLcfSenReqPorts->pLcfInputData->AoLCMode_nu) 
#define GET_S_LCFRCV_AoLCMode_nu()	S_LCFRCV_AoLCMode_nu
#endif

#ifndef	S_LCFRCV_DoorOpen_bool
#define S_LCFRCV_DoorOpen_bool			(pLcfSenReqPorts->pLcfInputData->DoorOpen_nu) /* Checked*/
#define GET_S_LCFRCV_DoorOpen_bool()	S_LCFRCV_DoorOpen_bool
#endif

#ifndef	S_LCFRCV_DriverNotBuckledUp_bool
#define S_LCFRCV_DriverNotBuckledUp_bool    	(pLcfSenReqPorts->pLcfInputData->DriverNotBuckledUp_nu)  /* Checked*/
#define GET_S_LCFRCV_DriverNotBuckledUp_bool()	S_LCFRCV_DriverNotBuckledUp_bool
#endif

#ifndef	S_LCFRCV_RollerBenchDetected_bool
#define S_LCFRCV_RollerBenchDetected_bool   	(pLcfSenReqPorts->pLcfInputData->DynamometerTestBenchDetected_nu) /* Checked*/
#define GET_S_LCFRCV_RollerBenchDetected_bool()	S_LCFRCV_RollerBenchDetected_bool
#endif

#ifndef	S_LCFRCV_SteerWAngleRate_degps
#define	S_LCFRCV_SteerWAngleRate_degps			((pLcfSenReqPorts->pLcfInputData->SteerHandWheelAngleRate_rps)*CONV_RAD2DEG) /* Checked*/
#define GET_S_LCFRCV_SteerWAngleRate_degps()	S_LCFRCV_SteerWAngleRate_degps
#endif

#ifndef	S_LCFRCV_SteerWAngle_deg
#define	S_LCFRCV_SteerWAngle_deg		((pLcfSenReqPorts->pLcfInputData->SteerHandWheelAngle_rad)*CONV_RAD2DEG) /*Checked*/
#define GET_S_LCFRCV_SteerWAngle_deg()	S_LCFRCV_SteerWAngle_deg
#endif

/*Temporary solution until ISSUE 882838*/
#ifndef	S_LCFRCV_SteerWAngle_rad
#define	S_LCFRCV_SteerWAngle_rad		(pLcfSenReqPorts->pLcfInputData->SteerHandWheelAngle_rad) /* Checked*/
#define GET_S_LCFRCV_SteerWAngle_rad()	S_LCFRCV_SteerWAngle_rad
#endif

#ifndef	S_LCFRCV_TurnSignalLeverHold_bool
#define S_LCFRCV_TurnSignalLeverHold_bool	(pLcfSenReqPorts->pLcfInputData->TurnSignalLever_nu == ((uint8)LCF_TURN_LEVER_ENGAGED)) /* Checked*/
#define GET_S_LCFRCV_TurnSignalLeverHold_bool()	S_LCFRCV_TurnSignalLeverHold_bool
#endif

#ifndef	S_LCFRCV_VehReadyToStart_bool
#define S_LCFRCV_VehReadyToStart_bool       (pLcfSenReqPorts->pLcfInputData->VehicleReadyState_nu) /* Checked*/
#define GET_S_LCFRCV_VehReadyToStart_bool()	S_LCFRCV_VehReadyToStart_bool
#endif

#ifndef	S_LCFRCV_EPS_ManualTrqActualVal_Nm
#define S_LCFRCV_EPS_ManualTrqActualVal_Nm			(pLcfSenReqPorts->pLcfInputData->DrvSteerWheelTrq_nm) /* Checked*/
#define GET_S_LCFRCV_EPS_ManualTrqActualVal_Nm()	S_LCFRCV_EPS_ManualTrqActualVal_Nm
#endif

#ifndef	S_LCFRCV_OversteeringDetected_bool
#define S_LCFRCV_OversteeringDetected_bool			(pLcfSenReqPorts->pLcfInputData->OversteeringDetected_nu) /* Checked*/
#define GET_S_LCFRCV_OversteeringDetected_bool()	S_LCFRCV_OversteeringDetected_bool
#endif

#ifndef	S_LCFRCV_UndersteeringDetected_bool
#define S_LCFRCV_UndersteeringDetected_bool			(pLcfSenReqPorts->pLcfInputData->UndersteeringDetected_nu)  /* Checked*/
#define GET_S_LCFRCV_UndersteeringDetected_bool()	S_LCFRCV_UndersteeringDetected_bool
#endif

#ifndef	S_LCFRCV_ActiveStateABS_enum
#define S_LCFRCV_ActiveStateABS_enum    	(pLcfSenReqPorts->pLcfInputData->ABS_ActiveState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_ActiveStateABS_enum()	S_LCFRCV_ActiveStateABS_enum
#endif

#ifndef	S_LCFRCV_ActiveStateACC_enum
#define S_LCFRCV_ActiveStateACC_enum    	(pLcfSenReqPorts->pLcfInputData->ACC_ActiveState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_ActiveStateACC_enum()	S_LCFRCV_ActiveStateACC_enum
#endif

#ifndef	S_LCFRCV_ActiveStateESC_enum
#define S_LCFRCV_ActiveStateESC_enum    	(pLcfSenReqPorts->pLcfInputData->ESC_ActiveState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_ActiveStateESC_enum()	S_LCFRCV_ActiveStateESC_enum
#endif

#ifndef	S_LCFRCV_ActiveStateTCS_enum
#define S_LCFRCV_ActiveStateTCS_enum    	(pLcfSenReqPorts->pLcfInputData->TCS_ActiveState_nu)  /* Checked, not used*/
#define GET_S_LCFRCV_ActiveStateTCS_enum()	S_LCFRCV_ActiveStateTCS_enum
#endif

#ifndef	S_LCFRCV_ActiveStateVSM_enum
#define S_LCFRCV_ActiveStateVSM_enum    	(pLcfSenReqPorts->pLcfInputData->VSM_ActiveState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_ActiveStateVSM_enum()	S_LCFRCV_ActiveStateVSM_enum
#endif

#ifndef	S_LCFRCV_ActiveStateTSA_enum
#define S_LCFRCV_ActiveStateTSA_enum    	(pLcfSenReqPorts->pLcfInputData->TSA_ActiveState_nu) 
#define GET_S_LCFRCV_ActiveStateTSA_enum()	S_LCFRCV_ActiveStateTSA_enum
#endif 

#ifndef	S_LCFRCV_ActiveStCtrlABS_bool
#define S_LCFRCV_ActiveStCtrlABS_bool	 	(pLcfSenReqPorts->pLcfInputData->ABS_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) /* Checked*/
#define GET_S_LCFRCV_ActiveStCtrlABS_bool()	S_LCFRCV_ActiveStCtrlABS_bool
#endif

#ifndef	S_LCFRCV_ActiveStCtrlACC_bool
#define S_LCFRCV_ActiveStCtrlACC_bool	 	(pLcfSenReqPorts->pLcfInputData->ACC_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) /* Checked*/
#define GET_S_LCFRCV_ActiveStCtrlACC_bool()	S_LCFRCV_ActiveStCtrlACC_bool
#endif

#ifndef	S_LCFRCV_ActiveStCtrlESC_bool
#define S_LCFRCV_ActiveStCtrlESC_bool	 	(pLcfSenReqPorts->pLcfInputData->ESC_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) /* Checked*/
#define GET_S_LCFRCV_ActiveStCtrlESC_bool()	S_LCFRCV_ActiveStCtrlESC_bool
#endif

#ifndef	S_LCFRCV_ActiveStCtrlTCS_bool
#define S_LCFRCV_ActiveStCtrlTCS_bool	 	(pLcfSenReqPorts->pLcfInputData->TCS_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) /* Checked*/
#define GET_S_LCFRCV_ActiveStCtrlTCS_bool()	S_LCFRCV_ActiveStCtrlTCS_bool
#endif

#ifndef	S_LCFRCV_ActiveStCtrlVSM_bool
#define S_LCFRCV_ActiveStCtrlVSM_bool	 	(pLcfSenReqPorts->pLcfInputData->VSM_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) /* Checked*/
#define GET_S_LCFRCV_ActiveStCtrlVSM_bool()	S_LCFRCV_ActiveStCtrlVSM_bool
#endif

#ifndef	S_LCFRCV_ActiveStCtrlTSA_bool
#define S_LCFRCV_ActiveStCtrlTSA_bool    	(pLcfSenReqPorts->pLcfInputData->TSA_ActiveState_nu == ((uint8)LCF_ACTIVITY_CONTROLLING)) 
#define GET_S_LCFRCV_ActiveStCtrlTSA_bool()	S_LCFRCV_ActiveStCtrlTSA_bool
#endif 

#ifndef	S_LCFRCV_SystemStateABS_enum
#define S_LCFRCV_SystemStateABS_enum		(pLcfSenReqPorts->pLcfInputData->ABS_SystemState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_SystemStateABS_enum()	S_LCFRCV_SystemStateABS_enum
#endif

#ifndef	S_LCFRCV_SystemStateACC_enum
#define S_LCFRCV_SystemStateACC_enum		(pLcfSenReqPorts->pLcfInputData->ACC_SystemState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_SystemStateACC_enum()	S_LCFRCV_SystemStateACC_enum
#endif

#ifndef	S_LCFRCV_SystemStateESC_enum
#define S_LCFRCV_SystemStateESC_enum		(pLcfSenReqPorts->pLcfInputData->ESC_SystemState_nu) /*Checked, not used*/
#define GET_S_LCFRCV_SystemStateESC_enum()	S_LCFRCV_SystemStateESC_enum
#endif

#ifndef	S_LCFRCV_SystemStateTCS_enum
#define S_LCFRCV_SystemStateTCS_enum		(pLcfSenReqPorts->pLcfInputData->TCS_SystemState_nu) /* Checked, not used*/
#define GET_S_LCFRCV_SystemStateTCS_enum()	S_LCFRCV_SystemStateTCS_enum
#endif

#ifndef	S_LCFRCV_SystemStateVSM_enum
#define S_LCFRCV_SystemStateVSM_enum		(pLcfSenReqPorts->pLcfInputData->VSM_SystemState_nu) /*Checked, not used*/
#define GET_S_LCFRCV_SystemStateVSM_enum()	S_LCFRCV_SystemStateVSM_enum
#endif

#ifndef	S_LCFRCV_SystemStateTSA_enum
#define S_LCFRCV_SystemStateTSA_enum    	(pLcfSenReqPorts->pLcfInputData->TSA_SystemState_nu)
#define GET_S_LCFRCV_SystemStateTSA_enum()	S_LCFRCV_SystemStateTSA_enum
#endif

#ifndef	S_LCFRCV_SysStAvailableABS_bool
#define S_LCFRCV_SysStAvailableABS_bool			(pLcfSenReqPorts->pLcfInputData->ABS_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE)) /*Checked*/
#define GET_S_LCFRCV_SysStAvailableABS_bool()	S_LCFRCV_SysStAvailableABS_bool
#endif

#ifndef	S_LCFRCV_SysStAvailableACC_bool
#define S_LCFRCV_SysStAvailableACC_bool			(pLcfSenReqPorts->pLcfInputData->ACC_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE)) /*Checked*/
#define GET_S_LCFRCV_SysStAvailableACC_bool()	S_LCFRCV_SysStAvailableACC_bool
#endif

#ifndef	S_LCFRCV_SysStAvailableESC_bool
#define S_LCFRCV_SysStAvailableESC_bool			(pLcfSenReqPorts->pLcfInputData->ESC_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE)) /*Checked*/
#define GET_S_LCFRCV_SysStAvailableESC_bool()	S_LCFRCV_SysStAvailableESC_bool
#endif

#ifndef	S_LCFRCV_SysStAvailableTCS_bool
#define S_LCFRCV_SysStAvailableTCS_bool			(pLcfSenReqPorts->pLcfInputData->TCS_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE)) /*Checked*/
#define GET_S_LCFRCV_SysStAvailableTCS_bool()	S_LCFRCV_SysStAvailableTCS_bool
#endif

#ifndef	S_LCFRCV_SysStAvailableVSM_bool
#define S_LCFRCV_SysStAvailableVSM_bool			(pLcfSenReqPorts->pLcfInputData->VSM_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE)) /* Checked*/
#define GET_S_LCFRCV_SysStAvailableVSM_bool()	S_LCFRCV_SysStAvailableVSM_bool
#endif

#ifndef	S_LCFRCV_SysStAvailableTSA_bool
#define S_LCFRCV_SysStAvailableTSA_bool    	(pLcfSenReqPorts->pLcfInputData->TSA_SystemState_nu == ((uint8)LCF_SYSTEM_AVAILABLE))
#define GET_S_LCFRCV_SysStAvailableTSA_bool()	S_LCFRCV_SysStAvailableTSA_bool
#endif

#ifndef	S_LCFRCV_SysStErrorABS_bool
#define S_LCFRCV_SysStErrorABS_bool	 		(pLcfSenReqPorts->pLcfInputData->ABS_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR)) /* Checked*/
#define GET_S_LCFRCV_SysStErrorABS_bool()	S_LCFRCV_SysStErrorABS_bool
#endif

#ifndef	S_LCFRCV_SysStErrorACC_bool
#define S_LCFRCV_SysStErrorACC_bool	 		(pLcfSenReqPorts->pLcfInputData->ACC_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR)) /* Checked*/
#define GET_S_LCFRCV_SysStErrorACC_bool()	S_LCFRCV_SysStErrorACC_bool
#endif

#ifndef	S_LCFRCV_SysStErrorESC_bool
#define S_LCFRCV_SysStErrorESC_bool	 		(pLcfSenReqPorts->pLcfInputData->ESC_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR)) /* Checked*/
#define GET_S_LCFRCV_SysStErrorESC_bool()	S_LCFRCV_SysStErrorESC_bool
#endif

#ifndef	S_LCFRCV_SysStErrorTCS_bool
#define S_LCFRCV_SysStErrorTCS_bool	 		(pLcfSenReqPorts->pLcfInputData->TCS_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR)) /* Checked*/
#define GET_S_LCFRCV_SysStErrorTCS_bool()	S_LCFRCV_SysStErrorTCS_bool
#endif

#ifndef	S_LCFRCV_SysStErrorVSM_bool
#define S_LCFRCV_SysStErrorVSM_bool	 		(pLcfSenReqPorts->pLcfInputData->VSM_SystemState_nu == ((uint8)LCF_SYSTEM_ERROR)) /* Checked*/
#define GET_S_LCFRCV_SysStErrorVSM_bool()	S_LCFRCV_SysStErrorVSM_bool
#endif

#ifndef	S_LCFRCV_AccObjTraceCrv_1pm
#define S_LCFRCV_AccObjTraceCrv_1pm	 		(pLcfSenReqPorts->pLcfInputData->ACC_TraceTrajCurve_1pm)
#define GET_S_LCFRCV_AccObjTraceCrv_1pm()	S_LCFRCV_AccObjTraceCrv_1pm
#endif

#ifndef	S_LCFRCV_AccObjTraceWeight_met
#define S_LCFRCV_AccObjTraceWeight_met	    	(pLcfSenReqPorts->pLcfInputData->ACC_TraceTrajWeight_nu)
#define GET_S_LCFRCV_AccObjTraceWeight_met()	S_LCFRCV_AccObjTraceWeight_met
#endif

#ifndef	S_LCFRCV_ACC_TraceTrajQualifier_nu
#define S_LCFRCV_ACC_TraceTrajQualifier_nu	    	(pLcfSenReqPorts->pLcfInputData->ACC_TraceTrajQualifier_nu)
#define GET_S_LCFRCV_ACC_TraceTrajQualifier_nu()	S_LCFRCV_ACC_TraceTrajQualifier_nu
#endif

#ifndef	S_LCFRCV_AccObjTraceDist_met
#define S_LCFRCV_AccObjTraceDist_met	    	(pLcfSenReqPorts->pLcfInputData->ACC_TraceTrajMaxDist_m)
#define GET_S_LCFRCV_AccObjTraceDist_met()	S_LCFRCV_AccObjTraceDist_met
#endif

#ifndef	S_LCFRCV_BSD_WarningRight_nu
#define S_LCFRCV_BSD_WarningRight_nu    	(pLcfSenReqPorts->pLcfInputData->BSD_Warning_Right_nu) /* Checked*/
#define GET_S_LCFRCV_BSD_WarningRight_nu()	S_LCFRCV_BSD_WarningRight_nu
#endif

#ifndef S_LCFRCV_BSD_WarningRight_bool
#define S_LCFRCV_BSD_WarningRight_bool ((GET_S_LCFRCV_BSD_WarningRight_nu() == (uint8)LCF_BSD_WARNING_1) || (GET_S_LCFRCV_BSD_WarningRight_nu() == (uint8)LCF_BSD_WARNING_2))
#define GET_S_LCFRCV_BSD_WarningRight_bool() S_LCFRCV_BSD_WarningRight_bool
#endif

#ifndef	S_LCFRCV_BSD_ActiveRight_nu
#define S_LCFRCV_BSD_ActiveRight_nu    	(pLcfSenReqPorts->pLcfInputData->BSD_Active_Right_nu)  /* Checked*/
#define GET_S_LCFRCV_BSD_ActiveRight_nu()	S_LCFRCV_BSD_ActiveRight_nu
#endif

#ifndef S_LCFRCV_BSD_ActiveRight_bool
#define S_LCFRCV_BSD_ActiveRight_bool  (GET_S_LCFRCV_BSD_ActiveRight_nu() == (uint8)LCF_BSD_ACTIVE)
#define GET_S_LCFRCV_BSD_ActiveRight_bool()  S_LCFRCV_BSD_ActiveRight_bool
#endif

#ifndef	S_LCFRCV_LCA_WarningRight_nu
#define S_LCFRCV_LCA_WarningRight_nu    	(pLcfSenReqPorts->pLcfInputData->LCA_Warning_Right_nu) /* Checked*/
#define GET_S_LCFRCV_LCA_WarningRight_nu()	S_LCFRCV_LCA_WarningRight_nu
#endif

#ifndef S_LCFRCV_LCA_WarningRight_bool
#define S_LCFRCV_LCA_WarningRight_bool ((GET_S_LCFRCV_LCA_WarningRight_nu() == (uint8)LCF_LCA_WARNING_1) || (GET_S_LCFRCV_LCA_WarningRight_nu() == (uint8)LCF_LCA_WARNING_2))
#define GET_S_LCFRCV_LCA_WarningRight_bool() S_LCFRCV_LCA_WarningRight_bool
#endif

#ifndef	S_LCFRCV_LCA_ActiveRight_nu
#define S_LCFRCV_LCA_ActiveRight_nu    	(pLcfSenReqPorts->pLcfInputData->LCA_Active_Right_nu) /*Checked*/
#define GET_S_LCFRCV_LCA_ActiveRight_nu()	S_LCFRCV_LCA_ActiveRight_nu
#endif

#ifndef S_LCFRCV_LCA_ActiveRight_bool
#define S_LCFRCV_LCA_ActiveRight_bool (GET_S_LCFRCV_LCA_ActiveRight_nu() == (uint8)LCF_LCA_ACTIVE)
#define GET_S_LCFRCV_LCA_ActiveRight_bool() S_LCFRCV_LCA_ActiveRight_bool
#endif

#ifndef	S_LCFRCV_BSD_WarningLeft_nu
#define S_LCFRCV_BSD_WarningLeft_nu    	(pLcfSenReqPorts->pLcfInputData->BSD_Warning_Left_nu) /*Checked*/
#define GET_S_LCFRCV_BSD_WarningLeft_nu()	S_LCFRCV_BSD_WarningLeft_nu
#endif

#ifndef S_LCFRCV_BSD_WarningLeft_bool
#define S_LCFRCV_BSD_WarningLeft_bool ((GET_S_LCFRCV_BSD_WarningLeft_nu() == (uint8)LCF_BSD_WARNING_1) || (GET_S_LCFRCV_BSD_WarningLeft_nu() == (uint8)LCF_BSD_WARNING_2))
#define GET_S_LCFRCV_BSD_WarningLeft_bool() S_LCFRCV_BSD_WarningLeft_bool
#endif

#ifndef	S_LCFRCV_BSD_ActiveLeft_nu
#define S_LCFRCV_BSD_ActiveLeft_nu    	(pLcfSenReqPorts->pLcfInputData->BSD_Active_Left_nu)  /*Checked*/
#define GET_S_LCFRCV_BSD_ActiveLeft_nu()	S_LCFRCV_BSD_ActiveLeft_nu
#endif

#ifndef S_LCFRCV_BSD_ActiveLeft_bool
#define S_LCFRCV_BSD_ActiveLeft_bool (GET_S_LCFRCV_BSD_ActiveLeft_nu() == (uint8)LCF_BSD_ACTIVE)
#define GET_S_LCFRCV_BSD_ActiveLeft_bool() S_LCFRCV_BSD_ActiveLeft_bool
#endif

#ifndef	S_LCFRCV_LCA_WarningLeft_nu
#define S_LCFRCV_LCA_WarningLeft_nu    	(pLcfSenReqPorts->pLcfInputData->LCA_Warning_Left_nu) /*Checked*/
#define GET_S_LCFRCV_LCA_WarningLeft_nu()	S_LCFRCV_LCA_WarningLeft_nu
#endif

#ifndef S_LCFRCV_LCA_WarningLeft_bool
#define S_LCFRCV_LCA_WarningLeft_bool ((GET_S_LCFRCV_LCA_WarningLeft_nu() == (uint8)LCF_LCA_WARNING_1) || (GET_S_LCFRCV_LCA_WarningLeft_nu() == (uint8)LCF_LCA_WARNING_2))
#define GET_S_LCFRCV_LCA_WarningLeft_bool() S_LCFRCV_LCA_WarningLeft_bool
#endif

#ifndef	S_LCFRCV_LCA_ActiveLeft_nu
#define S_LCFRCV_LCA_ActiveLeft_nu    	(pLcfSenReqPorts->pLcfInputData->LCA_Active_Left_nu) /*Checked*/
#define GET_S_LCFRCV_LCA_ActiveLeft_nu()	S_LCFRCV_LCA_ActiveLeft_nu
#endif

#ifndef S_LCFRCV_LCA_ActiveLeft_bool
#define S_LCFRCV_LCA_ActiveLeft_bool (GET_S_LCFRCV_LCA_ActiveLeft_nu() == (uint8)LCF_LCA_ACTIVE)
#define GET_S_LCFRCV_LCA_ActiveLeft_bool() S_LCFRCV_LCA_ActiveLeft_bool
#endif

/* RO 894318 */
#ifndef	S_LCFRCV_SteerAngleEPS_deg
#define	S_LCFRCV_SteerAngleEPS_deg			(pLcfSenReqPorts->pLcfInputData->DeltaFSteerAngle_deg)
#define GET_S_LCFRCV_SteerAngleEPS_deg()	S_LCFRCV_SteerAngleEPS_deg
#endif

#ifndef	S_LCFRCV_QuDangOcObjDtct_nu
#define S_LCFRCV_QuDangOcObjDtct_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.QuDangOcObjDtct_nu)  /* Checked*/
#define GET_S_LCFRCV_QuDangOcObjDtct_nu()	S_LCFRCV_QuDangOcObjDtct_nu
#endif

#ifndef	S_LCFRCV_DangOcObjLeLn_nu
#define S_LCFRCV_DangOcObjLeLn_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.DangOcObjLe_nu)  /* Checked*/
#define GET_S_LCFRCV_DangOcObjLeLn_nu()	S_LCFRCV_DangOcObjLeLn_nu
#endif

#ifndef	S_LCFRCV_DangOcObjRiLn_nu
#define S_LCFRCV_DangOcObjRiLn_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.DangOcObjRi_nu)  /* Checked*/
#define GET_S_LCFRCV_DangOcObjRiLn_nu()	S_LCFRCV_DangOcObjRiLn_nu
#endif 

#ifndef	S_LCFRCV_ObjectStationaryLeft_nu
#define S_LCFRCV_ObjectStationaryLeft_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.ObjectStationaryLeft_nu)  /* Checked*/
#define GET_S_LCFRCV_ObjectStationaryLeft_nu()	S_LCFRCV_ObjectStationaryLeft_nu
#endif 

#ifndef	S_LCFRCV_ObjectStationaryRight_nu
#define S_LCFRCV_ObjectStationaryRight_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.ObjectStationaryRight_nu)  /* Checked*/
#define GET_S_LCFRCV_ObjectStationaryRight_nu()	S_LCFRCV_ObjectStationaryRight_nu
#endif

#ifndef	S_LCFRCV_ObjectSensitiveLeft_nu
#define S_LCFRCV_ObjectSensitiveLeft_nu    	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.ObjectSensitiveLeft_nu)  /* Checked*/
#define GET_S_LCFRCV_ObjectSensitiveLeft_nu()	S_LCFRCV_ObjectSensitiveLeft_nu
#endif

#ifndef	S_LCFRCV_ObjectSensitiveRight_nu
#define S_LCFRCV_ObjectSensitiveRight_nu   	(pLcfSenReqPorts->pLcfInputData->FroopToLCF.ObjectSensitiveRight_nu)  /* Checked*/
#define GET_S_LCFRCV_ObjectSensitiveRight_nu()	S_LCFRCV_ObjectSensitiveRight_nu
#endif

#ifndef	S_ODPSOP_MSFlag_RearRight_nu
#define S_ODPSOP_MSFlag_RearRight_nu    	(pLcfSenReqPorts->pLcfInputData->MSFlag_RearRight_nu) /*Checked*/
#define GET_S_ODPSOP_MSFlag_RearRight_nu()	S_ODPSOP_MSFlag_RearRight_nu
#endif

#ifndef	S_ODPSOP_DanRearObjBS_RearRi_nu
#define S_ODPSOP_DanRearObjBS_RearRi_nu    	(pLcfSenReqPorts->pLcfInputData->DanRearObjBS_RearRight_nu) /* Checked*/
#define GET_S_ODPSOP_DanRearObjBS_RearRi_nu()	S_ODPSOP_DanRearObjBS_RearRi_nu
#endif

#ifndef	S_ODPROP_DanRearObjFOV_RearRi_nu
#define S_ODPROP_DanRearObjFOV_RearRi_nu    	(pLcfSenReqPorts->pLcfInputData->DanRearObjFOV_RearRight_nu) /* Checked*/
#define GET_S_ODPROP_DanRearObjFOV_RearRi_nu()	S_ODPROP_DanRearObjFOV_RearRi_nu
#endif

#ifndef	S_ODPROP_OIQualifierFlag_RearRi_nu
#define S_ODPROP_OIQualifierFlag_RearRi_nu    	(pLcfSenReqPorts->pLcfInputData->OIQualifierFlag_RearRight_nu) /* Checked*/
#define GET_S_ODPROP_OIQualifierFlag_RearRi_nu()	S_ODPROP_OIQualifierFlag_RearRi_nu
#endif

#ifndef	S_ODPSOP_MSFlag_RearLeft_nu
#define S_ODPSOP_MSFlag_RearLeft_nu    	(pLcfSenReqPorts->pLcfInputData->MSFlag_RearLeft_nu) /* Checked*/
#define GET_S_ODPSOP_MSFlag_RearLeft_nu()	S_ODPSOP_MSFlag_RearLeft_nu
#endif

#ifndef	S_ODPSOP_DanRearObjBS_RearLe_nu
#define S_ODPSOP_DanRearObjBS_RearLe_nu    	(pLcfSenReqPorts->pLcfInputData->DanRearObjBS_RearLeft_nu) /* Checked*/
#define GET_S_ODPSOP_DanRearObjBS_RearLe_nu()	S_ODPSOP_DanRearObjBS_RearLe_nu
#endif

#ifndef	S_ODPROP_DanRearObjFOV_RearLe_nu
#define S_ODPROP_DanRearObjFOV_RearLe_nu    	(pLcfSenReqPorts->pLcfInputData->DanRearObjFOV_RearLeft_nu) /* Checked*/
#define GET_S_ODPROP_DanRearObjFOV_RearLe_nu()	S_ODPROP_DanRearObjFOV_RearLe_nu
#endif

#ifndef	S_ODPROP_OIQualifierFlag_RearLe_nu
#define S_ODPROP_OIQualifierFlag_RearLe_nu    	(pLcfSenReqPorts->pLcfInputData->OIQualifierFlag_RearLeft_nu) /* Checked*/
#define GET_S_ODPROP_OIQualifierFlag_RearLe_nu()	S_ODPROP_OIQualifierFlag_RearLe_nu
#endif
/*---------------------------------------------------------------------------------------------*/

/*-------------- SEN Input from VEH(LCF_VehToSen_t* pLcfSenInputFromVehData) ------------------*/
#ifndef	S_LCFERR_VehErrorToSen_btf
#define S_LCFERR_VehErrorToSen_btf    	(pLcfSenReqPorts->pLcfSenInputFromVehData->EvntDtctnVehEvents_nu[0].EventId_nu)/*16 bits*/
#define GET_S_LCFERR_VehErrorToSen_btf()	S_LCFERR_VehErrorToSen_btf
#endif

#ifndef	S_DRMDAE_DrvAttention_perc
#define S_DRMDAE_DrvAttention_perc			(pLcfSenReqPorts->pLcfSenInputFromVehData->DrvAttention_perc)
#define GET_S_DRMDAE_DrvAttention_perc()	S_DRMDAE_DrvAttention_perc
#endif

#ifndef	S_DRMHOD_HandsOffConfirmed_bool
#define S_DRMHOD_HandsOffConfirmed_bool			(pLcfSenReqPorts->pLcfSenInputFromVehData->HandsOffConfirmed_nu)
#define GET_S_DRMHOD_HandsOffConfirmed_bool()	S_DRMHOD_HandsOffConfirmed_bool
#endif

#ifndef	S_DRMDAE_AbuseWarning_bool
#define S_DRMDAE_AbuseWarning_bool			(pLcfSenReqPorts->pLcfSenInputFromVehData->AbuseWarning_nu)
#define GET_S_DRMDAE_AbuseWarning_bool()	S_DRMDAE_AbuseWarning_bool
#endif

#ifndef	D_DRMHOD_EstHandTor_Nm
#define D_DRMHOD_EstHandTor_Nm			(pLcfSenReqPorts->pLcfSenInputFromVehData->EstHandTor_nm)
#define GET_D_DRMHOD_EstHandTor_Nm()	D_DRMHOD_EstHandTor_Nm
#endif

#ifndef	S_DRMDAE_DrvAttentionConf_perc
#define S_DRMDAE_DrvAttentionConf_perc		    (pLcfSenReqPorts->pLcfSenInputFromVehData->DrvAttentionConf_perc)
#define GET_S_DRMDAE_DrvAttentionConf_perc()	S_DRMDAE_DrvAttentionConf_perc
#endif

#ifndef	S_DRMDAE_SysWarning_nu
#define S_DRMDAE_SysWarning_nu			(pLcfSenReqPorts->pLcfSenInputFromVehData->DrvMonSysWarning_nu)
#define GET_S_DRMDAE_SysWarning_nu()	S_DRMDAE_SysWarning_nu
#endif

/* TRJPLN outputs */
#ifndef	S_TPLFBT_QuStatusTrajPlan_nu  /*RO840664*/
#define S_TPLFBT_QuStatusTrajPlan_nu			(pLcfSenReqPorts->pLcfSenInputFromVehData->Flags.QuStatusTrajPlan_nu)
#define GET_S_TPLFBT_QuStatusTrajPlan_nu()	S_TPLFBT_QuStatusTrajPlan_nu
#endif

/* TRJCTR outputs */
#ifndef	S_TCTCLM_Limiter_TgtCrv_1pm
#define S_TCTCLM_Limiter_TgtCrv_1pm			(pLcfSenReqPorts->pLcfSenInputFromVehData->Curvatures.TgtCrv_Limited_1pm)
#define GET_S_TCTCLM_Limiter_TgtCrv_1pm()	S_TCTCLM_Limiter_TgtCrv_1pm
#endif

#ifndef	S_TCTCLM_QuServTrajCtr_nu
#define S_TCTCLM_QuServTrajCtr_nu			(pLcfSenReqPorts->pLcfSenInputFromVehData->Flags.TrjCtrQualifierService_nu)
#define GET_S_TCTCLM_QuServTrajCtr_nu()	S_TCTCLM_QuServTrajCtr_nu
#endif

#ifndef	S_LCFRCV_EvntDtctnVehEvID_nu
#define	S_LCFRCV_EvntDtctnVehEvID_nu(i)		(pLcfSenReqPorts->pLcfSenInputFromVehData->EvntDtctnVehEvents_nu[i].EventId_nu)
#define	GET_S_LCFRCV_EvntDtctnVehEvID_nu(i)	S_LCFRCV_EvntDtctnVehEvID_nu(i)
#endif

#ifndef	S_LCFRCV_EvntDtctnVehEvLifeTime_nu
#define	S_LCFRCV_EvntDtctnVehEvLifeTime_nu(i)		(pLcfSenReqPorts->pLcfSenInputFromVehData->EvntDtctnVehEvents_nu[i].EventLifetime_nu)
#define	GET_S_LCFRCV_EvntDtctnVehEvLifeTime_nu(i)	S_LCFRCV_EvntDtctnVehEvLifeTime_nu(i)
#endif
/*---------------------------------------------------------------------------------------------*/

/*---------- Inputs from VEH Generic Outputs(LCF_VehGenericOutputs_t* pLcfVehOutputData)-------*/
#ifndef S_LCFRCV_LatDmcStrAngReq_deg
#define S_LCFRCV_LatDmcStrAngReq_deg          (pLcfSenReqPorts->pLcfVehOutputData->LaDMC_StrAngReq_deg)
#define GET_S_LCFRCV_LatDmcStrAngReq_deg()     S_LCFRCV_LatDmcStrAngReq_deg
#endif

#ifndef	S_LCFRCV_LaDMC_Status_nu
#define S_LCFRCV_LaDMC_Status_nu			(pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu)
#define GET_S_LCFRCV_LaDMC_Status_nu()	S_LCFRCV_LaDMC_Status_nu
#endif

#ifndef	S_LCFRCV_SysStErrorLatDMC_bool
#define S_LCFRCV_SysStErrorLatDMC_bool			((pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_PERM_DISABLED)) || (pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_TEMP_DISABLED)))
#define GET_S_LCFRCV_SysStErrorLatDMC_bool()	S_LCFRCV_SysStErrorLatDMC_bool
#endif

#ifndef	S_LCFRCV_ActToi_nu
#define S_LCFRCV_ActToi_nu			(pLcfSenReqPorts->pLcfVehOutputData->Lkas_ActToi_nu)
#define GET_S_LCFRCV_ActToi_nu()	S_LCFRCV_ActToi_nu
#endif

#ifndef	S_LCFRCV_StrToqReq_nm
#define S_LCFRCV_StrToqReq_nm		(pLcfSenReqPorts->pLcfVehOutputData->Lkas_StrToqReq_nm)
#define GET_S_LCFRCV_StrToqReq_nm()	S_LCFRCV_StrToqReq_nm
#endif

#ifndef	S_LCFRCV_SysStOffLatDMC_bool
#define	S_LCFRCV_SysStOffLatDMC_bool		(pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_OFF))
#define GET_S_LCFRCV_SysStOffLatDMC_bool()	S_LCFRCV_SysStOffLatDMC_bool
#endif

#ifndef	S_LCFRCV_SysStOnLatDMC_bool
#define S_LCFRCV_SysStOnLatDMC_bool         ((pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_ON)) || (pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_DRV_SUPPORT_STEER)) || (pLcfSenReqPorts->pLcfVehOutputData->LaDMC_Status_nu == ((uint8)LCF_LADMC_DRV_COUNTER_STEER)))
#define GET_S_LCFRCV_SysStOnLatDMC_bool()	S_LCFRCV_SysStOnLatDMC_bool
#endif
/*---------------------------------------------------------------------------------------------*/

/*------------------------ Info from LD(AbdOutputData_t* pAbdOutputData) ----------------------*/
#ifndef	S_LCFRCV_LaneBoundariesTstamp_us
#define S_LCFRCV_LaneBoundariesTstamp_us    	(pLcfSenReqPorts->pAbdOutputData->sSigHeader.uiTimeStamp)
#define GET_S_LCFRCV_LaneBoundariesTstamp_us()	S_LCFRCV_LaneBoundariesTstamp_us
#endif

#ifndef	S_LCFRCV_LaneChange_nu
#define S_LCFRCV_LaneChange_nu    	(pLcfSenReqPorts->pAbdOutputData->eLaneChange)
#define GET_S_LCFRCV_LaneChange_nu()	S_LCFRCV_LaneChange_nu
#endif

#ifndef	S_LCFRCV_AnyBndQuality_nu
#define S_LCFRCV_AnyBndQuality_nu(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sStatus.iQuality)
#define GET_S_LCFRCV_AnyBndQuality_nu(i)	S_LCFRCV_AnyBndQuality_nu(i)
#endif

#ifndef	S_LCFRCV_AnyBndMarkerType_nu
#define S_LCFRCV_AnyBndMarkerType_nu(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sAttributes.sType.eType)
#define GET_S_LCFRCV_AnyBndMarkerType_nu(i)	S_LCFRCV_AnyBndMarkerType_nu(i)
#endif

#ifndef	S_LCFRCV_AnyBndCrvRate_1pm2
#define S_LCFRCV_AnyBndCrvRate_1pm2(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidNear.fCurvatureRate)
#define GET_S_LCFRCV_AnyBndCrvRate_1pm2(i)	S_LCFRCV_AnyBndCrvRate_1pm2(i)
#endif

#ifndef	S_LCFRCV_AnyBndCurvature_1pm
#define S_LCFRCV_AnyBndCurvature_1pm(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidNear.fCurvature)
#define GET_S_LCFRCV_AnyBndCurvature_1pm(i)	S_LCFRCV_AnyBndCurvature_1pm(i)
#endif

#ifndef	S_LCFRCV_AnyBndYawAngle_rad
#define S_LCFRCV_AnyBndYawAngle_rad(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.fYawAngleRad * (-1.0f))
#define GET_S_LCFRCV_AnyBndYawAngle_rad(i)	S_LCFRCV_AnyBndYawAngle_rad(i)
#endif

#ifndef	S_LCFRCV_AnyBndValidLength_met
#define S_LCFRCV_AnyBndValidLength_met(i)			(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidNear.fValidLengthMeter)
#define GET_S_LCFRCV_AnyBndValidLength_met(i)	S_LCFRCV_AnyBndValidLength_met(i)
#endif

#ifndef	S_LCFRCV_AnyBndDistance_met
#define S_LCFRCV_AnyBndDistance_met(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.fDistanceMeter)
#define GET_S_LCFRCV_AnyBndDistance_met(i)	S_LCFRCV_AnyBndDistance_met(i)
#endif

#ifndef	S_LCFRCV_AnyBndAvailable_bool
#define S_LCFRCV_AnyBndAvailable_bool(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sStatus.bAvailable)
#define GET_S_LCFRCV_AnyBndAvailable_bool(i)	S_LCFRCV_AnyBndAvailable_bool(i)
#endif

#ifndef	S_LCFRCV_AnyBndYawAngleStd_rad
#define S_LCFRCV_AnyBndYawAngleStd_rad(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.fYawAngleStdRad)
#define GET_S_LCFRCV_AnyBndYawAngleStd_rad(i)	S_LCFRCV_AnyBndYawAngleStd_rad(i)
#endif

#ifndef	S_LCFRCV_AnyBndDistanceStd_met
#define S_LCFRCV_AnyBndDistanceStd_met(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.fDistanceStdMeter)
#define GET_S_LCFRCV_AnyBndDistanceStd_met(i)	S_LCFRCV_AnyBndDistanceStd_met(i)
#endif

#ifndef	S_LCFRCV_AnyBndCrvRateStd_1pm2
#define S_LCFRCV_AnyBndCrvRateStd_1pm2(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidNear.fCurvatureRateStd)
#define GET_S_LCFRCV_AnyBndCrvRateStd_1pm2(i)	S_LCFRCV_AnyBndCrvRateStd_1pm2(i)
#endif

#ifndef	S_LCFRCV_AnyBndCurvatureStd_1pm
#define S_LCFRCV_AnyBndCurvatureStd_1pm(i)			(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidNear.fCurvatureStd)
#define GET_S_LCFRCV_AnyBndCurvatureStd_1pm(i)	S_LCFRCV_AnyBndCurvatureStd_1pm(i)
#endif

#ifndef	S_LCFRCV_AnyBndColor_nu
#define S_LCFRCV_AnyBndColor_nu(i)		(pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sAttributes.eColor)
#define GET_S_LCFRCV_AnyBndColor_nu(i)	S_LCFRCV_AnyBndColor_nu(i)
#endif

#ifndef	S_LCFRCV_ParallelModelActiv_bool
#define S_LCFRCV_ParallelModelActiv_bool		(pLcfSenReqPorts->pAbdOutputData->eParallelModelActive)
#define GET_S_LCFRCV_ParallelModelActiv_bool()	S_LCFRCV_ParallelModelActiv_bool
#endif

#ifndef	S_LCFRCV_LaneEventType_nu
#define S_LCFRCV_LaneEventType_nu(i)		(Get_LCFRCV_SenCommonOutPtr()->apsLaneEvents[i]->eLaneEventType)
#define GET_S_LCFRCV_LaneEventType_nu(i)	S_LCFRCV_LaneEventType_nu(i)
#endif	

/*RO 863759*/
#ifndef S_LCFRCV_AnyBndRoadWorks_btf
#define S_LCFRCV_AnyBndRoadWorks_btf        T_LCFRCV_AnyBndRoadWorks_btf
#define GET_S_LCFRCV_AnyBndRoadWorks_btf()  S_LCFRCV_AnyBndRoadWorks_btf
#endif

/*RO 946177*/
#ifndef S_LCFRCV_FeatureCoordsXYLe_met 
#define S_LCFRCV_FeatureCoordsXYLe_met(i)      T_LCFRCV_FeatureCoordsXYLe_met(i) 
#define GET_S_LCFRCV_FeatureCoordsXYLe_met(i)  S_LCFRCV_FeatureCoordsXYLe_met(i) 
#endif

/*RO 946177*/
#ifndef S_LCFRCV_FeatureCoordsXYRi_met  
#define S_LCFRCV_FeatureCoordsXYRi_met(i)      T_LCFRCV_FeatureCoordsXYRi_met (i) 
#define GET_S_LCFRCV_FeatureCoordsXYRi_met(i)  S_LCFRCV_FeatureCoordsXYRi_met (i) 
#endif

#ifndef	S_LCFRCV_AnyBndCrvLaneTrackr_1pm
#define S_LCFRCV_AnyBndCrvLaneTrackr_1pm(i)    (pLcfSenReqPorts->pAbdOutputData->asLaneBoundary[i].sGeometry.sParameters.sClothoidVertical.fCurvature)
#define GET_S_LCFRCV_AnyBndCrvLaneTrackr_1pm(i)	S_LCFRCV_AnyBndCrvLaneTrackr_1pm(i)
#endif

#ifndef	S_LCFRCV_LaneEventQuality_nu
#define S_LCFRCV_LaneEventQuality_nu(i)		(Get_LCFRCV_SenCommonOutPtr()->apsLaneEvents[i]->iEventQuality)
#define GET_S_LCFRCV_LaneEventQuality_nu(i)	S_LCFRCV_LaneEventQuality_nu(i)
#endif

#ifndef	S_LCFRCV_LaneEventDistance_met
#define S_LCFRCV_LaneEventDistance_met(i)		(Get_LCFRCV_SenCommonOutPtr()->apsLaneEvents[i]->fEventDist)
#define GET_S_LCFRCV_LaneEventDistance_met(i)	S_LCFRCV_LaneEventDistance_met(i)
#endif

#ifndef	S_LCFRCV_AnyBndRightIndex_nu
#define S_LCFRCV_AnyBndRightIndex_nu(i)      	(pLcfSenReqPorts->pAbdOutputData->sLaneInformation.aiLaneBoundariesRight[i])
#define GET_S_LCFRCV_AnyBndRightIndex_nu(i)	S_LCFRCV_AnyBndRightIndex_nu(i)
#endif

#ifndef	S_LCFRCV_AnyBndLeftIndex_nu
#define S_LCFRCV_AnyBndLeftIndex_nu(i)       	(pLcfSenReqPorts->pAbdOutputData->sLaneInformation.aiLaneBoundariesLeft[i])
#define GET_S_LCFRCV_AnyBndLeftIndex_nu(i)	S_LCFRCV_AnyBndLeftIndex_nu(i)
#endif
/*---------------------------------------------------------------------------------------------*/

/*---------------- Generic Object list properties(EM_t_GenObjectList* pGenObjectList)  --------*/
#ifndef	S_LCFRCV_GenObjMovRelVelX_mps
#define	S_LCFRCV_GenObjMovRelVelX_mps(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fVrelX)
#define	GET_S_LCFRCV_GenObjMovRelVelX_mps(i)	S_LCFRCV_GenObjMovRelVelX_mps(i)
#endif

#ifndef	S_LCFRCV_GenObjMovRelVelY_mps
#define	S_LCFRCV_GenObjMovRelVelY_mps(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fVrelY)
#define	GET_S_LCFRCV_GenObjMovRelVelY_mps(i)	S_LCFRCV_GenObjMovRelVelY_mps(i)
#endif

#ifndef	S_LCFRCV_GenObjMovRelAclX_mps2
#define	S_LCFRCV_GenObjMovRelAclX_mps2(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fArelX)
#define	GET_S_LCFRCV_GenObjMovRelAclX_mps2(i)	S_LCFRCV_GenObjMovRelAclX_mps2(i)
#endif

#ifndef	S_LCFRCV_GenObjMovRelAclY_mps2
#define	S_LCFRCV_GenObjMovRelAclY_mps2(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fArelY)
#define	GET_S_LCFRCV_GenObjMovRelAclY_mps2(i)	S_LCFRCV_GenObjMovRelAclY_mps2(i)
#endif

#ifndef	S_LCFRCV_GenObjMovAbsVelX_mps
#define	S_LCFRCV_GenObjMovAbsVelX_mps(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fVabsX)
#define	GET_S_LCFRCV_GenObjMovAbsVelX_mps(i)	S_LCFRCV_GenObjMovAbsVelX_mps(i)
#endif

#ifndef	S_LCFRCV_GenObjMovAbsVelY_mps
#define	S_LCFRCV_GenObjMovAbsVelY_mps(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fVabsY)
#define	GET_S_LCFRCV_GenObjMovAbsVelY_mps(i)	S_LCFRCV_GenObjMovAbsVelY_mps(i)
#endif

#ifndef	S_LCFRCV_GenObjMovAbsAclX_mps2
#define	S_LCFRCV_GenObjMovAbsAclX_mps2(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fAabsX)
#define	GET_S_LCFRCV_GenObjMovAbsAclX_mps2(i)	S_LCFRCV_GenObjMovAbsAclX_mps2(i)
#endif

#ifndef	S_LCFRCV_GenObjMovAbsAclY_mps2
#define	S_LCFRCV_GenObjMovAbsAclY_mps2(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fAabsY)
#define	GET_S_LCFRCV_GenObjMovAbsAclY_mps2(i)	S_LCFRCV_GenObjMovAbsAclY_mps2(i)
#endif

#ifndef	S_LCFRCV_GenObjPosX_met
#define	S_LCFRCV_GenObjPosX_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fDistX)
#define	GET_S_LCFRCV_GenObjPosX_met(i)	S_LCFRCV_GenObjPosX_met(i)
#endif

#ifndef	S_LCFRCV_GenObjPosY_met
#define	S_LCFRCV_GenObjPosY_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Kinematic.fDistY)
#define	GET_S_LCFRCV_GenObjPosY_met(i)	S_LCFRCV_GenObjPosY_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt0State_nu
#define	S_LCFRCV_GenObjShPt0State_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointStates[0])
#define	GET_S_LCFRCV_GenObjShPt0State_nu(i)	S_LCFRCV_GenObjShPt0State_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt1State_nu
#define	S_LCFRCV_GenObjShPt1State_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointStates[1])
#define	GET_S_LCFRCV_GenObjShPt1State_nu(i)	S_LCFRCV_GenObjShPt1State_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt2State_nu
#define	S_LCFRCV_GenObjShPt2State_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointStates[2])
#define	GET_S_LCFRCV_GenObjShPt2State_nu(i)	S_LCFRCV_GenObjShPt2State_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt3State_nu
#define	S_LCFRCV_GenObjShPt3State_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointStates[3])
#define	GET_S_LCFRCV_GenObjShPt3State_nu(i)	S_LCFRCV_GenObjShPt3State_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt0PosX_met
#define	S_LCFRCV_GenObjShPt0PosX_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[0].fPosX)
#define	GET_S_LCFRCV_GenObjShPt0PosX_met(i)	S_LCFRCV_GenObjShPt0PosX_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt1PosX_met
#define	S_LCFRCV_GenObjShPt1PosX_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[1].fPosX)
#define	GET_S_LCFRCV_GenObjShPt1PosX_met(i)	S_LCFRCV_GenObjShPt1PosX_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt2PosX_met
#define	S_LCFRCV_GenObjShPt2PosX_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[2].fPosX)
#define	GET_S_LCFRCV_GenObjShPt2PosX_met(i)	S_LCFRCV_GenObjShPt2PosX_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt3PosX_met
#define	S_LCFRCV_GenObjShPt3PosX_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[3].fPosX)
#define	GET_S_LCFRCV_GenObjShPt3PosX_met(i)	S_LCFRCV_GenObjShPt3PosX_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt0PosY_met
#define	S_LCFRCV_GenObjShPt0PosY_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[0].fPosY)
#define	GET_S_LCFRCV_GenObjShPt0PosY_met(i)	S_LCFRCV_GenObjShPt0PosY_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt1PosY_met
#define	S_LCFRCV_GenObjShPt1PosY_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[1].fPosY)
#define	GET_S_LCFRCV_GenObjShPt1PosY_met(i)	S_LCFRCV_GenObjShPt1PosY_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt2PosY_met
#define	S_LCFRCV_GenObjShPt2PosY_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[2].fPosY)
#define	GET_S_LCFRCV_GenObjShPt2PosY_met(i)	S_LCFRCV_GenObjShPt2PosY_met(i)
#endif

#ifndef	S_LCFRCV_GenObjShPt3PosY_met
#define	S_LCFRCV_GenObjShPt3PosY_met(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Geometry.aShapePointCoordinates[3].fPosY)
#define	GET_S_LCFRCV_GenObjShPt3PosY_met(i)	S_LCFRCV_GenObjShPt3PosY_met(i)
#endif

#ifndef	S_LCFRCV_GenObjExistProb_nu
#define	S_LCFRCV_GenObjExistProb_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Qualifiers.uiProbabilityOfExistence)
#define	GET_S_LCFRCV_GenObjExistProb_nu(i)	S_LCFRCV_GenObjExistProb_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjStMeas_nu
#define	S_LCFRCV_GenObjStMeas_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].General.eMaintenanceState)
#define	GET_S_LCFRCV_GenObjStMeas_nu(i)	S_LCFRCV_GenObjStMeas_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjObjectID_nu
#define	S_LCFRCV_GenObjObjectID_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].General.uiID)
#define	GET_S_LCFRCV_GenObjObjectID_nu(i)	S_LCFRCV_GenObjObjectID_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjLifetime_sec
#define	S_LCFRCV_GenObjLifetime_sec(i)         (pLcfSenReqPorts->pGenObjectList->aObject[i].General.fLifeTime)
#define	GET_S_LCFRCV_GenObjLifetime_sec(i)	S_LCFRCV_GenObjLifetime_sec(i)
#endif

#ifndef	S_LCFRCV_GenObjSensSource_nu
#define	S_LCFRCV_GenObjSensSource_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].General.eSensorSource)
#define	GET_S_LCFRCV_GenObjSensSource_nu(i)	S_LCFRCV_GenObjSensSource_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjStMov_nu
#define	S_LCFRCV_GenObjStMov_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Attributes.eDynamicProperty)
#define	GET_S_LCFRCV_GenObjStMov_nu(i)	S_LCFRCV_GenObjStMov_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjStMovProb_nu
#define	S_LCFRCV_GenObjStMovProb_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Attributes.uiDynConfidence)
#define	GET_S_LCFRCV_GenObjStMovProb_nu(i)	S_LCFRCV_GenObjStMovProb_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjClType_nu
#define	S_LCFRCV_GenObjClType_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Attributes.eClassification)
#define	GET_S_LCFRCV_GenObjClType_nu(i)	S_LCFRCV_GenObjClType_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjClTypeProb_nu
#define	S_LCFRCV_GenObjClTypeProb_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Attributes.uiClassConfidence)
#define	GET_S_LCFRCV_GenObjClTypeProb_nu(i)	S_LCFRCV_GenObjClTypeProb_nu(i)
#endif

#ifndef	S_LCFRCV_GenObjOcclusion_nu
#define	S_LCFRCV_GenObjOcclusion_nu(i)		(pLcfSenReqPorts->pGenObjectList->aObject[i].Attributes.eObjectOcclusion)
#define	GET_S_LCFRCV_GenObjOcclusion_nu(i)	S_LCFRCV_GenObjOcclusion_nu(i)
#endif
/*--------------------------------------------------------------------------------------------*/

/*-------- Camera Object list properties(EM_t_CamObjectList* pCamObjectList)  ----------------*/
#ifndef	S_LCFRCV_CamObjVisRange_met
#define	S_LCFRCV_CamObjVisRange_met         (pLcfSenReqPorts->pCamObjectList->Qualifiers.uiVisibilityRange)
#define	GET_S_LCFRCV_CamObjVisRange_met()	S_LCFRCV_CamObjVisRange_met
#endif

#ifndef	S_LCFRCV_CamObjSerDeg_nu
#define	S_LCFRCV_CamObjSerDeg_nu		(pLcfSenReqPorts->pCamObjectList->Qualifiers.uiServiceDegradation)
#define	GET_S_LCFRCV_CamObjSerDeg_nu()	S_LCFRCV_CamObjSerDeg_nu
#endif

#ifndef	S_LCFRCV_CamObjQuaFlags_nu
#define	S_LCFRCV_CamObjQuaFlags_nu          (pLcfSenReqPorts->pCamObjectList->Qualifiers.uiQualityFlags)
#define	GET_S_LCFRCV_CamObjQuaFlags_nu()	S_LCFRCV_CamObjQuaFlags_nu
#endif

#ifndef	S_LCFRCV_CamObjYaw_rad
#define	S_LCFRCV_CamObjYaw_rad(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Kinematic.fYaw)
#define	GET_S_LCFRCV_CamObjYaw_rad(i)	S_LCFRCV_CamObjYaw_rad(i)
#endif

#ifndef	S_LCFRCV_CamObjYawRate_rads
#define	S_LCFRCV_CamObjYawRate_rads(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Kinematic.fYawRate)
#define	GET_S_LCFRCV_CamObjYawRate_rads(i)	S_LCFRCV_CamObjYawRate_rads(i)
#endif

#ifndef	S_LCFRCV_CamObjAssocL_nu
#define	S_LCFRCV_CamObjAssocL_nu(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Attributes.eAssociatedLane)
#define	GET_S_LCFRCV_CamObjAssocL_nu(i)	S_LCFRCV_CamObjAssocL_nu(i)
#endif

#ifndef	S_LCFRCV_CamObjPerOverDrL_nu
#define	S_LCFRCV_CamObjPerOverDrL_nu(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Attributes.percentageOwnDrivingLane)
#define	GET_S_LCFRCV_CamObjPerOverDrL_nu(i)	S_LCFRCV_CamObjPerOverDrL_nu(i)
#endif

#ifndef	S_LCFRCV_CamObjPerSDrvLLeft_perc
#define	S_LCFRCV_CamObjPerSDrvLLeft_perc(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Attributes.percentageSideDrivingLaneLeft)
#define	GET_S_LCFRCV_CamObjPerSDrvLLeft_perc(i)	S_LCFRCV_CamObjPerSDrvLLeft_perc(i)
#endif

#ifndef	S_LCFRCV_CamObjPerSDrvLRight_perc
#define	S_LCFRCV_CamObjPerSDrvLRight_perc(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Attributes.percentageSideDrivingLaneRight)
#define	GET_S_LCFRCV_CamObjPerSDrvLRight_perc(i)	S_LCFRCV_CamObjPerSDrvLRight_perc(i)
#endif

#ifndef	S_LCFRCV_CamObjLChMan_nu
#define	S_LCFRCV_CamObjLChMan_nu(i)		(pLcfSenReqPorts->pCamObjectList->aObject[i].Attributes.eLaneChangeManeuver)
#define	GET_S_LCFRCV_CamObjLChMan_nu(i)	S_LCFRCV_CamObjLChMan_nu(i)
#endif
/*----------------------------------------------------------------------------------------*/

/*--------------- Inputs from Main Vehicle Dynamics(VehSig_t* pVehSig) sensor ------------*/
#ifndef	S_LCFRCV_BrkPedlPressed_bool
#define S_LCFRCV_BrkPedlPressed_bool		(pLcfSenReqPorts->pVehSig->VehSigAdd.BrakePedalPressed)
#define GET_S_LCFRCV_BrkPedlPressed_bool()	S_LCFRCV_BrkPedlPressed_bool
#endif

#ifndef	S_LCFRCV_CurrentGear_enum
#define S_LCFRCV_CurrentGear_enum		(pLcfSenReqPorts->pVehSig->VehSigMain.ActGearPos)
#define GET_S_LCFRCV_CurrentGear_enum()	S_LCFRCV_CurrentGear_enum
#endif

#ifndef	S_LCFRCV_CurrentGearReverse_bool
#define S_LCFRCV_CurrentGearReverse_bool    	(pLcfSenReqPorts->pVehSig->VehSigMain.ActGearPos == ((uint8)ACT_GEAR_POS_REVERSE))
#define GET_S_LCFRCV_CurrentGearReverse_bool()	S_LCFRCV_CurrentGearReverse_bool
#endif

#ifndef	S_LCFRCV_CurrentGearParking_bool
#define S_LCFRCV_CurrentGearParking_bool    	(pLcfSenReqPorts->pVehSig->VehSigMain.ActGearPos == ((uint8)ACT_GEAR_POS_PARKING))
#define GET_S_LCFRCV_CurrentGearParking_bool()	S_LCFRCV_CurrentGearParking_bool
#endif

#ifndef	S_LCFRCV_CurrentGearNeutral_bool
#define S_LCFRCV_CurrentGearNeutral_bool		(pLcfSenReqPorts->pVehSig->VehSigMain.ActGearPos == ((uint8)ACT_GEAR_POS_NEUTRAL))
#define GET_S_LCFRCV_CurrentGearNeutral_bool()	S_LCFRCV_CurrentGearNeutral_bool
#endif

#ifndef	S_LCFRCV_SteeringAngleFrontAxleEff_rad
#define S_LCFRCV_SteeringAngleFrontAxleEff_rad   	(pLcfSenReqPorts->pVehSig->VehSigAdd.RoadWhlAngFr)
#define GET_S_LCFRCV_SteeringAngleFrontAxleEff_rad()	S_LCFRCV_SteeringAngleFrontAxleEff_rad
#endif

#ifndef	S_LCFRCV_TrailerPresent_bool
#define S_LCFRCV_TrailerPresent_bool        (pLcfSenReqPorts->pVehSig->VehSigAdd.TrailerConnection == VEH_SIG_ADD_TRLR_OK)
#define GET_S_LCFRCV_TrailerPresent_bool()	S_LCFRCV_TrailerPresent_bool
#endif

#ifndef	S_LCFRCV_AccelPedalPos_nu
#define S_LCFRCV_AccelPedalPos_nu		(pLcfSenReqPorts->pVehSig->VehSigAdd.GasPedalPos)
#define GET_S_LCFRCV_AccelPedalPos_nu()	S_LCFRCV_AccelPedalPos_nu
#endif

#ifndef	S_LCFRCV_VDy_VehVelocity_kph
#define S_LCFRCV_VDy_VehVelocity_kph		(pLcfSenReqPorts->pVehSig->VehSigAdd.SpeedoSpeed) /* issue 772468: SpeedoSpeed is always received in km/h*/
#define GET_S_LCFRCV_VDy_VehVelocity_kph()	S_LCFRCV_VDy_VehVelocity_kph
#endif

#ifndef	S_LCFRCV_TurnSignalState_enum
#define S_LCFRCV_TurnSignalState_enum       (pLcfSenReqPorts->pVehSig->VehSigAdd.TurnSignal)  /*RO 936352 Use TurnSignal from VDY*/
#define GET_S_LCFRCV_TurnSignalState_enum()	S_LCFRCV_TurnSignalState_enum
#endif

#ifndef	S_LCFRCV_TurnSignalLeft_bool
#define S_LCFRCV_TurnSignalLeft_bool        (pLcfSenReqPorts->pVehSig->VehSigAdd.TurnSignal == ((uint8)VEH_SIG_ADD_TURN_SIG_LEFT))  /*RO 936352 Use TurnSignal from VDY*/
#define GET_S_LCFRCV_TurnSignalLeft_bool()	S_LCFRCV_TurnSignalLeft_bool
#endif

#ifndef	S_LCFRCV_TurnSignalRight_bool
#define S_LCFRCV_TurnSignalRight_bool       (pLcfSenReqPorts->pVehSig->VehSigAdd.TurnSignal == ((uint8)VEH_SIG_ADD_TURN_SIG_RIGHT))  /*RO 936352 Use TurnSignal from VDY*/
#define GET_S_LCFRCV_TurnSignalRight_bool()	S_LCFRCV_TurnSignalRight_bool
#endif

#ifndef	S_LCFRCV_TurnSignalHazard_bool
#define S_LCFRCV_TurnSignalHazard_bool      	(pLcfSenReqPorts->pVehSig->VehSigAdd.TurnSignal == ((uint8)VEH_SIG_ADD_TURN_SIG_BOTH))  /*RO 936352 Use TurnSignal from VDY*/
#define GET_S_LCFRCV_TurnSignalHazard_bool()	S_LCFRCV_TurnSignalHazard_bool
#endif

#ifndef	S_LCFRCV_WiperStage_nu
#define S_LCFRCV_WiperStage_nu       (pLcfSenReqPorts->pVehSig->VehSigAdd.WiperStage)  /*RO 1066500*/
#define GET_S_LCFRCV_WiperStage_nu()	S_LCFRCV_WiperStage_nu
#endif

#ifndef	S_LCFRCV_WiperState_nu
#define S_LCFRCV_WiperState_nu       (pLcfSenReqPorts->pVehSig->VehSigAdd.WiperState)  /*RO 1066500*/
#define GET_S_LCFRCV_WiperState_nu()	S_LCFRCV_WiperState_nu
#endif
/*---------------------------------------------------------------------------*/

/*------- Inputs from Static Vehicle parameters( VehDyn_t* pVehDyn)  --------*/
#ifndef	S_LCFRCV_SysStErrorVDY_bool
#define S_LCFRCV_SysStErrorVDY_bool	 		(pLcfSenReqPorts->pVehDyn->sSigHeader.eSigStatus == AL_SIG_STATE_INVALID)
#define GET_S_LCFRCV_SysStErrorVDY_bool()	S_LCFRCV_SysStErrorVDY_bool
#endif

#ifndef	S_LCFRCV_VehAclY_mps2
#define S_LCFRCV_VehAclY_mps2 		(pLcfSenReqPorts->pVehDyn->Lateral.Accel.LatAccel) /* added for R 2.0 */
#define GET_S_LCFRCV_VehAclY_mps2()	S_LCFRCV_VehAclY_mps2
#endif

#ifndef	S_LCFRCV_VehCrv_1pm
#define S_LCFRCV_VehCrv_1pm			(pLcfSenReqPorts->pVehDyn->Lateral.Curve.Curve)
#define GET_S_LCFRCV_VehCrv_1pm()	S_LCFRCV_VehCrv_1pm
#endif

#ifndef	S_LCFRCV_VehMotionState_enum
#define S_LCFRCV_VehMotionState_enum    (pLcfSenReqPorts->pVehDyn->MotionState.MotState)
#define GET_S_LCFRCV_VehMotionState_enum()	S_LCFRCV_VehMotionState_enum
#endif

#ifndef	S_LCFRCV_VehMovesBckwd_bool
#define S_LCFRCV_VehMovesBckwd_bool     	(pLcfSenReqPorts->pVehDyn->MotionState.MotState == VDY_LONG_MOT_STATE_MOVE_RWD)
#define GET_S_LCFRCV_VehMovesBckwd_bool()	S_LCFRCV_VehMovesBckwd_bool
#endif

#ifndef	S_LCFRCV_VehOdoState_nu
#define S_LCFRCV_VehOdoState_nu         (pLcfSenReqPorts->pVehDyn->sSigHeader.eSigStatus == AL_SIG_STATE_OK)
#define GET_S_LCFRCV_VehOdoState_nu()	S_LCFRCV_VehOdoState_nu
#endif

#ifndef	S_LCFRCV_VehStopped_nu
#define S_LCFRCV_VehStopped_nu          (pLcfSenReqPorts->pVehDyn->MotionState.MotState == VDY_LONG_MOT_STATE_STDST)
#define GET_S_LCFRCV_VehStopped_nu()	S_LCFRCV_VehStopped_nu
#endif

#ifndef	S_LCFRCV_VehSync_us
#define S_LCFRCV_VehSync_us			(pLcfSenReqPorts->pVehDyn->sSigHeader.uiTimeStamp)
#define GET_S_LCFRCV_VehSync_us()	S_LCFRCV_VehSync_us
#endif

#ifndef	S_LCFRCV_VehYawRate_rps
#define S_LCFRCV_VehYawRate_rps         (pLcfSenReqPorts->pVehDyn->Lateral.YawRate.YawRate)
#define GET_S_LCFRCV_VehYawRate_rps()	S_LCFRCV_VehYawRate_rps
#endif

#ifndef	S_LCFRCV_VehYawRateStd_radps
#define S_LCFRCV_VehYawRateStd_radps    (CML_f_Sqrt(pLcfSenReqPorts->pVehDyn->Lateral.YawRate.Variance)) /*rps2 ??*/
#define GET_S_LCFRCV_VehYawRateStd_radps()	S_LCFRCV_VehYawRateStd_radps
#endif

#ifndef	S_LCFRCV_VehAclX_mps2
#define S_LCFRCV_VehAclX_mps2		(pLcfSenReqPorts->pVehDyn->Longitudinal.Accel)
#define GET_S_LCFRCV_VehAclX_mps2()	S_LCFRCV_VehAclX_mps2
#endif

#ifndef	S_LCFRCV_VehVelX_mps
#define S_LCFRCV_VehVelX_mps		(Get_LCFRCV_SenCommonOutPtr()->T_LCFRCV_VehVelX_mps)
#define GET_S_LCFRCV_VehVelX_mps()	S_LCFRCV_VehVelX_mps
#endif

/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_RoadBankAngle_rad
#define S_LCFRCV_RoadBankAngle_rad		(pLcfSenReqPorts->pVehDyn->Lateral.SelfSteering.RoadBankAngle)
#define GET_S_LCFRCV_RoadBankAngle_rad()	S_LCFRCV_RoadBankAngle_rad
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_QuRoadBankAngle_nu
#define S_LCFRCV_QuRoadBankAngle_nu		(pLcfSenReqPorts->pVehDyn->Lateral.SelfSteering.QuRoadBankAngle)
#define GET_S_LCFRCV_QuRoadBankAngle_nu()	S_LCFRCV_QuRoadBankAngle_nu
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_SelfSteerGradEst_rads2pm
#define S_LCFRCV_SelfSteerGradEst_rads2pm		(pLcfSenReqPorts->pVehDyn->Lateral.SelfSteering.SelfSteerGradEst)
#define GET_S_LCFRCV_SelfSteerGradEst_rads2pm()	S_LCFRCV_SelfSteerGradEst_rads2pm
#endif
/*RO 955654 New VDY RTE outputs*/
#ifndef	S_LCFRCV_QuSelfSteerGradEst_nu
#define S_LCFRCV_QuSelfSteerGradEst_nu		(pLcfSenReqPorts->pVehDyn->Lateral.SelfSteering.QuSelfSteerGradEst)
#define GET_S_LCFRCV_QuSelfSteerGradEst_nu()	S_LCFRCV_QuSelfSteerGradEst_nu
#endif
/*--------------------------------------------------------------------------------*/

/*---- Inputs from DMC Iuc(LCF_LaDmcIucToSoc_t* pLcfLaDmcIucToSoc) ---------------*/
#if defined(LCF_IUC_USED) && (LCF_IUC_USED == 1)
#ifndef	S_LCFRCV_LatDMCTrqRequest_bool
#define S_LCFRCV_LatDMCTrqRequest_bool         (pLcfSenReqPorts->pLcfLaDmcIucToSoc->SAC_Eps_Request_Flag_nu)
#define GET_S_LCFRCV_LatDMCTrqRequest_bool()	S_LCFRCV_LatDMCTrqRequest_bool
#endif
#endif
/*----------------------------------------------------------------------------------------------*/

/*-------- Radar Object List input(HLA_RadarObjectList_t* pHlaRadarObjectList)------------------*/
#if defined(HLA_RADAR_OBJECT_USED) && (HLA_RADAR_OBJECT_USED == 1)
	
#ifndef S_LCFRCV_HLAObjAPosX_met
#define S_LCFRCV_HLAObjAPosX_met               (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjKinematics.DistX)
#define GET_S_LCFRCV_HLAObjAPosX_met()         S_LCFRCV_HLAObjAPosX_met
#endif

#ifndef S_LCFRCV_HLAObjAPosY_met
#define S_LCFRCV_HLAObjAPosY_met              (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjKinematics.DistY)
#define GET_S_LCFRCV_HLAObjAPosY_met()         S_LCFRCV_HLAObjAPosY_met
#endif

#ifndef S_LCFRCV_HLAObjAClass_nu
#define S_LCFRCV_HLAObjAClass_nu               (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjAttributes.Classification)
#define GET_S_LCFRCV_HLAObjAClass_nu()         S_LCFRCV_HLAObjAClass_nu
#endif

#ifndef S_LCFRCV_HLAObjAClassConf_perc
#define S_LCFRCV_HLAObjAClassConf_perc        (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjAttributes.ClassConfidence)
#define GET_S_LCFRCV_HLAObjAClassConf_perc()   S_LCFRCV_HLAObjAClassConf_perc
#endif

#ifndef S_LCFRCV_HLAObjAExistProb_perc
#define S_LCFRCV_HLAObjAExistProb_perc         (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjAttributes.ProbabilityOfExistence)
#define GET_S_LCFRCV_HLAObjAExistProb_perc()    S_LCFRCV_HLAObjAExistProb_perc
#endif

#ifndef S_LCFRCV_HLAObjAObjID_nu
#define S_LCFRCV_HLAObjAObjID_nu                (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjGenerals.ID)
#define GET_S_LCFRCV_HLAObjAObjID_nu()           S_LCFRCV_HLAObjAObjID_nu
#endif

#ifndef S_LCFRCV_HLAObjALifeCycles_nu
#define S_LCFRCV_HLAObjALifeCycles_nu            (pLcfSenReqPorts->pHlaRadarObjectList->Object[0].HLA_RadarObjGenerals.LifeCycles)
#define GET_S_LCFRCV_HLAObjALifeCycles_nu()       S_LCFRCV_HLAObjALifeCycles_nu
#endif

#ifndef S_LCFRCV_HLAObjBPosX_met
#define S_LCFRCV_HLAObjBPosX_met              (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjKinematics.DistX)
#define GET_S_LCFRCV_HLAObjBPosX_met()        S_LCFRCV_HLAObjBPosX_met
#endif

#ifndef S_LCFRCV_HLAObjBPosY_met
#define S_LCFRCV_HLAObjBPosY_met              (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjKinematics.DistY)
#define GET_S_LCFRCV_HLAObjBPosY_met()        S_LCFRCV_HLAObjBPosY_met
#endif

#ifndef S_LCFRCV_HLAObjBClass_nu
#define S_LCFRCV_HLAObjBClass_nu                (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjAttributes.Classification)
#define GET_S_LCFRCV_HLAObjBClass_nu()           S_LCFRCV_HLAObjBClass_nu
#endif

#ifndef S_LCFRCV_HLAObjBClassConf_perc
#define S_LCFRCV_HLAObjBClassConf_perc            (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjAttributes.ClassConfidence)
#define GET_S_LCFRCV_HLAObjBClassConf_perc()      S_LCFRCV_HLAObjBClassConf_perc
#endif

#ifndef S_LCFRCV_HLAObjBExistProb_perc
#define S_LCFRCV_HLAObjBExistProb_perc            (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjAttributes.ProbabilityOfExistence)
#define GET_S_LCFRCV_HLAObjBExistProb_perc()      S_LCFRCV_HLAObjBExistProb_perc
#endif

#ifndef S_LCFRCV_HLAObjBObjID_nu
#define S_LCFRCV_HLAObjBObjID_nu                  (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjGenerals.ID)
#define GET_S_LCFRCV_HLAObjBObjID_nu()             S_LCFRCV_HLAObjBObjID_nu
#endif

#ifndef S_LCFRCV_HLAObjBLifeCycles_nu
#define S_LCFRCV_HLAObjBLifeCycles_nu              (pLcfSenReqPorts->pHlaRadarObjectList->Object[1].HLA_RadarObjGenerals.LifeCycles)
#define GET_S_LCFRCV_HLAObjBLifeCycles_nu()         S_LCFRCV_HLAObjBLifeCycles_nu
#endif
#endif
/*in case the HLA port is not available, the signals are set to 0 in LCFSEN_data.h*/
/*-----------------------------------------------------------------------------------------------*/

/*------------------ Light Source Detection Input(LSD_EnvironmentData_t* pLsdEnvironmentData)----*/
#ifndef	S_LCFRCV_BrightnessState_nu
#define S_LCFRCV_BrightnessState_nu       (pLcfSenReqPorts->pLsdEnvironmentData->brightnessState)
#define GET_S_LCFRCV_BrightnessState_nu()	S_LCFRCV_BrightnessState_nu
#endif 
/*-----------------------------------------------------------------------------------------------*/

/*------------------ Input from ERR --------------------------------------*/
#ifndef	S_LCFRCV_ErrorStateLKA_bool
#define	S_LCFRCV_ErrorStateLKA_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_TJA_LC])
#define	GET_S_LCFRCV_ErrorStateLKA_bool()	S_LCFRCV_ErrorStateLKA_bool
#endif

#ifndef	S_LCFRCV_ErrorStateLDP_bool
#define	S_LCFRCV_ErrorStateLDP_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDP])
#define	GET_S_LCFRCV_ErrorStateLDP_bool()	S_LCFRCV_ErrorStateLDP_bool
#endif

#ifndef	S_LCFRCV_ErrorStateRDP_bool
#define	S_LCFRCV_ErrorStateRDP_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_RDP])
#define	GET_S_LCFRCV_ErrorStateRDP_bool()	S_LCFRCV_ErrorStateRDP_bool
#endif

#ifndef	S_LCFRCV_ErrorStateLDW_bool
#define	S_LCFRCV_ErrorStateLDW_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDW])
#define	GET_S_LCFRCV_ErrorStateLDW_bool()	S_LCFRCV_ErrorStateLDW_bool
#endif

#ifndef	S_LCFRCV_ErrorStateTJA_bool
#define	S_LCFRCV_ErrorStateTJA_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_TJA_OF])
#define	GET_S_LCFRCV_ErrorStateTJA_bool()	S_LCFRCV_ErrorStateTJA_bool
#endif

#ifndef	S_LCFRCV_ErrorStateRDW_bool
#define	S_LCFRCV_ErrorStateRDW_bool			(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_RDW])
#define	GET_S_LCFRCV_ErrorStateRDW_bool()	S_LCFRCV_ErrorStateRDW_bool
#endif

#ifndef	S_LCFRCV_ErrorStateLDPOC_bool
#define	S_LCFRCV_ErrorStateLDPOC_bool		(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDPOC])
#define	GET_S_LCFRCV_ErrorStateLDPOC_bool()	S_LCFRCV_ErrorStateLDPOC_bool
#endif

#ifndef	S_LCFRCV_ErrorStateLDWOC_bool
#define	S_LCFRCV_ErrorStateLDWOC_bool		(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_LDWOC])
#define	GET_S_LCFRCV_ErrorStateLDWOC_bool()	S_LCFRCV_ErrorStateLDWOC_bool
#endif

#ifndef	S_LCFRCV_ErrorStateALCA_bool
#define	S_LCFRCV_ErrorStateALCA_bool		(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_ALCA])
#define	GET_S_LCFRCV_ErrorStateALCA_bool()	S_LCFRCV_ErrorStateALCA_bool
#endif

#ifndef	S_LCFRCV_ErrorStateSALC_bool
#define	S_LCFRCV_ErrorStateSALC_bool		(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_SALC])
#define	GET_S_LCFRCV_ErrorStateSALC_bool()	S_LCFRCV_ErrorStateSALC_bool
#endif

#ifndef	S_LCFRCV_ErrorStateAOLC_bool
#define	S_LCFRCV_ErrorStateAOLC_bool		(ERRIOSEN_ErrStateArray[LCF_ERRHNDL_AOLC])
#define	GET_S_LCFRCV_ErrorStateAOLC_bool()	S_LCFRCV_ErrorStateAOLC_bool
#endif


/*------------------ Renaming ----------------------------------------------------------*/
#ifndef S_LCFRCV_TurnSignalState_nu
#define S_LCFRCV_TurnSignalState_nu  S_LCFRCV_TurnSignalState_enum  /*still used by ALCASA, LDPSA updated with RO 1124888*/
#define GET_S_LCFRCV_TurnSignalState_nu()  S_LCFRCV_TurnSignalState_nu
#endif

/*---------------- Other info -------------------------------------*/
#ifndef	S_LCFRCV_SysCycleTimeSen_sec
#define S_LCFRCV_SysCycleTimeSen_sec    	(0.06f) /* TODO compute real delta cycle time in the main wrapper */
#define GET_S_LCFRCV_SysCycleTimeSen_sec()	S_LCFRCV_SysCycleTimeSen_sec
#endif

#endif /* _LCFRCV_SEN_H_ */

