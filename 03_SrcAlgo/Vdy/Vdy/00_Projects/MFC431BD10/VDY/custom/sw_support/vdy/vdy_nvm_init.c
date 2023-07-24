/*! \file **********************************************************************

  COMPANY:                   Continental AG, ADAS, A.D.C. GmbH
  PROJECT:                   MFC431
  CPU:                       CPU-Independent
  COMPONENT:                 VDY
  MODULNAME:                 vdy_nvm_init.c
  DESCRIPTION:               NVM Learning Values Initialization Service
  AUTHOR:                    Jayashree K Jahagirdar
  CREATION DATE:             2017-02-02
  VERSION:                   $$
  ---*/ /*---
  CHANGES:                   $$
**************************************************************************** */

/****************************************************************************
* INCLUDES
*****************************************************************************/
//#include "sys_mem.h"
#include "vdy_nvm_init.h" 

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

void NvmInitVDYNvIoData ( VDYNvIoData_t* const Dest, boolean bCalibReset )
{
  if(( Dest != NULL) && ( bCalibReset == b_FALSE ))
  {
	Dest->uiVersionNumber				  =	VDY_NVM_IO_DATA_INTFVER;
	Dest->sSigHeader.eSigStatus			  =	AL_SIG_STATE_OK;
	Dest->sSigHeader.uiCycleCounter		  =	0u;
	Dest->sSigHeader.uiMeasurementCounter =	0u;
	Dest->sSigHeader.uiTimeStamp		  =	0u;

	//for( i = 0; i < VDY_NVM_POS_MAX; i++ )
	{
      Dest->State	=	VDY_IO_STATE_VALID;
	}

	(void)memset( &Dest->LatAcc,	0, sizeof(Dest->LatAcc   )	);
	(void)memset( &Dest->SlfstGrad, 0, sizeof(Dest->SlfstGrad)	);
	(void)memset( &Dest->StWhlAng,	0, sizeof(Dest->StWhlAng )	);
	(void)memset( &Dest->VelCorr,	0, sizeof(Dest->VelCorr  )	);
	(void)memset( &Dest->Wld,		0, sizeof(Dest->Wld      )	);
	(void)memset( &Dest->YwRate,	0, sizeof(Dest->YwRate   )	);	
  }
}

/* EOF */
