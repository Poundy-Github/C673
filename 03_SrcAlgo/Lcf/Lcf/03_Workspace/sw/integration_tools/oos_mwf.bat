@echo off
:: This script checks for out of sync files in your sandbox
:: Using the script asumes that you know what you are doing. 

:: (C) 2014 - ADC Lindau GERMANY
:: Author: Frank Sautter-Steisslinger
:: Version: 1.0  Script generation							23.06.2015    Frank Sautter-Steisslinger
::          1.1  Moved to Mainstream                        17.01.2017    Magnus Baur
::          1.2  First working version in Mainstream        19.01.2017    Magnus Baur
::          1.3  Updated to use DPU and Deliverables folder 19.01.2017    Magnus Baur
::          1.4  Fixed a problem with mingw console output  20.01.2017    Magnus Baur

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

set CALL_DIR=%cd%
set ANSWER=n
set SYNCONLY=0
set DELIVERABLES=1
echo.

:optionsloop
if "%1" == "s"  set SYNCONLY=1
if "%1" == "d"  set DELIVERABLES=0
rem shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

:cdloop
if exist 04_Engineering goto cdend
cd ..\
goto cdloop
:cdend

:: Set DPU as Folder to be checked for Out of sync
set MY_DIR=%cd%

:: Sync only
if %SYNCONLY% == 1 (
  goto syncnow
  )

:filternow
echo Starting scan from %cd%
echo.
:: Change to deliverables folder
if %DELIVERABLES% == 1 (
  cd ..
  if exist DPU (
    echo Out of Sync Deliverables:
	cd 06_Deliverables
	si print --filter=changed:sync -R
	echo.
  )
  :: Change back to DPU Folder
  cd %MY_DIR%
)
echo Out of Sync DPU Members:
si print --filter=changed:sync -R

echo.
echo.
:: Change to deliverables folder
if %DELIVERABLES% == 1 (
  cd ..
  if exist DPU (
    echo Modified Deliverables:
	cd 06_Deliverables
	si print --filter=changed:working -R
	echo.
  )
  :: Change back to DPU Folder
  cd %MY_DIR%
)
echo Modified DPU Files:
si print --filter=changed:working -R
echo.
echo.

:syncnow
echo Do you want to resync the sandbox? [yn](n): 
SET /P ANSWER=
if %ANSWER%==y (si resync --quiet)
:: Change to deliverables folder
if %DELIVERABLES% == 1 (
  cd ..
  if exist DPU (
	cd 06_Deliverables
	if %ANSWER%==y (si resync --quiet)
  )
)

cd %CALL_DIR%