/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_nvm_convert.c
  DESCRIPTION:               NVM Learning Values Version Conversion Service
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-03
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

/****************************************************************************
* INCLUDES
*****************************************************************************/

#include "vdy_nvm_convert.h" 

/****************************************************************************
* SYMBOLIC CONSTANTS
*****************************************************************************/

/****************************************************************************
* LOCAL TYPEDEFS
*****************************************************************************/

typedef struct
{
  uint32	uiTimeStamp;
  uint16	uiMeasurementCounter;
  uint16	uiCycleCounter;
  uint8		eSigStatus;
} VdySignalHeader_t;	

typedef struct
{
  float32	ZeroAngle;
  uint32	CalStatus;
} VdyNvStWhlAngCal_t;

typedef struct
{
  float32	SlfStGrad;
  uint8		SlfStGradMax;
  uint8		SlfStGradMin;
  sint8		CalStatus;
  uint8		Dummy;
} VdyNvSlfStGradCal_t;	

typedef struct
{
  float32	ZeroRate;
  float32	ZeroRateMin;
  float32	ZeroRateMax;
  uint32	CalStatus;
} VdyYwRate_t;

typedef struct
{
  float32	ZeroAccel;
  uint32	CalStatus;
} VdyLatAcc_t;

typedef struct
{
  float32	CorrFact;
  float32	Velo;
  float32	Dev;
} VdyVelCorr_t;			/* Longitudinal velocity correction */

typedef VdyVelCorr_t	VdyVelCorr_array_t[3];

typedef struct
{
  float32	Wld_front;
  float32	Wld_rear;
  uint8		Wld_front_quality;
  uint8		Wld_rear_quality;
} VdyNvWldCal_t;


/* NVM VDY struct with Interface version NVM_VDY_INTFVER_V0. */
typedef struct
{
  uint32				uiVersionNumber;
  VdySignalHeader_t		sSigHeader;
  VdyNvStWhlAngCal_t	StWhlAng;
  VdyNvSlfStGradCal_t	SlfstGrad;
  VdyYwRate_t			YwRate;
  VdyLatAcc_t			LatAcc;
  VdyVelCorr_array_t	VelCorr;
  VdyNvWldCal_t			Wld;
  uint32				State;
} VdyNvIoData_v0_t;

/*****		[**** future implementation incase of newer version ****]
typedef struct 
{
  uint32 uiVersionNumber;
  SignalHeader_t sSigHeader;
  VDYNvStWhlAngCal_t StWhlAng;
  VDYNvSlfStGradCal_t SlfstGrad;
  YwRate_t YwRate;
  LatAcc_t LatAcc;
  VelCorr_array_t VelCorr;
  VDYNvWldCal_t Wld;
  VDYNvmState_t State;
} VdyNvIoData_v1_t;
******/

/****************************************************************************
* GLOBAL VARIABLES
*****************************************************************************/
 
/****************************************************************************
* LOCAL FUNCTIONS DECLARATION
*****************************************************************************/

sint32 NvmConvertVDYNvIoData( const void* const pSource, VDYNvIoData_t* const pDest)
{
  /* Local variables. */
  sint32 retval = -1;

  if( (NULL != pSource) && (NULL != pDest) )
  {
    VdyNvIoData_v0_t temp_pSource = *(VdyNvIoData_v0_t*)pSource;
 
//	VdyNvIoData_v0_t* vdy_nvm_v0;
 // VdyNvIoData_v0_t* vdy_nvm_v1;		[**** future implementation incase of newer version ****]

	switch( temp_pSource.uiVersionNumber )
	{
	case NVM_VDY_INTFVER_V0:
		if( NVM_VDY_INTFVER_V0 ==  pDest->uiVersionNumber)
		{
          *((VdyNvIoData_v0_t*)pDest) = *((VdyNvIoData_v0_t*)pSource);
		}		
/*****  else if( NVM_VDY_INTFVER_V1 == DestVersion )		[**** future implementation incase of newer version ****]
		{
          vdy_nvm_v0 = (VdyNvIoData_v0_t*)pSource;
          vdy_nvm_v1 = (VdyNvIoData_v1_t*)pDest;

		  //v1 <== v0
		  vdy_nvm_v1->uiVersionNumber = NVM_VDY_INTFVER_V1;
		  v1.x = v0.x;
		}
		else
		{
          retval = -1;
		}
		break;
	case NVM_VDY_INTFVER_V1:
		if( NVM_VDY_INTFVER_V1 == DestVersion )
		{
          *((VdyNvIoData_v1_t*)pDest) = *vdy_nvm_v1;
		}************/
		else
		{
          retval = -1;
		}
		break;
	default:
		retval = -2;
		break;
	}
  }
  return retval;
}

/* EOF */

