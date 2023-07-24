@echo off
:: This script checks in the needed files for a SoC checkpoint.
:: Files fust be in state modified.
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation							23.06.2015    Frank Sautter-Steisslinger


:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion
set PROJECT=
set ANSWER=n
set DRYRUN=0

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "" (
  echo.
  echo Error: Please specify the product ID with a parameter to the "p" argument
  echo        ie. lockFilesForCP.bat p mfs430bw16
  exit /b
)

if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. lockFilesForCP.bat p mfs430bw16
    exit /b
  ) else (
    set PROJECT=%2
  )
)

if "%1" == "d" (
  set DRYRUN=1
  echo.
  echo We just do a dry run.
)

if "%1" == "-d" (
  set DRYRUN=1
  echo.
  echo We just do a dry run.
)


:: Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

echo.
set /p descriptText="Enter the description for the checkpoint [%descriptText%]: "
if "%descriptText%" == "" (
    echo.
    echo Error: Please enter a description
    exit /b
  )

for /f "tokens=1,2 delims= " %%a in ("%descriptText%") do set labelText=%%a
echo.
echo Checkpoint with description:                %descriptText%
echo Checkpoint will get the following label:    %labelText%
echo.

SET /P ANSWER=Do you want to checkpoint now? [yn](n): 
if %ANSWER%==y (
	cd ..\..\..\..

	echo Checkpointing %PROJECT% DPU Sources quiet. You will see no output.
	if %DRYRUN%==0 (
		si checkpoint --label="%labelText%" --description="%descriptText%" --notify --quiet
	)
	rem Delay to get the right checkpoint information
	timeout 30
	si projectinfo --showCheckpointDescription --nodevpaths
	echo.
	echo Checkpoint done.
	echo.
	
	cd ..\06_Deliverables\DPU

	echo Checkpointing %PROJECT% DPU Deliverables quiet. You will see no output.
	if %DRYRUN%==0 (
		si checkpoint --label="%labelText%" --description="%descriptText%" --notify --quiet
	)
	rem Delay to get the right checkpoint information
	timeout 30
	si projectinfo --showCheckpointDescription --nodevpaths
	echo.
	echo Checkpoint done.
	cd %CURRENT_WD%
	)
echo.

ENDLOCAL & SET descriptText=%descriptText%& SET labelText=%labelText%
