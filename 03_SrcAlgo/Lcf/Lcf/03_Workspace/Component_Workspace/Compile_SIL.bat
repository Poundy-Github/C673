@echo off

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%
set PROJECT=
set INCREMENTAL_BUILD=0


:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CDing into the batch files home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "p" (
  if "%2%" NEQ "" (
    set PROJECT=%2
    :: convert project to upper case
    for %%L IN (A B C D E F G H I J K L M N O P Q R S T U V W X Y Z) DO SET PROJECT=!PROJECT:%%L=%%L!
  )
)

if "%1" == "-f" (
  echo.
  echo Enabled incremental build, i.e. skip cleaning of environment
  echo.
  set INCREMENTAL_BUILD=1
)

:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend
:: Check whether project was set 
if "%PROJECT%" == "" (
  goto usage
)

echo ###### SIL build for %PROJECT% ######

set CLEAN_LOG_FILE=%PROJECT%_clean.log
set SIL_LOG_FILE=%PROJECT%_sil_build.log
attrib -R .\* /S

if %INCREMENTAL_BUILD% == 0 (
  if exist %CLEAN_LOG_FILE% del %CLEAN_LOG_FILE%
  
  echo ###### Clean the environment ######
  
  :: Define relevant variables
  set LOG_FILE=%CLEAN_LOG_FILE%
  set CLEAN_FLAG=-c
  set BUILD_TYPE=algo
  
  call :buildAll
)

if exist %SIL_LOG_FILE% del %SIL_LOG_FILE%

:: Define relevant variables
set LOG_FILE=%SIL_LOG_FILE%
set CLEAN_FLAG=
set BUILD_TYPE=sim
call ::buildAll

cd %INITIAL_WD%
exit /b

:buildAll
set BUILD_ADDON=pc
  
echo ######
echo ###### Start LIB Release build ######
set BUILD_TYPE=algo

set COMPONENT=cml
call :build
set COMPONENT=cct
call :build
set COMPONENT=pc
call :build
set COMPONENT=og
call :build
set COMPONENT=gss
call :build
set COMPONENT=tp
call :build

echo ######
echo ###### Start SIM DLL Release build ######
set BUILD_TYPE=sim

set COMPONENT=cct
set TMP_BUILD_ADDON=%BUILD_ADDON%
set BUILD_ADDON=swc_cut_roi
call :build
set COMPONENT=cct
set BUILD_ADDON=swc_vis_image
call :build
set COMPONENT=cct
set BUILD_ADDON=swc_vis_perspectives
call :build
set COMPONENT=cct
set BUILD_ADDON=swc_vis_rt_range
call :build
set COMPONENT=cct
set BUILD_ADDON=swc_vis_velodyne
call :build
set COMPONENT=cct
set BUILD_ADDON=%TMP_BUILD_ADDON%

set COMPONENT=cb
call :build
set COMPONENT=cipp
call :build
set COMPONENT=ecm
call :build
set COMPONENT=em
call :build
set COMPONENT=famo
call :build
set COMPONENT=fct
call :build
set COMPONENT=gia
call :build
set COMPONENT=gs
call :build
set COMPONENT=hla
call :build
set COMPONENT=ld
call :build
set COMPONENT=lsd
call :build
set COMPONENT=memo
call :build
set COMPONENT=pc
call :build
set COMPONENT=pfc
call :build
set COMPONENT=rum
call :build
set COMPONENT=sr
call :build
set COMPONENT=tsa
call :build
set COMPONENT=udw
call :build
set COMPONENT=vdy
call :build
set COMPONENT=vodca
call :build

:: Special handling for LCF. sdlcompiler will fail during parallel build of three lcf SIL target. Let's call them separately
set COMPONENT=lcf
set BUILD_ADDON=swc_lcf_sen
call :build
set COMPONENT=lcf
set BUILD_ADDON=swc_lcf_veh
call :build
set COMPONENT=lcf
set BUILD_ADDON=swc_vis
call :build

exit /b

:build
echo ###### %COMPONENT% %BUILD_TYPE% %BUILD_ADDON% release ######
REM echo ###### .\%COMPONENT%\scons %COMPONENT%_%BUILD_TYPE%_%BUILD_ADDON%_release -j%NUMBER_OF_PROCESSORS% project=%PROJECT% %CLEAN_FLAG% #####
call .\%COMPONENT%\scons %COMPONENT%_%BUILD_TYPE%_%BUILD_ADDON%_release -j%NUMBER_OF_PROCESSORS% project=%PROJECT% %CLEAN_FLAG%

:: Preserve exit code of scons which should not destroyed by negative PING
set EXIT_CODE_SCONS=%ERRORLEVEL%

if "%CLEAN_FLAG%" NEQ "-c" (
    ping 1.1.1.1 -n 5 -w 5000  1>NUL
)

if %EXIT_CODE_SCONS% NEQ 0 (
  echo ***ERROR: %COMPONENT% %BUILD_TYPE% release failed. Please have a look at console *** >> %LOG_FILE% 2>&1
)

if %EXIT_CODE_SCONS% == 0 (
  echo ***Succeeded: %COMPONENT% %BUILD_TYPE% passed.  >> %LOG_FILE% 2>&1
)
exit /b

:usage
echo.
echo Error: Please specify the product ID with a parameter to the "p" argument
echo        ie. Compile_SIL.bat p MFC431
echo        Use option -f for incremental build
exit /b