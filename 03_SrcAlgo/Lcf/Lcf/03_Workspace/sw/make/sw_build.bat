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

:: Use the version of Python that is installed from the l: drive
set PYTHON_PATH=c:\Tools\python\2.7.10

set mksversion=$Revision: 1.1 $
set starttime=%time:~0,8%
echo.
echo --- Start: sw_build.bat - %mksversion:~1,15%
rem (C) 2012 - ADC Lindau GERMANY
rem Authors: Edmund Friedrichs and Colin Ward, changed by Frank Sautter-Steisslinger
rem Version: 1.1  Script moved into mainstream
rem          1.10 Removed SRLCam, Mono and Stereo from File.
rem          1.12 Include EVE memory test for VL

rem --- Help ---
echo.
echo Script options are    p (prj)   build project. e.g.: mfc431, mfc431ta19, ars441dp10. Actual supported projects are: ars441dp10, mfc431, mfc431ta19, mfc431hi28, hfl110, hfl110ta10
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
echo                       doxygen   Generate doxygen documentation
echo                       demdocu   Create DEM documentation, no code compilation
echo                       cantata   Perform dynamic code analysis
echo                       courage   Perform all courage test
echo                       courage##component1:short_name1+short_name2#component2   Perform courage test: testframes
echo                                 short_name1 and short_name2 from component1 and all test frames of component2
echo                       mtstat    Prints statistics about the activated module tests.
echo                       eclipse   Generate Module Tests Eclipse environment
echo                       notify    Pops up a little notification when this script is done
echo                       cores ^<num^>: Builds target with ^<num^> of cores. Replace ^<num^> by an actual number, e.g. 8
echo                       utonly    Builds only unit test targets. No mot file will be generated
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
set UTONLY=0
set POSTONLY=0
set BUILDCONFIG=release
set SOCTYPE=high
set CONTERROR=0
set PATCHCCS=0
set PROJECT_NAME=
set APP_PROJECT_NAME=
set MFL420_PROJECT_VARIANT=0
rem SET THE DEFAULT here...
set PRODUCT=
set SCRIPT=sw
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
set NOTIFY=0
set BUILDUTILOPT=""
set BUILD_SDL=1

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
if "%1" == "single" set BUILDCORES=1
if "%1" == "why" set SCONSOPTS=%SCONSOPTS% --debug=explain
if "%1" == "nogen" set NOGEN=1
if "%1" == "low" set SOCTYPE=low
if "%1" == "keepbios" set SCONSOPTS=%SCONSOPTS% keepbios=1
if "%1" == "listonly" (
    set SCONSOPTS=%SCONSOPTS% listonly=1
    set NOPOST=1
    set NOGEN=1
)
if "%1" == "cantata"    set SCONSOPTS=%SCONSOPTS% enable_cantata=1

set str1=%1
if not x%str1:courage=%==x%str1% set SCONSOPTS=%SCONSOPTS% courage_parameters=%1

if "%1" == "eclipse"    set SCONSOPTS=%SCONSOPTS% build_eclipse=1
if "%1" == "mtstat"     set BUILDUTILOPT=%BUILDUTILOPT% --mtstat
if "%1" == "notify"     set NOTIFY=1
if "%1" == "nosdl"      set BUILD_SDL=0

if "%1" == "p" (
  if not "%2" == "" (
    set PRODUCT=%2
    for %%L IN (a b c d e f g h i j k l m n o p q r s t u v w x y z) DO SET PRODUCT=!PRODUCT:%%L=%%L!
  ) else (
    echo.
    echo Error: Please specify the product ID with as a parameter to the "p" argument
    echo        ie. sw_build.bat p mfc431
    exit /b
  )
)

if "%1" == "cores" (
  if not "%2" == "" (
    set BUILDCORES=%2
    shift
  )
)

if "%1" == "utonly" (
  set SCONSOPTS=%SCONSOPTS% unit_test_only=1
  set UTONLY=1
  set NOPOST=1
  set SKIPSBL=1
)

rem Accept legacy names or updated names
if "%1" == "sbl" (
  set BUILD_SBL=1
  set BUILD_ALL=0
  set BUILD_EMT=1
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

rem shift next command option and do the loop again until all options are processed
shift
if "%1" == "" goto optionsend
goto optionsloop
:optionsend

if "%PRODUCT:~0,6%" == "ars441" (
  set SOCTYPE=low
  set PROJECT_NAME=ars441
  set APP_PROJECT_NAME=%PRODUCT%
) else if "%PRODUCT:~0,6%" == "mfc5j3" (
  set SOCTYPE=high
  set PROJECT_NAME=mfc400
  set APP_PROJECT_NAME=%PRODUCT%
) else if "%PRODUCT:~0,6%" == "hfl110" (
  set SOCTYPE=high
  set PROJECT_NAME=hfl110
  set APP_PROJECT_NAME=%PRODUCT%
) else (
  exit /b
)

rem Only Vision Low and Vision High are currently supported for QAC dynamic configuration file generation.
rem So instead of determining the cores used based on the project, base it on the chipset, as all products
rem for a given chipset currently use the same cores
if "%SOCTYPE%" == "low" (
  set QAC_CORES=arm-m_0,dsp_0,dsp_1
) else if "%SOCTYPE%" == "high" (
  set QAC_CORES=arm-a_0,arm-m_0,arm-m_1,dsp_0,dsp_1,eve_0,eve_1
)

if %BUILD_ALL% == 1 (
  rem Vision Low does not have an arm-a_0 core
  if not "%SOCTYPE%" == "low" (
    set BUILD_S11=1
    set BUILD_arm-a_0=1  
  )

  if !SKIPSBL! EQU 0 (
    set BUILD_SBL=1
    if "%SOCTYPE%" == "low" (
      set BUILD_PRESBL=1
      set BUILD_EMT=0
    ) else (
      set BUILD_EMT=1
    )
  )
  
  set BUILD_S12=1
  set BUILD_arm-m_0=1

  set BUILD_S14=1
  set BUILD_dsp_0=1
  set BUILD_S25=1
  set BUILD_dsp_1=1

  if "%SOCTYPE%" == "high" (
    set BUILD_S13=1
    set BUILD_arm-m_1=1

    set BUILD_S16=1
    set BUILD_eve_0=1
    set BUILD_eve_all=1
    
    set BUILD_S27=1
    set BUILD_eve_1=1
  )
)

if %DEBUG% == 1 (
  set BUILDCONFIG=debug
) else (
  set BUILDCONFIG=release
)

echo.
echo Current option settings:
echo.
echo    PAUSE                = %PAUSE%
echo    REMREAD              = %REMREAD%
echo    WSCLEAN              = %WSCLEAN%
echo    CONTERROR            = %CONTERROR%
echo    SINGLE               = %SINGLE%
echo    DEBUG                = %DEBUG%
echo    POSTONLY             = %POSTONLY%
echo    DOXYGEN              = %DOXYGEN%
echo    DEM documentation    = %DEMDOCU%
echo    NOPOST               = %NOPOST%
echo    NOGEN                = %NOGEN%
echo    BUILDCONFIG          = %BUILDCONFIG%
echo    SOCTYPE              = %SOCTYPE%
echo    PROJECT_NAME         = %PROJECT_NAME%
echo    APP_PROJECT_NAME     = %APP_PROJECT_NAME%
echo    Cores used for build = %BUILDCORES%
echo    UTONLY               = %UTONLY%
echo    SCONSOPTS            = %SCONSOPTS%

if %BUILD_ALL% == 0 (
  echo.
  echo    Cores to build:
  if %BUILD_S11% == 1 echo      S11 / arm-a_0
  if %BUILD_S12% == 1 echo      S12 / arm-m_0
  if %BUILD_S13% == 1 echo      S13 / arm-m_1
  if %BUILD_S14% == 1 echo      S14 / dsp_0
  if %BUILD_S16% == 1 echo      S16 / eve_0
  if %BUILD_S25% == 1 echo      S25 / dsp_1
  if %BUILD_S27% == 1 echo      S27 / eve_1
)

set starttime=%time:~0,8%
if %REMREAD% == 1 (
  echo.
  echo Remove Read-Only and Hidden attributes
  attrib -R -H ..\..\..\..\* /S
  goto :end
)

rem --- Extract SYS/BIOS, XDCTools, GNU GCC etc. if required ---
echo.
echo Activating project

call ..\preprocess\install_tools.bat noquit ..\..\02_Development_Tools ..\..\..\..\04_Engineering\04_Build\tools

if %DEMDOCU% == 1 (
  goto :nopostp
)

if %NOGEN% == 0 (
  if %PRODUCT% == ars441 (
    set "GEN_SWAP=--gen_swap"
  ) else if %SOCTYPE% == low (
    set GEN_SWAP=
  ) else if %PRODUCT% == mfc5j3 (
    set GEN_SWAP=
  ) else if %PRODUCT% == hfl110 (
    set GEN_SWAP=
  ) else if %PRODUCT% == hfl110ta10 (
    set GEN_SWAP=
  ) else (
    set "GEN_SWAP=--gen_swap"
  )

  rem --- Generate GA and MDB files from xml
  attrib -R -H ..\..\..\00_Projects\%APP_PROJECT_NAME%\DPUFF\ga\* /S
  echo.
  echo Generating GA and MDB files
  echo %PYTHON_PATH%\python.exe ..\..\..\02_Development_Tools\soccer\socGenerator.py SConscript_soccer --product=%PRODUCT% %GEN_SWAP% --ga --mdb
  call %PYTHON_PATH%\python.exe ..\..\..\02_Development_Tools\soccer\socGenerator.py SConscript_soccer --product=%PRODUCT% %GEN_SWAP% --ga --mdb
  if ERRORLEVEL 1 (
    echo.
    echo *** Generating GA and MDB files failed ***
    exit /b 1
  )
)

set time_buildPreEnd=%time:~0,8%

if %POSTONLY% == 1 (
  goto :postp
)

if %PAUSE% == 1 (
echo.
echo Is this OK? - CTRL+C to abort
pause
) else (
  rem echo NO Pause will be done
)

echo.
echo Go ...

if ERRORLEVEL 1 (
  echo.
  echo *** Unable to prepare environment for building - aborting ***
  exit /b 1
)

rem Delete build output
if %WSCLEAN% == 1 (
  echo.
  echo Make a clean WS
  if exist ..\..\..\04_Build\out\%APP_PROJECT_NAME% (
    echo Deleting previously built SW sources
    if %BUILD_arm-a_0%==1 rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-a_0
    if %BUILD_dsp_0%==1   rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_dsp_0
    if %BUILD_dsp_1%==1   rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_dsp_1
    if %BUILD_eve_0%==1   rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_eve_0
    if %BUILD_eve_1%==1   rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_eve_1
    if %BUILD_arm-m_0%==1 rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-m_0
    if %BUILD_arm-m_1%==1 rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_arm-m_1
    if %BUILD_SBL%==1     rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_sbl
    if %BUILD_SBL%==1     rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_sbl_loop
    if %BUILD_PRESBL%==1  rd /q /s ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_presbl
  )
  if exist ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME% (
    echo Deleting previously built moduletest sources
    if %BUILD_arm-a_0%==1 rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\arm-a_0
    if %BUILD_dsp_0%==1   rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\dsp_0
    if %BUILD_dsp_1%==1   rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\dsp_1
    if %BUILD_eve_0%==1   rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\eve_0
    if %BUILD_eve_1%==1   rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\eve_1
    if %BUILD_arm-m_0%==1 rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\arm-m_0
    if %BUILD_arm-m_1%==1 rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\arm-m_1
    if %BUILD_SBL%==1     rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\sbl
    if %BUILD_SBL%==1     rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\sbl_loop
    if %BUILD_PRESBL%==1  rd /q /s ..\..\..\04_Build\ModuleTests\%APP_PROJECT_NAME%\presbl
  )
  echo.
)

if %PAUSE% == 1 (
  echo.
  echo Build now? - CTRL+C to abort
  pause
)

rem Build and post process
  if %BUILD_S12% == 1 (
    rem Generating info block is only done in the sx_build.bat script.
    )

echo %BUILDCONFIG% build launched ...

rem Decide what arguments to pass to scons
echo Building product %APP_PROJECT_NAME% ...
set SCONSPARAMS=debug=%DEBUG% product=%APP_PROJECT_NAME% chipset=%SOCTYPE%

rem build target sbl builds sbl and sbl_loop
set time_buildStart=%time:~0,8%
if %BUILD_PRESBL% == 1 call::buildCore presbl
set time_buildPRESBL=%time:~0,8%
if %BUILD_SBL% == 1 call::buildCore sbl
set time_buildSBL=%time:~0,8%
if %BUILD_SBL% == 1 call::buildCore sbl_loop
set time_buildSBLLoop=%time:~0,8%
if %BUILD_EMT% == 1 call::buildCore eve_memtest
set time_buildEMT=%time:~0,8%
if %BUILD_S11% == 1 call::buildCore arm-a_0
set time_buildARM_A0=%time:~0,8%
if %BUILD_S12% == 1 call::buildCore arm-m_0
set time_buildARM_M0=%time:~0,8%
if %BUILD_S13% == 1 call::buildCore arm-m_1
set time_buildARM_M1=%time:~0,8%
if %BUILD_S14% == 1 call::buildCore dsp_0
set time_buildDSP_0=%time:~0,8%
if %BUILD_S16% == 1 call::buildCore eve_0
set time_buildEVE_0=%time:~0,8%
if %BUILD_S25% == 1 call::buildCore dsp_1
set time_buildDSP_1=%time:~0,8%
if %BUILD_S27% == 1 call::buildCore eve_1
set time_buildEVE_1=%time:~0,8%

:: Following if else is taking care of copying sbl out-files to deliverables
:: which doesn't happen in "nopost" scenario otherwise. 
if %BUILD_PRESBL% == 1 (
  call ..\postprocess\sbl_create_tiimage.bat %APP_PROJECT_NAME% .
) else if %BUILD_SBL% == 1 (
  call ..\postprocess\sbl_create_tiimage.bat %APP_PROJECT_NAME% .
)

:postp
rem Postprocess
set time_buildPost=%time:~0,8%
if %NOPOST% == 1 goto :nopostp

rem Generate an overall QAC dynamic configuration file, but only if the core list for the current
rem project has been defined
if "%QAC_CORES%" neq "" (
  if exist ..\..\qac\start_qac.cmd (
    echo.
    echo Post process - generate QAC C configuration
    pushd ..\..\qac
    call %PYTHON_PATH%\python.exe ..\sw\postprocess\qac_project_merger.py --cores=%QAC_CORES% --language=C --product=%PRODUCT%

    if ERRORLEVEL 1 (
      echo.
      echo *** Merging QAC configuration files failed ***
      exit /b 1
    )

    popd
  )

  if exist ..\..\qacpp\start_qacpp.cmd (
    echo.
    echo Post process - generate QAC C++ configuration
    pushd ..\..\qacpp
    call %PYTHON_PATH%\python.exe ..\sw\postprocess\qac_project_merger.py --cores=%QAC_CORES% --language=CPP --product=%PRODUCT%

    if ERRORLEVEL 1 (
      echo.
      echo *** Merging QACPP configuration files failed ***
      exit /b 1
    )
  
    popd
  )
)

echo.
echo Post process - build SOC mot file
call ..\postprocess\BuildSOCMotfileCommon.bat

rem If any error occurred then exit without displaying the end of build epilogue.
rem Otherwise the error message printed by the sub-batchfile can be missed by the user
if ERRORLEVEL 1 (
  exit /b 1
)

if %DOXYGEN% == 1 (
  rem Generate doxygen documentation
  for %%c in (../doxygen/*.doxy) do (
    if not "%%~nc" == "process" (
      echo.  
      if "%%~nc" == "SoC" ( 
        echo Generate doxygen documentation for %APP_PROJECT_NAME% SoC
      ) else (
        echo Generate doxygen documentation for %APP_PROJECT_NAME% component %%~nc
      )
      call ..\doxygen\create_documentation.bat p %APP_PROJECT_NAME% %%~nc
      if ERRORLEVEL 1 (
        exit /b 1
      )
    )  
  )
)


:nopostp
rem ZIPME is only done in the sx_build.bat script.

rem Generate DEM documentation
if %DEMDOCU% == 1 (
  rem Make doc dir in 04_Build
  if not exist ..\..\..\04_Build\doc\dem_docu mkdir ..\..\..\04_Build\doc\dem_docu
  echo.
  echo ******** Generate DEM documentation *********
  if exist createDemDocumentation.py (
    call %PYTHON_PATH%\python.exe createDemDocumentation.py ..\..\..\01_Source_Code\SW\source ..\..\..\04_Build\doc\dem_docu\DEM_descriptions.html

    if ERRORLEVEL 1 (
      echo.
      echo *** Generating DEM documentation failed ***
      exit /b 1
    )
  )
  echo *********************************************
)

:end

set endtime=%time:~0,8%

echo.
echo --- Done:  sw_build.bat
echo --- Started: %starttime:~0,8%, Ended: %endtime:~0,8%

set hrs=%endtime:~0,2%
set /a hrs=%hrs%-(%starttime:~0,2%)

set /a mins=1%endtime:~3,2%-100
set /a mins=%mins%-(1%starttime:~3,2%-100)

set /a secs=1%endtime:~6,2%-100
set /a secs=%secs%-(1%starttime:~6,2%-100)

if %secs% lss 0 (
    set /a secs=%secs%+60
    set /a mins=%mins%-1
)
if %mins% lss 0 (
    set /a mins=%mins%+60
    set /a hrs=%hrs%-1
)
if %hrs% lss 0 (
    set /a hrs=%hrs%+24
)

if %secs% lss 10 (
    set secs=0%secs%
)
if %mins% lss 10 (
    set mins=0%mins%
)
if %hrs% lss 10 (
    set hrs=0%hrs%
)

echo --- Script Execution Time:  %hrs%:%mins%:%secs%
echo.

call::coreBuildTime preProcess %starttime% %time_buildPreEnd%
if %POSTONLY% == 0 (
    if %BUILD_PRESBL% == 1 call::coreBuildTime PRESBL %time_buildStart% %time_buildPRESBL%
    if %BUILD_SBL% == 1 call::coreBuildTime SBL %time_buildPRESBL% %time_buildSBL%
    if %BUILD_SBL% == 1 call::coreBuildTime SBL_Loop %time_buildSBL% %time_buildSBLLoop%
    if %BUILD_EMT% == 1 call::coreBuildTime EVE_MemTest %time_buildSBLLoop% %time_buildEMT%
    if %BUILD_S11% == 1 call::coreBuildTime ARM_A0 %time_buildEMT% %time_buildARM_A0%
    if %BUILD_S12% == 1 call::coreBuildTime ARM_M0 %time_buildARM_A0% %time_buildARM_M0%
    if %BUILD_S13% == 1 call::coreBuildTime ARM_M1 %time_buildARM_M0% %time_buildARM_M1%
    if %BUILD_S14% == 1 call::coreBuildTime DSP_0 %time_buildARM_M1% %time_buildDSP_0%
    if %BUILD_S16% == 1 call::coreBuildTime EVE_0 %time_buildDSP_0% %time_buildEVE_0%
    if %BUILD_S25% == 1 call::coreBuildTime DSP_1 %time_buildEVE_0% %time_buildDSP_1%
    if %BUILD_S27% == 1 call::coreBuildTime EVE_1 %time_buildDSP_1% %time_buildEVE_1%
)
call::coreBuildTime postProcess %time_buildPost% %endtime%

goto:finish

::==================================================================
:: FUNCTIONS SECTION
::==================================================================

:: Calculate Execution Time
:coreBuildTime
    setlocal
    set CORENAME=%1
    set coreBuildStart=%~2
    set coreBuildEnd=%~3
    
    if "%coreBuildEnd:~1,1%" equ ":" (
        set hrsEnd=%coreBuildEnd:~0,1%
        set /a minEnd=1%coreBuildEnd:~2,2%-100
        set /a secEnd=1%coreBuildEnd:~5,2%-100
    ) else (
        set hrsEnd=%coreBuildEnd:~0,2%
        set /a minEnd=1%coreBuildEnd:~3,2%-100
        set /a secEnd=1%coreBuildEnd:~6,2%-100
    )
   
    if "%coreBuildStart:~1,1%" equ ":" (
        set hrsSta=%coreBuildStart:~0,1%
        set /a minSta=1%coreBuildStart:~2,2%-100
        set /a secSta=1%coreBuildStart:~5,2%-100
    ) else (
        set hrsSta=%coreBuildStart:~0,2%
        set /a minSta=1%coreBuildStart:~3,2%-100
        set /a secSta=1%coreBuildStart:~6,2%-100
    )

    set /a hrs=%hrsEnd%-%hrsSta%
    set /a mins=%minEnd%-%minSta%
    set /a secs=%secEnd%-%secSta%
    
    if %secs% lss 0 (
        set /a secs=%secs%+60
        set /a mins=%mins%-1
    )
    if %mins% lss 0 (
        set /a mins=%mins%+60
        set /a hrs=%hrs%-1
    )
    if %hrs% lss 0 (
        set /a hrs=%hrs%+24
    )

    if %secs% lss 10 (
        set secs=0%secs%
    )
    if %mins% lss 10 (
        set mins=0%mins%
    )
    if %hrs% lss 10 (
        set hrs=0%hrs%
    )
  
    echo --- Execution Time was %hrs%:%mins%:%secs% for %CORENAME%
goto:eof


:: buildCore: Compiles a single core
::
::  ARG0: Core name
:buildCore
  setlocal
  set CORENAME=%~1
  echo.
  echo Building %CORENAME%
  pushd ..\..\..\..

   :: Run movable Python and Scons from MKS
  echo ############# Using !BUILDCORES! cores for build. #############
  call %PYTHON_PATH%\python.exe %PYTHON_PATH%\Scripts\scons.py -C 04_Engineering\03_Workspace\sw\make target=%CORENAME% -j%BUILDCORES% %SCONSPARAMS% %SCONSOPTS%
  if ERRORLEVEL 1 (
    if "%CONTERROR%" == "0" call::halt 1
  )
  popd
  if not exist ..\..\..\04_Build\out\%APP_PROJECT_NAME%\%BUILDCONFIG%_%CORENAME%\%CORENAME%.out exit /b 1
goto:eof


::===================================================================
:: Functions required for exiting batch file from within a function.
::
:: http://stackoverflow.com/questions/3227796/exit-batch-script-from-inside-a-function
::===================================================================

:: Sets the errorlevel and stops the batch immediately
:halt
call :__SetErrorLevel %1
call :__ErrorExit 2> nul
goto :finish

:__ErrorExit
:: Go back to initial working directory, another program / batch file might have changed
:: the current working directory
cd %INITIAL_WD%
:: Creates a syntax error, stops immediately
()
goto :eof

:__SetErrorLevel
exit /b %time:~-2%
goto :eof

:finish
pushd ..\..\..\..
if exist ./BuildUtils.py (
  call %PYTHON_PATH%\python.exe BuildUtils.py %BUILDUTILOPT%

  if ERRORLEVEL 1 (
    echo.
    echo *** Calling Cantata statistics generator failed ***
    exit /b 1
  )
)

popd
if %NOTIFY% == 1 (
  call %PYTHON_PATH%\python.exe -c "import ctypes; ctypes.windll.user32.MessageBoxA(0, '%FILENAME% done!', 'Done', 0)"
)
