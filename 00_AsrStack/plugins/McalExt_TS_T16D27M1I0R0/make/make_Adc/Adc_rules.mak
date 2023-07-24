#EB_Automotive_Makefile

Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/McIsar/Src/Mcal/Tricore/Adc/ssc/src/Adc.c
Adc_src_FILES += $(wildcard $(McalExt_OUTPUT_PATH)/src/Adc_*.c)
Adc_src_FILES += $(McalExt_CORE_PATH)/MCAL_Delivery/DemoWorkspace/McalDemo/TC38A/0_Src/AppSw/Tricore/DemoMcal/Demo_Irq/Adc_Irq/Adc_Irq.c

ifeq ($(TS_BUILD_POST_BUILD_BINARY),TRUE)
# If the post build binary shall be built do 
# not compile any files other then the postbuild files.
Adc_src_FILES :=
endif

