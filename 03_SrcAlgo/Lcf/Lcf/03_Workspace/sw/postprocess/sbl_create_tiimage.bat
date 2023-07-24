:: turn off command-echoing
@echo off
setlocal
set post_process_dir=..\..\..\02_Development_Tools\post_process
set srec_cat=%post_process_dir%\srec_cat.exe
if "%PROJECT_NAME%" == "" (
	echo Error: This batch file can no longer be used standalone.  Please use the
	echo        command "sw_build.bat postonly" to generate ROM images without building
	exit /b
)


:: store directory where this batch file is stored
set MY_DIR=%~dp0

:: Set default build configuration to 'spi_release'
set BUILD_CFG=%MY_DIR%..\..\..\04_build\sbl\mfc431

:: Check if build configuration name has been passed as argument
if "%1%"=="" goto NEXT_1
set BUILD_CFG=%MY_DIR%..\..\..\04_Build\sbl\%1%

:: Check if output directory name has been passed as argument. Otherwise use build configuration directory
:NEXT_1
set BUILD_DIR=%BUILD_CFG%
if "%2%"=="" goto BUILD
set BUILD_DIR=%2%

:BUILD
echo Using build config: '%BUILD_CFG%'
echo Writing files to:   '%BUILD_DIR%'

:: setup directories
if not exist %BUILD_CFG% mkdir %BUILD_CFG%
set dirSblTools=%MY_DIR%..\..\..\02_Development_Tools
set dirSourcery=%MY_DIR%..\..\..\02_Development_Tools\utils
if %DEBUG% == 0 (
set dirSblBuildDir=%MY_DIR%..\..\..\..\04_Engineering\04_Build\out\%APP_PROJECT_NAME%\release_sbl
set dirPreSblBuildDir=%MY_DIR%..\..\..\..\04_Engineering\04_Build\out\%APP_PROJECT_NAME%\release_presbl
) else (
set dirSblBuildDir=%MY_DIR%..\..\..\..\04_Engineering\04_Build\out\%APP_PROJECT_NAME%\debug_sbl
set dirPreSblBuildDir=%MY_DIR%..\..\..\..\04_Engineering\04_Build\out\%APP_PROJECT_NAME%\debug_presbl
)

if %BUILD_SBL% == 1 (
echo SBL has been rebuilt, copying the files to deliverables folder..
attrib -R %BUILD_CFG%\*
copy %dirSblBuildDir%\sbl.out %BUILD_CFG%\
copy %dirSblBuildDir%\sbl.map %BUILD_CFG%\
copy %dirSblBuildDir%_loop\sbl_loop.out %BUILD_CFG%\sbl_loop.out
copy %dirSblBuildDir%_loop\sbl_loop.map %BUILD_CFG%\sbl_loop.map
)

if %BUILD_PRESBL% == 1 (
echo PreSBL has been rebuilt, copying the files to deliverables folder..
attrib -R %BUILD_CFG%\*
copy %dirPreSblBuildDir%\presbl.out %BUILD_CFG%\
copy %dirPreSblBuildDir%\presbl.map %BUILD_CFG%\
)

:: build binary
if "%SOCTYPE%" == "low" (
"%dirSourcery%\arm-none-eabi-objcopy.exe" --gap-fill=0xff -O binary "%BUILD_CFG%\PreSBL.out" "%BUILD_DIR%\PreSBL.bin"
)
"%dirSourcery%\arm-none-eabi-objcopy.exe" --gap-fill=0xff -O binary "%BUILD_CFG%\SBL.out" "%BUILD_DIR%\SBL.bin"

:: build tiimage
:: The Vision Low based camera unfortunately must have a different entry point to Vision Mid and Vision high, as
:: it boots using a Cortex-M rather than a Cortex-A
if "%SOCTYPE%" == "low" (
	set PRE_ENTRY_POINT=0x00300000
) else (
	set ENTRY_POINT=0x40301000
)

if "%SOCTYPE%" == "low" (
	"%dirSblTools%\tiimage\tiimage.exe" %PRE_ENTRY_POINT% BE "%BUILD_DIR%\PreSBL.bin" "%BUILD_DIR%\PreSBL.tiimage"
	 %srec_cat% ^
   PreSBL.tiimage -Binary ^
   -Output PreSBL_Standalone.bin -Binary
   if ERRORLEVEL 1 (
     echo srec_cat -Output presbl_standalone.bin failed & exit /b 1
   )
   echo PreSBL TI BIN File done..
	 copy %BUILD_DIR%\PreSBL_Standalone.bin %BUILD_CFG%\PreSBL.bin
  "..\..\..\02_Development_Tools\out2rprc\out2rprc_src\out2rprc\bin\Release\out2rprc.exe" "%BUILD_CFG%\SBL.out" "%BUILD_DIR%\SBL.rprc"
  "..\..\..\02_Development_Tools\multicore_image_generator\MulticoreImageGen.exe" BE 8 "%BUILD_DIR%\SBLBE.rprc" 2 "%BUILD_DIR%\SBL.rprc"
) else (
"%dirSblTools%\tiimage\tiimage.exe" %ENTRY_POINT% BE "%BUILD_DIR%\SBL.bin" "%BUILD_DIR%\SBL.tiimage"
)
 
set eveMemTest=false
if "%1%"=="mfc431" set eveMemTest=true
if "%1%"=="mfc431lo19" set eveMemTest=true
if "%1%"=="mfc431lo20" set eveMemTest=true
if "%1%"=="mfc431ta19" set eveMemTest=true
if "%1%"=="hfl110" set eveMemTest=true
if "%1%"=="hfl110ta10" set eveMemTest=true
if "%1%"=="ars441" set eveMemTest=true
if "%1%"=="ars441dc13" set eveMemTest=true
if "%1%"=="mfc431sc19" set eveMemTest=true
if "%1%"=="mfc431sw19" set eveMemTest=true
if "%1%"=="mfc431va10" set eveMemTest=true
if "%1%"=="mfc431bd10" set eveMemTest=true
if "%1%"=="mfc431va21" set eveMemTest=true
if "%eveMemTest%"=="true" (
  echo Converting EveMemTest...
  "..\..\..\02_Development_Tools\out2rprc\out2rprc_src\out2rprc\bin\Release\out2rprc.exe" "%MY_DIR%../../../04_Build/out/%APP_PROJECT_NAME%/release_eve_memtest/eve_memtest.out" "%BUILD_DIR%\EveMemTest.rprc"
  "..\..\..\02_Development_Tools\multicore_image_generator\MulticoreImageGen.exe" BE 8 "%BUILD_DIR%\EveMemTestBE.rprc" 10 "%BUILD_DIR%\EveMemTest.rprc"
  echo done.
)

:delte_temp_files
 echo Deleting temporary files
 if exist %BUILD_DIR%\PreSBL.bin del /Q %BUILD_DIR%\PreSBL.bin

 REM PreSBL_Standalone.bin shall not be deleted here, because still needed for ARS441 in MulticorePostprocCommon.bat
 REM is deleted at the end of MulticorePostprocCommon.bat    
 REM if exist %BUILD_DIR%\PreSBL_Standalone.bin del /Q %BUILD_DIR%\PreSBL_Standalone.bin

 if exist %BUILD_DIR%\PreSBL.tiimage del /Q %BUILD_DIR%\PreSBL.tiimage

:END
set PATH=%PATH_TEMP%
title Command Prompt
