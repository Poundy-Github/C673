@echo off
rem (C) 2012 - ADC Lindau GERMANY
rem Author: Frank Sautter-Steisslinger
rem Version: 1.1  Script generation
rem          1.1  Moved to Mainstream													29.11.2016	Magnus Baur
rem          1.7  First working version in Mainstream                                   11.01.2017  Magnus Baur
rem          1.11 Cleaned up from mono and stereo                                       19.01.2017  Magnus Baur

setlocal

:: Set default values meaning MFC431 stuff is active

set PRODUCT=""
set APP_PROJECT_NAME=MFC431
set APP_LINK_NAME=
set PAUSE=1

:optionsloop
if "%1" == "nopause" set PAUSE=0
if "%1" == "help" (
  echo.
  echo Script options are    nopause   Does not pause at the end
  echo                       p xxx    Build SDL file for xxx
  goto EXIT_NOPAUSE
)
if "%1" == "p" (
	if not "%2" == "" (
		set PRODUCT=%2
	) else (
		echo.
		echo Error: Please specify the product ID with as a parameter to the "p" argument
		echo        ie. sw_build.bat p mfc431
		goto EXIT_NOPAUSE
	)
)

if "%PRODUCT:~0,6%" == "ars441" (
	set APP_PROJECT_NAME=%PRODUCT%
	set APP_LINK_NAME=_%PRODUCT%
) else if "%PRODUCT:~0,6%" == "mfc431" (
	set APP_PROJECT_NAME=%PRODUCT%
	set APP_LINK_NAME=_%PRODUCT%
) else if "%PRODUCT:~0,6%" == "hfl110" (
	set APP_PROJECT_NAME=%PRODUCT%
	set APP_LINK_NAME=_%PRODUCT%
) else if "%PRODUCT:~0,6%" == "ncapx" (
	set APP_PROJECT_NAME=%PRODUCT%
	set APP_LINK_NAME=_%PRODUCT%
)

rem shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

set PROJECT_ROOT=..\..\..\..\..
set PDO_PATH=c:\tools\pdo\2.16.1.1
set PDO_TOOL=%PDO_PATH%\Pdo_tool.exe
set PDO_SCAN=%PDO_PATH%\Pdo_scan.exe
set PYTHON_PATH=c:\tools\python\2.7.10
set PYTHON=%PYTHON_PATH%\python.exe
set PYTHON_SCRIPT_PATH=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw

if "%PRODUCT:~0,6%" == "ars441" (
  set FILES_PART_01=dummy_m3_01.c
) else (
  set FILES_PART_01=%PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC\ic_controller.c ^
  %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC\ic_exposuremgr.c ^
  dummy_m3_01.c 
)
 
set FILES_PART_02=dummy_m3_02.c

if "%PRODUCT:~0,6%" == "ars441" (

  rem ===  ARS441 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VL\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VL\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\DGM ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF\config ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB\GLOB_DPU ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vl ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vl ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\algo_common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\em\emlib ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\long ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\spm ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\ga ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\ga ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\bit_array ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\general ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\grid ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\histogram ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\jpda ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\em\emlib\size ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\long ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\spm ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\gp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\ga ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\RTL ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTL
  
  
set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC430HI17=0 -D PDO_CFG_MFC431=0 -D PDO_CFG_HFL110=0 ^
            -D CFG_MFC_VISION_LOW=1 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0

  rem ) ARS441
)

if "%PRODUCT:~0,6%" == "mfc431" (

  rem ===  MFC431 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\rte ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\MFC431 ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\DGM ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF\config ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB\GLOB_DPU ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\MFC431\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\ga ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim\dim_eba ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim\dim_aldw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lka ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lks ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lck ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lcd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\udw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lka ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lks ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lck ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lcd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\udw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\udw\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\udw\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\udw\udw_custom ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\udw\daw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\udw\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\udw\udw_base ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\RTL ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTL

set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC431=1 -D -D PDO_CFG_HFL110=0 ^
            -D CFG_MFC_VISION_LOW=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0

  rem ) %MFC431%
)

if "%PRODUCT:~0,6%" == "hfl110" (

  rem ===  HFL110 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110 ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\pca ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\pca\frame\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\ga ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\common\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\frame\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\frame\ti_eve_arp32\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\shared_helpers\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\common\DGM ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF\config ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB\GLOB_DPU ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\RTL ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTL

set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC430HI17=0 -D PDO_CFG_MFC431=0 -D PDO_CFG_HFL110=1 ^
            -D CFG_MFC_VISION_LOW=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0

  rem ) %HFL110%
)

if "%PRODUCT:~0,6%" == "ncapx" (

  rem ===  NCAPX config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\rte ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\GLOB_VH ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VH\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\DGM ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF\config ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp\cp_cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim\dim_eba ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\dim\dim_aldw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lka ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lks ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lck ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\lcd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\udw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\cp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\dim ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\fip ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\emp ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\head ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lka ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lks ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lck ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\lcd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\si ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\udw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\fct\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME% ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\MFC431\ ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\MFC431\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\MFC431\RTL ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTL


set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC430HI17=0 -D PDO_CFG_MFC431=1 -D PDO_CFG_HFL110=0 ^
            -D CFG_MFC_VISION_LOW=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0

  rem ) %MFC431%
)

set DATFILE_PART_01=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC_01.dat
set DATFILE_PART_02=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC_02.dat
set SDLFILE=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl
set LOGFILE=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl.log
if NOT exist %PROJECT_ROOT%\04_Engineering\04_Build\sdl (
	mkdir %PROJECT_ROOT%\04_Engineering\04_Build\sdl
)

REM Generate xdc module and error id header
%PYTHON% %PYTHON_SCRIPT_PATH%\postprocess\generate_xdc_module_and_error_ids.py -p %APP_PROJECT_NAME% -c release

rem Generate DAT file
echo Generate DAT part 01 > %LOGFILE%
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %FILES_PART_01% -o %DATFILE_PART_01% >> %LOGFILE% 2>&1
if ERRORLEVEL 0 goto PDOSCAN_CONTINUE
echo ERROR running PDOScan!
goto EXIT

:PDOSCAN_CONTINUE
echo. >> %LOGFILE%
echo Generate DAT part 02 >> %LOGFILE%
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %FILES_PART_02% -o %DATFILE_PART_02% >> %LOGFILE% 2>&1

if ERRORLEVEL 0 goto PDOSCAN_OK
echo ERROR running PDOScan!
goto EXIT

:PDOSCAN_OK
rem Generate SDL from DAT
echo. >> %LOGFILE%
echo Generate SDL from DAT files >> %LOGFILE%

if "%PRODUCT:~0,6%" == "ars441" (

  rem ===  ARS441 ===

  %PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config pdo_tool_cfg_sdl_ars441dp10.cfg -o %SDLFILE% >> %LOGFILE% 2>&1

  rem ) %ARS441DP10%

)

if "%PRODUCT:~0,6%" == "mfc431" (

  rem ===  MFC431 ===

  %PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config pdo_tool_cfg_sdl_mfc431.cfg -o %SDLFILE% >> %LOGFILE% 2>&1

  rem ) %MFC431%

)

if "%PRODUCT:~0,6%" == "hfl110" (

  rem ===  HFL110 ===

  %PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config pdo_tool_cfg_sdl_hfl110.cfg -o %SDLFILE% >> %LOGFILE% 2>&1

  rem ) %HFL110%

)

if "%PRODUCT:~0,6%" == "ncapx" (
  rem ===  NCAPX ===
  %PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config pdo_tool_cfg_sdl_mfc431.cfg -o %SDLFILE% >> %LOGFILE% 2>&1
  rem ) %MFC431%
)

if ERRORLEVEL 0 goto PDOTOOL_OK
echo ERROR running PDOTool!
goto EXIT

:PDOTOOL_OK
echo SDL was generated for %APP_PROJECT_NAME%

:EXIT
del %DATFILE_PART_01%
del %DATFILE_PART_02%

if %PAUSE% == 0 goto EXIT_NOPAUSE:
pause
:EXIT_NOPAUSE
