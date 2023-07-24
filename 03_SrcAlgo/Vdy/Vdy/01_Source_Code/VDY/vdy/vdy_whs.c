/*! \file **********************************************************************

  @defgroup WheelSpeedSignalProcessingUnit VDY Offset Estimation - WHS Unit Design
	@ingroup VDYHandCode
  @{

  $Company:			Continental AG $

  $Component:		VDY (Vehicle Dynamics Observer) $

  $Module:			vdy_whs.c $

  @brief			This module contains the wheel speeds signal processing

  $Descripion:		$

  $Revision: 1.25 $

  CHANGES:
  ---*/ /*---
  CHANGE:           $Log: vdy_whs.c  $
  CHANGE:           Revision 1.25 2020/06/04 21:57:10CEST Chinnaswamy, Ramachandra (uids4735) (uids4735) 
  CHANGE:           Test Cases Links Update
  CHANGE:           Revision 1.24 2020/05/31 23:26:40CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Test Scripts Linking
  CHANGE:           Revision 1.23 2020/05/14 02:00:37CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.22 2020/05/13 01:00:49CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design update - Traceability
  CHANGE:           Revision 1.21 2020/05/06 08:47:01CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PRQA Template Update
  CHANGE:           Revision 1.20 2020/05/04 23:06:19CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.19 2020/04/25 22:23:07CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.18 2020/04/15 15:49:53CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           L4 Design Link
  CHANGE:           Revision 1.17 2019/12/31 12:24:21CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC Fixes
  CHANGE:           Revision 1.16 2019/06/11 08:36:15CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAF Fixes
  CHANGE:           Revision 1.15 2019/05/29 15:12:53CEST Hongal, Tammanna (uidp3499) 
  CHANGE:           cml defendecy changes
  CHANGE:           Revision 1.14 2019/03/13 13:15:16CET Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY MAinstream sync w.r.t-
  CHANGE:           
  CHANGE:           VDY checkpoint: AL_VDY_BASE_05.00.19_INT-1
  CHANGE:           CustomCP for ARS510TA19 : AL_VDY_ARS510TA19_CUS_05.00.19.30
  CHANGE:           Revision 1.13 2019/01/31 07:25:25CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.12 2019/01/26 21:24:00CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Followed camel case convention for methods
  CHANGE:           Revision 1.11 2019/01/26 09:22:18CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.10 2019/01/09 13:36:59CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design - Doors Linking
  CHANGE:           Revision 1.9 2019/01/03 10:44:39CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update - UML for functions
  CHANGE:           Revision 1.8 2018/12/05 10:53:25CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           QAC fixes
  CHANGE:           Revision 1.7 2018/11/15 10:41:23CET Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           PDO tool support
  CHANGE:           Revision 1.6 2018/09/17 14:00:10CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment: Defined STATIC_VAR
  CHANGE:           Revision 1.5 2018/09/12 16:23:14CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Support for courage environment
  CHANGE:           Revision 1.4 2018/09/04 12:00:05CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Design Update
  CHANGE:           Revision 1.3 2018/08/28 13:29:31CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Detailed Unit Design Update
  CHANGE:           Revision 1.2 2018/08/24 15:32:17CEST Chinnaswamy-EXT, Ramachandra (uids4735) 
  CHANGE:           Unit Design Update
  CHANGE:           Revision 1.1 2018/08/09 10:41:27CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           Initial revision
  CHANGE:           Member added to project /ADAS/SW/Components/VDY_VehicleDynamics/04_Engineering/01_Source_Code/VDY/vdy/project.pj
  CHANGE:           Revision 1.17.2.1 2018/07/25 11:48:55CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           VDY mearged code for ARS and MFC : Mainstream
  CHANGE:           Revision 1.17 2016/07/26 12:04:40CEST Mani, Yugesh (uidj6870) 
  CHANGE:           -Adapted the VDY Output RTE interfaces for ARS510
  CHANGE:           Revision 1.16 2015/07/10 14:29:40CEST Singh, Sanjiv (uidr1340) 
  CHANGE:           QAC fix for critical and mandatory errors
  CHANGE:           - Added comments -  uidr1340 [Jul 10, 2015 2:29:40 PM CEST]
  CHANGE:           Change Package : 355424:1 http://mks-psad:7002/im/viewissue?selection=355424
  CHANGE:           Revision 1.15 2014/12/03 11:13:36CET Balachandra, Swathi (uidj2447) 
  CHANGE:           Fix for MISRA violations
  CHANGE:           --- Added comments ---  uidj2447 [Dec 3, 2014 11:13:37 AM CET]
  CHANGE:           Change Package : 278585:1 http://mks-psad:7002/im/viewissue?selection=278585
  CHANGE:           Revision 1.14 2014/10/01 11:16:40CEST Wolter, Frank (wolterf) 
  CHANGE:           - lowered velocity threshold for wheel speed offset calculation to 40kph
  CHANGE:           --- Added comments ---  wolterf [Oct 1, 2014 11:16:41 AM CEST]
  CHANGE:           Change Package : 264939:1 http://mks-psad:7002/im/viewissue?selection=264939
  CHANGE:           Revision 1.13 2014/04/08 14:48:15CEST Wolter, Frank (wolterf) 
  CHANGE:           - doxygen function header
  CHANGE:           - removed MISRA violations
  CHANGE:           --- Added comments ---  wolterf [Apr 8, 2014 2:48:15 PM CEST]
  CHANGE:           Change Package : 229561:1 http://mks-psad:7002/im/viewissue?selection=229561
  CHANGE:           Revision 1.12 2013/10/11 16:41:37CEST Wolter, Frank (wolterf) 
  CHANGE:           - Code Review #339136
  CHANGE:           - implemented QAC MISRA findings
  CHANGE:           - switched to Autosar types
  CHANGE:           - grammar/spelling corrections
  CHANGE:           --- Added comments ---  wolterf [Oct 11, 2013 4:41:37 PM CEST]
  CHANGE:           Change Package : 198819:1 http://mks-psad:7002/im/viewissue?selection=198819
  CHANGE:           

*****************************************************************************/
/* PRQA S 3408 EOF */
/* date: Unknown, reviewer: Suggested TCI Code Review, reason: Legacy code of ARS301,It is already declared in header file but cant recognise since it is under MACRO condition  " */

/* QAC Level 1 & 2 Warning Suppression */
/* PRQA S 2211, 2981, 3212, 3227, 3469, 3678, 1532 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: This operation is intended */

/*****************************************************************************
  INCLUDES
*****************************************************************************/
/* PRQA S 0380 EOF */
/* date: 2019-06-10, reviewer: Mahesh Patle (uidr0487), reason: No Risk */

/* PRQA S 2755, 3447 EOF */
/* date: 2019-12-30, reviewer: Ramachandra Chinnaswamy (uids4735), reason: Fucntional Safe */

#include "vdy.h"


/*****************************************************************************
  SYMBOLIC CONSTANTS
*****************************************************************************/

/* general WSP definitions */

/// Minimum Vego to calculate the WSP curve
#define WHS_VEH_SPEED_MIN       VDY_CURVE_V_MIN
/// Filter time mean sample offset factor
#define WHS_MEAN_SMPL_FT         (0.15F)
/// Threshold one to tune up the overtake factor
#define WHS_MEAN_SMPL_DIFF_THR1  (0.0002F)
/// Min Factor if over Thrshold one
#define WHS_MEAN_SMPL_MIN_FACTOR (7.5F)
/// Threshold two to tune up the overtake factor
#define WHS_MEAN_SMPL_DIFF_THR2  (0.0004F)
/// Max Factor if over Thrshold one
#define WHS_MEAN_SMPL_MAX_FACTOR (15.0F)        


/* Bestimmung const Fahrt (ohne Schlenker) */

/// Maximum curve gradient. RDZ for const driving
#define WHS_DELTA_DIST_GRAD_MAX (1.0F/1500.F)
/// Minimum distance with low gradient for offset compensation
#define WHS_DELTA_DIST_MIN      (15.F)

/* Bestimmung Geradeausfahrt (Straight) */

/// curve threshold for straight driving with high quality
#define WHS_STRAIGHT_CMAX_QLT_HIGH (1.0F/3500.F)
/// Grenzkruemmung geradeaus bei niedriger Spurguete
#define WHS_STRAIGHT_CMAX_QLT_LOW  (1.0F/2000.F)
/// >= Hohe Spurguete ; < niedrige Spurguete
#define WHS_STRAIGHT_QLT_HIGH      (0.80F)
/// Minimale Guete fuer Geradeausermittlung
#define WHS_STRAIGHT_QLT_LOW       (0.05F)

/* Offsetbestimmung */
/// Minimum vehicle speed for offset calculation
#define WHS_OFFS_VSPEED_MIN    (40.F/C_KMH_MS)
/// Maximum vehicle speed for offset calculation
#define WHS_OFFS_VSPEED_MAX    (220.F/C_KMH_MS)
/// Max Number of values in the sample interval
#define WHS_OFFS_SINT_VOLUME_MAX (50)
/// Maximum standard deviation sample interval
#define WHS_OFFS_DEV_MAX         (0.0015F)
/// Maximum ratio deviation left / right
#define WHS_OFFS_MEAN_MAX        (0.0247F)
/// Maximum number per speed interval
#define WHS_OFFS_V_INT_VOL_MAX   (10000.F)
/// Maximum number per speed interval
#define WHS_OFFS_V_INT_RED_FACT  (9.F/10.F)
/// Maximum number of samples for all speed sensors
#define WHS_OFFS_INIT_VOLUME     (1000.F)
/// default variance for externally provided whs curve
#define VDY_TRACK_EX_WSP_VAR      (0.85F)

/*****************************************************************************
  MACROS
*****************************************************************************/
/// Get VDY Wheel speeds global data
#define WHS_GET_ME                    (&VDYWhsGlobData)
/// Get VDY internal intra module Wheel speeds data
#define WHS_GET_MIF_DATA              (VDYWhsGlobData.Io.mif)
/// Get VDY YWheel speeds global sensor data
#define WHS_GET_DATA                  (&VDYWhsGlobData.Sensor)
/// Get VDY Wheel speeds global sensor offset data
#define WHS_GET_OFFS                  (&VDYWhsGlobData.Offset)

/*****************************************************************************
  TYPEDEFS
*****************************************************************************/



/*****************************************************************************
  VARIABLES
*****************************************************************************/
SET_MEMSEC_VAR(VDYWhsGlobData)
STATIC_VAR VDYWhsData_t VDYWhsGlobData; 


/*****************************************************************************
  LOCAL FUNCTION PROTOTYPES
*****************************************************************************/


/* **********************************************************************
  @fn                     vdyWhsCommonInit */ /*!
  @brief           Initialises the wheel speed data without the offset data

  @description     Calls vdyWhsInitWspData()
                   Any additional initialisation can be done here

  @return          static void

  @param[in,out]   *pWhsdata : Wheel speed processing data structure

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- call vdyWhsInitWspData()
  
	@startuml
	start
		:vdyWhsInitWspData(&pWhsdata->Sensor);
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c ->
  @traceability			  - NA

  @author                 R.Ehrhardt
**************************************************************************** */
STATIC_MTD void vdyWhsCommonInit(VDYWhsData_t *pWhsdata);


/* **********************************************************************
  @fn                     vdyWhsInitWspOffsData */ /*!
  @brief           Initialisation of complete offset data

  @description     All offset data structures of both axles
                   but not the wheel speed measurement data

  @return          static void

  @param[in,out]   *WspOffsData : Wheel velocity offset data  

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Initialize of complete offset data
  
	@startuml
	start
		:vdyWhsInitWspAxleOffs(&WspOffsData->OffsFront);
		:vdyWhsInitWspAxleOffs(&WspOffsData->OffsRear);
		:WspOffsData->ExWspStatus       = (VDYCrvStatus_t) VDY_CRV_NOTOK;
		:WspOffsData->SpeedRange      = VDY_ZERO;
		:WspOffsData->LastSpeedRange  = VDY_ZERO;
		:WspOffsData->WspDeltaDist    = VDY_ZERO_F;
		:WspOffsData->GradAbsOld      = VDY_ZERO_F;
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c ->
  @traceability			  - NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspOffsData(VDYWhsOffsData_t *WspOffsData);


/* ***********************************************************************
  @fn                     vdyWhsTrackStraight */ /*!
  @brief           Detecs straight ahead driving

  @description     Checks for straight ahead driving depending on
                   curve variance, higher variance has higher
                   constraints for the straight ahead curve limit
                   and uses a bigger radius than low variances

  @return          static void

  @param[in,out]   *Status : Curve Status
  @param[in]       *TrackExWsp : Estimated curvature of vehicle trajectory 

  @glob_in         
				  - WHS_STRAIGHT_QLT_HIGH : High track Dumaguete       
				  - WHS_STRAIGHT_CMAX_QLT_HIGH : curve threshold for straight driving with high quality     
				  - WHS_STRAIGHT_CMAX_QLT_LOW : Boundary curvature straight at low trace Dumaguete
  @glob_out        None ? : Global output filled in this function

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					- Determine curvature limit for straight ahead driving ( TrackExWsp->Variance >= WHS_STRAIGHT_QLT_HIGH : high track quality)
						- If so, curvature limit if quality is high, CurveLimit = WHS_STRAIGHT_CMAX_QLT_HIGH
						- Else, curvature limit if quality is low, CurveLimit = WHS_STRAIGHT_CMAX_QLT_LOW
					- Check for straight ahead driving
  
	@startuml
	start
		if ( Determine curvature limit for straight ahead driving \n TrackExWsp->Variance >= WHS_STRAIGHT_QLT_HIGH) then (YES)
			:curvature limit if quality is high (Grenzkruemmung bei hoher Guete) \n CurveLimit = WHS_STRAIGHT_CMAX_QLT_HIGH ;
		else (NO)
			:curvature limit if quality is low (Grenzkruemmung bei niedriger Guete) \n CurveLimit = WHS_STRAIGHT_CMAX_QLT_LOW;
		endif
		:Check for straight ahead driving \n *Status = vdyCheckCurve(TrackExWsp, CurveLimit, WHS_STRAIGHT_QLT_LOW);
		:return;
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c ->TEST_vdyWhsTrackStraight_001()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1032-00026448

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsTrackStraight(VDYCrvStatus_t *Status, const VDYOutCurve_t *TrackExWsp);


/* **********************************************************************
  @fn                     vdyWhsAxleCalcRatioLeftRight */ /*!
  @brief           Calculates ratio left / right

  @description     Calculates ratio left / right

  @return          static void

  @param[in,out]   *Axle : Wheel speed axle raw data  

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Calculates ratio left / right
					- wheel speeds > 0  then calculate ratio
					- otherwise set ration to 1
  
	@startuml
	start
		if (   (Axle->WspLeft  > C_F32_DELTA) && (Axle->WspRight > C_F32_DELTA)) then (YES)
			:wheel speeds > 0  -> calculate ratio \n Axle->Ratio = Axle->WspLeft/Axle->WspRight;
		else (NO)
			:Axle->Ratio = VDY_ONE_F;
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsAxleCalcRatioLeftRight_001(), TEST_vdyWhsAxleCalcRatioLeftRight_002()
  @traceability			  
	- NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsAxleCalcRatioLeftRight(VDYWhsAxisData_t *Axle);


/* ***********************************************************************
  @fn                     vdyWhsCalcOffsetAxle */ /*!
  @brief                  Calculates offset of one axle

  @description            Offset is calculated if 
                          - car is driving straight
                          - driving straight for a minimum distance
                          - vehicle speed is in a defined speed range
                          to calculate the offset
                          At startup, all intervals are set filled

  @param[in]              Ratio       : ratio left / right)
  @param[in]              SpeedRange  : velocity range
  @param[in]              TrackStatus :info straight ahead driving
  @param[in]              DeltaDist   :distance with constant driving
  @param[out]             Offset	: Wheel velocity offset axle data  
  @return                 void

  @glob_in         
					  - WHS_GET_ME : Wheel speed processing database (Calibration inhibition states)   
					  - WHS_GET_MIF_DATA : Component internal intra module interface
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre                    wheel speed ratio must have already been calculated
  @post                   No changes
  @InOutCorrelation
						- get ego velocity
						- check if offset compensation can be done (driving straight ahead? & minimum driven distance with low wheel curvature reached? & v ego not too small (noise too big because number of ticks too low or time too long)? & v ego not too big (big offset change because tyres increase in volume (Aufquellen der Reifen)? )
							- if wheel speed calibration mode is off
								- add value (Offset->SampleInterval) to interval
								- mark speed range, offset calculation started before overrun could occur
							- If Accumlated weights of samples is greater than Max Number of values in the sample interval
								- calculate mean and standard deviation
								- check mean and standard deviation, if within the range
									- determine speed range for complete interval
									- at startup? no, then calculate offset
										- calculate tuning factor to rise sample interval weight
										- tune up the sample interval
										- take sample interval
										- calculate mean of offset
										- check if offset interval should be reduced
									- Otherwise,
										- fill intervals for all speed ranges at startup
										- take sample interval
										- calculate mean of offset
						- reset interval
  

	@startuml
	start
		:calibration mode states \n VDYCaliState_t CaliState = WHS_GET_ME->Io.in->Frame.CaliMode;
		:get ego velocity \n VehicleSpeed = WHS_GET_MIF_DATA->LongMot.VehVelocityCorr;
		if ( check if offset compensation can be done \n    ( driving straight ahead \n TrackStatus  == (VDYCrvStatus_t) VDY_CRV_OK  ) && ( minimum driven distance with low wheel curvature reached \n DeltaDist    >= WHS_DELTA_DIST_MIN  ) && ( v ego not too small (noise too big because number of ticks too low or time too long) \n VehicleSpeed >= WHS_OFFS_VSPEED_MIN ) && ( v ego not too big (big offset change because tyres increase in volume \n VehicleSpeed <= WHS_OFFS_VSPEED_MAX ) ) ) then (YES)
			:driving straight ahead detected \n add samples only if wheel speed calibration mode is off;
			if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_WHS_OFFS, CaliState)) then (YES)
				:add value to interval \n vdyStatIntervalAdd(&Offset->SampleInterval, Ratio, VDY_ONE_F);
				:mark speed range, offset calculation started before overrun could occur \n Offset->IntervalRangeVolume += SpeedRange;
			endif
			if (Offset->SampleInterval.Volume >= (float32) WHS_OFFS_SINT_VOLUME_MAX) then (YES)
				:calculate mean and standard deviation \n vdyStatIntervalMeanDev( &Offset->SampleInterval);
				:check mean and standard deviation;
				if (  (fABS(Offset->SampleInterval.Mean - VDY_ONE_F) <= (WHS_OFFS_MEAN_MAX)) &&(Offset->SampleInterval.Dev <= WHS_OFFS_DEV_MAX )) then (YES)
					:determine speed range for complete interval \n IntSpeedRange = Offset->IntervalRangeVolume  / (sint32) Offset->SampleInterval.Volume \n IntSpeedRange = MINMAX (0, (WHS_SPEEED_RANGE_VOLUME - 1), IntSpeedRange); 
					if ( at startup? no, then calculate offset, otherwise fill intervals for all speed ranges \n Offset->Interval[0].Volume >= WHS_OFFS_INIT_VOLUME) then (YES)
						:calculate tuning factor to rise sample interval weight \n Offset->Factor = vdyWhsCalcMeanFactor(Offset, IntSpeedRange);
						:tune up the sample interval \n vdyStatIntervalReduce( &Offset->SampleInterval, Offset->Factor);
						:take sample interval \n vdyStatIntervalMerge( &Offset->Interval[IntSpeedRange], &Offset->SampleInterval);
						:calculate mean of offset \n vdyStatIntervalMeanDev( &Offset->Interval[IntSpeedRange]);
						if ( check if offset interval should be reduced \n Offset->Interval[IntSpeedRange].Volume >= WHS_OFFS_V_INT_VOL_MAX) then (YES)
							:vdyStatIntervalReduce(&Offset->Interval[IntSpeedRange],WHS_OFFS_V_INT_RED_FACT);
						endif
					else (NO)
						:fill intervals for all speed ranges at startup;
						:ii = 0;
						repeat
							:take sample interval \n vdyStatIntervalMerge( &Offset->Interval[ii], &Offset->SampleInterval);
							:calculate mean of offset \n vdyStatIntervalMeanDev( &Offset->Interval[ii]);
							:ii++;
						repeat while ( ii<WHS_SPEEED_RANGE_VOLUME)
					endif
				endif
				:vdyStatIntervalInit(&Offset->SampleInterval);
				:Offset->IntervalRangeVolume = 0; 
			endif
		endif
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> \n
                            TEST_vdyWhsCalcOffsetAxle_01(),
                            TEST_vdyWhsCalcOffsetAxle_02(),
                            TEST_vdyWhsCalcOffsetAxle_03(),
                            TEST_vdyWhsCalcOffsetAxle_04(),
                            TEST_vdyWhsCalcOffsetAxle_05(),
                            TEST_vdyWhsCalcOffsetAxle_06(),
                            TEST_vdyWhsCalcOffsetAxle_07(),
                            TEST_vdyWhsCalcOffsetAxle_08(),
                            TEST_vdyWhsCalcOffsetAxle_09(),
                            TEST_vdyWhsCalcOffsetAxle_010(),
                            TEST_vdyWhsCalcOffsetAxle_011()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-718-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1035-00026448
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1036-00026448


  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsCalcOffsetAxle(VDYWhsAxleOffs_t *Offset, float32 Ratio, sint32 SpeedRange,
                                 VDYCrvStatus_t TrackStatus, fDistance_t DeltaDist );


/* **********************************************************************
  @fn                     vdyWhsVehSpeedRange */ /*!
  @brief           Calculates vehicle velocity range / offset interval

  @description     Calculates vehicle velocity range / offset interval

  @return          static sint32

  @param[in]       VehicleSpeed : Translatory velocity

  @glob_in         
					  - WHS_OFFS_VSPEED_MAX : Maximum air speed for offset calculation       
					  - WHS_OFFS_VSPEED_MIN : Minimum air speed for offset calculation    
					  - WHS_SPEEED_RANGE_VOLUME : Number of speed ranges of RDZ Offset
  @glob_out        None 

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Calculate vehicle velocity range / offset interval
  
	@startuml
	start
		:Divisor = (((WHS_OFFS_VSPEED_MAX - WHS_OFFS_VSPEED_MIN)) / (float32)(WHS_SPEEED_RANGE_VOLUME));
		:Range_2 = (VehicleSpeed - WHS_OFFS_VSPEED_MIN)  / Divisor;
		:Range = (sint32)Range_2;
		:Range = MINMAX(0, (WHS_SPEEED_RANGE_VOLUME - 1), Range);
		:return (Range);
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> \n
                            TEST_vdyWhsVehSpeedRange_001(),
                            TEST_vdyWhsVehSpeedRange_002(),
                            TEST_vdyWhsVehSpeedRange_003(),
                            TEST_vdyWhsVehSpeedRange_004()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1520-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1034-00026448

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD sint32 vdyWhsVehSpeedRange(fVelocity_t VehicleSpeed);


/* **********************************************************************
  @fn                     vdyWhsSetOffIntLastRange */ /*!
  @brief           Sets Offset intervall to last speed range mean

  @description     Sets offset of one vehicle axle to mean value of last speed range
                   Used if speed range changes
                   Parameter SpeedRange is always within array limits,
                   checked when calculated in vdyWhsVehSpeedRange()

  @return          static void

  @param[in,out]   *Offset : Wheel velocity offset axle data 
  @param[in]       SpeedRange : Velocity range  
  @param[in]       LastSpeedRange : Velocity range last cycle  

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					- If Accumlated weights of samples is greater than 0 and lesser than Maximum number of samples for all speed sensors
						- Sum up the samples
						- Square sum of samples
					- calculate offset mean value
  
	@startuml
	start
		if (   (Offset->Interval[LastSpeedRange].Volume > VDY_ZERO_F) && (Offset->Interval[SpeedRange].Volume <= WHS_OFFS_INIT_VOLUME)) then (YES)
			:Offset->Interval[SpeedRange].Sum = ( Offset->Interval[LastSpeedRange].Sum / Offset->Interval[LastSpeedRange].Volume ) * Offset->Interval[SpeedRange].Volume;
			:Offset->Interval[SpeedRange].SqSum = ( Offset->Interval[LastSpeedRange].SqSum / Offset->Interval[LastSpeedRange].Volume ) * Offset->Interval[SpeedRange].Volume;
		endif
		:calculate offset mean value \n vdyStatIntervalMeanDev( &Offset->Interval[SpeedRange]);
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsSetOffIntLastRange_001(), TEST_vdyWhsSetOffIntLastRange_002()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8 
    - doors://rbgs854a:40000/?version=2&prodID=0&view=0000012f&urn=urn:telelogic::1-503e822e5ec3651e-O-1520-000221c8
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1043-00026448

  @author                 J.Spruck
**************************************************************************** */
STATIC_MTD void vdyWhsSetOffIntLastRange(VDYWhsAxleOffs_t *Offset, sint32 SpeedRange, sint32 LastSpeedRange);


/* **********************************************************************
  @fn                     vdyWhsCalcMeanFactor */ /*!
  @brief           Calculate the Mean tune factor

  @description     If the difference between filtered mean sample interval
                   and the current speed range interval is high,
                   then the factor is set to a high value

  @return          static float32

  @param[in,out]   *Offset : Wheel velocity offset axle data 
  @param[in]       SpeedRange :	Velocity Range

  @glob_in         
				  - WHS_MEAN_SMPL_MAX_FACTOR : Max Factor if over Thrshold one       
				  - WHS_MEAN_SMPL_MIN_FACTOR : Min Factor if over Thrshold one        
				  - WHS_MEAN_SMPL_DIFF_THR2 : Threshold two to tune up the overtake factor   
				  - WHS_MEAN_SMPL_DIFF_THR1 : Threshold one to tune up the overtake factor
  @glob_out        None 

  @c_switch_part   None
  @c_switch_full   None

  @pre             None 
  @post            No changes 
  @InOutCorrelation
					- filter mean of sample interval
					- check delta between filtered mean of sample interval with current speed range interval
					- if delta is in threshold factor use linear funtion for the factor
					- else 
						- if delta is greater than Threshold two to tune up the overtake factor (WHS_MEAN_SMPL_DIFF_THR2) then set actor to max factor (WHS_MEAN_SMPL_MAX_FACTOR)
						- else set Factor = 1.0F
  
	@startuml
	start
		:filter mean of sample interval \n Offset->SampleIntFiltMean = vdyFilterCycleTime( Offset->SampleInterval.Mean, Offset->SampleIntFiltMean, WHS_MEAN_SMPL_FT );
		:check delta between filtered mean of sample interval with current speed range intervall \n Difference = fABS(Offset->SampleIntFiltMean - Offset->Interval[SpeedRange].Mean);
		if ( (Difference >= WHS_MEAN_SMPL_DIFF_THR1) && (Difference < WHS_MEAN_SMPL_DIFF_THR2) ) then (YES)
			:linear function for the factor \n Factor = ( (WHS_MEAN_SMPL_MAX_FACTOR - WHS_MEAN_SMPL_MIN_FACTOR) /(WHS_MEAN_SMPL_DIFF_THR2-WHS_MEAN_SMPL_DIFF_THR1) ) * Difference;
		else (NO)
			if (Difference >= WHS_MEAN_SMPL_DIFF_THR2) then (YES)
				:Factor = WHS_MEAN_SMPL_MAX_FACTOR;
			else (NO)
				:Factor = VDY_ONE_F;
			endif
		endif
		:return (Factor);
	stop
	@enduml
  @testmethod			  
	- Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsCalcMeanFactor_001(), TEST_vdyWhsCalcMeanFactor_002()
  @traceability			  
  - L3
    - doors://RBGS854A:40000/?version=2&prodID=0&view=000000cd&urn=urn:telelogic::1-503e822e5ec3651e-O-289-000221c8 
  - L4
    - doors://rbgs854a:40000/?version=2&prodID=0&urn=urn:telelogic::1-503e822e5ec3651e-O-1039-00026448

  @author                 J.Spruck
**************************************************************************** */
STATIC_MTD float32 vdyWhsCalcMeanFactor(VDYWhsAxleOffs_t *Offset, sint32 SpeedRange);


/* **********************************************************************
  @fn                     vdyWhsInitAxleData */ /*!
  @brief           Initialises the wheel speed data of one axle

  @description     Initialises the wheel speed data of one axle

  @return          static void

  @param[in,out]   *Axle : Wheel speed axle raw data  

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialize the wheel speed data of one axle
  
	@startuml
	start
		:Axle->Ratio         =   VDY_ONE_F;
		:Axle->WspLeft       =   VDY_ZERO_F;
		:Axle->WspRight      =   VDY_ZERO_F;
		:Axle->WspLeftFilt1  =   VDY_ZERO_F;
		:Axle->WspRightFilt1 =   VDY_ZERO_F;
		:Axle->WspLeftFilt2  =   VDY_ZERO_F;
		:Axle->WspRightFilt2 =   VDY_ZERO_F;
		:Axle->WspValid      =   FALSE;
		:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> NA
  @traceability			  - NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsInitAxleData(VDYWhsAxisData_t *Axle);


/* **********************************************************************
  @fn                     vdyWhsInitWspData */ /*!
  @brief           Initialises the wheel speed data 

  @description     Initialises the wheel speed data 

  @return          static void

  @param[in,out]   *WspData : Wheel speed sensor data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- Initialises the wheel speed data
  
	@startuml
	start
		:vdyWhsInitAxleData(&WspData->WspFornt);
		:vdyWhsInitAxleData(&WspData->WspRear);
		:WspData->Aquaplaning          = FALSE;
		:WspData->CurveOld             = VDY_ZERO_F;
		:WspData->WspFrontRaw.WspLeft  = VDY_ZERO_F;
		:WspData->WspFrontRaw.WspRight = VDY_ZERO_F;
		:WspData->WspRearRaw.WspLeft   = VDY_ZERO_F;
		:WspData->WspRearRaw.WspRight  = VDY_ZERO_F;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> NA
  @traceability			  - NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspData(VDYWhsSenData_t *WspData);


/* **********************************************************************
  @fn                     vdyWhsInitWspAxleOffs */ /*!
  @brief           Initialises the offset data of one axle

  @description     Initialises the offset data of one axle

  @return          static void

  @param[in,out]   *Offset : Whs Offset Data

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None 
  @post            No changes
  @InOutCorrelation
					- Initialises the offset data of one axle
  
	@startuml
	start

		:ii=0;
	repeat
		:vdyStatIntervalInit(&Offset->Interval[ii]);
		:ii++;
	repeat while ( ii < WHS_SPEEED_RANGE_VOLUME )

	:vdyStatIntervalInit(&Offset->SampleInterval);
	:Offset->IntervalRangeVolume = (sint32) 0;
	:return;
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> NA
  @traceability			  - NA

  @author                 M.Sachs
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspAxleOffs(VDYWhsAxleOffs_t *Offset);


/* **********************************************************************
  @fn                     vdyWhsGetPrivateData */ /*!
  @brief           Access to general wheel speed data

  @description     Provides access to module internal data by
                   providing the pointer to that data

  @return          VDYWhsData_t: Whs Data

  @glob_in         None 
  @glob_out        WHS_GET_ME : Wheel speed processing database

  @c_switch_part   None 
  @c_switch_full   None 

  @pre             None
  @post            No changes
  @InOutCorrelation
					- return VDY Wheel speeds global data
  
	@startuml
	start
		:return(WHS_GET_ME);
	stop
	@enduml
  @testmethod			  - Module Testing \n
                            This function has to be tested for statement and branch coverage. \n
                            For detailed unit test description follow the caller graph to the test function \n
                            test_vdy_whs.c -> TEST_vdyWhsGetPrivateData_001()
  @traceability			  - NA
**************************************************************************** */
VDYWhsData_t *vdyWhsGetPrivateData(void);


/* **********************************************************************
			Unit Design for vdyWhsExec is found in vdy.h 
**************************************************************************** */
void vdyWhsExec(const VDYInputData_t* input, VDYModIf_t *mif)
{
  VDYWhsData_t *pWhsdata = WHS_GET_ME;
  
  pWhsdata->Io.in  = input;
  pWhsdata->Io.mif = mif;

  /* Distinguish between different operating states */
#if (!CFG_VDY_MFC)
	if (VDY_CTRL_GET_STATE((VDYCtrlState_t)VDY_CTRL_STATE_RUNNING, input->Frame.CtrlMode))
#else
    if (VDY_CTRL_GET_STATE( (BaseOpMode_t)BASE_OM_RUN, input->Frame.OpMode) )
#endif
  {
    /*<--- Execution path for normal operating mode --->*/
    
    VDYWhsSenData_t     *WspData;          /* RDZ general date                */
    VDYWhsOffsData_t    *WspOffsData;      /* offset data                     */
    fVelocity_t         VehicleSpeed;      /* corrected vehicle velocity      */
    VDYOutCurve_t       TrackExWsp;        /* overall curve of vehicle        */

    /* get pointer to general wheel speed data */
    WspData = WHS_GET_DATA;

    /* get pointer to offset data */
    WspOffsData = WHS_GET_OFFS;

    /* get curve calculated without wheel speeds */
    TrackExWsp.Gradient = WHS_GET_MIF_DATA->CurveInt.Gradient;
    TrackExWsp.Variance = VDY_TRACK_EX_WSP_VAR;
    TrackExWsp.Curve    = WHS_GET_MIF_DATA->Curve.Curve;

    /* get ego velocity */
    VehicleSpeed = WHS_GET_MIF_DATA->LongMot.VehVelocityCorr;

    /* get wheel speeds from module interface */
    WspData->WspFornt.WspLeft  = WHS_GET_MIF_DATA->LongMot.FLWhlVelo;
    WspData->WspFornt.WspRight = WHS_GET_MIF_DATA->LongMot.FRWhlVelo;
    if (   ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FL, input->Signals.State) == VDY_IO_STATE_VALID)
        && ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_FR, input->Signals.State) == VDY_IO_STATE_VALID))
    {
      WspData->WspFornt.WspValid = (boolean)TRUE;
    }
    else
    {
      WspData->WspFornt.WspValid = (boolean)FALSE;
    }

    WspData->WspRear.WspLeft  = WHS_GET_MIF_DATA->LongMot.RLWhlVelo;
    WspData->WspRear.WspRight = WHS_GET_MIF_DATA->LongMot.RRWhlVelo;
    if (   ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RL, input->Signals.State) == VDY_IO_STATE_VALID)
        && ((sint32)VDY_GET_IO_STATE(VDY_SIN_POS_WVEL_RR, input->Signals.State) == VDY_IO_STATE_VALID))
    {
      WspData->WspRear.WspValid = (boolean)TRUE;
    }
    else
    {
      WspData->WspRear.WspValid = (boolean)FALSE;
    }

    /* detect driving straight ahead for offset calculation */
    vdyWhsTrackStraight(&WspOffsData->ExWspStatus, &TrackExWsp);


    if (TrackExWsp.Variance >= C_F32_DELTA)
    {
      /* check gradient for offset calculation */
      vdyCalcDistStblGrad(WHS_DELTA_DIST_GRAD_MAX , TrackExWsp.Gradient, &WspOffsData->GradAbsOld, &WspOffsData->WspDeltaDist, VehicleSpeed);
    }
    else
    {
      WspOffsData->WspDeltaDist = VDY_ZERO_F;
    }

    /* save last Speed Range */
    WspOffsData->LastSpeedRange = WspOffsData->SpeedRange;

    /* determine speed range for offset calculation */
    WspOffsData->SpeedRange = vdyWhsVehSpeedRange(VehicleSpeed);
    
    /* check if next SpeedRange was reached */
    if (WspOffsData->SpeedRange != WspOffsData->LastSpeedRange)
    {
      /* Set front offset to interval mean of last speed range */
      vdyWhsSetOffIntLastRange(&WspOffsData->OffsFront,WspOffsData->SpeedRange,WspOffsData->LastSpeedRange);
      /* Set rear offset to interval mean of last speed range */
      vdyWhsSetOffIntLastRange(&WspOffsData->OffsRear,WspOffsData->SpeedRange,WspOffsData->LastSpeedRange);
    }

    /* geradeziehen der WSP Spur bei Veigen nahe Null */
    if(VehicleSpeed >= WHS_VEH_SPEED_MIN )
    {
      /* check if wheel speeds front are valid */
      if (WspData->WspFornt.WspValid == (boolean)TRUE)
      {
        /* calculate ratio left/right */ 
        vdyWhsAxleCalcRatioLeftRight(&WspData->WspFornt);

        /* calculate offset, curvature and quality of wheel speeds front */
        vdyWhsCalcOffsetAxle(&WspOffsData->OffsFront , WspData->WspFornt.Ratio, WspOffsData->SpeedRange,
                             WspOffsData->ExWspStatus, WspOffsData->WspDeltaDist);
      }

      /* check if wheel speeds rear are valid */
      if (WspData->WspRear.WspValid == (boolean)TRUE)
      {
        /* calculate ratio left/right */ 
        vdyWhsAxleCalcRatioLeftRight(&WspData->WspRear);

        /* calculate offset, curvature and quality of wheel speeds rear */
        vdyWhsCalcOffsetAxle(&WspOffsData->OffsRear , WspData->WspRear.Ratio, WspOffsData->SpeedRange, 
                             WspOffsData->ExWspStatus, WspOffsData->WspDeltaDist);

      }
    } 
  }
  else
  {
    /*<--- Execution path for initialization mode  --->*/
    vdyWhsCommonInit(pWhsdata);
  }

  return;
}


/* **********************************************************************
			Unit Design for vdyWhsInit is found in vdy.h 
**************************************************************************** */
void vdyWhsInit(void)
{
  VDYWhsData_t *pWhsdata = WHS_GET_ME;

  vdyWhsInitWspOffsData(&pWhsdata->Offset);
  vdyWhsCommonInit(pWhsdata);

  return;
}


/* **********************************************************************
			Unit Design for vdyWhsGetPrivateData is found in vdy.h 
**************************************************************************** */
VDYWhsData_t *vdyWhsGetPrivateData(void)
{
  return(WHS_GET_ME);
}


/* **********************************************************************
			Unit Design for vdyWhsGetWspAquaplaning is found in vdy.h 
**************************************************************************** */
boolean vdyWhsGetWspAquaplaning(void)
{
  VDYWhsSenData_t *WspData = WHS_GET_DATA;

  return (WspData->Aquaplaning);
}


/* **********************************************************************
			Unit Design for vdyWhsGetOffsData is found in vdy.h 
**************************************************************************** */
const VDYWhsOffsData_t *vdyWhsGetOffsData(void)
{
  return (WHS_GET_OFFS);
}


/* **********************************************************************
			Unit Design for vdyWhsOffset is found in vdy.h 
**************************************************************************** */
vdy_whs_offset_t vdyWhsOffset(void)
{
  float32 fRatio;
  float32 fDeviation;
  const VDYWhsOffsData_t *pWhsOffsData = WHS_GET_OFFS; 
  vdy_whs_offset_t vdy_whs_offset;

  /* velocity range */
  vdy_whs_offset.SpeedRange = pWhsOffsData->SpeedRange;

  /* front axle offset ratio */
  fRatio     = pWhsOffsData->OffsFront.Interval[pWhsOffsData->SpeedRange].Mean;
  fDeviation = pWhsOffsData->OffsFront.Interval[pWhsOffsData->SpeedRange].Dev;

  if (CML_f_IsZero(fRatio))
  {
    vdy_whs_offset.offset_ratio_front      = VDY_ONE_F;
    vdy_whs_offset.offset_ratio_front_dev  = VDY_ONE_F;
  }
  else
  {
    vdy_whs_offset.offset_ratio_front      = fRatio;
    vdy_whs_offset.offset_ratio_front_dev  = fDeviation;
  }

  /* rear axle offset ratio */
  fRatio     = pWhsOffsData->OffsRear.Interval[pWhsOffsData->SpeedRange].Mean;
  fDeviation = pWhsOffsData->OffsRear.Interval[pWhsOffsData->SpeedRange].Dev;


  if (CML_f_IsZero(fRatio))
  {
    vdy_whs_offset.offset_ratio_rear      = VDY_ONE_F;
    vdy_whs_offset.offset_ratio_rear_dev  = VDY_ONE_F;
  }
  else
  {
    vdy_whs_offset.offset_ratio_rear      = fRatio;
    vdy_whs_offset.offset_ratio_rear_dev  = fDeviation;
  }

  return vdy_whs_offset;
}


/* **********************************************************************
	Unit Design for vdyWhsInitAxleData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsInitAxleData(VDYWhsAxisData_t *Axle)
{
  Axle->Ratio         =   VDY_ONE_F;
  Axle->WspLeft       =   VDY_ZERO_F;
  Axle->WspRight      =   VDY_ZERO_F;
  Axle->WspLeftFilt1  =   VDY_ZERO_F;
  Axle->WspRightFilt1 =   VDY_ZERO_F;
  Axle->WspLeftFilt2  =   VDY_ZERO_F;
  Axle->WspRightFilt2 =   VDY_ZERO_F;
  Axle->WspValid      =   (boolean)FALSE;

  return;
}


/* **********************************************************************
	Unit Design for vdyWhsInitWspData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspData(VDYWhsSenData_t *WspData)
{
  vdyWhsInitAxleData(&WspData->WspFornt);
  vdyWhsInitAxleData(&WspData->WspRear);
  
  WspData->Aquaplaning          = (boolean)FALSE;
  WspData->CurveOld             = VDY_ZERO_F;
  WspData->WspFrontRaw.WspLeft  = VDY_ZERO_F;
  WspData->WspFrontRaw.WspRight = VDY_ZERO_F;
  WspData->WspRearRaw.WspLeft   = VDY_ZERO_F;
  WspData->WspRearRaw.WspRight  = VDY_ZERO_F;

#ifdef ZAWSIM32
  WspData->FilterTime        = VDY_ZERO_F;
#endif
}


/* **********************************************************************
	Unit Design for vdyWhsInitWspAxleOffs is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspAxleOffs(VDYWhsAxleOffs_t *Offset)
{
  sint32 ii;

  for (ii=0; ii < WHS_SPEEED_RANGE_VOLUME; ii++)
  {
    vdyStatIntervalInit(&Offset->Interval[ii]);
  }

  vdyStatIntervalInit(&Offset->SampleInterval);
  Offset->IntervalRangeVolume = (sint32) 0;

  return;
}


/* **********************************************************************
	Unit Design for vdyWhsCommonInit is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsCommonInit(VDYWhsData_t *pWhsdata)
{
  vdyWhsInitWspData(&pWhsdata->Sensor);

  return;
}


/* **********************************************************************
	Unit Design for vdyWhsInitWspOffsData is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsInitWspOffsData(VDYWhsOffsData_t *WspOffsData)
{
  vdyWhsInitWspAxleOffs(&WspOffsData->OffsFront);
  vdyWhsInitWspAxleOffs(&WspOffsData->OffsRear);
  WspOffsData->ExWspStatus       = (VDYCrvStatus_t) VDY_CRV_NOTOK;
  WspOffsData->SpeedRange      = VDY_ZERO;
  WspOffsData->LastSpeedRange  = VDY_ZERO;
  WspOffsData->WspDeltaDist    = VDY_ZERO_F;
  WspOffsData->GradAbsOld      = VDY_ZERO_F;

  return;
}


/* **********************************************************************
	Unit Design for vdyWhsVehSpeedRange is found in Declaration Section
**************************************************************************** */
STATIC_MTD sint32 vdyWhsVehSpeedRange(fVelocity_t VehicleSpeed)
{
  sint32      Range;
  float32      Divisor, Range_2;

  Divisor = (((WHS_OFFS_VSPEED_MAX - WHS_OFFS_VSPEED_MIN)) / (float32)(WHS_SPEEED_RANGE_VOLUME));
  Range_2 = (VehicleSpeed - WHS_OFFS_VSPEED_MIN)  / Divisor;
  Range = (sint32)Range_2;
  Range = MINMAX(0, (WHS_SPEEED_RANGE_VOLUME - 1), Range);

  return (Range);
}


/* **********************************************************************
	Unit Design for vdyWhsSetOffIntLastRange is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsSetOffIntLastRange(VDYWhsAxleOffs_t *Offset, sint32 SpeedRange, sint32 LastSpeedRange)
{

  if (   (Offset->Interval[LastSpeedRange].Volume > VDY_ZERO_F)
      && (Offset->Interval[SpeedRange].Volume <= WHS_OFFS_INIT_VOLUME))
  {
    Offset->Interval[SpeedRange].Sum = ( Offset->Interval[LastSpeedRange].Sum / Offset->Interval[LastSpeedRange].Volume ) * Offset->Interval[SpeedRange].Volume;
    Offset->Interval[SpeedRange].SqSum = ( Offset->Interval[LastSpeedRange].SqSum / Offset->Interval[LastSpeedRange].Volume ) * Offset->Interval[SpeedRange].Volume;
  }

  /* calculate offset mean value */
  vdyStatIntervalMeanDev( &Offset->Interval[SpeedRange]);
}


/* **********************************************************************
	Unit Design for vdyWhsCalcMeanFactor is found in Declaration Section
**************************************************************************** */
STATIC_MTD float32 vdyWhsCalcMeanFactor(VDYWhsAxleOffs_t *Offset, sint32 SpeedRange)
{
  float32      Factor;
  float32      Difference;

  /* filter mean of sample interval */
  Offset->SampleIntFiltMean = vdyFilterCycleTime( Offset->SampleInterval.Mean, Offset->SampleIntFiltMean, WHS_MEAN_SMPL_FT );

  /* check delta between filtered mean of sample interval with current speed range intervall*/
  Difference = fABS(Offset->SampleIntFiltMean - Offset->Interval[SpeedRange].Mean);

  if ( (Difference >= WHS_MEAN_SMPL_DIFF_THR1) && (Difference < WHS_MEAN_SMPL_DIFF_THR2) )
  {
    /* linear function for the factor */
    Factor = ( (WHS_MEAN_SMPL_MAX_FACTOR - WHS_MEAN_SMPL_MIN_FACTOR) /(WHS_MEAN_SMPL_DIFF_THR2-WHS_MEAN_SMPL_DIFF_THR1) ) * Difference;
  }  
  else
  {
    if (Difference >= WHS_MEAN_SMPL_DIFF_THR2)
    {
      Factor = WHS_MEAN_SMPL_MAX_FACTOR;
    }
    else
    {
      Factor = VDY_ONE_F;
    }
  }

  return Factor;
}


/* **********************************************************************
	Unit Design for vdyWhsCalcOffsetAxle is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsCalcOffsetAxle(VDYWhsAxleOffs_t *Offset, float32 Ratio, sint32 SpeedRange,
                                 VDYCrvStatus_t TrackStatus, fDistance_t DeltaDist )
{
  fVelocity_t  VehicleSpeed;                       /* corrected ego velocity */
  sint32      ii            = 0;                   /* loop counter */
  sint32      IntSpeedRange = 0;                   /* speed range sample interval */
  VDYCaliState_t CaliState = WHS_GET_ME->Io.in->Frame.CaliMode; /* calibration mode states */
  
  /* get ego velocity */
  VehicleSpeed = WHS_GET_MIF_DATA->LongMot.VehVelocityCorr;

  /* check if offset compensation can be done */
  if (   ( TrackStatus  == (VDYCrvStatus_t) VDY_CRV_OK  )  /* driving straight ahead? */
      && ( DeltaDist    >= WHS_DELTA_DIST_MIN  )           /* minimum driven distance with low wheel curvature reached? */ 
      && ( VehicleSpeed >= WHS_OFFS_VSPEED_MIN )           /* v ego not too small (noise too big because number of ticks too low or time too long)? */
      && ( VehicleSpeed <= WHS_OFFS_VSPEED_MAX ) )         /* v ego not too big (big offset change because tyres increase in volume (Aufquellen der Reifen)? */

  {
    /* driving straight ahead detected  */

    /* add samples only if wheel speed calibration mode is off */
    if (!VDY_CTRL_GET_STATE((VDYCaliState_t)VDY_CAL_WHS_OFFS, CaliState))
    {
      /* add value to interval */
      vdyStatIntervalAdd(&Offset->SampleInterval, Ratio, VDY_ONE_F);

      /* mark speed range, offset calculation started before overrun could occur */
      Offset->IntervalRangeVolume += SpeedRange;
    }

    if (Offset->SampleInterval.Volume >= (float32) WHS_OFFS_SINT_VOLUME_MAX)
    {
      /* calculate mean and standard deviation */
      vdyStatIntervalMeanDev( &Offset->SampleInterval);

      /* check mean and standard deviation */
      if (  (fABS(Offset->SampleInterval.Mean - VDY_ONE_F) <= (WHS_OFFS_MEAN_MAX))
          &&(Offset->SampleInterval.Dev       <= WHS_OFFS_DEV_MAX ))
      {
        /* determine speed range for complete interval */
        IntSpeedRange = Offset->IntervalRangeVolume  / (sint32) Offset->SampleInterval.Volume;
        IntSpeedRange = MINMAX (0, (WHS_SPEEED_RANGE_VOLUME - 1), IntSpeedRange); 

        /* at startup? no, then calculate offset, otherwise fill intervals for all speed ranges (else-branch) */
        if (Offset->Interval[0].Volume >= WHS_OFFS_INIT_VOLUME)
        {
          /* calculate tuning factor to rise sample interval weight */
          Offset->Factor = vdyWhsCalcMeanFactor(Offset, IntSpeedRange);
          
          /* tune up the sample interval */
          vdyStatIntervalReduce( &Offset->SampleInterval, Offset->Factor);
          
          /* take sample interval */ 
          vdyStatIntervalMerge( &Offset->Interval[IntSpeedRange], &Offset->SampleInterval);

          /* calculate mean of offset */
          vdyStatIntervalMeanDev( &Offset->Interval[IntSpeedRange]);

          /* check if offset interval should be reduced */
          if (Offset->Interval[IntSpeedRange].Volume >= WHS_OFFS_V_INT_VOL_MAX)
          {
            vdyStatIntervalReduce(&Offset->Interval[IntSpeedRange],WHS_OFFS_V_INT_RED_FACT);
          }
        }
        else 
        {
          /* fill intervals for all speed ranges at startup */ 
          for (ii=0; ii<WHS_SPEEED_RANGE_VOLUME; ii++)
          {
            /* take sample interval */ 
            vdyStatIntervalMerge( &Offset->Interval[ii], &Offset->SampleInterval);
    
            /* calculate mean of offset */
            vdyStatIntervalMeanDev( &Offset->Interval[ii]);

          } /* END FOR */
        } /* END ELSE */  
      } /* END IF */

      /* reset intervall */
      vdyStatIntervalInit(&Offset->SampleInterval);
      Offset->IntervalRangeVolume = 0; 
    }
  }
}


/* **********************************************************************
	Unit Design for vdyWhsTrackStraight is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsTrackStraight(VDYCrvStatus_t *Status, const VDYOutCurve_t *TrackExWsp)
{
  fCurve_t CurveLimit;          /* curvature limit for straight ahead driving (Grenzkruemmung fuer geradeaus) */

  /* Determine curvature limit for straight ahead driving */
  if (TrackExWsp->Variance >= WHS_STRAIGHT_QLT_HIGH)
  {
    /* curvature limit if quality is high (Grenzkruemmung bei hoher Guete) */
    CurveLimit = WHS_STRAIGHT_CMAX_QLT_HIGH ;
  }
  else
  {
    /* curvature limit if quality is low (Grenzkruemmung bei niedriger Guete) */
    CurveLimit = WHS_STRAIGHT_CMAX_QLT_LOW;
  }

  /* Check for straight ahead driving */
  *Status = vdyCheckCurve(TrackExWsp, CurveLimit, WHS_STRAIGHT_QLT_LOW);

  return;
}


/* **********************************************************************
	Unit Design for vdyWhsAxleCalcRatioLeftRight is found in Declaration Section
**************************************************************************** */
STATIC_MTD void vdyWhsAxleCalcRatioLeftRight(VDYWhsAxisData_t *Axle)
{
  if (   (Axle->WspLeft  > C_F32_DELTA)
      && (Axle->WspRight > C_F32_DELTA))
  {
    /* wheel speeds > 0  -> calculate ratio */
    Axle->Ratio = Axle->WspLeft/Axle->WspRight;
  }
  else
  {
    Axle->Ratio = VDY_ONE_F;
  }
}


/* **********************************************************************
	Unit Design for vdyWhsIsValid is found in vdy.h
**************************************************************************** */
boolean vdyWhsIsValid(void)
{
  VDYWhsSenData_t *WspData = WHS_GET_DATA;

  return (WspData->WspFornt.WspValid);
}

/** @} */ 
/* EOF */
