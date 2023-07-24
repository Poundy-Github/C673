/**
 * \file SpiSync_Core.c
 *
 * \brief Implemented the time sync of Spi.
 *
 * \version refer the SpiSync_Core.h.
 *
 */

/*==================[inclusions]============================================*/
#include "SpiSync_Core.h"
#include "SpiSync_Type.h"
#include <Rte_SpiSync.h>

/*==================[external data]=========================================*/


/*==================[internal data]=========================================*/
#if (SPISYNC_DEBUG_ENABLE == STD_ON)
s_Time_RunCycleMeas_t Debug_SpiSync_Core_MainFunction_CycleTime;
s_Time_RunCycleMeas_t Debug_SpiSync_TimeSync_CycleTime;
#endif
e_Csc_Platform_InitStatus_t SpiSync_Core_InitStatus;
s_SpiSync_TimeSyncStatus_t SpiSync_TimeSyncStatus;
s_SipSync_TimeSyncMessage_t SpiSync_TimeSyncMsg;

/*==================[internal function declarations]========================*/
static uint8 SpiSync_Core_Dynamic_GetDefaultOffset(uint64 *time_stamp);
static uint8 SpiSync_Core_Dynamic_GetOffset(uint64 *time_stamp);

/*==================[external function definitions]=========================*/
/**
 * \functions SpiSync_Core_InitFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_Core_InitFunction(void)
{
#if (SPISYNC_FUNCTION_ENABLE == STD_ON)
    /*TODO : Clear the internal and external variable*/
    memset(&SpiSync_TimeSyncMsg, 0x00, sizeof(SpiSync_TimeSyncMsg));
    SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Init;

    /*TODO : Enable the SpiSync PPS pin--HIGH*/
    SPISYNC_PPS_DIO_SET(                                
#if (SPISYNC_USE_RTE_INTERFACE == STD_OFF)              
                        (SPISYNC_PPS_DIO_CHANNEL),        
#endif                                                  
                        (!SPISYNC_PPS_DIO_SYNC_LEVEL) );

    #if(SPISYNC_USERFUNCTION_ENABLE == STD_ON)
        SpiSync_UserInitFunction();
    #endif

    /*TODO : Updated the InitStatus flag*/
    SpiSync_Core_InitStatus = Csc_Platform_InitStatus_Init;
#endif
}

/**
 * \functions SpiSync_Core_MainFunction
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_Core_MainFunction(void)
{
#if (SPISYNC_DEBUG_ENABLE == STD_ON)
    Time_MeasRunCycleTimeMs(&Debug_SpiSync_Core_MainFunction_CycleTime);
#endif

#if (SPISYNC_FUNCTION_ENABLE == STD_ON)
    uint8 i;
    uint8 global_time_status = 0x00;
    uint64 global_time_stamp = 0x00;

    if(Csc_Platform_InitStatus_Init == SpiSync_Core_InitStatus)
    {
        switch (SpiSync_TimeSyncStatus.State)
        {
            case SpiSync_TimeSync_State_Init:
            {
                /*TODO : Check the Spi Connected status(hand shake status)*/
                SpiSync_TimeSyncMsg.CycleCounter = 0;
                SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_UpdatedOffset;
                break;
            }

            case SpiSync_TimeSync_State_UpdatedOffset:
            {   
                if (SpiSync_TimeSyncStatus.TimeSyncWaitStartUpCounter++ >= (SPISYNC_TIMESYNC_START_UP_WAIT_TIME/SPISYNC_MAIN_FUNCTION_PERIOD_TIME))
                {
                #if(SPISYNC_TIMESYNC_DYNAMIC_OFFSET_ENABLE == STD_ON)
                    if(SpiSync_TimeSyncStatus.TimeSyncWaitOffsetCounter++ >= (SPISYNC_TIMESYNC_DYNAMIC_OFFSET_WAIT_TIME/SPISYNC_MAIN_FUNCTION_PERIOD_TIME))
                    {
                        SpiSync_Core_Dynamic_GetDefaultOffset(&SpiSync_TimeSyncStatus.TimestampOffset);
                        SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync; 
                    }
                    else
                    {
                        if(0x00 == SpiSync_Core_Dynamic_GetOffset(&SpiSync_TimeSyncStatus.TimestampOffset))
                        {
                            SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync; 
                        }
                        else
                        {
                            /*TODO : doing nothing*/
                        }
                    }
                #else
                    SpiSync_Core_Static_GetOffset(&SpiSync_TimeSyncStatus.TimestampOffset);
                #endif
                }
                break;
            }

            case SpiSync_TimeSync_State_Sync:
            {
                /*TODO : Wait the Spi time sync cycle arrived*/
                SpiSync_TimeSyncStatus.TimeSyncCycleCounter++;
                if(SpiSync_TimeSyncStatus.TimeSyncCycleCounter >= (SpiSync_TimeSyncConfigTable.TimeSyncCycle / SPISYNC_MAIN_FUNCTION_PERIOD_TIME))
                {
                    SpiSync_TimeSyncStatus.TimeSyncCycleCounter = 0x00;

                    /*TODO : Check the Global time status*/
                    #if (SPISYNC_TIMESYNC_CHECK_GLOBAL_STATUS == STD_ON)
                    Time_GetGlobalTimeStatus(&global_time_status);
                    #else
                    global_time_status = TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE;
                    #endif
                    if(TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE == (global_time_status & TIME_GLOBAL_TIME_STATUS_MASK_GLOBAL_TIME_BASE))
                    {
                        /*TODO : Updated the PPS Level*/
                        SPISYNC_PPS_DIO_SET(     
                        #if (SPISYNC_USE_RTE_INTERFACE == STD_OFF)              
                            (SPISYNC_PPS_DIO_CHANNEL),        
                        #endif                                                  
                            (SPISYNC_PPS_DIO_SYNC_LEVEL) );

                        /*TODO : Read time stamp from Time components*/
                        Time_GetTimeStampNs(&global_time_stamp);/*Notes : the time stampe is ns,*/
                        SpiSync_TimeSyncMsg.TimeStamp.data = (sint64)(global_time_stamp + SpiSync_TimeSyncStatus.TimestampOffset);
                        
                        /*TODO : Clean the CheckSum*/
                        SpiSync_TimeSyncMsg.CheckSum = 0x00;
                        /*TODO : Clac the CheckSum*/
                        for(i = 0; i < 8; i++)
                        {
                            SpiSync_TimeSyncMsg.CheckSum  += SpiSync_TimeSyncMsg.TimeStamp.raw[i];
                        }
                        
                        #if (SPISYNC_DEBUG_ENABLE == STD_ON)
                            Time_MeasRunCycleTimeMs(&Debug_SpiSync_TimeSync_CycleTime);
                        #endif

                        /*TODO : Send the SpiSync Message*/
                        // SPISYNC_SEND_TIMESYNCMSG_API(&SpiSync_TimeSyncMsg, sizeof(SpiSync_TimeSyncMsg));
                        Rte_Call_RP_Sdc_TimeSync_TimeSyncMsg((uint8 *)&SpiSync_TimeSyncMsg, sizeof(SpiSync_TimeSyncMsg));
                        SpiSync_TimeSyncMsg.CycleCounter++;
                        SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync_Success;
                    }
                    else
                    {
                        SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync_Failed;
                    }               
                }
                else
                {
                    /*TODO : Doing nothing*/
                }
                break;
            }

            case SpiSync_TimeSync_State_Sync_Success:
            {
                SPISYNC_PPS_DIO_SET(                                
#if (SPISYNC_USE_RTE_INTERFACE == STD_OFF)              
                    (SPISYNC_PPS_DIO_CHANNEL),        
#endif                                                  
                    (!SPISYNC_PPS_DIO_SYNC_LEVEL) );
                SpiSync_TimeSyncStatus.TimeSyncCycleCounter++;
                SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync;
                break;
            }

            case SpiSync_TimeSync_State_Sync_Failed:
            {
                SpiSync_TimeSyncStatus.State = SpiSync_TimeSync_State_Sync;
                break;                     
            }
                
            default:
            {
                /*TODO : Doing nothing*/
                break;
            }
        }

    }
    else
    {
        /*TODO : Doing nothing*/
    }

    /*TODO : Perform the User Main Function*/
    #if (SPISYNC_USERFUNCTION_ENABLE == STD_ON)
        SpiSync_UserMainFunction();
    #endif
#endif
}

/**
 * \functions SpiSync_Core_GetTimestampOffset
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out timestamp,the offset time stamp,the unit is ns
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_Core_GetTimestampOffset(uint64 *timestamp)
{
    *timestamp = SpiSync_TimeSyncStatus.TimestampOffset;
}

/**
 * \functions SpiSync_Core_GetSpiTimeSyncStatus
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out Spi Time sync status
 *
 * \return none
 *
 * \comments
 *
 */
void SpiSync_Core_GetSpiTimeSyncStatus(e_SpiSync_TimeSyncState_t *status)
{
    *status = SpiSync_TimeSyncStatus.State;
}

/*==================[internal function definitions]=========================*/
/**
 * \functions SpiSync_Core_Dynamic_GetOffset
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return  0x00 : Get successful
 *          0x01 : Failure
 *
 * \comments
 *
 */
static uint8 SpiSync_Core_Dynamic_GetOffset(uint64 *time_stamp)
{
    return SPISYNC_TIMESYNC_DYNAMIC_GET_TIMESTAMP(time_stamp);
}

/**
 * \functions SpiSync_Core_Dynamic_GetDefaultOffset
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
static uint8 SpiSync_Core_Dynamic_GetDefaultOffset(uint64 *time_stamp)
{
    *time_stamp = SPISYNC_TIMESYNC_DYNAMIC_DEFAULT_TIMESTAMP_OFFSET * 1000000000ull;
    return 0;
}

/**
 * \functions SpiSync_Core_Static_GetOffset
 *
 * \brief
 *
 * \parameters-in none
 *
 * \parameters-out none
 *
 * \return none
 *
 * \comments
 *
 */
static uint8 SpiSync_Core_Static_GetOffset(uint64 *time_stamp)
{
    *time_stamp = SPISYNC_TIMESYNC_STATIC_TIMESTAMP_OFFSET * 1000000000ull;
    return 0;
}
