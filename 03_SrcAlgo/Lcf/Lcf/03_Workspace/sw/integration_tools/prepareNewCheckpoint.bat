@echo off
:: This script prepares sandbox and files for new SW-Build and checkpoint. (Checkout and open).
:: Using the script asumes that you know what you are doing. 

:: (C) 2015 - ADC Ulm GERMANY
:: Author: Magnus Baur
:: Version: 	1.0	Script generation
::              1.1 First usable version (Toyota only)                  30.03.2015  Magnus Baur
::                  Update for using different projects                 31.03.2015  Magnus Baur
::                  OpenFiles and StartBuild sections added             31.03.2015  Magnus Baur
::                  Notepad++ and UltraEdit support added               31.03.2015  Magnus Baur
::                  Configure Common Checkpoint added to process        31.03.2015  Magnus Baur
::                  Option Menu added                                   14.04.2015  Magnus Baur
::              1.2 updated for Mainstream, first usable version        19.01.2017  Magnus Baur
::              1.3  Fixed a problem with mingw console output          20.01.2017  Magnus Baur


:: Make sure changes to environment variables are only local do not affect the calling command line
SETLOCAL ENABLEDELAYEDEXPANSION
set project=
:: Store current working directory, so we can CD back in case of an error
set STARTING_WD=%CD%

:: Read input option
:optionsloop
if "%1" == "p" (
  if "%2%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
	echo        ie. prepareNewCheckpoint.bat p mfc431
    exit /b
  ) else (
    set project=%2
  )
) else (
	echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
	echo        ie. prepareNewCheckpoint.bat p mfc431
    exit /b
)

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%STARTING_WD%


:optionmenu
echo This script prepares sandbox and files for new SW-Build and checkpoint.
echo.
echo #####################################################################
echo ## 1 - Resynchronize Sandbox                                       ##
echo ##                                                                 ##
echo ## 2 - Checkout generated SIL Files and start SIL Build            ##
echo ##                                                                 ##
echo ## 3 - Checkout related files for new Checkpoint                   ##
echo ##                                                                 ##
echo ## 4 - Start SW-Build (sx_build with zipme)                        ##
echo ##                                                                 ##
echo ## 5 - Checkin related files for new Checkpoint                    ##
echo ##                                                                 ##
echo ## 6 - Remove all my locks                                         ##
echo ##                                                                 ##
echo ## 0 - Exit                                                        ##
echo ##                                                                 ##
echo #####################################################################
echo Please choose an option:
set /p optionID=

if %optionID% == 1 ( 
	goto resync 
	) else if %optionID% == 2 ( 
	goto checkoutSILFiles 
	) else if %optionID% == 3 ( 
	goto chekoutFiles 
	) else if %optionID% == 4 ( 
	goto buildSW 
	) else if %optionID% == 5 ( 
	goto chekinFiles 
	) else if %optionID% == 6 ( 
	goto removeMyLocks 
	) else if %optionID% == 0 ( 
	goto END 
	) else ( 
	goto optionmenu 
	)

:resync
:: Check for out of sync members
cd %CURRENT_WD%
call oos_mwf.bat
goto optionmenu

:checkoutSILFiles
cd %CURRENT_WD%
call lockSILFilesForCP.bat p %project%
goto optionmenu


:chekoutFiles
cd %CURRENT_WD%
call lockAndOpenFilesForCP.bat p %project%
goto optionmenu


:buildSW
cd %CURRENT_WD%
:: check out of sync members
call oos_mwf.bat
call ..\make\sx_build.bat p %project% zipme
goto optionmenu

:chekinFiles
cd %CURRENT_WD%
call ciFilesForCP.bat p %project%
goto optionmenu

:removeMyLocks
cd %CURRENT_WD%
call removeAllMyLocks.bat
goto optionmenu

:END
echo End




