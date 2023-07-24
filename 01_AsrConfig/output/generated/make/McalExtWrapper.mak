#################################################################
# This makefile exports parameters derived from the
# project configuration into variables for make

CC_INCLUDE_PATH  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\McIsar\Src\Infra_Prod\Sfr\TC38xA\_Reg
CC_INCLUDE_PATH  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal
CC_INCLUDE_PATH  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\
CC_INCLUDE_PATH  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\*\
CC_INCLUDE_PATH  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\*\*\

CC_FILES_TO_BUILD  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Ssw\TC38A\Tricore\Ifx_Ssw_Infra.c
CC_FILES_TO_BUILD  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*.c
CC_FILES_TO_BUILD  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\*.c
CC_FILES_TO_BUILD  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\*\*.c
CC_FILES_TO_BUILD  +=            $(PLUGINS_BASE)\McalExt_$(McalExt_VARIANT)\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\*\*\*\*.c


# variables defining module versions and locations of the plugins
McalExt_Adc_USED      :=true
McalExt_CanTrcv_Tja1043_USED      :=true
McalExt_Can_USED      :=true
McalExt_Dio_USED      :=true
McalExt_Dma_USED      :=true
McalExt_Fee_USED      :=true
McalExt_Fls_USED      :=true
McalExt_I2c_USED      :=true
McalExt_Icu_USED      :=true
McalExt_McalLib_USED      :=true
McalExt_Mcu_USED      :=true
McalExt_Port_USED      :=true
McalExt_Pwm_USED      :=true
McalExt_ResourceM_USED      :=true
McalExt_Smu_USED      :=true
McalExt_Spi_USED      :=true
McalExt_Wdg_USED      :=true


