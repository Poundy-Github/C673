/***********************************************************************
  COMPANY:     Continental Automotive
  PROJECT:     Mainstream
  COMPONENT:   MTSI - MFC5xx custom implementation. (header)
  VERSION:     $Revision: 1.3 $
 **********************************************************************/

#ifndef MTSI_Custom_H
#define MTSI_Custom_H

#include "MTSI_Cfg.h"

#ifdef __IPL_CANTPP__
#include "MTSi_Cou_Test.h"
#endif /*__IPL_CANTPP__*/

/* PRQA S 6000,6001,6011,6030,6040 EOF *//* Reviewer:TBD, ReviewDate:TBD, ReviewID:TBD */
#ifdef __cplusplus
extern "C"
{
#endif


#define MTSI_DEM_EVENT_STATUS_FAILED DGM_EVENT_STATUS_FAILED
#define MTSI_DEM_MEASFREEZE_LOST DemConf_DemEventParameter_MTSI_MEASFREEZE_LOST_IUC

/* Configuration mode of MTSI [CONFIG_MODE_UNKNOWN, CONFIG_MODE_OFF, CONFIG_MODE_ON] */
typedef enum
{
  CONFIG_MODE_UNKNOWN = 0,  /*< Configuration mode is unknown */
  CONFIG_MODE_MTSI_OFF = 1, /*< Configuration mode is: MTSI off */
  CONFIG_MODE_MTSI_ON = 2   /*< Configuration mode is: MTSI on */
} MTSI_t_ConfigMode;

/***    User explicit entries    ***/
/* Operations */

/* Set the MTSI configuration mode <br>
 @pre                 		none
 @post                		none
 @param[in] Mode   		  Configuration mode which shall be set
 @return              		void
 @globals				 ConfigMode [CONFIG_MODE_UNKNOWN, CONFIG_MODE_OFF, CONFIG_MODE_ON]
 @InOutCorrelation       "ConfigMode" is set according to the input parameter "Mode"
 @testmethod             \ref COU_TEST_MTSI_Custom */
void MTSI_CustomSetConfigMode(const MTSI_t_ConfigMode Mode);

/* Start task cycle for BSWCyclic <br>

 @pre                 		none
 @post                		none
 @return              		void
 @testmethod             \ref COU_TEST_MTSI_Custom */
void MTSI_StartTaskCycle_BSWCyclic(void);


/* Start MTA cycle for one LVDS lane <br>
 @pre                 		none
 @post                		none
 @return              		void
 @testmethod             \ref COU_TEST_MTSI_Custom */
void MTSI_StartMtaCycle(void);

void MTSI_Dem_ReportErrorStatus(const uint16 Dem_EventIdRaw, const uint8 Dem_EventStatus, const uint8* const Dem_pui8_PreExtData, uint8 Dem_PreExtDataSize);

#ifdef __cplusplus
}
#endif

#endif
