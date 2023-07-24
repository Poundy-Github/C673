/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG
  
PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 ACDC - Advanced collision detection and classification

PACKAGENAME:               acdc_meas.c

DESCRIPTION:               This module manages the measurement output of ACDC

AUTHOR:                    $Author: Annareddy, Praveen Kumar Reddy (uic32343) (uic32343) $

CREATION DATE:             $Date: 2020/11/10 05:03:42CET $

VERSION:                   $Revision: 1.30 $
**************************************************************************** */

/*****************************************************************************
  INCLUDE
*****************************************************************************/
#include "acdc_int.h"

#if (ACDC_CFG_FRAME)

/*****************************************************************************
  MODULE DESCRIPTION
*****************************************************************************/
/*!
@defgroup         acdc_meas Measurement
@ingroup          frame
@brief            This module manages the measurement output of the ACDC component.\n\n
@description      The following functionalities are provided by this module:
                  - Freezing of all In- and Output interfaces: @ref ACDC_v_ProcessMeasFreeze
@{
*/

/*****************************************************************************
  MACROS
*****************************************************************************/


/*****************************************************************************
  TYPEDEFS
*****************************************************************************/


/*****************************************************************************
  (SYMBOLIC) CONSTANTS
*****************************************************************************/

/*****************************************************************************
  VARIABLES
*****************************************************************************/

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
void ACDC_v_MeasCallback(void)
{
  /*! Callback function is a dummy */
  return;
}
/* ****************************************************************************
  Functionname:     MeasFreeze_GlobVar                                   */ /*!

  @brief            Freeze job uses application buffer
                    -> referenced data has to be kept global or static

  @description      WARNING: this is the UNBUFFERED MEASFREEZE!!
                    - to be renamed in future.
                    Populates descriptor of the data and address to freeze the data.
                    Throws error if freeze is not successful.

  @param[in]        VADDR_ : Virtual address to copy the data.
  @param[in]        ADDR_ : pointer of the data.
  @param[in]        SIZE_ : size of the data.

  @glob_in          @ref ACDC_p_GetServiceFunctionsList
  @glob_out         None

  @return           void

  @pre              None
  @post             No changes

  @author           Florian Foelster
**************************************************************************** */
void MeasFreeze_GlobVar(uint32 VADDR_,  void const * ADDR_, uint32 SIZE_)
{
#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  AS_t_ServiceFuncts const * const pServiceFuncts = ACDC_p_GetServiceFunctionsList();
#endif
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = ACDC_MEAS_FUNC_ID;
  desc.FuncChannelID  = ACDC_MEAS_FUNC_CHAN_ID;

#if (FCT_CFG_USE_SERVICE_POINTER_FUNCTS)
  if(pServiceFuncts != NULL )
  {
    if(pServiceFuncts->pfMeasFreeze!=NULL)
    {
      /* PRQA S 311 1 */ /* Andreas Kramer: Cast is OK here, Ensures compatibility with freeze function */
      (pServiceFuncts->pfMeasFreeze)(&desc, (void*)ADDR_, &ACDC_v_MeasCallback);
    }
  }
#else
  /* PRQA S 311 1 */ /* Andreas Kramer: Cast is OK here, Ensures compatibility with freeze function */
  (void)MEASFreezeDataMTS(&desc, (void*)ADDR_, &ACDC_v_MeasCallback);
#endif
}
#if (FCT_MEASUREMENT)

/*************************************************************************************************************************
  Functionname:    ACDC_v_ProcessMeasFreeze                                                                          */ /*!

  @brief           Calls all relevant functions to freeze all required data of FCT.

  @description     Freezes all relevant FCT Data by calling the freeze function for all output ports.
                   Additionally the trajectory data is frozen.

  @return          void
  
  @param[in,out]   pACDC_PortHandlerList

  @glob_in         None
  @glob_out        None

  @c_switch_part   None
  @c_switch_full   @ref ACDC_CFG_FRAME \n
                   @ref FCT_MEASUREMENT

  @pre             None
  @post            None

  
  @testmethod      @ref TEST_ACDC_V_FREEZEPORTS_001 \n
                   @ref TEST_ACDC_V_FREEZEPORTS_002

  @traceability    Design Decision

  @author          Andreas Kramer
*************************************************************************************************************************/
void ACDC_v_FreezePorts(ACDCPortHandlerList_t const * const pACDC_PortHandlerList)
{
  uint8                   uPortNo;

  /******************************/
  /* Freeze OUTPUT PORT-Data    */
  /******************************/

  for(uPortNo = 0; uPortNo < pACDC_PortHandlerList->uNofProPorts; uPortNo++)
  {
    ACDCProPortHandler_t const * const pCurrPort = &(pACDC_PortHandlerList->ProPortHandler[uPortNo]);
    if(    (pCurrPort->pProPort           != NULL)
        && (pCurrPort->uMeasFreezeAddress != 0u   ) )
    {
      /*PRQA S 0315 1*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
      MeasFreeze_GlobVar(pCurrPort->uMeasFreezeAddress, pCurrPort->pProPort, pCurrPort->uSize);
    }
  }
}

/*************************************************************************************************************************
  Functionname:         ACDC_v_FreezeWorkingData                                                                    */ /*!

  @brief                Freeze all data from ACDC 

  @description          Freeze all data from ACDC 

  @return               void
  
  @param[in]            pWorkData: pointer to the working data of ACDC

  @glob_in              
  @glob_out             None 

  @c_switch_part        @ref ACDC_SIMU\n
  @c_switch_full        @ref FCT_MEASUREMENT\n

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not defined 

  @testmethod           @ref TEST_ACDC_V_FREEZEWORKINGDATA_001

  @traceability         Design Decision
  
  @author               Andreas Kramer | Andreas.Kramer@continental-corporation.com | +49 (8382) 9699-246
*************************************************************************************************************************/
void ACDC_v_FreezeWorkingData(ACDC_Working_t const * const pWorkData)
{

#if FCT_CFG_USE_ACDC_INTERNAL_MEMORY
  /*PRQA S 0315 26*/ /* date: 2019-05-14, reviewer: Schnurr, Clemens, reason: Case to void intended as use of generic interface*/
  /* Freeze all MEAS data */
#if (USE_ACDCWRAPPER_INTERMEAS)
  MeasFreeze_GlobVar(GA_ACDC_MEAS_ID_INTER_CYCLE_MEAS_DATA, pWorkData->pInterCycleMeas, sizeof(ACDC_DataWrapperInterMeas_t) );
#endif
#if (USE_ACDCWRAPPER_INTRAMEAS)
  MeasFreeze_GlobVar(GA_ACDC_MEAS_ID_INTRA_CYCLE_MEAS_DATA, pWorkData->pIntraCycleMeas, sizeof(ACDC_DataWrapperIntraMeas_t) );
#endif

/* In simu freeze all data */
#ifdef ACDC_SIMU                                                                               
  MeasFreeze_GlobVar(GA_ACDC_MEAS_ID_INTER_CYCLE_DATA,      pWorkData->pInterCycle,     sizeof(ACDC_DataWrapperInter_t)     );
#if (USE_ACDCWRAPPER_INTRA)
  MeasFreeze_GlobVar(GA_ACDC_MEAS_ID_INTRA_CYCLE_DATA,      pWorkData->pIntraCycle,     sizeof(ACDC_DataWrapperIntra_t)     );
#endif
#if (USE_ACDCWRAPPER_SIMU)
  MeasFreeze_GlobVar(GA_ACDC_MEAS_ID_SIMU,                  pWorkData->pSimuData,       sizeof(ACDC_DataWrapperSimu_t)      );
#endif
#endif /* #ifdef ACDC_SIMU*/
#endif /* #if FCT_CFG_USE_ACDC_INTERNAL_MEMORY */

  /* In the simulation freeze the variables from the stack. This has to be done inside of the component. */
#ifdef ACDC_SIMU
#if USE_ACDCWRAPPER_STACK
  MeasFreeze_StackVar(GA_ACDC_MEAS_ID_STACK,                pWorkData->pStackData,      sizeof(ACDC_DataWrapperStack_t)     );
#endif
#endif
  _PARAM_UNUSED(pWorkData);/* PRQA S 3119 # Date:2020-06-01, Reviewer: Praveen Annareddy , Reason: Compiler throws warning, if code is removed */
}


#endif  /* #if FCT_MEASUREMENT */
///@}
#endif /*!(ACDC_CFG_FRAME) */

