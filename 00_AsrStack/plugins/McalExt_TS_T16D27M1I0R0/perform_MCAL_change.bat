@echo off
:: --------{ EB Automotive Batch File }--------
::
:: script to update MCAL module with EB content
:: or reset it to vendor content

if [%1]==[EB_update] goto usage
if [%1]==[origin] goto usage
echo Usage: %0 [OPTION]
echo(
echo   EB_update
echo		Update files of the plug-in with content of Elektrobit Automotive GmbH.
echo   origin
echo		Reset the files of the plug-in with vendor content.
echo(
goto copy_end

:usage
cd %~d0 >NUL
cd %~p0
:: if exist an *.origin_version delete the current file:
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h (
echo delete %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm (
echo delete %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c (
echo delete %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c (
echo delete %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h (
echo delete %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h )
:: if exist an *.EB_update file delete the current file:
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h (
echo 	remove %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h
del .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm
del .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h (
echo 	remove %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h
del .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h )
if exist .\templates\Icu.h (
echo 	remove %~d0%~p0templates\Icu.h
del .\templates\Icu.h )
if exist .\templates\Pwm.h (
echo 	remove %~d0%~p0templates\Pwm.h
del .\templates\Pwm.h )
if exist .\templates\Spi_UserCode.c (
echo 	remove %~d0%~p0templates\Spi_UserCode.c
del .\templates\Spi_UserCode.c )
if exist .\templates\Spi_UserCode.h (
echo 	remove %~d0%~p0templates\Spi_UserCode.h
del .\templates\Spi_UserCode.h )

:: perform origin
if [%1]==[EB_update] goto copy_EB
:: if exist an *.origin_version file make it to the current file:
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.origin_version 
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.origin_version .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.origin_version 
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.origin_version .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.origin_version 
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.origin_version .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.origin_version 
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.origin_version .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.origin_version 
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.origin_version .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.origin_version 
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.origin_version .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.origin_version (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.origin_version 
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.origin_version .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h >NUL )
goto copy_end

:: perform EB update
:copy_EB
:: if exist an *.EB_update file make it to the current file:
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Adc_Irq\Adc_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\AscLin_Irq\AscLin_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Can_Irq\Can_17_McmCan_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Ccu6_Irq\Ccu6_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dma_Irq\Dma_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Dsadc_Irq\Dsadc_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eru_Irq\Eru_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Eth_Irq\Eth_17_GEthMac_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Fls_Irq\Fls_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gpt12_Irq\Gpt12_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Gtm_Irq\Gtm_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Hssl_Irq\Hssl_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\I2c_Irq\I2c_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Sent_Irq\Sent_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Spi_Irq\Spi_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\AppSw\Tricore\DemoMcal\Demo_Irq\Stm_Irq\Stm_Irq.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Autosar_Srv\Mcal_SafetyError.c >NUL )
if exist .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.EB_update
copy .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h.EB_update .\MCAL_Delivery\DemoWorkspace\McalDemo\TC38A\0_Src\BaseSw\Infra\Irq\ssc\inc\Irq.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\config\AS422\CanTrcv_17_W9255.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\inc\CanTrcv_17_W9255_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\CanTrcv_17_W9255_Aurix2G\generate\template\src\CanTrcv_17_W9255_Cfg.c >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\config\AS422\Can_17_McmCan.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Can_17_McmCan_Aurix2G\generate\template\inc\Can_17_McmCan_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fls_17_Dmu_Aurix2G\generate\template\inc\Fls_17_Dmu_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\config\AS422\Fr_17_Eray.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\inc\Fr_17_Eray_Cfg.h >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Fr_17_Eray_Aurix2G\generate\template\src\Fr_17_Eray_PBcfg.c >NUL )
if exist .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.EB_update
copy .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm.EB_update .\MCAL_Delivery\McIsar\PluginsTresos\eclipse\plugins\Lin_17_AscLin_Aurix2G\config\AS422\Lin_17_AscLin.xdm >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.EB_update
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h.EB_update .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Can_17_McmCan\ssc\inc\Can_17_McmCan.h >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.EB_update
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c.EB_update .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\FlsLoader\Ssc\src\FlsLoader.c >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.EB_update
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h.EB_update .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\inc\Lin_17_AscLin.h >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.EB_update
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c.EB_update .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\Lin_17_AscLin\ssc\src\Lin_17_AscLin.c >NUL )
if exist .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.EB_update (
echo 	use %~d0%~p0MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.EB_update
copy .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h.EB_update .\MCAL_Delivery\McIsar\Src\Mcal\Tricore\McalLib\ssc\inc\Mcal_Compiler.h >NUL )
if exist .\templates\Icu.h.EB_update (
echo 	use %~d0%~p0templates\Icu.h.EB_update
copy .\templates\Icu.h.EB_update .\templates\Icu.h >NUL )
if exist .\templates\Pwm.h.EB_update (
echo 	use %~d0%~p0templates\Pwm.h.EB_update
copy .\templates\Pwm.h.EB_update .\templates\Pwm.h >NUL )
if exist .\templates\Spi_UserCode.c.EB_update (
echo 	use %~d0%~p0templates\Spi_UserCode.c.EB_update
copy .\templates\Spi_UserCode.c.EB_update .\templates\Spi_UserCode.c >NUL )
if exist .\templates\Spi_UserCode.h.EB_update (
echo 	use %~d0%~p0templates\Spi_UserCode.h.EB_update
copy .\templates\Spi_UserCode.h.EB_update .\templates\Spi_UserCode.h >NUL )
:copy_end
