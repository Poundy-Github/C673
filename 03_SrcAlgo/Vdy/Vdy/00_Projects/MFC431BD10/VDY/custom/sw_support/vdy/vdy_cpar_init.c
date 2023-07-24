/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431SW19
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_cpar_init.c
  DESCRIPTION:               Initializer code for CodingParameters (CPar)
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-01
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

/****************************************************************************
* INCLUDES
*****************************************************************************/
#include "vdy_cpar_init.h" 

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/
 
/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
 
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/

/*****************************************************************************
  MACROS
*****************************************************************************/
#undef DEG2RADIAN
#define DEG2RADIAN(deg_)           ( (deg_) * (3.14159265359f / 180.f) )


void CParInitVehPar_HA2HF ( VehPar_t* const Dest )
{
  /* local variable(s) */
  int i;

  /* set values if pointer is valid */
  if( Dest != 0 )
  {
    Dest->uiVersionNumber		=	BSW_VEH_PAR_INTFVER;
    Dest->sSigHeader.eSigStatus	=	AL_SIG_STATE_OK;

    /* set all states to INIT */
    for( i = 0; i < VDY_PAR_POS_MAX; i++ )
    {
      Dest->VehParMain.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_ADD_MAX; i++ )
    {
      Dest->VehParAdd.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_SEN_MOUNT_MAX; i++ )
    {
      Dest->SensorMounting.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_SENSOR_MAX; i++ )
    {
      Dest->Sensor.State[i]		=	VDY_IO_STATE_INIT;
    }

    /* VehParMain */
    Dest->VehParMain.SelfSteerGrad		        =0.0035F;
    Dest->VehParMain.SteeringRatio.swa.ang[0]	=0.0F;
    Dest->VehParMain.SteeringRatio.swa.ang[1]	=0.0F;
    Dest->VehParMain.SteeringRatio.swa.rat[0]	=14.35F;
    Dest->VehParMain.SteeringRatio.swa.rat[1]	=14.35F;
    Dest->VehParMain.SteeringRatio.vel.vel[0]	=1.0F;
    Dest->VehParMain.SteeringRatio.vel.vel[1]	=1.0F;
    Dest->VehParMain.SteeringRatio.vel.rat[0]	=1.0F;
    Dest->VehParMain.SteeringRatio.vel.rat[1]	=1.0F;
    Dest->VehParMain.WheelBase			        =2.7F;
    Dest->VehParMain.TrackWidthFront		    =1.5726F;
    Dest->VehParMain.TrackWidthRear		        =1.5728F;
    Dest->VehParMain.VehWeight			        =1783.0F;
    Dest->VehParMain.CntrOfGravHeight		    =0.55F;
    Dest->VehParMain.AxisLoadDistr		        =0.569F;
    Dest->VehParMain.WhlLoadDepFrontAxle	    =1.0F;
    Dest->VehParMain.WhlLoadDepRearAxle		    =1.0F;
    Dest->VehParMain.WhlCircumference		    =2.0985F;
    Dest->VehParMain.DrvAxle			        =0U;
    Dest->VehParMain.WhlTcksPerRev		        =96U;
    Dest->VehParMain.FrCrnrStiff		        =0.0F;
    Dest->VehParMain.ReCrnrStiff		        =0.0F;	

    VDY_SET_IO_STATE( VDY_PAR_POS_SSG      , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_SWARAT   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WBASE    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_TWDFR    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_TWDRE    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_VEHWGT   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_COGH     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_AXLD     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLDFR   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLDRE   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLCIR   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_DRVAXL   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WTCKSREV , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_CSFR     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_CSRE     , VDY_IO_STATE_VALID , Dest->VehParMain.State );	

    /* VehParAdd */
    Dest->VehParAdd.CurbWeight			=1596.0F;
    Dest->VehParAdd.FrontAxleRoadDist	=0.0F;
    Dest->VehParAdd.OverhangFront		=0.988F;
    Dest->VehParAdd.SteeringVariant		=VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE;
    Dest->VehParAdd.VehicleWidth		=1.845F;
    Dest->VehParAdd.WheelWidth			=0.3F;
    Dest->VehParAdd.PassableHeight		=1.51F;
    Dest->VehParAdd.DistCameraToHoodX	=1.4713F;
    Dest->VehParAdd.DistCameraToHoodY	=0.4059F;
	Dest->VehParAdd.VehicleLength 		=4.777F;
	
    VDY_SET_IO_STATE( VEH_PAR_ADD_VEHICLE_WIDTH      , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_CURB_WEIGHT        , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_OVERHANG_FRONT     , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_FRONT_AXLE_ROAD    , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_WHEEL_WIDTH        , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_STEERING_VARIANT   , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_PASSABLE_HEIGHT    , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_DIST_CAMERA_HOOD_X , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_DIST_CAMERA_HOOD_Y , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
	VDY_SET_IO_STATE( VEH_PAR_ADD_VEHICLE_LENGTH 	 , VDY_IO_STATE_VALID , Dest->VehParAdd.State );

    /* SensorMounting */
    Dest->SensorMounting.LatPos		 =0.0086F;
    Dest->SensorMounting.LongPos	 =-0.888F;
    Dest->SensorMounting.VertPos	 =1.3417F;
    Dest->SensorMounting.LongPosToCoG=Dest->SensorMounting.LongPos + (Dest->VehParMain.WheelBase * Dest->VehParMain.AxisLoadDistr);
	Dest->SensorMounting.PitchAngle	 =-0.007016F;
    Dest->SensorMounting.RollAngle	 =0.0F;
    Dest->SensorMounting.YawAngle	 =0.0F;

    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LAT_POS        , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LONG_POS       , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_VERT_POS       , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_PITCH_ANGLE    , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_ROLL_ANGLE    , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_YAW_ANGLE      , VDY_IO_STATE_VALID , Dest->SensorMounting.State );

    /* Sensor */
    Dest->Sensor.CoverDamping	=0.0F;
    Dest->Sensor.fCoverageAngle	=0.0F;
    Dest->Sensor.fCycleTime		=0.0F;
    Dest->Sensor.fLobeAngle		=0.0F;
    Dest->Sensor.uNoOfScans		=0U;

    /* states left at INIT as Sensor parameters are not used in MFC environments */
 }
  else
  {
	  //Do Nothing
  }
}

void CParInitVehPar_HA2EM ( VehPar_t* const Dest ) 
{
  /* local variable(s) */
  int i;

  /* set values if pointer is valid */
  if( Dest != 0 )
  {
    Dest->uiVersionNumber		=	BSW_VEH_PAR_INTFVER;
    Dest->sSigHeader.eSigStatus	=	AL_SIG_STATE_OK;

    /* set all states to INIT */
    for( i = 0; i < VDY_PAR_POS_MAX; i++ )
    {
      Dest->VehParMain.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_ADD_MAX; i++ )
    {
      Dest->VehParAdd.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_SEN_MOUNT_MAX; i++ )
    {
      Dest->SensorMounting.State[i]	=	VDY_IO_STATE_INIT;
    }
    for( i = 0; i < VEH_PAR_SENSOR_MAX; i++ )
    {
      Dest->Sensor.State[i]		=	VDY_IO_STATE_INIT;
    }

    /* VehParMain */
    Dest->VehParMain.SelfSteerGrad			 = 0.0035F;
    Dest->VehParMain.SteeringRatio.swa.ang[0]= 0.0F;
    Dest->VehParMain.SteeringRatio.swa.ang[1]= 0.0F;
    Dest->VehParMain.SteeringRatio.swa.rat[0]= 14.35F;
    Dest->VehParMain.SteeringRatio.swa.rat[1]= 14.35F;
    Dest->VehParMain.SteeringRatio.vel.vel[0]= 1.0F;
    Dest->VehParMain.SteeringRatio.vel.vel[1]= 1.0F;
    Dest->VehParMain.SteeringRatio.vel.rat[0]= 1.0F;
    Dest->VehParMain.SteeringRatio.vel.rat[1]= 1.0F;
    Dest->VehParMain.WheelBase 				 = 2.7F;
    Dest->VehParMain.TrackWidthFront		 = 1.5725F;
    Dest->VehParMain.TrackWidthRear 		 = 1.5731F;
    Dest->VehParMain.VehWeight 				 = 1852.0F;
    Dest->VehParMain.CntrOfGravHeight 		 = 0.506F;
    Dest->VehParMain.AxisLoadDistr 			 = 0.5225F;
    Dest->VehParMain.WhlLoadDepFrontAxle 	 = 1.0F;
    Dest->VehParMain.WhlLoadDepRearAxle 	 = 1.0F;
    Dest->VehParMain.WhlCircumference 		 = 2.1F;
    Dest->VehParMain.DrvAxle 				 = 0U;
    Dest->VehParMain.WhlTcksPerRev 			 = 96U;
    Dest->VehParMain.FrCrnrStiff 			 = 0.0F;
    Dest->VehParMain.ReCrnrStiff 			 = 0.0F;


    VDY_SET_IO_STATE( VDY_PAR_POS_SSG      , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_SWARAT   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WBASE    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_TWDFR    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_TWDRE    , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_VEHWGT   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_COGH     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_AXLD     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLDFR   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLDRE   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WHLCIR   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_DRVAXL   , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_WTCKSREV , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_CSFR     , VDY_IO_STATE_VALID , Dest->VehParMain.State );
    VDY_SET_IO_STATE( VDY_PAR_POS_CSRE     , VDY_IO_STATE_VALID , Dest->VehParMain.State );

	

    /* VehParAdd */
    Dest->VehParAdd.CurbWeight        = 1665.0F;
    Dest->VehParAdd.FrontAxleRoadDist = 0.0F;
    Dest->VehParAdd.OverhangFront     = 1.0178F;
    Dest->VehParAdd.SteeringVariant   = VEH_PAR_ADD_STEERING_VAR_LEFT_SIDE;
    Dest->VehParAdd.VehicleWidth      = 1.845F;
    Dest->VehParAdd.WheelWidth        = 0.3F;
    Dest->VehParAdd.PassableHeight    = 1.52F;
    Dest->VehParAdd.DistCameraToHoodX = 1.4713F;
    Dest->VehParAdd.DistCameraToHoodY = 0.4059;
	Dest->VehParAdd.VehicleLength 	  = 4.798F;

    VDY_SET_IO_STATE( VEH_PAR_ADD_VEHICLE_WIDTH      , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_CURB_WEIGHT        , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_OVERHANG_FRONT     , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_FRONT_AXLE_ROAD    , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_WHEEL_WIDTH        , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_STEERING_VARIANT   , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_PASSABLE_HEIGHT    , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_DIST_CAMERA_HOOD_X , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
    VDY_SET_IO_STATE( VEH_PAR_ADD_DIST_CAMERA_HOOD_Y , VDY_IO_STATE_VALID , Dest->VehParAdd.State );
	VDY_SET_IO_STATE( VEH_PAR_ADD_VEHICLE_LENGTH 	 , VDY_IO_STATE_VALID , Dest->VehParAdd.State );

    /* SensorMounting */
	Dest->SensorMounting.LatPos 	 = 0.0086F;
	Dest->SensorMounting.LongPos 	 = -0.888F;
	Dest->SensorMounting.VertPos 	 = 1.3491F;
	Dest->SensorMounting.LongPosToCoG= Dest->SensorMounting.LongPos + (Dest->VehParMain.WheelBase * Dest->VehParMain.AxisLoadDistr);
	Dest->SensorMounting.PitchAngle  = -0.009023F;
	Dest->SensorMounting.RollAngle 	 = 0.0F;
	Dest->SensorMounting.YawAngle 	 = 0.0F;

    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LAT_POS        , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LONG_POS       , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_VERT_POS       , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_LONGPOS_TO_COG , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_PITCH_ANGLE    , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_ROLL_ANGLE    , VDY_IO_STATE_VALID , Dest->SensorMounting.State );
    VDY_SET_IO_STATE( VEH_PAR_SEN_MOUNT_YAW_ANGLE      , VDY_IO_STATE_VALID , Dest->SensorMounting.State );

    /* Sensor */
    Dest->Sensor.CoverDamping	=0.0F;
    Dest->Sensor.fCoverageAngle	=0.0F;
    Dest->Sensor.fCycleTime		=0.0F;
    Dest->Sensor.fLobeAngle		=0.0F;
    Dest->Sensor.uNoOfScans		=0U;

    /* states left at INIT as Sensor parameters are not used in MFC environments */
 }
  else
  {
	  //Do Nothing
  }
}

/* EOF */
