
/* PRQA S 0715 EOF */ /* MD_MSR_1.1_715 */
/* PRQA S 0850 EOF */ /* MD_MSR_MacroArgumentEmpty */
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */
/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */
/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* ********************************************************************************************************************
 *  INCLUDES
 * *******************************************************************************************************************/
#define CANTRCV_TJA1043_INCLUDE_INTERNAL
#define V_CANTRCV_TJA1043_SOURCE

/* \trace SPEC-19973, SPEC-20008, SPEC-19954, SPEC-19965 */
/* \trace SPEC-14977, SPEC-15093, SPEC-15086, SPEC-14969 */
#include "CanTrcv_8_Tja1043.h"


# include "Dio.h"

#include "CanIf.h"

#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
# include "Det.h"
#endif

#include "EcuM.h"




/* *********************************************************************************************************************
 *  VERSION CHECK
 * ********************************************************************************************************************/

#if (DRVTRANS__CORECANXASR_VERSION                             != 0x0507u)
# error "Module CanTrcv_Tja1043: Source and Header files are inconsistent!"
#endif
#if (DRVTRANS__CORECANXASR_RELEASE_VERSION                     != 0x00u)
# error "Module CanTrcv_Tja1043: Source and Header files are inconsistent!"
#endif


/* ** Version Check: CFG5 - Base part ** */
#define CANTRCV_TJA1043_BASE_GENDATA_COMP_VERSION     0x0105u

#if (CANTRCV_TJA1043_GENTOOL_CFG5_BASE_COMP_VERSION != CANTRCV_TJA1043_BASE_GENDATA_COMP_VERSION)
# error "Module CanTrcv_Tja1043: Source and Generated Header files are inconsistent! [BASE]"
#endif




# if (DRVTRANS_TJA1043CANDIOASR_VERSION                    != 0x0404u)
#  error "Module CanTrcv_Tja1043: Source and Header files are inconsistent!"
# endif
# if (DRVTRANS_TJA1043CANDIOASR_RELEASE_VERSION            != 0x00u)
#  error "Module CanTrcv_Tja1043: Source and Header files are inconsistent!"
# endif

/* ** Version Check: CFG5 - HW specific part ** */
#define CANTRCV_TJA1043_HW_GENDATA_COMP_VERSION     0x0104u

#if (CANTRCV_TJA1043_GENTOOL_CFG5_HW_COMP_VERSION != CANTRCV_TJA1043_HW_GENDATA_COMP_VERSION)
# error "Module CanTrcv_Tja1043: Source and Generated Header files are inconsistent!"
#endif




# if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252)
#  error "Configuration error: Only one HWVARIANTGROUP must be defined at most"
# endif


/* ********************************************************************************************************************
 *  LOCAL DEFINES
 * ********************************************************************************************************************/


#if !defined (CANTRCV_TJA1043_LOCAL)
# define CANTRCV_TJA1043_LOCAL             static
#endif

#if !defined (CANTRCV_TJA1043_LOCAL_INLINE)
# define CANTRCV_TJA1043_LOCAL_INLINE      LOCAL_INLINE
#endif



#define CanTrcvCfg_IsChannelUsed(ch)                   CanTrcv_Tja1043_IsChannelUsed(ch)
#define CanTrcvCfg_IsWakeupByBusUsed(ch)               CanTrcv_Tja1043_IsWakeupByBusUsed(ch)
#define CanTrcvCfg_GetWakeupSource(ch)                 CanTrcv_Tja1043_GetWakeupSource(ch)
#define CanTrcvCfg_GetWakeupSourceSyserr(ch)           CanTrcv_Tja1043_GetWuSrcSyserr(ch)
#define CanTrcvCfg_GetWakeupSourcePor(ch)              CanTrcv_Tja1043_GetWuSrcPor(ch)
#define CanTrcvCfg_IsIcuChannelSet(ch)                 CanTrcv_Tja1043_IsIcuChannelSetOfChannel(ch)
#define CanTrcvCfg_GetIcuChannel(ch)                   CanTrcv_Tja1043_GetIcuChannelOfChannel(ch)
#define CanTrcvCfg_GetMagicNumber()                    CanTrcv_Tja1043_GetFinalMagicNumber()
#define CanTrcvCfg_GetGeneratorCompatibilityVersion()  CanTrcv_Tja1043_GetGeneratorCompatibilityVersion()
#define CanTrcv_Cfg_DemIdList(Index,DemId)             (CanTrcv_TJA1043_DemIdList[Index][DemId])




/* ********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 * ********************************************************************************************************************/
#define CANTRCV_TJA1043_IS_INIT                         1u
#define CANTRCV_TJA1043_IS_NOT_INIT                     0u

/* ********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 * ********************************************************************************************************************/
#if (CANTRCV_TJA1043_SCHM_GENERAL == STD_ON)
#define CanTrcv_EnterCritical() SchM_Enter_CanTrcv_Tja1043_CANTRCV_TJA1043_EXCLUSIVE_AREA_0()
#define CanTrcv_LeaveCritical() SchM_Exit_CanTrcv_Tja1043_CANTRCV_TJA1043_EXCLUSIVE_AREA_0()
#else
#define CanTrcv_EnterCritical()                 SuspendAllInterrupts()
#define CanTrcv_LeaveCritical()                 ResumeAllInterrupts()
#endif


#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
# define CanTrcv_DetReportError(apiId, errorId)  ((void)Det_ReportError((CANTRCV_TJA1043_MODULE_ID), (CANTRCV_TJA1043_INSTANCE_ID), (apiId), (errorId)))
#else
# define CanTrcv_DetReportError(apiId, errorId)
#endif


#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
#  define CanTrcv_ReportErrorNoTrcvControl(apiId) CanTrcv_DetReportError( (apiId), CANTRCV_TJA1043_E_NO_TRCV_CONTROL)
#endif


/* If no errors should be reported */
#if defined(CanTrcv_ReportErrorNoTrcvControl)
#else
# define CanTrcv_ReportErrorNoTrcvControl(apiId)
#endif


# if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON)
#  if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
#    define CANTRCV_TJA1043_CHECK_WA(index) ((CanTrcvSTB == STD_LOW) && (CanTrcvERR == STD_LOW))
#  elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
#    define CANTRCV_TJA1043_CHECK_WA(index) (CanTrcvRXD == STD_LOW)
#  else
#    define CANTRCV_TJA1043_CHECK_WA(index) (CanTrcv_Tja1043_CheckWa(index) == E_OK)
#    define CANTRCV_TJA1043_CHECK_WA_TJA1043(index) ((CanTrcvSTB == STD_LOW) && (CanTrcvERR == STD_LOW))
#    define CANTRCV_TJA1043_CHECK_WA_TLE9252(index)  (CanTrcvRXD == STD_LOW)
#  endif
# endif


/* The macro CANTRCV_TJA1043_IS_EXTERNAL_WU_REASON returns true if the
   given wakeup reason indicates an external wakeup event */
# if !defined(CANTRCV_TJA1043_IS_EXTERNAL_WU_REASON)
#   define CANTRCV_TJA1043_IS_EXTERNAL_WU_REASON(wuReason)               \
                        ((wuReason) == CANTRCV_TJA1043_WU_BY_BUS)
# endif /* !defined(CANTRCV_TJA1043_IS_EXTERNAL_WU_REASON) */

#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
# define CANTRCV_TJA1043_IS_INITIALIZED(channel) \
                  ( (CanTrcv_Tja1043_IsInitialized == CANTRCV_TJA1043_IS_INIT) \
                  )
#endif


/*!
 * Internal comment removed. *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * 
 */ 









/* ********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 * ********************************************************************************************************************/




/* ********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 * ********************************************************************************************************************/

#define CANTRCV_TJA1043_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
 /*
 * Specifies whether the CanTrcv module is initialized.
 */
# if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
CANTRCV_TJA1043_LOCAL VAR(uint8, CANTRCV_TJA1043_VAR_INIT) CanTrcv_Tja1043_IsInitialized = CANTRCV_TJA1043_IS_NOT_INIT;
# endif

#define CANTRCV_TJA1043_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */



#define CANTRCV_TJA1043_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*
 * ! In following variable CAN transceiver channel specific settings are stored e.g. the wake-up reason or the current operating mode. 
 * For more information see the description of type: CanTrcv_Tja1043_Prob_Type.
 */
VAR(CanTrcv_Tja1043_Prob_Type, CANTRCV_TJA1043_VAR_NOINIT) CanTrcv_Tja1043_Prob[CANTRCV_TJA1043_MAX_CHANNEL]; /* PRQA S 3408 */ /* MD_CanTrcv_Tja1043_3408 */

VAR(CanTrcv_Tja1043_DiagStatusType, CANTRCV_TJA1043_VAR_NOINIT)  CanTrcv_Tja1043_DiagStatus[CANTRCV_TJA1043_MAX_CHANNEL];

#if (CANTRCV_TJA1043_USE_INIT_POINTER == STD_ON)
/* ! In following variable the configuration is stored during the initialization of the CAN transceiver driver in case of a Post-build loadable / selectable configuration. */
CANTRCV_TJA1043_LOCAL P2CONST(CanTrcv_Tja1043_ConfigType, CANTRCV_TJA1043_VAR_NOINIT, CANTRCV_TJA1043_INIT_DATA) CanTrcv_Tja1043_ConfigDataPtr;
#endif

#define CANTRCV_TJA1043_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define CANTRCV_TJA1043_START_SEC_CODE
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ********************************************************************************************************************
 *  LOCAL FUNCTIONS
 * ********************************************************************************************************************/
/* Local function declarations */

#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_ReportWakeup
 **********************************************************************************************************************/
/*! \brief       Reports the wake-up reason to the upper layer.
 *  \details     This function has no service id. Called by transceiver driver within: LL-specific.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \pre         The LL must ensure that this API is called with valid <CanTrcvIndex>. 
 *               The value of <CanTrcvIndex> is valid if < CANTRCV_TJA1043_MAX_CHANNEL.
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_ReportWakeup(uint8 CanTrcvIndex);
#endif

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_LL_InitMemoryChannelBegin
 **********************************************************************************************************************/
/*! \brief       LL: Initializes the LL-specific channel data of the CAN transceiver hardware.
 *  \details     This function is called for ALL channels and has no service id.
 *               The callee (HL) ensures the validity of <CanTrcvIndex>. 
 *               Called by transceiver driver within: CanTrcv_Tja1043_Init().
 *               This is ensured if <CanTrcvIndex> < CANTRCV_TJA1043_MAX_CHANNEL.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE only for different transceiver channels (index)
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_LL_InitMemoryChannelBegin(uint8 CanTrcvIndex);

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_LL_InitChannel
 **********************************************************************************************************************/
/*! \brief       LL: Initializes the LL-specific channel data of the CAN transceiver hardware.
 *  \details     This function is called only for "used" (== activated) channels and has no service id.
 *               The callee (HL) ensures the validity of <CanTrcvIndex>. 
 *               This is ensured if <CanTrcvIndex> < CANTRCV_TJA1043_MAX_CHANNEL.
 *               Called by transceiver driver within: CanTrcv_Tja1043_Init().
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE only for different transceiver channels (index)
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_LL_InitChannel(uint8 CanTrcvIndex);





#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON)
# if (CANTRCV_TJA1043_CONFIGURATION_VARIANT != CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE) || (!defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && !defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252))
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_CheckWa
 **********************************************************************************************************************/
/*! \brief       Checks if a wakeup was detected by the transceiver.
 *  \details     This function has no service id. Called by transceiver driver within: LL-specific.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which call has to be applied.
 *  \pre         The LL must ensure that this API is called with valid <CanTrcvIndex>. 
 *               The value of <CanTrcvIndex> is valid if < CANTRCV_TJA1043_MAX_CHANNEL.
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      CANTRCV_TJA1043_CONFIGURATION_VARIANT != CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE
 *            || !defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && !defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252)
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_CheckWa(uint8_least CanTrcvIndex);
# endif
#endif




#if(CANTRCV_TJA1043_DEM_REPORT_SUPPORT == STD_ON)
/***************************************************************************************************
* Function      : CanTrcv_Tja1043_SetDiagDemState
* Description   : Report event status to dem
* Input         : uint16 DiagId                     
                CanTrcv_Tja1043_DiagStateEcumType DiagState  
* Output        : None
* Return        : void
* Others        : 
* Record
* 1.Date        : 20210926
*   Author      : Xiongyt
*   Modification: Created function

*-------------------------------------------------------------------------------------------------*/
CANTRCV_TJA1043_LOCAL_INLINE FUNC( void, CANTRCV_TJA1043_CODE ) CanTrcv_Tja1043_SetDiagDemState( uint16 DiagId,CanTrcv_Tja1043_DiagStateEcumType DiagState )
{
    if(DiagState == TJA1043_DIAG_STATE_FAULT)
    {
        (void)CANTRCV_TJA1043_DEM_SETEVENTSTATUS(DiagId,DEM_EVENT_STATUS_PREFAILED);
    }
    else if(DiagState == TJA1043_DIAG_STATE_NOFAULT)
    {
        (void)CANTRCV_TJA1043_DEM_SETEVENTSTATUS(DiagId,DEM_EVENT_STATUS_PREPASSED);
    }
    else
    {
        /*doing nothing*/
    }
}
#endif

/* ********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 * ********************************************************************************************************************/

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_InitMemory
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_InitMemory(void)
{
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #100 Mark driver as uninitialized. */
  CanTrcv_Tja1043_IsInitialized = CANTRCV_TJA1043_IS_NOT_INIT;
#endif
}


/**********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_LL_InitMemoryChannelBegin
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_LL_InitMemoryChannelBegin(uint8 CanTrcvIndex)
{
  /* #100 Initialize the CAN transceiver channel-specific settings (independent active or inactive one) (LL-specific). */
  /* This API is NOT required for Tja1043. */
  CANTRCV_TJA1043_DUMMY_STATEMENT(CanTrcvIndex); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
}


/**********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_LL_InitChannel
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_LL_InitChannel(uint8 CanTrcvIndex)
{

  /* #100 Initialize the CAN transceiver channel-specific settings (only active one) (LL-specific). */
  /* This API is NOT required for Tja1043. */
  CANTRCV_TJA1043_DUMMY_STATEMENT(CanTrcvIndex); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
}




/**********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_Init
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_Init( P2CONST(CanTrcv_Tja1043_ConfigType, AUTOMATIC, CANTRCV_TJA1043_INIT_DATA) ConfigPtr )
{
  /* \trace SPEC-14971 */

  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* ESCAN00076622 */
#if (CANTRCV_TJA1043_USE_INIT_POINTER == STD_ON)
  /* #100 Store the configuration pointer. (Required before any check especially for PBL-configurations due to access to GeneratorCompatibilityVersion and MagicNumber via the ConfigPtr.) */
  CanTrcv_Tja1043_ConfigDataPtr = ConfigPtr;

# if ((CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON) || (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)) /* COV_CANTRCV_HL_LL_TJA1043_VARCOV_SW_FEAT_NOT_SUPPORTED */
  /* #10 Check if parameter ConfigPtr is valid. */
  if (ConfigPtr == NULL_PTR)
  {
#  if (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) /* COV_CANTRCV_HL_LL_TJA1043_VARCOV_SW_FEAT_NOT_SUPPORTED */
    EcuM_BswErrorHook((uint16) CANTRCV_TJA1043_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
#  endif /* (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) */

#  if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON) /* COV_CANTRCV_HL_LL_TJA1043_VARCOV_SW_FEAT_NOT_SUPPORTED */
    /* \trace SPEC-14948 */
    errorId = CANTRCV_TJA1043_E_PARAM_POINTER;
#  endif /* (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON) */
  }
  else
# endif /* (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON) || (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) */
# if (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) /* COV_CANTRCV_HL_LL_TJA1043_VARCOV_SW_FEAT_NOT_SUPPORTED */
  /* #20 Check the generator compatibility version */
  if (CanTrcvCfg_GetGeneratorCompatibilityVersion() != (uint32)((CANTRCV_TJA1043_BASE_GENDATA_COMP_VERSION << 16u) | CANTRCV_TJA1043_HW_GENDATA_COMP_VERSION)) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_INVALID_GENDATA */
  {
    EcuM_BswErrorHook((uint16) CANTRCV_TJA1043_MODULE_ID, (uint8) ECUM_BSWERROR_COMPATIBILITYVERSION);
  }
  /* #30 Check the magic number */
  else if (CanTrcvCfg_GetMagicNumber() != CANTRCV_TJA1043_FINAL_MAGIC_NUMBER) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_INVALID_GENDATA */
  {
    EcuM_BswErrorHook((uint16) CANTRCV_TJA1043_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  }
  else
# endif /* (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) */
#endif /* (CANTRCV_TJA1043_USE_INIT_POINTER == STD_ON) */
  {
    uint8_least index;

#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
    #  if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
    Dio_LevelType CanTrcvSTB;
    Dio_LevelType CanTrcvERR;
    #  elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
    Dio_LevelType CanTrcvRXD;
    #  endif
#endif




#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
    /* #110 Set transceiver driver as initialized at all. */
    CanTrcv_Tja1043_IsInitialized = CANTRCV_TJA1043_IS_INIT;
#endif

    /* #120 Run through all transceiver channels and initialize them.*/
    for(index = 0; index < CANTRCV_TJA1043_MAX_CHANNEL; ++index)
    {

      /* Initialize variables */

      /* Initialize LL */
      CanTrcv_Tja1043_LL_InitMemoryChannelBegin((uint8)index);

      /* #130 Set the channel states concerning: initialization, wake-up report and wake-up reason to default values. */
      CanTrcv_Tja1043_Prob[index].wakeUpReport = CANTRCV_TJA1043_WU_ENABLE; /* SBSW_CANTRCV_HL_TJA1043_1 */
      CanTrcv_Tja1043_Prob[index].wakeUpReason = CANTRCV_TJA1043_WU_ERROR; /* SBSW_CANTRCV_HL_TJA1043_1 */

      /* #140 Set the channel state concerning: request state to default values (only SPI-interface or SBC-interface with PN). */




      /* ----- Implementation ----------------------------------------------- */

      /* #190 Initialize next parameters only for active transceiver channels. */
      if(CanTrcvCfg_IsChannelUsed(index))
      {



        /* #200 If no wake-up event occurred during initialization the default reason is RESET. */
        CanTrcv_Tja1043_Prob[index].wakeUpReason = CANTRCV_TJA1043_WU_RESET; /* SBSW_CANTRCV_HL_TJA1043_1 */


        /* #220 Do additional checks: wake-up event, HW status, PN configuration. (critical section is used). */
        CanTrcv_EnterCritical();

#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
        /* \trace SPEC-14953 */

        # if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
          CanTrcvERR = Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(index));
          CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(index));
        # elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
          CanTrcvRXD = Dio_ReadChannel(CanTrcv_Tja1043_GetPinRXDOfDioConfiguration(index));
        # endif

#endif /* CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON || CANTRCV_TJA1043_HW_PN_SUPPORT == STD_ON */

        /* #240 Determine whether a wake-up event (BY_BUS, BY_PIN) occurred or NOT. If occurred store it. */
#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON)
        if(CANTRCV_TJA1043_CHECK_WA(index))
        {
          /* The wake-up reason is: BY_BUS */
          CanTrcv_Tja1043_Prob[index].wakeUpReason = CANTRCV_TJA1043_WU_BY_BUS; /* SBSW_CANTRCV_HL_TJA1043_1 */
        }
#endif /* CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON */

        CanTrcv_LeaveCritical();

        /* Do some generic initialization of LL */
        CanTrcv_Tja1043_LL_InitChannel((uint8)index);


#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
        /* #260 Report the detected wake-up event to the upper layer. */
        CanTrcv_Tja1043_ReportWakeup((uint8)index);
#endif

        /* #270 Set the operating mode to NORMAL. In case of SPI-interface always synchronous. (critical section used) */
        CanTrcv_EnterCritical();

#if (CANTRCV_TJA1043_USE_ICU == STD_ON)
        /* #280 If ICU is configured, disable ICU. */
        if (CanTrcvCfg_IsIcuChannelSet(index)) /* \trace SPEC-14950 */
        {
          Icu_DisableNotification( CanTrcvCfg_GetIcuChannel(index) ); /* \trace SPEC-14973*/
        }
#endif

        Dio_WriteChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(index),STD_HIGH);
        Dio_WriteChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(index),STD_HIGH);
        

        CanTrcv_LeaveCritical();



      } /* CanTrcvChannelUsed == TRUE */
    } /* for (...) */
  } /* if (ConfigPtr == NULL_PTR) .. else */

#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_CanTrcv_Tja1043_14.3 */ /* COV_CANTRCV_HL_TJA1043_CODECOV_NOT_EACH_CONFIG */
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_INIT_ID, errorId); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif
  
#if (CANTRCV_TJA1043_USE_INIT_POINTER == STD_OFF)
  CANTRCV_TJA1043_DUMMY_STATEMENT(ConfigPtr); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6030,6050,6080 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */


/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_SetOpMode
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_SetOpMode(uint8 CanTrcvIndex, CanTrcv_TrcvModeType OpMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType returnVal = E_NOT_OK;
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;

  CanTrcv_Tja1043_TrcvModeType currentOpMode;

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter CanTrcvIndex is valid. */
  if(CanTrcvIndex >= CANTRCV_TJA1043_MAX_CHANNEL)
  {
    /* \trace SPEC-19976 */  
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #20 Check if transceiver channel (CanTrcvIndex) is active. */
  else if(!CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
  {
    /* \trace SPEC-19976 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #30 Check if transceiver channel (CanTrcvIndex) is initialized. */
  else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
  {
    /* \trace SPEC-15064 */
    errorId = CANTRCV_TJA1043_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
    /* #100 Do execute transition of operating mode only if transceiver channel (CanTrcvIndex) is active. */
    if(CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
#endif
    {
      /* #110 Check if the current operating mode equals the requested one. */
      (void)CanTrcv_Tja1043_GetOpMode(CanTrcvIndex, &currentOpMode); /* SBSW_CANTRCV_HL_TJA1043_3 */

      if (currentOpMode == OpMode) /* \trace SPEC-15090 */
      {
        /* \trace SPEC-19955 */
        returnVal = E_OK;


      }
      else
      {
        /* #160 The requested one does NOT equal the current one. Execute the requested mode change. (critical section is used) */
        /* \trace SPEC-19962 */
        switch(OpMode)
        {
          /* #200 Mode change request to NORMAL. */
          case CANTRCV_TJA1043_OP_MODE_NORMAL:

            /* #210 Check whether it is an internal wake-up. If yes store the wake-up reason. */         
            if(
               (CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason == CANTRCV_TJA1043_WU_ERROR))
            {
              /* Transceiver is switched from STANDBY/SLEEP -> NORMAL and has not detected any wakeup.
                 This is considered as internal wakeup. */
              CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason = CANTRCV_TJA1043_WU_INTERNALLY; /* SBSW_CANTRCV_HL_TJA1043_1 */
            }
            
            CanTrcv_EnterCritical();

            /* #220 If ICU is configured, disable ICU. */
# if (CANTRCV_TJA1043_USE_ICU == STD_ON)
            if (CanTrcvCfg_IsIcuChannelSet(CanTrcvIndex)) /* \trace SPEC-14950 */
            {
              Icu_DisableNotification( CanTrcvCfg_GetIcuChannel(CanTrcvIndex) ); /* \trace SPEC-14973 */
            }
# endif
            
            {
              /* #240 No mode request is currently pending. Store the current mode request. (only SPI-interface) */
              /* #250 Execute operating mode change request to NORMAL. */
              Dio_WriteChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex),STD_HIGH);
              Dio_WriteChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(CanTrcvIndex),STD_HIGH);
              

            }

            CanTrcv_LeaveCritical();
            returnVal = E_OK;
            break;

          case CANTRCV_TJA1043_OP_MODE_STANDBY:
             /* #300 Mode change request to STANDBY. (only if supported by HW) */
            /* #310 Mode transition to STANDBY is only possible from NORMAL. Otherwise DET error is reported. */
            if(currentOpMode != CANTRCV_TJA1043_OP_MODE_NORMAL) /* \trace SPEC-19955 */
            {
#  if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
              /* \trace SPEC-19985 */
              errorId = CANTRCV_TJA1043_E_TRCV_NOT_NORMAL;
#  endif
            }
            else
            {
              /* #320 Current mode is NORMAL: Execute mode request. */
              CanTrcv_EnterCritical();

              /* #330 If ICU is configured, enable ICU. */
# if (CANTRCV_TJA1043_USE_ICU == STD_ON)
              if (CanTrcvCfg_IsIcuChannelSet(CanTrcvIndex)) /* \trace SPEC-14950 */
              {
                Icu_EnableNotification( CanTrcvCfg_GetIcuChannel(CanTrcvIndex) ); /* \trace SPEC-15004 */
              }
# endif
              /* #340 Reset wake-up reason. */
              CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason = CANTRCV_TJA1043_WU_ERROR; /* SBSW_CANTRCV_HL_TJA1043_1 */

              {
                /* #360 No mode request is currently pending. Store the mode request. (only SPI-interface) */
                /* #370 Execute operating mode change request to STANDBY. */
                Dio_WriteChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(CanTrcvIndex),STD_LOW);
                Dio_WriteChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex),STD_LOW);
              }

              CanTrcv_LeaveCritical();
              returnVal = E_OK;
            }
            break;

          case CANTRCV_TJA1043_OP_MODE_SLEEP:
            /* #400 Mode change request to SLEEP. (only if supported by HW) */

            /* #410 Mode transition to SLEEP is only possible from STANDBY. Otherwise DET error is reported. */
            if(currentOpMode != CANTRCV_TJA1043_OP_MODE_STANDBY)
            {
#  if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
              /* \trace SPEC-19964 */
              errorId = CANTRCV_TJA1043_E_TRCV_NOT_STANDBY;
#  endif
            }
            else
            {
              CanTrcv_EnterCritical();

              {
                /* #430 No mode request is currently pending. Store the mode request. (only SPI-interface) */
                /* #440 Execute operating mode change request to SLEEP. */
                Dio_WriteChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(CanTrcvIndex),STD_HIGH);
                Dio_WriteChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex),STD_LOW);

                returnVal = E_OK;
              }

              CanTrcv_LeaveCritical();
            }
            break;

          default:
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
            /* \trace SPEC-14963 */
            /* #40 Check if parameter OpMode is valid. */
            errorId = CANTRCV_TJA1043_E_PARAM_TRCV_OP_MODE;
#endif
            break;
          } /* switch() */
      } /* currentOpMode == OpMode */

      /* #600 If mode request executed successfully then inform the CanIf else report error. */
      if (returnVal == E_OK)
      {
        (void)CanTrcv_Tja1043_GetOpMode(CanTrcvIndex, &currentOpMode); /* SBSW_CANTRCV_HL_TJA1043_3 */

        if(currentOpMode == OpMode) /* COV_CANTRCV_LL_TJA1043_CODECOV_HW_FAILURE */
        {
          /* #620 Inform the CanIf about successful operating mode transition. */
          CanIf_Tja1043_TrcvModeIndication(CanTrcvIndex, currentOpMode); /* \trace SPEC-20006 */
        }
        else
        {
          /* \trace SPEC-20011 */
          errorId = CANTRCV_TJA1043_E_NO_TRCV_CONTROL;

          returnVal = E_NOT_OK;
        } /* currentOpMode != OpMode */
      } /* returnVal == E_OK */
    } /* channelUsed == TRUE */
  }

#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_SETOPMODE_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif
  return returnVal;
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */


/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetOpMode
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetOpMode(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) OpMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType returnVal = E_NOT_OK;
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;


  Dio_LevelType CanTrcvSTB;
  Dio_LevelType CanTrcvEN;

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter OpMode is valid. */
  if(OpMode == NULL_PTR)
  {
    /* \trace SPEC-14958 */
    errorId = CANTRCV_TJA1043_E_PARAM_POINTER;
  }
  /* #20 Check if parameter CanTrcvIndex is valid. */
  else if(CanTrcvIndex >= CANTRCV_TJA1043_MAX_CHANNEL)
  {
    /* \trace SPEC-20009 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #30 Check if transceiver channel (CanTrcvIndex) is active. */
  else if(!CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
  {
    /* \trace SPEC-20009 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #40 Check if transceiver channel (CanTrcvIndex) is initialized. */
  else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
  {
    /* \trace SPEC-15042 */
    errorId =  CANTRCV_TJA1043_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
    /* #100 Do execute the request only if transceiver channel (CanTrcvIndex) is active. */
    if(CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
#endif
    {
      /* #200 DIO-interface: Read the mode from status of PINs of underlying HW. (critical section used) */
      /* #201 SPI-interface: Read the mode from state variable. */
      /* #202 SBC-interface: Read the mode via SBC module API. (critical section used) */
      CanTrcv_EnterCritical();

      CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex));
      CanTrcvEN  = Dio_ReadChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(CanTrcvIndex));
      

      CanTrcv_LeaveCritical();

      {
        /* \trace SPEC-19974 */

        if((CanTrcvSTB == STD_HIGH) && (CanTrcvEN == STD_HIGH)) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_HW_SPECIFIC */
        {
          /* CAN transceiver is in normal operation mode */
          *OpMode = CANTRCV_TJA1043_OP_MODE_NORMAL; /* SBSW_CANTRCV_HL_TJA1043_2 */
          returnVal = E_OK;
        }

        if((CanTrcvSTB == STD_LOW) && (CanTrcvEN == STD_HIGH))
        {
          /* CAN transceiver is in sleep mode */
          *OpMode = CANTRCV_TJA1043_OP_MODE_SLEEP; /* SBSW_CANTRCV_HL_TJA1043_2 */
          returnVal = E_OK;
        }


        if((CanTrcvSTB == STD_LOW) && (CanTrcvEN == STD_LOW))
        {
          /* CAN transceiver is in standby mode */
          *OpMode = CANTRCV_TJA1043_OP_MODE_STANDBY; /* SBSW_CANTRCV_HL_TJA1043_2 */
          returnVal = E_OK;
        }
      }

      /* #210 If reading of operating mode NOT succeeded report error. */
      if (returnVal == E_NOT_OK) /* PRQA S 2992,2996 */ /* MD_CanTrcv_Tja1043_14.3 */ /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_HW_SPECIFIC */
      {
        /* \trace SPEC-19940 */
        errorId = CANTRCV_TJA1043_E_NO_TRCV_CONTROL; /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
    } /* Channel is used */
  } /* DET checks passed */
  
#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_GETOPMODE_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif

 return returnVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetBusWuReason
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetBusWuReason(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) Reason)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType returnVal = E_NOT_OK;
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;

#if (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT != CANTRCV_TJA1043_WAKEUP_NONE) 
  CanTrcv_Tja1043_TrcvModeType currentOpMode;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if the return-parameter Reason is valid. */
  if(Reason == NULL_PTR)
  {
    /* \trace SPEC-15063 */
    errorId = CANTRCV_TJA1043_E_PARAM_POINTER;
  }
  /* #20 Check if parameter CanTrcvIndex is valid. */
  else if(CanTrcvIndex >= CANTRCV_TJA1043_MAX_CHANNEL)
  {
    /* \trace SPEC-19993 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #30 Check if transceiver channel (CanTrcvIndex) is active. */
  else if(!CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
  {
    /* \trace SPEC-19993 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #40 Check if transceiver channel (CanTrcvIndex) is initialized. */
  else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
  {
    /* \trace SPEC-15059 */
    errorId = CANTRCV_TJA1043_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
    /* #100 Do execute the request only if transceiver channel (CanTrcvIndex) is active. */
    if(CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
#endif
    {
      /* UREQ00015010 */
      /* #200 Check the wake-up reason for validity. */
#if (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT != CANTRCV_TJA1043_WAKEUP_NONE) 
      if(CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason == CANTRCV_TJA1043_WU_ERROR)
      {
        /* #300 If wake-up reason is invalid return WU_ERROR. */
        *Reason = CANTRCV_TJA1043_WU_ERROR; /* SBSW_CANTRCV_HL_TJA1043_2 */

        /* #310 Wake-up reason is invalid (WU_ERROR). This is OK only in case of transceiver channel is in NORMAL mode. */
        (void)CanTrcv_Tja1043_GetOpMode(CanTrcvIndex, &currentOpMode); /* SBSW_CANTRCV_HL_TJA1043_3 */

        if(currentOpMode != CANTRCV_TJA1043_OP_MODE_NORMAL)
        {
          /* \trace SPEC-19980 */
          /* #320 Being in any mode except NORMAL with WU_ERROR is an error hence report it. */
          errorId = CANTRCV_TJA1043_E_NO_TRCV_CONTROL;
        }
      }
      else
      {
        /* #400 Wake-up reason is valid (neither WU_ERROR nor WU_NOT_SUPPORTED). Return the current wake-up reason.*/
        *Reason = CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason; /* SBSW_CANTRCV_HL_TJA1043_2 */
        returnVal = E_OK;
      }
#else /* (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT == CANTRCV_TJA1043_WAKEUP_NONE) */
      *Reason = CANTRCV_TJA1043_WU_NOT_SUPPORTED; /* SBSW_CANTRCV_HL_TJA1043_2 */
#endif /* (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT != CANTRCV_TJA1043_WAKEUP_NONE) */
    } /* IsChannelUsed */
  }
  
#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_GETBUSWUREASON_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif
  
  return returnVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_SetWakeupMode
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_SetWakeupMode(uint8 CanTrcvIndex, CanTrcv_TrcvWakeupModeType TrcvWakeupMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType returnVal = E_NOT_OK;
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter CanTrcvIndex is valid. */
  if(CanTrcvIndex >= CANTRCV_TJA1043_MAX_CHANNEL)
  {
    /* \trace SPEC-19998 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #20 Check if transceiver channel (CanTrcvIndex) is active. */
  else if(!CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
  {
    /* \trace SPEC-19998 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #30 Check if transceiver channel (CanTrcvIndex) is initialized. */
  else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
  {
    /* \trace SPEC-15077 */
    errorId = CANTRCV_TJA1043_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT != CANTRCV_TJA1043_WAKEUP_NONE) 
# if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
    /* #100 Do execute the request only if transceiver channel (CanTrcvIndex) is active. */
    if(CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
# endif
    {
      /* #200 Set the requested wake-up mode. */
      switch(TrcvWakeupMode)
      {
        case CANTRCV_TJA1043_WU_ENABLE:
             /* \trace SPEC-19990 */
             CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReport = CANTRCV_TJA1043_WU_ENABLE; /* SBSW_CANTRCV_HL_TJA1043_1 */

             /* #300 In addition: If requested wake-up mode is WU_ENABLE report if wake-up event(s) is/are pending. */
# if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
             CanTrcv_Tja1043_ReportWakeup(CanTrcvIndex);
# endif

             returnVal = E_OK;
             break;

        case CANTRCV_TJA1043_WU_DISABLE:
             /* \trace SPEC-20012 */
             CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReport = CANTRCV_TJA1043_WU_DISABLE; /* SBSW_CANTRCV_HL_TJA1043_1 */

             returnVal = E_OK;
             break;

        case CANTRCV_TJA1043_WU_CLEAR:
             /* \trace SPEC-19961 */
             /* #500 In addition: If requested wake-up mode is WU_CLEAR clear the wake-up reason and all detected wake-up events. */
             CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason = CANTRCV_TJA1043_WU_ERROR; /* SBSW_CANTRCV_HL_TJA1043_1 */
             returnVal = E_OK;

             break;
        default:
# if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
             /* #40 Check if parameter TrcvWakeupMode is valid. */
             errorId = CANTRCV_TJA1043_E_PARAM_TRCV_WAKEUP_MODE; /* \trace SPEC-15036 */
# endif
             break;
      }
    }
#endif /* CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT != CANTRCV_TJA1043_WAKEUP_NONE */
  }
  
#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_SETWAKEUPMODE_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif  
  
#if (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT == CANTRCV_TJA1043_WAKEUP_NONE) 
  CANTRCV_TJA1043_DUMMY_STATEMENT(TrcvWakeupMode); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
# if(CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
  CANTRCV_TJA1043_DUMMY_STATEMENT(CanTrcvIndex); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
# endif
#endif
  /* \trace SPEC-19978: Not implemented as no need to query HW at this place. */

  return returnVal;
}


/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_CheckWakeup
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_CheckWakeup(uint8 CanTrcvIndex)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType returnVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;


#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
  #  if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
  Dio_LevelType CanTrcvSTB;
  Dio_LevelType CanTrcvERR;
  #  elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
  Dio_LevelType CanTrcvRXD;
  #  endif
#endif /* CANTRCV_TJA1043_WAKEUP_BY_BUS_USED */

  /* ----- Development Error Checks ------------------------------------- */
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter CanTrcvIndex is valid. */
  if(CanTrcvIndex >= CANTRCV_TJA1043_MAX_CHANNEL)
  {
    /* \trace SPEC-20003 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #20 Check if transceiver channel (CanTrcvIndex) is active. */
  else if(!CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
  {
    /* \trace SPEC-20003 */
    errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
  }
  /* #30 Check if transceiver channel (CanTrcvIndex) is initialized. */
  else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
  {
    /* \trace SPEC-19994 */
    errorId = CANTRCV_TJA1043_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON)
# if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF)
    /* #100 Do execute the request only if transceiver channel (CanTrcvIndex) is active and wake-up detection is enabled. (critical section used) */
    if(CanTrcvCfg_IsChannelUsed(CanTrcvIndex))
# endif
    {
      if(CanTrcvCfg_IsWakeupByBusUsed(CanTrcvIndex) &&
         (CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReport == CANTRCV_TJA1043_WU_ENABLE)) /* COV_CANTRCV_HL_TJA1043_CODECOV_IS_WU_BY_BUS_USED */
      {
        CanTrcv_Tja1043_TrcvModeType currentOpMode;
        CanTrcv_EnterCritical();

        /* #110 Is the transceiver channel in NORMAL? (only DIO-/SBC-interface) */
        (void)CanTrcv_Tja1043_GetOpMode(CanTrcvIndex, &currentOpMode); /* SBSW_CANTRCV_HL_TJA1043_3 */

        if (currentOpMode == CANTRCV_TJA1043_OP_MODE_NORMAL)
        {
          /* #120 Operating mode NORMAL: No valid wake-up event detected. (only DIO-/SBC-interface)*/
          returnVal = E_NOT_OK;
        }
        else
        /* #200 Check if there are any wake-up events pending in HW. */
        if (CANTRCV_TJA1043_IS_EXTERNAL_WU_REASON(CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason)) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_WU_BY_PIN */
        {
          /* #300 Any wake-up event is pending: Check if currently an operating mode change is requested. (only asynchronous SPI-interface) */
          {
            /* #340 Operating mode STANDBY / SLEEP: Report the detected wake-up event to the EcuM. */
            CanTrcv_Tja1043_ReportWakeup(CanTrcvIndex);

            returnVal = E_OK; /* wake-up detected  */
          }
        }
        else
        {
          /* #400 No pending wake-up flags. Request the underlying HW for wake-up flags. */
          # if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
            CanTrcvERR = Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(CanTrcvIndex));
            CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex));
          # elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
            CanTrcvRXD = Dio_ReadChannel(CanTrcv_Tja1043_GetPinRXDOfDioConfiguration(CanTrcvIndex));
          # endif
          if (CANTRCV_TJA1043_CHECK_WA(CanTrcvIndex)) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_CHECK_WA */
          {
            CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason = CANTRCV_TJA1043_WU_BY_BUS; /* SBSW_CANTRCV_HL_TJA1043_1 */
            CanTrcv_Tja1043_ReportWakeup(CanTrcvIndex);

            returnVal = E_OK;  /* Wakeup detected */ /* \trace SPEC-20014 */
          }

        }

        CanTrcv_LeaveCritical();

      }
    }
#else
    returnVal = E_NOT_OK;
#endif /* CANTRCV_TJA1043_WAKEUP_BY_BUS_USED */
  }
  
#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_CHECKWAKEUP_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif  
  
#if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_OFF) && (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_OFF)
  CANTRCV_TJA1043_DUMMY_STATEMENT(CanTrcvIndex); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif
  return returnVal;
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */




#if (CANTRCV_TJA1043_GET_VERSION_INFO == STD_ON) /* \trace SPEC-15105 */
/* \trace SPEC-19953 */
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetVersionInfo
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) VersionInfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter VersionInfo is valid. */
  if(VersionInfo == NULL_PTR)
  {
    errorId = CANTRCV_TJA1043_E_PARAM_POINTER;
  }
  else
# endif /* CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* \trace SPEC-14986, SPEC-15032 */
    /* #100 Retrieve the version information: VENDOR_ID, MODULE_ID, SW_MAJOR-, SW_MINOR- and SW_PATCH-version. */
    VersionInfo->vendorID = CANTRCV_TJA1043_VENDOR_ID; /* SBSW_CANTRCV_HL_TJA1043_2 */
    VersionInfo->moduleID = CANTRCV_TJA1043_MODULE_ID; /* SBSW_CANTRCV_HL_TJA1043_2 */

    VersionInfo->sw_major_version = CANTRCV_TJA1043_SW_MAJOR_VERSION; /* SBSW_CANTRCV_HL_TJA1043_2 */
    VersionInfo->sw_minor_version = CANTRCV_TJA1043_SW_MINOR_VERSION; /* SBSW_CANTRCV_HL_TJA1043_2 */
    VersionInfo->sw_patch_version = CANTRCV_TJA1043_SW_PATCH_VERSION; /* SBSW_CANTRCV_HL_TJA1043_2 */
  }
  
#if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
  {
    CanTrcv_DetReportError(CANTRCV_TJA1043_GETVERSIONINFO_ID, errorId);
  }
#else
  CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
#endif 
}
#endif /* CANTRCV_TJA1043_GET_VERSION_INFO == STD_ON */








/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_MainFunction
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 **********************************************************************************************************************/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least index;
  
  /* ----- Implementation ----------------------------------------------- */
  /* \trace SPEC-15067, SPEC-15085 */
  /* #100 Run through all transceiver channels. */
  for(index = 0; index < CANTRCV_TJA1043_MAX_CHANNEL; ++index)
  {
    if (CanTrcvCfg_IsChannelUsed(index))
    {
      {
        /* #200 Execute only if transceiver channel is active and initialized. */
        CanTrcv_Tja1043_TrcvModeType currentOpMode;

        (void)CanTrcv_Tja1043_GetOpMode((uint8)index, &currentOpMode); /* SBSW_CANTRCV_HL_TJA1043_3 */

        /* #300 Execute only if transceiver channel is in power-down mode (STANDBY / SLEEP). (only DIO- or SBC-interface) */
        if (currentOpMode != CANTRCV_TJA1043_OP_MODE_NORMAL)
        {
#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) && (CANTRCV_TJA1043_GENERAL_WAKE_UP_SUPPORT == CANTRCV_TJA1043_WAKEUP_POLLING) 
          if (CanTrcvCfg_IsWakeupByBusUsed(index)) /* COV_CANTRCV_HL_TJA1043_CODECOV_IS_WU_BY_BUS_USED */
          {
            {
              /* #210 Transceiver channel is in power-down mode (STANDBY / SLEEP) and has wake-up support enabled: Check if a wake-up event occurred. (critical section used) */
              #  if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
              Dio_LevelType CanTrcvSTB;
              Dio_LevelType CanTrcvERR;
              #  elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
              Dio_LevelType CanTrcvRXD;
              #  endif

              CanTrcv_TrcvWakeupReasonType wakeupReason = CANTRCV_TJA1043_WU_ERROR;

              CanTrcv_EnterCritical();
              /* #310 Determine whether a wake-up event occurred or NOT from current state of DIO pins. (only DIO-interface) */
              # if defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
                CanTrcvERR = Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(index));
                CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(index));
              # elif defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252) && (CANTRCV_TJA1043_CONFIGURATION_VARIANT == CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE)
                CanTrcvRXD = Dio_ReadChannel(CanTrcv_Tja1043_GetPinRXDOfDioConfiguration(index));
              # endif
              if(CANTRCV_TJA1043_CHECK_WA(index)) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_CHECK_WA */
              {
                wakeupReason = CANTRCV_TJA1043_WU_BY_BUS;
              }

              if (wakeupReason != CANTRCV_TJA1043_WU_ERROR)
              {
                /* #500 If any wake-up event detected, store the wake-up event. */
                CanTrcv_Tja1043_Prob[index].wakeUpReason = wakeupReason; /* SBSW_CANTRCV_HL_TJA1043_1 */

                if (CanTrcv_Tja1043_Prob[index].wakeUpReport == CANTRCV_TJA1043_WU_ENABLE)
                {
                  /* #510 If any wake-up event detected and wake-up detection is enabled, inform the EcuM to check for wake-up event(s). */
                  EcuM_CheckWakeup( CanTrcvCfg_GetWakeupSource(index) );
                }
              }

              CanTrcv_LeaveCritical();
            } /* (!CanTrcv_Tja1043_IsReqFlagPnd(index)) */
          }
# endif /* (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) */
        } /* CanTrcv_Tja1043_Prob[index].curOpMode != CANTRCV_TJA1043_OP_MODE_NORMAL */
      } /* CanTrcv_Tja1043_Prob[index].isInit != CANTRCV_TJA1043_IS_INIT */
    } /*  CanTrcvCfg_IsChannelUsed(index)  */
  } /* for ... */
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */


/***************************************************************************************************
* Function      : CanTrcv_Tja1043_MainFunctionDiagnostics
* Description   : Reads the transceiver diagnostic status periodically and
                  sets product/development accordingly.
* Input         : void  
* Output        : None
* Return        : void
* Others        : 
* Record
* 1.Date        : 20210923
*   Author      : Xiongyt
*   Modification: Created function

*-------------------------------------------------------------------------------------------------*/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_MainFunctionDiagnostics(void)
{
    uint8 errorId = CANTRCV_TJA1043_E_NO_ERROR;
    uint8_least index;
    Std_ReturnType retval = E_NOT_OK;
    Dio_LevelType CanTrcvSTB;
    Dio_LevelType CanTrcvEN;

    for(index = 0; index < CANTRCV_TJA1043_MAX_CHANNEL; ++index) /* PRQA S 2877 */
    {
    #if (CANTRCV_TJA1043_DEV_ERROR_DETECT == STD_ON)
        if (!CanTrcvCfg_IsChannelUsed(index))
        {
            errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
        }
        // else if(!CanTrcv_IsDiagnosisUsed(index))
        // {
        //     errorId = CANTRCV_TJA1043_E_INVALID_CAN_NETWORK;
        // }
        else if(!CANTRCV_TJA1043_IS_INITIALIZED(CanTrcvIndex))
        {
            errorId = CANTRCV_TJA1043_E_UNINIT;
        }
        else
    #endif
        {
			CanTrcv_EnterCritical();
            
			CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(index));
			CanTrcvEN  = Dio_ReadChannel(CanTrcv_Tja1043_GetPinENOfDioConfiguration(index));
            
            CanTrcv_LeaveCritical();

            if((CanTrcvSTB == STD_HIGH) && (CanTrcvEN == STD_HIGH))/*NORMAL MODE*/
            {
                if(0u == Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(index)) )
                {
                    CanTrcv_Tja1043_DiagStatus[index].BusFailure = TJA1043_DIAG_STATE_FAULT;

                }
                else
                {
                    CanTrcv_Tja1043_DiagStatus[index].BusFailure = TJA1043_DIAG_STATE_NOFAULT;
                }
            }
            else if((CanTrcvSTB == STD_HIGH) && (CanTrcvEN == STD_LOW))/*LISTEN ONLY MODE*/
            {
                if(0u ==Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(index)))
                {
                    CanTrcv_Tja1043_DiagStatus[index].LocalFailure = TJA1043_DIAG_STATE_FAULT;

                }
                else
                {
                    CanTrcv_Tja1043_DiagStatus[index].LocalFailure = TJA1043_DIAG_STATE_NOFAULT;
                }
                
            }
            #if(CANTRCV_TJA1043_DEM_REPORT_SUPPORT == STD_ON)
            CanTrcv_Tja1043_SetDiagDemState(CanTrcv_Cfg_DemIdList(index,0u),CanTrcv_Tja1043_DiagStatus[index].BusFailure);
            CanTrcv_Tja1043_SetDiagDemState(CanTrcv_Cfg_DemIdList(index,1u),CanTrcv_Tja1043_DiagStatus[index].LocalFailure);
            #endif
        }
    #if (CANTRCV_TJA1043_DEV_ERROR_REPORT == STD_ON)
        if (errorId != CANTRCV_TJA1043_E_NO_ERROR)
        {
            CanTrcv_DetReportError(CANTRCV_TJA1043_MAINFUNCTIONDIAGNOSTICS, errorId);
        }
    #else
            CANTRCV_TJA1043_DUMMY_STATEMENT(errorId); /* PRQA S 1338,2983,3112 */ /* MD_MSR_DummyStmt */
    #endif

    }
}





#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON) 
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_ReportWakeup
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_ReportWakeup(uint8 CanTrcvIndex)
{
  /* ----- Implementation ----------------------------------------------- */
  
  /* #100 If any wake-up event occurred, report it to EcuM. */
  /* #110 Depending on configuration report to EcuM the wake-up source which belongs to occurred wake-up reason (POWER_ON, BY_SYSERR (only PN), BY_BUS, BY_PIN). */
  switch(CanTrcv_Tja1043_Prob[CanTrcvIndex].wakeUpReason)
  {
  case CANTRCV_TJA1043_WU_BY_BUS:
    /* \trace SPEC-14953 */
    EcuM_SetWakeupEvent( CanTrcvCfg_GetWakeupSource(CanTrcvIndex) );
    break;

  default:
    /* No valid or an internal wakeup. Do not report this as wakeup event */
    break;
  }
}
#endif






#if (CANTRCV_TJA1043_WAKEUP_BY_BUS_USED == STD_ON)
# if (CANTRCV_TJA1043_CONFIGURATION_VARIANT != CANTRCV_TJA1043_CONFIGURATION_VARIANT_PRECOMPILE) || (!defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TJA1043) && !defined (CANTRCV_TJA1043_HW_REFERENCE_GROUP_TLE9252))
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_CheckWa
 **********************************************************************************************************************/
/*! Internal comment removed.
 *
 *
 *
 *
 **********************************************************************************************************************/
CANTRCV_TJA1043_LOCAL_INLINE FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_CheckWa(uint8_least CanTrcvIndex)
{
  Dio_LevelType CanTrcvSTB;
  Dio_LevelType CanTrcvRXD;
  Dio_LevelType CanTrcvERR;
  Std_ReturnType retVal = E_NOT_OK;
  
  CanTrcvERR = Dio_ReadChannel(CanTrcv_Tja1043_GetPinERROfDioConfiguration(CanTrcvIndex));
  /* #10 Check the configured hardware variant group for the given channel. */
  if (CanTrcv_Tja1043_GetHw_VariantGroup(CanTrcvIndex) == 0x00u) /* COV_CANTRCV_HL_LL_TJA1043_CODECOV_HW_SPECIFIC */
  {
    CanTrcvSTB = Dio_ReadChannel(CanTrcv_Tja1043_GetPinSTBOfDioConfiguration(CanTrcvIndex));
    /* #20 Evaluate the Dio pins of the Tja1043 reference group for an occured wakeup. */
    if (CANTRCV_TJA1043_CHECK_WA_TJA1043(CanTrcvIndex))
    {
      retVal = E_OK;
    }
  }
  else
  {
    CanTrcvRXD = Dio_ReadChannel(CanTrcv_Tja1043_GetPinRXDOfDioConfiguration(CanTrcvIndex));
    /* #30 Evaluate the Dio pins of the Tle9252 reference group for an occured wakeup. */
    if (CANTRCV_TJA1043_CHECK_WA_TLE9252(CanTrcvIndex))
    {
      retVal = E_OK;
    }
  }
  
  return retVal;
}
# endif
#endif


#define CANTRCV_TJA1043_STOP_SEC_CODE
#include "CanTrcv_8_Tja1043_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */




/* ********************************************************************************************************************
 *  END OF FILE
 * *******************************************************************************************************************/
