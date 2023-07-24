@echo off
:: This script prepares sandbox and files for new SW-Build and checkpoint. (Checkout and open).
:: Using the script asumes that you know what you are doing. 

:: (C) 2015 - ADC Ulm GERMANY
:: Author: Magnus Baur
:: Version: 	1.0	Script generation
::              1.1 First usable version 				                22.06.2018  Magnus Baur
::              1.2 Updated for more common usage                       28.06.2018  Magnus Baur


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
echo.# %project%
echo #####################################################################
echo ##                                                                 ##
echo ## 01 - Configure BU1 subprojects for Latest / Release             ##
echo ##                                                                 ##
echo ## 02 - Configure BU2 subprojects for Latest / Release             ##
echo ##                                                                 ##
echo ## 03 - Configure BU3 subprojects for Latest / Release             ##
echo ##                                                                 ##
echo ## 04 - Resynchronize Sandbox                                      ##
echo ##                                                                 ##
echo ## 05 - Update BU1 Software Version Number                         ##
echo ##                                                                 ##
echo ## 06 - Update BU2 Software Version Number                         ##
echo ##                                                                 ##
echo ## 07 - Update BU3 Software Version Number                         ##
echo ##                                                                 ##
echo ## 08 - Start BU1 SW-Build                                         ##
echo ##                                                                 ##
echo ## 09 - Start BU2 SW-Build                                         ##
echo ##                                                                 ##
echo ## 10 - Start BU3 SW-Build                                         ##
echo ##                                                                 ##
echo ## 11 - Check in Files for BU1                                     ##
echo ##                                                                 ##
echo ## 12 - Check in Files for BU2                                     ##
echo ##                                                                 ##
echo ## 13 - Check in Files for BU3                                     ##
echo ##                                                                 ##
echo ## 14 - Checkpoint Subprojects for BU1                             ##
echo ##                                                                 ##
echo ## 15 - Checkpoint Subprojects for BU2                             ##
echo ##                                                                 ##
echo ## 16 - Checkpoint Subprojects for BU3                             ##
echo ##                                                                 ##
echo ## 17 - Checkpoint Overall Project                                 ##
echo ##                                                                 ##
echo ## 0 - Exit                                                        ##
echo ##                                                                 ##
echo #####################################################################
echo Please choose an option:
set /p optionID=

if %optionID% == 1 ( 
	goto configureSubProjectsBU1 
	) else if %optionID% == 2 ( 
	goto configureSubProjectsBU2 
	) else if %optionID% == 3 ( 
	goto configureSubProjectsBU3 
	) else if %optionID% == 4 ( 
	goto resync 
	) else if %optionID% == 5 ( 
	goto updateSWVersionNumberBU1 
	) else if %optionID% == 6 ( 
	goto updateSWVersionNumberBU2 
	)else if %optionID% == 7 ( 
	goto updateSWVersionNumberBU3 
	)else if %optionID% == 8 ( 
	goto buildSWBU1
	)else if %optionID% == 9 ( 
	goto buildSWBU2
	)else if %optionID% == 10 ( 
	goto buildSWBU3
	) else if %optionID% == 11 ( 
	goto chekinFilesBU1 
	) else if %optionID% == 12 ( 
	goto chekinFilesBU2 
	) else if %optionID% == 13 ( 
	goto chekinFilesBU3 
	) else if %optionID% == 14 ( 
	goto checkpointProjectBU1 
	) else if %optionID% == 15 ( 
	goto checkpointProjectBU2 
	) else if %optionID% == 16 ( 
	goto checkpointProjectBU3 
	) else if %optionID% == 17 ( 
	goto checkpointProjectOverall 
	) else if %optionID% == 0 ( 
	goto END 
	) else ( 
	goto optionmenu 
	)

:configureSubProjectsBU1
:: Configure Subprojects according to Release
call python ais.py -p %project% configure_subprojects --iuc --force
goto optionmenu

:configureSubProjectsBU2
:: Configure Subprojects according to Release
call python ais.py -p %project% configure_subprojects --dpu --force
goto optionmenu

:configureSubProjectsBU3
:: Configure Subprojects according to Release
call python ais.py -p %project% configure_subprojects --sil --force
goto optionmenu
	
:resync
:: Check for out of sync members
call python ais.py -p %project% project_resync
goto optionmenu

:updateSWVersionNumberBU1
call python ais.py -p %project% update_sw_ver_no --iuc
goto optionmenu

:updateSWVersionNumberBU2
call python ais.py -p %project% update_sw_ver_no --dpu
goto optionmenu

:updateSWVersionNumberBU3
call python ais.py -p %project% update_sw_ver_no --sil
goto optionmenu

:buildSWBU1
call python ais.py -p %project% build_project --iuc
goto optionmenu

:buildSWBU2
call python ais.py -p %project% build_project --dpu
goto optionmenu

:buildSWBU3
call python ais.py -p %project% build_project --sil
goto optionmenu

:chekinFilesBU1
call python ais.py -p %project% check_in_files --iuc
goto optionmenu

:chekinFilesBU2
call python ais.py -p %project% check_in_files --dpu
goto optionmenu

:chekinFilesBU3
call python ais.py -p %project% check_in_files --sil
goto optionmenu

:checkpointProjectBU1
call python ais.py -p %project% checkpoint_subprojects --iuc
goto optionmenu

:checkpointProjectBU2
call python ais.py -p %project% checkpoint_subprojects --dpu
goto optionmenu

:checkpointProjectBU3
call python ais.py -p %project% checkpoint_subprojects --sil
goto optionmenu

:checkpointProjectOverall
call python ais.py -p %project% checkpoint_subprojects --overall
goto optionmenu

:END
echo End
