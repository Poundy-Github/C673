// **********************************************************************
// 
//COMPANY:     Continental Automotive 
// 
//PROJECT:     ARS400
//    
//CPU:         MPC577xN, MPC567xK, SPC56AP60
// 
//Component:   Mts_Adaption_Cmp
// 
//MODULNAME:   FullModelElementName
// 
//Description:  variant to configure project specific parameters like buffer size, amount of jobs (see package description)
// 
// **********************************************************************         


#ifndef Mts_Adaption_ARS400_H
#define Mts_Adaption_ARS400_H

/*## package ARS400_SW_Algo_Pkg::Radar_Pkg::ComplexDeviceDrivers_Pkg::Mts_Adaption_Pkg */

/*## class TopLevel::Mts_Adaption_ARS400 */
/*#[ ignore */
//Description:  variant to configure project specific parameters like buffer size, amount of jobs (see package description)
/*#]*/

#ifndef Std_Types_H
#include "Std_Types.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif


//- Description:	language just available for backward compatibility
//- Range:		none
//- Resolution:	none
//- Unit:		none

/* ########################################################################################################## */

//- Description:	JüGi: Added this as interrims solution until these are available in some other glob or MTS header.
//- Description:	Interims solution. Deletet this after this type is not used in DEM sources, anymore.
#define MEAS_MAIN_CYCLE_ID       60u    /*! Cycle ID of main cycle */
#define MEAS_VDY_CYCLE_ID        20u    /*! Cycle ID of vdy cycle */

/* ########################################################################################################## */


//Description:  version number of adaption
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_VER_ADAP_H */
#define MTS_VER_ADAP_H ((uint8) 8)

//Description:  just spacer for better readability
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SPACER0 */
#define MTS_SPACER0 0 /* ----------------------------------------------------------------------------------- */

//Description:  max number of mts jobs
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_MAX_NO_OF_JOBS_CORE0 */
#define MTS_MAX_NO_OF_JOBS_CORE0 500u

//Description:  modulo bit for DMA
//Important: modulo 14 -> 2^n -> 16384 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_DMA_SMOD_CORE0 */
#define MTS_DMA_SMOD_CORE0 14u  /* [Bit] ATT: modulo 14 -> 2^n -> 16384 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!! */

//Description:  max buffer size for each core (payload data)
//Important: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SIZE_OF_BUFFER_CORE0 */
#define MTS_SIZE_OF_BUFFER_CORE0 (16u*1024u)    /* ATT: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */

//Description:  just spacer for better readability
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SPACER1 */
#define MTS_SPACER1 0 /* ----------------------------------------------------------------------------------- */

//Description:  max number of mts jobs
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_MAX_NO_OF_JOBS_CORE1 */
#define MTS_MAX_NO_OF_JOBS_CORE1 200u

//Description:  modulo bit for DMA
//Important: modulo 14 -> 2^n -> 16384 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_DMA_SMOD_CORE1 */
#define MTS_DMA_SMOD_CORE1 13u  /* [Bit] ATT: modulo 13 -> 2^n -> 8192 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!! */

//Description:  max buffer size for each core (payload data)
//Important: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SIZE_OF_BUFFER_CORE1 */
#define MTS_SIZE_OF_BUFFER_CORE1 (8u*1024u)    /* ATT: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */

//Description:  just spacer for better readability
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SPACER2 */
#define MTS_SPACER2 0 /* ----------------------------------------------------------------------------------- */

//Description:  max number of mts jobs
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_MAX_NO_OF_JOBS_CORE2 */
#define MTS_MAX_NO_OF_JOBS_CORE2 100u

//Description:  modulo bit for DMA
//Important: modulo 14 -> 2^n -> 16384 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_DMA_SMOD_CORE2 */
#define MTS_DMA_SMOD_CORE2 11u  /* [Bit] ATT: modulo 11 -> 2^n -> 2048 Byte | Calculated value (2^n) must be the same value as in MTS_MAX_NO_OF_JOBS_COREn defined!! */

//Description:  max buffer size for each core (payload data)
//Important: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SIZE_OF_BUFFER_CORE2 */
#define MTS_SIZE_OF_BUFFER_CORE2 (2u*1024u)    /* ATT: MUST be a multiple of 2^n because of DMA modulo mode | check also MTS_DMA_SMOD_COREn, must be the same calculated value (2^n) */

//Description:  just spacer for better readability
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_SPACER3 */
#define MTS_SPACER3 0 /* ----------------------------------------------------------------------------------- */

//Description:  max number of mts jobs
//Range:        -
//Resolution:   -
//Unit:         -
/*## attribute MTS_MAX_NO_OF_PEAK_JOBS */
#define MTS_MAX_NO_OF_PEAK_JOBS 30u

/***    User explicit entries    ***/


#ifdef __cplusplus
}
#endif


#endif
/*********************************************************************
	File Path	: ..\..\..\04_Engineering\_gensrc\rhapsody\Mts_Adaption_ARS400.h
*********************************************************************/

