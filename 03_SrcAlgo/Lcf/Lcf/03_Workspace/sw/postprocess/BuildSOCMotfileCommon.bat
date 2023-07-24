@echo off

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

echo.
echo --- Start: BuildSOCMotfileCommon.bat

if "%PROJECT_NAME%" == "" (
	echo.
	echo Error: This batch file can no longer be used standalone.  Please use the
	echo        command "sw_build.bat postonly" to generate ROM images without building
	exit /b
)

rem this now calls the perl script to inspect the infoblock
call ../postprocess/MulticorePostprocCommon.bat
rem If either of the image archives (AppImage_BE.mfc or AppImageStereo_BE.mfc) could not be created
rem due to missing .out files, the MulticorePostprocCommonExe.bat batch file will return 1, so we will
rem exit here, to avoid generating invalid .bin and/or .mot files.  The ERRORLEVEL can be set by almost
rem any command, so this check must come *immediately* after the call to MulticorePostprocCommonExe.bat!
if ERRORLEVEL 1 (
  exit /b 1
)

rem Generate SDL file for the SoC if not switched off
IF "%BUILD_SDL%"=="" set BUILD_SDL=1
if %BUILD_SDL% == 0 goto :skipped_sdl

echo.
echo Generate SDL file for %APP_PROJECT_NAME% ...

cd ..\pdo\sdl

if "%PRODUCT:~0,6%" == "mfc431" (
  call build_sdl_v2.bat p %APP_PROJECT_NAME% nopause
) else if "%PRODUCT:~0,6%" == "hfl110" (
  call build_sdl_v2.bat p %APP_PROJECT_NAME% nopause
) else if "%PRODUCT:~0,6%" == "ars441" (
  call build_sdl_v2.bat p %APP_PROJECT_NAME% nopause
) else (
  call build_sdl.bat p %APP_PROJECT_NAME% nopause
)


if %DEBUG% == 0 (
  if %SCRIPT% == sx (
    echo Checking SDL file for errors ...
    findstr "reading" ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl.log
    if !ERRORLEVEL! == 0 (
      echo.
      echo Error while generating the SDL file. Please check.
      echo.
    )
    findstr "error: warning:" ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl.log
    if !ERRORLEVEL! == 0 (
      echo.
      echo PDO Tool found Errors and Warnings in SDL file. Please check.
      echo.
    )
    
    echo Copy SDL and DAT file to %APP_PROJECT_NAME% deliverables folder
    attrib -r ..\..\..\..\..\..\06_Deliverables\DPU\%APP_PROJECT_NAME%_SOC_rel.sdl
    attrib -r ..\..\..\..\..\..\06_Deliverables\DPU\%APP_PROJECT_NAME%_SOC_rel.dat
    copy ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl ..\..\..\..\..\..\06_Deliverables\DPU\%APP_PROJECT_NAME%_SOC_rel.sdl
    if exist ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC_01.dat copy ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC_01.dat ..\..\..\..\..\..\06_Deliverables\DPU\%APP_PROJECT_NAME%_SOC_rel.dat
    if exist ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC_02.dat (
        echo.
        echo Second .dat file found. Please check if realy needed and change copy to 06_Deliverables accordingly!
        echo.
        )
    copy ..\..\..\..\04_Build\sdl\%APP_PROJECT_NAME%_SOC.sdl ..\..\..\..\04_Build\sdl\%tsnow%_%BUILDCONFIG%_%APP_PROJECT_NAME%_SOC.sdl
  )
)

cd ../../make

:skipped_sdl
echo.
echo --- Done:  BuildSOCMotfileCommon.bat
