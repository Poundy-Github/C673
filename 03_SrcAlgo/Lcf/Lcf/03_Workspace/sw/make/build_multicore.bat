@echo off

:: Make sure changes to environment variables are only local do not affect the calling command line
setlocal EnableDelayedExpansion


:: Store current working directory, so we can CD back in case of an error
set INITIAL_WD=%CD%

:: Change working directory to the directory where this script is stored. This allows invoking
:: this script from any directory without CD'ing into the batch file's home directory
cd %~dp0
set CURRENT_WD=%CD%
set "FILENAME=%~n0"

set PYTHON_PATH=c:\Tools\python\2.7.10

set mksversion=$Revision: 1.1 $
set starttime=%time:~0,8%
echo.
echo --- Start: sx_build.bat - %mksversion:~1,15%
rem (C) 2012 - ADC Lindau GERMANY
rem Authors: Edmund Friedrichs and Colin Ward, changed by Frank Sautter-Steisslinger
rem Version: 1.1  Script moved into mainstream
rem          1.12  Removed mono and stereo option from script after move to mainstream.  	19.01.2017    Magnus Baur
rem          1.16  Removed srlcam, mono and stereo parts from script 						07.02.2017    Magnus Baur


rem --- Help ---
echo.
echo Script options are    p (prj)   build project. e.g.: mfc431, mfc431ta19, ars441. Actual supported projects are: ars441, mfc431, mfc431ta19, mfc431hi28, hfl110, hfl110ta10
echo                       pause     Shows the selected options and asks for GO
echo                       remread   Just removes the read-only attributes
echo                       wsclean   Make a clean workspace. Removes "out" directory
echo                                 and all .obj, .out etc. files in it
echo                       debug     Debug build. Default is release build
echo                       nopost    No post processing is done
echo                       postonly  Only post processing will be done
echo                       corename  name of the core selected for all the other
echo                                 options (e.g. arm-a_1 or dsp_0). ALL is default
echo                       sxx       old sxx core selection naming maintained for
echo                                 legacy. Core number is xx
echo                       conterror Continues after build errors
echo                       single    Use only a single thread for building (slow but
echo                                 helps to find compiler errors)
echo                       why       Tells SCons to explain why it is rebuilding
echo                                 something
echo                       keepbios  Do not rebuild an entire core when sysbios
echo                                 configuration (app.cfg) changed
echo                       listonly  Generate ^<outdir^>/^<corename^>.lst file only,
echo                                 without compiling code
echo                       nogen     Skip generation of GA, MDB and IPC files
echo                       algo      Check out specific algo checkpoint locally
echo                                 Valid algo label name needs to follow this option (e.g. algo AL_SRLCam4T0_02.01.00_INT10)
echo                       locpy     Usage of locally installed Python and Scons
echo                       a2l       Generating A2L file in postprocess
echo                       ipc       Generate IPC files new. Default is just generation of GA and MDB files
echo                       corCRC    Corrupt CRC values for all code sections (Image will not be bootable this is only for test of error reaction)
echo                       analyse   Generate RAM and ROM usage analysis of SW and Algo components for release build
echo                       zipme     Zip out and map file for release check-in
echo                       doxygen   Generate doxygen documentation
echo                       demdocu   Create DEM documentation, no code compilation
echo                       cantata   Perform dynamic code analysis
echo                       eclipse   Generate Module Tests Eclipse environment
echo                       notify    Pops up a little notification when this script is done
::echo                     patchccs  Patches CCS projects with scons generated listing files after scons build finished
echo.


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


rem --- Handling of build options ---
set PAUSE=0
set DEBUG=0
set REMREAD=0
set WSCLEAN=0
set NOPOST=0
set POSTONLY=0
set BUILDCONFIG=release
set SOCTYPE=high
set CONTERROR=0
set PATCHCCS=0
set PROJECT_NAME=
set APP_PROJECT_NAME=
set MFL420_PROJECT_VARIANT=0
set MFC440_PROJECT_VARIANT=0
set PRODUCT=
set SCRIPT=sx
set SINGLE=0
set SCONSOPTS=
set NOGEN=0
set CORRUPTCRC=0
set DOXYGEN=0
set DEMDOCU=0
set BUILD_SBL=0
set BUILD_PRESBL=0
set BUILD_EMT=0
set SKIPSBL=0
set IPC=0
set ANALYSE=0
set ZIPME=0
set LOCPY=0
set A2L=1
set mfl420=0
set NOTIFY=0
set BUILDUTILOPT=""
set KFILEPRECOMPILE=0

set BUILD_S11=0
set BUILD_arm-a_0=0
set BUILD_S12=0
set BUILD_arm-m_0=0
set BUILD_S13=0
set BUILD_arm-m_1=0
set BUILD_S14=0
set BUILD_dsp_0=0
set BUILD_S16=0
set BUILD_eve_0=0
set BUILD_S25=0
set BUILD_dsp_1=0
set BUILD_S27=0
set BUILD_eve_1=0
set BUILD_ALL=1
set BUILD_eve_all=0

set BUILDCORES=%NUMBER_OF_PROCESSORS%

:optionsloop
if "%1" == "help" goto :end
if "%1" == "h"    goto :end
if "%1" == "pause"    set PAUSE=1
if "%1" == "remread"  set REMREAD=1
if "%1" == "doxygen"  set DOXYGEN=1
if "%1" == "demdocu"  set DEMDOCU=1
if "%1" == "wsclean"  set WSCLEAN=1
if "%1" == "debug"    set DEBUG=1
if "%1" == "nopost"   set NOPOST=1
if "%1" == "postonly" set POSTONLY=1
if "%1" == "conterror" set CONTERROR=1
if "%1" == "patchccs" set PATCHCCS=1
if "%1" == "single" set SINGLE=1
if "%1" == "why" set SCONSOPTS=%SCONSOPTS% --debug=explain
if "%1" == "nogen" set NOGEN=1
if "%1" == "low" set SOCTYPE=low
if "%1" == "keepbios" set SCONSOPTS=%SCONSOPTS% keepbios=1
if "%1" == "listonly" (
    set SCONSOPTS=%SCONSOPTS% listonly=1
    set NOPOST=1
    set NOGEN=1
)
if "%1" == "zipme" set ZIPME=1
if "%1" == "a2l" set A2L=1
if "%1" == "ipc" set IPC=1
if "%1" == "cantata"    set SCONSOPTS=%SCONSOPTS% enable_cantata=1
if "%1" == "courage"    set SCONSOPTS=%SCONSOPTS% enable_courage=1
if "%1" == "eclipse"    set SCONSOPTS=%SCONSOPTS% build_eclipse=1
if "%1" == "mtstat"     set BUILDUTILOPT=%BUILDUTILOPT% --mtstat
if "%1" == "notify"     set NOTIFY=1

if "%1" == "p" (
  if not "%2" == "" (
    set PRODUCT=%2
  ) else (
    echo.
    echo Error: Please specify the product ID with as a parameter to the "p" argument
    echo        ie. sw_build.bat p mfc431
    exit /b
    )
)

rem Accept legacy names or updated names
if "%1" == "sbl" (
  set BUILD_SBL=1
  set BUILD_ALL=0
  if "%SOCTYPE%" == "high" (
     set BUILD_EMT=1
    ) else if "%SOCTYPE%" == "low" (
     set BUILD_EMT=1
	)
  )
if "%1" == "presbl" (
  set BUILD_PRESBL=1
  set BUILD_ALL=0
  )
if "%1" == "s11" (
  set BUILD_S11=1
  set BUILD_arm-a_0=1
  set BUILD_ALL=0
  )
if "%1" == "arm-a_0" (
  set BUILD_S11=1
  set BUILD_arm-a_0=1
  set BUILD_ALL=0
  )
if "%1" == "s12" (
  set BUILD_S12=1
  set BUILD_arm-m_0=1
  set BUILD_ALL=0
  )
if "%1" == "arm-m_0" (
  set BUILD_S12=1
  set BUILD_arm-m_0=1
  set BUILD_ALL=0
  )
if "%1" == "s13" (
  set BUILD_S13=1
  set BUILD_arm-m_1=1
  set BUILD_ALL=0
  )
if "%1" == "arm-m_1" (
  set BUILD_S13=1
  set BUILD_arm-m_1=1
  set BUILD_ALL=0
  )
if "%1" == "s14" (
  set BUILD_S14=1
  set BUILD_dsp_0=1
  set BUILD_ALL=0
  )
if "%1" == "dsp_0" (
  set BUILD_S14=1
  set BUILD_dsp_0=1
  set BUILD_ALL=0
  )
if "%1" == "s16" (
  set BUILD_S16=1
  set BUILD_eve_0=1
  set BUILD_eve_all=1
  set BUILD_ALL=0
  )
if "%1" == "eve_0" (
  set BUILD_S16=1
  set BUILD_eve_0=1
  set BUILD_eve_all=1
  set BUILD_ALL=0
  )
if "%1" == "s25" (
  set BUILD_S25=1
  set BUILD_dsp_1=1
  set BUILD_ALL=0
  )
if "%1" == "dsp_1" (
  set BUILD_S25=1
  set BUILD_dsp_1=1
  set BUILD_ALL=0
  )
if "%1" == "s27" (
  set BUILD_S27=1
  set BUILD_eve_1=1
  set BUILD_eve_all=1
  set BUILD_ALL=0
  )
if "%1" == "eve_1" (
  set BUILD_S27=1
  set BUILD_eve_1=1
  set BUILD_eve_all=1
  set BUILD_ALL=0
  )

if "%1" == "locpy" (
  set LOCPY=1
  )
if "%1" == "corCRC" (
  set CORRUPTCRC=1
  )
if "%1" == "analyse" set ANALYSE=1

rem shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

if "%PRODUCT:~0,6%" == "ars441" (
  set SOCTYPE=low
  set PROJECT_NAME=ars441
  set APP_PROJECT_NAME=%PRODUCT%
) else if "%PRODUCT:~0,6%" == "mfc431" (
  set SOCTYPE=high
  set PROJECT_NAME=mfc400
  set APP_PROJECT_NAME=%PRODUCT%
  set KFILEPRECOMPILE=0
) else if "%PRODUCT:~0,6%" == "hfl110" (
  set SOCTYPE=high
  set PROJECT_NAME=hfl110
  set APP_PROJECT_NAME=%PRODUCT%
) else (
  exit /b
)

call sx_build.bat p %APP_PROJECT_NAME% arm-a_0 nopost
start sx_build.bat p %APP_PROJECT_NAME% sbl multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% arm-m_0 multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% arm-m_1 multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% dsp_0 multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% dsp_1 multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% eve_0 multicore nogen nopost
timeout 5
start sx_build.bat p %APP_PROJECT_NAME% eve_1 multicore nogen nopost
timeout 5
call sx_build.bat p %APP_PROJECT_NAME% multicore zipme postonly
