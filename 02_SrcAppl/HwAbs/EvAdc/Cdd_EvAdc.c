/**
 * \file 
 *
 * \brief 
 *
 * \version 
 * --------------------------------------------------------------------------------------------
 * Version	| 		Date		|		Author			| 	Comments
 * V0.0.1		2022.01.04			Xiong Yating			Init version
 * 
 * \copyright  2021 - 2022 Conti Smart Core
 *
 */
/*==================[inclusions]============================================*/
#include "Cdd_EvAdc.h"
#include "Irq.h"
#include "IfxSrc_reg.h"
/*==================[external constants definition]=========================*/


/*==================[internal constants definition]=========================*/
#define EVADC_STATIC                                 static
#define EVADC_STATIC_INLINE                          static inline

/*current running core*/
#define EVADC_CORE_RUN_0                             (0u)
/*Initialize state definition*/
#define EVADC_INIT_STATE_UNINIT                      (0U)
#define EVADC_INIT_STATE_INIT                        (1U)
/*valid state definition*/
#define EVADC_SIGNAL_STATE_VALID                     (0U)
#define EVADC_SIGNAL_STATE_INVALID                   (1U)

/*define DMA channel priority*/
#define EVADC_SRC_DMACH0_PRIO                        (0U)
#define EVADC_SRC_DMACH1_PRIO                        (1U)
/*define Request Clear Bit*/
#define EVADC_SCR_CLR_MASK                           (0x02000000u)
/*  Set ToS to DMA  */
#define EVADC_SCR_DMA_MODE                           (1u)
/* Bit to enable service request */
#define EVADC_SCR_EN_SRE                             (1u)

#define EVADC_GXRES_RESULT_MASK                      (0x00001111)

/*Det Judge Mero*/
#define EVADC_CHANNEL_IS_INVALID(x,y)                (x>=y)
#define EVADC_PTR_IS_NULL(x)                         (x==NULL_PTR)


/*convert reg to phy*/
#define EVADC_CONVERT_REG_TO_PHY(Reg)                ((float32)((float32)Reg/4095.0f*EVADC_VOLT_REFERENCE))
#define EVADC_CONVERT_DEVIATION(Reg)                 ((float32)(((float32)Reg*33000.0f-32760.0f)/3701880.0f))


/*==================[external data definition]==============================*/


/*==================[internal data definition]==============================*/
/*data with initial value*/
#define EVADC_START_SEC_DSPR_CORE0_QM_VAR_INIT
#include "EvAdc_MemMap.h"

EVADC_STATIC uint8 EvAdc_InitStatus = EVADC_INIT_STATE_UNINIT;
EVADC_STATIC s_EvAdc_AdcBaseBuffData_t EvAdc_AdcBaseBuffData[EVADC_SIGNAL_NUMBER_ALL]=
{
    {0,0,1111,1975,0},
    {0,0,1111,1975,0},
    {0,0,1338,2033,0},
    {0,0,2958,1953,0},
    {0,0,1179,1303,0},
    {0,0,2953,3562,0},
    {0,0,324,3896,0},
    {0,0,324,3896,0}
};
#define EVADC_STOP_SEC_DSPR_CORE0_QM_VAR_INIT
#include "EvAdc_MemMap.h"


/*data with no initial value*/
#define EVADC_START_SEC_DSPR_CORE0_DMA_VAR_CLEARED_64
#include "EvAdc_MemMap.h"

EVADC_DMA_TYPE EvAdc_DMADataBufferPtr[EVADC_SIGNAL_NUMBER_ALL];

#define EVADC_STOP_SEC_DSPR_CORE0_DMA_VAR_CLEARED_64
#include "EvAdc_MemMap.h"

/*==================[internal function declarations]========================*/
static void Cdd_EvAdc_InitUsedDMA(void);
static void Cdd_EvAdc_InitUsedADC(void);
static sint16 Cdd_EvAdc_CalTempValue(uint16 Vdc_NTC_Value,const s_EvAdc_NtcType_t *const patTable);



/*==================[internal function definitions]=========================*/
#define EVADC_START_SEC_CORE0_QM_CODE
#include "EvAdc_MemMap.h"
/**
 * \functions Cdd_EvAdc_InitUsedDMA
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
static void Cdd_EvAdc_InitUsedDMA(void)
{
    Ifx_SRC_SRCR VADC_G0, VADC_G2;
    VADC_G0.U = 0U;
    VADC_G2.U = 0U;

    /* Set Type of Service to 'DMA' */
    VADC_G0.B.TOS = EVADC_SCR_DMA_MODE;
    VADC_G2.B.TOS = EVADC_SCR_DMA_MODE;
    /* Set Service Request Priority Number aka 'DMA channel' */
    VADC_G0.B.SRPN = EVADC_SRC_DMACH0_PRIO;
    VADC_G2.B.SRPN = EVADC_SRC_DMACH1_PRIO;
    /* Service Request Enable bit */
    VADC_G0.B.SRE = EVADC_SCR_EN_SRE;
    VADC_G2.B.SRE = EVADC_SCR_EN_SRE;

    /* Clear pending requests before DMA configuration */
    SRC_VADC_G0_SR0.U = EVADC_SCR_CLR_MASK;
    SRC_VADC_G2_SR0.U = EVADC_SCR_CLR_MASK;
    /* Write to ADC_GROUP Service Request registers */
    SRC_VADC_G0_SR0.U = VADC_G0.U;
    SRC_VADC_G2_SR0.U = VADC_G2.U;
    SRC_VADC_G0_SR1.U = VADC_G0.U;
    SRC_VADC_G2_SR1.U = VADC_G2.U;
    SRC_VADC_G0_SR2.U = VADC_G0.U;
    SRC_VADC_G2_SR2.U = VADC_G2.U;
    SRC_VADC_G0_SR3.U = VADC_G0.U;
    SRC_VADC_G2_SR3.U = VADC_G2.U;

    // /*Clear pending requests before DMA configuration*/
    // SRC_DMA_DMA0_ERR0.U = EVADC_SCR_CLR_MASK;
    // /*Enable DMA Err Interrupt*/
    // SRC_DMA_DMA0_ERR0.B.SRE = EVADC_SCR_EN_SRE;

    
    /* Enable HW trigger for the DMA Channel used */
    Dma_ChEnableHardwareTrigger( EVADC_GROUP0_USED_DMA_CHANNEL_ID );
    /* Start DMA Transfer */
    Dma_ChStartTransfer( EVADC_GROUP0_USED_DMA_CHANNEL_ID );

    Dma_ChEnableHardwareTrigger( EVADC_GROUP2_USED_DMA_CHANNEL_ID );
    Dma_ChStartTransfer( EVADC_GROUP2_USED_DMA_CHANNEL_ID );


}

/**
 * \functions Cdd_EvAdc_InitUsedADC
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
static void Cdd_EvAdc_InitUsedADC(void)
{
    Adc_GroupType Group0 = EvAdc_AdcGroupId0;
    Adc_GroupType Group2 = EvAdc_AdcGroupId2;

    #if(EVADC_CALIBRATION_SWITCH == STD_ON)
        /* ADC Startup Calibration */
        Adc_TriggerStartupCal();
        /* Wait till the Start Calibration is over*/
        while( Adc_GetStartupCalStatus() != ADC_STARTUP_CALIB_OVER );
    #endif

    Adc_EnableHardwareTrigger(Group0);

    Adc_EnableHardwareTrigger(Group2);
}

/**
 * \functions Cdd_EvAdc_CalTempValue
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
static sint16 Cdd_EvAdc_CalTempValue(uint16 Vdc_NTC_Value,const s_EvAdc_NtcType_t *const patTable)
{
    uint8 st = 0u;
    uint8 end = EVADC_NTC_TABLE_NUM - 1u;
    uint8 m = 0u;

    while(st < end)
    {
        m = (st + end) / 2u;
        if(Vdc_NTC_Value > patTable[m].Volt)
        {
            end = m;
        }
        else if(Vdc_NTC_Value < patTable[m+1u].Volt)
        {
            st = m;
        }
        else if(Vdc_NTC_Value == patTable[m+1u].Volt)
        {
            m = m + 1u;
            break;
        }
        else
        {
            break;
        }
    }

    return patTable[m].Temperature;
}


/*==================[external function definitions]=========================*/
/**
 * \functions Template_InitFunction
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
void Cdd_EvAdc_InitFunction(void)
{
    uint8 CoreId = 0U; 

    /*get core id*/
    CoreId = ( uint8 )Mcal_GetCpuIndex();

    if(CoreId == EVADC_CORE_RUN_0)
    {
        /*Init ADC */
        Cdd_EvAdc_InitUsedADC();
        /*Init DMA and ISR*/
        Cdd_EvAdc_InitUsedDMA();

        EvAdc_InitStatus = EVADC_INIT_STATE_INIT;
    }
    else
    {
        EVADC_DET_REPORTERROR( EVADC_API_ID_INIT, EVADC_ERROR_CODE_CORE_ERR );
    }

}

/**
 * \functions Template_MainFunction
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
void Cdd_EvAdc_MainFunction(void)
{
	/*TODO: Check InitStatus*/
	if(EvAdc_InitStatus == EVADC_INIT_STATE_INIT)
	{
        for(uint8 i=0u;i<EVADC_SIGNAL_NUMBER_ALL;i++)
        {
            EvAdc_AdcBaseBuffData[i].RegValue = EvAdc_DMADataBufferPtr[i];
        }

        EvAdc_AdcBaseBuffData[EVADC_VMON_BATT_AN0].PhyValue = EVADC_CONVERT_DEVIATION(EvAdc_AdcBaseBuffData[EVADC_VMON_BATT_AN0].RegValue);
        EvAdc_AdcBaseBuffData[EVADC_VMON_IGN_AN1].PhyValue = EVADC_CONVERT_DEVIATION(EvAdc_AdcBaseBuffData[EVADC_VMON_IGN_AN1].RegValue);
        EvAdc_AdcBaseBuffData[EVADC_J3_PMIC_8200_AMUX_OUT_AN3].PhyValue = (EVADC_CONVERT_REG_TO_PHY(EvAdc_AdcBaseBuffData[EVADC_J3_PMIC_8200_AMUX_OUT_AN3].RegValue)-1.498f)/-0.0035f;
        EvAdc_AdcBaseBuffData[EVADC_PMIC_FS84_AMUX_OUT_AN4].PhyValue = (EVADC_CONVERT_REG_TO_PHY(EvAdc_AdcBaseBuffData[EVADC_PMIC_FS84_AMUX_OUT_AN4].RegValue)-2.07f)*1000.0f/-6.0f+25.0f;
        EvAdc_AdcBaseBuffData[EVADC_VMON_1V0_GEPHY_AN17].PhyValue = EVADC_CONVERT_REG_TO_PHY(EvAdc_AdcBaseBuffData[EVADC_VMON_1V0_GEPHY_AN17].RegValue);
        EvAdc_AdcBaseBuffData[EVADC_VMON_3V3_GEPHY_AN19].PhyValue = EVADC_CONVERT_REG_TO_PHY(EvAdc_AdcBaseBuffData[EVADC_VMON_3V3_GEPHY_AN19].RegValue)*1.254298f;
		EvAdc_AdcBaseBuffData[EVADC_TMON_SYS1_SOC_J3_TEMP_AN20].PhyValue = (float32)Cdd_EvAdc_CalTempValue(EvAdc_AdcBaseBuffData[EVADC_TMON_SYS1_SOC_J3_TEMP_AN20].RegValue, EvAdc_NtcTempTable);
		EvAdc_AdcBaseBuffData[EVADC_TMON_SYS2_MCU_TEMP_AN21].PhyValue = (float32)Cdd_EvAdc_CalTempValue(EvAdc_AdcBaseBuffData[EVADC_TMON_SYS2_MCU_TEMP_AN21].RegValue, EvAdc_NtcTempTable);
	}
	else
	{	
		EVADC_DET_REPORTERROR( EVADC_API_ID_INIT, EVADC_ERROR_CODE_UNINIT );
	}
}

/**
 * \functions Cdd_EvAdc_GetRegValue
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
FUNC(Std_ReturnType, RTE_CODE) Cdd_EvAdc_GetRegValue (uint8 channel, P2VAR(uint16, AUTOMATIC, RTE_APPL_DATA) value)
{
    uint8 ret=E_NOT_OK;

    if( EVADC_CHANNEL_IS_INVALID(channel,EVADC_SIGNAL_NUMBER_ALL) )
    {
        EVADC_DET_REPORTERROR( EVADC_API_ID_GETREGVALUE, EVADC_ERROR_CODE_CHANNEL_ERR );
    }
    else if( EVADC_PTR_IS_NULL(value) )
    {
        EVADC_DET_REPORTERROR( EVADC_API_ID_GETREGVALUE, EVADC_ERROR_CODE_NULL_PTR );
    }
    else
    {
        ret  = (EvAdc_AdcBaseBuffData[channel].RegValue > EvAdc_AdcBaseBuffData[channel].RegValueMax)?E_NOT_OK:E_OK;
        ret |= (EvAdc_AdcBaseBuffData[channel].RegValue < EvAdc_AdcBaseBuffData[channel].RegValueMin)?E_NOT_OK:E_OK;
        EvAdc_AdcBaseBuffData[channel].Status = ret;
        *value = EvAdc_AdcBaseBuffData[channel].RegValue;
    }

    return ret;
}


/**
 * \functions Cdd_EvAdc_GetRegValue100us
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
FUNC(EVADC_DMA_TYPE, RTE_CODE) Cdd_EvAdc_GetRegValue100us (uint8 channel)
{
    return EvAdc_DMADataBufferPtr[channel];
}

/**
 * \functions Cdd_EvAdc_GetRhyValue
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
FUNC(Std_ReturnType, RTE_CODE) Cdd_EvAdc_GetRhyValue (uint8 channel, P2VAR(float32, AUTOMATIC, RTE_APPL_DATA) value)
{
    uint8 ret=E_NOT_OK;

    if( EVADC_CHANNEL_IS_INVALID(channel,EVADC_SIGNAL_NUMBER_ALL) )
    {
        EVADC_DET_REPORTERROR( EVADC_API_ID_GETREGVALUE, EVADC_ERROR_CODE_CHANNEL_ERR );
    }
    else if( EVADC_PTR_IS_NULL(value) )
    {
        EVADC_DET_REPORTERROR( EVADC_API_ID_GETREGVALUE, EVADC_ERROR_CODE_NULL_PTR );
    }
    else
    {
        ret = E_OK;
        *value = EvAdc_AdcBaseBuffData[channel].PhyValue;
    }

    return ret;
}



#define EVADC_STOP_SEC_CORE0_QM_CODE
#include "EvAdc_MemMap.h"

