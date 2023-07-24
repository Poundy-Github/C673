/**
 * \file Cpr_Stubs.c
 *
 * \brief Implement Can communication process of recevied
 *
 * \version refer the Cpr_Stubs.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Cpr_Stubs.h"
#include "Com.h"
#include "Crc.h"
#include "glob_defs.h"
#include "Rte_Dem_Type.h"
#include "Rte_Cpr.h"

/*==================[internal data]=========================================*/
/* variables for common interface begins */
GLOB_STATIC uint8     u8_RollingCounter_Previous_Value[RxMsgEnd]    = {0u};
GLOB_STATIC boolean   b_RollingCounter_Is_First[RxMsgEnd]           = {TRUE};
CPR_E2ECompute_Status_t s_E2ECompute_Error_Status[RxMsgEnd]         = {E_MSG_STATUS_NONE, E_CPR_MSG_ID_START};

/*==================[external data]=========================================*/

/*==================[external function definitions]=========================*/

/*==================[internal function definitions]=========================*/
/**
 * \functions Cpr_Read_E2ECompute_Status
 *
 * \brief
 *
 * \parameters-in e_CPR_RxMsgID
 *
 * \parameters-out uint8
 *
 * \return 	none
 *
 * \comments:return s_E2ECompute_Error_Status 
 *
 */
FUNC(uint8, COM_APPL_CODE) Cpr_RxMessageStatusInfo(e_CPR_RxMsgID eMsgIndex)
{
    if (eMsgIndex >= RxMsgEnd)
    {
        return E_MSG_STATUS_OUTID_RANGE;
    }
#if CPR_CRC_RC_TIMEOUT_ENABLE
    return s_E2ECompute_Error_Status[eMsgIndex].Cpr_Msg_ErrorState;
#else
    return E_MSG_STATUS_VALID;
#endif
}

FUNC(Std_ReturnType, RTE_CODE) Get_RxMsgStatus (Cpr_RxMsg_ID Cpr_RxMessageId, P2VAR(Cpr_Msg_State, AUTOMATIC, RTE_APPL_DATA) Cpr_MessageStatus)
{
  /* suppress compiler warnings about unused arguments */
#if CPR_CRC_RC_TIMEOUT_ENABLE
    *Cpr_MessageStatus = (Cpr_Msg_State)s_E2ECompute_Error_Status[Cpr_RxMessageId].Cpr_Msg_ErrorState;
#else
    *Cpr_MessageStatus = E_MSG_STATUS_VALID;
#endif
  
  return RTE_E_OK;
} /* FUNC(Std_ReturnType, RTE_CODE) Get_RxMsgStatus (Cpr_RxMsg_ID Cpr_RxMessageId, P2VAR(Cpr_Msg_State, AUTOMATIC, RTE_APPL_DATA) Cpr_MessageStatus) */



/**
 * \functions Cpr_Msg_E2E_Compute
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return 	none
 *
 * \comments
 *
 */
FUNC(uint8, COM_APPL_CODE)Cpr_Msg_E2E_Compute(
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr,
    uint16 MsgID, uint8 Method, uint8 RC_Byte, uint8 CRC_Byte, uint8 offset)
{
    uint8 u8_Byte_Crc       = 0;
    uint8 u8_Checksum       = 0;
    uint8 u8_High_Byte_Crc  = 0;
    uint8 u8_Low_Byte_Crc   = 0;
    uint8 u8_4_bits_Rc      = 0;
    uint8 u8_DeltaCounter   = 0;
    uint16 u16_Checksum     = 0;

    if (MsgID >= RxMsgEnd) // Wrong MsgID
    {
        return E_MSG_STATUS_OUTID_RANGE;
    }
    // Locate current error state via struct CRC_or_RC_Error_Status
    s_E2ECompute_Error_Status[MsgID].MsgID = MsgID;
    s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_VALID;

    switch (Method)
    {
        case CPR_METHOD_CRC8: // Pure CRC8
          u8_Byte_Crc     = PduInfoPtr->SduDataPtr[CRC_Byte];
          u8_4_bits_Rc    = PduInfoPtr->SduDataPtr[RC_Byte] & 0x0Fu;
          u8_Checksum     = Crc_CalculateCRC8((PduInfoPtr->SduDataPtr + offset), (RC_Byte + 1 - offset), 0xFFu, TRUE);
          u8_DeltaCounter = (u8_4_bits_Rc >= u8_RollingCounter_Previous_Value[MsgID])
                                          ? (u8_4_bits_Rc - u8_RollingCounter_Previous_Value[MsgID])
                                          : ((15u - u8_RollingCounter_Previous_Value[MsgID]) + u8_4_bits_Rc + 1u);
          
          // CRC check
          if (u8_Byte_Crc != u8_Checksum)
          {
              // CRC error
              s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC;
          }
          else
          {
            ; // no CRC error
          }

          // RC check
          // The first RC is fault tolerant.
          if (b_RollingCounter_Is_First[MsgID] == TRUE)
          {
              s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_VALID;
              b_RollingCounter_Is_First[MsgID] = FALSE;
          }
          // The delta between frames is set to 1 ONLY.
          else if(((u8_DeltaCounter > 2u)||(u8_DeltaCounter == 0u))) // Equal to ((u8_DeltaCounter > 1u) || (u8_DeltaCounter == 0u))
          {
              // RC error
              if (s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState == E_MSG_STATUS_CRC)
              {
                // Both CRC and RC error
                s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC_AND_ROLLINGCNT;
              }
              else
              {
                // ONLY RC error
                s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_ROLLINGCNT;
              }
          }
          else
          {
              if (u8_Byte_Crc != u8_Checksum)
              {
                  // CRC error
                  s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC;
              }
              else
              {
                  s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_VALID; // no CRC error
              }
          }

        // Relay RC
        u8_RollingCounter_Previous_Value[MsgID] = u8_4_bits_Rc;
        break;

        case CPR_METHOD_CRC16: // Pure CRC16
          u8_High_Byte_Crc = PduInfoPtr->SduDataPtr[CRC_Byte];
          u8_Low_Byte_Crc  = PduInfoPtr->SduDataPtr[CRC_Byte + 1];
          u8_4_bits_Rc     = PduInfoPtr->SduDataPtr[RC_Byte] & 0x0Fu;
          u16_Checksum     = Crc_CalculateCRC16((PduInfoPtr->SduDataPtr + offset), (RC_Byte + 1 - offset), 0xFFFFu, TRUE);
          u8_DeltaCounter  = (u8_4_bits_Rc >= u8_RollingCounter_Previous_Value[MsgID])
                                          ? (u8_4_bits_Rc - u8_RollingCounter_Previous_Value[MsgID])
                                          : ((15u - u8_RollingCounter_Previous_Value[MsgID]) + u8_4_bits_Rc + 1u);

          // CRC check
          if ((u8_High_Byte_Crc != ((u16_Checksum & 0xFF00u) >> 8u)) || (u8_Low_Byte_Crc != (u16_Checksum & 0x00FFu)))
          {
              // CRC error
              s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC;
          }
          else
          {
            ; // no CRC error
          }

          // RC check
          // The first RC is fault tolerant.
          if (b_RollingCounter_Is_First[MsgID] == TRUE)
          {
              s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_VALID;
              b_RollingCounter_Is_First[MsgID] = FALSE;
          }
          // The delta between frames is set to 1 ONLY.
          else if ((u8_DeltaCounter>=2u) || (u8_DeltaCounter == 0)) // Equal to ((u8_DeltaCounter > 1u) || (u8_DeltaCounter == 0u))
          {
              // RC error
              if (s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState == E_MSG_STATUS_CRC)
              {
                // Both CRC and RC error
                s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC_AND_ROLLINGCNT;
              }
              else
              {
                // ONLY RC error
                s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_ROLLINGCNT;
              }
          }
          else
          {
              if ((u8_High_Byte_Crc != ((u16_Checksum & 0xFF00u) >> 8u)) || (u8_Low_Byte_Crc != (u16_Checksum & 0x00FFu)))
              {
                  // CRC error
                  s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_CRC;
              }
              else
              {
                  s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState = E_MSG_STATUS_VALID; // no CRC error
              }
          }

          // Relay RC
          u8_RollingCounter_Previous_Value[MsgID] = u8_4_bits_Rc;
        break;

        default:
          break;
    }

    // Return Check Status.
    return s_E2ECompute_Error_Status[MsgID].Cpr_Msg_ErrorState;
}


/* receive callouts */
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_50_80R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_50  DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_50, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDVCU_161_353R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: VCU_161
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, VCU_161, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_170_368R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_170
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_170, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_17A_378R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_17A
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_17A, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_17E_382R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_17E
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_17E, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_180_384R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_180
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_180, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_1C2_450R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_1C2
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_1C2, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_20B_523R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
      uint8 Compute_ret = E_MSG_STATUS_VALID;

      // ID: GW_20B
      // DLC: 64 bytes
      Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_20B, 1, 61, 62, 0);

      return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_24F_591R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_24F
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_24F, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_278_632R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_278
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_278, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_288_648R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_288
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_288, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_28B_651R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_28B
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_28B, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2A8_680R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: GW_2A8
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_2A8, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2C2_706R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_2C2
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_2C2, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_2DE_734R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: GW_2DE
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_2DE, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDVCU_38A_906R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: VCU_38A
    // DLC:  8 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, VCU_38A, 0, 6, 7, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDGW_3C2_962R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: GW_3C2
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, GW_3C2, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_111_273R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_111
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_111, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_112_274R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_112
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_112, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_113_275R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_113
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_113, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_114_276R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_114
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_114, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_115_277R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_115
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_115, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_116_278R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_116
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_116, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_117_279R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_117
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_117, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_118_280R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_118
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_118, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_119_281R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_119
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_119, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11A_282R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11A
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11A, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11B_283R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11B
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11B, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11C_284R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11C
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11C, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11D_285R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11D
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11D, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11E_286R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11E
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11E, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_11F_287R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_11F
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_11F, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_120_288R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_120
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_120, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_136_310R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: FR_136
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_136, 1, 61, 62, 0);
    
    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDFR_138_312R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;
    // ID: FR_138
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, FR_138, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_19B_411R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: ADC_19B
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, ADC_19B, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_200_512R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    // ID: ADC_200
    // DLC: 16 bytes
    // Confirmed no need to handle ADC_200 by Mingfen

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_345_837R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    uint8 Compute_ret = E_MSG_STATUS_VALID;

    // ID: ADC_345
    // DLC: 64 bytes
    Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, ADC_345, 1, 61, 62, 0);

    return TRUE;
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)PDADC_346_838R_ComIPduCallout(
    PduIdType ID,
    P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
  uint8 Compute_ret = E_MSG_STATUS_VALID;

  // ID: ADC_346
  // DLC: 64 bytes
  Compute_ret = Cpr_Msg_E2E_Compute(PduInfoPtr, ADC_346, 1, 61, 62, 0);

  return TRUE;
}

FUNC(boolean, COM_APPL_CODE) GW_507_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
  uint8 signal_AEB = 0;
  uint8 signal_FCW = 0;
  uint8 signal_FAB = 0;
  uint8 signal_LDW_or_LKA = 0;
  uint8 signal_LDW_Warning = 0;

  /*HU_AutoBrakeEnable:
    0x0:off
    0x1:on
  */
  signal_AEB = (uint8)PduInfoPtr->SduDataPtr[16] >> 3u & 0x01;
  if(signal_AEB == 0x0 || signal_AEB == 0x1)
  {
    Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_AEB, signal_AEB);
  }

  /*HU_FCWSetting:
    0x0:Early
    0x1:Normal
    0x2:Late
    0x3:Off
  */
  signal_FCW = (uint8)(PduInfoPtr->SduDataPtr[20] >> 3u) & 0x07;
  if(signal_FCW == 0x0 || signal_FCW == 0x1 || signal_FCW == 0x2 || signal_FCW == 0x3)
  {
    Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_FCW, signal_FCW);
  }

  /*HU_HMAEnable:
    0x0:off
    0x1:on
  */
  signal_FAB = (uint8)(PduInfoPtr->SduDataPtr[1] >> 4u) & 0x01;
  if(signal_FAB == 0x0 || signal_FAB == 0x1)
  {
    Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_FAB, signal_FAB);
  }

  /* HU_LASModeSelection:
    0x1:LDW
    0x2:LKA
    0x3:LCS
    0x7:OFF
  */
  signal_LDW_or_LKA = (uint8)(PduInfoPtr->SduDataPtr[0] >> 3u) & 0x07;
  if(signal_LDW_or_LKA == 0x1 || signal_LDW_or_LKA == 0x2 || signal_LDW_or_LKA == 0x3 || signal_LDW_or_LKA == 0x7)
  {
    Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_LDW_or_LKA, signal_LDW_or_LKA);
  }

  /*HU_LASWarningModeSelection:
    0x1:visual
    0x2:sound
    0x3:vibration
    0x4:sound and vibration
  */
  signal_LDW_Warning = (PduInfoPtr->SduDataPtr[1]) & 0x07;
  if(signal_LDW_Warning == 0x1 || signal_LDW_Warning == 0x2 ||signal_LDW_Warning == 0x3 ||signal_LDW_Warning == 0x4)
  {
   Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_LDW_Warning, signal_LDW_Warning);
  }

	return TRUE;
}

FUNC(boolean, COM_APPL_CODE) GW_3BD_ComIPduCallout
(
  PduIdType ID,
  P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr
)
{
  uint8 signal_ELK = 0;

  /*HU_ELKEnable
    0x1:OFF
    0x2:ON
  */
  signal_ELK = (uint8)PduInfoPtr->SduDataPtr[0] & 0x03;
  if(signal_ELK == 0x1 || signal_ELK == 0x2)
  {
    Fcu_TxProcess_FuncSwitch_WriteNvm(Cpr_FUNC_ELK, signal_ELK);
  }
  
  return TRUE;
}

/***************************************Signal Timeout Callout  Start**********************************************/
/* ID:VCU_161 sigain:VcuAccrMod  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)VCU_161_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[VCU_161].MsgID = VCU_161;
    s_E2ECompute_Error_Status[VCU_161].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_17A sigain:EspVehSpd  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_17A_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_17A].MsgID = GW_17A;
    s_E2ECompute_Error_Status[GW_17A].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_1C2 sigain:EspAbsActv  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_1C2_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_1C2].MsgID = GW_1C2;
    s_E2ECompute_Error_Status[GW_1C2].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_20B sigain:WhlSpdLeReDir  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_20B_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_20B].MsgID = GW_20B;
    s_E2ECompute_Error_Status[GW_20B].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_2C2 sigain:IBBrkPedlModSts  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_2C2_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_2C2].MsgID = GW_2C2;
    s_E2ECompute_Error_Status[GW_2C2].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_278 sigain:ESP_LatAccelValid  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_278_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_278].MsgID = GW_278;
    s_E2ECompute_Error_Status[GW_278].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_170 sigain:EPS_ActualMotorTorq  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_170_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_170].MsgID = GW_170;
    s_E2ECompute_Error_Status[GW_170].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_180 sigain:EpsSasCalSts  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_180_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_180].MsgID = GW_180;
    s_E2ECompute_Error_Status[GW_180].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_17E sigain:EPS_Pinionang  TimeOut:100ms*/
FUNC(boolean, COM_APPL_CODE)GW_17E_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_17E].MsgID = GW_17E;
    s_E2ECompute_Error_Status[GW_17E].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_24F sigain:EPS_LDW_ShakeLevStatus  TimeOut:200ms*/
FUNC(boolean, COM_APPL_CODE)GW_24F_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_24F].MsgID = GW_24F;
    s_E2ECompute_Error_Status[GW_24F].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_288 sigain:BcmHiBeamSts  TimeOut:400ms*/
FUNC(boolean, COM_APPL_CODE)GW_288_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_288].MsgID = GW_288;
    s_E2ECompute_Error_Status[GW_288].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_2DE sigain:IP_DISFail  TimeOut:500ms*/
FUNC(boolean, COM_APPL_CODE)GW_2DE_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_2DE].MsgID = GW_2DE;
    s_E2ECompute_Error_Status[GW_2DE].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:GW_50 sigain:SrsCycCntr  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)GW_50_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[GW_50].MsgID = GW_50;
    s_E2ECompute_Error_Status[GW_50].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

//FR node

/* ID:FR_111 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_111_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_111].MsgID = FR_111;
    s_E2ECompute_Error_Status[FR_111].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_112 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_112_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_112].MsgID = FR_112;
    s_E2ECompute_Error_Status[FR_112].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_113 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_113_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_113].MsgID = FR_113;
    s_E2ECompute_Error_Status[FR_113].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_114 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_114_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_114].MsgID = FR_114;
    s_E2ECompute_Error_Status[FR_114].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_115 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_115_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_115].MsgID = FR_115;
    s_E2ECompute_Error_Status[FR_115].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_116 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_116_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_116].MsgID = FR_116;
    s_E2ECompute_Error_Status[FR_116].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_117 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_117_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_117].MsgID = FR_117;
    s_E2ECompute_Error_Status[FR_117].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_118 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_118_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_118].MsgID = FR_118;
    s_E2ECompute_Error_Status[FR_118].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_119 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_119_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_119].MsgID = FR_119;
    s_E2ECompute_Error_Status[FR_119].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11A sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11A_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11A].MsgID = FR_11A;
    s_E2ECompute_Error_Status[FR_11A].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11B sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11B_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11B].MsgID = FR_11B;
    s_E2ECompute_Error_Status[FR_11B].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11C sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11C_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11C].MsgID = FR_11C;
    s_E2ECompute_Error_Status[FR_11C].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11D sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11D_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11D].MsgID = FR_11D;
    s_E2ECompute_Error_Status[FR_11D].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11E sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11E_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11E].MsgID = FR_11E;
    s_E2ECompute_Error_Status[FR_11E].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_11F sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_11F_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_11F].MsgID = FR_11F;
    s_E2ECompute_Error_Status[FR_11F].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_120 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_120_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_120].MsgID = FR_120;
    s_E2ECompute_Error_Status[FR_120].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:FR_136 sigain:FR_ObjCount  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)FR_136_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[FR_136].MsgID = FR_136;
    s_E2ECompute_Error_Status[FR_136].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

//ADC node
/* ID:ADC_345 sigain:RLR_ElkOBJ1_Type  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_345_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[ADC_345].MsgID = ADC_345;
    s_E2ECompute_Error_Status[ADC_345].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}

/* ID:ADC_346 sigain:RLR_ElkOBJ3_Type  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_346_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[ADC_346].MsgID = ADC_346;
    s_E2ECompute_Error_Status[ADC_346].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}
/* ID:ADC_19B sigain:ADS_Fail  TimeOut:1s*/
FUNC(boolean, COM_APPL_CODE)ADC_19B_SignalTimeout(PduIdType ID, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_DATA) PduInfoPtr)
{
    s_E2ECompute_Error_Status[ADC_19B].MsgID = ADC_19B;
    s_E2ECompute_Error_Status[ADC_19B].Cpr_Msg_ErrorState = E_MSG_STATUS_TOUT;
    return TRUE;
}
/***************************************Signal Timeout Callout  End**********************************************/


