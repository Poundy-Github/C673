/**
 * \file Cps_Stubs.c
 *
 * \brief Implement Can communication process of recevied
 *
 * \version refer the Cps_Stubs.h.
 *
 */
/*==================[inclusions]============================================*/
#include "Cps_Stubs.h"
#include "Com.h"
#include "Crc.h"
#include "glob_defs.h"
#include "ComM_BSW.h"
#include "comcoordinator.h"

/*==================[external data]=========================================*/

/*==================[internal data]=========================================*/
static uint8 Get_ComMode_FC_PRIVATE = 0;
static uint8 Get_ComMode_FC_PUBLIC  = 0;
#if CPS_CRC_AND_RC_ENABLE
enum TxMsgID // Total number: COM_TX_CALL_OUT_FUNC_PTR_ARRAY_SIZE
{
  FC_107, // ID: FC_107, DLC: 64 bytes
  FC_108,
  FC_150,
  FC_151,
  FC_152,
  FC_153,
  FC_154,
  FC_160,
  FC_161,
  FC_162,
  FC_163,
  FC_164,
  FC_165,
  FC_166,
  FC_167,
  FC_168,
  FC_169,
  FC_170,
  FC_171,
  FC_172,
  FC_173,
  FC_174,
  FC_175,
  FC_176,
  FC_177,
  FC_178,
  FC_179,
  FC_180,
  FC_181,
  FC_190,
  FC_193,
  FC_195,
  FC_196,
  FC_197,
  FC_198,
  FC_1BA, // UNUSUAL DBC layout, TODO
  FC_244, // UNUSUAL DBC layout, NEED review
  FC_307, // UNUSUAL DBC layout, NEED review
  FC_312, // UNUSUAL DBC layout, NEED review
  FC_31A  // UNUSUAL DBC layout, NEED review
};

GLOB_STATIC uint8 u8_RC_FC_107_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_108_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_150_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_151_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_152_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_153_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_154_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_160_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_161_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_162_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_163_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_164_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_165_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_166_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_167_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_168_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_169_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_170_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_171_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_172_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_173_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_174_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_175_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_176_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_177_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_178_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_179_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_180_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_181_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_190_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_193_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_195_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_196_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_197_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_198_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_1BA_0_Current = 0u; // Need to be confirmed
GLOB_STATIC uint8 u8_RC_FC_1BA_1_Current = 0u; // Need to be confirmed
GLOB_STATIC uint8 u8_RC_FC_24E_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_25E_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_244_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_35E_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_322_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_344_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_35F_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_307_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_3E4_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_312_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_36D_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_30A_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_30D_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_367_Current = 0u;
GLOB_STATIC uint8 u8_RC_FC_31A_Current = 0u;
#endif

/*==================[internal function declarations]========================*/
static uint8 Cps_GetValidWakeupSource(void);

/* send callouts */
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_107_263T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_108_264T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_150_336T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_151_337T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_152_338T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_153_339T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_154_340T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_160_352T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_161_353T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_162_354T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_163_355T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_164_356T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_165_357T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_166_358T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_167_359T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_168_360T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_169_361T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_170_368T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_171_369T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_172_370T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_173_371T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_174_372T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_175_373T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_176_374T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_177_375T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_178_376T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_179_377T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_180_384T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
    /* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_181_385T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_190_400T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_193_403T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_195_405T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_196_406T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_197_407T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_198_408T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_1BA_442T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_244_580T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_307_775T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_312_786T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_31A_794T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr);
/*==================[external function definitions]=========================*/
/*==================[internal function definitions]=========================*/
/* send callouts */
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_107_263T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_107
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_107_Current);
    // Calculate RC
    u8_RC_FC_107_Current += 1u;
    u8_RC_FC_107_Current = u8_RC_FC_107_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_107_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_108_264T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_108
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_108_Current);
    // Calculate RC
    u8_RC_FC_108_Current += 1u;
    u8_RC_FC_108_Current = u8_RC_FC_108_Current % 16;
    
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_108_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_150_336T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_150
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_150_Current);
    // Calculate RC
    u8_RC_FC_150_Current += 1u;
    u8_RC_FC_150_Current = u8_RC_FC_150_Current % 16;
  
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_150_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_151_337T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_151
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_151_Current);
    // Calculate RC
    u8_RC_FC_151_Current += 1u;
    u8_RC_FC_151_Current = u8_RC_FC_151_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_151_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_152_338T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_152
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_152_Current);

    // Calculate RC
    u8_RC_FC_152_Current += 1u;
    u8_RC_FC_152_Current = u8_RC_FC_152_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_152_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_153_339T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE
  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_153
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_153_Current);

    // Calculate RC
    u8_RC_FC_153_Current += 1u;
    u8_RC_FC_153_Current = u8_RC_FC_153_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_153_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_154_340T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_154
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_154_Current);

    // Calculate RC
    u8_RC_FC_154_Current += 1u;
    u8_RC_FC_154_Current = u8_RC_FC_154_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_154_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_160_352T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_160
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_160_Current);

    // Calculate RC
    u8_RC_FC_160_Current += 1u;
    u8_RC_FC_160_Current = u8_RC_FC_160_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_160_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_161_353T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_161
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_161_Current);

    // Calculate RC
    u8_RC_FC_161_Current += 1u;
    u8_RC_FC_161_Current = u8_RC_FC_161_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_161_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_162_354T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_162
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_162_Current);

    // Calculate RC
    u8_RC_FC_162_Current += 1u;
    u8_RC_FC_162_Current = u8_RC_FC_162_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_162_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_163_355T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_163
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_163_Current);

    // Calculate RC
    u8_RC_FC_163_Current += 1u;
    u8_RC_FC_163_Current = u8_RC_FC_163_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_163_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_164_356T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_164
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_164_Current);

    // Calculate RC
    u8_RC_FC_164_Current += 1u;
    u8_RC_FC_164_Current = u8_RC_FC_164_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_164_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_165_357T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
      // ID: FC_165
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_165_Current);

    // Calculate RC
    u8_RC_FC_165_Current += 1u;
    u8_RC_FC_165_Current = u8_RC_FC_165_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_165_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_166_358T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_166
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_166_Current);

    // Calculate RC
    u8_RC_FC_166_Current += 1u;
    u8_RC_FC_166_Current = u8_RC_FC_166_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_166_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_167_359T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_167
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_167_Current);

    // Calculate RC
    u8_RC_FC_167_Current += 1u;
    u8_RC_FC_167_Current = u8_RC_FC_167_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_167_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_168_360T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_168
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_168_Current);

    // Calculate RC
    u8_RC_FC_168_Current += 1u;
    u8_RC_FC_168_Current = u8_RC_FC_168_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_168_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_169_361T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_169
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_169_Current);

    // Calculate RC
    u8_RC_FC_169_Current += 1u;
    u8_RC_FC_169_Current = u8_RC_FC_169_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);
    return TRUE;
  }
  else
  {
    u8_RC_FC_169_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_170_368T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_170
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_170_Current);

    // Calculate RC
    u8_RC_FC_170_Current += 1u;
    u8_RC_FC_170_Current = u8_RC_FC_170_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_170_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_171_369T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_171
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_171_Current);

    // Calculate RC
    u8_RC_FC_171_Current += 1u;
    u8_RC_FC_171_Current = u8_RC_FC_171_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_171_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_172_370T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_172
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_172_Current);

    // Calculate RC
    u8_RC_FC_172_Current += 1u;
    u8_RC_FC_172_Current = u8_RC_FC_172_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_172_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_173_371T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
      // ID: FC_173
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_173_Current);

    // Calculate RC
    u8_RC_FC_173_Current += 1u;
    u8_RC_FC_173_Current = u8_RC_FC_173_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_173_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_174_372T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_174
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_174_Current);

    // Calculate RC
    u8_RC_FC_174_Current += 1u;
    u8_RC_FC_174_Current = u8_RC_FC_174_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_174_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_175_373T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_175
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_175_Current);

    // Calculate RC
    u8_RC_FC_175_Current += 1u;
    u8_RC_FC_175_Current = u8_RC_FC_175_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_175_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_176_374T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_176
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_176_Current);

    // Calculate RC
    u8_RC_FC_176_Current += 1u;
    u8_RC_FC_176_Current = u8_RC_FC_176_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_176_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_177_375T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_177
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_177_Current);

    // Calculate RC
    u8_RC_FC_177_Current += 1u;
    u8_RC_FC_177_Current = u8_RC_FC_177_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_177_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_178_376T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_178
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_178_Current);

    // Calculate RC
    u8_RC_FC_178_Current += 1u;
    u8_RC_FC_178_Current = u8_RC_FC_178_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_178_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_179_377T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_179
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_179_Current);

    // Calculate RC
    u8_RC_FC_179_Current += 1u;
    u8_RC_FC_179_Current = u8_RC_FC_179_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_179_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_180_384T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_180
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_180_Current);

    // Calculate RC
    u8_RC_FC_180_Current += 1u;
    u8_RC_FC_180_Current = u8_RC_FC_180_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_180_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_181_385T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_181
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_181_Current);

    // Calculate RC
    u8_RC_FC_181_Current += 1u;
    u8_RC_FC_181_Current = u8_RC_FC_181_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_181_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_190_400T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_190
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_190_Current);

    // Calculate RC
    u8_RC_FC_190_Current += 1u;
    u8_RC_FC_190_Current = u8_RC_FC_190_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_190_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_193_403T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_193
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_193_Current);

    // Calculate RC
    u8_RC_FC_193_Current += 1u;
    u8_RC_FC_193_Current = u8_RC_FC_193_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_193_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_195_405T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_195
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_195_Current);

    // Calculate RC
    u8_RC_FC_195_Current += 1u;
    u8_RC_FC_195_Current = u8_RC_FC_195_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_195_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_196_406T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_196
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_196_Current);

    // Calculate RC
    u8_RC_FC_196_Current += 1u;
    u8_RC_FC_196_Current = u8_RC_FC_196_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_196_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_197_407T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_197
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_197_Current);

    // Calculate RC
    u8_RC_FC_197_Current += 1u;
    u8_RC_FC_197_Current = u8_RC_FC_197_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_197_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}
/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_198_408T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PRIVATE, &Get_ComMode_FC_PRIVATE);

  if((Cps_GetValidWakeupSource() == TRUE) && (2 == Get_ComMode_FC_PRIVATE))
  {
    // ID: FC_198
    // DLC: 64 bytes

    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_198_Current);

    // Calculate RC
    u8_RC_FC_198_Current += 1u;
    u8_RC_FC_198_Current = u8_RC_FC_198_Current % 16;

    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_198_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_1BA_442T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PUBLIC ,&Get_ComMode_FC_PUBLIC);

  if((Cps_GetValidWakeupSource() == TRUE)&&(2 == Get_ComMode_FC_PUBLIC))
  {
    // ID: FC_1BA
    // DLC: 16 bytes divided to 2 segments
    uint8 u8_Checksum = 0u;

    // Seg_0: FC_1BA_0, 0~7 byte, CRC8
    // Write RC
    PduInfoPtr->SduDataPtr[6] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_1BA_0_Current);
    // Calculate RC
    u8_RC_FC_1BA_0_Current += 1u;
    u8_RC_FC_1BA_0_Current = u8_RC_FC_1BA_0_Current % 16;
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[7] = u8_Checksum;

    // Seg_1: FC_1BA_1, 8~15 byte, CRC8
    // Write RC
    PduInfoPtr->SduDataPtr[14] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_1BA_1_Current);
    // Calculate RC
    u8_RC_FC_1BA_1_Current += 1u;
    u8_RC_FC_1BA_1_Current = u8_RC_FC_1BA_1_Current % 16;
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 8u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[15] = u8_Checksum;

    return TRUE;
  }
  else
  {
    u8_RC_FC_1BA_0_Current = 0;
    u8_RC_FC_1BA_1_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_244_580T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PUBLIC ,&Get_ComMode_FC_PUBLIC);

  if((Cps_GetValidWakeupSource() == TRUE)&&(2 == Get_ComMode_FC_PUBLIC))
  {
    // ID: FC_244
    // DLC: 64 bytes divided to 3 segments
    uint8 u8_Checksum = 0u;

  #if 0
    /*
      The u8_Checksum is 0.
    */
    // Seg_0: FC_24E, 0~7 byte, CRC8
    // Calculate RC
    u8_RC_FC_24E_Current += 1u;
    u8_RC_FC_24E_Current = u8_RC_FC_24E_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[6] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_24E_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[7] = u8_Checksum;

    // Seg_1: FC_25E, 8~15 byte, CRC8
    // Calculate RC
    u8_RC_FC_25E_Current += 1u;
    u8_RC_FC_25E_Current = u8_RC_FC_25E_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[14] = ((PduInfoPtr->SduDataPtr[14] & 0xF0u) | u8_RC_FC_25E_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 8u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[15] = u8_Checksum;
  #endif

    // Seg_2: FC_244, 0~55 byte, CRC16
    // Write RC
    PduInfoPtr->SduDataPtr[53] = ((PduInfoPtr->SduDataPtr[53] & 0xF0u) | u8_RC_FC_244_Current);
    // Calculate RC
    u8_RC_FC_244_Current += 1u;
    u8_RC_FC_244_Current = u8_RC_FC_244_Current % 16;
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 54u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[54] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[55] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_244_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_307_775T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PUBLIC ,&Get_ComMode_FC_PUBLIC);

  if((Cps_GetValidWakeupSource() == TRUE)&&(2 == Get_ComMode_FC_PUBLIC))
  {
    // ID: FC_307
    // DLC: 64 bytes divided to 5 segments
    uint8 u8_Checksum = 0u;

  #if 0
    // Seg_0: FC_35E, 0~7 byte, CRC8
    // Calculate RC
    u8_RC_FC_35E_Current += 1u;
    u8_RC_FC_35E_Current = u8_RC_FC_35E_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[6] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_35E_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[7] = u8_Checksum;

    // Seg_1: FC_322, 8~15 byte, CRC8
    // Calculate RC
    u8_RC_FC_322_Current += 1u;
    u8_RC_FC_322_Current = u8_RC_FC_322_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[14] = ((PduInfoPtr->SduDataPtr[14] & 0xF0u) | u8_RC_FC_322_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 8u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[15] = u8_Checksum;

    // Seg_2: FC_344, 16~23 byte, CRC8
    // Calculate RC
    u8_RC_FC_344_Current += 1u;
    u8_RC_FC_344_Current = u8_RC_FC_344_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[22] = ((PduInfoPtr->SduDataPtr[22] & 0xF0u) | u8_RC_FC_344_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 16u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[23] = u8_Checksum;

    // Seg_3: FC_35F, 24~31 byte, CRC8
    // Calculate RC
    u8_RC_FC_35F_Current += 1u;
    u8_RC_FC_35F_Current = u8_RC_FC_35F_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[30] = ((PduInfoPtr->SduDataPtr[30] & 0xF0u) | u8_RC_FC_35F_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 24u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[31] = u8_Checksum;
  #endif

    // Seg_4: FC_307, 0~63 byte, CRC16
    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_307_Current);
    // Calculate RC
    u8_RC_FC_307_Current += 1u;
    u8_RC_FC_307_Current = u8_RC_FC_307_Current % 16;
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_307_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_312_786T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PUBLIC ,&Get_ComMode_FC_PUBLIC);

  if((Cps_GetValidWakeupSource() == TRUE)&&(2 == Get_ComMode_FC_PUBLIC))
  {
    // ID: FC_312
    // DLC: 64 bytes divided to 2 segments
    uint8 u8_Checksum = 0u;

  #if 0
    // Seg_0: FC_3E4, 0~7 byte, CRC8
    // Calculate RC
    u8_RC_FC_3E4_Current += 1u;
    u8_RC_FC_3E4_Current = u8_RC_FC_3E4_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[6] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_3E4_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[7] = u8_Checksum;
  #endif

    // Seg_1: FC_312, 0~63 byte, CRC16
    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_312_Current);
    // Calculate RC
    u8_RC_FC_312_Current += 1u;
    u8_RC_FC_312_Current = u8_RC_FC_312_Current % 16;
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_312_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

/* Deviation MISRAC2012-2 */
FUNC(boolean, COM_APPL_CODE)
PDFC_31A_794T_ComIPduCallout(
    PduIdType ID,
    P2VAR(PduInfoType, AUTOMATIC, COM_VAR_CLEARED) PduInfoPtr)
{
#if CPS_CRC_AND_RC_ENABLE

  ComM_ASR40_GetCurrentComMode(CPS_CAN_PUBLIC ,&Get_ComMode_FC_PUBLIC);

  if((Cps_GetValidWakeupSource() == TRUE)&&(2 == Get_ComMode_FC_PUBLIC))
  {
    // ID: FC_31A
    // DLC: 64 bytes divided to 5 segments
    uint8 u8_Checksum = 0u;

  #if 0
    // Seg_0: FC_36D, 0~7 byte, CRC8
    // Calculate RC
    u8_RC_FC_36D_Current += 1u;
    u8_RC_FC_36D_Current = u8_RC_FC_36D_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[6] = ((PduInfoPtr->SduDataPtr[6] & 0xF0u) | u8_RC_FC_36D_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[7] = u8_Checksum;

    // Seg_1: FC_30A, 8~15 byte, CRC8
    // Calculate RC
    u8_RC_FC_30A_Current += 1u;
    u8_RC_FC_30A_Current = u8_RC_FC_30A_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[14] = ((PduInfoPtr->SduDataPtr[14] & 0xF0u) | u8_RC_FC_30A_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 8u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[15] = u8_Checksum;

    // Seg_2: FC_30D, 16~23 byte, CRC8
    // Calculate RC
    u8_RC_FC_30D_Current += 1u;
    u8_RC_FC_30D_Current = u8_RC_FC_30D_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[22] = ((PduInfoPtr->SduDataPtr[22] & 0xF0u) | u8_RC_FC_30D_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 16u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[23] = u8_Checksum;

    // Seg_3: FC_367, 24~31 byte, CRC8
    // Calculate RC
    u8_RC_FC_367_Current += 1u;
    u8_RC_FC_367_Current = u8_RC_FC_367_Current % 16;
    // Write RC
    PduInfoPtr->SduDataPtr[30] = ((PduInfoPtr->SduDataPtr[30] & 0xF0u) | u8_RC_FC_367_Current);
    // Calculate CRC
    u8_Checksum = Crc_CalculateCRC8(PduInfoPtr->SduDataPtr + 24u, 7u, 0xFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[31] = u8_Checksum;
  #endif

    // Seg_4: FC_31A, 0~63 byte, CRC16
    // Write RC
    PduInfoPtr->SduDataPtr[61] = ((PduInfoPtr->SduDataPtr[61] & 0xF0u) | u8_RC_FC_31A_Current);
    // Calculate RC
    u8_RC_FC_31A_Current += 1u;
    u8_RC_FC_31A_Current = u8_RC_FC_31A_Current % 16;
    // Calculate CRC
    const uint16 u16_Checksum = Crc_CalculateCRC16(PduInfoPtr->SduDataPtr, 62u, 0xFFFFu, TRUE);
    // Write CRC
    PduInfoPtr->SduDataPtr[62] = (uint8)((u16_Checksum & 0xFF00u) >> 8u);
    PduInfoPtr->SduDataPtr[63] = (uint8)(u16_Checksum & 0x00FFu);

    return TRUE;
  }
  else
  {
    u8_RC_FC_31A_Current = 0;
    return FALSE;
  }
#else
  return TRUE;
#endif
}

void Cps_UserInitFunction(void)
{

  return;
}

void Cps_UserMainFunction(void)
{

  return; 
}


static uint8 Cps_GetValidWakeupSource(void)
{
    uint8 ret= 0x00;//return 0:invalid wakeup source ; 1: valid wakeup source

	uint8 u_WakeupFlag;
	
	(void)Comco_u_NMWakupFlag_Read(&u_WakeupFlag);

    if(0x01 == u_WakeupFlag)
    {
        ret = 0x01;//valid wakeup source
    }
    else
    {
        ret = 0x00;//invalid wakeup source
    }

    return ret;
}



