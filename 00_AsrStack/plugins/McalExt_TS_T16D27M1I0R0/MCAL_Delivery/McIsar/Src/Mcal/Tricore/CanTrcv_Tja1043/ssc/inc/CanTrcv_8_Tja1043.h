
#if !defined (CANTRCV_TJA1043_API_H)
# define CANTRCV_TJA1043_API_H

/* PRQA S 0850 EOF */ /* MD_MSR_MacroArgumentEmpty */
/* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */

# define V_CANTRCV_TJA1043_HEADER

/* ********************************************************************************************************************
 * INCLUDES
 * *******************************************************************************************************************/
# include "CanTrcv_8_Tja1043_Cfg.h" /* SREQ00010148,SREQ00007523 */

#if (CANTRCV_TJA1043_SCHM_GENERAL == STD_ON)
# include "SchM_CanTrcv_Tja1043.h"
#endif
#include "Os_api_cfg.h"
/* ********************************************************************************************************************
 * Module version
 * *******************************************************************************************************************/

# define CANTRCV_TJA1043_AR_RELEASE_MAJOR_VERSION      4u
# define CANTRCV_TJA1043_AR_RELEASE_MINOR_VERSION      0u
# define CANTRCV_TJA1043_AR_RELEASE_REVISION_VERSION   3u
# define CANTRCV_TJA1043_AUTOSARVERSION_4X             0x403u


/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans_Tja1043CandioAsr CQComponent : Implementation */
# define DRVTRANS_TJA1043CANDIOASR_VERSION                 0x0404u
# define DRVTRANS_TJA1043CANDIOASR_RELEASE_VERSION         0x00u

#if defined(CANTRCV_TJA1043_INCLUDE_INTERNAL) /* COV_CANTRCV_HL_TJA1043_VARCOV_AVOID_COREVER_REDEF */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvTrans__coreCanxAsr CQComponent : Implementation */
# define DRVTRANS__CORECANXASR_VERSION                         0x0507u
# define DRVTRANS__CORECANXASR_RELEASE_VERSION                 0x00u
#endif

#  define CANTRCV_TJA1043_SW_MAJOR_VERSION      ((uint8)((DRVTRANS_TJA1043CANDIOASR_VERSION & 0xFF00u) >> 8))
#  define CANTRCV_TJA1043_SW_MINOR_VERSION               (DRVTRANS_TJA1043CANDIOASR_VERSION & 0x00FFu)
#  define CANTRCV_TJA1043_SW_PATCH_VERSION                DRVTRANS_TJA1043CANDIOASR_RELEASE_VERSION




#define CANTRCV_TJA1043_SUPPORTS_MODE_STANDBY

#define CANTRCV_TJA1043_SUPPORTS_MODE_SLEEP






/* ********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 * *******************************************************************************************************************/ 
# define CANTRCV_TJA1043_VENDOR_ID                      30u
# define CANTRCV_TJA1043_MODULE_ID                      70u

/* ! API IDs for Error Reporting */
# define CANTRCV_TJA1043_INIT_ID                        0x00u
# define CANTRCV_TJA1043_SETOPMODE_ID                   0x01u
# define CANTRCV_TJA1043_GETOPMODE_ID                   0x02u
# define CANTRCV_TJA1043_GETBUSWUREASON_ID              0x03u
# define CANTRCV_TJA1043_GETVERSIONINFO_ID              0x04u
# define CANTRCV_TJA1043_SETWAKEUPMODE_ID               0x05u
# define CANTRCV_TJA1043_MAINFUNCTION_ID                0x06u
# define CANTRCV_TJA1043_CHECKWAKEUP_ID                 0x07u 
# define CANTRCV_TJA1043_MAINFUNCTIONDIAGNOSTICS        0x08u
# define CANTRCV_TJA1043_GETTRCVSYSTEMDATA_ID           0x09u
# define CANTRCV_TJA1043_CLEARTRCVWUFFLAG_ID            0x0Au
# define CANTRCV_TJA1043_READTRCVTIMEOUTFLAG_ID         0x0Bu
# define CANTRCV_TJA1043_CLEARTRCVTIMEOUTFLAG_ID        0x0Cu
# define CANTRCV_TJA1043_READTRCVSILENCEFLAG_ID         0x0Du
# define CANTRCV_TJA1043_CHECKWAKEFLAG_ID               0x0Eu
# define CANTRCV_TJA1043_SETPNACTIVATIONSTATE_ID        0x0Fu
# define CANTRCV_TJA1043_SPIINDICATION_ID               0x10u


# define CANTRCV_TJA1043_OP_MODE_NORMAL                 CANTRCV_TRCVMODE_NORMAL
# define CANTRCV_TJA1043_OP_MODE_STANDBY                CANTRCV_TRCVMODE_STANDBY 
# define CANTRCV_TJA1043_OP_MODE_SLEEP                  CANTRCV_TRCVMODE_SLEEP

# define CANTRCV_TJA1043_WU_ENABLE                      CANTRCV_WUMODE_ENABLE
# define CANTRCV_TJA1043_WU_DISABLE                     CANTRCV_WUMODE_DISABLE
# define CANTRCV_TJA1043_WU_CLEAR                       CANTRCV_WUMODE_CLEAR

# define CANTRCV_TJA1043_WU_ERROR                       CANTRCV_WU_ERROR
# define CANTRCV_TJA1043_WU_NOT_SUPPORTED               CANTRCV_WU_NOT_SUPPORTED
# define CANTRCV_TJA1043_WU_BY_BUS                      CANTRCV_WU_BY_BUS
# define CANTRCV_TJA1043_WU_INTERNALLY                  CANTRCV_WU_INTERNALLY
# define CANTRCV_TJA1043_WU_RESET                       CANTRCV_WU_RESET
# define CANTRCV_TJA1043_WU_POWER_ON                    CANTRCV_WU_POWER_ON
# define CANTRCV_TJA1043_WU_BY_PIN                      CANTRCV_WU_BY_PIN
# define CANTRCV_TJA1043_WU_BY_SYSERR                   CANTRCV_WU_BY_SYSERR

# define CANTRCV_TJA1043_E_NO_ERROR                     0x00u
# define CANTRCV_TJA1043_E_INVALID_CAN_NETWORK          0x01u
/* ! SREQ00010156: Keep the invalid CAN Network switch for compatibility reason. */
# define CANTRCV_TJA1043_E_INVALID_TRANSCEIVER          CANTRCV_TJA1043_E_INVALID_CAN_NETWORK
# define CANTRCV_TJA1043_E_PARAM_POINTER                0x02u
# define CANTRCV_TJA1043_E_UNINIT                       0x11u
# define CANTRCV_TJA1043_E_TRCV_NOT_STANDBY             0x21u
# define CANTRCV_TJA1043_E_TRCV_NOT_NORMAL              0x22u
# define CANTRCV_TJA1043_E_PARAM_TRCV_WAKEUP_MODE       0x23u
# define CANTRCV_TJA1043_E_PARAM_TRCV_OP_MODE           0x24u
# define CANTRCV_TJA1043_E_BAUDRATE_NOT_SUPPORTED       0x25u
# define CANTRCV_TJA1043_E_CLR_TRCV_WUF_NOT_CALLED      0x30u
# define CANTRCV_TJA1043_E_NO_TRCV_CONTROL              0x40u /* SREQ00010156: Actual ID is unspecified in SWS! */


# define CANTRCV_TJA1043_WAKEUP_NOT_SUPPORTED          0u
# define CANTRCV_TJA1043_WAKEUP_BY_POLLING             1u
# define CANTRCV_TJA1043_WAKEUP_BY_ISR                 2u
/* ! Compatibility defines... */
# define CANTRCV_TJA1043_WAKEUP_NONE                   CANTRCV_TJA1043_WAKEUP_NOT_SUPPORTED
# define CANTRCV_TJA1043_WAKEUP_POLLING                CANTRCV_TJA1043_WAKEUP_BY_POLLING
# define CANTRCV_TJA1043_WAKEUP_ISR                    CANTRCV_TJA1043_WAKEUP_BY_ISR

# define CanTrcv_Tja1043_TrcvModeType                  CanTrcv_TrcvModeType
# define CanTrcv_Tja1043_TrcvWakeupModeType            CanTrcv_TrcvWakeupModeType
# define CanTrcv_Tja1043_TrcvWakeupReasonType          CanTrcv_TrcvWakeupReasonType


/* ! Timer configuration */


# define CANTRCV_TJA1043_USE_TIMERS                    STD_OFF

/* ! Predefined timer indexes (0x01 - 0x0f)                                   */
# define kCanTrcv_Tja1043_LoopInit                          0x01






/* ********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 * *******************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 * *******************************************************************************************************************/
/* SREQ00007522 */
/* ! Defines the state of any requested FLAG-action: *SET or *CLEARED. */
typedef enum
{
  CANTRCV_TJA1043_FLAG_SET,
  CANTRCV_TJA1043_FLAG_CLEARED
}
CanTrcv_Tja1043_TrcvFlagStateType;

/* ! Defines the state of PN (= Partial Networking): *ENABLED or *DISABLED. */
typedef enum
{
  CANTRCV_TJA1043_PN_ENABLED,
  CANTRCV_TJA1043_PN_DISABLED
} CanTrcv_Tja1043_PNActivationType;




/* ! The following type includes CAN transceiver channel specific settings. */
typedef struct
{
  /* ---- Common attributes ---- */

  /* ! Last detected wakeup reason */
  CanTrcv_Tja1043_TrcvWakeupReasonType wakeUpReason;

  /* ! Specifies whether or not to report wakeups */
  CanTrcv_Tja1043_TrcvWakeupModeType wakeUpReport;






  /* ! HW specific attributes */

} CanTrcv_Tja1043_Prob_Type;


typedef enum
{
    TJA1043_DIAG_STATE_NOFAULT=0u,
    TJA1043_DIAG_STATE_FAULT=1u
}CanTrcv_Tja1043_DiagStateEcumType;


typedef struct 
{
    /*bus err*/
    CanTrcv_Tja1043_DiagStateEcumType BusFailure;
    /*local err*/
    CanTrcv_Tja1043_DiagStateEcumType LocalFailure;
}CanTrcv_Tja1043_DiagStatusType;

/* ********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 * *******************************************************************************************************************/

/* ********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 * *******************************************************************************************************************/
/* for callback function prototypes see CanTrcv_Cbk.h */
# define CANTRCV_TJA1043_START_SEC_CODE
# include "CanTrcv_8_Tja1043_MemMap.h"



/************************************************************************************************************
 | NAME:  CanTrcv_Tja1043_Init()
 ***********************************************************************************************************/
/*! \brief         Initializes the CAN transceiver module.
 *  \details       Initializes all active channels of the CAN transceiver driver which are configured in the configuration tool.
 *                 This function has the service id 0x00.
 *  \param[in]     ConfigPtr - Pointer to the CanTrcv_Tja1043_Config structure.
 *                 If multiple configurations are available, the active configuration can be selected by using the related CanTrcv_Tja1043_Config_<IdentityName> structure.
 *  \pre           The function CanTrcv_Tja1043_InitMemory must be called before the function CanTrcv_Tja1043_Init can be called.
 *                 This function must be called before any other service functionality of the transceiver driver
 *                 The SPI/DIO driver must be initialized
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
***********************************************************************************************************/
extern FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_Init( P2CONST(CanTrcv_Tja1043_ConfigType, AUTOMATIC, CANTRCV_TJA1043_CONST) ConfigPtr );
#define CanTrcv_8_Tja1043_Init CanTrcv_Tja1043_Init


/***********************************************************************************************************************
 | NAME:  CanTrcv_Tja1043_InitMemory
 **********************************************************************************************************************/
/*! \brief         Initializes the memory of the CAN transceiver module.
 *  \details       -
 *  \param[in]     -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
 **********************************************************************************************************************/
FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_InitMemory(void);
#define CanTrcv_8_Tja1043_InitMemory CanTrcv_Tja1043_InitMemory

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_SetOpMode
 **********************************************************************************************************************/
/*! \brief       Changes the transceiver operating mode to the requested mode.
 *  \details     This function has the service id 0x01.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[in]   OpMode: Operating mode which shall be set.
 *  \return      E_OK: Change of transceiver operating mode was successful.
 *  \return      E_NOT_OK: Change of transceiver operating mode failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_SetOpMode(uint8 CanTrcvIndex, CanTrcv_TrcvModeType OpMode);
#define CanTrcv_8_Tja1043_SetOpMode CanTrcv_Tja1043_SetOpMode

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetOpMode
 **********************************************************************************************************************/
/*! \brief       Returns the current transceiver operating mode.
 *  \details     DIO transceiver: The mode is determined from status of PINs of the transceiver hardware.
 *               SPI transceiver: The mode is read from state variable. No access to transceiver hardware is performed.
 *               This function has the service id 0x02.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  OpMode: Pointer to buffer where the current operating mode is stored.
 *  \return      E_OK: Determination of current transceiver operating mode was successful.
 *  \return      E_NOT_OK: Determination of transceiver operating mode failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetOpMode(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) OpMode);
#define CanTrcv_8_Tja1043_GetOpMode CanTrcv_Tja1043_GetOpMode

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetBusWuReason
 **********************************************************************************************************************/
/*! \brief       Returns the bus wake-up reason.
 *  \details     The wake-up reason is read from state variable. No access to transceiver hardware is performed.
 *               This function has the service id 0x03.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[out]  Reason: Pointer to buffer where the bus wake-up reason is stored.
 *  \return      E_OK: Determination of wake-up reason was successfull.
 *  \return      E_NOT_OK: Determination of wake-up reason failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetBusWuReason(uint8 CanTrcvIndex, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) Reason);
#define CanTrcv_8_Tja1043_GetBusWuReason CanTrcv_Tja1043_GetBusWuReason

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_SetWakeupMode
 **********************************************************************************************************************/
/*! \brief       Changes the wake-up mode to the requested mode.
 *  \details     For more information about possible wake-up modes please see the description of type <CanTrcv_TrcvWakeupModeType>.
 *               This function has the service id 0x05.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \param[in]   TrcvWakeupMode: Requested wake-up mode for the transceiver channel (CanTrcvIndex).
 *  \return      E_OK: Change of wake-up mode was successful.
 *  \return      E_NOT_OK: Change of wake-up mode has failed or passed parameter(s) is/are invalid.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_SetWakeupMode(uint8 CanTrcvIndex, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#define CanTrcv_8_Tja1043_SetWakeupMode CanTrcv_Tja1043_SetWakeupMode

/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_CheckWakeup
 **********************************************************************************************************************/
/*! \brief       Checks if a wake-up event was detected.
 *  \details     This function has the service id 0x07.
 *  \param[in]   CanTrcvIndex: Index of the selected transceiver channel to which API call has to be applied.
 *  \return      E_OK: Wake-up was detected / the request to check for wake-up was accepted (only asynchronous SPI-interface).
 *  \return      E_NOT_OK: No wake-up was detected / the request to check for wake-up was rejected (only asynchronous SPI-interface).
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE only for different transceiver channels (CanTrcvIndex)
 *  \synchronous TRUE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(Std_ReturnType, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_CheckWakeup(uint8 CanTrcvIndex);
#define CanTrcv_8_Tja1043_CheckWakeup CanTrcv_Tja1043_CheckWakeup

#if (CANTRCV_TJA1043_GET_VERSION_INFO == STD_ON)
/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version info of the CAN transceiver module.
 *  \details     The versions are stored into the structure referenced by parameter: VersionInfo.
 *               This function has the service id 0x04.
 *  \param[out]  VersionInfo: Pointer to structure for storing of version info.
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      CANTRCV_TJA1043_GET_VERSION_INFO == STD_ON
 **********************************************************************************************************************/
extern FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTRCV_TJA1043_APPL_VAR) VersionInfo);
#define CanTrcv_8_Tja1043_GetVersionInfo CanTrcv_Tja1043_GetVersionInfo
#endif /* (CANTRCV_TJA1043_GET_VERSION_INFO == STD_ON) */

/* SREQ00007670 */



/***********************************************************************************************************************
| NAME:  CanTrcv_Tja1043_MainFunction
 **********************************************************************************************************************/
/*! \brief       Service to scan all buses for wake up events and perform these event.
 *  \details     This function has the service id 0x06.
 *  \param[in]   -
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_ON), FALSE (if CANTRCV_TJA1043_SPI_ACCESS_SYNCHRONOUS == STD_OFF)
 *  \config      -
 **********************************************************************************************************************/
extern FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_MainFunction(void);  /* ESCAN00091270 */
#define CanTrcv_8_Tja1043_MainFunction CanTrcv_Tja1043_MainFunction
extern FUNC(void, CANTRCV_TJA1043_CODE) CanTrcv_Tja1043_MainFunctionDiagnostics(void);
#define CanTrcv_8_Tja1043_MainFunctionDiagnostics CanTrcv_Tja1043_MainFunctionDiagnostics

# define CANTRCV_TJA1043_STOP_SEC_CODE
# include "CanTrcv_8_Tja1043_MemMap.h"

/*! 
* \exclusivearea CANTRCV_TJA1043_EXCLUSIVE_AREA_0
* Ensures consistent handling of CanTrcv-hardware via the DIO-interface.
* \protects Atomic / consistent reading of DIO-pins and setting of them.
* \usedin CanTrcv_Tja1043_Init(), CanTrcv_Tja1043_SetOpMode(), CanTrcv_Tja1043_GetOpMode(), CanTrcv_Tja1043_CheckWakeup() and CanTrcv_Tja1043_MainFunction().
* \exclude call of: CanTrcv-driver APIs: CanTrcv_Tja1043_Init(), CanTrcv_Tja1043_SetOpMode(), CanTrcv_Tja1043_GetOpMode(), CanTrcv_Tja1043_CheckWakeup() and CanTrcv_Tja1043_MainFunction() 
*                   AND in fact the instructions within the exclusive area must be executed atomic without any interruption / delay in between.
* \length SHORT
* \endexclusivearea
*/



#endif /* CANTRCV_TJA1043_API_H */

/* ********************************************************************************************************************
 *  END OF FILE
 * *******************************************************************************************************************/
