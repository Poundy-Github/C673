// Copyright (C) Continental AG
// All Rights Reserved
// COMPONENT: RTA - real time analysis
/// \file
/// \brief    small description of file

#include <Std_Types.h>
#include <rta_datasets_buffer_types.h>
#include <rta_cfg.h>

#ifdef __PDO__
#include <rta_pdo_tags.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/** ***********************************************************************************************
  \brief  This function implements the callbackFunction for asynchronous rtaBuffer freezes on core 0.
          It just increments the callbackCnt of dataSetCore_0.

  \pre    None
  \post   None

  \return void

  \b Input->Output-Correlation \n
          \parblock
                The callbackCnt of dataSetCore_0 is incremented by 1.
          \endparblock

  \testmethod
        Dynamic module test: \n
        - Test the InputOutput-Correlation like described above. \n

  \traceability
        <a href="doors://rbgs854a:40000/?version=2&prodID=0&view=00000006&urn=urn:telelogic::1-503e822e5ec3651e-O-475-0005ebe0">Link to L4 Design Spec</a>
***************************************************************************************************/
static void v_MeasFreezeCallBack_Core_0(void);
static void v_MeasFreezeCallBack_Core_1(void);
static void v_MeasFreezeCallBack_Core_2(void);
static void v_MeasFreezeCallBack_Core_3(void);


/** ***********************************************************************************************
\description This is the RTA buffer for core 0. In case of DPU it is the only existing dataSet as every \n
             core is built separately.\n
             Details see in description of RTA_t_Buffer
***************************************************************************************************/

//PRQA S 612 L1
//date:          2019-09-18, reviewer: R. Sanyasinaidu, M. Kammerl
//reason:        Size of object 'a_rtaBuffer' exceeds 32767 bytes - program does not conform strictly to ISO:C90 -> Non-critical.
//justification: BufferSize required by the project.
#define CddSwc_RTA_START_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>

RTA_t_Buffer_Core_0 a_rtaBufferCore_0[RTA_NO_OF_BUFFERS];
RTA_t_Buffer_Core_1 a_rtaBufferCore_1[RTA_NO_OF_BUFFERS];
RTA_t_Buffer_Core_2 a_rtaBufferCore_2[RTA_NO_OF_BUFFERS];
RTA_t_Buffer_Core_3 a_rtaBufferCore_3[RTA_NO_OF_BUFFERS];

#define CddSwc_RTA_STOP_SEC_VAR_BUFFER_CORE_0_NO_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>
//PRQA L:L1

/** ***********************************************************************************************
\description This is the parameter set for core 0.
             Details see in description of RTA_t_Params
***************************************************************************************************/
//PRQA S 0315, 1258, 3212 L1
//date:          2020-04-13, reviewer: M. Kovac, Dj. Vujic
//Reason :       Msg(2:0315) [I] Implicit conversion from a pointer to object type to a pointer to void.
//               Msg(2:1258) Suffixed integer constant cast to a different integral type.
//               Msg(2:3212) This cast is redundant.
//Justification: Conversion to void pointer is not critical. Void pointers filled once, with RTA_t_Buffer*.
//               Minor warning, values in range. No data overflow.
//               Cast is not redundant on 64. bit architecture.
#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

static const RTA_t_Params RTA_PARAMS_CORE_0 = {
  {
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_0[0],     // a_ptrRtaBuffer[0];
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_0[1],     // a_ptrRtaBuffer[1];
  },
  &v_MeasFreezeCallBack_Core_0,                      // (*p_measCallbackFct)(void);
  (uint32)RTA_NO_OF_EVENTS_CORE_0,                   // u_maxNumberOfRtaEvents;
  (uint32)RTA_CORE_ID_CORE_0,                        // u_CoreID
  (uint32)RTA_MEAS_VIRT_ADDRESS_CORE_0,              // u_virtAddrRtaBuffer;
  (uint32)RTA_MEAS_VIRT_ADDRESS_INFO_CORE_0,         // u_virtAddrRtaInfo;
  (uint8) RTA_MEAS_FUNC_ID_CORE_0,                   // u_functionId;
};

static const RTA_t_Params RTA_PARAMS_CORE_1 = {
  {
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_1[0],     // a_ptrRtaBuffer[0];
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_1[1],     // a_ptrRtaBuffer[1];
  },
  &v_MeasFreezeCallBack_Core_1,                      // (*p_measCallbackFct)(void);
  (uint32)RTA_NO_OF_EVENTS_CORE_1,                   // u_maxNumberOfRtaEvents;
  (uint32)RTA_CORE_ID_CORE_1,                        // u_CoreID
  (uint32)RTA_MEAS_VIRT_ADDRESS_CORE_1,              // u_virtAddrRtaBuffer;
  (uint32)RTA_MEAS_VIRT_ADDRESS_INFO_CORE_1,         // u_virtAddrRtaInfo;
  (uint8) RTA_MEAS_FUNC_ID_CORE_1,                   // u_functionId;
};

static const RTA_t_Params RTA_PARAMS_CORE_2 = {
  {
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_2[0],     // a_ptrRtaBuffer[0];
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_2[1],     // a_ptrRtaBuffer[1];
  },
  &v_MeasFreezeCallBack_Core_2,                      // (*p_measCallbackFct)(void);
  (uint32)RTA_NO_OF_EVENTS_CORE_2,                   // u_maxNumberOfRtaEvents;
  (uint32)RTA_CORE_ID_CORE_2,                        // u_CoreID
  (uint32)RTA_MEAS_VIRT_ADDRESS_CORE_2,              // u_virtAddrRtaBuffer;
  (uint32)RTA_MEAS_VIRT_ADDRESS_INFO_CORE_2,         // u_virtAddrRtaInfo;
  (uint8) RTA_MEAS_FUNC_ID_CORE_2,                   // u_functionId;
};

static const RTA_t_Params RTA_PARAMS_CORE_3 = {
  {
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_3[0],     // a_ptrRtaBuffer[0];
    (RTA_t_BufferGeneric*)&a_rtaBufferCore_3[1],     // a_ptrRtaBuffer[1];
  },
  &v_MeasFreezeCallBack_Core_3,                      // (*p_measCallbackFct)(void);
  (uint32)RTA_NO_OF_EVENTS_CORE_3,                   // u_maxNumberOfRtaEvents;
  (uint32)RTA_CORE_ID_CORE_3,                        // u_CoreID
  (uint32)RTA_MEAS_VIRT_ADDRESS_CORE_3,              // u_virtAddrRtaBuffer;
  (uint32)RTA_MEAS_VIRT_ADDRESS_INFO_CORE_3,         // u_virtAddrRtaInfo;
  (uint8) RTA_MEAS_FUNC_ID_CORE_3,                   // u_functionId;
};
#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

//PRQA L:L1

/** ***********************************************************************************************
\description This is the set of controlVariables or core 0.
             Details see in description of RTA_t_Ctrl.
***************************************************************************************************/
#define CddSwc_RTA_START_SEC_VAR_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>

static RTA_t_Ctrl rtaCtrlCore_0;
static RTA_t_Ctrl rtaCtrlCore_1;
static RTA_t_Ctrl rtaCtrlCore_2;
static RTA_t_Ctrl rtaCtrlCore_3;

#define CddSwc_RTA_STOP_SEC_VAR_INIT_UNSPECIFIED
#include <rta_memmap_cfg.h>


/** ***********************************************************************************************
 * - Description:  This counter is used to check whether the triggered asynchronous measFreeze has
                   been completed already or not. It is incremented by the callbackFunction.
 *  - Range:       0x0 ... 0xFFFFFFFF
***************************************************************************************************/
#define CddSwc_RTA_START_SEC_VAR_INIT_32_UNCACHED
#include <rta_memmap_cfg.h>

static uint32 u_measCallbackCntCore_0 = 0u;
static uint32 u_measCallbackCntCore_1 = 0u;
static uint32 u_measCallbackCntCore_2 = 0u;
static uint32 u_measCallbackCntCore_3 = 0u;

#define CddSwc_RTA_STOP_SEC_VAR_INIT_32_UNCACHED
#include <rta_memmap_cfg.h>

/** ***********************************************************************************************
\description This is the dataSet for core 0.
             Details see in description of RTA_t_DataSet
***************************************************************************************************/
#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

static const RTA_t_DataSet dataSetCore_0 = {
  &RTA_PARAMS_CORE_0,        // p_params
  &rtaCtrlCore_0,            //p_ctrl
  &u_measCallbackCntCore_0   //p_callbackCnt
};

static const RTA_t_DataSet dataSetCore_1 = {
  &RTA_PARAMS_CORE_1,        // p_params
  &rtaCtrlCore_1,            //p_ctrl
  &u_measCallbackCntCore_1   //p_callbackCnt
};

static const RTA_t_DataSet dataSetCore_2 = {
  &RTA_PARAMS_CORE_2,        // p_params
  &rtaCtrlCore_2,            //p_ctrl
  &u_measCallbackCntCore_2   //p_callbackCnt
};

static const RTA_t_DataSet dataSetCore_3 = {
  &RTA_PARAMS_CORE_3,        // p_params
  &rtaCtrlCore_3,            //p_ctrl
  &u_measCallbackCntCore_3   //p_callbackCnt
};
#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


/** ***********************************************************************************************
\description This array contains pointers to all available dataSets.
             See description of RTA_t_DataSet for details.
***************************************************************************************************/
#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

static const RTA_t_DataSet* const a_dataSetList[RTA_NO_OF_CORES] =
{
  &dataSetCore_0,
  &dataSetCore_1,
  &dataSetCore_2,
  &dataSetCore_3
};

#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>

const RTA_t_DataSetHandler rta_dataSetHandler =
{
  (const RTA_t_DataSet**const)a_dataSetList,   //p_dataSets
  RTA_NO_OF_CORES                              //u_numberOfCores
};

#define CddSwc_RTA_STOP_SEC_CONST_UNSPECIFIED
#include <rta_memmap_cfg.h>


#define CddSwc_RTA_START_SEC_CODE
#include <rta_memmap_cfg.h>

static void v_MeasFreezeCallBack_Core_0(void)
{
  const uint32 u_CORE_ID = 0u;

  //Increment callback counter in related dataset
  (*(a_dataSetList[u_CORE_ID]->p_callbackCnt))++;
}

static void v_MeasFreezeCallBack_Core_1(void)
{
  const uint32 u_CORE_ID = 1u;

  //Increment callback counter in related dataset
  (*(a_dataSetList[u_CORE_ID]->p_callbackCnt))++;
}

static void v_MeasFreezeCallBack_Core_2(void)
{
  const uint32 u_CORE_ID = 2u;

  //Increment callback counter in related dataset
  (*(a_dataSetList[u_CORE_ID]->p_callbackCnt))++;
}

static void v_MeasFreezeCallBack_Core_3(void)
{
  const uint32 u_CORE_ID = 3u;

  //Increment callback counter in related dataset
  (*(a_dataSetList[u_CORE_ID]->p_callbackCnt))++;
}

#define CddSwc_RTA_STOP_SEC_CODE
#include <rta_memmap_cfg.h>


#ifdef __cplusplus
}
#endif
