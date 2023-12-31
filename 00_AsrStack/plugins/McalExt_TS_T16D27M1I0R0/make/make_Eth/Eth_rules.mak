#EB_Automotive_Makefile

Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/McIsar/Src/Mcal/Tricore/Eth_17_GEthMac/ssc/src/Eth_17_GEthMac.c
Eth_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Eth_17_GEthMac_*.c)
Eth_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/DemoWorkspace/McalDemo/TC38A/0_Src/AppSw/Tricore/DemoMcal/Demo_Irq/Eth_Irq/Eth_17_GEthMac_Irq.c

ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Eth_src_FILES :=
endif

