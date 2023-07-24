/*! \file **********************************************************************

  COMPANY:                   Continental, ADAS, A.D.C. GmbH

  PROJECT:                   ARSXXX, SRRXXX

  CPU:                       CPU-Independent

  COMPONENT:                 ARCH Algorithm Architecture

  MODULNAME:                 algo_sensor_params.h

  DESCRIPTION:               -

  AUTHOR:                    -

  CREATION DATE:             -

  VERSION:                   $Revision: 1.4 $


  ---*/ /*---
  CHANGES:                   merged in SRR510 sensor 2017/05/09 Purusothaman, Thiyagarajan
  CHANGES:                   $Log: algo_sensor_params.h  $
  CHANGES:                   Revision 1.4 2017/05/15 11:15:37CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   updated SRR510 parameters
  CHANGES:                   Revision 1.3 2017/05/12 17:05:20CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added define for range gate length in EOL alignment
  CHANGES:                   Revision 1.2 2017/05/09 16:07:56CEST Purusothaman, Thiyagarajan (uidd7879) 
  CHANGES:                   changes for SRR510 based sys arch
  CHANGES:                   Revision 1.1 2017/04/24 09:53:30CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /ADAS/SW/Architecture/04_Engineering/00_Projects/ARS510/GA/algo_common/project.pj
  CHANGES:                   Revision 1.14 2017/04/20 08:29:30CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added HW version SYS_HF_BOARD_ES2_RF_DOUBLE_COLUMN
  CHANGES:                   Revision 1.13 2017/02/28 14:06:13CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   merged in ARS410 sensor
  CHANGES:                   Revision 1.12 2017/02/13 14:25:22CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   - bugfix: deactivate function ALGO_ARS510_DOUBLE_COLUMN for SRR510
  CHANGES:                   - added function ALGO_SRR520_ELEVATION_FEATURE_AVAILABLE
  CHANGES:                   Revision 1.11 2017/02/08 11:27:16CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added inline functions for double column antennae
  CHANGES:                   Revision 1.10 2016/12/22 14:43:05CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   fixed target compiler warnings
  CHANGES:                   Revision 1.9 2016/12/13 11:49:51CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   hide ALGO_f_DistRX_Y_Lambda and ALGO_f_DistRX_Z_Lambda for ARS4
  CHANGES:                   Revision 1.8 2016/12/13 11:46:04CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added define ALGO_ARSEntrySensor
  CHANGES:                   Revision 1.7 2016/12/13 10:13:53CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   merged ARS430/440 parameters to ARS510 parameters
  CHANGES:                   checked: does not change target compiler output in SW_ARS4D0_04.11.01
  CHANGES:                   Revision 1.6 2016/12/09 10:53:06CET Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added handling of double column antenna
  CHANGES:                   Revision 1.5 2016/10/07 09:59:17CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   shifted HW defines to RTE also for ARS510
  CHANGES:                   Revision 1.4 2016/09/08 15:34:30CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   HW version defines only for ARS510
  CHANGES:                   Revision 1.3 2016/08/10 11:24:12CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   added HW sample handling for resimulation of A sample recordings
  CHANGES:                   Revision 1.2 2016/07/18 13:24:30CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   bugfix for ARS510 sample for the following antenna parameters:
  CHANGES:                   ALGO_f_AzAmbigRangeNS
  CHANGES:                   ALGO_f_DistRX_Z_Lambda
  CHANGES:                   Revision 1.1 2016/07/18 12:44:49CEST Eisenacher, Michael (eisenacherm) 
  CHANGES:                   Initial revision
  CHANGES:                   Member added to project /nfs/projekte1/REPOSITORY/Base_Development/05_Algorithm/ARCH_AlgorithmArchitecture/04_Engineering/01_Source_Code/algo/algo_common/project.pj

**************************************************************************** */
#ifndef ALGO_SENSOR_PARAMS_H_INCLUDED
#define ALGO_SENSOR_PARAMS_H_INCLUDED

/* requirements
SRR520:
http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/02%5fSystem/04%5fSystem%5fDesign/01%5fSystem%5fArchitecture/project.pj&developmentPath=SMR420&selection=SMR420%5fSystemparameters.xlsx&revision=1.29
doors://rbgs854a:40000/?version=2&prodID=0&view=00000004&urn=urn:telelogic::1-503e822e5ec3651e-O-54-00041862
ARS510: doors://rbgs854a:40000/?version=2&prodID=0&view=00000004&urn=urn:telelogic::1-503e822e5ec3651e-O-587-00041862

a sample:
http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/04%5fTechnology/02%5fHF/04%5fArchitecure/01%5fDocuments/project.pj&developmentPath=SMR420&selection=ARS510SRR520%5fAMuster%5fedited%5fherb.vsd

SRR510:
http://ims-adas:7001/si/viewrevision?projectName=/nfs/projekte1/PROJECTS/SMR400/02%5fSystem/04%5fSystem%5fDesign/01%5fSystem%5fArchitecture/project.pj&developmentPath=USR130&selection=NRR520%5fSystemparameters.xlsx

*/

#include "algo_constants.h"
#include "Rte_Common.h"

/*! Configuration switch controlling if simple numeric types shall be used
instead of real enumerations. This is useful on architectures where the
compiler always allocates 'words' for enumerations, regardless of the
enumerator range */

#ifdef _MSC_VER

#define CFG_USE_COMPACT_ENUMS               1
#else
#define CFG_USE_COMPACT_ENUMS               0
#endif

/* sensor types which are supported by this configuration file */
#define ALGO_CFG_ARS400PPLUS          (0)
#define ALGO_CFG_ARS400P              (1)
#define ALGO_CFG_ARS400S              (2)
#define ALGO_CFG_ARS400Entry          (3)
#define ALGO_CFG_SRR300               (4)
#define ALGO_CFG_ARS510               (5)
#define ALGO_CFG_SRR520               (6)
#define ALGO_CFG_SRR510               (7)

/* down combatiblity */
#ifdef CFG_ARS400_PP
#define ALGO_SensorType			ALGO_CFG_ARS400PPLUS
#endif

#ifdef CFG_ARS400_PR
#define ALGO_SensorType			ALGO_CFG_ARS400P
#endif

#ifdef CFG_ARS400_EN
#define ALGO_SensorType			ALGO_CFG_ARS400Entry
#endif

#ifdef CFG_SRR300
#define ALGO_SensorType			ALGO_CFG_SRR300
#endif

#ifdef CFG_ARS510
#define ALGO_SensorType			ALGO_CFG_ARS510
#endif

#ifdef CFG_SRR520
#define ALGO_SensorType			ALGO_CFG_SRR520
#endif

#ifdef CFG_SRR510
#define ALGO_SensorType			ALGO_CFG_SRR510
#endif

#define ALGO_ARSEntrySensor ( (ALGO_SensorType == ALGO_CFG_ARS400Entry) || (ALGO_SensorType == ALGO_CFG_ARS510) )

#if(ALGO_SensorType ==  ALGO_CFG_ARS510)
/* true if ARS510 sensor with double column antenna */
ALGO_INLINE boolean ALGO_ARS510_DOUBLE_COLUMN(SYS_t_HWSample HWSample)
{
  boolean ReturnValue = FALSE;
  /* horizontal distance difference (added to every second antenna) of receiver antennae for near scan */
  if ( (HWSample.u_HighFreqBoardVersion == SYS_HF_BOARD_B0_SAMPLE_DOUBLE_COLUMN) || (HWSample.u_HighFreqBoardVersion == SYS_HF_BOARD_ES2_DOUBLE_COLUMN)|| (HWSample.u_HighFreqBoardVersion == SYS_HF_BOARD_ES2_RF_DOUBLE_COLUMN) )
  {
    ReturnValue = TRUE;
  }
  return ReturnValue;
}
#endif

#if(ALGO_SensorType ==  ALGO_CFG_SRR520)
/* true if SRR520 hw sample has elevation feature */
ALGO_INLINE boolean ALGO_SRR520_ELEVATION_FEATURE_AVAILABLE(SYS_t_HWSample HWSample)
{
  boolean ReturnValue = FALSE;
  if (HWSample.u_HighFreqBoardVersion <= SYS_HF_BOARD_B0_SAMPLE)
  {
    ReturnValue = TRUE;
  }
  return ReturnValue;
}
#endif

/* minimum and maximum possible range gate length in meters (0.2m due to potential near range chirps) */
#if ((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
  #define ALGO_f_RangeGateLengthMin	0.20f
  #define ALGO_f_RangeGateLengthEOL	0.25f
#elif ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P)||(ALGO_SensorType ==  ALGO_CFG_ARS400Entry))
  #define ALGO_f_RangeGateLengthMin	0.25f
#endif

#if (ALGO_SensorType ==  ALGO_CFG_SRR510)
  #define ALGO_f_RangeGateLengthMax	1.f
#else
  #define ALGO_f_RangeGateLengthMax	2.f
#endif

/* doppler FFT Size */
#if ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P))
#define ALGO_u_DoppFftSizeFar  512u
#endif

#define ALGO_u_DoppFftSizeNear 256u

#if(ALGO_SensorType ==  ALGO_CFG_SRR520)
  #define ALGO_u_DoppFftSizeHRR 64u
#endif

#if (ALGO_SensorType ==  ALGO_CFG_SRR510)
#define ALGO_u_DoppFftSizeFar  256u
#define ALGO_u_DoppFftSizeNear 64u
#endif

/* number of samples per chirp (after decimation) */
#if(ALGO_SensorType ==  ALGO_CFG_ARS510)
  #define ALGO_u_NumOfSamplesPerChirpNear		512
#elif(ALGO_SensorType ==  ALGO_CFG_SRR520)
  #define ALGO_u_NumOfSamplesPerChirpNear		384
  #define ALGO_u_NumOfSamplesPerChirpHRR		128 
#elif(ALGO_SensorType ==  ALGO_CFG_SRR510)
  #define ALGO_u_NumOfSamplesPerChirpNear		128	
  #define ALGO_u_NumOfSamplesPerChirpNear		64
#endif

/* number of samples per chirp (after decimation) */

#define ALGO_f_SampleFrequencyNear		6.66667e6f
#if(ALGO_SensorType ==  ALGO_CFG_SRR510)
  #define ALGO_f_SampleFrequencyNear	5e6f
#endif

#if(ALGO_SensorType ==  ALGO_CFG_SRR520)
  #define ALGO_f_SampleFrequencyHRR		5e6f
#endif

/* default transmit frequency */
#if(ALGO_SensorType ==  ALGO_CFG_ARS510)
  #define ALGO_f_TransmitFrequencyDefault	76.25e9f
#elif(ALGO_SensorType ==  ALGO_CFG_SRR520)
  #define ALGO_f_TransmitFrequencyDefault	76.75e9f
#elif ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P)||(ALGO_SensorType ==  ALGO_CFG_ARS400Entry)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
  #define ALGO_f_TransmitFrequencyDefault	76.5e9f
#endif

/* transmit frequency for EOL alignment (due to higher bandwidth) */
#define ALGO_f_TransmitFrequencyEOL	76.5e9f

#if ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P))
/* horizontal distance of receiver antennae for far scan */
#define ALGO_f_DistRXFar_Y_Lambda  2.25f
#define ALGO_f_DistRXFar_Y	       (ALGO_f_DistRXFar_Y_Lambda * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) )

/* vertical distance of receiver antennae for far scan */
#define ALGO_f_DistRXFar_Z_Lambda       2.85f
#define ALGO_f_DistRXFar_Z	            ( ALGO_f_DistRXFar_Z_Lambda * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) )

/* nominal horizontal distance of receiver antennae for near scan */
#define ALGO_f_DistRXNear_Y_Lambda	 1.4166f
#define ALGO_f_DistRXNear_Y       	( ALGO_f_DistRXNear_Y_Lambda * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) )
#endif

#if ((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
/* horizontal distance of receiver antennae for sub-beamformer 2 */
ALGO_INLINE float32 ALGO_f_DistRX_Y_Lambda (SYS_t_HWSample HWSample)
{
  float32 ReturnValue;
  /* if the following values are changed, ALGO_f_AzAmbigRangeNS has to be changed, too.*/
  #if(ALGO_SensorType ==  ALGO_CFG_ARS510)
  if (HWSample.u_HighFreqBoardVersion <= SYS_HF_BOARD_A0_SAMPLE)
  {
    ReturnValue = 2.84f;
  }
  else
  {
    ReturnValue = 3.f;
  }
  #elif(ALGO_SensorType ==  ALGO_CFG_SRR520)
    ReturnValue = 0.485f;
    HWSample;
  #elif(ALGO_SensorType ==  ALGO_CFG_SRR510)
    ReturnValue = 0.485f; //TODO: put in correct value for SRR510 antenna
    HWSample;
  #endif  
  return ReturnValue;
}
#elif (ALGO_SensorType ==  ALGO_CFG_ARS400Entry)
#define ALGO_f_DistRX_Y_Lambda  3.25f
#endif

#define ALGO_f_DistRX_Y	       (ALGO_f_DistRX_Y_Lambda * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) )

#if(ALGO_SensorType ==  ALGO_CFG_ARS510)

/* get sample dependent ppar scaling for monopulse */
ALGO_INLINE float32 ALGO_f_MonopulsePhasePparScaling(SYS_t_HWSample HWSample)
{
  float f_PparScaling;
  /* horizontal distance difference (added to every second antenna) of receiver antennae for near scan */
  if ( ALGO_ARS510_DOUBLE_COLUMN(HWSample)==TRUE )
  {
    f_PparScaling = 0.45e-3F;
  }
  else
  {
    f_PparScaling = 0.15e-3F;
  }
  return f_PparScaling;
}

/* horizontal distance of monopulse receiver antennae */
ALGO_INLINE float32 ALGO_f_DistRXMonopulse_Y_Lambda(SYS_t_HWSample HWSample)
{
  float ALGO_f_DistRXMonopulse_Y_Lambda;
  /* horizontal distance difference (added to every second antenna) of receiver antennae for near scan */
  if ( ALGO_ARS510_DOUBLE_COLUMN(HWSample)==TRUE )
  {
    ALGO_f_DistRXMonopulse_Y_Lambda = 1.f;
  }
  else
  {
    ALGO_f_DistRXMonopulse_Y_Lambda = 0.5f;
  }
  return ALGO_f_DistRXMonopulse_Y_Lambda;
}

ALGO_INLINE float32 ALGO_f_DistRXMonopulse_Y(SYS_t_HWSample HWSample)
{
  (void) HWSample;
  return (ALGO_f_DistRXMonopulse_Y_Lambda(HWSample) * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) );
}

/*Azimuth Ambigous range [rad] = ASIN_(2.0/ALGO_f_DistRX_Y_Lambda)*/
ALGO_INLINE float32 ALGO_f_AzAmbigRangeNS(SYS_t_HWSample HWSample)
{
	float32 ReturnValue;
  if (HWSample.u_HighFreqBoardVersion <= SYS_HF_BOARD_A0_SAMPLE)
	{
		ReturnValue = 0.7813f;
	}
	else
	{
		ReturnValue = 0.7297f;
	}
  return ReturnValue;
}
#elif ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P))
ALGO_INLINE float32 ALGO_GetDistRxNear_YDiff_Lambda(SYS_t_HWSample HWSample)
{
  /* horizontal distance difference (added to every second antenna) of receiver antennae for near scan */
  float ALGO_f_DistRXNear_YDiff_Lambda;

  if (HWSample <= SYS_B1_2)
  {
    ALGO_f_DistRXNear_YDiff_Lambda = 0.1876f;
  }
  else
  {
    ALGO_f_DistRXNear_YDiff_Lambda = 0.25f;
  }

  return ALGO_f_DistRXNear_YDiff_Lambda;
}

ALGO_INLINE float32 ALGO_GetDistRxNear_YDiff(SYS_t_HWSample HWSample)
{
  /* nominal horizontal distance of receiver antennae for near scan */
  return  ( ALGO_GetDistRxNear_YDiff_Lambda(HWSample) *
    (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) );
}
#elif (ALGO_SensorType ==  ALGO_CFG_ARS400Entry)
/* horizontal distance of monopulse receiver antennae */
ALGO_INLINE float32 ALGO_f_DistRXMonopulse_Y_Lambda(SYS_t_HWSample HWSample)
{
  /* horizontal distance difference (added to every second antenna) of receiver antennae for near scan */
  float ALGO_f_DistRXMonopulse_Y_Lambda;

  if (HWSample >= SYS_C1)
  {
    ALGO_f_DistRXMonopulse_Y_Lambda = 0.5416f;
  }
  else
  {
    ALGO_f_DistRXMonopulse_Y_Lambda = 0.575f;
  }

  return ALGO_f_DistRXMonopulse_Y_Lambda;
}

ALGO_INLINE float ALGO_f_DistRXMonopulse_Y(SYS_t_HWSample HWSample)
{
  return (ALGO_f_DistRXMonopulse_Y_Lambda(HWSample) * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) );
}

#define ALGO_f_AzAmbigRangeNS      0.3127667f
#endif

#if ((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
/* vertical distance of receiver antennae for far scan */
ALGO_INLINE float32 ALGO_f_DistRX_Z_Lambda (SYS_t_HWSample HWSample)
{
  float32 ReturnValue;
  #if(ALGO_SensorType ==  ALGO_CFG_ARS510)
    if (HWSample.u_HighFreqBoardVersion <= SYS_HF_BOARD_A0_SAMPLE)
	  {
		  ReturnValue = 1.f;
	  }
	  else
	  {
		  ReturnValue = 1.4f;
	  }
  #elif((ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
    ReturnValue = 0.5f;
    HWSample;
  #endif
  return ReturnValue;
}
#elif (ALGO_SensorType ==  ALGO_CFG_ARS400Entry)
#define ALGO_f_DistRX_Z_Lambda       1.f
#endif

#ifdef ALGO_f_DistRX_Z_Lambda
 #define ALGO_f_DistRX_Z	            ( ALGO_f_DistRX_Z_Lambda * (ALGO_f_SpeedOfLight / ALGO_f_TransmitFrequencyDefault) )
#endif

/* radar cycle time of sensor in seconds; affects ACTL, CAN, TP, VDY */
#if ((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510)||(ALGO_SensorType ==  ALGO_CFG_ARS400Entry))
  #define ALGO_f_RadarCycleTime	0.050f 
#elif ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P))
  #define ALGO_f_RadarCycleTime	0.076f
#endif

//TODO: for compatibility only. Remove later. Units are MILLISECS !!!
#define GLOB_CYCLE_TIME      (ALGO_f_RadarCycleTime * C_MILLISEC_SEC)   

/* maximum specified azimuth (i.e. field-of-view boundaries) [rad]*/
#if((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_ARS400Entry))
  #define ALGO_f_AzMaxSpecNear  0.785398163f /* 45° near */
#elif((ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
  #define ALGO_f_AzMaxSpecNear  1.308996939f /*  75° near */
#elif ((ALGO_SensorType ==  ALGO_CFG_ARS400PPLUS)||(ALGO_SensorType ==  ALGO_CFG_ARS400P))
  #define ALGO_f_AzMaxSpecFar   0.1570796f  
  #define ALGO_f_AzMaxSpecNear  1.047198f  
#endif

#define RSP_TIMESTAMP_TO_SECONDS     1000000.0F

/*! Conversion macro to convert cycles to lifetime */
#define CONV_CYCLES_TO_LIFETIME(c)    (c)
/*! Conversion macro to convert lifetime to cycles */
#define CONV_LIFETIME_TO_CYCLES(lt)   (lt)

#if ((ALGO_SensorType ==  ALGO_CFG_ARS510)||(ALGO_SensorType ==  ALGO_CFG_SRR520)||(ALGO_SensorType ==  ALGO_CFG_SRR510))
  /* STC characteristic */
  extern const float32 a_StcCharacteristicCurveNear[SYS_NUM_OF_RG_NEAR];
  #if(ALGO_SensorType ==  ALGO_CFG_SRR520)
    extern const float32 a_StcCharacteristicCurveHrr[SYS_NUM_OF_RG_HRR];
  #endif
#endif

#else
/* do nothing */
#endif //ALGO_SENSOR_PARAMS_H_INCLUDED
