/********************************************************************************/
/* COMPONENT: Linker test														*/
/* MODULNAME: Callout															*/
/********************************************************************************/
void Callout()
{
        /******************************************************************/
        /***********************Definations Variables**********************/

    volatile signed int Result;
        /******************************************************************/
        /********************Functions calls+++++++************************/

#ifdef ti_arp32
    {
#ifdef  sr_tst
        const SRIFCoproParams_t *pEveParams;
        //Result = SR_ARP32_Exec(pEveParams);
#endif
    }
    {
#ifdef cb_tst
        //CB
        const AS_t_EVEContainer *pEC;
        Result = CB_ARP32_Exec(pEC);
#endif
    }
    {
#ifdef vcl_tst
        //VCL
        const AS_t_EVEContainer *pEC;
        Result = VCL_ARP32_Exec(pEC);
#endif
    }

    {
#ifdef pfc_tst
        //PFC
        const AS_t_EVEContainer *pEC;
        Result = PFC_ARP32_Exec(pEC);
#endif
    }
    {
#ifdef hla_tst
        //HLA
        const AS_t_EVEContainer *pEveContainer;
        Result = HLA_Eve_Exec(pEveContainer);
#endif
    }

    {
#ifdef cipp_tst
        //CIPP
        const AS_t_EVEContainer *pEC;
        Result = CIPP_ARP32_Exec(pEC);
#endif
    }
#endif


#ifdef ti_c674x
    {
#ifdef hlaf_tst
        //HLAF
        /*! Initializes the HLAF-component only once after bootup */
        const HLAF_t_RequiredInputs *ps_In;
        HLAF_t_ProvidedOutputs *ps_Out;
        HLA_t_SystemInfo *ps_SystemInfo;
        const AS_t_ServiceFuncts *Services;
        HLAF_v_Init(ps_In, ps_Out, ps_SystemInfo, Services);

        /*! Executes HLAF function. */
        HLAF_v_Exec(ps_In, ps_Out, ps_SystemInfo, Services);

#endif
    }

    {
#ifdef hla_tstr
        /*! Initializes the HLAR-component only once after bootup */
        HLAR_t_ProvidedOutputs *ps_Out;
        const HLAR_t_RequiredInputs *ps_In;
        RTE_HLA_Seg_LightList_t *ps_SegLightList;
        HLA_t_SystemInfo *ps_SystemInfo;
        t_PixelData *pImg;
        const AS_t_ServiceFuncts *Services;
        uint32 *pHlaSWVersionNumber;
        uint32 *pHlaApplicationVersionNumber;
        uint8 versionInfo[MFC_VERSION_INFO_LENGTH];

        HLAR_v_Init(ps_In, ps_Out, ps_SegLightList, ps_SystemInfo, pImg, Services);

        /*! Executes tracking and environment modelling. */
        HLAR_v_Exec(ps_In, ps_Out, ps_SegLightList, ps_SystemInfo, pImg, Services);

        /*! Get Algo Version number */
        HLA_v_GetAlgoVersion(pHlaSWVersionNumber, pHlaApplicationVersionNumber, versionInfo);

#endif
    }
    {
#ifdef cipp_tst
        //CIPP
        const reqCippPrtList_t *reqPorts;
        proCippPrtList_t *proPorts;
        AS_t_ServiceFuncts *pServices;
        CippExec(reqPorts, proPorts, pServices);
#endif
    }

    {
#ifdef vodca_tst
        //VODCA
        const reqVodcaPrtList_t *reqPorts;
        proVodcaPrtList_t *proPorts;
        AS_t_ServiceFuncts *services;
        void *x;
        VodcaExec(reqPorts, proPorts, services);
        x = VodcaGetVodcaDebugData();

#endif
    }
    {

#ifdef em_tst
        //EM
        const reqEMPrtList_t *reqPorts;
        proEMPrtList_t *proPorts;
        AS_t_ServiceFuncts *services;
        EMExec(reqPorts, proPorts, services);
#endif
    }
    {
#ifdef vcl_tst
        //VCL
        const reqVCLPrtList_t *reqPorts;
        proVCLPrtList_t *proPorts;
        AS_t_ServiceFuncts *Services;
        VCLExec(reqPorts, proPorts, Services);
#endif
    }
    {
#ifdef pfc_tst
        //PFC
        const reqPfcPrtList_t *reqPorts;
        proPfcPrtList_t *proPorts;
        AS_t_ServiceFuncts *Services;
        PfcExec(reqPorts, proPorts, Services);
#endif
    }
    {
#ifdef ped_tst
        //PED
        const reqPedPrtList_t *reqPorts;
        proPedPrtList_t *proPorts;
        AS_t_ServiceFuncts *services;
        PedExec(reqPorts, proPorts, services);
#endif
    }
#endif

#ifdef ti_cortex_a8
    {
#ifdef tsa_tst
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFInputConfig_t const *tsaifInputConfig;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;
            TSAIFInit(tsaifStateAbst, tsaifPersStateAbst, tsaifInputConfig, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFInput_t const *tsaifInput;
            TSAIFOutput_t *tsaifOutput;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;
            TSAIFMain(tsaifStateAbst, tsaifPersStateAbst, tsaifInput, tsaifOutput, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFOutput_t *tsaifOutput;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;

            TSAIFExit(tsaifStateAbst, tsaifPersStateAbst, tsaifOutput, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFAlgoVersion_t *tsaifAlgoVersion;
            Result = TSAIFGetAlgoVersion(tsaifAlgoVersion);
        }
#endif
    }
    {
#ifdef  sr_tst
#ifdef CODE_BEFORE_SR_REDESIGN
        {
            SRIFStateAbstract_t *srifStateAbst;
            SRIFPersistentStateAbstract_t const *srifPersStateAbst;
            const SRIFInputConfig_t *srifInputConfig;
            SRIFOutputSystemInfo_t *srifOutputSystemInfo;
            SRIFOutputDebugAbstract_t *srifOutputDebugAbst;
            const SRIFServices_t *srifServices;

            SRIFInit(srifStateAbst, srifPersStateAbst, srifInputConfig, srifOutputSystemInfo, srifOutputDebugAbst, srifServices);

        }
        {
            SRIFStateAbstract_t *srifStateAbst;
            SRIFPersistentStateAbstract_t *srifPersStateAbst;
            SRIFOutput_t *srifOutput;
            SRIFOutputSystemInfo_t *srifOutputSystemInfo;
            SRIFOutputDebugAbstract_t *srifOutputDebugAbst;

            SRIFExit(srifStateAbst, srifPersStateAbst, srifOutput, srifOutputSystemInfo, srifOutputDebugAbst);
        }
#else
        {
            const SRIFInputConfig_t *p_srifInputConfig;
            const SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            const SRIFServices_t *p_srifServices;
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRSharedWorkingMemoryModule_t *p_srSharedWorkingMemory;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoA;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;


            SRIFInitA(p_srifInputConfig, p_srifPersStateAbst, p_srifServices, p_srifStateAAbst, p_srSharedWorkingMemory, p_srifOutputSystemInfoA, p_srifOutputDebugAAbst);
        }
        {
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            const SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            const SRIFServices_t *p_srifServices;
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            SRIFInitB(p_srifCommunicationBufferAbstract, p_srifPersStateAbst, p_srifServices, p_srifStateBAbst, p_srifOutputSystemInfo, p_srifOutputDebugBAbst);
        }
        {
            const SRIFInput_t *p_srifInput;
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRIFScratchBufferAbstract_t *p_srifScratchBufferAbstract;
            SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoA;
            SRIFMain_PartA(p_srifInput, p_srifStateAAbst, p_srifScratchBufferAbstract, p_srifCommunicationBufferAbstract, p_srifOutputDebugAAbst, p_srifOutputSystemInfoA);
        }
        {
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutput_t *p_srifOutput;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            SRIFInputApplicationControlFlow_t srifControlFlow;

            SRIFMain_PartB(p_srifCommunicationBufferAbstract, p_srifStateBAbst, p_srifPersStateAbst, p_srifOutput, p_srifOutputSystemInfo, p_srifOutputDebugBAbst, srifControlFlow);
        }
        {
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;

            SRIFExitA(p_srifStateAAbst, p_srifPersStateAbst, p_srifOutputSystemInfo, p_srifOutputDebugAAbst);
        }
        {
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutput_t *p_srifOutput;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoB;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFExitB(p_srifStateBAbst, p_srifPersStateAbst, p_srifOutput, p_srifOutputSystemInfoB, p_srifOutputDebugBAbst, p_srifCommunicationBufferAbstract);
        }

#endif
        {
            SRIFAlgoVersion_t *srifAlgoVersion;
            Result = SRIFGetAlgoVersion(srifAlgoVersion);
        }
#endif
    }
    {
#ifdef memo_tst
#endif
    }
#endif

#ifdef ti_cortex_a15
    {
#ifdef tsa_tst
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFInputConfig_t const *tsaifInputConfig;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;
            TSAIFInit(tsaifStateAbst, tsaifPersStateAbst, tsaifInputConfig, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFInput_t const *tsaifInput;
            TSAIFOutput_t *tsaifOutput;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;
            TSAIFMain(tsaifStateAbst, tsaifPersStateAbst, tsaifInput, tsaifOutput, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFStateAbstract_t *tsaifStateAbst;
            TSAIFPersistentStateAbstract_t *tsaifPersStateAbst;
            TSAIFOutput_t *tsaifOutput;
            TSAIFOutputSystemInfo_t *tsaifOutputSystemInfo;
            TSAIFOutputDebugAbstract_t *tsaifOutputDebugAbst;

            TSAIFExit(tsaifStateAbst, tsaifPersStateAbst, tsaifOutput, tsaifOutputSystemInfo, tsaifOutputDebugAbst);
        }
        {
            TSAIFAlgoVersion_t *tsaifAlgoVersion;
            Result = TSAIFGetAlgoVersion(tsaifAlgoVersion);
        }
#endif
    }
    {
#ifdef  sr_tst
#ifdef CODE_BEFORE_SR_REDESIGN
        {
            SRIFStateAbstract_t *srifStateAbst;
            SRIFPersistentStateAbstract_t const *srifPersStateAbst;
            const SRIFInputConfig_t *srifInputConfig;
            SRIFOutputSystemInfo_t *srifOutputSystemInfo;
            SRIFOutputDebugAbstract_t *srifOutputDebugAbst;
            const SRIFServices_t *srifServices;

            SRIFInit(srifStateAbst, srifPersStateAbst, srifInputConfig, srifOutputSystemInfo, srifOutputDebugAbst, srifServices);

        }
        {
            SRIFStateAbstract_t *srifStateAbst;
            SRIFPersistentStateAbstract_t *srifPersStateAbst;
            SRIFOutput_t *srifOutput;
            SRIFOutputSystemInfo_t *srifOutputSystemInfo;
            SRIFOutputDebugAbstract_t *srifOutputDebugAbst;

            SRIFExit(srifStateAbst, srifPersStateAbst, srifOutput, srifOutputSystemInfo, srifOutputDebugAbst);
        }
#else
        {
            const SRIFInputConfig_t *p_srifInputConfig;
            const SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            const SRIFServices_t *p_srifServices;
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRSharedWorkingMemoryModule_t *p_srSharedWorkingMemory;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoA;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;


            SRIFInitA(p_srifInputConfig, p_srifPersStateAbst, p_srifServices, p_srifStateAAbst, p_srSharedWorkingMemory, p_srifOutputSystemInfoA, p_srifOutputDebugAAbst);
        }
        {
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            const SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            const SRIFServices_t *p_srifServices;
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            SRIFInitB(p_srifCommunicationBufferAbstract, p_srifPersStateAbst, p_srifServices, p_srifStateBAbst, p_srifOutputSystemInfo, p_srifOutputDebugBAbst);
        }
        {
            const SRIFInput_t *p_srifInput;
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRIFScratchBufferAbstract_t *p_srifScratchBufferAbstract;
            SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoA;
            SRIFMain_PartA(p_srifInput, p_srifStateAAbst, p_srifScratchBufferAbstract, p_srifCommunicationBufferAbstract, p_srifOutputDebugAAbst, p_srifOutputSystemInfoA);
        }
        {
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutput_t *p_srifOutput;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            SRIFInputApplicationControlFlow_t srifControlFlow;

            SRIFMain_PartB(p_srifCommunicationBufferAbstract, p_srifStateBAbst, p_srifPersStateAbst, p_srifOutput, p_srifOutputSystemInfo, p_srifOutputDebugBAbst, srifControlFlow);
        }
        {
            SRIFStateAAbstract_t *p_srifStateAAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfo;
            SRIFOutputDebugAAbstract_t *p_srifOutputDebugAAbst;

            SRIFExitA(p_srifStateAAbst, p_srifPersStateAbst, p_srifOutputSystemInfo, p_srifOutputDebugAAbst);
        }
        {
            SRIFStateBAbstract_t *p_srifStateBAbst;
            SRIFPersistentStateAbstract_t *p_srifPersStateAbst;
            SRIFOutput_t *p_srifOutput;
            SRIFOutputSystemInfo_t *p_srifOutputSystemInfoB;
            SRIFOutputDebugBAbstract_t *p_srifOutputDebugBAbst;
            const SRIFCommunicationBufferAbstract_t *p_srifCommunicationBufferAbstract;
            SRIFExitB(p_srifStateBAbst, p_srifPersStateAbst, p_srifOutput, p_srifOutputSystemInfoB, p_srifOutputDebugBAbst, p_srifCommunicationBufferAbstract);
        }

#endif
        {
            SRIFAlgoVersion_t *srifAlgoVersion;
            Result = SRIFGetAlgoVersion(srifAlgoVersion);
        }
#endif
    }

#endif

        /******************************************************************/

}
