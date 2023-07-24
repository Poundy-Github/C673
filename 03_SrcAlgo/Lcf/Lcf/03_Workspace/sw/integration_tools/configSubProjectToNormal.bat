@echo off
SETLOCAL EnableDelayedExpansion

rem This script configures all component sub-projects to normal. 


SET MYPATH=%cd%
set ANSWER=n


rem Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%


rem Change working directory to the directory where this script is stored. This allows invoking
rem this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%


rem Create the date and time elements
if "%date:~2,1%" == "." (
    echo Using German date format
) else if "%date:~2,1%" == "/" (
    echo Using British date format
) else if "%date:~2,1%" == "-" (
    echo Using Indian date format
) else if "%date:~5,1%" == "." (
    echo Using Finnish date format
) else if "%date:~6,1%" == "/" (
    echo Using some special date format  
) else (
    echo *** Invalid regional settings detected - aborting ***
    echo.
    echo Only parsing of British, Indian, Finnish and German and date formats is supported.
    echo Please set your regional settings to either British, German, Finnish or Indian.  You
    echo can do this independently of the language used on your system.  US date format
    echo is non standard and thus not supported.
    exit /b 1
)

rem Check if hours are less 10 and add leading 0
if %time:~0,2% lss 10 (
    set hrs=0%time:~1,1%
) else (
    set hrs=%time:~0,2%
)
rem German date format
if "%date:~2,1%" == "." (
    set tsnow=%date:~8,2%%date:~3,2%%date:~0,2%_%hrs%%time:~3,2%
rem Finish date format
) else if "%date:~5,1%" == "." (
    set tsnow=%date:~11,2%%date:~6,2%%date:~3,2%_%hrs%%time:~3,2%
rem Special date format
) else if "%date:~6,1%" == "/" (
    set tsnow=%date:~12,2%%date:~7,2%%date:~4,2%_%hrs%%time:~3,2%
rem British and Indian date format
) else (
    set tsnow=%date:~8,2%%date:~3,2%%date:~0,2%_%hrs%%time:~3,2%
)


rem Read input option
:optionsloop
if "%1" == "p" (
    if "%2%"=="" (
        echo.
        echo Error: Please specify the product ID with a parameter to the "p" argument
        echo        ie. confAlgoSubProject.bat p mfs430bw16
        exit /b
    ) else (
        set project=%2
    )
) else if "%1%"=="" (
    echo.
    echo Error: Please specify the product ID with a parameter to the "p" argument
    echo        ie. confAlgoSubProject.bat p mfs430bw16
    exit /b
  )

rem Shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend


rem CP IDs to be used
echo.
si viewcps
echo.

echo Enter the Change Package ID to be used [%changePID%]: 
set /p changePID=

if "!changePID!"=="" (
	echo.
	echo Error: Please select the CP ID to be used
	exit /b
)


rem Set all sub-projects to be reconfigured
set supProj[0]=00_Projects\%project%
set supProj[1]=01_Source_Code
set supProj[2]=02_Development_Tools
set supProj[3]=03_Workspace


rem Give some info to the user
echo.
echo Info: This script will reconfigure all components in the following sub-projects:
for /F "tokens=2 delims==" %%s in ('set supProj[') do echo  - %%s
echo It does this for %project% project using the Changepackage %changePID%
echo.


for /F "tokens=2 delims==" %%s in ('set supProj[') do (
    set ANSWER=n
	echo.
    echo Reconfigure now ..\%%s
	echo Reconfigure now ..\%%s >> %INITIAL_WD%\%tsnow%_prepareMMI.txt
	cd ..\..\..\%%s	
	for /d %%a in ("!cd!\*") do (
        if %%~nxa neq common (
            if %%~nxa neq algo (
                echo.
                rem echo Folder name: %%~nxa, full folder path: %%a
                for /f "delims=)" %%j in ('"si viewproject --no %%~nxa\project.pj"') do set cpSource=%%j
                set cpSource=!cpSource:*(=!
                cd %%~nxa
                for /f %%k in ('"si viewprojecthistory --maxTrunkRevs=1"^|findstr ^)') do set cpHead=%%k
                cd ..
                if !ANSWER! neq Y (
                    echo Do you want to reconfigure %%a ^(!cpSource! to normal^) ? [!ANSWER!] 
                    SET /P ANSWER=
                )
                if !ANSWER!==y (
                    si configuresubproject --changePackageId=!changePID! --type=normal %%~nxa\project.pj
                    echo %%a ^(!cpSource! to normal^)
                    echo %%a ^(!cpSource! to normal^) >> %INITIAL_WD%\%tsnow%_prepareMMI.txt
                )
                if !ANSWER!==Y (
                    si configuresubproject --changePackageId=!changePID! --type=normal %%~nxa\project.pj
                    echo %%a ^(!cpSource! to normal^)
                    echo %%a ^(!cpSource! to normal^) >> %INITIAL_WD%\%tsnow%_prepareMMI.txt
                )
                if !ANSWER!==N exit /b
            )
        )
        if %%~nxa equ common (
            cd %%~nxa
            for /d %%b in ("!cd!\*") do (
                echo.
                rem echo Folder name: %%~nxb, full folder path: %%b
                for /f "delims=)" %%j in ('"si viewproject --no %%~nxb\project.pj"') do set cpSource=%%j
                set cpSource=!cpSource:*(=!
                cd %%~nxb
                for /f %%k in ('"si viewprojecthistory --maxTrunkRevs=1"^|findstr ^)') do set cpHead=%%k
                cd ..
                if !ANSWER! neq Y (
                    echo Do you want to reconfigure %%b ^(!cpSource! to !cpHead!^) ? [!ANSWER!] 
                    SET /P ANSWER=
                )
                if !ANSWER!==y (
                    si configuresubproject --changePackageId=!changePID! --type=normal %%~nxb\project.pj
                    echo %%b ^(!cpSource! to normal^)
                    echo %%b ^(!cpSource! to normal^) >> %INITIAL_WD%\%tsnow%_prepareMMI.txt   
                )
                if !ANSWER!==Y (
                    si configuresubproject --changePackageId=!changePID! --type=normal %%~nxb\project.pj
                    echo %%b ^(!cpSource! to normal^)
                    echo %%b ^(!cpSource! to normal^) >> %INITIAL_WD%\%tsnow%_prepareMMI.txt
                )
                if !ANSWER!==N exit /b
            )
            cd ..
        )
    )

    cd %CURRENT_WD%
)

ENDLOCAL & SET changePID=%changePID%