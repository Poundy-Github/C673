/*! \file **********************************************************************

COMPANY:                   COPYRIGHT (C) Continental AG

PROJECT:                   Mainstream

CPU:                       CPU-Independent

COMPONENT:                 MEDIC (Monitoring Evaluation And Decision For Intervention Control)

PACKAGENAME:               medic_meas.c

DESCRIPTION:               MeasFreeze related functions

AUTHOR:                    $Author: Muddaveeraiah, Nalina (uidn6869) $

CREATION DATE:             $Date: 2020/07/06 15:18:14CEST $

VERSION:                   $Revision: 1.50 $

**************************************************************************** */
/*****************************************************************************
  INCLUDES
*****************************************************************************/
#include "frame_medic/medic_int.h"

/*****************************************************************************
  PROTOTYPES
*****************************************************************************/
#if (MEDIC_CFG_EMERGENCY_BRAKE_ASSIST) && (MEDIC_ARCHITECTURE_VERSION < 0x10)
void MEDIC_v_FreezePorts (MEDICPortHandlerList_t const * const pMEDIC_PortHandlerList); /*PRQA S 3447*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason:Function decl is in .c file and cant be moved to .h file*/
void MEDIC_v_FreezeWorkingData(MEDIC_Working_t const * const pWorkData); /*PRQA S 3447*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason:Function decl is in .c file and cant be moved to .h file*/

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
  INLINE FUNCTION
*****************************************************************************/

/*****************************************************************************
  FUNCTION DEFINITIONS
*****************************************************************************/
void MEDIC_v_EBAMeasCallback(void)
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

  @return           void

  @param[in]        VADDR_ : Virtual address to copy the data.
  @param[in]        ADDR_ : pointer of the data.
  @param[in]        SIZE_ : size of the data.

  @glob_in           MEDIC_p_GetServiceFuncts(),  MEDIC_v_EBAMeasCallback, MEASFreezeDataMTS
  @glob_out          MEDIC_p_GetServiceFuncts(),  MEDIC_v_EBAMeasCallback, MEASFreezeDataMTS

  @c_switch_part    MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS  
  @c_switch_full    None  

  @pre              None 
  @post             None

  @InOutCorrelation Not defined
  
  @testmethod       None

  @traceability    Design Decision

  @author          Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com

**************************************************************************** */
void MeasFreeze_Medic_GlobVar(const uint32 VADDR_,  void const * const ADDR_, const uint32 SIZE_)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = MEDIC_MEAS_FUNC_ID;
  desc.FuncChannelID  = MEDIC_MEAS_FUNC_CHAN_ID;
  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  MEDIC_p_GetServiceFuncts()->pfMeasFreeze(&desc, (void *)ADDR_, &MEDIC_v_EBAMeasCallback); /*PRQA S 0311*//*date: 2020-07-02, Reviewer:Nalina M, Reason:Generic Implementation.*/
  #else
  (void)MEASFreezeDataMTS(&desc, (void *)ADDR_, &MEDIC_v_EBAMeasCallback); /*PRQA S 0311*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason: pointer has to be of generic type*/
  #endif
  #else
  // In architectures >=10, the service pointer for meas freezing is not available to components. All freezing is done in GA
  _PARAM_UNUSED(ADDR_);  /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  _PARAM_UNUSED(VADDR_); /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  _PARAM_UNUSED(SIZE_);  /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  #endif
}

/* ****************************************************************************
  Functionname:     MeasFreeze_StackVar                                   */ /*!

  @brief            Freeze copies data immediately to internal buffer 
                    -> buffer sized is limited

  @description      WARNING: this is the BUFFERED MEASFREEZE!!
                    - to be renamed in future
                    Populates descriptor and freezes the data at given virtual 
                    address. 
                    TODO: If freeze is not successful, error should be thrown  and 
                    counter to detect measurement failures should be incremented

  @return           void
  @param[in]        VADDR_ : virtual address to which data will be copied.
  @param[in]        ADDR_ : pointer to the data
  @param[in]        SIZE_ : size of the data.
  
  @glob_in           MEDIC_p_GetServiceFuncts(), MEASFreezeDataMTS
  @glob_out          MEDIC_p_GetServiceFuncts(), MEASFreezeDataMTS

  @c_switch_part    MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS  
  @c_switch_full    None  

  @pre              None 
  @post             None

  @InOutCorrelation Not defined
  
  @testmethod       None

  @traceability     Design Decision

  @author           Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com

**************************************************************************** */
void MeasFreeze_Medic_StackVar(const uint32 VADDR_, void const * const ADDR_, const uint32 SIZE_)
{
  #if (MEDIC_ARCHITECTURE_VERSION < 0x10)
  MEASInfo_t   desc;
  desc.VirtualAddress = (VADDR_);
  desc.Length         = (SIZE_);
  desc.FuncID         = MEDIC_MEAS_FUNC_ID;
  desc.FuncChannelID  = MEDIC_MEAS_FUNC_CHAN_ID;

  #if (MEDIC_CFG_USE_SERVICE_POINTER_FUNCTS)
  ( MEDIC_p_GetServiceFuncts()->pfMeasFreeze)(&desc, (void*)ADDR_, NULL); /*PRQA S 0311*//*date: 2020-07-02, Reviewer:Nalina M, Reason:Generic Implementation.*/
  #else
  (void)MEASFreezeDataMTS(&desc, (void *)ADDR_, NULL); /*PRQA S 0311*/ /*date: 2020-07-02, Reviewer:Nalina M, Reason:pointer has to be of generic type*/
  #endif
  #else
  // In architectures >=10, the service pointer for meas freezing is not available to components. All freezing is done in GA
  _PARAM_UNUSED(VADDR_); /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  _PARAM_UNUSED(SIZE_);  /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  _PARAM_UNUSED(ADDR_);  /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
  #endif 
}

/*****************************************************************************
  FUNCTION
*****************************************************************************/

#if (MEDIC_CFG_MEASUREMENT)

/*************************************************************************************************************************
  Functionname:         MEDIC_v_FreezePorts		                                                                        */ /*!

  @brief                Do data meas freeze for MEDIC

  @description          Do data meas freeze for MEDIC
                        @startuml
                        Start
                            :Setting Up MeasInfo;
                        Note left
                            Setting Up MeasInfo Based on the configuration.
                        End note
                            :MEAS Freeze;
                        Note right
                            ->MEAS Freeze HEAD and DIM Output data Based 
                            On the configuration.
                            ->MEAS Freeze Error output and Arbitrated Output.
                        End note
                        Stop
                        @enduml
  @return               Void

  @param[in]            pMEDIC_PortHandlerList 
  
  @glob_in              None
  @glob_out             None

  @c_switch_part        @ref FCT_VEH_CFG_FREEZE_CTRL_DATA 
  @c_switch_part        @ref FCT_CFG_ERROR_OUTPUT_VEH
  @c_switch_part        @ref FCT_CFG_HYPOTHESIS_EVAL_AND_DECISION 
  @c_switch_part        @ref FCT_CFG_DRIVER_INTENTION_MONITORING 
  @c_switch_part        @ref FCT_VEH_CFG_FREEZE_USE_CALLBACK 
  @c_switch_full        @ref FCT_MEASUREMENT 
  @c_switch_full        @ref FCT_CFG_EMERGENCY_BRAKE_ASSIST    

  @pre                  None
  @post                 None

  @InOutCorrelation     Not defined 
  
  @testmethod           Test of output data (dynamic module test)

  @traceability         Design Decision
  
  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com
*************************************************************************************************************************/
void MEDIC_v_FreezePorts (MEDICPortHandlerList_t const * const pMEDIC_PortHandlerList)  /* PRQA S 3408 *//* uic45572 -function declaration is available in a different file */
{
  uint8                   uPortNo;

  /******************************/
  /* Freeze OUTPUT PORT-Data    */
  /******************************/
  for(uPortNo = 0u; uPortNo < pMEDIC_PortHandlerList->uNofProPorts; uPortNo++)
  {
    MEDICProPortHandler_t const * const pCurrPort = &(pMEDIC_PortHandlerList->ProPortHandler[uPortNo]);
    if(    (pCurrPort->pProPort           != NULL)
        && (pCurrPort->uMeasFreezeAddress != 0u  ) )
    {
      MeasFreeze_Medic_GlobVar(pCurrPort->uMeasFreezeAddress, pCurrPort->pProPort, pCurrPort->uSize);
    }
  }
}

/*************************************************************************************************************************
  Functionname:         MEDIC_v_FreezeWorkingData                                                                    */ /*!

  @brief                Freeze all data from MEDIC 

  @description          Freeze all data from MEDIC 

  @return               void
  
  @param[in]            pWorkData: pointer to the working data of MEDIC

  @glob_in              
  @glob_out             None 

  @c_switch_part        @ref MEDIC_SIMU\n
  @c_switch_full        @ref MEDIC_CFG_MEASUREMENT\n

  @pre                  None 
  @post                 None 

  @InOutCorrelation     Not defined 
  
  @traceability         Design Decision

  @author               Nagaraja Veerashettappa  | Nagaraja.Veerashettappa@continental-corporation.com 
*************************************************************************************************************************/
void MEDIC_v_FreezeWorkingData(MEDIC_Working_t const * const pWorkData) /* PRQA S 3408 *//* uic45572 -function declaration is available in a different file */
{
  #if MEDIC_CFG_USE_MEDIC_INTERNAL_MEMORY
  /* Freeze all MEAS data */
  #if (USE_MEDICWRAPPER_INTERMEAS)
  MeasFreeze_Medic_GlobVar(GA_MEDIC_MEAS_ID_INTER_CYCLE_MEAS_DATA, pWorkData->pInterCycleMeas, sizeof(MEDIC_DataWrapperInterMeas_t) ); /* PRQA S 0315 *//*uic45572 - warning does not have any functional impact */
  #endif
  #if (USE_MEDICWRAPPER_INTRAMEAS)
  MeasFreeze_Medic_GlobVar(GA_MEDIC_MEAS_ID_INTRA_CYCLE_MEAS_DATA, pWorkData->pIntraCycleMeas, sizeof(MEDIC_DataWrapperIntraMeas_t) ); /* PRQA S 0315 *//*uic45572 - warning does not have any functional impact */
  #endif

  /* In simu freeze all data */
  #ifdef MEDIC_SIMU 
  #if(USE_MEDICWRAPPER_INTER)
  MeasFreeze_Medic_GlobVar(GA_MEDIC_MEAS_ID_INTER_CYCLE_DATA,      pWorkData->pInterCycle,     sizeof(MEDIC_DataWrapperInter_t)     );
  #endif
  #if (USE_MEDICWRAPPER_INTRA)
  MeasFreeze_Medic_GlobVar(GA_MEDIC_MEAS_ID_INTRA_CYCLE_DATA,      pWorkData->pIntraCycle,     sizeof(MEDIC_DataWrapperIntra_t)     );
  #endif
  #endif /* ifdef MEDIC_SIMU*/
  #endif /* if FCT_CFG_USE_MEDIC_INTERNAL_MEMORY */

  _PARAM_UNUSED(pWorkData); /*PRQA S 3119 *//* date: 2020-07-06, Reviewer VoglA, Reason: Needed for future implementation */
}

#endif /* MEDIC_CFG_MEASUREMENT */
#endif /* MEDIC_CFG_EMERGENCY_BRAKE_ASSIST */

