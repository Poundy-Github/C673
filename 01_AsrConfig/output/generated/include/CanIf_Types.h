/**
 * \file
 *
 * \brief AUTOSAR CanIf
 *
 * This file contains the implementation of the AUTOSAR
 * module CanIf.
 *
 * \version 6.10.19
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2021 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */

#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/*==================[inclusions]=============================================*/

#include <TSAutosar.h>
#include <Can_GeneralTypes.h>


/*==================[macros]=================================================*/

/** \brief Maximum DLC of a CAN 2.0 frame */
#if (defined CANIF_MAXIMUM_CAN_20_DLC)
#error CANIF_MAXIMUM_CAN_20_DLC already defined!
#endif /* #if( defined CANIF_MAXIMUM_CAN_20_DLC)*/
#define CANIF_MAXIMUM_CAN_20_DLC            8U

/** \brief Maximum DLC of a CAN FD frame */
#if (defined CANIF_MAXIMUM_CAN_FD_DLC)
#error CANIF_MAXIMUM_CAN_FD_DLC already defined!
#endif /* #if( defined CANIF_MAXIMUM_CAN_FD_DLC)*/
#define CANIF_MAXIMUM_CAN_FD_DLC           64U

/*==================[type definitions]=======================================*/

/* --- general types --------------------------------------------------- */

/** \brief States for a controller in the CAN interface
 **
 ** CAN controller states: Initially CANIF_CS_UNINIT, then switch between
 ** CANIF_CS_STOPPED, CANIF_CS_STARTED and CANIF_CS_SLEEP.
 */
typedef enum
{
  CANIF_CS_UNINIT  = 0U, /**<Controller is not initialized */
  CANIF_CS_SLEEP,        /**<Controller is in sleep mode */
  CANIF_CS_STARTED,      /**<Controller is active/running */
  CANIF_CS_STOPPED       /**<Controller is stopped */
} CanIf_ControllerModeType;


/** \brief State transitions for a controller in the CAN interface
 **
 ** Internal mapping of the state transitions in the CAN driver 
 ** which are used to call the Can_SetControllerMode() API.
 */
typedef enum
{
  CANIF_T_START  = (uint8)CAN_T_START,  /**< CAN controller transition value to request state STARTED. */
  CANIF_T_STOP   = (uint8)CAN_T_STOP,   /**< CAN controller transition value to request state STOPPED. */
  CANIF_T_SLEEP  = (uint8)CAN_T_SLEEP,  /**< CAN controller transition value to request state SLEEP. */
  CANIF_T_WAKEUP = (uint8)CAN_T_WAKEUP  /**< CAN controller transition value to request state STOPPED from state SLEEP. */
} CanIf_StateTransitionType;

/** \brief Type for PDU channel mode requests
 **
 ** This type defines the possible mode requests that can be stated for a
 ** PDU channel.
 */
typedef enum
{
  CANIF_OFFLINE = 0U,      /**<Transmit and receive path of the corresponding channel are disabled => no communication mode */
  CANIF_TX_OFFLINE,        /**<Transmit path of the corresponding channel is disabled. The receive path is enabled. */
  CANIF_TX_OFFLINE_ACTIVE, /**<Transmit path of the corresponding channel is in offline active mode. The receive path is disabled. */
  CANIF_ONLINE             /**<Transmit and receive path of the corresponding channel are enabled => full operation mode */
}CanIf_PduModeType;


/** \brief Notification status type
 **
 ** This type defines the values that the "read Rx/Tx notification status"
 ** API functions return if they are activated via configuration.
 */
typedef enum
{
  CANIF_NO_NOTIFICATION = 0U,  /**<No new event since the last read attempt*/
  CANIF_TX_RX_NOTIFICATION     /**<New Rx/Tx event since the last read*/
} CanIf_NotifStatusType;

/* --- CAN driver function definitions---------------------------------- */

/** \brief Pointer type definition to function Can_Write()
 **
 ** This is a function pointer type definition for the CAN driver function
 ** Can_Write().
 */
typedef P2FUNC( Can_ReturnType, CAN_CODE, CanIf_WriteFctPtrType )
  (
    Can_HwHandleType Hth,
    const Can_PduType* PduInfo
  );
  
/** \brief Pointer type definition to function Can_SetControllerMode()
 **
 ** This is a function pointer type definition for the CAN driver function
 ** Can_SetControllerMode().
 */
typedef P2FUNC( Can_ReturnType, CAN_CODE, CanIf_SetControllerModeFctPtrType )
  (
    uint8 Controller,
    Can_StateTransitionType Transition
  );



/* --- CAN Transceiver Configuration ----------------------------------- */

/** \brief Pointer to function CanTrcv_SetOpMode()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_SetOpMode().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvSetOpModeFctPtrType )
  (
    uint8 Transceiver,
    CanTrcv_TrcvModeType OpMode
  );


/** \brief Pointer to function CanTrcv_GetOpMode()
 **
 ** This is a function pointer type for the CAN transceiver function
 ** CanTrcv_GetOpMode().
 */
typedef P2FUNC( Std_ReturnType, CANTRCV_CODE, CanIf_TrcvGetOpModeFctPtrType )
  (
    uint8 Transceiver,
    P2VAR( CanTrcv_TrcvModeType, AUTOMATIC, CANTRCV_APPL_DATA ) OpMode
  );




/* --- upper layer callbacks and notifications ------------------------- */


/** \brief Pointer to <UpperLayer>_RxIndication
 **
 ** This is a function pointer type for the RxIndication function
 ** of all well-known upper layers and for all CDDs where parameter
 ** CanIfUpperLayerUseCanId is false.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_UlRxIndFctPtrType )
  (
    PduIdType CanIfRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxPduPtr
  );


/** \brief Pointer to <CDD>_RxIndication
 **
 ** This is a function pointer type for the RxIndication function
 ** of all CDD upper layers where parameter CanIfUpperLayerUseCanId is true.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_CddRxIndFctPtrType )
  (
    PduIdType CanIfRxPduId,
    P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxPduPtr,
    Can_IdType CanIfRxCanId
  );


/** \brief Pointer to <UpperLayer>_TxConfirmation
 **
 ** This is a function pointer type for the TxConfirmation function
 ** of all upper layers of CanIf.
 */
 /* !LINKSTO CanIf.EB.User_TxConfirmation.Signature.Result.OFF, 1 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_TxConfFctPtrType )
  (
    PduIdType CanIfTxPduId
  );


/** \brief Pointer to DLC check notification functions
 **
 ** This is a function pointer type for the upper layer DLC check notification
 ** functions.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_DlcCheckNotifFctPtrType )
  (
    PduIdType CanRxPduId
  );


/** \brief Pointer to ActMainFunction functions
 **
 ** This is a function pointer type for the SchM decoupled processing
 ** activation functions.
 */
typedef P2FUNC( void, CANIF_APPL_CODE, CanIf_ActMainFctPtrType )
  (
    void
  );


/* --- CAN driver Configuration ---------------------------------------- */
/** \brief CAN Driver function configuration
 **
 ** This type is used for configuring the CAN Driver list of functions.
 */

typedef struct
{
  CanIf_WriteFctPtrType                        Write;                        /**< Can Write */
  CanIf_SetControllerModeFctPtrType            SetControllerMode;            /**< Can Set Controller Mode */
  Can_HwHandleType                             HohIdOffset;                  /**< Offset for the HW Object id in the local struct */
} CanIf_CanDrvFctConfigType;


/* --- CAN Transceiver Configuration ----------------------------------- */

/** \brief CAN Transceiver Driver function configuration
 **
 ** This type is used for configuring the CAN Transceiver Driver functions.
 */
typedef struct
{
  CanIf_TrcvSetOpModeFctPtrType setOpMode;        /**< set operation mode */
  CanIf_TrcvGetOpModeFctPtrType getOpMode;        /**< get operation mode */
} CanIf_CanTrcvConfigType;

/* --- Upper Layer Configuration --------------------------------------- */

/** \brief Upper layer callback function configuration
 **
 ** This type contains the function pointer of the API functions
 ** <UL>_RxIndication, <CDD>_RxIndication, <UL>_TxConfirmation,
 ** <UL>_DlcErrorNotification and <UL>_DlcPassedNotification of all
 ** upper layers of the CanIf.
 */
typedef struct
{
  VAR(CanIf_UlRxIndFctPtrType, TYPEDEF)       UlRxIndFctPtr;         /**< <UL>_RxIndication */


  VAR(CanIf_TxConfFctPtrType, TYPEDEF)        TxConfFctPtr;          /**< <UL>_TxConfirmation */


} CanIf_CbkFctPtrTblType;



/* --- Tx buffering ---------------------------------------------------- */

/** \brief Type for Tx buffers
 **
 ** This type is used for the transmit buffers.
 */
typedef struct
{
  Can_IdType id;                        /**< CAN ID */
  uint8 length;                         /**< DLC */
} CanIf_TxBufferType;






/*==================[external function declarations]=========================*/

/*==================[internal function declarations]=========================*/

/*==================[external constants]=====================================*/

/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/

#endif /* ifndef CANIF_TYPES_H */
/*==================[end of file]============================================*/
