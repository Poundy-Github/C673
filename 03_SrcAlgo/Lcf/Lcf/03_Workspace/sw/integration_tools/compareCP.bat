@echo off

:: How to use the script:
:: The script compares two checkpoints with each other.
:: Also a comparison with the head revisions of a development path can be done.

:: Syntax:
:: compareCP.bat CP1 [CP2]

:: Options:
:: Options are: trunk, R21 or each CP ID.
:: There are also exclude options: . - + excludes changed, dropped or added objects
:: Option g opens the GUI

:: Example:
:: compareCP.bat trunk									-> Comparing last trunk CP with trunk.
:: compareCP.bat 1.133.1.40 1.133.1.41  -> Comparing 1.133.1.40 with 1.133.1.41.
:: compareCP.bat 1.133.1.41 i390        -> Comparing 1.133.1.41 with I390 Dev.Path.
:: compareCP.bat trunk x . -            -> Comparing last trunk CP with trunk. 
::										   Will not show changes and dropped files, just added objects.
::										   x is needed because exclude options start at position 3.
::
:: !-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!
:: CAUTION: The development path must be in the end and the CP ID first !!!!
:: !-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!-!

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion

:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD = %CD%

:: Delete intermediate file if exist
if exist mks_diff.txt del mks_diff.txt

:: Set init values
set PROJECT=#/ADAS/SW#Projects/MFC431x/MFC431
set GUI=0

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD = %CD%

if "%1"=="" (
    echo.
    echo Error. No parameter.
    echo Open Script file to see Help.
    goto endOfScript
    )

:: Set parameters
set CP1=%1
set nameCP1=%CP1%
set CP2=%2

if "%2"=="g" set GUI=1
if "%3"=="g" set GUI=1
if "%4"=="g" set GUI=1
if "%5"=="g" set GUI=1
if "%6"=="g" set GUI=1

:: Sort the parameters
echo.
if %CP1%==trunk (
  set CP1=
  set CP2=trunk
  set nameCP1=last trunk CP
) else if %CP1%==MFC431_R8.0 (
  set CP1=
  set CP2=MFC431_R8.0
  set nameCP1=last MFC431_R8.0 CP
) else if %CP1%==MFC431_R8.1 (
  set CP1=
  set CP2=MFC431_R8.1
  set nameCP1=last MFC431_R8.1 CP
) else if %CP1%==MFC431_R8.2 (
  set CP1=
  set CP2=MFC431_R8.2
  set nameCP1=last MFC431_R8.2 CP
) else (
  set CP1=-r %CP1%
)

if %CP2%==trunk (
  set PROJECT=%PROJECT%#DPU
  echo . Comparing %nameCP1% with trunk.
) else if %CP2%==MFC431_R8.0 (
  set PROJECT=%PROJECT%#d=MFC431_R8.0#DPU
  echo . Comparing %nameCP1% with MFC431_R8.0 Dev.Path.
) else if %CP2%==MFC431_R8.1 (
  set PROJECT=%PROJECT%#d=MFC431_R8.1#DPU
  echo . Comparing %nameCP1% with MFC431_R8.1 Dev.Path.
) else if %CP2%==MFC431_R8.2 (
  set PROJECT=%PROJECT%#d=MFC431_R8.2#DPU
  echo . Comparing %nameCP1% with MFC431_R8.2 Dev.Path.
) else (
  set PROJECT=%PROJECT%#DPU#b=%CP2%
  echo . Comparing %nameCP1% with %CP2%.
)
echo.

:: Compare and filter
si mods -R %CP1% --project=%PROJECT% > mks_diff.txt
perl.exe extractPrjDiff.pl %3 %4 %5
echo.
echo . Done!
echo.
:: Open GUI
if "%GUI%"=="1" si mods --gui -R %CP1% --project=%PROJECT%

:endOfScript
