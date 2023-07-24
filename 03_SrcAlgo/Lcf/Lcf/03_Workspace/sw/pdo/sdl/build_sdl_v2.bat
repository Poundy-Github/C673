@echo off
rem (C) 2012 - ADC Lindau GERMANY
rem Author: Frank Sautter-Steisslinger
rem Version: 1.1  Script generation
rem          1.1  Moved to Mainstream													29.11.2016	Magnus Baur
rem          1.7  First working version in Mainstream                                   11.01.2017  Magnus Baur
rem          1.11 Cleaned up from mono and stereo                                       19.01.2017  Magnus Baur

setlocal EnableDelayedExpansion

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

if "%PRODUCT:~0,6%" == "mfc431" (
  set APP_PROJECT_NAME=MFC431
) else if "%PRODUCT:~0,6%" == "hfl110" (
  set APP_PROJECT_NAME=HFL110
) else if "%PRODUCT:~0,6%" == "ars441" (
  set APP_PROJECT_NAME=ARS441
)

rem shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

set PROJECT_ROOT=..\..\..\..\..
set PDO_PATH=c:\tools\pdo\2.16.1.1
set PYTHON_PATH=c:\tools\python\2.7.10
set PYTHON=%PYTHON_PATH%\python.exe
set PYTHON_SCRIPT_PATH=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw
set PDO_TOOL=%PDO_PATH%\Pdo_tool.exe
set PDO_SCAN=%PDO_PATH%\Pdo_scan.exe
set PDO_RLST=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\readLstFile.py


set PDO_TMP_DIR=%PROJECT_ROOT%\04_Engineering\04_build\sdl\
set CFILES_FILE=%PDO_TMP_DIR%\sdl_cFile.txt
set PDOHEADER_CONFIG_FILE=%PDO_TMP_DIR%\sdl_hFile.cfg
set PDODEFINE_FILE=%PDO_TMP_DIR%\sdl_dFile.cfg
set PDOSCAN_LOG_FILE=%PDO_TMP_DIR%\pdoscan.log
set BUILD_MODE=release
set TARGET=arm-a_0
set PDO_CONFIG_FILE=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\sdl\pdo_tool_cfg_sdl_%APP_PROJECT_NAME%.cfg
set PDOSCAN_CONFIG_FILE=%PROJECT_ROOT%\04_Engineering\03_Workspace\sw\pdo\sdl\arm_m3_pdo_cmt.cfg

set APP_PROJECT_NAME=%PRODUCT%
set APP_LINK_NAME=_%PRODUCT%

set DATFILE_PART_01=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC_01.dat
set DATFILE_PART_02=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC_02.dat

set SDLFILE=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl
set LOGFILE=%PROJECT_ROOT%\04_Engineering\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl.log

if "%PRODUCT:~0,6%" == "mfc431" (
set FILES_PART_01=sdl_includes.c
set FILES_PART_02=
) else if "%PRODUCT:~0,6%" == "hfl110" (
set FILES_PART_01=sdl_includes.c
set FILES_PART_02=
) else if "%PRODUCT:~0,6%" == "ars441" (
set FILES_PART_01=sdl_includes.c
set FILES_PART_02=
) else (
set FILES_PART_01=dummy_m3_01.c
set FILES_PART_02=dummy_m3_02.c
)

if "%PRODUCT:~0,6%" == "ars441" (
set PDO_LST_FILES=%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_arm-m_0\arm-m_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_dsp_0\dsp_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_dsp_1\dsp_1.lst
) else (
set PDO_LST_FILES=%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_arm-a_0\arm-a_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_dsp_0\dsp_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_eve_0\eve_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_dsp_1\dsp_1.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_eve_1\eve_1.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_arm-m_0\arm-m_0.lst ^
%PROJECT_ROOT%\04_Engineering\04_build\out\%APP_PROJECT_NAME%\release_arm-m_1\arm-m_1.lst
)

if "%PRODUCT:~0,6%" == "ars441" (

  rem ===  ARS441 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME%
  
set DEFINES=-D PDO_CFG_ARS441=1 -D PDO_CFG_MFC430HI17=0 -D PDO_CFG_MFC431=0 -D PDO_CFG_HFL110=0 -D PRODUCT_ARS441 ^
            -D CFG_MFC_VISION_LOW=1 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L

  rem ) ARS441
)

if "%PRODUCT:~0,6%" == "mfc431" (

  rem ===  MFC431 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME%

set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC431=1 -D PDO_CFG_HFL110=0 -D PRODUCT_MFC431 ^
            -D CFG_MFC_VISION_LOW=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0 -D __PDO__ -D CURRENT_CHIPSET=CHIPSET_TI_VH

  rem ) %MFC431%
)

rem echo %INCLUDES%

if "%PRODUCT:~0,6%" == "hfl110" (

  rem ===  HFL110 config is here ===

set INCLUDES=-I %PROJECT_ROOT%\04_Engineering\04_Build\tools\arm\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\tools\bios\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\Tools\ti_bios\6.41.01.36\packages\gnu\targets\arm\libs\install-native\arm-none-eabi\include ^
  -I C:\tools\gcc_arm\4.7_2012q4\lib\gcc\arm-none-eabi\4.7.3\include ^
  -I %PROJECT_ROOT%\04_Engineering\04_Build\out\%APP_PROJECT_NAME%

set DEFINES=-D PDO_CFG_ARS441=0 -D PDO_CFG_MFC431=0 -D PDO_CFG_HFL110=1 -D PRODUCT_HFL110 ^
            -D CFG_MFC_VISION_LOW=0 -DUSE_OLD_ADC_CODING_STYLE_TYPEDEFS -D __STDC_VERSION__=199901L -D CORE_CA8_0 -D __PDO__ -D GA_ALGO_COMMON_IS_USED=1

  rem ) %HFL110%
)

if not exist %PROJECT_ROOT%\04_Engineering\04_Build\sdl mkdir %PROJECT_ROOT%\04_Engineering\04_Build\sdl

echo "###### Load CFile Source, Define and Header List from lst File ######" > %LOGFILE%
REM set CMD=%PYTHON% %PDO_RLST% %PDO_LST_FILES% -i %PDOHEADER_CONFIG_FILE% -c %CFILES_FILE% -d %PDODEFINE_FILE%
set CMD=%PYTHON% %PDO_RLST% %PDO_LST_FILES% -i %PDOHEADER_CONFIG_FILE% -d %PDODEFINE_FILE%
REM echo %CMD%
%CMD%

for /F %%g in (%PDODEFINE_FILE%) do set "DEFINES=%DEFINES% -D %%g"
REM set /p "DEFINES=" <%PDODEFINE_FILE%

for /F %%g in (%PDOCINPUT_FILE%) do set FILES_PART_01=%%g
REM set /p "FILES_PART_01=" <%PDOCINPUT_FILE%

echo "###### Generate xdc module and error id header ######"  > %LOGFILE%
%PYTHON% %PYTHON_SCRIPT_PATH%\postprocess\generate_xdc_module_and_error_ids.py -p %APP_PROJECT_NAME% -c release

set WD=%CD%
cd../../../..
set "pdoFiles="

if exist 04_Build\sdl\PDO_tag_file_list.txt del 04_Build\sdl\PDO_tag_file_list.txt

if "%PRODUCT:~0,6%" == "mfc431" (
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_CB.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_CIPP.cfg       ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_ECM.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_EM.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FCT.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FAMO.cfg       ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GS.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_HLA.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_IPC.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_LCF.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_LD.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_LSD.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_MEMO.cfg       ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_PC.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_PFC.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_RUM.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_SR.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_TSA.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_UDW.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_VDY.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_VODCA.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUFF.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUIA.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUIC.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUCOM.cfg     ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUINFRA.cfg   ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUSERVICE.cfg ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUST.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
) else if "%PRODUCT:~0,6%" == "hfl110" (
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_ECM.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_EM.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_EMO.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FAMO.cfg       ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FCU_DPU.cfg    ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GEN.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GS.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GSM.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_IPC.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_LIQOR.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_PCA.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_PDM.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_POC.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_VDY_hfl110.cfg ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUCOM.cfg     ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUFF.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUINFRA.cfg   ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUSERVICE.cfg ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUST.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
) else if "%PRODUCT:~0,6%" == "ars441" (
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_EM_ars441.cfg  ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FCT_ars441.cfg ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_FPS.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GFRS.cfg       ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_GS_ars441.cfg  ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_IPC.cfg        ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_PD.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_RC.cfg         ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUFF.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
  for /f "Tokens=* Delims=" %%x in (03_Workspace\sw\pdo\sdl\pdo_file_includes_DPUST.cfg      ) do dir /B /S %%x >> 04_Build\sdl\PDO_tag_file_list.txt
)
set PDO_TAG_FILE=%PDO_TMP_DIR%PDO_tag_file_list.txt
cd %WD%

echo "###### PDOSCAN Part 1 | Generate DAT file ######" >> %LOGFILE%
set CMD=%PDO_SCAN% -c %PDOSCAN_CONFIG_FILE% -c %PDOHEADER_CONFIG_FILE% %INCLUDES% %DEFINES% %FILES_PART_01% @%PDO_TAG_FILE% -o %DATFILE_PART_01%
REM echo %CMD%
%CMD% >> %LOGFILE% 2>&1
if ERRORLEVEL 0 goto PDOSCAN_GO_ON
echo ERROR running PDOScan!
goto EXIT

:PDOSCAN_GO_ON
if "%PRODUCT:~0,6%" == "mfc431" (
  goto PDOSCAN_OK
) else if "%PRODUCT:~0,6%" == "hfl110" (
  goto PDOSCAN_OK
) else if "%PRODUCT:~0,6%" == "ars441" (
  goto PDOSCAN_OK
) else (
  goto PDOSCAN_CONTINUE
)

:PDOSCAN_CONTINUE
echo "###### PDOSCAN Part 2 | Generate DAT file ######" >> %LOGFILE%
REM set CMD=%PDO_SCAN% -l %PDOSCAN_LOG_FILE% -c %PDO_CONFIG_FILE% -c %PDOHEADER_CONFIG_FILE% %INCLUDES% %DEFINES% %FILES_PART_01% -o %DATFILE_PART_01% >> %LOGFILE% 2>&1
set CMD=%PDO_SCAN% -c %PDOSCAN_CONFIG_FILE% -c %PDOHEADER_CONFIG_FILE% %INCLUDES% %DEFINES% %FILES_PART_02% -o %DATFILE_PART_02% 
REM echo %CMD%
%CMD% >> %LOGFILE% 2>&1
if ERRORLEVEL 0 goto PDOSCAN_OK
echo ERROR running PDOScan!
goto EXIT


:PDOSCAN_OK
rem Generate SDL from DAT
echo. >> %LOGFILE%
echo Generate SDL from DAT files >> %LOGFILE%
if "%PRODUCT:~0,6%" == "mfc431" (
  goto GENERATE_PROJECT_SDL
) else if "%PRODUCT:~0,6%" == "hfl110" (
  goto GENERATE_PROJECT_SDL
) else if "%PRODUCT:~0,6%" == "ars441" (
  goto GENERATE_PROJECT_SDL
) else (
  goto GENERATE_DPU_SDL
)
    
:GENERATE_PROJECT_SDL
set CMD=%PDO_TOOL% %DATFILE_PART_01% --enable virtualobj --disable normalobj --config %PDO_CONFIG_FILE% -o %SDLFILE%
%CMD% >> %LOGFILE% 2>&1
goto PDOTOOL_OK

:GENERATE_DPU_SDL
REM set CMD=%PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config pdo_tool_cfg_sdl_mfc431.cfg -o %SDLFILE% >> %LOGFILE% 2>&1
set CMD=%PDO_TOOL% %DATFILE_PART_01% %DATFILE_PART_02% --enable virtualobj --disable normalobj --config %PDO_CONFIG_FILE% -o %SDLFILE% 
REM echo %CMD%
%CMD% >> %LOGFILE% 2>&1

:PDOTOOL_OK
echo SDL was generated for %APP_PROJECT_NAME%

:EXIT
rem if exist %DATFILE_PART_01% del %DATFILE_PART_01%
rem if exist %DATFILE_PART_02% del %DATFILE_PART_02%

if %PAUSE% == 0 goto EXIT_NOPAUSE:
pause
:EXIT_NOPAUSE
