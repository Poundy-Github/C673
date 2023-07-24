@echo off

setlocal

:: Set default values meaning MFC400 stuff is active
set PAUSE=1
set PRODUCT=0

:optionsloop
if "%1" == "nopause" set PAUSE=0
if "%1" == "help" (
  echo.
  echo Script options are   nopause         Does not pause at the end
  echo                      mfc431          Build SDL file for mfc431
  echo                      mfc431hi28      Build SDL file for mfc431hi28
  echo                      mfc431ta19      Build SDL file for mfc431ta19
  echo                      hfl110          Build SDL file for hfl110
  echo                      hfl110ta10      Build SDL file for hfl110ta10
  echo                      ars441          Build SDL file for ARS441
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

rem shift next command option and do the loop again until all options are processed 
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

set PROJECT_NAME=%PRODUCT%

if "%PRODUCT:~0,6%" == "mfc431" (
  set SOCTYPE=high
  set MFC431=1
) else if "%PRODUCT:~0,6%" == "ars441" (
  set SOCTYPE=low
  set MFC431=0
) else if "%PRODUCT:~0,6%" == "hfl110" (
  set SOCTYPE=high
  set MFC431=0
) else if "%PRODUCT:~0,6%" == "ncapx" (
  set SOCTYPE=high
  set MFC431=1
) else (
  exit /b
)

set PROJECT_ROOT=..\..\..\..\..
set PDO_PATH=c:\tools\pdo\2.16.1.1
set PDO_TOOL=%PDO_PATH%\Pdo_tool.exe
set PDO_SCAN=%PDO_PATH%\Pdo_scan.exe

set PERL=c:\tools\perl\v5.6\bin\perl.exe

rem set dummy files
set ARM_A_0_FILES=dummy_arm-a_0.c
set ARM_M_0_FILES=%PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC\ic_controller.c ^
  %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC\ic_exposuremgr.c ^
  dummy_arm-m_0.c
)

set ARM_M_1_FILES=dummy_arm-m_1.c
set DSP_0_FILES=dummy_dsp_0.c
set EVE_0_FILES=dummy_eve_0.c
set DSP_1_FILES=dummy_dsp_1.c
set EVE_1_FILES=dummy_eve_1.c

rem set in map files
if "%SOCTYPE%" == "high" (
	set ARM_A_0_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-a_0\arm-a_0.map
)
set ARM_M_1_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-m_1\arm-m_1.map
set ARM_M_0_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-m_0\arm-m_0.map
set DSP_0_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_dsp_0\dsp_0.map
set EVE_0_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_eve_0\eve_0.map
if "%SOCTYPE%" == "high" (
    set DSP_1_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_dsp_1\dsp_1.map
    set EVE_1_IN_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_eve_1\eve_1.map
)

rem set out map files

if "%SOCTYPE%" == "high" (
	set ARM_A_0_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-a_0\arm-a_0-modified.map
)
set ARM_M_0_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-m_0\arm-m_0-modified.map
set ARM_M_1_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_arm-m_1\arm-m_1-modified.map
set DSP_0_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_dsp_0\dsp_0-modified.map
set EVE_0_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_eve_0\eve_0-modified.map
if "%SOCTYPE%" == "high" (
	set DSP_1_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_dsp_1\dsp_1-modified.map
    set EVE_1_OUT_MAP=%PROJECT_ROOT%\04_Engineering\04_Build\out\%PROJECT_NAME%\release_eve_1\eve_1-modified.map
)

rem Convert map files into PDO confirm map file including address offset for (GD) XCP 
echo.
echo Converting map files
pushd .

if %MFC431% NEQ 0 (
echo. %ARM_A_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\GCC_mapconv.pl %ARM_A_0_IN_MAP% %ARM_A_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_0_IN_MAP% %ARM_M_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_1_IN_MAP% %ARM_M_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_0_IN_MAP% %DSP_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_0_IN_MAP% %EVE_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_1_IN_MAP% %DSP_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_1_IN_MAP% %EVE_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
)

if "%PRODUCT:~0,6%" == "hfl110" (
echo. %ARM_A_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\GCC_mapconv.pl %ARM_A_0_IN_MAP% %ARM_A_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_0_IN_MAP% %ARM_M_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_1_IN_MAP% %ARM_M_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_0_IN_MAP% %DSP_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_0_IN_MAP% %EVE_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_1_IN_MAP% %DSP_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_1_IN_MAP% %EVE_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
)

if "%PROJECT_NAME:~0,6%" == "ars441" (
echo. %ARM_M_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_0_IN_MAP% %ARM_M_0_OUT_MAP% 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_1_IN_MAP% %ARM_M_1_OUT_MAP% 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_0_IN_MAP% %DSP_0_OUT_MAP% 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_0_IN_MAP% %EVE_0_OUT_MAP% 0x80000000 0x87FFFFFF 0x20000000
)

if "%PROJECT_NAME:~0,6%" == "ncapx" (
echo. %ARM_A_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\GCC_mapconv.pl %ARM_A_0_IN_MAP% %ARM_A_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_0_IN_MAP% %ARM_M_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %ARM_M_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %ARM_M_1_IN_MAP% %ARM_M_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_0_IN_MAP% %DSP_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_0_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_0_IN_MAP% %EVE_0_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %DSP_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %DSP_1_IN_MAP% %DSP_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
echo. %EVE_1_IN_MAP%
%PERL% %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\TI_mapconv.pl %EVE_1_IN_MAP% %EVE_1_OUT_MAP% 0x40000000 0x407FFFFF 0x50000000 0x80000000 0x87FFFFFF 0x20000000
)
popd

if %MFC431% NEQ 0 (

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
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\GLOB\GLOB_DPU ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUFF\ga ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUINFRA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUSERVICE\edma ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\INFOBLOCK\infoblock_dpu ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
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
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\ga ^
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
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\ABPR ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\latdmc ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\CTRSC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\DRVMN ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\HMIOC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\HMIOC\HMOHMC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\HMCSCT\HSCHDA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\HMCSCT\HSCHLC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\LDPSA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\LKASA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\MDCTR ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\RDPSA ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\TRJCTR ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\TRJPLN ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\VDPR ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\lcf\RTW_Common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\frame_sen ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\frame_veh ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\lcfveh_wrp ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include

set DEFINES=-D A2L_CFG_ARS441=0 -D A2L_CFG_MFC431=1 -D A2L_CFG_HFL110=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS

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
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\pca\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\ga ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\gs ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\frame ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\frame\ti_eve_arp32 ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\HFL110\algo\sources\pca\shared_helpers ^
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
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\RTA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUFF\ga ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUINFRA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUSERVICE\edma ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\INFOBLOCK\infoblock_dpu ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include
  
set DEFINES=-D A2L_CFG_ARS441=0 -D A2L_CFG_MFC431=0 -D A2L_CFG_HFL110=1 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS

)

if "%PROJECT_NAME:~0,6%" == "ars441" (

  rem ===  ars441 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\rte ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT% ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\GLOB_VL ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VL\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\RTE_VL\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\common\DGM ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUFF\config ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vl ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUFF\ga ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUINFRA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vl ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUSERVICE\edma ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\INFOBLOCK\infoblock_dpu ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VL ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
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
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include
  
set DEFINES=-D A2L_CFG_ARS441=1 -D A2L_CFG_MFC431=0 -D A2L_CFG_HFL110=0 -D -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS
  rem ) ars441
)

if "%PROJECT_NAME:~0,5%" == "ncapx" (

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
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\IPCBASE ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\common\MTSI ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUCOM\icc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUFF\ga ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUINFRA ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUHWIF\mc_vh ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUSERVICE\edma ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\INFOBLOCK\infoblock_dpu ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\RTA_VH ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\DPUIC ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\LDPDDR ^
  -I %PROJECT_ROOT%\04_Engineering\01_Source_Code\MTSI_VH ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\rtw ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\vdy ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\cml ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cd ^
  -I %PROJECT_ROOT%\04_Engineering\00_Projects\%PRODUCT%\algo\sources\00_Custom\fct\cp ^
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
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include

set DEFINES=-D A2L_CFG_ARS441=0 -D A2L_CFG_MFC431=1 -D A2L_CFG_HFL110=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS

  rem ) %MFC431%
)

if NOT exist %PROJECT_ROOT%\04_Engineering\04_Build\a2l (
	mkdir %PROJECT_ROOT%\04_Engineering\04_Build\a2l
)

rem set logfile
if exist %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_soc.a2l.log% (
del %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_soc.a2l.log%
)
set LOGFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_soc.a2l.log

rem =================== ALL CORE MAP, DAT AND A2L FILES ======================================================
rem ARM A 0
set ARM_A_0_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_0.dat
set ARM_A_0_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_0_map.dat
set ARM_A_0_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_0_map.a2l
rem ARM M 0
set ARM_M_0_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0.dat
set ARM_M_0_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0_map.dat
set ARM_M_0_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0_map.a2l
rem ARM M 1
set ARM_M_1_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1.dat
set ARM_M_1_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1_map.dat
set ARM_M_1_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1_map.a2l
rem DSP 0
set DSP_0_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0.dat
set DSP_0_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0_map.dat
set DSP_0_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0_map.a2l
rem EVE 0
set EVE_0_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0.dat
set EVE_0_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0_map.dat
set EVE_0_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0_map.a2l

rem ARM A 1
set ARM_A_1_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_1.dat
set ARM_A_1_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_1_map.dat
set ARM_A_1_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_1_map.a2l
rem DSP 1
set DSP_1_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_1.dat
set DSP_1_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_1_map.dat
set DSP_1_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_1_map.a2l
rem EVE 1
set EVE_1_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_1.dat
set EVE_1_MAP_DATFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_1_map.dat
set EVE_1_A2LFILE=%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_1_map.a2l

rem Generate core DAT files
echo.
echo Generate core DAT files
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %ARM_M_0_FILES% -o %ARM_M_0_DATFILE% >> %LOGFILE% 2>&1
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %ARM_M_1_FILES% -o %ARM_M_1_DATFILE% >> %LOGFILE% 2>&1
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %DSP_0_FILES% -o %DSP_0_DATFILE% >> %LOGFILE% 2>&1
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %EVE_0_FILES% -o %EVE_0_DATFILE% >> %LOGFILE% 2>&1
if "%SOCTYPE%" == "high" (
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %ARM_A_0_FILES% -o %ARM_A_0_DATFILE% >> %LOGFILE% 2>&1
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %DSP_1_FILES% -o %DSP_1_DATFILE% >> %LOGFILE% 2>&1
%PDO_SCAN% -c arm_m3_pdo_cmt.cfg %INCLUDES% %DEFINES% %EVE_1_FILES% -o %EVE_1_DATFILE% >> %LOGFILE% 2>&1
)

if ERRORLEVEL 0 goto PDO_MERGE
echo ERROR running PDOScan!
goto EXIT



:PDO_MERGE
echo.
echo Merge core DAT files with single core map files
rem Generate DAT file including map information
echo. DPU cores
if not "%PROJECT_NAME:~0,6%" == "ars441" (
	if EXIST %ARM_A_0_DATFILE% (
	echo ARM_A_0...
	%PDO_TOOL% %ARM_A_0_DATFILE% -c %ARM_A_0_OUT_MAP% -f xmldat1.0 -o %ARM_A_0_MAP_DATFILE% >> %LOGFILE% 2>&1
	)
)
if EXIST %ARM_M_0_DATFILE% (
echo ARM_M_0
%PDO_TOOL% %ARM_M_0_DATFILE% -c %ARM_M_0_OUT_MAP% -f xmldat1.0 -o %ARM_M_0_MAP_DATFILE% >> %LOGFILE% 2>&1
)
if EXIST %ARM_M_1_DATFILE% (
echo ARM_M_1
%PDO_TOOL% %ARM_M_1_DATFILE% -c %ARM_M_1_OUT_MAP% -f xmldat1.0 -o %ARM_M_1_MAP_DATFILE% >> %LOGFILE% 2>&1
)
if exist %DSP_0_DATFILE% (
echo DSP_0
%PDO_TOOL% %DSP_0_DATFILE% -c %DSP_0_OUT_MAP% -f xmldat1.0 -o %DSP_0_MAP_DATFILE% >> %LOGFILE% 2>&1
)
if EXIST %EVE_0_DATFILE% (
echo EVE_0
%PDO_TOOL% %EVE_0_DATFILE% -c %EVE_0_OUT_MAP% -f xmldat1.0 -o %EVE_0_MAP_DATFILE% >> %LOGFILE% 2>&1
)
if "%SOCTYPE%" == "high" (
	if EXIST %DSP_1_DATFILE% (
	echo DSP_1
	%PDO_TOOL% %DSP_1_DATFILE% -c %DSP_1_OUT_MAP% -f xmldat1.0 -o %DSP_1_MAP_DATFILE% >> %LOGFILE% 2>&1
	)
	if EXIST %EVE_1_DATFILE% (
	echo EVE_1
	%PDO_TOOL% %EVE_1_DATFILE% -c %EVE_1_OUT_MAP% -f xmldat1.0 -o %EVE_1_MAP_DATFILE% >> %LOGFILE% 2>&1
	)
)
if ERRORLEVEL 0 goto PDOSCAN_OK
echo ERROR running PDOTool merge!
goto EXIT


:PDOSCAN_OK
rem echo PDOSCAN_OK
rem Generate A2L from DAT

if %MFC431% NEQ 0 (

  rem ===  MFC431 ===

	echo.  
	echo Generate A2L files for the single cores
	if EXIST %ARM_A_0_MAP_DATFILE% (
	echo. %ARM_A_0_A2LFILE% 
	%PDO_TOOL% %ARM_A_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-a_0_a2l.cfg -o %ARM_A_0_A2LFILE% >> %LOGFILE% 2>&1
	)
	
	if EXIST %ARM_M_0_MAP_DATFILE% (
	echo. %ARM_M_0_A2LFILE%
	%PDO_TOOL% %ARM_M_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_0_a2l.cfg -o %ARM_M_0_A2LFILE% >> %LOGFILE% 2>&1
	)

	if EXIST %ARM_M_1_MAP_DATFILE% (
	echo. %ARM_M_1_A2LFILE%
	%PDO_TOOL% %ARM_M_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_1_a2l.cfg -o %ARM_M_1_A2LFILE% >> %LOGFILE% 2>&1
	)
	
	if EXIST %DSP_0_MAP_DATFILE% (
	echo. %DSP_0_A2LFILE%
	%PDO_TOOL% %DSP_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_dsp_0_a2l.cfg -o %DSP_0_A2LFILE% >> %LOGFILE% 2>&1
	)
	
	if EXIST %EVE_0_MAP_DATFILE% (
	echo. %EVE_0_A2LFILE%
	%PDO_TOOL% %EVE_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_eve_0_a2l.cfg -o %EVE_0_A2LFILE% >> %LOGFILE% 2>&1
	)

	if EXIST %DSP_1_MAP_DATFILE% (
	echo. %DSP_1_A2LFILE%
	%PDO_TOOL% %DSP_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_dsp_1_a2l.cfg -o %DSP_1_A2LFILE% >> %LOGFILE% 2>&1
	)
	
	if EXIST %EVE_1_MAP_DATFILE% (
	echo. %EVE_1_A2LFILE%
	%PDO_TOOL% %EVE_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_eve_1_a2l.cfg -o %EVE_1_A2LFILE% >> %LOGFILE% 2>&1
	)

  rem ) %MFC431%
)

if "%PRODUCT:~0,6%" == "hfl110" (

  rem ===  HFL110 ===

  echo.  
  echo Generate A2L files for the single cores
  if EXIST %ARM_A_0_MAP_DATFILE% (
  echo. %ARM_A_0_A2LFILE% 
  %PDO_TOOL% %ARM_A_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-a_0_a2l.cfg -o %ARM_A_0_A2LFILE% >> %LOGFILE% 2>&1
  )
  
  if EXIST %ARM_M_0_MAP_DATFILE% (
  echo. %ARM_M_0_A2LFILE%
  %PDO_TOOL% %ARM_M_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_0_a2l.cfg -o %ARM_M_0_A2LFILE% >> %LOGFILE% 2>&1
  )

  if EXIST %ARM_M_1_MAP_DATFILE% (
  echo. %ARM_M_1_A2LFILE%
  %PDO_TOOL% %ARM_M_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_1_a2l.cfg -o %ARM_M_1_A2LFILE% >> %LOGFILE% 2>&1
  )
  
  if EXIST %DSP_0_MAP_DATFILE% (
  echo. %DSP_0_A2LFILE%
  %PDO_TOOL% %DSP_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_dsp_0_a2l.cfg -o %DSP_0_A2LFILE% >> %LOGFILE% 2>&1
  )
  
  if EXIST %EVE_0_MAP_DATFILE% (
  echo. %EVE_0_A2LFILE%
  %PDO_TOOL% %EVE_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_eve_0_a2l.cfg -o %EVE_0_A2LFILE% >> %LOGFILE% 2>&1
  )

  if EXIST %DSP_1_MAP_DATFILE% (
  echo. %DSP_1_A2LFILE%
  %PDO_TOOL% %DSP_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_dsp_1_a2l.cfg -o %DSP_1_A2LFILE% >> %LOGFILE% 2>&1
  )
  
  if EXIST %EVE_1_MAP_DATFILE% (
  echo. %EVE_1_A2LFILE%
  %PDO_TOOL% %EVE_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_eve_1_a2l.cfg -o %EVE_1_A2LFILE% >> %LOGFILE% 2>&1
  )

  rem ) %HFL110%
)

if "%PROJECT_NAME:~0,6%" == "ars441" (

  rem ===  ars441 ===

	echo.  
	echo Generate A2L files for the single cores
	if EXIST %ARM_M_0_MAP_DATFILE% (
	echo. %ARM_M_0_A2LFILE%
	%PDO_TOOL% %ARM_M_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_0_a2l.cfg -o %ARM_M_0_A2LFILE% >> %LOGFILE% 2>&1
	)
	if EXIST %ARM_M_1_MAP_DATFILE% (
	echo. %ARM_M_1_A2LFILE%
	%PDO_TOOL% %ARM_M_1_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_arm-m_1_a2l.cfg -o %ARM_M_1_A2LFILE% >> %LOGFILE% 2>&1
	)
	if EXIST %DSP_0_MAP_DATFILE% (
	echo. %DSP_0_A2LFILE%
	%PDO_TOOL% %DSP_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_dsp_0_a2l.cfg -o %DSP_0_A2LFILE% >> %LOGFILE% 2>&1
	)
	if EXIST %EVE_0_MAP_DATFILE% (
	echo. %EVE_0_A2LFILE%
	%PDO_TOOL% %EVE_0_MAP_DATFILE% -f asap2 --config pdo_tool_cfg_soc_eve_0_a2l.cfg -o %EVE_0_A2LFILE% >> %LOGFILE% 2>&1
	)

  rem ) %ars441%
)

if ERRORLEVEL 0 goto PDOTOOL_OK
echo ERROR running PDOTool!
goto EXIT


:PDOTOOL_OK
echo.  
echo Merge All core A2L files to one single A2L file
pushd.

if %MFC431% NEQ 0 (
%PERL% merge_a2l_files.pl %PROJECT_NAME% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_1_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_1_map.a2l
)

if "%PRODUCT:~0,6%" == "hfl110" (
%PERL% merge_a2l_files.pl %PROJECT_NAME% %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_1_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_a_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_1_map.a2l
)

if "%PROJECT_NAME:~0,6%" == "ars441" (
%PERL% merge_a2l_files.pl %PROJECT_NAME% ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_m_1_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_dsp_0_map.a2l ^
%PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_eve_0_map.a2l
)

popd

echo. 
echo Copy combined A2L File
copy %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\%PROJECT_NAME%_PR_soc_rel.a2l ^ %PROJECT_ROOT%\04_Engineering\04_Build\a2l\%PROJECT_NAME%_PR_soc_rel.a2l
del %PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\a2l\%PROJECT_NAME%_PR_soc_rel.a2l


:EXIT
rem Delete temporary files

rem Delete out/modified map files
del %ARM_M_0_OUT_MAP% ^ %DSP_0_OUT_MAP% 
if "%SOCTYPE%" == "high" (
	del %ARM_A_0_OUT_MAP% ^ %ARM_M_1_OUT_MAP% ^ %EVE_0_OUT_MAP%
)

if "%SOCTYPE%" == "high" (
	del %DSP_1_OUT_MAP% ^ %EVE_1_OUT_MAP%
)

rem Delete core dat files
del %ARM_M_0_DATFILE% ^	%ARM_M_1_DATFILE% ^	%DSP_0_DATFILE% 
del %ARM_A_0_DATFILE% ^	%EVE_0_DATFILE%

if "%SOCTYPE%" == "high" (
	del %DSP_1_DATFILE% ^ %EVE_1_DATFILE%
)

rem Delete merged core dat files containing map information
del %ARM_M_0_MAP_DATFILE% ^ %DSP_0_MAP_DATFILE% 
del	%ARM_A_0_MAP_DATFILE% ^	%EVE_0_MAP_DATFILE%
del %ARM_M_1_MAP_DATFILE%

if "%SOCTYPE%" == "high" (
	del %DSP_1_MAP_DATFILE% ^	%EVE_1_MAP_DATFILE%
)

rem Delete core A2L files
del %ARM_M_0_A2LFILE% ^	%DSP_0_A2LFILE% 
del %ARM_A_0_A2LFILE% ^ %EVE_0_A2LFILE%
del %ARM_M_1_A2LFILE%

if "%SOCTYPE%" == "high" (
	del %DSP_1_A2LFILE% ^	%EVE_1_A2LFILE%
)

if %PAUSE% == 0 goto EXIT_NOPAUSE:
pause
:EXIT_NOPAUSE
